//https://www.acmicpc.net/problem/4195
/*풀이 : 그냥 map은 탐색속도 O(logN) unordered_map은 O(1)이다. 해시테이블을
사용하기 때문 대신 string 길이가 길어지면 그냥 map이 나을 수도 있다.
일반적인 union_find 문제인데 노드가 문자열로 주어진다. 그래서
처음 나온 문자열이면 어떤 값을 준다. 그 값을 기준으로 union_find를 한다.*/
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


int parent[200002];
int num[200002];


int find(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	parent[x] = find(parent[x]);

	return parent[x];
}

int Union(int x, int y)
{
	x = find(x);
	y = find(y);
	//부모를 찾자
	if (x != y)
	{
		parent[x] = y;
		num[y] += num[x];
	}
	//y를 기준으로 합친다.
	return num[y];
}
int main()
{
	int t, f;
	
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{

		unordered_map<string, int> m;
		char a[22];
		char b[22];
		scanf("%d", &f);
		for (int j = 0; j < 2 * f; j++)
		{
			parent[j] = j;
			num[j] = 1;
			//초기 상태 : 부모는 자기 자신, 연결되어 있지 않으므로 친구 숫자 1
		}
		int cnt = 0;
		for (int j = 0; j < f; j++)
		{
			scanf("%s %s", &a, &b);
			//해싱단계
			if (m.count(a) == 0)
			{
				m[a] = cnt++;
			}
			if (m.count(b) == 0)
			{
				m[b] = cnt++;
			}
			printf("%d\n", Union(m[a], m[b]));
		}

	}
	return 0;
}
