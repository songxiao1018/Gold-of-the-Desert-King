/************************************************************************************/
/*                                                                                  */
/*                         Project name : Gold of the Desetrt King                  */
/*                         File name    : Gold of the Desert King.cpp               */
/*                                                                                  */
/*                         Author       : Song HY  & Zhang X                        */
/*                                                                                  */
/*                         Start time   : 2021.07.10                                */
/*                         End time     : 2023.07.10                                */
/*                                                                                  */
/*                         School       : Nanjing Xiaozhuang University             */
/*                         Department   : Information Engineering                   */
/*                                                                                  */
/*                         Major        : Artificial Intelligence                   */
/*                                                                                  */
/************************************************************************************/

/************************************************************************************/
/*                                                                                  */
/*                         项目名称：沙漠黄金                                       */
/*                         文件名称：沙漠黄金.cpp                                   */
/*                         项目作者：宋韩尧、张  祥                                 */
/*                         学    校：南京晓庄学院                                   */
/*                         院    系：信息工程学院、人工智能学院                     */
/*                                                                                  */
/*                         起止时间：2023.07.10                                     */
/*                                                                                  */
/************************************************************************************/

/************************************************************************************/
/*                                                                                  */
/*                                   MIT License                                    */
/*                                                                                  */
/*  Copyright (c) 2022 xiaomeng                                                     */
/*                                                                                  */
/*  Permission is hereby granted, free of charge, to any person obtaining a copy    */
/*  of this software and associated documentation files (the "Software"), to deal   */
/*  in the Software without restriction, including without limitation the rights    */
/*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       */
/*  copies of the Software, and to permit persons to whom the Software is           */
/*  furnished to do so, subject to the following conditions:                        */
/*                                                                                  */
/*  The above copyright notice and this permission notice shall be included in all  */
/*  copies or substantial portions of the Software.                                 */
/*                                                                                  */
/*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      */
/*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        */
/*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     */
/*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          */
/*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   */
/*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   */
/*  SOFTWARE.                                                                       */
/*                                                                                  */
/************************************************************************************/

#include <time.h>
#include <iostream>
using namespace std;

struct GROUP {
    int ID = 0;                // 队名
    int alive = 1;             // 是否存活
    int miss = 0;              // 是否迷路
    int back = 0;              // 是否回到大本营
    int rank = -1;             // 排名
    int integral = 1000;       // 积分
    int alive_day = 0;         // 存活天数
    int money = 10000;          // 剩余的金钱
    int residual_load = 10000;  // 剩余的磅重
    int water = 1000;             // 水
    int food = 1000;              // 食物
    int tent = 1000;              // 帐篷
    int compass = 1000;           // 指南针
    string locations = "D";    // 位置
    int gold = 0;              // 黄金
    int card = -1;              // 王陵抽取卡牌编号
    string Bei_zhu = " ";      // 备注
};

GROUP group[100];            // 预设100个队伍


int group_num = 0;       // 队伍数量
int group_back[100];
int game_ranking = 0;
int weather_list[25][5] = {  // 第一维度为天数，第二维度为各地点的天气
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,
};

// 商店系统
void Base_camp_store(int num);    // 大本营购物
void Village_store(int ID);       // 村庄购物
// 天气部分
int   Weather(int day, int locations);                // 天气生成
void Weather_list();                                 // 天气列表生成
void Weather_list_show();                           // 天气列表输出
void Weather_show(int day);                          // 当天天气输出(当天全部地点)
void Weather_location_show(int day, int locations ); // 当天天气输出(带地点)
// 游戏事件
void Oasis_water_intake(int ID);  // 绿洲取水
void Tomb_card(int ID);           // 王陵抽卡
void Struck_gold(int ID);         //大山挖黄金
// 行动系统
void Move_Action(int ID);                // 行动
void Weather_action(int ID, int day);    // 天气行动
// 游戏系统
void Game_start();                // 游戏开始
void Game_going(int day);         // 游戏进行
int  Game_end();                  // 游戏结束
// 系统设置
void Welcome_interface();         // 欢迎界面
void Player_init();               // 游戏人数录入
void Team_supplies();             // 各队物资输出
void Team_supplies_one(int ID);   // 当前队伍数据输出
void Team_information();          // 各队信息
void Team_Integral();             // 计算各队积分

int main() {
    // 欢迎界面
    Welcome_interface();

    return 0;
}

// 游戏人数录入     // 得到队伍数量
void Player_init() {      
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                第    一     阶    段                                */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                  管理员录入团队数                                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         请管理员在下方录入一共有几只队伍！                          */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                      注     意                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                             1.系统建议每队6人。                                     */\n");
    printf("/*                             2.队伍构成建议如下                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                        队  长                                       */\n");
    printf("/*                                           |                                         */\n");
    printf("/*                                  财务官---+---观察员                                */\n");
    printf("/*                                           |                                         */\n");
    printf("/*                            采购员------领驼人------信息员                           */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                             3.更多信息请参考规则介绍。                              */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    cout << "请输入队伍数量：";
    cin >> group_num;
    game_ranking = 0;
    system("cls");
}

// 各队物资输出     // 显示各队物资剩余，未变更数据信息
void Team_supplies(){
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*------------------------------------各队物资信息-------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*          |  队名  | 水 | 食物 | 帐篷 | 指南针 | 黄金 | 零钱钱 | 剩余磅重 |          */\n");
    for (int i = 0; i < group_num; i++) {
        printf("/*          | 第%2d队 | %2d |  %2d  |  %2d  |   %2d   ", i + 1, group[i].water, group[i].food, group[i].tent, group[i].compass);
        printf("|  %2d  |  %4d  |   %4d   |          */\n", group[i].gold, group[i].money, group[i].residual_load);
    }
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "请管理员确认后按1，并回车。";
    int k;
    cin >> k;
    system("cls");
}

// 当前队伍数据输出
void Team_supplies_one(int ID){
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------第%2d队物资信息------------------------------------*/\n", ID + 1);
    printf("/*                                                                                     */\n");
    printf("/*          |  队名  | 水 | 食物 | 帐篷 | 指南针 | 黄金 | 零钱钱 | 剩余磅重 |          */\n");
    printf("/*          | 第%2d队 | %2d |  %2d  |  %2d  |   %2d   ", ID + 1, group[ID].water, group[ID].food, group[ID].tent, group[ID].compass);
    printf("|  %2d  |  %4d  |   %4d   |          */\n", group[ID].gold, group[ID].money, group[ID].residual_load);
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
}

// 各队信息
void Team_information(){
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------第    五     阶    段--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                   所有队伍已到达大本营或葬身沙海，本轮游戏结束！                    */\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------各团队物资清算------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*          |  队名  |  水  |  食物  | 帐篷 | 指南针 | 黄金 | 零钱钱 | 排名 |          */\n");

    for (int i = 0; i < group_num; i++) {
        printf("/*          | 第%2d队 |  %2d  |   %2d   |  %2d  |", i + 1, group[i].water, group[i].food, group[i].tent);
        printf("   %2d   |  %2d  |  %4d  |  %2d  |          */\n", group[i].compass, group[i].gold, group[i].money, group[i].rank + 1);
    }

    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    int k;
    cout << "请输入1，已确认";
    cin >> k;
}

// 计算各队积分
void Team_Integral(){
    for (int i = 0; i < group_num; i++) {
        group[i].integral = group[i].money;

        if (group[i].rank == -1) {
            group[i].integral = 0;
        }
        group[i].integral += group[i].gold * 1000 * group[i].rank;
    }

    system("cls");

    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------游戏结束各队积分如下---------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                            |    队名    |     积分     |                            */\n");
    for (int i = 0; i < group_num; i++) {
        printf("/*                            |   第%2d队   |   %8d   |                            */\n", i + 1, group[i].integral);
    }
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    cout << "请管理员输入1，已确认";
    int k;
    cin >> k;

}

// 欢迎界面        // 选择游戏模式
void Welcome_interface(){
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                  欢迎来到沙漠掘金                                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         请输入您的选择：                                            */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              1.规则介绍                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              2.开始游戏                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              3.开发人员介绍                                         */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              4.项目介绍                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                           本项目由宋韩尧、张祥联合研发                              */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "请输入您的选择：";
    int k;
    cin >> k;
    system("cls");
    switch (k) {
    case 1:
        break;
    case 2:  // 游戏开始
        Game_start();
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    system("cls");
}

// 游戏开始
void Game_start() {
    // 生成全部天气
    Weather_list();

    // 输出全部天气
    Weather_list_show();

    // 获取队伍数量
    Player_init();

    // 大本营购物
    Base_camp_store(group_num);

    // 游戏进行  25天
    for (int i = 0; i < 25; i++) {
        if (Game_end() == 1) {
            break;
        }

        Game_going(i);

    }

    // 输出所有队伍状态
    Team_information();

    Team_Integral();
}

// 游戏进行
void Game_going(int day) {
    // 每队移动
    for (int i = 0; i < group_num; i++) {
        //           存活                    回到大本营 
        if (group[i].alive == 0 || group[i].back == 1) {
            continue;
        }

        // 天数增加 将本队存活天数增加
        group[i].alive_day++;

        // 判断是否迷路  若以迷路则跳过该队
        if (group[i].miss == 1) {
            cout << "您所在的队伍本回合需要找到正确的行动方向！" << endl;
            group[i].miss = 0;
            continue;
        }

        // 行动
        Move_Action(i);
    }

    // 各队解决天气问题
    for (int i = 0; i < group_num; i++) {
        //           存活                    回到大本营 
        if (group[i].alive == 0 || group[i].back == 1) {
            continue;
        }

        // 天气输出 当天
        Weather_show(day);


        // 应对天气
        Weather_action(i, day);

    }

    // 判断是否在绿洲，并安排可以取水队伍取水
    for (int i = 0; i < group_num; i++) {
        //           死亡                    不在绿洲                         磅重不够                        回到大本营
        if (group[i].alive == 0 || group[i].locations[0] != 'L' || group[i].residual_load < 50 || group[i].back == 1) {
            continue;
        }
        Oasis_water_intake(i);
    }

    // 判断是否在村庄，并安排可以购买物资的队伍购物
    for (int i = 0; i < group_num; i++) {
        //           死亡                    不在村庄                         钱不够                  磅重不够                        回到大本营
        if (group[i].alive == 0 || group[i].locations[0] != 'C' || group[i].money < 50 || group[i].residual_load < 10 || group[i].back == 1) {
            continue;
        }
        Village_store(i);
    }

    // 判断是否在大山，并安排可以挖金矿的队伍挖金矿
    for (int i = 0; i < group_num; i++) {
        //           死亡                    不在大山                         磅重不够                        回到大本营
        if (group[i].alive == 0 || group[i].locations[0] != 'M' || group[i].residual_load < 50 || group[i].back == 1) {
            continue;
        }
        Struck_gold(i);
    }

    // 判断是否在王陵，并安排可以抽卡的队伍抽卡
    for (int i = 0; i < group_num; i++) {
        //           死亡                    不在王陵                         钱不够                   回到大本营              已抽卡
        if (group[i].alive == 0 || group[i].locations[0] != 'W' || group[i].money < 100 || group[i].back == 1 || group[i].card != -1) {
            continue;
        }
        Tomb_card(i);
    }

    Team_supplies();
}

// 游戏结束
int  Game_end() {
    for (int i = 0; i < group_num; i++) {
        if (group[i].alive == 1 && group[i].back == 0) {
            return 0;
        }
    }
    return 1;
}

// 天气行动
void Weather_action(int ID, int day) {
    cout << "您好，第" << ID + 1 << "队！您目前在" << group[ID].locations << "。" << endl;
    // 判断天气
    int k = 0;
    string locations = group[ID].locations;
    switch (locations[0]) {
    case 'S': k = 0; break;   // 沙漠
    case 'W': k = 1; break;   // 王陵
    case 'L': k = 2; break;   // 绿洲
    case 'C': k = 3; break;   // 村庄
    case 'M': k = 4; break;   // 大山
    }
    Weather_location_show(day, k);
    switch (weather_list[day][k]) {
    case 0:
        cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
        cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl;
        cout << " |  1     \t| 1      \t|  1     \t|   0    \t|  0     \t| " << endl;
        cout << "您拥有的物资如下：" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "请输入您的选择：";
        cin >> k;
        group[ID].food -= 1;
        group[ID].residual_load += 1 * 10;
        group[ID].water -= 1;
        group[ID].residual_load += 1 * 50;
        break;
    case 1:
        cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
        cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl;
        cout << " |  1     \t| 3      \t|  1     \t|   0    \t|  0     \t| " << endl;
        cout << "您拥有的物资如下：" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "请输入您的选择：";
        cin >> k;
        group[ID].food -= 1;
        group[ID].residual_load += 1 * 10;
        group[ID].water -= 3;
        group[ID].residual_load += 3 * 50;
        break;
    case 2:
        cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
        cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl;
        cout << " |  1     \t| 4      \t|  10    \t|   0    \t|  0     \t| " << endl;
        cout << " |  2     \t| 2      \t|  5     \t|   1    \t|  0     \t| " << endl;
        cout << " |  3     \t| 1      \t|  1     \t|   0    \t|  1     \t| " << endl;
        cout << "您拥有的物资如下：" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "请输入您的选择：";
        cin >> k;
        if (k == 1) {
            group[ID].food -= 10;
            group[ID].residual_load += 10 * 10;
            group[ID].water -= 4;
            group[ID].residual_load += 4 * 50;
            cout << "由于您遇到恶劣天气，并且未做好防护措施，您所在的队伍迷路了，需要一个回合找到方向！" << endl;
            group[ID].miss = 1;
        }
        else if (k == 2 && group[ID].compass > 0) {
            group[ID].food -= 5;
            group[ID].residual_load += 5 * 10;
            group[ID].water -= 2;
            group[ID].residual_load += 2 * 50;
            group[ID].compass -= 1;
            group[ID].residual_load += 1 * 10;
        }
        else if (k == 3 && group[ID].tent > 0) {
            group[ID].food -= 1;
            group[ID].residual_load += 1 * 10;
            group[ID].water -= 1;
            group[ID].residual_load += 1 * 50;
            group[ID].tent -= 1;
            group[ID].residual_load += 1 * 20;
        }
        else {
            cout << "您提供的选项有误或者您没有足够的物资！以按照第一个选项上交！" << endl;
            group[ID].food -= 10;
            group[ID].residual_load += 1 * 10;
            group[ID].water -= 4;
            group[ID].residual_load += 4 * 50;
            cout << "由于您遇到恶劣天气，并且未做好防护措施，您所在的队伍迷路了，需要一个回合找到方向！" << endl;
            group[ID].miss = 1;
        }
        break;
    case 3:
        cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
        cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl;
        cout << " |  1     \t| 8      \t|  10    \t|   0    \t|  0     \t| " << endl;
        cout << " |  2     \t| 4      \t|  5     \t|   1    \t|  0     \t| " << endl;
        cout << " |  3     \t| 3      \t|  1     \t|   0    \t|  1     \t| " << endl;
        cout << "您拥有的物资如下：" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "请输入您的选择：";
        cin >> k;
        if (k == 1) {
            group[ID].food -= 10;
            group[ID].residual_load += 10 * 10;
            group[ID].water -= 8;
            group[ID].residual_load += 8 * 50;
            cout << "由于您遇到恶劣天气，并且未做好防护措施，您所在的队伍迷路了，需要一个回合找到方向！" << endl;
            group[ID].miss = 1;
        }
        else if (k == 2 && group[ID].compass > 0) {
            group[ID].food -= 5;
            group[ID].residual_load += 5 * 10;
            group[ID].water -= 4;
            group[ID].residual_load += 4 * 50;
            group[ID].compass -= 1;
            group[ID].residual_load += 1 * 10;
        }
        else if (k == 3 && group[ID].tent > 0) {
            group[ID].food -= 1;
            group[ID].residual_load += 1 * 10;
            group[ID].water -= 3;
            group[ID].residual_load += 3 * 50;
            group[ID].tent -= 1;
            group[ID].residual_load += 1 * 20;
        }
        else {
            cout << "您提供的选项有误或者您没有足够的物资！以按照第一个选项上交！" << endl;
            group[ID].food -= 10;
            group[ID].residual_load += 10 * 10;
            group[ID].water -= 8;
            group[ID].residual_load += 8 * 10;
            cout << "由于您遇到恶劣天气，并且未做好防护措施，您所在的队伍迷路了，需要一个回合找到方向！" << endl;
            group[ID].miss = 1;
        }
        break;
    default:
        break;
    }

    if (group[ID].food < 0 || group[ID].water < 0) {
        cout << "您的队伍未能穿越沙漠，请下次继续努力！" << endl;
        if (group[ID].food < 0) {
            group[ID].residual_load -= group[ID].food * 10;
            group[ID].food = 0;
        }
        if (group[ID].water < 0) {
            group[ID].residual_load -= group[ID].water * 50;
            group[ID].water = 0;
        }
        group[ID].alive = 0;
        group[ID].back = 1;
                
    }

    if (group[ID].alive == 0) {
        cout << "今天结束！很遗憾你的团队没能成功度过今天。";
    }
    else {
        cout << "今天结束！恭喜你的团队成功度过今天。";
    }
    cout << endl << "您拥有的物资如下：" << endl;
    cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl;
    cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
    cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
    cout << "请输入1，已确认";
    cin >> k;

    system("cls");
}

// 行动
void Move_Action(int ID) {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------第    三     阶    段--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------各团队移动位置------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*      地图简图如下，请各领驼人选择前进方向（输入格子左上角的编号）                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                   +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+                    */\n");
    printf("/*                   |M       |S01        |S02     |C01     |S03  |                    */\n");
    printf("/*                   | 大山   |           |        | 村庄   |     |                    */\n");
    printf("/*                   |        +--------+--+--+-----+--------+     |                    */\n");
    printf("/*                   +-----+--+        |S06  |S07           |     |                    */\n");
    printf("/*                   |S04  |   S05     |     |              +-----+                    */\n");
    printf("/*                   |     |        +--+-----+-----+--------+S10  |                    */\n");
    printf("/*                   +-----+        | W            | S09    |     |                    */\n");
    printf("/*                   |C02  +--------+              |-----+  +-----+                    */\n");
    printf("/*                   |村庄 |S08     |   王   陵    | L01 |  |     |                    */\n");
    printf("/*                   |     |        |              | 绿洲|  | S13 |                    */\n");
    printf("/*                   |     |        |              |-----+--+     |                    */\n");
    printf("/*                   +-----+--------+--+--+-----+--+        |     |                    */\n");
    printf("/*                   |村庄 |S11        |L02 绿洲|   S12     |     |                    */\n");
    printf("/*                   |C03  |           +--------+        +--+-----+                    */\n");
    printf("/*                   +-----+--+--------+--------+--------+D       |                    */\n");
    printf("/*                   | S14    | C04    | S15             | 大本营 |                    */\n");
    printf("/*                   |        |  村庄  |     +--------+  |        |                    */\n");
    printf("/*                   |        |        |     |C05村庄 |  |        |                    */\n");
    printf("/*                   +--------+--------+-----+--------+--+--------+                    */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    string action;
    cout << "您好，第" << ID + 1 << "队！您们目前在" << group[ID].locations << "，请问需要前往什么位置？" << endl;
    cout << "请输入您的目标地点的编号：";
    cin >> action;

    int k = 0;
    while (1) {
        k = 0;
        cout << "请管理员检查输入是否有误？有（1）/无（0）";
        cin >> k;
        if (k == 1) {
            cout << "请重新输入：";
            cin >> action;
        }
        else {
            break;
        }
    }

    group[ID].locations = action;

    system("cls");

    if (action == "D") {
        cout << "恭喜你的队伍回到大本营！" << endl;
        cout << "本次行程共取得" << group[ID].gold << "块黄金！" << endl;
        group[ID].rank = game_ranking;
        game_ranking++;
        group[ID].back = 1;

        cout << "请输入1，已确认";
        cin >> k;
    }

}

//大山挖黄金
void Struck_gold(int ID) {
    cout << "您好第" << ID + 1 << "队。欢迎您到达大山！" << endl;
    int k;
    if (group[ID].residual_load < 50) {
        cout << "您目前在" << group[ID].locations << "，但是没有多余的空间存放黄金，无法挖黄金。";
        return;
    }

    cout << "您目前在" << group[ID].locations << "，并且符合挖金子条件。请问是否挖黄金？（是1/否0）";
    cin >> k;
    if (k == 1) {
        cout << "恭喜你成功挖掘！" << endl;
        group[ID].gold += 1;
        group[ID].residual_load -= 50;
    }

    cout << "请输入1，已确认！";
    cin >> k;

    system("cls");
}

// 王陵抽卡
void Tomb_card(int ID) {
    cout << "您好第" << ID + 1 << "队。欢迎您到达王陵！" << endl;
    int a;
    cout << "您目前在王陵可以和神秘老人获得一条预言，但是需要花费100元，请问是否获得？是（1）/否（0）";
    cin >> a;
    if (a == 0) {
        return;
    }
    group[ID].money -= 100;
    a = rand() * int(time(NULL));
    a = abs(a) % 10;
    switch (a)
    {
    case 0:
        a = 0;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌0号" << endl;
        break;
    case 1:
        a = 1;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌1号" << endl;
        break;
    case 2:
        a = 2;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌2号" << endl;
        break;
    case 3:
        a = 3;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌3号" << endl;
        break;
    case 4:
        a = 4;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌4号" << endl;
        break;
    case 5:
        a = 5;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌5号" << endl;
        break;
    case 6:
        a = 6;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌6号" << endl;
        break;
    case 7:
        a = 7;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌7号" << endl;
        break;
    case 8:
        a = 8;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌8号" << endl;
        break;
    case 9:
        a = 9;
        group[ID].card = a;
        cout << "恭喜你抽到了第" << a << "号卡牌，卡牌内容如下：" << endl;
        cout << "卡牌9号" << endl;
        break;

    default:
        break;
    }

    cout << "请输入1，已确认！";
    cin >> a;

    system("cls");
}

// 绿洲取水
void Oasis_water_intake(int ID) {
    cout << "您好第" << ID + 1 << "队。欢迎您到达绿洲！" << endl;

    int bang4_zhong4_sheng4 = group[ID].residual_load;
    int shui = bang4_zhong4_sheng4 / 50;

    // 判断是否有空间买水
    if (shui < 1) {
        cout << "您不能取水！";
        return;
    }

    // 开始买
    int k;
    // 记录购买数量
    cout << "您可以买" << shui << "罐水，请输入您需要买水的罐数：";
    cin >> k;
    group[ID].residual_load -= 50 * k;
    while (group[ID].residual_load < 0) {
        cout << "磅重超限！请重新输入！";
        // 回退
        group[ID].residual_load += 50 * k;
        // 重新输入
        cin >> k;
        group[ID].residual_load -= 50 * k;
    }
    group[ID].water += k;

    cout << "请输入1，已确认！";
    cin >> k;

    system("cls");
}

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
    for (int i = 0; i < 25; i++) {
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
    for (int i = 0; i < 25; i++) {
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
    int k;
    cout << "请管理员截图留存！已完成请输入1，并回车！";
    cin >> k;
    
    system("cls");
}

// 当天天气输出
void Weather_show(int day ) {

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
void Weather_location_show(int day, int locations ) {
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

// 村庄购物
void Village_store(int ID) {
    cout << "您好第" << ID + 1 << "队。欢迎您到达村庄！" << endl;

    int t;
    cout << "您有" << group[ID].money << "元。" << group[ID].residual_load << "磅。并且身处村庄，请问是否购买物资？是（1）/否（0）";
    cin >> t;
    if (t == 0) {
        return;
    }
    cout << "您有" << group[ID].money << "元。" << group[ID].residual_load << "磅。请输入在村庄购买的水的数量（50元/罐、50磅/罐）：";
    // 记录购买数量
    cin >> t;
    group[ID].money -= 50 * t;
    group[ID].residual_load -= 50 * t;
    while (group[ID].money < 0 || group[ID].residual_load < 0) {
        cout << "零钱或磅重超限！请重新输入！若无多余空间购买请输入0！";
        // 回退
        group[ID].money += 50 * t;
        group[ID].residual_load += 50 * t;
        // 重新输入
        cin >> t;
        group[ID].money -= 50 * t;
        group[ID].residual_load -= 50 * t;
    }
    group[ID].water += t;

    cout << "您有" << group[ID].money << "元。" << group[ID].residual_load << "磅。请输入在村庄购买的食物的数量（20元/罐、10磅/罐）：";
    // 记录购买数量
    cin >> t;
    group[ID].money -= 20 * t;
    group[ID].residual_load -= 10 * t;
    while (group[ID].money < 0 || group[ID].residual_load < 0) {
        cout << "零钱或磅重超限！请重新输入！若无多余空间购买请输入0！";
        // 回退
        group[ID].money += 20 * t;
        group[ID].residual_load += 10 * t;
        // 重新输入
        cin >> t;
        group[ID].money -= 20 * t;
        group[ID].residual_load -= 10 * t;
    }
    group[ID].food += t;

    Team_supplies_one(ID);
    cout << "在村庄购物无法反悔，请输入1确认！";
    cin >> t;

    system("cls");
}

// 大本营购物
void Base_camp_store(int num) {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------第    二     阶    段--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------各团队购买物资------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         请管理员在下方录入一共有几只队伍！                          */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                      注     意                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              在大本营各物资的价目表如下                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                      |     资源     |     定价    |   磅重   |                      */\n");
    printf("/*                      |      水      |     25      |    50    |                      */\n");
    printf("/*                      |     食物     |     10      |    10    |                      */\n");
    printf("/*                      |     帐篷     |     400     |    60    |                      */\n");
    printf("/*                      |    指南针    |     100     |    10    |                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         各采购员注意到村庄购买物资价格翻倍                          */\n");
    printf("/*                                     请慎重考虑                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "请管理员讲解完成后输入1并回车！";
    int k;
    cin >> k;

    system("cls");

    for (int i = 0; i < num; i++) {
        cout << "请输入第" << i + 1 << "组购买的物资！" << endl;
        group[i].ID = i;

        cout << "您有" << group[i].money << "元。" << group[i].residual_load << "磅。请输入在大本营购买的水的数量（25元/罐、50磅/罐）：";
        // 记录购买数量
        cin >> group[i].water;
        group[i].money -= 25 * group[i].water;
        group[i].residual_load -= 50 * group[i].water;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "零钱或磅重超限！请重新输入！若无多余空间购买请输入0！";
            // 回退
            group[i].money += 25 * group[i].water;
            group[i].residual_load += 50 * group[i].water;
            // 重新输入
            cin >> group[i].water;
            group[i].money -= 25 * group[i].water;
            group[i].residual_load -= 50 * group[i].water;
        }

        cout << "您有" << group[i].money << "元。" << group[i].residual_load << "磅。请输入在大本营购买的食物的数量（10元/罐、10磅/罐）：";
        // 记录购买数量
        cin >> group[i].food;
        group[i].money -= 10 * group[i].food;
        group[i].residual_load -= 10 * group[i].food;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "零钱或磅重超限！请重新输入！若无多余空间购买请输入0！";
            // 回退
            group[i].money += 10 * group[i].food;
            group[i].residual_load += 10 * group[i].food;
            // 重新输入
            cin >> group[i].food;
            group[i].money -= 10 * group[i].food;
            group[i].residual_load -= 10 * group[i].food;
        }

        cout << "您有" << group[i].money << "元。" << group[i].residual_load << "磅。请输入在大本营购买的帐篷的数量（400元/3顶、20磅/顶、三个一组）：";
        // 记录购买数量
        cin >> group[i].tent;
        group[i].money -= 400 * group[i].tent;
        group[i].residual_load -= 60 * group[i].tent;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "零钱或磅重超限！请重新输入！若无多余空间购买请输入0！";
            // 回退
            group[i].money += 400 * group[i].tent;
            group[i].residual_load += 60 * group[i].tent;
            // 重新输入
            cin >> group[i].tent;
            group[i].money -= 400 * group[i].tent;
            group[i].residual_load -= 60 * group[i].tent;
        }
        group[i].tent *= 3;

        cout << "您有" << group[i].money << "元。" << group[i].residual_load << "磅。请输入在大本营购买的指南针的数量（100元/个、10磅/个）：";
        // 记录购买数量
        cin >> group[i].compass;
        group[i].money -= 100 * group[i].compass;
        group[i].residual_load -= 10 * group[i].compass;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "零钱或磅重超限！请重新输入！若无多余空间购买请输入0！";
            // 回退
            group[i].money += 100 * group[i].compass;
            group[i].residual_load += 10 * group[i].compass;
            // 重新输入
            cin >> group[i].compass;
            group[i].money -= 100 * group[i].compass;
            group[i].residual_load -= 10 * group[i].compass;
        }

        Team_supplies_one(i);

        int k = 0;
        cout << "是否有误？有（1）/无（0）";
        cin >> k;
        if (k == 1) {
            group[i].money = 1000;
            group[i].residual_load = 1000;
            // 回退一队。实现重新输入
            i--;
        }
        system("cls");
    }
    Team_supplies();
}
