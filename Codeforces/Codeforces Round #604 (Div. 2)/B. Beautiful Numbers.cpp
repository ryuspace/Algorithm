#include <iostream>
#include <algorithm>

using namespace std;

int t;
int arr[200001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			arr[a] = i;
		}
	
		cout << 1;
		int minn = arr[1];
		int maxx = arr[1];
		for (int i = 2; i <= n; i++)
		{
			minn = min(minn, arr[i]);
			maxx = max(maxx, arr[i]);
			if (maxx - minn + 1 == i)
				cout << 1;
			else
				cout << 0;
		}
		cout << '\n';
	}
	return 0;
}
