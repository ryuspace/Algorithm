//https://www.acmicpc.net/problem/1062
/*풀이 :
단어를 k개를 선택한 모든 경우의 수를 해도 21C10이므로 AC가 난다.
하지만 비트마스킹 방법으로 풀면 단어를 고르고 나서 읽을 수 있는지 판별할 때 시간이 훨씬 덜 걸린다 (n^2 -> n)
입력받은 단어를 비트마스크 방법을 통해 어떤 변수에 저장해 놓고
dfs를 이용해 알파벳을 골라 비트마스킹 방법을 이용해 변수에 저장해 놓고 이 둘을 비교한다.
&연산을 했을 때 원래 단어가 나오면 그 단어는 읽을 수 있다고 판단할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, k;
int arr[51];
int maxx = 0;
int learn = 0;
void play(int learn)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (((arr[i] & learn) == arr[i]))
		{
			cnt++;
		}
	}
	maxx = max(cnt, maxx);
}
void dfs(int idx, int cnt, int learn)
{
	if (maxx == n)
		return;
	if (cnt == k)
	{
		play(learn);
		return;
	}
	if (idx >= 26)
		return;

	if (idx == ('n' - 'a') || idx == ('t' - 'a') || idx == ('i' - 'a')
		|| idx == ('c' - 'a'))//모든 단어는 a,n,t,i,c,가 들어가므로 이미 배워놓은 상태 pass.
	{
		dfs(idx + 1, cnt, learn);
	}
	else
	{
		dfs(idx + 1, cnt + 1, (learn | (1 << idx)));
		dfs(idx + 1, cnt, learn);
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			arr[i] |= ((1 << (tmp[j] - 'a')));
		}
	}
	if (k < 5)
	{
		cout << 0;
		exit(0);
	}
	k -= 5;
	learn |= (1 << ('n' - 'a'));
	learn |= (1 << ('t' - 'a'));
	learn |= (1 << ('i' - 'a'));
	learn |= (1 << ('c' - 'a'));
	learn |= (1 << ('a' - 'a'));
	dfs(1, 0, learn);
	cout << maxx;
	return 0;
}
