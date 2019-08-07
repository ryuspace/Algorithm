//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int k;
char bu[10];
bool visit[11];
vector<string> v;
void dfs(int cnt,string tmp)
{
	if (cnt == k)
	{
		v.push_back(tmp);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!visit[i])
		{
			if (bu[cnt] == '<' && tmp[cnt]-'0'<i)
			{
				visit[i] = true;
				dfs(cnt + 1, tmp + to_string(i));
				visit[i] = false;
			}
			else if(bu[cnt]=='>' && tmp[cnt] - '0' > i)
			{
				visit[i] = true;
				dfs(cnt + 1, tmp + to_string(i));
				visit[i] = false;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> bu[i];

	for (int i = 0; i < 10; i++)
	{
		visit[i] = true;
		dfs(0,to_string(i));
		visit[i] = false;
	}
	sort(v.begin(), v.end());
	cout << v[v.size() - 1] << '\n' << v[0];
	
	return 0;
}

