#pragma once
#include "graphics.h"
#include "Process.h"
#include <math.h>
#include "DrawerSet.h"
#define PINK 0xffc0cb
//设置中需要储存的全局变量
LINET line_t;

//设置前景色函数
int Set_front_color(int switch_frontcolor) {
	switch (switch_frontcolor)
	{
	case 49:
		setcolor(BLUE);
		xyprintf(15,705, "已将前景色设置为 蓝色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setcolor(GREEN);
		xyprintf(15, 705, "已将前景色设置为 绿色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setcolor(CYAN);
		xyprintf(15, 705, "已将前景色设置为 青色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setcolor(RED);
		xyprintf(15, 705, "已将前景色设置为 红色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 53:
		setcolor(MAGENTA);
		xyprintf(15, 705, "已将前景色设置为 紫色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 54:
		setcolor(BROWN);
		xyprintf(15, 705, "已将前景色设置为 棕色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 55:
		setcolor(YELLOW);
		xyprintf(15, 705, "已将前景色设置为 黄色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 56:
		setcolor(PINK);
		xyprintf(15, 705, "已将前景色设置为 粉色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 57:
		setcolor(WHITE);
		xyprintf(15, 705, "已将前景色设置为 白色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 122:
		setcolor(LIGHTGRAY);
		xyprintf(15, 705, "已将前景色设置为 浅灰色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 120:
		setcolor(DARKGRAY);
		xyprintf(15, 705, "已将前景色设置为 深灰色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 99:
		setcolor(LIGHTBLUE);
		xyprintf(15, 705, "已将前景色设置为 亮蓝色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 118:
		setcolor(LIGHTGREEN);
		xyprintf(15, 705, "已将前景色设置为 亮绿色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 98:
		setcolor(BLACK);
		xyprintf(15, 705, "已将前景色设置为 黑色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}//设置前景色函数

//背景色设置函数
int Set_back_color(int switch_backcolor) {
	switch (switch_backcolor)
	{
	case 49:
		setbkcolor(BLUE);
		setbkcolor_f(BLUE);
		xyprintf(15, 705, "已将背景色设置为 蓝色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setbkcolor(GREEN);
		setbkcolor_f(GREEN);
		xyprintf(15, 705, "已将背景色设置为 绿色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setbkcolor(CYAN);
		setbkcolor_f(CYAN);
		xyprintf(15, 705, "已将背景色设置为 青色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setbkcolor(RED);
		setbkcolor_f(RED);
		xyprintf(15, 705, "已将背景色设置为 红色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 53:
		setbkcolor(MAGENTA);
		setbkcolor_f(MAGENTA);
		xyprintf(15, 705, "已将背景色设置为 紫色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 54:
		setbkcolor(BROWN);
		setbkcolor_f(BROWN);
		xyprintf(15, 705, "已将背景色设置为 棕色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 55:
		setbkcolor(YELLOW);
		setbkcolor_f(YELLOW);
		xyprintf(15, 705, "已将背景色设置为 黄色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 56:
		setbkcolor(PINK);
		setbkcolor_f(PINK);
		xyprintf(15, 705, "已将背景色设置为 粉色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 57:
		setbkcolor(WHITE);
		setbkcolor_f(WHITE);
		xyprintf(15, 705, "已将背景色设置为 白色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 122:
		setbkcolor(LIGHTGRAY);
		setbkcolor_f(LIGHTGRAY);
		xyprintf(15, 705, "已将背景色设置为 浅灰色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 120:
		setbkcolor(DARKGRAY);
		setbkcolor_f(DARKGRAY);
		xyprintf(15, 705, "已将背景色设置为 深灰色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 99:
		setbkcolor(LIGHTBLUE);
		setbkcolor_f(LIGHTBLUE);
		xyprintf(15, 705, "已将背景色设置为 亮蓝色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 118:
		setbkcolor(LIGHTGREEN);
		setbkcolor_f(LIGHTGREEN);
		xyprintf(15, 705, "已将背景色设置为 亮绿色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 98:
		setbkcolor(BLACK);
		setbkcolor_f(BLACK);
		xyprintf(15, 705, "已将背景色设置为 黑色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}

//填充色设置函数
int Set_fill_color(int switch_fillcolor) {
	switch (switch_fillcolor)
	{
	case 49:
		setfillcolor(BLUE);
		xyprintf(15, 705, "已将填充色设置为 蓝色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setfillcolor(GREEN);
		xyprintf(15, 705, "已将填充色设置为 绿色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setfillcolor(CYAN);
		xyprintf(15, 705, "已将填充色设置为 青色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setfillcolor(RED);
		xyprintf(15, 705, "已将填充色设置为 红色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 53:
		setfillcolor(MAGENTA);
		xyprintf(15, 705, "已将填充色设置为 紫色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 54:
		setfillcolor(BROWN);
		xyprintf(15, 705, "已将填充色设置为 棕色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 55:
		setfillcolor(YELLOW);
		xyprintf(15, 705, "已将填充色设置为 黄色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 56:
		setfillcolor(PINK);
		xyprintf(15, 705, "已将填充色设置为 粉色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 57:
		setfillcolor(WHITE);
		xyprintf(15, 705, "已将填充色设置为 白色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 122:
		setfillcolor(LIGHTGRAY);
		xyprintf(15, 705, "已将填充色设置为 浅灰色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 120:
		setfillcolor(DARKGRAY);
		xyprintf(15, 705, "已将填充色设置为 深灰色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 99:
		setfillcolor(LIGHTBLUE);
		xyprintf(15, 705, "已将填充色设置为 亮蓝色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 118:
		setfillcolor(LIGHTGREEN);
		xyprintf(15, 705, "已将填充色设置为 亮绿色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 98:
		setfillcolor(BLACK);
		xyprintf(15, 705, "已将填充色设置为 黑色 ");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}

//线型设置函数
int Set_linetype (int switch_linetype){
	char thick[3];
	int  t = 0;
	switch (switch_linetype)
	{
	case 49:
		inputbox_getline("这是一个可爱的输入框", "请输入要设置实线的粗细值:(0-99)", thick, 3);
		t = atoi(thick);
		setlinestyle(SOLID_LINE, NULL, t, NULL);
		line_t.type = 0;
		line_t.thickness = t;
		xyprintf(15, 705, "已设置为实线，粗细为%d磅", t);
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setlinestyle(CENTER_LINE, NULL, 1, NULL);
		line_t.type = 1;
		line_t.thickness = 1;
		xyprintf(15, 705, "线形已设置为虚线（该线形粗细只能为1磅）");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setlinestyle(DOTTED_LINE, NULL, 1, NULL);
		line_t.type = 2;
		line_t.thickness = 1;
		xyprintf(15, 705, "线形已设置为点线（该线形粗细只能为1磅）");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setlinestyle(DASHED_LINE, NULL, 1, NULL);
		line_t.type = 3;
		line_t.thickness = 1;
		xyprintf(15, 705, "线形已设置为点虚线（该线形粗细只能为1磅）");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}