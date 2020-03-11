//https://www.acmicpc.net/problem/5904
/*풀이 :

우선 moo 수열의 길이가 10억이 나올만한 n을 구한다.
그리고 분할정복을 이용하여 기저부터 idx를 증가시키면서 n과 idx가 일치할 때를 찾는다.


*/
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int idx = 1;
void moo(int num)
{

	if (num == 0)//기저
	{
		if (idx == n)
		{
			cout << "m";
			exit(0);
		}
		else if (idx + 1 == n || idx + 2 == n)
		{
			cout << "o";
			exit(0);
		}
		idx += 3;
		return;
	}
	moo(num - 1);
	if (idx == n)
	{
		cout << "m";
		exit(0);
	}
	idx++;
	if (idx <= n && idx + num + 1 >= n)
	{
		cout << "o";
		exit(0);
	}
	idx += num + 2;
	moo(num - 1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;


	moo(27);
	return 0;
}
