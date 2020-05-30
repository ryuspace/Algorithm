//https://www.acmicpc.net/problem/17779
/*
풀이 : 평소 삼성 느낌 나는 문제가 아니었다.. 상당히 당황을 많이 했다. 
그냥 4중 포문을 이용해서 x,y,d1,d2값을 1~n까지 돌리고 문제에 제시된 제약 조건이 맞다면 구역을 나눈다.
구역을 나누는 것 또한 문제에 조건 그대로 따라하면 된다.
수학을 잘 못 해서 꽤 어렵게 느껴졌다 ㅠㅠ
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[21][21];
int label[21][21];

int mini = 1e9;
int sum;
void go(int x, int y, int d1, int d2)
{
	memset(label, 0, sizeof(label));

	int min1 = 0, min2 = 0, min3 = 0, min4 = 0, min5 = 0;
	if (!(x >= 1 && x < x + d1 + d2 && x + d1 + d2 <= n))
	{
		return;
	}
	if (!(y - d1 >= 1 && y - d1 < y && y < y + d2 && y + d2 <= n))
	{
		return;
	}
	//5번
	for (int i = 0;i <= d1;i++)
	{
		label[x + i][y - i] = 5;
	}

	for (int i = 0;i <= d2;i++)
	{
		label[x + i][y + i] = 5;
	}

	for (int i = 0;i <=d2;i++)
	{
		label[x +d1+ i][y - d1+i] = 5;
	}

	for (int i = 0;i <= d1;i++)
	{
		label[x + d2 + i][y + d2- i] = 5;
	}

	//1번
	for (int i = 1;i < x+d1;i++)
	{
		for (int j = 1;j <= y;j++)
		{
			if (label[i][j] == 5)
			{
				break;
			}
			label[i][j] = 1;
			min1 += arr[i][j];
		}
	}

	//2번
	for (int i = 1;i <= x+d2;i++)
	{
		for (int j = n;j >y;j--)
		{
			if (label[i][j] == 5)
			{
				break;
			}
			label[i][j] = 2;
			min2 += arr[i][j];
		}
	}

	//3번
	for (int i = x+d1;i <=n;i++)
	{
		for (int j = 1;j < y-d1+d2;j++)
		{
			if (label[i][j] == 5)
			{
				break;
			}
			label[i][j] = 3;
			min3 += arr[i][j];
		}
	}

	//4번
	for (int i = x + d2+1;i <= n;i++)
	{
		for (int j = n;j >= y - d1 + d2;j--)
		{
			if (label[i][j] == 5)
			{
				break;
			}
			label[i][j] = 4;
			min4 += arr[i][j];
		}
	}

	min5 = sum - (min1 + min2 + min3 + min4);

	int maxx = max({ min1,min2,min3,min4,min5 });
	int minn = min({ min1,min2,min3,min4,min5 });

	mini = min(mini, maxx - minn);
	
}

void findMin()
{
	for (int x = 1;x <=n;x++)
	{
		for (int y = 1;y <=n;y++)
		{
			for (int d1 = 1;d1 <= n;d1++)
			{
				for (int d2 = 1;d2 <= n;d2++)
				{
					go(x, y, d1, d2);
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j =1;j <= n;j++)
		{
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	findMin();
	cout << mini;

	return 0;
}
