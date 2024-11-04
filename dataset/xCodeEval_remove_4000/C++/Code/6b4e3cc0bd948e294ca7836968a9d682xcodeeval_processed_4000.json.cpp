






       








    

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;




template<class K, class V, int L=8, bool alloc=true> struct id3{};





const uint64_t id4 = uint64_t(4e18 * acos(0)) | 71;







template<class K, class V, int L>
struct id3<K,V,L,false> {
    const int __res = L;
    K table[1<<L];
    V value[1<<L];
    char used_arr[1<<(L-3)];
    int __size=0;

    template<class U=V> typename enable_if<! is_empty<U>::value, V&>::type
    operator[](const K &x) {
        int h = __builtin_bswap64(id4*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(id4*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(id4*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(id4*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
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
struct id3<K,V,L,true> {
    int __res; int __size;
    K* table; V* value; char *used_arr;

    id3() : __res(L), __size(0), table(new K[1<<L]), value(new V[1<<L]), used_arr(new char[1<<(L-3)]()) {}
    id3(const id3& m) {
        __res = m.__res; __size=m.__size;
        table = new K[1<<__res]; copy(m.table, m.table+(1<<__res), table);
        value = new V[1<<__res]; copy(m.value, m.value+(1<<__res), value);
        used_arr = new char[1<<(__res-3)]; copy(m.used_arr, m.used_arr+(1<<(__res-3)), used_arr);
    }
    id3& operator=(id3 o) {
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
                    int h = __builtin_bswap64(id4*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
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
        int h = __builtin_bswap64(id4*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=x, ({used_arr[h/8] |= (1<<(h%8));}), __size++, value[h]=V{};
            if (CHKLOADF()) return (*this)[x];
        }
        return value[h];
    }

    bool count(const K&x) const {
        int h = __builtin_bswap64(id4*hash<K>{}(x)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=x) h = (h+1) & ((1<<__res)-1);
        return ((used_arr[h/8]>>(h%8))&1);
    }

    template<class U=V> typename enable_if<! is_empty<U>::value, bool>::type
    insert(const pair<K, V> &p) {
        int h = __builtin_bswap64(id4*hash<K>{}(p.first)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=p.first) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=p.first, ({used_arr[h/8] |= (1<<(h%8));}), value[h]=p.second, __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    template<class U=V> typename enable_if< is_empty<U>::value, bool>::type
    insert(const K &k) {
        int h = __builtin_bswap64(id4*hash<K>{}(k)) & ((1<<__res)-1); while (((used_arr[h/8]>>(h%8))&1) && table[h]!=k) h = (h+1) & ((1<<__res)-1);
        if (!((used_arr[h/8]>>(h%8))&1)) {
            table[h]=k, ({used_arr[h/8] |= (1<<(h%8));}), __size++;
            CHKLOADF();
            return true;
        }
        return false;
    }

    void clear() {memset(used_arr, 0, 1<<(__res-3)); __size=0;}
    int size() {return __size;}

    ~id3(){delete[] used_arr; delete[] table; delete[] value;};
};

template<class K, class V, int L, bool alloc>
ostream& operator<< (ostream& o, const id3<K,V,L,alloc> &m) {
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
amogus_map_iter<K,V> begin(const id3<K,V,L,alloc> &m) {
    amogus_map_iter<K,V> r{(const ll*)m.used_arr, m.table, (V*)m.value, (1<<m.__res)/64};
    return ++r;
}

template<class K, class V, int L, bool alloc>
amogus_map_iter<K,V> end(const id3<K,V,L,alloc> &m) {
    return {nullptr, nullptr, nullptr, (1<<m.__res)/64, 0, (1<<m.__res)/64-1};
}




template<class A, class B>
struct std::hash<pair<A, B>> {
    std::size_t operator()(const pair<A, B> &p) const noexcept {
        return hash<A>{}(p.first) ^ hash<B>{}(p.second);
    }
};

template<class T, int L=8, bool alloc=true>
using amogus_set = id3<T, tuple<>, L, alloc>;

template<class T, int __NN, T(* f)(T, T)>
struct id0 {
    T t[2 * __NN];
    int n=__NN;
    T id;

    id0(){} id0(T idv) {id=idv;}

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
        vl segs, id2;
        int r0=r;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) segs.push_back(l++);
            if (r&1) id2.push_back(--r);
        }
        segs.insert(segs.end(), id2.rbegin(), id2.rend());

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
    


       



void id5(ll *prime, const ll n) {
    for (ll i=2; i<n; i++)
        if (prime[i]==0) {
            prime[i] = i;
            for (ll j=i*i;j<n;j+=i) if(!prime[j]) prime[j]=i;
        }
}

vl id1(ll *prime, const ll n) {
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



constexpr ll M = 2;


       


       

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


typedef vector<vector<ll>> mat;

mat operator*(const mat &a, const mat &b) {
    mat c(a.size(), vector<ll>(b[0].size()));

    for (int i=0; i<a.size(); ++i)
        for (int k=0; k<b.size(); ++k)
            for (int j=0; j<b[0].size(); ++j)
                ( c[i][j] += a[i][k]*b[k][j] )%=M;
    return c;
}

mat operator+(mat a, const mat&b) {
    for (int i=0; i<a.size(); ++i)
        for (int j=0; j<a[0].size(); ++j)
            ( a[i][j] += b[i][j] )%=M;
    return a;
}

mat operator*(ll f, mat a) {
    for (int i=0; i<a.size(); ++i)
        for (int j=0; j<a[0].size(); ++j)
            ( a[i][j] *= f )%=M;
    return a;
}

mat operator*(const mat &a, ll f) {return f*a;}
mat operator/(const mat &a, ll f) {return a*inv(f);}
mat operator-(const mat &a){return a*(M-1);}
mat operator-(const mat &a, const mat &b) {return a + -b;}

vl operator*(const mat &a, const vl &b) {
    vl c(a.size());

    for (int i=0; i<a.size(); ++i)
        for (int j=0; j<b.size(); ++j)
                ( c[i] += a[i][j]*b[j] )%=M;
    return c;
}

mat transpose(const mat &a) {
    mat b(a[0].size(), vector<ll>(a.size()));
    for (int i=0; i<a.size(); ++i)
        for (int j=0; j<a[0].size(); ++j)
            b[j][i] = a[i][j];
    return b;
}

mat mat_id(int n) {
    mat a(n, vector<ll>(n));
    for (ll i=0; i<n; ++i) a[i][i]=1;
    return a;
}

mat exp_mat(const mat &x, ll y) {
    if (y==0) return mat_id(x.size());
    mat t = exp_mat(x, y/2);
    if (y%2) return t*t*x;
    return t*t;
}


vector<int> where;
int solve_system(mat a, vector<ll> &b) {
    int n=a.size();
    int m=a[0].size();
    for (int i=0; i<n; ++i) a[i].push_back(b[i]);

    where.assign(m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        if (!a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                ll c = a[i][col] * inv(a[row][col]) %M;
                for (int j=col; j<=m; ++j)
                    a[i][j] = ( a[i][j] - a[row][j]*c%M + M)%M;
            }
        ++row;
    }

    b.assign(m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            b[i] = a[where[i]][m] * inv(a[where[i]][i]) %M;
    for (int i=0; i<n; ++i) {
        ll sum = 0;
        for (int j=0; j<m; ++j)
           ( sum += b[j] * a[i][j] )%=M;
        if (sum != a[i][m])
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}


ll a[1010][1010];

ll solve(ll o, ll n) {
    ll ans = 0;
    if (n<=8) {
        mat A; vl b;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                vl v(n*n);
                for (auto pa:{pair<int,int>{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                    int ni=i+pa.first, nj=j+pa.second;
                    if (ni>=0 && ni<n && nj>=0 && nj<n)
                        v[ni*n + nj] = 1;
                }
                A.push_back(v);
                b.push_back(1);
            }
        }
        solve_system(A, b);

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) ans ^= b[i*n+j]*a[i+o][j+o];
        return ans;
    }

    for (ll j=0; j<n; ++j) ans ^= a[o][j+o] ^ a[o+n-2][j+o];
    for (ll j=1; j<n-1; ++j) ans ^= a[o+1][j+o] ^ a[o+n-3][j+o];
    for (ll i=2; i<=n-4; ++i) {
        if (i%2==0) ans ^= a[i+o][0+o] ^ a[i+o][1+o] ^ a[i+o][n-1+o] ^ a[i+o][n-2+o];
        else ans ^= a[i+o][1+o] ^ a[i+o][2+o] ^ a[i+o][n-2+o] ^ a[i+o][n-3+o];
    }
    ans ^= solve(o+4, n-8);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ntests;cin>>ntests;ll tc=0;goto _restart;_restart:;while(++tc<=ntests) {
        ll n; cin>>n;
        for (ll i=0; i<n; ++i) for (ll j=0; j<n; ++j) cin>>a[i][j];
        cout<<solve(0, n)<<'\n';
    }
}