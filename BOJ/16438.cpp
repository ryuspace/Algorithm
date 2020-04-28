//https://www.acmicpc.net/problem/16438
/*풀이 : 머지소트와 같은 원리로 배열을 계속 나눈 결과를 출력한다.
배열을 나눴다는 건 팀을 가른다는 뜻이다. 한번 팀이였으면 갈라져야 하므로 계속 반으로 가른다.*/
#include <iostream>
#include <algorithm>
using namespace std;
int n;
bool arr[100];
void printt()
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			cout << 'A';
		}
		else
		{
			cout << 'B';
		}
	}
	cout << '\n';
}
void merge(int start, int end, int cnt)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		for (int i = start; i <= mid; i++)
		{
			arr[i] = 1;

		}
		for (int i = mid + 1; i <= end; i++)
		{
			arr[i] = 0;
		}

		if (cnt > 0)
		{
			merge(start, mid, cnt - 1);
			merge(mid + 1, end, cnt - 1);
		}
	}

}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);


	cin >> n;
	for (int i = 0; i < 7; i++)
	{
		merge(0, n - 1, i);
		printt();
	}
}
