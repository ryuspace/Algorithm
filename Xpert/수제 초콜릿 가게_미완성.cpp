#define NULL 0
#define MAXORDER 20001
#define MAXMOLD 101
#define MAXSHAPE 1001

struct Order
{
    int shapeId;
    int tickLater;
};

struct PriorityQueue
{
    Order queue[MAXORDER];
    
}q;



struct Mold
{
    int moldId;
    int shapeCnt;
    int canShape[MAXSHAPE];
    Mold* next;
    Mold* alloc(int vmoldId, int vshapeCnt, int vcanShape[],Mold *vnext)
    {
        moldId = vmoldId;
        shapeCnt = vshapeCnt;
        for (int i = 0; i < vshapeCnt; i++)
        {
            canShape[vcanShape[i]] = 1;
        }
        next = vnext;
        return this;
    }
}buf[MAXSHAPE],shapeTable[MAXSHAPE];
//최대 10개의 모양인데 100번 호출 가능하니깐..
int tmpIdx;

int tickCurrent;

int allOrder[MAXSHAPE];
extern void makeChoco(int moldID);

void initUser()
{
    tmpIdx = 0;
    tickCurrent = 0;
    for (int i = 0; i < MAXSHAPE; i++)
    {
        for (int j = 0; j < MAXSHAPE; j++)
        {
            buf[i].canShape[j] = 0;
        }
        buf[i].next = NULL;
        allOrder[i] = 0;
    }
}

void addChocoMold(int moldID, int shapeN, int shapeIDList[])
{
    for (int i = 0; i < shapeN; i++)
    {
        shapeTable[shapeIDList[i]].next = buf[tmpIdx++].alloc(moldID, shapeN, shapeIDList, shapeTable[shapeIDList[i]].next);
    }
}

void orderChoco(int shapeID, int tickLater)
{
    q.push({ shapeID,tickCurrent+tickLater });
    allOrder[shapeID]++;
}

int howRemainShapeID(int shapeID)
{
    return allOrder[shapeID];
}



void newTick()
{
    tickCurrent++;

    int needChoco[20001];
    int cnt = 0;

    while (!q.Empty() && q.front().tickLater == tickCurrent)
    {
        q.pop();
        needChoco[cnt++] = q.front().shapeId;
    }
    


    for (int i = 0; i < cnt; i++)
    {

        if (needChoco[i] == -1)
            continue;
        Mold* p = shapeTable[needChoco[i]].next;

        Mold* here=NULL;

        int maxOrder = -1;
        int minMoldId = -1;

        for (; p; p = p->next)
        {
            int order = 0;
            for (int r = i; r < cnt; r++)
            {
                if (needChoco[r] == -1)
                    continue;

                if (p->canShape[needChoco[r]] == 1)
                {
                    order++;
                }

            }
            if (order > maxOrder)
            {
                maxOrder = order;
                minMoldId = p->moldId;
                here = p;
            }
            else if (order == maxOrder)
            {
                if (p->moldId < minMoldId);
                {
                    maxOrder = order;
                    minMoldId = p->moldId;
                    here = p;
                }
            }
        }

        if (maxOrder == -1)
            continue;
        for (int r = i; r < cnt; r++)
        {
            if (needChoco[r] == -1)
                continue;
            if (here->canShape[needChoco[r]] == 1)
            {
                allOrder[needChoco[r]]--;
                needChoco[r] = -1;
            }
        }
        makeChoco(minMoldId);
    }
}
