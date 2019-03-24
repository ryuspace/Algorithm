//https://www.acmicpc.net/problem/5052
/*풀이 : 문자열을 벡터에 받고 sort 한다. 만약 이전에 나온 문자가
현재 문자열의 접두어이면 일관성이 없는 것이다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	int t,n;
	cin >> t;
	while (t--)
	{
		vector<string> v;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		bool flag = true;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i - 1] == v[i].substr(0, v[i - 1].size()))
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}
