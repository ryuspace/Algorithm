//https://www.acmicpc.net/problem/1725
/*풀이 : 나를 기준으로 스택 가장 위가 나보다 작으면 계속 push
나보다 크면 나보다 큰 애 나올 때 까지 pop 하고 그 높이와 나 사이의 거리를 곱한다..
처음과 끝을 구분하기 위하여 처음과 끝에 0을 푸쉬해준다.*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int arr[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack <int> s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int maxx = 0;
	s.push(0);
	for (int i = 1; i <= n+1; i++)
	{
		while (!s.empty() && arr[s.top()] > arr[i])
		{
			int hi = arr[s.top()];
			s.pop();
			int wi = i - s.top()-1;
			maxx = max(maxx, hi * wi);
			/*
			int hi = arr[s.top()];
			int wi = i - s.top();
			s.pop();
			maxx = max(maxx, hi * wi);
			이 안되는 이유는
			1 4 2 4 4 4 1 히스토그램 한번 생각해보기..
			내가 pop되었다는 것은 나보다 앞에있던 모든 나보다 긴 놈은 이미 빠져있는 상태야! 
			그러므로 나보다 앞에 살아있는 놈 기준으로 봐야해.. 나와 내 앞 살아있는 놈 사이에
			얼마나 죽었는지 모르니까..!
			*/
		}
		s.push(i);
	}
	cout << maxx;
	return 0;
}
