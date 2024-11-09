#include <iostream>
#include <vector>
using namespace std;

struct SegNode
{
    SegNode()
    {
        v00 = v01 = v10 = v11 = 0; // 初始化节点状态
    }
    void set(unsigned int val)
    {
        v00 = v01 = v10= 0;
       v11 = val;
    }
    unsigned int GetMax() const
    {
        return v11;
    }

    unsigned int v00, v01, v10, v11;
};

class SegTree // 线段树类
{
public:
    SegTree(vector<int>& nums)
    {
        // 根据传入的数组进行建树
        n = nums.size();
        tree.resize(4 * n); // 重新为树分配合适的空间

        // 插入节点
        CreatSegTree(nums, 0, 0, n - 1);
    }

    const unsigned int GetMax() const
    {
        return tree[0].GetMax();
    }

    // 单点修改
    void UpDate(int i, int val)
    {
        internal_update(0, i, val, 0, n - 1);
    }
private:
    void CreatSegTree(vector<int>& nums, int root, int l, int r)
    { // root是该节点在数组中的位置
        // l = 0, r = n - 1;//初始从数组下标开始

        // 插入节点并进行维护
        if (l == r) // 找到叶子节点
        {
            tree[root].set(nums[l]);
            return; // 叶子节点不需要进行维护
        } // 对应节点初始值插入
        // 分别插入左右孩子的叶子节点
        int mid = (l + r) / 2;
        CreatSegTree(nums, 2 * (root+1)-1, l, mid);
        CreatSegTree(nums, 2 * (root + 1), mid + 1, r);
        PushUp(root); // 维护节点
    }
    void internal_update(int root, int i, int val, int l, int r)
    {
        if (l == r)
        {
            tree[root].set(val>0?val:0);
            return;
        }
        // i修改位置，
        int mid = (l + r) / 2;
        if (i <= mid) // 在左区间进行查找
        {
            internal_update(2 * (root + 1) - 1, i, val, l, mid);
        }
        else
            internal_update(2 * (root + 1), i, val, mid + 1, r);
        PushUp(root);
    }

    void PushUp(int root) // 维护root节点
    {
        // 用于维护树
        // 每次创建树和单点修改后维护所有的节点
        // 就是跟新每个可能区间的值
        // 首先计算该节点的孩子节点
        int l = 2 * (root+1)-1, r = 2 * (root + 1);
        tree[root].v00 = max(tree[l].v01 + tree[r].v00, tree[l].v00 + tree[r].v10);
        tree[root].v01 = max(tree[l].v01 + tree[r].v01, tree[l].v00 + tree[r].v11);
        tree[root].v10 = max(tree[l].v10 + tree[r].v10, tree[l].v11 + tree[r].v00);
        tree[root].v11 = max(tree[l].v11 + tree[r].v01, tree[l].v10 + tree[r].v11);
    }

private:
    vector<SegNode> tree; // 实际的线段树
    int n;
};

int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size(); // 记录数组长度
    // 记录查询次数
    int sum = 0; // 记录初始和，当每次查询最大值不小于0时，才相加
    SegTree tree(nums);

    for (auto& query : queries)
    {
        // 每次查询要将对应位置的值进行替换
        tree.UpDate(query[0], query[1]);
        sum += (int)tree.GetMax();
    }
    return sum % 1000000007;
}
int main()
{
    vector<int >  vec = {3,5,9};
    vector<vector<int>>  que;
    que.push_back({ 1,-2 });
    que.push_back({ 0,-3 });
    int ans=maximumSumSubsequence(vec, que);
    std::cin.get();
}