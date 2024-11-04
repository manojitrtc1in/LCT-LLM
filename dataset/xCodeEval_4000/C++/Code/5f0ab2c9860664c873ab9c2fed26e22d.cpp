# 1 "d.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "d.cpp"
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 1
       
# 12 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/bits/stdc++.h" 1
 #include <bits/stdc++.h>
# 13 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/assoc_container.hpp" 1
 #include <ext/pb_ds/assoc_container.hpp>
# 14 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/tree_policy.hpp" 1
 #include <ext/pb_ds/tree_policy.hpp>
# 15 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2







using namespace std;
using namespace __gnu_pbds;

using ii = pair<long long, long long>;
using vi = vector<long long>;
using vd = vector<long double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
# 50 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
inline long long mod(const long long n, const long long m = ((long long)1e9+7)){
    return (n%m + m)%m;
}


long long gcd(const long long a, const long long b){
    if(a < 0 or b < 0)
        return gcd(abs(a), abs(b));
    if(a == 0)
        return b;
    return gcd(b%a, a);
}


long long lcm(const long long a, const long long b){
    

    return a/gcd(a, b)*b;
}
# 2 "d.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/data-structure/tree/segment-tree.hpp" 1
       



template<typename T>
struct STNodeB {
    T value, lazy = 0;

    STNodeB()
    {
        

    }

    STNodeB(const T value) :
        value(value)
    {
        

    }

    STNodeB(const STNodeB &lhs, const STNodeB &rhs)
    {
        

    }

    
    virtual bool match(const T value) const = 0;

    
    virtual void update(const size_t range) = 0;
};


template<typename Node, typename T>
class SegTreeB
{
public:
    SegTreeB() = delete;

    SegTreeB(const size_t arr_size) :
        tree(4*arr_size), arr_size(arr_size) {}

    SegTreeB(const vector<T> &arr) :
        SegTreeB(arr.size(), arr) {}

    SegTreeB(const size_t arr_size, const vector<T> &arr) :
        tree(4*arr_size), arr_size(arr_size)
    {
        build(0, arr_size-1, 0, arr);
    }

    SegTreeB(const SegTreeB &lhs, const SegTreeB &rhs) :
        SegTreeB(lhs.arr_size)
    {
        assert(lhs.arr_size == rhs.arr_size);
        for(size_t i=0; i<4*arr_size; ++i)
            tree[i] = Node(lhs.tree[i], rhs.tree[i]);
    }

    
    size_t find(const T value)
    {
        return find(0, arr_size-1, 0, value);
    }

    
    T query(const size_t i)
    {
        assert(i < arr_size);
        return query(i, i);
    }

    
    T query(const size_t l, const size_t r)
    {
        assert(l <= r and r < arr_size);
        return query(0, arr_size-1, l, r, 0).value;
    }

    
    void update(const size_t i, const T delta)
    {
        assert(i < arr_size);
        update(i, i, delta);
    }

    
    void update(const size_t l, const size_t r, const T delta)
    {
        assert(l <= r and r < arr_size);
        update(0, arr_size-1, l, r, 0, delta);
    }

private:
    Node build(const size_t l, const size_t r, const size_t pos, const vector<T> &arr)
    {
        if(l == r)
            return tree[pos] = Node(arr[l]);

        size_t mid = (l + r)/2;
        return tree[pos] = Node(build(l, mid, 2*pos+1, arr), build(mid+1, r, 2*pos+2, arr));
    }

    size_t find(const size_t l, const size_t r, const size_t pos, const T value)
    {
        propagate(l, r, pos);

        if(!tree[pos].match(value))
            return arr_size;
        else if(l == r)
            return l;

        size_t mid = (l + r)/2;
        size_t ans = find(l, mid, 2*pos+1, value);
        return ans != arr_size? ans : find(mid+1, r, 2*pos+2, value);
    }

    Node query(const size_t l, const size_t r, const size_t i, const size_t j, const size_t pos)
    {
        propagate(l, r, pos);

        if(l > j or r < i)
            return Node();

        if(l >= i and r <= j)
            return tree[pos];

        size_t mid = (l + r)/2;
        return Node(query(l, mid, i, j, 2*pos+1), query(mid+1, r, i, j, 2*pos+2));
    }

    Node update(const size_t l, const size_t r, const size_t i, const size_t j, const size_t pos, const T delta)
    {
        propagate(l, r, pos);

        if(l > j or r < i)
            return tree[pos];

        if(l >= i and r <= j){
            tree[pos].lazy = delta;
            

            propagate(l, r, pos);
            return tree[pos];
        }

        size_t mid = (l + r)/2;
        return tree[pos] = Node(update(l, mid, i, j, 2*pos+1, delta), update(mid+1, r, i, j, 2*pos+2, delta));
    }

    virtual void propagate(const size_t l, const size_t r, const size_t pos)
    {
        T lazy = tree[pos].lazy;

        if(lazy == 0)
            return;

        tree[pos].update(r - l + 1);

        if(l != r){
            tree[2*pos+1].lazy += lazy;
            tree[2*pos+2].lazy += lazy;
        }
    }

protected:
    vector<Node> tree;
    size_t arr_size;
};


template<typename T>
struct STNodeSB : STNodeB<T> {
    using super_type = STNodeB<T>;
    pair<T, bool> set = {0, false};

    STNodeSB() :
        super_type() {}

    STNodeSB(const T value) :
        super_type(value) {}

    STNodeSB(const STNodeSB &lhs, const STNodeSB &rhs)
    {
        

    }
};


template<typename NodeS, typename T>
class SegTreeSB : public SegTreeB<NodeS, T>
{
public:
    SegTreeSB() = delete;

    SegTreeSB(const size_t arr_size) :
        super_type(arr_size) {}

    SegTreeSB(const vector<T> &arr) :
        super_type(arr) {}

    SegTreeSB(const size_t arr_size, const vector<T> &arr) :
        super_type(arr_size, arr) {}

    SegTreeSB(const SegTreeSB &lhs, const SegTreeSB &rhs) :
        super_type(lhs, rhs) {}

    
    void set(const size_t i, const T value)
    {
        assert(i < this->arr_size);
        set(i, i, value);
    }

    
    void set(const size_t l, const size_t r, const T value)
    {
        assert(l <= r and r < this->arr_size);
        set(0, this->arr_size-1, l, r, 0, value);
    }

private:
    using super_type = SegTreeB<NodeS, T>;

    NodeS set(const size_t l, const size_t r, const size_t i, const size_t j, const size_t pos, const T value)
    {
        propagate(l, r, pos);

        if(l > j or r < i)
            return this->tree[pos];

        if(l >= i and r <= j){
            this->tree[pos].set = {value, true};
            

            propagate(l, r, pos);
            return this->tree[pos];
        }

        size_t mid = (l + r)/2;
        return this->tree[pos] = NodeS(set(l, mid, i, j, 2*pos+1, value), set(mid+1, r, i, j, 2*pos+2, value));
    }

    void propagate(const size_t l, const size_t r, const size_t pos)
    {
        T lazy = this->tree[pos].lazy;
        pair<T, bool> set = this->tree[pos].set;

        if(lazy == 0 and !set.second)
            return;

        this->tree[pos].update(r - l + 1);

        if(l != r){
            if(set.second){
                this->tree[2*pos+1].set = set;
                this->tree[2*pos+2].set = set;

                this->tree[2*pos+1].lazy = 0;
                this->tree[2*pos+2].lazy = 0;
            }
            this->tree[2*pos+1].lazy += lazy;
            this->tree[2*pos+2].lazy += lazy;
        }
    }
};

enum class STKind
{
    RMaxQ,
    RMinQ,
    RSumQ,
    RXorQ,
};

const STKind RMaxQ = STKind::RMaxQ;
const STKind RMinQ = STKind::RMinQ;
const STKind RSumQ = STKind::RSumQ;
const STKind RXorQ = STKind::RXorQ;


template<typename T>
T default_value(STKind k){
    switch(k){
        case RMaxQ:
            return -((long long)1e9+1);
        case RMinQ:
            return ((long long)1e9+1);
        case RSumQ:
            return 0;
        case RXorQ:
            return 0;
        default:
            assert(false);
    }
}


template<typename T>
T merge_values(STKind k, const T lhs, const T rhs){
    switch(k){
        case RMaxQ:
            return max(lhs, rhs);
        case RMinQ:
            return min(lhs, rhs);
        case RSumQ:
            return lhs + rhs;
        case RXorQ:
            return lhs ^ rhs;
        default:
            assert(false);
    }
}


template<STKind K, typename T>
struct STNode : STNodeB<T> {
    using super_type = STNodeB<T>;

    STNode() :
        super_type(default_value<T>(K)) {}

    STNode(const T value) :
        super_type(value) {}

    STNode(const STNode &lhs, const STNode &rhs) :
        super_type(merge_values<T>(K, lhs.value, rhs.value))
    {
        assert(lhs.lazy == 0 and rhs.lazy == 0);
    }

    
    bool match(const T value) const
    {
        switch(K){
            case RMaxQ:
                return this->value >= value;
                

            case RMinQ:
                return this->value <= value;
                

            case RSumQ:
            case RXorQ:
            default:
                assert(false);
        }
    }

    
    void update(const size_t range)
    {
        switch (K){
            case RMaxQ:
            case RMinQ:
                this->value += this->lazy;
                break;
            case RSumQ:
                this->value += range*this->lazy;
                break;
            case RXorQ:
                break;
            default:
                assert(false);
        }
        this->lazy = 0;
    }
};

template<STKind K, typename T>
using SegTree = SegTreeB<STNode<K, T>, T>;


template<STKind K, typename T>
struct STNodeS : STNodeSB<T> {
    using super_type = STNodeSB<T>;

    STNodeS() :
        super_type(default_value<T>(K)) {}

    STNodeS(const T value) :
        super_type(value) {}

    STNodeS(const STNodeS &lhs, const STNodeS &rhs) :
        super_type(merge_values<T>(K, lhs.value, rhs.value))
    {
        assert(lhs.lazy == 0 and rhs.lazy == 0);
        assert(!lhs.set.second and !rhs.set.second);
    }

    
    bool match(const T value) const
    {
        switch(K){
            case RMaxQ:
                return this->value >= value;
                

            case RMinQ:
                return this->value <= value;
                

            case RSumQ:
            case RXorQ:
            default:
                assert(false);
        }
    }

    
    void update(const size_t range)
    {
        if(this->set.second){
            switch (K){
                case RMaxQ:
                case RMinQ:
                    this->value = this->set.first;
                    break;
                case RSumQ:
                    this->value = range*this->set.first;
                    break;
                case RXorQ:
                    this->value = (range%2)*this->set.first;
                    break;
                default:
                    assert(false);
            }
        }

        switch (K){
            case RMaxQ:
            case RMinQ:
                this->value += this->lazy;
                break;
            case RSumQ:
                this->value += range*this->lazy;
                break;
            case RXorQ:
                break;
            default:
                assert(false);
        }

        this->lazy = 0;
        this->set = {0, false};
    }
};

template<STKind K, typename T>
using SegTreeS = SegTreeSB<STNodeS<K, T>, T>;
# 3 "d.cpp" 2

int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    long long n;
    cin >> n;
    vii arr(n, {-1, -1});
    for(ii &i:arr)
        cin >> i.first;
    long long q;
    cin >> q;
    SegTreeS<RMaxQ, long long> st(q+1);
    st.set(0, q-1, 0);
    for(long long i=0; i<q; ++i){
        long long op;
        cin >> op;
        if(op == 1){
            long long p, x;
            cin >> p >> x;
            arr[p-1] = {x, i};
        }
        else{
            long long x;
            cin >> x;
            st.set(i, x);
        }
    }
    for(long long i=0; i<n; ++i){
        if(i)
            cout << ' ';
        cout << max(arr[i].first, st.query(arr[i].second+1, q));
    }
    cout << "\n";
    return 0;
}
