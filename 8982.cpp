//https://www.acmicpc.net/problem/8982
/*풀이 :
수족관의 각 깊이를 저장한 후 구멍이 뚫린 위치의 양 옆을 체크하는데 높이가 더 낮으면 그 높이 만큼만 빠진다는걸 유의하자
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int n, k;
pii le, ri;
int depth[40001];
int check[40001];
int sum;
void go(int num)
{
	int del = depth[num];
	check[num] = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		del = min(del, depth[i]);
		if (depth[i] - check[i] <= del)//그림 기준으로 y 인덱스 del만큼 뺄건데 현재 깊이와 남아있는 물의 차이가 del 인덱스 보다는 작아야 뺄 수 있는거지
		{
			check[i] = depth[i] - del;
		}
	}
	del = depth[num];
	for (int i = num + 1; i < ri.first; i++)
	{
		del = min(del, depth[i]);
		if (depth[i] - check[i] <= del)
		{
			check[i] = depth[i] - del;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(&check[0], &check[40001], -1);
	cin >> n;
	cin >> le.first >> le.second;
	for (int i = 1; i < n - 1; i++)
	{
		int r, h;
		cin >> r >> h;
		if (i % 2 == 1)
		{
			check[r] = h;
		}
	}
	cin >> ri.first >> ri.second;
	for (int i = 0; i < ri.first; i++)
	{
		if (check[i] == -1)
		{
			check[i] = check[i - 1];
		}
		depth[i] = check[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c >> b;
		go(a);
	}


	for (int i = 0; i < ri.first; i++)
	{
		sum += check[i];
	}
	cout << sum;
	return 0;
}
