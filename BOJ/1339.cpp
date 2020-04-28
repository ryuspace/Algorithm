//https://www.acmicpc.net/problem/1339
/*풀이 : 알파벳 별로 다항식의 계수를 더해놓고 
다항식의 계수가 큰 순서부터 9부터 0까지 순차적으로 값을 부여한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int n;
bool visit[27];
vector<int> v;
int check[27];
int da[27];
bool cmp(int& a, int& b)
{
	return a > b;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		int fac = (pow(10, tmp.length())) / 10;
		for (int j = 0; j < tmp.length(); j++)
		{
			if (!visit[tmp[j] - 'A'])
			{
				visit[tmp[j] - 'A'] = true;
				v.push_back(cnt);
				check[tmp[j] - 'A'] = cnt++;
			}
			da[check[tmp[j] - 'A']] += fac;
			fac /= 10;
		}
	}
	sort(da, da+cnt,cmp);
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += da[i] * (9 - v[i]);
	}
	cout << sum;
	return 0;
}
