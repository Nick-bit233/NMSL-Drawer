#pragma once
#include "graphics.h"
#include "Process.h"
#include <math.h>
typedef struct {
	int type = 0;
	int thickness = 1;
}LINET;


int Set_front_color(int switch_frontcolor);
int Set_back_color(int switch_backcolor);
int Set_fill_color(int switch_fillcolor);
int Set_linetype(int switch_fillcolor);
