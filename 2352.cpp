//https://www.acmicpc.net/problem/2352
/*풀이 : 왼쪽 포트가 오른쪽 포트에 연결할 때 오름차순으로 연결하므로 오른쪽 포트에 대해
LIS를 찾으면 된다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
vector<int> v;
vector<int>::iterator iter;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		iter = lower_bound(v.begin(), v.end(), a);
		if (iter == v.end())
		{
			v.push_back(a);
		}
		else
		{
			*iter = a;
		}
	}
	cout << v.size();
	return 0;
}
