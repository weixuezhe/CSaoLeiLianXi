#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("********************\n");
	printf("****   1.play   ****\n");
	printf("****   0.exit   ****\n");
	printf("********************\n");
}

void game()
{
	//存储雷的棋盘
	char leiPan[ROWS][COLS] = { 0 };
	//展示给玩家的棋盘
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	InitBoard(leiPan, ROW, COL, ' ');
	InitBoard(show, ROW, COL, '*');
	//打印棋盘
	//DisplayBoard(leiPan, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetBoard(leiPan, ROW, COL);
	DisplayBoard(leiPan, ROW, COL);

	//玩游戏
	PlayGame(leiPan, show, ROW, COL);
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入您的选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("没有此选项，请重新选择\n");
			break;
		}
	}while(input);
}

int main() 
{
	test();
	return 0;
}