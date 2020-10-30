//https://www.acmicpc.net/problem/20055
/*
풀이 : deque를 이용해 컨베이어 벨트를 돌리고 로봇의 움직임을 0~n-1만큼 시뮬레이션 해주면 된다.
문제 이해를 못 해서 구현이 복잡해졌었다.
*/
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
deque<int> v;
int cnt;
int turn;
bool robot[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
			cnt++;
		v.push_back(num);
	}

	while (true)
	{
		turn++;
		int hi = v.back();
		v.pop_back();
		v.push_front(hi);

		for (int i = n - 1; i >= 0; i--)
		{
			if (robot[i])
			{
				robot[i + 1] = true;
				robot[i] = false;
			}

		}

		robot[n] = false;
		robot[n - 1] = false;
		for (int i = n - 2; i >= 0; i--)
		{

			if (robot[i] == true && robot[i + 1] == false && v[i + 1] >= 1)
			{
				robot[i] = false;
				robot[i + 1] = true;
				v[i + 1]--;
				if (v[i + 1] == 0)
					cnt++;
			}
		}

		if (robot[0] == false && v[0] >= 1)
		{
			robot[0] = true;
			v[0]--;
			if (v[0] == 0)
				cnt++;
		}
		if (cnt >= k)
		{
			cout << turn;
			break;
		}


	}

	return 0;
}
