//intro : 神魔之塔
//remark -> this code is refered to classmates
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BOARD_WIDTH 6
#define BOARD_HEIGHT 5
#define MAX_N 10000
#define ELEM_NUM 12

typedef struct Member {
    char* name;
    int attack;
    double damage;
    int recovery;
    char type;
} Member;

Member members[6];
int memberNum = 0;
int extraBoardLen = 0;
char extraBoard[MAX_N][BOARD_WIDTH];
char board[BOARD_HEIGHT][BOARD_WIDTH];
bool traveled[BOARD_HEIGHT][BOARD_WIDTH];
int dirX[] = { 0, 1, 0, -1 };
int dirY[] = { -1, 0, 1, 0 };
int elemCnt[ELEM_NUM] = {};

void getMember();
void getExtraBoard();
void getBoard();
bool dissolvable();
int calElemCntRow(int y, int x, char elem);
int calElemCntCol(int y, int x, char elem);
void countElemRow(int y, int x, char elem);
void countElemCol(int y, int x, char elem);
void dissolve();
void fallBoard();
void fallExtraBoard();
void fall();
void calMemberDamage();
void printResult();

// Utils
int stoi(char* s);
int elemToIdx(char elem);
char idxToElem(int idx);
void swap(char* a, char* b);
int comp(const void* a, const void* b);
char toggleCase(char c);
void resetTraveled();
void printExtraBoard();
void printBoard();
void printTraveled();
void printElemCnt();

int main() {
    // input
    getMember();
    getExtraBoard();
    getBoard();

    while (dissolvable()) {
        dissolve();
        fall();
    }

    calMemberDamage();
    qsort(members, memberNum, sizeof(members[0]), comp);
    printResult();
}

void getMember() {
    char line[200] = "";
    memberNum = 0;
    while (1) {
        scanf("%[^\n]\n", line);  // Member ID
        if (strcmp(line, "--------------------") == 0) 
            return;
        scanf("NAME : %[^\n]\n", line);  // Name
        members[memberNum].name = malloc(sizeof(char) * 200);
        strcpy(members[memberNum].name, line);
        scanf("TYPE : %[^\n]\n", line);  // Type
        members[memberNum].type = tolower(line[0]);
        scanf("ATTACK : %d\n", &members[memberNum].attack);  // Attack
        scanf("RECOVERY : %d\n", &members[memberNum].recovery);  // Recovery
        ++memberNum;
    }
}

void getExtraBoard() {
    char line[BOARD_WIDTH + 1];
    int extraBoardIdx = 0;
    while (1) {
        scanf("%[^\n]\n", line);
        if (strcmp(line, "------") == 0)
            break;
        strcpy(extraBoard[extraBoardIdx], line);
        ++extraBoardIdx;
    }
    extraBoardLen = extraBoardIdx;
}

void getBoard() {
    char line[BOARD_WIDTH + 1];
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        scanf("%[^\n]\n", line);
        strcpy(board[i], line);
    }
}

bool dissolvable() {
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            char elem = board[i][j];
            if (elem == '.') continue;
            int cntRow = calElemCntRow(i, j, elem);
            if (cntRow >= 3) {
                return true;
            }
            int cntCol = calElemCntCol(i, j, elem);
            if (cntCol >= 3) {
                return true;
            }
        }
    }
    return false;
}

int calElemCntRow(int y, int x, char elem) {
    int cnt = 0;
    for (int i = x; i < BOARD_WIDTH; ++i) {
        if (board[y][i] != elem && board[y][i] != toggleCase(elem))
            break;
        ++cnt;
    }
    return cnt;
}

int calElemCntCol(int y, int x, char elem) {
    int cnt = 0;
    for (int i = y; i < BOARD_HEIGHT; ++i) {
        if (board[i][x] != elem && board[i][x] != toggleCase(elem))
            break;
        ++cnt;
    }
    return cnt;
}

void countElemRow(int y, int x, char elem) {
    for (int i = x; i < BOARD_WIDTH; ++i) {
        if (board[y][i] != elem && board[y][i] != toggleCase(elem))
            break;
        if (!traveled[y][i])
            ++elemCnt[elemToIdx(board[y][i])];
        traveled[y][i] = true;
    }
}

void countElemCol(int y, int x, char elem) {
    for (int i = y; i < BOARD_HEIGHT; ++i) {
        if (board[i][x] != elem && board[i][x] != toggleCase(elem))
            break;
        if (!traveled[i][x])
            ++elemCnt[elemToIdx(board[i][x])];
        traveled[i][x] = true;
    }
}

void dissolve() {
    resetTraveled();
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            char elem = board[i][j];
            if (elem == '.')
                continue;
            int cntRow = calElemCntRow(i, j, elem);
            if (cntRow >= 3) {
                countElemRow(i, j, elem);
            }
            int cntCol = calElemCntCol(i, j, elem);
            if (cntCol >= 3) {
                countElemCol(i, j, elem);
            }
        }
    }
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (traveled[i][j])
                board[i][j] = '.';
        }
    }
}

void fallBoard() {
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        for (int j = BOARD_HEIGHT - 1; j >= 0; --j) {
            if (board[j][i] != '.')
                continue;
            int nextStoneIdx = j;
            while (nextStoneIdx >= 0 && board[nextStoneIdx][i] == '.') 
                --nextStoneIdx;
            if (nextStoneIdx == -1)
                break;
            swap(&board[j][i], &board[nextStoneIdx][i]);
        }
    }
}

void fallExtraBoard() {
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        for (int j = BOARD_HEIGHT - 1; j >= 0; --j) {
            if (board[j][i] != '.')
                continue;
            int nextStoneIdx = extraBoardLen - 1;
            while (nextStoneIdx >= 0 && extraBoard[nextStoneIdx][i] == '.') 
                --nextStoneIdx;
            if (nextStoneIdx == -1)
                break;
            swap(&board[j][i], &extraBoard[nextStoneIdx][i]);
        }
    }
}

void fall() {
    fallBoard();
    fallExtraBoard();
}

void calMemberDamage() {
    for (int i = 0; i < memberNum; i++) {
        char type = members[i].type;
        members[i].damage = members[i].attack * (elemCnt[elemToIdx(type)] * 0.25 + elemCnt[elemToIdx(toggleCase(type))] * 0.4 + 1 * 0.25);

    }
}

void printResult() {
    printf("-------------------------------------------\n");
    for (int i = 0; i < memberNum; i++) {
        char type = members[i].type;
        double damage = members[i].attack * (elemCnt[elemToIdx(type)] * 0.25 + elemCnt[elemToIdx(toggleCase(type))] * 0.4 + 1 * 0.25);
        double recovery = members[i].recovery * (elemCnt[elemToIdx('h')] * 0.25 + elemCnt[elemToIdx('H')] * 0.4 + 1 * 0.25);
        printf("| %-40s|\n| Damage : %-10.0lf| Recovery : %-8.0lf|\n", members[i].name, damage, recovery);
        printf("-------------------------------------------\n");
    }
}

// Utils
int stoi(char* s) {
    while (!isdigit(*s)) ++s;
    int num = 0;
    while (*s != '\0') 
        num = num * 10 + (*(s++) - '0');
    return num;
}

int elemToIdx(char elem) {
    if (elem == 'w') return 0;
    else if (elem == 'f') return 1;
    else if (elem == 'e') return 2;
    else if (elem == 'l') return 3;
    else if (elem == 'd') return 4;
    else if (elem == 'h') return 5;
    else if (elem == 'W') return 6;
    else if (elem == 'F') return 7;
    else if (elem == 'E') return 8;
    else if (elem == 'L') return 9;
    else if (elem == 'D') return 10;
    else if (elem == 'H') return 11;
    else return -1;
}

char idxToElem(int idx) {
    if (idx == 0) return 'w';
    else if (idx == 1) return 'f';
    else if (idx == 2) return 'e';
    else if (idx == 3) return 'l';
    else if (idx == 4) return 'd';
    else if (idx == 5) return 'h';
    else if (idx == 6) return 'W';
    else if (idx == 7) return 'F';
    else if (idx == 8) return 'E';
    else if (idx == 9) return 'L';
    else if (idx == 10) return 'D';
    else if (idx == 11) return 'H';
    else return '.';
}

void swap(char* a, char* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int comp(const void* a, const void* b) {
    Member memberA = *(const Member*)a;
    Member memberB = *(const Member*)b;
    return memberB.damage - memberA.damage;
}

char toggleCase(char c) {
    return c ^ (1 << 5);
}

void resetTraveled() {
    for (int i = 0; i < BOARD_HEIGHT; ++i)
        memset(traveled[i], false, BOARD_WIDTH);
}

void printExtraBoard() {
    printf("------------\n");
    printf("Extra Board:\n");
    for (int i = 0; i < extraBoardLen; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            printf("%c ", extraBoard[i][j]);
        }
        printf("\n");
    }
}

void printBoard() {
    printf("------------\n");
    printf("Board:\n");
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void printTraveled() {
    printf("------------\n");
    printf("Traveled:\n");
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        for (int j = 0; j < BOARD_HEIGHT; ++j) {
            printf("%d ", traveled[i][j]);
        }
        printf("\n");
    }
}

void printElemCnt() {
    printf("------------\n");
    printf("Dissolved Element Count:\n");
    for (int i = 0; i < ELEM_NUM; ++i) {
        printf("%c: %d\n", idxToElem(i), elemCnt[i]);
    }
}
