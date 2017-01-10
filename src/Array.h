#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct 
{
	
	unsigned int ID ;
	unsigned int xCord ;
	unsigned int yMinCord ;
	unsigned int yMaxCord ;
	
} Cell ;


typedef struct
{
	
	Cell* cellArray ;
	size_t Size ;
	size_t Capacity ;
	
} Array ;


void initArray(Array*, size_t) ;
void insertArray(Array*, Cell) ;
void freeArray(Array*) ;
void ArraySorter(Array*) ;
int comparator(const void*, const void*) ; 
void err_mesg(const char*) ;

#endif