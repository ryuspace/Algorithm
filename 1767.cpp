/*1767 프로세서 연결하기
풀이 : 네 방향을 탐색해서 연결 할 수 있는 모든 경우를 찾는다.
하지만 어떤 경우에도 연결하지 못하는 코어가 있을 수 있다.
그럴 때는 연결된 코어의 수와 전선의 길이를 담는 벡터를 이용해서
sort를 적절히 구현해서 가장 많이 코어가 연결 될 때 최소 전선의 길이를 찾았다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int arr[13][13];
int t,n;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector <pii> core;
vector <pii> si;

bool cmp(pii& a, pii& b)
{
	if (a.first > b.first)
		return 1;
	if (a.first == b.first)
	{
		if (a.second < b.second)
			return 1;
		else
			return 0;
	}
	if (a.first < b.first)
		return 0;
}
bool check(int x, int y, int dir)
{
	while (!(x < 0 || x >= n || y < 0 || y >= n))
	{
		if (arr[x][y] == 2 || arr[x][y] == 1)
			return false;
		x += dx[dir];
		y += dy[dir];
	}
	return true;
}
void bim(int x, int y, int dir)
{
	while (!(x < 0 || x >= n || y < 0 || y >= n))
	{
		arr[x][y] = 2;
		x += dx[dir];
		y += dy[dir];
	}

}
void dfs(int pro,int cnt)
{
	if (cnt == core.size())
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 2)
					sum++;
			}
		}
		si.push_back({ pro,sum });
		return;
	}
	int tmp[13][13];
	for (int r = 0; r < n; r++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[r][j] = arr[r][j];
		}
	}
	bool flag = false;
	for (int i = 0; i <4; i++)
	{
		int nx = dx[i] + core[cnt].first;
		int ny = dy[i] + core[cnt].second;
		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			if (check(nx, ny, i))
			{
				flag = true;
				bim(nx, ny, i);
				dfs(pro+1,cnt + 1);
				for (int r = 0; r < n; r++)
				{
					for (int j = 0; j < n; j++)
					{
						arr[r][j] = tmp[r][j];
					}
				}
			}
		}

	}
	if(!flag)
		dfs(pro,cnt + 1);
}
int main()
{
	freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		si.clear();
		core.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (i != 0 && j != 0 &&i!=n-1&&j!=n-1&& arr[i][j] == 1)
				{
					core.push_back({ i,j });
				}
			}
		}
		dfs(0,0);
		sort(si.begin(), si.end(), cmp);
		cout << "#" << r << " " << si[0].second << '\n';

	}
	return 0;
}

