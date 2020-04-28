/*1244번 최대상금
dfs를 이용해 모든 가능한 경우를 바꿔본다. 하지만 중복 방지를 위해
이번 바꾸는 차례에 이미 이 숫자가 나왔으면 넘겨버리는 check 배열을 만들었다.
바꾸는 횟수의 맥시멈이 나오지 않아서 우선 tc에서 최대 10번 바꾸므로 11로 선언하였다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int t;
string tmp;
int sw;
bool check[1000000][11];
void swaping(int x, int y)
{
	int hi = tmp[x];
	tmp[x] = tmp[y];
	tmp[y] = hi;
}
int maxx = 0;
void dfs(int cnt)
{
	if (cnt == sw)
	{
		maxx = max(maxx, stoi(tmp));
		return;
	}
	if (check[stoi(tmp)][cnt])
		return;
	check[stoi(tmp)][cnt] = 1;
	for (int i = 0; i < tmp.length(); i++)
	{
		for (int j = i+1; j < tmp.length(); j++)
		{
			swaping(i, j);
			dfs(cnt + 1);
			swaping(i, j);

		}
	}
}
int main()
{
	freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		memset(check, 0, sizeof(check));
		cin >> tmp >> sw;
		maxx = stoi(tmp);
		dfs(0);
		cout << "#" << r << " " << maxx << '\n';
	}
	return 0;
}

