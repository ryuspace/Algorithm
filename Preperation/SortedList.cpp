//단방향 연결리스트, 성능 별로
#define MAXN 20001
#define NULL 0
struct node
{
	int data;
	struct node *next;
};

node list;
node tmpNode[MAXN + 10];
int tmpIdx;
node *alloc(int data)
{
	node *np = &tmpNode[tmpIdx++];
	np->next = NULL;
	np->data = data;
	return np;
}

void init() {
	tmpIdx = 0;
	list.next = NULL;
}

void insert(int data) {
	
	node *np = alloc(data);
	node *head = &list;
	while (head->next)
	{
		if (head->next->data > data)
			break;
		head = head->next;
	}
	np->next = head->next;
	head->next = np;
}

int remove(int index) {

	int turn = index;
	node *head = &list;
	while (head->next)
	{
		if (turn == 0)
			break;
		turn--;
		head = head->next;
	}

	int value = head->next->data;
	head->next = head->next->next;
	return value;
}

int searchByIndex(int index) {

	int turn = index;
	node *head = &list;
	while (head->next)
	{
		if (turn == 0)
			break;
		turn--;
		head = head->next;
	}

	return head->next->data;
}
