//https://www.acmicpc.net/problem/18234
/*풀이 : 처음에는 당근을 아예 안 먹었다 가정했을 때 마지막 날 당도가 최고인 당근부터
먹는 것이 맞다고 생각했지만 반례로 1 99
                                   50 51 을 찾았다.
p가 적으면 굳이 마지막 날에 먹기보단 미리먹어도 손해가 적다. 
그러므로 마지막 날 기준으로 p가 큰 순서대로 먹는다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
ll arr[200001];
vector<pll> v;
ll n, t, w;
ll sum;
bool cmp(pll& a, pll& b)
{
	return a.second > b.second;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i] >> w;
		arr[i] += w * (t - 1);
		v.push_back({ arr[i],w });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		sum += v[i].first - i * v[i].second;
	}
	cout << sum;
	return 0;
}
