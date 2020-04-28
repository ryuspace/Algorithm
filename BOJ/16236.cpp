//https://www.acmicpc.net/problem/16236
/*풀이 : 먹이를 발견할 때 그 탐색시간을 결과값에 계속 더해준다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

int arr[21][21];
bool visit[21][21];
int baby_size = 2;
int eat_cnt = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n;
int time = 0;
int res = 0;
void bfs(pii start)
{
	vector <pii> v;
	queue <pii> q;
	visit[start.first][start.second] = true;
	q.push(start);

	while (!q.empty())
	{
		time++;
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			int sizz = q.size();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n
					&&arr[nx][ny] <= baby_size
					&& visit[nx][ny] == false)
					//크지만 않으면 지나갈 수 있다.
				{
					visit[nx][ny] = true;
					if (arr[nx][ny] != 0 && arr[nx][ny] < baby_size)
					{
						v.push_back({ nx,ny });
					}
					q.push({ nx,ny });
				}

			}
		}
		if (v.size() != 0)
		{
			res += time;
			time = 0;
			sort(v.begin(), v.end());
			arr[v[0].first][v[0].second] = 0;

			eat_cnt++;
			if (eat_cnt == baby_size)
			{
				baby_size++;
				eat_cnt = 0;
			}
			while (!q.empty())
				q.pop();
			q.push({ v[0].first,v[0].second });
			memset(visit, false, sizeof(visit));
			visit[v[0].first][v[0].second] = true;
			v.clear();
		}

	}
}
int main()
{
	pii baby;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				baby = { i,j };
				arr[i][j] = 0;
			}
		}
	}
	bfs({ baby.first,baby.second });
	cout << res;

	return 0;
}

