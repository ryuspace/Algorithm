//https://www.acmicpc.net/problem/14453
/*풀이 : 벡터에 이길 수 있는 경우의 문자를 넣고 그 넣은 벡터에 대해 왼쪽 오른쪽을 나눠 숫자를 센다. 그 값들을 배열에 넣고 각각의 위치에 대해 왼쪽의
최대값 오른쪽의 최대값을 구한다*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
int l_rcs[100001][3];
int r_rcs[100001][3];
vector <char> v;
int all_cnt[3];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'P')
		{
			v.push_back('S');
			all_cnt[1]++;
			if (i + 1 < n)
			{
				l_rcs[i + 1][0] = l_rcs[i][0];
				l_rcs[i + 1][1] = l_rcs[i][1];
				l_rcs[i + 1][2] = l_rcs[i][2];
				++l_rcs[i + 1][1];

			}
		}
		else if (c == 'H')
		{
			v.push_back('P');
			all_cnt[0]++;
			if (i + 1 < n)
			{
				l_rcs[i + 1][0] = l_rcs[i][0];
				l_rcs[i + 1][1] = l_rcs[i][1];
				l_rcs[i + 1][2] = l_rcs[i][2];
				++l_rcs[i + 1][0];

			}
		}
		else if (c == 'S')
		{
			v.push_back('H');
			all_cnt[2]++;
			if (i + 1 < n)
			{
				l_rcs[i + 1][0] = l_rcs[i][0];
				l_rcs[i + 1][1] = l_rcs[i][1];
				l_rcs[i + 1][2] = l_rcs[i][2];
				++l_rcs[i + 1][2];
			}
		}
	}
	r_rcs[0][0] = all_cnt[0];
	r_rcs[0][1] = all_cnt[1];
	r_rcs[0][2] = all_cnt[2];
	for (int i = 0; i < n; i++)
	{
		if (i + 1 < n)
		{
			r_rcs[i + 1][0] = all_cnt[0] - l_rcs[i + 1][0];
			r_rcs[i + 1][1] = all_cnt[1] - l_rcs[i + 1][1];
			r_rcs[i + 1][2] = all_cnt[2] - l_rcs[i + 1][2];
		}
	}

	int l_max = 0;
	int r_max = 0;
	int sum_max = 0;
	for (int i = 0; i < n; i++)
	{
		l_max = 0;
		r_max = 0;
		for (int j = 0; j < 3; j++)
		{
			l_max = max(l_max, l_rcs[i][j]);
			r_max = max(r_max, r_rcs[i][j]);
		}
		sum_max = max(sum_max, l_max + r_max);
	}
	cout << sum_max;
	return 0;
}
