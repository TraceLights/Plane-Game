#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "myfun.h"

int main()
{
    HideCursor();
	startup();  // ���ݳ�ʼ��
	while (1) //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();  // ���û������йصĸ���
	}
	return 0;
}
