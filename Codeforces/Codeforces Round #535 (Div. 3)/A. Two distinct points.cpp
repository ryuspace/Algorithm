#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int l1, r1, l2, r2;
	int t;
	int a, b;
	cin >> t;
	while (t--)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		a = l1;
		b = l2;
		if (a == b)
		{
			b = b + 1;
		}
		cout << a << " " << b<<'\n';
	}

	return 0;
}
