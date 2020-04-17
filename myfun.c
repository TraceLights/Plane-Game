#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "myfun.h"

int high ,width; //  ��Ϸ����ߴ�
int position_x , position_y; // �ɻ�λ��
int bullet_x ,bullet_y ; // �ӵ�λ��
int target_x , target_y ; // Ŀ��λ��
int score ; //�÷�


void HideCursor()
{
    CONSOLE_CURSOR_INFO  cursor_info = {1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}



void startup() // ���ݳ�ʼ��
{
    high = 30;
    width = 50; //  ��Ϸ����ߴ�
    position_x = width/2;
    position_y = high/2; // �ɻ�λ��
    bullet_x = position_x;
    bullet_y = -1; // �ӵ�λ��
    target_x = position_x;
    target_y = 0; // Ŀ��λ��
    score = 0;
}


void gotoxy(int x,int y)//��������������������ƶ���ԭ��λ�ý����ػ�
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void show()  // ��ʾ����
{
	gotoxy(0,0);  // ����ƶ���ԭ��λ�ý����ػ�����
	int i,j;
    for (i=0;i<high;i++)
       {
         for (j=0;j<width;j++)
           {
             if ((i==position_y) && (j==position_x))
                 printf("  *");  //   ����ɻ�*
              else if ((i==position_y+1) && (j==position_x))
                  printf("*****") ;
              else if ((i==position_y+2) && (j==position_x))
                   printf(" * *") ;
              else if ((i==target_y) && (j==target_x))
                  printf("@");  //   ����л�@
              else if ((i==bullet_y) && (j==bullet_x))
                   printf("|");  //   ����ӵ�|
              else
                  printf(" ");  //   ����ո�
            }
            printf("\n");
        }
	printf("�÷֣�%d\n",score);

}

void updateWithoutInput()  // ���û������޹صĸ���
{
  static int speed = 0;
  if (speed < 10)
      speed++;
  if (speed == 10)
    {
       target_y++;
       speed = 0; //����speed
    }

  if (bullet_y>-1)
      bullet_y--;

  if ((bullet_x==target_x) && (bullet_y==target_y))  // �ӵ����ел�
	{
		score++;                // ������1
		target_y = -1;           // �����µķɻ�
		target_x = rand()%width;
		bullet_x = -2;          // �ӵ���Ч
	}

	if (target_y>high)   // �л��ܳ���ʾ��Ļ
	{
		target_y = -1;           // �����µķɻ�
		target_x = rand()%width;
	}

	if ((target_x>=position_x) &&  (target_x<=position_x+5) && (target_y==position_y))  // �ɻ���л���ײ
	{
        system("cls");
		gotoxy(width/2,high/2);
		printf("Game over!\n");
		gotoxy(width/2,high/2+1);
		printf("�÷֣�%d\n",score);
        getchar();
		exit(0);// �ӵ���Ч
	}

}

void updateWithInput()
{
    char input;
    if(kbhit())  // �ж��Ƿ�������
        {
          input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		  switch (input)
            {
                case 'a': position_x--; break; // λ������
                case 'd': position_x++; break; // λ������
                case 'w': position_y--; break; // λ������
                case 's': position_y++; break; // λ������
                case ' ':
                    {
                        bullet_y = position_y - 1;
                        bullet_x = position_x + 2;
                        break;//����ӵ�
                    }
                case 'q': exit(0);
            }
        }
}
