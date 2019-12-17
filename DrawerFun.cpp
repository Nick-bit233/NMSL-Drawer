
#include "graphics.h"
#include "Process.h"
#include "DrawerFun.h"
#include <math.h>
#include <stdio.h>
int Flag = 0;
char Text_temp[3];                             //��ʱ�洢�����ı����ж��������ʱʹ�ã�
NMSLSHAPE Saved_shape[100] = { None,{0},0,0 }; //����ͼ�δ���ṹ��
extern LINET line_t;

//��ͼ�еĺ���
int Draw_point() {
	char Text_pointx[] = "�������ĺ�����:(000����999������ᳬ����Χ)";
	char Text_pointy[] = "��������������:(000����700������ᳬ����Χ)";
	int x = -1, y = -1, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx, point_x, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy, point_y, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		if (x == -1 || y == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)        //��ʾ����ʾ������󲢹��û�ѡ���������뻹��ȡ�����ƣ�	������ͼ����ͬ�������ģ��
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	putpixel(x + 280, y, getcolor());
	Clear_info();
	xyprintf(15, 705, "�õ�����Ϊ��(%d,%d) ", x, y);
	Flag++;
	Saved_shape[Flag].type = Point;
	Saved_shape[Flag].parameter[0] = x;
	Saved_shape[Flag].parameter[1] = y;
	Saved_shape[Flag].color = getcolor();
	return 0;
}
int Draw_circle() {
	char Text_pointx[] = "������Բ�ĵĺ�����:(0����999������ᳬ����Χ)";
	char Text_pointy[] = "������Բ�ĵ�������:(0����700������ᳬ����Χ)";
	char Text_radio[] = "������뾶:(0����700������ᳬ����Χ)";
	int x = 0, y = 0, r = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], radio[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx, point_x, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy, point_y, 4);
		inputbox_getline("����һ���ɰ��������", Text_radio, radio, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		r = GetInt(radio);
		if (x == -1 || y == -1 || r == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	circle(x, y, r);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "Բ������(%d, %d) , �뾶%d", x, y, r);
	Flag++;
	Saved_shape[Flag].type = Empty_circle;
	Saved_shape[Flag].parameter[0] = x;
	Saved_shape[Flag].parameter[1] = y;
	Saved_shape[Flag].parameter[2] = r;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_line() {
	char Text_pointx1[] = "������ ��˵� ������x1:(0����999������ᳬ����Χ)";
	char Text_pointy1[] = "������ ��˵� ������y1:(0����700������ᳬ����Χ)";
	char Text_pointx2[] = "������ �Ҷ˵� ������x2:(0����999������ᳬ����Χ)";
	char Text_pointy2[] = "������ �Ҷ˵� ������y2:(0����700������ᳬ����Χ)";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, f = 1;
	while (f == 1) {
		char point_x1[4], point_y1[4], point_x2[4], point_y2[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx1, point_x1, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy1, point_y1, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointx2, point_x2, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy2, point_y2, 4);
		x1 = GetInt(point_x1);
		y1 = GetInt(point_y1);
		x2 = GetInt(point_x2);
		y2 = GetInt(point_y2);
		if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	line(x1, y1, x2, y2);
	int square = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	int r = sqrt(square);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "��˵�(%d, %d) ,�Ҷ˵㣨%d, %d��, ����%d", x1, y1, x2, y2, r);
	Flag++;
	Saved_shape[Flag].type = Line;
	Saved_shape[Flag].parameter[0] = x1;
	Saved_shape[Flag].parameter[1] = y1;
	Saved_shape[Flag].parameter[2] = x2;
	Saved_shape[Flag].parameter[3] = y2;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_empty_rectangle() {
	char Text_pointx1[] = "������ ���϶˵�A ������x1:(0����999������ᳬ����Χ)";
	char Text_pointy1[] = "������ ���϶˵�A ������y1:(0����700������ᳬ����Χ)";
	char Text_pointx2[] = "������ ���¶˵�D ������x2:(0����999������ᳬ����Χ)";
	char Text_pointy2[] = "������ ���¶˵�D ������y2:(0����700������ᳬ����Χ)";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, f = 1;
	while (f == 1) {
		char point_x1[4], point_y1[4], point_x2[4], point_y2[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx1, point_x1, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy1, point_y1, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointx2, point_x2, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy2, point_y2, 4);
		x1 = GetInt(point_x1);
		y1 = GetInt(point_y1);
		x2 = GetInt(point_x2);
		y2 = GetInt(point_y2);
		if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	rectangle(x1, y1, x2, y2);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "������������(%d, %d) , ��%d ,��%d", (x1 + x2) / 2, (y1 + y2) / 2, abs(x2 - x1), abs(y2 - y1));
	Flag++;
	Saved_shape[Flag].type = Empty_rect;
	Saved_shape[Flag].parameter[0] = x1;
	Saved_shape[Flag].parameter[1] = y1;
	Saved_shape[Flag].parameter[2] = x2;
	Saved_shape[Flag].parameter[3] = y2;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_arcf() {
	char Text_pointx[] = "������Բ�ĵĺ�����:(0����999������ᳬ����Χ)";
	char Text_pointy[] = "������Բ�ĵ�������:(0����700������ᳬ����Χ)";
	char Text_radio[] = "������뾶:(0����700������ᳬ����Χ)";
	char Text_rstart[] = "������Բ����ʼ�Ƕȣ�˳ʱ�룩:(0����360������ᳬ����Χ)";
	char Text_rend[] = "������Բ����ֹ�Ƕȣ�˳ʱ�룩:(0����360������ᳬ����Χ)";
	int x = 0, y = 0, r = 0, rs = 0, re = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], radio[4], rstart[4], rend[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx, point_x, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy, point_y, 4);
		inputbox_getline("����һ���ɰ��������", Text_radio, radio, 4);
		inputbox_getline("����һ���ɰ��������", Text_rstart, rstart, 4);
		inputbox_getline("����һ���ɰ��������", Text_rend, rend, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		r = GetInt(radio);
		rs = GetInt(rstart);
		re = GetInt(rend);
		if (x == -1 || y == -1 || r == -1 || rs == -1 || re == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	arcf(x, y, r, rs, re);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "Բ������(%d, %d) , �뾶%d, �Ƕ���%d", x, y, r, abs(re - rs));
	Flag++;
	Saved_shape[Flag].type = Arcf;
	Saved_shape[Flag].parameter[0] = x;
	Saved_shape[Flag].parameter[1] = y;
	Saved_shape[Flag].parameter[2] = r;
	Saved_shape[Flag].parameter[3] = rs;
	Saved_shape[Flag].parameter[4] = re;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_empty_ellipse() {
	char Text_pointx[] = "��������Բ���ĵĺ�����:(0����999������ᳬ����Χ)";
	char Text_pointy[] = "��������Բ���ĵ�������:(0����700������ᳬ����Χ)";
	char Text_ea[] = "��������Բ�볤�᳤a:";
	char Text_eb[] = "��������Բ����᳤b:";
	int x = 0, y = 0, a = 0, b = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], ea[4], eb[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx, point_x, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy, point_y, 4);
		inputbox_getline("����һ���ɰ��������", Text_ea, ea, 4);
		inputbox_getline("����һ���ɰ��������", Text_eb, eb, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		a = GetInt(ea);
		b = GetInt(eb);
		if (x == -1 || y == -1 || a == -1 || b == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	ellipse(x, y, 0, 360, a, b);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "��ԲԲ������(%d, %d) ,����a��b = %d��%d", x, y, a, b);
	Flag++;
	Saved_shape[Flag].type = Empty_ellipse;
	Saved_shape[Flag].parameter[0] = x;
	Saved_shape[Flag].parameter[1] = y;
	Saved_shape[Flag].parameter[2] = a;
	Saved_shape[Flag].parameter[3] = b;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_empty_poly() {
	char Text_pnumber[44] = { 0 };
	sprintf(Text_pnumber, "���������εĶ������\n�����������ܳ���18��");
	char pnumber[4];
	inputbox_getline("����һ���ɰ��������", Text_pnumber, pnumber, 4);
	int pn = GetInt(pnumber);
	while (pn <= 2 || pn > 18) {
		char Text_pnumber1[32] = { 0 };
		if (pn <= 2)
			sprintf(Text_pnumber1, "����ζ���������Ϊ3������������");
		if (pn > 18)
			sprintf(Text_pnumber1, "����ζ�����̫���ˣ� ����������");
		char pnumber1[4];
		inputbox_getline("���������е㲻̫����", Text_pnumber1, pnumber1, 4);
		pn = GetInt(pnumber1);
	}
	char Text_pointx[18][72] = { 0 };
	char Point_x[18][4] = { 0 };
	char Text_pointy[18][72] = { 0 };
	char Point_y[18][4] = { 0 };
	int ps[38] = { 0 };
	int i;
	char temp[100] = "����һ���ɰ��������";
	for (i = 0; i < pn; i++) {    //���ڶ���Σ�����ʹ����forѭ�����룬�������ʱ��i--��continue��������������ʵ�ֲ��˳�ѭ���������롣
		int t = 2 * i;
		sprintf(Text_pointx[i], "������\n����%d\n������x%d:(1����999������ᳬ����Χ)\n��ȡ������������0��", i + 1, i + 1); //���⣬Ҳ�ṩ���û��ֶ��˳�ѭ���Ĺ���
		inputbox_getline(temp, Text_pointx[i], Point_x[i], 4);
		ps[t] = GetInt(Point_x[i]);
		if (ps[t] == 0)
			return 0;
		if (ps[t] == -1) {
			sprintf(temp, "�����ʽ��������������������꣡");
			i--;
			continue;
		}
		sprintf(Text_pointy[i], "������\n����%d\n������y%d:(1����700������ᳬ����Χ)\n��ȡ������������0��", i + 1, i + 1);
		inputbox_getline(temp, Text_pointy[i], Point_y[i], 4);
		ps[t + 1] = GetInt(Point_y[i]);
		if (ps[t + 1] == 0)
			return 0;
		if (ps[t + 1] == -1) {
			sprintf(temp, "�����ʽ��������������������꣡");
			i--;
			continue;
		}
		sprintf(temp, "����һ���ɰ��������");
	}
	ps[2 * pn] = ps[0];
	ps[2 * pn + 1] = ps[1];
	setviewport(280, 0, getwidth(), 700);
	drawpoly(pn + 1, ps);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "����εĶ�����Ϊ%d", pn);
	Flag++;
	Saved_shape[Flag].type = Empty_poly;
	Saved_shape[Flag].parameter[0] = pn;
	for (int k = 1; k <= 2 * pn + 2; k++) {
		Saved_shape[Flag].parameter[k] = ps[k - 1];
	}
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_fill_rectangle() {
	char Text_pointx1[] = "������ ���϶˵�A ������x1:(0����999������ᳬ����Χ)";
	char Text_pointy1[] = "������ ���϶˵�A ������y1:(0����700������ᳬ����Χ)";
	char Text_pointx2[] = "������ ���¶˵�D ������x2:(0����999������ᳬ����Χ)";
	char Text_pointy2[] = "������ ���¶˵�D ������y2:(0����700������ᳬ����Χ)";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, f = 1;
	while (f == 1) {
		char point_x1[4], point_y1[4], point_x2[4], point_y2[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx1, point_x1, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy1, point_y1, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointx2, point_x2, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy2, point_y2, 4);
		x1 = GetInt(point_x1);
		y1 = GetInt(point_y1);
		x2 = GetInt(point_x2);
		y2 = GetInt(point_y2);
		if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	bar(x1, y1, x2, y2);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "������������(%d, %d) , ��%d ,��%d", (x1 + x2) / 2, (y1 + y2) / 2, abs(x2 - x1), abs(y2 - y1));
	Flag++;
	Saved_shape[Flag].type = Fill_rect;
	Saved_shape[Flag].parameter[0] = x1;
	Saved_shape[Flag].parameter[1] = y1;
	Saved_shape[Flag].parameter[2] = x2;
	Saved_shape[Flag].parameter[3] = y2;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].fillcolor = getfillcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_fill_circle() {
	char Text_pointx[] = "������Բ�ĵĺ�����:(0����999������ᳬ����Χ)";
	char Text_pointy[] = "������Բ�ĵ�������:(0����700������ᳬ����Χ)";
	char Text_radio[] = "������뾶:(0����700������ᳬ����Χ)";
	int x = 0, y = 0, r = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], radio[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx, point_x, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy, point_y, 4);
		inputbox_getline("����һ���ɰ��������", Text_radio, radio, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		r = GetInt(radio);
		if (x == -1 || y == -1 || r == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	fillellipse(x, y, r, r);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "Բ������(%d, %d) , �뾶%d", x, y, r);
	Flag++;
	Saved_shape[Flag].type = Fill_circle;
	Saved_shape[Flag].parameter[0] = x;
	Saved_shape[Flag].parameter[1] = y;
	Saved_shape[Flag].parameter[2] = r;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].fillcolor = getfillcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_fill_ellipse() {
	char Text_pointx[] = "��������Բ���ĵĺ�����:(0����999������ᳬ����Χ)";
	char Text_pointy[] = "��������Բ���ĵ�������:(0����700������ᳬ����Χ)";
	char Text_ea[] = "��������Բ�볤�᳤a:";
	char Text_eb[] = "��������Բ����᳤b:";
	int x = 0, y = 0, a = 0, b = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], ea[4], eb[4];
		inputbox_getline("����һ���ɰ��������", Text_pointx, point_x, 4);
		inputbox_getline("����һ���ɰ��������", Text_pointy, point_y, 4);
		inputbox_getline("����һ���ɰ��������", Text_ea, ea, 4);
		inputbox_getline("����һ���ɰ��������", Text_eb, eb, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		a = GetInt(ea);
		b = GetInt(eb);
		if (x == -1 || y == -1 || a == -1 || b == -1) {
			inputbox_getline("���������е㲻̫����", "��������겻�������������������룡\n ��Enter�������룬����-1ȡ������", Text_temp, 3);
			if (atoi(Text_temp) == -1)
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	setviewport(280, 0, getwidth(), 700);
	fillellipse(x, y, a, b);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "��ԲԲ������(%d, %d) ,����a��b = %d��%d", x, y, a, b);
	Flag++;
	Saved_shape[Flag].type = Fill_ellipse;
	Saved_shape[Flag].parameter[0] = x;
	Saved_shape[Flag].parameter[1] = y;
	Saved_shape[Flag].parameter[2] = a;
	Saved_shape[Flag].parameter[3] = b;
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].fillcolor = getfillcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}
int Draw_fill_poly() {
	char Text_pnumber[44] = { 0 };
	sprintf(Text_pnumber, "���������εĶ������\n�����������ܳ���18��");
	char pnumber[4];
	inputbox_getline("����һ���ɰ��������", Text_pnumber, pnumber, 4);
	int pn = GetInt(pnumber);
	while (pn <= 2 || pn > 18) {
		char Text_pnumber1[32] = { 0 };
		if (pn <= 2)
			sprintf(Text_pnumber1, "����ζ���������Ϊ3������������");
		if (pn > 18)
			sprintf(Text_pnumber1, "����ζ�����̫���ˣ� ����������");
		char pnumber1[4];
		inputbox_getline("���������е㲻̫����", Text_pnumber1, pnumber1, 4);
		pn = GetInt(pnumber1);
	}
	char Text_pointx[18][72] = { 0 };
	char Point_x[18][4] = { 0 };
	char Text_pointy[18][72] = { 0 };
	char Point_y[18][4] = { 0 };
	int ps[38] = { 0 };
	int i;
	char temp[100] = "����һ���ɰ��������";
	for (i = 0; i < pn; i++) {
		int t = 2 * i;
		sprintf(Text_pointx[i], "������\n����%d\n������x%d:(1����999������ᳬ����Χ)\n��ȡ������������0��", i + 1, i + 1);
		inputbox_getline(temp, Text_pointx[i], Point_x[i], 4);
		ps[t] = GetInt(Point_x[i]);
		if (ps[t] == 0)
			return 0;
		if (ps[t] == -1) {
			sprintf(temp, "�����ʽ��������������������꣡");
			i--;
			continue;
		}
		sprintf(Text_pointy[i], "������\n����%d\n������y%d:(1����700������ᳬ����Χ)\n��ȡ������������0��", i + 1, i + 1);
		inputbox_getline(temp, Text_pointy[i], Point_y[i], 4);
		ps[t + 1] = GetInt(Point_y[i]);
		if (ps[t + 1] == 0)
			return 0;
		if (ps[t + 1] == -1) {
			sprintf(temp, "�����ʽ��������������������꣡");
			i--;
			continue;
		}
		sprintf(temp, "����һ���ɰ��������");
	}
	setviewport(280, 0, getwidth(), 700);
	fillpoly(pn, ps);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "����εĶ�����Ϊ%d", pn);
	Flag++;
	Saved_shape[Flag].type = Fill_poly;
	Saved_shape[Flag].parameter[0] = pn;
	for (int k = 1; k <= 2 * pn; k++) {
		Saved_shape[Flag].parameter[k] = ps[k - 1];
	}
	Saved_shape[Flag].color = getcolor();
	Saved_shape[Flag].fillcolor = getfillcolor();
	Saved_shape[Flag].Linetype = line_t;
	return 0;
}

//���»��Ƶĺ�������ȡ�ṹ���ڵ����ݲ����»��ƣ�
int Reprint() {
	int colortemp, fillcolortemp;
	int pn = 0;
	int ps[38] = { 0 };
	int pn_fill = 0;
	int ps_fill[38] = { 0 };
	NMSLSHAPE* Sp; //Sp = shape pointer
	for (int i = 1; i <= Flag; i++) {
		Sp = &Saved_shape[i];
		switch (Sp->type) {
		case(Point):
			putpixel(Sp->parameter[0], Sp->parameter[1], Sp->color);
			break;
		case(Line):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			setcolor(Sp->color);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			line(Sp->parameter[0], Sp->parameter[1], Sp->parameter[2], Sp->parameter[3]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setcolor(colortemp);
			break;
		case(Empty_rect):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			setcolor(Sp->color);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			rectangle(Sp->parameter[0], Sp->parameter[1], Sp->parameter[2], Sp->parameter[3]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setcolor(colortemp);
			break;
		case(Empty_circle):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			setcolor(Sp->color);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			circle(Sp->parameter[0], Sp->parameter[1], Sp->parameter[2]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setcolor(colortemp);
			break;
		case(Arcf):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			setcolor(Sp->color);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			arcf(Sp->parameter[0], Sp->parameter[1], Sp->parameter[2], Sp->parameter[3], Sp->parameter[4]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setcolor(colortemp);
			break;
		case(Empty_ellipse):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			setcolor(Sp->color);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			ellipse(Sp->parameter[0], Sp->parameter[1], 0, 360, Sp->parameter[2], Sp->parameter[3]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setcolor(colortemp);
			break;
		case(Empty_poly):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			setcolor(Sp->color);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);
			pn = Sp->parameter[0];
			for (int k = 1; k <= 2 * pn + 2; k++) {
				ps[k - 1] = Sp->parameter[k];
			}
			drawpoly(pn + 1, ps);
			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setcolor(colortemp);
			break;
		case(Fill_rect):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			fillcolortemp = getfillcolor();
			setcolor(Sp->color);
			setfillcolor(Sp->fillcolor);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			bar(Sp->parameter[0], Sp->parameter[1], Sp->parameter[2], Sp->parameter[3]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setfillcolor(fillcolortemp);
			setcolor(colortemp);
			break;
		case(Fill_circle):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			fillcolortemp = getfillcolor();
			setcolor(Sp->color);
			setfillcolor(Sp->fillcolor);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			fillellipse(Sp->parameter[0], Sp->parameter[1], Sp->parameter[2], Sp->parameter[2]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setfillcolor(fillcolortemp);
			setcolor(colortemp);
			break;
		case(Fill_ellipse):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			fillcolortemp = getfillcolor();
			setcolor(Sp->color);
			setfillcolor(Sp->fillcolor);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);

			fillellipse(Sp->parameter[0], Sp->parameter[1], Sp->parameter[2], Sp->parameter[3]);

			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setfillcolor(fillcolortemp);
			setcolor(colortemp);
			break;
		case(Fill_poly):
			setviewport(280, 0, getwidth(), 700);
			colortemp = getcolor();
			fillcolortemp = getfillcolor();
			setcolor(Sp->color);
			setfillcolor(Sp->fillcolor);
			setlinestyle(Saved_shape[i].Linetype.type, NULL, Saved_shape[i].Linetype.thickness, NULL);
			pn_fill = Sp->parameter[0];
			for (int k = 1; k <= 2 * pn_fill; k++) {
				ps_fill[k - 1] = Sp->parameter[k];
			}
			fillpoly(pn_fill, ps_fill);
			setviewport(0, 0, getwidth(), getheight());
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			setfillcolor(fillcolortemp);
			setcolor(colortemp);
			break;
		}
	}
	return 0;

}
//���ɻ��ƺ���
int Freedraw(){
	int is_exit = 0;
	int last_x=0;
	int last_y=0;
	int isclick,isend;
	mouse_msg ms = { 0 };
	isclick = 0;
	for ( ; is_run(); delay_fps(1200)) {
		while (mousemsg()) {
			ms = getmouse();
			if (ms.is_left()&& ms.is_up() || ms.is_down()) {
				break;
			}
		}
		if (isclick == 1 && last_x != 0 && last_y != 0 && ms.x > 280 && ms.y > 0 && ms.x < 1280 && ms.y < 700) {
			line(last_x, last_y, ms.x, ms.y);
		}
		if (isclick == 1) {
			last_x = ms.x;
			last_y = ms.y;
		}
		if (ms.is_left() && ms.is_down() && ms.x > 280 && ms.y > 0 && ms.x < 1280 && ms.y < 700) {
			isclick = 1;
			//putpixel(ms.x, ms.y,getcolor());
		}
		if (ms.is_left() && ms.is_up()) {
			isclick = 0;
			last_x = 0;
			last_y = 0;
		}
		if (ms.is_left() && ms.is_down() && ms.x > 15 && ms.y > 200 && ms.x < 140 && ms.y < 260) {
			break;
		}
		if (ms.is_left() && ms.is_down() && ms.x > 15 && ms.y > 300 && ms.x < 140 && ms.y < 360) {
			Clear();
			PrintMenuRectangle(1, 100, 260, 700, line_t.type, line_t.thickness);
		}
		if(ms.x - 280 > 0 && ms.x - 280 <= 999 && ms.y > 0 && ms.y <= 700)
			xyprintf(1100, 705, "��ǰ���λ�ã�%d %d", ms.x-280, ms.y);
		else
			xyprintf(1100, 705, "��ǰ���λ�ã�                 ", ms.x - 280, ms.y);
	}
	return 0;
}

//��ѯ����
int FindReprint(int find){
	int count = 0;
	if (find == 'a')
		find = 10;
	if (find == 'b')
		find = 11;
	if (find >= '0' && find <= '9')
		find -= '0';
	if (find == 0)
		return 0;
	if (find <= 11) {
		char name[12][100] = { "��","��","ֱ��","Բ��","���ľ���","����Բ","������Բ","���Ķ����","���Բ","������","�����Բ","�������" };
		for (int i = 1; i <= Flag; i++) {
			if (Saved_shape[i].type == find)
				count++;
		}
		if (count > 0) {
			xyprintf(15, 405, "�ڴ�����%d��%s", count, name[find]);
		}
		else {
			xyprintf(15, 405, "�ڴ���δ�ҵ���ͼ��");
		}
	}
	return 1;
}
//�������ƺ���
int UNDO(){
	if (Flag == 0)
		return -1;
	else {
		Saved_shape[Flag] = { None,{0},0,0 };
		Flag--;
		Clear();
		PrintMenuRectangle(1, 100, 260, 700, line_t.type, line_t.thickness);
		Reprint();
		return 0;
	}
}
