//https://www.acmicpc.net/problem/2580
/*풀이 :  2239 스도쿠랑 같은 문제
3x3보드를 (3*(행/3)+(열/3))을 하면 하나의 보드로 접근할 수 있다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10][10];
int ne[10][10];
int ga[10][10];
int se[10][10];

void dfs(int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = cnt / 9;
	int y = cnt % 9;
	if (arr[x][y] != 0)
	{
		dfs(cnt + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if(ga[x][i]==0 && se[y][i] ==0 && ne[3*(x/3)+(y/3)][i]==0)
			{
				arr[x][y] = i;
				ga[x][i] = 1;
				se[y][i] = 1;
				ne[3 * (x / 3) + (y / 3)][i] = 1;
				dfs(cnt + 1);
				arr[x][y] = 0;
				ga[x][i] = 0;
				se[y][i] = 0;
				ne[3 * (x / 3) + (y / 3)][i] = 0;
			}
		}
	}
}
int main(void)
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				ga[i][arr[i][j]] = 1;
				se[j][arr[i][j]] = 1;
				ne[3 * (i / 3) + (j / 3)][arr[i][j]] = 1;
			}
		}
	}
	dfs(0);
	return 0;
}
