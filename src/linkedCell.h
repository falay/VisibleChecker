#ifndef LINKEDCELL_H
#define LINKEDCELL_H

#include "Array.h"

typedef struct ListCell
{
	struct ListCell* next ;
	unsigned int yMax ;
	unsigned int yMin ;

} ListCell ;


ListCell* listCellConstructor(Cell) ;
ListCell* Projector(ListCell*, Cell) ;
int isEmpty(ListCell*) ;

#endif