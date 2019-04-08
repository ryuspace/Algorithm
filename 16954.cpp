//https://www.acmicpc.net/problem/16954
/*풀이 : bfs를 이용해 우선 9방향을 탐색해 벽이 아닌 곳을 가본다.
만약 갔는데 벽이 나중에 내려오면 continue 해준다.
서로 같은 시간대에 같은 위치에 가는 경우를 방지하기 위해 visit 처리를 매 count마다 새로 해준다.*/
#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;
char arr[8][8];
bool visit[8][8];

int dx[9] = { -1,1,0,0,-1,-1,1,1,0 };
int dy[9] = { 0,0,-1,1,-1,1,-1,1,0 };

void movv()
{
	for (int i = 7; i >= 1; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = arr[i - 1][j];
			arr[i - 1][j] = '.';
		}
	}
}

bool bfs()
{
	int cnt = 0;
	queue<pii> q;
	q.push({ 7,0 });
	while (!q.empty())
	{
		memset(visit, 0, sizeof(visit));
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			if (arr[front.first][front.second] == '#')
			{
				continue;
			}
			if (front.first == 0 && front.second == 7)
				return true;
			for (int i = 0; i < 9; i++)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8&&arr[nx][ny]!='#' &&
					!visit[nx][ny])
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		movv();
		cnt++;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << bfs();
	return 0;

}
