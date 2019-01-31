//https://www.acmicpc.net/problem/14527
/*풀이 : 마릿수대로 생산량에대해 정렬해서 양사이드에서 마릿수를 줄여가면서 최대값을 찾는다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector < pair<int,int> > v;
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());

	int left = 0;
	int right = n - 1;
	int Max = 0;
	int Min = 1e9;
	while (left < right)
	{
		Max = max(Max,v[left].first+v[right].first);
		Min = min(v[left].second, v[right].second);
		v[left].second -= Min;
		v[right].second -= Min;
		if (v[left].second == 0)
		{
			left++;
		}
		if (v[right].second == 0)
		{
			right--;
		}
	}
	if (left == right)
	{
		Max = max(Max, v[left].first + v[right].first);
	}
	cout << Max;
	return 0;
}
