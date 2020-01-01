//https://www.acmicpc.net/problem/1009
/*최대 b%4번만 반복이 포인트.*/
#include <cstdio>
int main(void) {

	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		b %= 4;
		if (b == 0)
			b = 4;

		int t = a % 10;
		for (int i = 2; i <= b; ++i)
			t = (t * a) % 10;
		if (t == 0)
			t = 10;

		printf("%d\n", t);
	}
	return 0;
}
