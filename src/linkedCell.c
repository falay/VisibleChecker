#include "linkedCell.h"
#include <stdio.h>

ListCell* listCellConstructor(Cell line)
{
	ListCell* dummy = (ListCell*)malloc( sizeof(ListCell) ) ;
	ListCell* node  = (ListCell*)malloc( sizeof(ListCell) ) ;
	
	node->yMin = line.yMinCord ;
	node->yMax = line.yMaxCord ;
	node->next = NULL ;
	
	dummy->yMin = dummy->yMax = -1 ;
	dummy->next = node ;
	
	return dummy ;
}



int caseAnalyser(int cellyMin, int cellyMax, int obsyMin, int obsyMax)
{
	if( cellyMin >= obsyMax || cellyMax <= obsyMin )
		return 0 ;
	
	else if( obsyMax >= cellyMax && cellyMax >= obsyMin && obsyMin >= cellyMin )
		return 1 ;

	else if( cellyMax >= obsyMax && obsyMax >= cellyMin && cellyMin >= obsyMin )	
		return 2 ;
	
	else if( cellyMax >= obsyMax && obsyMax >= obsyMin && obsyMin >= cellyMin )
		return 3 ;
	
	else if( obsyMax >= cellyMax && cellyMax >= cellyMin && cellyMin >= obsyMin )
		return 4 ;
	
	else
		return -1 ;	
}



ListCell* Projector(ListCell* head, Cell obstacle)
{
	ListCell* curCell  = head->next ;
	ListCell* prevCell = head ; 
	int visible = 0 ;
	
	while( curCell )
	{
		int Case = caseAnalyser( curCell->yMin, curCell->yMax, obstacle.yMinCord, obstacle.yMaxCord ) ;
		
		switch( Case )
		{
			case 0: /* Not overlap */
				break ;
				
			case 1: /* Upper overlapped */
				curCell->yMax = obstacle.yMinCord ;
				visible = 1 ;
				break ;	
			
			case 2: /* Lower overlapped */
				curCell->yMin = obstacle.yMaxCord ;
				visible = 1 ;
				break ;
			
			case 3: /* Inner overlapped */
			{	
				ListCell* oldNext = curCell->next ;	
				ListCell* upperCell = (ListCell*)malloc( sizeof(ListCell) ) ;
				
				upperCell->yMin = obstacle.yMaxCord ;
				upperCell->yMax = curCell->yMax ;
				curCell->yMax   = obstacle.yMinCord ;
				
				curCell->next = upperCell ;
				upperCell->next = oldNext ;
				curCell = oldNext ;
				
				visible = 1 ;
				break ;
			}	
			
			case 4: /* Totally overlapped*/
				prevCell->next = curCell->next ;
				curCell->next = NULL ;
				free( curCell ) ;
				curCell = prevCell ;
				
				visible = 1 ;
				break ;
				
			
			default:
				err_mesg("Weird overlapping") ;
		}
		
		if( curCell )
		{
			prevCell = curCell ;
			curCell = curCell->next ;
		}	
	}
	
	if( visible )
		head->yMin = 1 ;
	else 
		head->yMin = 0 ;
	
	
	return head ;
}




int isEmpty(ListCell* head)
{
	return ( head->next == NULL ) ;
}