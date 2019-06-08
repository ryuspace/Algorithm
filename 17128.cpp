//https://www.acmicpc.net/problem/17128
/*풀이 : 어떤 소는 부분합의 4군데에만 속해있으므로 그 4군데의 값만 바꿔줘서
O(80만)에 해결한다.*/
#include <iostream>

using namespace std;

int arr[200010];
int memo[200010];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	int hap = 0;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		hap+=memo[i] += (arr[i % n] * arr[(i + 1) % n] * arr[(i + 2) % n] * arr[(i + 3) % n]);
	}
	for (int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < 4; j++)
		{
			hap -= memo[((a - 1)-j + n) % n];
			hap += memo[((a - 1)-j + n) % n] *= -1;
		}
		cout << hap << '\n';
	}
	return 0;
}
