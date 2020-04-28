//https://www.acmicpc.net/problem/6549
/*풀이 : 세그먼트 트리로 현재 구간의 최대 넓이를 구하고 그 넓이의 역할을 하는 인덱스를
구한다. 또한 그 인덱스를 기준으로 좌우를 확인해 그 좌우의 넓이를 구하고 이를 반복해 
전체의 최대 넓이를 구한다.*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[100001];
long long int tree[400100];
long long int maxx = 0;
void init(int start, int end, int node)//트리를 구간에서의 높이의 최소를 가지는 인덱스로 구성한다.
{
	if (start == end)
	{
		tree[node] = start;
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);

	if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]])
		tree[node] = tree[node * 2];
	else
		tree[node] = tree[node * 2 + 1];
}
long long int quer(int start, int end, int left, int right, int node)
{
	if (left > end || right < start)
	{
		return -1;
	}
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	long long int left_quer = quer(start, mid, left, right, node * 2);
	long long int right_quer = quer(mid + 1, end, left, right, node * 2 + 1);
	if (left_quer == -1)
	{
		return right_quer;
	}
	else if (right_quer == -1)
	{
		return left_quer;
	}
	else if (arr[left_quer] < arr[right_quer])
		return left_quer;
	else
		return right_quer;
}

long long int findd(int start, int end)
{

	int idx = quer(1, n, start, end, 1);//이 구간에서의 최소 인덱스
	long long int area = 1LL * (end - start + 1) * arr[idx];
	if (start < idx)//좌측의 넓이 체크
	{
		long long int tmp = findd(start, idx - 1);
		area = max(tmp, area);
	}
	if (end > idx)//우측의 넓이 체크
	{
		long long int tmp = findd(idx + 1, end);
		area = max(tmp, area);
	}
	return area;

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n != 0)
	{
		maxx = 0;
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		init(1, n, 1);
		maxx = findd(1, n);
		cout << maxx << '\n';
		cin >> n;
	}
	return 0;
}
