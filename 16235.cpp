//https://www.acmicpc.net/problem/16235
/*풀이 : 2차원 배열 벡터를 처음 써봄 . 봄 여름/가을 겨울 이렇게 같이 기능을 수행할 수 있다.
어린 나무부터 양분을 먹기 위해 이차원 배열에 있는 나무들을 오름차순으로 정렬한다.
오름차순으로 정렬했으니 양분이 부족해 먹지 못하는 나무의 갯수는 벡터를 뒤에서 그 갯수를
뺀 것과 같다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
vector <int> v[101][101];
int arr[101][101];//추가되는 양분을 받음
int tree[101][101];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int n, m, k;
void hi()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sort(v[i][j].begin(), v[i][j].end());
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			int cnt = 0;
			for (int k = 0; k < v[i][j].size(); k++)
			{
				if (v[i][j][k] <= tree[i][j])
				{
					tree[i][j] -= v[i][j][k];//나이만큼 양분 감소
					v[i][j][k]++;
				}
				else
				{
					sum += v[i][j][k] / 2;
					cnt++;
				}
				
			}
			while (cnt--)
			{
				v[i][j].pop_back();
			}
			tree[i][j] += sum;
		}
	}
}
void bye()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < v[i][j].size(); k++)
			{
				if (v[i][j][k] % 5 == 0)
				{
					for (int r = 0; r < 8; r++)
					{
						int nx = i + dx[r];
						int ny = j + dy[r];

						if (nx >= 0 && nx < n && ny >= 0 && ny < n)
						{
							v[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tree[i][j] += arr[i][j];
		}
	}

}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			tree[i][j] = 5;
		}
	}
	int x, y, z;
	
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		v[x - 1][y - 1].push_back(z);
	}

	while (k--)
	{
		hi();
		bye();
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt += v[i][j].size();
		}
	}
	cout << cnt;
	return 0;
}
