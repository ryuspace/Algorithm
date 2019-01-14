//https://www.acmicpc.net/problem/14925
/*풀이 : 내 위치에서 위,오른쪽,대각선 위에 있는 애들이 만들 수 있는 사각형 갯수 +1이 내가 만들 수
있는 사각형 갯수이다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int m, n,Max=0;
	cin >> m >> n;
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			if (x == 0)
			{
				map[i][j] = 1;
				map[i][j] = min({ map[i - 1][j],map[i][j - 1],map[i - 1][j - 1] }) + 1;
				if (Max < map[i][j])
				{
					Max = map[i][j];
				}
			}
			
		}
	}


	cout << Max;
	return 0;
}
