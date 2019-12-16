#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int cnt = 0;
void dfs(int num,int cnt)
{

	if (num >= m)
	{
		if (num == m)
		{
			cout << cnt;
			exit(0);
		}
		else
		{
			return;
		}
	}
	dfs(num * 2,cnt+1);
	dfs(num * 3,cnt+1);
}
int main()
{
	ios_base::sync_with_stdio(0);


	cin >> n >> m;
	dfs(n,0);
	cout << -1;
	return 0;
}
