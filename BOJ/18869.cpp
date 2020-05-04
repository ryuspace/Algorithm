/*
풀이 : 각 우주를 행성 크기 순으로 정렬하고 우주 별로 행성끼리 같은 인덱스인지 체크해보면 된다. 
*/
#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main(void)
{
	int N, M;
    int count = 0;
	int flag = 0;
	std::cin >> N >> M;
	vector< vector<pii> > arr;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		arr[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			int k;
			std::cin >> k;
			arr[i][j] = { k,j };
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			if (arr[i][j].first == arr[i][j + 1].first)
			{
				arr[i][j + 1].second = arr[i][j].second;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			flag = 0;
			for (int k = 0; k < M; k++)
			{
				if (arr[i][k].second != arr[j][k].second)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				count++;
			}

		}
	}
	cout << count;
	return 0;
}
