//https://www.acmicpc.net/problem/4485
/*풀이 : 현재 위치에서 왼쪽 오른쪽 위 아래의 비용에 현재 위치 비용 더한게 여태까지 현재 위치의
비용보다 적으면 값을 저장하는 배열의 값을 갱신해준다. */
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int arr[126][126];
int dist[126][126];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dikstra(int n)
{
	priority_queue< pair< int, pair<int, int>  >, vector< pair< int, pair<int, int>  > >, greater< pair< int, pair<int, int>  > > > q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = 1e9;
		}
	}

	dist[0][0] = arr[0][0];

	q.push({ arr[0][0],{0,0} });

	while (!q.empty())
	{
		int cost = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		if (dist[x][y] < cost)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1 && dist[nx][ny]>cost+arr[nx][ny])
			{
				dist[nx][ny] = cost + arr[nx][ny];
				q.push({ dist[nx][ny],{nx,ny} });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	int cnt = 1;
	cin >> n;
	while (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		dikstra(n);
		cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << '\n';
		cin >> n;
		cnt++;
	}
	return 0;
}
