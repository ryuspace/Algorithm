//https://www.acmicpc.net/problem/10166
/*풀이 : 원 둘레를 1이라고 생각 . 어떤 분수가 나왔는데 기약분수로 만들었는데 
분모가 이미 이전에 나왔던 분모면 그 분모는 이전에 무조건 체크가 된 것이다.*/
#include <iostream>
#include <algorithm>

using namespace std;

bool check[2001];

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}
int main() 
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int d1, d2;
	cin >> d1 >> d2;
	for (int i = d1; i <= d2; i++)
	{
		bool check2[2001] = { 0, };
		for (int j = 1; j <= i; j++)
		{
			int num = gcd(i, j);//gcd를 이용해서 최대공약수를 구해 기약분수로 만든다. 만약 둘이 안 나눠 떨어지면 1로 만들게 해서 순수 분모만 비교하게 한다. 분모가 지금 분모보다 작은데 방문이 되어있으면 이미 나왔던 것이다.
			if (!check[i/num])
			{
				check2[i/num] = true;
				cnt++;
				//체크1랑 체크2로 나눈 이유는 현재 turn에서 d1이 10보다 큰데 만약 2/10이랑 4/10이 있다면 체크1이랑 체크2로 나누지 않으면 4/10은 방문되었다고 처리되기 때문이다. 현재 턴에서 방문된 것은 우선은 무시해준다.
			}
		}
		for (int j = 1; j <= i; j++)
		{
			if (check2[j])
				check[j] = true;
		}
	}
	cout << cnt;
	return 0;
}

