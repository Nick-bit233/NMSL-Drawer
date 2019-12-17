#include <math.h>
#include <stdio.h>
#include <io.h>  
#include <Windows.h>  
#include "graphics.h"
#include "DrawerFun.h"
#include "DrawerSet.h"
#include "Process.h"

//全局变量：
int check_start = 1;
int check_main = 1;
int check_findredraw = 1;
int check_redraw = 0;
int check_draw = 1;
int check_set = 1;
int check_setfrontcolor = 1;
int check_setbackcolor = 1;
int check_setfillcolor = 1;
int check_setlinetype = 1;
extern LINET line_t;
int double_check = 0;
char current_filename[260];//储存当前编辑的文件名
char filename[51][260] = { 0 };//储存文件名的数组，最多50个
//绘图和设置的实现函数
int Settings(int switch_3) {
	PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
	switch (switch_3)
	{
	case 49:
		Clear_menu();
		check_setfrontcolor = 1;
		while (check_setfrontcolor == 1) {
			PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
			int switch_frontcolor;
			PrintColorMenu();   //简化代码，用颜色菜单打印函数替换重复部分
			switch_frontcolor = getch();
			if(CheckColorRepeat(switch_frontcolor,1) == 1 )  //CheckColorRepeat用来检测前景色和背景色是否重合
				check_setfrontcolor = Set_front_color(switch_frontcolor);  //设置前景色（选项菜单模式）
		} 
		delay_ms(500);
		break;
	case 50:
		Clear_menu();
		check_setbackcolor = 1;
		while (check_setbackcolor == 1) {
			PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
			int switch_backcolor;
			PrintColorMenu();
			switch_backcolor = getch();
			if (CheckColorRepeat(switch_backcolor, 2) == 1)
				check_setbackcolor = Set_back_color(switch_backcolor);//设置背景色（选项菜单模式）
		}
		delay_ms(500);
		break;
	case 51:
		Clear_menu();
		check_setfillcolor = 1;
		while (check_setfillcolor == 1) {
			PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
			int switch_fillcolor;
			PrintColorMenu();
			switch_fillcolor = getch();
			if (CheckColorRepeat(switch_fillcolor, 3) == 1)
				check_setfillcolor = Set_fill_color(switch_fillcolor);//设置填充色（选项菜单模式）
		}
		delay_ms(500);
		break;
	case 52:
		Clear_menu();
		check_setlinetype = 1;
		while (check_setlinetype == 1) {
			PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
			int switch_linetype;
			xyprintf(15, 120, "1-4设置线形为：");
			xyprintf(30, 135, "1:实线 ————");
			xyprintf(30, 150, "2:虚线 ----");
			xyprintf(30, 165, "3:点线 ····");
			xyprintf(30, 180, "4:点虚线 -·-·");
			xyprintf(15, 195, "【注：设置线条粗细仅限实线】");
			xyprintf(15, 230, "线条粗细值示例：");
			xyprintf(15, 250, "1磅");
			xyprintf(15, 270, "2磅");
			xyprintf(15, 290, "5磅");
			xyprintf(15, 320, "10磅");
			xyprintf(15, 400, "0:返回上一级");
			setlinestyle(SOLID_LINE, NULL, 1, NULL);
			line(50, 250, 120, 250);
			setlinestyle(SOLID_LINE, NULL, 2, NULL);
			line(50, 270, 120, 270);
			setlinestyle(SOLID_LINE, NULL, 5, NULL);
			line(50, 290, 120, 290);
			setlinestyle(SOLID_LINE, NULL, 10, NULL);
			line(50, 320, 120, 320);
			setlinestyle(line_t.type, NULL, line_t.thickness, NULL);
			switch_linetype = getch();
			check_setlinetype = Set_linetype(switch_linetype);
		}
		delay_ms(500);
		break;
	case 48:
		return 0;
	}
	return 1;
}    //设置菜单的实现
int Draw(int switch_2) {
	PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
	switch (switch_2)
	{
	case 49:
		Draw_point();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 50:
		Draw_line();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 51:
		Draw_arcf();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 52:
		Draw_empty_rectangle();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 53:
		Draw_circle();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 54:
		Draw_empty_ellipse();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 55:
		Draw_empty_poly();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 99:
		Draw_fill_circle();
		check_redraw = 1;
		delay_ms(500);
		Clear_info();
		break;
	case 114:
		Draw_fill_rectangle();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 116:
		Draw_fill_ellipse();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 112:
		Draw_fill_poly();
		check_redraw = 1;
		delay_ms(500);
		break;
	case 'z':
		if (UNDO()) {
			xyprintf(15, 705, "没有可以撤销的操作！");
			delay_ms(500);
			Clear_info();
		}
		break;
	case 48:
		return 0;
	}
	return 1;
}    //绘图菜单的实现

//绘图菜单和设置菜单（第三层菜单）
void menu_Draw() {
	Clear_menu();
	Clear_info();
	check_draw = 1;
	while (check_draw == 1) {
		FileWriting(current_filename);
		int switch_2;
		xyprintf(15, 120, "1:画点");
		xyprintf(15, 135, "2:画直线");
		xyprintf(15, 150, "3:画圆弧");
		xyprintf(15, 165, "4:画矩形");
		xyprintf(15, 180, "5:画圆");
		xyprintf(15, 195, "6:画椭圆");
		xyprintf(15, 210, "7:画多边形");
		xyprintf(15, 225, "c:画填充圆");
		xyprintf(15, 240, "r:画填充矩形");
		xyprintf(15, 255, "t:画填充椭圆");
		xyprintf(15, 270, "p:画填充多边形");
		xyprintf(15, 300, "z:撤销（不可重做哦）");
		xyprintf(15, 320, "0:返回上一级");
		switch_2 = getch();
		check_draw = Draw(switch_2); //返回1保持菜单活动，返回0退出循环回到上级
	}
}
void menu_Settings() {
	Clear_menu();
	Clear_info();
	check_set = 1;
	while (check_set == 1) {
		PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
		Clear_menu();
		int switch_3;
		xyprintf(15, 120, "1:设置前景色");
		xyprintf(15, 135, "2:设置背景色");
		xyprintf(15, 150, "3:设置填充色");
		xyprintf(15, 165, "4:设置线形和线条粗细");
		xyprintf(15, 300, "0:返回上一级");
		switch_3 = getch();
		check_set = Settings(switch_3);//同上道理
	}
}

//清屏，绘图和设置菜单的入口（第二层菜单）（集成了返回第一层菜单的功能）
int menu_Second(int switch_1) {
	Clear_info();
	PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
	switch (switch_1)
	{
	case 49:
		Clear_menu();
		PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
		xyprintf(15, 705, "确认要清屏吗？（1：是 | 其他按键：返回）");
		double_check = getch();//清屏二次确认
		if (double_check == 49) {
			Clear();
			Clear_menu();
			Clear_info();
			PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
			xyprintf(15, 705, "已清空！即将返回");
			delay_ms(1000);
		}
		else {
			return 1;
		}
		return 1;
	case 50:
		menu_Draw();
		return 1;
	case 51:
		menu_Settings();
		return 1;
	case 52:
		if (check_redraw == 1) {
			Reprint();
			xyprintf(15, 705, "重新作画已完成！");
			delay_ms(1000);
			Clear_info();
		}
		else {
			xyprintf(15, 705, "当前没有作画！");
			delay_ms(1000);
			Clear_info();
		}
		return 1;
	case 53:
		if (check_redraw == 1){
			check_findredraw = 1;
			while (check_findredraw == 1) {
				PrintMenuRectangle(1, 100, 260, 700, line_t.type, line_t.thickness);
				Clear_menu();
				int switch_find;
				xyprintf(15, 120, "查询内存中是否有：");
				xyprintf(15, 135, "1:点");
				xyprintf(15, 150, "2:直线");
				xyprintf(15, 165, "3:圆弧");
				xyprintf(15, 180, "4:空心矩形");
				xyprintf(15, 195, "5:空心圆");
				xyprintf(15, 210, "6:空心椭圆");
				xyprintf(15, 225, "7:空心多边形");
				xyprintf(15, 240, "8:填充圆");
				xyprintf(15, 255, "9:填充矩形");
				xyprintf(15, 270, "a:填充椭圆");
				xyprintf(15, 285, "b:填充多边形");

				xyprintf(15, 300, "0:返回上一级");
				switch_find = getch();
				check_findredraw = FindReprint(switch_find);
				delay_ms(500);
				Clear_info();
			}
		}
		else {
			xyprintf(15, 705, "当前没有作画！");
			delay_ms(1000);
			Clear_info();
		}
		return 1;
	case 54:
		Clear_menu();
		xyprintf(15, 105, "自由绘制模式");
		xyprintf(15, 120, "请使用鼠标自由绘制图案");
		xyprintf(15, 140, "【注意：");
		xyprintf(15, 155, "  自由绘画无法保存！】");
		rectangle(15, 200, 140, 260);
		rectangle(15, 300, 140, 360);
		xyprintf(40, 220, "点击退出");
		xyprintf(40, 320, "点击清除屏幕");
		Freedraw();
		return 1;
	case 48:
		xyprintf(15, 705, "已保存！即将退出");
		delay_ms(1500);
		return 0;//返回0退出main函数中的循环
	default:
		xyprintf(10, 680, "非法参数，请重新输入");
		delay_ms(500);
		return 1;//给出错误提示并返回1，保持待输入状态
	}
	return 0;
}//第二级菜单

//第一级菜单
void menu_Start() {
	setcolor(BLACK);
	setbkcolor(WHITE);
	xyprintf(0, 20, "———NMSL画板 V1.0.0 控制台———");
	xyprintf(0, 40, "（注：NMSL = New Mine Scinece Lab ）");
	xyprintf(0, 60, "—————————————————");
	xyprintf(0, 80, "请选择你要进行的操作：");
	int switch_main;
	while (check_main == 1) {
		FileWriting(current_filename);
		PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);   //菜单外边框
		Clear_menu();
		xyprintf(15, 165, "1:清空当前画板");
		xyprintf(15, 180, "2:进入绘图区");
		xyprintf(15, 195, "3:设置");
		xyprintf(15, 210, "4:重做已保存的作画");
		xyprintf(15, 225, "5:查询已保存的作画");
		xyprintf(15, 240, "6:自由绘画");
		xyprintf(15, 300, "0:保存并退出");
		switch_main = getch();
		check_main = menu_Second(switch_main);
	}
}
//查找文件
int Findfile() {
	long handle;  //用long整形存储的文件地址
	struct _finddata_t fileinfo; //储存文件信息的结构体
	handle = _findfirst("*.dat", &fileinfo);//找到第一个后缀名为.dat的文件并存储文件地址到handle,找不到文件返回-1
	if (handle == -1)
		return -1;
	int i = 1;  //i用来存储找到文件的数量
	sprintf(filename[i], fileinfo.name);
	while (!_findnext(handle, &fileinfo))//继续寻找其他.dat文件，直到找完或超过内存为止
	{
		i += 1;
		if (i > 50) {
			xyprintf(460, 140, "警告：已储存文件数量超过内存最大值，部分文件可能无法读取");
			delay_ms(1000);
			break;
		}
		sprintf(filename[i], fileinfo.name);
	}
	_findclose(handle);//结束文件搜索
	return i;
}
//通过列表选择读取文件
int Choosefile() { 
	int i,chosenfile = 0;
	i = Findfile();
	if (i == -1)
		return -1;
	//接下来按页打印文件名并供用户翻页和选择
	Clear();
	xyprintf(460, 160, "请选择要打开的文件：");
	int t = 200,k = 0; //t:标记打印的垂直位置，k:标记当前页码
	if(i <= 9){
		for (int j = 1; j <= i; j++) {
			xyprintf(500, t, "%d.%s\n", j, filename[j]);
			t += 20;
		}
		chosenfile = getch();
		chosenfile -= '0';
		FileReading(filename[chosenfile]);
		sprintf(current_filename, filename[chosenfile]);
		return 0;
	}
	else {
		while (!chosenfile) {
			Clear();
			xyprintf(460, 160, "请选择要打开的文件：");
			t = 200;
			if (k == 0) {
				for (int j = 1; j <= 9; j++) {
					xyprintf(500, t, "%d.%s\n", j, filename[j]);
					t += 20;
				}
				xyprintf(500, t, ">.下一页");
			}
			else if (k == (i-1) / 9 ) {
				int index = 1;
				for (int j = 9 * k + 1; j <= i; j++) {
					xyprintf(500, t, "%d.%s\n", index, filename[j]);
					t += 20;
					index++;
				}
				xyprintf(500, t, "<.上一页");
			}
			else {
				int index = 1;
				for (int j = 9 * k + 1; j <= 9 * (k+1) ; j++) {
					xyprintf(500, t, "%d.%s\n", index, filename[j]);
					t += 20;
					index++;
				}
				xyprintf(500, t, "<.上一页");
				t += 20;
				xyprintf(500, t, ">.下一页");
			}
			chosenfile = getch();
			chosenfile -= '0';
			if (chosenfile > 0 && chosenfile < 10) {
				chosenfile = chosenfile + 9 * k;
				FileReading(filename[chosenfile]);
				sprintf(current_filename, filename[chosenfile]);
				return 0;
			}
			else if (chosenfile == -4) {
				if (k >= 1)
					k--;
				chosenfile = 0;
			}
			else if (chosenfile == -2) {
				if (k <= i / 9 - 1 && (k+1)*9 != i)
					k++;
				chosenfile = 0;
			}
			else {
				chosenfile = 0;
			}
		}
		return 0;
	}
}
//初始化读取文件函数，包含用户是否读取文件以及读取是否成功的框架
void menu_Welcome() {
	setinitmode(INIT_WITHLOGO);
	initgraph(1280, 725);
	setcaption("NMSL画板V1.2.0");
	int switch_start = 0;
	setfont(16, 0, "黑体",0,0, 550,false,false,false);
	while (check_start == 1) {
		xyprintf(410, 200, "欢迎来到NMSL画板（注：NMSL=New Mine Scinece Lab：）V1.2.0");
		xyprintf(540, 220, "是否读取已保存的文件？");
		xyprintf(410, 240, "————————1：是    2：否    0：退出————————");
		switch_start = getch();
		if (switch_start == 49) {
			int judge_filereading = 1;
			if(judge_filereading = Choosefile()){
				xyprintf(400, 340, "读取文件失败，请检查否存在.dat文件或新建文件");
				delay_ms(1000);
				Clear();
				check_start = 1;
				continue;
			}
			xyprintf(600, 640, "读取文件成功");
			check_redraw = 1;
			check_start = 0;
			break;
		}
		else if (switch_start == 50) {
			int judge_samename = 1;
			int i = Findfile();
			int ifcover;
			while(judge_samename){
				inputbox_getline("新建文件", "请输入文件名（不需要后缀名）", current_filename, 260);
				for (int j = 1; j <= i; j++) {
					if (CheckFilenameRepeat(current_filename, filename[j])) {
						char text[3] = { 0 };
						inputbox_getline("警告", "当前文件已存在，确定要覆盖吗？\n输入1覆盖，输入其它重新命名", text, 2);
						ifcover = atoi(text);
						if (ifcover == 1)
							judge_samename = 0;
						else
							judge_samename = 2;
						break;
					}
				}
				if (judge_samename == 1)
					break;
				else
					judge_samename = 1;
			}
			strcat(current_filename, ".dat");
			xyprintf(500, 340, "已新建文件");
			delay_ms(1000);
			check_redraw = 0;
			check_start = 0;
		}
		else if (switch_start == 48) {
			closegraph();
			check_start = 0;
		}
		else {
			xyprintf(500, 340, "输入有误，请重新输入");
			delay_ms(500);
			Clear(); //清除提示信息
		}
	}
	delay_ms(500);
	clearviewport();
}

int main(void) {
	menu_Welcome();
	menu_Start();
	FileWriting(current_filename);
	closegraph();
	return 0;
}

