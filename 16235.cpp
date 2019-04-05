//https://www.acmicpc.net/problem/16235
/*풀이 : 2차원 배열 벡터를 처음 써봄 . 봄 여름/가을 겨울 이렇게 같이 기능을 수행할 수 있다.
어린 나무부터 양분을 먹기 위해 이차원 배열에 있는 나무들을 오름차순으로 정렬한다.
오름차순으로 정렬했으니 양분이 부족해 먹지 못하는 나무의 갯수는 벡터를 뒤에서 그 갯수를
뺀 것과 같다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k;
int yang[11][11];
int yang2[11][11];
vector<int> arr[11][11];
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
void ss()
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int die_yang = 0;
			int idx = 0;
			for (int r = 0; r < arr[i][j].size(); r++)
			{
				if (arr[i][j][r] <= yang[i][j])
				{
					yang[i][j] -= arr[i][j][r];
					arr[i][j][r]++;
				}
				else
				{
					idx++;
					break;
				}
			}
			if (idx != 1e9)
			{
				for (int r = arr[i][j].size() - 1; r >= idx; r--)
				{
					die_yang += (arr[i][j][r] / 2);
				}
				for (int r = arr[i][j].size() - 1; r >= idx; r--)
				{
					arr[i][j].pop_back();
				}
			}
			yang[i][j] += die_yang;
		}
	}
}
void aw()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int nai = 0;
			for (int r = 0; r < arr[i][j].size(); r++)
			{
				if (arr[i][j][r] % 5 == 0)
					nai++;
			}
			for (int r = 0; r < 8; r++)
			{
				int nx = i + dx[r];
				int ny = j + dy[r];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					for (int k = 0; k < nai; k++)
					{
						arr[nx][ny].push_back(1);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			yang[i][j] += yang2[i][j];
		}
	}


}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			yang[i][j] = 5;
			cin >> yang2[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		arr[x-1][y-1].push_back(z);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!arr[i][j].empty())
			{
				sort(arr[i][j].begin(), arr[i][j].end());
			}
		}
	}
	while (k--)
	{
		ss();
		aw();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!arr[i][j].empty())
				{
					sort(arr[i][j].begin(), arr[i][j].end());
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt += arr[i][j].size();
		}
	}
	cout << cnt;
	return 0;
}
