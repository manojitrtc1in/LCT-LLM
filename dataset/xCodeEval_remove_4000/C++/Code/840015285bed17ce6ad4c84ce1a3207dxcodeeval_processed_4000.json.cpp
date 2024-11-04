













 




 


 










 


 










 




 






 




 




 








 






 










 




 












 




 


 




 


 












 


 


 




 


 











































































































































































































using namespace std;



template<class Fun> class id4 {
    Fun fun_;
public:
    template<class T> explicit id4(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) id6(Fun &&fun) { return id4<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }



















































































































































































using T = int;

struct splay_node {
    splay_node *parent = nullptr, *child[2] = {nullptr, nullptr};
    int size = 1;

    T value;

    friend int get_size(splay_node *x) {
        return x == nullptr ? 0 : x->size;
    }

    int parent_index() const {
        return parent == nullptr ? -1 : int(this == parent->child[1]);
    }

    void set_child(int index, splay_node *x) {
        child[index] = x;

        if (x != nullptr)
            x->parent = this;
    }

    void join() {
        size = get_size(child[0]) + get_size(child[1]) + 1;
    }
};

namespace splay_tree {
    const int POOL_SIZE = 10000;
    vector<splay_node*> node_pool;
    vector<splay_node*> id9;
    int64_t id5 = 0;

    splay_node* new_node(const T &value) {
        if (node_pool.empty()) {
            splay_node *ptr = new splay_node[POOL_SIZE];
            id9.push_back(ptr);
            node_pool.reserve(POOL_SIZE);

            for (int i = POOL_SIZE - 1; i >= 0; i--)
                node_pool.push_back(ptr + i);
        }

        splay_node *node = node_pool.back();
        node_pool.pop_back();
        *node = splay_node();
        node->value = value;
        node->join();
        return node;
    }

    bool id10 = false;

    void id3() {
        for (splay_node *node : id9)
            delete[] node;

        id9.clear();
    }

    void init() {
        if (!id10) {
            atexit(id3);
            id10 = true;
        }
    }

    splay_node *construct(const vector<splay_node *> &nodes, int start, int end) {
        if (start >= end)
            return nullptr;

        if (end - start == 1)
            return nodes[start];

        int mid = (start + end) / 2;
        splay_node *current = nodes[mid];
        current->set_child(0, construct(nodes, start, mid));
        current->set_child(1, construct(nodes, mid + 1, end));
        current->join();
        return current;
    }

    

    splay_node *build(const vector<splay_node *> &nodes) {
        return construct(nodes, 0, int(nodes.size()));
    }

    splay_node *set_root(splay_node *x) {
        if (x != nullptr)
            x->parent = nullptr;

        return x;
    }

    bool is_root(splay_node *x) {
        return x == nullptr || x->parent == nullptr;
    }

    void rotate_up(splay_node *x, bool x_join = true) {
        splay_node *p = x->parent, *gp = p->parent;
        int index = x->parent_index();

        if (gp == nullptr)
            set_root(x);
        else
            gp->set_child(p->parent_index(), x);

        p->set_child(index, x->child[!index]);
        x->set_child(!index, p);
        p->join();

        if (x_join)
            x->join();
    }

    

    void splay(splay_node *x) {
        if (x == nullptr)
            return;

        id5++;

        while (!is_root(x)) {
            splay_node *p = x->parent;

            if (!is_root(p))
                rotate_up(x->parent_index() == p->parent_index() ? p : x, false);

            rotate_up(x, false);
        }

        x->join();
    }

    int get_index(splay_node *node) {
        splay(node);
        return get_size(node->child[0]);
    }

    int id1(splay_node *node) {
        splay(node);
        return get_size(node);
    }

    splay_node *id7(splay_node *root, int index) {
        assert(is_root(root));

        if (index < 0 || index >= get_size(root))
            return nullptr;

        splay_node *current = root;

        while (current != nullptr) {
            int left_size = get_size(current->child[0]);

            if (index == left_size) {
                splay(current);
                return current;
            }

            if (index < left_size) {
                current = current->child[0];
            } else {
                current = current->child[1];
                index -= left_size + 1;
            }
        }

        assert(false);
    }

    splay_node *insert(splay_node *root, int index, splay_node *node) {
        assert(is_root(root) && is_root(node));
        assert(0 <= index && index <= get_size(root));

        if (node == nullptr)
            return nullptr;
        else if (root == nullptr)
            return set_root(node);

        splay_node *current = root, *previous = nullptr;
        int previous_dir = -1;

        while (current != nullptr) {
            previous = current;
            int left_size = get_size(current->child[0]);

            if (index <= left_size) {
                current = current->child[0];
                previous_dir = 0;
            } else {
                current = current->child[1];
                previous_dir = 1;
                index -= left_size + 1;
            }
        }

        previous->set_child(previous_dir, node);
        splay(node);
        return node;
    }

    

    void detach(splay_node *x) {
        if (x == nullptr)
            return;

        if (is_root(x)) {
            set_root(nullptr);
            return;
        }

        splay_node *parent = x->parent;
        assert(parent != nullptr);
        parent->set_child(x->parent_index(), nullptr);
        x->parent = nullptr;
        splay(parent);
    }

    

    splay_node *id2(splay_node *root, int count) {
        assert(is_root(root));

        if (count <= 0)
            return nullptr;
        else if (count >= get_size(root))
            return root;

        splay_node *node = id7(root, count);
        splay(node);
        return node->child[0];
    }

    

    splay_node *id0(splay_node *root, int count) {
        assert(is_root(root));

        if (count >= get_size(root))
            return root;
        else if (count <= 0)
            return nullptr;

        int index = get_size(root) - count;
        splay_node *node = id7(root, index - 1);
        splay(node);
        return node->child[1];
    }

    

    splay_node *query_range(splay_node *root, int start, int end) {
        assert(is_root(root));

        if (start >= end)
            return nullptr;
        else if (start <= 0)
            return id2(root, end);
        else if (end >= get_size(root))
            return id0(root, get_size(root) - start);

        splay_node *before = id7(root, start - 1);
        splay_node *after = id7(root, end);
        splay(after);
        splay(before);

        if (after->parent != before)
            rotate_up(after);

        assert(before->child[1] == after);
        return after->child[0];
    }

    void print_tree(splay_node *x, int depth = 0) {
        cerr << string(depth, ' ');

        if (x == nullptr) {
            cerr << "null" << endl;
            return;
        }

        cerr << x->value << " (" << x->size << ")\n";

        if (x->child[0] != nullptr || x->child[1] != nullptr) {
            print_tree(x->child[0], depth + 1);
            print_tree(x->child[1], depth + 1);
        }
    }
};


struct id8 {
    int n;
    vector<splay_node *> nodes;
    vector<int> P;

    id8(int _n = 0) {
        init(_n);
    }

    id8(const vector<int> &_P) {
        init(_P);
    }

    void init(int _n) {
        splay_tree::init();
        n = _n;
        P.resize(n);
        iota(P.begin(), P.end(), 0);
        nodes.resize(n);

        for (int i = 0; i < n; i++)
            nodes[i] = splay_tree::new_node(i);
    }

    void init(const vector<int> &_P) {
        splay_tree::init();
        init(int(_P.size()));
        P = _P;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
            if (!visited[i]) {
                vector<splay_node *> cycle;
                int x = i;

                do {
                    cycle.push_back(nodes[x]);
                    visited[x] = true;
                    x = P[x];
                } while (x != i);

                splay_tree::build(cycle);
            }
    }

    

    void p_swap(int x, int y) {
        assert(0 <= min(x, y) && max(x, y) < n);

        if (x == y)
            return;

        swap(P[x], P[y]);
        int x_index = splay_tree::get_index(nodes[x]);
        int y_index = splay_tree::get_index(nodes[y]);

        if (x_index > y_index) {
            swap(x, y);
            swap(x_index, y_index);
        }

        splay_tree::splay(nodes[y]);
        splay_tree::splay(nodes[x]);

        

        

        if (!splay_tree::is_root(nodes[y])) {
            if (nodes[y]->parent != nodes[x])
                splay_tree::rotate_up(nodes[y]);

            splay_tree::detach(nodes[y]);
            splay_node *y_right = nodes[y]->child[1];
            splay_tree::detach(y_right);
            splay_tree::insert(nodes[x], splay_tree::id1(nodes[x]), y_right);
            return;
        }

        

        

        splay_node *x_right = nodes[x]->child[1];
        splay_node *y_right = nodes[y]->child[1];
        splay_tree::detach(x_right);
        splay_tree::detach(y_right);
        splay_tree::insert(nodes[x], splay_tree::id1(nodes[x]), y_right);
        splay_tree::insert(nodes[y], splay_tree::id1(nodes[y]), x_right);
        splay_tree::splay(nodes[x]);
        splay_tree::splay(nodes[y]);
        splay_tree::insert(nodes[y], 0, nodes[x]);
    }

    

    int get_node_at_offset(int x, int64_t k) {
        int index = splay_tree::get_index(nodes[x]);
        index = int((index + k) % splay_tree::id1(nodes[x]));
        return splay_tree::id7(nodes[x], index)->value;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin>>N>>Q;
    vector<int> P(N);
    for(auto& p:P){
        cin>>p;
        p--;
    }
    id8 cycles(P);
    for(int q = 0; q < Q; q++){
        int type;
        cin>>type;
        if(type == 1){
            int x, y;
            cin>>x>>y;
            x--;y--;
            cycles.p_swap(x, y);
        }
        else{
            int x, k;
            cin>>x>>k;
            x--;
            cout<<cycles.get_node_at_offset(x, k) + 1<<'\n';
        }
    }
}


























































