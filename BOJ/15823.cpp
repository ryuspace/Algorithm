//https://www.acmicpc.net/problem/15823
/*풀이 : 이분탐색으로 카드팩 몇 장 살 수 있는지 계속 찾는다. 만약 mid값만큼 찾았으면
그 앞에 카드는 카드팩을 구성한거므로 다음장으로 바로 넘어간다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int arr[100001];
set <int> s;
queue <int> q;
queue <int> hi;
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int ans = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int left = 1;
	int right = n;

	while (left <= right)
	{

		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (s.find(arr[i]) == s.end())//새로운 수
			{
				q.push(arr[i]);
				s.insert(arr[i]);
				if (s.size() == mid)
				{
					cnt++;
					s.clear();
					q = hi;
				}
			}
			else//이미 나온 수
			{
				while (!q.empty())
				{
					int front = q.front();
					s.erase(front);
					q.pop();
					if (front == arr[i])
						break;
				}
				q.push(arr[i]);
				s.insert(arr[i]);
				if (s.size() == mid)
				{
					cnt++;
					s.clear();
					q = hi;
				}
				
			}
			
		}
		if (cnt < m)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		q = hi;
		s.clear();
	}

	cout << right;
	return 0;
}
