#define MAXN 100000
#define NULL 0
struct node
{
	int data;
	char name[12];
	struct node* next;
};

node htable[MAXN + 10];
node tmpnode[MAXN + 10];
int tmpidx;

int getHash(char* str)
{
	int code = 5381;
	for (int i = 0; str[i]; i++)
	{
		code = (code * 33 + str[i]) % MAXN;
	}
	return code;
}

void init()
{
	tmpidx = 0;
	for (int i = 0; i < MAXN; i++)
	{
		htable[i].next = NULL;
	}
}

void strcopy(char* dst, char* src)
{
	while (*dst++ = *src++);
}
int strcompare(char* a, char* b)
{
	int i;
	for (i = 0; a[i] && (a[i] == b[i]); i++);
	return a[i] - b[i];
}

node* alloc(int data, char* name, node* next)
{
	node* np = &tmpnode[tmpidx++];
	np->data = data;
	strcopy(np->name, name);
	np->next = next;
	return np;
}

int find(char key[])
{
	int hashKey = getHash(key);
	node* head = &htable[hashKey];
	while (head->next)
	{
		if (strcompare(head->next->name, key) == 0)
		{
			return head->next->data;
		}
		head = head->next;
	}
}

void add(char key[], int data) //그냥 삽입할 때 정렬하는 것 보다 head 앞에 삽입하는게 더 나은듯.. 나중에 탐색 고려해도
{
	int hashKey = getHash(key);
	node* head = &htable[hashKey];
	node* np = alloc(data, key, head->next);
	head->next = np;
}
