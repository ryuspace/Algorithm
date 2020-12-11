#define NULL 0
#define MAX 50000
#define FLEN 150
typedef struct pair {
    int y, x;
}pair;
 
 
void m_strcpy(char* a, char* b) {
    while (*a) {
        *b++ = *a++;
    }
    *b = '\0';
    return;
}
 
int strcompare(char *a, char *b)
{
    int i;
    for (i = 0; (a[i] == b[i]) && a[i] && b[i]; i++);
    return a[i] - b[i];
}
 
int GetHash(char* name) {
    int ret = 5381;
    for (int i = 0; name[i]; i++) {
        ret = (ret * 33 + name[i]) % (MAX + 100);
    }
    return ret;
}
 
typedef struct Crop {
    char name[11];
    int key;
    int num_cell;
    int num_area;
    Crop* next;
 
    Crop* alloc(char _name[], Crop* _next) {
        m_strcpy(_name, name);
        key = GetHash(_name);
        num_cell = 0;
        num_area = 0;
        next = _next;
        return this;
    }
};
int hcnt;
Crop* Htab[MAX + 100];
Crop Hbuf[25000];
 
typedef struct Node {
    pair pixel;
    Node* next;
    Node* alloc(pair _pixel, Node* _next) {
        pixel = _pixel;
        next = _next;
        return this;
    }
}Node;
Node Pbuf[MAX];
int pcnt;
 
typedef struct Cell {
    char name[11];
    pair Parent;
    int Area;
    Node* head;
}Cell;
Cell Farm[FLEN + 10][FLEN + 10];
 
 
Crop* Search(char *name) {
    int Hashkey = GetHash(name);
    Crop* p = Htab[Hashkey];
 
    for (; p; p = p->next)
        if (strcompare(p->name, name) == 0)return p;
 
    return Htab[Hashkey] = Hbuf[hcnt++].alloc(name, Htab[Hashkey]);
}
 
void renew(Cell* Pas, Cell* Act) {
    Pas->Parent = Act->Parent;
    m_strcpy(Act->name, Pas->name);
    Pas->Area = 0;
}
 
void init(int Row, int Col) {
    hcnt = pcnt = 0;
 
    for (int i = 0; i < MAX; i++)
        Htab[i] = NULL;
 
    for (int y = 1; y <= FLEN; y++)
        for (int x = 1; x <= FLEN; x++) {
            Farm[y][x].head = NULL;
            Farm[y][x].name[0] = '\0';
            Farm[y][x].Parent = { y,x };
            Farm[y][x].Area = 1;
        }
}
void setFarm(int row, int col, char crop[]) {
 
    pair par = Farm[row][col].Parent;
 
    Cell* p = &Farm[par.y][par.x];
    if (p->name[0] != '\0') {
        Crop* prev = Search(p->name);
        prev->num_cell--;
        prev->num_area -= p->Area;
    }
    Crop* t = Search(crop);
 
    t->num_cell++;
 
    //아예 맨 처음 들어온 경우라면
    if ((par.y == row && par.x == col) && p->head == NULL) {
        m_strcpy(crop, p->name);
        t->num_area++;
    }
 
    else {
        t->num_area += p->Area;
        m_strcpy(crop, p->name);
        Node* tmp = p->head;
        while (tmp) {
            m_strcpy(crop, Farm[tmp->pixel.y][tmp->pixel.x].name);
            tmp = tmp->next;
        }
    }
    return;
}
void getCrop(int row, int col, char crop[]) {
    m_strcpy(Farm[row][col].name, crop);
    return;
 
}
void mergeCell(int row1, int col1, int row2, int col2, int sw) {
    pair act, pas;
 
    if (sw == 1) {
        act = { row1,col1 };
        pas = { row2,col2 };
    }
    else {
        act = { row2,col2 };
        pas = { row1,col1 };
    }
 
    act = Farm[act.y][act.x].Parent;
    pas = Farm[pas.y][pas.x].Parent;
 
    Cell* Act = &Farm[act.y][act.x];
    Cell* Pas = &Farm[pas.y][pas.x];
 
    Act->Area += Pas->Area;
 
    //해당 작물의 넓이를 넓혀준다
    Crop* Act_p = Search(Act->name);
    Act_p->num_area += Pas->Area;
    //합침 당하는 쪽은 재배작물에 셀 하나 줄여주고, 넓이 감소시켜 준다.
    Crop* Pas_p = Search(Pas->name);
    Pas_p->num_area -= Pas->Area;
    Pas_p->num_cell--;
 
    //부모의 정보먼저 갱신해준다.
    renew(Pas, Act);
 
 
    //각 부모에 있던 리스트를 생성하거나, 이어 붙이는 작업
    Node* P = Pas->head;
    Node* A = Act->head;
 
    //아무 자기 자신만 있는 상태였다면, act 부모의 리스트에 하나 새로 생성한다.
 
    Act->head = Pbuf[pcnt++].alloc(pas, Act->head);
 
    //이미 갖고 있던 리스트가 있는 경우
 
    Node* t = P;
    while (t) {
 
        Cell* tmp = &Farm[t->pixel.y][t->pixel.x];
        renew(tmp, Act);
        t = t->next;
    }
    //A가 아무것도 없는 상태였다면 P를 그대르 넣어준다.
    if (Act->head == NULL)
        Act->head = P;
    //그렇지 않다면 A의 마지막에 P를 연결시킨다.
    else {
        Node* prev = Act->head;
        while (A) {
            prev = A;
            A = A->next;
        }
        prev->next = P;
    }
}
int cntCell(char crop[]) {
    Crop* p = Search(crop);
    return p->num_cell;
}
int cntArea(char crop[]) {
    Crop* p = Search(crop);
    return p->num_area;
}
