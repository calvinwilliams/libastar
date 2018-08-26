#include "libastar.h"

#include "rbtree_tpl.h"

char __LIBASTAR_VERSION_0_1_0_0[] = "0.1.0.0" ;
char *__LIBASTAR_VERSION = __LIBASTAR_VERSION_0_1_0_0 ;

#define ASTAR_DEBUG		0

#define ASTAR_GETMAPDATA_2(_p_astar_,_p_open_node_)	*( (_p_astar_)->map_data + (_p_open_node_)->y*(_p_astar_)->map_width + (_p_open_node_)->x )
#define ASTAR_GETMAPDATA_3(_p_astar_,_x_,_y_)		*( (_p_astar_)->map_data + (_y_)*(_p_astar_)->map_width + (_x_) )

struct AStarNode
{
	unsigned int		x ;
	unsigned int		y ;
	struct AStarNode	*p_prev_node ;
	struct AStarNode	*p_next_node ;
	
	unsigned int		f_score ;
	unsigned int		g_score ;
	unsigned int		h_score ;
	
	struct rb_node		close_node_rbnode ;
	struct rb_node		open_node_rbnode ;
	struct rb_node		f_score_rbnode ;
} ;

struct AStarPathFinding
{
	int			*map_data ;
	unsigned int		map_width ;
	unsigned int		map_height ;
	
	unsigned int		begin_x ;
	unsigned int		begin_y ;
	unsigned int		end_x ;
	unsigned int		end_y ;
	struct AStarNode	*p_begin_node ;
	struct AStarNode	*p_end_node ;
	
	struct rb_root		close_node_rbtree ;
	struct rb_root		open_node_rbtree ;
	struct rb_root		f_score_rbtree ;
} ;

funcCompareRbTreeNodeEntry ComparePositionEntry ;
int ComparePositionEntry( void *pv1 , void *pv2 )
{
	struct AStarNode	*p_pt1 = (struct AStarNode *)pv1 ;
	struct AStarNode	*p_pt2 = (struct AStarNode *)pv2 ;
	
	if( p_pt1->x > p_pt2->x )
		return 1;
	else if( p_pt1->x < p_pt2->x )
		return -1;
	else if( p_pt1->y > p_pt2->y )
		return 1;
	else if( p_pt1->y < p_pt2->y )
		return -1;
	else
		return 0;
}

LINK_RBTREENODE( LinkCloseListTreeNode , struct AStarPathFinding , close_node_rbtree , struct AStarNode , close_node_rbnode , ComparePositionEntry )
UNLINK_RBTREENODE( UnlinkCloseListTreeNode , struct AStarPathFinding , close_node_rbtree , struct AStarNode , close_node_rbnode )
QUERY_RBTREENODE( QueryCloseListTreeNode , struct AStarPathFinding , close_node_rbtree , struct AStarNode , close_node_rbnode , ComparePositionEntry )
TRAVEL_RBTREENODE( TravelCloseListTreeNodes , struct AStarPathFinding , close_node_rbtree , struct AStarNode , close_node_rbnode )
DESTROY_RBTREE( DestroyCloseListTree , struct AStarPathFinding , close_node_rbtree , struct AStarNode , close_node_rbnode , FREE_RBTREENODEENTRY_DIRECTLY )

LINK_RBTREENODE( LinkOpenListTreeNode , struct AStarPathFinding , open_node_rbtree , struct AStarNode , open_node_rbnode , ComparePositionEntry )
UNLINK_RBTREENODE( UnlinkOpenListTreeNode , struct AStarPathFinding , open_node_rbtree , struct AStarNode , open_node_rbnode )
QUERY_RBTREENODE( QueryOpenListTreeNode , struct AStarPathFinding , open_node_rbtree , struct AStarNode , open_node_rbnode , ComparePositionEntry )
TRAVEL_RBTREENODE( TravelOpenListTreeNodes , struct AStarPathFinding , open_node_rbtree , struct AStarNode , open_node_rbnode )
DESTROY_RBTREE( DestroyOpenListTree , struct AStarPathFinding , open_node_rbtree , struct AStarNode , open_node_rbnode , FREE_RBTREENODEENTRY_DIRECTLY )

LINK_RBTREENODE_INT_ALLOWDUPLICATE( LinkFScoreListTreeNode , struct AStarPathFinding , f_score_rbtree , struct AStarNode , f_score_rbnode , f_score )
UNLINK_RBTREENODE( UnlinkFScoreListTreeNode , struct AStarPathFinding , f_score_rbtree , struct AStarNode , f_score_rbnode )
QUERY_RBTREENODE_INT( QueryFScoreListTreeNode , struct AStarPathFinding , f_score_rbtree , struct AStarNode , f_score_rbnode , f_score )
TRAVEL_RBTREENODE( TravelFScoreListTreeNodes , struct AStarPathFinding , f_score_rbtree , struct AStarNode , f_score_rbnode )
DESTROY_RBTREE( DestroyFScoreListTree , struct AStarPathFinding , f_score_rbtree , struct AStarNode , f_score_rbnode , NULL )

struct AStarPathFinding *ASTARInitPathFinding( int *map_data , unsigned int map_width , unsigned int map_height , unsigned int begin_x , unsigned int begin_y , unsigned int end_x , unsigned int end_y )
{
	struct AStarPathFinding		*p_astar = NULL ;
	
	p_astar = (struct AStarPathFinding *)malloc( sizeof(struct AStarPathFinding) ) ;
	if( p_astar == NULL )
		return NULL;
	memset( p_astar , 0x00 , sizeof(struct AStarPathFinding) );
	
	p_astar->map_data = (int*)malloc( sizeof(int)*map_width*map_height  )  ;
	if( p_astar->map_data == NULL )
		return NULL;
	memcpy( p_astar->map_data , map_data , sizeof(int)*map_width*map_height );
	p_astar->map_width = map_width ;
	p_astar->map_height = map_height ;
	
	p_astar->begin_x = begin_x ;
	p_astar->begin_y = begin_y ;
	p_astar->end_x = end_x ;
	p_astar->end_y = end_y ;
	
	return p_astar;
}

void ASTARCleanPathFinding( struct AStarPathFinding *p_astar )
{
	DestroyCloseListTree( p_astar );
	DestroyFScoreListTree( p_astar );
	DestroyOpenListTree( p_astar );
	
	free( p_astar->map_data );
	
	free( p_astar );
	
	return;
}

void ASTARPrintMap( struct AStarPathFinding *p_astar )
{
	unsigned int		y , x ;
	int			*p_map = NULL ;
	struct AStarNode	close_node ;
	struct AStarNode	*p_close_node = NULL ;
	struct AStarNode	open_node ;
	struct AStarNode	*p_open_node = NULL ;
	unsigned int		ch ;
	char			*bg_color = NULL ;
	char			*fg_color = NULL ;
	
	printf( "--- PrintMap ---------\n" );
	
	printf( "  " );
	for( x = 0 ; x < p_astar->map_width ; x++ , p_map++ )
	{
		printf( "%d" , x%10 );
	}
	printf( "\n" );
	
	p_map = p_astar->map_data ;
	for( y = 0 ; y < p_astar->map_height ; y++ )
	{
		printf( "%d " , y%10 );
		
		for( x = 0 ; x < p_astar->map_width ; x++ , p_map++ )
		{
			if( (*p_map) < 0 )
				ch = ' ' ;
			else
				ch = ((*p_map)%10)+'0' ;
			
			close_node.x = x ;
			close_node.y = y ;
			p_close_node = QueryCloseListTreeNode( p_astar , & close_node ) ;
			if( p_close_node )
			{
				bg_color = "43" ;
			}
			else
			{
				open_node.x = x ;
				open_node.y = y ;
				p_open_node = QueryOpenListTreeNode( p_astar , & open_node ) ;
				if( p_open_node )
				{
					bg_color = "47" ;
				}
				else
				{
					bg_color = "40" ;
				}
			}
			
			if( x == p_astar->begin_x && y == p_astar->begin_y )
			{
				ch = 'B' ;
				fg_color = "47" ;
			}
			else if( x == p_astar->end_x && y == p_astar->end_y )
			{
				ch = 'E' ;
				fg_color = "47" ;
			}
			else if( p_close_node && p_close_node->p_next_node )
			{
				fg_color = "47" ;
			}
			else
			{
				fg_color = "32" ;
			}
			
			printf( "\033[%s;%sm%c\033[0m" , fg_color , bg_color , ch );
		}
		
		printf( "\n" );
	}
	
	return;
}

void ASTARPrintCloseListTree( struct AStarPathFinding *p_astar )
{
	struct AStarNode		*p_close_node = NULL ;
	
	printf( "--- PrintCloseListTree ---------\n" );
	
	p_close_node = TravelCloseListTreeNodes( p_astar , NULL ) ;
	while( p_close_node )
	{
		printf( "- close_node[%p] [%d,%d] f[%u]=g[%u]+h[%u]\n" , p_close_node , p_close_node->x , p_close_node->y , p_close_node->f_score , p_close_node->g_score , p_close_node->h_score );
		
		p_close_node = TravelCloseListTreeNodes( p_astar , p_close_node ) ;
	}
	
	return;
}

void ASTARPrintOpenListTree( struct AStarPathFinding *p_astar )
{
	struct AStarNode		*p_open_node = NULL ;
	
	printf( "--- PrintOpenListTree ---------\n" );
	
	p_open_node = TravelOpenListTreeNodes( p_astar , NULL ) ;
	while( p_open_node )
	{
		printf( "- open_node[%p] [%d,%d] f[%u]=g[%u]+h[%u]\n" , p_open_node , p_open_node->x , p_open_node->y , p_open_node->f_score , p_open_node->g_score , p_open_node->h_score );
		
		p_open_node = TravelOpenListTreeNodes( p_astar , p_open_node ) ;
	}
	
	return;
}

void ASTARPrintFScoreListTree( struct AStarPathFinding *p_astar )
{
	struct AStarNode		*p_f_score_pos = NULL ;
	
	printf( "--- PrintFScoreListTree ---------\n" );
	
	p_f_score_pos = TravelFScoreListTreeNodes( p_astar , NULL ) ;
	while( p_f_score_pos )
	{
		printf( "- f_score_pos[%p] [%d,%d] f[%u]=g[%u]+h[%u]\n" , p_f_score_pos , p_f_score_pos->x , p_f_score_pos->y , p_f_score_pos->f_score , p_f_score_pos->g_score , p_f_score_pos->h_score );
		
		p_f_score_pos = TravelFScoreListTreeNodes( p_astar , p_f_score_pos ) ;
	}
	
	return;
}

static void InitAStarNode( struct AStarNode *p_node , struct AStarNode *p_prev_node , int x , int y )
{
	memset( p_node , 0x00 , sizeof(struct AStarNode) );
	
	p_node->x = x ;
	p_node->y = y ;
	p_node->p_prev_node = p_prev_node ;
	
	return;
}

/*
static struct AStarNode *AllocAStarNode( struct AStarNode *p_prev_node , int x , int y )
{
	struct AStarNode 	*p_pos = NULL ;
	
	p_pos = (struct AStarNode *)malloc( sizeof(struct AStarNode) ) ;
	if( p_pos == NULL )
		return NULL;
	
	InitAStarNode( p_pos , p_prev_node , x , y );
	
	return p_pos;
}
*/

static struct AStarNode *DuplicateAStarNode( struct AStarNode *p_node )
{
	struct AStarNode 	*p_dup_node = NULL ;
	
	p_dup_node = (struct AStarNode *)malloc( sizeof(struct AStarNode) ) ;
	if( p_dup_node == NULL )
		return NULL;
	
	memcpy( p_dup_node , p_node , sizeof(struct AStarNode) );
	
	return p_dup_node;
}

static unsigned int CalcStraightLineDistance_3( struct AStarNode *p_curr_pos , unsigned int end_x , unsigned int end_y )
{
	unsigned int		a , b , c ;
	
	a = abs( end_x - p_curr_pos->x ) ;
	b = abs( end_y - p_curr_pos->y ) ;
	a *= a ;
	b *= b ;
	c = (unsigned int)sqrt( (double)(a+b) );
	
	return c;
}

/*
static unsigned int CalcManhattanDistance( struct AStarNode *p_curr_pos , struct AStarNode *p_end_node )
{
	unsigned int	a , b , c ;
	
	a = abs( p_end_node->x - p_curr_pos->x ) ;
	b = abs( p_end_node->y - p_curr_pos->y ) ;
	c = a + b ;
	
	return (unsigned int)c;
}
*/

static int AddOpenList( struct AStarPathFinding *p_astar , struct AStarNode *p_open_node )
{
	struct AStarNode	*p_node = NULL ;
	struct AStarNode	*p_dup_open_node = NULL ;
	
	int			nret = 0 ;
	
	p_open_node->g_score = (p_open_node->p_prev_node==NULL?0:p_open_node->p_prev_node->g_score) + ASTAR_GETMAPDATA_2(p_astar,p_open_node) ;
	p_open_node->h_score = CalcStraightLineDistance_3( p_open_node , p_astar->end_x , p_astar->end_y ) ;
	p_open_node->f_score = p_open_node->g_score + p_open_node->h_score ;
	
	p_node = QueryCloseListTreeNode( p_astar , p_open_node ) ;
	if( p_node )
	{
#if ASTAR_DEBUG
		printf( "position[%d,%d] f[%u]=g[%u]+h[%u] in close list\n" , p_open_node->x , p_open_node->y , p_open_node->f_score , p_open_node->g_score , p_open_node->h_score );
#endif
		return 1;
	}
	
	p_node = QueryOpenListTreeNode( p_astar , p_open_node ) ;
	if( p_node == NULL )
	{
		p_dup_open_node = DuplicateAStarNode( p_open_node ) ;
		if( p_dup_open_node == NULL )
		{
#if ASTAR_DEBUG
			printf( "DuplicateAStarNode failed[%d] , pos[%d,%d]\n" , nret , p_open_node->x , p_open_node->y );
#endif
			return -1;
		}
		
		nret = LinkOpenListTreeNode( p_astar , p_dup_open_node ) ;
		if( nret )
		{
#if ASTAR_DEBUG
			printf( "LinkOpenListTreeNode failed[%d] , pos[%d,%d]\n" , nret , p_dup_open_node->x , p_dup_open_node->y );
#endif
			return -1;
		}
		
		nret = LinkFScoreListTreeNode( p_astar , p_dup_open_node ) ;
		if( nret )
		{
#if ASTAR_DEBUG
			printf( "LinkFScoreListTreeNode failed[%d] , pos[%d,%d]\n" , nret , p_dup_open_node->x , p_dup_open_node->y );
#endif
			return -1;
		}
	}
	else
	{
		struct AStarNode		*p_prev_node = p_open_node->p_prev_node ;
		
		if( p_prev_node->g_score + ASTAR_GETMAPDATA_2(p_astar,p_node) < p_node->g_score )
		{
			UnlinkFScoreListTreeNode( p_astar , p_node ) ;
			
			p_node->g_score = p_prev_node->g_score + ASTAR_GETMAPDATA_2(p_astar,p_node) ;
			p_node->f_score = p_prev_node->g_score + p_prev_node->h_score ;
			p_node->p_prev_node = p_prev_node ;
			
			nret = LinkFScoreListTreeNode( p_astar , p_node ) ;
			if( nret )
			{
#if ASTAR_DEBUG
				printf( "LinkFScoreListTreeNode failed[%d] , pos[%d,%d]\n" , nret , p_prev_node->x , p_prev_node->y );
#endif
				return -1;
			}
			
#if ASTAR_DEBUG
			printf( "adjust f score position[%d,%d] f[%u]=g[%u]+h[%u]\n" , p_prev_node->x , p_prev_node->y , p_prev_node->f_score , p_prev_node->g_score , p_prev_node->h_score );
#endif
			return 1;
		}
		else
		{
#if ASTAR_DEBUG
			printf( "no adjust f score position[%d,%d] f[%u]=g[%u]+h[%u]\n" , p_open_node->x , p_open_node->y , p_open_node->f_score , p_open_node->g_score , p_open_node->h_score );
#endif
			return 1;
		}
	}
	
	return 0;
}

static int AddAroundToOpenListTree( struct AStarPathFinding *p_astar , struct AStarNode *p_prev_node )
{
	struct AStarNode 	open_node ;
	
	int			nret = 0 ;
	
	if( p_prev_node->x > 0 && ASTAR_GETMAPDATA_3(p_astar,p_prev_node->x-1,p_prev_node->y) >= 0 )
	{
		InitAStarNode( & open_node , p_prev_node , p_prev_node->x-1 , p_prev_node->y );
		
		nret = AddOpenList( p_astar , & open_node ) ;
		if( nret < 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList failed[%d]\n" , nret );
#endif
			return -1;
		}
		else if( nret > 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList return[%d]\n" , nret );
#endif
		}
		else if( nret == 0 )
		{
#if ASTAR_DEBUG
			printf( "add left position[%d,%d] f[%u]=g[%u]+h[%u] to open list\n" , open_node.x , open_node.y , open_node.f_score , open_node.g_score , open_node.h_score );
#endif
		}
	}
	
	if( p_prev_node->y > 0 && ASTAR_GETMAPDATA_3(p_astar,p_prev_node->x,p_prev_node->y-1) >= 0 )
	{
		InitAStarNode( & open_node , p_prev_node , p_prev_node->x , p_prev_node->y-1 );
		
		nret = AddOpenList( p_astar , & open_node ) ;
		if( nret < 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList failed[%d]\n" , nret );
#endif
			return -1;
		}
		else if( nret > 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList return[%d]\n" , nret );
#endif
		}
		else if( nret == 0 )
		{
#if ASTAR_DEBUG
			printf( "add top position[%d,%d] f[%u]=g[%u]+h[%u] to open list\n" , open_node.x , open_node.y , open_node.f_score , open_node.g_score , open_node.h_score );
#endif
		}
	}
	
	if( p_prev_node->x < p_astar->map_width-1 && ASTAR_GETMAPDATA_3(p_astar,p_prev_node->x+1,p_prev_node->y) >= 0 )
	{
		InitAStarNode( & open_node , p_prev_node , p_prev_node->x+1 , p_prev_node->y );
		
		nret = AddOpenList( p_astar , & open_node ) ;
		if( nret < 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList failed[%d]\n" , nret );
#endif
			return -1;
		}
		else if( nret > 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList return[%d]\n" , nret );
#endif
		}
		else if( nret == 0 )
		{
#if ASTAR_DEBUG
			printf( "add right position[%d,%d] f[%u]=g[%u]+h[%u] to open list\n" , open_node.x , open_node.y , open_node.f_score , open_node.g_score , open_node.h_score );
#endif
		}
	}
	
	if( p_prev_node->y < p_astar->map_height-1 && ASTAR_GETMAPDATA_3(p_astar,p_prev_node->x,p_prev_node->y+1) >= 0 )
	{
		InitAStarNode( & open_node , p_prev_node , p_prev_node->x , p_prev_node->y+1 );
		
		nret = AddOpenList( p_astar , & open_node ) ;
		if( nret < 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList failed[%d]\n" , nret );
#endif
			return -1;
		}
		else if( nret > 0 )
		{
#if ASTAR_DEBUG
			printf( "AddOpenList return[%d]\n" , nret );
#endif
		}
		else if( nret == 0 )
		{
#if ASTAR_DEBUG
			printf( "add bottom position[%d,%d] f[%u]=g[%u]+h[%u] to open list\n" , open_node.x , open_node.y , open_node.f_score , open_node.g_score , open_node.h_score );
#endif
		}
	}
	
	return 0;
}

static struct AStarNode *GetMinFScoreOpenList( struct AStarPathFinding *p_astar )
{
	struct rb_node 		*p_f_score_rbnode = NULL ;
	
	p_f_score_rbnode = rb_first( & (p_astar->f_score_rbtree) ) ;
	if( p_f_score_rbnode == NULL )
		return NULL;
	
	return rb_entry( p_f_score_rbnode , struct AStarNode , f_score_rbnode ) ;
}

int ASTARFindRouter( struct AStarPathFinding *p_astar )
{
	struct AStarNode	begin_node ;
	
	struct AStarNode 	*p_open_node = NULL ;
	struct AStarNode 	*p_close_node = NULL ;
	
	struct AStarNode 	*p_travel_node = NULL ;
	
	int			nret = 0 ;
	
	InitAStarNode( & begin_node , NULL , p_astar->begin_x , p_astar->begin_y ) ;
	
	nret = AddOpenList( p_astar , & begin_node ) ;
	if( nret < 0 )
	{
#if ASTAR_DEBUG
		printf( "AddOpenList failed[%d]\n" , nret );
#endif
		return -1;
	}
	else if( nret == 0 )
	{
#if ASTAR_DEBUG
		printf( "add begin position[%d,%d] g[%u]+h[%u]=f[%u] to open list\n" , begin_node.x , begin_node.y , begin_node.g_score , begin_node.h_score , begin_node.f_score );
#endif
	}
	
	while(1)
	{
#if ASTAR_DEBUG
		ASTARPrintMap( p_astar );
		ASTARPrintCloseListTree( p_astar );
		ASTARPrintOpenListTree( p_astar );
		ASTARPrintFScoreListTree( p_astar );
#endif
		
		p_open_node = GetMinFScoreOpenList( p_astar ) ;
		if( p_open_node == NULL )
		{
#if ASTAR_DEBUG
			printf( "can't reach end point\n" );
#endif
			return 1;
		}
		else
		{
#if ASTAR_DEBUG
			printf( "GetMinFScoreOpenList ok , p_open_node[%d,%d]\n" , p_open_node->x , p_open_node->y );
#endif
		}
		
		UnlinkOpenListTreeNode( p_astar , p_open_node );
		UnlinkFScoreListTreeNode( p_astar , p_open_node );
#if ASTAR_DEBUG
		printf( "remove position[%d,%d] from open list\n" , p_open_node->x , p_open_node->y );
#endif
		
		p_close_node = p_open_node ;
		nret = LinkCloseListTreeNode( p_astar , p_close_node ) ;
		if( nret )
		{
#if ASTAR_DEBUG
			printf( "LinkCloseListTreeNode failed[%d]\n" , nret );
#endif
			return -1;
		}
		
		if( p_close_node->x == p_astar->end_x && p_close_node->y == p_astar->end_y )
		{
#if ASTAR_DEBUG
			printf( "find end position[%d,%d]\n" , p_astar->end_x , p_astar->end_y );
#endif
			p_astar->p_end_node = p_close_node ;
			break;
		}
		
		nret = AddAroundToOpenListTree( p_astar , p_close_node ) ;
		if( nret > 0 )
		{
#if ASTAR_DEBUG
			printf( "AddAroundToOpenListTree return[%d]\n" , nret );
#endif
			continue;
		}
		else if( nret < 0 )
		{
#if ASTAR_DEBUG
			printf( "AddAroundToOpenListTree failed[%d]\n" , nret );
#endif
			return -1;
		}
		
#if ASTAR_DEBUG
		printf( "add position[%d,%d] f[%u]=g[%u]+h[%u] to close list\n" , p_close_node->x , p_close_node->y , p_close_node->f_score , p_close_node->g_score , p_close_node->h_score );
#endif
	}
	
	p_travel_node = p_astar->p_end_node ;
	while(1)
	{
		p_travel_node->p_prev_node->p_next_node = p_travel_node ;
		p_travel_node = p_travel_node->p_prev_node ;
		if( p_travel_node->p_prev_node == NULL )
		{
			p_astar->p_begin_node = p_travel_node ;
			break;
		}
	}
	
#if ASTAR_DEBUG
	ASTARPrintMap( p_astar );
	ASTARPrintCloseListTree( p_astar );
	ASTARPrintOpenListTree( p_astar );
	ASTARPrintFScoreListTree( p_astar );
#endif
	
	return 0;
}

unsigned int GetBeginNodeX( struct AStarPathFinding *p_astar )
{
	return p_astar->begin_x;
}

unsigned int GetBeginNodeY( struct AStarPathFinding *p_astar )
{
	return p_astar->begin_y;
}

unsigned int GetEndNodeX( struct AStarPathFinding *p_astar )
{
	return p_astar->end_x;
}

unsigned int GetEndNodeY( struct AStarPathFinding *p_astar )
{
	return p_astar->end_y;
}

struct AStarNode *TravelReachableNodes( struct AStarPathFinding *p_astar , struct AStarNode *p_travel_node )
{
	if( p_travel_node == NULL )
		return p_astar->p_begin_node;
	else
		return p_travel_node->p_next_node;
}

unsigned int GetReachableNodeX( struct AStarNode *p_travel_node )
{
	return p_travel_node->x;
}

unsigned int GetReachableNodeY( struct AStarNode *p_travel_node )
{
	return p_travel_node->y;
}

