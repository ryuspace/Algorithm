/*4112. 이상한 피라미드 탐험
백준의 과외맨과 문제가 비슷했다. 우선 피라미드를 전부 왼쪽으로 몰아 넣은다고
생각하면
ㅇ
ㅇㅇ
ㅇㅇㅇ
ㅇㅇㅇㅇ
이런 모양이 되는데 여기서 한 점을 기준으로 갈 수 있는 곳은
북쪽 동쪽 남동쪽 남쪽 서쪽 북서쪽 이렇게 6개의 방향이다.
1부터 10000까지 미리 배열에 모양대로 선언해 놓고 bfs를 돌린다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int arr[181][181];
pii point[100001];
int dx[6] = { -1,-1,0,0,1,1 };
int dy[6] = { -1,0,-1,1,0,1 };
int bfs(pii start, pii des)
{
	bool visit[201][201] = { 0, };
	int cnt = 0;
	queue<pii> q;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			if (arr[front.first][front.second] == arr[des.first][des.second])
			{
				return cnt;
			}
			for (int i = 0; i < 6; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 1 && nx <= 181 && ny >= 1 && ny <= 181 && !visit[nx][ny] && arr[nx][ny] != 0)
				{
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
		cnt++;
	}
}

int main(void)
{
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x = 1;
	int y = 1;
	int cnt = 0;
	int gi = 1;
	for (int i = 1; i <= 10000; i++)
	{
		arr[x][y] = i;
		point[i] = make_pair(x, y);
		cnt++;
		if (cnt == gi)
		{
			x++;
			y=1;
			cnt = 0;
			gi++;
		}
		else
			y++;
	}
	int t;
	cin >> t;
	for(int r=1;r<=t;r++)
	{
		int a, b;
		cin >> a >> b;
		pii start = point[a];
		pii des = point[b];
		cout << "#" << r << " " << bfs(start, des) << '\n';;
	}
	return 0;
}
