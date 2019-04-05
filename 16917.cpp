//https://www.acmicpc.net/problem/16917
/*풀이 : 처음에는 반반치킨 0마리인 상태로
후라이드,양념의 갯수를 채운다. 그리고 반반치킨을 2개 단위로 늘리고
순수 후라이드,양념의 갯수를 하나씩 빼고 계속 최솟값을 찾는다.
어쩌면 최소 마리를 사지 않아도 반반치킨으로만 채우는게 더 이득일 수 도 있으므로
순수 후라이드,양념의 갯수가 모두 0이 될 때까지 찾아본다.*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
int a, b, c, x, y;
vector<pii> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> a >> b >> c >> x >> y;
	//처음에는 반반 0마리로 시작하자
	int ban_c = 0;
	int gap = a * x + b * y;
	while (!(x==0 &&y==0))
	{
		if(x>0)
			x--;
		if(y>0)
			y--;
		ban_c++;
		ban_c++;
		int gaeng = a * x + b * y + c*ban_c;
		gap = min(gap, gaeng);
	}
	cout << gap;
	return 0;
}
