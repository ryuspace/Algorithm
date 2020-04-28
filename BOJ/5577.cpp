//https://www.acmicpc.net/problem/5577
/*풀이 : 처음에는 완탐 + bfs를 돌렸다.. 10000^3이니까 당연히 시간초과.. 감이 잡히지 않아서
투 포인터를 사용하는 힌트를 받았다. 
색깔을 바꿀 위치의 인덱스의 위,아래를 색깔이 같을 때 까지 찾아본다.
만약 위,아래가 가리키는 색깔이 모두 다를 때 까지
같은 색의 갯수가 4이상이면 결과값을 저장해 놓고 현재 위,아래의 포인터가 가리키는
색이 같으면 반복하고, 그렇지 않으면 종료한다.
색을 아무것도 바꾸지 않은 상태에서는 공이 터질 수가 없으므로
색을 바꾼 위치의 왼쪽 또는 오른쪽 밖에 공이 터질 수 밖에 없다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10001];
int fun(int idx, int type)
{
	int tmp = 0;
	int res = 1;
	int wonbon = arr[idx];
	arr[idx] = type;
	int left = idx-1;
	int right = idx+1;
	int color = type;
	while (left >= 0 || right < n)
	{
		if (left>=0 && arr[left] == color)
		{
			left--;
			res++;
		}
		if (right<n && arr[right] == color)
		{
			right++;
			res++;
		}
		if (arr[left] != color && arr[right] != color)
		{
			if (res>= 4)
			{
				if (arr[left] == arr[right])
				{
					color = arr[left];
					tmp += res;
					res = 0;
				}
				else
				{
					tmp += res;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	arr[idx] = wonbon;
	return tmp;
}
int main()
{
	int maxx = 0;
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			maxx = max(maxx,fun(i, j));
		}
	}
	cout << n-maxx;
	return 0;
}
