//https://www.acmicpc.net/problem/10845
/*풀이 : stl을 쓰지 않고 구조체를 이용해 큐를 구현했다.*/
#include <iostream>
#include <cstring>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;
typedef struct queue
{
public:
	node* head = NULL;
	node* tail = NULL;
	int _size = 0;
	void push(int num)
	{
		node* temp = new node;
		temp->data = num;
		temp->next = NULL;
		if (is_empty())
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		_size++;
	}
	int pop()
	{
		if (is_empty())
			return -1;
		else if (head == tail)
		{
			_size--;
			struct node* temp = head;
			int tmp = head->data;
			head = NULL;
			tail = NULL;
			delete temp;
			return tmp;

		}
		else
		{
			_size--;
			struct node* temp = head;
			int tmp = head->data;
			head = head->next;
			delete temp;
			return tmp;
		}

	}
	bool is_empty()
	{
		if (head == NULL && tail == NULL)
			return 1;
		else
			return 0;
	}
	int front()
	{
		if (head == NULL)
			return -1;
		else
			return head->data;
	}
	int back()
	{
		if (tail == NULL)
			return -1;
		else
			return tail->data;
	}
	int size()
	{
		return _size;
	}
};
int main()
{
	queue q;
	int n, num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char c[6] = { 0 };
		scanf("%s", c);
		if (strcmp(c, "push") == 0)
		{
			scanf("%d", &num);
			q.push(num);
		}
		else if (strcmp(c, "pop") == 0)
		{
			printf("%d\n", q.pop());
		}
		else if (strcmp(c, "size") == 0)
		{
			printf("%d\n", q.size());
		}
		else if (strcmp(c, "empty") == 0)
		{
			printf("%d\n", q.is_empty());
		}
		else if (strcmp(c, "front") == 0)
		{
			printf("%d\n", q.front());
		}
		else if (strcmp(c, "back") == 0)
		{
			printf("%d\n", q.back());
		}
	}
	return 0;
}
