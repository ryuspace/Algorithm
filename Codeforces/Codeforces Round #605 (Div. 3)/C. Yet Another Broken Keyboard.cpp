#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool visit[27] = { 0, };
	long long int sum = 0;
	long long int real = 0;
	int n, k;
	cin >> n >> k;
	string tmp;
	cin >> tmp;
	for (int i = 0; i < k; i++)
	{
		char a;
		cin >> a;
		visit[a - 'a'] = true;
	}
	int idx = 0;
	while (idx < tmp.length())
	{
		if (visit[tmp[idx] - 'a'])
		{
			sum++;
		}
		else
		{
			if (sum != 0)
			{
				real += sum * (sum + 1) / 2;
				sum = 0;
			}
 
		}
		idx++;
	}
	if (sum != 0)
	{
		real += sum * (sum + 1) / 2;
		sum = 0;
	}
	cout << real << '\n';
 
	return 0;
}
