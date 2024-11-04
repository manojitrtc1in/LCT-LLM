#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

typedef long long int excess_t;
typedef long long int price_t;

typedef struct ARC {
    long _rez_capacity; 
    price_t _cost; 
    struct NODE *_head; 
    struct ARC *_sister; 
} ARC;

typedef struct NODE {
    excess_t _excess; 
    price_t _price; 
    ARC *_first; 
    ARC *_current; 
    ARC *_suspended;
    struct NODE *_q_next; 
    struct NODE *_b_next; 
    struct NODE *_b_prev; 
    long _rank; 
    long _inp; 
} NODE;

typedef struct BUCKET {
    NODE *_p_first;
} BUCKET;

typedef struct MCMF_CS2 {
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
    bool _no_zero_cycles; 
    bool _check_solution; 
    bool _comp_duals; 
    bool _cost_restart; 
    bool _print_ans;
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
} MCMF_CS2;

void err_end(int cc) {
    exit(cc);
}

void allocate_arrays(MCMF_CS2 *mcmf) {
    mcmf->_nodes = (NODE*) calloc(mcmf->_n + 2, sizeof(NODE));
    mcmf->_arcs = (ARC*) calloc(2 * mcmf->_m + 1, sizeof(ARC));
    mcmf->_cap = (long*) calloc(2 * mcmf->_m, sizeof(long));
    mcmf->_arc_tail = (long*) calloc(2 * mcmf->_m, sizeof(long));
    mcmf->_arc_first = (long*) calloc(mcmf->_n + 2, sizeof(long));

    for (NODE *in = mcmf->_nodes; in <= mcmf->_nodes + mcmf->_n; in++) {
        in->_excess = 0;
    }
    if (mcmf->_nodes == NULL || mcmf->_arcs == NULL || mcmf->_arc_first == NULL || mcmf->_arc_tail == NULL) {
        exit(1);
    }

    mcmf->_pos_current = 0;
    mcmf->_arc_current = mcmf->_arcs; 
    mcmf->_node_max = 0;
    mcmf->_node_min = mcmf->_n;
    mcmf->_max_cost = 0;
    mcmf->_total_p = mcmf->_total_n = 0;
}

void deallocate_arrays(MCMF_CS2 *mcmf) { 
    if (mcmf->_arcs) free(mcmf->_arcs);
    if (mcmf->_dnode) free(mcmf->_dnode);
    if (mcmf->_cap) free(mcmf->_cap);
    if (mcmf->_buckets) free(mcmf->_buckets);
    if (mcmf->_check_solution == true) free(mcmf->_node_balance);
    if (mcmf->_nodes) {
        mcmf->_nodes = mcmf->_nodes - mcmf->_node_min;
        free(mcmf->_nodes);
    }
}

void set_arc(MCMF_CS2 *mcmf, long tail_node_id, long head_node_id, long low_bound, long up_bound, price_t cost) {
    if (tail_node_id < 0 || tail_node_id > mcmf->_n || head_node_id < 0 || head_node_id > mcmf->_n) {
        exit(1);
    }
    if (up_bound < 0) {
        up_bound = MAX_32;
    }
    if (low_bound < 0 || low_bound > up_bound) {
        exit(1);
    }

    mcmf->_arc_first[tail_node_id + 1]++;
    mcmf->_arc_first[head_node_id + 1]++;
    mcmf->_i_node = mcmf->_nodes + tail_node_id;
    mcmf->_j_node = mcmf->_nodes + head_node_id;

    mcmf->_arc_tail[mcmf->_pos_current] = tail_node_id;
    mcmf->_arc_tail[mcmf->_pos_current + 1] = head_node_id;
    mcmf->_arc_current->set_head(mcmf->_j_node);
    mcmf->_arc_current->set_rez_capacity(up_bound - low_bound);
    mcmf->_cap[mcmf->_pos_current] = up_bound;
    mcmf->_arc_current->set_cost(cost);
    mcmf->_arc_current->set_sister(mcmf->_arc_current + 1);
    (mcmf->_arc_current + 1)->set_head(mcmf->_nodes + tail_node_id);
    (mcmf->_arc_current + 1)->set_rez_capacity(0);
    mcmf->_cap[mcmf->_pos_current + 1] = 0;
