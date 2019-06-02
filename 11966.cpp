//https://www.acmicpc.net/problem/11966
/*풀이 : 숫자를 계속 2로 나누고 나머지가 0이 아닌 수가 나오면
2의 제곱수가 아니다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 !=0)
		{
			cout << 0;
			exit(0);
		}
		n /= 2;
	}
	cout << 1;
	return 0;
}
