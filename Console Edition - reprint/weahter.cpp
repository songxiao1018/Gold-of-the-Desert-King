#include "weahter.h"

using namespace std;


// 随机天气生成
int Weather(int day, int locations) {
    // 生成随机数
    int a;
    // 随机数处理——时间函数
    a = (rand() + day) * int(time(NULL));
    a = abs(a) % 100;
    // 根据数字得到天气
    // 0-晴天 1-高温 2-沙尘暴 3-高温沙尘暴
    /*************************************/
    /* | 地点 | 晴天 |高温|沙尘暴|高温沙尘暴|*/
    /* | 沙漠 |  70  | 15 |  10  |    5     |*/
    /* | 王陵 |  45  | 30 |  10  |    15    |*/
    /* | 绿洲 |  80  | 10 |  5   |    5     |*/
    /* | 村庄 |  85  |  5 |  5   |    5     |*/
    /* | 大山 |  65  | 20 |  10  |    5     |*/
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

// 天气列表生成
void Weather_list() {
    for (int i = 0; i < ALL_DAY; i++) {
        for (int j = 0; j < 5; j++) {
            weather_list[i][j] = Weather(i, j);
        }
    }
}

// 天气输出
void Weather_list_show() {

    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                天    气     列    表                                */\n");
    printf("/*                                                                                     */\n");
    printf("/*     |  日期  |    沙漠    |    王陵    |    绿洲    |    村庄    |    大山    |     */\n");
    //             /*     | 第01天 |    晴天    |    高温    |   沙尘暴   | 高温沙尘暴 | 高温沙尘暴 |     */ 
    for (int i = 0; i < ALL_DAY; i++) {
        printf("/*     | 第%2d天 |", i + 1);
        for (int j = 0; j < 5; j++) {
            switch (weather_list[i][j]) {
            case 0: cout << "    晴天    |"; break;
            case 1: cout << "    高温    |"; break;
            case 2: cout << "   沙尘暴   |"; break;
            case 3: cout << " 高温沙尘暴 |"; break;
            }
        }
        cout << "     */" << endl;
    }
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    cout << "请管理员截图留存！并按任意键确认。";
    confirm = _getch();

    system("cls");
}

// 当天天气输出
void Weather_show(int day) {

    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------第    四     阶    段--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*---------------------------------各团队解决天气问题----------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------天    气     播    报--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*      第%2d天天气如下：                                                               */\n", day + 1);
    printf("/*          |    沙漠    |    王陵    |    绿洲    |    村庄    |    大山    |         */\n");
    printf("/*          |");

    for (int i = 0; i < 5; i++) {
        switch (weather_list[day][i]) {
        case 0: cout << "    晴天    |"; break;
        case 1: cout << "    高温    |"; break;
        case 2: cout << "   沙尘暴   |"; break;
        case 3: cout << " 高温沙尘暴 |"; break;
        }
    }
    printf("         */\n/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << endl << endl;
}

// 当天天气输出(带地点)
void Weather_location_show(int day, int locations) {
    int k = 0;
    cout << "第" << day + 1 << "天的天气情况如下：" << endl;
    switch (locations) {
    case 0: cout << "沙漠：\t"; k = 0; break;
    case 1: cout << "王陵：\t"; k = 1; break;
    case 2: cout << "绿洲：\t"; k = 2; break;
    case 3: cout << "村庄：\t"; k = 3; break;
    case 4: cout << "大山：\t"; k = 4; break;
    }
    switch (weather_list[day][k]) {
    case 0: cout << "晴天      \t"; break;
    case 1: cout << "高温      \t"; break;
    case 2: cout << "沙尘暴    \t"; break;
    case 3: cout << "高温沙尘暴\t"; break;
    }
    cout << endl;
}
