//https://www.acmicpc.net/problem/17419
/*풀이 : 계산해 보면 이진수의 1의 갯수 만큼 연산한다. 오른쪽에서 왼쪽 방향으로 
차례대로 1이 없어진다.*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		cnt += a - '0';
	}
	cout << cnt;
	
	return 0;
}
