//https://www.acmicpc.net/problem/15461
/*풀이 : id와 생셩량을 담는 map과 생성량과 마릿수를 담는 map을 만든다. display가 바뀌는 경우를 나눠
count 한다.*/
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector< pair< pair<int, string>, int> > v;
map<string, int> m;
map<int, int> win;
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, g;
	cin >> n >> g;
	for (int i = 0; i < n; i++)
	{
		int day;
		string id;
		char buho;
		int amount;
		cin >> day >> id >> buho >> amount;
	
		if (buho == '+')
		{
			v.push_back({ {day,id},amount });
		}
		else
		{
			v.push_back({ {day,id},-amount });
		}
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		string id = v[i].first.second;
		int amount = v[i].second;
		if (m.find(id) == m.end())//이 id에 대한 정보가 처음 들어감
		{
			m[id] =g+amount;
			win[m[id]]++;
			if (win.find(g+amount) == --win.end())
			{
				cnt++;
			}
		}
		else if(win.find(m[id])== --win.end() && win[m[id]]==1)//기존의 id가 담은 양이 최대고 혼자다.
		{
			win.erase(win.find(m[id]));
			m[id] += amount;
			win[m[id]]++;
			if (amount < 0)
			{
				if (win.find(m[id]) == --win.end() && win[m[id]]==1)//amount가 마이너스지만 미묘하게 변하면 display가 안 바뀌는 경우가 생긴다.
				{

				}
				else
				{
					cnt++;
				}
			}
		}
		else if (win.find(m[id]) == --win.end() && win[m[id]] > 1)//기존의 id가 담은 양이 최대고 혼자가 아니다.
		{
			win[m[id]]--;
			m[id] += amount;
			win[m[id]]++;
			cnt++;
		}
		else//기존의 id가 담은 양이 최대가 아니다.
		{
			if (win[m[id]] == 1)
				win.erase(win.find(m[id]));
			else
			{
				win[m[id]]--;
			}
			m[id] += amount;
			win[m[id]]++;
			if (win.find(m[id]) == --win.end())
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
