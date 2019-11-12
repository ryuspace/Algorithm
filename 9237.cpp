//https://www.acmicpc.net/problem/9237
/*풀이 : 분류는 트리지만 수학 계산으로 답을 찾았다.
우선 가장 오래 걸리는 나무부터 심는 것이 가장 효율적이다.
나무가 자라는 시간을 내림차순으로 정렬하고 순서대로 N,N-1,,,1만큼의 시간을 빼준다.
모든 나무가 같이 자라는 시점부터 보기 위해서 이다.
그리고 나서 가장 오래 걸리는 나무를 찾고, 그 나무 + 처음 1일 + 마지막 1일을 더하면 답이 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
bool cmp(const int& a, const int& b)
{
	if (a > b)
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int maxx = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n,cmp);
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i] - n + i;
		if (arr[i] > maxx)
			maxx = arr[i];
	}
	cout << maxx + n+2;
	return 0;
}
