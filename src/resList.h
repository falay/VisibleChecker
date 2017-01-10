#ifndef RESLIST_H
#define RESLIST_H

#include <stdlib.h>

typedef struct ListNode
{
	struct ListNode* next ;
	int ID ;
	
} ListNode ;


typedef struct
{
	ListNode** List ;
	size_t Size ;
	
} ArrayList ;


void listInitializer(ArrayList*, int) ;
void listNodeAdder(ListNode**, int) ;



#endif