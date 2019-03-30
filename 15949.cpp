//https://www.acmicpc.net/problem/15949
/*풀이 : 시키는 대로 하자.. 범위 밖으로 벗어나는 걸 막기 위해 map의 둘레를 'X'로 쳐준다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };//우하좌상
int n, m;
int arr[102][102];
bool visit[102][102];
map<int,char> ma;
int cc = 0;//0 : 왼쪽 1 : 오른쪽
int dp = 0;
void bfs(pii start,int num)
{
	queue<pii> q;
	visit[start.first][start.second] = true;
	q.push({ start.first,start.second });
	char color = arr[start.first][start.second];
	arr[start.first][start.second] = num;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		arr[front.first][front.second] = num;
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 1 && nx <= n &&ny >= 1 && ny <= m && 
				!visit[nx][ny] && arr[nx][ny] == color)
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
pii find(int num)
{
	vector<pii> v;
	bool f = false;
	if (dp==0)
	{
		for (int j = m; j >= 1; j--)
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[i][j] == num)
				{
					v.push_back({ i,j });
					f = 1;
				}
			}
			if (f)
				break;
		}
	}
	else if (dp==1)
	{
		for (int i = n; i >= 1; i--)
		{
			for (int j = m; j >= 1; j--)
			{
				if (arr[i][j] == num)
				{
					v.push_back({ i,j });
					f = 1;
				}
			}
			if (f)
				break;
		}
	}
	else if (dp==2)
	{
		for (int j = 1; j <=m; j++)
		{
			for (int i = n; i >= 1; i--)
			{
				if (arr[i][j] == num)
				{
					v.push_back({ i,j });
					f = 1;
				}
			}
			if (f)
				break;
		}
	}
	else if (dp==3)
	{
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j<=m; j++)
			{
				if (arr[i][j] == num)
				{
					v.push_back({ i,j });
					f = 1;
				}
			}
			if (f)
				break;
		}
	}
	pii idx;
	if (cc == 0)
		idx = v[0];
	else
		idx = v[v.size() - 1];
	if (dp == 0)
	{
		return { idx.first,idx.second + 1 };
	}
	else if (dp == 1)
	{
		return { idx.first+1,idx.second  };
	}
	else if (dp == 2)
	{
		return { idx.first,idx.second - 1 };
	}
	else if (dp == 3)
	{
		return { idx.first-1,idx.second};
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	pii begin = { 1,1 };
	cin >> n >> m;

	for (int i = 0; i <= 101; i++)
	{
		for (int j = 0; j <= 101; j++)
		{
			arr[i][j] = 'X';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			arr[i][j+1] = tmp[j];
		}
	}
	//bfs를 돌려 같은 구역인 애들은 고유번호를 매겨주자
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!visit[i][j] && arr[i][j] != 'X')
			{
				ma[num] = arr[i][j];
				bfs({ i,j },num);
				num++;
			}
			if (num == 'X')//X는 색으로 간주 안하니까 고유변호가 X(88)가 되면 다음 숫자로 pass
				num++;
		}
	}
	pii now = { 1,1 };
	vector<char> ans;
	ans.push_back(ma[arr[begin.first][begin.second]]);
	while (true)
	{
		now = find(arr[begin.first][begin.second]);
		int cnt = 0;
		bool is_c = 0;
		bool is_d = 1;
		while (cnt < 7 && arr[now.first][now.second] == 'X')//나머지 7번의 가능한 모든 경우를 해보자
		{
			if (is_c==1)
			{
				is_c = 0;
				dp = (dp + 1) % 4;
			}
			else
			{
				is_c = 1;
				cc = 1 - cc;
			}
			cnt++;
			now = find(arr[begin.first][begin.second]);
		}
		if (cnt == 7)
		{
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i];
			}
			exit(0);
		}
		ans.push_back(ma[arr[now.first][now.second]]);
		begin = now;
	}
	return 0;
}
