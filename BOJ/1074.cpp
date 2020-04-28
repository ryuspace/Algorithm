//https://www.acmicpc.net/problem/1074
/*풀이 :
moo랑 비슷하게 풀었다.
분할정복의 기본은 기저를 찾고, 반복되는 구간을 도출해내는 것이다.
우선 기저는 2*2 배열이고 이 배열에 도달하면 내가 찾는 값이 있는지 체크를 한다.
체크하면서 전역 인덱스를 올려준다.

*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, r, c;
int idx = 0;
void func(int row, int col,int num)
{

	if (num == 2)
	{
		if (row == r && col == c)
		{
			cout << idx;
			exit(0);
		}
		idx++;
		if (row == r && col + 1 == c)
		{
			cout << idx;
			exit(0);
		}
		idx++;
		if (row+1 == r && col == c)
		{
			cout << idx;
			exit(0);
		}
		idx++;
		if (row+1 == r && col+1 == c)
		{
			cout << idx;
			exit(0);
		}
		idx++;
		return;
	}
	func(row, col, num / 2);
	func(row, col + num / 2, num / 2);
	func(row + num / 2, col, num / 2);
	func(row + num / 2, col + num / 2, num / 2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> c;
	func(0, 0, pow(2, n));
	return 0;
}
