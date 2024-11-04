#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mod1 = 998244353;

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

    TreeNode(int k, int v) : key(k), value(v), left(nullptr), right(nullptr), parent(nullptr), height(1), num_left(1), num_total(1) {}
};

class id8 {
private:
    TreeNode* _tree;

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
        node->num_total = 1 + id1(node->left) + id1(node->right);
        node->num_left = 1 + id1(node->left);
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
        node->num_total = 1 + id1(node->left) + id1(node->right);
        node->num_left = 1 + id1(node->left);
    }

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

    static bool _is_leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    static TreeNode* _get_next(TreeNode* node) {
        if (!node->right) return node->parent;
        TreeNode* n = node->right;
        while (n->left) {
            n = n->left;
        }
        return n;
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

    static bool _is_left(TreeNode* node) {
        return node->parent->left == node;
    }
};

class SegmentTree {
private:
    vector<int> data;
    int _default, _len, _size;

public:
    SegmentTree(vector<int>& arr, int default_value = 0, function<int(int, int)> func = [](int a, int b) { return max(a, b); }) {
        _default = default_value;
        _len = arr.size();
        _size = 1 << (_len - 1).bit_length();
        data.assign(2 * _size, default_value);
        copy(arr.begin(), arr.end(), data.begin() + _size);
        for (int i = _size - 1; i > 0; --i) {
            data[i] = func(data[i + i], data[i + i + 1]);
        }
    }

    void update(int idx, int value) {
        idx += _size;
        data[idx] = value;
        while (idx > 1) {
            idx >>= 1;
            data[idx] = max(data[2 * idx], data[2 * idx + 1]);
        }
    }

    int query(int start, int stop) {
        if (start == stop) return data[start + _size];
        stop += 1;
        start += _size;
        stop += _size;

        int res = _default;
        while (start < stop) {
            if (start & 1) {
                res = max(res, data[start]);
                start += 1;
            }
            if (stop & 1) {
                stop -= 1;
                res = max(res, data[stop]);
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
        s.update(ind[i], mw);
    }

    for (int i = 0; i < m; ++i) {
        cnt_pairs[i] = {cnt_pairs[i].first, -cnt_pairs[i].second};
    }
    sort(cnt_pairs.begin(), cnt_pairs.end());
    for (int i = 0; i < m; ++i) {
        ind[-cnt_pairs[i].second] = i;
    }

    for (int i = m - 1; i >= 0; --i) {
        int mw = s1.query(0, ind[i]) + 1;
        fi[i] += mw;
        l1[ind[i]] = mw;
        s1.update(ind[i], mw);
    }
    cout << *max_element(fi.begin(), fi.end()) - 1 << endl;

    return 0;
}
