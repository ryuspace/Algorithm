//https://www.acmicpc.net/problem/1005
/*풀이 : 위상정렬을 이용해 일의 순서를 정한다.
어떤 일을 마치려면 앞의 일들이 모두 마쳐져야 한다.
어떤 일이 마쳐지는 데 걸리는 최장시간을 time배열에 넣고
arr배열에는 처음 일부터 이번 일 까지 걸린 총 시간을 넣는다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int arr[1001];
int degree[1001];
int time[1001];
vector<int> v[1001];

int topology(int num)
{

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (int i = 0; i < v[front].size(); i++)
		{
			time[v[front][i]] = max(arr[v[front][i]] + arr[front], time[v[front][i]]);
			if (--degree[v[front][i]] == 0)
			{
				q.push(v[front][i]);
				arr[v[front][i]] = time[v[front][i]];
			}
		}
	}
	return arr[num];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int r = 0; r < t; r++)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
			time[i] = 0;
			cin >> arr[i];
		}
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			degree[b]++;
		}
		int num,sum=0;
		cin >> num;
		cout << topology(num) << '\n';
	}
	return 0;
}
