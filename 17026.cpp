//https://www.acmicpc.net/problem/17026
/*풀이 : 산의 왼쪽과 오른쪽의 좌표를 벡터에 담고 
다음 산의 왼쪽 좌표가 이전 산의 오른쪽 좌표보다 오른쪽에 있으면
카운트 해준다. 왼쪽 좌표를 기준으로 sort 했으므로 오른쪽 좌표만 봐주면 된다.
단 왼쪽 좌표가 같을 때에는 오른쪽 좌표를 내림차순으로 해준다.
왜냐하면 왼쪽 좌표가 같으면 오른쪽 좌표가 더 큰 것의 산만 보이기 때문이다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector <pii> v;
bool compare(pair<int, int>&a, pair<int, int>&b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a - b,a + b });
	}
	sort(v.begin(), v.end(), compare);
	int cnt = 1;
	int right = v[0].second;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].second > right)
			cnt++;
		right = max(v[i].second, right);
	}
	cout << cnt;
	return 0;
}
