//https://www.acmicpc.net/problem/1764
/*풀이 : 벡터 내에서 binary_search 하는 방법을 배웠다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <string> v;
vector <string> ans;
int main()
{
	int n, m;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		if (binary_search(v.begin(), v.end(), name))
		{
			ans.push_back(name);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
