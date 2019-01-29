//https://www.acmicpc.net/problem/9576
/*풀이 : 첫번째 학생부터 선택되지 않은 원하는 책을 고르는데 학생들에게 책을 나눠주다가 
어떤 학생이 이미 점유된 책을 원하면 다른 학생들이 다른 책을 고를 수 있는지 물어봐서 가능하면
그 책을 다른 학생이 점유하게 한다.*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <int> v[1001];
int d[1001];
int c[1001];

bool dfs(int x)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		int t = v[x][i];
		if (c[t])
			continue;
		c[t] = true;
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	int n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i <= 1000; i++)
		{
			v[i].clear();
		}
		memset(d, 0, sizeof(d));
		memset(c, false, sizeof(c));
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			cin >> a >> b;
			for (int j = a; j <= b; j++)
			{
				v[i].push_back(j);
			}
			
		}
		int count = 0;
		for (int i = 1; i <= m; i++)
		{
			memset(c, false, sizeof(c));
			if (dfs(i))
				count++;
		}
		cout << count << '\n';;
	}
	return 0;
}
