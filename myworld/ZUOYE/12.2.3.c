#include "pe12-2a.h"
static int mode;
static double liters,kilometers;
void get_info(void);
void show_info(void);
void set_mode(int n);
#include "pe12-3a.h"
void get_info(int mode,double*liters,double*kilometers);
void show_info(int mode,double liters,double kilometers);
void set_info(int*mode,int n);