//https://www.acmicpc.net/problem/4574
/*풀이 : 모든 칸을 탐색하면서 가능한 숫자 두 개를 뽑는다. 그 숫자 들을 기준으로,
가로,세로,네모에 나온적이 없는지 체크하고 칸에 넣어준다. 한 도미노에 숫자 두 개가 표현이 가능하므로
한 턴에 숫자를 뒤집은 경우도 체크하고 칸에 넣어준다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n;
int arr[36][36];
bool visit[10][10];
int ga[10][10];
int se[10][10];
int ne[10][10];
int t;
int hi = 0;
bool flag = false;
void dfs(int cnt)
{
	if (flag)
		return;
	int r = cnt / 9;
	int c = cnt % 9;
	if (cnt == 81)
	{
		cout << "Puzzle" << " " << hi << '\n';
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j];
			}
			cout << '\n';
		}
		flag = true;
		return;
	}
	if (arr[r][c] != 0)
	{
		dfs(cnt + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = i + 1; j <= 9; j++)
			{
				if (!visit[i][j])
				{
					visit[i][j] = true;
					visit[j][i] = true;
					if (c + 1 < 9 && arr[r][c] == 0 && arr[r][c + 1] == 0 &&
						ne[3 * (r / 3) + (c / 3)][i] == 0 && ne[3 * (r / 3)+((c+1)/3)][j]==0 &&
						ga[r][i]==0 &&ga[r][j]==0&&se[c][i]==0&&se[c+1][j]==0)
					{
						//가로..1방향
						arr[r][c] = i;
						arr[r][c + 1] = j;
						ga[r][i] = 1;
						ga[r][j] = 1;
						se[c][i] = 1;
						se[c + 1][j] = 1;
						ne[3 * (r / 3) + (c / 3)][i] = 1;
						ne[3 * (r / 3) + ((c + 1) / 3)][j] = 1;
						dfs(cnt + 2);
						arr[r][c] = 0;
						arr[r][c + 1] = 0;
						ga[r][i] = 0;
						ga[r][j] = 0;
						se[c][i] = 0;
						se[c + 1][j] = 0;
						ne[3 * (r / 3) + (c / 3)][i] = 0;
						ne[3 * (r / 3) + ((c + 1) / 3)][j] =0;
					}
					if (c + 1 < 9 && arr[r][c] == 0 && arr[r][c + 1] == 0 &&
						ne[3 * (r / 3) + (c / 3)][j] == 0 && ne[3 * (r / 3) + ((c + 1) / 3)][i] == 0 &&
						ga[r][j] == 0 && ga[r][i] == 0 && se[c][j] == 0 && se[c + 1][i] == 0)
					{
						//가로..2방향
						arr[r][c] = j;
						arr[r][c + 1] = i;
						ga[r][j] = 1;
						ga[r][i] = 1;
						se[c][j] = 1;
						se[c + 1][i] = 1;
						ne[3 * (r / 3) + (c / 3)][j] = 1;
						ne[3 * (r / 3) + ((c + 1) / 3)][i] = 1;
						dfs(cnt + 2);
						arr[r][c] = 0;
						arr[r][c + 1] = 0;
						ga[r][j] = 0;
						ga[r][i] = 0;
						se[c][j] = 0;
						se[c + 1][i] = 0;
						ne[3 * (r / 3) + (c / 3)][j] = 0;
						ne[3 * (r / 3) + ((c + 1) / 3)][i] = 0;
					}
					if (r+ 1 < 9 && arr[r][c] == 0 && arr[r+1][c] == 0 &&
						ne[3 * (r / 3) + (c / 3)][i] == 0 && ne[3 * ((r+1) / 3) + (c / 3)][j] == 0 &&
						ga[r][i] == 0 && ga[r+1][j] == 0 && se[c][i] == 0 && se[c][j] == 0)
					{
						//세로..1방향
						arr[r][c] = i;
						arr[r+1][c] = j;
						ne[3 * (r / 3) + (c / 3)][i] = 1;
						ne[3 * ((r + 1) / 3) + (c / 3)][j] = 1;
						ga[r][i] = 1;
						ga[r + 1][j] = 1;
						se[c][i] = 1;
						se[c][j] = 1;
						dfs(cnt + 1);
						arr[r][c] = 0;
						arr[r+1][c] = 0;
						ne[3 * (r / 3) + (c / 3)][i] = 0;
						ne[3 * ((r + 1) / 3) + (c / 3)][j] = 0;
						ga[r][i] = 0;
						ga[r + 1][j] =0;
						se[c][i] = 0;
						se[c][j] = 0;
					}
					if (r + 1 < 9 && arr[r][c] == 0 && arr[r + 1][c] == 0 &&
						ne[3 * (r / 3) + (c / 3)][j] == 0 && ne[3 * ((r + 1) / 3) + (c / 3)][i] == 0 &&
						ga[r][j] == 0 && ga[r + 1][i] == 0 && se[c][j] == 0 && se[c][i] == 0)
					{
						//세로..2방향
						arr[r][c] = j;
						arr[r + 1][c] = i;
						ne[3 * (r / 3) + (c / 3)][j] = 1;
						ne[3 * ((r + 1) / 3) + (c / 3)][i] = 1;
						ga[r][j] = 1;
						ga[r + 1][i] = 1;
						se[c][j] = 1;
						se[c][i] = 1;
						dfs(cnt + 1);
						arr[r][c] = 0;
						arr[r + 1][c] = 0;
						ne[3 * (r / 3) + (c / 3)][j] = 0;
						ne[3 * ((r + 1) / 3) + (c / 3)][i] = 0;
						ga[r][j] = 0;
						ga[r + 1][i] = 0;
						se[c][j] = 0;
						se[c][i] = 0;
					}
					visit[i][j] = false;
					visit[j][i] = false;
				}
			}
		}
	}
	

}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (n != 0)
	{
		hi++;
		flag = false;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		memset(ga, 0, sizeof(ga));
		memset(se, 0, sizeof(se));
		memset(ne, 0, sizeof(ne));
		for (int i = 0; i < n; i++)
		{
			int a, b;
			string ss, tt;
			cin >> a >> ss >> b >> tt;
			int r1 = ss[0] - 'A';
			int r2 = tt[0] - 'A';
			int c1 = ss[1] - '0' - 1;
			int c2 = tt[1] - '0' - 1;
			arr[r1][c1] = a;
			arr[r2][c2] = b;
			visit[a][b] = true;
			visit[b][a] = true;
			ga[r1][a] = 1;
			ga[r2][b] = 1;
			se[c1][a] = 1;
			se[c2][b] = 1;
			ne[3 * (r1 / 3) + (c1 / 3)][a] = 1;
			ne[3 * (r2 / 3) + (c2 / 3)][b] = 1;
		}
		for (int i = 1; i <= 9; i++)
		{
			string tmp;
			cin >> tmp;
			arr[tmp[0] - 'A'][tmp[1]-'0' - 1] = i;
			int r = tmp[0] - 'A';
			int c = tmp[1] - '0' - 1;
			ga[r][i] = 1;
			se[c][i] = 1;
			ne[3 * (r / 3) + (c / 3)][i] = 1;
		}
		dfs(0);
		cin >> n;
	}
	
	
	return 0;
}
