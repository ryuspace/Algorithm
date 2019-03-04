//https://www.acmicpc.net/problem/15664
/*풀이 : dfs를 이용하여 수열을 출력한다. 이미 앞에 나온 것은 다시 출력하지 않게 하기 위해
(오름차순) 시작 위치를 매개변수로 받아준다. 그리고 dfs가 종료되고 다시 실행될 때 같은 숫자이면
무시해준다.(중복 제거)*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[10001];
int jemul[10001];
bool visit[10001];

int n, m;

void dfs(int cnt,int idx)
{
	int tmp = -1;
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << jemul[i] << " ";

		}
		cout << '\n';
	}
	for (int i = idx; i < n; i++)
	{
		if (tmp == arr[i])
			continue;
		if (visit[i] == false)
		{
			jemul[cnt] = arr[i];
			tmp = arr[i];
			visit[i] = true;
			dfs(cnt + 1,i+1);
			visit[i] = false;

		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0,0);

}
