//https://www.acmicpc.net/problem/11054
/*풀이 : 
dp배열 : n번째까지의 증가,감소하는 수열의 최대 길이.*/
#include <iostream>
#include <algorithm>

using namespace std;
int arr[1001];
int dp1[1001];
int dp2[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp1[i] = max(dp1[i], dp1[j]+1);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (arr[i] > arr[j])
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		maxx = max(dp1[i] + dp2[i], maxx);
	}
	cout << maxx+1;
	return 0;
}
