#define NULL 0;
int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

struct inform
{
    int bell_id, orderTime, nanido;
    struct inform* next;
};

int n;
int hardListCopy[51];
int bell_id_cnt[100010];
int individualCnt[100010][51];


int gijun(inform a, inform b)
{
    if (a.nanido + a.orderTime < b.nanido + b.orderTime)
        return 1;
    else if (a.nanido + a.orderTime == b.nanido + b.orderTime)
    {
        if (a.orderTime < b.orderTime)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

void swap(inform& a, inform& b)
{
    inform t = a;
    a = b;
    b = t;
}
struct PriorityQueue {
    inform heap[100010];
    int hn;

    int(*comp)(inform, inform);
    void init()
    {
        hn = 0;
        comp = gijun;
    }

    void push(inform a)
    {
        heap[++hn] = a;

        for (register int c = hn; c > 1; c /= 2)
        {
            if (comp(heap[c], heap[c / 2]))
                swap(heap[c], heap[c / 2]);
            else
                break;
        }

    }

    void pop()
    {
        swap(heap[1], heap[hn--]);

        for (register int c = 2; c <= hn; c *= 2)
        {
            if (c < hn && comp(heap[c + 1], heap[c]))
            {
                c++;
            }
            if (comp(heap[c], heap[c / 2]))
                swap(heap[c], heap[c / 2]);
            else
                break;
        }
        //주문 완료, 유효한 주문이 아닌 경우에도 pop해주자
    }

    inform top()
    {
        return heap[1];
    }

}orderQueue[61];




void init(int N, int hardList[]) {
    n = N;
    for (register int i = 0; i < 51; ++i)
    {
        hardListCopy[i] = hardList[i];
        orderQueue[i].init();
    }

    for (register int i = 0; i < 100010; ++i)
    {
        bell_id_cnt[i] = 0;
        for (register int j = 0; j < 51; ++j)
        {
            individualCnt[i][j] = 0;
        }
    }


}

void order(int orderTime, int cnt, int kindList[], int bell_id) {

    int maxi = 0;
    for (register int i = 0; i < cnt; ++i)
    {
        maxi = max(maxi, hardListCopy[kindList[i]]);
    }
    for (register int i = 0; i < cnt; ++i)
    {
        orderQueue[kindList[i]].push({ bell_id,orderTime,maxi });
        individualCnt[bell_id][kindList[i]]++;
    }
    bell_id_cnt[bell_id] += cnt;
}

int supply(int kind) {

    inform deleteInfo = orderQueue[kind].top();
    while (individualCnt[deleteInfo.bell_id][kind] == 0)
    {
        orderQueue[kind].pop();
        deleteInfo = orderQueue[kind].top();
    }//유효하지 않은 주문 싹다 밴


    orderQueue[kind].pop();
    individualCnt[deleteInfo.bell_id][kind]--;
    bell_id_cnt[deleteInfo.bell_id]--;

    if (bell_id_cnt[deleteInfo.bell_id] == 0)
    {
        return deleteInfo.bell_id;
    }
    return 0;

}

int cancel(int bell_id, int kind) {
    
    if (individualCnt[bell_id][kind] >= 1)
    {
        individualCnt[bell_id][kind]--;
        bell_id_cnt[bell_id]--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int ask(int bell_id) {
    return bell_id_cnt[bell_id];
}
