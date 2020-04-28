//https://www.acmicpc.net/problem/2143
/*풀이 : v1벡터와 v2벡터에 각각 A와 B의 부분합을 넣는다.
그리고 upper_bound,lower_bound를 이용하여 찾는다.*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v1;
vector <int> v2;

int arr1[1001];
int arr2[1001];

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int t, n, m;
	cin >> t;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}
	int sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 = arr1[i];
		v1.push_back(sum1);

		for (int j = i + 1; j < n; j++)
		{
			sum1 += arr1[j];
			v1.push_back(sum1);
		}
	}

	int sum2 = 0;
	for (int i = 0; i < m; i++)
	{
		sum2 = arr2[i];
		v2.push_back(sum2);

		for (int j = i + 1; j < m; j++)
		{
			sum2 += arr2[j];
			v2.push_back(sum2);
		}
	}
	sort(v2.begin(), v2.end());

	long long int ans = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		int num = t - v1[i];

		auto upp = upper_bound(v2.begin(), v2.end(), num);
		auto dwn = lower_bound(v2.begin(), v2.end(), num);
		ans += upp - dwn;
	}
	cout << ans;
	return 0;
}
