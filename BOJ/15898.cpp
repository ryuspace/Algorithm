//https://www.acmicpc.net/problem/15898
/*풀이 : 극 구현.. dfs+시뮬레이션, 각 함수의 역할은 주석.*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, char> pic;
int n;
pic jae[11][5][5];
bool visit[11];
int jemul[4];
int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,1,0 };//재료를 둘 수 있는 4가지 위치
int maxx = -1e9;
void play(int one, int two, int three)//재료를 가마에 넣는다.
{
	pic plate[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			plate[i][j].first = 0;
			plate[i][j].second = 'W';
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0 ; j < 4; j++)
		{
			plate[i + dx[one]][j+dy[one]] = jae[jemul[0]][i][j];
			if (plate[i + dx[one]][j + dy[one]].first < 0)
				plate[i + dx[one]][j + dy[one]].first = 0;
			else if(plate[i + dx[one]][j + dy[one]].first >9)
				plate[i + dx[one]][j + dy[one]].first = 9;
		
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			plate[i + dx[two]][j + dy[two]].first += jae[jemul[1]][i][j].first;
			if (jae[jemul[1]][i][j].second != 'W')
				plate[i + dx[two]][j + dy[two]].second = jae[jemul[1]][i][j].second;
			if (plate[i + dx[two]][j + dy[two]].first < 0)
				plate[i + dx[two]][j + dy[two]].first = 0;
			else if (plate[i + dx[two]][j + dy[two]].first > 9)
				plate[i + dx[two]][j + dy[two]].first = 9;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			plate[i + dx[three]][j + dy[three]].first += jae[jemul[2]][i][j].first;
			if (jae[jemul[2]][i][j].second != 'W')
				plate[i + dx[three]][j + dy[three]].second = jae[jemul[2]][i][j].second;
			if (plate[i + dx[three]][j + dy[three]].first < 0)
				plate[i + dx[three]][j + dy[three]].first = 0;
			else if (plate[i + dx[three]][j + dy[three]].first > 9)
				plate[i + dx[three]][j + dy[three]].first = 9;
		}
	}
	int r = 0, b = 0, g = 0, y = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (plate[i][j].second == 'R')
			{
				r += plate[i][j].first;
			}
			if (plate[i][j].second == 'B')
			{
				b += plate[i][j].first;
			}
			if (plate[i][j].second == 'G')
			{
				g += plate[i][j].first;
			}
			if (plate[i][j].second == 'Y')
			{
				y += plate[i][j].first;
			}
		}
	}
	maxx = max(maxx, 7*r+5*b+3*g+2*y);
}
void movv()//재료는 0,0시작, 0,1 시작 1,0, 시작 1,1 시작 총 4가지의 위치에 둘 수 있다.
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int r = 0; r < 4; r++)
			{
				play(i, j, r);
			}
		}
	}
}
void rotatt(int num)//회전
{
	pic tmpp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tmpp[i][j] = jae[num][i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			jae[num][i][j] = tmpp[3 - j][i];
		}
	}
}
void dfs2(int cnt)//뽑힌 세개의 재료를 회전할 수 있는 모든 조합을 만든다.
{
	if (cnt == 3)
	{
		movv();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		rotatt(jemul[cnt]);
		dfs2(cnt + 1);
	}
}
void dfs(int cnt)//재료 n개중 3개를 뽑는다.
{
	if (cnt == 3)
	{
		dfs2(0);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			jemul[cnt] = i;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int r = 0; r < n; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> jae[r][i][j].first;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> jae[r][i][j].second;
			}
		}
	}
	dfs(0);
	cout << maxx;
	return 0;
}

