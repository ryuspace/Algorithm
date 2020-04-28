//https://www.acmicpc.net/problem/15463
#include <iostream>
#include <algorithm>

using namespace std;
int arr[2001][2001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int x1, y1, x2, y2, a1, b1, a2, b2, t1, r1, t2, r2;
	cin >> x1 >> y1 >> x2 >> y2 >> a1 >> b1 >> a2 >> b2 >> t1 >> r1 >> t2 >> r2;
	x1 += 1000;
	y1 += 1000;
	x2 += 1000;
	y2 += 1000;
	a1 += 1000;
	b1 += 1000;
	a2 += 1000;
	b2 += 1000;
	t1 += 1000;
	r1 += 1000;
	t2 += 1000;
	r2 += 1000;

	for (int i = x1 + 1; i <= x2; i++)
	{
		for (int j = y1 + 1; j <= y2; j++)
		{
			arr[i][j] = 1;
		}
	}

	for (int i = a1 + 1; i <= a2; i++)
	{
		for (int j = b1 + 1; j <= b2; j++)
		{
			arr[i][j] = 1;
		}
	}
	for (int i = t1 + 1; i <= t2; i++)
	{
		for (int j = r1 + 1; j <= r2; j++)
		{
			arr[i][j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 2000; i++)
	{
		for (int j = 0; j <= 2000; j++)
		{
			if (arr[i][j] == 1)
				cnt++;
		}
	}
	cout << cnt;
	return 0;

}
