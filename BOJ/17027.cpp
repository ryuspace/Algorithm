//https://www.acmicpc.net/problem/17027
/*풀이 : 껍데기는 총 3개가 있다. 모든 껍데기에 한번씩 돌을 넣고 
swap한 결과중 최대를 찾는다. */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int arr[4];
vector< pair<pair<int, int>, int> > v;

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int maxx = 0;
	for (int j = 0; j < n; j++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ { a,b },c });
	}
	for (int i = 1; i <= 3; i++)
	{
		memset(arr, 0, sizeof(arr));
		arr[i] = 1;
		int cntt = 0;
		for (int j = 0; j < n; j++)
		{
			int tmp1 = arr[v[j].first.first];
			int tmp2 = arr[v[j].first.second];
			arr[v[j].first.second] = tmp1;
			arr[v[j].first.first] = tmp2;
			if (arr[v[j].second] == 1)
				cntt++;
		}
		maxx = max(maxx, cntt);
	}
	cout << maxx;
	return 0;
}
