//https://www.acmicpc.net/problem/15462
/*풀이 : 소 별로 각각 a,b,c,d,e... 알파벳을 부여하고 가야하는 위치에다가 알파벳을 붙인다.
이전 상태와 현재상태의 빈 위치가 아닌 갯수가 같으면 반복문을 멈춘다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int arr[100001];
string cow[100001];
string cow2[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[i] = arr[i] - 1;
	}
	for (int i = 0; i < n; i++)
	{
		cow[i] = 'a' + i;
	}

	int cnt = n;
	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			cow2[arr[i]] += cow[i];
		}

		int cnt2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (cow2[i] != "")
			{
				cnt2++;
			}
		}
		if (cnt2 == cnt)
		{
			cout << cnt2;
			exit(0);
		}
		for (int i = 0; i < n; i++)
		{
			cow[i] = cow2[i];
		}

		for (int i = 0; i < n; i++)
		{
			cow2[i] = "";
		}
		cnt = cnt2;
	}


	return 0;
}
