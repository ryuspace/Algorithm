/*풀이 :
010101010123232323 이런식으로 두 가지 숫자가 번갈아서 나오게 하는데.
시작 숫자를 정해놓고 다음 수가 지금 수보다 작은 게 있는지 없으면 큰게 있는지 체크를 해서 수열을 만들어본다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[4], b[4];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (!a[i])
			continue;
		vector<int> v;
		for (int j = 0; j < 4; j++)
		{
			b[j] = a[j];
		}
		int idx = i;
		while (true)
		{
			v.push_back(idx);
			b[idx]--;
			if (idx >= 1 && b[idx - 1] > 0)
				idx--;
			else if (idx <= 2 && b[idx + 1] > 0)
				idx++;
			else
				break;
		}
		if (b[0] + b[1] + b[2] + b[3] == 0)
		{
			cout << "YES" << '\n';
			for (auto& j : v)
				cout << j << " ";
			exit(0);
		}
	}
	cout << "NO";
	return 0;
}
