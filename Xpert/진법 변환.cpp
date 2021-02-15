/*

A진법 수 N을 입력 받아 B진법 수로 출력하는 프로그램을 작성하시오.

N에 사용되는 값은 0 ~ 9, A ~ Z이다.

(2 ≤ A, B ≤​ 36) ( 0≤​ N≤​ 263-1 )

입력은 100개 이하의 테스트 케이스가 행으로 구분하여 주어진다.

테스트 케이스의 끝에는 0이 주어진다.

각 테스트 케이스에는 세 수 A, N, B가 공백으로 구분되어 주어진다.

각 테스트 케이스에 대하여 A진법수 N을 B진법 수로 변환한 결과를 행으로 구분하여 출력한다.

2 11010 8
2 10110 10
10 2543 16
16 ABC 8
0

32
22
9EF
5274

[ Horner's Method ]

2진수 1101을 자리수별 가중치를 주어 10진수로 나타내면 아래와 같다.

1101 = 0 * 24 + 1 * 23 + 1 * 22 + 0 * 21 + 1 이므로

	 = (((0*2 + 1) * 2 + 1) * 2 + 0) * 2 + 1 과 같다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long LL; 
int A, B;
char str[70], base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


void dToB(LL d) {
	if (d < B) {
		printf("%c", base[d]);
		return;
	}
	dToB(d / B);
	printf("%c", base[d%B]);
}
int main() 
{
	while (scanf("%d %s %d", &A, str, &B) && A) {
		LL deci = 0;
		//A to deci
		for (int i = 0; str[i]; ++i) {
			deci = deci * A + str[i] - (str[i] < 'A' ? 48 : 55); //A가 들어오면 65-55 해서 10으로 만들어줌
		}
		dToB(deci);
		puts("");
	}
	
	return 0;
}
