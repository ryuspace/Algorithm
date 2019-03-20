#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

queue<int> l[500];
queue<int> r[500];
vector<pair<int, int> > v;
int l_cnt[500];
int r_cnt[500];

//알파벳끼리 매칭, 위쪽 ?와 아랫쪽 알파벳과 매칭, 위쪽 알파벳과 아래쪽 ?과 매칭, 위쪽 ?와 아랫쪽 ?과 매칭
int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		l_cnt[a[i]]++;
		l[a[i]].push(i + 1);
	}
	for (int i = 0; i < a.length(); i++)
	{
		r_cnt[b[i]]++;
		r[b[i]].push(i + 1);
	}


	int minn = 1e9;
	for (int i = 'a'; i <= 'z'; i++)
	{
		minn = min(l_cnt[i], r_cnt[i]);

		for (int j = 0; j < minn; j++)
		{
			int front1 = l[i].front();
			int front2 = r[i].front();
			v.push_back({ front1,front2 });
			l[i].pop();
			r[i].pop();
			l_cnt[i]--;
			r_cnt[i]--;
		}
	}
	minn = 1e9;

	for (int i = 'a'; i <= 'z'; i++)
	{
		minn = min(l_cnt['?'], r_cnt[i]);
		for (int j = 0; j < minn; j++)
		{
			int front1 = l['?'].front();
			int front2 = r[i].front();
			v.push_back({ front1,front2 });
			l['?'].pop();
			r[i].pop();
			l_cnt['?']--;
			r_cnt[i]--;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		minn = min(l_cnt[i], r_cnt['?']);
		for (int j = 0; j < minn; j++)
		{
			int front1 = l[i].front();
			int front2 = r['?'].front();
			v.push_back({ front1,front2 });
			l[i].pop();
			r['?'].pop();
			l_cnt[i]--;
			r_cnt['?']--;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		minn = min(l_cnt['?'], r_cnt['?']);
		for (int j = 0; j < minn; j++)
		{
			int front1 = l['?'].front();
			int front2 = r['?'].front();
			v.push_back({ front1,front2 });
			l['?'].pop();
			r['?'].pop();
			l_cnt['?']--;
			r_cnt['?']--;
		}
	}

	cout << v.size() << "\n";
	for (auto&i : v)
	{
		cout << i.first << " " << i.second << '\n';
	}


	return 0;
}
