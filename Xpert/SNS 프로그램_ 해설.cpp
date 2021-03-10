#ifndef NULL
#define NULL 0 
#endif
 
#define MAX_UID ((int)1e3+1)
#define MAX_PID ((int)1e5+1) 
#define MAX_TIME ((int)1e5+1) 
int current_time;//현재시각
int like_cnt[MAX_PID];//pid별 좋아요 개수 세는 용
typedef struct post
{
    int pid,  time_stamp;
    struct post *next;
}POST;
POST arr_post[MAX_PID];
typedef struct user
{
    int follow_cnt;//팔로우한 인원수
    int follow_id[MAX_UID];//팔로우한 id 저장
    POST *post_head;
}USER;
USER arr_user[MAX_UID];
 
void init() {
    int i;
    current_time = 0;
    for (i = 0; i < MAX_PID; i++)like_cnt[i] = 0;
    for (i = 0; i < MAX_UID; i++)
    {
        arr_user[i].follow_cnt = 0;
        arr_user[i].post_head = NULL;
    }
 
}
 
void makePost(int uid,  int pid,  int timeStamp) {
    current_time = timeStamp;
    arr_post[pid].pid = pid;
    arr_post[pid].time_stamp = timeStamp;
    arr_post[pid].next = arr_user[uid].post_head;
    arr_user[uid].post_head = &arr_post[pid];
}
 
void like(int pid) {
    like_cnt[pid]++;
}
 
void follow(int sid,  int tid) {
    arr_user[sid].follow_id[arr_user[sid].follow_cnt++] = tid;
}
POST * cotinue_ptr[MAX_UID];
 
int search_remain_feed(int uid,  int cnt,  int record[])
{
    POST *p = cotinue_ptr[uid];
    int idx,  cur_pid;
    while (p)
    {
        idx = cnt - 1;
        for (idx = cnt - 1; idx >= 0; idx--)
        {
            cur_pid = record[idx];
            if (arr_post[cur_pid].time_stamp >= p->time_stamp) break;
            record[idx + 1] = cur_pid;
        }
        record[++idx] = p->pid;
        if (++cnt > 10)
        {
            cnt = 10;
            if ((p->next != NULL) && (p->next->time_stamp < arr_post[record[cnt - 1]].time_stamp))break;
        }
        p = p->next;
    }
    return cnt;
}
 
int search_feed(int uid,  int etime,  int cnt,  int record[])
{
    POST* p = arr_user[uid].post_head;
    int idx,  cur_pid;
    while ((p != NULL) && (p->time_stamp >= etime))
    {
        for (idx = cnt - 1; idx >= 0; idx--)
        {
            cur_pid = record[idx];
            if (like_cnt[cur_pid] < like_cnt[p->pid])//좋아요 수가 더 많음
            {
                record[idx + 1] = cur_pid;
            }
            else if (like_cnt[cur_pid] > like_cnt[p->pid])break;
            else if (arr_post[cur_pid].time_stamp < p->time_stamp)
            {
                record[idx + 1] = cur_pid;
            }
            else break;
        }
 
        record[++idx] = p->pid;
        if (++cnt > 10) cnt = 10;
        p = p->next;
    }
    cotinue_ptr[uid] = p;
    return cnt;
}
int getFeed(int uid,  int timeStamp,  int result[]) {
    int record[12] = { 0,  };
    int rec_cnt = 0;
    int etime,  i;
 
    current_time = timeStamp;
    etime = current_time - 1000;
    rec_cnt = search_feed(uid,  etime,  0,  record);
    for (i = 0; i < arr_user[uid].follow_cnt; i++)
    {
        rec_cnt = search_feed(arr_user[uid].follow_id[i],  etime,  rec_cnt,  record);
    }
    if (rec_cnt < 10)
    {
        rec_cnt = search_remain_feed(uid,  rec_cnt,  record);
        for (i = 0; i < arr_user[uid].follow_cnt; i++)
        {
            rec_cnt = search_remain_feed(arr_user[uid].follow_id[i],  rec_cnt,  record);
        }
    }
    for (i = 0; i < rec_cnt; i++) result[i] = record[i];
    if (rec_cnt == 0) result[0] = rec_cnt++;
    return rec_cnt;
}
 
