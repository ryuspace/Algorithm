//https://www.acmicpc.net/problem/9466
#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;

int visit[100001];
int t;
int student, num;
int arr[100001];//학생들이 선택한 학생의 정보를 담은 배열
int cycle[100001];//cycle인지 확인하는 배열
int cnt = 0;
void dfs(int start)
{
	visit[start] = true;
	if (!visit[arr[start]])//방문 안 했으면 학생이 지목한 학생으로 방문해본다.
	{
		dfs(arr[start]);
	}
	else//이미 방문됐다.
	{
		if (!cycle[arr[start]])//이미 방문됐는데 싸이클 배열이 0이면 아직 싸이클을 이루지 않은 것. 싸이클 배열이 1이면 이미 싸이클을 이룬 상태므로 낄 자리가 없다.
		{
			cnt++;
			for (int i = arr[start]; i != start; i = arr[i])
			{
				cnt++;
			}
		}
	}
	cycle[start] = 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> student;
		memset(visit, 0, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		memset(cycle, 0, sizeof(cycle));
		cnt = 0;
		for (int i = 1; i <= student; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= student; i++)
		{
			if (!visit[i])
			{
				dfs(i);
			}
		}
		cout << student-cnt << '\n';
	}

	return 0;
}
