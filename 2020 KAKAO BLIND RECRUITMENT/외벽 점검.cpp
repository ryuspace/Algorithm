/*풀이 :
사람들을 1~n까지 배치할 수 있는 경우의 수를 구하고 취약점에 배치한다.
배치할 때 배치한 사람의 관장 가능 거리 이후에 다음 사람을 배치를 한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
bool visit[9];
vector<int> me;
vector<int> weak2;
vector<int> dist2;
int weak_size;
int dist_size;
int minn = 1e9;

void go()
{
	for (int i = 0; i < weak_size; i++)
	{
		bool flag = false;
		int sum = 0;
		int idx = 0;
		for (int j = i; j < weak_size + i; j++)
		{
			if (i != j)
			{
				sum += weak2[j] - weak2[j - 1];
				if (sum > dist2[me[idx]])
				{
					sum = 0;
					idx++;
				}
				if (idx >= me.size())
				{
					flag = true;
					break;
				}
			}
		}
		if (!flag && idx < me.size())
		{
			minn = min(minn, idx+1);
		}
	}

}
void dfs(int cnt)
{
	if (cnt > dist_size || cnt>=minn)
	{
		return;
	}
	else if(cnt>=1)
	{
		go();
		if (cnt == dist_size)
			return;
	}
	for (int i = 0; i < dist_size; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			me.push_back(i);
			dfs(cnt + 1);
			visit[i] = false;
			me.pop_back();
		}
	}
}
int solution(int n, vector<int> weak, vector<int> dist) {

	dist_size = dist.size();
	weak_size = weak.size();
	dist2 = dist;
	for (int i = 0; i < weak.size(); i++)
	{
		weak2.push_back(weak[i]);
	}
	for (int i = 0; i < weak.size(); i++)
	{
		weak2.push_back(weak[i]+n);
	}
	dfs(0);
	if (minn == 1e9)
		return -1;
	return minn;
}
