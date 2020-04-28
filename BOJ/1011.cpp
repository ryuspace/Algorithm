/*풀이 :
첫번째 시도 : dfs로 재귀 이용해서 메모리 초과 남..
두번째 시도 : 처음과 끝은 1이므로 최소 이동횟수는 팰린드롬을 나타낸다..
1 1 =>1
2 11 => 2
3 111 =>3
4 121 =>3
5 1211 =>4
6 1221 =>4
7 12211 =>5
8 12221 =>5
9 12321 =>5
10 123211 =>6
11 123221 =>6
12 123321  =>6
13 1233211 =>7
14 1233221 =>7
15 1233321 =>7
16 1234321 =>7
17 12343211 => 7

1 2 (3 3) (4 4) (5 5 5) (6 6 6) (7 7 7 7) (8 8 8 8)
1 1 2 2 3 3 4 4 5 5 6 6 ...


sum 숫자에서 나타내는 이동횟수가 num..
ex) sum이 10이면 이동횟수는 6... dis는 반복 횟수(1 1 2 2 3 3 4 4 5 5 6 6 ...)! 
*/
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long int x, y;
		cin >> x >> y;
		long long int hi = y - x;
		long long int dis = 1;
		long long int sum = 0;
		long long int num = 0;
		while (sum < hi)
		{
			sum += dis;
			num++;
			if (sum >= hi)
				break;
			sum += dis;
			num++;
			dis++;
		}
		cout << num << '\n';
	
	}

	return 0;
}
