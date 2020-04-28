/*5648번 원자 소멸 시뮬레이션
풀이 : 시뮬레이션. 코드마다 주석으로 풀이를 닮.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct point
{
	int x, y, dir, en;
};
int t, n;
int mp[4001][4001];//최대 4000 X 4000 까지 나올 수 있다. energy 값을 담는 배열
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	//freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for(int e = 1; e <= t; e++)
	{
		cin >>n;
		int sum = 0;
		queue<point>q;
		for (int i = 0; i < n; i++)
		{
			fill(&mp[0][0], &mp[4000][4000], 0);
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			//음수 좌표 계산하기 싫으니까 무조건 양수로 만들어주자.
			a = (a + 1000) * 2;
			b = (b + 1000) * 2;//1.5초에 터지는 거 계산하기 싫으니까 무조건 1초에 터지게 *2를 해주자.
			mp[a][b] = d;
			q.push({ a,b,c,d });
		}
		while (!q.empty())
		{
			point front = q.front();
			q.pop();
			if (front.en < mp[front.x][front.y])//합쳐진 경우 터뜨리자
			{
				sum += mp[front.x][front.y];
				mp[front.x][front.y] = 0;
				continue;
			}//터뜨림
			int nx = front.x + dx[front.dir];
			int ny = front.y + dy[front.dir];
			if (nx < 0 || nx>4000 || ny < 0 || ny>4000)
				continue;
			if (mp[nx][ny] == 0)
			{
				mp[nx][ny] = front.en;
				q.push({ nx,ny,front.dir,front.en });
			}
			else//여기 이미 누군가 왔으니까 에너지만 더해주고 터질 예정이니 push 해주지 말자.. 대표 한놈만 push 한 상태
			{
				mp[nx][ny] += front.en;
			}
			mp[front.x][front.y] = 0;
		}
	    cout<<"#"<<e<<" "<<sum<<'\n';

	}
	return 0;
}
