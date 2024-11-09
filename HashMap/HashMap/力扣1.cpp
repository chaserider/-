
#include "HashMap_V1.cpp"
//������ϣ���������е�ÿ��ֵ���Ӧ��ϣ����
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
//����ʾ��
int main()
{
	std::vector<int> nums = { 2,7,11,15 };
	int target = 9;
	Solution solution;
	std::vector<int> result = solution.twoSum(nums, target);
	//����������
	auto it = result.begin();
	while (it != result.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cin.get();
}