//https://www.acmicpc.net/problem/17142/
/*풀이 :
dfs를 이용해 활성 바이러스를 선택하고 bfs를 이용해 바이러스를 퍼뜨린다.
1.바이러스의 위치를 벡터에 담아 바이러스를 활성 바이러스 m개를 고르는 과정의 시간을 줄인다.
2.빈 칸의 갯수를 미리 세어놓고 bfs를 돌릴 때 빈 칸이 0개가 되면 stop 한다.
3.바이러스를 담은 벡터의 인덱스가 넘어버리면 함수를 더 이상 실행시키지 않게 한다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int arr[51][51];
bool visit[51][51];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef pair<int, int> pii;
queue <pii> q;
int zero =0;
vector <pii> virus;

int bfs()
{
	int hi = zero;
	int time = 0;
	while (!q.empty())
	{
		if (hi == 0)
			break;
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
					arr[nx][ny] == 0 && !visit[nx][ny])
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
					hi--;

				}
				if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
					arr[nx][ny] == 2 && !visit[nx][ny])
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		time++;

	}
	if (!hi)
		return time;
	else
		return 1e9;

}
int play()
{
	while (!q.empty())
		q.pop();
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 3)
			{
				q.push({ i,j });
			}
		}
	}
	return bfs();
}
int minn = 1e9;
void dfs(int idx, int cnt)
{
	if (idx > virus.size())
		return;
	if (cnt == m)
	{
		minn = min(minn, play());
		return;
	}
	for (int i = idx; i < virus.size(); i++)
	{
		if (arr[virus[i].first][virus[i].second] == 2)
		{
			arr[virus[i].first][virus[i].second] = 3;
			dfs(i + 1, cnt + 1);
			arr[virus[i].first][virus[i].second] = 2;
		}
	}


}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				zero++;
			else if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
	//0 빈 칸, 1 벽, 2 바이러스
	dfs(0, 0);
	if (minn == 1e9)
		cout << -1;
	else
		cout << minn;
	return 0;
}
