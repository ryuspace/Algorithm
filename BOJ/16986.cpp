//https://www.acmicpc.net/problem/16986
/*풀이 : 지우가 낼 수 있는 모든 경우의 수를 찾고, 가위바위보 한다.
만약 지우가 n번째 까지 이기지 못하면 n+1번째는 같은 동작이 나오므로
경기를 종료한다.*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k;
int arr[10][10];
int play[4][21];
int win[4];
bool visit[10];
int maxx = 0;
void fight(int p1,int p2,int p3,int cnt1,int cnt2,int cnt3)//p1,p2는 겨룸 p3는 대기
{
	if (win[1] >= k|| win[2]>=k|| win[3]>=k)
	{
		if (win[1] >= k)
		{
			cout << 1;
			exit(0);
		}
		else
		{
			return;
		}
	}
	if ((p1 == 1 && cnt1 >= n + 1) || (p2 == 1 && cnt2 >= n + 1))
		return;
	if (arr[play[p1][cnt1]][play[p2][cnt2]] == 2)
	{
		win[p1]++;
		fight(p1, p3, p2, cnt1+1,cnt3,cnt2+1);
	}
	else if(arr[play[p1][cnt1]][play[p2][cnt2]] == 0)
	{
		win[p2]++;
		fight(p2, p3, p1, cnt2+1,cnt3,cnt1+1);
	}
	else if (arr[play[p1][cnt1]][play[p2][cnt2]] == 1)
	{
		if (p1 < p2)
		{
			win[p2]++;
			fight(p2, p3, p1, cnt2 + 1, cnt3, cnt1 + 1);
		}
		else if(p1>p2)
		{
			win[p1]++;
			fight(p1, p3, p2, cnt1 + 1, cnt3, cnt2 + 1);
		}
	}

}

void dfs(int cnt)
{
	if (cnt == n+1)
	{
		memset(win, 0, sizeof(win));
		fight(1,2,3,1,1,1);
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			play[1][cnt] = i;
			visit[i] = true;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= 20; i++)
		cin >> play[2][i];
	for (int i = 1; i <= 20; i++)
		cin >> play[3][i];
	dfs(1);
	cout << 0;
	return 0;
}
