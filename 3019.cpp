//https://www.acmicpc.net/problem/3019
/*풀이 : 가능한 테트리스의 모든 모양의 땅과의 높이 차를
구해놓는다. 그리고 테트리스를 놓았을 때 테트리스 길이만큼
높이차가 모두 같으면 그 테트리스는 놓을 수 있는 테트리스다.*/
#include <iostream>
#include <algorithm>
using namespace std;
int c, p;
int arr[101];
int ans = 0;
void check(string tmp)
{
	for (int i = 0; i <= c - tmp.length(); i++)
	{
		bool flag = false;
		int chai = arr[i] - tmp[0]-'0';
		for (int j = 0 ; j < tmp.length(); j++)
		{
			if (chai != arr[j+i] - tmp[j]-'0')
				flag = true;
		}
		if (!flag)
			ans++;
	}
}

void fun(int num)
{
	if (num == 1)
	{
		check("0");
		check("0000");
	}
	if (num == 2)
	{
		check("00");
	}
	if (num == 3)
	{
		check("001");
		check("10");
	}
	if (num == 4)
	{
		check("100");
		check("01");
	}
	if (num == 5)
	{
		check("000");
		check("10");
		check("01");
		check("101");
	}
	if (num == 6)
	{
		check("000");
		check("00");
		check("20");
		check("011");
	}
	if (num == 7)
	{
		check("000");
		check("02");
		check("110");
		check("00");
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> c >> p;
	for (int i = 0; i < c; i++)
	{
		cin >> arr[i];
	}
	fun(p);
	cout << ans;
	return 0;
}
