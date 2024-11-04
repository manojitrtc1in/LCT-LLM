
using namespace std;





std::ostream& PrintFunction(std::ostream& out, int a) {
    return out << a;
}
std::ostream& PrintFunction(std::ostream& out, std::unique_ptr<int> a) {
    return out << *a;
}











template <typename KeyType>
class id1 {
protected:
    struct Node {
        KeyType* key = nullptr;
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;

        Node() = default;
        ~Node() {
            delete key;
        }
        template <typename T>
        Node(T&& my_key, Node* my_parent):
                key(new KeyType(std::forward<T>(my_key))), parent(my_parent){}
        template <typename T>
        void id6(T&& child_key) {
            left = new Node{std::forward<T>(child_key), this};
        }
        template <typename T>
        void id4(T&& child_key) {
            right = new Node{std::forward<T>(child_key), this};
        }
    };

    Node* root = new Node();   


    static Node* successor_(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        } else {
            while (node->parent->right == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }
    static Node* predecessor_(Node* node) {
        

        if (node->left) {
            node = node->left;
            while (node->right) {
                node = node->right;
            }
            return node;
        } else {
            while (node->parent->left == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }

    template <typename T>
    bool search_(T &&key, Node **id3, bool *is_left) const {
        

        

        

        

        *id3 = root->left;
        do {
            if (key < *((*id3)->key)) {
                if((*id3)->left) {
                    *id3 = (*id3)->left;
                } else {
                    *is_left = true;
                    return false;
                }
            } else if (*((*id3)->key) < key) {
                if((*id3)->right) {
                    *id3 = (*id3)->right;
                } else {
                    *is_left = false;
                    return false;
                }
            } else {
                return true;
            }
        } while (true);
    }

    template <typename T>
    Node* find_(T &&key) const {
        if (!root->left) {
            return root;
        }
        Node* id3;
        bool dummy;
        if (search_(std::forward<T>(key), &id3, &dummy)) {
            return id3;
        } else {
            return root;
        }
    }

    template <typename T>
    Node* insert_(T &&key) {
        

        

        if (!root->left) {
            return root->left = new Node{std::forward<T>(key), root};
        }
        Node* id3;
        bool is_left;
        if (search_(std::forward<T>(key), &id3, &is_left)) {

            id3->key = std::forward<T>(key);


            return id3;
        } else {
            return (is_left ? id3->left : id3->right)
                           = new Node{std::forward<T>(key), id3};
        }
    }
    
    Node* min_() const {
        if (!root->left) {
            return root;
        }
        Node* current = root->left;
        while (current->left) {
            current = current->left;
        }
        return current;
    }
    Node* max_() const {
        if (!root->left) {
            return root;
        }
        Node* current = root->left;
        while (current->right) {
            current = current->right;
        }
        return current;
    }
    static void engrow_tree_(Node* donor, Node* acceptor) {
        while (donor) {
            if (donor->left && !acceptor->left) {
                donor = donor->left;
                acceptor->left = new Node{*(donor->key), acceptor};
                acceptor = acceptor->left;
            } else if (donor->right && !acceptor->right) {
                donor = donor->right;
                acceptor->right = new Node{*(donor->key), acceptor};
                acceptor = acceptor->right;
            } else {
                acceptor = acceptor->parent;
                donor = donor->parent;
            }
        }
    }

    void print_(std::ostream& out, Node* subtree_root) const {
        if (subtree_root) {
            out << "[";
            print_(out, subtree_root->left);
            PrintFunction(out, *(subtree_root->key));
            print_(out, subtree_root->right);
            out << "]";
        }
    }
    static bool check_integrity_ (Node* subroot) {
        return (subroot->left == nullptr ||
                (subroot->left->parent == subroot && check_integrity_(subroot->left))
               ) &&
               (subroot->right == nullptr ||
                (subroot->right->parent == subroot && check_integrity_(subroot->right))
               );
    }


public:
    class iterator {
    protected:
        Node* node_;
        explicit iterator(Node* node): node_(node) {}
    public:
        iterator () = default;
        iterator (const iterator&) = default;
        

        iterator& operator++ () {
            node_ = successor_(node_);
            return *this;
        }
        iterator operator++ (int) {
            iterator result(*this);
            ++(*this);
            return result;
        }
        

        iterator& operator-- () {
            node_ = predecessor_(node_);
            return *this;
        }
        iterator operator-- (int) {
            iterator result(*this);
            --(*this);
            return result;
        }
        const KeyType& operator *() {
            return *node_->key;
        }
        const KeyType* operator->() {
            return node_->key;
        }
        bool operator == (const iterator& other) {
            return node_ == other.node_;
        }
        bool operator != (const iterator& other) {
            return node_ != other.node_;
        }
        friend class id1<KeyType>;
    };

    id1() = default;
    

    id1(const id1& other) {
        if (other.root->left) {
            root->left = new Node{*(other.root->left->key), root};
            engrow_tree_(other.root->left, root->left);
        }
    }
    id1& operator=(const id1& other) {
        if (this != &other && other.root->left) {
            clear();
            root->left = new Node{*(other.root->left->key), root};
            engrow_tree_(other.root->left, root->left);
        }
        return *this;
    }
    ~id1() {
        clear();
        delete root;
    }

    void clear() {
        Node* current = root->left;
        if (current) {
            while (current != root) {
                if (current->left) {
                    current = current->left;
                    current->parent->left = nullptr;
                } else if (current->right) {
                    current = current->right;
                    current->parent->right = nullptr;
                } else {
                    auto parent = current->parent;
                    delete current;
                    current = parent;
                }
            }
        }
    }

    template <typename T>
    iterator insert (T&& key) {
        return iterator(insert_(std::forward<T>(key)));
    }
    template <typename T>
    iterator find(T&& key) const {
        return iterator(find_(std::forward<T>(key)));
    }
    iterator begin() const {
        return iterator{min_()};
    }
    iterator end() const {
        return iterator{root};
    }
    template <typename T>
    friend std::ostream& operator << (std::ostream&, const id1<T>&);

    bool check_integrity() {
        return root->left == nullptr && root->parent == nullptr && check_integrity_(root);
    }


};

template <typename KeyType>
std::ostream& operator << (std::ostream& out, const id1<KeyType>& a) {
    a.print_(out, a.root->left);
    return out;
}



template <typename KeyType>
class SplayTree : public id1<KeyType> {
private:
    using typename id1<KeyType>::Node;
    void splay_(Node* node) {
        Node* parent = node->parent;
        Node* the_root = this->root;
        while (parent != the_root) {
            Node* grandparent = parent->parent;
            if (grandparent == the_root) {
                

                node->parent = the_root;
                parent->parent = node;
                this->root->left = node;
                if (node == parent->left) {
                    if (node->right) {
                        node->right->parent = parent;
                    }
                    parent->left = node->right;
                    node->right = parent;
                } else {
                    

                    if (node->left) {
                        node->left->parent = parent;
                    }
                    parent->right = node->left;
                    node->left = parent;
                }
            } else {
                Node* ggparent = grandparent->parent;
                (grandparent == ggparent->left ? ggparent->left : ggparent->right) = node;
                node->parent = ggparent;
                parent->parent = node;
                if (parent == grandparent->left){
                    if (node == parent->left) {
                        

                        grandparent->parent = parent;

                        grandparent->left = parent->right;
                        if (parent->right) {
                            parent->right->parent = grandparent;
                        }

                        parent->left = node->right;
                        if (node->right) {
                            node->right->parent = parent;
                        }

                        parent->right = grandparent;
                        node->right = parent;
                    } else {
                        

                        grandparent->parent = node;

                        parent->right = node->left;
                        if (node->left) {
                            node->left->parent = parent;
                        }

                        grandparent->left = node->right;
                        if (node->right) {
                            node->right->parent = grandparent;
                        }

                        node->left = parent;
                        node->right = grandparent;
                    }
                } else {
                    

                    if (node == parent->right) {
                        

                        grandparent->parent = parent;

                        grandparent->right = parent->left;
                        if (parent->left) {
                            parent->left->parent = grandparent;
                        }

                        parent->right = node->left;
                        if (node->left) {
                            node->left->parent = parent;
                        }

                        parent->left = grandparent;
                        node->left = parent;
                    } else {
                        

                        grandparent->parent = node;

                        parent->left = node->right;
                        if (node->right) {
                            node->right->parent = parent;
                        }

                        grandparent->right = node->left;
                        if (node->left) {
                            node->left->parent = grandparent;
                        }

                        node->right = parent;
                        node->left = grandparent;
                    }
                }
            }
            parent = node->parent;
        }
    }
    void split_(Node* node, SplayTree<KeyType>* left, SplayTree<KeyType>* right) {
        

        splay_(node);
        left->root->left = node->left;
        if (node->left) {
            node->left->parent = left->root;
        }
        right->root->left = node->right;
        if (node->right) {
            node->right->parent = right->root;
        }
        delete node;
        this->root->left = nullptr;
    }
    void merge_(SplayTree<KeyType>* left, SplayTree<KeyType>* right) {
        

        if (right->root->left) {
            right->splay_(right->min_());
            right->root->left->left = left->root->left;
            this->root->left = right->root->left;
            right->root->left = nullptr;
            left->root->left = nullptr;
        } else {
            this->root->left = left->root->left;
            left->root->left = nullptr;
        }
        if (this->root->left) {
            this->root->left->parent = this->root;
        }
    }
public:
    class iterator : public id1<KeyType>::iterator {
    private:
        explicit iterator(Node* node) {
            this->node_ = node;
        }
    public:
        iterator() = default;
        friend class SplayTree<KeyType>;
    };
    template <typename T>
    iterator find (T&& key) {
        if (!this->root->left) {
            return end();
        }
        Node* id3;
        bool branch;
        if (this->search_(std::forward<T>(key), &id3, &branch)) {
            splay_(id3);
            return iterator{id3};
        } else {
            splay_(id3);  

            return end();
        }
    }
    template <typename T>
    iterator insert (T&& key) {
        Node* node_place = this->insert_(std::forward<T>(key));
        this->splay_(node_place);
        return iterator{node_place};
    }
    template <typename T>
    bool erase(T&& key) {
        Node* removable = find(std::forward<T>(key)).node_;
        if (removable != this->root) {
            SplayTree<KeyType> left, right;
            split_(removable, &left, &right);
            merge_(&left, &right);
            return true;
        } else {
            return false;
        }
    }
    template <typename T>
    iterator lower_bound(T&& key) {
        if (!this->root->left) {
            return end();
        }
        Node* best = this->root;
        Node* current = this->root->left;
        do {
            if (key < *(current->key)) {
                best = current;
                if(current->left) {
                    current = current->left;
                } else {
                    return iterator{best};
                }
            } else if (*(current->key) < key) {
                if(current->right) {
                    current = current->right;
                } else {
                    return iterator{best};
                }
            } else {
                return iterator{current};
            }
        } while (true);
    }

    iterator begin() {
        Node* answer = this->min_();
        if (answer != this->root) {
            splay_(answer);
        }
        return iterator{answer};
    }
    iterator end() const {
        return iterator{this->root};
    }
};

template<class ValueType> class Set {
public:
    using iterator = typename SplayTree<ValueType>::iterator;

    Set() = default;
    template <typename InputIt>
    Set(InputIt begin, InputIt end) {
        for (auto i = begin; i != end; ++i, ++size_) {
            data_.insert(*i);
        }
    }
    Set(std::initializer_list<ValueType> args): size_(args.size()) {
        for (const auto& i : args) {
            data_.insert(i);
        }
    }
    Set(const Set& other): data_(other.data_), size_(other.size_) {}
    Set& operator=(const Set& other) {
        data_ = other.data_;
        size_ = other.size_;
        return *this;
    }
    size_t size() const {
        return size_;
    }
    bool empty() const {
        return size_ == 0;
    }
    void insert(const ValueType& key) {
        if (data_.find(key) == data_.end()) {
            data_.insert(key);
            ++size_;
        }
    }
    void erase(const ValueType& key) {
        if (data_.erase(key)) {
            --size_;
        }
    }
    iterator find(const ValueType& key) const {
        return data_.find(key);
    }
    iterator lower_bound(const ValueType& key) const {
        return data_.lower_bound(key);
    }
    iterator begin() const {
        return data_.begin();
    }
    iterator end() const {
        return data_.end();
    }

    void print() {
        std::cout << data_ << std::endl;
        data_.check_integrity();
    }


    ~Set() = default;
private:
    mutable SplayTree<ValueType> data_;
    size_t size_ = 0;
};

typedef long long ll;
typedef long double ld;
typedef set<ll> si;
typedef vector<ll> vi;
typedef pair<int, int> pii;



const ll MOD = 1e9+7;
const ld pi = acos(-1.0);
const ll INF = (unsigned ll)(-1) >> 1;
const ll NINF = -1ll^INF;

template<typename T>
void write_vector(vector<T>& arg){
    for(auto i: arg){
        cout << i << " ";
    }
    cout << endl;
}

class Graph{
public:
    vector<Set<int> > neighbours;
    int size;
    int bfs_start;
    Graph(int vertices=0): size(vertices), bfs_start(0){
        times(size){
            neighbours.push_back(Set<int>());
        }
    }
    void add_vertex(){
        neighbours.push_back(Set<int>());
        size++;
    }
    void add_edge(int v1, int v2){
        neighbours[v1].insert(v2);
    }
    void add_nonor_edge(int v1, int v2){
        neighbours[v1].insert(v2);
        neighbours[v2].insert(v1);
    }
    void read_edges(int edges, int shift=1){
        times(edges){
            int v1, v2;
            cin >> v1 >> v2;
            add_edge(v1-shift, v2-shift);
        }
    }
    void read_nonor_edges(int edges, int shift=1){
        times(edges){
            int v1, v2;
            cin >> v1 >> v2;
            add_nonor_edge(v1-shift, v2-shift);
        }
    }
    bool has_edge(int v1, int v2){
        return neighbours[v1].find(v2)!=neighbours[v1].end();
    }
    int degree(int v){
        return neighbours[v].size();
    }
    friend class bfs;
};


class _generator{
protected:
    int _line;
    _generator(): _line(0) {}
};


                    DATA_TYPE data;\
                    NAME(DATA_TYPE input_data): data(input_data) {}

                        switch(_line) { case 0:;

                        switch(_line) { case 0:;




        do {\
            _line=id0;\
            _rv = (V); return true; case id0:;\
        } while (0)


        do {\
            _line=id0;\
            id2 = (V), id5 = (W); return true; case id0:;\
        } while (0)

$generator(bfs, Graph&)
    queue<int> qu;
    vector<bool> unused;
    int curr, v;
    Set<int>::iterator it;
    $emit(int, int)
        qu.push(data.bfs_start);
        unused.assign(data.size, true);
        unused[data.bfs_start] = false;
        while(!qu.empty()){
            curr = qu.front();
            qu.pop();
            for(it=data.neighbours[curr].begin(); it!=data.neighbours[curr].end(); it++){
                v = *it;
                if(unused[v]){
                    unused[v] = false;
                    qu.push(v);
                    $yield(v, curr);
                }
            }
        }
    $stop


int main(){
    
    try {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    

    long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, w, x, y, z;
    

    cin >> n >> m;
    Graph Bgraph(n), Rgraph(n), total_graph(n);
    times(m) {
        char color;
        cin >> x >> y >> color;
        x--, y--;
        if(color == 'B'){
            Bgraph.add_nonor_edge(x, y);
        }
        else{
            Rgraph.add_nonor_edge(x, y);
        }
        total_graph.add_nonor_edge(x, y);
    }
    vector<vector<int> > savelist;
    times(2) {
        vector<int> colors;
        vector<bool> visited;
        vector<int> lst;
        colors.assign(n, 0);
        visited.assign(n, false);
        lst.clear();
        for(i=0; i<n; ++i){
            if(!visited[i]){
                visited[i] = true;
                vector<int> lists[2] = {{i}, {}};
                bfs mbfs(total_graph);
                total_graph.bfs_start = i;
                for(int vertex, source; mbfs(vertex, source);){
                    visited[vertex] = true;
                    if (Bgraph.has_edge(vertex, source))
                        colors[vertex] = 1 - colors[source];
                    else
                        colors[vertex] = colors[source];
                    lists[colors[vertex]].push_back(vertex);
                    for(auto neighbour : Bgraph.neighbours[vertex])
                        if (visited[neighbour] && colors[neighbour] == colors[vertex])
                            goto fail;
                    for(auto neighbour : Rgraph.neighbours[vertex])
                        if (visited[neighbour] && colors[neighbour] != colors[vertex])
                            goto fail;
                }
                if (lists[0].size() < lists[1].size())
                    l = 0;
                else
                    l = 1;
                lst.insert(lst.end(), lists[l].begin(), lists[l].end());
            }
        }
        savelist.push_back(lst);
fail:   swap(Bgraph, Rgraph);
    }
    if (savelist.size()){
        vector<int>& lst = savelist[0];
        if(savelist.size() == 2 && savelist[1].size() < savelist[0].size())
            lst = savelist[1];
        cout << lst.size() << endl;
        for(auto elem : lst){
            cout << elem+1 << " ";
        }
        return 0;
    }
    cout << -1;

    
    
    }
    catch(const char* str) {
        cerr << "Exception caught: " << str << endl;
    }
    

	return 0;
}