#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mod1 = 998244353;

class TreeNode {
public:
    int key;
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int height;
    int num_left;
    int num_total;

    TreeNode(int k, int v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        height = 1;
        num_left = 1;
        num_total = 1;
    }
};

class AvlTree {
private:
    TreeNode* _tree;

public:
    AvlTree() {
        _tree = nullptr;
    }

    void add(int k, int v) {
        if (!_tree) {
            _tree = new TreeNode(k, v);
            return;
        }
        TreeNode* node = _add(k, v);
        if (node) {
            _rebalance(node);
        }
    }

    TreeNode* _add(int k, int v) {
        TreeNode* node = _tree;
        while (node) {
            if (k < node->key) {
                if (node->left) {
                    node = node->left;
                }
                else {
                    node->left = new TreeNode(k, v);
                    node->left->parent = node;
                    return node->left;
                }
            }
            else if (node->key < k) {
                if (node->right) {
                    node = node->right;
                }
                else {
                    node->right = new TreeNode(k, v);
                    node->right->parent = node;
                    return node->right;
                }
            }
            else {
                node->value = v;
                return nullptr;
            }
        }
    }

    int get_height(TreeNode* x) {
        return x ? x->height : 0;
    }

    int get_num_total(TreeNode* x) {
        return x ? x->num_total : 0;
    }

    void _rebalance(TreeNode* node) {
        TreeNode* n = node;
        while (n) {
            int lh = get_height(n->left);
            int rh = get_height(n->right);
            n->height = max(lh, rh) + 1;
            int balance_factor = lh - rh;
            n->num_total = 1 + get_num_total(n->left) + get_num_total(n->right);
            n->num_left = 1 + get_num_total(n->left);

            if (balance_factor > 1) {
                if (get_height(n->left->left) < get_height(n->left->right)) {
                    _rotate_left(n->left);
                }
                _rotate_right(n);
            }
            else if (balance_factor < -1) {
                if (get_height(n->right->right) < get_height(n->right->left)) {
                    _rotate_right(n->right);
                }
                _rotate_left(n);
            }
            else {
                n = n->parent;
            }
        }
    }

    void _remove_one(TreeNode* node) {
        TreeNode* replacement = node->left ? node->left : node->right;
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = replacement;
            }
            else {
                node->parent->right = replacement;
            }
            if (replacement) {
                replacement->parent = node->parent;
            }
            node->parent = nullptr;
        }
        else {
            _tree = replacement;
            if (replacement) {
                replacement->parent = nullptr;
            }
        }
        delete node;
        _rebalance(replacement);
    }

    void _remove_leaf(TreeNode* node) {
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = nullptr;
            }
            else {
                node->parent->right = nullptr;
            }
            _rebalance(node->parent);
        }
        else {
            _tree = nullptr;
        }
        delete node;
    }

    void remove(int k) {
        TreeNode* node = _get_node(k);
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            _remove_leaf(node);
        }
        else if (node->left && node->right) {
            TreeNode* nxt = _get_next(node);
            node->key = nxt->key;
            node->value = nxt->value;
            if (!nxt->left && !nxt->right) {
                _remove_leaf(nxt);
            }
            else {
                _remove_one(nxt);
            }
            _rebalance(node);
        }
        else {
            _remove_one(node);
        }
    }

    int get(int k) {
        TreeNode* node = _get_node(k);
        return node ? node->value : -1;
    }

    TreeNode* _get_node(int k) {
        if (!_tree) {
            return nullptr;
        }
        TreeNode* node = _tree;
        while (node) {
            if (k < node->key) {
                node = node->left;
            }
            else if (node->key < k) {
                node = node->right;
            }
            else {
                return node;
            }
        }
        return nullptr;
    }

    pair<int, int> get_at(int pos) {
        int x = pos + 1;
        TreeNode* node = _tree;
        while (node) {
            if (x < node->num_left) {
                node = node->left;
            }
            else if (node->num_left < x) {
                x -= node->num_left;
                node = node->right;
            }
            else {
                return make_pair(node->key, node->value);
            }
        }
        throw out_of_range("Out of ranges");
    }

    static bool _is_left(TreeNode* node) {
        return node->parent && node->parent->left == node;
    }

    static bool _is_leaf(TreeNode* node) {
        return !node->left && !node->right;
    }

    void _rotate_right(TreeNode* node) {
        if (!node->parent) {
            _tree = node->left;
            if (node->left) {
                node->left->parent = nullptr;
            }
        }
        else if (_is_left(node)) {
            node->parent->left = node->left;
            if (node->left) {
                node->left->parent = node->parent;
            }
        }
        else {
            node->parent->right = node->left;
            if (node->left) {
                node->left->parent = node->parent;
            }
        }
        TreeNode* bk = node->left->right;
        node->left->right = node;
        node->parent = node->left;
        node->left = bk;
        if (bk) {
            bk->parent = node;
        }
        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        node->num_total = 1 + get_num_total(node->left) + get_num_total(node->right);
        node->num_left = 1 + get_num_total(node->left);
    }

    void _rotate_left(TreeNode* node) {
        if (!node->parent) {
            _tree = node->right;
            if (node->right) {
                node->right->parent = nullptr;
            }
        }
        else if (_is_left(node)) {
            node->parent->left = node->right;
            if (node->right) {
                node->right->parent = node->parent;
            }
        }
        else {
            node->parent->right = node->right;
            if (node->right) {
                node->right->parent = node->parent;
            }
        }
        TreeNode* bk = node->right->left;
        node->right->left = node;
        node->parent = node->right;
        node->right = bk;
        if (bk) {
            bk->parent = node;
        }
        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        node->num_total = 1 + get_num_total(node->left) + get_num_total(node->right);
        node->num_left = 1 + get_num_total(node->left);
    }

    static TreeNode* _get_next(TreeNode* node) {
        if (!node->right) {
            return node->parent;
        }
        TreeNode* n = node->right;
        while (n->left) {
            n = n->left;
        }
        return n;
    }
};

class SegmentTree1 {
private:
    vector<int> data;
    int _default;
    function<int(int, int)> _func;
    int _len;
    int _size;

public:
    SegmentTree1(vector<int>& data, int default_val, function<int(int, int)> func) {
        _default = default_val;
        _func = func;
        _len = data.size();
        _size = 1 << (int)ceil(log2(_len));

        this->data.resize(2 * _size, default_val);
        copy(data.begin(), data.end(), this->data.begin() + _size);
        for (int i = _size - 1; i >= 0; i--) {
            this->data[i] = _func(this->data[i + i], this->data[i + i + 1]);
        }
    }

    void erase(int idx) {
        (*this)[idx] = _default;
    }

    int operator[](int idx) {
        return data[idx + _size];
    }

    void operator=(pair<int, int> p) {
        int idx = p.first;
        int value = p.second;
        idx += _size;
        data[idx] = value;
        idx >>= 1;
        while (idx) {
            data[idx] = _func(data[2 * idx], data[2 * idx + 1]);
            idx >>= 1;
        }
    }

    int size() {
        return _len;
    }

    int query(int start, int stop) {
        if (start == stop) {
            return (*this)[start];
        }
        stop += 1;
        start += _size;
        stop += _size;

        int res = _default;
        while (start < stop) {
            if (start & 1) {
                res = _func(res, data[start]);
                start += 1;
            }
            if (stop & 1) {
                stop -= 1;
                res = _func(res, data[stop]);
            }
            start >>= 1;
            stop >>= 1;
        }
        return res;
    }
};

class SegmentTree {
private:
    vector<int> data;
    int _default;
    function<int(int, int)> _func;
    int _len;
    int _size;

public:
    SegmentTree(vector<int>& data, int default_val, function<int(int, int)> func) {
        _default = default_val;
        _func = func;
        _len = data.size();
        _size = 1 << (int)ceil(log2(_len));

        this->data.resize(2 * _size, default_val);
        copy(data.begin(), data.end(), this->data.begin() + _size);
        for (int i = _size - 1; i >= 0; i--) {
            this->data[i] = _func(this->data[i + i], this->data[i + i + 1]);
        }
    }

    void erase(int idx) {
        (*this)[idx] = _default;
    }

    int operator[](int idx) {
        return data[idx + _size];
    }

    void operator=(pair<int, int> p) {
        int idx = p.first;
        int value = p.second;
        idx += _size;
        data[idx] = value;
        idx >>= 1;
        while (idx) {
            data[idx] = _func(data[2 * idx], data[2 * idx + 1]);
            idx >>= 1;
        }
    }

    int size() {
        return _len;
    }

    int query(int start, int stop) {
        if (start == stop) {
            return (*this)[start];
        }
        stop += 1;
        start += _size;
        stop += _size;

        int res = _default;
        while (start < stop) {
            if (start & 1) {
                res = _func(res, data[start]);
                start += 1;
            }
            if (stop & 1) {
                stop -= 1;
                res = _func(res, data[stop]);
            }
            start >>= 1;
            stop >>= 1;
        }
        return res;
    }
};

class Factorial {
private:
    int MOD;
    vector<int> factorials;
    vector<int> invModulos;
    vector<int> invFactorial_;

public:
    Factorial(int mod) {
        MOD = mod;
        factorials = {1, 1};
        invModulos = {0, 1};
        invFactorial_ = {1, 1};
    }

    int calc(int n) {
        if (n <= -1) {
            cout << "Invalid argument to calculate n!" << endl;
            cout << "n must be non-negative value. But the argument was " << n << endl;
            exit(1);
        }
        if (n < factorials.size()) {
            return factorials[n];
        }
        vector<int> nextArr(n + 1 - factorials.size(), 0);
        int initialI = factorials.size();
        int prev = factorials.back();
        int m = MOD;
        for (int i = initialI; i <= n; i++) {
            prev = nextArr[i - initialI] = (prev * i) % m;
        }
        factorials.insert(factorials.end(), nextArr.begin(), nextArr.end());
        return factorials[n];
    }

    int inv(int n) {
        if (n <= -1) {
            cout << "Invalid argument to calculate n^(-1)" << endl;
            cout << "n must be non-negative value. But the argument was " << n << endl;
            exit(1);
        }
        int p = MOD;
        int pi = n % p;
        if (pi < invModulos.size()) {
            return invModulos[pi];
        }
        vector<int> nextArr(n + 1 - invModulos.size(), 0);
        int initialI = invModulos.size();
        for (int i = initialI; i < min(p, n + 1); i++) {
            int next = -invModulos[p % i] * (p / i) % p;
            invModulos.push_back(next);
        }
        return invModulos[pi];
    }

    int invFactorial(int n) {
        if (n <= -1) {
            cout << "Invalid argument to calculate (n^(-1))!" << endl;
            cout << "n must be non-negative value. But the argument was " << n << endl;
            exit(1);
        }
        if (n < invFactorial_.size()) {
            return invFactorial_[n];
        }
        inv(n);
        vector<int> nextArr(n + 1 - invFactorial_.size(), 0);
        int initialI = invFactorial_.size();
        int prev = invFactorial_.back();
        int p = MOD;
        for (int i = initialI; i <= n; i++) {
            prev = nextArr[i - initialI] = (prev * invModulos[i % p]) % p;
        }
        invFactorial_.insert(invFactorial_.end(), nextArr.begin(), nextArr.end());
        return invFactorial_[n];
    }
};

class Combination {
private:
    int MOD;
    Factorial factorial;

public:
    Combination(int mod) : factorial(mod) {
        MOD = mod;
    }

    int ncr(int n, int k) {
        if (k < 0 || n < k) {
            return 0;
        }
        k = min(k, n - k);
        return (factorial.calc(n) * factorial.invFactorial(max(n - k, k)) % MOD * factorial.invFactorial(min(k, n - k)) % MOD) % MOD;
    }
};

int powm(int a, int n, int m) {
    if (a == 1 || n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        int s = powm(a, n / 2, m);
        return (s * s) % m;
    }
    else {
        return (a * powm(a, n - 1, m)) % m;
    }
}

vector<int> sort_list(vector<int>& list1, vector<int>& list2) {
    vector<pair<int, int>> zipped_pairs;
    for (int i = 0; i < list1.size(); i++) {
        zipped_pairs.push_back(make_pair(list2[i], list1[i]));
    }
    sort(zipped_pairs.begin(), zipped_pairs.end());

    vector<int> z;
    for (auto p : zipped_pairs) {
        z.push_back(p.second);
    }

    return z;
}

int product(vector<int>& l) {
    int por = 1;
    for (int i = 0; i < l.size(); i++) {
        por *= l[i];
    }
    return por;
}

int binarySearchCount(vector<int>& arr, int n, int key) {
    int left = 0;
    int right = n - 1;

    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < key) {
            count = mid + 1;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return count;
}

int countdig(int n) {
    int c = 0;
    while (n > 0) {
        n /= 10;
        c += 1;
    }
    return c;
}

string binary(int x, int length) {
    string y = bitset<32>(x).to_string();
    return y.substr(32 - length);
}

int countGreater(vector<int>& arr, int n, int k) {
    int l = 0;
    int r = n - 1;

    int leftGreater = n;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] > k) {
            leftGreater = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return (n - leftGreater);
}

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = getNode();
    }

    TrieNode* getNode() {
        return new TrieNode();
    }

    void insert(string key) {
        TrieNode* pCrawl = root;
        int length = key.length();
        for (int level = 0; level < length; level++) {
            int index = key[level] - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = getNode();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(string key) {
        TrieNode* pCrawl = root;
        int length = key.length();
        for (int level = 0; level < length; level++) {
            int index = key[level] - 'a';
            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }
};

class Node {
public:
    int data;
    int count;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        count = 0;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTrie {
private:
    Node* root;

public:
    BinaryTrie() {
        root = new Node(0);
    }

    void insert(int pre_xor) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int val = pre_xor & (1 << i);
            if (val) {
                if (!temp->right) {
                    temp->right = new Node(0);
                }
                temp = temp->right;
                temp->count += 1;
            }
            if (!val) {
                if (!temp->left) {
                    temp->left = new Node(0);
                }
                temp = temp->left;
                temp->count += 1;
            }
        }
        temp->data = pre_xor;
    }

    int query(int xor_val) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int val = xor_val & (1 << i);
            if (!val) {
                if (temp->left && temp->left->count > 0) {
                    temp = temp->left;
                }
                else if (temp->right) {
                    temp = temp->right;
                }
            }
            else {
                if (temp->right && temp->right->count > 0) {
                    temp = temp->right;
                }
                else if (temp->left) {
                    temp = temp->left;
                }
            }
            temp->count -= 1;
        }
        return xor_val ^ temp->data;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<pair<int, int>> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end());
    auto check = [&](int x) {
        int now = x;
        int c = accumulate(l.begin(), l.end(), 0);
        int cur = 0;
        int last = 0;
        unordered_map<int, int> ld;
        for (int i = 0; i < t.size(); i++) {
            if (t[i].first <= x) {
                ld[t[i].second] = i;
            }
        }
        for (int i = 0; i < m; i++) {
            if (ld[t[i].second] != i) {
                continue;
            }
            if (t[i].first > x) {
                break;
            }
            cur += t[i].first - last;
            int rt = min(cur, l[t[i].second - 1]);
            cur -= rt;
            now -= rt;
            c -= rt;
            last = t[i].first;
        }
        if (now >= 2 * c) {
            return true;
        }
        return false;
    };
    int st = 1;
    int end = 2 * accumulate(l.begin(), l.end(), 0);
    int ans = end;
    while (st <= end) {
        int mid = (st + end) / 2;
        if (check(mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
