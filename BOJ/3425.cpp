//https://www.acmicpc.net/problem/3425
/*풀이 : 시키는 대로 하면 되는 구현 문제다. 하지만 잠깐 방심하면 조건 하나 정도 삐끗하기 아주 좋은 문제*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


string go(long long int a, vector<string> myung)
{
	vector<string> ans;
	stack<long long int> s;
	s.push(a);
	for (int i = 0; i < myung.size(); i++)
	{

		if (myung[i][0] >= 'A' && myung[i][0] <= 'Z')
		{
			if (myung[i] == "POP")
			{
				if (s.empty())
				{
					return "ERROR";
				}
				else
				{
					s.pop();
				}
			}
			else if (myung[i] == "INV")
			{
				if (s.empty())
				{
					return "ERROR";
				}
				else
				{
					long long int front = s.top();
					s.pop();
					s.push(front * -1);
					if (abs(s.top()) > 1000000000)
					{
						return "ERROR";
					}
				}
			}
			else if (myung[i] == "DUP")
			{
				if (s.empty())
				{
					return "ERROR";
				}
				else
				{
					s.push(s.top());
					if (abs(s.top()) > 1000000000)
					{
						return "ERROR";
					}
				}
			}
			else if (myung[i] == "SWP")
			{
				if (s.size() < 2)
				{
					return "ERROR";
				}
				else
				{
					long long int first = s.top();
					s.pop();
					long long int second = s.top();
					s.pop();
					s.push(first);
					if (abs(s.top()) > 1000000000)
					{
						return "ERROR";
					}
					s.push(second);
					if (abs(s.top()) > 1000000000)
					{
						return "ERROR";
					}

				}
			}
			else if (myung[i] == "ADD")
			{
				if (s.size() < 2)
				{
					return "ERROR";
				}
				else
				{
					long long int first = s.top();
					s.pop();
					long long int second = s.top();
					s.pop();
					s.push(first+second);
					if (abs(s.top()) > 1000000000)
					{
						return "ERROR";
					}
				}
			}
			else if (myung[i] == "SUB")
			{
				if (s.size() < 2)
				{
					return "ERROR";
				}
				else
				{
					long long int first = s.top();
					s.pop();
					long long int second = s.top();
					s.pop();
					s.push(second-first);
					if (abs(s.top()) > 1000000000)
					{
						return "ERROR";
					}
				}
			}
			else if (myung[i] == "MUL")
			{
				if (s.size() < 2)
				{
					return "ERROR";
				}
				else
				{
					long long int first = s.top();
					s.pop();
					long long int second = s.top();
					s.pop();
					s.push(first * second);
					if (abs(s.top()) > 1000000000)
					{
						return "ERROR";
					}
				}
			}
			else if (myung[i] == "DIV")
			{
				if (s.size() < 2)
				{
					return "ERROR";
				}
				else
				{
					long long int first = s.top();
					s.pop();
					long long int second = s.top();
					s.pop();
					if (first == 0)
					{
						return "ERROR";

					}

					if ((first>0 && second<0) || (first<0 && second>0))
					{
						s.push((abs(second) / abs(first))*(-1));
						if (abs(s.top()) > 1000000000)
						{
							return "ERROR";
						}
					}
					else
					{
						s.push(abs(second) / abs(first));
						if (abs(s.top()) > 1000000000)
						{
							return "ERROR";
						}
					}
				}
			}
			else if (myung[i] == "MOD")
			{
				if (s.size() < 2)
				{
					return "ERROR";
				}
				else
				{
					long long int first = s.top();
					s.pop();
					long long int second = s.top();
					s.pop();

					if (first == 0)
					{
						return "ERROR";

					}

					if (second<0)
					{

						s.push((abs(second) % abs(first)) * (-1));
						if (abs(s.top()) > 1000000000)
						{
							return "ERROR";
						}
					}
					else
					{
						s.push(abs(second) % abs(first));
						if (abs(s.top()) > 1000000000)
						{
							return "ERROR";
						}
					}
				}
			}

		}
		else
		{
			s.push(stoi(myung[i]));
			if (abs(s.top()) > 1000000000)
			{
				return "ERROR";
			}
		}
	}
	if (s.size() == 1)
	{
		return to_string(s.top());
	}
	else
	{
		return "ERROR";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string prom;
	cin >> prom;
	while (prom != "QUIT")
	{

		vector<string> myung;
		while (prom != "END")
		{
			if (prom == "NUM")
			{
				cin >> prom;
			}
			myung.push_back(prom);
			cin >> prom;
		}
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			long long int a;
			cin >> a;
			cout << go(a, myung) << '\n';;
		}
		cout << '\n';
		cin >> prom;
	}
	return 0;
}
