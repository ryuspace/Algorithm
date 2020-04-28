//https://www.acmicpc.net/problem/17280
/*풀이 : 
1<= N,M <=100일 때만 성공했다.
우선 승객들이 갈 거리는 오름차순으로 정렬하고,
택시 기사들의 거리 범위를 이분탐색으로 구간을 찾고, 그 구간을 이용해 이분매칭을 한다.
시간복잡도는 O(V*E)므로 약 O(N^2)*TC 갯수
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int t, n, m;
ll arr[102];
bool visit[102];
int jari[102];
vector<ll> v[102];


bool dfs(int num)
{
	for (int i = 0; i < v[num].size(); i++)
	{
		if (visit[v[num][i]])
			continue;
		visit[v[num][i]] = true;
		if (jari[v[num][i]] == -1)
		{
			jari[v[num][i]] = num;
			return true;
		}
		else if (dfs(jari[v[num][i]]))
		{
			jari[v[num][i]] = num;
			return true;
		}
	}
	return false;
}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < m; i++)
		{
			v[i].clear();
			int a, b;
			cin >> a >> b;
			int mini = lower_bound(arr, arr + n, a) - arr;
			int maxi = upper_bound(arr, arr + n, b) - arr;
			for (int j = mini; j < maxi; j++)
			{
				v[i].push_back(j);
			}
		}
		fill(&jari[0], &jari[n + 1], -1);
		for (int i = 0; i < m; i++)
		{
			fill(&visit[0], &visit[n + 1], false);
			if (dfs(i))
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
