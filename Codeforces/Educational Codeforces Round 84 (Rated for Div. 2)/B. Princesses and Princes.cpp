/*풀이 :
공주와 왕자는 수가 같으므로 매칭된 공주가 없으면 그 수만큼 매칭된 왕자도 없다.
매칭된 공주를 찾고, 매칭되지 않은 왕자 중 아무나 매칭해준다.

Issue : 기존에 매칭된 커플을 옮길 필요는 없나?
Answer : 우리는 최대 매칭 커플을 구해줘야한다. 매칭되지 않은 공주 중 매칭되지 않은 아무 왕자나 찍으면 무조건 매칭이 된다. (상황을 그래프로 그려보면 알 수 있다.)

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int t;
bool visit[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		memset(visit, 0, sizeof(visit));
		int n;
		int solo = -1;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			bool flag = false;
			int num;
			cin >> num;
			for (int j = 1; j <= num; j++)
			{
				int a;
				cin >> a;
				if (!flag && !visit[a])
				{
					flag = true;
					visit[a] = true;
				}				
			}
			if (!flag)
			{
				solo = i;
			}
		}
		if (solo!=-1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (!visit[i])
				{
					cout << "IMPROVE" << '\n';
					cout << solo << " " << i << '\n';
					break;
				}
			}
		}
		else
		{
			cout << "OPTIMAL" << '\n';
		}
	}
	return 0;
}
