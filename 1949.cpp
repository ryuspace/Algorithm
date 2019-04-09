/*1949번 등산로 조성
풀이 : 가장 높은 지점을 미리 큐에 담아놓고 bfs를 돌리는데
산이 깎인적이 있는 경우, 없는 경우로 나눈다.
front.value는 산을 깎았으면 깎인 값을 큐에 넣어주기 위함이다. 
그 이유는 다른 곳에서 온 등산로는 깎이지 않은 상태로 보여야 하기 때문이다. 
직접적으로 map을 바꾸지 않음.
그리고 이전에 온 방향도 큐에 넣어줘서 이전에 온 방향으로는 체크하지 않게 한다.
*/
#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct point {
	int x, y,value, flag,dir;
};
int n,k;
int arr[9][9];
queue <point> q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx =  front.x + dx[i];
				int ny = front.y + dy[i];
				int nv = front.value;
				int flag = front.flag;
				int di = front.dir;
				if (nx >= 0 && nx < n&&ny >= 0 && ny < n &&di!=i)
				{
					if (front.flag == 0)
					{
						if (arr[nx][ny] >= nv)
						{
							int num = arr[nx][ny] - nv;
							if (num + 1 <= k)
							{
								q.push({ nx,ny,arr[nx][ny]-(num+1),1,(i+2)%4 });
							}
						}
						else if (arr[nx][ny] < nv)
						{
							q.push({ nx,ny,arr[nx][ny],0,(i + 2) % 4 });
						}
					}
					else if (front.flag == 1 && arr[nx][ny] < nv)
					{
						q.push({ nx,ny,arr[nx][ny],1,(i + 2) % 4 });
					}
				}
			}
		}
		cnt++;
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		queue<point> q2;
		q = q2;
		int maxx = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				maxx = max(maxx, arr[i][j]);
			}
		}
		int cntt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == maxx)
				{
					q.push({ i,j,arr[i][j],0,-1 });
					cntt++;
				}
			}
		}
		cout<<"#"<<r<<" "<<bfs()<<'\n';

	}
	return 0;

}
