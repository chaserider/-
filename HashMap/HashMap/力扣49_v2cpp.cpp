#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//template<typename value >
//void Log(value message)
//{
//	std::cout <<message<< std::endl;
//}


	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> map;
		for (string& str : strs)
		{
			string count = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (auto it : str)
				count[it - 'a']++;
			map[count].push_back(str);
		}
		vector<vector<string>> result;

		for (auto it : map)
		{
			result.emplace_back(it.second);
		}
		return result;
	}


int main()
{
	std::vector<string> strs = { "eat","tea","tan","ate","nat","bat","ac","bd","aac","bbd","aacc","bbdd","acc","bdd" };
	std::vector<vector<string>> result = groupAnagrams(strs);
	//Log(result);

	std::cin.get();
}