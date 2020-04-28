//자른 문자열을 벡터에 담고 다음 문자열을 자를 때 이전 문자열과 같은지 비교하는게 포인트!
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int solution(string s) {
	int minn = 1e9;
	for (int i = 1; i <= s.length(); i++)
	{
		vector<pair<string,int> > v;
		string tmp= "";
		int cnt = 0;
		for (int j = 0; j <s.length(); j++)
		{
			cnt++;
			tmp += s[j];
			if (cnt == i)
			{
				if (!v.empty() && v[v.size() - 1].first == tmp)//이전 문자열이랑 같다. 갯수만 추가
				{
					v[v.size() - 1].second += 1;
				}
				else//반복되는 문자열 끝
				{
					v.push_back(make_pair(tmp, 1));
				}
				cnt = 0;
				tmp = "";
			}
		}
		if (cnt != 0)
		{
			if (!v.empty() && v[v.size() - 1].first == tmp)
			{
				v[v.size() - 1].second += 1;
			}
			else
			{
				v.push_back(make_pair(tmp, 1));
			}
		}
		int cnt2 = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j].second != 1)
			{
				string hi = to_string(v[j].second);
				cnt2 += hi.length();
			}
			cnt2 += v[j].first.length();
		}
		minn = min(minn, cnt2);
	}
	return minn;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	cout << solution(s);

	return 0;
}
