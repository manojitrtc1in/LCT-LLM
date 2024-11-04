


#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <cstring>
#include <unordered_map>

template<typename T, int MAXN = -1>
class RBTree {
public:
    enum Color: bool {
        RED = 1,
        BLACK = 0
    };

    struct Node {
        T key;
        size_t size; 

        bool color;  

        Node *left, *right, *parent;
        Node(T key, Node *parent) : key(key), parent(parent) {
            size = 1;
            color = RED;
            left = right = nullptr;
        }
        Node() {
            size = 1;
            color = RED;
            left = right = nullptr;
        }
        Node &operator=(const Node &rhs) {
            key = rhs.key;
            size = rhs.size;
            color = rhs.color;
            left = rhs.left;
            right = rhs.right;
            parent = rhs.parent;
        }
    }*root = nullptr;
    
    void swapNode(Node *a, Node *b) {
        

        std::swap(a->size, b->size);
        std::swap(a->color, b->color);
        
        if (a->left)
            a->left->parent = b;
        if (b->left)
            b->left->parent = a;
        std::swap(a->left, b->left);

        if (a->right)
            a->right->parent = b;
        if (b->right)
            b->right->parent = a;
        std::swap(a->right, b->right);

        if (a->parent) 

            a->parent->left==a ? (a->parent->left = b) : (a->parent->right = b);
        if (b->parent)
            b->parent->left==b ? (b->parent->left = a) : (b->parent->right = a);
        std::swap(a->parent, b->parent);
    }

private:
    template<int, class = void>
    struct storage{};

    template<int NN>
    struct storage<NN, std::enable_if_t<(NN <= 0)>> {
        Node *alloc(T key, Node *parent) {
            

            return new Node{key, parent};
        }
        void free(Node *p) {
            delete p;
        }
    };

    storage<MAXN> allocator;

    

    

    Node *cw(Node *p);

    

    

    Node* ccw(Node *p);

    size_t count_larger_than(Node *p, const T& key) const;

    size_t count_smaller_than(Node *p, const T& key) const;

    void print_tree(Node *p);

    void askBlack(Node *p);

    template<int NN>
    typename std::enable_if_t<(NN > 0)> destroy(Node *p) {}

    template<int NN>
    typename std::enable_if_t<(NN <= 0)> destroy(Node *p) {
        if (p) destroy<NN>(p->left), destroy<NN>(p->right), allocator.free(p);
    }

public:
    RBTree() = default;
    RBTree(RBTree &&rhs) = delete;

    ~RBTree() {
        destroy<MAXN>(root);
    }

    size_t size() const { return root?root->size:0; }

    Node* insert(T newkey);


    size_t count_larger_than(const T& key) const { return count_larger_than(root, key); }

    size_t count_smaller_than(const T& key) const { return count_smaller_than(root, key); }

    void erase(Node *p);

    void debug() { print_tree(root); }
}; 



template<typename T, int MAXN>
typename RBTree<T, MAXN>::Node* 
RBTree<T, MAXN>::cw(Node *p) {
    Node *tmp = p->left;
    Node *up = p->parent;
    if (up) {
        if (up->left == p)
            up->left = tmp;
        else
            up->right = tmp;
    }
    tmp->parent = up;
    p->parent = tmp;
    p->left = tmp->right;
    if (tmp->right)
        tmp->right->parent = p;

    tmp->right = p;
    p->size = (p->left?p->left->size:0) + (p->right?p->right->size:0) + 1;
    tmp->size = (tmp->left?tmp->left->size:0) + p->size + 1;
    return tmp;
}


template<typename T, int MAXN>
typename RBTree<T, MAXN>::Node* 
RBTree<T, MAXN>::ccw(Node *p) {
        Node *tmp = p->right;
        p->right = tmp->left;
        if (p->right)
            p->right->parent = p;
        tmp->left = p;
        if (p->parent)
            p->parent->left==p? (p->parent->left=tmp): (p->parent->right=tmp);
        tmp->parent = p->parent;
        p->parent = tmp;
        p->size = (p->left?p->left->size:0) + (p->right?p->right->size:0) + 1;
        tmp->size = p->size + (tmp->right?tmp->right->size:0) + 1;
        return tmp;
    }


template<typename T, int MAXN>
typename RBTree<T, MAXN>::Node* RBTree<T, MAXN>::insert(T newkey) {
    

    

    Node *up = nullptr, *p = root, **up2down, *rv;
    while(p != nullptr) {
        p->size++;
        up = p;
        if (newkey < p->key)
            up2down = &p->left, p = p->left;
        else
            up2down = &p->right, p = p->right;
    }
    

    p = allocator.alloc(newkey, up);
    if (up == nullptr)

        root = p;
    else
        *up2down = p;
    rv = p;

    


    

    while(p != root && up != root && p->color == RED) {
        if (up->color == BLACK)
            break;
        

        Node *top = up->parent;
        if (top->left == up) {
            if (top->right && top->right->color == RED) {
                up->color = top->right->color = BLACK;
                top->color = RED;
                p = top; up = p->parent; continue;
            }
            

            if (p == up->right) {
                up = ccw(up);
                p = up->left;
            }

            
            std::swap(top->color, up->color);
            (top==root?root:top) = cw(top);
            break;
        }
        else { 

            if (top->left == nullptr || top->left->color == BLACK) {
                if (p == up->left) {
                    up = cw(up);
                    p = up->right;
                }
                std::swap(up->color, top->color);
                (top==root?root:top) = ccw(top);
                break;
            }
            else {
                top->color = RED;
                top->left->color = top->right->color = BLACK;
                p = top; up = p->parent;
            }
        }
    }

    root->color = BLACK;
    return rv;
}


















template<typename T, int MAXN>
void RBTree<T,MAXN>::askBlack(Node *p) {
    

    

    if (p == root) {
        p->color = BLACK;
        return ;
    }
    Node *up = p->parent;
    Node *sibling = (p==up->left ? up->right : up->left);
    bool at_left = (p == up->left);

    if (sibling == nullptr) {
        if (up->color == BLACK)
            return askBlack(up);
        up->color = BLACK;
        return ;
    }

    

    if (up->color == BLACK && sibling->color == RED) {
        

        at_left?ccw(up):cw(up);
        if (root == up)
            root = up->parent;
        std::swap(up->color, up->parent->color);
        sibling = (at_left ? up->right : up->left);
    }

    

    if (up->color == RED && sibling->color == BLACK
        && (sibling->left?sibling->left->color:BLACK) == BLACK
        && (sibling->right?sibling->right->color:BLACK) == BLACK) {
            

            std::swap(sibling->color, up->color);
            return ;
        }

    

    if (sibling->color == BLACK) {
        Node *s_inner = at_left?sibling->left:sibling->right;
        Node *s_outer = at_left?sibling->right:sibling->left;
        if (s_inner && s_inner->color == RED && (s_outer?s_outer->color==BLACK:true)) {
            

            std::swap(sibling->color, s_inner->color);
            sibling = at_left?cw(sibling):ccw(sibling);
        }
    }

    

    if (sibling->color == BLACK) {
        Node *s_outer = at_left?sibling->right:sibling->left;
        if (s_outer && s_outer->color == RED) {
            

            

            std::swap(sibling->color, up->color);
            s_outer->color = BLACK;
            at_left?ccw(up):cw(up);
            if (root == up)
                

                root = up->parent;
            return ;
        }
    }

    

    if (up->color == BLACK && sibling->color == BLACK &&
        (sibling->left?sibling->left->color==BLACK:true) &&
        (sibling->right?sibling->right->color==BLACK:true)) {
            

            sibling->color = RED;
            return askBlack(up);
        }
}


template<typename T, int MAXN>
void RBTree<T,MAXN>::erase(Node *p) {
    if (p->left && p->right) {
        Node *nxt = p->right;
        while(nxt->left)
            nxt = nxt->left;
        

        swapNode(p, nxt);
        if (root == p)
            root = nxt;
        

    }

    

    Node* progeny = p->left?p->left:(p->right?p->right:nullptr);
    if (p->color == BLACK) {
        if (progeny && progeny->color == RED)
            progeny->color = BLACK;
        else
            

            askBlack(p);
    }

    if (progeny)
        progeny->parent = p->parent;

    if (p->parent) {
        if (p->parent->left == p)
            p->parent->left = progeny;
        else
            p->parent->right = progeny;
        

        for (auto t = p->parent; t; t=t->parent)
            t->size--;
    }
    else
        root = progeny;
    allocator.free(p);
}

template<typename T, int MAXN>
void RBTree<T, MAXN>::print_tree(Node *p) {
    if (!p)
        return ;
    auto fmt = [&](Node *p) {
        std::stringstream ss;
        if (p == nullptr)
            ss<<"NIL";
        else
            ss<<p->key;
        return ss.str();
    };
    std::cout<<"-- " << p->key << (p->color==RED?" RED  ":" BLACK")
        << " >> child=["
        <<fmt(p->left)<<", "
        <<fmt(p->right)<<"]"
        <<"\tup=" << fmt(p->parent)
        <<" size=" <<p->size <<std::endl;
    print_tree(p->left);
    print_tree(p->right);
}


template<typename T, int MAXN>
size_t RBTree<T, MAXN>::count_larger_than(Node *p, const T& key) const {
    if (p == nullptr)
        return 0;
    if (!(key < p->key)) 

        return count_larger_than(p->right, key);
    return count_larger_than(p->left, key) + (p->right?p->right->size:0) + 1;
}


template<typename T, int MAXN>
size_t RBTree<T, MAXN>::count_smaller_than(Node *p, const T& key) const {
    if (p == nullptr)
        return 0;
    

    if (!(p->key < key)) 

        return count_smaller_than(p->left, key);
    return count_smaller_than(p->right, key) + (p->left?p->left->size:0) + 1;
}











using namespace std;

const int MAXN = 200010, MAXQ = 100010;
struct Edge {
    int to;
    Edge *next;
}*head[MAXN];
void addedge(int a, int b) {
    head[a] = new Edge{b, head[a]};
    head[b] = new Edge{a, head[b]};
}




std::list< pair<int, int> > query[MAXN];

int n, qn, c[MAXN], ans[MAXQ];
struct Result {
    struct CPair {
        int color, count;
        bool operator<(const CPair &rhs) const {
            return count < rhs.count;
        }
        bool operator==(const CPair &rhs) const {
            return color == rhs.color && count == rhs.count;
        }
        friend ostream& operator<<(ostream &out, const CPair &rhs) {
            

            return out;
        }
    };
    RBTree<CPair> rbt;
    std::unordered_map<int, RBTree<CPair>::Node*> by_color;
};

Result* dfs(int p, int from) {
    

    Result *now = new Result{};
    now->by_color[c[p]] = now->rbt.insert({c[p], 1});
    for (Edge *e=head[p]; e; e=e->next) 
        if (e->to != from) {
            Result *remote = dfs(e->to, p);
            if (remote->by_color.size() > now->by_color.size())
                swap(remote, now);

            for (auto &[r_col, remote_tnode]: remote->by_color) {
                

                if (now->by_color.find(r_col) != now->by_color.end()) {
                    auto* now_tnode = now->by_color[r_col];
                    int newcount = remote_tnode->key.count + now_tnode->key.count;
                    now->rbt.erase(now_tnode);
                    now->by_color[r_col] = now->rbt.insert(Result::CPair{r_col, newcount});
                }
                else
                    now->by_color[r_col] = now->rbt.insert({r_col, remote_tnode->key.count});

            

            

            

            }

            delete remote;
        }

    

    

    


    for (auto &[qryk, ansidx] : query[p]) {
        int tmp = now->rbt.size() - now->rbt.count_smaller_than({-1, qryk});
        ans[ansidx] = tmp;
        

    }
    return now;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>qn;
    for (int i=1; i<=n; i++)
        cin>>c[i];
    memset(head, 0, sizeof(head));
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        addedge(a, b);
    }
    for (int i=0; i<qn; i++) {
        int p, k;
        cin>>p>>k;
        query[p].push_back({k, i});
    }
    delete dfs(1, -1);
    for (int i=0; i<qn; i++)
        cout<<ans[i]<<endl;
    return 0;
}