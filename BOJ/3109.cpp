//https://www.acmicpc.net/problem/3109
/*풀이 : 파이프는 오른쪽으로 밖에 못간다.
오른쪽 위 오른쪽 오른쪽 아래 방향으로 갔는데 못 가면 
어디서 이어진 파이프던 간에 다시 갈 필요가 없다..
파이프 연결을 맨 오른쪽 위에다 할 수록 많이 연결 할 수 있으니
dfs 탐색 순서를 오른쪽 위, 오른쪽, 오른쪽 아래 순서대로 해준다.
그리고 먼저 빵집에 도착한 파이프는 가장 효율적으로 온 파이프 일 수 밖에 없으므로
턴을 종료해준다.
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int r, c;
char arr[10001][501];
int ans = 0;
int dfs(int rr, int cc)
{
	if (rr<0 || rr>=r ||arr[rr][cc] !='.')
		return 0;
	if (cc == c - 1)
		return 1;
	arr[rr][cc] = 'x';
	return dfs(rr - 1, cc + 1) || dfs(rr, cc + 1) || dfs(rr + 1, cc + 1);
}
int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf(" %c", &arr[i][j]);
	for (int i = 0; i < r; i++)
		ans += dfs(i, 0);
	printf("%d", ans);
	return 0;
}
