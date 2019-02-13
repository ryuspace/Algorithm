//https://www.acmicpc.net/problem/15760
/*풀이 : 원래 위치에서 정렬된 곳에서의 위치의 최대가 횟수..*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int> >v;
vector<pair<int, int> >v2;//소트할거
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back({ a,i });
		v2.push_back({ a,i });
	}
	sort(v2.begin(), v2.end());
	int Max = 0;
	for (int i =0 ; i<n; i++)
	{
		v2[i].second - i;
		Max=max(Max, v2[i].second - i);
	}

	cout << Max+1;


	return 0;
}
