//https://www.acmicpc.net/problem/2621
/*풀이 : 실수하기 쉬운 구현. 카드 색과 숫자를 pair 배열로 받고 숫자에 대해 sort 하면 그래도 구현이 편해진다..*/
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, char> arr[5];

void game()
{
	int maxx = 0;
	//1번
	if ((arr[0].second == arr[1].second)&&(arr[1].second == arr[2].second)&&(arr[2].second == arr[3].second)
		&&(arr[3].second == arr[4].second )&&
		(arr[0].first == arr[1].first - 1)&&(arr[1].first - 1 == arr[2].first - 2)&&
		(arr[2].first - 2 == arr[3].first - 3) &&
		(arr[3].first - 3 == arr[4].first - 4))
	{
		maxx = max(maxx, arr[4].first + 900);
	}
	//2번
	int num[10] = { 0, };
	for (int i = 0; i < 5; i++)
		num[arr[i].first]++;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 4)
		{
			maxx = max(maxx, i + 800);
		}
	}
	//3번
	
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 3)
		{
			cnt1++;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 2)
		{
			cnt2++;
		}
	}
	if (cnt1 == 1 && cnt2==1)
	{
		int sum = 0;
		for (int i = 1; i < 10; i++)
		{
			if (num[i] == 3)
			{
				sum+=i * 10;
			}
			if (num[i] == 2)
			{
				sum += i + 700;
			}
		}
		maxx = max(sum, maxx);
	}
	//4번
	if ((arr[0].second == arr[1].second) && (arr[1].second == arr[2].second) && (arr[2].second == arr[3].second)
		&& (arr[3].second == arr[4].second))
		maxx = max(maxx, arr[4].first + 600);
	//5번
	if ((arr[0].first == arr[1].first - 1) && (arr[1].first - 1 == arr[2].first - 2) &&
		(arr[2].first - 2 == arr[3].first - 3) &&
		(arr[3].first - 3 == arr[4].first - 4))
		maxx = max(maxx, arr[4].first + 500);
	//6번
	int hi = 0;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 3)
		{
			maxx = max(maxx, 400 + i);
			break;
		}
	}
	//7번
	int cnt = 0;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 2)
		{
			cnt++;
		}
	}
	if (cnt == 2)
	{

		int sum = 0;
		for (int i = 1; i < 10; i++)
		{
			if (num[i] == 2)
			{
				sum += 300 + i;
				break;

			}
		}
		for (int i = 9; i >=1; i--)
		{
			if (num[i] == 2)
			{
				sum += i*10;
				break;
			}
		}
		maxx = max(maxx, sum);
	}
	//8번
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 2)
		{
			maxx = max(maxx, i + 200);
		}
	}
	//9번
	maxx = max(maxx, 100 + arr[4].first);
	cout << maxx;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + 5);
	game();
	return 0;
}
