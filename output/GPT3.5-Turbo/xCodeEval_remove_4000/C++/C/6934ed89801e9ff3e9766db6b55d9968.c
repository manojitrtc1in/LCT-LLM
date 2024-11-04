#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define SCALE_DEFAULT 100
#define UPDT_FREQ 0.5
#define UPDT_FREQ_S 0.02
#define PRICE_MAX 1000000
#define MAX_64 9223372036854775807
#define CUT_OFF_COEF 0.5
#define CUT_OFF_POWER 1.5
#define CUT_OFF_MIN 0.01
#define CUT_OFF_GAP 0.2
#define MAX_CYCLES_CANCELLED 1000
#define START_CYCLE_CANCEL 100
#define WHITE 0
#define GREY 1
#define BLACK 2
#define OPEN(a) ((a)->rez_capacity() > 0)
#define CLOSED(a) ((a)->rez_capacity() == 0)
#define REDUCED_COST(i, j, a) ((i)->price() + (a)->cost() - (j)->price())

typedef long long int excess_t;
typedef long long int price_t;

typedef struct arc {
    long id5;
    price_t _cost;
    struct node *_head;
    struct arc *_sister;
} ARC;

typedef struct node {
    excess_t _excess;
    price_t _price;
    struct arc *_first;
    struct arc *_current;
    struct arc *_suspended;
    struct node *_q_next;
    struct node *_b_next;
    struct node *_b_prev;
    long _rank;
    long _inp;
} NODE;

typedef struct bucket {
    struct node *_p_first;
} BUCKET;

typedef struct id32 {
    long _n;
    long _m;
    long *_cap;
    NODE *_nodes;
    NODE *id31;
    NODE *id14;
    NODE *id30;
    ARC *_arcs;
    ARC *id26;
    BUCKET *_buckets;
    BUCKET *_l_bucket;
    long _linf;
    int id16;
    price_t _epsilon;
    price_t _dn;
    price_t _price_min;
    price_t _mmc;
    double _f_scale;
    double id18;
    double _cut_on;
    double _cut_off;
    excess_t id23;
    int _flag_price;
    int id29;
    int id0;
    ARC _d_arc;
    NODE _d_node;
    NODE *_dummy_node;
    NODE *_dnode;
    long _n_rel;
    long _n_ref;
    long _n_src;
    long _n_push;
    long id24;
    long id17;
    long id22;
    long _n_update;
    long _n_scan;
    long id6;
    long id34;
    long id27;
    long id15;
    long id7;
    long id3;
    bool id2;
    bool _check_solution;
    bool id1;
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
} id32;

void err_end(int cc) {
    exit(cc);
}

void allocate_arrays(id32 *id8) {
    id8->_nodes = (NODE *)calloc(id8->_n + 2, sizeof(NODE));
    id8->_arcs = (ARC *)calloc(2 * id8->_m + 1, sizeof(ARC));
    id8->_cap = (long *)calloc(2 * id8->_m, sizeof(long));
    id8->_arc_tail = (long *)calloc(2 * id8->_m, sizeof(long));
    id8->_arc_first = (long *)calloc(id8->_n + 2, sizeof(long));

    for (NODE *in = id8->_nodes; in <= id8->_nodes + id8->_n; in++) {
        in->_excess = 0;
    }
    if (id8->_nodes == NULL || id8->_arcs == NULL || id8->_arc_first == NULL || id8->_arc_tail == NULL) {
        exit(1);
    }

    id8->_pos_current = 0;
    id8->_arc_current = id8->_arcs;

    id8->_node_max = 0;
    id8->_node_min = id8->_n;
    id8->_max_cost = 0;
    id8->_total_p = 0;
    id8->_total_n = 0;
}

void deallocate_arrays(id32 *id8) {
    if (id8->_arcs) free(id8->_arcs);
    if (id8->_dnode) free(id8->_dnode);
    if (id8->_cap) free(id8->_cap);
    if (id8->_buckets) free(id8->_buckets);
    if (id8->_check_solution == true) free(id8->_node_balance);
    if (id8->_nodes) {
        id8->_nodes = id8->_nodes - id8->_node_min;
        free(id8->_nodes);
    }
}

void set_arc(id32 *id8, long id10, long id28, long low_bound, long up_bound, price_t cost) {
    if (id10 < 0 || id10 > id8->_n || id28 < 0 || id28 > id8->_n) {
        exit(1);
    }
    if (up_bound < 0) {
        up_bound = id9;
    }
    if (low_bound < 0 || low_bound > up_bound) {
        exit(1);
    }

    id8->_arc_first[id10 + 1]++;
    id8->_arc_first[id28 + 1]++;
    id8->_i_node = id8->_nodes + id10;
    id8->_j_node = id8->_nodes + id28;

    id8->_arc_tail[id8->_pos_current] = id10;
    id8->_arc_tail[id8->_pos_current + 1] = id28;
    id8->_arc_current->head = id8->_j_node;
    id8->_arc_current->rez_capacity = up_bound - low_bound;
    id8->_cap[id8->_pos_current] = up_bound;
    id8->_arc_current->cost = cost;
    id8->_arc_current->sister = id8->_arc_current + 1;
    (id8->_arc_current + 1)->head = id8->_nodes + id10;
    (id8->_arc_current + 1)->rez_capacity = 0;
    id8->_cap[id8->_pos_current + 1] = 0;
    (id8->_arc_current + 1)->cost = -cost;
    (id8->_arc_current + 1)->sister = id8->_arc_current;

    id8->_i_node->excess -= low_bound;
    id8->_j_node->excess += low_bound;

    if (id28 < id8->_node_min)
        id8->_node_min = id28;
    if (id10 < id8->_node_min)
        id8->_node_min = id10;
    if (id28 > id8->_node_max)
        id8->_node_max = id28;
    if (id10 > id8->_node_max)
        id8->_node_max = id10;

    if (cost < 0)
        cost = -cost;
    if (cost > id8->_max_cost && up_bound > 0)
        id8->_max_cost = cost;

    id8->_arc_current += 2;
    id8->_pos_current += 2;
}

void set_supply_demand_of_node(id32 *id8, long id, long excess) {
    if (id < 0 || id > id8->_n) {
        exit(1);
    }
    (id8->_nodes + id)->excess = excess;
    if (excess > 0)
        id8->_total_p += excess;
    if (excess < 0)
        id8->_total_n -= excess;
}

void pre_processing(id32 *id8) {
    long i;
    long last, arc_num, id20;
    long id10;
    NODE *head_p;
    ARC *arc_new, *arc_tmp;
    long up_bound;
    price_t cost;

    excess_t cap_out;
    excess_t cap_in;

    if (ABS(id8->_total_p - id8->_total_n) > 0.5) {
        exit(1);
    }

    (id8->_nodes + id8->_node_min)->_first = id8->_arcs;

    for (i = id8->_node_min + 1; i <= id8->_node_max + 1; i++) {
        id8->_arc_first[i] += id8->_arc_first[i - 1];
        (id8->_nodes + i)->_first = id8->_arcs + id8->_arc_first[i];
    }

    for (i = id8->_node_min; i < id8->_node_max; i++) {

        last = ((id8->_nodes + i + 1)->_first) - id8->_arcs;

        for (arc_num = id8->_arc_first[i]; arc_num < last; arc_num++) {
            id10 = id8->_arc_tail[arc_num];

            while (id10 != i) {

                id20 = id8->_arc_first[id10];
                id8->_arc_current = id8->_arcs + arc_num;
                arc_new = id8->_arcs + id20;

                head_p = arc_new->head;
                arc_new->head = id8->_arc_current->head;
                id8->_arc_current->head = head_p;

                up_bound = id8->_cap[id20];
                id8->_cap[id20] = id8->_cap[arc_num];
                id8->_cap[arc_num] = up_bound;

                up_bound = arc_new->rez_capacity;
                arc_new->rez_capacity = id8->_arc_current->rez_capacity;
                id8->_arc_current->rez_capacity = up_bound;

                cost = arc_new->cost;
                arc_new->cost = id8->_arc_current->cost;
                id8->_arc_current->cost = cost;

                if (arc_new != id8->_arc_current->sister) {
                    arc_tmp = arc_new->sister;
                    arc_new->sister = id8->_arc_current->sister;
                    id8->_arc_current->sister = arc_tmp;

                    id8->_arc_current->sister->sister = id8->_arc_current;
                    arc_new->sister->sister = arc_new;
                }

                id8->_arc_tail[arc_num] = id8->_arc_tail[id20];
                id8->_arc_tail[id20] = id10;

                id8->_arc_first[id10]++;

                id10 = id8->_arc_tail[arc_num];
            }
        }
    }

    id8->_n = id8->_node_max - id8->_node_min + 1;
    id8->_nodes = id8->_nodes + id8->_node_min;

    free(id8->_arc_first);
    free(id8->_arc_tail);
}

void cs2_initialize(id32 *id8) {
    NODE *i;
    ARC *a;
    ARC *a_stop;
    BUCKET *b;
    long df;

    id8->_f_scale = (long)SCALE_DEFAULT;
    id8->id31 = id8->_nodes + id8->_n;
    id8->id26 = id8->_arcs + id8->_m;

    for (i = id8->_nodes; i != id8->id31; i++) {
        i->_price = 0;
        i->_suspended = i->_first;
        i->_q_next = id8->id31;
    }

    id8->id31->_first = id8->id26;
    id8->id31->_suspended = id8->id26;

    for (i = id8->_nodes; i != id8->id31; i++) {
        for (a = i->_first, a_stop = (i + 1)->_suspended; a != a_stop; a++) {
            if (a->_cost < 0) {
                if ((df = a->_rez_capacity) > 0) {
                    id8->increase_flow(i, a->_head, a, df);
                }
            }
        }
    }

    id8->_dn = id8->_n + 1;
    if (id8->id2 == true) {

        id8->_dn = 2 * id8->_dn;
    }

    for (a = id8->_arcs; a != id8->id26; a++) {
        a->_cost *= id8->_dn;
    }

    if (id8->id2 == true) {

        for (a = id8->_arcs; a != id8->id26; a++) {
            if ((a->_cost == 0) && (a->_sister->_cost == 0)) {
                a->_cost = 1;
                a->_sister->_cost = -1;
            }
        }
    }

