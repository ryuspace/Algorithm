//https://www.acmicpc.net/problem/11403
/*풀이 : 처음에 단순 bfs로 짰다가 20ms나 걸렸다.
생각해보니 어떤 점에서 어떤 점으로 가기 위해 직접 연결된 경우 아니면 어떤 노드를 거쳐야한다.
그 다리는 무조건 n중에서 하나겠지. */
#include<iostream>
#include<algorithm>

using namespace std;

int arr[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)//j에서 k로 가고 싶은데 i번 다리가 있는지? 
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (arr[j][i] && arr[i][k])
					arr[j][k] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
	return 0;
}
