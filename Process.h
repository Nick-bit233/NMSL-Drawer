#pragma once
#include "graphics.h"

int GetInt(char text[4]);
int FileReading(char *name);
int FileWriting(char name[260]);
void PrintColorMenu();
void PrintMenuRectangle(int,int,int,int,int,int);
int CheckColorRepeat(int, int);
int CheckFilenameRepeat(char name1[260], char name2[260]);
void Clear();
void Clear_menu();
void Clear_info();