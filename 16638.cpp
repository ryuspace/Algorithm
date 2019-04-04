//https://www.acmicpc.net/problem/16638
/*풀이 : 괄호에 있는 값은 미리 계산해서 하나의 숫자로 만들어 놓고 
수식을 펼친다. 그 수식을 탐색해 *가 있으면 미리 계산해놓는다. 완성되면
+,-만 남은 식이 되니까 순차적으로 계산한다.

*은 아스키코드로 42다.... 숫자 42와 주의하자.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
bool use[22];
int su[22];
int bu[22];
string tmp;
vector<long long int> vv;
long long int cal(long long int a, char b, long long int c)
{
	if (b == '+')
		return a + c;
	if (b == '-')
		return a - c;
	else
		return a * c;
}
long long int res = -1e9-1;
long long int yeon(vector<long long int> vv)
{

	vector<long long int> v;
	for (int i = 0; i < vv.size(); i++)
	{
		if (i%2==0 || (i%2==1 && vv[i] != '*'))
		{
			v.push_back(vv[i]);
			
		}
		else if(i%2==1 && vv[i] == '*')
		{
			long long int aa = v.back();
			v.pop_back();
			v.push_back((aa)*(vv[i+1]));
			i++;
		}
	}
	

	long long int ans = v[0];
	for (int i = 1; i < v.size(); i+=2)
	{
		if (i % 2 == 1 && v[i] == '+')
		{
			ans=ans + (v[i + 1]);
		}
		else if (i % 2 == 1 && v[i] == '-')
		{
			ans = ans - (v[i + 1]);
		}
	}
	return ans;
}
void dfs(bool flag,long long int one,char buho,long long int two,int now)
{
	if (now >= n - 1)
	{
		vv.push_back(buho);
		vv.push_back(two);
		res = max(res, yeon(vv));
		vv.pop_back();
		vv.pop_back();
		return;
	}
	if (flag == 0)
	{
		vv.push_back(buho);
		vv.push_back(two);
		dfs(0, cal(one, buho, two), bu[now + 1], su[now + 2], now + 2);
		dfs(1, cal(one, buho, two), bu[now + 1], su[now + 2], now + 2);
		vv.pop_back();
		vv.pop_back();
		
	}
	else
	{

		long long int hi = cal(one, buho, cal(two, bu[now + 1], su[now + 2]));
		long long int bye = cal(two, bu[now + 1], su[now + 2]);
		vv.push_back(buho);
		vv.push_back(bye);
		dfs(0, hi, bu[now+3], su[now + 4], now + 4);
		dfs(1, hi, bu[now + 3], su[now + 4], now + 4);
		vv.pop_back();
		vv.pop_back();

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> tmp;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			su[i] = (tmp[i] - '0');
		else
			bu[i] = tmp[i];
	}
	//괄호가 있다고 가정하면 4씩 넘어가니까.. n-1을 넘어갈 경우의 연산해도 의미 없는 숫자를 미리 넣어준다.
	bu[n] = '+';
	su[n + 1] = 0;

	vv.push_back(0);
	dfs(0, 0, '+', su[0], 0);
	dfs(1, 0, '+', su[0], 0);
	cout << res;
	return 0;
}
