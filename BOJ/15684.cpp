//https://www.acmicpc.net/problem/15684
/*풀이 : dfs를 이용하여 사다리를 놓을 수 있는 모든 곳에다가
사다리를 놓는다. 최대 3개까지 놓을 수 있으므로 0개인 경우,1개인 경우,
2개인 경우,3개 인 경우
각각 나눠서 dfs를 돌린다. 사다리 조작을 성공을 체크하는 함수는 각각의 위치에서
그 위치에 사다리가 있는지 왼쪽에 있으면 현재 위치를 하나 줄여주고
오른쪽에 있으면 현재 위치를 하나 늘려줘서 계속 현재 위치를 갱신해서
원래 내 위치로 가는지 체크해준다.
현재 위치에서 왼쪽,오른쪽만 봐주면 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, h;
int map[31][11];//map[i][j]의 의미는 i번째 점선에 세로선 j에서 j+1 사이에 사다리가 연결되어있다.
//h가 가로 n이 세로
bool check()
{
	for (int i = 1; i <= n; i++)
	{
		int pos = i;
		for (int j = 1; j <= h; j++)
		{
			if (map[j][pos] == 1)
			{
				pos++;
			}
			else if (map[j][pos-1] == 1)
			{
				pos--;
			}
		}
		if (pos != i)
			return false;
	}
	return true;
}
int minn = 1e9;
void dfs(int x ,int now,int cnt)
{
	if (now <=cnt)
	{
		if (check())
		{
			minn = min(minn, cnt);
		}
		return;
	}
	for (int i = x; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (map[i][j] ==0 && map[i][j-1]==0)
			{
				map[i][j] = 1;
				dfs(i,now,cnt + 1);
				map[i][j] = 0;
			}
		}
	}


}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	cin >> n >> m >> h;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int i = 0; i <= 3; i++)
	{
		dfs(1,i,0);
	}
	if (minn == 1e9)
		cout << -1;
	else
		cout << minn;
	return 0;
}
