//https://www.acmicpc.net/problem/1946
/*풀이 : 지원자의 서류순위든 면접순위든 하나를 기준으로 잡고 오름차순으로 정렬한다.
그리고 나머지 요소에 대해 이전에 나온 지원자중 나보다 높은 요소가 있으면 그 지원자는
선발될 수 없다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
int t, n;
pii arr[100001];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[i] = { a,b };
		}
		sort(arr,arr+n);
		int minn= 1e9;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].second > minn)
			{
				cnt++;
			}
			minn = min(minn, arr[i].second);
		}
		cout << n-cnt << '\n';
	}
	return 0;
}
