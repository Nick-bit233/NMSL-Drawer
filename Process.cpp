#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"
#include "DrawerFun.h"
#define PINK 0xffc0cb
int color_Dict[] = {BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,YELLOW,PINK,WHITE,LIGHTGRAY,DARKGRAY,LIGHTBLUE,LIGHTGREEN};
NMSLSHAPE Temp_shape[100];
extern NMSLSHAPE Saved_shape[100];
extern int Flag;
//转换类型用的函数（三位使用，其他位数使用atoi）
int GetInt(char text[4]) {
	int a = 0, tenin = 1, k = 0;
	if (text[k] == '\0')
		return -1;
	while (text[k] != '\0') {
		if (text[k] > '9' || text[k] < '0')
			return -1;         //判断输入是否符合整数格式，不符合返回-1
		k++;
	}
	if (text[1] == '\0') {
		a = text[0] - '0';
		return a;
	}
	for (int i = 2; i >= 0; i--) {
		if (text[i] == '\0')
			text[i] = 0;
		else {
			text[i] = text[i] - '0';
			a += (text[i] * tenin);
			tenin = tenin * 10;
		}
	}
	return a;
}//将获得的三位字符串转换为整数类型（只能是三位数）

//文件读取的实现
int FileReading(char *name){
	FILE* fp;
	if ((fp = fopen(name, "rb")) == NULL) {
		return -1;
	}
	else {
		fread((void*)&Flag, sizeof(int), 1, fp);
		int i = 0;
		while (!feof(fp))
		{
			i++;
			fread(&Saved_shape[i], sizeof(NMSLSHAPE), 1, fp);
		}
		return 1;
	}
}

//文件写入的实现
int FileWriting(char name[260]) {
	int number_of_shape = Flag;
	FILE* fp;
	if ((fp=fopen(name, "wb") )== NULL){
		return -1;
	}
	fwrite((void*)&number_of_shape, sizeof(int), 1, fp);
	for(int i = 1 ; i<= number_of_shape;i++)
		fwrite(&Saved_shape[i], sizeof(NMSLSHAPE), 1 , fp);
	fclose(fp);

	return 0;
}

//简化菜单打印的函数
void PrintColorMenu() {
	xyprintf(15, 120, "1:蓝色");
	xyprintf(15, 135, "2:绿色");
	xyprintf(15, 150, "3:青色");
	xyprintf(15, 165, "4:红色");
	xyprintf(15, 180, "5:紫色");
	xyprintf(15, 195, "6:棕色");
	xyprintf(15, 210, "7:黄色");
	xyprintf(15, 225, "8:粉色");
	xyprintf(15, 240, "9:白色");
	xyprintf(15, 255, "z:浅灰色");
	xyprintf(15, 270, "x:深灰色");
	xyprintf(15, 285, "c:亮蓝色");
	xyprintf(15, 300, "v:亮绿色");
	xyprintf(15, 315, "b:黑色");
	xyprintf(15, 360, "0:返回上一级");
	xyprintf(15, 375, "【ps：请使用英文输入法】");
}
void PrintMenuRectangle(int x1, int y1, int x2, int y2, int type,int thickness) {
	setlinestyle(type, NULL, 1, NULL);
	rectangle(x1, y1, x2, y2);
	setlinestyle(type, NULL, thickness, NULL);
}
//检查设置颜色时颜色是否重合
int CheckColorRepeat(int Color,int check_Type) {
	int check_color_n = Color;
	char choice[2] = { 0 };
	if (Color <= 57 && Color >= 49) {
		check_color_n = color_Dict[Color - '0'];
	}
	else {
		switch (Color) {
		case 122:
			check_color_n = color_Dict[10];
			break;
		case 120:
			check_color_n = color_Dict[11];
			break;
		case 99:
			check_color_n = color_Dict[12];
			break;
		case 118:
			check_color_n = color_Dict[13];
			break;
		case 98:
			check_color_n = color_Dict[0];
			break;
		}
	}
	if (check_Type == 1) {
		if (check_color_n == getbkcolor()) {
			char Text_warning[100] = { 0 };
			sprintf(Text_warning, "准备设置的前景色与背景色相同，\n可能会导致菜单、作画被覆盖\n确定要继续吗？\n确定请输入1，输入其他取消");
			inputbox_getline("警告！！！", Text_warning, choice, 2);
			return atoi(choice);
		}
	}
	else if (check_Type == 2) {
		if (check_color_n == getcolor()) {
			char Text_warning[100] = { 0 };
			sprintf(Text_warning, "准备设置的背景色与前景色相同，\n可能会导致菜单、作画被覆盖\n确定要继续吗？\n确定请输入1，输入其他取消");
			inputbox_getline("警告！！！", Text_warning, choice, 2);
			return atoi(choice);
		}
	}
	else if (check_Type == 3) {
		if (check_color_n == getbkcolor()) {
			char Text_warning[100] = { 0 };
			sprintf(Text_warning, "准备设置的填充色与背景色相同，\n可能会导致作画被覆盖\n确定要继续吗？\n确定请输入1，输入其他取消");
			inputbox_getline("警告！！！", Text_warning, choice, 2);
			return atoi(choice);
		}
	}
	return 1;
}
//刷新屏幕用的函数
int CheckFilenameRepeat(char name1[260], char name2[260]) {
	int k = 0;
	while (name2[k] != '.') {
		if (name1[k] != name2[k]) {
			return 0;
		}
		k++;
	}
	if (name1[k] != '\0')
		return 0;
	return 1;
}
void Clear() {
	int colortemp = getfillcolor();
	setfillcolor(getbkcolor());
	bar(280, 0, getwidth(), getheight());
	setfillcolor(colortemp);	
}    //清屏，用于清除画板内容
void Clear_menu() {
	int colortemp = getfillcolor();
	setfillcolor(getbkcolor());
	bar(2, 101, 259, 699);
	setfillcolor(colortemp);
	xyprintf(0, 20, "———NMSL画板 V1.2.0 控制台———");
	xyprintf(0, 40, "（注：NMSL = New Mine Scinece Lab ）");
	xyprintf(0, 60, "———Copyright By @Nick-bit———");
	xyprintf(0, 80, "请选择你要进行的操作：");
}    //清除菜单内容，用于菜单刷新的时候
void Clear_info() {
	int colortemp = getfillcolor();
	setfillcolor(getbkcolor());
	bar(15,705,getwidth(),720);
	setfillcolor(colortemp);
}   //清除绘图信息内容，用于菜单刷新的时候
