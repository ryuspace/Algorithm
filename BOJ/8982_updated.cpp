//https://www.acmicpc.net/problem/8982
/*풀이 :
수족관의 각 깊이를 저장한 후 구멍이 뚫린 위치의 양 옆을 체크한다.
자세한 건 주석으로
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
	check[num] = del;
	for (int i = num - 1; i >= 0; i--)
	{
		del = min(del, depth[i]);//시작 점 기준으로 높이가 낮아지면 낮은 높이만큼 빠진다.
		check[i] = max(check[i], del);//최종적으로 빠지는건 낮은 높이 중에 가장 높은 높이 만큼 빠진다.
	}
	del = depth[num];
	for (int i = num + 1; i < ri.first; i++)
	{
		del = min(del, depth[i]);
		check[i] = max(check[i], del);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> le.first >> le.second;
	fill(&depth[0], &depth[40001], -1);
	for (int i = 1; i < n - 1; i++)
	{
		int r, h;
		cin >> r >> h;
		if (i % 2 == 1)
		{
			depth[r] = h;
		}
	}
	cin >> ri.first >> ri.second;
	for (int i = 0; i < ri.first; i++)
	{
		if (depth[i] == -1)
		{
			depth[i] = depth[i - 1];
		}
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
		sum += depth[i] - check[i];
	}
	cout << sum;
	return 0;
}
