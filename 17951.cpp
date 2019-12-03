//https://www.acmicpc.net/problem/17951
/*풀이 : 
약간의 greedy + 이분탐색
N과 K의 제한이 10^5이므로 시간복잡도가 n^2 미만이어야 한다.
우선 시험지의 총 점수 / k를 한 것이 k개의 그룹으로 나눴을 때 최대한의 점수이다.
그러므로 최소 점수인 0점부터 총 점수/k 까지 이분 탐색으로 점수를 정해놓고
그 점수보다 그룹 점수가 낮으면 (너무 높게 잡았다)right를 mid로 해주고 
그 점수보다 그룹 점수가 높으면 (너무 낮게 잡았다)left를 mid로 해줘서 정답을 구한다.
배열을 순차적으로 탐색하면서 정해진 점수보다 높아지면 그룹을 잘라준다.
시간 복잡도는 nlogn으로 해결하였다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	int l = 0;
	int r = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		r += arr[i];
	}
	r = r / k;
	while (l <= r)
	{
		int m = (l + r) / 2;
		int sum = 0;
		int minn = 1e9;
		int cnt = 1;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			if (sum > m)//정해놓은 점수를 넘어버렸으면 stop!
			{
				minn = min(minn, sum);
				sum = 0;
				cnt++;
			}
			bool f = false;
			if (cnt == k)//마지막 그룹. 모든 수를 다 더해서 체크하자.
			{
				for (int j = i + 1; j < n; j++)
				{
					sum += arr[j];
				}
				minn = min(minn, sum);
				f = true;
			}
			if (f)
				break;
		}
		if (minn <= m)
			r = m - 1;
		else
			l = m + 1;
	}
	cout << l;

	return 0;
}
