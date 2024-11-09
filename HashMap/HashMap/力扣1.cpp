
#include "HashMap_V1.cpp"
//创建哈希表，将数组中的每个值填到对应哈希表里
std::vector<int> twoSum(std::vector<int>& nums, int target) {
	size_t count = nums.size();
	unordered_map<int, int, std::hash<int>>* map = new unordered_map<int, int, std::hash<int>>(count);
	std::vector<int> tmp;
	for (int i = 0; i < count; i++) {
		bool val = map->find(target - nums[i]);
		if (val == true)
		{
			tmp.push_back(map->get(target - nums[i]));
			tmp.push_back(i);
		}
		else map->put(nums[i], i);
	}
	return tmp;
}
//测试示例
int main()
{
	std::vector<int> nums = { 2,7,11,15 };
	int target = 9;
	Solution solution;
	std::vector<int> result = solution.twoSum(nums, target);
	//迭代器遍历
	auto it = result.begin();
	while (it != result.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cin.get();
}