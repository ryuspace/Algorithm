/*풀이 : 
Trie를 이용하여 순서대로, 역순으로 따로 따로 저장한다.
Trie를 단어길이에 맞는 배열로 만들어 단어를 찾을 때 ?가 나오기 전까지 몇개가 있는지 체크한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Trie
{
	Trie* next[27];
	int cnt;
	Trie()
	{
		for (int i = 0; i < 27; i++)
		{
			next[i] = nullptr;
		}
		cnt = 0;
	}
	~Trie()
	{
		for (int i = 0; i < 27; i++)
		{
			if (next[i] != nullptr)
				delete next[i];
		}
	}
	void insert(const char *a)
	{
		if (*a == '\0')
			return;
		if (next[*a-'a'] == nullptr)
		{
			next[*a - 'a'] = new Trie();
		}
		next[*a - 'a']->insert(a + 1);
		next[*a - 'a']->cnt++;
	}
	int find(const char* a)
	{
		if (*a == '?')
		{
			return cnt;
		}
		if (next[*a - 'a'] == nullptr)
		{
			return 0;
		}
		return next[*a - 'a']->find(a + 1);
	}
	
};
Trie* start[10001];
Trie* endd[10001];
vector<int> solution(vector<string> words, vector<string> queries) {

	vector<int> ans(queries.size(), 0);
	for (int i = 0; i < words.size(); i++)
	{
		const char* c = words[i].c_str();
		if (start[words[i].size()] == nullptr)
			start[words[i].size()] = new Trie();
		start[words[i].size()]->insert(c);
		string tmp = words[i];
		reverse(tmp.begin(), tmp.end());
		const char* d = tmp.c_str();
		if (endd[words[i].size()] == nullptr)
			endd[words[i].size()] = new Trie();
		endd[words[i].size()]->insert(d);
	}
	int idx = 0;
	for (int i = 0;i < queries.size(); i++)
	{
		const char* c = queries[i].c_str();
		
		if (queries[i][0] == '?' && queries[i][queries[i].size() - 1] == '?')
		{
			if (start[queries[i].size()] == nullptr)
			{
				ans[i] = 0;
			}
			else
			{
				int cntt = 0;
				for (int j = 0; j < 27; j++)
				{
					if (start[queries[i].size()]->next[j] != nullptr)
					{
						cntt += start[queries[i].size()]->next[j]->cnt;
					}
				}
				ans[i] = cntt;
			}
			
		}
		else if (queries[i][0] != '?')
		{
			if (start[queries[i].size()] == nullptr)
			{
				continue;
			}
			else
			{
				ans[i] = start[queries[i].size()]->find(c);
			}
		}
		else
		{
			if (endd[queries[i].size()] == nullptr)
			{
				continue;
			}
			else
			{
				string tmp = queries[i].c_str();
				reverse(tmp.begin(), tmp.end());
				const char* d = tmp.c_str();
				ans[i] = endd[queries[i].size()]->find(d);
			}
			
		}
	}
	return ans;
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	return 0;
}
