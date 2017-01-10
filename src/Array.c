#include "Array.h"
#include "stdio.h"

void initArray(Array* myArray, size_t capacity)
{
	myArray->cellArray = (Cell*)malloc( capacity*sizeof(Cell) ) ;
	myArray->Size = 0 ;
	myArray->Capacity = capacity ;
}


void insertArray(Array* myArray, Cell content)
{
	if( myArray->Size == myArray->Capacity )
	{	
		myArray->Capacity <<= 1 ;
		myArray->cellArray = (Cell*)realloc( myArray->cellArray, myArray->Capacity*sizeof(Cell) ) ;
	}
	
	myArray->cellArray[myArray->Size++] = content ;
}


void freeArray(Array* myArray)
{
	free( myArray->cellArray ) ;
	myArray->cellArray = NULL ;
	myArray->Size = myArray->Capacity = 0 ;
}


int comparator(const void* cellA, const void* cellB)
{
	return (*(Cell*)cellA).xCord > (*(Cell*)cellB).xCord ;
}


void ArraySorter(Array* data)
{
	qsort( data->cellArray, data->Size, sizeof(Cell), comparator ) ;
}


void err_mesg(const char* mesg)
{
	fprintf(stderr, "%s\n", mesg) ;
	exit(0) ;
}
