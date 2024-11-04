








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



heap_node * id14(heap_t *h);


void id6(heap_t *h);


heap_node * id4(heap_t *h);



int heap_insert(heap_t *h, heap_node * node);



int id7(heap_t *h1, heap_t *h2);


int id15(heap_t *h, heap_node * node, heap_key_t new_key);


int id0(heap_t *h, heap_node * node, heap_key_t new_key);


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





static void id9(heap_node * node, heap_node * rchild) {
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

        id9(new_child, lchild);

        

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




static heap_node * id5(heap_node * node) {
    heap_node * lchild = node->lchild;

    if (lchild != node) {
        


        

        heap_node * id13 = RSIB(lchild);

        if (IS_RIGHT_CHILD(lchild)) {
            


            

            HEAP_ASSERT(id13 == node);

            

            node->lchild = node;
            return lchild;
        }
        else if (id13 != node) {
            

            HEAP_ASSERT(IS_RIGHT_CHILD(id13));

            

            

            lchild->rsib = (heap_node *) (((ptr_t) node) | LEFT_CHILD);
            return id13;
        }
    }

    

    

    return NULL;
}



static void _unlink(heap_node * node) {

    

    HEAP_ASSERT(HAS_PARENT(node));

    

    


    int id12 = IS_LEFT_CHILD(node);
    heap_node * rsib = RSIB(node);

    

    

    heap_node * rchild = id5(node);

    if (rsib->lchild == node) {
        

        heap_node * parent = rsib;

        if (rchild != NULL) {
            

            parent->lchild = rchild;

            

            rchild->rsib =
                (heap_node *) (((ptr_t) parent) | id12);
        }
        else {
            

            

            

            parent->lchild = parent;
        }
    }
    else {
        

        


        if (id12) {

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




heap_node * id14(heap_t *h) {
    if (h->root == (heap_node *) h) {
        return NULL;
    }
    return h->root;
}






static heap_node * _delete_root(heap_node * node) {
    heap_node * id8 = NULL;
    heap_node * id2;

    heap_node * child = node->lchild;
    if (child == node) {
        

        return NULL;
    }

    

    

    do {
        heap_node * child2 = _right_child(child);
        if (child2 != NULL) {
            id2 = _right_child(child2);

            

            id5(child);
            id5(child2);

            

            child = _link(child, child2);
        }
        else {
            id2 = NULL;
        }

        

        child->rsib = id8;
        id8 = child;

        child = id2;
    } while (child != NULL);

    

    


    

    child = id8->rsib;
    while (child != NULL) {
        HEAP_ASSERT((((ptr_t) child) & 0x1) == 0);
        id2 = child->rsib;
        id8 = _link(id8, child);
        child = id2;
    }

    return id8;
}



void id6(heap_t *h) {
    heap_node * root = h->root;
    root = _delete_root(root);

    if (root != NULL) {
        _make_root(h, root);
    }
    else {
        h->root = (heap_node *) h;
    }
}


heap_node * id4(heap_t *h) {
    heap_node * min = id14(h);
    if (min != NULL) {
        id6(h);
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



int id7(heap_t *h1, heap_t *h2) {
    heap_node * r1 = id14(h1);
    heap_node * r2 = id14(h2);

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




int id15(heap_t *h, heap_node * node, heap_key_t new_key) {

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



int id0(heap_t *h, heap_node * node, heap_key_t new_key) {

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
        

        

        id6(h);
    }
    else {
        

        

        

        _unlink(node);
        heap_node * id11 = _delete_root(node);

        if (id11 != NULL) {
            

            

            root = _link(root, id11);
        }

        _make_root(h, root);
    }

    return 0;
}





typedef struct edge {
    uint32_t w;
    uint32_t to;
    uint32_t edge_idx;
} edge_t;

typedef struct val_edge {
    heap_node node;
    uint32_t w;
    

    uint32_t n_children;
} val_edge_t;


typedef struct dylist {
    uint32_t len;
    uint32_t cap;
    edge_t * ptr;
} dylist_t;

static void id1(dylist_t * l, edge_t val) {
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

static void id3(dylist_t * l) {
    free(l->ptr);
}


typedef struct node {
    dylist_t edges;

    

    uint32_t par_edge_idx;
} node_t;


static void add_edge(node_t * nodes, uint32_t v, uint32_t u, uint32_t w,
        uint32_t edge_idx) {
    edge_t ev = {
        .w = w,
        .to = u,
        .edge_idx = edge_idx
    };
    edge_t eu = {
        .w = w,
        .to = v,
        .edge_idx = edge_idx
    };
    id1(&nodes[v].edges, ev);
    id1(&nodes[u].edges, eu);
}


static uint32_t resolve_edges(val_edge_t * edges, const node_t * nodes, uint32_t idx, uint32_t parent) {
    uint32_t id10 = 0;

    const node_t * node = &nodes[idx];

    


    for (uint32_t i = 0; i < node->edges.len; i++) {
        edge_t * e = &node->edges.ptr[i];
        if (e->to == parent) {
            continue;
        }

        uint32_t num_paths = resolve_edges(edges, nodes, e->to, idx);

        edges[e->edge_idx].w = e->w;
        edges[e->edge_idx].n_children = num_paths;

        id10 += num_paths;
    }

    

    return id10 | !id10;
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
            uint32_t w;
            assert(fscanf(stdin, "%d %d %u", &v, &u, &w) == 3);

            add_edge(nodes, v - 1, u - 1, w, e);
        }

        

        

        resolve_edges(edges, nodes, 0, n);

        for (int i = 0; i < n; i++) {
            id3(&nodes[i].edges);
        }
        free(nodes);

        uint64_t tot_w = 0;
        uint32_t n_actions = 0;
        heap_t h;
        heap_init(&h);

        for (int i = 0; i < n - 1; i++) {
            tot_w += ((uint64_t) edges[i].w) * ((uint64_t) edges[i].n_children);
            

            edges[i].node.key = -(((heap_key_t) ((edges[i].w + 1) / 2)) * edges[i].n_children);
            heap_insert(&h, &edges[i].node);
        }

        

        while (tot_w > S) {
            val_edge_t * e = (val_edge_t *) id4(&h);

            heap_key_t dif = -e->node.key;

            


            

            


            


            uint64_t w = e->w;
            const uint64_t n_c = e->n_children;

            

                

                


                

                tot_w -= dif;

                


                

                w >>= 1;

                dif = ((heap_key_t) (((w + 1) / 2) * n_c));

                n_actions++;

                

            

            
            e->w = w;
            e->n_children = n_c;
            e->node.key = -dif;
            heap_insert(&h, &e->node);

            if (n_actions == 4999999) {
                printf("%lld, %lld\n", tot_w, dif);
            }

        }

        heap_destroy(&h);

        free(edges);

        printf("%u\n", n_actions);
    }

    return 0;
}
