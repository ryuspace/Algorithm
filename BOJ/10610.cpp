//https://www.acmicpc.net/problem/10610
/*풀이 : 30의 배수는 0이 한번 이상 나와야 하고 자릿수를 다 더하면 3의 배수여야 한다.
그 중 가장 큰 수는 나온 숫자 들을 큰 숫자 부터 나열하면 된다. */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string n;
	int sum = 0;
	bool zero = false;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n.length(); i++)
	{
		v.push_back(n[i] - '0');
		if (n[i]-'0' == 0)
			zero = true;
		else
			sum += n[i] - '0';
	}
	if (zero == true && sum % 3 == 0)
	{
		sort(v.begin(), v.end(),greater<int>());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
	}
	else
		cout << -1;
	return 0;
}
