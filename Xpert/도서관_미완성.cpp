#define NULL 0
#define MAXTITLE 10010
#define MAXAUTHOR 510
#define MAXGENRE 110
typedef unsigned long long ull;

struct Node
{
    char title[22];
    ull author;
    ull genre;
    int cnt;
    int loan;
};

struct Title
{
    ull title;
    Title* next;
    Title* alloc(ull vtitle, Title* vnext)
    {
        title = vtitle;
        next = vnext;
        return this;
    }
}buf[MAXTITLE],*htable[MAXTITLE];

int tmpIdx;
int AuthorIdx[MAXAUTHOR];
int GenreIdx[MAXGENRE];

Node Book[MAXTITLE];


int findTitleidx(char name[])
{

}
int findAuthorIdx(char name[])
{
    
}

int findGenreIdx(char name[])
{

}


int bigyo(Node a, Node b)
{
    if (a.loan > b.loan)
    {
        return 1;
    }
    else if (a.loan == b.loan)
    {
        if (strcmp(a.title, b.title) < 0)
            return 1;
        return 0;
    }
    else
    {
        return 0;
    }
}
void swap(Node& a, Node& b)
{
    Node tmp = a;
    a = b;
    b = tmp;
}
struct PriorityQueue
{
    Node heap[MAXTITLE];
    int (*cmp)(Node, Node);
    int bn;

    void init()
    {
        cmp = bigyo;
        bn = 0;
    }

    void push(Node num)
    {
        heap[++bn] = num;

        for (int c = bn;c > 1;c /= 2)
        {
            if (c < bn && cmp(heap[c+1], heap[c]))
            {
                c++;
            }
            if (cmp(heap[c], heap[c / 2]))
            {
                swap(heap[c], heap[c / 2]);
            }
        }
    }


}pqAuthor[MAXAUTHOR],pqGenre[MAXGENRE];


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

void init() {
    tmpIdx = 0;
}

void inputBook(char title[], char author[], char genre[], int cnt) {

}

void loanBook(char title[], int cnt) {

}

int getLoanableCnt(int type, char str[]) {

}

void recommendBook(int type, char str[], char(*userStr)[22]) {

}
