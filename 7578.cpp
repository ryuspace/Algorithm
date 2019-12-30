//https://www.acmicpc.net/problem/7578
/*풀이 : 세그먼트 트리를 이용해서 이 인덱스에 몇개가 교차하는지 찾는다.
교차할 수 있는 선의 갯수는 최대 500000*250000 이므로 long long 을 써준다.

*/
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[500001];
long long arr2[1000001];
long long seg[4000004];
void update(long long idx, long long left, long long right, long long node)
{
	if (right < idx || left > idx)
	{
		return;
	}
	if (left == right)
	{
		seg[node]++;
		return;
	}
	long long mid = (left + right) / 2;
	update(idx, left, mid, node * 2);
	update(idx, mid + 1, right, node * 2 + 1);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
long long find(long long start,long long end, long long left, long long right, long long node)
{
	
	if (right < start || end < left)
	{
		return 0;
	}
	if (left<=start && right>=end)
	{
		return seg[node];
	}
	long long mid = (start + end) / 2;
	return find(start, mid, left, right, node * 2) + find(mid+1, end, left, right, node * 2 + 1); 

}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i =1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		arr2[a] = i;
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		
		sum += find(1,n,arr2[arr[i]]+1,n,1);//i번째 인덱스에 선을 연결할건데 이 인덱스 뒤에 연결되어 있는 갯수를 찾는다.
		update(arr2[arr[i]],  1, n, 1);//이번 인덱스에 연결되어있는 것을 표시.
	}
	
	cout << sum;
	return 0;

}
