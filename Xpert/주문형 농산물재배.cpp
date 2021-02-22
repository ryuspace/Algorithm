#ifndef NULL
#define NULL 0
#endif
#define MAXP 10000
#define MAXS 1000
#define LOTX 100
#define LOTY 100000
extern int add_lot();
extern void assign(int lot_num, int s, int size, int member_id);
extern void back(int lot_num, int s, int size);
extern void grow(int lot_num, int s, int size, int crop);

struct node
{
	int r, c;
};

node remain[LOTX*LOTY+10];
node info[MAXP+10][MAXS+ 10];
int remainCnt;

void init_member()
{
	remainCnt = 0;
}
//빈 공간을 하나로 모아놓는게 포인트
void assign_member(int member_id, int size)
{

	if (remainCnt < size)
	{
		int num = add_lot();
		for (int i = 0; i < LOTY; i++)
		{
			remain[remainCnt].r = num;
			remain[remainCnt].c = i;
			remainCnt++;
		}
		//빈 롯드가 받아야 할 롯드보다 작으면 일단 새 롯드 받고
	}

	for (int i = 0; i < size; i++)
	{
		node k = remain[--remainCnt];
		assign(k.r, k.c, 1, member_id);
		info[member_id][i] = k;
	}

	info[member_id][size].r = 0;
}

void back_member(int member_id)
{
	for (int i = 0; info[member_id][i].r != 0; i++)
	{
		back(info[member_id][i].r, info[member_id][i].c, 1);
		remain[remainCnt].r = info[member_id][i].r;
		remain[remainCnt].c = info[member_id][i].c;
		remainCnt++;
		info[member_id][i].r = 0;
		info[member_id][i].c = 0;
	}
}

void grow_member(int member_id, int crop)
{
	for (int i = 0; info[member_id][i].r != 0; i++)
	{
		grow(info[member_id][i].r, info[member_id][i].c, 1, crop);
	}
}
