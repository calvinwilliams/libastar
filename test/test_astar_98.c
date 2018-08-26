#include "libastar.h"

#include <time.h>

static int Rand( int min, int max )
{
	return ( rand() % ( max - min + 1 ) ) + min ;
}

#define TEST_ASTAR_WIDTH	234
#define TEST_ASTAR_HEIGHT	55

struct AStarPathFinding *LoadTestData()
{
	int		map_data[TEST_ASTAR_WIDTH*TEST_ASTAR_HEIGHT] ; 
	unsigned int	i ;
	unsigned int	begin_x ;
	unsigned int	begin_y ;
	unsigned int	end_x ;
	unsigned int	end_y ;
	
	srand( time(NULL) );
	
	for( i = 0 ; i < sizeof(map_data)/sizeof(map_data[0]) ; i++ )
	{
		map_data[i] = (unsigned int)(Rand(0,2)==0?-1:1) ;
	}
	
	while(1)
	{
		begin_x = Rand(0,TEST_ASTAR_WIDTH) ;
		begin_y = Rand(0,TEST_ASTAR_HEIGHT) ;
		if( *(map_data+begin_y*TEST_ASTAR_WIDTH+begin_x) >= 0 )
			break;
	}
	
	while(1)
	{
		end_x = Rand(0,TEST_ASTAR_WIDTH) ;
		end_y = Rand(0,TEST_ASTAR_HEIGHT) ;
		if( *(map_data+end_y*TEST_ASTAR_WIDTH+end_x) >= 0 )
			break;
	}
	
	return ASTARInitPathFinding( map_data , TEST_ASTAR_WIDTH , TEST_ASTAR_HEIGHT , begin_x , begin_y , end_x , end_y );
}

