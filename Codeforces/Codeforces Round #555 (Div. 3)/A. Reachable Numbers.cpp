//풀이 : n부터 시작해서 f를 적용한 모든 숫자를 set에 추가한다. 나왔던 숫자가 나온 순간 계속 반복되므로 stop 해준다.
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set <int> arr;
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	int cnt = 0;
	cin >> n;
	int num = n;
	while (arr.count(num) == 0)
	{
		arr.insert(num);
		num += 1;
		while (num % 10 == 0)
		{
			num /= 10;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
