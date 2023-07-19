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

#include <iostream>
#include <time.h>
using namespace std;

struct GROUP {
	int ID = 0;                // 队名
	int alive = 1;             // 是否存活
	int alive_day = 0;         // 存活天数
	int money = 10000;          // 剩余的金钱
	int residual_load = 10000;  // 剩余的磅重
	int water = 0;             // 水
	int food = 0;              // 食物
	int tent = 0;              // 帐篷
	int compass = 0;           // 指南针
	string locations = "D";    // 位置
	int gold = 0;              // 黄金
	int card = 0;              // 王陵抽取卡牌编号
	string Bei_zhu = " ";      // 备注
};

GROUP group[100];            // 预设100个队伍
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

int group_num = 0;       // 队伍数量

// 天气部分
int  Weather(int day, int locations);                // 天气生成
void Weather_show(int day);                          // 当天天气输出(当天全部地点)
void Weather_location_show(int day , int locations); // 当天天气输出(带地点)
void Weather_list();                                 // 天气列表生成
void Weather_list_show();                           // 天气列表输出
// 商店系统
void Base_camp_store(int num);    // 大本营购物
void Village_store(int ID);       // 村庄购物
void Oasis_water_intake(int ID);  // 绿洲取水
void Tomb_card(int ID);           // 王陵抽卡
void Struck_gold(int ID);         //大山挖黄金
// 行动系统
void Move_Action(int ID);                // 行动
void Weather_action(int ID , int day);   // 天气行动
// 游戏系统
void Game_start();                // 游戏开始
void Game_going(int day);         // 游戏进行
void Game_end();                  // 游戏结束



int main() {
	// 游戏开始
	Game_start();

	// 游戏进行
	for (int i = 0; i < 15; i++) {
		Game_going(i);
	}




	return 0;
}



// 游戏开始
void Game_start(){
	// 生成全部天气
	Weather_list();
	
	// 输出全部天气
	Weather_list_show();
	
	// 大本营购物
	cout << "请输入队伍数量：";
	cin >> group_num;
	Base_camp_store(group_num);
}

// 游戏进行
void Game_going(int day){
	// 每队分别行动
	for(int i = 0 ; i < group_num ; i ++){
		if (group[i].alive == 0) {
			continue;
		}
		// 天数增加
		group[i].alive_day ++;
		// 行动
		Move_Action(i);
	}
	// 天气输出
	Weather_show(day);
	// 各队解决天气问题
	for (int i = 0; i < group_num; i++) {
		if (group[i].alive == 0) {
			continue;
		}
		Weather_action(i, day);
	}

}

// 游戏结束
void Game_end(){
	
}

// 天气行动
void Weather_action(int ID , int day){
	cout << "您好，第" << ID+1 << "队！您目前在" << group[ID].locations << "，今天的天气是：" << endl ;
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
	Weather_location_show(day , k);
	switch (weather_list[day][k]){
		case 0:
			cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
			cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl ;
			cout << " |  1     \t| 1      \t|  1     \t|   0    \t|  0     \t| " << endl ;
			cout << "您拥有的物资如下：" << endl;
			cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
			cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
			cin >> k;
			group[ID].food -= 1;
			group[ID].water -= 1;
			if (group[ID].food < 0 || group[ID].water < 0) {
				cout << "您的队伍未能穿越沙漠，请下次继续努力！";
				group[ID].alive = 0;
			}
			break;
		case 1:
			cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
			cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl ;
			cout << " |  1     \t| 3      \t|  1     \t|   0    \t|  0     \t| " << endl ;
			cout << "您拥有的物资如下：" << endl;
			cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
			cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
			cin >> k;
			group[ID].food -= 1;
			group[ID].water -= 3;
			if (group[ID].food < 0 || group[ID].water < 0) {
				cout << "您的队伍未能穿越沙漠，请下次继续努力！";
				group[ID].alive = 0;
			}
			break;
		case 2:
			cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
			cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl ;
			cout << " |  1     \t| 4      \t|  10    \t|   0    \t|  0     \t| " << endl;
			cout << " |  2     \t| 2      \t|  5     \t|   1    \t|  0     \t| " << endl;
			cout << " |  3     \t| 1      \t|  1     \t|   0    \t|  1     \t| " << endl ;
			cout << "您拥有的物资如下：" << endl;
			cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
			cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
			cin >> k;
			if(k == 1){
				group[ID].food -= 10;
				group[ID].water -= 4;
				if(group[ID].food < 0 || group[ID].water < 0){
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}else if(k == 2 && group[ID].compass > 0){
				group[ID].food -= 5;
				group[ID].water -= 2;
				group[ID].compass -= 1;
				if (group[ID].food < 0 || group[ID].water < 0) {
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}else if(k == 3 && group[ID].tent > 0){
				group[ID].food -= 1;
				group[ID].water -= 1;
				group[ID].tent -= 1;
				if (group[ID].food < 0 || group[ID].water < 0) {
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}else{
				cout << "您提供的选项有误或者您没有足够的物资！以按照第一个选项上交！";
				group[ID].food -= 10;
				group[ID].water -= 4;
				if(group[ID].food < 0 || group[ID].water < 0){
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}
			break;
		case 3:
			cout << "今天需上交内容如下表。请选择其中一个选项上交！" << endl;
			cout << " | 选项   \t| 水     \t| 食物   \t| 指南针 \t| 帐篷   \t| " << endl ;
			cout << " |  1     \t| 8      \t|  10    \t|   0    \t|  0     \t| " << endl;
			cout << " |  2     \t| 4      \t|  5     \t|   1    \t|  0     \t| " << endl;
			cout << " |  3     \t| 3      \t|  1     \t|   0    \t|  1     \t| " << endl ;
			cout << "您拥有的物资如下：" << endl;
			cout << " |        \t| " << group[ID].water << "     \t|  " << group[ID].food << "     \t|   ";
			cout << group[ID].compass << "     \t|  " << group[ID].tent << "     \t| " << endl;
			cin >> k;
			if(k == 1){
				group[ID].food -= 10;
				group[ID].water -= 8;
				if(group[ID].food < 0 || group[ID].water < 0){
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}else if(k == 2 && group[ID].compass > 0){
				group[ID].food -= 5;
				group[ID].water -= 4;
				group[ID].compass -= 1;
				if (group[ID].food < 0 || group[ID].water < 0) {
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}else if(k == 3 && group[ID].tent > 0){
				group[ID].food -= 1;
				group[ID].water -= 3;
				group[ID].tent -= 1;
				if (group[ID].food < 0 || group[ID].water < 0) {
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}else{
				cout << "您提供的选项有误或者您没有足够的物资！以按照第一个选项上交！";
				group[ID].food -= 10;
				group[ID].water -= 8;
				if(group[ID].food < 0 || group[ID].water < 0){
					cout << "您的队伍未能穿越沙漠，请下次继续努力！";
					group[ID].alive = 0;
				}
			}
			break;
		default:
			break;
	}
}

// 行动
void Move_Action(int ID) {
	string action;
	cout << "您好，第" << ID+1 << "队！您们目前在" << group[ID].locations << "，请问需要前往什么位置？" << endl;
	cin >> action;

	while(1){
		cout << "请管理员检查输入是否有误？有（1）/无（0）";
		int k = 0;
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
}

// 当天天气输出
void Weather_show(int day) {
	cout << "第" << day + 1 << "天的天气情况如下：" << endl;
	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0: cout << "沙漠：\t"; break;
		case 1: cout << "王陵：\t"; break;
		case 2: cout << "绿洲：\t"; break;
		case 3: cout << "村庄：\t"; break;
		case 4: cout << "大山：\t"; break;
		}
		switch (weather_list[day][i]) {
		case 0: cout << "晴天      \t"; break;
		case 1: cout << "高温      \t"; break;
		case 2: cout << "沙尘暴    \t"; break;
		case 3: cout << "高温沙尘暴\t"; break;
		}
	}
	cout << endl;
}

void Weather_location_show(int day, int locations){
	int k = 0;
	cout << "第" << day + 1 << "天的天气情况如下：" << endl;
	switch (locations) {
	case 0: cout << "沙漠：\t";k=0; break;
	case 1: cout << "王陵：\t";k=1; break;
	case 2: cout << "绿洲：\t";k=2; break;
	case 3: cout << "村庄：\t";k=3; break;
	case 4: cout << "大山：\t";k=4; break;
	}
	switch (weather_list[day][k]) {
	case 0: cout << "晴天      \t"; break;
	case 1: cout << "高温      \t"; break;
	case 2: cout << "沙尘暴    \t"; break;
	case 3: cout << "高温沙尘暴\t"; break;
	}
	cout << endl;
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
	for (int i = 0; i < 25; i++) {
		printf("第%2d天：\t", i+1);
		for (int j = 0; j < 5; j++) {
			switch (j){
			case 0: cout << "沙漠：\t"; break;
			case 1: cout << "王陵：\t"; break;
			case 2: cout << "绿洲：\t"; break;
			case 3: cout << "村庄：\t"; break;
			case 4: cout << "大山：\t"; break;
			}
			switch (weather_list[i][j]) {
			case 0: cout << "晴天      \t"; break;
			case 1: cout << "高温      \t"; break;
			case 2: cout << "沙尘暴    \t"; break;
			case 3: cout << "高温沙尘暴\t"; break;
			}
		}
		cout << endl;
	}
}

//大山挖黄金
void Struck_gold(int ID) {
	int k;
	if (group[ID].residual_load < 50) {
		cout << "您目前在" << group[ID].locations << "，但是没有多余的空间存放黄金，无法挖黄金。";
		return;
	}

	cout << "您目前在" << group[ID].locations << "，并且符合挖金子条件。请问是否挖黄金？（是1/否0）";
	cin >> k;
	if (k == 1) {
		cout << "恭喜你成功挖掘！";
		group[ID].gold += 1;
		group[ID].residual_load -= 50;
	}
}

// 王陵抽卡
void Tomb_card(int ID) {
	int a;
	a = rand() * time(NULL);
	a = abs(a);
//	char str[1000];
//	//sprintf(str, "%d", a);
	group[ID].Bei_zhu = ID;
}

// 村庄购物
void Village_store(int ID) {
	int t;
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
}

// 大本营购物
void Base_camp_store(int num) {
	for (int i = 0; i < num; i++) {
		cout << "请输入第" << i << "组购买的物资！" << endl;
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

		cout << "队名\t钱\t磅重\t水\t食物\t帐篷\t指南针\t位置\t黄金" << endl;
		cout << group[i].ID << " \t" << group[i].money << " \t" << group[i].residual_load << " \t" << group[i].water << " \t" << group[i].food << " \t" << group[i].tent << " \t" << group[i].compass << " \t" << group[i].locations << " \t" << group[i].gold << endl;

		int k = 0;
		cout << "是否有误？有（1）/无（0）";
		cin >> k;
		if (k == 1) {
			group[i].money = 1000;
			group[i].residual_load = 1000;
			// 回退一队。实现重新输入
			i--;
		}
	}
}

// 绿洲取水
void Oasis_water_intake(int ID) {
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
}

// 随机天气生成
int Weather(int day, int locations) {
	// 生成随机数
	int a;
	// 随机数处理——时间函数
	a = (rand() + day) * time(NULL);
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
