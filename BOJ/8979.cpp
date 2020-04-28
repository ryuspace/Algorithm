//https://www.acmicpc.net/problem/8979
/*풀이 : 구조체 정렬을 다시 되새겨 주는 문제*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ran
{
	int num, a, b, c;
};
bool cmp(ran& aa, ran& bb)
{
	if (aa.a > bb.a)
		return true;
	else if (aa.a == bb.a)
	{
		if (aa.b > bb.b)
			return true;
		else if (aa.b == bb.b)
			return aa.c > bb.c;
		else
			return false;
	}
	else
		return false;
}
vector <ran> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a, b, c,d;
		cin >> a >> b >> c >> d;
		v.push_back({ a,b,c,d });
	}
	int now = 1;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		if (!(v[i - 1].a == v[i].a && v[i - 1].b == v[i].b && v[i - 1].c == v[i].c))
		{
			now = i + 1;
		}
		if (v[i].num == k)
			cout << now;
	}
	return 0;
}
