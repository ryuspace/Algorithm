/*풀이 :
사람들을 무게순으로 정렬하고 남은 사람중 가장 무거운 사람과 가장 가벼운 사람을 태워본다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool already[50001];
int solution(vector<int> people, int limit) {
	/*int answer = 0;
	return answer;*/
	int cnt = 0;
	int cuty = 0;
	sort(people.begin(), people.end());
	for (int i = people.size() - 1; i >= 0; i--)
	{
		if (already[i])
			break;
		if (people[i] + people[cuty] <= limit)
		{
			already[cuty] = true;
			cuty++;
		}
		already[i] = true;
		cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
