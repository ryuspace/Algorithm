#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
#include <string.h>
 
#define INIT       0
#define SETFARM    1
#define GETCROP    2
#define MERGECELL  3
#define CNTCELL    4
#define CNTAREA    5
 
extern void init(int Row, int Col);
extern void setFarm(int row, int col, char crop[]);
extern void getCrop(int row, int col, char crop[]);
extern void mergeCell(int row1, int col1, int row2, int col2, int sw);
extern int cntCell(char crop[]);
extern int cntArea(char crop[]);
 
static int run()
{
    int score = 100;
    int N, cmd, row1, col1, row2, col2, op, usercnt;
    char str[12], user[12];
 
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &cmd);
        switch (cmd) {
        case INIT:
            scanf("%d %d", &row1, &col1);
            init(row1, col1);
            break;
        case SETFARM:
            scanf("%d %d %s", &row1, &col1, str);
            setFarm(row1, col1, str);
            break;
        case GETCROP:
            scanf("%d %d %s", &row1, &col1, str);
            getCrop(row1, col1, user);
            if (str[0] == 'N') str[0] = '\0';
            if (strcmp(str, user) != 0) score = 0;
            break;
        case MERGECELL:
            scanf("%d %d %d %d %d", &row1, &col1, &row2, &col2, &op);
            mergeCell(row1, col1, row2, col2, op);
            break;
        case CNTCELL:
            scanf("%d %s", &op, str);
            usercnt = cntCell(str);
            if (usercnt != op) score = 0;
            break;
        case CNTAREA:
            scanf("%d %s", &op, str);
            usercnt = cntArea(str);
            if (usercnt != op) score = 0;
            break;
        default:
            break;
        }
    }
 
    return score;
}
 
int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
 
    int T;
    scanf("%d", &T);
 
    for (int tc = 1; tc <= T; tc++) {
        printf("#%d %d\n", tc, run());
    }
 
    return 0;
} 
