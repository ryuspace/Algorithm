//https://www.acmicpc.net/problem/15352
/*풀이 : 각 배열의 왼쪽과 오른쪽의 인덱스를 담는 배열을 두개를 만든다.
union하는 조건은 나의 왼쪽 또는 오른쪽에 같은 팬클럽 일 때 union 한다.
delete하고 나서도 합쳐지는 왼쪽,오른쪽이 같으면 union 해준다.*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];
int parent[1000001];
long long int cntt[1000001];
int le[1000001];
int ri[1000001];


int find(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	parent[a] = b;
	cntt[b] += cntt[a];
}
void del(int a)
{
	cntt[find(a)]--;
	int L = le[a];
	int R = ri[a];
	le[R] = L;
	ri[L] = R;
	if (arr[L] == arr[R])
		merge(L, R);
}
int main() {
	
	ios_base::sync_with_stdio(0);
	int k, n;
	cin >> k >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		le[i] = i - 1;
		ri[i] = i + 1;
		cntt[i] = 1;
		parent[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			merge(i-1, i);
		}
	}
	int q;
	long long int res = 0;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
			del(b);
		else
			res += cntt[find(b)];
	}
	cout << res;
	return 0;
}

