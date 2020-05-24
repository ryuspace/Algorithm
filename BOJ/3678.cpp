//https://www.acmicpc.net/problem/3678
/*풀이 :

육각형 타일을 조금 그려보면 (-1,1) -> (-1,0) -> (-1,-1) -> (1,-1) -> (1,0) -> (1,1) 순서로 반복되는 것을 알 수 있다.
판이 커질수록 이동방향의 반복이 생기는데 다음 방향으로 가려고 할 때 안되면 현재 방향으로 계속 가보면 해결이 된다 => 포인트
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c, n;

int dx[6] = {-1,-2,-1,1,2 ,1};
int dy[6] = { 1,0,-1,-1,0 ,1};
vector<int> ans;
int arr[501][501];
int chong[6];
int returnValue(int x, int y)
{
	int cnt[6] = { 0,0,0,0,0,0 };
	for (int i = 0; i < 6; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (arr[nx][ny] != 0)
		{
			cnt[arr[nx][ny]]++;
		}

	}

	vector<int> v;

	for (int i = 1; i <=5; i++)
	{
		if (cnt[i] == 0)
		{
			v.push_back(i);
		}

	}

	if (v.size() == 1)
	{
		return v[0];
	}

	int mini = 1e9;
	for (int i = 0; i < v.size(); i++)
	{
		if (chong[v[i]] < mini)
		{
			mini = chong[v[i]];
		}
	}

	vector<int> v2;


	for (int i = 0; i < v.size(); i++)
	{
		if (mini == chong[v[i]])
		{
			v2.push_back(v[i]);
		}
	}
	sort(v2.begin(), v2.end());

	return v2[0];
}
void go(int x,int y,int num,int cnt)
{

	if (cnt > 10000)
	{
		return;
	}

	arr[x][y] = returnValue(x, y);
	ans.push_back(arr[x][y]);
	chong[arr[x][y]]++;

	int next_x = x + dx[num];
	int next_y = y + dy[num];

	if (arr[next_x][next_y] != 0)
	{
		if (num == 0)
		{
			num = 6;
		}
		go(x+dx[(num - 1) % 6], y+dy[(num - 1) % 6] ,(num)%6,cnt+1);
	}
	else
	{
		go(next_x, next_y, (num + 1) % 6,cnt+1);
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	arr[250][250] = 1;
	arr[249][251] = 2;
	chong[1]++;
	chong[2]++;
	ans.push_back(1);
	ans.push_back(2);
	go(248, 250, 3, 1);
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		cout << ans[n - 1] << '\n';
	}
	return 0;
}
