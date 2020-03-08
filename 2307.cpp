//https://www.acmicpc.net/problem/2307
/*풀이 : 전체에 대해서 dikstra를 돌리고 dikstra 경로를 역추적 해서 경로를 하나씩 지워나가면서 지연시간의 최대를 찾는다. 최단 경로로 갈 것이고 최단 경로가 아닌 곳을 지우면 의미가 없다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> v[1001];
int price[1001];

int parent[1001];
int minn;
int minn2 = 0;

void dik()
{
    for (int i = 1; i <= n; i++)
    {
        price[i] = 1e9;
    }
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push({ 1,0 });
    price[1] = 0;
    while (!q.empty())
    {
        pii front = q.top();
        q.pop();
        int now = front.first;
        int sum = front.second;

        for (int i = 0; i < v[now].size(); i++)
        {
            if (price[v[now][i].first] > price[now] + v[now][i].second)
            {
                parent[v[now][i].first] = now;
                price[v[now][i].first] = price[now] + v[now][i].second;
                q.push({ v[now][i].first,price[now] + v[now][i].second });
            }
        }
    }
}

void dik2(int before, int next)
{
    for (int i = 1; i <= n; i++)
    {
        price[i] = 1e9;
    }
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push({ 1,0 });
    price[1] = 0;
    while (!q.empty())
    {
        pii front = q.top();
        q.pop();
        int now = front.first;
        int sum = front.second;
        for (int i = 0; i < v[now].size(); i++)
        {
            if ((before == now && next == v[now][i].first) || (before == v[now][i].first && next == now))
            {
                continue;

            }
            if (price[v[now][i].first] > price[now] + v[now][i].second)
            {
                price[v[now][i].first] = price[now] + v[now][i].second;
                q.push({ v[now][i].first,price[now] + v[now][i].second });
            }
        }
    }

}
int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    dik();
    minn = price[n];
    int _n = n;
    while (_n != 1)
    {

        int before = _n;
        int next = parent[_n];
        dik2(before, next);
        if (price[n] == 1e9)
        {
            cout << -1;
            exit(0);
        }
        else
        {
            minn2 = max(minn2, price[n] - minn);
        }
        _n = parent[_n];
    }
    cout << minn2;
    return 0;

}
