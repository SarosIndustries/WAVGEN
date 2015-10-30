#ifndef TXTFILE_UTIL_H
#define TXTFILE_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 256

typedef struct TXTFILE_DATA_STACK
{
	int SIZE;
	double FREQUENCY[STACK_MAX];
	double VOLUME[STACK_MAX];
	double LENGTH[STACK_MAX];
	
} TXTFILE_DATA_STACK;

void stack_initialize( TXTFILE_DATA_STACK *master );
void stack_push( TXTFILE_DATA_STACK *master, double frequency, double volume, double length );

#endif
