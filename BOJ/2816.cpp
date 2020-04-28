//https://www.acmicpc.net/problem/2816
/*풀이 : 최적이란 말은 없다.. 그냥 kbs1 찾을 때 까지 내리고 찾으면 첫번째 위치로 올리고
그 다음으로 kbs2 찾을 때 까지 내리고 두번째 위치로 올린다. 단 kbs1이 kbs2보다 아래에 있으면
kbs1이 맨 위로 올라간 후 kbs2의 위치는 기존의 위치보다 하나 내려가 있다.*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[101];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a,b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == "KBS1")
			a = i;
		else if (arr[i] == "KBS2")
			b = i;
	}
	if (a < b)
	{
		for (int i = 0; i < a; i++)
		{
			cout << 1;
		}
		for (int i = 0; i < a; i++)
		{
			cout << 4;
		}
		for (int i = 0; i < b; i++)
		{
			cout << 1;
		}
		for (int i = 0; i < b-1; i++)
		{
			cout << 4;
		}

	}
	else
	{
		for (int i = 0; i < a; i++)
		{
			cout << 1;
		}
		for (int i = 0; i < a; i++)
		{
			cout << 4;
		}
		for (int i = 0; i < b+1; i++)
		{
			cout << 1;
		}
		for (int i = 0; i < b; i++)
		{
			cout << 4;
		}
	}
	return 0;
}
