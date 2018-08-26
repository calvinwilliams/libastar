#include "libastar.h"

struct AStarPathFinding *LoadTestData()
{
	int		map_data[] = 
		{
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 9 , 1 , 9 , 9 , 9 , 9 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
		} ;
	
	return ASTARInitPathFinding( map_data , 10 , 10 , 0 , 9 , 7 , 3 );
}

