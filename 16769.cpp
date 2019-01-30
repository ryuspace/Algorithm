//https://www.acmicpc.net/problem/16769
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int c1, c2, c3;
	int m1, m2, m3;
	int cnt = 0;
	cin >> m1 >> c1 >> m2 >> c2 >> m3 >> c3;
	while (true)
	{
		if (c1 + c2 > m2)
		{
			c1 = c1 - (m2 - c2);
			c2 = m2;
			cnt++;
		}
		else
		{
			c2 = c1 + c2;
			c1 = 0;
			cnt++;
		}
		if (cnt == 100)
		{
			cout << c1 << '\n' << c2 << '\n' << c3 << '\n';
			break;
		}
		if (c2 + c3 > m3)
		{
			c2 = c2 - (m3 - c3);
			c3 = m3;
			cnt++;
		}
		else
		{
			c3 = c2 + c3;
			c2 = 0;
			cnt++;
		}

		if (c3 + c1 > m1)
		{
			c3 = c3 - (m1 - c1);
			c1 = m1;
			cnt++;
		}
		else
		{
			c1 = c1 + c3;
			c3 = 0;
			cnt++;
		}
	}
	return 0;
}
