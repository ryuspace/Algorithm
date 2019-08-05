//https://www.acmicpc.net/problem/17281
/*풀이 : 어떤 타자에서 아웃이 되었던 36번 미만으로 돈다. 
그래서 같은 for문 내에서 36번까지 돌게 해서 나머지 연산자를 이용해 타순이 반복되는 것을 표현한다.
또한 4번 타자는 정해져 있으므로 제외한 채로 dfs를 돌린다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[9] = { 0,};
int ining[51][10];
int maxx = 0;
bool visit[10];
void play()
{
	int sum = 0;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0, juja[4] = { 0, };
		for (int j = start; j < 27; j++)
		{
			if (cnt == 3)
			{
				start = j % 9;
				break;
			}
			if (ining[i][arr[j % 9]] == 0)
				cnt++;
			else if (ining[i][arr[j % 9]] == 1)
			{
				if (juja[3] == 1)
				{
					juja[3] = 0;
					sum++;
				}
				if (juja[2] == 1)
				{
					juja[3] = 1;
					juja[2] = 0;
				}
				if (juja[1] == 1)
				{
					juja[2] = 1;
					juja[1] = 0;
				}
				juja[1] = 1;
			}
			else if (ining[i][arr[j % 9]] == 2)
			{

				if (juja[3] == 1)
				{
					juja[3] = 0;
					sum++;
				}
				if (juja[2] == 1)
				{
					juja[2] = 0;
					sum++;
				}
				if (juja[1] == 1)
				{
					juja[3] = 1;
					juja[1] = 0;
				}
				juja[2] = 1;
			}
			else if (ining[i][arr[j % 9]] == 3)
			{
				if (juja[3] == 1)
				{
					juja[3] = 0;
					sum++;
				}
				if (juja[2] == 1)
				{
					juja[2] = 0;
					sum++;
				}
				if (juja[1] == 1)
				{
					juja[1] = 0;
					sum++;
				}
				juja[3] = 1;
			}
			else if (ining[i][arr[j % 9]] == 4)
			{
				if (juja[3] == 1)
					sum++;
				if (juja[2] == 1)
					sum++;
				if (juja[1] == 1)
					sum++;
				sum++;
				juja[3] = juja[2] = juja[1] = 0;
			}
		}
	}
	maxx = max(maxx, sum);
}
void dfs(int cnt)
{
	if (cnt == 3)
	{
		dfs(cnt + 1);
		return;
	}
	if (cnt == 9)
	{
		play();
		return;
	}

	for (int i = 1; i < 9; i++)
	{
		if (!visit[i])
		{
			arr[cnt] = i;
			visit[i] = true;
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
	for(int i=0;i<n;i++)
		for (int j = 0; j < 9; j++)
		cin >> ining[i][j];
	dfs(0);
	cout << maxx;
	return 0;
}

