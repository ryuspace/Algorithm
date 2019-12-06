//http://codeforces.com/contest/1265/problem/A
/*풀이 : ?가 나올 때 마다 앞 뒤 문자를 판별하여 적당한 알파벳을 넣어준다. */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		bool f = 0;
		string tmp;
		cin >> tmp;
		for (int i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] == '?')
			{
				for (int j = 'a'; j <= 'c'; j++)
				{
					if (i == 0)
					{
						if (char(j) != tmp[i+1])
						{
							tmp[i] = char(j);
							break;
						}
					}
					else if (i == tmp.length() - 1)
					{
						if (char(j) != tmp[i-1])
						{
							tmp[i] = char(j);
							break;
						}
					}
					else
					{
						if (char(j) != tmp[i - 1] && char(j)!=tmp[i+1])
						{
							tmp[i] = char(j);
							break;
						}
					}
				}
			}
			else
			{
				if (i+1<tmp.length() && tmp[i] == tmp[i + 1])
				{
					f = 1;
					break;
				}
			}
			
		}
		if (f == 1)
			cout << -1 << '\n';
		else
			cout << tmp << '\n';
	}

	return 0;
}

