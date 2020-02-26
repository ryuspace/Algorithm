//https://www.acmicpc.net/problem/18138
/*
단순 이분매칭
시간복잡도는 O(V*E)
모든 정점(V)이 자리를 차지하는데.
dfs를 한번 도는데 간선의 갯수(E)만큼 도니깐
V*E
정점의 갯수는 최대 200
간선의 갯수는 최대 200*200

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double shirt[202];
double kara[202];
vector<int> v[202];
int chaji[202];
bool visit[202];
bool dfs(int num)
{

    for (int i = 0; i < v[num].size(); i++) {
        //
        if (visit[v[num][i]])
            continue;
        visit[v[num][i]] = true;
        //
        //이 부분이 포인트. 우선 점 하나를 먹어보고 다른 애보고 비켜보라고 하자, 되면 장땡이지만 안되면 다음 점 먹어보고 계속 반복. 
        if (chaji[v[num][i]] == 0 || dfs(chaji[v[num][i]]))
        {
            chaji[v[num][i]] = num;
            return true;
        }
    }
    return false;
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> shirt[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> kara[i];
    }
    for (int i = 1; i <= n; i++)
    {
        double gi = shirt[i];
        for (int j = 1; j <= m; j++)
        {
            if ((kara[j] >= (double)(gi / 2) && kara[j] <= (double)(gi * 3) / 4) || (kara[j] >= (double)gi && kara[j] <= (double)(gi *5) / 4))
            {
                v[i].push_back(j);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        fill(&visit[1], &visit[n + 1], false);
        if (dfs(i))
            cnt++;
    }
    cout << cnt;
    return 0;

}
