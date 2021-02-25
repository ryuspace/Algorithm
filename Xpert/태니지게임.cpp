#ifndef NULL
#define NULL 0
#endif
#define MAXLEN (5)
#define MAXNAME 30010
#define MAXLOG 140010
#define MAXGYEJWA 100010
#define MAXGROUP 21

void strcopy(char *dst, char*src)
{
	while (*dst++ = *src++);
}
int strcmp(char *a, char *b)
{
	int i;
	for (i = 0; a[i] && (a[i] == b[i]); i++);
	return a[i] - b[i];
}

struct IDX
{
	char name[MAXLEN];
	int idxName;
	IDX *next;
	IDX *alloc(char vName[],int vidxName, IDX *vNext)
	{
		strcopy(name, vName);
		idxName = vidxName;
		next = vNext;
		return this;
	}
}bufName[MAXNAME],*htableName[MAXNAME];
int tmpName;
int IdxName;

struct Group
{
	char name[MAXLEN];
	int idxGroup;
	Group *next;
	Group *alloc(char vName[], int vidxGroup, Group *vNext)
	{
		strcopy(name, vName);
		idxGroup = vidxGroup;
		next = vNext;
		return this;
	}
}bufGroup[MAXGROUP],*htableGroup[MAXGROUP];
int tmpGroup;
int IdxGroup;

struct Log
{
	int tick;
	int gyejwa;
	int flag; //받음 1, 보냄 2 존재 3, 존재 X 0
	Log *next;
	Log *alloc(int vtick,int vgyejwa, int vflag,Log *vNext)
	{
		tick = vtick;
		gyejwa = vgyejwa;
		flag = vflag;
		next = vNext;
		return this;
	}
}bufLog[MAXLOG], * Logtble[MAXGROUP][MAXNAME];
int tmpLog;

struct node
{
	int idxName, idxGroup, money, flag; //여기서 flag는 삭제되었는지 정도 체크하기위해 삭제 0
};

node gyejwaInfo[MAXGYEJWA];

void userInit() {

	tmpName = IdxName = tmpGroup = IdxGroup = tmpLog = 0;
	for (int i = 0; i < MAXNAME; i++)
	{
		htableName[i] = NULL;
		for (int j = 0; j < MAXGROUP; j++)
		{
			Logtble[j][i] = NULL;
		}
	}

	for (int i = 0; i < MAXGROUP; i++)
	{
		htableGroup[i] = NULL;
	}

	for (int i = 0; i < MAXGYEJWA; i++)
	{
		gyejwaInfo[i].idxName = gyejwaInfo[i].idxGroup = gyejwaInfo[i].money = gyejwaInfo[i].flag = 0;
	}

}

int hashName(char name[])
{
	int code = 5381;
	for (int i = 0; name[i]; i++)
	{
		code = (code * 33 + name[i]) % MAXNAME;
	}
	return code;
}

int hashGroup(char name[])
{
	int code = 5381;
	for (int i = 0; name[i]; i++)
	{
		code = (code * 33 + name[i]) % MAXGROUP;
	}
	return code;
}



int findIdxName(char name[],int mode) //0이면 찾기 모드 그 외는 찾고 없으면 삽입모드
{

	int code = hashName(name);

	for (IDX *p = htableName[code]; p; p = p->next)
	{
		if (strcmp(p->name, name) == 0)
		{
			return p->idxName;
		}
	}
	if (mode == 0)
		return -1;
	htableName[code] = bufName[tmpName++].alloc(name,IdxName, htableName[code]);
	int tmp = IdxName;
	IdxName++;
	return tmp;
}

int findIdxGroup(char name[])
{
	int code = hashGroup(name);

	for (Group *p = htableGroup[code]; p; p = p->next)
	{
		if (strcmp(p->name, name) == 0)
		{
			return p->idxGroup;
		}
	}

	htableGroup[code] = bufGroup[tmpName++].alloc(name, IdxGroup, htableGroup[code]);
	int tmp = IdxGroup;
	IdxGroup++;
	return tmp;
}



void create(int tick, char userName[MAXLEN], char serverName[MAXLEN], int charID, int point) {


	int idxName = findIdxName(userName,1);
	int idxGroup = findIdxGroup(serverName);
	gyejwaInfo[charID].idxName = idxName;
	gyejwaInfo[charID].idxGroup = idxGroup;
	gyejwaInfo[charID].money = point;
	gyejwaInfo[charID].flag = 3;

	Logtble[idxGroup][idxName] = bufLog[tmpLog++].alloc(tick, charID, 3, Logtble[idxGroup][idxName]);
}

int destroy(int tick, int charID) {
	gyejwaInfo[charID].flag = 0;
	return gyejwaInfo[charID].money;
}

int numToNum(int tick, int giverID, int receiverID, int point) {

	if ((gyejwaInfo[giverID].flag == 0) || (gyejwaInfo[receiverID].flag == 0) ||
		(gyejwaInfo[giverID].money < point))
		return -1;

	gyejwaInfo[giverID].money -= point;
	
	Logtble[gyejwaInfo[giverID].idxGroup][gyejwaInfo[giverID].idxName] = bufLog[tmpLog++].alloc(tick,giverID, 2, Logtble[gyejwaInfo[giverID].idxGroup][gyejwaInfo[giverID].idxName]);

	gyejwaInfo[receiverID].money += point;

	Logtble[gyejwaInfo[receiverID].idxGroup][gyejwaInfo[receiverID].idxName] = bufLog[tmpLog++].alloc(tick, receiverID, 1, Logtble[gyejwaInfo[receiverID].idxGroup][gyejwaInfo[receiverID].idxName]);

	return gyejwaInfo[receiverID].money;
}


int numToName(int tick, int giverID, char recieverName[MAXLEN], int point) {

	int nameFlag = findIdxName(recieverName, 0);


	if ((gyejwaInfo[giverID].flag == 0 )|| (nameFlag == -1) ||
		(gyejwaInfo[giverID].money < point))
		return -1;

	int maxtick = 0;
	int flag = 0;
	int gyejwa = 0;
	for (int i = 0; i < IdxGroup; i++)
	{
		if (Logtble[i][nameFlag] == NULL)
			continue;
		Log * p = Logtble[i][nameFlag];

		while (gyejwaInfo[p->gyejwa].flag == 0)
		{
			p = p->next;
		}
	
		if (p->tick > maxtick)
		{
			maxtick = p->tick;
			gyejwa = p->gyejwa;
			flag = p->flag;
		}
		else if (p->tick == maxtick)
		{
			if (flag > p->flag)
			{
				maxtick = p->tick;
				gyejwa = p->gyejwa;
				flag = p->flag;
			}
		}
	}

	gyejwaInfo[giverID].money -= point;

	Logtble[gyejwaInfo[giverID].idxGroup][gyejwaInfo[giverID].idxName] = bufLog[tmpLog++].alloc(tick, giverID, 2, Logtble[gyejwaInfo[giverID].idxGroup][gyejwaInfo[giverID].idxName]);

	gyejwaInfo[gyejwa].money += point;

	Logtble[gyejwaInfo[gyejwa].idxGroup][gyejwaInfo[gyejwa].idxName] = bufLog[tmpLog++].alloc(tick, gyejwa, 1, Logtble[gyejwaInfo[gyejwa].idxGroup][gyejwaInfo[gyejwa].idxName]);

	return gyejwaInfo[gyejwa].money;
}

void payBonusPoint(int tick, char serverName[MAXLEN], int point) {

	int idxGroup = findIdxGroup(serverName);
	for (int i = 0; i < IdxName; i++)
	{
		if (Logtble[idxGroup][i] == NULL)
			continue;
		while (gyejwaInfo[Logtble[idxGroup][i]->gyejwa].flag == 0)
		{
			Logtble[idxGroup][i] = Logtble[idxGroup][i]->next;
		}

		int bonusgyejwa = Logtble[idxGroup][i]->gyejwa;
		gyejwaInfo[bonusgyejwa].money += point;
		Logtble[idxGroup][i] = bufLog[tmpLog++].alloc(tick, bonusgyejwa, 1, Logtble[idxGroup][i]);
	}
}
