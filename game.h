#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COL 9

#define LEI 10

#define ROWS ROW + 2
#define COLS COL + 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], int row, int col, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetBoard(char board[ROWS][COLS], int row, int col);
void PlayGame(char leipan[ROWS][COLS], char show[ROWS][COLS], int row, int col);