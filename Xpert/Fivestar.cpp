/*

풀이 : 세로로는 최대 1개 들어올 수 있고 가로로는 최대 2개 들어올 수 있다.
열마다 *의 갯수를 각각 세주고 행마다 *의 누적합을 구한다.  
그래서 열에서 세로 기둥을 세웠을 때 모든 경우(dfs) 에다가 가로로 최대 5개까지 세본다.
누적합이므로 5개를 세기 전에 조건이 어긋났는데 5개 이상이 있다면 거기에다가 막대를 놓을 수 있단 소리다.
그리고 막대의 마지막 다음 위치부터 다시 카운트를 한다.
코드를 다시 분석하면 최적인 경우임을 알 수 있을 것이다.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n,m;
char arr[11][11];
int row[6];
int col[11][11];
int used[11];
int mini = 1e9;

int calc()
{
	
	int cnt = 0;
	int i, j, r;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (col[i][j] && !used[j]) //일단 세로 기둥 없는 데 부터 세고싶어. 하지만 이 코드에서 세로 기둥과 겹치는게 최적이라고 쳐도 누적합 덕분에 겹치는 경우도 체크할 수 있다!!
			{
				for (r = j; r < j + 5 && r < m && col[i][r]; r++);
				j = r - 1;

				if (col[i][j] >= 5)
					cnt++;
				else
					return -1;
			}
			
		}
	}


	return cnt;
}

void dfs(int cnt,int col)
{
	if (col >= m)
	{
		int cal = calc();
		if (cal == -1)
		{

		}
		else
		{
			if (mini > cal + cnt)
			{
				mini = cal+cnt;
			}
		}
		return;
	}

	if (row[col] == 5)
	{
		used[col] = 1;
		dfs(cnt+1, col + 1);
		used[col] = 0;
	}
	dfs(cnt,col + 1);

}


int main() 
{
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == '*')
			{
				col[i][j] = col[i][j - 1] + 1;
				row[j]++;
			}
		}
	}


	dfs(0, 0);
	if (mini == 1e9)
		printf("-1");
	else
		printf("%d", mini);
	return 0;
}
