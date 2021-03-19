#ifndef NULL
#define NULL 0
#endif // NULL

#define MAXTITLE 10010
#define MAXTITLELEN 22

#define MAXAUTHOR 510
#define MAXAUTHORLEN 12

#define MAXGENRE 110
#define MAXGENRELEN 12

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

}bookInfo[MAXTITLE];


struct Title
{
    char title[MAXTITLELEN];
    int idx;
    Title* next;
    Book* here;

    Title* alloc(char vtitle[], int vidx, Title* vnext,Book *vhere)
    {
        strcpy(title, vtitle);
        idx = vidx;
        next = vnext;
        here = vhere;
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

void init() {

    for (int i = 0; i < MAXTITLE; i++)
    {
        titleTable[i].next = NULL;
        bookInfo[i].remainCnt = 0;
        bookInfo[i].loanCnt = 0;
    }
    for (int i = 0; i < MAXAUTHOR; i++)
    {
        authorTable[i].next = NULL;
    }
    for (int i = 0; i < MAXGENRE; i++)
    {
        genreTable[i].next = NULL;
    }

    tmpTitle = tmpAuthor = tmpGenre = tmpIdx = 0;

    for (int i = 0; i < MAXIDX; i++)
    {
        authorCnt[i] = genreCnt[i] = 0;
    }
}

int findBookIdx(char title[])
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
    

    titleTable[titleKey].next = bufTitle[tmpTitle].alloc(title, tmpTitle, titleTable[titleKey].next, &bookInfo[tmpTitle]);
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




struct PriorityQueue
{
    //지은이랑 장르.. IDX이용해서 힙 업데이트도 구현해야해

    
};


void inputBook(char title[], char author[], char genre[], int cnt) {

    int titleIdx = findBookIdx(title);
    Book me = bookInfo[titleIdx];
    strcpy(bookInfo[titleIdx].title, title);
    strcpy(bookInfo[titleIdx].author, author);
    strcpy(bookInfo[titleIdx].genre, genre);
    bookInfo[titleIdx].remainCnt += cnt;

    int authorIdx = findAuthorIdx(author);
    authorCnt[authorIdx] += cnt;
    int genreIdx = findGenreIdx(genre);
    genreCnt[genreIdx] += cnt;


    //pq에도 추가
}

void loanBook(char title[], int cnt) {

}

int getLoanableCnt(int type, char str[]) {

}

void recommendBook(int type, char str[], char(*userStr)[22]) {

}
