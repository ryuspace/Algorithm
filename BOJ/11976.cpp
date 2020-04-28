//https://www.acmicpc.net/problem/11976
/*풀이 : 플래티넘부터 세야한다. 등록 후 플래티넘 수 - 기존에 플래티넘을 신청한 사람은 플래티넘으로 승급한 사람이다.
등록 후 플래티넘 수 - 기존에 플래티넘을 신청한 사람 +등록 후 골드 수 - 기존에 골드 등록 수는 골드로 승급한 사람이다. 플래티넘도 넣어준 이유는 
플래티넘으로 갈라면 골드를 거쳐야하기 때문.. 실버도 마찬가지로 구할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a1, a2, b1, b2, c1, c2, d1, d2;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;

	int slv_cnt = 0;
	int gld_cnt = 0;
	int plt_cnt = 0;

	plt_cnt = d2 - d1;
	gld_cnt = d2 - d1 + c2 - c1;
	slv_cnt = d2 - d1 + c2 - c1 + b2 - b1;
	cout << slv_cnt << '\n' << gld_cnt << '\n' << plt_cnt;
	return 0;
}
