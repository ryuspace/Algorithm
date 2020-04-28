//수를 나눴을 때 2가 나오면 안된다. 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		long long int n;
		cin >> n;
		while (true) {
			bool ok = true;
			int cur = n;
			while (cur > 0) {
				if (ok && cur % 3 == 2)
				{
					ok = false;
					break;
				}
				cur /= 3;
			}
			if (ok) 
				break;
			++n;
		}
		cout << n << endl;
	}
 
	return 0;
}
