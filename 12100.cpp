//https://www.acmicpc.net/problem/12100
/*풀이 : 카피 배열은 카피 할 때 마다 새로 만들자.
한번의 시행은 상,하,좌,우 중 하나로 움직이는 거다.
맵에서 0이 아닌 숫자를 큐에 담고 첫번째 인덱스 부터
숫자들을 조건에 맞게(같은 숫자면 *2,다른 숫자면 다음에 놓는다,0이면 그 자리에 놓는다.)
놓아준다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int arr[21][21];

int n;

void fun(int num)
{
	if (num == 0)//상
	{
		for (int j = 0; j < n; j++)
		{
			queue <int> q;
			for (int i = 0; i < n; i++)
			{
				if (arr[i][j] != 0)
				{
					q.push(arr[i][j]);
				}
				arr[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				if (arr[idx][j] == 0)
				{
					arr[idx][j] = front;
				}
				else
				{
					if (arr[idx][j] == front)
					{
						arr[idx][j] = arr[idx][j] * 2;
						idx++;
					}
					else
					{
						idx++;
						arr[idx][j] = front;
					}
				}
			}
		}
	}
	else if (num == 1)//하
	{
		for (int j = 0; j < n; j++)
		{
			queue <int> q;
			for (int i = n-1; i>=0; i--)
			{
				if (arr[i][j] != 0)
				{
					q.push(arr[i][j]);
				}
				arr[i][j] = 0;
			}
			int idx = n-1;
			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				if (arr[idx][j] == 0)
				{
					arr[idx][j] = front;
				}
				else
				{
					if (arr[idx][j] == front)
					{
						arr[idx][j] = arr[idx][j] * 2;
						idx--;
					}
					else
					{
						idx--;
						arr[idx][j] = front;
					}
				}
			}
		}
	}
	else if (num == 2)//좌
	{
		for (int j = 0; j < n; j++)
		{
			queue <int> q;
			for (int i = 0; i < n; i++)
			{
				if (arr[j][i] != 0)
				{
					q.push(arr[j][i]);
				}
				arr[j][i] = 0;
			}
			int idx = 0;
			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				if (arr[j][idx] == 0)
				{
					arr[j][idx] = front;
				}
				else
				{
					if (arr[j][idx] == front)
					{
						arr[j][idx] = arr[j][idx] * 2;
						idx++;
					}
					else
					{
						idx++;
						arr[j][idx] = front;
					}
				}
			}
		}
	}
	else if (num == 3)//우
	{
		for (int j = 0; j < n; j++)
		{
			queue <int> q;
			for (int i = n-1; i >=0; i--)
			{
				if (arr[j][i] != 0)
				{
					q.push(arr[j][i]);
				}
				arr[j][i] = 0;
			}
			int idx = n-1;
			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				if (arr[j][idx] == 0)
				{
					arr[j][idx] = front;
				}
				else
				{
					if (arr[j][idx] == front)
					{
						arr[j][idx] = arr[j][idx] * 2;
						idx--;
					}
					else
					{
						idx--;
						arr[j][idx] = front;
					}
				}
			}
		}
	}
}
int maxx = 0;
void dfs(int cnt)
{
	if (cnt == 6)
	{
		return;
	}
	for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++)
		{
			maxx = max(arr[k][j], maxx);
		}
	int cop[21][21];
	for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++)
			cop[k][j] = arr[k][j];
	for (int i = 0; i < 4; i++)//상하좌우
	{
		fun(i);
		dfs(cnt + 1);
		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++)
				arr[k][j] = cop[k][j];
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	dfs(0);
	cout << maxx;
	return 0;
}

