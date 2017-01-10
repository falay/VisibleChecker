#include "resList.h"
#include <stdio.h>

void listInitializer(ArrayList* myList, int Size) 
{
	myList->List = (ListNode**)malloc( Size*sizeof(ListNode*) ) ;
	myList->Size = Size ;
	
	for(int i=0; i<Size; i++)
		myList->List[i] = NULL ;	
}



void listNodeAdder(ListNode** head, int ID)
{
	if( *head == NULL )
	{	
		*head = malloc( sizeof(ListNode) ) ;
		(*head)->ID = ID ;
		(*head)->next = NULL ;
	}
	else
	{
		ListNode* tmpNode = (*head) ;
		*head = malloc( sizeof(ListNode) ) ;
		(*head)->ID = ID ;
		(*head)->next = tmpNode ;
	}		
}

