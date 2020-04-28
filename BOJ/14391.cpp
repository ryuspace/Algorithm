//https://www.acmicpc.net/problem/14391
/*풀이 : 맵을 0,1로 가능한 모든 경우를 채운다.
0은 가로를 뜻하고 1은 세로로 뜻한다. 0,0부터 n-1,m-1까지 가로방향 세로방향을 탐색한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int arr[5][5];
bool visit[5][5];

int check()
{

	string tmp = "";
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] == true)
			{
				tmp +=( arr[i][j] + '0');
			}
			else
			{
				if (tmp != "") 
				{
					sum += stoi(tmp);
				}
				tmp = "";
			}
		}
		if (tmp != "")
		{
			sum += stoi(tmp);
		}
		tmp = "";
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[j][i] == false)
			{
				tmp += (arr[j][i] + '0');
			}
			else
			{
				if (tmp != "")
				{
					sum += stoi(tmp);
				}
				tmp = "";
			}
		}
		if (tmp != "")
		{
			sum += stoi(tmp);
		}
		tmp = "";
	}
	return sum;
}
int res = 0;
void dfs(int r,int c)
{
	if (r == n - 1 &&c == m )
	{
		res=max(res,check());
		return;
	}
	if (c >= m)
	{
		dfs(r + 1, 0);
		return;
	}
	visit[r][c] = true;
	dfs(r, c + 1);
	visit[r][c] = false;
	dfs(r, c + 1);
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			cin >> a;
			arr[i][j] = a - '0';
		}
	}
	dfs(0, 0);
	cout << res;
	return 0;
}
