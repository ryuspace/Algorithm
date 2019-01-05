//https://www.acmicpc.net/problem/1421
#include <iostream>
#include <algorithm>

using namespace std;
int namu[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, c, w;
	int Max=0;
	int cut_cnt = 0;
	int namu_cnt = 0;
	int value = 0;
	int sum = 0;
	cin >> n >> c >>w;
	for (int i = 1; i <= n; i++)
	{
		cin >> namu[i];
		if (Max < namu[i])
			Max = namu[i];
	}
	for (int i = 1; i <= Max; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (namu[j] % i == 0)//잘라서 버리는게 없을 경우
			{
				cut_cnt = namu[j] / i - 1;
			}
			else//잘랐는데 버려지는게 생기는 경우
			{
				cut_cnt = namu[j] / i;
			}
			namu_cnt = namu[j] / i;
			if (namu_cnt*w*i - cut_cnt * c > 0)//자른 비용이 수익보다 더 크면 안 자르고 안 파는게 낫다
			{
				sum += namu_cnt * w*i - cut_cnt * c;
			}
			
		}
		if (sum > value)
		{
			value = sum;
		}
	}
	cout << value;

	return 0;
}
