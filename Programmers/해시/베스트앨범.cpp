/*풀이 : 
cmp 하는 방법 익혀둘 만 하다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, int> m;
map<string, int> m2;
struct point
{
	string jang;
	int je, idx;
};
bool cmp(point& a, point& b)
{
	if (m[a.jang]>m[b.jang])
	{
		return true;
	}
	else if (m[a.jang] == m[b.jang])
	{
		if (a.je > b.je)
			return true;
		else if (a.je == b.je)
		{
			return a.idx < b.idx;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<point> first;
	for (int i = 0; i < genres.size(); i++)
	{
		m2[genres[i]]++;
		m2[genres[i]] = min(m2[genres[i]], 2);
		m[genres[i]] += plays[i];
		first.push_back({ genres[i],plays[i],i });
	}
	sort(first.begin(), first.end(), cmp);
	for (int i = 0; i < first.size(); i++)
	{
		if (m2[first[i].jang] > 0)
		{
			answer.push_back(first[i].idx);
			m2[first[i].jang]--;
		}
	}
	return answer;
}
