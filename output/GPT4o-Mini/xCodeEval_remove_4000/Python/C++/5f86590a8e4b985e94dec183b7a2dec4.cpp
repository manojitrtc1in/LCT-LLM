#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <limits>
#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>

using namespace std;

class id17 {
public:
    id17* prev;
    id17* next;

    id17() : prev(nullptr), next(nullptr) {}

    id17* connect(id17* node) {
        this->next = node;
        node->prev = this;
        return node;
    }

    id17* splice(id17* fragment) {
        if (fragment->prev) fragment->prev->next = nullptr;

        id17* u = this;
        id17* v = fragment;
        id17* w = this->next;

        u->connect(v);
        while (v->next) v = v->next;
        v->connect(w);

        return v;
    }

    void splice1(id17* node) {
        node->connect(this->next);
        this->connect(node);
    }

    void eject() {
        this->prev->connect(this->next);
    }

    class iterator {
        id17* current;
        id17* start;

    public:
        iterator(id17* start) : current(start), start(start) {}

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        id17& operator*() const {
            return *current;
        }

        iterator& operator++() {
            current = current->next;
            if (!current || current == start) current = nullptr;
            return *this;
        }
    };

    iterator begin() {
        return iterator(this);
    }

    iterator end() {
        return iterator(nullptr);
    }
};

class AbstractHeap {
public:
    virtual ~AbstractHeap() = default;
    virtual bool id6() = 0;
    virtual int id18() = 0;
    virtual bool id14(int value) = 0;
    virtual int id21(int value) = 0;
    virtual void push(int key, int value) = 0;
    virtual pair<int, int> pop() = 0;
    virtual void id28(int value, int key) = 0;
    virtual void merge(AbstractHeap* other) = 0;
};

class id13 : public id17 {
public:
    int key;
    int value;
    id13* parent;
    id13* child;
    int degree;
    bool mark;

    id13(int key, int value) : key(key), value(value), parent(nullptr), child(nullptr), degree(0), mark(false) {}
};

class id0 : public AbstractHeap {
    int _n;
    id13* _root;
    unordered_map<int, id13*> _index;

public:
    id0(const vector<pair<int, int>>& iterable) : _n(0), _root(nullptr) {
        for (const auto& [k, v] : iterable) {
            push(k, v);
        }
    }

    bool id6() override {
        return _n > 0;
    }

    int id18() override {
        return _n;
    }

    bool id14(int value) override {
        return _index.find(value) != _index.end();
    }

    int id21(int value) override {
        return _index[value]->key;
    }

    void push(int key, int value) override {
        id13* node = new id13(key, value);
        _index[value] = node;

        if (_root == nullptr) {
            node->connect(node);
            _root = node;
            _n = 1;
        } else {
            _root->splice1(node);
            if (key < _root->key) _root = node;
            _n++;
        }
    }

    pair<int, int> pop() override {
        id13* z = _root;

        if (z->child) {
            for (auto c : z->child->begin()) {
                c.parent = nullptr;
            }
            z->splice(z->child);
        }

        if (z->next == z) {
            _root = nullptr;
        } else {
            _root = z->next;
            z->eject();
            id31();
        }

        _n--;
        _index.erase(z->value);
        return {z->key, z->value};
    }

    void id31() {
        unordered_map<int, id13*> A;
        for (auto x : _root->begin()) {
            int d = x.degree;
            while (A.find(d) != A.end()) {
                id13* y = A[d];
                if (x.key > y->key) swap(x, y);
                _link(y, x);
                A.erase(d);
                d++;
            }
            A[d] = x;
        }

        auto it = A.begin();
        _root = it->second;
        _root->connect(_root);
        for (++it; it != A.end(); ++it) {
            _root->splice1(it->second);
            if (it->second->key < _root->key) _root = it->second;
        }
    }

    void _link(id13* y, id13* x) {
        y->eject();
        y->parent = x;
        if (x->child) {
            x->child->splice1(y);
        } else {
            x->child = y;
            y->connect(y);
        }
        x->degree++;
        y->mark = false;
    }

    void id28(int value, int key) override {
        id13* x = _index[value];
        x->key = key;
        _index.erase(value);
        _index[value] = x;

        id13* y = x->parent;
        if (y && x->key < y->key) {
            _cut(x, y);
            id2(y);
        }

        if (x->key < _root->key) _root = x;
    }

    void _cut(id13* x, id13* y) {
        if (x->next == x) {
            y->child = nullptr;
        } else {
            y->child = x->next;
        }
        x->parent = nullptr;
        x->eject();
        y->degree--;

        _root->splice1(x);
        x->mark = false;
    }

    void id2(id13* y) {
        id13* z = y->parent;
        if (z) {
            if (!y->mark) {
                y->mark = true;
            } else {
                _cut(y, z);
                id2(z);
            }
        }
    }

    void merge(AbstractHeap* other) override {
        if (!other) return;

        id0* otherHeap = dynamic_cast<id0*>(other);
        if (this) {
            _root->splice(otherHeap->_root);
            if (otherHeap->_root->key < _root->key) _root = otherHeap->_root;
            _index.insert(otherHeap->_index.begin(), otherHeap->_index.end());
        } else {
            _root = otherHeap->_root;
            _index = otherHeap->_index;
        }

        _n += otherHeap->_n;
        otherHeap->_root = nullptr;
        otherHeap->_n = 0;
        otherHeap->_index.clear();
    }
};

class id5 : public AbstractHeap {
    vector<pair<int, int>> _tree;
    unordered_map<int, int> _index;

public:
    id5(const vector<pair<int, int>>& iterable) {
        _build_heap(iterable);
    }

    bool id6() override {
        return !_tree.empty();
    }

    int id18() override {
        return _tree.size();
    }

    bool id14(int value) override {
        return _index.find(value) != _index.end();
    }

    int id21(int value) override {
        return _tree[_index[value]].first;
    }

    void _build_heap(const vector<pair<int, int>>& iterable) {
        _tree = iterable;
        int size = _tree.size();
        for (int i = size / 2 - 1; i >= 0; --i) {
            _heapify(i);
        }
    }

    void _heapify(int i) {
        int size = _tree.size();
        int left = (i + 1) * 2 - 1;
        int right = (i + 1) * 2;

        int z = (left < size && _tree[left] < _tree[i]) ? left : i;
        if (right < size && _tree[right] < _tree[z]) {
            z = right;
        }

        if (z != i) {
            swap(_tree[i], _tree[z]);
            _heapify(z);
        }

        _index[_tree[i].second] = i;
    }

    void id28(int value, int key) override {
        int i = _index[value];
        while (i > 0) {
            int p = (i + 1) / 2 - 1;
            if (!(key < _tree[p].first)) break;
            _tree[i] = _tree[p];
            _index[_tree[i].second] = i;
            i = p;
        }

        _tree[i] = {key, value};
        _index[value] = i;
    }

    void push(int key, int value) override {
        _index[value] = _tree.size();
        _tree.emplace_back(numeric_limits<int>::min(), value);
        id28(value, key);
    }

    pair<int, int> pop() override {
        auto z = _tree[0];
        _tree[0] = _tree.back();
        _tree.pop_back();
        if (!_tree.empty()) _heapify(0);

        _index.erase(z.second);
        return z;
    }

    void merge(AbstractHeap* other) override {
        if (!other) return;

        id5* otherHeap = dynamic_cast<id5*>(other);
        _build_heap(_tree + otherHeap->_tree);

        otherHeap->_tree.clear();
        otherHeap->_index.clear();
    }
};

class Graph {
    int maxV;
    bool isflow;
    bool sparse;
    vector<int> _V;
    unordered_map<int, int> _V_index;
    vector<vector<int>> _E;
    vector<set<int>> _adj;
    unordered_map<int, vector<int>> _levels;

public:
    Graph(int maxV, bool isflow = false, bool sparse = false) 
        : maxV(maxV), isflow(isflow), sparse(sparse) {
        int non_edge = isflow ? 0 : numeric_limits<int>::max();
        if (sparse) {
            _E.resize(maxV);
        } else {
            _E.resize(maxV, vector<int>(maxV, non_edge));
        }
        _adj.resize(maxV);
    }

    bool id14(int label) {
        return _V_index.find(label) != _V_index.end();
    }

    auto id33() {
        return _V.begin();
    }

    int nV() {
        return _V.size();
    }

    int nE() {
        int n = 0;
        for (const auto& a : _adj) {
            n += a.size();
        }
        return isflow ? n / 2 : n;
    }

    void add_vertex(int label) {
        _V_index[label] = nV();
        _V.push_back(label);
    }

    void id12(const vector<int>& labels) {
        for (int u_label : labels) {
            add_vertex(u_label);
        }
    }

    void _add_edge(int u, int v, int w) {
        if (isflow) {
            _E[u][v] += w;
            _adj[u].insert(v);
            _adj[v].insert(u);
        } else {
            _E[u][v] = w;
            _adj[u].insert(v);
        }
    }

    void add_edge(int u_label, int v_label, int w = 1) {
        _add_edge(_V_index[u_label], _V_index[v_label], w);
    }

    bool _isadj(int u, int v) {
        return _adj[u].find(v) != _adj[u].end();
    }

    bool isadj(int u_label, int v_label) {
        return _isadj(_V_index[u_label], _V_index[v_label]);
    }

    void trim(int u_label) {
        int u = _V_index[u_label];
        _adj[u].clear();
        if (sparse) {
            _E[u].clear();
        } else {
            fill(_E[u].begin(), _E[u].end(), numeric_limits<int>::max());
        }
    }

    int id20(int s, int t) {
        _levels[s] = vector<int>(maxV, numeric_limits<int>::max());
        _levels[s][s] = 0;

        deque<int> queue;
        queue.push_back(s);
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop_front();
            for (int v : _adj[u]) {
                if (_E[u][v] > 0 && _levels[s][v] == numeric_limits<int>::max()) {
                    _levels[s][v] = _levels[s][u] + 1;
                    queue.push_back(v);
                }
            }
        }

        return _levels[s][t];
    }

    int id30(int s, int t) {
        vector<set<int>> pointers(nV());
        for (int i = 0; i < nV(); ++i) {
            pointers[i] = _adj[i];
        }

        function<int(int, int, int)> dfs_push = [&](int u, int t, int inflow) {
            if (u == t) return inflow;
            int id4 = 0;
            while (!pointers[u].empty()) {
                int v = *pointers[u].begin();
                pointers[u].erase(pointers[u].begin());
                if (_levels[s][v] == _levels[s][u] + 1 && _E[u][v] > 0) {
                    int v_flow = dfs_push(v, t, min(inflow, _E[u][v]));
                    _E[u][v] -= v_flow;
                    _E[v][u] += v_flow;
                    inflow -= v_flow;
                    id4 += v_flow;
                    if (inflow == 0) {
                        pointers[u].insert(v);
                        break;
                    }
                }
            }
            return id4;
        };

        int blocking_flow = dfs_push(s, t, numeric_limits<int>::max());
        _levels.clear();
        return blocking_flow;
    }

    int max_flow(int s_label, int t_label) {
        auto E_saved = _E;
        int s = _V_index[s_label];
        int t = _V_index[t_label];

        int mf = 0;
        while (id20(s, t) != numeric_limits<int>::max()) {
            mf += id30(s, t);
        }

        _E = E_saved;
        return mf;
    }

    unordered_map<int, unordered_map<int, int>> id1() {
        vector<vector<int>> fw = _E;
        for (int k = 0; k < nV(); ++k) {
            vector<vector<int>> next_fw(nV(), vector<int>(nV(), numeric_limits<int>::max()));
            for (int i = 0; i < nV(); ++i) {
                for (int j = 0; j < nV(); ++j) {
                    next_fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
                }
            }
            fw = next_fw;
        }

        unordered_map<int, unordered_map<int, int>> id10;
        for (int u = 0; u < nV(); ++u) {
            for (int v = 0; v < nV(); ++v) {
                id10[_V[u]][_V[v]] = fw[u][v];
            }
        }
        return id10;
    }

    unordered_map<int, int> id9(int s_label, const vector<int>& t_labels = {}, int d_limit = numeric_limits<int>::max(), AbstractHeap* Heap = new id5({})) {
        unordered_map<int, int> ret;

        int s = _V_index[s_label];
        set<int> t_set;
        if (t_labels.empty()) {
            for (int i = 0; i < nV(); ++i) {
                t_set.insert(i);
            }
        } else {
            for (int t_label : t_labels) {
                t_set.insert(_V_index[t_label]);
            }
        }

        Heap->push(0, s);
        unordered_map<int, int> spaths;
        unordered_map<int, int> parents;
        vector<int> t_found;

        while (Heap->id6()) {
            auto [su, u] = Heap->pop();
            if (su >= d_limit) {
                ret[-1] = d_limit;
                break;
            }

            spaths[u] = su;
            if (t_set.find(u) != t_set.end()) {
                t_set.erase(u);
                t_found.push_back(u);
                if (t_set.empty()) {
                    ret[-1] = su;
                    break;
                }
            }

            for (int v : _adj[u]) {
                int sv = su + _E[u][v];
                if (Heap->id14(v)) {
                    if (sv < Heap->id21(v)) {
                        parents[v] = u;
                        Heap->id28(v, sv);
                    }
                } else if (spaths.find(v) == spaths.end()) {
                    parents[v] = u;
                    Heap->push(sv, v);
                }
            }
        }

        ret[-1] = numeric_limits<int>::max();
        for (const auto& [v, d] : spaths) {
            ret[_V[v]] = d;
        }
        ret[-2] = parents;
        ret[-3] = t_found;
        return ret;
    }

    int id25(int s_label, int t_label, const unordered_map<string, int>& kwarg) {
        auto spaths = id9(s_label, {t_label}, kwarg);
        return spaths[t_label];
    }

    bool id26() {
        vector<set<int>> adj;
        if (isflow) {
            adj = _adj;
        } else {
            adj.resize(nV());
            for (int u = 0; u < nV(); ++u) {
                for (int v : _adj[u]) {
                    adj[u].insert(v);
                    adj[v].insert(u);
                }
            }
        }

        unordered_map<int, bool> colors;
        function<bool(int)> id24 = [&](int s) {
            if (colors.find(s) != colors.end()) return true;
            colors[s] = true;
            deque<int> queue;
            queue.push_back(s);
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop_front();
                for (int v : adj[u]) {
                    if (colors.find(v) == colors.end()) {
                        colors[v] = !colors[u];
                        queue.push_back(v);
                    } else if (colors[v] == colors[u]) {
                        return false;
                    }
                }
            }
            return true;
        };

        return all_of(adj.begin(), adj.end(), [&](int s) { return id24(s); });
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; ++i) {
        cin >> roads[i].first >> roads[i].second;
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
    }

    Graph G(n, false, true);
    unordered_map<int, set<int>> adj;
    G.id12(vector<int>(1, 1));
    for (const auto& [u, v] : roads) {
        G.add_edge(v, u);
        adj[u].insert(v);
    }

    auto spaths = G.id9(p.back(), nullptr);

    int id22 = 0;
    int id27 = 0;
    for (size_t i = 0; i < p.size() - 1; ++i) {
        int u = p[i];
        int v = p[i + 1];
        if (spaths[v] != spaths[u] - 1) {
            id22++;
            id27++;
            continue;
        }

        for (int w : adj[u]) {
            if (w != v && spaths[w] == spaths[v]) {
                id27++;
                break;
            }
        }
    }

    cout << id22 << " " << id27 << endl;

    return 0;
}
