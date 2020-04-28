//https://www.acmicpc.net/problem/1654
/*풀이 : 이분탐색 정석. 자를 랜선을 mid로 설정해서 n개보다 많은지 적은지 판단해서 이분탐색을 계속 돌린다.*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int arr[10001];
int main()
{
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
	long long int left = 1;
	long long int right = pow(2,31)-1;
	while (left <= right)
	{
		long long int mid = (left + right) / 2;
		long long int sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += (arr[i] / mid);
		}
		if (sum < n)
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
