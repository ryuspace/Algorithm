#include <iostream>

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
