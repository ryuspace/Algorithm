//https://www.acmicpc.net/problem/16287
/*풀이 : 모든 가능한 두 원소의 합과 위치를 vector에 넣고 찾는 숫자 - 원소의 합인 원소를 찾아서 겹치는 위치가 있는지
비교해준다. 같은 합을 나타내도 위치가 다를 수 있으므로 합의 갯수(upper_bound-lower_bound)만큼 위치를 탐색해서 찾는다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[5001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	vector < pair<int, pair<int, int> > > v;
	int w, n;
	cin >> w >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			v.push_back({ arr[i] + arr[j],{ i,j } });
		}
	}
	sort(v.begin(), v.end());

	for (int i = 0; i<v.size(); i++)
	{
		pair<int, pair<int, int> > a = { w - v[i].first,{ 0,0 } };
		pair<int, pair<int, int> > b = { w - v[i].first,{ n - 1,n } };
		auto it = lower_bound(v.begin(), v.end(), a);
		int num = upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
		while (num--)
		{
			if (it->first == w - v[i].first)
			{
				if (it->second.first != v[i].second.first && it->second.first != v[i].second.second &&
					it->second.second != v[i].second.first && it->second.second != v[i].second.second)
				{
					cout << "YES";
					exit(0);
				}
			}
			it++;
		}
	}
	cout << "NO";
	return 0;

}
