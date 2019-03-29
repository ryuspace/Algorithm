//https://www.acmicpc.net/problem/11559
/*풀이 : bfs를 이용해 조건에 맞는 터뜨릴 수 있는 블럭들을 터뜨린다.
맵의 전체를 탐색하면서 bfs를 돌린다.
맵이 바뀌면 또 맵의 전체를 탐색하면서 bfs를 돌린다. 이 횟수가 답.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
char arr[13][7];
char tmp[13][7];
bool visit[13][7];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (tmp[i][j] != arr[i][j])
				return false;
		}
	}
	return true;
}
void bfs1(pii start)
{
	memset(visit, false, sizeof(visit));
	int cnt = 1;
	char num = arr[start.first][start.second];
	visit[start.first][start.second] = true;
	queue<pii> q;
	vector <pii> v;
	q.push({ start.first,start.second });
	v.push_back({ start.first,start.second });
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && !visit[nx][ny] && arr[nx][ny] == num)
			{
				cnt++;
				q.push({ nx,ny });
				v.push_back({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	if (cnt >= 4)
	{
		for (auto&i : v)
		{
			arr[i.first][i.second] = '.';
		}
	}
}
void move()
{
	for (int i = 0; i < 6; i++)
	{
		int idx = 11;
		int start = 11;
		while (idx >= 0 && start >= 0)
		{
			if (arr[start][i] != '.')
			{
				arr[idx][i] = arr[start][i];
				if (idx != start)
					arr[start][i] = '.';
				idx--;
			}
			start--;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	while (true)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				tmp[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (arr[i][j] != '.')
				{
					bfs1({ i,j });
				}
			}
		}
		if (check())
			break;
		move();
		ans++;
	}
	cout << ans;
	return 0;
}
