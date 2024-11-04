#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <cmath>
#include <algorithm>

class LinkedListNodeBase {
public:
    LinkedListNodeBase* prev;
    LinkedListNodeBase* next;

    LinkedListNodeBase() {
        prev = nullptr;
        next = nullptr;
    }

    LinkedListNodeBase* connect(LinkedListNodeBase* node) {
        next = node;
        node->prev = this;
        return node;
    }

    LinkedListNodeBase* splice(LinkedListNodeBase* fragment) {
        if (fragment->prev) fragment->prev->next = nullptr;

        LinkedListNodeBase* u = this;
        LinkedListNodeBase* v = fragment;
        LinkedListNodeBase* w = next;

        u->connect(v);
        while (v->next) v = v->next;
        v->connect(w);

        return v;
    }

    void splice1(LinkedListNodeBase* node) {
        node->connect(next);
        connect(node);
    }

    void eject() {
        prev->connect(next);
    }

    std::vector<LinkedListNodeBase*> iterate() {
        std::vector<LinkedListNodeBase*> result;
        LinkedListNodeBase* u = this;
        while (true) {
            result.push_back(u);
            u = u->next;
            if (!u || u == this) break;
        }
        return result;
    }
};

class AbstractHeap {
public:
    virtual ~AbstractHeap() {}

    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual bool contains(int value) const = 0;
    virtual int operator[](int value) const = 0;
    virtual void push(int key, int value) = 0;
    virtual std::pair<int, int> pop() = 0;
    virtual void decreaseKey(int value, int key) = 0;
    virtual void merge(AbstractHeap* other) = 0;
};

class FibonacciHeapNode : public LinkedListNodeBase {
public:
    int key;
    int value;
    FibonacciHeapNode* parent;
    FibonacciHeapNode* child;
    int degree;
    bool mark;

    FibonacciHeapNode(int key, int value) : LinkedListNodeBase() {
        this->key = key;
        this->value = value;
        parent = nullptr;
        child = nullptr;
        degree = 0;
        mark = false;
    }
};

class FibonacciHeap : public AbstractHeap {
private:
    FibonacciHeapNode* root;
    std::unordered_map<int, FibonacciHeapNode*> index;
    int n;

    void consolidate() {
        std::unordered_map<int, FibonacciHeapNode*> A;
        for (auto x : root->iterate()) {
            int d = x->degree;
            while (A.count(d)) {
                FibonacciHeapNode* y = A[d];
                if (x->key > y->key) std::swap(x, y);
                link(y, x);
                A.erase(d);
                d++;
            }
            A[d] = x;
        }

        auto it = A.begin();
        root = it->second;
        root->connect(root);
        it++;
        for (; it != A.end(); it++) {
            root->splice1(it->second);
            if (it->second->key < root->key) root = it->second;
        }
    }

    void link(FibonacciHeapNode* y, FibonacciHeapNode* x) {
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
    FibonacciHeap() {
        root = nullptr;
        n = 0;
    }

    bool empty() const {
        return n == 0;
    }

    int size() const {
        return n;
    }

    bool contains(int value) const {
        return index.count(value);
    }

    int operator[](int value) const {
        return index[value]->key;
    }

    void push(int key, int value) {
        FibonacciHeapNode* node = new FibonacciHeapNode(key, value);
        index[value] = node;

        if (root == nullptr) {
            node->connect(node);
            root = node;
            n = 1;
        } else {
            root->splice1(node);
            if (key < root->key) root = node;
            n++;
        }
    }

    std::pair<int, int> pop() {
        FibonacciHeapNode* z = root;

        if (z->child) {
            for (auto c : z->child->iterate()) c->parent = nullptr;
            z->splice(z->child);
        }

        if (z->next == z) {
            root = nullptr;
        } else {
            root = z->next;
            z->eject();
            consolidate();
        }

        n--;
        int value = z->value;
        index.erase(value);
        std::pair<int, int> result(z->key, value);
        delete z;
        return result;
    }

    void decreaseKey(int value, int key) {
        FibonacciHeapNode* x = index[value];

        x->key = key;
        index.erase(value);
        index[value] = x;

        FibonacciHeapNode* y = x->parent;
        if (y && x->key < y->key) {
            cut(x, y);
            cascadingCut(y);
        }

        if (x->key < root->key) root = x;
    }

    void cut(FibonacciHeapNode* x, FibonacciHeapNode* y) {
        if (x->next == x) {
            y->child = nullptr;
        } else {
            y->child = x->next;
        }
        x->parent = nullptr;
        x->eject();
        y->degree--;

        root->splice1(x);
        x->mark = false;
    }

    void cascadingCut(FibonacciHeapNode* y) {
        FibonacciHeapNode* z = y->parent;
        if (z) {
            if (!y->mark) {
                y->mark = true;
            } else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

    void merge(AbstractHeap* other) {
        FibonacciHeap* otherHeap = dynamic_cast<FibonacciHeap*>(other);
        if (otherHeap == nullptr) return;

        if (!otherHeap->empty()) {
            root->splice(otherHeap->root);
            if (otherHeap->root->key < root->key) root = otherHeap->root;
            index.insert(otherHeap->index.begin(), otherHeap->index.end());
        }

        n += otherHeap->n;
        otherHeap->root = nullptr;
        otherHeap->n = 0;
        otherHeap->index.clear();
    }
};

class Implicit2Heap : public AbstractHeap {
private:
    std::vector<std::pair<int, int>> tree;
    std::unordered_map<int, int> index;

    void buildHeap(const std::vector<std::pair<int, int>>& iterable) {
        tree = iterable;
        int size = tree.size();

        index.clear();
        for (int i = size / 2; i < size; i++) {
            index[tree[i].second] = i;
        }

        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void heapify(int i) {
        int size = tree.size();
        int left = (i + 1) * 2 - 1;
        int right = (i + 1) * 2 + 1 - 1;

        int z = i;
        if (left < size && tree[left] < tree[i]) {
            z = left;
        }
        if (right < size && tree[right] < tree[z]) {
            z = right;
        }

        if (z != i) {
            std::swap(tree[i], tree[z]);
            index[tree[i].second] = i;
            heapify(z);
        }

        index[tree[i].second] = i;
    }

public:
    Implicit2Heap(const std::vector<std::pair<int, int>>& iterable) {
        buildHeap(iterable);
    }

    bool empty() const {
        return tree.empty();
    }

    int size() const {
        return tree.size();
    }

    bool contains(int value) const {
        return index.count(value);
    }

    int operator[](int value) const {
        return tree[index.at(value)].first;
    }

    void push(int key, int value) {
        index[value] = tree.size();
        tree.push_back(std::make_pair(std::numeric_limits<int>::max(), value));
        decreaseKey(value, key);
    }

    std::pair<int, int> pop() {
        std::pair<int, int> z = tree[0];
        tree[0] = tree.back();
        tree.pop_back();
        if (!tree.empty()) heapify(0);

        index.erase(z.second);
        return z;
    }

    void decreaseKey(int value, int key) {
        int i = index[value];

        while (i > 0) {
            int p = (i + 1) / 2 - 1;
            if (!(key < tree[p].first)) break;
            tree[i] = tree[p];
            index[tree[i].second] = i;
            i = p;
        }

        tree[i] = std::make_pair(key, value);
        index[value] = i;
    }

    void merge(AbstractHeap* other) {
        Implicit2Heap* otherHeap = dynamic_cast<Implicit2Heap*>(other);
        if (otherHeap == nullptr) return;

        buildHeap(tree);
        buildHeap(otherHeap->tree);

        otherHeap->tree.clear();
        otherHeap->index.clear();
    }
};

class PairingHeapNode {
public:
    int key;
    int value;
    PairingHeapNode* parent;
    PairingHeapNode* left;
    PairingHeapNode* right;

    PairingHeapNode(int key, int value) {
        this->key = key;
        this->value = value;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    PairingHeapNode* link(PairingHeapNode* other) {
        if (other->key < key) std::swap(this, other);
        if (!left) {
            left = other;
            other->parent = this;
        } else {
            PairingHeapNode* r = left;
            while (r->right) r = r->right;
            r->right = other;
            other->parent = r;
        }
        return this;
    }
};

class PairingHeap : public AbstractHeap {
private:
    PairingHeapNode* root;
    std::unordered_map<int, PairingHeapNode*> index;

    void merge(PairingHeapNode* other) {
        if (!other) return;
        if (!root) {
            root = other;
        } else {
            root = root->link(other);
        }
    }

public:
    PairingHeap() {
        root = nullptr;
    }

    bool empty() const {
        return root == nullptr;
    }

    int size() const {
        return index.size();
    }

    bool contains(int value) const {
        return index.count(value);
    }

    int operator[](int value) const {
        return index[value]->key;
    }

    void push(int key, int value) {
        PairingHeapNode* node = new PairingHeapNode(key, value);
        index[value] = node;
        merge(node);
    }

    std::pair<int, int> pop() {
        PairingHeapNode* z = root;
        if (z->left == nullptr) {
            root = nullptr;
        } else {
            std::vector<PairingHeapNode*> pass0;
            PairingHeapNode* i = z->left;
            while (i) {
                PairingHeapNode* j = i->right;
                i->parent = nullptr;
                i->right = nullptr;
                pass0.push_back(i);
                i = j;
            }

            std::vector<PairingHeapNode*> pass1;
            for (int i = 0; i < pass0.size() - 1; i += 2) {
                pass1.push_back(pass0[i]->link(pass0[i + 1]));
            }
            if (pass0.size() % 2 == 1) pass1.push_back(pass0.back());

            PairingHeapNode* y = pass1.back();
            pass1.pop_back();
            while (!pass1.empty()) {
                y = y->link(pass1.back());
                pass1.pop_back();
            }

            root = y;
        }

        index.erase(z->value);
        std::pair<int, int> result(z->key, z->value);
        delete z;
        return result;
    }

    void decreaseKey(int value, int key) {
        PairingHeapNode* x = index[value];

        x->key = key;
        index.erase(value);
        index[value] = x;
        if (x->parent == nullptr) return;

        if (x->parent->left == x) {
            x->parent->left = x->right;
        } else {
            x->parent->right = x->right;
        }
        if (x->right) x->right->parent = x->parent;

        x->parent = nullptr;
        x->right = nullptr;
        merge(x);
    }

    void merge(AbstractHeap* other) {
        PairingHeap* otherHeap = dynamic_cast<PairingHeap*>(other);
        if (otherHeap == nullptr) return;

        merge(otherHeap->root);
        index.insert(otherHeap->index.begin(), otherHeap->index.end());

        otherHeap->root = nullptr;
        otherHeap->index.clear();
    }
};

class Graph {
private:
    int maxV;
    bool isflow;
    bool sparse;
    std::vector<int> V;
    std::unordered_map<int, int> V_index;
    std::vector<std::unordered_map<int, int>> E;
    std::vector<std::unordered_set<int>> adj;
    std::unordered_map<int, std::vector<int>> levels;

    int bfsLevels(int s, int t) {
        levels[s] = std::vector<int>(maxV, std::numeric_limits<int>::max());
        levels[s][s] = 0;

        std::queue<int> queue;
        queue.push(s);
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            for (int v : adj[u]) {
                if (E[u][v] > 0 && levels[s][v] == std::numeric_limits<int>::max()) {
                    levels[s][v] = levels[s][u] + 1;
                    queue.push(v);
                }
            }
        }

        return levels[s][t];
    }

    int pushBlockingFlow(int s, int t) {
        std::vector<std::unordered_set<int>> pointers(adj.size());
        for (int u = 0; u < adj.size(); u++) {
            pointers[u] = adj[u];
        }

        std::function<int(int, int, int)> dfsPush = [&](int u, int t, int inflow) {
            if (u == t) return inflow;
            int uOutflow = 0;
            while (!pointers[u].empty()) {
                int v = *pointers[u].begin();
                pointers[u].erase(v);
                if (levels[s][v] == levels[s][u] + 1 && E[u][v] > 0) {
                    int vFlow = dfsPush(v, t, std::min(inflow, E[u][v]));
                    E[u][v] -= vFlow;
                    E[v][u] += vFlow;
                    inflow -= vFlow;
                    uOutflow += vFlow;
                    if (inflow == 0) {
                        pointers[u].insert(v);
                        break;
                    }
                }
            }
            return uOutflow;
        };

        int blockingFlow = dfsPush(s, t, std::numeric_limits<int>::max());
        levels.clear();
        return blockingFlow;
    }

public:
    Graph(int maxV, bool isflow = false, bool sparse = false) {
        this->maxV = maxV;
        this->isflow = isflow;
        this->sparse = sparse;

        V.clear();
        V_index.clear();

        int nonEdge = isflow ? 0 : std::numeric_limits<int>::max();
        if (sparse) {
            E = std::vector<std::unordered_map<int, int>>(maxV, std::unordered_map<int, int>());
        } else {
            E = std::vector<std::unordered_map<int, int>>(maxV, std::unordered_map<int, int>(maxV, nonEdge));
        }

        adj = std::vector<std::unordered_set<int>>(maxV, std::unordered_set<int>());
        levels.clear();
    }

    void addVertex(int label) {
        V_index[label] = V.size();
        V.push_back(label);
    }

    void addVertices(const std::vector<int>& labels) {
        for (int uLabel : labels) {
            addVertex(uLabel);
        }
    }

    void addEdge(int uLabel, int vLabel, int w = 1) {
        int u = V_index[uLabel];
        int v = V_index[vLabel];
        if (isflow) {
            E[u][v] += w;
            adj[u].insert(v);
            adj[v].insert(u);
        } else {
            E[u][v] = w;
            adj[u].insert(v);
        }
    }

    void trim(int uLabel) {
        int u = V_index[uLabel];
        adj[u].clear();
        if (sparse) {
            E[u].clear();
        } else {
            E[u] = std::unordered_map<int, int>(maxV, std::numeric_limits<int>::max());
        }
    }

    int bfsShortestPath(int sLabel, int tLabel, int dLimit = std::numeric_limits<int>::max(), AbstractHeap* Heap = new Implicit2Heap(std::vector<std::pair<int, int>>())) {
        int s = V_index[sLabel];
        int t = V_index[tLabel];

        class SPathsObject : public std::unordered_map<int, int> {
        public:
            std::unordered_map<int, int> parents;
            std::vector<int> found;
            int stop;
        };

        SPathsObject ret;

        std::unordered_set<int> tSet;
        if (tLabel == -1) {
            tSet = std::unordered_set<int>(V_index.begin(), V_index.end());
        } else {
            tSet = std::unordered_set<int>({ t });
        }

        Heap->push(0, s);
        std::unordered_map<int, int> spaths;
        std::unordered_map<int, int> parents;
        std::vector<int> tFound;
        while (!Heap->empty()) {
            auto [su, u] = Heap->pop();
            if (su >= dLimit) {
                ret.stop = dLimit;
                break;
            }

            spaths[u] = su;
            if (tSet.count(u)) {
                tSet.erase(u);
                tFound.push_back(u);
                if (tSet.empty()) {
                    ret.stop = su;
                    break;
                }
            }

            for (int v : adj[u]) {
                int sv = su + E[u][v];
                if (Heap->contains(v)) {
                    if (sv < (*Heap)[v]) {
                        parents[v] = u;
                        Heap->decreaseKey(v, sv);
                    }
                } else if (!spaths.count(v)) {
                    parents[v] = u;
                    Heap->push(sv, v);
                }
            }
        }

        ret.insert(spaths.begin(), spaths.end());
        ret.parents = parents;
        ret.parents[sLabel] = -1;
        ret.found = tFound;
        return ret[tLabel];
    }

    int maxFlow(int sLabel, int tLabel) {
        int s = V_index[sLabel];
        int t = V_index[tLabel];

        std::vector<std::unordered_map<int, int>> E_saved = E;
        std::unordered_map<int, std::vector<int>> levels_saved = levels;

        int mf = 0;
        while (bfsLevels(s, t) != std::numeric_limits<int>::max()) {
            mf += pushBlockingFlow(s, t);
        }

        E = E_saved;
        levels = levels_saved;
        return mf;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) {
        std::cin >> roads[i].first >> roads[i].second;
    }
    int k;
    std::cin >> k;
    std::vector<int> p(k);
    for (int i = 0; i < k; i++) {
        std::cin >> p[i];
    }

    Graph G(n, true, true);
    std::unordered_map<int, std::unordered_set<int>> adj;
    G.addVertices(std::vector<int>(n, 0));
    for (auto [u, v] : roads) {
        G.addEdge(v, u);
        adj[u].insert(v);
    }

    std::unordered_map<int, int> spaths = G.bfsShortestPath(p.back(), -1, std::numeric_limits<int>::max(), new FibonacciHeap());
    int minRebuild = 0;
    int maxRebuild = 0;
    for (int i = 0; i < k - 1; i++) {
        int u = p[i];
        int u_d = spaths[u];
        int v = p[i + 1];
        int v_d = spaths[v];

        if (v_d != u_d - 1) {
            minRebuild++;
            maxRebuild++;
            continue;
        }

        bool found = false;
        for (int w : adj[u]) {
            if (w != v && spaths[w] == v_d) {
                found = true;
                break;
            }
        }
        if (found) maxRebuild++;
    }

    std::cout << minRebuild << " " << maxRebuild << std::endl;

    return 0;
}
