//https://www.acmicpc.net/problem/15761

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[100001];
vector <int> v;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = n - 1; i >= 0; i--)
	{
		if (v.size() <= arr[i])
		{
			v.push_back(arr[i]);
		}
	}
	cout << v.size();
	

	return 0;
}
