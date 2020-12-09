#include <stdio.h>
#define MAXR 150
#define MAXC 150
#define MAXN 10

int strcompare(char *a, char *b)
{
	register int i;
	for (i = 0; a[i] && b[i] && (a[i] == b[i]); i++);
	return a[i] - b[i];
}

void strcopy(char *dst, char *src)
{
	while (*dst++ = *src++);
}

struct fruit
{
	int id;
	char *name;
	struct fruit *next;
};
struct realFruit //총 갯수
{
	char *name;
	int cell;
	int cnt;
};

struct individualFruit
{
	int id;
	int cnt;
};
fruit findId[MAXN + 10];
fruit tmpNode[MAXN + 10];
realFruit informFruit[MAXN + 10];
individualFruit needMerge[MAXR + 10][MAXC + 10];

int tmpIdx;
int ID = 1;

void init(int Row, int Col)
{
	ID = 1;
	tmpIdx = 0;
	for (int i = 0; i < MAXR + 10; i++)
	{
		for (int j = 0; j < MAXC + 10; j++)
		{
			needMerge[i][j].cnt = 1;
			needMerge[i][j].id = 0;
		}
	}
	
	//밭 초기화
}

int getHash(char *name)
{
	int code = 5381;
	for (int i = 0; name[i]; i++)
	{
		code = (code * 33 + name[i]) % (MAXN + 10);
	}
	return code;
}

int giveMeMyId(char *name)
{
	int hashKey = getHash(name);
	fruit*head = &findId[hashKey];
	while (head->next)
	{
		if (strcompare(head->next->name, name) == 0)
		{
			return head->next->id;
		}
		head = head->next;
	}
	return 0;
}


fruit *myalloc(char *name,int id, fruit *next)
{
	fruit* np = &tmpNode[tmpIdx++];
	np->name = name;
	np->id = id;
	np->next = next;

	return np;
}

void setFarm(int row, int col, char crop[])
{
	int hashKey = getHash(crop);
	fruit * head = &findId[hashKey];
	while (head->next)
	{
		if (strcompare(head->next->name, crop) == 0)
		{
			int myId = head->next->id;
			informFruit[myId].cnt += needMerge[row][col].cnt;
			informFruit[myId].cell++;

			needMerge[row][col].id = myId;
			needMerge[row][col].cnt = 1;
			
			//printf("흠 %s %d %d\n", informFruit[myId].name, informFruit[myId].cnt, informFruit[myId].cell);
			return;
		}
		else if (strcompare(head->next->name, crop) > 0)
			break;
		head = head->next;
	}

	fruit *tmp = myalloc(crop,ID, head->next);

	head->next = tmp;


	informFruit[ID].cell++;
	informFruit[ID].cnt += needMerge[row][col].cnt;;
	informFruit[ID].name = crop;

	needMerge[row][col].id = ID;
	needMerge[row][col].cnt = 1;

	//printf("%s %d %d\n", informFruit[ID].name, informFruit[ID].cnt, informFruit[ID].cell);
	ID++;
}

void getCrop(int row, int col, char crop[])
{

	if (needMerge[row][col].id != 0)
	{
		strcopy(crop, informFruit[needMerge[row][col].id].name);
		//printf("뀨%s을 뽑았당\n", crop);
	}
		
}

void mergeCell(int row1, int col1, int row2, int col2, int sw)
{
	if (sw == 1)
	{
		int id1 = needMerge[row1][col1].id;
		int id2 = needMerge[row2][col2].id;
	
		int cnt1 = needMerge[row1][col1].cnt;
		int cnt2 = needMerge[row2][col2].cnt;

		informFruit[id1].cnt += cnt2;
		informFruit[id2].cell--;
		informFruit[id2].cnt -= cnt2;

		needMerge[row2][col2].id = needMerge[row1][col1].id;
		int sum = needMerge[row1][col1].cnt + needMerge[row2][col2].cnt;
		needMerge[row1][col1].cnt = needMerge[row2][col2].cnt = sum;

	}
	else
	{
		int id1 = needMerge[row1][col1].id;
		int id2 = needMerge[row2][col2].id;

		int cnt1 = needMerge[row1][col1].cnt;
		int cnt2 = needMerge[row2][col2].cnt;

		informFruit[id2].cnt += cnt1;
		informFruit[id1].cell--;
		informFruit[id1].cnt -= cnt1;


		needMerge[row1][col1].id = needMerge[row2][col2].id;
		int sum = needMerge[row1][col1].cnt + needMerge[row2][col2].cnt;
		needMerge[row1][col1].cnt = needMerge[row2][col2].cnt = sum;
	}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			printf("%d ", needMerge[i][j].id);
		}
		printf("\n");
	}
	printf("\n");
	getchar();
}

int cntCell(char crop[])
{
	int myId = giveMeMyId(crop);
	//printf("cntCell = %d\n", informFruit[myId].cell);
	return informFruit[myId].cell;
}

int cntArea(char crop[])
{
	int myId = giveMeMyId(crop);
	//printf("cntArea = %d\n", informFruit[myId].cnt);
	return informFruit[myId].cnt;
}
//
