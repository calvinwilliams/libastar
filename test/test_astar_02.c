#include "libastar.h"

struct AStarPathFinding *LoadTestData()
{
	int		map_data[] = 
		{
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , 1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , -1 , 1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , 1 , -1 , 1 , 1 ,
			1 , 1 , 1 , 1 , 1 , -1 , 1 , 1 , -1 , 1 ,
			1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , -1
		} ;
	
	return ASTARInitPathFinding( map_data , 10 , 10 , 1 , 9 , 9 , 8 );
}

