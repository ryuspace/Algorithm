//https://www.acmicpc.net/problem/9205
/*풀이 : bfs를 돌려 현재 위치에서 갈 수 있는 편의점을 큐에 푸쉬해주고 목적지 까지 갈 수 있는지 체크한다.
이미 방문된 편의점임을 표시하는 변수도 하나 선언해준다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
struct point
{
	int x, y;
	bool flag = false;
};
point store[101];
pii start;
pii des;
int store_cnt;

bool check(int now_x,int now_y,int x,int y)
{
	if (abs(now_x - x) + abs(now_y- y) <=1049)
		return 1;
	return 0;
}
void bfs()
{
	queue<point> q;
	q.push({ start.first,start.second,0 });
	while (!q.empty())
	{
		point front = q.front();
		q.pop();
		if (front.x == des.first && front.y == des.second ||
			check(front.x,front.y,des.first,des.second))
		{
			cout << "happy" << '\n';
			return;
		}
		for (int i = 0; i < store_cnt; i++)
		{
			if (!store[i].flag && check(front.x, front.y, store[i].x, store[i].y))
			{
				store[i].flag = 1;
				q.push({ store[i].x,store[i].y,1 });
			}
		}
	}
	cout << "sad" << '\n';
}
int main(void)
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> store_cnt;
		cin >> start.first >> start.second;
		for (int i = 0; i < store_cnt; i++)
		{
			cin >> store[i].x >> store[i].y;
			store[i].flag = false;
		}
		cin >> des.first >> des.second;
		bfs();
	}

	return 0;
}
