int high ;
int width; //  ��Ϸ����ߴ�
int position_x;
int position_y; // �ɻ�λ��
int bullet_x;
int bullet_y ; // �ӵ�λ��
int target_x;
int target_y ; // Ŀ��λ��
int score ; //�÷�

void gotoxy(int x,int y);//��������������������ƶ���ԭ��λ�ý����ػ�
void startup(); // ���ݳ�ʼ��
void show();  // ��ʾ����
void updateWithoutInput();  // ���û������޹صĸ���
void updateWithInput();  // ���û������йصĸ���
void HideCursor();
