//https://www.acmicpc.net/problem/3967
/*풀이 : 좌표를 넣는 벡터를 하나 만들고 알파벳을 넣는 벡터를 하나 만든다. 그리고 
x인 곳에 이미 나와있지 않는 알파벳들의 순열을 집어 넣어 보고 가장 먼저 조건에 맞는
순열을 담은 map을 출력한다.*/
#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

char map[5][9];
vector < pair <int, int> > v1;//좌표를 넣는 벡터
vector <char> v2; //알파벳을 넣는 벡터
char used[300];
bool visit[300];

bool check()
{
	int res1 = (map[0][4] - 'A') + (map[1][3] - 'A') + (map[2][2] - 'A') + (map[3][1] - 'A');
	int res2 = (map[0][4] - 'A') + (map[1][5] - 'A') + (map[2][6] - 'A') + (map[3][7] - 'A');
	int res3 = (map[3][1] - 'A') + (map[3][3] - 'A') + (map[3][5] - 'A') + (map[3][7] - 'A');
	int res4 = (map[1][1] - 'A') + (map[1][3] - 'A') + (map[1][5] - 'A') + (map[1][7] - 'A');
	int res5 = (map[1][1] - 'A') + (map[2][2] - 'A') + (map[3][3] - 'A') + (map[4][4] - 'A');
	int res6 = (map[1][7] - 'A') + (map[2][6] - 'A') + (map[3][5] - 'A') + (map[4][4] - 'A');

	if ((res1 == res2)&&(res2==res3)&&(res3==res4)&&(res4==res5)&&(res5==res6))
		return 1;
	else
		return 0;


}
void dfs(int cnt, vector <char> v)
{
	if (cnt == v1.size())
	{
		for (int i = 0; i < v1.size(); i++)
		{
			map[v1[i].first][v1[i].second] = v[i];
		}
		if (check())
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << map[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
		return;
	}
	for (int i = 0; i < v2.size(); i++)
	{
		if (!visit[v2[i]])
		{
			v.push_back(v2[i]);
			visit[v2[i]] = true;
			dfs(cnt + 1, v);
			v.pop_back();
			visit[v2[i]] = false;
		}
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'x')
			{
				v1.push_back({ i,j });
			}
			if (map[i][j] >= 'A' && map[i][j] <= 'L')
			{
				used[map[i][j]] = true;
			}

		}
	}
	for (int i = 'A'; i <= 'L'; i++)
	{
		if (!used[i])
		{
			v2.push_back(i);
		}
	}

	dfs(0, {});

	return 0;
}
