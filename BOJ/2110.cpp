//https://www.acmicpc.net/problem/2110
/*풀이 : 인접한 공유기 사이의 최대 거리를 이분탐색을 이용하여 찾는다.*/
#include <iostream>
#include <algorithm>

using namespace std;
int n, c;
int arr[200001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int left = 1;//나올 수 있는 최소 거리
	int right = arr[n - 1]-arr[0];//나올 수 있는 최대 거리
	while (left <= right)
	{
		int start = arr[0];
		int cnt =1;
		int mid = (left + right) / 2;
		for (int i = 1; i < n; i++)
		{
			int d = arr[i] - start;
			if (d >= mid)
			{
				cnt++;
				start = arr[i];
			}
		}
		if (cnt >=c)
		{
			left= mid+1;
		}
		else
		{
			right= mid-1;
		}
	}
	cout << right;
	return 0;
}
