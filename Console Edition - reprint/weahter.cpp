#include "weahter.h"

using namespace std;


// �����������
int Weather(int day, int locations) {
    // ���������
    int a;
    // �����������ʱ�亯��
    a = (rand() + day) * int(time(NULL));
    a = abs(a) % 100;
    // �������ֵõ�����
    // 0-���� 1-���� 2-ɳ���� 3-����ɳ����
    /*************************************/
    /* | �ص� | ���� |����|ɳ����|����ɳ����|*/
    /* | ɳĮ |  70  | 15 |  10  |    5     |*/
    /* | ���� |  45  | 30 |  10  |    15    |*/
    /* | ���� |  80  | 10 |  5   |    5     |*/
    /* | ��ׯ |  85  |  5 |  5   |    5     |*/
    /* | ��ɽ |  65  | 20 |  10  |    5     |*/
    /*************************************/
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

// �����б�����
void Weather_list() {
    for (int i = 0; i < ALL_DAY; i++) {
        for (int j = 0; j < 5; j++) {
            weather_list[i][j] = Weather(i, j);
        }
    }
}

// �������
void Weather_list_show() {

    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                ��    ��     ��    ��                                */\n");
    printf("/*                                                                                     */\n");
    printf("/*     |  ����  |    ɳĮ    |    ����    |    ����    |    ��ׯ    |    ��ɽ    |     */\n");
    //             /*     | ��01�� |    ����    |    ����    |   ɳ����   | ����ɳ���� | ����ɳ���� |     */ 
    for (int i = 0; i < ALL_DAY; i++) {
        printf("/*     | ��%2d�� |", i + 1);
        for (int j = 0; j < 5; j++) {
            switch (weather_list[i][j]) {
            case 0: cout << "    ����    |"; break;
            case 1: cout << "    ����    |"; break;
            case 2: cout << "   ɳ����   |"; break;
            case 3: cout << " ����ɳ���� |"; break;
            }
        }
        cout << "     */" << endl;
    }
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    cout << "�����Ա��ͼ���棡���������ȷ�ϡ�";
    confirm = _getch();

    system("cls");
}

// �����������
void Weather_show(int day) {

    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*---------------------------------���Ŷӽ����������----------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*      ��%2d���������£�                                                               */\n", day + 1);
    printf("/*          |    ɳĮ    |    ����    |    ����    |    ��ׯ    |    ��ɽ    |         */\n");
    printf("/*          |");

    for (int i = 0; i < 5; i++) {
        switch (weather_list[day][i]) {
        case 0: cout << "    ����    |"; break;
        case 1: cout << "    ����    |"; break;
        case 2: cout << "   ɳ����   |"; break;
        case 3: cout << " ����ɳ���� |"; break;
        }
    }
    printf("         */\n/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << endl << endl;
}

// �����������(���ص�)
void Weather_location_show(int day, int locations) {
    int k = 0;
    cout << "��" << day + 1 << "�������������£�" << endl;
    switch (locations) {
    case 0: cout << "ɳĮ��\t"; k = 0; break;
    case 1: cout << "���꣺\t"; k = 1; break;
    case 2: cout << "���ޣ�\t"; k = 2; break;
    case 3: cout << "��ׯ��\t"; k = 3; break;
    case 4: cout << "��ɽ��\t"; k = 4; break;
    }
    switch (weather_list[day][k]) {
    case 0: cout << "����      \t"; break;
    case 1: cout << "����      \t"; break;
    case 2: cout << "ɳ����    \t"; break;
    case 3: cout << "����ɳ����\t"; break;
    }
    cout << endl;
}
