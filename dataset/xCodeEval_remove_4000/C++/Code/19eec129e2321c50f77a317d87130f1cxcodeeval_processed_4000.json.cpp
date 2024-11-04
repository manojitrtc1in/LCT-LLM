






       








    

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;




template<class K, class V, int L=8, bool alloc=true> struct id6{};





const uint64_t id2 = uint64_t(4e18 * acos(0)) | 71;







template<class K, class V, int L>
struct id6<K,V,L,false> {
    const int __res = L;
    K table[1<<L];
    V value[1<<L];
    char used_arr[1<<(L-3)];
    int __size=0;

    template<class U=V> typename enable_if<! is_empty<U>::value, V&>::type
    operator[](const K &x) {
        int h = __builtin_bswap64(id2*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(id2*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(id2*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(id2*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
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
struct id6<K,V,L,true> {
    int __res; int __size;
    K* table; V* value; char *used_arr;

    id6() : __res(L), __size(0), table(new K[1<<L]), value(new V[1<<L]), used_arr(new char[1<<(L-3)]()) {}
    id6(const id6& m) {
        __res = m.__res; __size=m.__size;
        table = new K[1<<__res]; copy(m.table, m.table+(1<<__res), table);
        value = new V[1<<__res]; copy(m.value, m.value+(1<<__res), value);
        used_arr = new char[1<<(__res-3)]; copy(m.used_arr, m.used_arr+(1<<(__res-3)), used_arr);
    }
    id6& operator=(id6 o) {
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
                    int h = __builtin_bswap64(id2*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
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
        int h = __builtin_bswap64(id2*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
            if (CHKLOADF()) return (*this)[x];
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(id2*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(id2*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(id2*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=k, ({used_arr[h/8] |= (1<<(h%8));}), __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    void clear() {memset(used_arr, 0, 1<<(__res-3)); __size=0;}
    int size() {return __size;}

    ~id6(){delete[] used_arr; delete[] table; delete[] value;};
};

template<class K, class V, int L, bool alloc>
ostream& operator<< (ostream& o, const id6<K,V,L,alloc> &m) {
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
amogus_map_iter<K,V> begin(const id6<K,V,L,alloc> &m) {
    amogus_map_iter<K,V> r{(const ll*)m.used_arr, m.table, (V*)m.value, (1<<m.__res)/64};
    return ++r;
}

template<class K, class V, int L, bool alloc>
amogus_map_iter<K,V> end(const id6<K,V,L,alloc> &m) {
    return {nullptr, nullptr, nullptr, (1<<m.__res)/64, 0, (1<<m.__res)/64-1};
}




template<class A, class B>
struct std::hash<pair<A, B>> {
    std::size_t operator()(const pair<A, B> &p) const noexcept {
        return hash<A>{}(p.first) ^ hash<B>{}(p.second);
    }
};

template<class T, int L=8, bool alloc=true>
using amogus_set = id6<T, tuple<>, L, alloc>;

template<class T, int __NN, T(* f)(T, T)>
struct id4 {
    T t[2 * __NN];
    int n=__NN;
    T id;

    id4(){} id4(T idv) {id=idv;}

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
        vl segs, id0;
        int r0=r;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) segs.push_back(l++);
            if (r&1) id0.push_back(--r);
        }
        segs.insert(segs.end(), id0.rbegin(), id0.rend());

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
    


       



void id3(ll *prime, const ll n) {
    for (ll i=2; i<n; i++)
        if (prime[i]==0) {
            prime[i] = i;
            for (ll j=i*i;j<n;j+=i) if(!prime[j]) prime[j]=i;
        }
}

vl id5(ll *prime, const ll n) {
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

struct edge {ll b, cap, flow, flip;};
int S, nn;
vector<edge> g[2010];
ll ans=0, d[2010], ptr[2010];
ll INF = 1e6;

void add_edge (ll a, ll b, ll cap) {
    g[a].push_back({b, cap, 0, g[b].size()});
    g[b].push_back({a, 0, 0, g[a].size()-1});
}

ll dfs (ll u, ll flow=id1) {
    if (u==S+1 || !flow) return flow;
    while (++ptr[u] < g[u].size()) {
        edge &e = g[u][ptr[u]];
        if (d[e.b] != d[u]+1) continue;
        if (ll pushed = dfs(e.b, min(flow, e.cap-e.flow))) {
            e.flow += pushed;
            g[e.b][e.flip].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

void calc() {
    do {
        vector<ll> q {S};
        for (int i=0; i<nn; ++i) d[i]=0;
        ll i = -(d[S] = 1);
        while (++i<q.size() && !d[S+1])
            for (auto e: g[q[i]])
                if (!d[e.b] && e.flow<e.cap) {
                    q.push_back(e.b);
                    d[e.b] = d[q[i]]+1;
                }

        for (int i=0; i<nn; ++i) ptr[i]=-1;
        while(ll pushed=dfs(S)) ans+=pushed;
    } while (d[S+1]);
}

int n;
ll d1[2010], d2[2010];
id6<ll, int> freq2, freq1;
id6<ll, int> canon1, canon2;
ll look1[2010], look2[2010];

bool test(ll p2) {
    for (int i=0; i<nn; ++i) g[i].clear();
    ans = 0;
    for (auto pa:freq2) {
        auto __p = pa; auto x = __p.first; auto k = __p.second;
        ll op1 = abs(p2+x);
        ll op2 = abs(p2-x);
        if (canon1.count(op1)) add_edge(canon2[x], canon2.size() + canon1[op1], INF);
        if (op1!=op2 && canon1.count(op2)) add_edge(canon2[x], canon2.size() + canon1[op2], INF);
        add_edge(S, canon2[x], k);
    }
    for (auto pa:freq1) {
        auto __p = pa; auto x = __p.first; auto k = __p.second;
        add_edge(canon2.size() + canon1[x], S+1, k);
    }
    calc();
    if (ans==n) {
        cout<<"YES\n";
        ll SH = 0;
        vl h;
        for (auto pa:freq2) {
            ll x = pa.first;
            for (auto e:g[canon2[x]]) {
                if (e.cap!=INF) continue;
                ll y = look1[e.b - (ll)canon2.size()];
                ll cur;
                if (y==p2+x || -y==p2+x) cur=p2+x;
                else cur=p2-x;
                cur += SH;
                for (int i=0; i<e.flow; ++i) h.push_back(cur);
            }
        }
        h.push_back(0);
        h.push_back(p2);
        for (auto x:h) {
            if (x<0) SH = max(SH, -x);
            if (x>2000000000) SH = min(SH, 2000000000 - x);
        }
        h.pop_back(), h.pop_back();
        for (auto x:h) cout<<x+SH<<' ';
        cout<<'\n';
        cout<<0+SH<<' '<<p2+SH;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ntests;cin>>ntests;ll tc=0;goto _restart;_restart:;while(++tc<=ntests) {
        cin>>n;
        canon1.clear(), canon2.clear();
        freq1.clear(), freq2.clear();
        ll uu = 0;
        for (ll i=0; i<n; ++i) {cin>>d1[i], freq1[d1[i]]++; if (canon1.count(d1[i])==0) canon1[d1[i]]=uu++;}
        uu = 0;
        for (ll i=0; i<n; ++i) {cin>>d2[i], freq2[d2[i]]++; if (canon2.count(d2[i])==0) canon2[d2[i]]=uu++;}
        for (auto pa:canon1) look1[pa.second] =pa.first;
        for (auto pa:canon2) look2[pa.second] =pa.first;
        nn = canon1.size() + canon2.size() + 2;
        S = nn-2;
        for (int i=0; i<canon2.size(); ++i) {
            ll u = look1[0];
            ll v = look2[i];
            if (test(u+v)) {cout<<""<<'\n'; goto _restart;}
            if (test(abs(u-v))) {cout<<""<<'\n'; goto _restart;}
        }
        cout<<"NO\n";
    }
}
