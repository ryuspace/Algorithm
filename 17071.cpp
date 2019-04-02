//https://www.acmicpc.net/problem/17071
/*풀이 : 수빈이는 2초 뒤에 제자리에 다시 올 수 있다.
그러므로 방문처리를 홀짝을 나눠서 한다.
종료 조건 : 1.같은 시간이 지났는데 동생과 수빈이의 위치가 같다
            2.홀짝번째 시간이 같은 가정하에, 동생이 이 위치에 왔을 때 수빈이가 이미 온 적이 있다.
홀짝번째 시간에 이미 수빈이가 방문한 적 있으면 큐에 넣지 않는다.*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
bool visit[500001][2];//홀짝 이동
int maxx = 500000;
void bfs(int n, int k)
{
	queue<int> q;
	int cnt = 0;
	int subin = n;
	int dong = k;
	if (subin == dong)
	{
		cout << 0;
		exit(0);
	}
	visit[subin][cnt %2] = true;
	q.push(subin);
	while (!q.empty())
	{
		cnt++;
		dong += cnt;
		if (dong > maxx)
			break;
		int sizz = q.size();
		while (sizz--)
		{
			int front = q.front();
			q.pop();
			if (dong == front-1 || dong == front+1 || dong ==front*2)
			{
				cout << cnt;
				exit(0);
			}
			if (front - 1 >= 0 && !visit[front - 1][(cnt) % 2])
			{
				q.push(front - 1);
				visit[front - 1][cnt % 2] = true;
			}
			if (front + 1 <= maxx && !visit[front + 1][(cnt) % 2])
			{
				q.push(front + 1);
				visit[front + 1][cnt % 2] = true;
			}
			if (front * 2 <= maxx && !visit[front * 2][(cnt) % 2])
			{
				q.push(2 * front);
				visit[2 * front][cnt % 2] = true;
			}

		}	
		if (visit[dong][cnt % 2])
		{
			cout << cnt;
			exit(0);
		}
	}
	cout << -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	bfs(n, k);
	return 0;
}
