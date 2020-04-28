#include <iostream>
#include <algorithm>

using namespace std;

int arr[400002];
int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n; i < 2 * n; i++)
	{
		arr[i] = arr[i - n];
	}
	int maxx = 0;
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (arr[i] == 1)
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
		maxx = max(cnt, maxx);
	}
	cout << maxx;

	return 0;
}
