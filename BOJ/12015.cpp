//https://www.acmicpc.net/problem/12015
/*풀이 : LIS 문제. 다음 숫자가 나왔을 때 현재 존재하는 벡터 안에 적당한 위치가 있으면 그 위치에 값을 넣어주고 여태 나온 숫자보다 크면 push 해준다
nlog(n)만에 해결 가능.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		auto iter = lower_bound(v.begin(), v.end(), a);
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
