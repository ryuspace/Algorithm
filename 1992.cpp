//https://www.acmicpc.net/problem/1992
/*
풀이 : 시키는 대로 한다.. 우선 현재 기준 맵이 0또는 1로 채워졌는지 체크, 그렇지 않으면 네 등분으로 나눠서 다시 체크해본다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[65][65];
bool check(int x,int y,int value,int num)
{

}
void div(int x, int y, int value)
{
    if (value == 0)
    {
        return;
    }
    bool zero = true;
    bool one = true;
    for (int i = x; i < x + value; i++)
    {
        for (int j = y; j < y + value; j++)
        {
            if (arr[i][j] == 1)
            {
                zero = false;
            }
            else
            {
                one = false;
            }
        }
    }
    if (zero)
    {
        cout << 0;
    }
    else if (one)
    {
        cout << 1;
    }
    else
    {
        cout << "(";
        div(x, y, value / 2);
        div(x, y + value / 2, value / 2);
        div(x + value / 2, y, value / 2);
        div(x + value / 2, y + value / 2, value / 2);
        cout << ")";
    }
}
int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char a;
            cin >> a;
            arr[i][j] = a - '0';
        }
    }
    div(1, 1, n);
    return 0;

}
