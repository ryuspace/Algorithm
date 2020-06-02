//https://www.acmicpc.net/problem/15684
/*풀이 : dfs를 이용하여 사다리를 놓을 수 있는 모든 곳에다가
사다리를 놓는다. 최대 3개까지 놓을 수 있으므로 3개 이하인 모든 경우에 dfs를 돌린다. 
사다리 조작을 성공을 체크하는 함수는 각각의 위치에서
그 위치에 사다리가 있는지 왼쪽에 있으면 현재 위치를 하나 줄여주고
오른쪽에 있으면 현재 위치를 하나 늘려줘서 계속 현재 위치를 갱신해서
원래 내 위치로 가는지 체크해준다.
현재 위치에서 왼쪽,오른쪽만 봐주면 된다.
dfs 과정 시간복잡도 주의
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, h;
bool visit[31][11];
int minn = 1e9;
bool play()
{
	for (int i = 1;i <= n;i++)
	{
		int now = i;//어디 방향 타고 있는지
		for (int j = 1;j <= h;j++)
		{
			if (visit[j][now] == true)
			{
				now++;
			}
			else if (now-1>=1 && visit[j][now - 1] == true)
			{
				now--;
			}
		}
		if (now != i)
			return false;
	}

	return true;
}
void dfs(int x,int y,int cnt)
{
	if (play())
	{
		minn = min(minn, cnt);
		return;
	}
	if (cnt == 3 || (x==h && y==n) || minn < cnt)
	{
		return;
	}
	if (y == n)
	{
		x++;
		y = 1;
	}

	for (int i = x;i <= h;i++) //dfs 과정을 이렇게 하면 시간이 줄여진다. 15684.cpp 원래 코드는 지수승으로 올라가서 값이 커질수록 시간이 부담된다.
	{
		for (int j = 0;j <= n-1;j++)
		{
			if (!visit[i][j])
			{
				if (j == 1 || (j - 1 >= 1 && !visit[i][j - 1]))
				{
					visit[i][j] = true;
					dfs(i, j, cnt + 1);
					visit[i][j] = false;
				}
			}
		}
	}
}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> h;
	for (int i = 0;i <m;i++)
	{
		int a, b;
		cin >> a >> b;
		visit[a][b] = true;
	}
	dfs(1, 1, 0);
	if (minn == 1e9)
		cout << -1;
	else
		cout << minn;
	return 0;
}
