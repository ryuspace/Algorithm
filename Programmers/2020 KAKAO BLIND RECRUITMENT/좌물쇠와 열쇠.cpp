/*풀이 : 
Lock 모양에서 뚫어져있는 부분을 포함할 수 있게 최소한으로 자르고 그 자른 모양을
Key 모양을 돌려가면서 매칭이 되는지 체크한다.
*/
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int m = key[0].size();
	int n = lock[0].size();

	int min_r = 1e9;
	int min_c = 1e9;
	int max_r = 0;
	int max_c = 0;
	int arr[21][21] = { 0, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (lock[i][j] == 0)
			{
				min_r = min(min_r, i);
				min_c = min(min_c, j);
				max_r = max(max_r, i);
				max_c = max(max_c, j);
			}
		}
	}
	for (int i = min_r; i <= max_r; i++)
	{
		for (int j = min_c; j <= max_c; j++)
		{
			arr[i - min_r][j - min_c] = lock[i][j];
		}
	}

	for (int t = 1; t <= 4; t++)
	{
		int tmp[21][21] = { 0, };
		int imsi[21][21] = { 0, };
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tmp[i][j] = key[i][j];
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				key[i][j] = tmp[m-1 - j][i];
			}
		}
		for (int r = 0; r < m - (max_r - min_r); r++)
		{
			for (int k = 0; k < m - (max_c - min_c); k++) 
			{
				
				bool flag = false;
				for (int i = 0; i < max_r - min_r + 1; i++)
				{
					for (int j = 0; j < max_c - min_c + 1; j++)
					{
						if (arr[i][j] != 1 - key[r + i][k + j])
						{
							flag = true;
							break;
						}
					}
				}
				if (!flag)
					return true;
				
			}

		}
	}
	return false;
}
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*vector<vector<int>> key(3, vector<int>(3, 0));
	vector<vector<int>> lock(3, vector<int>(3, 0));
	for (int i = 0; i < key[0].size(); i++)
	{
		for (int j = 0; j < key[0].size(); j++)
		{
			cin >> key[i][j];
		}
	}
	for (int i = 0; i < lock[0].size(); i++)
	{
		for (int j = 0; j < lock[0].size(); j++)
		{
			cin >> lock[i][j];
		}
	}
	cout<<solution(key, lock);*/
	return 0;
}
