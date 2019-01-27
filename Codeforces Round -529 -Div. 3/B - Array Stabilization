#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int arr[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);


	int res1 = arr[n - 2] - arr[0];
	int res2 = arr[n - 1] - arr[1];

	cout << min(res1, res2);

	return 0;
}
