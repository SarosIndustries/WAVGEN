#ifndef TXTFILE_UTIL_H
#define TXTFILE_UTIL_H

typedef struct TXTFILE_DATA_NODE
{
	struct TXTFILE_DATA_NODE *NEXT;

	float FREQUENCY;
	float VOLUME;
	float LENGTH;
} TXTFILE_DATA_MASTER;

#endif
