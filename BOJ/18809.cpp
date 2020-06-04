//https://www.acmicpc.net/problem/18809
/*풀이 :
dfs를 돌려 빨간색 배양액과 초록색 배양액의 가능한 모든 조합을 구한다.
그리고 bfs를 돌리는데 방문 처리를 방문한 시간으로 처리해서 현재 방문한 시간에 각자 다른 배양액을 넣는 경우를 찾아준다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int arr[51][51];
int n, m, g, r;
vector<pii> v;
bool visit[11];



struct point {
	int x, y, color;
};

vector<point> vec;
queue<point> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

pii visit2[51][51];
int bfs()
{
	int flower = 0;
	memset(visit2, 0, sizeof(visit2));
	int cnt = 1;
	for (int i = 0;i < vec.size();i++)
	{
		q.push({ vec[i].x,vec[i].y,vec[i].color });
		visit2[vec[i].x][vec[i].y] = { cnt,vec[i].color };
	}

	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if (visit2[front.x][front.y].second == 7)
			{
				continue;
			}
			for (int i = 0;i < 4;i++)
			{
				int nx = dx[i] + front.x;
				int ny = dy[i] + front.y;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 0)
				{
					if (visit2[nx][ny].first==0)
					{
						visit2[nx][ny].first = cnt + 1;
						visit2[nx][ny].second = front.color;
						q.push({ nx,ny,front.color });
					}
					else if (visit2[nx][ny].first == cnt + 1)
					{
						if (visit2[nx][ny].second == 3 && front.color == 4)
						{
							visit2[nx][ny].second = 7;
							flower++;
						}
						else if (visit2[nx][ny].second == 4 && front.color == 3)
						{
							visit2[nx][ny].second = 7;
							flower++;
						}
					}
				}
			}
		}
		cnt++;
	}

	return flower;
}
int maxi;
void dfs(int idx,int red, int green)
{
	if (red+green==0)
	{
		maxi = max(maxi, bfs());
		return;
	}

	for (int i = idx;i < v.size();i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			if (red >= 1)
			{
				arr[v[i].first][v[i].second] = 3;
				vec.push_back({ v[i].first,v[i].second,3 });
				dfs(i+1, red - 1, green);
				arr[v[i].first][v[i].second] = 2;
				vec.pop_back();

			}
			if (green >= 1)
			{
				arr[v[i].first][v[i].second] = 4;
				vec.push_back({ v[i].first,v[i].second,4 });
				dfs(i+1, red, green - 1);
				arr[v[i].first][v[i].second] = 2;
				vec.pop_back();
			}
			visit[i] = false;
		}
	}
}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> g >> r;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				v.push_back({ i,j });
		}
	}
	dfs(0, r, g);
	cout << maxi;
	return 0;
}
