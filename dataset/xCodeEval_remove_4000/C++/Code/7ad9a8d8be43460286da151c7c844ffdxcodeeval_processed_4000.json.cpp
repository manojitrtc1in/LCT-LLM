

using namespace std;
using ll = long long;

template<typename ValueType, typename Comparator = std::less<ValueType>>
class Set {
 public:
    
    Set(Comparator _comp = Comparator());

    
    template<typename InputIterator>
    Set(InputIterator first, InputIterator last, Comparator _comp = Comparator());

    
    Set(std::initializer_list<ValueType> input
            , Comparator _comp = Comparator());

    
    ~Set();

    
    Set(const Set & other);
    Set& operator = (const Set & other);

                     
    class iterator;

    
    using reverse_iterator = std::reverse_iterator<iterator>;

    
    iterator insert(const ValueType & key);

    
    bool erase(const ValueType & key);

    
    iterator erase(iterator where);

    
    iterator find(const ValueType & key) const;

    
    iterator begin() const;
    iterator end() const;

    
    reverse_iterator rbegin() const;
    reverse_iterator rend() const;

    
    iterator lower_bound(const ValueType & key) const;

    
    size_t size() const;

    
    bool empty() const;

    
    void swap(Set & other);

 private:
    
    struct Node {
        ValueType value;  


        
        Node * left, * right;

        
        Node * parent;

        
        Node * next, * prev;

        
        Node(const ValueType & key);
    };

    
    Node * head, * tail;

    
    mutable Node * root;

    
    Comparator comp;

    
    size_t id0;

    
    template<typename DerivedType, typename Pointer, typename Reference>
    class IteratorBase;
    template<typename DerivedType, typename Pointer, typename Reference>
    friend class IteratorBase;

    
    friend class iterator;

    
    void rotateUp(Node * child) const;

    
    void splay(Node * where) const;

    
    std::pair<Node*, Node*> findNode(const ValueType & key) const;

    
    Node * mergeTrees(Node * left, Node * right) const;

    
    static Node * cloneTree(Node * toClone, Node * parent);

    
    static Node * update_links(Node * root, Node * id1);
};

template<typename ValueType, typename Comparator>
template<typename DerivedType, typename Pointer, typename Reference>
class Set<ValueType, Comparator>::IteratorBase {
 public:
    
    using Node = typename Set<ValueType, Comparator>::Node;

    DerivedType& operator++ () {
        curr = curr->next;
        return static_cast<DerivedType&>(*this);
    }

    const DerivedType operator++ (int) {
        DerivedType result = static_cast<DerivedType&>(*this);
        ++(*this);
        return result;
    }

    DerivedType& operator-- () {
        
        if (curr == nullptr) {
            curr = owner->tail;
        } else {
            curr = curr->prev;
        }
        return static_cast<DerivedType&>(*this);
    }

    const DerivedType operator-- (int) {
        DerivedType result = static_cast<DerivedType&>(*this);
        --(*this);
        return result;
    }

    template<typename DerivedType2, typename Pointer2, typename Reference2>
    bool operator == (const IteratorBase<DerivedType2, Pointer2, Reference2>& rhs) const {
        return (owner == rhs.owner) && (curr == rhs.curr);
    }

    template<typename DerivedType2, typename Pointer2, typename Reference2>
    bool operator != (const IteratorBase<DerivedType2, Pointer2, Reference2>& rhs) const {
        return (owner != rhs.owner) || (curr != rhs.curr);
    }

    
    const Reference operator * () const {
        return curr->value;
    }

    
    Pointer operator-> () const {
        
        return &**this;
    }

 protected:
    
    const Set * owner;
    
    Node * curr;

    template<typename Derived2, typename Pointer2, typename Reference2>
    friend class IteratorBase;

    
    IteratorBase(const Set * _owner = nullptr, Node * _curr = nullptr)
            : owner(_owner), curr(_curr) {}
};

template<typename ValueType, typename Comparator>
class Set<ValueType, Comparator>::iterator:
    public std::iterator<std::bidirectional_iterator_tag, ValueType>,
    public IteratorBase<iterator, ValueType*, ValueType&> {
 public:
    iterator() {}

 private:
    
    iterator(const Set *  _owner,
             typename Set<ValueType, Comparator>::Node * _node)
        : IteratorBase<iterator, ValueType*, ValueType&>(_owner, _node) {}

    friend class Set;
};


template<typename ValueType, typename Comparator>
Set<ValueType, Comparator>::Node::Node(const ValueType & key)
    : value(key) {}

template<typename ValueType, typename Comparator>
Set<ValueType, Comparator>::Set(Comparator _comp)
    : comp(_comp) {
    head = tail = root = nullptr;
    id0 = 0;
}

template<typename ValueType, typename Comparator>
template<typename InputIterator>
Set<ValueType, Comparator>::Set(InputIterator first
        , InputIterator last, Comparator _comp) : comp(_comp) {
    head = tail = root = nullptr;
    id0 = 0;
    for (auto it = first; it != last; ++it) {
        insert(*it);
    }
}

template<typename ValueType, typename Comparator>
Set<ValueType, Comparator>::Set(
        std::initializer_list<ValueType> input, Comparator _comp)
            : comp(_comp) {
    head = tail = root = nullptr;
    id0 = 0;
    for (auto it = input.begin(); it != input.end(); ++it)
        insert(*it);
}


template<typename ValueType, typename Comparator>
Set<ValueType, Comparator>::~Set() {
    Node * curr = head;
    while (curr != nullptr) {
        Node * next = curr->next;
        delete curr;
        curr = next;
    }
}


template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::iterator
Set<ValueType, Comparator>::insert(const ValueType & key) {
    Node * lastLeft = nullptr, * lastRight = nullptr;
    Node **curr = &root;
    Node * id3 = nullptr;

    while (*curr != nullptr) {
        id3 = *curr;
        if (comp(key, (*curr)->value)) {
            lastLeft = *curr;
            curr = &((*curr)->left);
        } else {
            if (comp((*curr)->value, key)) {
                lastRight = *curr;
                curr = &((*curr)->right);
            } else {
                splay(*curr);
                return end();
            }
        }
    }

    Node *to_insert = new Node(key);
    to_insert->parent = id3;
    *curr = to_insert;

    to_insert->left = nullptr;
    to_insert->right = nullptr;
    to_insert->next = lastLeft;
    to_insert->prev = lastRight;

    if (to_insert->next != nullptr) {
        to_insert->next->prev = to_insert;
    } else {
        tail = to_insert;
    }

    if (to_insert->prev != nullptr) {
        to_insert->prev->next = to_insert;
    } else {
        head = to_insert;
    }

    splay(to_insert);
    ++id0;
    return iterator(this, to_insert);
}

template<typename ValueType, typename Comparator>
void Set<ValueType, Comparator>::rotateUp(Node * node) const {
    Node * child, * id2;
    if (node != node->parent->left) {
        child = node->left;
        id2 = node->parent;

        node->parent = id2->parent;
        node->left = id2;

        id2->right = child;
    } else {
        child = node->right;
        id2 = node->parent;

        node->parent = id2->parent;
        node->right = id2;

        id2->left = child;
    }
    if (child != nullptr)
        child->parent = id2;

    if (id2->parent != nullptr) {
        if (id2 != id2->parent->left)
            id2->parent->right = node;
        else
            id2->parent->left = node;
    } else {
        root = node;
    }

    id2->parent = node;
}

template<typename ValueType, typename Comparator>
void Set<ValueType, Comparator>::splay(Node * node) const {
    while (node != nullptr && node->parent != nullptr) {
        Node * id2 = node->parent;

        if (id2->parent == nullptr) {
            rotateUp(node);
        } else if ((id2->parent->left == id2)
                == (node->parent->left == node)) {
            rotateUp(id2);
            rotateUp(node);
        } else {
            rotateUp(node);
            rotateUp(node);
        }
    }
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::iterator
Set<ValueType, Comparator>::find(const ValueType & key) const {
    std::pair<Node*, Node*> result = findNode(key);
    splay(result.first == nullptr ? result.second : result.first);
    return iterator(this, result.first);
}

template<typename ValueType, typename Comparator>
std::pair<typename Set<ValueType, Comparator>::Node*,
          typename Set<ValueType, Comparator>::Node*>
Set<ValueType, Comparator>::findNode(const ValueType & key) const {
    Node * curr = root, * prev = nullptr;
    while (curr != nullptr) {
        prev = curr;
        if (comp(key, curr->value))
            curr = curr->left;
        else if (comp(curr->value, key))
            curr = curr->right;
        else
            return std::make_pair(curr, curr->parent);
    }
    return std::make_pair(nullptr, prev);
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::iterator
Set<ValueType, Comparator>::begin() const {
    return iterator(this, head);
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::iterator
Set<ValueType, Comparator>::end() const {
    return iterator(this, nullptr);
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::reverse_iterator
Set<ValueType, Comparator>::rbegin() const {
    return reverse_iterator(end());
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::reverse_iterator
Set<ValueType, Comparator>::rend() const {
    return reverse_iterator(begin());
}

template<typename ValueType, typename Comparator>
size_t Set<ValueType, Comparator>::size() const {
    return id0;
}

template<typename ValueType, typename Comparator>
bool Set<ValueType, Comparator>::empty() const {
    return (id0 == 0);
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::iterator
Set<ValueType, Comparator>::erase(iterator where) {
    Node * node = where.curr;
    splay(node);

    Node * lhs = node->left;
    Node * rhs = node->right;

    if (lhs != nullptr)
        lhs->parent = nullptr;
    if (rhs != nullptr)
        rhs->parent = nullptr;

    root = mergeTrees(lhs, rhs);
    if (node->next != nullptr)
        node->next->prev = node->prev;
    else
        tail = node->prev;
    if (node->prev != nullptr)
        node->prev->next = node->next;
    else
        head = node->next;

    iterator result(this, node->next);
    delete node;
    --id0;
    return result;
}

template<typename ValueType, typename Comparator>
bool Set<ValueType, Comparator>::erase(const ValueType & key) {
    iterator where = find(key);
    if (where == end())
        return false;

    erase(where);
    return true;
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::Node *
Set<ValueType, Comparator>::mergeTrees(Node * lhs, Node * rhs) const {
    if (lhs == nullptr)
        return rhs;
    if (rhs == nullptr)
        return lhs;

    Node * max_elem = lhs;
    while (max_elem->right != nullptr)
        max_elem = max_elem->right;

    splay(max_elem);
    max_elem->right = rhs;
    rhs->parent = max_elem;

    return max_elem;
}

template<typename ValueType, typename Comparator>
Set<ValueType, Comparator>::Set(const Set & other) {
    id0 = other.id0;
    comp = other.comp;
    root = cloneTree(other.root, nullptr);
    update_links(root, nullptr);
    tail = head = root;
    while ((head != nullptr) && (head->left != nullptr)) {
        head = head->left;
    }
    while ((tail != nullptr) && (tail->right != nullptr)) {
        tail = tail->right;
    }
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::Node *
Set<ValueType, Comparator>::cloneTree(Node * toClone, Node * parent) {
    if (toClone == nullptr)
        return nullptr;

    Node * result = new Node(toClone->value);
    result->left = cloneTree(toClone->left, result);
    result->right = cloneTree(toClone->right, result);
    result->parent = parent;

    return result;
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::Node *
Set<ValueType, Comparator>::update_links(
        Node * root, Node * id1) {
    if (root == nullptr)
        return id1;

    id1 = update_links(root->left, id1);
    root->prev = id1;
    if (id1 != nullptr)
        id1->next = root;
    root->next = nullptr;
    return update_links(root->right, root);
}

template<typename ValueType, typename Comparator>
Set<ValueType, Comparator>&
Set<ValueType, Comparator>::operator = (const Set & other) {
    Set clone = other;
    swap(clone);
    return *this;
}

template<typename ValueType, typename Comparator>
void Set<ValueType, Comparator>::swap(Set & other) {
    std::swap(root, other.root);
    std::swap(id0, other.id0);
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(comp, other.comp);
}

template<typename ValueType, typename Comparator>
typename Set<ValueType, Comparator>::iterator
Set<ValueType, Comparator>::lower_bound(const ValueType & key) const {
    if (empty())
        return end();

    std::pair<Node*, Node*> result = findNode(key);
    splay(result.first == nullptr ? result.second : result.first);

    if (result.first !=  nullptr)
        return iterator(this, result.first);

    if (comp(result.second->value, key))
        result.second = result.second->next;

    return iterator(this, result.second);
}



const int N = 245678;

int mx[N], a[N], b[N];
vector<int> e[N];
int main() {
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        mx[a[i]] = b[i];
        e[a[i]].push_back(b[i]);
    }
    Set<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
        sort(e[i].begin(), e[i].end());
        if (mx[i]) s.insert({mx[i], i});
    }
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int w[k];
        for (int i = 0; i < k; ++i) {
            cin >> w[i];
            if (!mx[w[i]]) continue;
            s.erase({mx[w[i]], w[i]});
        }
        if (s.empty()) {
            cout << 0 << " " << 0 << '\n';
            for (int i = 0; i < k; ++i) {
                if (!mx[w[i]]) continue;
                s.insert({mx[w[i]], w[i]});
            }
            continue;
        }
        auto ita = s.end();
        --ita;
        int v = ita->second;
        s.erase({mx[v], v});
        if (s.empty()) {
            cout << v << " " << e[v][0] << '\n';
            s.insert({mx[v], v});
            for (int i = 0; i < k; ++i) {
                if (!mx[w[i]]) continue;
                s.insert({mx[w[i]], w[i]});
            }
            continue;
        }
        auto ita1 = s.end();
        ita1--;
        int top = ita1->first;
        int j = upper_bound(e[v].begin(), e[v].end(), top) - e[v].begin();
        cout << v << " " << e[v][j] << '\n';
        s.insert({mx[v], v});
        for (int i = 0; i < k; ++i) {
            if (!mx[w[i]]) continue;
            s.insert({mx[w[i]], w[i]});
        }
    }
}