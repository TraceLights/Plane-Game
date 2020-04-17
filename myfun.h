int high ;
int width; //  游戏画面尺寸
int position_x;
int position_y; // 飞机位置
int bullet_x;
int bullet_y ; // 子弹位置
int target_x;
int target_y ; // 目标位置
int score ; //得分

void gotoxy(int x,int y);//类似于清屏函数，光标移动到原点位置进行重画
void startup(); // 数据初始化
void show();  // 显示画面
void updateWithoutInput();  // 与用户输入无关的更新
void updateWithInput();  // 与用户输入有关的更新
void HideCursor();
