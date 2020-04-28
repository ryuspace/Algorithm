//https://www.acmicpc.net/problem/15991
/*풀이 : n번째 숫자는 n-2번째에 양 옆에 1을 붙인 것, n-4번째에 양 옆에 2를 붙인 것 n-6번째에
양 옆에 3을 붙인 것과 같다. 초반에는 n이 4일 때와 6일 때는 예욋값인 22,33이 들어가므로 memeo[0]
에 그걸 처리해 줄 값 하나를 넣어준다.*/
#include <iostream>
#include <algorithm>

using namespace std;

long long int memo[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 2;
	for (int i = 4; i <= 100000; i++)
	{
		memo[i] = (memo[i - 2] + memo[i - 4] + memo[i - 6]) % 1000000009;
	}

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << memo[n] << '\n';
	}
	return 0;
}
