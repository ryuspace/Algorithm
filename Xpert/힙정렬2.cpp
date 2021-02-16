#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const int SIZE = 500001;

int max(int a, int b)
{
	if (a > b)
		return 1;
	return 0;
}
int min(int a, int b)
{
	if (a < b)
		return 1;
	return 0;
}
void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

struct PriorityQueue {
	int heap[SIZE], hn;

	//init 함수를 통하여 결정
	int(*cmp)(int, int);

	// order==1 : max heap
	// order==0 : min heap
	void init(int order) {
		hn = 0;
		cmp = order ? max : min;
	}

	int top() {
		return heap[1];
	}

	void push(int data)
	{
		//heap의 맨 뒤에 New Data 추가
		heap[++hn] = data;
		for (int c = hn; c > 1; c /= 2)
		{
			if (cmp(heap[c], heap[c / 2]))
				swap(heap[c], heap[c / 2]);
			else
				break;
		}

	}
	void pop()
	{
		swap(heap[1], heap[hn--]);
		for (int c = 2; c <= hn; c *= 2)
		{
			//오른쪽 child가 있고 그 값이 왼쪽 child값보다 ~다면
			if (c < hn && cmp(heap[c + 1], heap[c]))
				c++;
			//child값 (heap[c])이 parent값 (heap[c/2])보다 ~다면
			if (cmp(heap[c], heap[c / 2]))
				swap(heap[c], heap[c / 2]);
			else
				break;
		}
	}
}maxpq, minpq;

int main()
{
	maxpq.init(1);
	minpq.init(0);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		maxpq.push(a);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", maxpq.heap[i]);
	}
	printf("\n");

	for (int i = 1; i <= n; i++)
	{
		maxpq.pop();
	}//전부 pop을 하고 원소들이 사라진 heap 배열을 보면 오름차순 정렬이 되어있다!

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", maxpq.heap[i]);
	}
	return 0;
}
