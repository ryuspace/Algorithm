//https://www.acmicpc.net/problem/1525
/*풀이 : 0이 있는 곳을 기준으로 왼쪽 오른쪽 위 아래 위치를 바꾼다.(방문되지 않은 경우에만) 방문처리를 위해 map을 사용한다.*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;
map<string, int> m;
queue<string> q;
string n = "";

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
//왼쪽 오른쪽 위 아래
void bfs()
{
	m[n] = 0;
	q.push(n);
	while (!q.empty())
	{
		string front = q.front();
		q.pop();
		int idx = front.find('0');
		int x = idx / 3;
		int y = idx % 3;
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2)
			{
				string next = front;
				swap(next[x * 3 + y], next[nx * 3 + ny]);

				if (m.count(next)==0)
				{
					m[next] = m[front] + 1;
					q.push(next);
				}
			}
		}

	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int tmp;
	for (int i = 0; i < 9; i++)
	{
		cin >> tmp;

		n += tmp + '0';
	}
	bfs();
	if (m.count("123456780")==0)
	{
		cout << -1;
	}
	else
	{
		cout << m["123456780"];
	}
	return 0;

}
