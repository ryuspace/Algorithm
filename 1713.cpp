#include <iostream>
#include <algorithm>

using namespace std;
int arr[1001];
struct point
{
	int x, y, z;
};
point now[21];
bool cmp(point& a, point& b)
{
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
	{
		if (a.y < b.y)
			return true;
		else
			return false;
	}
	else
		return false;
}
//추천횟수, 오래된 순, 번호순으로 sort
bool cmp2(point& a, point& b)
{
	return a.z < b.z;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int idx = 0;
	int n, cnt;
	cin >> n>>cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
		//이미 걸려있는지
		bool f = false;
		int idx = 0;
		for (int j = 0; j < n; j++)
		{
			if (now[j].z == arr[i])
			{
				now[j].x++;//걸려있는 후보 다시 추천 받은 경우. 추천 횟수만 높여주기.
				f = true;
				break;
			}
			if(now[j].z!=0)
				idx++;
		}
		//안 걸려 있으면
		if (!f)
		{
			if (idx >= n)//차있는지
			{
				sort(now, now + n, cmp);
				now[0] = { 1,i,arr[i] };
			}
			else
			{
				now[idx]= { 1,i,arr[i] };
			}

		}

	}
	sort(now, now + n, cmp2);
	for (int i = 0; i < n; i++)
	{
		if (now[i].z != 0)//사진틀이 비어있을 수도 있다.
			cout << now[i].z << " ";
	}
	return 0;
}
