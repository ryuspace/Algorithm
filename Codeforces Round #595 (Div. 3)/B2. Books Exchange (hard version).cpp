//책을 건네주는 사이클을 찾아 같은 사이클은 같은 지나온 날짜를 부여한다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int arr[200001];
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;
	while (t--)
	{
		int ans[200001] = { 0, };
		bool visit[200001] = { 0, };
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++)
		{
			vector<int> v;
			if (!visit[i])
			{
				while (!visit[i])
				{
					v.push_back(i);
					visit[i] = true;
					i = arr[i];
				}
				for (int i = 0; i < v.size(); i++)
				{
					ans[v[i]] = v.size();
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
