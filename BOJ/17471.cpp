//https://www.acmicpc.net/problem/17471
/*풀이 : dfs를 이용해 모든 경우의 수의 팀을 구성한다.
팀을 Team1,Team2 벡터에 담으면 팀이 하나로만 이루어진 경우를 쉽게 피할 수 있다.
팀이 이루어지는 지 체크하는 것은 두 벡터에 대해 bfs를 돌려서 판단하는데,
다음으로 갈 노드가 팀원에 속해있으면 큐에 담고 그렇지 않으면 큐에 담지 않아서
마지막에 bfs를 돈 결과와 처음에 설정한 팀의 구성원이 같은지 체크한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector <int> v[11];
int people[11];
vector<int> team1;
vector<int> team2;
bool team[11];
int n;
bool check(vector<int> vv)
{
	vector<int> ans;
	bool visit[11] = { 0, };
	queue<int> q;
	visit[vv[0]] = true;
	q.push(vv[0]);
	ans.push_back(vv[0]);
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (int i = 0; i < v[front].size(); i++)
		{
			if (team[v[front][i]] == team[front] && !visit[v[front][i]])
			{
				q.push(v[front][i]);
				visit[v[front][i]]=true;
				ans.push_back(v[front][i]);
			}
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == vv.size())
	{
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] != vv[i])
				return false;
		}
		return true;
	}
	else
		return false;

}
int minn = 1e9;
void dfs(int cnt)
{
	if (cnt == n)
	{
		if (team1.size() == n || team2.size() == n)
			return;
		if (check(team1) && check(team2))
		{
			int jum[2] = { 0, };
			for (int i = 1; i <= n; i++)
			{
				jum[team[i]] += people[i];
			}
			minn = min(minn, abs(jum[0]-jum[1]));
		}
		return;
	}
	
	team1.push_back(cnt+1);
	team[cnt+1] = 1;
	dfs(cnt + 1);
	team1.pop_back();
	team[cnt+1] = 0;

	team2.push_back(cnt+1);
	dfs(cnt + 1);
	team2.pop_back();

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> people[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int num2;
			cin >> num2;
			v[i].push_back(num2);
			v[num2].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
		v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());//벡터 중복 제거
	}
	dfs(0);
	if (minn == 1e9)
		cout << -1;
	else
		cout << minn;
	return 0;
}
