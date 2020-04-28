/*풀이 
a와 b중 작은거를 1,2,3,... 자연수를 계속 더해본다. 만약 a가 b보다 커졌는데 a에 어떤 자연수를 빼고 b에 어떤 자연수를 더했을 때 
같은 값이 나오면 stop 해준다.*/
#include <iostream>
#include <algorithm>
using namespace std;
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int cnt = 0;
		int fac = 1;
		if (a > b)
		{
			swap(a, b);
		}
		while (a != b)
		{
			if (a > b && (a - b) % 2 == 0)
			{
				break;
			}
			a += fac;
			fac++;
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
