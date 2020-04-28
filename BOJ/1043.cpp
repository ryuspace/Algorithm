//https://www.acmicpc.net/problem/1043
/*풀이 :
진실을 알고 있는 사람과 같이 있는 사람들은 결국 진실을 알게됨.
이 구조가 바이러스 처럼 퍼져나간다.
만약 이 파티에 진실을 알고있는 사람이 있다? 그럼 그 파티는 망한거다.
만약 망한 파티에 진실을 모르고 있는 사람이 있으면 또 퍼질 가능성이 있다.
이 두가지를 염두해 둬서 진실을 아는 사람들을 찾는다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, m, truth;
vector<int> v[51];
bool visit[51];
vector<int> my_party;
bool people[51];


void find_wrong_party()
{
	bool check[51] = { 0, };
	bool flag = false;
	while (flag == false)
	{
		flag = true;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (people[v[i][j]])//여기 진실을 아는 사람이 있는데..
				{
					if (!check[i])//파티가 살아있다..? 주겨야해.. 앞에 애들 체크 안됐을 수도 있으니깐 또 돌아보자..
					{
						flag = false;
						check[i] = true;
					}
					
				}
				if (check[i] && !people[v[i][j]])//망한 파틴데 진실을 몰랐어..? 이제 알게 되니깐 또 돌아보자..
				{
					people[v[i][j]] = true;
					flag = false;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (!check[i])
		{
			cnt++;
		}
	}
	cout << cnt;
}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> truth;
	for (int i = 0; i < truth; i++)
	{
		int a;
		cin >> a;
		people[a] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b;
			cin >> b;
			v[i].push_back(b);
		}
	}

	find_wrong_party();
	return 0;
}
