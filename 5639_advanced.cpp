//https://www.acmicpc.net/problem/5639
/*풀이 : 트리 구조를 보면 루트 기준으로 왼쪽은 다 루트보다 작고 오른족은 다 루트보다 크다.
트리를 루트 왼쪽 서브트리 오른쪽 서브트리를 분할정복으로 나뉘에서 최소단위로 나뉠 때 까지 시행한 후 출력한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10010], n;

void go(int l, int r) {
	if (l > r) return;

	int root = l;
	int s = l, e = r;
	while (arr[s] >= arr[root]) s++;
	while (arr[e] > arr[root]) e--;
	go(s, e);
	go(e + 1, r);
	printf("%d\n", arr[root]);

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x;
	while (scanf(" %d", &x) != -1) arr[n++] = x;
	go(0, n - 1);
	return 0;
}
