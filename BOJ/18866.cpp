//https://www.acmicpc.net/problem/18866
/*풀이 :
1~i번 인덱스까지 젊은 날로 나누고 i+1~n번 인덱스까지 늙은 날로 나누고
최소 행복도, 최대 피로도/ 최대 행복도, 최소 피로도를 각각 비교해본다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 1e9+1
typedef pair<int, int> pii;
int n;
pii arr[1000001];
pii arr1[1000001];
pii arr2[1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;

	}

	int mini = 1000000001;
	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].first == 0)
		{
			mini = min(1000000001, mini);
			arr1[i].first = mini;
		}
		else
		{
			mini = min(arr[i].first, mini);
			arr1[i].first = mini;
		}

		maxi = max(maxi, arr[i].second);
		arr1[i].second = maxi;
	}
	mini = 1000000001;
	maxi = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i].second == 0)
		{
			mini = min(1000000001, mini);
			arr2[i].second = mini;
		}
		else
		{
			mini = min(arr[i].second, mini);
			arr2[i].second = mini;
		}

		maxi = max(maxi, arr[i].first);
		arr2[i].first = maxi;
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{

		if (arr1[i - 1].first > arr2[i].first&& arr1[i - 1].second < arr2[i].second)
		{
			ans = i;
		}

	}
	if (ans == 0)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}
