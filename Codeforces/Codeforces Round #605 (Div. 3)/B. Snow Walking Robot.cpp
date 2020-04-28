/*풀이 : 처음에는 어려워보였지만 순서를 바꿀 수 있으므로 매우 쉬운 문제가 되었다.
우선 (0,0)으로 다시 돌아와야하고 그 이외의 셀은 밟으면 안된다.
그렇다면 L갯수와 R갯수를 파악해 최소만큼 가게하고 U갯수와 D갯수를 파악해 최소만큼 가게 한다.
만약 위의 두 쌍 중 한 쌍이 0이면 그냥 한번만 왔다갔다 하게 하면 된다
이렇게 했으면 같은 셀로만 안 가게 임의로 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[200001];
int arr[200001];
queue<int> q;
int ans[200001];
bool visit[200001];
void bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (int i = 0; i < v[front].size(); i++)
		{
			if (!visit[v[front][i]])
			{
				visit[v[front][i]] = true;
				q.push(v[front][i]);
				ans[v[front][i]] = ans[front] + 1;
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		ans[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (i - arr[i] >= 0)
		{
			v[i - arr[i]].push_back(i);
			if ((arr[i] % 2) != (arr[i - arr[i]] % 2))
			{
				ans[i] = 1;
			}
		}
		if (arr[i] + i < n)
		{
			v[i + arr[i]].push_back(i);
			if ((arr[i] % 2 )!= (arr[i + arr[i]] % 2))
			{
				ans[i] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 1)
		{
			q.push(i);
			visit[i] = true;
		}
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
