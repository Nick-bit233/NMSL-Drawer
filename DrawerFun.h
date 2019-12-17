#pragma once
#include "graphics.h"
#include "Process.h"
#include "DrawerSet.h"
#include <math.h>
typedef enum {
	None,Point,Line,Arcf,Empty_rect,Empty_circle, Empty_ellipse, Empty_poly,Fill_circle,Fill_rect, Fill_ellipse, Fill_poly
}SHAPETYPE;

typedef struct {
	SHAPETYPE type;
	int parameter[39];
	int color;
	int fillcolor;
	LINET Linetype;
}NMSLSHAPE;

int Draw_point();
int Draw_circle();
int Draw_line();
int Draw_arcf();
int Draw_empty_ellipse();
int Draw_empty_rectangle();
int Draw_empty_poly();
int Draw_fill_rectangle();
int Draw_fill_circle();
int Draw_fill_ellipse();
int Draw_fill_poly();


int Reprint();
int FindReprint(int find);
int UNDO();

int Freedraw();