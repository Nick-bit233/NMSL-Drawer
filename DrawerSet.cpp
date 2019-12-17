#pragma once
#include "graphics.h"
#include "Process.h"
#include <math.h>
#include "DrawerSet.h"
#define PINK 0xffc0cb
//��������Ҫ�����ȫ�ֱ���
LINET line_t;

//����ǰ��ɫ����
int Set_front_color(int switch_frontcolor) {
	switch (switch_frontcolor)
	{
	case 49:
		setcolor(BLUE);
		xyprintf(15,705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setcolor(GREEN);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setcolor(CYAN);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setcolor(RED);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 53:
		setcolor(MAGENTA);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 54:
		setcolor(BROWN);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 55:
		setcolor(YELLOW);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 56:
		setcolor(PINK);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 57:
		setcolor(WHITE);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 122:
		setcolor(LIGHTGRAY);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ǳ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 120:
		setcolor(DARKGRAY);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ���ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 99:
		setcolor(LIGHTBLUE);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ����ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 118:
		setcolor(LIGHTGREEN);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ����ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 98:
		setcolor(BLACK);
		xyprintf(15, 705, "�ѽ�ǰ��ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}//����ǰ��ɫ����

//����ɫ���ú���
int Set_back_color(int switch_backcolor) {
	switch (switch_backcolor)
	{
	case 49:
		setbkcolor(BLUE);
		setbkcolor_f(BLUE);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setbkcolor(GREEN);
		setbkcolor_f(GREEN);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setbkcolor(CYAN);
		setbkcolor_f(CYAN);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setbkcolor(RED);
		setbkcolor_f(RED);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 53:
		setbkcolor(MAGENTA);
		setbkcolor_f(MAGENTA);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 54:
		setbkcolor(BROWN);
		setbkcolor_f(BROWN);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 55:
		setbkcolor(YELLOW);
		setbkcolor_f(YELLOW);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 56:
		setbkcolor(PINK);
		setbkcolor_f(PINK);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 57:
		setbkcolor(WHITE);
		setbkcolor_f(WHITE);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 122:
		setbkcolor(LIGHTGRAY);
		setbkcolor_f(LIGHTGRAY);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ǳ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 120:
		setbkcolor(DARKGRAY);
		setbkcolor_f(DARKGRAY);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ���ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 99:
		setbkcolor(LIGHTBLUE);
		setbkcolor_f(LIGHTBLUE);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ����ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 118:
		setbkcolor(LIGHTGREEN);
		setbkcolor_f(LIGHTGREEN);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ����ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 98:
		setbkcolor(BLACK);
		setbkcolor_f(BLACK);
		xyprintf(15, 705, "�ѽ�����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}

//���ɫ���ú���
int Set_fill_color(int switch_fillcolor) {
	switch (switch_fillcolor)
	{
	case 49:
		setfillcolor(BLUE);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setfillcolor(GREEN);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setfillcolor(CYAN);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setfillcolor(RED);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 53:
		setfillcolor(MAGENTA);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 54:
		setfillcolor(BROWN);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 55:
		setfillcolor(YELLOW);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 56:
		setfillcolor(PINK);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 57:
		setfillcolor(WHITE);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 122:
		setfillcolor(LIGHTGRAY);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ǳ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 120:
		setfillcolor(DARKGRAY);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ���ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 99:
		setfillcolor(LIGHTBLUE);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ����ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 118:
		setfillcolor(LIGHTGREEN);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ����ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 98:
		setfillcolor(BLACK);
		xyprintf(15, 705, "�ѽ����ɫ����Ϊ ��ɫ ");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}

//�������ú���
int Set_linetype (int switch_linetype){
	char thick[3];
	int  t = 0;
	switch (switch_linetype)
	{
	case 49:
		inputbox_getline("����һ���ɰ��������", "������Ҫ����ʵ�ߵĴ�ϸֵ:(0-99)", thick, 3);
		t = atoi(thick);
		setlinestyle(SOLID_LINE, NULL, t, NULL);
		line_t.type = 0;
		line_t.thickness = t;
		xyprintf(15, 705, "������Ϊʵ�ߣ���ϸΪ%d��", t);
		delay_ms(1000);
		Clear_info();
		break;
	case 50:
		setlinestyle(CENTER_LINE, NULL, 1, NULL);
		line_t.type = 1;
		line_t.thickness = 1;
		xyprintf(15, 705, "����������Ϊ���ߣ������δ�ϸֻ��Ϊ1����");
		delay_ms(1000);
		Clear_info();
		break;
	case 51:
		setlinestyle(DOTTED_LINE, NULL, 1, NULL);
		line_t.type = 2;
		line_t.thickness = 1;
		xyprintf(15, 705, "����������Ϊ���ߣ������δ�ϸֻ��Ϊ1����");
		delay_ms(1000);
		Clear_info();
		break;
	case 52:
		setlinestyle(DASHED_LINE, NULL, 1, NULL);
		line_t.type = 3;
		line_t.thickness = 1;
		xyprintf(15, 705, "����������Ϊ�����ߣ������δ�ϸֻ��Ϊ1����");
		delay_ms(1000);
		Clear_info();
		break;
	case 48:
		return 0;
	}
	return 1;
}