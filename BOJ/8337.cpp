//https://www.acmicpc.net/problem/8337
/*풀이 : 겹치는 사각형은 제외한다 가정하면 
가로길이가 1인 사각형은 총 n개를 만들 수 있다..
가로길이가 2인 사각형은 총 n/2-1개를 만들 수 있다..
가로길이가 3인 사각형은 총 n/3-2개를 만들 수 있다..
...
가로가 k인 사각형은 총 n/k-(k-1)개를 만들 수 있다..
그리고 가로가 k인 사각형은 k^2이  n보다 작은 경우에만 만들 수 있다..
*/
#include <iostream>
#include <math.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll n, sum = 0;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++)
		sum += ((n / i) - (i - 1));
	cout << sum;
	return 0;
}
