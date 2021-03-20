#ifndef NULL
#define NULL 0
#endif // NULL
 
#define MAXTITLE 10001
#define MAXTITLELEN 21
 
#define MAXAUTHOR 501
#define MAXAUTHORLEN 11
 
#define MAXGENRE 101
#define MAXGENRELEN 11
 
#define MAXIDX MAXTITLE+MAXAUTHOR+MAXGENRE
 
int strcmp(const char* s, const char* t) {
    while (*s && *s == *t) ++s, ++t;
    return *s - *t;
}
 
int strlen(const char* s, int len = 0) {
    while (s[len]) ++len;
    return len;
}
 
void strcpy(char* dest, const char* src) {
    while ((*dest++ = *src++));
}
 
struct Book
{
    char title[MAXTITLELEN];
    char author[MAXAUTHORLEN];
    char genre[MAXGENRELEN];
    int loanCnt;
    int remainCnt;
    int idx;
 
}bookInfo[MAXTITLE];
 
 
struct Title
{
    char title[MAXTITLELEN];
    int idx;
    Title* next;
 
    Title* alloc(char vtitle[], int vidx, Title* vnext)
    {
        strcpy(title, vtitle);
        idx = vidx;
        next = vnext;
 
        return this;
    }
}bufTitle[MAXTITLE], titleTable[MAXTITLE];
 
int tmpTitle;
 
struct Author
{
    char author[MAXAUTHORLEN];
    int idx;
    Author* next;
 
    Author* alloc(char vauthor[], int vidx, Author* vnext)
    {
        strcpy(author, vauthor);
        idx = vidx;
        next = vnext;
        return this;
    }
}bufAuthor[MAXAUTHOR], authorTable[MAXAUTHOR];
 
int tmpAuthor;
 
struct Genre
{
    char genre[MAXGENRELEN];
    int idx;
    Genre* next;
 
    Genre* alloc(char vgenre[], int vidx, Genre* vnext)
    {
        strcpy(genre, vgenre);
        idx = vidx;
        next = vnext;
        return this;
    }
}bufGenre[MAXGENRE],genreTable[MAXGENRE];
 
int tmpGenre;
 
 
int tmpIdx;
 
 
int authorCnt[MAXIDX];
int genreCnt[MAXIDX];
int alreadyInput[MAXTITLE];
 
int getHashTitle(char title[]) 
{
    int code = 5381;
    for (int i = 0; title[i]; i++)
    {
        code = (code * 33 + title[i]) % MAXTITLE;
    }
    return code;
}
 
int getHashAuthor(char author[])
{
    int code = 5381;
    for (int i = 0; author[i]; i++)
    {
        code = (code * 33 + author[i]) % MAXAUTHOR;
    }
    return code;
}
 
int getHashGenre(char genre[])
{
    int code = 5381;
    for (int i = 0; genre[i]; i++)
    {
        code = (code * 33 + genre[i]) % MAXGENRE;
    }
    return code;
}
 
 
 
int findBookIdx(char title[],int mode)
{
 
    int titleKey = getHashTitle(title);
 
    Title* p = titleTable[titleKey].next;
 
    for (; p; p = p->next)
    {
        if (strcmp(title, p->title) == 0)
        {
            return p->idx;
        }
    }
     
    if (mode == 0)
    {
        return -1;
    }
    titleTable[titleKey].next = bufTitle[tmpTitle].alloc(title, tmpTitle, titleTable[titleKey].next);
    tmpTitle++;
    return tmpTitle - 1;
}
 
int findAuthorIdx(char author[])
{
    int key = getHashAuthor(author);
 
    Author* p = authorTable[key].next;
 
    for (; p; p = p->next)
    {
        if (strcmp(p->author, author) == 0)
            return p->idx;
    }
 
    authorTable[key].next = bufAuthor[tmpAuthor].alloc(author, tmpAuthor, authorTable[key].next);
    tmpAuthor++;
    return tmpAuthor - 1;
}
 
int findGenreIdx(char genre[])
{
    int key = getHashGenre(genre);
 
    Genre* p = genreTable[key].next;
 
    for (; p; p = p->next)
    {
        if (strcmp(p->genre, genre) == 0)
            return p->idx;
    }
 
    genreTable[key].next = bufGenre[tmpGenre].alloc(genre, tmpGenre, genreTable[key].next);
    tmpGenre++;
    return tmpGenre - 1;
}
 
 
int bigyo(int a, int b)
{
 
    if (bookInfo[a].loanCnt > bookInfo[b].loanCnt)
    {
        return 1;
    }
    else if (bookInfo[a].loanCnt == bookInfo[b].loanCnt)
    {
        if (strcmp(bookInfo[a].title, bookInfo[b].title) < 0)
            return 1;
        return 0;
    }
    return 0;
}
 
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
 
 
struct PriorityQueue
{
    int heap[MAXTITLE];
    int heapIdx[MAXTITLE];
    int bn;
    int (*cmp)(int, int);
     
    void init()
    {
        bn = 0;
        cmp = bigyo;
    }
 
    void push(int titleIdx)
    {
        heap[++bn] = titleIdx;
        heapIdx[titleIdx] = bn;
        for (int c = bn; c > 1; c /= 2)
        {
             
            if (cmp(heap[c], heap[c / 2]))
            {
                swap(heap[c], heap[c / 2]);
                swap(heapIdx[heap[c]], heapIdx[heap[c / 2]]);
            }
            else
            {
 
                break;
            }
        }
    }
 
    void pop()
    {
        swap(heap[1], heap[bn]);
        swap(heapIdx[heap[1]], heapIdx[heap[bn]]);
        bn--;
 
        for (int c = 2; c <= bn; c *= 2)
        {
            if (c < bn && cmp(heap[c + 1], heap[c]))
            {
                c++;
            }
 
            if (cmp(heap[c], heap[c / 2]))
            {
                swap(heap[c], heap[c / 2]);
                swap(heapIdx[heap[c]], heapIdx[heap[c / 2]]);
 
            }
            else
            {
                break;
            }
        }
    }
 
    Book top()
    {
        return bookInfo[heap[1]];
    }
     
    int Empty()
    {
        if (bn == 0)
            return 1;
        return 0;
    }
 
    void updateLoan(int idx)
    {
        int myBn = heapIdx[idx];
        for (int c = myBn; c > 1; c /= 2)
        {
            if (cmp(heap[c], heap[c / 2]))
            {
                swap(heap[c], heap[c / 2]);
                swap(heapIdx[heap[c]], heapIdx[heap[c / 2]]);
            }
            else
            {
 
                break;
            }
        }
    }
 
    
}pqAuthor[MAXAUTHOR],pqGenre[MAXGENRE];
 
void init() {
 
    for (int i = 0; i < MAXTITLE; i++)
    {
        titleTable[i].next = NULL;
        bookInfo[i].remainCnt = 0;
        bookInfo[i].loanCnt = 0;
        alreadyInput[i] = 0;
    }
    for (int i = 0; i < MAXAUTHOR; i++)
    {
        authorTable[i].next = NULL;
        pqAuthor[i].init();
    }
    for (int i = 0; i < MAXGENRE; i++)
    {
        genreTable[i].next = NULL;
        pqGenre[i].init();
    }
 
    tmpTitle = tmpAuthor = tmpGenre = tmpIdx = 0;
 
    for (int i = 0; i < MAXIDX; i++)
    {
        authorCnt[i] = genreCnt[i] = 0;
    }
}
 
void inputBook(char title[], char author[], char genre[], int cnt) {
 
     
    int titleIdx = findBookIdx(title,1);
    strcpy(bookInfo[titleIdx].title, title);
    strcpy(bookInfo[titleIdx].author, author);
    strcpy(bookInfo[titleIdx].genre, genre);
    bookInfo[titleIdx].remainCnt += cnt;
    bookInfo[titleIdx].idx = titleIdx;
 
 
    int authorIdx = findAuthorIdx(author);
    authorCnt[authorIdx] += cnt;
    int genreIdx = findGenreIdx(genre);
    genreCnt[genreIdx] += cnt;
    if (alreadyInput[titleIdx] == 0)
    {
        pqAuthor[authorIdx].push(titleIdx);
        pqGenre[genreIdx].push(titleIdx);
    }
 
    alreadyInput[titleIdx] = 1;
}
 
void loanBook(char title[], int cnt) {
 
    int titleIdx = findBookIdx(title,0);
 
    if (titleIdx == -1)
        return;
 
    int authorIdx = findAuthorIdx(bookInfo[titleIdx].author);
    int genreIdx = findGenreIdx(bookInfo[titleIdx].genre);
 
    if (bookInfo[titleIdx].remainCnt < cnt)
    {
        bookInfo[titleIdx].loanCnt += bookInfo[titleIdx].remainCnt;
        bookInfo[titleIdx].remainCnt = 0;
        pqAuthor[authorIdx].updateLoan(titleIdx);
        pqGenre[genreIdx].updateLoan(titleIdx);
         
        authorCnt[authorIdx] -= bookInfo[titleIdx].remainCnt;
        genreCnt[genreIdx] -= bookInfo[titleIdx].remainCnt;
 
         
 
        
    }
    else
    {
        bookInfo[titleIdx].loanCnt += cnt;
        bookInfo[titleIdx].remainCnt -= cnt;
        pqAuthor[authorIdx].updateLoan(titleIdx);
        pqGenre[genreIdx].updateLoan(titleIdx);
 
        authorCnt[authorIdx] -= cnt;
        genreCnt[genreIdx] -= cnt;
    }
    
}
 
int getLoanableCnt(int type, char str[]) {
 
    if (type == 0)
    {
        int titleIdx = findBookIdx(str,1);
        return bookInfo[titleIdx].remainCnt;
    }
    else if (type == 1)
    {
        int authorIdx = findAuthorIdx(str);
        return authorCnt[authorIdx];
    }
    else
    {
        int genreIdx = findGenreIdx(str);
        return genreCnt[genreIdx];
    }
}
int buf[MAXTITLE];
void recommendBook(int type, char str[], char(*userStr)[22]) {
 
     
     
    int cnt = 0;
    if (type == 1)
    {
        int authorIdx = findAuthorIdx(str);
        while (!pqAuthor[authorIdx].Empty())
        {
            Book top = pqAuthor[authorIdx].top();
             
            if (top.remainCnt == 0)
            {
                buf[cnt++] = top.idx;
                pqAuthor[authorIdx].pop();
            }
            else
            {
                strcpy(userStr[0], top.title);
                strcpy(userStr[1], top.author);
                strcpy(userStr[2], top.genre);
                break;
            }
        }
 
        for (int i = 0; i < cnt; i++)
        {
            pqAuthor[authorIdx].push(buf[i]);
        }
    }
    else if (type == 2)
    {
        int genreIdx = findGenreIdx(str);
        while (!pqGenre[genreIdx].Empty())
        {
            Book top = pqGenre[genreIdx].top();
            
            if (top.remainCnt == 0)
            {
                buf[cnt++] = top.idx;
                pqGenre[genreIdx].pop();
            }
            else
            {
                strcpy(userStr[0], top.title);
                strcpy(userStr[1], top.author);
                strcpy(userStr[2], top.genre);
                break;
            }
        }
 
        for (int i = 0; i < cnt; i++)
        {
            pqGenre[genreIdx].push(buf[i]);
        }
    }
 
}
