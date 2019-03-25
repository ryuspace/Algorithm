//https://www.acmicpc.net/problem/2210
/*풀이 : 가능한 상하좌우 방향에 대해 dfs를 돌리고
map을 이용해 중복인 경우는 답에 포함하지 않는다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

map <string, int> m;
int arr[5][5];
int ans = 0;
void dfs(int r, int c,int cnt,string tmp)
{
	if (cnt == 6)
	{
		if (m.count(tmp) == 0)
		{
			ans++;
		}

		m[tmp]++;
		return;
	}
	if (r - 1 >= 0)
	{
		string tmpp = tmp;
		tmp += to_string(arr[r][c]);
		dfs(r - 1, c, cnt + 1, tmp);
		tmp = tmpp;
	}

	if (r + 1 < 5)
	{
		string tmpp = tmp;
		tmp += to_string(arr[r][c]);
		dfs(r + 1, c, cnt + 1, tmp);
		tmp = tmpp;
	}

	if(c-1 >=0)
	{
		string tmpp = tmp;
		tmp += to_string(arr[r][c]);
		dfs(r, c-1, cnt + 1, tmp);
		tmp = tmpp;
	}
	if (c +1 < 5)
	{
		string tmpp = tmp;
		tmp += to_string(arr[r][c]);
		dfs(r, c+1, cnt + 1, tmp);
		tmp = tmpp;
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(i, j, 0,"");
	cout << ans;
	return 0;
}
