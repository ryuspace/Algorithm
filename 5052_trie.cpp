//https://www.acmicpc.net/problem/5052
/*풀이 : 트라이를 이용해 중복되는 문자열을 찾아냈다. 
트라이 : 문자열에 특화된 자료구조, 원하는 원소를 O(n)만에 찾아낼 수 있다. //n은 문자열 길이
map을 쓰면 검색하는데 기본적으로 log(N)에다가 원소를 찾는데 문자열 길이만큼 시간이 들어서 O(MlgN) 만큼 든다.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int t;
struct Trie
{

	Trie* next[11];
	bool finish;//끝난 표시. 이미 여기서 끝난 이력이 있는데 누가 다시 방문하면 일관성이 없는거다!
	bool nextchild;
	
	Trie()
	{
		fill(next, next + 11, nullptr);
		finish = false;
		nextchild = false;
	}
	~Trie()
	{
		for (int i = 0; i < 11; i++)
		{
			if (next[i])
				delete next[i];
		}
	}
	bool insert(const char* key)
	{
		if (*key == '\0')
		{
			finish = true;
			if (nextchild)
				return 0;
			else
				return 1;
		}

		int nextKey = *key - '0';
		if (next[nextKey] == 0)
			next[nextKey] = new Trie;
		nextchild = true;

		bool get = next[nextKey]->insert(key + 1);
		return !finish && get;
	}

};
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		Trie* hi = new Trie;
		bool bye = true;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char arr[11];
			cin >> arr;
			bye &= hi->insert(arr);

		}
		if (bye)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		delete hi;
	}
	return 0;
}
