#include <stdio.h>
void hanoi(int n, int s, int e){
if(n <= 0) return;
hanoi(n-1, s, 6-s-e); //n-1개의 하노이탑을 여분의 위치에 치워주세요
printf("%d : %d -> %d\n", n, s, e);//그럼 가장 큰 하노이 하나가 남을 테니 걔를 3번째 위치에 치워주세요
hanoi(n-1, 6-s-e, e); //n-1개의 하노이탑을 여분의 위치에서 3번째 위치로 치워주세요
}
int main(){
int N;
scanf("%d", &N);
hanoi(N, 1, 3);
return 0;
}
