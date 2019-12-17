#include <math.h>
#include <stdio.h>
#include <io.h>  
#include <Windows.h>  
#include "graphics.h"
#include "DrawerFun.h"
#include "DrawerSet.h"
#include "Process.h"

//ȫ�ֱ�����
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
char current_filename[260];//���浱ǰ�༭���ļ���
char filename[51][260] = { 0 };//�����ļ��������飬���50��
//��ͼ�����õ�ʵ�ֺ���
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
			PrintColorMenu();   //�򻯴��룬����ɫ�˵���ӡ�����滻�ظ�����
			switch_frontcolor = getch();
			if(CheckColorRepeat(switch_frontcolor,1) == 1 )  //CheckColorRepeat�������ǰ��ɫ�ͱ���ɫ�Ƿ��غ�
				check_setfrontcolor = Set_front_color(switch_frontcolor);  //����ǰ��ɫ��ѡ��˵�ģʽ��
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
				check_setbackcolor = Set_back_color(switch_backcolor);//���ñ���ɫ��ѡ��˵�ģʽ��
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
				check_setfillcolor = Set_fill_color(switch_fillcolor);//�������ɫ��ѡ��˵�ģʽ��
		}
		delay_ms(500);
		break;
	case 52:
		Clear_menu();
		check_setlinetype = 1;
		while (check_setlinetype == 1) {
			PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
			int switch_linetype;
			xyprintf(15, 120, "1-4��������Ϊ��");
			xyprintf(30, 135, "1:ʵ�� ��������");
			xyprintf(30, 150, "2:���� ----");
			xyprintf(30, 165, "3:���� ��������");
			xyprintf(30, 180, "4:������ -��-��");
			xyprintf(15, 195, "��ע������������ϸ����ʵ�ߡ�");
			xyprintf(15, 230, "������ϸֵʾ����");
			xyprintf(15, 250, "1��");
			xyprintf(15, 270, "2��");
			xyprintf(15, 290, "5��");
			xyprintf(15, 320, "10��");
			xyprintf(15, 400, "0:������һ��");
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
}    //���ò˵���ʵ��
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
			xyprintf(15, 705, "û�п��Գ����Ĳ�����");
			delay_ms(500);
			Clear_info();
		}
		break;
	case 48:
		return 0;
	}
	return 1;
}    //��ͼ�˵���ʵ��

//��ͼ�˵������ò˵���������˵���
void menu_Draw() {
	Clear_menu();
	Clear_info();
	check_draw = 1;
	while (check_draw == 1) {
		FileWriting(current_filename);
		int switch_2;
		xyprintf(15, 120, "1:����");
		xyprintf(15, 135, "2:��ֱ��");
		xyprintf(15, 150, "3:��Բ��");
		xyprintf(15, 165, "4:������");
		xyprintf(15, 180, "5:��Բ");
		xyprintf(15, 195, "6:����Բ");
		xyprintf(15, 210, "7:�������");
		xyprintf(15, 225, "c:�����Բ");
		xyprintf(15, 240, "r:��������");
		xyprintf(15, 255, "t:�������Բ");
		xyprintf(15, 270, "p:���������");
		xyprintf(15, 300, "z:��������������Ŷ��");
		xyprintf(15, 320, "0:������һ��");
		switch_2 = getch();
		check_draw = Draw(switch_2); //����1���ֲ˵��������0�˳�ѭ���ص��ϼ�
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
		xyprintf(15, 120, "1:����ǰ��ɫ");
		xyprintf(15, 135, "2:���ñ���ɫ");
		xyprintf(15, 150, "3:�������ɫ");
		xyprintf(15, 165, "4:�������κ�������ϸ");
		xyprintf(15, 300, "0:������һ��");
		switch_3 = getch();
		check_set = Settings(switch_3);//ͬ�ϵ���
	}
}

//��������ͼ�����ò˵�����ڣ��ڶ���˵����������˷��ص�һ��˵��Ĺ��ܣ�
int menu_Second(int switch_1) {
	Clear_info();
	PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
	switch (switch_1)
	{
	case 49:
		Clear_menu();
		PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
		xyprintf(15, 705, "ȷ��Ҫ�����𣿣�1���� | �������������أ�");
		double_check = getch();//��������ȷ��
		if (double_check == 49) {
			Clear();
			Clear_menu();
			Clear_info();
			PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);
			xyprintf(15, 705, "����գ���������");
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
			xyprintf(15, 705, "������������ɣ�");
			delay_ms(1000);
			Clear_info();
		}
		else {
			xyprintf(15, 705, "��ǰû��������");
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
				xyprintf(15, 120, "��ѯ�ڴ����Ƿ��У�");
				xyprintf(15, 135, "1:��");
				xyprintf(15, 150, "2:ֱ��");
				xyprintf(15, 165, "3:Բ��");
				xyprintf(15, 180, "4:���ľ���");
				xyprintf(15, 195, "5:����Բ");
				xyprintf(15, 210, "6:������Բ");
				xyprintf(15, 225, "7:���Ķ����");
				xyprintf(15, 240, "8:���Բ");
				xyprintf(15, 255, "9:������");
				xyprintf(15, 270, "a:�����Բ");
				xyprintf(15, 285, "b:�������");

				xyprintf(15, 300, "0:������һ��");
				switch_find = getch();
				check_findredraw = FindReprint(switch_find);
				delay_ms(500);
				Clear_info();
			}
		}
		else {
			xyprintf(15, 705, "��ǰû��������");
			delay_ms(1000);
			Clear_info();
		}
		return 1;
	case 54:
		Clear_menu();
		xyprintf(15, 105, "���ɻ���ģʽ");
		xyprintf(15, 120, "��ʹ��������ɻ���ͼ��");
		xyprintf(15, 140, "��ע�⣺");
		xyprintf(15, 155, "  ���ɻ滭�޷����棡��");
		rectangle(15, 200, 140, 260);
		rectangle(15, 300, 140, 360);
		xyprintf(40, 220, "����˳�");
		xyprintf(40, 320, "��������Ļ");
		Freedraw();
		return 1;
	case 48:
		xyprintf(15, 705, "�ѱ��棡�����˳�");
		delay_ms(1500);
		return 0;//����0�˳�main�����е�ѭ��
	default:
		xyprintf(10, 680, "�Ƿ�����������������");
		delay_ms(500);
		return 1;//����������ʾ������1�����ִ�����״̬
	}
	return 0;
}//�ڶ����˵�

//��һ���˵�
void menu_Start() {
	setcolor(BLACK);
	setbkcolor(WHITE);
	xyprintf(0, 20, "������NMSL���� V1.0.0 ����̨������");
	xyprintf(0, 40, "��ע��NMSL = New Mine Scinece Lab ��");
	xyprintf(0, 60, "����������������������������������");
	xyprintf(0, 80, "��ѡ����Ҫ���еĲ�����");
	int switch_main;
	while (check_main == 1) {
		FileWriting(current_filename);
		PrintMenuRectangle(1, 100, 260, 700,line_t.type,line_t.thickness);   //�˵���߿�
		Clear_menu();
		xyprintf(15, 165, "1:��յ�ǰ����");
		xyprintf(15, 180, "2:�����ͼ��");
		xyprintf(15, 195, "3:����");
		xyprintf(15, 210, "4:�����ѱ��������");
		xyprintf(15, 225, "5:��ѯ�ѱ��������");
		xyprintf(15, 240, "6:���ɻ滭");
		xyprintf(15, 300, "0:���沢�˳�");
		switch_main = getch();
		check_main = menu_Second(switch_main);
	}
}
//�����ļ�
int Findfile() {
	long handle;  //��long���δ洢���ļ���ַ
	struct _finddata_t fileinfo; //�����ļ���Ϣ�Ľṹ��
	handle = _findfirst("*.dat", &fileinfo);//�ҵ���һ����׺��Ϊ.dat���ļ����洢�ļ���ַ��handle,�Ҳ����ļ�����-1
	if (handle == -1)
		return -1;
	int i = 1;  //i�����洢�ҵ��ļ�������
	sprintf(filename[i], fileinfo.name);
	while (!_findnext(handle, &fileinfo))//����Ѱ������.dat�ļ���ֱ������򳬹��ڴ�Ϊֹ
	{
		i += 1;
		if (i > 50) {
			xyprintf(460, 140, "���棺�Ѵ����ļ����������ڴ����ֵ�������ļ������޷���ȡ");
			delay_ms(1000);
			break;
		}
		sprintf(filename[i], fileinfo.name);
	}
	_findclose(handle);//�����ļ�����
	return i;
}
//ͨ���б�ѡ���ȡ�ļ�
int Choosefile() { 
	int i,chosenfile = 0;
	i = Findfile();
	if (i == -1)
		return -1;
	//��������ҳ��ӡ�ļ��������û���ҳ��ѡ��
	Clear();
	xyprintf(460, 160, "��ѡ��Ҫ�򿪵��ļ���");
	int t = 200,k = 0; //t:��Ǵ�ӡ�Ĵ�ֱλ�ã�k:��ǵ�ǰҳ��
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
			xyprintf(460, 160, "��ѡ��Ҫ�򿪵��ļ���");
			t = 200;
			if (k == 0) {
				for (int j = 1; j <= 9; j++) {
					xyprintf(500, t, "%d.%s\n", j, filename[j]);
					t += 20;
				}
				xyprintf(500, t, ">.��һҳ");
			}
			else if (k == (i-1) / 9 ) {
				int index = 1;
				for (int j = 9 * k + 1; j <= i; j++) {
					xyprintf(500, t, "%d.%s\n", index, filename[j]);
					t += 20;
					index++;
				}
				xyprintf(500, t, "<.��һҳ");
			}
			else {
				int index = 1;
				for (int j = 9 * k + 1; j <= 9 * (k+1) ; j++) {
					xyprintf(500, t, "%d.%s\n", index, filename[j]);
					t += 20;
					index++;
				}
				xyprintf(500, t, "<.��һҳ");
				t += 20;
				xyprintf(500, t, ">.��һҳ");
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
//��ʼ����ȡ�ļ������������û��Ƿ��ȡ�ļ��Լ���ȡ�Ƿ�ɹ��Ŀ��
void menu_Welcome() {
	setinitmode(INIT_WITHLOGO);
	initgraph(1280, 725);
	setcaption("NMSL����V1.2.0");
	int switch_start = 0;
	setfont(16, 0, "����",0,0, 550,false,false,false);
	while (check_start == 1) {
		xyprintf(410, 200, "��ӭ����NMSL���壨ע��NMSL=New Mine Scinece Lab����V1.2.0");
		xyprintf(540, 220, "�Ƿ��ȡ�ѱ�����ļ���");
		xyprintf(410, 240, "����������������1����    2����    0���˳�����������������");
		switch_start = getch();
		if (switch_start == 49) {
			int judge_filereading = 1;
			if(judge_filereading = Choosefile()){
				xyprintf(400, 340, "��ȡ�ļ�ʧ�ܣ���������.dat�ļ����½��ļ�");
				delay_ms(1000);
				Clear();
				check_start = 1;
				continue;
			}
			xyprintf(600, 640, "��ȡ�ļ��ɹ�");
			check_redraw = 1;
			check_start = 0;
			break;
		}
		else if (switch_start == 50) {
			int judge_samename = 1;
			int i = Findfile();
			int ifcover;
			while(judge_samename){
				inputbox_getline("�½��ļ�", "�������ļ���������Ҫ��׺����", current_filename, 260);
				for (int j = 1; j <= i; j++) {
					if (CheckFilenameRepeat(current_filename, filename[j])) {
						char text[3] = { 0 };
						inputbox_getline("����", "��ǰ�ļ��Ѵ��ڣ�ȷ��Ҫ������\n����1���ǣ�����������������", text, 2);
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
			xyprintf(500, 340, "���½��ļ�");
			delay_ms(1000);
			check_redraw = 0;
			check_start = 0;
		}
		else if (switch_start == 48) {
			closegraph();
			check_start = 0;
		}
		else {
			xyprintf(500, 340, "������������������");
			delay_ms(500);
			Clear(); //�����ʾ��Ϣ
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

