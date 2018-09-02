#ifndef _H_LIBASTAR_
#define _H_LIBASTAR_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

struct AStarNode ;
struct AStarPathFinding ;

struct AStarPathFinding *ASTARInitPathFinding( int *map_data , unsigned int map_width , unsigned int map_height , unsigned int begin_x , unsigned int begin_y , unsigned int end_x , unsigned int end_y );
void ASTARCleanPathFinding( struct AStarPathFinding *p_astar );

void ASTARPrintMap( struct AStarPathFinding *p_astar );
void ASTARPrintCloseListTree( struct AStarPathFinding *p_astar );
void ASTARPrintOpenListTree( struct AStarPathFinding *p_astar );
void ASTARPrintFScoreListTree( struct AStarPathFinding *p_astar );

int ASTARFindRouter( struct AStarPathFinding *p_astar );

unsigned int GetBeginNodeX( struct AStarPathFinding *p_astar );
unsigned int GetBeginNodeY( struct AStarPathFinding *p_astar );
unsigned int GetEndNodeX( struct AStarPathFinding *p_astar );
unsigned int GetEndNodeY( struct AStarPathFinding *p_astar );

struct AStarNode *TravelReachableNodes( struct AStarPathFinding *p_astar , struct AStarNode *p_travel_node );
unsigned int GetReachableNodeX( struct AStarNode *p_travel_node );
unsigned int GetReachableNodeY( struct AStarNode *p_travel_node );

#ifdef __cplusplus
}
#endif

#endif

