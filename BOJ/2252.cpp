//https://www.acmicpc.net/problem/2252
/*풀이 : 위상정렬을 쓰라고 했지만 나는 쓰지 않았다 ㅎㅎ
A와 B를 비교할 때 A가 더 크면 그동안 A 앞에 있던 학생들의 수 + 1을 B에게 준다.
그러면 랭킹이 정해진다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int arr[320001];
vector<pii> v;
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[b]+=arr[a];
		arr[b]++;
	}
	for (int i = 1; i <= n; i++)
	{
		v.push_back({ arr[i],i });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << " ";
	}
	
	return 0;
}
