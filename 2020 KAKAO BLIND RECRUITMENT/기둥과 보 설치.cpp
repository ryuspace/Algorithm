/*풀이 : 기둥이나 보를 현재 기준점 기준으로 시계방향으로 있는 기둥과 보를 체크해놓고, 
설치할 때 규칙에 맞게 방향에 기둥이나 보가 있는지 체크한다.
삭제할 때는 삭제하는 위치 기준으로 시계방향에 있는 기둥과 보가 설치가 가능한지 체크한다.
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct point
{
	int x, y;
};
int nn;
int r, c;
int arr[101][101];
int map[101][101];
bool gi(point hi)//기둥이 있는지?
{
	int x = hi.x;
	int y = hi.y;
	if (x >= 0 && x <= nn && y >= 0 && y <= nn && (map[x][y] == 1 || map[x][y] == 3))
	{
		return true;
	}
	return false;
}
bool bo(point hi)//보자기가 있는지?
{
	int x = hi.x;
	int y = hi.y;
	if (x >= 0 && x <= nn && y >=0 && y <= nn && (map[x][y] == 2 || map[x][y] == 3))
	{
		return true;
	}
	return false;
}
bool check(int x, int y, int a, int b)
{
    if(a==0)
    {
        return true;
    }
	//빈칸에 접근 한 것이므로 문제 없다.
	point p[13];
	p[0] = { x,y };
	p[1] = { x + 1,y + 1 };
	p[3] = { x + 1,y };
	p[5] = { x + 1,y - 1 };
	p[6] = { x,y - 1 };
	p[7] = { x - 1,y - 1 };
	p[9] = { x - 1,y };
	p[11] = { x - 1,y + 1 };
	p[12] = { x,y + 1 };
	//설치되는 점 기준으로 시계방향 탐색
	if (b == 1)//설치
	{
		if (a == 1)//기둥
		{
			if (y == 0 || bo(p[9]) || bo(p[0]) || gi(p[6]))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if(a==2)//보자기
		{
			if ((gi(p[5]) ||gi(p[6])))
			{
				return true;
			}
			else if ((bo(p[9]) && bo(p[3])))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if(b==0)
	{
		//기준이 되는 부분 없애보고 시계방향에 있는 기둥과 보가 맞는 위치에 있는지 체크
		if(a == 1)//기둥
		{
			bool f = true;
			map[x][y] -= 1;
			f &= check(p[0].x, p[0].y, map[p[0].x][p[0].y], 1);
			f &= check(p[1].x, p[1].y, map[p[1].x][p[1].y], 1);
			f &= check(p[3].x, p[3].y, map[p[3].x][p[3].y] , 1);
			f &= check(p[5].x, p[5].y, map[p[5].x][p[5].y], 1);
			f &= check(p[6].x, p[6].y, map[p[6].x][p[6].y] , 1);
			f &= check(p[7].x, p[7].y, map[p[7].x][p[7].y] , 1);
			f &= check(p[9].x, p[9].y, map[p[9].x][p[9].y] , 1);
			f &= check(p[11].x, p[11].y, map[p[11].x][p[11].y] , 1);
			f &= check(p[12].x, p[12].y, map[p[12].x][p[12].y] , 1);
			map[x][y] += 1;
			return f;
		}
		else if(a==2)//보
		{
			bool f = true;
			map[x][y] -= 2;
			f &= check(p[0].x, p[0].y, map[p[0].x][p[0].y] , 1);
			f &= check(p[1].x, p[1].y, map[p[1].x][p[1].y] , 1);
			f &= check(p[3].x, p[3].y, map[p[3].x][p[3].y] , 1);
			f &= check(p[5].x, p[5].y, map[p[5].x][p[5].y] , 1);
			f &= check(p[6].x, p[6].y, map[p[6].x][p[6].y] , 1);
			f &= check(p[7].x, p[7].y, map[p[7].x][p[7].y] , 1);
			f &= check(p[9].x, p[9].y, map[p[9].x][p[9].y] , 1);
			f &= check(p[11].x, p[11].y, map[p[11].x][p[11].y] , 1);
			f &= check(p[12].x, p[12].y, map[p[12].x][p[12].y] , 1);
			map[x][y] += 2;
			return f;
		}
	}
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	nn = n;
	vector<vector<int>> answer;
	for (int i = 0; i < build_frame.size(); i++)
	{
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int a = build_frame[i][2];
		int b = build_frame[i][3];
		bool f = check(x, y, a+1, b);//설치 또는 삭제가 되는 조건 인지
		if (f && (b == 1))//설치
		{
			if (a == 0)
			{
				map[x][y] += 1;
			}
			else if(a==1)
			{
				map[x][y] += 2;
			}
		}
		else if(f && (b==0))
		{
			if (a == 0)
			{
				map[x][y] -= 1;
			}
			else if(a==1)
			{
				map[x][y] -= 2;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			vector<int>tmp;
			if (map[i][j] != 0)
			{
				if (map[i][j] == 3)
				{
					tmp.push_back(i);
					tmp.push_back(j);
					tmp.push_back(0);
					answer.push_back(tmp);
                    tmp.clear();
                    
					tmp.push_back(i);
					tmp.push_back(j);
					tmp.push_back(1);
					answer.push_back(tmp);
				}
				else if (map[i][j] == 1)
				{
					tmp.push_back(i);
					tmp.push_back(j);
					tmp.push_back(0);
					answer.push_back(tmp);
				}
				else if(map[i][j]==2)
				{
					tmp.push_back(i);
					tmp.push_back(j);
					tmp.push_back(1);
					answer.push_back(tmp);
				}
			}
		}
	}
	return answer;
}
