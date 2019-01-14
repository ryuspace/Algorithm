//https://www.acmicpc.net/problem/2239

#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
/*풀이 : map의 행,열,네모를 기준으로 숫자가 있는지 파악하는 배열을 만든다. 그래서 
맵에 숫자를 넣을때 행,열,네모에 그 숫자가 있는지 파악한 후 없으면 숫자를 넣고 dfs를
돌린다.*/
int num_cnt[11];
int map[10][10];
int hang[11][11];
int yeol[11][11];
int nemo[11][11];

void dfs(int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << map[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}

	int x = cnt / 9;
	int y = cnt % 9;
	if (map[x][y] != 0)
	{
		dfs(cnt + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (hang[x][i] == 0 && yeol[y][i] == 0 && nemo[3 * (x / 3) + (y / 3)][i]==0)
			{
				hang[x][i] = 1;
				yeol[y][i] = 1;
				nemo[3 * (x / 3) + (y / 3)][i] = 1;
				map[x][y] = i;
				dfs(cnt + 1);
				hang[x][i] = 0;
				yeol[y][i] = 0;
				nemo[3 * (x / 3) + (y / 3)][i] = 0;
				map[x][y] = 0;

			}
		}
	}
	
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	string m;
	for (int i = 0; i < 9; i++)
	{
		cin >> m;
		for (int j = 0; j < 9; j++)
		{
			map[i][j]=m[j]-'0';
			if (map[i][j] != 0)
			{
				hang[i][map[i][j]] = 1;//행을 기준으로 숫자 있는 곳을 1로 표시
				yeol[j][map[i][j]] = 1;//열을 기준으로 숫자 있는 곳을 1로 표시
				nemo[3 * (i / 3) + (j / 3)][map[i][j]] = 1;//네모를 기준으로 숫자 있는 곳을 1로 표시
			}
			
		}
	}

	dfs(0);

	return 0;
}
