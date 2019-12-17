
#include "graphics.h"
#include "Process.h"
#include "DrawerFun.h"
#include <math.h>
#include <stdio.h>
int Flag = 0;
char Text_temp[3];                             //临时存储输入文本（判断输入错误时使用）
NMSLSHAPE Saved_shape[100] = { None,{0},0,0 }; //定义图形储存结构体
extern LINET line_t;

//绘图中的函数
int Draw_point() {
	char Text_pointx[] = "请输入点的横坐标:(000——999，否则会超出范围)";
	char Text_pointy[] = "请输入点的纵坐标:(000——700，否则会超出范围)";
	int x = -1, y = -1, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx, point_x, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy, point_y, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		if (x == -1 || y == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
			if (atoi(Text_temp) == -1)        //提示框，提示输入错误并供用户选择重新输入还是取消绘制，	其他绘图函数同理包含此模块
				return 0;
			else
				f = 1;
		}
		else
			f = 0;
	}
	putpixel(x + 280, y, getcolor());
	Clear_info();
	xyprintf(15, 705, "该点坐标为：(%d,%d) ", x, y);
	Flag++;
	Saved_shape[Flag].type = Point;
	Saved_shape[Flag].parameter[0] = x;
	Saved_shape[Flag].parameter[1] = y;
	Saved_shape[Flag].color = getcolor();
	return 0;
}
int Draw_circle() {
	char Text_pointx[] = "请输入圆心的横坐标:(0——999，否则会超出范围)";
	char Text_pointy[] = "请输入圆心的纵坐标:(0——700，否则会超出范围)";
	char Text_radio[] = "请输入半径:(0——700，否则会超出范围)";
	int x = 0, y = 0, r = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], radio[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx, point_x, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy, point_y, 4);
		inputbox_getline("这是一个可爱的输入框", Text_radio, radio, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		r = GetInt(radio);
		if (x == -1 || y == -1 || r == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "圆心坐标(%d, %d) , 半径%d", x, y, r);
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
	char Text_pointx1[] = "请输入 左端点 横坐标x1:(0——999，否则会超出范围)";
	char Text_pointy1[] = "请输入 左端点 纵坐标y1:(0——700，否则会超出范围)";
	char Text_pointx2[] = "请输入 右端点 横坐标x2:(0——999，否则会超出范围)";
	char Text_pointy2[] = "请输入 右端点 纵坐标y2:(0——700，否则会超出范围)";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, f = 1;
	while (f == 1) {
		char point_x1[4], point_y1[4], point_x2[4], point_y2[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx1, point_x1, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy1, point_y1, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointx2, point_x2, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy2, point_y2, 4);
		x1 = GetInt(point_x1);
		y1 = GetInt(point_y1);
		x2 = GetInt(point_x2);
		y2 = GetInt(point_y2);
		if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "左端点(%d, %d) ,右端点（%d, %d）, 长度%d", x1, y1, x2, y2, r);
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
	char Text_pointx1[] = "请输入 左上端点A 横坐标x1:(0——999，否则会超出范围)";
	char Text_pointy1[] = "请输入 左上端点A 纵坐标y1:(0——700，否则会超出范围)";
	char Text_pointx2[] = "请输入 右下端点D 横坐标x2:(0——999，否则会超出范围)";
	char Text_pointy2[] = "请输入 右下端点D 纵坐标y2:(0——700，否则会超出范围)";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, f = 1;
	while (f == 1) {
		char point_x1[4], point_y1[4], point_x2[4], point_y2[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx1, point_x1, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy1, point_y1, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointx2, point_x2, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy2, point_y2, 4);
		x1 = GetInt(point_x1);
		y1 = GetInt(point_y1);
		x2 = GetInt(point_x2);
		y2 = GetInt(point_y2);
		if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "矩形中心坐标(%d, %d) , 长%d ,宽%d", (x1 + x2) / 2, (y1 + y2) / 2, abs(x2 - x1), abs(y2 - y1));
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
	char Text_pointx[] = "请输入圆心的横坐标:(0——999，否则会超出范围)";
	char Text_pointy[] = "请输入圆心的纵坐标:(0——700，否则会超出范围)";
	char Text_radio[] = "请输入半径:(0——700，否则会超出范围)";
	char Text_rstart[] = "请输入圆弧起始角度（顺时针）:(0——360，否则会超出范围)";
	char Text_rend[] = "请输入圆弧终止角度（顺时针）:(0——360，否则会超出范围)";
	int x = 0, y = 0, r = 0, rs = 0, re = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], radio[4], rstart[4], rend[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx, point_x, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy, point_y, 4);
		inputbox_getline("这是一个可爱的输入框", Text_radio, radio, 4);
		inputbox_getline("这是一个可爱的输入框", Text_rstart, rstart, 4);
		inputbox_getline("这是一个可爱的输入框", Text_rend, rend, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		r = GetInt(radio);
		rs = GetInt(rstart);
		re = GetInt(rend);
		if (x == -1 || y == -1 || r == -1 || rs == -1 || re == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "圆心坐标(%d, %d) , 半径%d, 角度数%d", x, y, r, abs(re - rs));
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
	char Text_pointx[] = "请输入椭圆中心的横坐标:(0——999，否则会超出范围)";
	char Text_pointy[] = "请输入椭圆中心的纵坐标:(0——700，否则会超出范围)";
	char Text_ea[] = "请输入椭圆半长轴长a:";
	char Text_eb[] = "请输入椭圆半短轴长b:";
	int x = 0, y = 0, a = 0, b = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], ea[4], eb[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx, point_x, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy, point_y, 4);
		inputbox_getline("这是一个可爱的输入框", Text_ea, ea, 4);
		inputbox_getline("这是一个可爱的输入框", Text_eb, eb, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		a = GetInt(ea);
		b = GetInt(eb);
		if (x == -1 || y == -1 || a == -1 || b == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "椭圆圆心坐标(%d, %d) ,参数a，b = %d，%d", x, y, a, b);
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
	sprintf(Text_pnumber, "请输入多边形的顶点点数\n（顶点数不能超过18）");
	char pnumber[4];
	inputbox_getline("这是一个可爱的输入框", Text_pnumber, pnumber, 4);
	int pn = GetInt(pnumber);
	while (pn <= 2 || pn > 18) {
		char Text_pnumber1[32] = { 0 };
		if (pn <= 2)
			sprintf(Text_pnumber1, "多边形顶点数至少为3！请重新输入");
		if (pn > 18)
			sprintf(Text_pnumber1, "多边形顶点数太多了！ 请重新输入");
		char pnumber1[4];
		inputbox_getline("这个输入框有点不太高兴", Text_pnumber1, pnumber1, 4);
		pn = GetInt(pnumber1);
	}
	char Text_pointx[18][72] = { 0 };
	char Point_x[18][4] = { 0 };
	char Text_pointy[18][72] = { 0 };
	char Point_y[18][4] = { 0 };
	int ps[38] = { 0 };
	int i;
	char temp[100] = "这是一个可爱的输入框";
	for (i = 0; i < pn; i++) {    //对于多边形，由于使用了for循环输入，输入错误时用i--和continue重置条件，可以实现不退出循环重新输入。
		int t = 2 * i;
		sprintf(Text_pointx[i], "请输入\n顶点%d\n横坐标x%d:(1——999，否则会超出范围)\n【取消绘制请输入0】", i + 1, i + 1); //此外，也提供了用户手动退出循环的功能
		inputbox_getline(temp, Text_pointx[i], Point_x[i], 4);
		ps[t] = GetInt(Point_x[i]);
		if (ps[t] == 0)
			return 0;
		if (ps[t] == -1) {
			sprintf(temp, "输入格式有误，请重新输入该组坐标！");
			i--;
			continue;
		}
		sprintf(Text_pointy[i], "请输入\n顶点%d\n纵坐标y%d:(1——700，否则会超出范围)\n【取消绘制请输入0】", i + 1, i + 1);
		inputbox_getline(temp, Text_pointy[i], Point_y[i], 4);
		ps[t + 1] = GetInt(Point_y[i]);
		if (ps[t + 1] == 0)
			return 0;
		if (ps[t + 1] == -1) {
			sprintf(temp, "输入格式有误，请重新输入该组坐标！");
			i--;
			continue;
		}
		sprintf(temp, "这是一个可爱的输入框");
	}
	ps[2 * pn] = ps[0];
	ps[2 * pn + 1] = ps[1];
	setviewport(280, 0, getwidth(), 700);
	drawpoly(pn + 1, ps);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "多边形的顶点数为%d", pn);
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
	char Text_pointx1[] = "请输入 左上端点A 横坐标x1:(0——999，否则会超出范围)";
	char Text_pointy1[] = "请输入 左上端点A 纵坐标y1:(0——700，否则会超出范围)";
	char Text_pointx2[] = "请输入 右下端点D 横坐标x2:(0——999，否则会超出范围)";
	char Text_pointy2[] = "请输入 右下端点D 纵坐标y2:(0——700，否则会超出范围)";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, f = 1;
	while (f == 1) {
		char point_x1[4], point_y1[4], point_x2[4], point_y2[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx1, point_x1, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy1, point_y1, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointx2, point_x2, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy2, point_y2, 4);
		x1 = GetInt(point_x1);
		y1 = GetInt(point_y1);
		x2 = GetInt(point_x2);
		y2 = GetInt(point_y2);
		if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "矩形中心坐标(%d, %d) , 长%d ,宽%d", (x1 + x2) / 2, (y1 + y2) / 2, abs(x2 - x1), abs(y2 - y1));
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
	char Text_pointx[] = "请输入圆心的横坐标:(0——999，否则会超出范围)";
	char Text_pointy[] = "请输入圆心的纵坐标:(0——700，否则会超出范围)";
	char Text_radio[] = "请输入半径:(0——700，否则会超出范围)";
	int x = 0, y = 0, r = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], radio[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx, point_x, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy, point_y, 4);
		inputbox_getline("这是一个可爱的输入框", Text_radio, radio, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		r = GetInt(radio);
		if (x == -1 || y == -1 || r == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "圆心坐标(%d, %d) , 半径%d", x, y, r);
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
	char Text_pointx[] = "请输入椭圆中心的横坐标:(0——999，否则会超出范围)";
	char Text_pointy[] = "请输入椭圆中心的纵坐标:(0——700，否则会超出范围)";
	char Text_ea[] = "请输入椭圆半长轴长a:";
	char Text_eb[] = "请输入椭圆半短轴长b:";
	int x = 0, y = 0, a = 0, b = 0, f = 1;
	while (f == 1) {
		char point_x[4], point_y[4], ea[4], eb[4];
		inputbox_getline("这是一个可爱的输入框", Text_pointx, point_x, 4);
		inputbox_getline("这是一个可爱的输入框", Text_pointy, point_y, 4);
		inputbox_getline("这是一个可爱的输入框", Text_ea, ea, 4);
		inputbox_getline("这是一个可爱的输入框", Text_eb, eb, 4);
		x = GetInt(point_x);
		y = GetInt(point_y);
		a = GetInt(ea);
		b = GetInt(eb);
		if (x == -1 || y == -1 || a == -1 || b == -1) {
			inputbox_getline("这个输入框有点不太高兴", "输入的坐标不是正整数，请重新输入！\n 按Enter重新输入，输入-1取消绘制", Text_temp, 3);
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
	xyprintf(15, 705, "椭圆圆心坐标(%d, %d) ,参数a，b = %d，%d", x, y, a, b);
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
	sprintf(Text_pnumber, "请输入多边形的顶点点数\n（顶点数不能超过18）");
	char pnumber[4];
	inputbox_getline("这是一个可爱的输入框", Text_pnumber, pnumber, 4);
	int pn = GetInt(pnumber);
	while (pn <= 2 || pn > 18) {
		char Text_pnumber1[32] = { 0 };
		if (pn <= 2)
			sprintf(Text_pnumber1, "多边形顶点数至少为3！请重新输入");
		if (pn > 18)
			sprintf(Text_pnumber1, "多边形顶点数太多了！ 请重新输入");
		char pnumber1[4];
		inputbox_getline("这个输入框有点不太高兴", Text_pnumber1, pnumber1, 4);
		pn = GetInt(pnumber1);
	}
	char Text_pointx[18][72] = { 0 };
	char Point_x[18][4] = { 0 };
	char Text_pointy[18][72] = { 0 };
	char Point_y[18][4] = { 0 };
	int ps[38] = { 0 };
	int i;
	char temp[100] = "这是一个可爱的输入框";
	for (i = 0; i < pn; i++) {
		int t = 2 * i;
		sprintf(Text_pointx[i], "请输入\n顶点%d\n横坐标x%d:(1——999，否则会超出范围)\n【取消绘制请输入0】", i + 1, i + 1);
		inputbox_getline(temp, Text_pointx[i], Point_x[i], 4);
		ps[t] = GetInt(Point_x[i]);
		if (ps[t] == 0)
			return 0;
		if (ps[t] == -1) {
			sprintf(temp, "输入格式有误，请重新输入该组坐标！");
			i--;
			continue;
		}
		sprintf(Text_pointy[i], "请输入\n顶点%d\n纵坐标y%d:(1——700，否则会超出范围)\n【取消绘制请输入0】", i + 1, i + 1);
		inputbox_getline(temp, Text_pointy[i], Point_y[i], 4);
		ps[t + 1] = GetInt(Point_y[i]);
		if (ps[t + 1] == 0)
			return 0;
		if (ps[t + 1] == -1) {
			sprintf(temp, "输入格式有误，请重新输入该组坐标！");
			i--;
			continue;
		}
		sprintf(temp, "这是一个可爱的输入框");
	}
	setviewport(280, 0, getwidth(), 700);
	fillpoly(pn, ps);
	setviewport(0, 0, getwidth(), getheight());
	Clear_info();
	xyprintf(15, 705, "多边形的顶点数为%d", pn);
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

//重新绘制的函数（读取结构体内的数据并重新绘制）
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
//自由绘制函数
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
			xyprintf(1100, 705, "当前鼠标位置：%d %d", ms.x-280, ms.y);
		else
			xyprintf(1100, 705, "当前鼠标位置：                 ", ms.x - 280, ms.y);
	}
	return 0;
}

//查询函数
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
		char name[12][100] = { "空","点","直线","圆弧","空心矩形","空心圆","空心椭圆","空心多边形","填充圆","填充矩形","填充椭圆","填充多边形" };
		for (int i = 1; i <= Flag; i++) {
			if (Saved_shape[i].type == find)
				count++;
		}
		if (count > 0) {
			xyprintf(15, 405, "内存中有%d个%s", count, name[find]);
		}
		else {
			xyprintf(15, 405, "内存中未找到该图形");
		}
	}
	return 1;
}
//撤销绘制函数
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
