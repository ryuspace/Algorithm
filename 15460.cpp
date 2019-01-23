//https://www.acmicpc.net/problem/15460
/*풀이 : 이전것의 합을 계속 더한 배열과 뒤에서부터 최솟값을 찾은 배열 두 개를 만들어서 가능한 k별로 최댓값을 찾는다 */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[100001];
int mini[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int Min = 1e9;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n; i >= 1; i--)
	{
		Min = min(Min, arr[i]);
		mini[i] = Min;
	}
	for (int i = 1; i < n; i++)
	{
		arr[i + 1] += arr[i];
	}


	double Max = 0;
	int Max_idx = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		double sum = (double)(arr[n] - arr[i] - mini[i + 1]) / (n - i - 1);
		if (sum > Max)
		{
			Max = sum;
		}
	}
	for (int i = 1; i <= n - 2; i++)
	{
		double sum = (double)(arr[n] - arr[i] - mini[i + 1]) / (n - i - 1);
		if (Max == sum)
		{
			cout << i << " ";

		}
	}

	return 0;
}
