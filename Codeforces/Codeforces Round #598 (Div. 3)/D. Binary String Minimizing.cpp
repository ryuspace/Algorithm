/*풀이 : 0이 있는 인덱스를 기준으로 앞에 있는 최대한 많은 1과 swap을 한다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> pii;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int q;
	cin >> q;
	while (q--)
	{
		bool hi[1000001] = { false, };
		vector<long long int> v;
		long long int n, k;
		long long int mae = 0;

		string tmp;
		cin >> n >> k;
		cin >> tmp;
		for (int i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] == '0')
			{
				if (k >= i-mae)
				{
					k -= (i-mae);
					hi[mae] = true;
					mae++;
				}
				else
				{
					hi[i - k] = true;
					k = 0;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			cout << !hi[i];
		}
		cout << '\n';
	}
	return 0;
}
