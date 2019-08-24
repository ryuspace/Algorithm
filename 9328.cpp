//https://www.acmicpc.net/problem/9328
/*풀이 : 문제가 굉장히 불친절 헀다. 한번의 경로로 해결하는 게 아니라. 열쇠 얻고 나와서 다른 가장자리로도 들어갈 수 있다..
열쇠를 못 얻을 때 까지 bfs를 계속 돌려준다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int t,h,w;
char arr[101][101];
bool visit[101][101];
bool key[27];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
int key_cnt = 0;
void bfs(pii start)
{
	queue<pii> q;
	visit[start.first][start.second] = true;
	q.push(start);
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		if (arr[front.first][front.second] == '$'){
			arr[front.first][front.second] = '.';
			cnt++;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx < h && ny >= 0 && ny < w 
				&& !visit[nx][ny] && arr[nx][ny] != '*')
			{
				if ((arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z' &&
					key[arr[nx][ny]-'A']))
				{
					arr[nx][ny] = '.';
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
				else if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z')
				{
					visit[nx][ny] = true;
					key[arr[nx][ny] - 'a'] = true;
					key_cnt++;
					arr[nx][ny] = '.';
					q.push({ nx,ny });
				}
				else if(arr[nx][ny]=='.' || arr[nx][ny]=='$')
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main(void)
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;

	for (int r = 0; r < t; r++)
	{
		cnt = 0;
		memset(key, 0, sizeof(key));
		memset(visit, 0, sizeof(visit));
		key_cnt = 0;
		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		string tmp;
		cin >> tmp;
		if (!(tmp[0] - '0' == 0))
		{
			for (int i = 0; i < tmp.length(); i++)
			{
				key[tmp[i] - 'a'] = true;
				key_cnt++;
			}
		}
		int now;
		do
		{

			memset(visit, 0, sizeof(visit));
			now= key_cnt;
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					if (!visit[i][j] && (i == 0 || j == 0 || i == h - 1 || j == w - 1))
					{

						if ((arr[i][j] >= 'A' && arr[i][j] <= 'Z' &&
							key[arr[i][j]-'A']))
						{
							arr[i][j] = '.';
							bfs({ i,j });
						}
						else if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
						{
							key[arr[i][j] - 'a'] = true;
							key_cnt++;
							arr[i][j] = '.';
							bfs({ i,j });
						}
						else if (arr[i][j] == '.' || arr[i][j] == '$')
						{
							bfs({ i,j });
						}
					}
				}
			}


		} while (now != key_cnt);
		
		cout << cnt << '\n';
	}
	return 0;
}
