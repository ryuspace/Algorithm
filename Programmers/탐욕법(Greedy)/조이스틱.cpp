/*
풀이 : 수학적으로 얼마만큼 갔는지 계산하는게 너무 힘들었다.
어떤 지점에서 가능한 모든 지점에서 반대편으로 가봐서 최소 값을 찾았다. 그리디로 하는 방법은 너무 어려워서 완탐으로 구했다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

int solution(string name) {
	/*int answer = 0;
	return answer;*/
	string me = "";
	string real_me = "";
	for (int i = 0; i < name.length(); i++)
	{
		me += 'A';
	}
	real_me = me;
	int cnt = 0;
	int mini = 1e9;
	for (int i = 0; i < name.length(); i++)
	{
		cnt = 0;
		int go = 1;
		int now = 0;
		while (name != me)
		{
			cnt += min(abs(name[now] - 'A'), abs(('Z'-'A') - ((name[now] - 'A'))+1));
			me[now] = name[now];
			if (i == now)
			{
				//now = 'Z' - 'A';
				cnt += now;
				now = name.length();
				go = -1;
			}
			now += go;
			cnt++;
		}
		mini = min(mini, cnt-1);
		me = real_me;
	}

	for (int i = 0; i < name.length(); i++)
	{
		cnt = 0;
		int go = 1;
		int now = 0;
		while (name != me)
		{
			cnt += min(abs(name[now] - 'A'), abs(('Z'-'A') - ((name[now] - 'A'))+1));
			me[now] = name[now];
			now += go;

			cnt++;
		}
		mini = min(mini, cnt-1);
		me = real_me;
	}
	if (mini == -1)
	{
		return 0;
	}
	return mini;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << solution("AB");
	//cout << solution("FRANCE", "french");
	return 0;
}
