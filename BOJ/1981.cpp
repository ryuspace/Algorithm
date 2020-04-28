//https://www.acmicpc.net/problem/1981
/*풀이 : 이런 유형을 접해본적이 없어서 힌트를 얻었다.
우선 배열을 쭉 돌아서 가장 큰 수와 가장 작은 수를 구한다.
그 둘의 차이는 최악의 경우 벌어지는 차이일 것이다.
그리고 1,1와 n,n의 차이를 left로 둔다. 이 둘은 반드시 거쳐야 하므로 
적어도 이 둘의 차이 이상의 값이 나올것이다.
그래서 구한 left와 right로 이분탐색을 진행하고,
배열의 최솟값 부터 최댓값 까지 쭉 탐색하는데 만약 그 수를 a라고 하면
a부터 a+mid까지 숫자가 배열에 있으면 체크를 해주고 그 체크해 준 숫자를 통한 경로가
생성되는지 체크한다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
bool visit[101][101];
int arr[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;
int min_val = 1e9;
int max_val = 0;

bool bfs(int mid)
{
	for (int r = min_val; r <= max_val - mid; r++)
	{
		memset(visit, 0, sizeof(visit));
		//r부터 r+mid 까지만 체크

		if (arr[0][0] >=r && arr[0][0]<=r+mid)
		{
			queue<pii> q;
			q.push({ 0,0 });
			visit[0][0] = true;
			while (!q.empty())
			{
				pii front = q.front();
				q.pop();
				if (front.first == n - 1 && front.second == n - 1)
					return true;
				for (int i = 0; i < 4; i++)
				{
					int nx = dx[i] + front.first;
					int ny = dy[i] + front.second;
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] 
						&& arr[nx][ny] >= r && arr[nx][ny] <= r + mid)
					{
						q.push({ nx,ny });
						visit[nx][ny] = true;
					}
				}
			}
		}
	}
	return false;
}
int main(void)
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			min_val = min(min_val, arr[i][j]);
			max_val = max(max_val, arr[i][j]);
		}
	}
	//차이는 0~(max_val-min_val)
	int left = (arr[n-1][n-1]-arr[0][0]);
	int right = max_val - min_val;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (bfs(mid))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left;
	return 0;
}
