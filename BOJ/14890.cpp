//https://www.acmicpc.net/problem/14890
/*풀이 : 
j-1열과 j열을 비교해서 같으면 우선 pass, 1이상으로 차이나면 불가능한 경우다.
그 이외의 경우는 차이가 1이다.
이전보다 현재가 높이가 높으면 왼쪽으로 경사로를 놔보고 그렇지 않으면 오른쪽으로 경사로를 놔본다.
왼쪽으로는 경사로를 놔보다가 l보다 놓을 길이가 짧거나, 이미 경사로가 있으면 놓을 수 없다.
오른쪽으로는 경사로를 놔보다가 이미 경사로가 있으면 놓을 수 없다.
열 방향 탐색은 기존 배열을 돌려 같은 코드로 체크를 한다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, l;
int arr[101][101];
bool gyeong[101][101];
int sum;
bool check(int start,int x, int y, int l,int dir)
{
	int cnt = 0;
	if (dir == 0) //왼쪽
	{
		int nx = x;
		int ny = y;
		for (int i = 0;i < l;i++)
		{
			if (arr[nx][ny] + 1 == start && !gyeong[nx][ny])
			{
				cnt++;
			}
			else
			{
				break;
			}
			ny--;
			if (ny < 0)
				break;
		}
		if (cnt == l)
		{
			int nx = x;
			int ny = y;
			for (int i = 0;i < l;i++)
			{
				gyeong[nx][ny] = true;
				ny--;
			}

			return true;
		}

	}
	else//오른쪽
	{
		int nx = x;
		int ny = y;
		for (int i = 0;i < l;i++)
		{
			if (arr[nx][ny] + 1 == start && !gyeong[nx][ny])
			{
				cnt++;
			}
			else
			{
				break;
			}
			ny++;
			if (ny >= n)
				break;
		}
		if (cnt == l)
		{
			int nx = x;
			int ny = y;
			for (int i = 0;i < l;i++)
			{
				gyeong[nx][ny] = true;
				ny++;
			}
			return true;
		}
	}
	return false;
}
void go()
{
	for (int i = 0;i < n;i++)
	{
		bool flag = false;
		int start = arr[i][0];
		for (int j = 1;j < n;j++)
		{
			if (abs(arr[i][j] - start) > 1)
			{
				flag = true;
				break;
			}
			if (gyeong[i][j])
			{
				start = arr[i][j];
				continue;
			}
			if (start < arr[i][j])
			{
				if (!check(arr[i][j], i, j-1, l, 0))
				{
					flag = true;
					break;
				}
			}
			else if (start > arr[i][j])
			{
				if (!check(start, i, j, l, 1))
				{
					flag = true;
					break;
				}
				
			}
			start = arr[i][j];
		}
		if (!flag)
		{
			sum++;
		}
	}
}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n>>l;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> arr[i][j];
		}
	}
	go();
	memset(gyeong, 0, sizeof(gyeong));
	int tmp[101][101];
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			arr[i][j] = tmp[n - 1 - j][i];
		}
	}
	go();
	cout << sum;
	return 0;
}
