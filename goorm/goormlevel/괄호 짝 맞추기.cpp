//https://level.goorm.io/exam/43119/%EA%B4%84%ED%98%B8-%EC%A7%9D-%EB%A7%9E%EC%B6%94%EA%B8%B0/quiz/1
/*풀이 :
stack을 이용하여 왼쪽 괄호면 push 해주고 오른쪽 괄호면 스택의 가장 위가 같은 쌍인지 체크한다.
은근 고려할 경우가 꽤 있는 문제
어떤 경우가 false가 될지 잘 생각해보자
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '[' || tmp[i] == '{' || tmp[i] == '(')
		{
			s.push(tmp[i]);
		}
		else
		{
			if (s.empty())
			{
				cout << "False";
				return 0;
			}
			else if (tmp[i] == ']' && s.top() == '[')
			{
				s.pop();
			}
			else if (tmp[i] == '}' && s.top() == '{')
			{
				s.pop();
			}
			else if (tmp[i] == ')' && s.top() == '(')
			{
				s.pop();
			}
			else
			{
				cout << "False";
				return 0;
			}

		}
	}
	if (!s.empty())
	{
		cout << "False";
		return 0;
	}
	cout << "True";
	return 0;
}
