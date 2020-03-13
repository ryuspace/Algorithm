/*
풀이 : now일(밀가루를 며칠까지 버틸 수 있는지)
이전까지 수급 받을 수 있는 날짜 중 가장 많이 밀가루를 받을 수 있는 날짜를 선택한다. 
k일 이상 버틸 수 있으면 break 한다.
k일에는 받을 필요 없는거 주의.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int, int> pii;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) 
{
	priority_queue<pii, vector<pii>, less<pii> >pq;
	int now = 0,idx=0,cnt=0;
	now += stock;
	while (true)
	{
		//cout << dates[idx] << " " << now << '\n';
		while (idx < dates.size() && dates[idx] <= now)
		{
			pq.push({ supplies[idx],dates[idx] });
			idx++;
		}
		if (!pq.empty() && now < k)
		{
			now += pq.top().first;
			pq.pop();
			cnt++;
		}
		else
		{
			break;
		}
	}
	return cnt;

}

//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//	cout<<solution(4, { 1,2,3,4}, { 1,1,1,1 }, 6);
//	return 0;
//}
