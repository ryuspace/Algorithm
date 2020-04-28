//https://www.acmicpc.net/problem/15686
/*풀이 : 치킨집의 위치를 담은 벡터를 만든다. dfs를 이용해 최대 m개의 치킨집을 선택하고
치킨집 선택 or 치킨집 안 선택 이렇게. 최대 m개의 치킨집이 선택되었으면 각각의 집에 대하여
치킨집과의 최소 거리를 결과값에 더한다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
vector <pii> chi;
vector <pii> hom;

int map[51][51];
int n, m;
bool visit[51];//dfs 방문확인

int minn = 1e9;
void dfs(int cur,int cnt)
{
	if (cur > chi.size())
		return;
	if (cnt == m)
	{
		int res = 0;
		for (int i = 0; i < hom.size(); i++)
		{
			int hi =1e9;
			for (int j = 0; j < chi.size(); j++)
			{
				if (visit[j])
				{
					hi = min(hi, abs(chi[j].first - hom[i].first) + abs(chi[j].second - hom[i].second));
				}
			}
			res += hi;
		}
		minn = min(res, minn);
		return;
	}
	visit[cur] = true;
	dfs(cur + 1, cnt + 1);
	visit[cur] = false;
	dfs(cur + 1, cnt);

}
int main()
{
	//dfs를 이용해 치킨집을 선택하고,치킨집이 선택 되면 각 집에 대해 bfs를 돌려보자.
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				hom.push_back({ i,j });
			}
			else if (map[i][j] == 2)
			{
				chi.push_back({ i,j });
			}
		}
	}

	dfs(0,0);
	cout << minn;
	return 0;
}

