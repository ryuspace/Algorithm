/*풀이 :
조금 난잡하게 풀었다.
o은 물이고 -는 다리라고 하면 
o-o-o-o 이런식으로 다리 양 옆에 물이 있는 경우가 마지노선으로 건널 수 있는 경우다.
그걸 식으로 표현하면 다리의 합 + (다리의 갯수 + 1)*(점프 가능거리 -1)이다.
우선 건널 수 있는게 확정 된다면 다리끼리 겹쳐도 상관 없으니깐 
가장 길게 점프를 해보고 안되면 점프 길이를 줄인다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];
vector<int> v;
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, d;
	int len=0;
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
		len += arr[i];
	}
	d -= 1;
	int pos = len + (m+1) * d;
	if (pos < n)
	{
		cout << "NO";
		exit(0);
	}
	else
	{
		int na = n - len;
		if (na < d) //점프 길이보다 물 길이가 더 적다..? 물 길이만 점프하면 돼!
		{
			v.push_back(na);
		}
		else
		{
			while (na != 0)
			{
				na -= d;//우선 뛸 수 있는 최대치부터 뛰어보자!
				v.push_back(d);
				if (na < d)
				{
					if (na >= 1)
					{
						v.push_back(na);
					}
					break;
				}
			}
		}
		int num = v.size();
		int minn = min(num, m);
		int idx = 1;
		for (int i = 0; i < minn; i++)
		{
			for (int j = 0; j < v[i]; j++)
			{
				ans.push_back(0);
			}
			ans.push_back(arr[i]);
		}
		if (num > m)
		{
			for (int i=minn; i < num; i++)
			{
				for (int j = 0; j < v[i]; j++)
				{
					ans.push_back(0);
				}
			}
		}
		else if (num < m)
		{
			for (int i = minn; i < m; i++)
			{
				ans.push_back(arr[i]);
			}
		}
	}
	int idx = 1;
	cout << "YES" << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] != 0)
		{
			for (int j = 0; j < ans[i]; j++)
			{
				cout << idx << " ";
			}
			idx++;
		}
		else
			cout << ans[i] << " ";
	}

	return 0;
}
