//https://www.acmicpc.net/problem/17938
/*풀이 : 
사람이 n명이면 손은 총 2*n개가 있다. 2*n개 까지 손의 합을 세고
2*n을 넘어가면 초기화해 손의 합을 다시 세준다.
손의 합의 결과로 /2를 하여 사람의 인덱스를 구하고 또한,
이전 차례의 사람 위치도 파악해서 휘수가 이 사이에 속해있는지 체크한다.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	int last = 0;
	double sum = 0;
	double hi = 0;
	double bye = 0;
	int c = 1;
	int n, p, t;
	cin >> n >> p >> t;
	for (int i = 1; i <= t; i++)
	{
		cnt += c;
		last = sum;
		sum += cnt;
		if (cnt == 2 * n || (cnt == 1 && i != 1))
		{
			c *= -1;
		}
		if (sum > 2 * n)
		{
			sum -= 2 * n;
		}
	}
	bye = ceil(((last) / 2));
	hi = ceil(sum / 2);
	if (bye > hi)
	{
		if (p > bye || p <= hi)
		{
			cout << "Dehet YeonJwaJe ^~^";
		}
		else
		{
			cout << "Hing...NoJam";
		}
	}
	else
	{
		if (p > bye && p <= hi)
		{
			cout << "Dehet YeonJwaJe ^~^";
		}
		else
		{
			cout << "Hing...NoJam";
		}
	}
	return 0;
}
