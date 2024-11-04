
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef int64_t heap_key_t;

#ifdef __LP64__
typedef uint64_t ptr_t;
#else
typedef uint32_t ptr_t;
#endif

#define HEAP_ASSERT(expr)

typedef struct heap_node {
    struct heap_node * lchild;
    struct heap_node * rsib;
    heap_key_t key;
} heap_node;


#define HEAP_NODE_SET(heap_node, k) \
    ((heap_node)->key = ((heap_key_t) k))


typedef struct min_heap {
    heap_node * root;
} heap_t;



int heap_init(heap_t *h);

void heap_destroy(heap_t *h);



heap_node * heap_find_min(heap_t *h);


void heap_delete_min(heap_t *h);


heap_node * heap_extract_min(heap_t *h);



int heap_insert(heap_t *h, heap_node * node);



int heap_meld(heap_t *h1, heap_t *h2);


int heap_decrease_key(heap_t *h, heap_node * node, heap_key_t new_key);


int heap_increase_key(heap_t *h, heap_node * node, heap_key_t new_key);


int heap_delete(heap_t *h, heap_node * node);



#define LEFT_CHILD 0x1



#define ALIGNMENT_REQUIREMENT 2


#define IS_LEFT_CHILD(heap_node) \
    ((((ptr_t) (heap_node)->rsib) & LEFT_CHILD) != 0)

#define IS_RIGHT_CHILD(heap_node) (!IS_LEFT_CHILD(heap_node))


#define SET_LEFT_CHILD(node) \
    ((node)->rsib = (heap_node *) (((ptr_t) (node)->rsib) | LEFT_CHILD))

#define SET_RIGHT_CHILD(node) \
    ((node)->rsib = (heap_node *) (((ptr_t) (node)->rsib) & ~LEFT_CHILD))








#define HAS_PARENT(heap_node) \
    (((heap_node)->rsib) != NULL)

#define RSIB(node) \
    ((heap_node*) (((ptr_t) (node)->rsib) & ~LEFT_CHILD))


#define IS_ALIGNED(ptr) \
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





static void __add_right_child(heap_node * node, heap_node * rchild) {
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

        __add_right_child(new_child, lchild);

        

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




static heap_node * __unlink_from_rchild(heap_node * node) {
    heap_node * lchild = node->lchild;

    if (lchild != node) {
        


        

        heap_node * l_rsib = RSIB(lchild);

        if (IS_RIGHT_CHILD(lchild)) {
            


            

            HEAP_ASSERT(l_rsib == node);

            

            node->lchild = node;
            return lchild;
        }
        else if (l_rsib != node) {
            

            HEAP_ASSERT(IS_RIGHT_CHILD(l_rsib));

            

            

            lchild->rsib = (heap_node *) (((ptr_t) node) | LEFT_CHILD);
            return l_rsib;
        }
    }

    

    

    return NULL;
}



static void _unlink(heap_node * node) {

    

    HEAP_ASSERT(HAS_PARENT(node));

    

    


    int node_is_left_child = IS_LEFT_CHILD(node);
    heap_node * rsib = RSIB(node);

    

    

    heap_node * rchild = __unlink_from_rchild(node);

    if (rsib->lchild == node) {
        

        heap_node * parent = rsib;

        if (rchild != NULL) {
            

            parent->lchild = rchild;

            

            rchild->rsib =
                (heap_node *) (((ptr_t) parent) | node_is_left_child);
        }
        else {
            

            

            

            parent->lchild = parent;
        }
    }
    else {
        

        


        if (node_is_left_child) {

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




heap_node * heap_find_min(heap_t *h) {
    if (h->root == (heap_node *) h) {
        return NULL;
    }
    return h->root;
}






static heap_node * _delete_root(heap_node * node) {
    heap_node * prev_subtree = NULL;
    heap_node * next_subtree;

    heap_node * child = node->lchild;
    if (child == node) {
        

        return NULL;
    }

    

    

    do {
        heap_node * child2 = _right_child(child);
        if (child2 != NULL) {
            next_subtree = _right_child(child2);

            

            __unlink_from_rchild(child);
            __unlink_from_rchild(child2);

            

            child = _link(child, child2);
        }
        else {
            next_subtree = NULL;
        }

        

        child->rsib = prev_subtree;
        prev_subtree = child;

        child = next_subtree;
    } while (child != NULL);

    

    


    

    child = prev_subtree->rsib;
    while (child != NULL) {
        HEAP_ASSERT((((ptr_t) child) & 0x1) == 0);
        next_subtree = child->rsib;
        prev_subtree = _link(prev_subtree, child);
        child = next_subtree;
    }

    return prev_subtree;
}



void heap_delete_min(heap_t *h) {
    heap_node * root = h->root;
    root = _delete_root(root);

    if (root != NULL) {
        _make_root(h, root);
    }
    else {
        h->root = (heap_node *) h;
    }
}


heap_node * heap_extract_min(heap_t *h) {
    heap_node * min = heap_find_min(h);
    if (min != NULL) {
        heap_delete_min(h);
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



int heap_meld(heap_t *h1, heap_t *h2) {
    heap_node * r1 = heap_find_min(h1);
    heap_node * r2 = heap_find_min(h2);

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




int heap_decrease_key(heap_t *h, heap_node * node, heap_key_t new_key) {

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



int heap_increase_key(heap_t *h, heap_node * node, heap_key_t new_key) {

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
        

        

        heap_delete_min(h);
    }
    else {
        

        

        

        _unlink(node);
        heap_node * new_subtree = _delete_root(node);

        if (new_subtree != NULL) {
            

            

            root = _link(root, new_subtree);
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

static void dylist_push(dylist_t * l, edge_t val) {
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

static void dylist_delete(dylist_t * l) {
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
    dylist_push(&nodes[v].edges, ev);
    dylist_push(&nodes[u].edges, eu);
}


static uint32_t resolve_edges(val_edge_t * edges, const node_t * nodes, uint32_t idx, uint32_t parent) {
    uint32_t num_paths_thru = 0;

    const node_t * node = &nodes[idx];

    


    for (uint32_t i = 0; i < node->edges.len; i++) {
        edge_t * e = &node->edges.ptr[i];
        if (e->to == parent) {
            continue;
        }

        uint32_t num_paths = resolve_edges(edges, nodes, e->to, idx);

        edges[e->edge_idx].w = e->w;
        edges[e->edge_idx].n_children = num_paths;

        num_paths_thru += num_paths;
    }

    

    return num_paths_thru | !num_paths_thru;
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
            dylist_delete(&nodes[i].edges);
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
            val_edge_t * e = (val_edge_t *) heap_extract_min(&h);

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

