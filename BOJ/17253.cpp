//https://www.acmicpc.net/problem/17253
/*풀이 : 삼삼한 수랑 문제는 같지만 숫자의 범위가 다르다.
unsinged long long의 범위는
0 ~ (9,223,372,036,854,755,808 + 9,223,372,036,854,755,807)*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unsigned long long int n, start = 1;
	cin >> n;
	if (n == 0)
	{
		cout << "NO";
		exit(0);
	}
	while (start <= n)
	{
		start *= 3;
	}
	start /= 3;
	while (n > 0 && start != 0)
	{
		n -= start;
		start /= 3;
		while (start > n)
		{
			start /= 3;
		}

	}
	if (n == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
