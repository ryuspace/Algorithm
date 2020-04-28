/*풀이 : 돈의 가치와 갯수가 주어지면 그 돈으로 S의 값을 만들 수 있는지.
수의 크기 제한 때문에 간단한 식 하나로 해결해야한다.
우선 n의 가치의 돈을 얼마나 낼 수 있는지 체크하고
나머지 1의 돈으로 다 낼 수 있는지 체크한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int a, b, n, S,hi;
		cin >> a >> b >> n >> S;
		hi = S / n;
		if (a < hi)
		{
			hi = a;
		}
		S = S - hi * n;
		if(b>=S)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}
