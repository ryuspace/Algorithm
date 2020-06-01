//https://www.acmicpc.net/problem/17822
/*풀이 : 시키는 대로 하면 되는 구현. 요구사항을 꼼꼼히 읽어보자. 평균이 실수형이 나올 수 있는 것도 주의 (미리 명시해줬으면 좋았는데..)*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, t;
int arr[51][51];


void rotate(int r,int d)
{
	int tmp[51][51];

	for (int j = 1;j <= m;j++)
	{
		tmp[r][j] = arr[r][j];
	}

	if (d == 0)
	{
		for (int j = 2;j <= m;j++)
		{
			arr[r][j] = tmp[r][j - 1];
		}
		arr[r][1] = tmp[r][m];
	}
	else
	{
		for (int j = 1;j < m;j++)
		{
			arr[r][j] = tmp[r][j + 1];
		}
		arr[r][m] = tmp[r][1];
	}
}
void go(int x, int d, int k) {

	bool visit[51][51];
	memset(visit, 0, sizeof(visit));

	for (int i =1;i <= n;i++)
	{
		if (i % x == 0)//x의 배수
		{
			for (int r = 0;r < k;r++)
			{
				rotate(i, d);
			}
		}
	}


	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			int su = arr[i][j];
			if (su == -1)
				continue;
			if (j == 1)
			{
				if (su==arr[i][2])
				{
					visit[i][2] = true;
					visit[i][j] = true;
				}
				if (su == arr[i][m])
				{

					visit[i][m] = true;
					visit[i][j] = true;
				}
			}
			if (j==m)
			{
				if (su == arr[i][m-1])
				{
					visit[i][m-1] = true;
					visit[i][j] = true;
				}
				if (su == arr[i][1])
				{
					visit[i][1] = true;
					visit[i][j] = true;
				}
			}
			if(j>=2 &&j<=m-1)
			{
				if (su == arr[i][j - 1])
				{
					visit[i][j - 1] = true;
					visit[i][j] = true;
				}
				if (su == arr[i][j+1])
				{
					visit[i][j+1] = true;
					visit[i][j] = true;
				}
			}


			if (i == 1)
			{
				if (su == arr[2][j])
				{
					visit[2][j] = true;
					visit[i][j] = true;
				}
				
			}
			if (i == n)
			{
				if (su == arr[n-1][j])
				{
					visit[n-1][j] = true;
					visit[i][j] = true;
				}
			}
			if(i>=2 && i<=n-1)
			{
				if (su == arr[i-1][j])
				{
					visit[i-1][j] = true;
					visit[i][j] = true;
				}
				if (su == arr[i+1][j])
				{
					visit[i+1][j] = true;
					visit[i][j] = true;
				}
			}
		}
	}

	bool flag = false;
	int sum = 0;
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (visit[i][j])
			{
				arr[i][j] = -1;
				flag = true;
			}
			else if (arr[i][j] != -1)
			{
				sum += arr[i][j];
				cnt++;
			}
		}
	}
	if (!flag)
	{
		double avg = (double)sum / (double)cnt;

		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				if (arr[i][j] != -1)
				{
					if (arr[i][j] < avg)
						arr[i][j]++;
					else if (arr[i][j] > avg)
						arr[i][j]--;

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

	cin >> n >> m >> t;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int r = 0;r < t;r++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		go(x, d, k);
	
	}
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if(arr[i][j]!=-1)
				sum += arr[i][j];
		}
	}
	cout << sum;
	return 0;
}
