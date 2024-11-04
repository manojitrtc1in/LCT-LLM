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
amogus_map_iter<K,V> begin(const amogus_map<K,V,L,alloc> &m) {
    amogus_map_iter<K,V> r{(const ll*)m.used_arr, m.table, (V*)m.value, (1<<m.__res)/64};
    return ++r;
}

template<class K, class V, int L, bool alloc>
amogus_map_iter<K,V> end(const amogus_map<K,V,L,alloc> &m) {
    return {nullptr, nullptr, nullptr, (1<<m.__res)/64, 0, (1<<m.__res)/64-1};
}




template<class A, class B>
struct std::hash<pair<A, B>> {
    std::size_t operator()(const pair<A, B> &p) const noexcept {
        return hash<A>{}(p.first) ^ hash<B>{}(p.second);
    }
};

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



template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;




    #ifdef __SIZEOF_INT128__
        typedef __int128 bb;
    #else
        typedef ll bb;
    #endif
# 310 "/home/dooku/programming/cp/amoguslib/bin/../amoguslib.h"
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
# 311 "/home/dooku/programming/cp/amoguslib/bin/../amoguslib.h" 2

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
# 2 "e.cpp" 2



constexpr ll M = 1e9+7;

int nex_big[500010], nex_smol[500010], prev_big[500010], prev_smol[500010], a[500010];
vector<int> divs[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i=1; i<1000010; ++i) for (int j=i+i; j<1000010; j+=i) divs[j].push_back(i);

    ll ntests;cin>>ntests;ll tc=0;goto _restart;_restart:;while(++tc<=ntests) {
        int n; cin>>n;
        amogus_map<int, vector<int>> occ;
        for (int i=0; i<n; ++i) cin>>a[i], occ[a[i]].push_back(i);;

        {
            stack<int> sbig, ssmol;
            for (int i=0; i<n; ++i) {
                while (!sbig.empty() && a[sbig.top()]<=a[i]) sbig.pop();
                if (sbig.empty()) prev_big[i] = -1;
                else prev_big[i] = sbig.top();
                sbig.push(i);

                while (!ssmol.empty() && a[ssmol.top()]>=a[i]) ssmol.pop();
                if (ssmol.empty()) prev_smol[i] = -1;
                else prev_smol[i] = ssmol.top();
                ssmol.push(i);
            }
        }

        {
            stack<int> sbig, ssmol;
            for (int i=n-1; i>=0; --i) {
                while (!sbig.empty() && a[sbig.top()]<a[i]) sbig.pop();
                if (sbig.empty()) nex_big[i] = n;
                else nex_big[i] = sbig.top();
                sbig.push(i);

                while (!ssmol.empty() && a[ssmol.top()]>=a[i]) ssmol.pop();
                if (ssmol.empty()) nex_smol[i] = n;
                else nex_smol[i] = ssmol.top();
                ssmol.push(i);
            }
        }

        ll ans = 0;
        for (int i=0; i<n; ++i) {
            int lm = prev_big[i];
            int rm = nex_big[i];

            ans += max(0, min(rm, nex_smol[i])-i) * (ll)max(0, i-max(lm, prev_smol[i]));



            for (int d:divs[a[i]]) {
                ll cur = 0;

                int pre=-1, nex=-1;
                auto w = upper_bound(begin(occ[d]), end(occ[d]), i);
                if (w!=occ[d].end()) nex=*w;
                if (w!=occ[d].begin()) pre=*prev(w);
                if (nex!=-1 && nex>=rm) nex=-1;
                if (pre!=-1 && pre<=lm) pre=-1;

                if (nex==-1 && pre==-1) continue;
                if (~nex)
                    cur += max(0, i-max(lm, prev_smol[nex]))*(ll)max(0, min(nex_smol[nex], rm) - nex);
                if (~pre) {
                    cur += max(0, min(rm, nex_smol[pre])-i)*(ll)max(0, pre - max(prev_smol[pre], lm));
                }
                if (pre!=-1 && nex!=-1)
                    cur -= max(0, pre - max({prev_smol[nex], prev_smol[pre], lm}))*(ll)max(0, min({nex_smol[nex], nex_smol[pre], rm}) - nex);

                ans += cur;
            }
        }
        cout<<ans<<'\n';
    }
}
