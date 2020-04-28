//https://www.acmicpc.net/problem/10868
/*풀이 : N이 10만이고 쿼리가 10만이므로 1초안에는 못 푼다.. 하지만 세그먼트 트리를 이용하면
10만 * log(10만)이므로 통과가 된다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int tree[400004];
int init(int start, int end, int node)//구간 중에 최소를 찾자
{
	if (start == end)
	{
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
int mini(int start, int end, int node, int left, int right)//원하는 구간 중에 최소를 찾자
{
	if (left > end || right < start)
		return 1e9;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	return min(mini(start, mid, node * 2, left, right), mini(mid + 1, end, node * 2 + 1, left, right));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);//이 세 개 안 해주면 시간초과 뜬다.
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	init(1, n, 1);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << mini(1, n, 1, a, b) << '\n';;
	}

	return 0;
}
