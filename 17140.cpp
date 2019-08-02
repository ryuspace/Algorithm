//https://www.acmicpc.net/problem/17140
/*풀이 : cmp 함수 때문에 엄청 틀렸다.. cmp 함수를 더 꼼꼼히 작성하자.
그냥 구현. 인덱스 처리하는 것이 조금 복잡.*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int arr[202][202];
bool cmp(pii& a, pii& b)
{
	if (a.second == b.second)
	{
		if (a.first < b.first)
			return 1;
		else
			return 0;
	}
	else if (a.second < b.second)
	{
		return 1;
	}
	else
		return 0;

}
int col()//행 갯수 체크
{
	int maxx = 0;
	for (int i = 1; i <= 100; i++)
	{

		int cnt = 0;
		for (int j = 1; j <= 100; j++)
		{
			if (arr[i][j] != 0)
			{
				cnt++;
			}
			else
			{
				maxx = max(maxx, cnt);
				break;
			}
		}
	}
	return maxx;
}
int row()//열 갯수 체크
{
	int maxx = 0;
	for (int i = 1; i <= 100; i++)
	{

		int cnt = 0;
		for (int j = 1; j <= 100; j++)
		{
			if (arr[j][i] != 0)
			{
				cnt++;
			}
			else
			{
				maxx = max(maxx, cnt);
				break;
			}
		}
	}
	return maxx;
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ro, co, k;
	cin >> ro >> co >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	for(int n=0;n<=100;n++)
	{
		if (arr[ro][co] == k)
		{
			cout << n;
			exit(0);
		}
		int r= row();
		int c = col();
		//cout << r << " " << c << '\n';
		if (r >= c)//R 연산
		{
			for (int i = 1; i <= r; i++)
			{
				int num[101] = { 0, };
				vector<pii> v;
				for (int j = 1; j <= c; j++)
				{
					num[arr[i][j]]++;
					arr[i][j] = 0;
				}
				for (int j = 1; j <= 100; j++)
				{
					if (num[j] != 0)
					{
						v.push_back({ j,num[j] });
					}
				}
				int idx = 0;
				sort(v.begin(), v.end(), cmp);
				for (int j = 1; j <=100; j+=2)
				{
					arr[i][j] = v[idx].first;
					arr[i][j + 1] = v[idx].second;
					if (idx == v.size() - 1)
						break;
					idx++;

				}

			}
		}
		else//C 연산
		{
			for (int i = 1; i <= c; i++)
			{
				int num[101] = { 0, };
				vector<pii> v;
				for (int j = 1; j <= r; j++)
				{
					num[arr[j][i]]++;
					arr[j][i] = 0;
				}
				for (int j = 1; j <= 100; j++)
				{
					if (num[j] != 0)
					{
						v.push_back({ j,num[j] });
					}
				}
				int idx = 0;
				sort(v.begin(), v.end(), cmp);
				for (int j = 1; j <= 100; j+=2)
				{

					arr[j][i] = v[idx].first;
					arr[j+1][i] = v[idx].second;
					if (idx == v.size() - 1)
						break;
					idx++;
					
				}
			}
		}

	}
	cout << -1;
	return 0;
}
