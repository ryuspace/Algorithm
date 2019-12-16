#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, k;
	cin >> n >> k;
	int real_n = n;
	int real_k = k;
	int start = 1;
	if (n < k)
	{
		cout << "NO";
		exit(0);
	}
	while (start <= n)
	{
		start = start * 2;
	}
	start = start / 2;
	for (int i = 1; i <= k; i++)
	{
		while(real_n - start < real_k - 1)
		{
			start = start / 2;
		}
		arr[i] = start;
		real_n = real_n - start;
		real_k--;
	}
	int sum = 0;
	for (int i = 1; i <= k; i++)
	{
		sum += arr[i];
	}
	if (sum == n)
	{
		cout << "YES" << '\n';
		for (int i = k; i >= 1; i--)
		{
			cout << arr[i] << " ";
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
