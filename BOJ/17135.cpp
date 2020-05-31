//https://www.acmicpc.net/problem/17135
/*풀이 : dfs를 이용해 궁수 위치 선택.
bfs를 이용해 모든 궁수가 잡을 수 있는 적을 찾는다.
처음엔 상하좌우 방문해서 sort 열 오름차순으로 했는데 방향 접근을 서쪽 북쪽 동쪽으로 하면 그런 과정이 필요가 없어진다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

int n, m, d;
int arr[18][18];
int arr2[18][18];
bool visit[18];
bool check[18][18];
bool victim[18][18];

int maxi;
vector<pii> gung;

int dx[4] = { 0,-1,0 };
int dy[4] = { -1,0 ,1};


void mapDown()
{
	for (int i = n-2;i>=0;i--)
	{
		for (int j = 0;j < m;j++)
		{
			arr[i + 1][j] = arr[i][j];
		}
	}
	for (int j = 0;j < m;j++)
	{
		arr[0][j] = 0;
	}
}

void bfs(pii start)
{
	memset(check, 0, sizeof(check));
	int cnt = 0;
	queue<pii> q;
	vector<pii> hubo;
	q.push(start);
	check[start.first][start.second] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			for (int i = 0;i < 3;i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !check[nx][ny])
				{
					if (arr[nx][ny] == 1)
					{
						victim[nx][ny] = true;
						return;
					}
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		cnt++;
		if (cnt == d)
			break;
	
	}
}

bool isPossible()
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (arr[i][j] == 1)
				return false;
		}
	}
	return true;
}

int play()
{
	int sum = 0;
	while (!isPossible())
	{
		for (int i = 0;i < 3;i++)
		{
			bfs(gung[i]);
		}

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (victim[i][j])
				{
					arr[i][j] = 0;
					sum++;
					victim[i][j] = false;
				}
			}
		}
		mapDown();
	}
	return sum;

}

void dfs(int idx,int cnt) //궁수 위치 선택
{
	if (cnt == 3)
	{
		maxi=max(maxi,play());
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				arr[i][j] = arr2[i][j];
			}
		}
		return;
	}
	if (idx >= m)
		return;

	gung.push_back({ n, idx });
	dfs(idx + 1, cnt + 1);
	gung.pop_back();
	dfs(idx + 1, cnt);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> d;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}
	dfs(0,0);
	cout << maxi;
	return 0;
}
