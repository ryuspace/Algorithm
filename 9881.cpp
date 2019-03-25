//https://www.acmicpc.net/problem/9881
/*풀이 : 언덕은 0~83...83~100 사이의 범위에 무조건 있어야 한다.
가능한 범위를 하나씩 체크해 보면서 설정한 범위 밖에 있는 언덕은 잘라버리고
비용을 더한다. 모든 가능한 범위에 대해 그 최소비용을 구한다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	long long int sum = 0;
	long long int minn = 1e9;
	for (int i = 0; i <= 83; i++)//i~i+17 범위 이외인 것들은 잘라버리자
	{
		long long int cost = 0;
		for (int j = 0; j < n; j++)
		{
			int x = 0;
			if (v[j] < i)
			{
				x = i - v[j];
			}
			else if (v[j] > i + 17)
			{
				x = v[j] - (i + 17);
			}
			cost += x * x;
		}
		minn = min(minn, cost);
	}
	cout << minn;
	return 0;
}
