//https://www.acmicpc.net/problem/3190
/*풀이 : 왼쪽 방향으로 한 번 도는건 오른쪽 방향으로 3번 돌린거랑 같다.
머리를 움직일때 마다 머리의 정보를 큐에 넣는다. 그리고 꼬리를 줄여야 할 때
큐의 가장 앞에 있는 것이 꼬리가 된다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
queue <pii>q;
vector< pair<int,char> > v;
int n, k,l;
int arr[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	arr[1][1] = 1;
	pii head = { 1,1 };
	pii tail = { 1,1 };
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 2;//사과는 2로 놓는다.
	}
	cin >> l;
	int dir = 0;
	int cntt = 1;
	for (int i = 0; i < l; i++)
	{
		int a;
		char b;
		cin >> a >> b;	
		v.push_back({ a,b });
	}
	int idx = 0;
	while (true)
	{
		arr[head.first][head.second] = 1;
		head.first += dx[dir];
		head.second += dy[dir];
		q.push(head);
		
		if (arr[head.first][head.second] == 2)
		{
			arr[head.first][head.second] = 0;
		}
		else if (arr[head.first][head.second] == 0)
		{
			pii front = q.front();
			q.pop();
			arr[tail.first][tail.second] = 0;
			tail.first = front.first;
			tail.second = front.second;
		}
		if (head.first < 1 || head.first > n || head.second < 1
			|| head.second >n ||
			arr[head.first][head.second] == 1)
		{
			cout << cntt;
			exit(0);
		}
		cntt++;
		if (idx < v.size())
		{
			if (cntt == v[idx].first + 1)
			{
				if (v[idx].second == 'D')
				{
					dir = (dir + 1) % 4;
				}
				else if (v[idx].second == 'L')
				{
					for (int r = 0; r<3; r++)
						dir = (dir + 1) % 4;
				}
				idx++;
			}
		}
	}
	return 0;
}
