#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "myfun.h"

int high ,width; //  游戏画面尺寸
int position_x , position_y; // 飞机位置
int bullet_x ,bullet_y ; // 子弹位置
int target_x , target_y ; // 目标位置
int score ; //得分


void HideCursor()
{
    CONSOLE_CURSOR_INFO  cursor_info = {1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}



void startup() // 数据初始化
{
    high = 30;
    width = 50; //  游戏画面尺寸
    position_x = width/2;
    position_y = high/2; // 飞机位置
    bullet_x = position_x;
    bullet_y = -1; // 子弹位置
    target_x = position_x;
    target_y = 0; // 目标位置
    score = 0;
}


void gotoxy(int x,int y)//类似于清屏函数，光标移动到原点位置进行重画
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void show()  // 显示画面
{
	gotoxy(0,0);  // 光标移动到原点位置进行重画清屏
	int i,j;
    for (i=0;i<high;i++)
       {
         for (j=0;j<width;j++)
           {
             if ((i==position_y) && (j==position_x))
                 printf("  *");  //   输出飞机*
              else if ((i==position_y+1) && (j==position_x))
                  printf("*****") ;
              else if ((i==position_y+2) && (j==position_x))
                   printf(" * *") ;
              else if ((i==target_y) && (j==target_x))
                  printf("@");  //   输出敌机@
              else if ((i==bullet_y) && (j==bullet_x))
                   printf("|");  //   输出子弹|
              else
                  printf(" ");  //   输出空格
            }
            printf("\n");
        }
	printf("得分：%d\n",score);

}

void updateWithoutInput()  // 与用户输入无关的更新
{
  static int speed = 0;
  if (speed < 10)
      speed++;
  if (speed == 10)
    {
       target_y++;
       speed = 0; //重置speed
    }

  if (bullet_y>-1)
      bullet_y--;

  if ((bullet_x==target_x) && (bullet_y==target_y))  // 子弹击中敌机
	{
		score++;                // 分数加1
		target_y = -1;           // 产生新的飞机
		target_x = rand()%width;
		bullet_x = -2;          // 子弹无效
	}

	if (target_y>high)   // 敌机跑出显示屏幕
	{
		target_y = -1;           // 产生新的飞机
		target_x = rand()%width;
	}

	if ((target_x>=position_x) &&  (target_x<=position_x+5) && (target_y==position_y))  // 飞机与敌机相撞
	{
        system("cls");
		gotoxy(width/2,high/2);
		printf("Game over!\n");
		gotoxy(width/2,high/2+1);
		printf("得分：%d\n",score);
        getchar();
		exit(0);// 子弹无效
	}

}

void updateWithInput()
{
    char input;
    if(kbhit())  // 判断是否有输入
        {
          input = getch();  // 根据用户的不同输入来移动，不必输入回车
		  switch (input)
            {
                case 'a': position_x--; break; // 位置左移
                case 'd': position_x++; break; // 位置右移
                case 'w': position_y--; break; // 位置上移
                case 's': position_y++; break; // 位置下移
                case ' ':
                    {
                        bullet_y = position_y - 1;
                        bullet_x = position_x + 2;
                        break;//输出子弹
                    }
                case 'q': exit(0);
            }
        }
}
