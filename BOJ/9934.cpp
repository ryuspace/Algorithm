//https://www.acmicpc.net/problem/9934
/*풀이 : 
수가 중위 순회로 들어가니깐 첫 중간 값은 루트 노드다.
이를 계속 절반으로 잘라 그 절반의 중간이 또한 서브트리의 루트 노드이다. 이런식으로
깊이에 맞는 노드를 넣어준다.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int k;
vector <int> tree[11];
int arr[1024];
void insert(int start,int end,int dep)
{
	int idx = 1;
	int mid = (start + end) / 2;
	tree[dep].push_back(arr[mid]);
	if (start == end)
		return;
	insert(start, mid - 1, dep + 1);
	insert(mid + 1, end, dep + 1);
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	for (int i = 1; i <= pow(2, k) - 1; i++)
	{
		cin >> arr[i];
	}
	insert(1, pow(2, k) - 1, 1);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < tree[i].size(); j++)
		{
			cout << tree[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;

}
