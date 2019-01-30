//https://www.acmicpc.net/problem/16771
/*풀이 : 첫번째 헛간에서 온 양동이는 b[10]에 넣고 두번째 헛간에서 온 양동이는 첫번째 헛간에서 온 양동이
위치에다 놓고 그 빈 곳에 b[10]을 놓고 b[10]을 다시 0으로 해서 모든 경우 계속 반복*/
#include <iostream>
#include <cstring>
using namespace std;
int ans[12100];
bool sum[2000];
int main() {

	memset(sum, false, sizeof(sum));
	int a[10], b[11], tmp_a[10], tmp_b[11];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		tmp_a[i] = a[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> b[i];
		tmp_b[i] = b[i];
	}
	b[10] = 0;
	tmp_b[10] = 0;
	int c = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 11; l++) {
					ans[c] = 1000;
					ans[c] -= a[i];
					b[10] = a[i];
					ans[c] += b[j];
					a[i] = b[j];
					b[j] = b[10];
					b[10] = 0;
					ans[c] -= a[k];
					b[10] = a[k];
					ans[c] += b[l];
					a[k] = b[l];
					b[l] = b[10];
					b[10] = 0;
					for (int m = 0; m < 10; m++) {
						a[m] = tmp_a[m];
					}
					for (int m = 0; m < 10; m++) {
						b[m] = tmp_b[m];
					}
					c++;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 12100; i++) {
		sum[ans[i]] = true;
	}
	for (int i = 0; i < 2000; i++) {

		if (sum[i]) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
