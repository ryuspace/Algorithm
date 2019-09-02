//https://www.acmicpc.net/problem/1700
/*풀이 : 운영체제때 배운 스케줄링이다. 가장 늦게 나오는 작업을 교체해주기..
OPT 알고리즘.
우선순위 : 1.아예 안 나오는 전기용품 , 2.가장 늦게 나오는 전기용품.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, k;
int multi[101];
int stuff[101];
queue <int> arr[101];
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	int res = 0;
	for (int i = 1; i <= k; i++)
	{
		int a;
		cin >> a;
		stuff[i] = a;
		arr[a].push(i);
	}
	for (int i = 1; i <= k; i++)
	{
		bool flag = false;
		for (int j = 1; j <= n; j++)
		{
			if (multi[j] == 0 || multi[j]==stuff[i])
			{
				flag = true;
				multi[j] = stuff[i];
				arr[stuff[i]].pop();
				break;
			}
		}
		if (!flag)
		{
			int minn = 0;
			int min_idx;
			for (int j = 1; j <= n; j++)
			{
				if (arr[multi[j]].empty())
				{
					min_idx = j;
					break;
				}
				else if (arr[multi[j]].front() > minn)
				{
					minn = arr[multi[j]].front();
					min_idx = j;
				}
			}
			multi[min_idx] = stuff[i];
			arr[stuff[i]].pop();
			res++;
		}

	}
	cout << res;
	return 0;
}
