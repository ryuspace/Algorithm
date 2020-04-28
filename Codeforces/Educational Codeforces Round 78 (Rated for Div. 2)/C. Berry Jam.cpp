
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int arr[200002];
		map<int, int> m;
		int minn = 1e9;
		int sum = 0;
		int cnt = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= 2*n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 2 * n; i >= n; i--)//탐색범위는 오른쪽 잼 하나도 안 먹음 ~ 오른쪽 잼 다 먹음..  그래서 n까지 탐색하는거다.
		{
			m[sum] = i;//이 인덱스 이전까지 다 먹음.
			if (arr[i] == 1)
				sum++;//양수면 딸기잼이 더 많이 남은거고 음수면 블루베리 잼이 더 많이 남은거다.
			else
				sum--;
		}
		for (int i = 1; i <= n+1; i++)
		{
			if (m.count(cnt) != 0)//탐색범위는 왼쪽 잼 하나도 안 먹음 ~ 왼쪽 잼 다 먹음..  그래서 n+1까지 탐색하는거다.
			{
				minn = min(minn, m[cnt] - i + 1);
			}
			if (arr[i] == 2)//오른쪽은 딸기잼 기준으로 count했으니 왼쪽은 상쇄 시켜야 하므로 블루베리 잼 기준으로 카운트 해줘야 한다.
			{
				cnt++;
			}
			else
			{
				cnt--;
			}
		}
		cout << minn << '\n';

	}
	return 0;
}
