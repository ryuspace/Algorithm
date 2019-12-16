#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector <int> v;
bool visit[10001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin >> t;
	int real_t = t;
	for(int i=0;i<t;i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	if (t==2 && v[0] == 1 && v[1] == 1)
	{
		cout << 1 << " " << 1;
		exit(0);
	}
	sort(v.begin(), v.end());
	int start = v[v.size() - 1];
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (start%v[i] == 0)
		{
			if (visit[v[i]] == false)
			{
				visit[v[i]] = true;
				v[i] = 0;
			}
		}
	}

	for (int i = v.size() - 2; i >= 0; i--)
	{
		if (v[i] != 0)
		{
			cout << start << " " << v[i];
			exit(0);
		}
	}

	return 0;
}
