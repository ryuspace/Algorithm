//https://www.acmicpc.net/problem/14789
/*풀이 : 처음부터 탐색하는데 -가 나오면 k개만큼 뒤집어 본다.*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		int cnt = 0;
		string tmp;
		cin >> tmp>>k;
		for (int i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] == '-')
			{
				if (i + k <= tmp.length())
				{
					for (int j = i; j < i + k; j++)
					{
						if (tmp[j] == '-')
						{
							tmp[j] = '+';
						}
						else
						{
							tmp[j] = '-';
						}
					}
				}
				
				cnt++;
			}

		}
		bool flag = false;
		for (int j = 0; j < tmp.length(); j++)
		{
			if (tmp[j] == '-')
				flag = true;
		}
		if (flag)
		{
			cout << "Case #" << i + 1 << ": " << "IMPOSSIBLE" << '\n';
		}
		else
		{
			cout << "Case #" << i + 1 << ": " << cnt << '\n';
		}
	}
	return 0;
}
