//https://www.acmicpc.net/problem/16161
/*풀이 : 나올 수 있는 팰린드롬의 경우를 찾아서 양 옆으로 퍼지는 식으로 찾는다.*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int arr[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max_length = 1;
	int start = 0;
	while (start < n)
	{
		int idx = start + 1;

		while (idx<n && arr[idx]>arr[idx - 1])
		{
			idx++;
		}
		if (idx == start + 1)// 1 1 , 2 2, 3 3 같은 형식 
		{
			if (arr[start] == arr[idx])
			{
				max_length = max(max_length, 2);
			}
			start++;
		}
		else if (arr[idx] == arr[idx - 1]) //1221 1331 같은 형식
		{
			int length = 1;

			while (idx + length < n && idx - 1 - length >= start &&
				arr[idx + length] == arr[idx - 1 - length])
			{
				length++;
			}
			max_length = max(max_length, 2*length);
			start = idx + length - 1;
		}
		else//12321 13531 같은 형식
		{
			idx--;
			int length = 1;

			while (idx - length >= start && idx + length < n &&
				arr[idx - length] == arr[idx + length])
			{
				length++;
			}
			max_length = max(max_length, 2*length-1);
			start = idx + length - 1;
		}
	}
	cout << max_length;
	return 0;
}
