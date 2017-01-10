#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Array.h"
#include "linkedCell.h"
#include "resList.h"

#define BUFSIZE 256




Cell lineDecomposer(char* line)
{
	Cell content ;
	char* pch ;
	int Counter ;
	
	pch = strtok( line, " \n" ) ;
	Counter = 1 ;
	while( pch != NULL )
	{
		switch( Counter )
		{
			case 1:
				content.ID 	  	 = atoi( pch ) ;
				break ;
			
			case 2:
				content.xCord 	 = atoi( pch ) ;
				break ;
				
			case 3:
				content.yMinCord = atoi( pch ) ;
				break ;
			
			case 4:
				content.yMaxCord = atoi( pch ) ;				
				break ;
		} ;
		
		pch = strtok(NULL, " \n") ;
		Counter ++ ;	
	}	
	
	return content ;
}


Array Parser(char* inputFile, unsigned int Capacity)
{
	FILE* file; 
	char line[BUFSIZE] ;
	Array parsedData ;

	initArray( &parsedData, Capacity ) ;
	
	if( (file = fopen(inputFile, "r")) == NULL )	
		err_mesg("fopen error") ;

	while( fgets(line, sizeof(line), file) )
	{
		Cell curContent = lineDecomposer( line ) ;
		insertArray( &parsedData, curContent ) ;
	}
	
	fclose( file ) ;	
	
	return parsedData ;
}	



ArrayList mainChecker(Array* data)
{
	ArrayList resultList ;
	listInitializer( &resultList, data->Size ) ;
	
	int counter = 1 ;
	for(int i=0; i<data->Size-1; i++)
	{
		ListCell* head = listCellConstructor( data->cellArray[i] ) ;
		int curID = data->cellArray[i].ID ;
		
		for(int j=i+1; j<data->Size; j++)
		{
			if( data->cellArray[j].ID == curID )
				continue ;
			
			head = Projector( head, data->cellArray[j] ) ;
				
			if( head->yMin ) // Overlap 
				listNodeAdder( &(resultList.List[curID-1]), data->cellArray[j].ID ) ;	
			
			if( isEmpty( head ) )
				break ;
		}	
	}		
	
	return resultList ;
	
}


void fileWriter(char* inputName, ArrayList resData)
{
	char* outputFile = strstr( inputName, ".txt" ) ;
	
	if( outputFile )
		strncpy( outputFile, ".out", 4 ) ;
	else
		strcat( inputName, ".out" ) ;	
	
	outputFile = inputName ;
				
	FILE* file ;
	if( (file = fopen( outputFile, "w" )) == NULL )
		err_mesg("fopen error") ;
	
	
	for(int i=0; i<resData.Size; i++)
	{	
		fprintf(file, "%d ", i+1) ;
		
		ListNode* node = resData.List[i] ;
		while( node )
		{
			fprintf(file, "%d ", node->ID) ;
			node = node->next ;
		}
		fprintf(file, "\n") ;	
	}		
	
	fclose( file ) ;
}



void visbilityChecker(char* inputFile, unsigned int Capacity)
{
	Array rawData = Parser( inputFile, Capacity ) ;
	
	ArraySorter( &rawData ) ;
	
	ArrayList resData = mainChecker( &rawData ) ; 
	
	fileWriter( inputFile, resData ) ;
}


int main(int argc, char* argv[])
{
	if( argc == 3 )
		visbilityChecker( argv[1], atoi(argv[2]) ) ;
	else
		fprintf( stderr, "Usage: %s [input file] [number of lines]\n", argv[0] ) ;	

	return 0 ;
}