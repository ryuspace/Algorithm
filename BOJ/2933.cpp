//https://www.acmicpc.net/problem/2933
/*풀이 :한 칸씩 없어지니까 여러 조각 조각이 우수수 떨어지는건 불가능.
클러스터 하나가 떨어질 수 밖에 없다. 원래 다 이어졌으니까 
핵심 : 맨 아래 첫번째 줄을 bfs 돌리면 밑에 큰 클러스터가 인식이 된다. 방문되지
않은 'x'는 클러스터가 아님. 밑으로 떨어뜨려야 한다. 합칠때는 미네랄과 클러스터의
열의 차이의 최소만큼 갈 수 있다. 어려웠다!!*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

char arr[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int r, c;

void bfs(pii start)
{
	queue<pii> q;
	q.push({ start.first,start.second });
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c
				&&visit[nx][ny] == false && arr[nx][ny] == 'x')
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}
void Union()//땅바닥 부터 시작해서 클러스터를 찾자 ☆ 여기서 안 찾아진 애들은 따로 노는애들
{

	memset(visit, false, sizeof(visit));
	for (int i = 0; i < c; i++)
	{
		if (visit[r - 1][i] == false && arr[r - 1][i] == 'x')
		{
			bfs({ r - 1,i });
		}
	}
	int down = 1e9;
	for (int i = 0; i <c; i++)
	{
		for (int j = r-1; j>=0; j--)
		{
			if (arr[j][i] == 'x' && visit[j][i] == false)
			{
				int now = j+1;
				while (arr[now][i] == '.' && now <r)
				{
					now++;
				}
				down = min(now -j-1, down);//얼마나 내려가야하는지.
				break;

			}
		}
	}
	for (int i = r - 1; i >= 0; i--)
	{
		for (int j = 0; j <c; j++)
		{
			if (i + down<r && down != 0 && arr[i][j] == 'x' && visit[i][j] == false)
			{

				arr[i + down][j] = 'x';
				arr[i][j] = '.';

			}
		}
	}


}
void destroy(int num, int turn)
{

	if (turn == 0)
	{
		int y = 0;
		while (arr[num][y] != 'x' && y<c)
		{
			y++;
		}
		if (y != c)//부딪혔었다.
		{
			arr[num][y] = '.';
			Union();
		}
	}
	else
	{
		int y = c - 1;
		while (arr[num][y] != 'x' && y >= 0)
		{
			y--;
		}
		if (y != -1)//부딪혔었다.
		{
			arr[num][y] = '.';
			Union();
		}
	}

}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		if (i % 2 == 0)//창영
		{
			destroy(r - a, 0);
		}
		else//상근
		{
			destroy(r - a, 1);
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}
