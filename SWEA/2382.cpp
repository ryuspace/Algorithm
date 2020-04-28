/*2382번 미생물 격리
풀이 : 시뮬레이션..어떤 한 공간에 여러미생물이 몰릴 때
그 몰리는 미생물 중 군집이 큰 애의 방향으로 선택되는거 주의!
위치가 다들 다르므로 같은 위치의 약품처리에 있는 애들끼리 겹칠 일은 없다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int t, n, m, k;
int dx[4] = { -1,0,1,0 };//상좌하우
int dy[4] = { 0,-1,0,1 };
pii arr[102][102];
pii nex[102][102];
bool visit[102][102];
vector<pii> v;
vector<pii> v2;
vector<int> ho[102][102];

void check(int x, int y)
{
	int real_x = x;
	int real_y = y;
	x += dx[arr[real_x][real_y].second];
	y += dy[arr[real_x][real_y].second];
	if (x==0 || y==0 || x==n-1|| y==n-1)
	{
		nex[x][y].first = (arr[real_x][real_y].first) / 2;
		nex[x][y].second = (arr[real_x][real_y].second + 2) % 4;
		if (nex[x][y].first != 0)
			v2.push_back(make_pair(x, y));
	}
	else
	{
		if (nex[x][y].first == 0 && nex[x][y].second == 0)//아무도 없다
		{
			nex[x][y].first = (arr[real_x][real_y].first);
			nex[x][y].second = (arr[real_x][real_y].second);
			v2.push_back(make_pair(x, y));
			ho[x][y].push_back(nex[x][y].first);
		}
		else
		{

			if (ho[x][y][0] < arr[real_x][real_y].first)
			{
				nex[x][y].second = (arr[real_x][real_y].second);
				ho[x][y][0] = arr[real_x][real_y].first;


			}
			nex[x][y].first += (arr[real_x][real_y].first);
		}
	}

}
int main()
{
	freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		v.clear();
		v2.clear();
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
		{
			int ga, se, mi, dir;
			cin >> ga >> se >> mi >> dir;
			if (dir == 1) {
				arr[ga][se] = make_pair(mi, 0);
			}
			else if (dir == 2) {
				arr[ga][se] = make_pair(mi, 2);
			}
			else if (dir == 3) {
				arr[ga][se] = make_pair(mi, 1);
			}
			else if (dir == 4) {
				arr[ga][se] = make_pair(mi, 3);
			}
			v.push_back(make_pair(ga, se));
		}
		for (int i = 0; i < m; i++)//지난 시간.
		{
			for (int j = 0; j < v.size(); j++)
			{
				check(v[j].first, v[j].second);
			}
			for (int j = 0; j < n; j++)
			{
				for (int p = 0; p < n; p++)
				{
					ho[j][p].clear();
				}
			}
			v.clear();
			v = v2;
			for (int u = 0; u < n; u++)
			{
				for (int j = 0; j < n; j++)
				{
					arr[u][j].first = nex[u][j].first;
					arr[u][j].second = nex[u][j].second;
					nex[u][j].first = 0;
					nex[u][j].second = 0;
				}
			}
			v2.clear();


		}
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += arr[v[i].first][v[i].second].first;
		}
		cout << "#" << q << " " << sum << '\n';

	}
	return 0;
}
