//https://www.acmicpc.net/problem/1517
/*풀이 : 머지소트를 처음 구현해봤다. 시간복잡도는 (nlog(n)). 머지소트를 할 때 
역전한 횟수가 버블정렬 횟수다. 역전한 횟수를 알기 위해 오른쪽에 있는 애를 정렬할 때
왼쪽에 이보다 큰 게 몇개나 있는지(어렵다..)*/
#include <iostream>

using namespace std;

int arr[500001];
int sorted[500001];
long long int cnt = 0;
void merge(int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;
	while (i <= middle && j <= n)
	{
		if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i];
			i++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
			cnt += middle - i + 1;
		}
		k++;
	}
	if (i <= middle)
	{
		for (int t = i; t <=middle; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	else
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	for (int r = m; r <= n; r++)
	{
		arr[r] = sorted[r];
	}
}

void merge_sort(int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		merge_sort(m, middle);
		merge_sort(middle+1, n);
		merge(m, middle, n);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	merge_sort(0, n - 1);

	cout << cnt;
}
