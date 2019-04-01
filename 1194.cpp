//https://www.acmicpc.net/problem/1194
/*풀이 : 열쇠를 가진 걸 표시하기 위해 비트마스크를 사용한다.
visit 처리를 해줄때에는 이 열쇠를 가지고 지나간 적이 있는지를 체크한다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, m;
char arr[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[51][51][1<<7];
struct point
{
	pii start;
	int key;
};
point hazime;
void bfs()
{
	queue<point> q;
	q.push(hazime);
	visit[hazime.start.first][hazime.start.second][hazime.key] = true;
	int time = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		while(sizz--)
		{
			point front = q.front();
			q.pop();
			if (arr[front.start.first][front.start.second] == '1')
			{
				cout<<time;
				exit(0);
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = front.start.first + dx[i];
				int ny = front.start.second + dy[i];
				if (!visit[nx][ny][front.key] && nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny]!='#')
				{
					if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f')
					{
						int new_key = front.key | 1 << (arr[nx][ny] - 'a');
						q.push({ {nx,ny},new_key });
						visit[nx][ny][new_key] = true;
					}
					else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F')
					{
						if (front.key & 1<<(arr[nx][ny] - 'A'))
						{
							q.push({ { nx,ny },front.key });
							visit[nx][ny][front.key] = true;
						}
					}
					else 
					{
						q.push({ { nx,ny },front.key });
						visit[nx][ny][front.key] = true;
					}
				}
			}
		}
		time++;
	}
	cout << -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = tmp[j];
			if (tmp[j] == '0')
			{
				hazime = { {i,j},1<<7 };
				arr[i][j] = '.';
			}
		}
	}
	bfs();
	return 0;
}
