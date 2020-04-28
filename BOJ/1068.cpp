//https://www.acmicpc.net/problem/1068
/*풀이 : 벡터 배열에 각각 이어진 정보를 저장하고 dfs 함수로 지워질 노드의 자식 노드를 모두 지워버린다.
그리고 벡터 배열을 쭉 탐색해서 지워질 노드를 자식으로 한 경우 지워준다.
또 dfs2 함수를 이용해 루트부터 탐색하는데 만약 자식이 없는 상태면 카운트를 올려준다.
하지만 이 코드는 루트를 지울 때 적용되지 않는다! 그러므로 반례로 루트를 지운 경우 자식 노드가 전부
지워지고 본인도 지워지므로 그때는 0을 출력하게 한다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[51];
void dfs(int num)
{
	for (int i = 0; i < v[num].size(); i++)
	{
		dfs(v[num][i]);
		v[num].pop_back();
	}
}
int cnt2 = 0;
void dfs2(int num)
{
	if (v[num].size() == 0)
		cnt2++;
	for (int i = 0; i < v[num].size(); i++)
	{
		dfs2(v[num][i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n, del, root, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == -1)
			root = i;
		else
			v[a].push_back(i);
	}
	cin >> del;
	dfs(del);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == del)
			{
				v[i].erase(v[i].begin() + j);
			}
		}
	}
	dfs2(root);
	if (del == root)
		cout << 0;
	else
		cout << cnt2;
	return 0;
}
