//https://www.acmicpc.net/problem/10711
/*풀이 : 흙을 기준으로 8방향에 대해 bfs를 돌린다. 만약 숫자랑 닿으면 숫자를 하나 줄여주는데 0이 되면 흙으로 변한다. 다시 큐에 푸시.
큐에 아무것도 없을 때 까지 진행.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int h, w;
char arr[1001][1001];
char brr[1001][1001];
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
queue<pii> q;
void bfs()
{
	int before = q.size();
	int hi = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			int cnt = 0;
			for (int i = 0; i < 8; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < h && ny >= 0 && ny < w)
				{
					if (arr[nx][ny] >= '1' && arr[nx][ny] <= '9')
					{
						arr[nx][ny]--;
						if (arr[nx][ny] == '0')
						{
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		hi++;
	}
	cout << hi - 1;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '.')
				q.push({ i,j });
		}
	}
	bfs();

	return 0;
}
