//https://www.acmicpc.net/problem/16770
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = a; i <= b; i++)
		{
			for (int j = 0; j < c; j++)
			{
				arr[i]++;
			}
		}
	}
	sort(arr, arr + 1001);
	cout << arr[1000];
	return 0;
}
