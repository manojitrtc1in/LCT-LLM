#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MOD1 = 998244353;

class FastIO {
public:
    FastIO() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
};

class TreeNode {
public:
    int key, value, height, num_left, num_total;
    TreeNode *left, *right, *parent;

    TreeNode(int k, int v) : key(k), value(v), height(1), num_left(1), num_total(1), left(nullptr), right(nullptr), parent(nullptr) {}
};

class AvlTree {
private:
    TreeNode* _tree;

    static int get_height(TreeNode* x) {
        return x ? x->height : 0;
    }

    static int get_num_total(TreeNode* x) {
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

    void _rotate_right(TreeNode* node) {
        if (!node->parent) {
            _tree = node->left;
            node->left->parent = nullptr;
        } else if (node->parent->left == node) {
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
            node->right->parent = nullptr;
        } else if (node->parent->left == node) {
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
        if (bk) {
            bk->parent = node;
        }
        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        node->num_total = 1 + get_num_total(node->left) + get_num_total(node->right);
        node->num_left = 1 + get_num_total(node->left);
    }

public:
    AvlTree() : _tree(nullptr) {}

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

    void remove(int k) {
        TreeNode* node = _get_node(k);
        if (!node) {
            return;
        }
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
        if (!_tree) {
            return nullptr;
        }
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

    static bool _is_leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
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

class SegmentTree {
private:
    vector<int> data;
    int _default;
    function<int(int, int)> _func;
    int _len, _size;

public:
    SegmentTree(const vector<int>& arr, int default_val = 0, function<int(int, int)> func = [](int a, int b) { return max(a, b); }) 
        : _default(default_val), _func(func), _len(arr.size()), _size(1 << (arr.size() - 1).bit_length()) {
        data.assign(2 * _size, default_val);
        copy(arr.begin(), arr.end(), data.begin() + _size);
        for (int i = _size - 1; i > 0; --i) {
            data[i] = _func(data[i + i], data[i + i + 1]);
        }
    }

    void set(int idx, int value) {
        idx += _size;
        data[idx] = value;
        while (idx > 1) {
            idx >>= 1;
            data[idx] = _func(data[2 * idx], data[2 * idx + 1]);
        }
    }

    int query(int start, int stop) {
        if (start == stop) {
            return data[start + _size];
        }
        stop += 1;
        start += _size;
        stop += _size;

        int res = _default;
        while (start < stop) {
            if (start & 1) {
                res = _func(res, data[start++]);
            }
            if (stop & 1) {
                res = _func(res, data[--stop]);
            }
            start >>= 1;
            stop >>= 1;
        }
        return res;
    }
};

int main() {
    FastIO io;
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[a - 1]++;
        cnt[b]--;
    }
    for (int i = 1; i <= m; ++i) {
        cnt[i] += cnt[i - 1];
    }
    vector<int> l(m, 0), l1(m, 0);
    vector<pair<int, int>> cnt_pairs(m);
    for (int i = 0; i < m; ++i) {
        cnt_pairs[i] = {cnt[i], i};
    }
    sort(cnt_pairs.begin(), cnt_pairs.end());
    unordered_map<int, int> ind;
    for (int i = 0; i < cnt_pairs.size(); ++i) {
        ind[cnt_pairs[i].second] = i;
    }
    SegmentTree s(l), s1(l1);
    vector<int> cou(m, 0), fi(m, 0);
    int cur = 0, cur1 = 0;

    for (int i = 0; i < m; ++i) {
        int mw = s.query(0, ind[i]) + 1;
        l[ind[i]] = mw;
        fi[i] = mw;
        cur1 = max(cur1, mw);
        s.set(ind[i], mw);
    }

    for (int i = 0; i < m; ++i) {
        cnt_pairs[i] = {cnt[i], -cnt[i]};
    }
    sort(cnt_pairs.begin(), cnt_pairs.end());
    for (int i = 0; i < cnt_pairs.size(); ++i) {
        ind[-cnt_pairs[i].second] = i;
    }

    for (int i = m - 1; i >= 0; --i) {
        int mw = s1.query(0, ind[i]) + 1;
        fi[i] += mw;
        l1[ind[i]] = mw;
        s1.set(ind[i], mw);
    }
    cout << *max_element(fi.begin(), fi.end()) - 1 << endl;

    return 0;
}
