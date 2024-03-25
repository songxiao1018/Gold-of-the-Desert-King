#pragma once

#include "docs.h"

// 天气部分
int  Weather(int day, int locations);                // 天气生成
void Weather_list();                                 // 天气列表生成
void Weather_list_show();                             // 天气列表输出
void Weather_show(int day);                          // 当天天气输出(当天全部地点)
void Weather_location_show(int day, int locations); // 当天天气输出(带地点)