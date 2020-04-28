//https://www.acmicpc.net/problem/15708
/*풀이 : 지나가면서 시간 내에 담을 수 있는 돌을 담는다. 시간초과가 나면 가장 곡괭이질을 
많이 해야하는 돌부터 차례대로 뺀다. */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int arr[100001];
priority_queue <int, vector<int>, less<int> > pq;
int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, t, p;
	cin >> n >> t >> p;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sum = 0;
	int cnt = 0;
	int Max = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		pq.push(arr[i]);
		cnt++;
		while (sum > t - i * p)
		{
			if (t - i * p < 0)//더 이상 지나가는 것이 불가능하다.
			{
				cout << Max;
				exit(0);
			}
			int top = pq.top();
			pq.pop();
			sum -= top;
			cnt--;
		}
		Max = max(cnt, Max);
	}

	cout << Max;
	return 0;
}
