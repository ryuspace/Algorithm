/*2477번 차량정비소
풀이 : 시키는대로 구현하자
ver1보다 훨씬 현실적인 상황을 고려해서 코딩했다. 시간과 코드 길이는 더 늘어났지만 디버깅하기가 더 편했다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

int t,n,m,k,a,b;

int rec_time[10];
int rep_time[10];
struct point
{
	int burst, who;
};

struct people
{
	int idx, time;
};
point rec[10];
point rep[10];

queue<people> q1;


pii check[1001];

int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int q = 1;q <= t;q++)
	{
		memset(rep, 0, sizeof(rep));
		vector<pii> v;
		queue<int> q2;
		cin >> n >> m >> k >> a >> b;
		for (int i = 0;i < n;i++)
		{
			cin >> rec_time[i];
		}
		for (int i = 0;i < m;i++)
		{
			cin >> rep_time[i];
		}
		for (int i = 0;i < k;i++)
		{
			int aa;
			cin >> aa;
			q1.push({ i + 1,aa });
		}
		int finish = 0;
		for (int time = 0;;time++)
		{
			//먼저 끝났으면 내쫓기
			for (int i = 0;i < n;i++)
			{
				if (rec[i].who != 0)
				{
					rec[i].burst--;
					if (rec[i].burst == 0)
					{
						q2.push({ rec[i].who });
						rec[i].who = 0;
					}
				}
			}

			if (!q1.empty())
			{
				for (int i = 0;i < n;i++)
				{
					if (!q1.empty() && q1.front().time <= time && rec[i].who == 0)
					{
						rec[i].who = q1.front().idx;
						rec[i].burst = rec_time[i];
						check[rec[i].who].first = i + 1;
						q1.pop();
					}
				}
			}
			//접수창구 완료

			
			for (int i = 0;i < m;i++)
			{
				if (rep[i].who != 0)
				{
					rep[i].burst--;
					if (rep[i].burst == 0)
					{
						rep[i].who = 0;
					}
				}
			}

			if (!q2.empty())
			{
				for (int i = 0;i < m;i++)
				{
					if (!q2.empty() && rep[i].who == 0)
					{

						rep[i].who = q2.front();
						rep[i].burst = rep_time[i];
						check[rep[i].who].second = i + 1;
						q2.pop();
						finish++;
					}
				}
			}

			if (finish == k)
				break;
		}
		int sum = 0;
		for (int i = 1;i <= k;i++)
		{

			if (check[i].first == a && check[i].second == b)
			{
				sum += i;
			}

		}
		if (sum == 0)
		{
			cout << "#" << q << " " << -1 << '\n';
		}
		else
			cout << "#" << q << " " << sum << '\n';
	}
	return 0;
}
