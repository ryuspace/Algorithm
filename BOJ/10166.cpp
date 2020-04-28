//https://www.acmicpc.net/problem/10166
/*풀이 : 각도가 같으면 한 자리 밖에 못 놓는다. 각도를 기약분수 형태로 만든 후
겹치는지 체크한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

bool visit[2001][2001];
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
int main() 
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int d1, d2;
	cin >> d1 >> d2;
	
	for (int i = d1; i <= d2; i++)//분모
	{
		for (int j = 1; j <= i; j++)//분자
		{
			int na = gcd(i, j);
			int x = j / na;
			int y = i / na;
			if (!visit[x][y])
			{
				visit[x][y] = true;
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
