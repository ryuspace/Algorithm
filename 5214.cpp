//https://www.acmicpc.net/problem/5214
/*풀이 : 연결되는 모든 경로를 다 넣으면 1000^3으로 메모리 초과가 난다.
n이상인 가짜노드를 만들어 하이퍼튜브에 연결된 노드를 넣고 bfs로 탐색해준다.
큐에 n이상인 노드가 나오면 그건 가짜노드이므로 카운트 해주지 않는다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int k, m, n;
vector<int> v[200002];
bool visit[200002];
void bfs(int start, int end)
{
	queue<pii> q;
	q.push({ start,1 });
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			if (front.first == end)
			{
				cout << front.second;
				exit(0);
			}
			for (int i = 0; i < v[front.first].size(); i++)
			{
				if (!visit[v[front.first][i]])
				{
					visit[v[front.first][i]] = true;
					if (front.first >= n + 1)
					{
						q.push({ v[front.first][i],front.second });
					}
					else
						q.push({ v[front.first][i],front.second + 1 });
						
				}
			}
		}

	}
	
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			v[i + n + 1].push_back(a);
			v[a].push_back(i + n + 1);
		}
		
	}
	bfs(1, n);
	cout << -1;
	return 0;
}
