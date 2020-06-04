//https://www.acmicpc.net/problem/17825
/*풀이 : 1.한번으로 갈 수 있는 경로를 찾는다.
		 2.그 경로를 배열에다 미리 적는다.
		 3.주사위를 굴려보고 그 위치에 말이 없으면 가게한다. 단 25 30 35 40 같은 경우는 여러 배열에 값이 선언되어있다. 이 위치에 올 때 한 곳으로 텔레포트 하게 한다. 안 그러면 같은 위치에 말이 두 번 있게 된다 ㅂㄷㅂㄷ ㅠㅠㅠㅠㅠㅠ
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii start[4] = { {0,-1},{0,-1}, {0,-1},{0,-1} };
int dice[11];
int map[4][30] = { {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},{10,13,16,19,25,30,35,40},{20,22,24,25,30,35,40},{30,28,27,26,25,30,35,40} };
int maxi;
bool already(int idx,pii me)
{
	for (int i = 0;i < 4;i++)
	{
		if (idx!=i && ((me.first == start[i].first) && (me.second == start[i].second)))
			return true;
	}
	return false;
}
void dfs(int cnt,int sum)
{
	maxi = max(maxi, sum);
	if (cnt == 10)
	{
		return;
	}
	for (int i = 0;i < 4;i++)
	{
		if (!(start[i].first >= 3 && start[i].second>=8))
		{
			pii tmp = start[i];
			start[i].second += dice[cnt];
			if (map[start[i].first][start[i].second] == 10)
			{
				start[i] = { 1,0 };
			}
			else if (map[start[i].first][start[i].second] == 20)
			{
				start[i] = { 2,0 };
			}
			else if (map[start[i].first][start[i].second] == 25)
			{
				start[i] = { 3,4 };
			}
			else if (map[start[i].first][start[i].second] == 30 && (start[i].first==0 && start[i].second==14))
			{
				start[i] = { 3,0 };
			}
			else if (map[start[i].first][start[i].second] == 30 && !(start[i].first == 0 && start[i].second == 14))
			{
				start[i] = { 3,5 };
			}
			else if (map[start[i].first][start[i].second] == 35)
			{
				start[i] = { 3,6 };
			}
			else if (map[start[i].first][start[i].second] == 40)
			{
				start[i] = { 3,7 };
			}
			else if (map[start[i].first][start[i].second] == 0)
			{
				start[i] = { 3,8 };
			}
			if ((start[i].first>=3 && start[i].second>=8) || !already(i,start[i]))
			{
				dfs(cnt + 1, sum + map[start[i].first][start[i].second]);
			}
			start[i] = tmp;
		}
	}
}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0;i < 10;i++)
	{
		cin >> dice[i];
	}
	dfs(0, 0);
	cout << maxi;
	return 0;
}
