#include "game.h"


//初始化棋盘
void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}


//显示棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("  ");
	for (j = 1; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	printf("  ");
	for (j = 1; j <= col; j++)
	{
		printf("--");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//布置雷
void SetBoard(char board[ROWS][COLS], int row, int col)
{
	int count = LEI;
	int x = 0;
	int y = 0;
	while(count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == ' ')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


//判断雷的个数
int IsCount(char leipan[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int shu = 0;
	shu = leipan[x - 1][y] +
		leipan[x - 1][y - 1] +
		leipan[x][y - 1] +
		leipan[x + 1][y - 1] +
		leipan[x + 1][y] +
		leipan[x + 1][y + 1] +
		leipan[x][y + 1] +
		leipan[x - 1][y + 1] - 8 * ' ' + 32;
	if (shu == 66)
	{
		//有两个雷
		shu = 50;
	}
	else if (shu == 83)
	{
		//有三个雷
		shu = 51;
	}
	else if (shu == 100)
	{
		//有四个雷
		shu = 52;
	}
	else if (shu == 117)
	{
		//有五个雷
		shu = 53;
	}
	else if (shu == 134)
	{
		//有六个雷
		shu = 54;
	}
	else if (shu == 151)
	{
		//有七个雷
		shu = 55;
	}
	else if (shu == 168)
	{
		//有八个雷
		shu = 56;
	}
	return shu;
}

//通过这个函数来判断剩余的雷如果剩余的雷的个数等于设置的雷的个数则闯关成功
int leishu(char show[ROWS][COLS], int row, int col)
{
	int s = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				s++;
			}
		}
	}
	return s;
}

//玩游戏
void PlayGame(char leipan[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	//int lei = row * col - LEI;
	int lei = leishu(show, row, col);
	int x = 1;
	int y = 1;
	while (1)
	{
		
		printf("请输入您的坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row + 1 && y >= 1 && y <= row + 1)
		{
			
			if (leipan[x][y] == '1')
			{
				printf("您踩到雷了，游戏结束\n");
				DisplayBoard(leipan, row, col);
				break;
			}
			else
			{
				//判断用户输入的周围有几颗雷显示在show棋盘上
				count = IsCount(leipan, show, x, y);
				show[x][y] = count;

				//如果这个坐标周围没有雷则这个坐标周围的格子都显示出来。
				//目前实现不了，下面这个是可以实现一部分显示，但是雷的个数统计不完全会出现全部雷都排完了但是没有结束游戏
				/*if (count == 32)
				{

					int x1 = x;
					while (1)
					{
						x1 = x1 - 1;
						if (show[x1][y] == '*')
						{
							count = IsCount(leipan, show, x1, y);
							show[x1][y] = count;
						}
						if (count != ' ')
						{
							break;
						}
						
					}
					int x2 = x;
					int y2 = y;
					while (1)
					{
						
						x2 = x2 - 1;
						y2 = y2 - 1;
						if (show[x2][y2] == '*')
						{
						
							count = IsCount(leipan, show, x2, y2);
							show[x2][y2] = count;
						}
						
						if (count != ' ')
						{
							break;
						}
					}
					int y3 = y;
					while (1)
					{
						
						y3 = y3 - 1;
						if (show[x][y3] == '*')
						{
							
							count = IsCount(leipan, show, x, y3);
							show[x][y3] = count;
						}
						
						if (count != ' ')
						{
							break;
						}
					}
					int x4 = x;
					int y4 = y;
					while (1)
					{
						
						x4 = x4 + 1;
						y4 = y4 - 1;
						if (show[x4][y4] == '*')
						{
							
							count = IsCount(leipan, show, x4, y4);
							show[x4][y4] = count;
						}
						
						if (count != ' ')
						{
							break;
						}
					}
					int x5 = x;
					while (1)
					{
						
						x5 = x5 + 1;
						if (show[x5][y] == '*')
						{
						
							count = IsCount(leipan, show, x5, y);
							show[x5][y] = count;
						}
						
						if (count != ' ')
						{
							break;
						}
					}
					int x6 = x;
					int y6 = y;
					while (1)
					{
						
						x6 = x6 + 1;
						y6 = y6 + 1;
						if (show[x6][y6] == '*')
						{
							
							count = IsCount(leipan, show, x6, y6);
							show[x6][y6] = count;
						}
						
						if (count != ' ')
						{
							break;
						}
					}
					int y7 = y;
					while (1)
					{
						
						y7 = y7 + 1;
						if (show[x][y7] == '*')
						{
							
							count = IsCount(leipan, show, x, y7);
							show[x][y7] = count;
						}
						if (count != ' ')
						{
							break;
						}
						
					}
					int x8 = x;
					int y8 = y;
					while (1)
					{
						
						x8 = x8 - 1;
						y8 = y8 + 1;
						if (show[x8][y8] == '*')
						{
							
							count = IsCount(leipan, show, x8, y8);
							show[x8][y8] = count;
						}
						
						if (count != ' ')
						{
							break;
						}
					}
				}*/
				DisplayBoard(leipan, row, col);
				DisplayBoard(show, row, col);
				lei = leishu(show, row, col);
				if (lei == LEI)
				{
					printf("闯关成功\n");
					DisplayBoard(leipan, row, col);
					break;
				}
			}
		}
		else
		{
			printf("您输入的坐标错误，请重新输入\n");
		}
	}
	
}