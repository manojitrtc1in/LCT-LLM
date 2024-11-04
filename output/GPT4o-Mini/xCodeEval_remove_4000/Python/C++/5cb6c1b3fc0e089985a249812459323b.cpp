#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MOD1 = 998244353;

class TreeNode {
public:
    int key, value, height, num_left, num_total;
    TreeNode *left, *right, *parent;

    TreeNode(int k, int v) : key(k), value(v), left(nullptr), right(nullptr), parent(nullptr), height(1), num_left(1), num_total(1) {}
};

class id8 {
private:
    TreeNode* _tree;

public:
    id8() : _tree(nullptr) {}

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
                } else {
                    node->left = new TreeNode(k, v);
                    node->left->parent = node;
                    return node->left;
                }
            } else if (node->key < k) {
                if (node->right) {
                    node = node->right;
                } else {
                    node->right = new TreeNode(k, v);
                    node->right->parent = node;
                    return node->right;
                }
            } else {
                node->value = v;
                return nullptr;
            }
        }
        return nullptr;
    }

    static int get_height(TreeNode* x) {
        return x ? x->height : 0;
    }

    static int id1(TreeNode* x) {
        return x ? x->num_total : 0;
    }

    void _rebalance(TreeNode* node) {
        TreeNode* n = node;
        while (n) {
            int lh = get_height(n->left);
            int rh = get_height(n->right);
            n->height = max(lh, rh) + 1;
            int balance_factor = lh - rh;
            n->num_total = 1 + id1(n->left) + id1(n->right);
            n->num_left = 1 + id1(n->left);

            if (balance_factor > 1) {
                if (get_height(n->left->left) < get_height(n->left->right)) {
                    _rotate_left(n->left);
                }
                _rotate_right(n);
            } else if (balance_factor < -1) {
                if (get_height(n->right->right) < get_height(n->right->left)) {
                    _rotate_right(n->right);
                }
                _rotate_left(n);
            } else {
                n = n->parent;
            }
        }
    }

    void _remove_one(TreeNode* node) {
        TreeNode* replacement = node->left ? node->left : node->right;
        if (node->parent) {
            if (_is_left(node)) {
                node->parent->left = replacement;
            } else {
                node->parent->right = replacement;
            }
            if (replacement) replacement->parent = node->parent;
            node->parent = nullptr;
        } else {
            _tree = replacement;
            if (replacement) replacement->parent = nullptr;
        }
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        _rebalance(replacement);
    }

    void _remove_leaf(TreeNode* node) {
        if (node->parent) {
            if (_is_left(node)) {
                node->parent->left = nullptr;
            } else {
                node->parent->right = nullptr;
            }
            _rebalance(node->parent);
        } else {
            _tree = nullptr;
        }
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
    }

    void remove(int k) {
        TreeNode* node = _get_node(k);
        if (!node) return;
        if (_is_leaf(node)) {
            _remove_leaf(node);
            return;
        }
        if (node->left && node->right) {
            TreeNode* nxt = _get_next(node);
            node->key = nxt->key;
            node->value = nxt->value;
            if (_is_leaf(nxt)) {
                _remove_leaf(nxt);
            } else {
                _remove_one(nxt);
            }
            _rebalance(node);
        } else {
            _remove_one(node);
        }
    }

    int get(int k) {
        TreeNode* node = _get_node(k);
        return node ? node->value : -1;
    }

    TreeNode* _get_node(int k) {
        if (!_tree) return nullptr;
        TreeNode* node = _tree;
        while (node) {
            if (k < node->key) {
                node = node->left;
            } else if (node->key < k) {
                node = node->right;
            } else {
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
            } else if (node->num_left < x) {
                x -= node->num_left;
                node = node->right;
            } else {
                return {node->key, node->value};
            }
        }
        throw out_of_range("Out of ranges");
    }

    static bool _is_left(TreeNode* node) {
        return node->parent->left && node->parent->left == node;
    }

    static bool _is_leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    void _rotate_right(TreeNode* node) {
        if (!node->parent) {
            _tree = node->left;
            node->left->parent = nullptr;
        } else if (_is_left(node)) {
            node->parent->left = node->left;
            node->left->parent = node->parent;
        } else {
            node->parent->right = node->left;
            node->left->parent = node->parent;
        }
        TreeNode* bk = node->left->right;
        node->left->right = node;
        node->parent = node->left;
        node->left = bk;
        if (bk) bk->parent = node;
        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        node->num_total = 1 + id1(node->left) + id1(node->right);
        node->num_left = 1 + id1(node->left);
    }

    void _rotate_left(TreeNode* node) {
        if (!node->parent) {
            _tree = node->right;
            node->right->parent = nullptr;
        } else if (_is_left(node)) {
            node->parent->left = node->right;
            node->right->parent = node->parent;
        } else {
            node->parent->right = node->right;
            node->right->parent = node->parent;
        }
        TreeNode* bk = node->right->left;
        node->right->left = node;
        node->parent = node->right;
        node->right = bk;
        if (bk) bk->parent = node;
        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        node->num_total = 1 + id1(node->left) + id1(node->right);
        node->num_left = 1 + id1(node->left);
    }

    static TreeNode* _get_next(TreeNode* node) {
        if (!node->right) return node->parent;
        TreeNode* n = node->right;
        while (n->left) {
            n = n->left;
        }
        return n;
    }
};

class id0 {
private:
    int _len, _size;
    vector<int> data;
    int _default;
    function<int(int, int)> _func;

public:
    id0(vector<int> &data, int default_value = 'z', function<int(int, int)> func = [](int a, int b) { return min(a, b); }) 
        : _default(default_value), _func(func), _len(data.size()), _size(1 << (int(log2(_len - 1)) + 1)) {
        this->data.assign(2 * _size, default_value);
        copy(data.begin(), data.end(), this->data.begin() + _size);
        for (int i = _size - 1; i > 0; --i) {
            this->data[i] = _func(this->data[i + i], this->data[i + i + 1]);
        }
    }

    void id4(int idx) {
        this->data[idx] = _default;
    }

    int id6(int idx) {
        return this->data[idx + _size];
    }

    void id3(int idx, int value) {
        idx += _size;
        this->data[idx] = value;
        idx >>= 1;
        while (idx) {
            this->data[idx] = _func(this->data[2 * idx], this->data[2 * idx + 1]);
            idx >>= 1;
        }
    }

    int id11() {
        return _len;
    }

    int query(int start, int stop) {
        if (start == stop) return id6(start);
        stop++;
        start += _size;
        stop += _size;

        int res = _default;
        while (start < stop) {
            if (start & 1) {
                res = _func(res, data[start]);
                start++;
            }
            if (stop & 1) {
                stop--;
                res = _func(res, data[stop]);
            }
            start >>= 1;
            stop >>= 1;
        }
        return res;
    }

    string id2() {
        return "SegmentTree(" + to_string(data) + ")";
    }
};

class SegmentTree {
private:
    int _len, _size;
    vector<int> data;
    int _default;
    function<int(int, int)> _func;

public:
    SegmentTree(vector<int> &data, int default_value = 0, function<int(int, int)> func = [](int a, int b) { return a + b; }) 
        : _default(default_value), _func(func), _len(data.size()), _size(1 << (int(log2(_len - 1)) + 1)) {
        this->data.assign(2 * _size, default_value);
        copy(data.begin(), data.end(), this->data.begin() + _size);
        for (int i = _size - 1; i > 0; --i) {
            this->data[i] = _func(this->data[i + i], this->data[i + i + 1]);
        }
    }

    void id4(int idx) {
        this->data[idx] = _default;
    }

    int id6(int idx) {
        return this->data[idx + _size];
    }

    void id3(int idx, int value) {
        idx += _size;
        this->data[idx] = value;
        idx >>= 1;
        while (idx) {
            this->data[idx] = _func(this->data[2 * idx], this->data[2 * idx + 1]);
            idx >>= 1;
        }
    }

    int id11() {
        return _len;
    }

    int query(int start, int stop) {
        if (start == stop) return id6(start);
        stop++;
        start += _size;
        stop += _size;

        int res = _default;
        while (start < stop) {
            if (start & 1) {
                res = _func(res, data[start]);
                start++;
            }
            if (stop & 1) {
                stop--;
                res = _func(res, data[stop]);
            }
            start >>= 1;
            stop >>= 1;
        }
        return res;
    }

    string id2() {
        return "SegmentTree(" + to_string(data) + ")";
    }
};

class Factorial {
private:
    int MOD;
    vector<int> factorials, invModulos, invFactorial_;

public:
    Factorial(int MOD) : MOD(MOD) {
        factorials = {1, 1};
        invModulos = {0, 1};
        invFactorial_ = {1, 1};
    }

    int calc(int n) {
        if (n < 0) {
            cerr << "Invalid argument to calculate n!" << endl;
            exit(1);
        }
        if (n < factorials.size()) return factorials[n];
        int initialI = factorials.size();
        int prev = factorials.back();
        factorials.resize(n + 1);
        for (int i = initialI; i <= n; ++i) {
            prev = factorials[i] = prev * i % MOD;
        }
        return factorials[n];
    }

    int inv(int n) {
        if (n < 0) {
            cerr << "Invalid argument to calculate n^(-1)" << endl;
            exit(1);
        }
        if (n < invModulos.size()) return invModulos[n];
        int initialI = invModulos.size();
        for (int i = initialI; i < min(MOD, n + 1); ++i) {
            invModulos.push_back(-invModulos[MOD % i] * (MOD / i) % MOD);
        }
        return invModulos[n % MOD];
    }

    int id10(int n) {
        if (n < 0) {
            cerr << "Invalid argument to calculate (n^(-1))!" << endl;
            exit(1);
        }
        if (n < invFactorial_.size()) return invFactorial_[n];
        inv(n);
        int initialI = invFactorial_.size();
        int prev = invFactorial_.back();
        invFactorial_.resize(n + 1);
        for (int i = initialI; i <= n; ++i) {
            prev = invFactorial_[i] = (prev * invModulos[i % MOD]) % MOD;
        }
        return invFactorial_[n];
    }
};

class Combination {
private:
    int MOD;
    Factorial factorial;

public:
    Combination(int MOD) : MOD(MOD), factorial(MOD) {}

    int ncr(int n, int k) {
        if (k < 0 || n < k) return 0;
        k = min(k, n - k);
        return factorial.calc(n) * factorial.id10(max(n - k, k)) % MOD * factorial.id10(min(k, n - k)) % MOD;
    }
};

int powm(int a, int n, int m) {
    if (a == 1 || n == 0) return 1;
    if (n % 2 == 0) {
        int s = powm(a, n / 2, m);
        return s * s % m;
    } else {
        return a * powm(a, n - 1, m) % m;
    }
}

vector<int> sort_list(vector<int>& list1, vector<int>& list2) {
    vector<pair<int, int>> id5;
    for (size_t i = 0; i < list2.size(); ++i) {
        id5.emplace_back(list2[i], list1[i]);
    }
    sort(id5.begin(), id5.end());
    vector<int> z;
    for (auto& p : id5) {
        z.push_back(p.second);
    }
    return z;
}

int product(const vector<int>& l) {
    int por = 1;
    for (int i : l) {
        por *= i;
    }
    return por;
}

int id9(const vector<int>& arr, int n, int key) {
    int left = 0, right = n - 1, count = 0;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] <= key) {
            count = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countdig(int n) {
    int c = 0;
    while (n > 0) {
        n /= 10;
        c++;
    }
    return c;
}

int countGreater(const vector<int>& arr, int n, int k) {
    int l = 0, r = n - 1;
    int leftGreater = n;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] >= k) {
            leftGreater = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return (n - leftGreater);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        l[i] %= k;
    }
    if (n == 1) {
        cout << l[0] << endl;
        return 0;
    }
    vector<int> l1(l.begin(), l.begin() + n / 2);
    vector<int> l2(l.begin() + n / 2, l.end());
    set<int> s, s1, s2;
    for (int i = 0; i < n / 2; ++i) {
        for (int j : s) {
            s2.insert((j + l1[i]) % k);
        }
        s.insert(l1[i]);
        for (int j : s2) {
            s.insert(j);
        }
        s2.clear();
    }
    for (int i = 0; i < n - n / 2; ++i) {
        for (int j : s1) {
            s2.insert((j + l2[i]) % k);
        }
        s1.insert(l2[i]);
        for (int j : s2) {
            s1.insert(j);
        }
        s2.clear();
    }
    vector<int> s_vec(s.begin(), s.end());
    vector<int> s1_vec(s1.begin(), s1.end());
    sort(s_vec.begin(), s_vec.end());
    sort(s1_vec.begin(), s1_vec.end());
    int ans = max(max(s_vec), max(s1_vec));
    for (size_t i = 0; i < s_vec.size(); ++i) {
        int t = k - 1 - s_vec[i];
        int ind = id9(s1_vec, s1_vec.size(), t);
        int r = s1_vec[ind - 1];
        int rt = s1_vec.back();
        ans = max({(r + s_vec[i]) % k, (s_vec[i] + rt) % k, ans});
    }
    cout << ans << endl;
    return 0;
}
