//https://www.acmicpc.net/problem/2840
/*풀이 : 모듈러 연산 하면서 알파벳의 위치를 찾아주고 마지막 위치를 기준으로
왼쪽 방향, 오른쪽 방향으로 원래 알파벳들을 출력한다.
'?'가 나오는 경우는 그 위치에 어느 알파벳도 들어오지 않는 경우이다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
char v[26];
bool visit[500];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(v, '?', sizeof(v));
	int start = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		start += a;
		if (start >= n)
		{
			start = start % n;
		}
		//모순인 경우 ! 배열 자리에 다른 알파벳이 있는 경우. 이미 나온 알파벳인데 다른 자리에 그 알파벳이 있으려고 하는 경우
		if (v[start] != '?' && v[start]!=b || (visit[b] && v[start]!=b))
		{
			cout << '!';
			exit(0);
		}
		v[start] = b;
		visit[b] = 1;
	}
	for (int i = start; i >= 0; i--)
	{
		cout << v[i];
	}
	for (int i = n - 1; i >= start + 1; i--)
	{
		cout << v[i];
	}
	return 0;
}
