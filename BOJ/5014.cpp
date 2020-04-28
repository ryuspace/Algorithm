//https://www.acmicpc.net/problem/5014
/*풀이 : bfs를 이용하여 목적지까지 도착하는 최단경로를 찾는다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int f, s, g, u, d;
bool visit[1000001];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;
	int cnt = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			int num = q.front();
			q.pop();
			if (num == g)
			{
				cout << cnt;
				exit(0);
			}
			int next[2] = { num + u,num - d };
			for (int i = 0; i < 2; i++)
			{
				if (!visit[next[i]] && next[i] >= 1 && next[i] <= f)
				{
					q.push(next[i]);
					visit[next[i]] = true;
				}
			}
		}
		cnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> f >>s >> g >> u >> d;
	bfs(s);
	cout << "use the stairs";
	return 0;
}
