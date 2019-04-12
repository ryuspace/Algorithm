/*5658번 보물상자 비밀번호
풀이 : 어렵지는 않지만 16진수를 10진수로 변환하는 방법과 vector에서 중복 제거하는
방법을 알아야 한다. unique를 처음 이용해 봄
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int t, n, k;

long long int change(string tmp)
{
	int ans = 0;
	int fac = 1;
	for (int i = tmp.length()-1; i >= 0; i--)
	{
		if (tmp[i] >= 65)
		{
			ans += fac * (tmp[i] - 55);
		}
		else
		{
			ans += fac * (tmp[i] - 48);
		}
		fac *= 16;
	}
	return ans;
}
string rotate(string tmp)
{
	string won = tmp;
	for (int i = 0; i < tmp.length(); i++)
	{
		tmp[(i + 1) % tmp.length()] = won[i];
	}
	return tmp;

}
int main()
{
	freopen("t.txt", "r", stdin);
	string tmp;
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int y = 1; y <= t; y++)
	{
		vector<long long int> v;
		cin >> n >> k;
		cin >> tmp;
		for (int j = 0; j < n/4; j++)
		{
			string jemul = "";
			int summ = 0;
			for (int i = 0; i < n; i++)
			{
				jemul += tmp[i];
				if ((i + 1) % (n/4) == 0)
				{
					v.push_back(change(jemul));
					jemul = "";

				}
			}
			tmp=rotate(tmp);
			
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());//벡터에서 중복 제거!
		cout << "#" << y << " " << v[v.size()-k] << '\n';
	}
	return 0;
}
