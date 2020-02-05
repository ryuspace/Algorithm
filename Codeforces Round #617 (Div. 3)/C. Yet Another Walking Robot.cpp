#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;
 
typedef pair<int, int> pii;
struct point
{
	int x, y, cnt;
};
bool cmp(const point& a, const point& b)
{
	if (a.cnt < b.cnt)
		return true;
	return false;
}
int main(void)
{
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;
	while (t--)
	{
		vector<point> v;
		map<pii, int> m;
		bool flag = false;
		int x = 0, y = 0;
		int n;
		cin >> n;
		string tmp;
		cin >> tmp;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == 'L')
			{
				if (m.count(make_pair(x - 1, y)) == 0)
				{
					if (x - 1 == 0 && y == 0)
					{
						flag = true;
						v.push_back({ 1,i + 1,i + 1 - 1 + 1 });
						//cout << 1 << " " << i + 1 << '\n';
						m[make_pair(x-1,y)] = i + 1;
					}
					else
					{
						m[make_pair(x - 1, y)] = i + 1;
					}
				}
				else
				{
					flag = true;
					v.push_back({ m[make_pair(x - 1, y)] + 1 ,i+1,(i+1) - (m[make_pair(x - 1, y)] + 1) +1});
					//cout << m[make_pair(x - 1, y)] + 1 << " " << i + 1 << '\n';
					m[make_pair(x - 1, y)] = i + 1;
				}
				x -= 1;
 
			}
			else if (tmp[i] == 'R')
			{
				if (m.count(make_pair(x + 1, y)) == 0)
				{
					if (x + 1 == 0 && y == 0)
					{
						flag = true;
						//cout << 1 << " " << i + 1 << '\n';
						v.push_back({ 1,i + 1,i + 1 - 1 + 1 });
						m[make_pair(x+1, y)] = i + 1;
					}
					else
					{
						m[make_pair(x + 1, y)] = i + 1;
					}
				}
				else
				{
					flag = true;
					//cout << m[make_pair(x + 1, y)] + 1 << " " << i + 1 << '\n';
					v.push_back({ m[make_pair(x + 1, y)] + 1 ,i + 1,(i + 1) - (m[make_pair(x + 1, y)] + 1)+1 });
					m[make_pair(x + 1, y)] = i + 1;
				}
				x += 1;
			}
			else if (tmp[i] == 'U')
			{
				if (m.count(make_pair(x, y + 1)) == 0)
				{
					if (x == 0 && y + 1 == 0)
					{
						flag = true;
						//cout << 1 << " " << i + 1 << '\n';
						v.push_back({ 1,i + 1,i + 1 - 1 + 1 });
						m[make_pair(x, y +1)] = i + 1;
					}
					else
					{
						m[make_pair(x, y + 1)] = i + 1;
					}
				}
				else
				{
					flag = true;
					
					//cout << m[make_pair(x, y + 1)] + 1 << " " << i + 1 << '\n';
 
					v.push_back({ m[make_pair(x, y+1)] + 1 ,i + 1,(i + 1) - (m[make_pair(x, y+1)] + 1)+1 });
					m[make_pair(x, y + 1)] = i + 1;
				}
				y += 1;
			}
			else if (tmp[i] == 'D')
			{
				if (m.count(make_pair(x, y - 1)) == 0)
				{
					if (x == 0 && y - 1 == 0)
					{
						flag = true;
						//cout << 1 << " " << i + 1 << '\n';
						v.push_back({ 1,i + 1,i + 1 - 1 + 1 });
						m[make_pair(x, y - 1)] = i + 1;
					}
					else
					{
						m[make_pair(x, y - 1)] = i + 1;
					}
				}
				else
				{
					flag = true;
					//cout << m[make_pair(x, y - 1)] + 1 << " " << i + 1 << '\n';
					v.push_back({ m[make_pair(x, y-1)] + 1 ,i + 1,(i + 1) - (m[make_pair(x, y-1)] + 1)+1 });
					m[make_pair(x, y - 1)] = i + 1;
				}
				y -= 1;
			}
			
		}
		if (!flag)
			cout << -1 << '\n';
		else
		{
			sort(v.begin(), v.end(), cmp);
			cout << v[0].x << " " << v[0].y << '\n';
		}
	}
	return 0;
}
