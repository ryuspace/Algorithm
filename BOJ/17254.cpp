//https://www.acmicpc.net/problem/17254
/*풀이 : 구조체를 cmp 함수를 이용해 정렬해보는 방법을 배웠다.*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct point {
	int x, y;
	char c;
};
bool cmp(const point& a, const point& b)
{
	if (a.y < b.y)
	{
		return true;
	}
	else if (a.y == b.y)
	{
		return a.x < b.x;
	}
	else
		return false;
}
vector<point> v;
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].c;
	}

	return 0;
}
