//https://www.acmicpc.net/problem/14465
/*처음 k개 만큼 신호등에서 몇 개가 고장난지 미리 파악한다. 그리고 k+1개 부터 n개만큼 
뒤에 한개를 추가하고 앞에 한개를 빼는 식으로 계속 찾는다.*/
#include <iostream>
#include <algorithm>

using namespace std;

bool broken[100001];

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, k, b;
	int sum = 0;
	cin >> n >> k >> b;
	for (int i = 1; i <= b; i++)
	{
		int a;
		cin >> a;
		broken[a] = true;
	}

	for (int i = 1; i <= k; i++)
	{
		if (broken[i] == true)
			sum++;
	}
	int mini = 9999999;

	for (int i = k + 1; i <= n; i++)
	{
		if (broken[i - k] == true)
			sum--;
		if (broken[i])
			sum++;
		mini = min(mini, sum);
	}

	cout << mini;

	return 0;
}
