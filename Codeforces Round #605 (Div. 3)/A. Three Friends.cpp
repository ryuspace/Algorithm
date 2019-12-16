#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
int arr[4];
long long minn = 1e18;
bool visit[4];
void dfs(int cnt)
{
	if (cnt == 3)
	{
		long long sum = 0;
		sum += abs(arr[0] - arr[1]) + abs(arr[0] - arr[2]) + abs(arr[1] - arr[2]);
		minn = min(minn, sum);
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			for (int j = 0; j < 3; j++)
			{
				if (j == 1)
				{
					arr[i] -= 1;
					dfs(cnt + 1);
					arr[i] += 1;
				}
				else if (j == 2)
				{
					arr[i] += 1;
					dfs(cnt + 1);
					arr[i] -= 1;
				}
				else
				{
					dfs(cnt + 1);
				}
			}
			visit[i] = false;
		}
		
	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		minn = 1e18;
		cin >> arr[0] >> arr[1] >> arr[2];
		//정지,왼쪽,오른쪽
		dfs(0);
		cout << minn << '\n';
	}
	return 0;
}
