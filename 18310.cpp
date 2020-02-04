//https://www.acmicpc.net/problem/18310
/*풀이 : 자신의 집을 기준으로 부분합을 이용해 
왼쪽 오른쪽 집의 인덱스의 합과, 집의 갯수를 미리 받아놓는다.
그리고 최소를 탐색..
근데 집들을 쭉 나열했을 때 가운데에 있는 집이 답이라고 한다.. 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int arr[200001];
pll idx1[200001];
pll idx2[200001];
typedef pair<int, int> pii;

int main(void)
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
		arr[a] += 1;
	}
	vector<pii> v;
	for (int i = 1; i <= 200000; i++)
	{
		if (arr[i] != 0)
		{
			v.push_back({ i,arr[i] });
		}
	}
	for (int i = 1; i <v.size(); i++)
	{
		idx1[i].first = idx1[i - 1].first + (v[i - 1].first) * v[i - 1].second;
		idx1[i].second = idx1[i - 1].second + v[i - 1].second;
	}
	for (int i = v.size()-2; i >= 0; i--)
	{
		idx2[i].first = idx2[i + 1].first + (v[i + 1].first) * v[i + 1].second;
		idx2[i].second = idx2[i + 1].second + v[i + 1].second;
	}
	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << idx1[i].first << " " << idx2[i].first << '\n';
	//}
	ll minn = 1e18;
	int min_idx = 0;
	for (int i = 0; i < v.size(); i++)
	{
		//cout << ((v[i].first * (idx1[i].second)) - idx1[i].first) + (idx2[i].first - (v[i].first * (idx2[i].second))) << '\n';
		if (minn > ((v[i].first * (idx1[i].second)) - idx1[i].first) + (idx2[i].first - (v[i].first * (idx2[i].second))))
		{
			minn = ((v[i].first * (idx1[i].second))-idx1[i].first) + (idx2[i].first - (v[i].first * (idx2[i].second)));
			min_idx = v[i].first;
		}
		
	}
	cout << min_idx;
	return 0;
}
