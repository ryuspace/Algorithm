//https://www.acmicpc.net/problem/15745
/*풀이 : 부츠 중에서 깊은 부츠를 기준으로 시작한다.
길에서 갈 수 없는 길이가 그 부츠의 갈 수 있는 길이보다 크다면 불가능 하다.
현재 상태에서 갈 수 없는 길이는 최소 다음 상태의 길이이다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > mp;
vector<pair<pair<int, int>, int> > boots;
bool use[100001];
int parent[100001];
int sizz[100001];
bool ans[100001];
int maxx = 0;
int find(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	parent[a] = b;
	sizz[b] += sizz[a];
	sizz[a] = 1;
	maxx = max(maxx, sizz[b]);
}
int main() {
	
	ios_base::sync_with_stdio(0);
	int n,r;
	cin >> n >> r;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (i != 0 && i != n - 1)
		{
			mp.push_back({ a,i });
			parent[i] = i;
			sizz[i] = 1;
		}
	}
	for (int i = 0; i < r; i++)
	{
		int a, B;
		cin >> a >> B;
		boots.push_back({ {a,B},i });
	}
	sort(mp.begin(), mp.end());
	sort(boots.begin(), boots.end());
	int idx = n - 3;
	for (int i = r-1; i >= 0; i--)
	{
		while (idx >= 0 && mp[idx].first > boots[i].first.first)
		{
			maxx = max(1, maxx);
			use[mp[idx].second] = true;
			if (use[mp[idx].second - 1])
				merge(mp[idx].second - 1, mp[idx].second);
			if (use[mp[idx].second + 1])
				merge(mp[idx].second, mp[idx].second + 1);
			idx--;
		}
		if (maxx >= boots[i].first.second)
			ans[boots[i].second] = true;
	}
	for (int i = 0; i < r; i++)
	{
		if (ans[i])
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
	return 0;
}

