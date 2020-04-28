//https://www.acmicpc.net/problem/15831
/*풀이 : 우선 돌이 들어오면 큐에 돌을 넣어주고 흰 돌이 들어온 갯수와 검은 돌이 들어온 갯수를 각각 센다.
검은 돌이 들어왔으면 만약 검은 돌이 기준치보다 넘으면 큐의 앞에서부터 검은 돌이 나올 때까지 pop 해준다.(흰 돌의 개수는 계속 줄어든다)
그리고 흰 돌이 기준치보다 넘으면 큐의 사이즈와 max를 비교해본다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

queue <char> q;
vector <char> v;

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int maxx = 0;
	int blck = 0;
	int wte = 0;
	int n, b, w;
	cin >> n >> b >> w;
	for (int i = 1; i <= n; i++)
	{
		char a;
		cin >> a;
		q.push(a);
		if (a == 'W')
		{
			wte++;
		}
		else if (a == 'B')
		{
			blck++;
			if (blck > b)
			{
				char front = q.front();
				while (front != 'B')
				{
					wte--;
					q.pop();
					front = q.front();
				}
				q.pop();
				blck--;
			}
		}
		if (wte >= w)
		{
			int siz = q.size();
			maxx = max(maxx, siz);
		}
		
	}
	cout << maxx;
	return 0;
}
