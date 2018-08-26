#include "libastar.h"

#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>

struct AStarPathFinding *LoadTestData();

int main()
{
	struct AStarPathFinding		*p_astar = NULL ;
	struct AStarNode		*p_travel_node = NULL ;
	struct timeval			tv1 , tv2 , diff_tv ;
	
	int				nret = 0 ;
	
	p_astar = LoadTestData();
	if( p_astar == NULL )
		return 1;
	
	printf( "ASTARFindRouter [%u,%u] -> [%u,%u] ...\n" , GetBeginNodeX(p_astar) , GetBeginNodeY(p_astar) , GetEndNodeX(p_astar) , GetEndNodeY(p_astar) );
	gettimeofday( & tv1 , NULL );
	nret = ASTARFindRouter( p_astar ) ;
	gettimeofday( & tv2 , NULL );
	diff_tv.tv_sec = tv2.tv_sec - tv1.tv_sec ;
	diff_tv.tv_usec = tv2.tv_usec - tv1.tv_usec ;
	while( diff_tv.tv_usec < 0 )
	{
		diff_tv.tv_usec += 1000000 ;
		diff_tv.tv_sec--;
	}
	if( nret < 0 )
	{
		printf( "ASTARFindRouter failed[%d]\n" , nret );
	}
	else if( nret > 0 )
	{
		printf( "ASTARFindRouter return[%d] , no route found , ELAPSE[%ld.%06ld]\n" , nret , diff_tv.tv_sec , diff_tv.tv_usec );
	}
	else
	{
		printf( "ASTARFindRouter ok , ELAPSE[%ld.%06ld]\n" , diff_tv.tv_sec , diff_tv.tv_usec );
		
		p_travel_node = TravelReachableNodes( p_astar , NULL ) ;
		while( p_travel_node )
		{
			printf( "p_travel_node[%u,%u]\n" , GetReachableNodeX(p_travel_node) , GetReachableNodeY(p_travel_node) );
			
			p_travel_node = TravelReachableNodes( p_astar , p_travel_node ) ;
		}
	}
	
	ASTARPrintMap( p_astar );
	
	ASTARCleanPathFinding( p_astar );
	
	return 0;
}

