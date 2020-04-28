/*풀이 : (같은 점수, 사람의 수)로 묶어 벡터에 담은 뒤 최대 n/2만큼 위치를
체크한다. 금메달은 은,동메달 보다 작기만 하면 되니깐 가장 높은 득점을 한
사람에게만 금메달을 우선 주고, 금메달 숫자를 간신히 넘을 때까지 은메달,
그 이후로 모두 동메달로 주고 이 경우가 되지 않으면 줄 수 없는 케이스이고 
되면 메달의 숫자를 출력하면 된다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int arr[400001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		vector<pii> v;
		int n;
		cin >> n;
		int before = 0;
		int cnt = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		before = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (before == arr[i])
			{
				cnt++;
			}
			else
			{
				v.push_back({ before,cnt });
				cnt = 1;
				before = arr[i];
			}
		}
		v.push_back({ before,cnt });
		int give = 0;
		int idx2 = v.size()-1;
		for (int i = 0; i < v.size(); i++)
		{
			if (give + v[i].second > n / 2)
			{
				idx2 = i;
				break;
			}
			else
			{
				give += v[i].second;
			}

		}
		bool flag = false;
		if (idx2 <= 2)
		{
			cout << "0 0 0" << '\n';
			flag = true;
		}
		if (!flag)
		{
			int g = v[0].second;
			int s = 0;
			int d = 0;
			int idx = 0;
			for (int i = 1; i < idx2; i++)
			{
				s += v[i].second;
				idx = i;
				if (g < s)
				{
					break;
				}

			}
			for (int i = idx + 1; i < idx2; i++)
			{
				d += v[i].second;
			}
			if (g < s && g < d)
			{
				cout << g << " " << s << " " << d << '\n';
			}
			else
			{
				cout << "0 0 0" << '\n';
			}
		}
		
	}
	return 0;
}
