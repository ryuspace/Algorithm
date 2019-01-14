//https://codeforces.com/contest/1100/problem/A
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[101];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, k;
	cin >> n >> k;
	int c = 0;
	int s_c = 0;
	int Max = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (arr[i] == 1)
		{
			c++;
		}
		else
		{
			s_c++;
		}
	}
	int tmp_c = c;
	int tmp_s_c = s_c;
	for (int i = 1; i <= k; i++)
	{
		for (int j =i; j <= n; j=j+k)
		{
			if (arr[j] == 1)
			{
				tmp_c--;
			}
			else
			{
				tmp_s_c--;
			}
		}
		Max = max(abs(tmp_c - tmp_s_c), Max);
		tmp_c = c;
		tmp_s_c = s_c;
	}
	cout << Max;
	return 0;
}
