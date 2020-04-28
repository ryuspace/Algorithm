//https://www.acmicpc.net/problem/1800
/*풀이 :
벽 부수고 이동하기 문제랑 비슷하다.
visit 처리는 몇 개의 인터넷을 공짜로 설치했는데 그 때 까지의 가장 비싼 인터넷 값이다.
visit 처리가 조금 까다로웠다. 자세한 건 주석
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int n, k, p;
vector<pii> v[1001];
int visit[1001][1001];
struct point
{
	int num, gap, gong;
};
queue<point> q;
void bfs()
{
	while (!q.empty())
	{
		point front = q.front();
		q.pop();
		for (int i = 0; i < v[front.num].size(); i++)
		{
			if (visit[v[front.num][i].first][front.gong] > max(visit[front.num][front.gong],v[front.num][i].second))//공짜로 설치 안 할건데 이번에 온 경우가 더 작으면 무조건 값 바꾸기
			{
				visit[v[front.num][i].first][front.gong] = max(visit[front.num][front.gong], v[front.num][i].second);
				q.push({ v[front.num][i].first ,v[front.num][i].second ,front.gong});
			}
			if (front.gong <k && visit[v[front.num][i].first][front.gong + 1] > visit[front.num][front.gong])//공짜 설치 찬스 한 번 쓰려고 하는데 나의 이전까지의 가장 비싼 선 값이 현재 선 값 보다 당연히 싸야지
			{
				visit[v[front.num][i].first][front.gong+1] = visit[front.num][front.gong];
				q.push({ v[front.num][i].first ,v[front.num][i].second,front.gong+1 });
			}
		}
	}
	
	if (visit[n][k]==1e9)
	{
		cout << -1;
	}
	else
	{
		cout << visit[n][k];
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> p >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			visit[i][j] = 1e9;
		}
	}
	if (k >= p)//그냥 다 공짜 설치 가능
	{
		cout << 0;
		exit(0);
	}
	for (int i = 0; i < p; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	q.push({ 1,0,0 });
	visit[1][0] = 0;
	bfs();
	return 0;
}
