/************************************************************************************/
/*                                                                                  */
/*                         Project name : Gold of the Desetrt King                  */
/*                         File name    : Gold of the Desert King.cpp               */
/*                                                                                  */
/*                         Author       : Song HY                                   */
/*                                                                                  */
/*                         Start time   : 2024.03.15                                */
/*                         End time     :                                           */
/*                                                                                  */
/*                         School       : Nanjing Xiaozhuang University             */
/*                         Department   : Information Engineering                   */
/*                                                                                  */
/*                         Major        : Artificial Intelligence                   */
/*                                                                                  */
/************************************************************************************/

/************************************************************************************/
/*                                                                                  */
/*                                   MIT License                                    */
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
#include <conio.h>
#include <iostream>
#include <string>
#include <cstdio>

#include <fstream>
using namespace std;

#define FOOD_Base       10
#define FOOD_Village    5
#define FOOD_Load       10

#define WATER_Base      25
#define WATER_Village   15
#define WATER_Load      50

#define TENT_Base       400
#define TENT_Village    100
#define TENT_Load       20

#define COMPASS_Base    100
#define COMPASS_Village 50
#define COMPASS_Load    10

struct GROUP {
    int ID = 0;                  // ����
    int alive = 1;               // �Ƿ���
    int miss = 0;                // �Ƿ���·
    int back = 0;                // �Ƿ�ص���Ӫ
    int rank = -1;               // ����
    int integral = 1000;         // ����
    int alive_day = 0;           // �������
    int money = 1000;            // ʣ��Ľ�Ǯ
    int residual_load = 1000;    // ʣ��İ���
    int water = 1;               // ˮ
    int food = 1;                // ʳ��
    int tent = 1;                // ����
    int compass = 1;             // ָ����
    string locations = "D";      // λ��
    int gold = 0;                // �ƽ�
    int card = -1;               // ��ȡ���Ʊ��
    int W_card = -1;             // �����ȡ���Ʊ��
    int C_card = -1;             // ��ׯ��ȡ���Ʊ��
    int L_card = -1;             // ���޳�ȡ���Ʊ��
    string Bei_zhu = " ";        // ��ע
};

GROUP group[100];                // Ԥ��100������
int ALL_DAY = 15;                // ��Ϸ����
char confirm;                    // ����ȷ�ϻز�
int group_num = 0;               // ��������
int game_day = 0;                // ��Ϸ����
int game_ranking = 0;            // ����
int back_day = 0;                // ��һ�ӵ�������

int weather_list[30][5] = {
    { 0 , 2 , 0 , 1 , 0 } ,{ 1 , 1 , 1 , 0 , 0 } ,
    { 2 , 2 , 0 , 1 , 0 } ,{ 0 , 1 , 0 , 0 , 1 } ,{ 1 , 3 , 1 , 0 , 0 } ,
    { 0 , 2 , 0 , 1 , 1 } ,{ 1 , 2 , 1 , 0 , 2 } ,
    { 0 , 2 , 0 , 1 , 0 } ,{ 3 , 1 , 1 , 0 , 1 } ,{ 2 , 1 , 0 , 0 , 0 } ,
    { 0 , 0 , 0 , 0 , 0 } ,{ 2 , 1 , 1 , 0 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,
    { 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 } ,{ 0 , 1 , 2 , 3 , 0 }
};

string MAP[25][10] = {
    {"W"  ,"S05","S06","S07","S09","L01","S12","L02","S11","S08"},
    {"M"  ,"S01","S04","S05"},
    {"D"  ,"S15","S12","S13"},

    {"S01","M"  ,"S05","S06","S02"},
    {"S02","S01","S06","S07","C01"},
    {"S03","C01","S07","S10"},
    {"S04","M"  ,"S05","C02"},
    {"S05","M"  ,"S01","S06","W"  ,"S08","C02","S04"},
    {"S06","S01","S02","S07","W"  ,"S05"},
    {"S07","S02","C01","S03","S10","S09","W"  ,"S06"},
    {"S08","C02","S05","W"  ,"S11"},
    {"S09","W"  ,"S07","S10","L01","S12","S13"},
    {"S10","S07","S03","S13","S09"},
    {"S11","S08","C03","S14","C04","S15","S12","L02","W"},
    {"S12","W"  ,"L01","S09","S13","D"  ,"S15","S11","L02"},
    {"S13","S09","S10","D"  ,"S12"},
    {"S14","C03","S11","C04"},
    {"S15","C04","C05","S11","D"  ,"S12"},

    {"C01","S02","S07","S03"},
    {"C02","S04","S05","S08","C03"},
    {"C03","C02","S11","S14"},
    {"C04","S14","S11","S15"},
    {"C05","S15"},

    {"L01","W"  ,"S09","S12"},
    {"L02","S11","W"  ,"S12"},
};

// UI
void Welcome_interface();         // ��ӭ����
void Developer_introduction();    // ������Ա����
void Development_history();       // ��������
void Introduction_rules();        // �������
// �̵�ϵͳ
void Buy(int ID, int num, int price, int weight);  // ����
void Base_camp_store(int num);    // ��Ӫ����
void Village_store(int ID);       // ��ׯ����
// ��������
int  Weather(int day, int locations);                // ��������
void Weather_list();                                 // �����б�����
void Weather_list_show();                             // �����б����
void Weather_show(int day);                          // �����������(����ȫ���ص�)
void Weather_location_show(int day, int locations); // �����������(���ص�)
// ��Ϸ�¼�
void Oasis_water_intake(int ID);         // ����ȡˮ
void Tomb_card(int ID);                  // ����鿨
void Struck_gold(int ID);                //��ɽ�ڻƽ�
void Black_market(int Team1, int Team2); // ���н���
// �ж�ϵͳ
void Move_Action(int ID);                // �ж�
int  Move_map(int ID, string action);    // ��ͼ�ж�
void Weather_action(int ID, int day);    // �����ж�
// ��Ϸϵͳ
void Game_start();                // ��Ϸ��ʼ
void Game_going(int day);         // ��Ϸ����
int  Game_end();                  // ��Ϸ����
// ϵͳ����
void Player_init();               // ��Ϸ����¼��
void Team_supplies();             // �����������
void Team_supplies_one(int ID);   // ��ǰ�����������
void Team_information();          // ������Ϣ
void Team_Integral();             // ������ӻ���



int main() {

    // ͼ��·��
    const char* imagePath = "map.jpg";

    // �Զ�����ֻ����ʽ��ͼ���ļ�
    FILE* file = nullptr;
    fopen_s(&file, imagePath, "rb");
    if (file == nullptr) {
        std::cout << "�޷���ͼ���ļ�" << std::endl;
        return -1;
    }

    // ��ӭ���� 
    Welcome_interface();

    return 0;
}

// ��Ϸ����¼��     // �õ���������
void Player_init() {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                ��    һ     ��    ��                                */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                  ����Ա¼���Ŷ���                                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         �����Ա���·�¼��һ���м�ֻ���飡                          */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                      ע     ��                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                             1.ϵͳ����ÿ��6�ˡ�                                     */\n");
    printf("/*                             2.���鹹�ɽ�������                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                        ��  ��                                       */\n");
    printf("/*                                           |                                         */\n");
    printf("/*                                  �����---+---�۲�Ա                                */\n");
    printf("/*                                           |                                         */\n");
    printf("/*                            �ɹ�Ա------������------��ϢԱ                           */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                             3.������Ϣ��ο�������ܡ�                              */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    cout << "���������������";
    cin >> group_num;
    game_ranking = 0;
    system("cls");
}

// �����������     // ��ʾ��������ʣ�࣬δ���������Ϣ
void Team_supplies() {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*------------------------------------����������Ϣ-------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*          |  ����  | ˮ | ʳ�� | ���� | ָ���� | �ƽ� | ��ǮǮ | ʣ����� |          */\n");
    for (int i = 0; i < group_num; i++)
        printf("/*          | ��%2d�� | %2d |  %2d  |  %2d  |   %2d   |  %2d  |  %4d  |   %4d   |          */\n"
                , i + 1, group[i].water, group[i].food, group[i].tent, group[i].compass, group[i].gold, group[i].money, group[i].residual_load);
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "�����Ա�������ȷ�ϡ�";
    confirm = _getch();
    system("cls");
}

// ��ǰ�����������
void Team_supplies_one(int ID) {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------��%2d��������Ϣ------------------------------------*/\n", ID + 1);
    printf("/*                                                                                     */\n");
    printf("/*          |  ����  | ˮ | ʳ�� | ���� | ָ���� | �ƽ� | ��ǮǮ | ʣ����� |          */\n");
    printf("/*          | ��%2d�� | %2d |  %2d  |  %2d  |   %2d   |  %2d  |  %4d  |   %4d   |          */\n"
            , ID + 1, group[ID].water, group[ID].food, group[ID].tent, group[ID].compass, group[ID].gold, group[ID].money, group[ID].residual_load);
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
}

// ������Ϣ
void Team_information() {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                   ���ж����ѵ����Ӫ������ɳ����������Ϸ������                    */\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------���Ŷ���������------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*          |  ����  |  ˮ  |  ʳ��  | ���� | ָ���� | �ƽ� | ��ǮǮ | ���� |          */\n");
    for (int i = 0; i < group_num; i++)
        printf("/*          | ��%2d�� |  %2d  |   %2d   |  %2d  |   %2d   |  %2d  |  %4d  |  %2d  |          */\n"
                , i + 1, group[i].water, group[i].food, group[i].tent, group[i].compass, group[i].gold, group[i].money, group[i].rank + 1);
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    cout << "�����Ա�������ȷ�ϡ�";
    confirm = _getch();
}

// ������ӻ���
void Team_Integral() {
    for (int i = 0; i < group_num; i++) {
        group[i].integral = group[i].money;

        if (group[i].rank == -1) {
            group[i].integral = 0;
        }
        group[i].integral += group[i].gold * 50 * 10 * (11 - group[i].rank);
    }

    system("cls");

    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��Ϸ�������ӻ�������---------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                            |    ����    |     ����     |                            */\n");
    for (int i = 0; i < group_num; i++) {
        printf("/*                            |   ��%2d��   |   %8d   |                            */\n", i + 1, group[i].integral);
    }
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");

    cout << "�����Ա�������ȷ�ϡ�";
    confirm = _getch();
}

// ������Ա����
void Developer_introduction() {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        ��֮���Ŷ�                                                                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        ������һ֧��������ʹ������ĿƼ��Ŷӣ������ڽ�����ӵļ���������ƶ�         */\n");
    printf("/*    ���¡����ǵ��Ŷ���һȺӵ�зḻ�����רҵ֪ʶ�ļ���ר����ɣ��ó���������         */\n");
    printf("/*    ��                                                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        1. ����ר����                                                                */\n");
    printf("/*        ������C/C++��Java����ӵ������רҵ֪ʶ�;��顣������Ϥ���µļ�������        */\n");
    printf("/*    �ͷ�չ�����ܹ�Ӧ��������������ӵ����⡣                                         */\n");
    printf("/*                                                                                     */\n");
    printf("/*        2. �ŶӺ�����                                                                */\n");
    printf("/*        ���ǵ��Ŷ�ע�غ�����Э����ÿ����Ա���߱����õĹ�ͨ���ŶӺ�����������         */\n");
    printf("/*    ������ͨ������֪ʶ�;��飬�����ܹ���ͬ������ӵ����⣬���ṩ��ѽ��������       */\n");
    printf("/*                                                                                     */\n");
    printf("/*        3. ���¾���                                                                */\n");
    printf("/*        ���ǹ����Ŷӳ�Ա���ִ��¾��񣬲�����׷������ͻ�ƺʹ��¡����ǹ�����         */\n");
    printf("/*    �ӳ�Ա����µ��뷨�ͽ����������Ϊ�����ṩ֧�ֺ���Դ����ʵ�����ǵĴ����         */\n");
    printf("/*    Ǳ����                                                                           */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        ���������Ѱ��һ֧���о���ʹ��¾���ĿƼ��Ŷӣ�����Ը��������������         */\n");
    printf("/*    ͬ���������ս��ʵ��ҵ��Ŀ�ꡣ����������ϵ���˽������������Ŷӵ���Ϣ��         */\n");
    printf("/*    ������Ϊ���ṩ�ķ���                                                           */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "�밴�����������";
    confirm = _getch();
}

// ��������
void Development_history() {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*---------------------------------------V 1.0.0---------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*    2023-7-10 ��Ŀ����                                                               */\n");
    printf("/*                                                                                     */\n");
    printf("/*    2023-7-18 ��ɻ�����Ϸ�߼�                                                       */\n");
    printf("/*                                                                                     */\n");
    printf("/*    2023-7-21 ��Ϸ�����                                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*    2023-7-22 ���Ϸ����                                                           */\n");
    printf("/*                                                                                     */\n");
    printf("/*    2023-7-23 ��Ŀ���                                                               */\n");
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
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "�밴�����������";
    confirm = _getch();
}

// �������
void Introduction_rules() {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        �ܶ���ǰ����̽�������˼������ĵط�����ط�����һ����طḻ�Ľ�󣬲�����     */\n");
    printf("/*    ���ط�ȡ��Ϊ��ɽ����Ϣ�����󣬲�������֮���͡�                                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        ���ڣ���Щ���صȴ��������򡭡�                                                 */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        �����鹹�����£�                                                           */\n");
    printf("/*                                                                                     */\n");
    printf("/*        �ӳ��������̵�ͳ������������ߣ����Ŷӳ�Ա����                         */\n");
    printf("/*        ����٣��ƹ�ȫ�ӵĲƲ������ʣ�����ÿ������ģ���д���߱�                     */\n");
    printf("/*        �۲�Ա������������̾��ߣ��۲�ÿλ��Ա�Ĺ��̱��֣������跴��               */\n");
    printf("/*        �ɹ�Ա���ӽ������Ĳɹ�/������������                                          */\n");
    printf("/*        �����ˣ������ն��н�·�ߣ��ල�����ն��н�·�ߣ���ȡ���ڻƽ�               */\n");
    printf("/*        ��ϢԱ���ռ������ڱ��ն�Ŀ��ʵ�ֵĸ����鱨                                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*        �Ӵ�Ӫ������ÿ��ֻ���н������ڵ�һ��                                     */\n");
    printf("/*        25���ڱ���ص���Ӫ��������ǡ�����ɳ������                                   */\n");
    printf("/*        ̽��;�У��κ�һ����������������ˮ������������ɳ�������öӼ��Զ��˳���       */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "�밴�����������";
    confirm = _getch();
}

// ��ӭ����        // ѡ����Ϸģʽ
void Welcome_interface() {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                  ��ӭ����ɳĮ���                                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         ����������ѡ��                                            */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              1.�������                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              2.��ʼ��Ϸ                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              3.�Ŷӽ���                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              4.��Ŀ����                                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              5.�˳�                                                 */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                        ���γ��� ���ô�Eagle��s Flight��˾ �з�                       */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                 �� ��֮�� �ŶӸı�                                  */\n");
    printf("/*                          ����Ŀ���ս���Ȩ����֮���Ŷ�����                           */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "����������ѡ��";
    confirm = _getch();
    system("cls");
    switch (confirm) {
    case '1':  // �������
        Introduction_rules();
        system("cls");
        Welcome_interface();
        break;
    case '2':  // ��Ϸ��ʼ
        Game_start();
        system("cls");
        Welcome_interface();
        break;
    case '3':  // �Ŷӽ���
        Developer_introduction();
        system("cls");
        Welcome_interface();
        break;
    case '4':  // ��Ŀ����
        Development_history();
        system("cls");
        Welcome_interface();
        break;
    default:
        break;
    }
    system("cls");
    return;
}

// ��Ϸ��ʼ
void Game_start() {
    // ����ȫ������
//    Weather_list();

    // ���ȫ������
    Weather_list_show();

    // ��ȡ��������
    Player_init();

    // ��Ӫ����
    Base_camp_store(group_num);

    // ��Ϸ����
    for (game_day = 0; game_day < ALL_DAY; game_day++) {
        if (Game_end() == 1) {
            break;
        }

        Game_going(game_day);

    }

    // ������ж���״̬
    Team_information();

    Team_Integral();
}

// ��Ϸ����
void Game_going(int day) {
    // ÿ���ƶ�
    for (int i = 0; i < group_num; i++) {
        //           ���                    �ص���Ӫ 
        if (group[i].alive == 0 || group[i].back == 1) {
            continue;
        }

        // �������� �����Ӵ����������
        group[i].alive_day++;

        // �ж��Ƿ���·  ������·�������ö�
        if (group[i].miss == 1) {
            cout << "�����ڵĶ��鱾�غ���Ҫ�ҵ���ȷ���ж�����" << endl;
            group[i].miss = 0;
            continue;
        }

        // �ж�
        Move_Action(i);
    }

    // ���ӽ����������
    for (int i = 0; i < group_num; i++) {
        //           ���                    �ص���Ӫ 
        if (group[i].alive == 0 || group[i].back == 1) {
            continue;
        }

        // ������� ����
        Weather_show(day);


        // Ӧ������
        Weather_action(i, day);

    }

    // �ж��Ƿ������ޣ������ſ���ȡˮ����ȡˮ
    for (int i = 0; i < group_num; i++) {
        //           ����                    ��������                         ���ز���                        �ص���Ӫ
        if (group[i].alive == 0 || group[i].locations[0] != 'L' || group[i].residual_load < 50 || group[i].back == 1) {
            continue;
        }
        Oasis_water_intake(i);
    }

    // �ж��Ƿ��ڴ�ׯ�������ſ��Թ������ʵĶ��鹺��
    for (int i = 0; i < group_num; i++) {
        //           ����                    ���ڴ�ׯ                         Ǯ����                  ���ز���                        �ص���Ӫ
        if (group[i].alive == 0 || group[i].locations[0] != 'C' || group[i].money < 50 || group[i].residual_load < 10 || group[i].back == 1) {
            continue;
        }
        Village_store(i);
    }

    // �ж��Ƿ��ڴ�ɽ�������ſ����ڽ��Ķ����ڽ��
    for (int i = 0; i < group_num; i++) {
        //           ����                    ���ڴ�ɽ                         ���ز���                        �ص���Ӫ
        if (group[i].alive == 0 || group[i].locations[0] != 'M' || group[i].residual_load < 50 || group[i].back == 1) {
            continue;
        }
        Struck_gold(i);
    }

    // �ж��Ƿ������꣬�����ſ��Գ鿨�Ķ���鿨
    for (int i = 0; i < group_num; i++) {
        //           ����                    ��������                         Ǯ����                   �ص���Ӫ              �ѳ鿨
        if (group[i].alive == 0 || group[i].locations[0] != 'W' || group[i].money < 100 || group[i].back == 1 || group[i].card != -1) {
            continue;
        }
        Tomb_card(i);
    }

    // �ж��Ƿ���ں��н���
    cout << "�����Ƿ���ں��н��ף��ǣ�1��/��0��";
    int k;
    cin >> k;
    while (k == 1) {
        char Team1, Team2;
        cout << "���������ӵı�ţ��м��ÿո�ָ�������������������c���س���" << endl;
        cin >> Team1;
        if (Team1 == 'c') {
            break;
        }
        cin >> Team2;
        Team1--, Team2--;
        Black_market(Team1 - '0', Team2 - '0');

        cout << "�����Ƿ���ں��н��ף��ǣ�1��/��0��";
        cin >> k;
    }


    system("cls");

    Team_supplies();
}

// ���н���
void Black_market(int Team1, int Team2) {
    system("cls");
    if (group[Team1].alive == 0 || group[Team2].alive == 0) {
        cout << "�Բ��𣬰������������飬�޷����ף�" << endl;
        cout << "�밴�����ȷ�ϡ�";
        confirm = _getch();
        system("cls");
        return;
    }
    if (group[Team1].locations != group[Team2].locations) {
        cout << "�Բ��������Ӳ���ͬһ���޷����ף�" << endl;
        cout << "�밴�����ȷ�ϡ�";
        confirm = _getch();
        system("cls");
        return;
    }
    cout << "����Ϊ���������嵥" << endl;
    Team_supplies_one(Team1);
    Team_supplies_one(Team2);

    int T1W, T1F, T1T, T1C, T1G, T1M, T2W, T2F, T2T, T2C, T2G, T2M;
    cout << "�����ӷֱ�����˳�����뽻�׵����ʣ�������������0���м��ÿո�ָ" << endl;
    cout << "\t| ˮ | ʳ�� | ���� | ָ���� | �ƽ� |  ��Ǯ  |\n";
    cout << "��" << Team1 + 1 << "��\t";
    cin >> T1W >> T1F >> T1T >> T1C >> T1G >> T1M;
    cout << "��" << Team2 + 1 << "��\t";
    cin >> T2W >> T2F >> T2T >> T2C >> T2G >> T2M;



    if (group[Team1].water - T1W < 0 || group[Team1].food - T1F < 0 || group[Team1].tent - T1T < 0 || group[Team1].compass - T1C < 0 || group[Team1].gold - T1G < 0 || group[Team1].money - T1M < 0) {
        cout << "�Բ����" << Team1 + 1 << "�ӣ���û���㹻�����ʽ�����" << endl;
        cout << "�밴�����ȷ�ϡ�";
        confirm = _getch();
        return;
    }
    if (group[Team2].water - T2W < 0 || group[Team2].food - T2F < 0 || group[Team2].tent - T2T < 0 || group[Team2].compass - T2C < 0 || group[Team2].gold - T2G < 0 || group[Team2].money - T2M < 0) {
        cout << "�Բ����" << Team2 + 1 << "�ӣ���û���㹻�����ʽ�����" << endl;
        cout << "�밴�����ȷ�ϡ�";
        confirm = _getch();
        return;
    }

    // �������� �жϳ���
    group[Team1].residual_load = group[Team1].residual_load - T1W * 50 - T1F * 10 - T1T * 20 - T1C * 10 - T1G * 50;
    group[Team1].residual_load = group[Team1].residual_load + T2W * 50 + T2F * 10 + T2T * 20 + T2C * 10 + T2G * 50;

    group[Team2].residual_load = group[Team2].residual_load - T2W * 50 - T2F * 10 - T2T * 20 - T2C * 10 - T2G * 50;
    group[Team2].residual_load = group[Team2].residual_load + T1W * 50 + T1F * 10 + T1T * 20 + T1C * 10 + T1G * 50;

    if (group[Team1].residual_load < 0 || group[Team2].residual_load < 0 || group[Team1].residual_load > 1000 || group[Team2].residual_load > 1000) {
        cout << "���س��ޣ��޷���ɽ��ף�" << endl;
        // ����
        group[Team1].residual_load = group[Team1].residual_load + T1W * 50 + T1F * 10 + T1T * 20 + T1C * 10 + T1G * 50;
        group[Team1].residual_load = group[Team1].residual_load - T2W * 50 - T2F * 10 - T2T * 20 - T2C * 10 - T2G * 50;

        group[Team2].residual_load = group[Team2].residual_load + T2W * 50 + T2F * 10 + T2T * 20 + T2C * 10 + T2G * 50;
        group[Team2].residual_load = group[Team2].residual_load - T1W * 50 - T1F * 10 - T1T * 20 - T1C * 10 - T1G * 50;

        Team_supplies_one(Team1);
        Team_supplies_one(Team2);
        cout << "�밴�����ȷ�ϡ�";
        confirm = _getch();
        system("cls");
        return;
    }

    group[Team1].water = group[Team1].water + T2W - T1W;
    group[Team1].food = group[Team1].food + T2F - T1F;
    group[Team1].tent = group[Team1].tent + T2T - T1T;
    group[Team1].compass = group[Team1].compass + T2C - T1C;
    group[Team1].gold = group[Team1].gold + T2G - T1G;
    group[Team1].money = group[Team1].money + T2M - T1M;

    group[Team2].water = group[Team2].water + T1W - T2W;
    group[Team2].food = group[Team2].food + T1F - T2F;
    group[Team2].tent = group[Team2].tent + T1T - T2T;
    group[Team2].compass = group[Team2].compass + T1C - T2C;
    group[Team2].gold = group[Team2].gold + T1G - T2G;
    group[Team2].money = group[Team2].money + T1M - T2M;

    cout << "��ϲ�ɹ����ף�����Ϊ���������嵥" << endl;
    Team_supplies_one(Team1);
    Team_supplies_one(Team2);
    cout << "�밴�����ȷ�ϡ�";
    confirm = _getch();

    system("cls");


}

// ��Ϸ����
int  Game_end() {
    for (int i = 0; i < group_num; i++) {
        if (group[i].alive == 1 && group[i].back == 0) {
            return 0;
        }
    }
    return 1;
}

// �����ж�
void Weather_action(int ID, int day) {
    cout << "���ã���" << ID + 1 << "�ӣ���Ŀǰ��" << group[ID].locations << "��" << endl;
    // �ж�����
    int k = 0;
    string locations = group[ID].locations;
    switch (locations[0]) {
    case 'S': k = 0; break;   // ɳĮ
    case 'W': k = 1; break;   // ����
    case 'L': k = 2; break;   // ����
    case 'C': k = 3; break;   // ��ׯ
    case 'M': k = 4; break;   // ��ɽ
    }
    Weather_location_show(day, k);
    switch (weather_list[day][k]) {
    case 0:
        cout << "�������Ͻ��������±���ѡ������һ��ѡ���Ͻ���" << endl;
        cout << " | ѡ��   \t| ˮ     \t| ʳ��   \t| ָ���� \t| ����   \t| " << endl;
        cout << " |  1     \t| 1      \t|  1     \t|   0    \t|  0     \t| " << endl;
        cout << "��ӵ�е��������£�" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "����������ѡ��";
        cin >> k;
        group[ID].food -= 1;
        group[ID].residual_load += 1 * 10;
        group[ID].water -= 1;
        group[ID].residual_load += 1 * 50;
        break;
    case 1:
        cout << "�������Ͻ��������±���ѡ������һ��ѡ���Ͻ���" << endl;
        cout << " | ѡ��   \t| ˮ     \t| ʳ��   \t| ָ���� \t| ����   \t| " << endl;
        cout << " |  1     \t| 3      \t|  1     \t|   0    \t|  0     \t| " << endl;
        cout << "��ӵ�е��������£�" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "����������ѡ��";
        cin >> k;
        group[ID].food -= 1;
        group[ID].residual_load += 1 * 10;
        group[ID].water -= 3;
        group[ID].residual_load += 3 * 50;
        break;
    case 2:
        cout << "�������Ͻ��������±���ѡ������һ��ѡ���Ͻ���" << endl;
        cout << " | ѡ��   \t| ˮ     \t| ʳ��   \t| ָ���� \t| ����   \t| " << endl;
        cout << " |  1     \t| 4      \t|  10    \t|   0    \t|  0     \t| " << endl;
        cout << " |  2     \t| 2      \t|  5     \t|   1    \t|  0     \t| " << endl;
        cout << " |  3     \t| 1      \t|  1     \t|   0    \t|  1     \t| " << endl;
        cout << "��ӵ�е��������£�" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "����������ѡ��";
        cin >> k;
        if (k == 1) {
            group[ID].food -= 10;
            group[ID].residual_load += 10 * 10;
            group[ID].water -= 4;
            group[ID].residual_load += 4 * 50;
            cout << "������������������������δ���÷�����ʩ�������ڵĶ�����·�ˣ���Ҫһ���غ��ҵ�����" << endl;
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
            cout << "���ṩ��ѡ�����������û���㹻�����ʣ��԰��յ�һ��ѡ���Ͻ���" << endl;
            group[ID].food -= 10;
            group[ID].residual_load += 1 * 10;
            group[ID].water -= 4;
            group[ID].residual_load += 4 * 50;
            cout << "������������������������δ���÷�����ʩ�������ڵĶ�����·�ˣ���Ҫһ���غ��ҵ�����" << endl;
            group[ID].miss = 1;
        }
        break;
    case 3:
        cout << "�������Ͻ��������±���ѡ������һ��ѡ���Ͻ���" << endl;
        cout << " | ѡ��   \t| ˮ     \t| ʳ��   \t| ָ���� \t| ����   \t| " << endl;
        cout << " |  1     \t| 8      \t|  10    \t|   0    \t|  0     \t| " << endl;
        cout << " |  2     \t| 4      \t|  5     \t|   1    \t|  0     \t| " << endl;
        cout << " |  3     \t| 3      \t|  1     \t|   0    \t|  1     \t| " << endl;
        cout << "��ӵ�е��������£�" << endl;
        cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
        cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
        cout << "����������ѡ��";
        cin >> k;
        if (k == 1) {
            group[ID].food -= 10;
            group[ID].residual_load += 10 * 10;
            group[ID].water -= 8;
            group[ID].residual_load += 8 * 50;
            cout << "������������������������δ���÷�����ʩ�������ڵĶ�����·�ˣ���Ҫһ���غ��ҵ�����" << endl;
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
            cout << "���ṩ��ѡ�����������û���㹻�����ʣ��԰��յ�һ��ѡ���Ͻ���" << endl;
            group[ID].food -= 10;
            group[ID].residual_load += 10 * 10;
            group[ID].water -= 8;
            group[ID].residual_load += 8 * 10;
            cout << "������������������������δ���÷�����ʩ�������ڵĶ�����·�ˣ���Ҫһ���غ��ҵ�����" << endl;
            group[ID].miss = 1;
        }
        break;
    default:
        break;
    }

    if (group[ID].food < 0 || group[ID].water < 0) {
        cout << "���Ķ���δ�ܴ�ԽɳĮ�����´μ���Ŭ����" << endl;
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
        cout << "������������ź�����Ŷ�û�ܳɹ��ȹ����졣";
    }
    else {
        cout << "�����������ϲ����Ŷӳɹ��ȹ����졣";
    }
    cout << endl << "��ӵ�е��������£�" << endl;
    cout << " | ѡ��   \t| ˮ     \t| ʳ��   \t| ָ���� \t| ����   \t| " << endl;
    cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
    cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;

    cout << "�밴�����ȷ�ϡ�";
    confirm = _getch();

    system("cls");
}

// ��ͼ�ж�
int Move_map(int ID, string action) {
    for (int i = 0; i < 25; i++) {
        if (MAP[i][0] == group[ID].locations) {
            for (int j = 0; j < 10; j++) {
                if (MAP[i][j] == action) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// �ж�
void Move_Action(int ID) {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------���Ŷ��ƶ�λ��------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*      ��ͼ��ͼ���£����������ѡ��ǰ����������������Ͻǵı�ţ�                   */\n");
    printf("/*                                                                                     */\n");
    printf("/*                   +--------+-----------+--------+--------+-----+                    */\n");
    printf("/*                   |M       |S01        |S02     |C01     |S03  |                    */\n");
    printf("/*                   | ��ɽ   |           |        | ��ׯ   |     |                    */\n");
    printf("/*                   |        +--------+--+--+-----+--------+     |                    */\n");
    printf("/*                   +-----+--+        |S06  |S07           |     |                    */\n");
    printf("/*                   |S04  |   S05     |     |              +-----+                    */\n");
    printf("/*                   |     |        +--+-----+-----+--------+S10  |                    */\n");
    printf("/*                   +-----+        | W            | S09    |     |                    */\n");
    printf("/*                   |C02  +--------+              |-----+  +-----+                    */\n");
    printf("/*                   |��ׯ |S08     |   ��   ��    | L01 |  |     |                    */\n");
    printf("/*                   |     |        |              | ����|  | S13 |                    */\n");
    printf("/*                   |     |        |              |-----+--+     |                    */\n");
    printf("/*                   +-----+--------+--+--+-----+--+        |     |                    */\n");
    printf("/*                   |��ׯ |S11        |L02 ����|   S12     |     |                    */\n");
    printf("/*                   |C03  |           +--------+        +--+-----+                    */\n");
    printf("/*                   +-----+--+--------+--------+--------+D       |                    */\n");
    printf("/*                   | S14    | C04    | S15             | ��Ӫ |                    */\n");
    printf("/*                   |        |  ��ׯ  |     +--------+  |        |                    */\n");
    printf("/*                   |        |        |     |C05��ׯ |  |        |                    */\n");
    printf("/*                   +--------+--------+-----+--------+--+--------+                    */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    string action;
    cout << "���ã���" << ID + 1 << "�ӣ�����Ŀǰ��" << group[ID].locations << "��������Ҫǰ��ʲôλ�ã�" << endl;
    cout << "����������Ŀ��ص�ı�ţ�";
    cin >> action;
    //while (action[0] != 'D' && action[0] != 'S' && action[0] != 'W' && action[0] != 'C' && action[0] != 'L' && action[0] != 'M') {
    //    cout << "����ص㲻�Ϸ�����ע���Сд��" << endl;
    //    cout << "����������Ŀ��ص�ı�ţ�";
    //    cin >> action;
    //}
    //while (Move_map(ID, action) == 0) {
    //    cout << "����ص㲻�Ϸ�����ע��ص��ţ�" << endl;
    //    cout << "����������Ŀ��ص�ı�ţ�";
    //    cin >> action;
    //}

    int k = 0;
    while (1) {
        k = 0;
        cout << "�����Ա��������Ƿ������У�1��/�ޣ�0��";
        cin >> k;
        if (k == 1) {
            cout << "���������룺";
            cin >> action;
        }
        else {
            break;
        }
    }

    group[ID].locations = action;

    system("cls");

    if (action[0] == 'D') {
        cout << "���õ�" << ID + 1 << "�ӣ���ϲ��Ķ���ص���Ӫ��" << endl;
        cout << "�����г̹�ȡ��" << group[ID].gold << "��ƽ�" << endl;
        group[ID].rank = game_ranking;
        if (back_day == 0) {
            back_day = game_day;
        }
        if (back_day != game_day) {
            game_ranking++;
        }
        back_day = game_day;
        group[ID].back = 1;


        cout << "�밴�����ȷ�ϡ�";
        confirm = _getch();
    }

}

//��ɽ�ڻƽ�
void Struck_gold(int ID) {
    cout << "���õ�" << ID + 1 << "�ӡ���ӭ�������ɽ��" << endl;
    int k;
    if (group[ID].residual_load < 50) {
        cout << "��Ŀǰ��" << group[ID].locations << "������û�ж���Ŀռ��Żƽ��޷��ڻƽ�";
        return;
    }

    cout << "��Ŀǰ��" << group[ID].locations << "�����ҷ����ڽ��������������Ƿ��ڻƽ𣿣���1/��0��";
    cin >> k;
    if (k == 1) {
        cout << "��ϲ��ɹ��ھ�" << endl;
        group[ID].gold += 1;
        group[ID].residual_load -= 50;
    }

    cout << "�밴�����ȷ�ϡ�";
    confirm = _getch();

    system("cls");
}

// ����鿨
void Tomb_card(int ID) {
    cout << "���õ�" << ID + 1 << "�ӡ���ӭ���������꣡" << endl;
    int a;
    cout << "��Ŀǰ��������Ժ��������˻��һ��Ԥ�ԣ�������Ҫ����100Ԫ�������Ƿ��ã��ǣ�1��/��0��";
    cin >> a;
    if (a == 0) {
        system("cls");
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
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����0��" << endl;
        break;
    case 1:
        a = 1;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����1��" << endl;
        break;
    case 2:
        a = 2;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����2��" << endl;
        break;
    case 3:
        a = 3;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����3��" << endl;
        break;
    case 4:
        a = 4;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����4��" << endl;
        break;
    case 5:
        a = 5;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����5��" << endl;
        break;
    case 6:
        a = 6;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����6��" << endl;
        break;
    case 7:
        a = 7;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����7��" << endl;
        break;
    case 8:
        a = 8;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����8��" << endl;
        break;
    case 9:
        a = 9;
        group[ID].card = a;
        cout << "��ϲ��鵽�˵�" << a << "�ſ��ƣ������������£�" << endl;
        cout << "����9��" << endl;
        break;

    default:
        break;
    }

    cout << "�밴�����ȷ�ϡ�";
    confirm = _getch();

    system("cls");
}

// ����ȡˮ
void Oasis_water_intake(int ID) {
    cout << "���õ�" << ID + 1 << "�ӡ���ӭ���������ޣ�" << endl;

    int bang4_zhong4_sheng4 = group[ID].residual_load;
    int shui = bang4_zhong4_sheng4 / 50;

    // �ж��Ƿ��пռ���ˮ
    if (shui < 1) {
        cout << "������ȡˮ��";
        return;
    }

    // ��ʼ��
    int k;
    // ��¼��������
    cout << "��������" << shui << "��ˮ������������Ҫ��ˮ�Ĺ�����";
    cin >> k;
    group[ID].residual_load -= 50 * k;
    while (group[ID].residual_load < 0) {
        cout << "���س��ޣ����������룡";
        // ����
        group[ID].residual_load += 50 * k;
        // ��������
        cin >> k;
        group[ID].residual_load -= 50 * k;
    }
    group[ID].water += k;

    cout << "�밴�����ȷ�ϡ�";
    confirm = _getch();

    system("cls");
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

// ��ׯ����
void Village_store(int ID) {
    cout << "���õ�" << ID + 1 << "�ӡ���ӭ�������ׯ��" << endl;

    int t;
    cout << "����" << group[ID].money << "Ԫ��" << group[ID].residual_load << "������������ׯ�������Ƿ������ʣ��ǣ�1��/��0��";
    cin >> t;
    if (t == 0) {
        system("cls");
        return;
    }
    cout << "����" << group[ID].money << "Ԫ��" << group[ID].residual_load << "�����������ڴ�ׯ�����ˮ��������50Ԫ/�ޡ�50��/�ޣ���";
    // ��¼��������
    cin >> t;
    group[ID].money -= WATER_Village * t;
    group[ID].residual_load -= 50 * t;
    while (group[ID].money < 0 || group[ID].residual_load < 0) {
        cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
        // ����
        group[ID].money += WATER_Village * t;
        group[ID].residual_load += 50 * t;
        // ��������
        cin >> t;
        group[ID].money -= WATER_Village * t;
        group[ID].residual_load -= 50 * t;
    }
    group[ID].water += t;

    cout << "����" << group[ID].money << "Ԫ��" << group[ID].residual_load << "�����������ڴ�ׯ�����ʳ���������20Ԫ/�ޡ�10��/�ޣ���";
    // ��¼��������
    cin >> t;
    group[ID].money -= FOOD_Village * t;
    group[ID].residual_load -= 10 * t;
    while (group[ID].money < 0 || group[ID].residual_load < 0) {
        cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
        // ����
        group[ID].money += FOOD_Village * t;
        group[ID].residual_load += 10 * t;
        // ��������
        cin >> t;
        group[ID].money -= FOOD_Village * t;
        group[ID].residual_load -= 10 * t;
    }
    group[ID].food += t;

    cout << "����" << group[ID].money << "Ԫ��" << group[ID].residual_load << "�����������ڴ�ׯ����������������20Ԫ/�ޡ�10��/�ޣ���";
    // ��¼��������
    cin >> t;
    group[ID].money -= TENT_Village * t;
    group[ID].residual_load -= 20 * t;
    while (group[ID].money < 0 || group[ID].residual_load < 0) {
        cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
        // ����
        group[ID].money += TENT_Village * t;
        group[ID].residual_load += 20 * t;
        // ��������
        cin >> t;
        group[ID].money -= TENT_Village * t;
        group[ID].residual_load -= 20 * t;
    }
    group[ID].tent += t;


    cout << "����" << group[ID].money << "Ԫ��" << group[ID].residual_load << "�����������ڴ�ׯ�����ָ�����������20Ԫ/�ޡ�10��/�ޣ���";
    // ��¼��������
    cin >> t;
    group[ID].money -= COMPASS_Village * t;
    group[ID].residual_load -= 10 * t;
    while (group[ID].money < 0 || group[ID].residual_load < 0) {
        cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
        // ����
        group[ID].money += COMPASS_Village * t;
        group[ID].residual_load += 10 * t;
        // ��������
        cin >> t;
        group[ID].money -= COMPASS_Village * t;
        group[ID].residual_load -= 10 * t;
    }
    group[ID].compass += t;

    Team_supplies_one(ID);
    cout << "�ڴ�ׯ�����޷����ڣ��밴�����ȷ�ϡ�";
    confirm = _getch();

    system("cls");
}

// ��Ӫ����
void Base_camp_store(int num) {
    printf("/***************************************************************************************/\n");
    printf("/*                                                                                     */\n");
    printf("/*--------------------------------��    ��     ��    ��--------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*-----------------------------------���Ŷӹ�������------------------------------------*/\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         �����Ա���·�¼��һ���м�ֻ���飡                          */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                      ע     ��                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                              �ڴ�Ӫ�����ʵļ�Ŀ������                             */\n");
    printf("/*                                                                                     */\n");
    printf("/*                      |     ��Դ     |     ����    |   ����   |                      */\n");
    printf("/*                      |      ˮ      |     25      |    50    |                      */\n");
    printf("/*                      |     ʳ��     |     10      |    10    |                      */\n");
    printf("/*                      |     ����     |     400     |    60    |                      */\n");
    printf("/*                      |    ָ����    |     100     |    10    |                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                         ���ɹ�Աע�⵽��ׯ�������ʼ۸񷭱�                          */\n");
    printf("/*                                     �����ؿ���                                      */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/*                                                                                     */\n");
    printf("/***************************************************************************************/\n");
    cout << "�����Ա������ɺ��밴�����ȷ�ϡ�";
    confirm = _getch();

    system("cls");

    for (int i = 0; i < num; i++) {

        printf("/***************************************************************************************/\n");
        printf("/*                                                                                     */\n");
        printf("/*                   +--------+-----------+--------+--------+-----+                    */\n");
        printf("/*                   |M       |S01        |S02     |C01     |S03  |                    */\n");
        printf("/*                   | ��ɽ   |           |        | ��ׯ   |     |                    */\n");
        printf("/*                   |        +--------+--+--+-----+--------+     |                    */\n");
        printf("/*                   +-----+--+        |S06  |S07           |     |                    */\n");
        printf("/*                   |S04  |   S05     |     |              +-----+                    */\n");
        printf("/*                   |     |        +--+-----+-----+--------+S10  |                    */\n");
        printf("/*                   +-----+        | W            | S09    |     |                    */\n");
        printf("/*                   |C02  +--------+              |-----+  +-----+                    */\n");
        printf("/*                   |��ׯ |S08     |   ��   ��    | L01 |  |     |                    */\n");
        printf("/*                   |     |        |              | ����|  | S13 |                    */\n");
        printf("/*                   |     |        |              |-----+--+     |                    */\n");
        printf("/*                   +-----+--------+--+--+-----+--+        |     |                    */\n");
        printf("/*                   |��ׯ |S11        |L02 ����|   S12     |     |                    */\n");
        printf("/*                   |C03  |           +--------+        +--+-----+                    */\n");
        printf("/*                   +-----+--+--------+--------+--------+D       |                    */\n");
        printf("/*                   | S14    | C04    | S15             | ��Ӫ |                    */\n");
        printf("/*                   |        |  ��ׯ  |     +--------+  |        |                    */\n");
        printf("/*                   |        |        |     |C05��ׯ |  |        |                    */\n");
        printf("/*                   +--------+--------+-----+--------+--+--------+                    */\n");
        printf("/*                                                                                     */\n");
        printf("/***************************************************************************************/\n");

        cout << "�������" << i + 1 << "�鹺������ʣ�" << endl;
        group[i].ID = i;

        cout << "����" << group[i].money << "Ԫ��" << group[i].residual_load << "�����������ڴ�Ӫ�����ˮ��������25Ԫ/�ޡ�50��/�ޣ���";
        // ��¼��������
        cin >> group[i].water;
        group[i].money -= WATER_Base * group[i].water;
        group[i].residual_load -= 50 * group[i].water;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
            // ����
            group[i].money += WATER_Base * group[i].water;
            group[i].residual_load += 50 * group[i].water;
            // ��������
            cin >> group[i].water;
            group[i].money -= WATER_Base * group[i].water;
            group[i].residual_load -= 50 * group[i].water;
        }

        cout << "����" << group[i].money << "Ԫ��" << group[i].residual_load << "�����������ڴ�Ӫ�����ʳ���������10Ԫ/�ޡ�10��/�ޣ���";
        // ��¼��������
        cin >> group[i].food;
        group[i].money -= FOOD_Base * group[i].food;
        group[i].residual_load -= 10 * group[i].food;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
            // ����
            group[i].money += FOOD_Base * group[i].food;
            group[i].residual_load += 10 * group[i].food;
            // ��������
            cin >> group[i].food;
            group[i].money -= FOOD_Base * group[i].food;
            group[i].residual_load -= 10 * group[i].food;
        }

        cout << "����" << group[i].money << "Ԫ��" << group[i].residual_load << "�����������ڴ�Ӫ����������������400Ԫ/3����20��/��������һ�飩��";
        // ��¼��������
        cin >> group[i].tent;
        group[i].money -= TENT_Base * group[i].tent;
        group[i].residual_load -= 60 * group[i].tent;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
            // ����
            group[i].money += TENT_Base * group[i].tent;
            group[i].residual_load += 60 * group[i].tent;
            // ��������
            cin >> group[i].tent;
            group[i].money -= TENT_Base * group[i].tent;
            group[i].residual_load -= 60 * group[i].tent;
        }
        group[i].tent *= 3;

        cout << "����" << group[i].money << "Ԫ��" << group[i].residual_load << "�����������ڴ�Ӫ�����ָ�����������100Ԫ/����10��/������";
        // ��¼��������
        cin >> group[i].compass;
        group[i].money -= COMPASS_Base * group[i].compass;
        group[i].residual_load -= 10 * group[i].compass;
        while (group[i].money < 0 || group[i].residual_load < 0) {
            cout << "��Ǯ����س��ޣ����������룡���޶���ռ乺��������0��";
            // ����
            group[i].money += COMPASS_Base * group[i].compass;
            group[i].residual_load += 10 * group[i].compass;
            // ��������
            cin >> group[i].compass;
            group[i].money -= COMPASS_Base * group[i].compass;
            group[i].residual_load -= 10 * group[i].compass;
        }

        Team_supplies_one(i);

        int k = 0;
        cout << "�Ƿ������У�1��/�ޣ�0��";
        cin >> k;
        if (k == 1) {
            group[i].money = 1000;
            group[i].residual_load = 1000;
            // ����һ�ӡ�ʵ����������
            i--;
        }
        system("cls");
    }
    Team_supplies();
}
