#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	string name;
	string name2;
	cin >> n >> name;
	name2 = name;
	int cnt = 0;
	for (int i = 1; i <= name.length()-1; i++)
	{
		if (name[i] == name[i - 1])
		{
			if (name[i - 1] == 'R')
			{
				if (name[i + 1] == 'R')
				{
					name[i] = 'G';
				}
				else if (name[i + 1] == 'G')
				{
					name[i] = 'B';
				}
				else
				{
					name[i] = 'G';
				}
			}
			else if (name[i - 1] == 'G')
			{
				if (name[i + 1] == 'R')
				{
					name[i] = 'B';
				}
				else if (name[i + 1] == 'G')
				{
					name[i] = 'R';
				}
				else
				{
					name[i] = 'R';
				}
			}
			else
			{
				if (name[i + 1] == 'R')
				{
					name[i] = 'G';
				}
				else if (name[i + 1] == 'G')
				{
					name[i] = 'R';
				}
				else
				{
					name[i] = 'R';
				}
			}
		}
	}
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] != name2[i])
		{
			cnt++;
		}
	}
	cout << cnt << '\n';
	cout<< name;
	return 0;
}
