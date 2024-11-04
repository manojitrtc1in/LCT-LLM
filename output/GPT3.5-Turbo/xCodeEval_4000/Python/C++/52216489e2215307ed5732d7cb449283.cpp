#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <functional>
#include <numeric>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define all(c) c.begin(),c.end()
#define F first
#define S second
#define sz(a) (int)a.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define endl "\n"
#define INF 1e18
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

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
        return nullptr;
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
            if (is_left(node)) {
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
            if (is_left(node)) {
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

    TreeNode* _get_next(TreeNode* node) {
        if (!node->right) {
            return node->parent;
        }
        TreeNode* n = node->right;
        while (n->left) {
            n = n->left;
        }
        return n;
    }

    bool is_left(TreeNode* node) {
        return node->parent && node->parent->left && node->parent->left == node;
    }

    bool is_leaf(TreeNode* node) {
        return !node->left && !node->right;
    }

    void _rotate_right(TreeNode* node) {
        if (!node->parent) {
            _tree = node->left;
            if (_tree) {
                _tree->parent = nullptr;
            }
        }
        else if (is_left(node)) {
            node->parent->left = node->left;
            node->left->parent = node->parent;
        }
        else {
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
            if (_tree) {
                _tree->parent = nullptr;
            }
        }
        else if (is_left(node)) {
            node->parent->left = node->right;
            node->right->parent = node->parent;
        }
        else {
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

    void remove(int k) {
        TreeNode* node = _get_node(k);
        if (!node) {
            return;
        }
        if (is_leaf(node)) {
            _remove_leaf(node);
            return;
        }
        if (node->left && node->right) {
            TreeNode* nxt = _get_next(node);
            node->key = nxt->key;
            node->value = nxt->value;
            if (is_leaf(nxt)) {
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

    pii get_at(int pos) {
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
                return mp(node->key, node->value);
            }
        }
        throw out_of_range("Out of ranges");
    }
};

class SegmentTree {
private:
    vector<int> data;
    int _default;
    function<int(int, int)> _func;
    int _len;
    int _size;

    void build(int idx, int start, int stop, vector<int>& arr) {
        if (start == stop) {
            data[idx] = arr[start];
            return;
        }
        int mid = (start + stop) / 2;
        build(2 * idx, start, mid, arr);
        build(2 * idx + 1, mid + 1, stop, arr);
        data[idx] = _func(data[2 * idx], data[2 * idx + 1]);
    }

    void update(int idx, int start, int stop, int pos, int value) {
        if (start == stop) {
            data[idx] = value;
            return;
        }
        int mid = (start + stop) / 2;
        if (pos <= mid) {
            update(2 * idx, start, mid, pos, value);
        }
        else {
            update(2 * idx + 1, mid + 1, stop, pos, value);
        }
        data[idx] = _func(data[2 * idx], data[2 * idx + 1]);
    }

    int query(int idx, int start, int stop, int left, int right) {
        if (left > right) {
            return _default;
        }
        if (start == left && stop == right) {
            return data[idx];
        }
        int mid = (start + stop) / 2;
        int left_val = query(2 * idx, start, mid, left, min(right, mid));
        int right_val = query(2 * idx + 1, mid + 1, stop, max(left, mid + 1), right);
        return _func(left_val, right_val);
    }

public:
    SegmentTree(vector<int>& arr, int default_val, function<int(int, int)> func) {
        _default = default_val;
        _func = func;
        _len = arr.size();
        _size = 1 << (int)ceil(log2(_len));
        data.resize(2 * _size);
        build(1, 0, _len - 1, arr);
    }

    void update(int pos, int value) {
        update(1, 0, _len - 1, pos, value);
    }

    int query(int left, int right) {
        return query(1, 0, _len - 1, left, right);
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a - 1]++;
        cnt[b]--;
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<int> l(m, 0);
    vector<int> l1(m, 0);
    vector<pair<int, int>> cnt_pairs;
    for (int i = 0; i <= m; i++) {
        cnt_pairs.push_back(make_pair(cnt[i], i));
    }
    sort(all(cnt_pairs));
    unordered_map<int, int> ind;
    for (int i = 0; i < sz(cnt_pairs); i++) {
        ind[cnt_pairs[i].second] = i;
    }
    SegmentTree s(l, 0, [](int a, int b) { return max(a, b); });
    SegmentTree s1(l1, 0, [](int a, int b) { return max(a, b); });
    vector<int> cou(m, 0);
    int cur = 0;
    int cur1 = 0;
    vector<int> fi(m, 0);
    for (int i = 0; i < m; i++) {
        int mw = s.query(0, ind[i]) + 1;
        l[ind[i]] = mw;
        fi[i] = mw;
        cur1 = max(cur1, mw);
        s.update(ind[i], mw);
    }
    cnt_pairs.clear();
    for (int i = 0; i <= m; i++) {
        cnt_pairs.push_back(make_pair(cnt[i], -i));
    }
    sort(all(cnt_pairs));
    cnt_pairs.clear();
    for (int i = 0; i <= m; i++) {
        cnt_pairs.push_back(make_pair(cnt[i], -i));
    }
    for (int i = 0; i < sz(cnt_pairs); i++) {
        ind[cnt_pairs[i].second] = i;
    }
    for (int i = m - 1; i >= 0; i--) {
        int mw = s1.query(0, ind[i]) + 1;
        fi[i] += mw;
        l1[ind[i]] = mw;
        s1.update(ind[i], mw);
    }
    cout << *max_element(all(fi)) - 1 << endl;

    return 0;
}
