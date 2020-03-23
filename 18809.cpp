//https://www.acmicpc.net/problem/18809
/*풀이 :
우선 dfs를 한번만 돌려도 되는 것이 포인트다
배양액을 뿌릴 수 있는 땅을 dfs로 고른 동시에 미리 받은 배양액을 순차적으로 넣는다. 이 자체가 모든 경우를 탐색하는 것이다.. 포인트!
bfs를 구현하는 방법은 내 머리론 힘들어서 배워왔다. 이걸 익혀보자.


*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct point
{
    int x, y, color;
};
typedef pair<int, int> pii;
int n, m, r, g;
int arr[51][51];
int idx = 0;
vector<pii> v;
vector<pii> noye;
vector<point> noye2;
int visit_v[11];
bool visit_d[11];
bool red[6];
int maxx = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
pair<int,int> tmp[51][51];
bool visit_b[51][51];
int drug[11];
void play()
{
    memset(tmp, 0, sizeof(tmp));
    queue<pair<int,int> > q;

  /*  cout << noye2.size() << '\n';
    getchar();*/
    for (int i = 0; i < noye2.size(); i++)
    {
        
        //cout << noye2[i].x << " " << noye2[i].y << " " << noye2[i].color << '\n';

        q.push({ noye2[i].x,noye2[i].y });
        tmp[noye2[i].x][noye2[i].y] = { 0,noye2[i].color };

    }

    int time = 0;
    int cnt = 0;
    while (!q.empty())
    {
        pair<int,int> front = q.front();
        q.pop();
        if (tmp[front.first][front.second].second == 5)
            continue;
        int color = tmp[front.first][front.second].second;
        int time = tmp[front.first][front.second].first;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + front.first;
            int ny = dy[i] + front.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 0)
            {
                if (tmp[nx][ny].second == 0)
                {
                    tmp[nx][ny]= { time + 1,color };
                    q.push({ nx,ny });
                }
                else if (color==4 && tmp[nx][ny].second == 3 && time + 1 == tmp[nx][ny].first)
                {
                    tmp[nx][ny].second = 5;
                    cnt++;
                }
                else if (color==3 && tmp[nx][ny].second == 4 && time + 1 == tmp[nx][ny].first)
                {
                    tmp[nx][ny].second = 5;
                    cnt++;
                }
            }

        }

    }


    maxx = max(maxx, cnt);
}
void dfs_d(int idx,int cnt)
{
    if (cnt == g)
    {
        play();
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (visit_v[i] == 0)
        {
            visit_v[i] = 4;
            noye2.push_back({ v[i].first,v[i].second,4 });
            dfs_d(i, cnt + 1);
            visit_v[i] = 0;
            noye2.pop_back();
        }
    }
}
void dfs_v(int idx,int cnt)
{
    if (cnt == r)
    {
        dfs_d(0,0);
        return;
        //배열 선택 완료
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (visit_v[i] == 0)
        {
            visit_v[i] = 3;
            noye2.push_back({ v[i].first,v[i].second,3 });
            dfs_v(i, cnt + 1);
            visit_v[i] = 0;
            noye2.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r >> g;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                v.push_back({ i,j });
        }
    }
    for (int i = 0; i < r; i++)
    {
        drug[idx++] = 3;
    }
    for (int i = 0; i < g; i++)
    {
        drug[idx++] = 4;
    }
    //do {
    //    /*for (int i = 0; i < v.size(); i++)
    //    {
    //        cout << drug[i] << " ";
    //    }
    //    cout << '\n';
    //    getchar();*/
    //    play();
    //} while (next_permutation(drug, drug + v.size()));
    dfs_v(0,0);
    cout << maxx;
    return 0;
}
