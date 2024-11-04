#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int excess_t;
typedef long long int price_t;

typedef struct NODE NODE;
typedef struct ARC ARC;

struct ARC {
    long id5;
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

typedef struct BUCKET {
    NODE *_p_first;
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

int n, m;

int f(int r, int c) {
    return r * m + c + 1;
}

void err_end(int cc) {
    exit(cc);
}

void allocate_arrays(id32 *id) {
    id->_nodes = (NODE*) calloc(id->_n + 2, sizeof(NODE));
    id->_arcs = (ARC*) calloc(2 * id->_m + 1, sizeof(ARC));
    id->_cap = (long*) calloc(2 * id->_m, sizeof(long));
    id->_arc_tail = (long*) calloc(2 * id->_m, sizeof(long));
    id->_arc_first = (long*) calloc(id->_n + 2, sizeof(long));

    for (NODE *in = id->_nodes; in <= id->_nodes + id->_n; in++) {
        in->_excess = 0;
    }
    if (id->_nodes == NULL || id->_arcs == NULL || id->_arc_first == NULL || id->_arc_tail == NULL) {
        exit(1);
    }

    id->_pos_current = 0;
    id->_arc_current = id->_arcs;
    id->_node_max = 0;
    id->_node_min = id->_n;
    id->_max_cost = 0;
    id->_total_p = id->_total_n = 0;
}

void deallocate_arrays(id32 *id) {
    if (id->_arcs) free(id->_arcs);
    if (id->_dnode) free(id->_dnode);
    if (id->_cap) free(id->_cap);
    if (id->_buckets) free(id->_buckets);
    if (id->_check_solution == true) free(id->_node_balance);
    if (id->_nodes) {
        id->_nodes = id->_nodes - id->_node_min;
        free(id->_nodes);
    }
}

void set_arc(id32 *id, long id10, long id28, long low_bound, long up_bound, price_t cost) {
    if (id10 < 0 || id10 > id->_n || id28 < 0 || id28 > id->_n) {
        exit(1);
    }
    if (up_bound < 0) {
        up_bound = 0; // Assuming id9 is 0 as it is not defined
    }
    if (low_bound < 0 || low_bound > up_bound) {
        exit(1);
    }

    id->_arc_first[id10 + 1]++;
    id->_arc_first[id28 + 1]++;
    id->_i_node = id->_nodes + id10;
    id->_j_node = id->_nodes + id28;

    id->_arc_tail[id->_pos_current] = id10;
    id->_arc_tail[id->_pos_current + 1] = id28;
    id->_arc_current->set_head(id->_j_node);
    id->_arc_current->set_rez_capacity(up_bound - low_bound);
    id->_cap[id->_pos_current] = up_bound;
    id->_arc_current->set_cost(cost);
    id->_arc_current->set_sister(id->_arc_current + 1);
    (id->_arc_current + 1)->set_head(id->_nodes + id10);
    (id->_arc_current + 1)->set_rez_capacity(0);
    id->_cap[id->_pos_current + 1] = 0;
    (id->_arc_current + 1)->set_cost(-cost);
    (id->_arc_current + 1)->set_sister(id->_arc_current);

    id->_i_node->dec_excess(low_bound);
    id->_j_node->inc_excess(low_bound);

    if (id28 < id->_node_min) id->_node_min = id28;
    if (id10 < id->_node_min) id->_node_min = id10;
    if (id28 > id->_node_max) id->_node_max = id28;
    if (id10 > id->_node_max) id->_node_max = id10;

    if (cost < 0) cost = -cost;
    if (cost > id->_max_cost && up_bound > 0) id->_max_cost = cost;

    id->_arc_current += 2;
    id->_pos_current += 2;
}

void set_supply_demand_of_node(id32 *id, long id, long excess) {
    if (id < 0 || id > id->_n) {
        exit(1);
    }
    (id->_nodes + id)->set_excess(excess);
    if (excess > 0) id->_total_p += excess;
    if (excess < 0) id->_total_n -= excess;
}

void pre_processing(id32 *id) {
    long i;
    long last, arc_num, id20;
    long id10;
    NODE *head_p;
    ARC *arc_new, *arc_tmp;
    long up_bound;
    price_t cost;

    excess_t cap_out;
    excess_t cap_in;

    if (abs(id->_total_p - id->_total_n) > 0.5) {
        printf("%lld %lld\n", id->_total_p, id->_total_n);
        exit(1);
    }

    (id->_nodes + id->_node_min)->set_first(id->_arcs);

    for (i = id->_node_min + 1; i <= id->_node_max + 1; i++) {
        id->_arc_first[i] += id->_arc_first[i - 1];
        (id->_nodes + i)->set_first(id->_arcs + id->_arc_first[i]);
    }

    for (i = id->_node_min; i < id->_node_max; i++) {
        last = ((id->_nodes + i + 1)->first()) - id->_arcs;

        for (arc_num = id->_arc_first[i]; arc_num < last; arc_num++) {
            id10 = id->_arc_tail[arc_num];

            while (id10 != i) {
                id20 = id->_arc_first[id10];
                id->_arc_current = id->_arcs + arc_num;
                arc_new = id->_arcs + id20;

                head_p = arc_new->head();
                arc_new->set_head(id->_arc_current->head());
                id->_arc_current->set_head(head_p);

                up_bound = id->_cap[id20];
                id->_cap[id20] = id->_cap[arc_num];
                id->_cap[arc_num] = up_bound;

                up_bound = arc_new->rez_capacity();
                arc_new->set_rez_capacity(id->_arc_current->rez_capacity());
                id->_arc_current->set_rez_capacity(up_bound);

                cost = arc_new->cost();
                arc_new->set_cost(id->_arc_current->cost());
                id->_arc_current->set_cost(cost);

                if (arc_new != id->_arc_current->sister()) {
                    arc_tmp = arc_new->sister();
                    arc_new->set_sister(id->_arc_current->sister());
                    id->_arc_current->set_sister(arc_tmp);

                    id->_arc_current->sister()->set_sister(id->_arc_current);
                    arc_new->sister()->set_sister(arc_new);
                }

                id->_arc_tail[arc_num] = id->_arc_tail[id20];
                id->_arc_tail[id20] = id10;

                id->_arc_first[id10]++;

                id10 = id->_arc_tail[arc_num];
            }
        }
    }

    for (NODE *ndp = id->_nodes + id->_node_min; ndp <= id->_nodes + id->_node_max; ndp++) {
        cap_in = (ndp->excess());
        cap_out = -(ndp->excess());
        for (id->_arc_current = ndp->first(); id->_arc_current != (ndp + 1)->first(); id->_arc_current++) {
            arc_num = id->_arc_current - id->_arcs;
            if (id->_cap[arc_num] > 0) cap_out += id->_cap[arc_num];
            if (id->_cap[arc_num] == 0)
                cap_in += id->_cap[id->_arc_current->sister() - id->_arcs];
        }
    }
    if (id->_node_min < 0 || id->_node_min > 1) {
        exit(1);
    }

    id->_n = id->_node_max - id->_node_min + 1;
    id->_nodes = id->_nodes + id->_node_min;

    free(id->_arc_first);
    free(id->_arc_tail);
}

void cs2_initialize(id32 *id) {
    NODE *i;
    ARC *a;
    ARC *a_stop;
    BUCKET *b;

    long df;

    id->_f_scale = (long) 1; // Assuming SCALE_DEFAULT is 1
    id->id31 = id->_nodes + id->_n;
    id->id26 = id->_arcs + id->_m;

    for (i = id->_nodes; i != id->id31; i++) {
        i->set_price(0);
        i->set_suspended(i->first());
        i->set_q_next(id->id31);
    }

    id->id31->set_first(id->id26);
    id->id31->set_suspended(id->id26);

    for (i = id->_nodes; i != id->id31; i++) {
        for (a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a++) {
            if (a->cost() < 0) {
                if ((df = a->rez_capacity()) > 0) {
                    increase_flow(i, a->head(), a, df);
                }
            }
        }
    }

    id->_dn = id->_n + 1;
    if (id->id2 == true) {
        id->_dn = 2 * id->_dn;
    }

    for (a = id->_arcs; a != id->id26; a++) {
        a->multiply_cost(id->_dn);
    }

    if (id->id2 == true) {
        for (a = id->_arcs; a != id->id26; a++) {
            if ((a->cost() == 0) && (a->sister()->cost() == 0)) {
                a->set_cost(1);
                a->sister()->set_cost(-1);
            }
        }
    }

    if ((double) id->_max_cost * (double) id->_dn > 9223372036854775807) {
        // Handle overflow case
    }
    id->_mmc = id->_max_cost * id->_dn;

    id->_linf = (long) (id->_dn * ceil(id->_f_scale) + 2);

    id->_buckets = (BUCKET*) calloc(id->_linf, sizeof(BUCKET));
    if (id->_buckets == NULL)
        err_end(1); // Assuming ALLOCATION_FAULT is 1

    id->_l_bucket = id->_buckets + id->_linf;

    id->_dnode = (NODE*) malloc(sizeof(NODE)); // Assuming new NODE is malloc

    for (b = id->_buckets; b != id->_l_bucket; b++) {
