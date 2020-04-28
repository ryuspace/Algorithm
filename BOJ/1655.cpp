//https://www.acmicpc.net/problem/1655
/*풀이 : 중앙값 측정이랑 비슷한 문제. pq를 이용해서 삽입되는 값을 기준으로 매 순간 중간값을 찾는다.*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
map<int, int> m;
map<int, int>::iterator iter;
int main(void) 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int cnt = 0;//가운데 숫자 기준으로 앞에 몇 개의 숫자가 있는지.
	int a;
	cin >> a;
	m[a]++;
	iter = m.begin();
	cout << a << '\n';
	for (int i = 1; i < n; i++)
	{
		int a;
		cin >> a;
		m[a]++;
		if (a < iter->first)
		{
			cnt++;
		}
		if (cnt >i/2)//숫자가 추가되었더니 중간값의 기준이 넘어버렸다. 무조건 이전 중간값으로 가기.
		{
			iter--;
			cnt -= iter->second;
			cout << iter->first << '\n';
		}
		else if (cnt == i / 2)
		{
			cout << iter->first << '\n';
		}
		else if (cnt < i / 2)//숫자가 추가되었더니 중간값의 기준이 줄어버렸다. 우선 다음 숫자의 갯수만큼 가봤다가 너무 많이 가버리면 돌아간다.
		{
			cnt += iter->second;
			iter++;
			if (cnt > i / 2)
			{
				iter--;
				cnt -= iter->second;
			}
			cout << iter->first << '\n';
		}
	}


	return 0;
}

