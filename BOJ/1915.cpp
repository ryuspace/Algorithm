//https://www.acmicpc.net/problem/1915
/*풀이 :
dp[x][y] : (x,y)까지 왔는데 여기까지의 최대 정사각형
그럼 봐야할 게 (x-1,y), (x,y-1),(x-1,y-1)에서 정사각형 가장 큰 것을 끌어다 쓰고 +1 하면 현재까지의 가장 큰 정사각형이 된다..
x-1 y-1 접근할 땐 인덱스 1부터 시작하자.. 0부터 시작하면 위험하다(아마 쓰레기값..?)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            arr[i][j] = a - '0';
        }
    }
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 1)
            {
                dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
                maxx = max(maxx, dp[i][j]);
            }

        }
    }
    cout << maxx * maxx;
    return 0;

}
