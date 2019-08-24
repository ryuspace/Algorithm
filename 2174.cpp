//https://www.acmicpc.net/problem/2174
/*풀이 : 문제에 있는 맵을 오른쪽으로 90도 돌리면 우리가 일반적으로 쓰는 배열 형식으로
접근할 수 있다. 그 대신 방향도 
동서남북이 남북서동으로 바뀐다. 이 점을 고려해서 시뮬레이션을 한다.
로봇이 무언가에 부딪히면 잘못된 시뮬레이션 명령을 담고 더 이상 로봇을 움직이는 것을
무의미하게 한다.. (최초 결과만 출력해야 하므로)
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct point
{
	int x, y, dir;
};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
//동남서북 인데.. 배열을 돌릴거야
point robot[101];
int arr[101][101];
int a, b, n, m;
vector<string> tmp;
void mov(int idx, char see, int rep)
{

	if (see == 'L')
	{
		for (int i = 0; i < rep; i++)
		{
			robot[idx].dir = (robot[idx].dir + 3) % 4;
		}
	}
	else if (see == 'R')
	{
		for (int i = 0; i < rep; i++)
		{
			robot[idx].dir = (robot[idx].dir + 1) % 4;
		}
	}
	else if (see == 'F')
	{
		int befor_x = robot[idx].x;
		int befor_y = robot[idx].y;
		for (int i = 0; i < rep; i++)
		{
			robot[idx].x += dx[robot[idx].dir];
			robot[idx].y += dy[robot[idx].dir];
			if (arr[robot[idx].x][robot[idx].y] != 0)
			{

				string hi = "";
				hi += "Robot ";
				hi += to_string(idx + 1);
				hi += " crashes into robot ";
				hi += to_string(arr[robot[idx].x][robot[idx].y]);
				tmp.push_back(hi);
				return;
			}
			else if (robot[idx].x <= 0 || robot[idx].x > a || robot[idx].y <= 0 || robot[idx].y > b)
			{
				string hi = "";
				hi += "Robot ";
				hi += to_string(idx + 1);
				hi += " crashes into the wall";
				tmp.push_back(hi);
				return;
			}
		}
		arr[befor_x][befor_y] = 0;
		arr[robot[idx].x][robot[idx].y] = idx + 1;
	}
}
int main(void)
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> n >> m;
	for (int i = 0; i < n; i++)
	{
		char di;
		cin >> robot[i].x >> robot[i].y >> di;
		arr[robot[i].x][robot[i].y] = i + 1;
		if (di == 'N')
		{
			robot[i].dir = 3;
		}
		else if (di == 'W') {
			robot[i].dir = 2;
		}
		else if (di == 'S')
		{
			robot[i].dir = 1;
		}
		else if (di == 'E')
		{
			robot[i].dir = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int aa, cc;
		char bb;
		cin >> aa >> bb >> cc;
		if (tmp.size() == 0)//잘못된 명령이 들어가지 않았으면 계속 진행 그렇지 않으면 더 할 필요가 없다.
			mov(aa - 1, bb, cc);
	}
	if (!tmp.empty())
		cout << tmp[0] << '\n';
	else
		cout << "OK" << '\n';
	return 0;
}
