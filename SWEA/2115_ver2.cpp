/*2115번 벌꿀채취
풀이 : 구현 문제, dfs를 이용하여 두 일꾼이 벌꿀을 담게 하고 
일꾼이 담은 벌꿀 별로 각각 next_permutation을 돌려 각각 가치의 최대를 구한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;
int t, n, m,c;
int arr[11][11];
bool visit[11][11];
int maxx = 0;
void dfs(int idx,int cnt)
{
	if (cnt == 2)
	{
		int max1 = 0, max2 = 0;
		vector<int> v1, v2;
		for (int i = 0; i < m; i++)
		{
			v1.push_back(v[i]);
		}
		for (int i = m; i < 2 * m; i++)
		{
			v2.push_back(v[i]);
		}
		do
		{
			int hap = 0;
			int sum = 0;
			for (int i = 0; i < v1.size(); i++)
			{
				hap += v1[i] * v1[i];
				sum += v1[i];
				if (sum > c)
				{
					hap -= v1[i] * v1[i];
					sum -= v1[i];
				}
			}
			max1 = max(max1, hap);
		} while (next_permutation(v1.begin(), v1.end()));

		do
		{
			int hap = 0;
			int sum = 0;
			for (int i = 0; i < v2.size(); i++)
			{
				hap += v2[i] * v2[i];
				sum += v2[i];
				if (sum > c)
				{
					hap -= v2[i] * v2[i];
					sum -= v2[i];
				}
			}
			max2 = max(max2, hap);
		} while (next_permutation(v2.begin(), v2.end()));
		maxx = max(maxx, max1 + max2);
		return;
	}
	for (int i = idx; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j]&& (n - j) >= m)
			{
				bool flag = false;
				for (int r = 0; r < m; r++)
				{
					if (visit[i][j + r]) {
						flag = true;
						break;
					}
				}
				if (flag)
					break;
				for (int r = 0; r < m; r++)
				{
					visit[i][j + r] = true;
					v.push_back(arr[i][j+r]);
				}
				dfs(i,cnt + 1);
				for (int r = 0; r < m; r++)
				{
					visit[i][j + r] = false;
					v.pop_back();
				}
			}
		}
	}
}
int main()
{
	freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		maxx = 0;
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		dfs(0, 0);
		cout << "#" << r << " " << maxx << '\n';
	}
	return 0;
}

