/*
9088.다이아몬드
풀이 :다이아몬드를 하나를 기준을 잡아 가장 적은 무게의 다이아몬드라 가정하면
가져올 수 있는 다이아몬드들은 기준보단 같거나 무겁고 기준+k보단 같거나 가볍다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int main()
{
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int q=1;q<=t;q++)
	{
		int maxx = 0;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++)
		{
			int cnt = 1;
			int si = arr[i] + k;
			int bal = arr[i];
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					if (arr[j] >= bal && arr[j]<=si)
						cnt++;
				}
				
			}
			maxx = max(maxx, cnt);
		}
		cout << "#" << q << " " << maxx << '\n';
	}
	return 0;
}
