#ifndef NULL
#define NULL 0
#endif
#define MAXUID 1010
#define MAXPID 100010
#define MAXTIME 100010

struct Node
{
    int cnt;
    int arr[11];
};

struct Follow
{
    int cnt;
    int follower[1001];
};

struct hash
{
    int pid;
    int time;
}buf[MAXTIME],*htble[2][101];

//1000개 그냥 링크드리스트..?



Node tree[2][MAXUID][101];
int timeToValue[MAXPID];
int pidToTime[MAXPID];
int pidToUid[MAXPID];
int likey[MAXPID];
Follow followee[MAXUID];







void init() {
}

void makePost(int uid, int pid, int timeStamp) {

    timeToValue[timeStamp] = pid;
    pidToTime[pid] = timeStamp;
    pidToUid[pid] = uid;
}

void like(int pid) {

    likey[pid]++;

}

void follow(int sid, int tid) {

    int cnt = followee[sid].cnt;
    followee[sid].follower[cnt] = tid;
    followee[sid].cnt++;
}

int getFeed(int uid, int timeStamp, int result[]) {

    for (int i = 0;i < followee[uid].cnt;i++)
    {
        for (int j = 0;j < followee[uid].follower[i];j++)
        {

        }
    }


    return 1;
}
