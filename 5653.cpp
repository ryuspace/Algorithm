/*5653번 줄기세포 배양
풀이 : 구조체에 x좌표 y좌표 값,시간,활성화 시간의 변수를
넣어줘서 시키는 대로 시뮬레이션 한다. 코드에 상황에 따른 주석을 달겠음.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
int t;
int n, m, k;
int arr[621][621];
struct point
{
	int x, y, value,time,burst;
	bool flag;
};
bool operator<(point t, point u)
{
	return t.value < u.value;
}
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

priority_queue<point> qq;
queue<point> q;
int bfs()
{
	int cnt = 0;
	while (!qq.empty())
		//순전히 밑의 조건 때문에 priority queue를 사용하였다. 같은 pq에 계속 담으면 size 만큼 bfs 돌릴 때 이상하게 되므로 어떤 시간에 우선순위를 우선 정하는 용도로만 pq를 쓴다.
		//두 개 이상의 줄기 세포가 하나의 그리드 셀에 동시 번식하려고 하는 경우 생명력 수치가 높은 줄기 세포가 해당 그리드 셀을 혼자서 차지하게 된다.

	{
		point front = qq.top();
		qq.pop();
		q.push(front);//큐에다 옮기기..
	}
	while (!q.empty())
	{
		int sizz = q.size();
		if (cnt == k)
			return sizz;
		while (sizz--)//pq에다 계속 push 하면 큰 값은 계속 위로 올라온다. 시간에 따른 순서가 지켜지지 않는다.
		{
			point front = q.front();
			q.pop();
			if (front.flag == false)//비활성 상태
			{
				front.time++;
				if (front.time == arr[front.x][front.y])//다음 시간에는 활성으로 넘어가자
				{
					front.flag = true;
					front.burst = 1;//활성화 시간 초기화
				}
				qq.push({front.x,front.y,arr[front.x][front.y],front.time,front.burst,front.flag });
			}
			else if (front.flag == true)//활성 상태
			{
				for (int i = 0; i < 4; i++)
				{
					int nx = front.x + dx[i];
					int ny = front.y + dy[i];
					if (nx >= 0 && nx < 2001 && ny >= 0 && ny < 2001)
					{
						if (arr[nx][ny] == 0)
						{
							arr[nx][ny] = arr[front.x][front.y];
							qq.push({ nx,ny,arr[nx][ny],0,0,false });
						}
					
					}
				
				}
				if (front.burst < arr[front.x][front.y])//아직 활성화 시간 남으면 이 아이만 따로 push 해준다.
					qq.push({ front.x,front.y,arr[front.x][front.y],front.time,front.burst + 1,front.flag });
			}
		}
		cnt++;
		while (!q.empty())
			q.pop();
		while (!qq.empty())
		{
			point front = qq.top();
			qq.pop();
			q.push(front);
		}
	}
	return cnt;
}
int main()
{
	//freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int y = 1; y <= t; y++)
	{
		while (!q.empty())
			q.pop();
		while (!qq.empty())
			qq.pop();
		memset(arr, 0, sizeof(arr));
		cin >> n >> m >> k;
		for (int i = 310; i < n+310; i++)
		{
			for (int j = 310; j < m+310; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] != 0)
				{
					qq.push({i,j,arr[i][j],0,0,false });
				}
			}
		}
		cout<<"#"<<y<<" "<<bfs()<<'\n';
	}
	return 0;
}
