// https://blog.csdn.net/weixin_42631782/article/details/121316185

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct GROUP {
    int ID = 0;                // ����
    int alive = 1;             // �Ƿ���
    int miss = 0;              // �Ƿ���·
    int back = 0;              // �Ƿ�ص���Ӫ
    int rank = -1;             // ����
    int integral = 1000;       // ����
    int alive_day = 0;         // �������
    int money = 1000;          // ʣ��Ľ�Ǯ
    int residual_load = 1000;  // ʣ��İ���
    int water = 1000;          // ˮ
    int food = 1000;           // ʳ��
    int tent = 1000;           // ����
    int compass = 1000;        // ָ����
    string locations = "D";    // λ��
    int gold = 0;              // �ƽ�
    int card = -1;             // �����ȡ���Ʊ��
    string Bei_zhu = " ";      // ��ע
};

GROUP group[100];            // Ԥ��100������
int ALL_DAY = 15;         // ��Ϸ����
char confirm;           // ����ȷ�ϻز�
int group_num = 0;       // ��������
int game_day = 0;        // ��Ϸ����
int game_ranking = 0;    // ����
int back_day = 0;        // ��һ�ӵ�������
int weather_list[30][5] = {  // ��һά��Ϊ�������ڶ�ά��Ϊ���ص������
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 }
};

// ��������
int  Weather(int day, int locations );                // ��������
void Weather_list();                                 // �����б�����
void Weather_list_show();                             // �����б����
void Day_show(int x, int y, int w, int h, int i);

int main(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(1000, 1000);
    Weather_list();
    Weather_list_show();

/*    Fl_Box* box = new Fl_Box(40, 80, 300, 100, "ss");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD + FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);*/
    window->end();
    window->show(argc, argv);
    return Fl::run();
}

// �������
void Weather_list_show() {
    Fl_Box* list_title = new Fl_Box(0, 0, 996, 40, "Weather List");
    list_title->box(FL_UP_BOX);
    list_title->labelfont(FL_BOLD + FL_ITALIC);
    list_title->labelsize(36);
    list_title->labeltype(FL_SHADOW_LABEL);
    Fl_Box* list_day = new Fl_Box(0,40,  166, 40, "Day");
    list_day->box(FL_UP_BOX);
    list_day->labelfont(FL_BOLD + FL_ITALIC);
    list_day->labelsize(36);
    list_day->labeltype(FL_SHADOW_LABEL);
    Fl_Box* list_S = new Fl_Box(166,40,  166, 40, "S M");
    list_S->box(FL_UP_BOX);
    list_S->labelfont(FL_BOLD + FL_ITALIC);
    list_S->labelsize(36);
    list_S->labeltype(FL_SHADOW_LABEL);
    Fl_Box* list_W = new Fl_Box(332,40,  166, 40, "W L");
    list_W->box(FL_UP_BOX);
    list_W->labelfont(FL_BOLD + FL_ITALIC);
    list_W->labelsize(36);
    list_W->labeltype(FL_SHADOW_LABEL);
    Fl_Box* list_L = new Fl_Box(498,40,  166, 40, "L Z");
    list_L->box(FL_UP_BOX);
    list_L->labelfont(FL_BOLD + FL_ITALIC);
    list_L->labelsize(36);
    list_L->labeltype(FL_SHADOW_LABEL);
    Fl_Box* list_C = new Fl_Box(664,40,  166, 40, "C Z");
    list_C->box(FL_UP_BOX);
    list_C->labelfont(FL_BOLD + FL_ITALIC);
    list_C->labelsize(36);
    list_C->labeltype(FL_SHADOW_LABEL);
    Fl_Box* list_M = new Fl_Box(830,40,  166, 40, "D S");
    list_M->box(FL_UP_BOX);
    list_M->labelfont(FL_BOLD + FL_ITALIC);
    list_M->labelsize(36);
    list_M->labeltype(FL_SHADOW_LABEL);
    //printf("/***************************************************************************************/\n");
    //printf("/*                                                                                     */\n");
    //printf("/*                                ��    ��     ��    ��                                */\n");
    //printf("/*                                                                                     */\n");
    //printf("/*     |  ����  |    ɳĮ    |    ����    |    ����    |    ��ׯ    |    ��ɽ    |     */\n");
    //             /*     | ��01�� |    ����    |    ����    |   ɳ����   | ����ɳ���� | ����ɳ���� |     */ 
    for (int i = 0; i < ALL_DAY; i++) {
        //printf("/*     | ��%2d�� |", i + 1);
        Day_show(0, 40 + 40 * (i + 1), 166, 40, i);
        for (int j = 0; j < 5; j++) {
             if (weather_list[i][j] == 0) {
                cout << "    ����    |";
                Fl_Box* Q = new Fl_Box(166 * (j + 1), 40 + 40 * (i + 1), 166, 40, "Clear Weather");
                Q->box(FL_UP_BOX);
                Q->labelfont(FL_BOLD + FL_ITALIC);
                Q->labelsize(20);
                Q->labeltype(FL_SHADOW_LABEL);
             }else if (weather_list[i][j] == 1) {
                cout << "    ����    |";
                Fl_Box* G = new Fl_Box(166 * (j + 1), 40 + 40 * (i + 1), 166, 40, "Hyperthermia");
                G->box(FL_UP_BOX);
                G->labelfont(FL_BOLD + FL_ITALIC);
                G->labelsize(20);
                G->labeltype(FL_SHADOW_LABEL);
             }else if (weather_list[i][j] == 2) {
                cout << "   ɳ����   |";
                Fl_Box* S = new Fl_Box(166 * (j + 1), 40 + 40 * (i + 1), 166, 40, "sandstorm");
                S->box(FL_UP_BOX);
                S->labelfont(FL_BOLD + FL_ITALIC);
                S->labelsize(20);
                S->labeltype(FL_SHADOW_LABEL);
             }else if (weather_list[i][j] == 3) {
                cout << " ����ɳ���� |";
                Fl_Box* GS = new Fl_Box(166 * (j + 1), 40 + 40 * (i + 1), 166, 40, "High-temper storm");
                GS->box(FL_UP_BOX);
                GS->labelfont(FL_BOLD + FL_ITALIC);
                GS->labelsize(20);
                GS->labeltype(FL_SHADOW_LABEL);
             }
        }
             cout << endl;
    }
        cout << "     */" << endl;
    
    //printf("/*                                                                                     */\n");
    //printf("/***************************************************************************************/\n");

//    cout << "�����Ա��ͼ���棡���������ȷ�ϡ�";
//    confirm = _getch();

//    system("cls");
}

void Day_show(int x,int y,int w,int h,int i){
    if (i == 0) { Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D1"); D->labelfont(FL_BOLD + FL_ITALIC);
    D->labelsize(20);
    D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 1) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D2"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 2) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D3"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 3) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D4"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 4) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D5"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 5) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D6"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 6) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D7"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 7) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D8"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 8) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D9"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 9) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D10"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 10) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D11"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 11) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D12"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 12) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D13"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 13) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D14"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 14) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D15"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 15) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D16"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 16) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D17"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 17) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D18"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 18) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D19"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 19) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D20"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 20) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D21"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 21) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D22"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 22) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D23"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 23) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D24"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 24) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D25"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 25) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D26"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 26) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D27"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 27) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D28"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 28) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D29"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 29) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D30"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
    else if (i == 30) {
        Fl_Box* D = new Fl_Box(x, 40 + 40 * (i + 1), 166, 40, "D31"); D->labelfont(FL_BOLD + FL_ITALIC);
        D->labelsize(20);
        D->labeltype(FL_SHADOW_LABEL);
    }
}

// �����б�����
void Weather_list() {
    for (int i = 0; i < ALL_DAY; i++) {
        for (int j = 0; j < 5; j++) {
            weather_list[i][j] = Weather(i, j);
        }
    }
}

// �����������
int Weather(int day, int locations) {
    // ���������
    int a;
    // �����������ʱ�亯��
    a = (rand() + day) * int(time(NULL));
    a = abs(a) % 100;
    // �������ֵõ�����
    // 0-���� 1-���� 2-ɳ���� 3-����ɳ����
    if (locations == 0) {
        if (a <= 70) { return 0; }
        if (a <= 85) { return 1; }
        if (a <= 95) { return 2; }
        return 3;
    }
    else if (locations == 1) {
        if (a <= 45) { return 0; }
        if (a <= 75) { return 1; }
        if (a <= 85) { return 2; }
        return 3;
    }
    else if (locations == 2) {
        if (a <= 80) { return 0; }
        if (a <= 90) { return 1; }
        if (a <= 95) { return 2; }
        return 3;
    }
    else if (locations == 3) {
        if (a <= 85) { return 0; }
        if (a <= 90) { return 1; }
        if (a <= 95) { return 2; }
        return 3;
    }
    else if (locations == 4) {
        if (a <= 65) { return 0; }
        if (a <= 85) { return 1; }
        if (a <= 95) { return 2; }
        return 3;
    }
    return -1;
}