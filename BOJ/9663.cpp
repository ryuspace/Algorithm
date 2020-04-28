//https://www.acmicpc.net/problem/9663
/*풀이 : 퀸을 놓으면 같은 행,열,대각선은 못 둔다. n번째 행에다가 퀸을 뒀으면 그 행은 퀸을
둘 수 없으므로 바로 n+1행으로 넘어간다. 그리고 같은 열인지, 같은 대각선에 속한지 체크해준다.
오른쪽 대각선은 행과 열을 더하면 서로 같고 왼쪽 대각선은 행과 열을 서로 빼면 같다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int map[16][16];
bool col[16];
bool dl[32];
bool dr[32];

int n;

int cntt = 0;
void dfs(int cnt)
{
	if (cnt == n)
	{
		cntt++;
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if (col[i] == 0 && dl[n + i - cnt] == 0 && dr[i + cnt]==0)
		{
			col[i] = 1;
			dl[n + i - cnt] = 1;
			dr[i + cnt] = 1;
			dfs(cnt + 1);
			col[i] = 0;
			dl[n + i - cnt] = 0;
			dr[i + cnt] = 0;
		}
	}

}


int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);


	cin >> n;
	dfs(0);
	cout << cntt;
	return 0;
}
