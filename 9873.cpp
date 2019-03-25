//https://www.acmicpc.net/problem/9873
/*풀이 dfs를 이용해 조건에 맞는지 체크한다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[1001];
bool visit[1001];
int ans = 0;
vector<int> v;
void dfs(int idx,int cnt)
{
	if (idx >= n)
		return;
	if (cnt == 3)
	{
		
		if ((v[1] - v[0]) * 2 >= (v[2] - v[1]) 
			&& (v[1] - v[0]) <= (v[2] - v[1]))
		{
			ans++;
		}
		return;
	}
	
	for (int i = idx; i < n; i++)
	{
		if (!visit[i])
		{
			v.push_back(arr[i]);
			visit[i] = true;
			dfs(i,cnt + 1);
			v.pop_back();
			visit[i] = false;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0,0);
	cout << ans;
	return 0;
}
