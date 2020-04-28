//https://www.acmicpc.net/problem/13913
/*풀이 : parent 배열을 만들어서 이전 상태를 저장한 후 동생의 위치에 도착한 순간 수빈이의 위치가
나올 때 까지 역추적한다. */
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

bool visit[200001];
int arr[200001];
int parent[200001];
int n, k;
queue <int> q;
vector <int> v;
void bfs()
{
	//parent[n] = 0;
	visit[n] = true;
	q.push(n);

	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			int tmp = q.front();
			q.pop();
			if (tmp == k)
			{
				for (int i = k; i != n; i = parent[i])
				{
					v.push_back(i);
				}
				v.push_back(n);

				cout << arr[tmp] << '\n';
				for(int i=v.size()-1;i>=0;i--)
				{
					cout << v[i] << " ";
				}
				exit(0);
			}
			if (tmp - 1 >= 0)
			{
				if (visit[tmp - 1] == false)
				{
					arr[tmp - 1] = arr[tmp]+1;
					parent[tmp - 1] = tmp;
					q.push(tmp - 1);
					visit[tmp - 1] = true;
				}

			}
			if (tmp + 1 <= 200000)
			{
				if (visit[tmp + 1] == false)
				{
					arr[tmp + 1] = arr[tmp]+1;
					parent[tmp + 1] = tmp;
					q.push(tmp + 1);
					visit[tmp + 1] = true;
				}

			}
			if (2 * tmp <= 200000)
			{
				if (visit[2 * tmp] == false)
				{
					arr[2 * tmp] = arr[tmp]+1;
					parent[2 * tmp] = tmp;
					q.push(2 * tmp);
					visit[2 * tmp] = true;
				}
			}
		}
		
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> k;
	bfs();
	
	return 0;

}
