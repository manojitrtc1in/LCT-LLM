






       








    

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;




template<class K, class V, int L=8, bool alloc=true> struct id4{};





const uint64_t id6 = uint64_t(4e18 * acos(0)) | 71;







template<class K, class V, int L>
struct id4<K,V,L,false> {
    const int __res = L;
    K table[1<<L];
    V value[1<<L];
    char used_arr[1<<(L-3)];
    int __size=0;

    template<class U=V> typename enable_if<! is_empty<U>::value, V&>::type
    operator[](const K &x) {
        int h = __builtin_bswap64(id6*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(id6*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(id6*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(id6*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=k, ({used_arr[h/8] |= (1<<(h%8));}), __size++;
            return true;
        }
        return false;
    }
    void clear() {memset(used_arr, 0, 1<<(L-3)); __size=0;}
    int size() {return __size;}
};

template<class K, class V, int L>
struct id4<K,V,L,true> {
    int __res; int __size;
    K* table; V* value; char *used_arr;

    id4() : __res(L), __size(0), table(new K[1<<L]), value(new V[1<<L]), used_arr(new char[1<<(L-3)]()) {}
    id4(const id4& m) {
        __res = m.__res; __size=m.__size;
        table = new K[1<<__res]; copy(m.table, m.table+(1<<__res), table);
        value = new V[1<<__res]; copy(m.value, m.value+(1<<__res), value);
        used_arr = new char[1<<(__res-3)]; copy(m.used_arr, m.used_arr+(1<<(__res-3)), used_arr);
    }
    id4& operator=(id4 o) {
        __res=o.__res; __size=o.__size;
        swap(table, o.table); swap(value, o.value); swap(used_arr, o.used_arr);
        return *this;
    }

    bool CHKLOADF() {
        if (__size*3 > (1<<__res)) {
            __res++;
            K* ot=table; V* ov=value; char* ou = used_arr;
            table=new K[1<<__res]; value=new V[1<<__res]; used_arr = new char[1<<(__res-3)]();
            for (int i=0; i<(1<<(__res-1)); ++i) {
                if (((ou[i/8]>>(i%8))&1)) {
                    K k = ot[i];
                    int h = __builtin_bswap64(id6*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
                    table[h]=k, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=ov[i];
                }
            }
            delete[]ot; delete[] ou; delete[] ov;
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, V&>::type
    operator[](const K &x) {
        int h = __builtin_bswap64(id6*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
            if (CHKLOADF()) return (*this)[x];
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(id6*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(id6*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(id6*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=k, ({used_arr[h/8] |= (1<<(h%8));}), __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    void clear() {memset(used_arr, 0, 1<<(__res-3)); __size=0;}
    int size() {return __size;}

    ~id4(){delete[] used_arr; delete[] table; delete[] value;};
};

template<class K, class V, int L, bool alloc>
ostream& operator<< (ostream& o, const id4<K,V,L,alloc> &m) {
 o<<'[';
 for (auto a:m) o<<a <<", ";
 return o<<']';
}





template<class K, class V> struct amogus_map_iter {
    const ll *used;
    const K *table;
    V *value;
    int sz;
    ll block=0;
    int i=-1;

    amogus_map_iter<K, V>& operator++() {
        block = block & (block-1);
        while (block==0 && i<sz-1) {
            ++i;
            block = used[i];
        }
        return *this;
    };
    amogus_map_iter<K,V> operator++(int) {
        amogus_map_iter<K,V> old=*this;
        operator++();
        return old;
    }

    using ITT = pair<const K, V&>;
    template<class U=V> typename enable_if<! is_empty<U>::value, ITT>::type operator*() {
        int j=__builtin_ffsll(block)-1;
        return {table[i*64+j], value[i*64+j]};
    }
    template<class U=V> typename enable_if< is_empty<U>::value, K>::type operator*() {
        int j=__builtin_ffsll(block)-1;
        return table[i*64+j];
    }
    bool operator==(amogus_map_iter<K,V> o) {
        return o.i==i && o.block==block;
    }
    bool operator!=(amogus_map_iter<K,V> o) {
        return o.i!=i || o.block!=block;
    }
};

template<class K, class V, int L, bool alloc>
amogus_map_iter<K,V> begin(const id4<K,V,L,alloc> &m) {
    amogus_map_iter<K,V> r{(const ll*)m.used_arr, m.table, (V*)m.value, (1<<m.__res)/64};
    return ++r;
}

template<class K, class V, int L, bool alloc>
amogus_map_iter<K,V> end(const id4<K,V,L,alloc> &m) {
    return {nullptr, nullptr, nullptr, (1<<m.__res)/64, 0, (1<<m.__res)/64-1};
}




template<class A, class B>
struct std::hash<pair<A, B>> {
    std::size_t operator()(const pair<A, B> &p) const noexcept {
        return hash<A>{}(p.first) ^ hash<B>{}(p.second);
    }
};

template<class T, int L=8, bool alloc=true>
using amogus_set = id4<T, tuple<>, L, alloc>;

template<class T, int __NN, T(* f)(T, T)>
struct id1 {
    T t[2 * __NN];
    int n=__NN;
    T id;

    id1(){} id1(T idv) {id=idv;}

    void build() {for (int i=n-1; i>0; --i) t[i] = f(t[i<<1], t[i<<1|1]);}

    void modify(int p, T value) {
        for (p+=n, t[p] = value; p>>=1;) t[p] = f(t[p<<1], t[p<<1|1]);
    }
    void incr(int p, T value) {
        for (p+=n, t[p] = f(t[p], value); p>>=1;) t[p] = f(t[p<<1], t[p<<1|1]);
    }

    T query(int l, int r) {
      T resl=id, resr=id;
      for (l += n, r += n; l < r; l>>=1, r>>=1) {
        if (l&1) resl = f(resl, t[l++]);
        if (r&1) resr = f(t[--r], resr);
      }
      return f(resl, resr);
    }


    int lower_bound(int l, int r, T x, bool (*less)(T, T)) {
        vl segs, id3;
        int r0=r;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) segs.push_back(l++);
            if (r&1) id3.push_back(--r);
        }
        segs.insert(segs.end(), id3.rbegin(), id3.rend());

        T cur = id;
        for (int i=0; i<segs.size(); ++i) {
            T neow = f(cur, t[segs[i]]);
            if (!less(neow, x)) {
                for (i=segs[i]; i<n; ) {
                    neow = f(cur, t[i<<=1]);
                    if (less(neow, x)) i++, cur=neow;
                }
                return i-n;
            }
            cur = neow;
        }
        return r0;
    }
};



template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;




    
        typedef __int128 bb;
    
        typedef ll bb;
    


       



void id7(ll *prime, const ll n) {
    for (ll i=2; i<n; i++)
        if (prime[i]==0) {
            prime[i] = i;
            for (ll j=i*i;j<n;j+=i) if(!prime[j]) prime[j]=i;
        }
}

vl id2(ll *prime, const ll n) {
    vl primes;
    for (ll i=2; i<n; i++)
        if (prime[i]==0) {
            primes.push_back(i);
            prime[i] = i;
            for (ll j=i*i;j<n;j+=i) if(!prime[j]) prime[j]=i;
        }
    return primes;
}



ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}
bb inv(bb a, bb b){return 1<a ? b - inv(b%a,a)*b/a : 1;}


bb CRT(const vector<ll> &a, const vector<ll> &n) {
  bb prod = 1;
  for (auto ni:n) prod*=ni;

  bb sm = 0;
  for (int i=0; i<n.size(); i++) {
    bb p = prod/n[i];
    sm += a[i]*inv(p, (bb)n[i])*p;
  }
  return sm % prod;
}







template<class T, class S>
ostream& operator<<(ostream& o, pair<T, S> p) {
 return o<<'('<<p.first<<", "<<p.second<<')';
}

template<template<class, class...> class T, class... A>
typename enable_if<!(is_same<T<A...>, string>() || is_same<T<A...>, complex< tuple_element_t<0, tuple<A...>> >>()), ostream&>::type
operator<< (ostream& o, T<A...> v) {
 o<<'[';
 for (auto a:v) o<<a <<", ";
 return o<<']';
}


template<ll i, class... T>
typename enable_if<i==sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {}

template<ll i, class... T>
typename enable_if<i<sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {
    _p<i+1>(o << get<i>(t)<< ", ", t);
}

template<class... T>
ostream& operator<<(ostream& o, tuple<T...> t) {
    _p<0>(o<<'(', t);
    return o<<')';
}

void _print() {cerr << "]"<<endl;} template <class T, class... second>
void _print(T t, second... v) {cerr<<t; if (sizeof...(v)) cerr << ", "; _print(v...);}



constexpr ll M = 1e9+7;


       

template<class T, int __NN, T(* f)(T, T)>
struct id0 {
    T t[2 * __NN];
    int n=__NN;
    T id;

    id0(){} id0(T idv) {
        id=idv; fill(t, t+2*n, id);
    }

    void modify(int l, int r, T v) {
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l&1) t[l] = f(t[l], v), l++;
            if (r&1) --r, t[r] = f(t[r], v);
        }
    }

    T query(int p) {
        T res = id;
        for (p+=n; p>0; p/=2) res = f(res, t[p]);
        return res;
    }

    void push() {
        for (int i=1; i<n; ++i) {
            t[i*2] = f(t[i*2], t[i]);
            t[i*2+1] = f(t[i*2+1], t[i]);
            t[i] = 0;
        }
    }
};

template<class T, class U, int __NN, T(*f)(T, T), U(*g)(U, U), T(*h)(U, T), int L=26>
struct id5 {
 T t[2 * __NN];
 U d[__NN];
    T idT; U idU;
 ll n = __NN;

    id5(T id1, U id2) {
        idT=id1; idU=id2;
        fill(d, d+n, idU);
    }

    void calc(int p) {
        t[p] = f(t[p*2], t[p*2+1]);
        if (d[p]!=idU) t[p] = h(d[p], t[p]);
    }

    void apply(int p, U v) {
        t[p] = h(v, t[p]);
        if (p<n) d[p] = g(v, d[p]);
    }

    void build(int l, int r) {
        for (l+=n, r+=n-1; l>1; ) {
            l/=2, r/=2;
            for (int i=r; i>=l; --i) calc(i);
        }
    }

    void push(int p) {
        p+=n;
        for (int s=L; s>0; --s) {
            int i=p>>s;
            if (d[i]!=idU) {
                apply(i*2, d[i]);
                apply(i*2+1, d[i]);
                d[i]=idU;
            }
        }
    }

    void modify(int p, T v) {
        push(p);
        t[p+n] = v;
        build(p, p+1);
    }

    void modify(int l, int r, U v) {
        if (v==idU) return;
        push(l), push(r-1);
        bool cl=false, cr=false;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (cl) calc(l-1);
            if (cr) calc(r);
            if (l&1) apply(l++, v), cl=true;
            if (r&1) apply(--r, v), cr=true;
        }
        for (--l; r>0; l/=2, r/=2) {
            if (cl) calc(l);
            if (cr && (!cl || l != r)) calc(r);
        }
    }

    T query(int l, int r) {
        push(l), push(r-1);
        T resl=idT, resr=idT;
        for (l += n, r += n; l < r; l/=2, r/=2) {
            if (l&1) resl = f(resl, t[l++]);
            if (r&1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
};

template<class first, class T, T(*f)(T, T)>
struct d2dseg {
    T id;

    struct seg {
        T* t, id;
        int n;

        void init(int nn, T idT) {
            id = idT;
            n = nn;
            t = new T[2*n];
            fill(t, t+2*n, id);
        }

        void modify(int p, T value) {
            for (p+=n, t[p] = value; p /= 2;) t[p] = f(t[2*p], t[2*p+1]);
        }

        T query(int l, int r) {
            T resl=id, resr=id;
            for (l += n, r += n; l < r; l /= 2, r /= 2) {
                if (l&1) resl = f(resl, t[l++]);
                if (r&1) resr = f(t[--r], resr);
            }
            return f(resl, resr);
        }
    };

    using I=pair<first, int>;
    int n;
    first* keys;
    seg *s;
    I **k;

    int m;

    void init(T idT) {
        id = idT;
        k = new I*[2*n];
        s = new seg[2*n];
        for (int p=2*n; --p;) if(p>=n || (m=s[2*p].n)==s[2*p+1].n) {
            s[p].init(2*m + !m, id);
            k[p] = new I[s[p].n];
            I** y = k+2*p;
            m ? *merge(*y, *y+m, y[1], y[1]+m, k[p])
                : *k[p] = {keys[p-n], p-n};
        }
    }


    void modify(int p, T v) {
        I a{keys[p], p};
        for (p+=n; p; p/=2) if(p>=n || (m=s[2*p].n)==s[2*p+1].n) s[p].modify(lower_bound(k[p], k[p]+s[p].n, I{a}) - k[p], v);
    }


    T query(int l, int r, first a, first b) {
        int p;
        T res=id;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l&1) p=l++, res=f(res, s[p].query(lower_bound(k[p], k[p]+s[p].n, I{a, -1}) - k[p], lower_bound(k[p], k[p]+s[p].n, I{b, -1}) - k[p]));
            if (r&1) p=--r, res=f(res, s[p].query(lower_bound(k[p], k[p]+s[p].n, I{a, -1}) - k[p], lower_bound(k[p], k[p]+s[p].n, I{b, -1}) - k[p]));
        }
        return res;
    }




};


typedef pl T;
typedef ll U;

T f(T a, T b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}

U g(U a, U b) {
    return a+b;
}

T h(U o, T a) {
    return {a.first+o, a.second+o};
}

id5<T, U, 200010, f, g, h> s({INT_MAX, INT_MIN}, 0);

ll a[200010], ans[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin>>n;
    vector<pl> vals;
    for (ll i=0; i<n; ++i) {
        cin>>a[i];
        vals.push_back({a[i], i});
    }

    sort(begin(vals), end(vals));
    for (ll iter=0; iter<2; ++iter) {
        for (ll i=0; i<=n; ++i) s.modify(i, {i, i});

        for (ll j=0; j<n; ) {
            ll o = vals[j].first, og=j;
            while (j<n && o==vals[j].first) ++j;

            for (ll k=og; k<j; ++k) {
                ll i = vals[k].second;
                ll lef = s.query(0, i+1).first;
                ll ri = s.query(i+1, n+1).second;
                ans[i] = max(ans[i], (ri-lef - 1 + !iter)/2);
            }
            for (ll k=og; k<j; ++k) {
                s.modify(vals[k].second+1, n+1, -2);
            }
        }
        reverse(begin(vals), end(vals));
    }
    for (ll i=0; i<n; ++i)cout<<ans[i]<<' ';
    cout<<endl;
}
