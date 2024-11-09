#include <iostream>
#include<bitset>
using namespace std;
int minChanges(int n, int k)
{
	int sum = 0;//记录最大次数

	bitset<31> bitn = n;
	bitset<31> bitk = k;
	bitk = n ^ k;
	for (int i = 0; i < 31; i++)
	{
		if (!bitk.test(i))
			continue;
		else if (!bitn.test(i))
			return -1;
		else sum++;
	}
	return sum;
}



int main()
{
	int n = 13;
	int k = 4;

	minChanges(n, k);
	return 0;
}