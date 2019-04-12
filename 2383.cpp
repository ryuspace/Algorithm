/*2383번 점심 식사시간
풀이 : dfs로 모든 가능한 사람들이 계단을 고르는 경우의 수를 구하고
구현한다.
num 배열에 각자 고른 계단의 도착시간을 넣어준다.
계단을 내려가고 있는 사람의 도착시간을 miq라고 하고
기다리고 있는 사람을 q라고 하면
miq는 도착 시간이 되면 pop해주고
q는 miq의 크기가 3보다 작으면 최대 3이 될 때까지 큐에서 빼주고 도착시간을 miq에 push 해준다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int t,n;
int arr[11][11];
vector<pii> st;
vector<pii> pp;
int jemul[11];
int num[11];
int was[2];
int res = 1e9;
bool wait[2];
void play()
{
	int num2[11] = {};
	for (int i = 0; i < pp.size(); i++)
	{
		if (jemul[i] == 1)
		{
			num[i] = abs( pp[i].first- st[1].first ) + abs( pp[i].second- st[1].second );
			num2[i] = 1;
		}
		else if(jemul[i]==0)
		{
			num[i] = abs(pp[i].first - st[0].first) + abs(pp[i].second - st[0].second);
			num2[i] = 0;
		}
	}
	int mi_cnt = 0;
	queue<int> q[2];
	queue<int> miq[2];
	int cntt = 0;
	int maxx = 0;
	for (int ti = 1;; ti++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (miq[i].empty())
				continue;
			int num = miq[i].front();
			while (num== ti)
			{
				miq[i].pop();
				if (miq[i].empty())
					break;
				num = miq[i].front();
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (miq[i].size() == 3)
				continue;
			else
			{
				int sizz = 3 - miq[i].size();
				while (sizz--)
				{
					if (q[i].empty())
						break;
					maxx = max(maxx, ti + arr[st[i].first][st[i].second]);
					miq[i].push(ti + arr[st[i].first][st[i].second]);
					q[i].pop();
					cntt++;
				}
			}
		}
		if (cntt == pp.size())
		{
			res = min(maxx, res);
			return;
		}
		for (int i = 0; i < pp.size(); i++)
		{
			if(num[i]>=0)
				num[i]--;
			if (num[i] == 0)
			{
				q[num2[i]].push(i);
			}
		}
	}
}
void dfs(int cnt)
{
	if (cnt == pp.size())
	{
		play();
		return;
	}
	jemul[cnt] = 1;
	dfs(cnt + 1);
	jemul[cnt] = 0;
	dfs(cnt + 1);
}
int main()
{
	freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		st.clear();
		pp.clear();
		memset(jemul, 0, sizeof(jemul));
		res = 1e9;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] >= 2)
				{
					st.push_back({ i,j });
				}
				else if (arr[i][j] == 1)
				{
					pp.push_back({ i,j });
				}
			}
		}
		dfs(0);
		cout << "#"<<q<<" "<<res<< '\n';
	}

	return 0;
}
