/*
풀이 : 시작 단어와 모든 words 벡터의 단어 간의 관계를 파악해서 차이가 1이 나는 것들만 간선을 이어줘서 bfs를 돌린다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[53];
bool visit[53];

bool check(string a, string b)
{
	int cnt = 0;
	for (int i = 0;i < a.length();i++)
	{
		if (a[i] != b[i])
			cnt++;
	}
	if (cnt == 1)
		return true;
	return false;
}

int bfs(vector<string> words,string target)
{
	int cnt = 0;
	queue<int> q;
	q.push(0);
	visit[0] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			int front = q.front();
			if (front!=0 && words[front-1] == target)
			{
				return cnt;
			}
			q.pop();
			for (int i = 0;i < v[front].size();i++)
			{
				if (!visit[v[front][i]])
				{
					visit[v[front][i]] = true;
					q.push(v[front][i]);
				}
			}
		}
		cnt++;
	}

	return 0;
}
int solution(string begin, string target, vector<string> words) {
	/*int answer = 0;
	return answer;*/
	for (int i = 0;i < words.size();i++)
	{
		for (int j = i + 1;j < words.size();j++)
		{
			if (check(words[i], words[j]))
			{
				v[i+1].push_back(j+1);
				v[j+1].push_back(i+1);
			}
		}
	}
	for (int i = 0;i < words.size();i++)
	{
		if (check(begin, words[i]))
		{
			v[0].push_back(i + 1);
			v[i + 1].push_back(0);
		}
	}

	return bfs(words,target);
}
//int main()
//{
//	//freopen("Test.txt", "r", stdin);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cout<<solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
//
//	return 0;
//}
