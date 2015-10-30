#include <stdio.h>
#include <stdlib.h>
#include "TXTFILE_UTIL.h"

void stack_initialize( TXTFILE_DATA_STACK *master )
{
	master->FREQUENCY[0] = 0.0;
	master->VOLUME[0] = 0.0;
	master->LENGTH[0] = 0.0;
	master->SIZE = 0;
}

void stack_push( TXTFILE_DATA_STACK *master, double frequency, double volume, double length )
{
	if ( master->SIZE < STACK_MAX )
	{
		master->FREQUENCY[master->SIZE] = frequency;
		master->VOLUME[master->SIZE] = volume;
		master->LENGTH[master->SIZE] = length;
		master->SIZE++;
	}
	
	else
	{
		exit( EXIT_FAILURE );
	}
}
