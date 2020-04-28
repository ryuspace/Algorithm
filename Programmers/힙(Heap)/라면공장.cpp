/*
풀이 : 0일부터 k-1일까지 반복문을 돌려서
매일 재고가 있는 상태인지 체크하고 없으면
받을 수 있는 밀가루 중 가장 큰 무게를 선택한다.
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
#include <functional>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, less<pii> >pq;
queue<pii> q;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	//int answer = 0;
	//return answer;
	for (int i = 0; i < dates.size(); i++)
	{
		q.push({ supplies[i],dates[i] });
	}
	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		if (q.front().second == i)
		{
			pq.push(q.front());
			q.pop();
		}
		if (stock == 0)
		{
			pii front = pq.top();
			pq.pop();
			stock += front.first;
			cnt++;

		}
		
		stock--;
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
