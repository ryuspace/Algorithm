//https://www.acmicpc.net/problem/12886
/*풀이 : 모든 경우를 탐색해본다. 이미 나왔던 숫자들인 경우를 체크해 주기 위해
set을 사용한다.*/
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

set <string> s;
void dfs(int a, int b, int c)
{
	string tmp = "";
	int arr[3] = { a,b,c };
	sort(arr, arr + 3);
	tmp += to_string(a) + to_string(b) + to_string(c);
	if (s.count(tmp))
		return;
	s.insert(tmp);
	if (arr[0] == arr[1] && arr[1] == arr[2])
	{
		cout << 1;
		exit(0);
	}
	if (arr[0] > arr[1])
	{
		dfs(arr[0] - arr[1], arr[1] * 2, arr[2]);
	}
	if (arr[1] > arr[0])
	{
		dfs(arr[0] * 2, arr[1] - arr[0], arr[2]);
	}
	if (arr[0] > arr[2])
	{
		dfs(arr[0] - arr[2], arr[1], arr[2] * 2);
	}
	if (arr[2] > arr[0])
	{
		dfs(arr[0] * 2, arr[1], arr[2] - arr[0]);
	}
	if (arr[1] > arr[2])
	{
		dfs(arr[0], arr[1] - arr[2], arr[2] * 2);
	}
	if (arr[2] > arr[1])
	{
		dfs(arr[0], arr[1] * 2, arr[2] - arr[1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	dfs(a, b, c);
	cout << 0;
	return 0;

}

