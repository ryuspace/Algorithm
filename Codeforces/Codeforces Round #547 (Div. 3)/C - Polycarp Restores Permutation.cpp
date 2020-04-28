#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <long long int> v;
bool visit[200001];
int main()
{
	ios_base::sync_with_stdio(0);

	int minn = 1e9;
	int chogi = 1;
	minn = min(chogi, minn);
	v.push_back(chogi);
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a;
		int num = v[i - 1];
		cin >> a;
		if (num + a > n || num+a<-n)
		{
			cout << -1;
			exit(0);
		}
		v.push_back(num + a);
		minn = min(num + a, minn);
	}
	int start = 1- minn;

	for (int i = 0; i < v.size(); i++)
	{
		visit[v[i] + start] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			cout << -1;
			exit(0);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] + start << " ";
	}

	return 0;
}
