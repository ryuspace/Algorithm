//https://www.acmicpc.net/problem/16437
/*풀이 : 
늑대는 일생에 한번 밖에 양을 먹지 못 한다. 
그러므로 루트 노드를 기점으로 왼쪽 서브트리 오른쪽 서브트리의 합과 합쳐지는 것을 유의해야한다.
즉 후위순회를 이용할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[123457];
int sheep[123457];
long long int find(int num)
{
	long long int sum = 0;
	for (int i = 0; i < v[num].size(); i++)
	{
		sum += find(v[num][i]);
	}
	if (sum + sheep[num] < 0)
		return 0;
	else
		return sum + sheep[num];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		char a;
		int b, c;
		cin >> a >> b >> c;
		v[c].push_back(i);
		if (a == 'S')
			sheep[i] = b;
		else if (a == 'W')
			sheep[i] = -b;
	}
	cout << find(1);
}
