//https://www.acmicpc.net/problem/1107
#include <iostream>
#include <math.h>
using namespace std;

bool broke[10];
int possible(int n)
{
	int len = 0;
	if (n == 0)
	{
		if (broke[n] == true)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	while (n != 0)
	{
		if (broke[n % 10] == true)
			return 0;
		else
		{
			n = n / 10;
			len++;
		}
	}
	return len;
}
int main()
{
	int num,broke_cnt;
	cin >> num;//이동하려는 채널
	cin >> broke_cnt;//고장난 버튼의 개수
	while (broke_cnt--)
	{
		int tmp;
		cin >> tmp;
		broke[tmp] = true;
	}
	//첫번째 경우 : +나 -로 원하는 번호 옮김
	int first = abs(num - 100);
	int second;
	//두번째 경우 : 번호를 누르고 +,-로 이동
	
	for (int i = 0; i <= 1000000; i++)
	{
		int temp = possible(i);
		
		if (temp > 0)
		{
			second = temp + abs(num - i);
			if (first > second)
			{
				first = second;
			}
		}
		
	}
	cout << first;
	return 0;
}
