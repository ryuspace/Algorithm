#include <stdio.h>
const int SIZE = 20005;

bool max(int a, int b) { return a > b; }
bool min(int a, int b) { return a < b; }
void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

struct PriorityQueue {
	int heap[SIZE], hn;

	//init 함수를 통하여 결정
	bool(*cmp)(int, int);

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
	
	return 0;
}
