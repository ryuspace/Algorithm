//https://www.acmicpc.net/problem/6987
/*풀이 : 기존 결과판을 이용해 나라의 승 패 여부를 정해서 기존 결과판에서 값을 빼준다.
*/
#include <iostream>
#include <algorithm>


using namespace std;

int arr[7][4];
bool flag = false;
void dfs(int first, int second)
{
	if (first == 6)
	{
		flag = true;
		return;
	}
	if (second == 6)
	{
		dfs(first + 1, first + 2);
		return;
	}
	if (flag)
		return;
	for (int i = 0; i < 3; i++)
	{
		if (arr[first][i] >= 1 && arr[second][2 - i] >= 1)//1이상이 남아있어야 가능한 결과. 그렇지 않으면 탐색할 필요도 없다.
		{
			arr[first][i]--;
			arr[second][2 - i]--;
			dfs(first, second + 1);
			arr[first][i]++;
			arr[second][2 - i]++;
		}

	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int t = 0; t < 4; t++)
	{
		int win = 0, draw = 0, lose = 0;
		flag = false;
		for (int i = 0; i < 6; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			win += a;
			draw += b;
			lose += c;
			arr[i][0] = a;
			arr[i][1] = b;
			arr[i][2] = c;
		}
		if (win + draw + lose == 30 && win == lose)
		{
			dfs(0, 1);
		}
		else
		{
			flag = false;
		}

		cout << flag << " ";
	}

	return 0;
}
