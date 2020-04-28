#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
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
		int hol = 0;
		int jjak = 0;
		int a,sum=0;
		cin >> a;
		for (int i = 0; i < a; i++)
		{
			cin >> arr[i];
			if (arr[i] % 2 == 1)
				hol++;
			else
				jjak++;
			sum += arr[i];
			
		}
		if (sum % 2 == 1)
		{
			cout << "YES" << '\n';
		}
		else
		{
			if (hol >= 1 && jjak >= 1)
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
		}
 
	}
	return 0;
}
