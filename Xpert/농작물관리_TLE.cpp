#include <stdio.h>
#define MAXR 150
#define MAXC 150
#define MAXH MAXR*MAXC // **여유공간 더 잡아야한다
#define MAXNAME 10

struct fruit
{
	int root;
	int px, py;
	int id;
	int cnt;
};

struct allFruit
{
	char *name=NULL;
	int cnt;
	int cell;
};

struct informId
{
	int id;
	char *name=NULL;
	struct informId *next;
};


informId findName[MAXH + 10];
informId tmpNode[MAXH + 10];
int tmpIdx;
int ID = 1;
fruit arr[MAXR + 10][MAXC + 10];
allFruit allFruitInform[MAXNAME + 10];//아이디로 모든 과일 정보 **배열크기 MAXH+10;

int getHash(char *name)
{
	int code = 5381;
	
	for (int i = 0; name[i]; i++)
	{
		code = (code * 33 + name[i]) % (MAXH + 10);
	}
	return code;
}

int strcompare(char *a, char *b)
{
	int i;
	for (i = 0; (a[i] == b[i]) && a[i] && b[i]; i++);
	return a[i] - b[i];
}

void strcopy(char *a, char *b)
{
	while (*a++ = *b++);
}

void init(int Row, int Col)
{
	tmpIdx = 0;
	ID = 1;
	for (int i = 1; i <= Row; i++) {
		for (int j = 1; j <= Col; j++)
		{
			arr[i][j].cnt = 1;
			arr[i][j].id = 0;
			arr[i][j].px = i;
			arr[i][j].py = j;
			arr[i][j].root = 1;
			allFruitInform[0].cell++;
			allFruitInform[0].cnt++;
		}
	}

	for (int i = 0; i < MAXH + 10; i++)
	{
		allFruitInform[i].name = NULL;
	}

	for (int i = 0; i < MAXH + 10; i++)
	{
		findName[i].next = NULL;
		findName[i].id = 0;
	}
}

informId *myalloc(int id, char *name, informId *next)
{
	informId *np = &tmpNode[tmpIdx++];
	np->id = id;
	np->name = name;
	np->next = next;
	return np;
}

int giveMeMyId(char *name) 
{
	int key = getHash(name);

	informId *head = &findName[key];
	
	while (head->next)
	{
		if (strcompare(head->next->name, name) == 0)
		{
			return head->next->id;
		}
		else if (strcompare(head->next->name, name) > 0)
			break;
		head = head->next;
	}

	informId *np = myalloc(ID, name, head->next);

	np->next = head->next;
	head->next = np;

	allFruitInform[ID].name = name;
	ID++;

	return ID - 1;
}


void setFarm(int row, int col, char crop[])
{
	int myRoot = arr[row][col].root;
	int myRow = row;
	int myCol = col;
	while (myRoot == 0) 
	{
		myRow = arr[myRow][myCol].px;
		myCol = arr[myRow][myCol].py;
		myRoot = arr[myRow][myCol].root;
	}//*myRow가 134번째 줄에서 바뀌니깐 135번쨰 줄부터 엉뚱한 곳이 들어간다. 변수를 새로 선언해서 미리 myRow와 myCol을 담아두자

	int prevId = arr[myRow][myCol].id;
	allFruitInform[prevId].cnt -= arr[myRow][myCol].cnt;
	allFruitInform[prevId].cell--;

	int newId = giveMeMyId(crop);
	arr[myRow][myCol].id = newId;
	allFruitInform[newId].cnt += arr[myRow][myCol].cnt;
	allFruitInform[newId].cell++;

	arr[row][col].px = myRow;
	arr[row][col].py = myCol;
}

void getCrop(int row, int col, char crop[])
{

	int myRoot = arr[row][col].root;
	int myRow = row;
	int myCol = col;
	while (myRoot == 0)
	{
		myRow = arr[myRow][myCol].px;
		myCol = arr[myRow][myCol].py;
		myRoot = arr[myRow][myCol].root;
	}

	if (allFruitInform[arr[myRow][myCol].id].name != NULL)
		strcopy(crop, allFruitInform[arr[myRow][myCol].id].name);
	else
		crop[0] = '\0';

}

void mergeCell(int row1, int col1, int row2, int col2, int sw)
{
	int myRoot1 = arr[row1][col1].root;
	int myRow1 = row1;
	int myCol1 = col1;
	while (myRoot1 == 0)
	{
		myRow1 = arr[myRow1][myCol1].px;
		myCol1 = arr[myRow1][myCol1].py;
		myRoot1 = arr[myRow1][myCol1].root;
	}

	int myRoot2 = arr[row2][col2].root;
	int myRow2 = row2;
	int myCol2 = col2;
	while (myRoot2 == 0)
	{
		myRow2 = arr[myRow2][myCol2].px;
		myCol2 = arr[myRow2][myCol2].py;
		myRoot2 = arr[myRow2][myCol2].root;
	}

	int myId1 = arr[myRow1][myCol1].id;
	int myId2 = arr[myRow2][myCol2].id;

	if (sw == 1)
	{
		//전체부터 갱신
		allFruitInform[myId2].cell--;
		allFruitInform[myId2].cnt -= arr[myRow2][myCol2].cnt;

		allFruitInform[myId1].cnt += arr[myRow2][myCol2].cnt;

		arr[myRow1][myCol1].cnt += arr[myRow2][myCol2].cnt;
		arr[myRow2][myCol2].cnt = 0;

		arr[myRow2][myCol2].root = 0;
		arr[myRow2][myCol2].id = 0;
		arr[myRow2][myCol2].px = myRow1;
		arr[myRow2][myCol2].py = myCol1;
	}
	else
	{
		allFruitInform[myId1].cell--;
		allFruitInform[myId1].cnt -= arr[myRow1][myCol1].cnt;

		allFruitInform[myId2].cnt += arr[myRow1][myCol1].cnt;

		arr[myRow2][myCol2].cnt += arr[myRow1][myCol1].cnt;
		arr[myRow1][myCol1].cnt = 0;

		arr[myRow1][myCol1].root = 0;
		arr[myRow1][myCol1].id = 0;
		arr[myRow1][myCol1].px = myRow2;
		arr[myRow1][myCol1].py = myCol2;
	}
}

int cntCell(char crop[])
{
	int myId = giveMeMyId(crop);
	return allFruitInform[myId].cell;
}

int cntArea(char crop[])
{
	int myId = giveMeMyId(crop);
	return allFruitInform[myId].cnt;
}
