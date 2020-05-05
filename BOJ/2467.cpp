//https://www.acmicpc.net/problem/2467
/*풀이 : 
합이 0인 네 정수 문제와 비슷했다.
현재 숫자 기준으로 현재 숫자의 음수와 가장 가까운 수를 이분탐색으로 찾는다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
int mini = 2000000002;
pair<int, int> num;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int idx = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();
		if (idx == n)
		{
			idx--;
			if (v[idx] == v[i])
				continue;
			if (abs(v[idx] + v[i]) < mini)
			{
				mini = abs(v[idx] + v[i]);
				num = { v[idx],v[i] };
			}
		}
		else if(idx==0)
		{
			if (v[idx] == v[i])
				continue;
			if (abs(v[idx] + v[i]) < mini)
			{
				mini = abs(v[idx] + v[i]);
				num = { v[idx],v[i] };
			}
		}
		else
		{
			if (v[idx] == v[i])
				continue;
			if (abs(v[idx] + v[i]) < mini)
			{
				mini = abs(v[idx] + v[i]);
				num = { v[idx],v[i] };
			}
			idx--;
			if (v[idx] == v[i])
				continue;
			if (abs(v[idx] + v[i]) < mini)
			{
				mini = abs(v[idx] + v[i]);
				num = { v[idx],v[i] };
			}
		}
	}
	if(num.first<num.second)
		cout << num.first << " " << num.second;
	else
		cout << num.second << " " << num.first;

	return 0;
}
