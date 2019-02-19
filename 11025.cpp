//https://www.acmicpc.net/problem/11025
/*풀이 : 마지막에 살아있는 애를 기준으로 m%i (i=2...n ) (i는 살아있는 애 수) 만큼 더해서 위치를 갱신한다... 
만약 살린 애들보다 인덱스가 뒤에있다면 그 넘은 인덱스 % 살아있는 애 수를 해줘 인덱스를 갱신한다.
모두를 살릴때까지 반복*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	int start = 1;
	int cnt = 1;
	int idx = 1;
	while (cnt < n)
	{
		int time = m % (start+1);
		idx += time;
		if (idx > start + 1)
		{
			idx %= start+1;
		}
		cnt++;
		start++;
	}
	cout << idx;
	return 0;
}
