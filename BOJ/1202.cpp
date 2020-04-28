//https://www.acmicpc.net/problem/1202
/*풀이 : 수용할 수 있는 무게가 적은 가방부터 담을 수 있는 보석을 담는다.(map에서 관리) 
담긴 보석중에 가장 가치가 큰 것을 선택 후 삭제한다.*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <pair<int, int> > v1;
vector <int> v2;

map<int, int> m;
int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	long long int cnt = 0;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v1.push_back({ a,b });
	}
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		v2.push_back(a);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int idx = 0;

	for (int i = 0; i < v2.size(); i++)
	{
		if (idx < v1.size())
		{
			while (v1[idx].first <= v2[i])
			{
				m[v1[idx].second]++;
				idx++;
				if (idx >= v1.size())
					break;
			}
		}
		if (!(m.empty()))
		{
			auto iter = --(m.end());
			cnt += iter->first;
			m[iter->first]--;
			if (m[iter->first] == 0)
				m.erase(iter);
		}
	}
	cout << cnt;
	return 0;
}
