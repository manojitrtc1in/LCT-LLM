#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <limits>
#include <cmath>
#include <memory>
#include <functional>

class LinkedListNodeBase {
public:
    LinkedListNodeBase* prev;
    LinkedListNodeBase* next;

    LinkedListNodeBase() : prev(nullptr), next(nullptr) {}

    LinkedListNodeBase* connect(LinkedListNodeBase* node) {
        this->next = node;
        node->prev = this;
        return node;
    }

    LinkedListNodeBase* splice(LinkedListNodeBase* fragment) {
        if (fragment->prev) fragment->prev->next = nullptr;

        LinkedListNodeBase* u = this;
        LinkedListNodeBase* v = fragment;
        LinkedListNodeBase* w = this->next;

        u->connect(v);
        while (v->next) v = v->next;
        v->connect(w);

        return v;
    }

    void splice1(LinkedListNodeBase* node) {
        node->connect(this->next);
        this->connect(node);
    }

    void eject() {
        this->prev->connect(this->next);
    }

    std::vector<LinkedListNodeBase*> iterate() {
        std::vector<LinkedListNodeBase*> result;
        LinkedListNodeBase* u = this;
        do {
            result.push_back(u);
            u = u->next;
        } while (u && u != this);
        return result;
    }
};

class AbstractHeap {
public:
    virtual ~AbstractHeap() = default;
    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;
    virtual bool contains(int value) const = 0;
    virtual int getItem(int value) const = 0;
    virtual void push(int key, int value) = 0;
    virtual std::pair<int, int> pop() = 0;
    virtual void decreaseKey(int value, int key) = 0;
    virtual void merge(AbstractHeap* other) = 0;
};

class _FibHeapNode : public LinkedListNodeBase {
public:
    int key;
    int value;
    _FibHeapNode* parent;
    _FibHeapNode* child;
    int degree;
    bool mark;

    _FibHeapNode(int key, int value) : key(key), value(value), parent(nullptr), child(nullptr), degree(0), mark(false) {}
};

class FibonacciHeap : public AbstractHeap {
private:
    int _n;
    _FibHeapNode* _root;
    std::unordered_map<int, _FibHeapNode*> _index;

    void _consolidate() {
        std::unordered_map<int, _FibHeapNode*> A;
        for (auto x : _root->iterate()) {
            int d = x->degree;
            while (A.count(d)) {
                _FibHeapNode* y = A[d];
                if (x->key > y->key) std::swap(x, y);
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

    void _link(_FibHeapNode* y, _FibHeapNode* x) {
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

public:
    FibonacciHeap() : _n(0), _root(nullptr) {}

    bool isEmpty() const override {
        return _n == 0;
    }

    size_t size() const override {
        return _n;
    }

    bool contains(int value) const override {
        return _index.count(value);
    }

    int getItem(int value) const override {
        return _index.at(value)->key;
    }

    void push(int key, int value) override {
        auto node = new _FibHeapNode(key, value);
        _index[value] = node;

        if (!_root) {
            node->connect(node);
            _root = node;
            _n = 1;
        } else {
            _root->splice1(node);
            if (key < _root->key) _root = node;
            _n++;
        }
    }

    std::pair<int, int> pop() override {
        _FibHeapNode* z = _root;

        if (z->child) {
            for (auto c : z->child->iterate()) c->parent = nullptr;
            z->splice(z->child);
        }

        if (z->next == z) {
            _root = nullptr;
        } else {
            _root = z->next;
            z->eject();
            _consolidate();
        }

        _n--;
        _index.erase(z->value);
        return {z->key, z->value};
    }

    void decreaseKey(int value, int key) override {
        _FibHeapNode* x = _index[value];

        x->key = key;
        _index.erase(value);
        _index[value] = x;

        _FibHeapNode* y = x->parent;
        if (y && x->key < y->key) {
            _cut(x, y);
            _cascadingCut(y);
        }

        if (x->key < _root->key) _root = x;
    }

    void merge(AbstractHeap* other) override {
        if (!other) return;

        if (_root) {
            _root->splice(other->_root);
            if (other->_root->key < _root->key) _root = other->_root;
            _index.insert(other->_index.begin(), other->_index.end());
        } else {
            _root = other->_root;
            _index = other->_index;
        }

        _n += other->_n;
        other->_root = nullptr;
        other->_n = 0;
        other->_index.clear();
    }

    void _cut(_FibHeapNode* x, _FibHeapNode* y) {
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

    void _cascadingCut(_FibHeapNode* y) {
        _FibHeapNode* z = y->parent;
        if (z) {
            if (!y->mark) {
                y->mark = true;
            } else {
                _cut(y, z);
                _cascadingCut(z);
            }
        }
    }
};

class Graph {
private:
    int maxV;
    bool isflow;
    bool sparse;
    std::vector<int> _V;
    std::unordered_map<int, int> _V_index;
    std::vector<std::vector<int>> _E;
    std::vector<std::set<int>> _adj;

public:
    Graph(int maxV, bool isflow = false, bool sparse = false) 
        : maxV(maxV), isflow(isflow), sparse(sparse) {
        int non_edge = isflow ? 0 : std::numeric_limits<int>::max();
        if (sparse) {
            _E.resize(maxV);
            for (auto& e : _E) e = std::vector<int>(maxV, non_edge);
        } else {
            _E.resize(maxV, std::vector<int>(maxV, non_edge));
        }
        _adj.resize(maxV);
    }

    bool contains(int label) const {
        return _V_index.count(label);
    }

    void addVertex(int label) {
        _V_index[label] = _V.size();
        _V.push_back(label);
    }

    void addEdge(int u_label, int v_label, int w = 1) {
        int u = _V_index[u_label];
        int v = _V_index[v_label];
        if (isflow) {
            _E[u][v] += w;
            _adj[u].insert(v);
            _adj[v].insert(u);
        } else {
            _E[u][v] = w;
            _adj[u].insert(v);
        }
    }

    void trim(int u_label) {
        int u = _V_index[u_label];
        _adj[u].clear();
        if (sparse) {
            _E[u].clear();
        } else {
            std::fill(_E[u].begin(), _E[u].end(), std::numeric_limits<int>::max());
        }
    }

    int maxFlow(int s_label, int t_label) {
        // Implementation of Dinitz (Dinic) algorithm
        // ...
        return 0; // Placeholder
    }

    void singleSourceSPaths(int s_label, const std::vector<int>& t_labels) {
        // Implementation of Dijkstra algorithm
        // ...
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> roads(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> roads[i].first >> roads[i].second;
    }
    int k;
    std::cin >> k;
    std::vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> p[i];
    }

    Graph G(n, false, true);
    std::unordered_map<int, std::set<int>> adj;
    for (int i = 1; i <= n; ++i) {
        G.addVertex(i);
    }
    for (const auto& [u, v] : roads) {
        G.addEdge(v, u);
        adj[u].insert(v);
    }

    // Call to G.singleSourceSPaths(p.back(), ...);

    int min_rebuild = 0;
    int max_rebuild = 0;
    for (int i = 0; i < k - 1; ++i) {
        int u = p[i];
        int v = p[i + 1];
        // Logic to calculate min_rebuild and max_rebuild
        // ...
    }

    std::cout << min_rebuild << " " << max_rebuild << std::endl;

    return 0;
}
