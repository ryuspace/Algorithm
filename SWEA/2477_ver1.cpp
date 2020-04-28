/*2477번 차량정비소
풀이 : 시키는대로 구현하자
인덱스를 1부터 시작해서 순차적으로 접수창구에 넣어준다.
빈창구가 있으면 바로 넣고 없으면 빌 때까지 기다리고 가장 숫자가 작은 빈창구에 넣어준다.
시간별로 창구를 처음부터 탐색해 가장 숫자가 작은 빈창구를 찾을 수 있다.
시간별로 동시에 끝난 사람이 여럿이면 그들을 접수창구 번호를 기준으로 sort 해준다음에
큐에 넣어준다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int t, n, m, k, a, b;
int one[10];
int two[10];

int ot[10][2];
int tt[10];

int go[1001];

vector<pii> v;
queue<pii> q;
void solve(int tc)
{
	int sum = 0;
	int idx = 1;
	int cnt = 0;
	for (int t = 0;; t++)
	{
		v.clear();
		for (int i = 1; i <= n; i++)
		{
			if (ot[i][0] <= 0)
			{
				if (idx <= k && go[idx] <= t)
				{
					ot[i][0] = one[i];
					ot[i][1] = idx;
					idx++;
				}
			}
			else
			{
				ot[i][0]--;
				if (ot[i][0] == 0)
				{
					v.push_back({i, ot[i][1] });
					i--;
				}
			}
		}
		if (!v.empty())
		{
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
			{
				q.push({ v[i].first,v[i].second });
			}

		}
		for (int i = 1; i <= m; i++)
		{
			if (tt[i] <= 0)
			{
				if (q.empty())
					continue;
				cnt++;
				if (a == q.front().first && b == i)
				{

					sum += q.front().second;
				}
				q.pop();
				tt[i] = two[i];
			}
			else
			{
				tt[i]--;
				if (tt[i] == 0)
				{
					i--;
				}

			}
			if (cnt == k)
			{
				if (sum == 0)
				{
					sum = -1;
				}
				cout << "#" << tc << " " << sum << '\n';
				return;
			}
		}
	}

}
int main()
{
	freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int z = 1; z <= t; z++)
	{
		while (!q.empty())
			q.pop();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 2; j++)
			{
				ot[i][j] = 0;
			}
		}
		for (int i = 0; i < 10; i++) {
			tt[i] = 0;
		}
		memset(tt, 0, sizeof(tt));
		cin >> n >> m >> k >> a >> b;
		for (int i = 1; i <= n; i++)
		{
			cin >> one[i];
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> two[i];
		}
		for (int i = 1; i <= k; i++)
		{
			cin >> go[i];

		}
		solve(z);
	}
	return 0;
}
