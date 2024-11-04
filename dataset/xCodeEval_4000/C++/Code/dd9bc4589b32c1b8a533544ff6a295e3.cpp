# 0 "e.cpp"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "e.cpp"
# 1 "/home/dooku/programming/cp/amoguslib/bin/../amoguslib.h" 1
       

#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2")
#pragma GCC optimize("O3,unroll-loops")





    #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;




template<class K, class V, int L=8, bool alloc=true> struct amogus_map{};





const uint64_t __AMOGUSMAP_HASH_C = uint64_t(4e18 * acos(0)) | 71;







template<class K, class V, int L>
struct amogus_map<K,V,L,false> {
    const int __res = L;
    K table[1<<L];
    V value[1<<L];
    char used_arr[1<<(L-3)];
    int __size=0;

    template<class U=V> typename enable_if<! is_empty<U>::value, V&>::type
    operator[](const K &x) {
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
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
struct amogus_map<K,V,L,true> {
    int __res; int __size;
    K* table; V* value; char *used_arr;

    amogus_map() : __res(L), __size(0), table(new K[1<<L]), value(new V[1<<L]), used_arr(new char[1<<(L-3)]()) {}
    amogus_map(const amogus_map& m) {
        __res = m.__res; __size=m.__size;
        table = new K[1<<__res]; copy(m.table, m.table+(1<<__res), table);
        value = new V[1<<__res]; copy(m.value, m.value+(1<<__res), value);
        used_arr = new char[1<<(__res-3)]; copy(m.used_arr, m.used_arr+(1<<(__res-3)), used_arr);
    }
    amogus_map& operator=(amogus_map o) {
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
                    int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
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
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
            if (CHKLOADF()) return (*this)[x];
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(__AMOGUSMAP_HASH_C*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=k, ({used_arr[h/8] |= (1<<(h%8));}), __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    void clear() {memset(used_arr, 0, 1<<(__res-3)); __size=0;}
    int size() {return __size;}

    ~amogus_map(){delete[] used_arr; delete[] table; delete[] value;};
};

template<class K, class V, int L, bool alloc>
ostream& operator<< (ostream& o, const amogus_map<K,V,L,alloc> &m) {
 o<<'[';
 for (auto a:m) o<<a <<", ";
 return o<<']';
}





template<class K, class V> struct amogus_map_iter {
    ll *used;
    K *table;
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
amogus_map_iter<K,V> begin(const amogus_map<K,V,L,alloc> &m) {
    amogus_map_iter<K,V> r{(ll*)m.used_arr, m.table, m.value, (1<<m.__res)/64};
    return ++r;
}

template<class K, class V, int L, bool alloc>
amogus_map_iter<K,V> end(const amogus_map<K,V,L,alloc> &m) {
    return {nullptr, nullptr, nullptr, (1<<m.__res)/64, 0, (1<<m.__res)/64-1};
}



template<class T, int L=8, bool alloc=true>
using amogus_set = amogus_map<T, tuple<>, L, alloc>;

template<class T, int __NN, T(* f)(T, T)>
struct segtree {
    T t[2 * __NN];
    int n=__NN;
    T id;

    segtree(){} segtree(T idv) {id=idv;}

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
        vl segs, segsr;
        int r0=r;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) segs.push_back(l++);
            if (r&1) segsr.push_back(--r);
        }
        segs.insert(segs.end(), segsr.rbegin(), segsr.rend());

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



# 1 "/home/dooku/programming/cp/amoguslib/bin/../prime.h" 1
       

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
void prime_seive(ll *prime, const ll n) {
    for (ll i=2; i<n; i++)
        if (prime[i]==0) {
            prime[i] = i;
            for (ll j=i*i;j<n;j+=i) if(!prime[j]) prime[j]=i;
        }
}

vl prime_seive_list(ll *prime, const ll n) {
    vl primes;
    for (ll i=2; i<n; i++)
        if (prime[i]==0) {
            primes.push_back(i);
            prime[i] = i;
            for (ll j=i*i;j<n;j+=i) if(!prime[j]) prime[j]=i;
        }
    return primes;
}
#pragma GCC diagnostic pop
# 281 "/home/dooku/programming/cp/amoguslib/bin/../amoguslib.h" 2

ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}


ll CRT(const vector<ll> &a, const vector<ll> &n) {
  ll prod = 1;
  for (auto ni:n) prod*=ni;

  ll sm = 0;
  for (int i=0; i<n.size(); i++) {
    ll p = prod/n[i];
    sm += a[i]*inv(p, n[i])*p;
  }
  return sm % prod;
}





template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;




    #ifdef __SIZEOF_INT128__
        typedef __int128 bb;
    #else
        typedef ll bb;
    #endif
# 323 "/home/dooku/programming/cp/amoguslib/bin/../amoguslib.h"
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
# 2 "e.cpp" 2


constexpr ll M = 998244353;

ll g(ll a, ll b){return a+b;}
segtree<ll, 200010, g> seg;

ll f[200010], fi[200010], s[200010], t[200010];

# 1 "/home/dooku/programming/cp/amoguslib/bin/../combo.h" 1
       

# 1 "/home/dooku/programming/cp/amoguslib/bin/../modular.h" 1
       

ll powmod(ll x, ll y){
  ll r=1;
  while (y) {
    if (y%2) r = r*x%M;
    x = x*x%M;
    y/=2;
  }
  return r;
}

ll powmod(ll x, ll y, ll m) {
  ll r=1;
  while (y) {
    if (y%2) r = r*x%m;
    x = x*x%m;
    y/=2;
  }
  return r;
}

ll inv(ll a) {return inv(a, M);}
# 4 "/home/dooku/programming/cp/amoguslib/bin/../combo.h" 2

ll choose(ll n, ll k) {
    if (k>n) return 0;
    return f[n] *fi[n-k]%M * fi[k]%M;
}

ll choose_with_repl(ll n, ll k) {
    return choose(n+k-1, k);
}

ll catalan(ll n) {
    return choose(2*n, n)*inv(n+1)%M;
}
# 12 "e.cpp" 2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ({f[0]=fi[0] = 1; for (int i=1; i<200010; ++i) {f[i]=f[i-1]*i%M; fi[i]=fi[i-1]*inv(i)%M;} });

    ll n, m; cin>>n>>m;
    for (ll i=0; i<n; ++i) {
        cin>>s[i];
        seg.incr(s[i], 1);
    }
    ll div=1;
    for (ll i=0; i<200010; ++i)
        div = div*fi[seg.query(i, i+1)]%M;

    for (ll i=0; i<m; ++i) cin>>t[i];
    ll ans=0;
    ll eq=1;
    for (ll i=0; i<min(n, m); ++i) {
        ( ans += eq*seg.query(0, t[i])%M *f[n-i-1]%M )%=M;
        eq = eq*seg.query(t[i], t[i]+1)%M;
        seg.incr(t[i], -1);
    }
    if (m>n) ans = (ans+eq)%M;
    ans = ans*div%M;
    cout<<ans<<endl;
}
