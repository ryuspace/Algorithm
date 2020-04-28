/*2477번 차량정비소
풀이 : 시키는대로 구현하자
ver1보다 훨씬 현실적인 상황을 고려해서 코딩했다. 시간과 코드 길이는 더 늘어났지만 디버깅하기가 더 편했다.
주석으로 추가 설명을 하겠습니다.

간과했던 부분 : 마지막 인덱스 사람이 마지막으로 끝날 것이라고 생각했다. + 문제를 잘 읽자.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
int t, n, m, k, a,b;
struct info
{
	int jin, so, idx;
};
//접수 창구와 정비 창구가 갖고 있는 요소는 진행 시간, 접수(정비)창구의 소요시간, 그 창구에 있는 사람 
struct point
{
	int time, num, idx;
};//정비창구의 우선순위 요소
bool cmp(const point& a, const point& b)
{
	if (a.time < b.time)
		return true;
	else if (a.time == b.time)
	{
		if (a.num < b.num)
			return true;
		else
			return false;
	}
	else
		return false;
}
info jub[11];
info jung[11];

int main()
{
	freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		int out = 0;
		pii ans[1001];
		queue<pii> zero;
		priority_queue<pii, vector<pii>, greater<pii> > one;
		vector<point> two;
		cin >> n >> m >> k >> a>>b;
		for (int i = 1; i <= n; i++)
		{
			cin >> jub[i].so;
			jub[i].jin = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> jung[i].so;//진행시간 소요시간 있는 사람
			jung[i].jin = 0;

		}
		for (int i = 1; i <= k; i++)
		{
			int n;
			cin >> n;
			zero.push({ i,n });//사람, 온 시간..
		}
		int idx = 1;
		for (int time = 0;; time++)
		{
			while (!zero.empty() && time == zero.front().second)
			{
				one.push({ zero.front().first,zero.front().second });
				zero.pop();
			}
			for (int i = 1; i <= n; i++)
			{
				if (jub[i].jin==jub[i].so)//시간이 다 지났다 내보내자.
				{
					two.push_back({ time,i,jub[i].idx });
					jub[i].idx= 0;
					jub[i].jin = 0;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (jub[i].idx == 0)
				{
					if (!one.empty())
					{
						ans[one.top().first].first = i;
						jub[i].idx = one.top().first;
						jub[i].jin = 1;
						one.pop();
					}
				}
				else
				{
					jub[i].jin++;
				}
			}
			bool flag = false;
			sort(two.begin(), two.end(),cmp);
			for (int i =1; i <= m; i++)
			{
				if (jung[i].jin ==jung[i].so)
				{
					out++;
					if (out == k)
						flag = true;
					jung[i].idx = 0;
					jung[i].jin = 0;
				}
			}
			for (int i = 1; i <= m; i++)
			{
				if (jung[i].idx == 0)
				{
					if (!two.empty())
					{
						ans[two[0].idx].second = i;
						jung[i].idx = two[0].idx;
						jung[i].jin= 1;
						two.erase(two.begin());
					}
				}
				else
				{
					jung[i].jin++;
				}
			}
			if (flag)
				break;
		}
		int cnt = 0;

		for (int i = 1; i <= k; i++)
		{
			if (ans[i].first ==  a && ans[i].second==b)
			{
				cnt += i;
			}
		}
		if (cnt == 0)
			cnt = -1;
		cout << "#" << r << " " << cnt << '\n';
	}
	return 0;
}

