//https://www.acmicpc.net/problem/15976
/*풀이 :

골드4라고 하기엔 나에겐 너무 어려웠다..

어려웠던 포인트
1. 수열 X와 수열 Y의 길이가 최대 10억이다. 입력으로 0이 아닌 값들을 주어도 그 값들이 중간 중간 있으니깐 결국 다 계산해야한다고 생각했다.
   N,M(수열 각각의 0이 아닌 숫자의 갯수)가 3*10000개여서 이걸로 접근하려고 했지만 두 수열의 인덱스가 제각각이라 실패했다.
2. 점화식 도출
   최소값 ~ 최대값 범위를 손으로 그려가면서 계산을 해봤지만 점화식이 도출되지 않았다(나에겐 너무 어려워ㅠ_ㅠ)

결국 힌트를 봤다.
수열 X와 수열 Y를 (인덱스, 값) 쌍으로 저장한다.
수열 X의 인덱스 기준으로 X의 인덱스+최소 ~ X의 인덱스+최대 이 범위 만큼 Y 값과 곱하는 것이다.
X와 Y를 곱하는데 X값이 우선 0이면 의미가 없으므로 0이 아닌 인덱스를 기준으로 Y와 매칭을 해본다.

하지만 X의 인덱스가 0이고 최소가 -1 최대가 1이라면..!? Y는 -1 ~ 1 인덱스의 값들과 곱해야 한다.
-1의 인덱스는 의미가 없으므로 0 ~ 1 값만 곱해야한다. 반대로 수열의 길이보다 더 큰 인덱스를 곱해야 하면 그 인덱스는 또한 무시당해야 한다.

이것은 배열로 처리하기엔 어렵다. 하지만 lower_bound를 이용하면 현재 인덱스의 이상 값을 구해주기 때문에 무시당하는 인덱스가 자연히 없어진다.
finded 함수를 참고하자.

사실 수열 X와 수열 Y를 매칭하는데 네이브하게 풀면 시간복잡도는 3*10^5 * 3*10^5이므로 시간초과가 날 것이 뻔하다.
점화식을 도출해보면 Y는 연속적인 값을 가지므로 미리 부분합을 구해 Y를 계산하는 시간복잡도는 O(1)로 바꿔준다.

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector <pii> x;
vector <pii> y;
vector<long long int> hap;
long long int sum;

long long int finded(int s,int e)
{
	int hi = lower_bound(y.begin(), y.end(),  make_pair(e+1,0)) - y.begin();
	int bye = lower_bound(y.begin(), y.end(), make_pair(s,0)) - y.begin();
	//s~e까지의 부분합을 구하려면 e+1~s까지 빼주면 된다. 이에 맞는 y의 인덱스를 찾아보자.
	return hap[hi] - hap[bye];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		x.push_back(make_pair(a,b));
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		y.push_back(make_pair(a,b));
	}
	hap.push_back(0);
	for (int i = 0; i < m; i++)
	{
		hap.push_back(y[i].second + hap.back());
	}

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++)
	{
		sum += x[i].second* (finded(x[i].first + a, x[i].first + b));
	}
	cout << sum;
	return 0;
}
