/*풀이 : 
문제를 이해하기보다 용어의 정의 부분만 시키는 대로 구현하면 원하는 결과가 나온다.
*/
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

bool check(string p)
{
	stack<char> s;
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == '(')
		{
			s.push(p[i]);
		}
		else
		{
			if (s.empty())
				return false;
			s.pop();
		}
	}
	if (s.size() == 0)
		return true;
	return false;
}
string gyun(string p)
{
	if (p == "")
		return p;
	int l = 0, r = 0;
	string tmp = "";
	string tmp2 = "";
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == '(')
		{
			l++;
		}
		else
		{
			r++;
		}
		tmp += p[i];
		if (l == r)
		{
			for (int j = i + 1; j < p.length(); j++)
			{
				tmp2 += p[j];
			}
			break;
		}
	}
	if (check(tmp))
	{
		string ho = gyun(tmp2);
		tmp += ho;
		return tmp;
	}
	else
	{
		string si = "";
		si += '(';
		string ho = gyun(tmp2);
		si += ho;
		si += ')';
		string tmp3 = "";
		for (int i = 1; i < tmp.length() - 1; i++)
		{
			if (tmp[i] == '(')
				tmp3 += ')';
			else
				tmp3 += '(';
		}
		si += tmp3;
		return si;
	}
}
string solution(string p) {
	
	if (check(p))
		return p;
	return gyun(p);
	
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
