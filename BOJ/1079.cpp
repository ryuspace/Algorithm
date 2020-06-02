//https://www.acmicpc.net/problem/1079
/*풀이 :
처음엔 은진이는 마피아가 필수고 나머지 사용자에서도 마피아가 있을 줄 알았다. 그래서 은진이만 살아남는 경우만 찾았는데,
알고보니 은진이만 마피아라고 가정하고 구현을 했어야 했다.
이 부분은 조금 조건이 불친절 했던 것 같다.
나머지 부분은 그렇게 어렵지 않았다.
그리고 은진이가 낮에 죽으면 다음날 밤에 가지 못 한 것이다.. 이 부분도 놓쳤었다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int arr[17][17];
int yuje[17];
bool die[17];
int mapia_su;
int simin_su;
int max_day;
int jini;
bool flag;
void play(int sun,int night)
{
	if (flag)
		return;
	if (simin_su == 0)
	{
		flag = true;
		max_day = max(max_day, night);
		return;
	}
	if ((mapia_su+simin_su) % 2 == 0)//밤
	{
		for (int i = 0;i < n;i++)
		{
			if (!die[i] && i!=jini)
			{
				die[i] = true;
				simin_su--;
				for (int j = 0;j < n;j++)
				{
					yuje[j] += arr[i][j];
				}
				play(sun + 1, night);
				die[i] = false;
				simin_su++;
				for (int j = 0;j < n;j++)
				{
					yuje[j] -= arr[i][j];
				}
			}
		}
	}
	else//낮
	{
		int maxx= -1e9;
		int maxi = 0;
		for (int i = 0;i < n;i++)
		{
			if (maxx < yuje[i] && !die[i])
			{
				maxx = yuje[i];
				maxi = i;
			}
		}
		if (maxi==jini)
		{
			max_day = max(max_day, night);
			return;
		}
		die[maxi] = true;
		simin_su--;
		play(sun, night + 1);
		die[maxi] = false;
		simin_su++;

	}

}

void selectMapia()
{
	mapia_su = 1;
	simin_su = n - 1;
	if (n % 2 == 0)
	{
		play(0, 1);
	}
	else
	{
		play(1, 0);
	}

}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> yuje[i];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> jini;
	selectMapia();
	cout << max_day;
	return 0;
}
