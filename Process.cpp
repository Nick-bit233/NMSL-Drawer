#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"
#include "DrawerFun.h"
#define PINK 0xffc0cb
int color_Dict[] = {BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,YELLOW,PINK,WHITE,LIGHTGRAY,DARKGRAY,LIGHTBLUE,LIGHTGREEN};
NMSLSHAPE Temp_shape[100];
extern NMSLSHAPE Saved_shape[100];
extern int Flag;
//ת�������õĺ�������λʹ�ã�����λ��ʹ��atoi��
int GetInt(char text[4]) {
	int a = 0, tenin = 1, k = 0;
	if (text[k] == '\0')
		return -1;
	while (text[k] != '\0') {
		if (text[k] > '9' || text[k] < '0')
			return -1;         //�ж������Ƿ����������ʽ�������Ϸ���-1
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
}//����õ���λ�ַ���ת��Ϊ�������ͣ�ֻ������λ����

//�ļ���ȡ��ʵ��
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

//�ļ�д���ʵ��
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

//�򻯲˵���ӡ�ĺ���
void PrintColorMenu() {
	xyprintf(15, 120, "1:��ɫ");
	xyprintf(15, 135, "2:��ɫ");
	xyprintf(15, 150, "3:��ɫ");
	xyprintf(15, 165, "4:��ɫ");
	xyprintf(15, 180, "5:��ɫ");
	xyprintf(15, 195, "6:��ɫ");
	xyprintf(15, 210, "7:��ɫ");
	xyprintf(15, 225, "8:��ɫ");
	xyprintf(15, 240, "9:��ɫ");
	xyprintf(15, 255, "z:ǳ��ɫ");
	xyprintf(15, 270, "x:���ɫ");
	xyprintf(15, 285, "c:����ɫ");
	xyprintf(15, 300, "v:����ɫ");
	xyprintf(15, 315, "b:��ɫ");
	xyprintf(15, 360, "0:������һ��");
	xyprintf(15, 375, "��ps����ʹ��Ӣ�����뷨��");
}
void PrintMenuRectangle(int x1, int y1, int x2, int y2, int type,int thickness) {
	setlinestyle(type, NULL, 1, NULL);
	rectangle(x1, y1, x2, y2);
	setlinestyle(type, NULL, thickness, NULL);
}
//���������ɫʱ��ɫ�Ƿ��غ�
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
			sprintf(Text_warning, "׼�����õ�ǰ��ɫ�뱳��ɫ��ͬ��\n���ܻᵼ�²˵�������������\nȷ��Ҫ������\nȷ��������1����������ȡ��");
			inputbox_getline("���棡����", Text_warning, choice, 2);
			return atoi(choice);
		}
	}
	else if (check_Type == 2) {
		if (check_color_n == getcolor()) {
			char Text_warning[100] = { 0 };
			sprintf(Text_warning, "׼�����õı���ɫ��ǰ��ɫ��ͬ��\n���ܻᵼ�²˵�������������\nȷ��Ҫ������\nȷ��������1����������ȡ��");
			inputbox_getline("���棡����", Text_warning, choice, 2);
			return atoi(choice);
		}
	}
	else if (check_Type == 3) {
		if (check_color_n == getbkcolor()) {
			char Text_warning[100] = { 0 };
			sprintf(Text_warning, "׼�����õ����ɫ�뱳��ɫ��ͬ��\n���ܻᵼ������������\nȷ��Ҫ������\nȷ��������1����������ȡ��");
			inputbox_getline("���棡����", Text_warning, choice, 2);
			return atoi(choice);
		}
	}
	return 1;
}
//ˢ����Ļ�õĺ���
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
}    //���������������������
void Clear_menu() {
	int colortemp = getfillcolor();
	setfillcolor(getbkcolor());
	bar(2, 101, 259, 699);
	setfillcolor(colortemp);
	xyprintf(0, 20, "������NMSL���� V1.2.0 ����̨������");
	xyprintf(0, 40, "��ע��NMSL = New Mine Scinece Lab ��");
	xyprintf(0, 60, "������Copyright By @Nick-bit������");
	xyprintf(0, 80, "��ѡ����Ҫ���еĲ�����");
}    //����˵����ݣ����ڲ˵�ˢ�µ�ʱ��
void Clear_info() {
	int colortemp = getfillcolor();
	setfillcolor(getbkcolor());
	bar(15,705,getwidth(),720);
	setfillcolor(colortemp);
}   //�����ͼ��Ϣ���ݣ����ڲ˵�ˢ�µ�ʱ��
