//https://www.acmicpc.net/problem/14614
/*풀이 : a를 b와 짝수번 xor 연산 하면 a가 나온다. 그러므로 홀수번 연산 할 때는 a xor b가 나온다.*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	long long int a, b;
	string c;
	cin >> a >> b >> c;

	int cnt = c[c.length() - 1] - '0';

	if (cnt % 2 == 0)
	{
		cout << a;
	}
	else
	{
		long long int ans = a ^ b;
		cout << ans;
	}
	return 0;
}
