//https://www.acmicpc.net/problem/11509
/*풀이 :
그리디 알고리즘. 이 풍선을 터뜨리는데 화살이 들지 않으려면 이 풍선 왼쪽 어딘가에 1 큰 풍선이 있어야 한다.
풍선을 한 바퀴 돌면서 다음 풍선들을 체크하기 위해 풍선이 있는 위치를 계속 카운트 해준다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000001];
int lef[1000001];
int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (lef[arr[i] + 1] == 0)//없엉
		{
			cnt++;
		}
		else
		{
			lef[arr[i] + 1]--;
		}
		lef[arr[i]]++;

	}

	cout << cnt;
	return 0;
}
