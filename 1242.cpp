//https://www.acmicpc.net/problem/1242
/*풀이 : ex) n=5,m=2,k=3이면 1 2 3 4 5 -> 3 4 5 1 -> 5 1 3 -> 3 5 -> 3 이렇게 현재 3의 위치에서
m%n (n은 한번 수행할때마다 하나씩 준다) 만큼 빼줘서 인덱스를 갱신해준다. 만약 인덱스가
음수면 n만큼 더한다.*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int past_k = k;
	int real_n = n;
	int cnt = 0;
	for (int i = 0; i < real_n; i++)
	{
		int time = m % n;
		if (time == 0)
		{
			time = n;
		}
		k -= time;
		n--;
		if (k == 0)
		{
			cout << cnt + 1 << '\n';
			exit(0);
		}
		else if (k < 0)
		{
			k += n + 1;
		}
		else if (n == 0)
		{
			cout << cnt + 1 << '\n';
			exit(0);
		}
		cnt++;
		//cout << time << " " << k << " " << n << '\n';
	}
	return 0;
}
