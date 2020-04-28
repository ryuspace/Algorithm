//https://www.acmicpc.net/problem/11974
/*풀이 : 나머지 합과 유사한 문제 부분합을 구한 배열의 %7한 값을 저장 후, 숫자가 같은 한 쌍중 서로의 인덱스가 가장 먼 걸 찾는다.*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long int arr[50001];
long long int cnt[50001];
vector< pair<long long int, long long int> >v;
int main()
{
	long long int sum = 0;
	long long int n, m;
	cin >> n;
	arr[0] = 0;
	v.push_back({ 0,0 });
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] = arr[i] + arr[i - 1];
		arr[i] %= 7;
		v.push_back({ arr[i],i });
		cnt[arr[i]]++;
	}

	sort(v.begin(), v.end());



	long long int Max = 0;
	long long int start = v[0].first;
	long long int start_n = v[0].second;
	for (int i = 0; i < v.size(); i++)
	{

		if (start == v[i].first)
		{
			Max = max(v[i].second - start_n, Max);
		}
		else
		{
			start = v[i].first;
			start_n = v[i].second;
			Max = max(v[i].second - start_n, Max);
		}

	}

	cout << Max;

	return 0;
}
