#include <bits/stdc++.h>

using namespace std;

template<typename T>
class AVLTree{
private:
    struct Node{
        T data;
        int height, cnt;
        Node *left, *right;
        Node(T _data):
            data(_data),
            left(nullptr),
            right(nullptr),
            height(1),
            cnt(1)
            {}
    } *root;

    void recalc_height(Node *node){
        if (node == nullptr) return;
        int lft = 0;
        if (node->left != nullptr) lft = node->left->height;
        int rght = 0;
        if (node->right != nullptr) rght = node->right->height;
        node->height = max(lft, rght) + 1;
    }

    Node *rotate_right(Node *node){
        if (node->left == nullptr) return node;
        Node *lft = node->left;
        node->left = lft->right;
        lft->right = node;
        recalc_height(lft->right);
        recalc_height(lft);
        return lft;
    }

    Node *rotate_left(Node *node){
        if (node->right == nullptr) return node;
        Node *rght = node->right;
        node->right = rght->left;
        rght->left = node;
        recalc_height(rght->left);
        recalc_height(rght);
        return rght;
    }

    int balance(Node *node){
        int lft = 0;
        if (node->left != nullptr) lft = node->left->height;
        int rght = 0;
        if (node->right != nullptr) rght = node->right->height;
        return (lft - rght);
    }

    bool is_balanced(Node *node){
        if (node == nullptr) return true;
        return (abs(balance(node)) < 2);
    }

    Node* insert_node(Node* node, T data){
        if (node == nullptr){
            return new Node(data);
        }
        if (node->data == data){
            ++ node->cnt;
            return node;
        }
        if (data > node->data){
            node->right = insert_node(node->right, data);
        }else{
            node->left = insert_node(node->left, data);
        }
        if (!is_balanced(node)){
            bool lft1 = false, lft2 = false;
            Node *child = nullptr, *grandchild = nullptr;
            if (data > node->data){
                child = node->right;
            }else{
                lft1 = true;
                child = node->left;
            }
            if (data > child->data){
                grandchild = child->right;
            }else{
                lft2 = true;
                grandchild = child->left;
            }
            if (lft1){
                if (lft2){
                    return rotate_right(node);
                }else{
                    node->left = rotate_left(node->left);
                    return rotate_right(node);
                }
            }else{
                if (lft2){
                    node->right = rotate_right(node->right);
                    return rotate_left(node);
                }else{
                    return rotate_left(node);
                }
            }
        }
        recalc_height(node);
        return node;
    }

    Node *delete_node(Node *node, T data){
        if (node == nullptr) return node;
        if (node -> data < data){
            node->right = delete_node(node->right, data);
        }else{
            if (node -> data > data){
                node->left = delete_node(node->left, data);
            }else{
                if (node->cnt > 1){
                    node->cnt --;
                    return node;
                }else{
                    if (node->right == nullptr || node->left == nullptr) {
                        Node *tmp = node->right;
                        if (tmp == nullptr) tmp = node->left;
                        if (tmp == nullptr) {
                            tmp = node;
                            node = nullptr;
                        } else *node = *tmp;
                        free(tmp);
                    } else {
                        Node *rght = node->right;
                        while (rght->left != nullptr) {
                            rght = rght->left;
                        }
                        node->data = rght->data;
                        node->right = delete_node(node->right, node->data);
                    }
                }
            }
        }
        if (node == nullptr){
            return node;
        }
        node->height --;
        if (!is_balanced(node)){
            bool lft1 = false, lft2 = false;
            Node *child = nullptr;
            if (balance(node) > 0){
                lft1 = true;
                child = node->left;
            }else child = node->right;
            if (balance(child) > 0){
                lft2 = true;
            }
            if (lft1){
                if (lft2){
                    return rotate_right(node);
                }else{
                    node->left = rotate_left(node->left);
                    return rotate_right(node);
                }
            }else{
                if (lft2){
                    node->right = rotate_right(node->right);
                    return rotate_left(node);
                }else{
                    return rotate_left(node);
                }
            }
        }
        recalc_height(node);
        return node;
    }

    void print_inorder(Node *node){
        if (node == nullptr) return;
        print_inorder(node->left);
        cout << node->data << ' ';
        print_inorder(node->right);
    }

    int count(Node *node, T data){
        if (node == nullptr) return 0;
        if (node->data == data) return node->cnt;
        if (data > node->data) return count(node->right, data);
        else return count(node->left, data);
    }

    T get_rightest(Node *node){
        if (node->right == nullptr) return node->data;
        else return get_rightest(node->right);
    }

public:
    AVLTree():
        root(nullptr)
        {}

    void add(T data){
        root = insert_node(root, data);
    }

    void remove(T data){
        root = delete_node(root, data);
    }

    void print_inorder(){
        print_inorder(root);
        cout << '\n';
    }

    int count(T data){
        return count(root, data);
    }

    T max_element(){
        return get_rightest(root);
    }

};

class Kruskal{
private:
    vector < int > parent, sz;
    int find_head(int v){
        if (parent[v] == v) return v;
        return parent[v] = find_head(parent[v]);
    }
public:
    Kruskal(){

    }

    long long mst_mass(vector<tuple<int,int,int>> &edges, int n){
        parent.resize(n+1);
        sz.resize(n+1);
        fill(sz.begin(), sz.end(), 1);
        for (int i=1; i<=n; i++){
            parent[i] = i;
        }
        long long ans = 0;
        for (auto &[c, a, b]: edges){
            int h1 = find_head(a);
            int h2 = find_head(b);
            if (h1 == h2) continue;
            if (sz[h1] > sz[h2]){
                sz[h1] += sz[h2];
                parent[h2] = h1;
            }else{
                sz[h2] += sz[h1];
                parent[h1] = h2;
            }
            ans += c;
        }
        for (int i=2; i<=n; i++){
            if (find_head(i) != find_head(i-1)) return -1;
        }
        return ans;
    }
};

template<typename T>
class RBTree{
    enum NODE_COLOR{
        RED, BLACK
    };
    struct Node{
        T val;
        Node *lft, *rght, *parent;
        NODE_COLOR color;
        Node(T _val):
            val(_val),
            lft(nullptr),
            rght(nullptr),
            parent(nullptr),
            color(RED)
        {}
        bool is_left(){
            return (this->parent != nullptr && this == this->parent->lft);
        }
    } *root;
    int size;

    void rotate_right(Node *node){
        if (node == nullptr) return;
        Node *lft = node->lft;
        if (lft == nullptr) return;
        Node *LR = lft->rght;
        lft->rght = node;
        lft->parent = node->parent;
        node->parent = lft;
        node->lft = LR;
        if (LR != nullptr){
            LR->parent = node;
        }
        if (lft->parent != nullptr){
            if (lft->val < lft->parent->val){
                lft->parent->lft = lft;
            }else{
                lft->parent->rght = lft;
            }
        }
    }

    void rotate_left(Node *node){
        if (node == nullptr) return;
        Node *rght = node->rght;
        if (rght == nullptr) return;
        Node *RL = rght->lft;
        rght->lft = node;
        rght->parent = node->parent;
        node->parent = rght;
        node->rght = RL;
        if (RL != nullptr){
            RL->parent = node;
        }
        if (rght->parent != nullptr){
            if (rght->val < rght->parent->val){
                rght->parent->lft = rght;
            }else{
                rght->parent->rght = rght;
            }
        }
    }

    bool is_red(Node *node){
        return (node != nullptr && node->color == RED);
    }

    void fixRR(Node *node){
        if (node->parent == nullptr){
            node->color = BLACK;
            return;
        }
        Node *parent = node->parent;
        Node *grandparent = parent->parent;
        Node *uncle = (grandparent == nullptr ? nullptr : (parent->is_left() ? grandparent->rght : grandparent->lft));
        if (is_red(parent)) {
            if (is_red(uncle)) {
                parent->color = BLACK;
                uncle->color = BLACK;
                if (grandparent != nullptr) {
                    grandparent->color = RED;
                    fixRR(grandparent);
                }
            } else {
                if (parent->is_left()) { 

                    if (!node->is_left()) { 

                        rotate_left(parent);
                        swap(node->color, grandparent->color);
                    } else {
                        swap(parent->color, grandparent->color);
                    }
                    

                    rotate_right(grandparent);
                } else { 

                    if (node->is_left()) { 

                        rotate_right(parent);
                        swap(node->color, grandparent->color);
                    } else {
                        swap(parent->color, grandparent->color);
                    }
                    

                    rotate_left(grandparent);
                }
            }
        }
    }

    void fixDB(Node *node){
        if (node == root){
            return;
        }
        Node *parent = node->parent;
        Node *sibling = (node->is_left() ? parent->rght : parent->lft);
        if (is_red(sibling)){
            swap(sibling->color, parent->color);
            if (sibling->is_left()){
                rotate_right(sibling);
            }else{
                rotate_left(sibling);
            }
            fixDB(node);
        }else{
            if (sibling == nullptr  || (!is_red(sibling->lft) && !is_red(sibling->rght))){
                if (sibling != nullptr){
                    sibling->color = RED;
                    if (parent->color == BLACK) {
                        fixDB(node->parent);
                    }else{
                        node->parent->color = BLACK;
                    }
                }
            }else{
                if (sibling->is_left()){
                    if (is_red(sibling->lft)){ 

                        sibling->lft->color = sibling->color;
                        sibling->color = parent->color;
                        rotate_right(parent);
                    }else{ 

                        sibling->rght->color = parent->color;
                        rotate_left(sibling);
                        rotate_right(parent);
                    }
                }else{
                    if (is_red(sibling->rght)){ 

                        sibling->rght->color = sibling->color;
                        sibling->color = parent->color;
                        rotate_left(parent);
                    }else{ 

                        sibling->lft->color = parent->color;
                        rotate_right(sibling);
                        rotate_left(parent);
                    }
                }
                parent->color = BLACK;
            }
        }
    }

    Node *find_by_val(T _val){
        Node *node = root;
        while(node != nullptr){
            if (node->val == _val){
                break;
            }
            if (node->val > _val){
                node = node->lft;
            }else{
                node = node->rght;
            }
        }
        return node;
    }

    Node *find_replacement(Node *node){
        if (node == nullptr) return nullptr;
        if (node->lft == nullptr && node->rght == nullptr) return nullptr;
        if (node->lft != nullptr && node->rght != nullptr){
            Node *tmp = node->rght;
            while(tmp->lft != nullptr){
                tmp = tmp->lft;
            }
            return tmp;
        }
        if (node->lft != nullptr) return node->lft;
        else return node->rght;
    }

    void remove_node(Node *node){
        if (node == nullptr) return;
        Node *u = find_replacement(node);
        bool both_are_black = (!is_red(node) && !is_red(u));
        if (u == nullptr){
            if (node == root){
                root = nullptr;
            }else{
                if (both_are_black){
                    fixDB(node);
                }else{
                    Node *sibling = (node->is_left() ? node->parent->rght : node->parent->lft);
                    if (sibling != nullptr){
                        sibling->color = RED;
                    }
                }
                if (node->is_left()){
                    node->parent->lft = nullptr;
                }else{
                    node->parent->rght = nullptr;
                }
            }
            delete node;
            return;
        }

        if (node->lft == nullptr || node->rght == nullptr){
            if (node == root){
                node->val = u->val;
                node->lft = node->rght = nullptr;
                delete u;
            }else{
                if (node->is_left()){
                    node->parent->lft = u;
                }else{
                    node->parent->rght = u;
                }
                u->parent = node->parent;
                delete node;
                if (both_are_black){
                    fixDB(u);
                }else{
                    u->color = BLACK;
                }
            }
            return;
        }

        swap(node->val, u->val);
        remove_node(u);
    }

    void print_inorder(Node *node){
        if (node == nullptr) return;
        print_inorder(node->lft);
        cout << node->val << ' ' << (node->color == BLACK ? 'B' : 'R') << ' ' << (node->parent != nullptr ? node->parent->val : -1) << '\n';
        print_inorder(node->rght);
    }

    bool dfs_for_db(Node *node, int cnt_of_black, set<int> &s){
        if (node == nullptr) return true;
        cnt_of_black += (node->color == BLACK);
        bool ok = true;
        if (node->lft == nullptr) {
            s.insert(cnt_of_black);
            if (s.size() > 1) return false;
        }
        ok = (ok && dfs_for_db(node->lft, cnt_of_black, s));
        if (node->rght == nullptr) {
            s.insert(cnt_of_black);
            if (s.size() > 1) return false;
        }
        ok = (ok && dfs_for_db(node->rght, cnt_of_black, s));
        return ok;
    }
public:
    RBTree():
        root(nullptr),
        size(0)
    {}

    void add(T _val){
        if (contains(_val)) return;
        ++ size;
        Node *new_node = new Node(_val);
        if (root == nullptr){
            root = new_node;
            root->color = BLACK;
        }else{
            Node *parent = root;
            while(new_node->parent == nullptr){
                if (parent->val < _val){
                    if (parent->rght == nullptr){
                        parent->rght = new_node;
                        new_node->parent = parent;
                        break;
                    }else{
                        parent = parent->rght;
                    }
                }else{
                    if (parent->lft == nullptr){
                        parent->lft = new_node;
                        new_node->parent = parent;
                        break;
                    }else{
                        parent = parent->lft;
                    }
                }
            }
            fixRR(new_node);
            while(root->parent != nullptr){
                root = root->parent;
            }
        }
    }

    void remove(T _val){
        if (root == nullptr) return;
        if (!contains(_val)) return;
        -- size;
        Node *v = find_by_val(_val);
        remove_node(v);
    }

    bool contains(T _val){
        return (find_by_val(_val) != nullptr);
    }

    int get_size(){
        return size;
    }

    void print(){
        cout << "Inorder traversal:\n";
        print_inorder(root);
        cout << '\n';
    }

    bool check_for_rr(){
        if (root == nullptr) return true;
        queue < Node* > q;
        q.push(root);
        while(!q.empty()){
            Node *v = q.front();
            q.pop();
            if (is_red(v) && is_red(v->lft)) return false;
            if (is_red(v) && is_red(v->rght)) return false;
            if (v->lft != nullptr){
                q.push(v->lft);
            }
            if (v->rght != nullptr){
                q.push(v->rght);
            }
        }
        return true;
    }

    bool check_for_db(){
        set < int > s;
        return dfs_for_db(root, 0, s);
    }

};

int main1() {
    int x;
    char t;
    RBTree < int > tree;
    while(cin >> t >> x){
        if (t == '+'){
            tree.add(x);
        }else{
            tree.remove(x);
        }
        tree.print();
        if (!tree.check_for_db()){
            cout << "Black distance rule violated!\n";
        }
        if (!tree.check_for_rr()){
            cout << "Red->Red rule violated!\n";
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        string s;
        cin >> s;
        RBTree < char > ss;
        for (char c: s) {
            ss.add(c);
        }
        cout << s.length() + ss.get_size() << '\n';
    }
    return 0;
}
