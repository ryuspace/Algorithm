//https://www.acmicpc.net/problem/17131
/*풀이 y를 기준으로 모든 x좌표를 삽입하고 y의 좌우의 별의 갯수의 합을 구한다.
단 y를 오름차순으로 탐색해야 가능하다.
N의 범위 때문에 세그먼트 트리를 이용해 시간을 줄인다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define mod 1000000007
#define MAX 400002
int n, x, y;
vector<int> v[MAX];
long long int tree[1600100];

void update(int start, int end, int node, int idx)
{
	if (!(idx >= start && idx <= end))
	{
		return;
	}
	tree[node] ++;//이 위치에 별이 있다.
	if (start != end)
	{
		update(start, (start + end) / 2, node * 2, idx);
		update((start + end) / 2 + 1, end, node * 2 + 1, idx);
	}
}
long long sum(int start, int end, int left, int right, int node)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	return sum(start, (start + end) / 2, left, right, node * 2) + sum((start + end) / 2 + 1, end, left, right, node * 2 + 1);

}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		x += 200001;
		y += 200001;
		v[y].push_back(x);
	}
	for (int i = 400001; i >= 0; i--)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			ans = (ans + 1LL * sum(0, MAX, 0, v[i][j] - 1, 1) * sum(0, MAX, v[i][j] + 1, MAX, 1)) % mod;//왼쪽에 n개 오른쪽에 m개 있으면 총 별의 갯수는 n*m개.
		}

		for (int j = 0; j < v[i].size(); j++)
		{
			update(0, MAX, 1, v[i][j]);
		}
	}
	cout << ans;
	return 0;
}

