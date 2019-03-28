//https://www.acmicpc.net/problem/17028
/*풀이 : 뒤에서 부터 부분정렬된 곳을 찾는다. 정렬되지 않은 부분을 만나면 break
그 정렬된 곳 기준으로 앞에 숫자들을 적절히 보내면 된다.*/
#include <iostream>
using namespace std;

int N;
int A[100000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int ans = N - 1;
	for (int i = N - 2; i >= 0; i--)
	{
		if (A[i] < A[i + 1])
			ans = i;//이 인덱스까지의 숫자들은 다 적당히 뒤로 보내야한다.
		else
			break;
	}
	cout << ans << '\n';
	return 0;
}
