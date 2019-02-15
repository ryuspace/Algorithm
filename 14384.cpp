//https://www.acmicpc.net/problem/14384
/*풀이 : 뒤에서부터 -가 나오면 앞까지 뒤집는다.*/
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
		int cnt = 0;
		string tmp;
		cin >> tmp;
		for (int i = tmp.length() - 1; i >= 0; i--)
		{
			if (tmp[i] == '-')
			{
				for (int j = i; j >= 0; j--)
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
				cnt++;
			}
		}
		cout << "Case #"<<i+1<<": " <<cnt << '\n';
	}
	return 0;
}
