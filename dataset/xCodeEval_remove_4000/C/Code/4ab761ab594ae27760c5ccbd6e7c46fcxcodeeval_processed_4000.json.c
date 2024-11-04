







static int64_t min(int64_t a, int64_t b) {
    return a < b ? a : b;
}



typedef int64_t heap_key_t;


typedef uint64_t ptr_t;

typedef uint32_t ptr_t;




typedef struct heap_node {
    struct heap_node * lchild;
    struct heap_node * rsib;
    heap_key_t key;
} heap_node;



    ((heap_node)->key = ((heap_key_t) k))


typedef struct min_heap {
    heap_node * root;
} heap_t;



int heap_init(heap_t *h);

void heap_destroy(heap_t *h);



heap_node * id18(heap_t *h);


void id8(heap_t *h);


heap_node * id5(heap_t *h);



int heap_insert(heap_t *h, heap_node * node);



int id9(heap_t *h1, heap_t *h2);


int id20(heap_t *h, heap_node * node, heap_key_t new_key);


int id1(heap_t *h, heap_node * node, heap_key_t new_key);


int heap_delete(heap_t *h, heap_node * node);











    ((((ptr_t) (heap_node)->rsib) & LEFT_CHILD) != 0)





    ((node)->rsib = (heap_node *) (((ptr_t) (node)->rsib) | LEFT_CHILD))


    ((node)->rsib = (heap_node *) (((ptr_t) (node)->rsib) & ~LEFT_CHILD))









    (((heap_node)->rsib) != NULL)


    ((heap_node*) (((ptr_t) (node)->rsib) & ~LEFT_CHILD))



    ((((ptr_t) (ptr)) & 0x7) == 0)




static heap_node * _right_child(heap_node * node) {
    heap_node * child = node->lchild;
    if (child != node) {
        heap_node * rsib = RSIB(child);
        if (rsib != node) {
            return rsib;
        }
        else if (IS_RIGHT_CHILD(child)) {
            return child;
        }
    }
    return NULL;
}


static void _make_root(heap_t * h, heap_node * root) {
    h->root = root;
    root->rsib = (heap_node *) (((ptr_t) h) | LEFT_CHILD);
}



int heap_init(heap_t *h) {
    

    h->root = (heap_node *) h;
    return 0;
}


void heap_destroy(heap_t *h) {
}





static void id11(heap_node * node, heap_node * rchild) {
    heap_node * lchild = node->lchild;

    rchild->rsib = node;
    if (lchild == node) {
        

        node->lchild = rchild;
    }
    else {
        

        HEAP_ASSERT(IS_LEFT_CHILD(lchild));
        HEAP_ASSERT(RSIB(lchild) == node);

        lchild->rsib = (heap_node *) (((ptr_t) rchild) | LEFT_CHILD);
    }
}



static void _add_child(heap_node * node, heap_node * new_child) {
    heap_node * lchild = node->lchild;

    if (lchild == node) {
        

        node->lchild = new_child;

        

        new_child->rsib = (heap_node *) (((ptr_t) node) | LEFT_CHILD);
    }
    else {
        

        HEAP_ASSERT(IS_LEFT_CHILD(lchild));
        HEAP_ASSERT(RSIB(lchild) == node);

        id11(new_child, lchild);

        

        node->lchild = new_child;
        new_child->rsib = (heap_node *) (((ptr_t) node) | LEFT_CHILD);
    }
}





static heap_node * _link(heap_node * n1, heap_node * n2) {

    HEAP_ASSERT(n1 != NULL);
    HEAP_ASSERT(n2 != NULL);

    if (n2->key < n1->key) {
        heap_node * tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    


    _add_child(n1, n2);

    

    return n1;
}




static heap_node * id7(heap_node * node) {
    heap_node * lchild = node->lchild;

    if (lchild != node) {
        


        

        heap_node * id17 = RSIB(lchild);

        if (IS_RIGHT_CHILD(lchild)) {
            


            

            HEAP_ASSERT(id17 == node);

            

            node->lchild = node;
            return lchild;
        }
        else if (id17 != node) {
            

            HEAP_ASSERT(IS_RIGHT_CHILD(id17));

            

            

            lchild->rsib = (heap_node *) (((ptr_t) node) | LEFT_CHILD);
            return id17;
        }
    }

    

    

    return NULL;
}



static void _unlink(heap_node * node) {

    

    HEAP_ASSERT(HAS_PARENT(node));

    

    


    int id15 = IS_LEFT_CHILD(node);
    heap_node * rsib = RSIB(node);

    

    

    heap_node * rchild = id7(node);

    if (rsib->lchild == node) {
        

        heap_node * parent = rsib;

        if (rchild != NULL) {
            

            parent->lchild = rchild;

            

            rchild->rsib =
                (heap_node *) (((ptr_t) parent) | id15);
        }
        else {
            

            

            

            parent->lchild = parent;
        }
    }
    else {
        

        


        if (id15) {

            HEAP_ASSERT(IS_RIGHT_CHILD(rsib));

            

            

            heap_node * parent = rsib->rsib;

            

            if (rchild != NULL) {
                parent->lchild = rchild;
                rchild->rsib = (heap_node *) (((ptr_t) rsib) | LEFT_CHILD);
            }
            else {
                

                

                parent->lchild = rsib;
            }
        }
        else  {
            

            heap_node * parent = rsib;
            heap_node * lsib = parent->lchild;

            HEAP_ASSERT(IS_LEFT_CHILD(lsib));

            

            if (rchild != NULL) {
                lsib->rsib = (heap_node *) (((ptr_t) rchild) | LEFT_CHILD);
                rchild->rsib = parent;
            }
            else {
                

                

                lsib->rsib = (heap_node *) (((ptr_t) parent) | LEFT_CHILD);
            }
        }
    }
}




heap_node * id18(heap_t *h) {
    if (h->root == (heap_node *) h) {
        return NULL;
    }
    return h->root;
}






static heap_node * _delete_root(heap_node * node) {
    heap_node * id10 = NULL;
    heap_node * id3;

    heap_node * child = node->lchild;
    if (child == node) {
        

        return NULL;
    }

    

    

    do {
        heap_node * child2 = _right_child(child);
        if (child2 != NULL) {
            id3 = _right_child(child2);

            

            id7(child);
            id7(child2);

            

            child = _link(child, child2);
        }
        else {
            id3 = NULL;
        }

        

        child->rsib = id10;
        id10 = child;

        child = id3;
    } while (child != NULL);

    

    


    

    child = id10->rsib;
    while (child != NULL) {
        HEAP_ASSERT((((ptr_t) child) & 0x1) == 0);
        id3 = child->rsib;
        id10 = _link(id10, child);
        child = id3;
    }

    return id10;
}



void id8(heap_t *h) {
    heap_node * root = h->root;
    root = _delete_root(root);

    if (root != NULL) {
        _make_root(h, root);
    }
    else {
        h->root = (heap_node *) h;
    }
}


heap_node * id5(heap_t *h) {
    heap_node * min = id18(h);
    if (min != NULL) {
        id8(h);
    }
    return min;
}





int heap_insert(heap_t *h, heap_node * node) {

    HEAP_ASSERT(IS_ALIGNED(node));
    

    node->lchild = node;

    heap_node * root = h->root;

    if (root != (heap_node *) h) {
        

        root = _link(root, node);

        _make_root(h, root);
    }
    else {
        

        

        

        _add_child((heap_node *) h, node);
    }

    return 0;
}



int id9(heap_t *h1, heap_t *h2) {
    heap_node * r1 = id18(h1);
    heap_node * r2 = id18(h2);

    if (r2 == NULL) {
        

    }
    else if (r1 == NULL) {
        _make_root(h1, r1);
    }
    else {
        r1 = _link(r1, r2);
        _make_root(h1, r1);
    }

    return 0;
}




int id20(heap_t *h, heap_node * node, heap_key_t new_key) {

    heap_key_t old_key = node->key;

    

    HEAP_ASSERT(old_key > new_key);

    node->key = new_key;

    

    

    _unlink(node);

    heap_node * root = h->root;
    if (root != (heap_node *) h) {
        root = _link(root, node);

        _make_root(h, root);
    }
    else {
        

        HEAP_ASSERT(IS_LEFT_CHILD(node));
        h->root = node;
    }

    return 0;
}



int id1(heap_t *h, heap_node * node, heap_key_t new_key) {

    heap_key_t old_key = node->key;

    

    HEAP_ASSERT(old_key < new_key);

    node->key = new_key;

    int res = heap_delete(h, node);
    if (res == 0) {
        res = heap_insert(h, node);
    }
    return res;
}




int heap_delete(heap_t *h, heap_node * node) {
    heap_node * root = h->root;

    if (root == node) {
        

        

        id8(h);
    }
    else {
        

        

        

        _unlink(node);
        heap_node * id13 = _delete_root(node);

        if (id13 != NULL) {
            

            

            root = _link(root, id13);
        }

        _make_root(h, root);
    }

    return 0;
}





typedef struct edge {
    uint32_t w;
    uint32_t to;
    uint32_t cost;
    uint32_t edge_idx;
} edge_t;

typedef struct val_edge {
    heap_node node;
    uint32_t w;
    

    uint32_t n_children;
    

    uint32_t cost;
} val_edge_t;


typedef struct dylist {
    uint32_t len;
    uint32_t cap;
    edge_t * ptr;
} dylist_t;

static void id2(dylist_t * l, edge_t val) {
    uint32_t cap = l->cap;
    if (cap == l->len) {
        cap = (cap << 1) | !cap;
        l->cap = cap;
        edge_t * new_ptr = (edge_t *) realloc(l->ptr, cap * sizeof(edge_t));
        l->ptr = new_ptr;
    }
    l->ptr[l->len] = val;
    l->len++;
}

static void id4(dylist_t * l) {
    if (l->ptr) {
        free(l->ptr);
    }
}


typedef struct int_dylist {
    uint32_t len;
    uint32_t cap;
    uint64_t * ptr;
} int_dylist_t;

static void id16(int_dylist_t * l, uint64_t val) {
    uint32_t cap = l->cap;
    if (cap == l->len) {
        cap = (cap << 1) | !cap;
        l->cap = cap;
        uint64_t * new_ptr = (uint64_t *) realloc(l->ptr, cap * sizeof(edge_t));
        l->ptr = new_ptr;
    }
    l->ptr[l->len] = val;
    l->len++;
}

static void id0(int_dylist_t * l) {
    if (l->ptr) {
        free(l->ptr);
    }
}


typedef struct node {
    dylist_t edges;

    

    uint32_t par_edge_idx;
} node_t;


static void add_edge(node_t * nodes, uint32_t v, uint32_t u, uint32_t w,
        uint32_t edge_idx, uint32_t cost) {
    edge_t ev = {
        .w = w,
        .to = u,
        .edge_idx = edge_idx,
        .cost = cost
    };
    edge_t eu = {
        .w = w,
        .to = v,
        .edge_idx = edge_idx,
        .cost = cost
    };
    id2(&nodes[v].edges, ev);
    id2(&nodes[u].edges, eu);
}


static uint32_t resolve_edges(val_edge_t * edges, const node_t * nodes, uint32_t idx, uint32_t parent) {
    uint32_t id12 = 0;

    const node_t * node = &nodes[idx];

    


    for (uint32_t i = 0; i < node->edges.len; i++) {
        edge_t * e = &node->edges.ptr[i];
        if (e->to == parent) {
            continue;
        }

        uint32_t num_paths = resolve_edges(edges, nodes, e->to, idx);

        edges[e->edge_idx].w = e->w;
        edges[e->edge_idx].n_children = num_paths;
        edges[e->edge_idx].cost = e->cost;

        id12 += num_paths;
    }

    

    return id12 | !id12;
}


int main(int argc, char * argv[]) {

    int test_cases;
    int n;
    int64_t S;

    assert(fscanf(stdin, "%d", &test_cases) == 1);

    for (int t = 0; t < test_cases; t++) {
        assert(fscanf(stdin, "%d %lld", &n, &S) == 2);

        node_t * nodes = (node_t *) calloc(n, sizeof(node_t));
        val_edge_t * edges = (val_edge_t *) malloc((n - 1) * sizeof(val_edge_t));

        for (int e = 0; e < n - 1; e++) {
            int v, u;
            uint32_t w, c;
            assert(fscanf(stdin, "%d %d %u %u", &v, &u, &w, &c) == 4);

            add_edge(nodes, v - 1, u - 1, w, e, c);
        }

        

        resolve_edges(edges, nodes, 0, n);

        for (int i = 0; i < n; i++) {
            id4(&nodes[i].edges);
        }
        free(nodes);

        uint64_t tot_w = 0;
        uint32_t n_actions = 0;
        heap_t h1;
        heap_t h2;
        heap_init(&h1);
        heap_init(&h2);


        for (int i = 0; i < n - 1; i++) {
            

            tot_w += ((uint64_t) edges[i].w) * ((uint64_t) edges[i].n_children);
            

            edges[i].node.key = -(((heap_key_t) ((edges[i].w + 1) / 2)) * edges[i].n_children);

            if (edges[i].cost == 1) {
                heap_insert(&h1, &edges[i].node);
            }
            else {
                heap_insert(&h2, &edges[i].node);
            }
        }

        


        int_dylist_t l1, l2;
        __builtin_memset(&l1, 0, sizeof(int_dylist_t));
        __builtin_memset(&l2, 0, sizeof(int_dylist_t));

        uint64_t id14 = tot_w;

        while (id14 > S && id18(&h1) != NULL) {
            val_edge_t * e = (val_edge_t *) id5(&h1);

            heap_key_t dif = -e->node.key;

            id16(&l1, dif);

            uint64_t w = e->w;
            const uint64_t n_c = e->n_children;

            id14 -= dif;

            w >>= 1;
            dif = ((heap_key_t) (((w + 1) / 2) * n_c));
            n_actions++;

            e->w = w;
            e->n_children = n_c;
            e->node.key = -dif;
            if (dif > 0) {
                heap_insert(&h1, &e->node);
            }
        }

        uint64_t id6 = tot_w;

        while (id6 > S && id18(&h2) != NULL) {
            val_edge_t * e = (val_edge_t *) id5(&h2);

            heap_key_t dif = -e->node.key;

            id16(&l2, dif);

            uint64_t w = e->w;
            const uint64_t n_c = e->n_children;

            id6 -= dif;

            w >>= 1;
            dif = ((heap_key_t) (((w + 1) / 2) * n_c));
            n_actions++;

            e->w = w;
            e->n_children = n_c;
            e->node.key = -dif;
            if (dif > 0) {
                heap_insert(&h2, &e->node);
            }
        }

        heap_destroy(&h2);
        heap_destroy(&h1);

        free(edges);

        

        int64_t id19 = tot_w - S;

        int64_t tots = (int64_t) (tot_w - id6);
        int64_t min_cost = l1.len + 2 * l2.len;

        uint32_t i1 = 0, i2 = l2.len;
        while (i1 < l1.len && tots < id19) {
            tots += l1.ptr[i1];
            i1++;
        }
        while (1) {
            while (i2 > 0 && (tots - ((int64_t) l2.ptr[i2 - 1])) >= id19) {
                i2--;
                tots -= l2.ptr[i2];
            }
            

            if (tots >= id19) {
                min_cost = min(i1 + 2 * i2, min_cost);
            }
            if (i1 == l1.len) {
                break;
            }
            tots += l1.ptr[i1];
            i1++;
        }

        id0(&l2);
        id0(&l1);

        printf("%lld\n", min_cost);
    }

    return 0;
}

