//https://www.acmicpc.net/problem/2312
/*풀이 : 2부터 n까지 주어진 숫자를 나눌 수 있는지 판단해본다. 만약 나눌 수 있다면
그 수로 나눌 수 있을 때 까지 진행해주고 결과를 출력해준다.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		while (n != 1)
		{
			for (int i = 2; i <=n; i++)
			{
				if (n % i == 0)
				{
					int cnt = 0;
					while (n!= 1)
					{
						n /= i;
						cnt++;
						if (n % i != 0)
							break;
					}
					cout << i << " " << cnt << '\n';
				}
			}
		}

	}
	return 0;
}

