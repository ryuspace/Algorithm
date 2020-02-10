//https://www.acmicpc.net/problem/18311
/*풀이 : 자료형 주의...
K에서 i번째 이동거리만큼 빼본다. 0이랑 같으면은 다음 인덱스므로 0 미만일 때 해당위치가 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long int k;
long long int arr[100001];
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		k -= arr[i];
		if (k < 0)
		{
			cout << i + 1;
			exit(0);
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		k -= arr[i];
		if (k < 0)
		{
			cout << i + 1;
			exit(0);
		}
	}

	return 0;
}
