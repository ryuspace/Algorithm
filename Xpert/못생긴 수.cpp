/*
풀이 : 1을 시작으로 2,3,5를 각각 곱해서 maxheap에 넣는다 그리고 다 빼면 오름차순 정렬이 된다.
곱한 값의 중복 처리는 해시테이블을 사용했다...
뭔가 비효율적
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXN 2010

long long max(long long a, long long b)
{
	if (a > b)
		return 1;
	return 0;
}
long long min(long long a, long long b)
{
	if (a < b)
		return 1;
	return 0;
}
void swap(long long& a, long long& b)
{
	long long t = a;
	a = b;
	b = t;
}

struct node
{
	long long num;
	struct node* next= NULL;
};

node htable[MAXN];
node tmpNode[MAXN];
int tmpIdx;

node* alloc(long long num,node*next)
{
	node* np = &tmpNode[tmpIdx++];
	np->num = num;
	np->next = next;
	return np;
}

void insert(long long num)
{

	long long key = num % MAXN;
	node* head = &htable[key];
	node* np = alloc(num, head->next);
	head->next = np;
}

long long findMe(long long num)
{

	long long key = num % MAXN;
	node* head = &htable[key];
	while (head->next)
	{
		if (head->next->num == num)
			return 1;
		head = head->next;
	}

	return 0;
}


struct PriorityQueue {

	long long hash;
	long long size;
	long long heap[MAXN], hn;
	long long (*comp)(long long, long long);
	
	void init(int mode)
	{
		hash = 0;
		size = 0;
		hn = 0;
		comp = mode ? max : min;
	}
	void push(long long num)
	{
		size++;
		heap[++hn] = num;

		for (int c = hn; c > 1; c /= 2)
		{
			if (comp(heap[c], heap[c / 2]))
				swap(heap[c], heap[c / 2]);
			else
				break;
		}
		if(hash)
			insert(num);
	}
	void pop()
	{
		size--;
		swap(heap[1], heap[hn--]);

		for (int c = 2; c <= hn; c *= 2)
		{
			if (c<hn && comp(heap[c + 1], heap[c]))
				c++;

			if (comp(heap[c], heap[c / 2]))
				swap(heap[c], heap[c / 2]);
			else
				break;
		}
	}

	long long top()
	{
		return heap[1];
	}

	long long find(long long num)
	{
		return findMe(num);
	}


}maxpq,minpq,minipq;




int n;
int main()
{

	minpq.init(0);
	minipq.init(1);
	minipq.hash = 1;

	minpq.push(1);

	minpq.push(2);

	minpq.push(3);
	
	minpq.push(5);

	while (minpq.size && minipq.size <= 2000)
	{
		long long num = minpq.top();
		minpq.pop(); 
		if (!minipq.find(num))
		{
			minipq.push(num);
			minpq.push(num);
		}
		if (!minipq.find(num*2))
		{
			minipq.push(num*2);
			minpq.push(num*2);
		}
		if (!minipq.find(num*3))
		{
			minipq.push(num*3);
			minpq.push(num*3);
		}
		if (!minipq.find(num*5))
		{
			minipq.push(num*5);
			minpq.push(num*5);
		}

	}

	while (minipq.size)
	{
		minipq.pop();
	}



	scanf("%d", &n);
	while (n != 0)
	{
		printf("%lld\n",minipq.heap[n]);
		scanf("%d", &n);
	}
	return 0;
}
