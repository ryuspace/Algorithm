/*3752. 가능한 시험 점수
우선 숫자를 입력 받으면 합산을 한다. 
그리고 합산 값~0까지 나왔던 숫자가 있고 이 숫자에서 현재 내 숫자 더한 값이 없으면 체크해준다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int arr[101];
	bool f[10001];
	int t;
	cin >> t;
	for(int q=1;q<=t;q++)
	{
		memset(arr, 0, sizeof(arr));
		memset(f, 0, sizeof(f));
		f[0] = true;
		int sum = 0;
		int cnt = 1;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			for (int j = sum; j >= 0; j--)
			{
				if (f[j]&&!f[j+arr[i]])
				{
					f[j + arr[i]] = true;
					cnt++;
				}
			}
		}
		cout << "#" << q << " " << cnt << '\n';
	}
	return 0;
}
