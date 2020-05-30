//https://www.acmicpc.net/problem/2931
/*풀이 : 가스관을 기준으로 반드시 이어져야 하는 곳에 .이 있는지 체크했다. 있으면 그 곳이
문제점이므로 문제점을 기준으로 이어져야하는 곳을 체크해 가스관을 찾는다. 하지만 이러면
반례가 생긴다.

//M.C 처럼 가스관이 없는 경우가 생긴다.. 그래서 가스관이 없으면 출발점과 도착점을 기준으로
반드시 연결되어야 하는 곳을 체크해 가스관을 찾는다.//
*수정 : 또, 모스크바와 자그레브가 하나의 블록과 인접해 있는 입력만 주어진다. 이라는 조건에 따라
M과 C가 파이프로 직빵으로 연결되는 경우는 없다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int r, c;
char arr[26][26];
bool visit[4][26][26];
pii wrong = { -1,-1 };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == '|')
			{
				visit[0][i][j] = true;
				if (arr[i + dx[0]][j + dy[0]] == '.')
					wrong = { i + dx[0],j + dy[0] };
				visit[2][i][j] = true;
				if (arr[i + dx[2]][j + dy[2]] == '.')
					wrong = { i + dx[2],j + dy[2] };
			}
			else if (arr[i][j] == '-')
			{
				visit[1][i][j] = true;
				if (arr[i + dx[1]][j + dy[1]] == '.')
					wrong = { i + dx[1],j + dy[1] };
				visit[3][i][j] = true;
				if (arr[i + dx[3]][j + dy[3]] == '.')
					wrong = { i + dx[3],j + dy[3] };
			}
			else if (arr[i][j] == '+')
			{
				visit[0][i][j] = true;
				if (arr[i + dx[0]][j + dy[0]] == '.')
					wrong = { i + dx[0],j + dy[0] };
				visit[2][i][j] = true;
				if (arr[i + dx[2]][j + dy[2]] == '.')
					wrong = { i + dx[2],j + dy[2] };
				visit[1][i][j] = true;
				if (arr[i + dx[1]][j + dy[1]] == '.')
					wrong = { i + dx[1],j + dy[1] };
				visit[3][i][j] = true;
				if (arr[i + dx[3]][j + dy[3]] == '.')
					wrong = { i + dx[3],j + dy[3] };
			}
			else if (arr[i][j] == '1')
			{
				visit[2][i][j] = true;
				if (arr[i + dx[2]][j + dy[2]] == '.')
					wrong = { i + dx[2],j + dy[2] };
				visit[3][i][j] = true;
				if (arr[i + dx[3]][j + dy[3]] == '.')
					wrong = { i + dx[3],j + dy[3] };
			}
			else if (arr[i][j] == '2')
			{
				visit[0][i][j] = true;
				if (arr[i + dx[0]][j + dy[0]] == '.')
					wrong = { i + dx[0],j + dy[0] };
				visit[3][i][j] = true;
				if (arr[i + dx[3]][j + dy[3]] == '.')
					wrong = { i + dx[3],j + dy[3] };
			}
			else if (arr[i][j] == '3')
			{
				visit[0][i][j] = true;
				if (arr[i + dx[0]][j + dy[0]] == '.')
					wrong = { i + dx[0],j + dy[0] };
				visit[1][i][j] = true;
				if (arr[i + dx[1]][j + dy[1]] == '.')
					wrong = { i + dx[1],j + dy[1] };
			}
			else if (arr[i][j] == '4')
			{
				visit[2][i][j] = true;
				if (arr[i + dx[2]][j + dy[2]] == '.')
					wrong = { i + dx[2],j + dy[2] };
				visit[1][i][j] = true;
				if (arr[i + dx[1]][j + dy[1]] == '.')
					wrong = { i + dx[1],j + dy[1] };
			}
		}
	}
	vector<int> v;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + wrong.first;
		int ny = dy[i] + wrong.second;
		if (nx >= 0 && nx < r &&
			ny >= 0 && ny < c &&
			(visit[(i + 2) % 4][nx][ny] == true))
			v.push_back(i);
	}
	sort(v.begin(), v.end());
	if (v.size() == 4)
	{
		cout << wrong.first + 1 << " " << wrong.second + 1 << " " << '+';
	}
	else
	{
		if (v[0] == 0 && v[1] == 1)
		{
			cout << wrong.first + 1 << " " << wrong.second + 1 << " " << '3';
		}
		if (v[0] == 0 && v[1] == 2)
		{
			cout << wrong.first + 1 << " " << wrong.second + 1 << " " << '|';
		}
		if (v[0] == 0 && v[1] == 3)
		{
			cout << wrong.first + 1 << " " << wrong.second + 1 << " " << '2';
		}
		if (v[0] == 1 && v[1] == 2)
		{
			cout << wrong.first + 1 << " " << wrong.second + 1 << " " << '4';
		}
		if (v[0] == 1 && v[1] == 3)
		{
			cout << wrong.first + 1 << " " << wrong.second + 1 << " " << '-';
		}
		if (v[0] == 2 && v[1] == 3)
		{
			cout << wrong.first + 1 << " " << wrong.second + 1 << " " << '1';
		}

	}
	return 0;
}
