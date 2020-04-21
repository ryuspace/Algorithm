//https://www.acmicpc.net/problem/1138
/*풀이 : 가장 키 큰 사람 부터 차례로 줄을 세워본다.
자세한건 주석
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[11];
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		v.insert(v.begin() + arr[i],(i+1));//왼쪽에 arr[i]만큼 있으니깐 arr[i] 위치에 내가 끼어들면 맞는 거겠지 다음 순서는 나보다 키가 작으니깐 어디에 껴도 영향을 끼치지 않는다.
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;


}
