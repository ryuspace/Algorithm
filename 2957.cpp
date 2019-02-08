//https://www.acmicpc.net/problem/2957
/*문제에서 C는 여탯동한 더한 깊이 + 현재 노드의 깊이다. bst를 사용해서 탐색시간을 log(n)으로
줄일 수 있다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

map <int, ll> m;

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	ll cnt = 0;
	cin >> n;
	m[0] = -1;
	m[300001] = -1;
	map <int, ll> ::iterator lower;
	map <int, ll> ::iterator upper;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		lower = -- (m.lower_bound(a));
		upper = m.upper_bound(a);
		long long int dep = max(lower->second, upper->second)+1;
		m[a] = dep;
		cnt += dep;
		cout << cnt<<'\n';
	}

	return 0;
}
