//https://www.acmicpc.net/problem/1629
/*풀이 : a^b을 쪼개보면 짝수일 때 a^(b/2)*a(b/2) 홀수일 때 a^(b-1)*a
인 것을 알 수 있다. 이를 이용하여 재귀함수를 사용한다.*/
#include <iostream>

using namespace std;

typedef long long int ll;
ll poww(ll a, ll b, ll c)
{
	if (b ==0)
	{
		return 1;
	}
	
	if (b%2 == 0)
	{
		return (ll)((ll)poww(a, b / 2, c)*(ll)poww(a, b / 2, c) %c);

	}
	else if (b%2 == 1)
	{
		return (ll)poww(a, b - 1, c)*a %c;
	}
	
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;

	cout<<(ll)poww(a, b, c);
}
