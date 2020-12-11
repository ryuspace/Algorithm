 
#define NULL 0
#define MAXR 150
#define MAXC 150
#define MAXH 50000
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
    char name[12];
    int cnt;
    int cell;
};
  
struct informId
{
    int id;
    char name[12];
    struct informId *next;
};
  
  
informId findName[MAXH + 10];
informId tmpNode[MAXH + 10];
int tmpIdx;
int ID = 1;
fruit arr[MAXR + 10][MAXC + 10];
allFruit allFruitInform[MAXH + 10];//아이디로 모든 과일 정보
  
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
    for (int i = 0; i < MAXH + 10; i++)
    {
        findName[i].next = NULL;
    }
  
    for (int i = 0; i < MAXH + 10; i++)
    {
        allFruitInform[i].cell = 0;
        allFruitInform[i].cnt = 0;
    }
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
  
      
}
  
informId *myalloc(int id, char *name, informId *next)
{
    informId *np = &tmpNode[tmpIdx++];
    np->id = id;
    strcopy(np->name,name);
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
  
    strcopy(allFruitInform[ID].name,name);
    ID++;
  
    return ID - 1;
}
  
  
void setFarm(int myRow, int myCol, char crop[])
{
    int r, c;
    while (!arr[myRow][myCol].root)
    {
        r = arr[myRow][myCol].px, c = arr[myRow][myCol].py;
        myRow = r, myCol = c;
    }
  
  
    int prevId = arr[myRow][myCol].id;
    allFruitInform[prevId].cnt -= arr[myRow][myCol].cnt;
    allFruitInform[prevId].cell--;
  
    int newId = giveMeMyId(crop);
    arr[myRow][myCol].id = newId;
    allFruitInform[newId].cnt += arr[myRow][myCol].cnt;
    allFruitInform[newId].cell++;
}
  
void getCrop(int myRow, int myCol, char crop[])
{
    int r, c;
    while (!arr[myRow][myCol].root)
    {
        r = arr[myRow][myCol].px, c = arr[myRow][myCol].py;
        myRow = r, myCol = c;
    }
  
  
    strcopy(crop, allFruitInform[arr[myRow][myCol].id].name);
  
}
  
void mergeCell(int myRow1, int myCol1, int myRow2, int myCol2, int sw)
{
    int a, b;
    while (!arr[myRow1][myCol1].root)
    {
        a = arr[myRow1][myCol1].px, b = arr[myRow1][myCol1].py;
        myRow1 = a, myCol1 = b;
    }
  
  
    while (!arr[myRow2][myCol2].root)
    {
        a = arr[myRow2][myCol2].px, b = arr[myRow2][myCol2].py;
        myRow2 = a, myCol2 = b;
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
    //printf("%d cntCell\n", allFruitInform[myId].cell);
    return allFruitInform[myId].cell;
}
  
int cntArea(char crop[])
{
    int myId = giveMeMyId(crop);
    //printf("%d cntArea\n", allFruitInform[myId].cnt);
    return allFruitInform[myId].cnt;
}
