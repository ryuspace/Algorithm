//https://www.acmicpc.net/problem/2915
/*풀이 : 1부터 99까지 모든 문자를 벡터에 넣고
입력 받은 문자열을 dfs를 이용해 가능한 문자열로 바꿔보고
순차적으로 탐색해 최소 인덱스를 찾는다.*/
#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
string n;
string one[9] = { "I","II","III","IV","V","VI","VII","VIII","IX" };
string two[9] = { "X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
bool visit[7];
int minn = 1e9;
void dfs(int cnt,string tmpp)
{
	if (cnt == n.length())
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (tmpp == v[i])
			{
				minn = min(minn, i);
				break;
			}
		}
		return;
	}
	for (int i = 0; i < n.length(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(cnt + 1, tmpp + n[i]);
			visit[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 9; i++)
	{
		v.push_back(one[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		v.push_back(two[i]);
		for (int j = 0; j < 9; j++)
		{
			v.push_back(two[i]+one[j]);
		}
	}


	cin >> n;
	dfs(0,"");
	cout << v[minn];
	return 0;

}
