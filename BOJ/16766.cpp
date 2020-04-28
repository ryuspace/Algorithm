//https://www.acmicpc.net/problem/16766
/*시간이 주어졌을때 주어진 버스의 갯수로 모든 소가 탈 수 있는지 이분탐색으로 찾는다.*/
#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];
int n, m, c;
bool check(int num)
{
	int bus_cnt = 1;
	int cnt = 1;
	int start = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - start < num && cnt<c)
		{
			cnt++;
		}

		else
		{
			start = arr[i];
			cnt = 1;
			bus_cnt++;
		}

	}
	if (bus_cnt > m)
		return false;
	else
		return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int left = 0;
	int right = 1000000000;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (check(mid))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << right;

	return 0;
}
