//https://www.acmicpc.net/problem/14528
/*풀이 : 유전자 중 3개의 위치를 뽑아 모두 탐색해본다.
set을 이용해 plain cow에 이미 나와있는 유전자인지 체크한다.*/
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
string arr[1002];


int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	int ans = 0;
	set <string> s;
	cin >> n >> m;
	
	for (int i = 0; i < 2*n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			for (int r = j + 1; r < m; r++)
			{
				s.clear();
				for (int k = 0; k < n; k++)
				{
					string tmp = "";
					tmp += arr[k][i];
					tmp += arr[k][j];
					tmp += arr[k][r];
					s.insert(tmp);
				}
				bool flag = false;
				for (int k = n; k < 2*n; k++)
				{
					string tmp = "";
					tmp += arr[k][i];
					tmp += arr[k][j];
					tmp += arr[k][r];
					if (s.count(tmp))
					{
						flag = true;
						break;
					}
				}
				if (!flag)
					ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

