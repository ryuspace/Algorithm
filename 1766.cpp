//https://www.acmicpc.net/problem/1766
/*풀이 : 단순한 위상정렬.. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> v[32001];
int arr[32001];
int n, m;

void topology()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			pq.push(i);
		}
	}
	while (!pq.empty())
	{
		int front = pq.top();
		pq.pop();
		cout << front << " ";
		for (int i = 0; i < v[front].size(); i++)
		{
			arr[v[front][i]]--;
			if (arr[v[front][i]] == 0)
			{
				pq.push(v[front][i]);
			}
		}
	}


}
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	topology();
	return 0;
}
