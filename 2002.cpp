//https://www.acmicpc.net/problem/2002
/*풀이 : 
추월된 등수를 반영했을 때 차가 분명히 앞질렀으면 추월한 것이다.
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
int cnt = 0;
map<string, int> m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		m[tmp] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		if (m[tmp]>i)
		{
			map<string, int> ::iterator iter;
			for (iter = m.begin(); iter != m.end(); iter++)//현재 내가 갈 등수 보다 크고 기존에 내 등수보다 작은 애들은 추월당한다. 
			{
				if (iter->second>=i && m[tmp]>iter->second)//하나씩 밀린다.
				{
					m[iter->first]++;
					
				}
			}
			cnt++;
			m[tmp] = i;
		}
	}
	cout << cnt;
	return 0;
}
