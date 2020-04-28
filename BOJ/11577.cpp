//https://www.acmicpc.net/problem/11577
/*풀이 : 큐의 사이즈가 토글의 횟수.. 현재 숫자가 1이고 큐사이즈가 짝수, 현재 숫자가 0이고 큐사이즈가 홀수면 토글이 필요하다. 그러므로 큐에 넣는다.. 뒤에서 k번째에 있는 수부터는 큐에 넣지 말고 현재 큐에 있는 상태에서 판단. 만약 토글이 필요한 상황이면 insomnia*/
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int arr[100001];
queue < pair<int, int> > q;
int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{

		if (i < n - k + 1)
		{
			if (arr[i] == 1 && (q.size() == 0 || q.size() % 2 == 0) || arr[i] == 0 && (q.size() % 2 == 1))
			{
				q.push({ i,i + k - 1 });
				cnt++;
			}
		}
		else
		{
			if (arr[i] == 1 && (q.size() == 0 || q.size() % 2 == 0) || arr[i] == 0 && (q.size() % 2 == 1))
			{
				cout << "Insomnia";
				exit(0);
			}
		}
		if (!q.empty())
		{
			if (i == q.front().second)
			{
				q.pop();
			}
		}
	}
	cout << cnt;

	return 0;
}
