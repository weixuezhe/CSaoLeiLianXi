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
	//�洢�׵�����
	char leiPan[ROWS][COLS] = { 0 };
	//չʾ����ҵ�����
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	InitBoard(leiPan, ROW, COL, ' ');
	InitBoard(show, ROW, COL, '*');
	//��ӡ����
	//DisplayBoard(leiPan, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetBoard(leiPan, ROW, COL);
	DisplayBoard(leiPan, ROW, COL);

	//����Ϸ
	PlayGame(leiPan, show, ROW, COL);
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("����������ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("û�д�ѡ�������ѡ��\n");
			break;
		}
	}while(input);
}

int main() 
{
	test();
	return 0;
}