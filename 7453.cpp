//https://www.acmicpc.net/problem/7453
/*풀이 : 완탐으로는 시간이 n^4가 나오므로 시간초과가 뜬다. 우선 a와 가능한 b를 모두
더하고 c와 가능한 d를 모두 더한다. 그리고 그 더한 것들에 대해 이분탐색을 실행한다.
둘이 더해서 0이 나오는 것을 lower_bound, upper_bound를 이용해서 찾는다. 약 n^2으로 줄였다*/
#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int a[4000];
int b[4000];
int c[4000];
int d[4000];

vector <int> v_a;
vector <int> v_c;
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	long long int cnt = 0;//cnt는 n^4까지 나올 수 있으므로 long long int 형식으로 해야한다
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v_a.push_back(a[i] + b[j]);
			v_c.push_back(c[i] + d[j]);
		}
	}
	sort(v_c.begin(), v_c.end());
	for (int i = 0; i < n*n; i++)
	{
		cnt += upper_bound(v_c.begin(), v_c.end(), -v_a[i]) - lower_bound(v_c.begin(), v_c.end(), -v_a[i]);
	}
	cout << cnt;
	return 0;
}
