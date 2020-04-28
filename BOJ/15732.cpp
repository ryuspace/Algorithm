//https://www.acmicpc.net/problem/15732
/*풀이 : 상자 번호를 이분탐색으로 찾는다. 
만약 이 상자번호가 조건 안에 있거나 조건 보다 큰 경우면 해당 범위 안에 있는 도토리를 세어준다. 
O(log(100만*log(loo만))으로 해결 가능하다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point
{
	int a, b, c;
};
vector<point> v;
int minn = 1e9;
int maxx = 0;
int n, k, t;
point tmp;
bool func(int mid)
{
	long long sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (mid >= v[i].a && mid <= v[i].b)
		{
			sum += (((mid - v[i].a) / v[i].c) + 1);
		}
		else if (mid >= v[i].a && mid >= v[i].b)
		{
			sum += (((v[i].b - v[i].a) / v[i].c) + 1);
		}
	}
	if (sum < t)
		return true;
	else
		return false;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> t;
	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
		minn = min(minn, a);
		maxx = max(maxx, b);
	}
	int left = minn;
	int right = maxx;
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (func(mid))
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}

	}
	cout << ans;

}
