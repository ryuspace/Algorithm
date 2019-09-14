//https://programmers.co.kr/learn/courses/30/lessons/49993
/*풀이 : 윈터코딩 2018 문제. 우선 선행스킬순서에 맞게 큐에 넣어주고 스킬트리를 체크해보는데
선행스킬에 있는 스킬이면 큐에 맨 앞쪽에 있어야 한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

set<char> s;
queue<char> q;
int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill.length(); i++)
	{
		q.push(skill[i]);
		s.insert(skill[i]);
	}
	queue<char> qq = q;
	for (int i = 0; i < skill_trees.size(); i++)
	{

		bool flag = false;
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			if (s.count(skill_trees[i][j]) != 0)
			{
				if (q.front() != skill_trees[i][j])
				{
					flag = true;
				}
				if(!q.empty())
					q.pop();
			}
			if (flag)
				break;
		}
		if (!flag)
			answer++;
		q = qq;
	}

	return answer;
}

