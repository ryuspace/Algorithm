//https://www.acmicpc.net/problem/1525
/*풀이 : 빈 공간을 기준으로 4방향을 탐색해본다. set을 이용하여 이미 방문한
모양이면 더 방문하지 않게 해준다.*/
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int arr[4][4];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

set <string> s;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tmp = "";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
			tmp += to_string(arr[i][j]);
		}
	}
	int time = 0;
	queue<string> q;
	q.push(tmp);
	s.insert(tmp);
	
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			string front = q.front();
			q.pop();
			if (front == "123456780")
			{
				cout << time;
				exit(0);
			}
			int idx = front.find('0');
			int x = idx / 3;
			int y = idx % 3;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
				{
					string cop = front;
					swap(cop[idx], cop[nx * 3 + ny]);
					if (s.count(cop) == 0)
					{
						s.insert(cop);
						q.push(cop);
					}
				}
			}

		}
		time++;
	}
	cout << -1;
	return 0;
}
