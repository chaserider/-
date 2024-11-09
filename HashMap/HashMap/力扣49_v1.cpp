//利用排序确定每个字符串的key

#include "HashMap_V1.cpp"
#include <string>
#include <algorithm>
using namespace std;

void Log(string message)
{
	std::cout << message << std::endl;
}


vector<vector<string>> groupAnagrams(std::vector<string>& strs) {
	auto it = strs.begin();
	vector<string>  cash;
	while (it!= strs.end())
	{
		string tmp = *it;
		sort(tmp.begin(), tmp.end());
		cash.push_back(tmp);
		//Log(tmp);
		it++;
	}

	vector<vector<string>> result;
	unordered_map<string, vector<string>> *map=new unordered_map<string, vector<string>>();
	for (int i = 0; i < strs.size(); i++)
	{
		size_t index = map->getIndex(cash[i]);
		node<string,vector<string>>* temp = map->map[index];
		node<string, vector<string>>* prenode= temp;
		while(temp!=nullptr)
		{
			if (temp->key == cash[i])
			{
				temp->val.push_back(strs[i]);
				(map->cnt)++;
				break;
			}
			prenode = temp;
			temp = temp->next;
		}
		if (temp == nullptr) {
			vector<string> str;
			str.push_back(strs[i]);
			node<string, vector<string>> *p= new node<string, vector<string>>(cash[i], str);
			if (prenode != nullptr)
				prenode->next = p;
			else
				map->map[index] = p;
			(map->cnt)++;
		}

	}

	for (int i=0; i<map->capacity; i++)
	{
		node<string, vector<string>>* p = map->map[i]; 
		while (p != nullptr)
		{
			vector<string> value = p->val;
			result.push_back(value);
			p = p->next;
		}
	}
	return result;
}

int main()
{
	std::vector<string> strs = { "eat","tea","tan","ate","nat","bat","ac","bd","aac","bbd","aacc","bbdd","acc","bdd" };
	std::vector<vector<string>> result =groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++)
	{
		auto it = result[i].begin();
		while (it!=result[i].end())
		{
			Log(*it);
			it++;
		}
		Log("======");
	}
	std::cin.get();
}