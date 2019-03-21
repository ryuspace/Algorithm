//https://www.acmicpc.net/problem/1021
/*풀이 : deque를 이용한다. 찾고싶은 숫자를 기준으로 앞에서 부터 셌을 때랑 뒤에서 부터 셌을 때의
최소의 명령을 실행한다. 만약 뒤에서부터 찾을때는 찾을 수를 앞으로 한번 더 빼야하는 것 주의*/
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> dq;
deque<int>::iterator iter;

int main() 
{
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
	int cnt = 0;
	while (m--)
	{
		int a;
		cin >> a;
		int idx = 0;
		for (iter = dq.begin(); iter < dq.end(); iter++)
		{
			if (*iter == a)
				break;
			idx++;
		}
		int le = idx;
		int ri = dq.size() - idx;
		if (le < ri)
		{
			for (int i = 0; i < le; i++)
			{
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				cnt++;
			}
			dq.pop_front();
		}
		else
		{
			for (int i = 0; i < ri; i++)
			{
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				cnt++;
			}
			dq.pop_front();
		}
	}
	cout << cnt;
	return 0;
}

