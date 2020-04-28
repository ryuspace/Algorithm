//https://www.acmicpc.net/problem/2667
/*풀이 : 전형적인 bfs 문제..*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int n;
int arr[26][26];
bool visit[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector <int> v;

void bfs(int x, int y)
{
	int sum = 1;
	visit[x][y] = true;
	queue <pii> q;
	q.push({ x,y });
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (!visit[nx][ny] && arr[nx][ny] == 1 &&
				nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
				sum++;
			}
		}
	}
	v.push_back(sum);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = tmp[j] - '0';
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j] && arr[i][j]==1)
			{
				cnt++;
				bfs(i, j);
			}
		}
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (auto& i : v)
		cout << i << '\n';

	return 0;
}
