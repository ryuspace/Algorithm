#include <stdio.h>
#define NULL 0
#define MAX_N			5
#define MAXM 110
#define MAXTYPE 6
#define MAX_NAME_LEN	7
#define MAX_TAG_LEN		4
#define MAXNAMECNT 50010
#define MAXTAGCNT 510
int m;

void mstrcpy(char dst[], const char src[]) {
	int c = 0;
	while ((dst[c] = src[c]) != '\0') ++c;
}

int mstrcmp(const char str1[], const char str2[]) {
	int c = 0;
	while (str1[c] != '\0' && str1[c] == str2[c]) ++c;
	return str1[c] - str2[c];
}

struct Info
{
	int nameKey;
	int section;
	int mTypeNum;
	int mTypesKey[MAXTYPE];
	int flag;
};

struct Name
{
	char name[MAX_NAME_LEN];
	int idx;
	Name *prev;
	Name *next;
	Name * alloc(char vname[], int vidx, Name *vprev,Name *vnext)
	{
		mstrcpy(name, vname);
		idx = vidx;
		prev = vprev;
		next = vnext;
		return this;
	}
	void pop()
	{
		if (prev)
		{
			prev->next = next;
		}
		if (next)
		{
			next->prev = prev;
		}
	}

}bufName[MAXNAMECNT], nameTble[MAXNAMECNT];

struct Tag
{
	char tag[MAX_TAG_LEN];
	int idx;

	Tag *prev;
	Tag *next;
	Tag *alloc(char vtag[], int vidx, Tag *vprev,Tag *vnext)
	{
		mstrcpy(tag, vtag);
		idx = vidx;
		prev = vprev;
		next = vnext;
		return this;
	}
	void pop()
	{
		if (prev)
		{
			prev->next = next;
		}
		if (next)
		{
			next->prev = prev;
		}
	}
}bufTag[MAXTAGCNT], tagTble[MAXTAGCNT];

struct Map
{
	int nameIdx;
	Map *prev;
	Map *next;
	Map *alloc(int vnameIdx, Map *vprev,Map *vnext)
	{
		nameIdx = vnameIdx;
		prev = vprev;
		next = vnext;
		return this;
	}
	void pop()
	{
		if (prev)
		{
			prev->next = next;
		}
		if (next)
		{
			next->prev = prev;
		}
	}
}bufMap[MAXM*MAXTAGCNT*4],mapTble[MAXM*2][MAXTAGCNT*2];

int tmpNameIdx;
int allNameIdx;

int tmpTagIdx;
int allTagIdx;

int tmpMapIdx;

Info Book[50010];

int getNameKey(char name[])
{
	int code = 5381;
	for (int i = 0; name[i]; i++)
	{
		code = (code * 33 + name[i]) % MAXNAMECNT;
	}
	return code;
}

int getTagKey(char name[])
{
	int code = 5381;
	for (int i = 0; name[i]; i++)
	{
		code = (code * 33 + name[i]) % MAXTAGCNT;
	}
	return code;
}

int findNameIdx(char name[],int key)
{
	Name *p = nameTble[key].next;

	for (; p; p = p->next)
	{
		if (mstrcmp(p->name, name) == 0)
		{
			return p->idx;
		}
	}
	nameTble[key].next = bufName[tmpNameIdx++].alloc(name, ++allNameIdx, &nameTble[key], nameTble[key].next);
	return allNameIdx;
}

int findTagIdx(char tag[],int key)
{
	Tag *p = tagTble[key].next;

	for (; p; p = p->next)
	{
		if (mstrcmp(p->tag, tag) == 0)
		{
			return p->idx;
		}
	}
	tagTble[key].next = bufTag[tmpTagIdx++].alloc(tag, ++allTagIdx, &tagTble[key], tagTble[key].next);
	return allTagIdx;
}

void init(int M)
{
	m = M;
	tmpNameIdx = 0;
	allNameIdx = 0;

	tmpTagIdx = 0;
	allTagIdx = 0;

	tmpMapIdx = 0;
}

void add(char mName[MAX_NAME_LEN], int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	int nameKey = getNameKey(mName);
	int nameIdx = findNameIdx(mName,nameKey);
	Book[nameIdx].nameKey = nameKey;
	for (int i = 0; i < mTypeNum; i++)
	{
		int tagKey = getTagKey(mTypes[i]);
		int tagIdx = findTagIdx(mTypes[i], tagKey);
		Book[nameIdx].mTypeNum = mTypeNum;
		Book[nameIdx].mTypesKey[i] = tagKey;
		mapTble[mSection][tagIdx].next = bufMap[tmpMapIdx++].alloc(allNameIdx, &mapTble[mSection][tagIdx], mapTble[mSection][tagIdx].next);
	}
	Book[nameIdx].section = mSection;
}

int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo)
{
	int tagKey = getTagKey(mType);
	int tagIdx = findTagIdx(mType,tagKey);
	Map *p = mapTble[mFrom][tagIdx].next;
	int cnt = 0;

	for (; p; p = p->next)
	{
		int nameIdx = p->nameIdx;
		p->pop();
		mapTble[mTo][tagIdx].next = bufMap[tmpMapIdx++].alloc(nameIdx, &mapTble[mTo][tagIdx], mapTble[mTo][tagIdx].next);
		Book[nameIdx].section = mTo;
		cnt++;
	}

	return cnt;
}

void moveName(char mName[MAX_NAME_LEN], int mSection)
{
	int nameKey = getNameKey(mName);
	int nameIdx = findNameIdx(mName, nameKey);
	for (int i = 0; i < Book[nameIdx].mTypeNum; i++)
	{
		Map *p = mapTble[Book[nameIdx].section][Book[nameIdx].mTypesKey[i]].next;

		for (; p; p = p->next)
		{
			if (p->nameIdx == nameIdx)
			{
				p->pop();
				mapTble[mSection][Book[nameIdx].mTypesKey[i]].next = p->alloc(nameIdx, &mapTble[mSection][Book[nameKey].mTypesKey[i]], mapTble[mSection][Book[nameKey].mTypesKey[i]].next);
				break;
			}
		}
	}
}

void deleteName(char mName[MAX_NAME_LEN])
{
	int nameKey = getNameKey(mName);
	int nameIdx = findNameIdx(mName, nameKey);
	for (int i = 0; i < Book[nameIdx].mTypeNum; i++)
	{
		Map *p = mapTble[Book[nameIdx].section][Book[nameIdx].mTypesKey[i]].next;

		for (; p; p = p->next)
		{
			if (p->nameIdx == nameIdx)
			{
				p->pop();
				break;
			}
		}
	}
}

int countBook(int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	int cnt = 0;
	for (int i = 0; i < mTypeNum; i++)
	{
		int tagKey = getTagKey(mTypes[i]);
		Map *p = mapTble[mSection][tagKey].next;
		for (; p; p = p->next)
		{
			if (Book[p->nameIdx].flag == 0)
			{
				cnt++;
				Book[p->nameIdx].flag = 1;
			}
		}
	}

	for (int i = 0; i < mTypeNum; i++)
	{
		int tagKey = getTagKey(mTypes[i]);
		Map *p = mapTble[mSection][tagKey].next;
		for (; p; p = p->next)
		{
			Book[p->nameIdx].flag = 0;
		}
	}
	return cnt;
}
