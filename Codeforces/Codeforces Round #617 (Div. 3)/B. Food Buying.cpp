#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;
 
typedef pair<int, int> pii;
 
int arr[2001];
int main(void)
{
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int sum = 0;
		while ((n/10) != 0)
		{
			int hi = n / 10;
			sum += hi * 10;
			n %= 10;
			n += hi;
		}
		sum += n % 10;
		cout << sum << '\n';
 
	}
	return 0;
}
