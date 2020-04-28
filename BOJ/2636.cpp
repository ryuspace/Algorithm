//https://www.acmicpc.net/problem/2636
/*풀이 :
녹는 과정에서 삽질을 좀 했다. 
//바깥 공기 부분을 bfs 돌리고, 그 좌표들을 큐에 넣는다.
그 큐에 담긴 좌표에 상하좌우에 닿는 치즈는 녹는다.//
//이 과정을 치즈가 모두 녹을 때 까지 반복.

*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int arr[101][101];
int neww[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
queue <pii> q;
int zero;
int last;
int cnt = 0;
void bfs()
{
    cnt++;
    int sizz = q.size();
    while (sizz--)
    {
        pii front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + front.first;
            int ny = dy[i] + front.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] == 1)
            {
                arr[nx][ny] = 0;
                neww[nx][ny] = cnt;
                visit[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    }
 
}
bool check()
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                flag = true;
        }
    }
    return flag;
}
void bfs2()
{
    memset(visit, 0, sizeof(visit));
    bool flag = false;
    queue<pii> q;
    q.push({ 0,0 });
    visit[0][0] = true;
    while (!q.empty())
    {
        pii front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) 
        {
            int nx = dx[i] + front.first;
            int ny = dy[i] + front.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] == 0)
            {
                q.push({ nx,ny });
                visit[nx][ny] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fill(&neww[0][0], &neww[n + 1][m + 1], -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (check())
    {
        bfs2();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visit[i][j] && arr[i][j] == 0)
                {
                    q.push({ i,j });
                }
            }
        }
        bfs();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (neww[i][j] == cnt)
            {
                zero++;
            }
        }

    }
    cout << cnt << '\n' << zero;
    

    return 0;
}
