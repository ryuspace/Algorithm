//https://www.acmicpc.net/problem/16920
/*풀이 : 
bfs 스킬이 부족한 것 같다.
그냥 큐를 두개 놔서 하나는 다음 turn에 기준이 되는 값들을 넣어놓으면 된다.
큐 배열 쓰는건 좀 신선했다.
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, p;
int player[1001];
int cnt[1001];
char arr[1001][1001];
bool visit[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct point
{
	int p, x, y, sizz;
};
queue<point> q[10];
queue<point> q2[10];
bool bfs(int num)
{

	q[num] = q2[num];
	bool flag = false;
	//cout << q[num].size() << '\n';
	//getchar();
	while (!q[num].empty())
	{
		point front = q[num].front();
		q[num].pop();
		if (front.sizz == player[num])
			q2[num].pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.x;
			int ny = dy[i] + front.y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == '.')
			{
				if (!visit[nx][ny])
				{
					//cout << "읭";
					visit[nx][ny] = true;
					if (front.sizz == 1)
					{
						q2[num].push({ front.p,nx,ny,player[front.p] });
					}
					else
					{
						q[num].push({ front.p,nx,ny,front.sizz - 1 });
					}
					flag = true;
					cnt[front.p]++;
				}
			}
		}

	}
	if (!flag)
	{
		return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)
	{
		cin >> player[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] >= '1' && arr[i][j] <= '9')
			{
				visit[i][j] = true;
				q2[arr[i][j] - '0'].push({ arr[i][j] - '0',i,j,min(max(n,m),player[arr[i][j] - '0']) });
				cnt[arr[i][j] - '0']++;
			}
			if (arr[i][j] == '#')
			{
				visit[i][j] = true;
			}
		}
	}

	while (true)
	{
		bool flag = false;
		for (int i = 1; i <= p; i++)
		{
			flag |= bfs(i);
		}
		if (!flag)
		{
			for (int i = 1; i <= p; i++)
			{
				cout << cnt[i] << " ";
			}
			exit(0);
		}
	}
	return 0;
}
