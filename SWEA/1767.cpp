/*1767 프로세서 연결하기
풀이 : 네 방향을 탐색해서 연결 할 수 있는 모든 경우를 찾는다.
하지만 어떤 경우에도 연결하지 못하는 코어가 있을 수 있다.
그럴 때는 연결된 코어의 수와 전선의 길이를 담는 벡터를 이용해서
sort를 적절히 구현해서 가장 많이 코어가 연결 될 때 최소 전선의 길이를 찾았다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int t, n;
int arr[13][13];
vector<pii> v;
vector<pii> hubo;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool cmp(const pii& a, const pii& b)
{
	if (a.first > b.first)
	{
		return true;
	}
	else if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return false;
	}

}
bool check(int x, int y, int dir)
{
	int xx = x;
	int yy = y;

	while (xx >= 0 && xx < n && yy >= 0 && yy < n)
	{
		if (arr[xx][yy] != 0)
		{
			return false;
		}
		xx += dx[dir];
		yy += dy[dir];
	}
	return true;
}

int paint(int x, int y, int dir, int color)
{
	int sum = 0;
	int xx = x;
	int yy = y;

	while (xx >= 0 && xx < n && yy >= 0 && yy < n)
	{
		arr[xx][yy] = color;
		sum++;
		xx += dx[dir];
		yy += dy[dir];
	}
	return sum;
}

void go(int me, int cnt, int sum)
{
	if (cnt == v.size())
	{
		hubo.push_back({ me,sum });
		return;
	}
	bool flag = false;
	for (int i = 0;i < 4;i++)
	{
		int nx = dx[i] + v[cnt].first;
		int ny = dy[i] + v[cnt].second;
		if (check(nx, ny, i))
		{
			flag = true;
			int hi = paint(nx, ny, i, 2);
			go(me + 1, cnt + 1, sum + hi);
			paint(nx, ny, i, 0);
		}
	}
	if (!flag)
	{
		go(me, cnt + 1, sum);
	}

}
int main()
{

	//freopen("Test.txt", "r", stdin);
	cin >> t;

	for (int i = 1;i <= t;i++)
	{
		hubo.clear();
		v.clear();
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				cin >> arr[i][j];
				if (i != 0 && i != n - 1 && j != 0 && j != n - 1 && arr[i][j] == 1)
				{
					v.push_back({ i,j });
				}
			}
		}
		go(0, 0, 0);
		sort(hubo.begin(), hubo.end(), cmp);
		cout << "#" << i << " " << hubo[0].second << '\n';

	}
	return 0;
}
