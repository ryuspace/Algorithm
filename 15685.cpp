//https://www.acmicpc.net/problem/15685
#include <iostream>
#include <vector>

using namespace std;
int n;
int x, y, d, g;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
bool map[102][102];
void dragon()
{
	vector <int> v;
	map[x][y] = true;
	x += dx[d];
	y += dy[d];
	map[x][y] = true;
	v.push_back(d);
	while (g--)
	{
		for (int i = v.size()-1; i >= 0; i--)
		{
			int tmp = (v[i] + 1) % 4;
			x += dx[tmp];
			y += dy[tmp];
			map[x][y] = true;
			v.push_back(tmp);
		}
	}

}
int main()
{
	int cnt = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> y >> x >> d >> g;
		dragon();
	}
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (map[i][j] == true && map[i + 1][j] == true && map[i][j + 1] == true && map[i + 1][j + 1])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
