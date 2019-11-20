//https://www.acmicpc.net/problem/17952
/*풀이 : 스택이 벡터보다 메모리를 덜 먹는다.*/
#include <iostream>
#include <stack>
using namespace std;
stack<pair<int, int>> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			s.push({ b,c });
		}
		if (!s.empty())
		{
			s.top().second--;
			if (s.top().second == 0)
			{
				sum += s.top().first;
				s.pop();
			}
		}
	}
	cout << sum;
	return 0;
}
