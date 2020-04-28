//https://www.acmicpc.net/problem/17029
/*풀이 : name을 인덱스로 하는 벡터 배열을 만들고
벡터 배열에 특징들을 넣는다. 그리고 한 벡터와 모든 벡터들을 비교하면서
겹치는 특징의 최대 갯수를 찾는다.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<string> c[101];

int num_common(int i, int j)
{
	int cnt = 0;
	vector<string> v1 = c[i];
	vector<string> v2 = c[j];
	for (int i = 0; i < v1.size(); i++)
		for (int j = 0; j < v2.size(); j++)
			if (v1[i] == v2[j]) 
				cnt++;
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> s >> K;
		for (int j = 0; j < K; j++) {
			string tmp;
			cin >> tmp;
			c[i].push_back(tmp);
		}
	}
	int maxx = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			maxx= max(maxx, num_common(i, j));
	cout << maxx + 1 << "\n";
	return 0;
}
