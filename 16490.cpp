//https://www.acmicpc.net/problem/16490
/*풀이 원주각과 제 2 코사인 법칙을 잘 이용해보자....
t^2=c^2+a^2-2ac*1/2  ....1)    t^2=a^2+b^2-2ab*1/2  .....2) <ABC 60도 <APC 60도.. 원주각 */
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int a, t;
  cin>>a>>t;
  cout<<a*a-t*t;
	return 0;
}
