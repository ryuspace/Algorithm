//https://www.acmicpc.net/problem/1756
/*풀이 : i번째 오븐에 넣을 수 있는 피자의 지름은 0~i-1번째의 오븐 길이의 최소이다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[300001];
int pizza[300001];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int minn = 1e9;
	int d, n;
	cin >> d >> n;
	for (int i = 0; i < d; i++)
	{
		cin >> arr[i];
		arr[i]= minn = min(minn, arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> pizza[i];
	}
	int cnt = 0;
	for (int i = d - 1; i >= 0; i--)
	{
		if (pizza[cnt] <= arr[i])
		{
			cnt++;
		}
		if (cnt == n)
		{
			cout << i + 1;
			exit(0);
		}
	}
	cout << 0;
	return 0;
}
