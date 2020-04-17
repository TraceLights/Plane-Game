#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "myfun.h"

int main()
{
    HideCursor();
	startup();  // 数据初始化
	while (1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
	return 0;
}
