//https://www.acmicpc.net/problem/17024
/*풀이 : 한 노드에서 다른 노드로 가는 간선의 최대갯수 +1이
필요한 색이다*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b;
int arr[100001];
int main()
{
	cin >> n;
	for (int i = 1; i <n; i++) {
		cin >> a >> b;
		arr[a]++;
		arr[b]++;
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++)
		maxx = max(maxx, arr[i]);
	cout << maxx + 1;
}
