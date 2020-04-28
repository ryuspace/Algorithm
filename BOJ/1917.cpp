//https://www.acmicpc.net/problem/1917
/*
풀이 : 테트로미노 상위호환 버전.
배열로 미리 모든 정육면체 전개도를 그려놓고 회전과 뒤집기를 해본 모든 경우를 탐색해본다.

깨달은 점 : 회전하기 위해서는 정육면체 전개도 배열을 n X n 으로 같은 크기로 만들어줘야한다.
            기존 입력 받는 배열은 상하좌우 넉넉하게 더 공간을 잡아준다. 전개도 배열 빈 부분에 매칭 시킬 때 문제 없게 하기 위해서
아쉬운 점 : 전개도를 그냥 미리 뭐가 있는지 알려줘도 되지 않을까 싶다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[11][5][5] = { {0,0,0,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{ 0,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 }, { 0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 }, { 0,0,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0} };
int my[21][21];

void rotate(int arr[5][5])
{
    int tmp[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = tmp[4 - j][i];
        }
    }
}
void revers(int arr[5][5])
{
    int tmp[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = tmp[i][4-j];
        }
    }
}
bool check(int arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //cout << arr[i][j] << " ";
            if (arr[i][j] != 0)
                return false;
        }
        //cout << '\n';
    }
    return true;
}
bool match(int arr[5][5])
{
    /*for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    getchar();*/
    bool flag = false;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            int clear[5][5] = { 0, };
            for (int r = 0; r < 5; r++)
            {
                for (int k = 0; k < 5; k++)
                {
                    clear[r][k] = my[i + r][j + k] + arr[r][k];
                    //cout << clear[r][k] << " ";
                    

                }
                //cout << '\n';
            }
            //cout << '\n';
            //getchar();
            if (check(clear))
            {
                flag = true;
                break;
            }
            if (flag)
                break;
        }

    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int t = 0; t < 3; t++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cin >> my[i+5][j+5];
                if (my[i+5][j+5] == 1)
                    my[i+5][j+5] = -1;
            }
        }
        /*for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 21; j++)
            {
                cout << my[i][j] << " ";
            }
            cout << '\n';
        }
        getchar();*/
        bool flag = false;
        for (int i = 0; i < 11; i++)
        {
            int tmp[5][5];
            for (int r = 0; r < 5; r++)
            {
                for (int k = 0; k < 5; k++) {
                    tmp[r][k] = arr[i][r][k];
                }
            }
            for (int r = 0; r < 2; r++)
            {
                revers(arr[i]);
                for (int j = 0; j < 4; j++)
                {
                    rotate(arr[i]);
                    if (match(arr[i]))
                    {
                        flag = true;
                    }
                    if (flag)
                        break;
                }
            }
            
            for (int r = 0; r < 5; r++)
            {
                for (int k = 0; k < 5; k++) {
                    arr[i][r][k] = tmp[r][k];
                }
            }
            
            
            if (flag)
            {
                //cout << i << "번" << '\n';
                break;
            }
           
            
        }

        if (flag)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }

       
    }
    return 0;
}
