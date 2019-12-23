//https://www.acmicpc.net/problem/18233
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int n, p, e;
vector <pii> v;
bool visit[21];

void play()
{
	int cnt[21] = { 0, };
	int sum = 0;
	int na = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (visit[i])
		{
			sum += v[i].first;
			na += v[i].second - v[i].first;
			cnt[i] += v[i].first;
		}
	}
	if (sum == e)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << cnt[i] << " ";
		}
		exit(0);
	}
	else if (sum > e)
		return;
	else
	{
		if (na >= e - sum)//선택된 회원들에게 줄 수 있는 인형들의 합이 줄 수 있는 인형 보다 많으면 무조건 나눠줄 수 있다.
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (visit[i])
				{
					int minn = min(v[i].second - v[i].first, e - sum);
					cnt[i] += minn;
					sum += minn;

				}
				cout << cnt[i] << " ";
			}
			exit(0);
		}
		else
			return;
	}
	
}
void dfs(int idx, int cnt)
{
	if (cnt == p)
	{
		play();
		return;
	}
	if (idx >= n)
		return;
	for (int i = idx; i < n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(i + 1, cnt + 1);
			visit[i] = false;
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p >> e;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	dfs(0, 0);
	cout << -1;
	return 0;
}
