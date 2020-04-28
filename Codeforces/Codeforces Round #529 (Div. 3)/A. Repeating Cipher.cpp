#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int arr[11];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	string name;
	cin >> n;
	cin >> name;
	for (int i = 1; i <= 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 1; i <= 9; i++)
	{
		arr[i+1]+=arr[i];
	}
	int cnt = 1;
	while (arr[cnt] != n)
	{
		cout << name[arr[cnt]-1];
		cnt++;
	}
	cout << name[n-1];
	return 0;
}
