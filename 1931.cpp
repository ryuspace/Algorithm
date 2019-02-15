//https://www.acmicpc.net/problem/1931
/*풀이 : 끝나는 시간으로 오름차순 정렬을 한다. 처음부터 끝나는 시간 기준으로 가장 빠른 시작시간을 찾는다.*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pii;
vector <pii> v;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), cmp);
	int cnt = 1;
	int start = v[0].second;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first >= start)
		{
			cnt++;
			start = v[i].second;
		}
	}
	cout << cnt;
	return 0;
}
