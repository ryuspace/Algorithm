//https://www.acmicpc.net/problem/14891
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int arr1[8];
int arr2[8];
int arr3[8];
int arr4[8];
//tmp는 톱니바퀴가 움직이기 전의 상태 이에 맞춰서 톱니바퀴를 움직일때 동작을 판단해야한다
int tmp1[8];
int tmp2[8];
int tmp3[8];
int tmp4[8];
void clock(int num)
{
	if (num == 1)
	{
		arr1[1] = tmp1[0];
		arr1[2] = tmp1[1];
		arr1[3] = tmp1[2];
		arr1[4] = tmp1[3];
		arr1[5] = tmp1[4];
		arr1[6] = tmp1[5];
		arr1[7] = tmp1[6];
		arr1[0] = tmp1[7];
	}
	else if (num == 2)
	{
		arr2[1] = tmp2[0];
		arr2[2] = tmp2[1];
		arr2[3] = tmp2[2];
		arr2[4] = tmp2[3];
		arr2[5] = tmp2[4];
		arr2[6] = tmp2[5];
		arr2[7] = tmp2[6];
		arr2[0] = tmp2[7];
	}
	else if (num == 3)
	{
		arr3[1] = tmp3[0];
		arr3[2] = tmp3[1];
		arr3[3] = tmp3[2];
		arr3[4] = tmp3[3];
		arr3[5] = tmp3[4];
		arr3[6] = tmp3[5];
		arr3[7] = tmp3[6];
		arr3[0] = tmp3[7];
	}
	else if (num == 4)
	{
		arr4[1] = tmp4[0];
		arr4[2] = tmp4[1];
		arr4[3] = tmp4[2];
		arr4[4] = tmp4[3];
		arr4[5] = tmp4[4];
		arr4[6] = tmp4[5];
		arr4[7] = tmp4[6];
		arr4[0] = tmp4[7];
	}
}
void clockwise(int num)
{
	if (num == 1)
	{
		arr1[1] = tmp1[2];
		arr1[2] = tmp1[3];
		arr1[3] = tmp1[4];
		arr1[4] = tmp1[5];
		arr1[5] = tmp1[6];
		arr1[6] = tmp1[7];
		arr1[7] = tmp1[0];
		arr1[0] = tmp1[1];
	}
	else if (num == 2)
	{
		arr2[1] = tmp2[2];
		arr2[2] = tmp2[3];
		arr2[3] = tmp2[4];
		arr2[4] = tmp2[5];
		arr2[5] = tmp2[6];
		arr2[6] = tmp2[7];
		arr2[7] = tmp2[0];
		arr2[0] = tmp2[1];
	}
	else if (num == 3)
	{
		arr3[1] = tmp3[2];
		arr3[2] = tmp3[3];
		arr3[3] = tmp3[4];
		arr3[4] = tmp3[5];
		arr3[5] = tmp3[6];
		arr3[6] = tmp3[7];
		arr3[7] = tmp3[0];
		arr3[0] = tmp3[1];
	}
	else if (num == 4)
	{
		arr4[1] = tmp4[2];
		arr4[2] = tmp4[3];
		arr4[3] = tmp4[4];
		arr4[4] = tmp4[5];
		arr4[5] = tmp4[6];
		arr4[6] = tmp4[7];
		arr4[7] = tmp4[0];
		arr4[0] = tmp4[1];
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	string str;
	int k, num,rot;
	cin >> str;
	for (int i = 0; i < 8; i++)
	{
		arr1[i] = str[i] - '0';
		tmp1[i] = str[i] - '0';
	}
	cin >> str;
	for (int i = 0; i < 8; i++)
	{
		arr2[i] = str[i] - '0';
		tmp2[i] = str[i] - '0';
	}
	cin >> str;
	for (int i = 0; i < 8; i++)
	{
		arr3[i] = str[i] - '0';
		tmp3[i] = str[i] - '0';
	}
	cin >> str;
	for (int i = 0; i < 8; i++)
	{
		arr4[i] = str[i] - '0';
		tmp4[i] = str[i] - '0';
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> num >> rot;
		if (num == 1)
		{
			if (rot == 1)
			{
				clock(1);
				if (tmp1[2] != tmp2[6])
				{
					clockwise(2);
					if (tmp2[2] != tmp3[6])
					{
						clock(3);
						if (tmp3[2] != tmp4[6])
						{
							clockwise(4);
						}
					}

				}

			}
			else if (rot == -1)
			{
				clockwise(1);
				if (tmp1[2] != tmp2[6])
				{
					clock(2);
					if (tmp2[2] != tmp3[6])
					{
						clockwise(3);
						if (tmp3[2] != tmp4[6])
						{
							clock(4);
						}
					}

				}
			}
		}
		else if (num == 2)
		{
			if (rot == 1)
			{
				clock(2);
				if (tmp1[2] != tmp2[6])
				{
					clockwise(1);
				}
				if (tmp2[2] != tmp3[6])
				{
					clockwise(3);
					if (tmp3[2] != tmp4[6])
					{
						clock(4);
					}
				}

			}
			else if (rot == -1)
			{
				clockwise(2);
				if (tmp1[2] != tmp2[6])
				{
					clock(1);
				}
				if (tmp2[2] != tmp3[6])
				{
					clock(3);
					if (tmp3[2] != tmp4[6])
					{
						clockwise(4);
					}
				}
			}
		}
		else if (num == 3)
		{
			if (rot == 1)
			{
				clock(3);
				if (tmp3[2] != tmp4[6])
				{
					clockwise(4);
				}
				if (tmp2[2] != tmp3[6])
				{
					clockwise(2);
					if (tmp1[2] != tmp2[6])
					{
						clock(1);
					}
				}

			}
			else if (rot == -1)
			{
				clockwise(3);
				if (tmp3[2] != tmp4[6])
				{
					clock(4);
				}
				if (tmp2[2] != tmp3[6])
				{
					clock(2);
					if (tmp1[2] != tmp2[6])
					{
						clockwise(1);
					}
				}
			}
		}
		else if (num == 4)
		{
			if (rot == 1)
			{
				clock(4);
				if (tmp3[2] != tmp4[6])
				{
					clockwise(3);
					if (tmp2[2] != tmp3[6])
					{
						clock(2);
						if (tmp1[2] != tmp2[6])
						{
							clockwise(1);
						}
					}

				}

			}
			else if (rot == -1)
			{
				clockwise(4);
				if (tmp3[2] != tmp4[6])
				{
					clock(3);
					if (tmp2[2] != tmp3[6])
					{
						clockwise(2);
						if (tmp1[2] != tmp2[6])
						{
							clock(1);
						}
					}
				}
			}
		}
		//움직인 톱니바퀴의 위치를 업데이트
		for (int i = 0; i < 8; i++)
		{
			tmp1[i] = arr1[i];
			tmp2[i] = arr2[i];
			tmp3[i] = arr3[i];
			tmp4[i] = arr4[i];
		}
	}
	int ans = 0;
	if (arr1[0] == 1)
	{
		ans += 1;
	}
	if (arr2[0] == 1)
	{
		ans += 2;
	}
	if (arr3[0] == 1)
	{
		ans += 4;
	}
	if (arr4[0] == 1)
	{
		ans += 8;
	}
	cout << ans;

	return 0;
}
