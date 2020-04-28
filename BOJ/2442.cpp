//https://www.acmicpc.net/problem/2442
/*풀이 : cout.width를 처음 써봄. cout.width는 출력할 칸을 미리 정해놓고
그 다음 cout을 한 무언가를 그 칸에 맞게 오른쪽부터 채워서 출력한다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout.width(n - i + 1);
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << '*';
		cout << "\n";
	}

	return 0;
}
