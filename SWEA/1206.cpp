/*1206번 View
풀이 : 2차원 배열을 이용해 실제 빌딩이 있는 위치에다가 숫자를
표시해준다. 그리고 2차원 배열을 탐색하면서 빌딩이 있으면
왼쪽 오른쪽 2칸이 비어있는지 체크해준다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[256][1001];
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int t = 0; t < 10; t++)
	{
		int cnt = 0;
		memset(arr, 0, sizeof(arr));
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			int a;
			cin >> a;
			for (int j = 0; j < a; j++)
			{
				arr[j][i]++;
			}
		}
		for (int i = 0; i <=255; i++)
		{
			for (int j = 0; j <=998; j++)
			{
				if (arr[i][j] != 0)
				{
					if (!arr[i][j - 1] && !arr[i][j - 2] &&
						!arr[i][j + 1] && !arr[i][j + 2])
					{
						cnt++;
					}
				}
			}
		}
		cout << "#" << t + 1 << " " << cnt << '\n';

	}
	return 0;
}
