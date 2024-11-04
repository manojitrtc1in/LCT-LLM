




       


 


 


 








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


       



template<typename T>
struct id5 {
    T value, lazy = 0;

    id5()
    {
        

    }

    id5(const T value) :
        value(value)
    {
        

    }

    id5(const id5 &lhs, const id5 &rhs)
    {
        

    }

    
    virtual bool match(const T value) const = 0;

    
    virtual void update(const size_t range) = 0;
};


template<typename Node, typename T>
class id6
{
public:
    id6() = delete;

    id6(const size_t arr_size) :
        tree(4*arr_size), arr_size(arr_size) {}

    id6(const vector<T> &arr) :
        id6(arr.size(), arr) {}

    id6(const size_t arr_size, const vector<T> &arr) :
        tree(4*arr_size), arr_size(arr_size)
    {
        build(0, arr_size-1, 0, arr);
    }

    id6(const id6 &lhs, const id6 &rhs) :
        id6(lhs.arr_size)
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
struct id1 : id5<T> {
    using super_type = id5<T>;
    pair<T, bool> set = {0, false};

    id1() :
        super_type() {}

    id1(const T value) :
        super_type(value) {}

    id1(const id1 &lhs, const id1 &rhs)
    {
        

    }
};


template<typename NodeS, typename T>
class id4 : public id6<NodeS, T>
{
public:
    id4() = delete;

    id4(const size_t arr_size) :
        super_type(arr_size) {}

    id4(const vector<T> &arr) :
        super_type(arr) {}

    id4(const size_t arr_size, const vector<T> &arr) :
        super_type(arr_size, arr) {}

    id4(const id4 &lhs, const id4 &rhs) :
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
    using super_type = id6<NodeS, T>;

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
    id3,
    id8,
    id7,
    id2,
};

const STKind id3 = STKind::id3;
const STKind id8 = STKind::id8;
const STKind id7 = STKind::id7;
const STKind id2 = STKind::id2;


template<typename T>
T default_value(STKind k){
    switch(k){
        case id3:
            return -((long long)1e9+1);
        case id8:
            return ((long long)1e9+1);
        case id7:
            return 0;
        case id2:
            return 0;
        default:
            assert(false);
    }
}


template<typename T>
T merge_values(STKind k, const T lhs, const T rhs){
    switch(k){
        case id3:
            return max(lhs, rhs);
        case id8:
            return min(lhs, rhs);
        case id7:
            return lhs + rhs;
        case id2:
            return lhs ^ rhs;
        default:
            assert(false);
    }
}


template<STKind K, typename T>
struct STNode : id5<T> {
    using super_type = id5<T>;

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
            case id3:
                return this->value >= value;
                

            case id8:
                return this->value <= value;
                

            case id7:
            case id2:
            default:
                assert(false);
        }
    }

    
    void update(const size_t range)
    {
        switch (K){
            case id3:
            case id8:
                this->value += this->lazy;
                break;
            case id7:
                this->value += range*this->lazy;
                break;
            case id2:
                break;
            default:
                assert(false);
        }
        this->lazy = 0;
    }
};

template<STKind K, typename T>
using SegTree = id6<STNode<K, T>, T>;


template<STKind K, typename T>
struct id0 : id1<T> {
    using super_type = id1<T>;

    id0() :
        super_type(default_value<T>(K)) {}

    id0(const T value) :
        super_type(value) {}

    id0(const id0 &lhs, const id0 &rhs) :
        super_type(merge_values<T>(K, lhs.value, rhs.value))
    {
        assert(lhs.lazy == 0 and rhs.lazy == 0);
        assert(!lhs.set.second and !rhs.set.second);
    }

    
    bool match(const T value) const
    {
        switch(K){
            case id3:
                return this->value >= value;
                

            case id8:
                return this->value <= value;
                

            case id7:
            case id2:
            default:
                assert(false);
        }
    }

    
    void update(const size_t range)
    {
        if(this->set.second){
            switch (K){
                case id3:
                case id8:
                    this->value = this->set.first;
                    break;
                case id7:
                    this->value = range*this->set.first;
                    break;
                case id2:
                    this->value = (range%2)*this->set.first;
                    break;
                default:
                    assert(false);
            }
        }

        switch (K){
            case id3:
            case id8:
                this->value += this->lazy;
                break;
            case id7:
                this->value += range*this->lazy;
                break;
            case id2:
                break;
            default:
                assert(false);
        }

        this->lazy = 0;
        this->set = {0, false};
    }
};

template<STKind K, typename T>
using SegTreeS = id4<id0<K, T>, T>;


int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    long long n;
    cin >> n;
    vii arr(n, {-1, -1});
    for(ii &i:arr)
        cin >> i.first;
    long long q;
    cin >> q;
    SegTreeS<id3, long long> st(q+1);
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
