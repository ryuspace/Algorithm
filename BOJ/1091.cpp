//https://www.acmicpc.net/problem/1091
/*풀이 : 그냥 나왔던 문자열이면 set에 저장해줘서 다시 그 set 값에 접근하려고 하면 무한루프가 돈다는 뜻이다. 구현.*/
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int n;
set <string> se;
string p;
int s[49];

void go(string tmp)
{
	int cnt = 0;
	while (se.count(tmp) == 0)
	{
		se.insert(tmp);
		if (tmp == p)
		{
			cout << cnt << '\n';
			exit(0);
		}
		string new_tmp = "";
		for (int i = 0; i < tmp.size(); i++)
		{
			new_tmp += tmp[s[i]];
		}
		cnt++;
		tmp = new_tmp;
	}


}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string jemul = "";
	string a = "";
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		jemul += to_string(i % 3);
		int a;
		cin >> a;
		p += to_string(a);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	go(jemul);
	cout << -1;
	return 0;
}
