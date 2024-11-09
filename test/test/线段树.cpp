#include <iostream>
#include <vector>
using namespace std;

struct SegNode
{
    SegNode()
    {
        v00 = v01 = v10 = v11 = 0; // ��ʼ���ڵ�״̬
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

class SegTree // �߶�����
{
public:
    SegTree(vector<int>& nums)
    {
        // ���ݴ����������н���
        n = nums.size();
        tree.resize(4 * n); // ����Ϊ��������ʵĿռ�

        // ����ڵ�
        CreatSegTree(nums, 0, 0, n - 1);
    }

    const unsigned int GetMax() const
    {
        return tree[0].GetMax();
    }

    // �����޸�
    void UpDate(int i, int val)
    {
        internal_update(0, i, val, 0, n - 1);
    }
private:
    void CreatSegTree(vector<int>& nums, int root, int l, int r)
    { // root�Ǹýڵ��������е�λ��
        // l = 0, r = n - 1;//��ʼ�������±꿪ʼ

        // ����ڵ㲢����ά��
        if (l == r) // �ҵ�Ҷ�ӽڵ�
        {
            tree[root].set(nums[l]);
            return; // Ҷ�ӽڵ㲻��Ҫ����ά��
        } // ��Ӧ�ڵ��ʼֵ����
        // �ֱ�������Һ��ӵ�Ҷ�ӽڵ�
        int mid = (l + r) / 2;
        CreatSegTree(nums, 2 * (root+1)-1, l, mid);
        CreatSegTree(nums, 2 * (root + 1), mid + 1, r);
        PushUp(root); // ά���ڵ�
    }
    void internal_update(int root, int i, int val, int l, int r)
    {
        if (l == r)
        {
            tree[root].set(val>0?val:0);
            return;
        }
        // i�޸�λ�ã�
        int mid = (l + r) / 2;
        if (i <= mid) // ����������в���
        {
            internal_update(2 * (root + 1) - 1, i, val, l, mid);
        }
        else
            internal_update(2 * (root + 1), i, val, mid + 1, r);
        PushUp(root);
    }

    void PushUp(int root) // ά��root�ڵ�
    {
        // ����ά����
        // ÿ�δ������͵����޸ĺ�ά�����еĽڵ�
        // ���Ǹ���ÿ�����������ֵ
        // ���ȼ���ýڵ�ĺ��ӽڵ�
        int l = 2 * (root+1)-1, r = 2 * (root + 1);
        tree[root].v00 = max(tree[l].v01 + tree[r].v00, tree[l].v00 + tree[r].v10);
        tree[root].v01 = max(tree[l].v01 + tree[r].v01, tree[l].v00 + tree[r].v11);
        tree[root].v10 = max(tree[l].v10 + tree[r].v10, tree[l].v11 + tree[r].v00);
        tree[root].v11 = max(tree[l].v11 + tree[r].v01, tree[l].v10 + tree[r].v11);
    }

private:
    vector<SegNode> tree; // ʵ�ʵ��߶���
    int n;
};

int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size(); // ��¼���鳤��
    // ��¼��ѯ����
    int sum = 0; // ��¼��ʼ�ͣ���ÿ�β�ѯ���ֵ��С��0ʱ�������
    SegTree tree(nums);

    for (auto& query : queries)
    {
        // ÿ�β�ѯҪ����Ӧλ�õ�ֵ�����滻
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