//https://www.acmicpc.net/problem/15565
/*1이 들어오면 큐에 담다가 k개만큼 찼을때 앞에서부터 빼준다. 그리고 큐에 있는 맨 뒤 인덱스 - 맨 앞 인덱스 +1 한 것(길이)을 벡터에다 담아준다.
그리고 그 길이 중 최소를 출력.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue <int> q;
vector <int> v;
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, k;
	int start = 0;
	int cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;

		if (a == 1)
		{
			q.push(i);
			cnt++;
			if (cnt == k)
			{
				v.push_back(i - q.front() + 1);
				q.pop();
				cnt--;
			}
		}
	}
	if (v.empty())
	{
		cout << -1;
		exit(0);
	}
	sort(v.begin(), v.end());
	cout << v[0];
	
	return 0;
}
