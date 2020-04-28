/*풀이 : 처음에 dfs를 이용해 이미 방문한 곳은 다시 재귀호출 안하게 했지만 
N이 워낙 크다보니깐 메모리 초과가 났다.
만약 어떤 지점에서 한번에 다른 지점으로 가는 경로가 있으면(무조건 도착을 가정!)
그 지점으로부터 거꾸로 bfs를 돌려 카운트를 세준다!
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[200001];
int arr[200001];
queue<int> q;
int ans[200001];
bool visit[200001];
void bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (int i = 0; i < v[front].size(); i++)
		{
			if (!visit[v[front][i]])
			{
				visit[v[front][i]] = true;
				q.push(v[front][i]);
				ans[v[front][i]] = ans[front] + 1;
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		ans[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (i - arr[i] >= 0)
		{
			v[i - arr[i]].push_back(i);
			if ((arr[i] % 2) != (arr[i - arr[i]] % 2))
			{
				ans[i] = 1;
			}
		}
		if (arr[i] + i < n)
		{
			v[i + arr[i]].push_back(i);
			if ((arr[i] % 2) != (arr[i + arr[i]] % 2))
			{
				ans[i] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 1)
		{
			q.push(i);
			visit[i] = true;
		}
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
