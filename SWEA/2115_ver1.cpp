/*2115번 벌꿀채취
풀이 : 그냥 구현.... 한명의 일꾼이 어떤 위치를 선택하면 나머지 일꾼이 그 다음 위치부터
하나씩 선택해서 최대를 구한다.
만약 최대 벌꿀양을 넘으면 선택된 모든 벌꿀의 순서를 바꿔봐서 최대벌꿀양을 넘지 않는
벌꿀의 최대 가치를 찾아본다.(next_permutation 사용)
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int arr[11][11];
bool visit[11][11];
int n, m, c;
vector<int> v1;
vector<int> v2;
int maxx;
int sum1;
int sum2;
int cnt1;
int cnt2;
void dfs(int idx,int col,int cnt)
{
	int hi;
	bool flag = false;
	while (idx < n)
	{
		if (flag == false)
		{
			hi = col;
			flag = true;
		}
		else
		{
			hi =0;
		}
		while (hi+m <= n)
		{
			v2.clear();
			sum2 = 0;
			cnt2 = 0;
			for (int i = hi; i < hi + m; i++)
			{
				sum2 += arr[idx][i];
				cnt2 += (arr[idx][i])*(arr[idx][i]);
				v2.push_back(arr[idx][i]);
			}
			if (sum2 > c)
			{
				int maxx2 = 0;
				do
				{
					int sum11 = 0;
					int happ = 0;
					for (int i = 0; i < v2.size(); i++)
					{
						if (sum11 + v2[i] <= c)
						{
							happ += (v2[i] * v2[i]);
							sum11 += v2[i];
						}
						else
						{
							break;
						}
					}
					maxx2 = max(maxx2, happ);
				} while (next_permutation(v2.begin(), v2.end()));
				maxx = max(cnt1+maxx2, maxx);
			}
			else
			{
				maxx = max(cnt1 + cnt2, maxx);
			}
			hi++;
		}
		idx +=1;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("t.txt", "r", stdin);
	int t;
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - m + 1; j++)
			{
				memset(visit, 0, sizeof(visit));
				v1.clear();
				v2.clear();
				sum1 = 0;
				sum2 = 0;
				cnt1 = 0;
				cnt2 = 0;
				for (int k = j; k < j +m; k++)
				{
					visit[i][k] = true;
					v1.push_back(arr[i][k]);
					cnt1 += (arr[i][k])*(arr[i][k]);
					sum1 += arr[i][k];
				}
				if (sum1 > c)
				{
					int maxx2 = 0;
					do
					{
						int sum11 = 0;
						int happ = 0;
						for (int i = 0; i < v1.size(); i++)
						{
							if (sum11 + v1[i] <= c)
							{
								happ += (v1[i] * v1[i]);
								sum11 += v1[i];
							}
						}
						maxx2= max(maxx2, happ);
					} while (next_permutation(v1.begin(), v1.end()));
					cnt1 = maxx2;
					if (n - (j + m ) >= m)
					{
						dfs(i,j+m,0);
					}
					else
					{
						dfs(i + 1,0, 0);
					}
				}
				else
				{
					if (n - (j + m) >= m)
					{
						dfs(i, j + m, 0);
					}
					else
					{
						dfs(i + 1, 0, 0);
					}
				}

			}
		}
		cout << '#' << r << " " << maxx << '\n';
		maxx = 0;
	}

	return 0;
}
