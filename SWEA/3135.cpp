/*

3135번 홍준이의 사전놀이

풀이 : 백준의 전화번호 목록과 유사한 문제. Trie를 이용해서 현재 위치의 알파벳 위치인 트라이에 도착했으면 
카운트를 올려준다.

*/

#include <malloc.h>
#include <cstdio>

struct Trie
{
	Trie* next[27];
	int cnt;
};
Trie* root;
extern void init(void) {

	root = new Trie;
	for (int i = 0; i < 26; i++)
	{
		root->next[i] = 0;
	}
	root->cnt = 0;
}
extern void insert(int buffer_size, char* buf) {

	Trie* now = root;
	for (int i = 0; i < buffer_size; i++)
	{
		if (now->next[buf[i] - 'a'] == nullptr)
		{
			now->next[buf[i] - 'a'] = (Trie*)malloc(sizeof(Trie));
			for (int j = 0; j < 26; j++) {
				now->next[buf[i] - 'a']->next[j] = 0;
				now->next[buf[i] - 'a']->cnt = 0;
			}
		}
		now->next[buf[i] - 'a']->cnt++;
		now = now->next[buf[i] - 'a'];
	}
	delete now;
}
extern int query(int buffer_size, char* buf) {

	Trie* now = root;
	for (int i = 0; i < buffer_size; i++)
	{
		if (now->next[buf[i] - 'a']!=nullptr)
		{
			now = now->next[buf[i] - 'a'];
		}
		else
		{
			return 0;
		}
	}
	return now->cnt;
}
int main(void) {
	//freopen("Text.txt", "r", stdin);
	int TestCase;
	for (scanf("%d", &TestCase); TestCase--;) {
		int Query_N;
		scanf("%d", &Query_N);

		init();

		static int tc = 0;
		printf("#%d", ++tc);

		for (int i = 1; i <= Query_N; i++) {
			int type; scanf("%d", &type);

			if (type == 1) {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				insert(buffer_size, buf);
			}
			else {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
		fflush(stdout);
	}
}
