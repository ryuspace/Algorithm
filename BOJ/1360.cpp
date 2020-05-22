//https://www.acmicpc.net/problem/1360
/*풀이 :
쿼리들을 우선 담고 마지막 쿼리부터 수행하면 된다.
쿼리를 탐색하는데 undo가 나오면 시간 범위 내까지 무시하면 된다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
struct point
{
	string a;
	string b;
	int c;
};
vector<point> s;
string tmp;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--)
	{
		string a;
		string b;
		int c;
		cin >> a >> b >> c;
		s.push_back({ a,b,c });
	}
	string tmp = "";
	while (!s.empty())
	{
		if (s.back().a == "type")
		{
			tmp = s.back().b + tmp;
			s.pop_back();
		}
		else
		{
			int time = s.back().c - stoi(s.back().b);
			s.pop_back();
			while (!s.empty() && s.back().c >= time)
			{
				s.pop_back();
			}
		}
	}
	cout << tmp;
	return 0;
}
