/// user.cpp
#ifndef NULL
#define NULL 0
#endif
#define MAXUID 1010
#define MAXPID 100010
#define MAXTIME 100010


struct Node
{
    int uid;
    int pid;
    int time;
    Node* next;
    Node* alloc(int vuid, int vpid, int vtime, Node *vnext)
    {
        uid = vuid;
        pid = vpid;
        time = vtime;
        next = vnext;
        return this;
    }
}buf[MAXPID],*htable[MAXUID],info[MAXPID];
Node *continuePtr[MAXUID];
int likey[MAXPID];
int tmpIdx;

struct User
{
    int cnt;
    int follower[MAXUID];
}user[MAXUID];

void init() {

    tmpIdx = 0;

    for (int i = 0;i < MAXUID;i++)
    {
        user[i].follower[user[i].cnt++] = i;
        htable[i] = NULL;
    }
    for (int i = 0;i < MAXPID;i++)
    {
        likey[i] = 0;
    }
}

void makePost(int uid, int pid, int timeStamp) {

    htable[uid] = buf[tmpIdx++].alloc(uid, pid, timeStamp, htable[uid]);
    info[pid].pid = pid;
    info[pid].time = timeStamp;
    info[pid].uid = uid;
}

void like(int pid) {
    likey[pid]++;
}

void follow(int sid, int tid) {
    user[sid].follower[user[sid].cnt++] = tid;
}

int findMe(int idx,int me,int timeStamp,int res[])
{
    Node* p = htable[me];
    int r=idx;
    for (;p;p = p->next)
    {
        if (p->time < timeStamp - 1000)
            break;

        r = idx;
        for (;r > 0;r--)
        {
            if (likey[p->pid] > likey[res[r - 1]])
            {
                res[r] = res[r - 1];
            }
            else if (likey[p->pid] == likey[res[r - 1]])
            {
                if (p->time > info[res[r - 1]].time)
                {
                    res[r] = res[r - 1];
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        res[r] = p->pid;
        if (r < 10)
            r++;
    }

    continuePtr[me] = p;
    return r;
}
void findLeft(int me)
{

}
int getFeed(int uid, int timeStamp, int result[]) {


    int res[12] = { 0, };
    for (int i = 0;i < user[uid].cnt;i++)
    {
        int you = user[uid].follower[i];
        
    }
    return 1;
}
