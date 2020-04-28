// https://www.acmicpc.net/problem/18235
/*풀이 : 1. x일 동안 2^(x-1)만큼 갈 수 있으니깐 log(x)일만큼만 생각하면 된다. 2^(log x)=x
2.멤버들을 1e9로 초기화했더니 런타임에러가 뜬다. 배열의 크기가 크면 사용하지 말자
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[500002];
int arr2[500002];
bool tmp[500002];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = arr2[i] = -1;
	}
	arr[a] = 0;
	arr2[b] = 0;
	for (int r = 1; r <= 21; r++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] == r - 1)
			{
				if (i - (1 << (r - 1)) >= 1)
					tmp[i - (1 << (r - 1))] = true;
				if (i + (1 << (r - 1)) <= n)
					tmp[i + (1 << (r - 1))] = true;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (tmp[i])
			{
				arr[i] = r;
				tmp[i] = false;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (arr2[i] == r - 1)
			{
				if (i - (1 << (r - 1)) >= 1)
					tmp[i - (1 << (r - 1))] = true;
				if (i + (1 << (r - 1)) <= n)
					tmp[i + (1 << (r - 1))] = true;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (tmp[i])
			{
				arr2[i] = r;
				tmp[i] = false;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (arr[i]!=-1 && arr[i] ==arr2[i])
			{
				cout << arr[i];
				exit(0);
			}
		}
	}
	cout << -1;
	return 0;
}
