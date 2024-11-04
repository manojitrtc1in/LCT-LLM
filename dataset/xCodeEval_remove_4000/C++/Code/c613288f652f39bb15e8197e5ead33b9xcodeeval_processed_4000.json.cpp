


namespace stlb
{

    template<class T>
    class fib_queue
    {

    private:

        struct node_t
        {
            const T key;
            node_t* next;
            node_t* child;
            size_t deg;

            node_t(const T& key) : key(key) {
                next = this;
                child = nullptr;
                deg = 0;
            }
        };

        node_t* _root;
        size_t _size;

        node_t *const merge_(node_t *const ptr1, node_t *const ptr2) const {
            if (ptr1 == nullptr) {
                return ptr2;
            }
            else if (ptr2 == nullptr) {
                return ptr1;
            }
            else {
                std::swap(ptr1->next, ptr2->next);
                return ptr1->key < ptr2->key ? ptr1 : ptr2;
            }
        }

        void consolidate_() {
            size_t max_size = std::floor(std::log(_size)/std::log((1+std::sqrt(5))/2.0));
            std::vector<node_t*> arr(max_size+2, nullptr);
            for (node_t* tmp = _root; tmp != nullptr;) {
                node_t *const next = tmp->next;
                tmp->next = tmp;
                while (arr[tmp->deg] != nullptr) {
                    node_t* up;
                    node_t* down;
                    if (tmp->key < arr[tmp->deg]->key) {
                        up = tmp, down = arr[tmp->deg];
                    }
                    else {
                        up = arr[tmp->deg], down = tmp;
                    }
                    arr[tmp->deg] = nullptr;
                    up->child = merge_(up->child, down);
                    up->deg++;
                    tmp = up;
                }
                arr[tmp->deg] = tmp;
                tmp = next;
            }
            _root = nullptr;
            for (node_t* tmp : arr) {
                _root = merge_(_root, tmp);
            }
        }

        void clear_(const node_t *const ptr) const {
            if (ptr != nullptr) {
                const node_t* tmp = ptr;
                do {
                    const node_t* const next = tmp->next;
                    clear_(tmp->child);
                    delete tmp;
                    tmp = next;
                } while (tmp != ptr);
            }
        }

    public:

        fib_queue() {
            _root = nullptr;
            _size = 0;
        }

        ~fib_queue() {
            clear();
        }

        const size_t size() const {
            return _size;
        }

        const T& top() const {
            return _root->key;
        }

        const bool empty() const {
            return _size == 0;
        }

        void clear() {
            clear_(_root);
            _root = nullptr;
            _size = 0;
        }

        void push(const T& key) {
            _root = merge_(_root, new node_t(key));
            _size++;
        }

        void pop() {
            if (_size == 1) {
                delete _root;
                _root = nullptr;
            }
            else {
                merge_(_root, _root->child);
                node_t *const new_root = _root->next;
                node_t* tmp = _root->next;
                while (tmp->next != _root) {
                    tmp = tmp->next;
                }
                tmp->next = nullptr;
                delete _root;
                _root = new_root;
                consolidate_();
            }
            _size--;
        }
        
    };
    

    template<class T>
    class fib_heap
    {

    private:

        struct node_t
        {
            T key;
            node_t* left;
            node_t* right;
            node_t* child;
            node_t* parent;
            size_t deg;
            bool mark;

            node_t(const T& key) : key(key) {
                left = this;
                right = this;
                child = nullptr;
                parent = nullptr;
                deg = 0;
                mark = false;
            }
        };

        node_t* _root;
        size_t _size;

        node_t *const merge_(node_t *const ptr1, node_t *const ptr2) const {
            if (ptr1 == nullptr) {
                return ptr2;
            }
            else if (ptr2 == nullptr) {
                return ptr1;
            }
            else {
                std::swap(ptr1->right->left, ptr2->right->left);
                std::swap(ptr1->right, ptr2->right);
                return ptr1->key < ptr2->key ? ptr1 : ptr2;
            }
        }

        void cut_(node_t *const ptr) {
            if (ptr->parent != nullptr) {
                node_t *const L = ptr->left;
                node_t *const R = ptr->right;
                L->right = R;
                R->left = L;
                if (ptr->parent != nullptr) {
                    ptr->parent->deg--;
                    ptr->parent->child = R == ptr ? nullptr : R;
                }
                ptr->left = ptr;
                ptr->right = ptr;
                ptr->parent = nullptr;
                _root = merge_(_root, ptr);
            }
            ptr->mark = false;
        }

        void cascading_cut_(node_t* ptr) {
            while (ptr != nullptr) {
                if (ptr->mark == false) {
                    ptr->mark = true;
                    break;
                }
                else {
                    node_t *const parent = ptr->parent;
                    cut_(ptr);
                    ptr = parent;
                }
            }
        }

        void consolidate_() {
            _root->left->right = nullptr;
            size_t max_size = std::floor(std::log(_size)/std::log((1+std::sqrt(5))/2.0));
            std::vector<node_t*> arr(max_size+2, nullptr);
            for (node_t* tmp = _root; tmp != nullptr;) {
                node_t *const next = tmp->right;
                tmp->left = tmp;
                tmp->right = tmp;
                tmp->parent = nullptr;
                while (arr[tmp->deg] != nullptr) {
                    node_t* up;
                    node_t* down;
                    if (tmp->key < arr[tmp->deg]->key) {
                        up = tmp, down = arr[tmp->deg];
                    }
                    else {
                        up = arr[tmp->deg], down = tmp;
                    }
                    arr[tmp->deg] = nullptr;
                    down->parent = up;
                    up->child = merge_(up->child, down);
                    up->deg++;
                    tmp = up;
                }
                arr[tmp->deg] = tmp;
                tmp = next;
            }
            _root = nullptr;
            for (node_t* tmp : arr) {
                _root = merge_(_root, tmp);
            }
        }

        void clear_(const node_t *const ptr) const {
            if (ptr != nullptr) {
                ptr->left->right = nullptr;
                const node_t* tmp = ptr;
                while (tmp != nullptr) {
                    const node_t* const next = tmp->right;
                    clear_(tmp->child);
                    delete tmp;
                    tmp = next;
                }
            }
        }

    public:

        class pointer
        {

            friend class fib_heap;

        private:

            node_t* ptr;

        public:

            pointer() : ptr(nullptr) {}

            pointer(node_t *const ptr) : ptr(ptr) {}

            const pointer& operator=(const pointer& other) {
                ptr = other.ptr;
                return *this;
            }

            const T& operator*() const {
                return ptr->key;
            }

        };

        fib_heap() {
            _root = nullptr;
            _size = 0;
        }

        ~fib_heap() {
            clear();
        }

        const size_t size() const {
            return _size;
        }

        const T& top() const {
            return _root->key;
        }

        const bool empty() const {
            return _size == 0;
        }

        void clear() {
            clear_(_root);
            _root = nullptr;
            _size = 0;
        }

        pointer push(const T& key) {
            node_t *const new_node = new node_t(key);
            _root = merge_(_root, new_node);
            _size++;
            return pointer(new_node);
        }

        void pop() {
            if (_size == 1) {
                delete _root;
                _root = nullptr;
            }
            else {
                merge_(_root, _root->child);
                node_t *const new_root = _root->right;
                _root->left->right = _root->right;
                _root->right->left = _root->left;
                delete _root;
                _root = new_root;
                consolidate_();
            }
            _size--;
        }

        void decrease_key(pointer& node, const T& key) {
            node.ptr->key = key;
            node_t *const parent = node.ptr->parent;
            if (parent != nullptr && key < parent->key) {
                cut_(node.ptr);
                cascading_cut_(parent);
            }
            else if (key < _root->key) {
                _root = node.ptr;
            }
        }
        
    };


    template<class weight = void>
    class id5
    {

    private:

        std::vector<std::vector<std::pair<size_t, weight>>> _graph;
        size_t _vertices_count = 0;
        size_t _edges_count = 0;

    public:

        id5(size_t N = 0) {
            resize(N);
        }

        void clear() {
            _graph.clear();
            _vertices_count = 0;
        }

        void resize(size_t size) {
            if (_vertices_count < size) {
                _vertices_count = size;
                _graph.resize(size);
            }
        }

        const size_t size() const {
            return _vertices_count;
        }

        const size_t edges_count() const {
            return _edges_count;
        }

        void add_edge(const size_t from, const size_t to, weight w) {
            resize(from > to ? from : to);
            _graph[from].push_back(std::make_pair(to, w));
            _graph[to].push_back(std::make_pair(from, w));
            _edges_count++;
        }

        std::vector<std::pair<size_t, weight>> get_next_vertices(const size_t vertex) const {
            return _graph[vertex];
        }

    };


    template<class weight>
    auto id4(const id5<weight>& graph, const size_t start) {
        std::vector<std::pair<weight, size_t>> dist(
            graph.size(),
            std::make_pair(weight(), -1)
        );

        std::vector<bool> used(graph.size(), false);
        std::vector<bool> inf(graph.size(), true);
        inf[start] = false;
        size_t used_count = 1;

        while (used_count++ < graph.size()) {
            size_t v = -1;
            for (size_t i = 0; i < graph.size(); i++) {
                if (!inf[i] && !used[i] && (v == -1 || dist[i] < dist[v])) {
                    v = i;
                }
            }
            if (v == -1) {
                return dist;
            }
            used[v] = true;
            for (const auto& u : graph.get_next_vertices(v)) {
                if (inf[u.first] || dist[v].first + u.second < dist[u.first].first) {
                    inf[u.first] = false;
                    dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                }
            }
        }

        return dist;
    }


    template<class weight>
    auto id3(const id5<weight>& graph, const size_t start) {
        std::vector<std::pair<weight, size_t>> dist(
            graph.size(),
            std::make_pair(weight(), -1)
        );

        std::vector<bool> used(graph.size(), false);
        std::vector<bool> inf(graph.size(), true);
        std::priority_queue<
            std::pair<weight, size_t>,
            std::vector<std::pair<weight, size_t>>,
            std::greater<std::pair<weight, size_t>>
        > q;
        inf[start] = false;
        q.push(std::make_pair(weight(), start));

        while (!q.empty()) {
            size_t v = q.top().second; q.pop();
            if (!used[v]) {
                used[v] = true;
                for (const auto& u : graph.get_next_vertices(v)) {
                    if (inf[u.first] || dist[v].first + u.second < dist[u.first].first) {
                        inf[u.first] = false;
                        dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                        q.push(std::make_pair(dist[u.first].first, u.first));
                    }
                }
            }
        }

        return dist;
    }


    template<class weight>
    auto id1(const id5<weight>& graph, const size_t start) {
        std::vector<std::pair<weight, size_t>> dist(
            graph.size(),
            std::make_pair(weight(), -1)
        );

        std::vector<bool> inf(graph.size(), true);
        std::vector<
            typename fib_heap<std::pair<weight, size_t>
        >::pointer> ptrs(graph.size());
        fib_heap<std::pair<weight, size_t>> q;
        inf[start] = false;
        ptrs[start] = q.push(std::make_pair(weight(), start));

        while (!q.empty()) {
            size_t v = q.top().second; q.pop();
            for (const auto& u : graph.get_next_vertices(v)) {
                if (inf[u.first]) {
                    inf[u.first] = false;
                    dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                    ptrs[u.first] = q.push(std::make_pair(dist[u.first].first, u.first));
                }
                else if (dist[v].first + u.second < dist[u.first].first) {
                    dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                    q.decrease_key(ptrs[u.first], std::make_pair(dist[u.first].first, u.first));
                }
            }
        }

        return dist;
    }


    template<class weight>
    auto id2(const id5<weight>& graph, const size_t start) {
        std::vector<std::pair<weight, size_t>> dist(
            graph.size(),
            std::make_pair(weight(), -1)
        );

        std::vector<bool> used(graph.size(), false);
        std::vector<bool> inf(graph.size(), true);
        fib_queue<std::pair<weight, size_t>> q;
        inf[start] = false;
        q.push(std::make_pair(weight(), start));

        while (!q.empty()) {
            size_t v = q.top().second; q.pop();
            if (!used[v]) {
                used[v] = true;
                for (const auto& u : graph.get_next_vertices(v)) {
                    if (inf[u.first] || dist[v].first + u.second < dist[u.first].first) {
                        inf[u.first] = false;
                        dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                        q.push(std::make_pair(dist[u.first].first, u.first));
                    }
                }
            }
        }

        return dist;
    }


    template<class weight>
    auto id0(const id5<weight>& graph, const size_t start) {
        struct edge_t {
            size_t x, y;
            weight w;
        };

        std::vector<edge_t> edges;
        for (size_t i = 0; i < graph.size(); i++) {
            for (const auto& j : graph.get_next_vertices(i)) {
                edges.push_back({ i, j.first, j.second });
            }
        }

        std::vector<bool> inf(graph.size(), true);
        std::vector<std::pair<weight, size_t>> dist(
            graph.size(),
            std::make_pair(weight(), -1)
        );
        inf[start] = false;

        while (true) {
            bool updated = false;
            for (const auto& e : edges) {
                if (!inf[e.x]) {
                    if (inf[e.y] || dist[e.x].first + e.w < dist[e.y].first) {
                        inf[e.y] = false;
                        dist[e.y] = std::make_pair(dist[e.x].first + e.w, e.x);
                        updated = true;
                    }
                }
            }
            if (!updated) {
                break;
            }
        }

        return dist;
    }


    template<class weight>
    auto SPFA(const id5<weight>& graph, const size_t start) {
        std::vector<bool> in_queue(graph.size(), false);
        std::vector<bool> inf(graph.size(), true);
        std::vector<std::pair<weight, size_t>> dist(
            graph.size(),
            std::make_pair(weight(), -1)
        );
        std::queue<size_t> q;

        q.push(start);
        inf[start] = false;
        in_queue[start] = true;
        while (!q.empty()) {
            size_t v = q.front(); q.pop();
            in_queue[v] = false;
            for (const auto& u : graph.get_next_vertices(v)) {
                if (inf[u.first] || dist[v].first + u.second < dist[u.first].first) {
                    inf[u.first] = false;
                    dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                    if (!in_queue[u.first]) {
                        in_queue[u.first] = true;
                        q.push(u.first);
                    }
                }
            }
        }

        return dist;
    }


    template<class weight>
    auto id6(const id5<weight>& graph, const size_t start) {
        std::vector<std::pair<weight, size_t>> dist(
            graph.size(),
            std::make_pair(weight(), -1)
        );

        std::vector<bool> inf(graph.size(), true);
        std::set<std::pair<weight, size_t>> q;
        inf[start] = false;
        q.insert(std::make_pair(weight(), start));

        while (!q.empty()) {
            size_t v = q.begin()->second; q.erase(q.begin());
            for (const auto& u : graph.get_next_vertices(v)) {
                if (inf[u.first]) {
                    inf[u.first] = false;
                    dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                    q.insert(std::make_pair(dist[u.first].first, u.first));
                }
                else if (dist[v].first + u.second < dist[u.first].first) {
                    q.erase(std::make_pair(dist[u.first].first, u.first));
                    dist[u.first] = std::make_pair(dist[v].first + u.second, v);
                    q.insert(std::make_pair(dist[u.first].first, u.first));
                }
            }
        }

        return dist;
    }

}


int fr()
{
	char t = _getchar_nolock();
	int to = 0;
	while (t > 47) { to = 10*to + t - 48; t = _getchar_nolock(); }
	return to;
}
void fw(const size_t what)
{
	if (what > 9) fw(what / 10);
	_putchar_nolock(what % 10 + 48);
}

void path(std::vector<std::pair<long long, size_t>>& ans, size_t x) {
    if (ans[x].second != -1) {
        path(ans, ans[x].second);
    }
    fw(x+1);
    _putchar_nolock(' ');
}

int main() {
    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    

    int n = fr();
    int m = fr();
    stlb::id5<long long> g(n);
    for (int i = 0; i < m; i++) {
        int a = fr();
        int b = fr();
        int c = fr();
        g.add_edge(a-1, b-1, c);
    }
    
    std::vector<std::pair<long long, size_t>> ans = stlb::id6(g, 0);
    if (ans[n-1].second == -1) {
        puts("-1");
    }
    else {
        path(ans, n-1);
    }
}