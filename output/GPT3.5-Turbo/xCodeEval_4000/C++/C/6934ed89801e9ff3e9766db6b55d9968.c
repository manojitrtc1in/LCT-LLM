#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAX_64 (0x7fffffffffffffffLL)
#define MAX_32 (0x7fffffff)
#define PRICE_MAX MAX_64

#define MAXLINE       100 

#define ARC_FIELDS      5 

#define NODE_FIELDS     2 

#define P_FIELDS        3 

#define PROBLEM_TYPE "min" 


#define UNFEASIBLE          2
#define ALLOCATION_FAULT    5
#define PRICE_OFL           6



#define UPDT_FREQ      0.4
#define UPDT_FREQ_S    30
#define SCALE_DEFAULT  12.0


#define PRICE_OUT_START  1
#define CUT_OFF_POWER    0.44
#define CUT_OFF_COEF     1.5
#define CUT_OFF_POWER2   0.75
#define CUT_OFF_COEF2    1
#define CUT_OFF_GAP      0.8
#define CUT_OFF_MIN      12
#define CUT_OFF_INCREASE 4

#define TIME_FOR_PRICE_IN1    2
#define TIME_FOR_PRICE_IN2    4
#define TIME_FOR_PRICE_IN3    6

#define MAX_CYCLES_CANCELLED 0
#define START_CYCLE_CANCEL   100

#define MAX( x, y ) ( ( (x) > (y) ) ?  x : y )
#define MIN( x, y ) ( ( (x) < (y) ) ? x : y )
#define ABS( x ) ( (x) >= 0 ) ? (x) : -(x)
#define N_NODE( i ) ( ( (i) == NULL ) ? -1 : ( (i) - _nodes + _node_min ) )
#define N_ARC( a ) ( ( (a) == NULL )? -1 : (a) - _arcs )

typedef long long int excess_t;
typedef long long int price_t;

typedef struct NODE NODE;
typedef struct ARC ARC;
typedef struct BUCKET BUCKET;

struct ARC {
    long _rez_capacity; 
    price_t _cost; 
    NODE *_head; 
    ARC *_sister; 
};

struct NODE {
    excess_t _excess; 
    price_t _price; 
    ARC *_first; 
    ARC *_current; 
    ARC *_suspended;
    NODE *_q_next; 
    NODE *_b_next; 
    NODE *_b_prev; 
    long _rank; 
    long _inp; 
};

struct BUCKET {
    NODE *_p_first;
};

long _n; 
long _m; 
long *_cap; 
NODE *_nodes; 
NODE *_sentinel_node; 
NODE *_excq_first; 
NODE *_excq_last; 
ARC *_arcs; 
ARC *_sentinel_arc; 
BUCKET *_buckets; 
BUCKET *_l_bucket; 
long _linf; 
int _time_for_price_in;
price_t _epsilon; 
price_t _dn; 
price_t _price_min; 
price_t _mmc; 
double _f_scale; 
double _cut_off_factor; 
double _cut_on; 
double _cut_off; 
excess_t _total_excess; 
int _flag_price;
int _flag_updt;
int _snc_max;
ARC _d_arc; 
NODE _d_node; 
NODE *_dummy_node; 
NODE *_dnode;
long _n_rel; 
long _n_ref; 
long _n_src; 
long _n_push;
long _n_relabel;
long _n_discharge;
long _n_refine;
long _n_update;
long _n_scan;
long _n_prscan;
long _n_prscan1;
long _n_prscan2;
long _n_bad_pricein;
long _n_bad_relabel;
long _n_prefine;
int _no_zero_cycles; 
int _check_solution; 
int _comp_duals; 
int _cost_restart; 
int _print_ans;
long long int *_node_balance;
long _node_min; 
long _node_max; 
long *_arc_first; 
long *_arc_tail; 
long _pos_current;
ARC *_arc_current;
ARC *_arc_new;
ARC *_arc_tmp;
price_t _max_cost; 
excess_t _total_p; 
excess_t _total_n; 
NODE *_i_node;
NODE *_j_node;

void err_end( int cc);
void allocate_arrays();
void deallocate_arrays();
void set_arc( long tail_node_id, long head_node_id,
              long low_bound, long up_bound, price_t cost);
void set_supply_demand_of_node( long id, long excess);
void pre_processing();
void cs2_initialize();
void up_node_scan( NODE *i);
void price_update();
int relabel( NODE *i);
void discharge( NODE *i);
int price_in();
void refine();
int price_refine();
void compute_prices();
void price_out();
int update_epsilon();
int check_feas();
int check_cs();
int check_eps_opt();
void init_solution();
void cs_cost_reinit();
void cs2_cost_restart( double *objective_cost);
void print_solution();
void print_graph();
void finishup( double *objective_cost);
void cs2( double *objective_cost);
int run_cs2();

int f(int r, int c){
    return r*m+c+1;
}

int main( int argc, char *argv[]){
    scanf("%d%d",&n,&m);
    int grid[n][m];
    int a[4*n*m],b[4*n*m],c[4*n*m];
    int na = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            scanf("%d",&grid[i][j]);
            if((i+j)%2){
                if(i > 0){a[na] = f(i,j); b[na] = f(i-1,j); c[na] = grid[i][j] != grid[i-1][j]; na++;}
                if(j > 0){a[na] = f(i,j); b[na] = f(i,j-1); c[na] = grid[i][j] != grid[i][j-1]; na++;}
                if(i+1 < n){a[na] = f(i,j); b[na] = f(i+1,j); c[na] = grid[i][j] != grid[i+1][j]; na++;}
                if(j+1 < m){a[na] = f(i,j); b[na] = f(i,j+1); c[na] = grid[i][j] != grid[i][j+1]; na++;}
            }
        }
    int num_nodes = n*m*4;
    int num_arcs = na;
    allocate_arrays();
    for(int i = 0; i < num_arcs; ++i)
        set_arc( a[i], b[i], 0, 1, c[i]);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if((i+j)%2){
                set_supply_demand_of_node( f(i,j), 1);
            }
            else{
                set_supply_demand_of_node( f(i,j), -1);
            }
    run_cs2();
    return 0;
}
