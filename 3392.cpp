//https://www.acmicpc.net/problem/3392
/*풀이 : 세그먼트 트리 + 평면 스위핑 + 좌표 압축
사각형의 x 좌표를 기준으로 순서대로 탐색하는데 그때 그 좌표에 맞는 y좌표를 업데이트 한다.
x 좌표의 시작부분 탐색 중이라면 여탯동안 나왔던 y좌표들의 구간들을 찾는다.
x 좌표의 끝부분 탐색 중이라면 우선 여탯동아 나왔던 y좌표들의 구간들을 찾고, 이 좌표의 y 좌표 카운트에서 구간들을 없애준다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct point
{
	int x, y1, y2, gap;
};
int cnt[80008];
int gesu[80008];
vector<int> yy;
vector<point> v;
bool cmp(point& a, point& b)
{
	return a.x < b.x;
}
int getidx(int gap)
{
	return lower_bound(yy.begin(), yy.end(), gap) - yy.begin();
}
void update(int start, int end, int left, int right, int gap,int node)
{
	if (left>end || right <start)
		return;
	if (left <= start && right >= end)
	{
		cnt[node] += gap;
	}
	else
	{
		int mid = (start + end) / 2;
		update(start, mid, left, right, gap, node * 2);
		update(mid + 1, end, left, right, gap, node * 2+1);
	}
	if (cnt[node] >= 1)//이 구간에 무조건 겹친다. 범위를 그대로 가져오자.
	{
		gesu[node] = yy[end+1] - yy[start];
	}
	else
	{
		if (start == end)
			gesu[node] = 0;
		else
			gesu[node] = gesu[node * 2] + gesu[node * 2 + 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ x1,y1,y2,1 });
		v.push_back({ x2,y1,y2,-1 });
		yy.push_back(y1);
		yy.push_back(y2);
	}
	sort(v.begin(), v.end(), cmp);
	sort(yy.begin(), yy.end());
	yy.erase(unique(yy.begin(), yy.end()), yy.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0)
		{
			ans += (v[i].x - v[i - 1].x) * gesu[1];
		}
		update(0, yy.size() - 1, getidx(v[i].y1), getidx(v[i].y2)-1, v[i].gap, 1);
		//만약 0~n까지의 인덱스의 좌표를 구해야 하는데 세그먼트 트리 특징상 하나의 노드에서 겹쳤다고 
		//표시가 나면 그건 y의 구간으로 볼 수 없다. 그래서 애초에 0~n-1까지 탐색하고 겹치는 좌표가 생겼을 때 구간을 end+1~start라고 보면 해결된다.

	}
	cout << ans;
	return 0;
}
