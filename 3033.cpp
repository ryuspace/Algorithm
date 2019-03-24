//https://www.acmicpc.net/problem/3033
/*풀이 : 라빈카프 알고리즘. 문자열을 해싱한다!
각 문자의 아스키코드와 2와 2^63(long long 범위)의 서로소의
적당한 수를 찾아서(char형은 2^7이니까 여기랑 비슷한 수)
해싱한다! 최대한 중복을 방지하기 위해서
디디님 감사합니다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

long long int p[200001];

int main()
{
	ios_base::sync_with_stdio(0);

	long long int n;
	string tmp;
	cin >> n >> tmp;
	long long int le = 1;
	long long int ri = tmp.length();
	long long int res = 0;
	p[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * 129;
	}
	while (le <= ri)
	{
		long long int maxx = 0;
		long long int mid = (le + ri) / 2;
		long long int hash = 0;
		for (int i = 0; i < mid; i++)
		{
			hash += tmp[i] * p[mid - i];
		}
		unordered_set<long long int> s;
		s.insert(hash);
		for (int i = mid; i < n; i++)
		{
			hash = (hash - tmp[i - mid] * p[mid]) * 129 + p[1] * tmp[i];
			if (s.count(hash))
			{
				maxx = mid;
				break;
			}
			s.insert(hash);
		}
		if (res<maxx)
		{
			res = maxx;
			le = mid + 1;
		}
		else
		{
			ri = mid - 1;
		}
	}
	cout << res;
	return 0;
}
