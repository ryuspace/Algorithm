//https://www.acmicpc.net/problem/13160
/*풀이 : 시작점을 -1,끝점을 1로 잡는다. 정렬 한 후 -1의 갯수가 최대가 될 때
그 곳이 가장 많이 겹치는 곳이다. 그 겹치는 곳 기준으로 시작점이 겹치는 곳보다 작거나 같고,
끝 점이 겹치는 곳보다 크거나 같으면 그 선분은 클리크이다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int> >v;
vector <pair<int, int> > ans;

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,-1 });//시작점은 -1로 잡는다.
		v.push_back({ b,1 });//끝점은 1로 잡는다.
		ans.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int num = 0;
	int mini = 0;
	int pos= 0;
	for (int i = 0; i < 2*n; i++)
	{
		num += v[i].second;
		if (num < mini)
		{
			mini = num;
			pos = v[i].first;
		}
	}
	cout << -mini << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i].first <= pos && ans[i].second >= pos)
			cout << i + 1 << " ";
	}

	return 0;
}
