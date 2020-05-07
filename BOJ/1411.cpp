//https://www.acmicpc.net/problem/1411
/*풀이 : 문제가 조금 모호했다.
두 알파벳 배열을 비교하는데
다르면 각자의 알파벳을 대체했다는 표시를 한다.
쭉 탐색하다가
모순이 생기면(대체할 단어가 각자를 가리켜야 하는데 그게 아님) 비슷한 단어가 아니다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n;
string arr[101];
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			char pyosi[2][28] = { 0, };
			bool flag = false;
			if (arr[i].size() != arr[j].size())
			{
				continue;
			}
			for (int r = 0; r < arr[i].length(); r++)
			{
				if (!pyosi[0][arr[i][r] - 'a'] && !pyosi[1][arr[j][r] - 'a'])
				{
					pyosi[0][arr[i][r] - 'a'] = (arr[j][r]);
					pyosi[1][arr[j][r] - 'a'] = (arr[i][r]);
		
				}
				else if((pyosi[0][arr[i][r] - 'a'] != (arr[j][r])) || (pyosi[1][arr[j][r] - 'a'] != (arr[i][r])))
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cnt++;
			}


		}
	}
	cout << cnt;
	return 0;
}
