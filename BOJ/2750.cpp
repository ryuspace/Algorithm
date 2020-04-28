//https://www.acmicpc.net/problem/2750
/*풀이 : 퀵 소트를 이용했다. pivot을 기준으로 분할하므로 시간 복잡도는 nlogn.
정렬된 상태면 최악의 경우므로 n^2번 탐색한다...*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
int n;
int quick(int arr[],int start,int end)
{
	int pivot = 0;
	int tmp = 0, left = 0, right = 0, t = 0;
	left = start;
	right = end;
	pivot = end;

	while (left < right)
	{
		while (arr[left] < arr[pivot] && left < right)
		{
			left++;
		}
		while (arr[right] >= arr[pivot] && left < right)
		{
			right--;
		}
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}

	tmp = arr[pivot];
	arr[pivot] = arr[left];
	arr[left] = tmp;

	return right;
}
void div(int arr[], int start, int end)
{
	int pivot = 0;
	if (start < end)
	{
		pivot = quick(arr, start, end);
		div(arr, start, pivot - 1);
		div(arr, pivot + 1, end);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	div(arr,0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
