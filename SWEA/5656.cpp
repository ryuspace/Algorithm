/* 5656번 벽돌깨기
풀이 : dfs를 이용해 구슬을 떨어뜨릴 수 있는 가능한 모든 위치를 구하고
bfs를 이용해 벽돌을 폭파시킨다. 
가능한 모든 위치를 선정한 후 벽돌을 폭파시키면 시간이 많이 걸리므로..
위치를 하나 선정할 때 마다 벽돌을 폭파시킨다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int t, n, w, h;
int arr[16][13];
//h가 행 w가 열
struct point
{
	int x, y, value;
};

void mov()
{
	for (int i = 0; i < w; i++)
	{
		vector<int> v;
		for (int j = h - 1; j >= 0; j--)
		{
			if (arr[j][i] != 0)
			{
				v.push_back(arr[j][i]);
			}
			arr[j][i] = 0;
		}
		for (int j = 0; j<v.size();j++)
		{
			arr[h - 1 - j][i] = v[j];
		}

	}
}
void play(int col)
{
	queue <point> q;
	for (int i = 0; i < h; i++)
	{
		if (arr[i][col] != 0)
		{
			q.push({ i,col,arr[i][col] });
			arr[i][col] = 0;
			break;
		}
	}
	while (!q.empty())
	{
		point front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.x;
			int ny = dy[i] + front.y;
			int value = front.value-1;
			while (nx >= 0 && nx < h && ny >= 0 && ny < w && value--)
			{
				if(arr[nx][ny]>1)
					q.push({ nx,ny,arr[nx][ny] });
				arr[nx][ny] = 0;
				nx += dx[i];
				ny += dy[i];
			}
		}
	}

}
int minn = 1e9;
void dfs(int cnt)
{
	
	if (cnt == n)
	{
		int cn = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] != 0)
					cn++;
			}
		}
		minn = min(minn, cn);
		return;
	}
	int tmp[16][13];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}

	for (int r = 0; r < w;r++)
	{
		play(r);
		mov();
		dfs(cnt + 1);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				arr[i][j] = tmp[i][j];
			}
		}
	}
}
int main()
{
	//freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		minn = 1e9;
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		dfs(0);
		cout << "#" << r << " " << minn << '\n';
	}
	return 0;
}
