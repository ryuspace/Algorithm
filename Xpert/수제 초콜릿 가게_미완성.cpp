#define NULL 0
#define MAXORDER 20001
#define MAXMOLD 101
#define MAXSHAPE 1001

struct Order
{
    int shapeId;
    int tickLater;
    int currentTick;
};

int bigyo(Order a, Order b)
{
    if (a.tickLater < b.tickLater)
        return 1;
    else if (a.tickLater == b.tickLater)
    {
        if (a.currentTick < b.currentTick)
            return 1;
        return 0;
    }
    return 0;
}



void swap(Order& a, Order& b)
{
    Order tmp = a;
    a = b;
    b = tmp;
}

struct PriorityQueue
{
    Order heap[MAXORDER];
    int bn;
    int (*cmp)(Order, Order);

    void init()
    {
        bn = 0;
        cmp = bigyo;
    }

    void push(Order num)
    {
        heap[++bn] = num;
        for (int c = bn; c > 1; c /= 2)
        {
            if (cmp(heap[c], heap[c / 2]))
            {
                swap(heap[c], heap[c / 2]);
            }
            else
            {
                break;
            }
        }
    }

    void pop()
    {
        swap(heap[1], heap[bn--]);

        for (int c = 2; c <= bn; c *= 2)
        {
            if (c < bn && cmp(heap[c + 1], heap[c]))
            {
                c++;
            }
            if (cmp(heap[c], heap[c / 2]))
            {
                swap(heap[c], heap[c / 2]);
            }
            else
            {
                break;
            }
        }
    }

    Order top()
    {
        return heap[1];
    }

    int Empty()
    {
        if (bn == 0)
            return 1;
        return 0;
    }
}pq;



struct Mold
{
    int moldId;
    int shapeCnt;
    int canShape[11];
    Mold* next;
    Mold* alloc(int vmoldId, int vshapeCnt, int vcanShape[], Mold* vnext)
    {
        moldId = vmoldId;
        shapeCnt = vshapeCnt;
        for (int i = 0; i < vshapeCnt; i++)
        {
            canShape[i] = vcanShape[i];
        }
        next = vnext;
        return this;
    }
}buf[MAXSHAPE], shapeTable[MAXSHAPE];
//최대 10개의 모양인데 100번 호출 가능하니깐..
int tmpIdx;

int tickCurrent;

int allOrder[MAXSHAPE];
int alreadyMake[MAXSHAPE];
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
        alreadyMake[i] = 0;
    }
    pq.init();
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
    pq.push({ shapeID,tickCurrent + tickLater,tickCurrent });
    allOrder[shapeID]++;
}

int howRemainShapeID(int shapeID)
{
    return allOrder[shapeID];
}



void newTick()
{
    tickCurrent++;

    if (pq.Empty())
        return;
    if (pq.top().tickLater > tickCurrent)
        return;



    while (!pq.Empty() && pq.top().tickLater == tickCurrent)
    {
        
        Mold* p = shapeTable[pq.top().shapeId].next;
        
        if (p == NULL)
            return;
        pq.pop();
        Mold* here = NULL;

        int maxOrder = -1;
        int minMoldId = -1;

        for (; p; p = p->next)
        {

            int order = 0;

            for (int i = 0; i < p->shapeCnt; i++)
            {
                if (allOrder[p->canShape[i]] >= 1)
                    order++;
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
            return;

        for (int i = 0; i < here->shapeCnt; i++)
        {
            if (allOrder[here->canShape[i]] >= 1)
            {
                allOrder[here->canShape[i]]--;
                alreadyMake[here->canShape[i]]++;
            }

        }

        makeChoco(minMoldId);
        
    }    
}
//전체 힙 인덱스 힙으로 재구현 해보자
