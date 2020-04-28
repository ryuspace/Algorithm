/*4014번 활주로 건설
풀이 : 백준 경사로랑 같은 문제. 현재 배열에 있는 숫자랑 이전 배열에 있는 숫자가 1 차이가 나면
경사로를 놓을 수 있는지 체크해보고 놓을 수 있으면 놓는다.
경사로를 놓고 탐색하는데 경사로를 놔야하는데 이미 경사로라 있던지. 경사로 길이보다 땅의 길이가 적으면
그 행 또는 열의 탐색을 끝낸다.
어떤 배열에 기존 배열의 행,열을 반대로 넣어주면 같은 함수로 재사용이 가능하다.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int t, n, X;
int arr[21][21];
int brr[21][21];
bool visit[21];
bool check(int arr[21][21],int x,int y)
{
	int cnt = 0;
	int num = arr[x][y];
	for (int i = y; i < n; i++)
	{
		if (visit[i] == true)
			break;
		if (arr[x][i] == num)
			cnt++;
		else
			break;
	}
	if (cnt >= X)
	{
		for (int i = y ; i < y+X; i++)
		{
			visit[i] = true;
		}
		return true;
	}
	return false;
}

bool check2(int arr[21][21],int x, int y)
{
	int cnt = 0;
	int num = arr[x][y];
	for (int i = y; i>=0; i--)
	{
		if (visit[i] == true)
			break;
		if (arr[x][i] == num)
			cnt++;
		else
			break;
	}
	if (cnt >= X)
	{
		for (int i = y; i >y-X; i--)
		{
			visit[i] = true;
		}
		return true;
	}
	return false;
}


int main()
{
	freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		int cnt = 0;
		cin >> n >> X;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				brr[j][i] = arr[i][j];
			}
		}


		//행 탐색
		for (int i = 0; i < n; i++)
		{
			memset(visit, 0, sizeof(visit));
			int start = arr[i][0];
			for (int j = 1; j < n; j++)
			{
				if (visit[j])
				{
					if (j == n - 1)
					{
						cnt++;
						break;
					}
					start = arr[i][j];
					continue;
				}
				if (arr[i][j] < start )
				{
					if (!check(arr,i, j) || abs(arr[i][j] - start) != 1)
						break;
				}
				else if (arr[i][j] > start)
				{
					if (!check2(arr,i, j-1) || abs(arr[i][j] - start) != 1)
						break;
				}
			
				start = arr[i][j];
				if (j == n - 1)
				{
					cnt++;
					break;
				}
			}
		}
		//열탐색
		for (int i = 0; i < n; i++)
		{
			memset(visit, 0, sizeof(visit));
			int start = brr[i][0];
			for (int j = 1; j < n; j++)
			{
				if (visit[j])
				{
					if (j == n - 1)
					{
						cnt++;
						break;
					}
					start = brr[i][j];
					continue;
				}
				if (brr[i][j] < start )
				{
					if (!check(brr,i, j) || abs(brr[i][j] - start) != 1)
						break;
				}
				else if (brr[i][j] > start )
				{
					if (!check2(brr,i, j-1) || abs(brr[i][j] - start) != 1)
						break;
				}
				
				start = brr[i][j];
				if (j == n - 1)
				{
					cnt++;
					break;
				}
			}
			
		}
		cout << "#" << r << " " << cnt << '\n';
	}
	
	return 0;
}

