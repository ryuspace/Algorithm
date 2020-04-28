/*1952번 수영장
풀이 : 이번 월에 이용 안했으면 다음 월로 패스
이용 했으면 가능한 모든 이용권을 사용하는 경우를 찾는다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int t;
int n;
int gap[4];
int day[12];
int minn = 1e9;
void dfs(int cnt,int sum)//cnt는 현재 달
{
	if (cnt > 12)
		return;
	if (cnt == 12)
	{
		minn = min(minn, sum);
		return;
	}
	if (day[cnt] == 0)
		dfs(cnt + 1, sum);

	dfs(cnt + 1, sum + day[cnt] * gap[0]);
	dfs(cnt + 1, sum + gap[1]);
	dfs(cnt + 3, sum + gap[2]);
	if(cnt==0)
		dfs(cnt + 12, sum + gap[3]);

}
int main()
{
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		minn = 1e9;
		for (int i = 0; i < 4; i++)
			cin >> gap[i];
		for (int i = 0; i < 12; i++)
			cin >> day[i];
		dfs(0,0);
		cout << "#"<<r<<" "<<minn<<'\n';
	}
	return 0;
}
