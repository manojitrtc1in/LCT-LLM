

















typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;


using namespace std;
 







template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, deque<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }




























pi t[N*2];
ll n;

pi op(pi a, pi b){
    return min(a,b);
}

pi query(ll l, ll r){
    pi res = {INF, INF};
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1)
            res = op(res,t[l++]);
            

        if(r&1)
            res = op(res,t[--r]);
            

    }
    return res;
}










template<typename T, size_t sz = 1000000, bool id3 = true, bool id1 = false>
struct fastdeque {
    T _a[sz];
    T *a = _a;
    
    
    
    
    
    
    int initpos = id3 ? sz : id1 ? 0 : sz >> 1;
    
    int l = initpos, r = initpos;
    void resize(size_t dyn_sz) {
        static_assert(sz == 0, "resize on nonzero init size");
        a = new T[dyn_sz];
        l = r = initpos = id3 ? dyn_sz : id1 ? 0 : dyn_sz >> 1;
    }
    
    void push_back(const T& value) {
        static_assert(!id3, "push_back on id3");
        a[r++] = value;
    }
    void pop_back() {
        --r;
    }
    
    void push_front(const T& value) {
        static_assert(!id1, "push_front on id1");
        a[--l] = value;
    }
    void pop_front() {
        ++l;
    }
    T &front() {
        return a[l];
    }
    T &back() {
        return a[r - 1];
    }
    T *begin() {
        return &a[l];
    }
    T *end() {
        return &a[r];
    }
    ssize_t size() {
        return r - l;
    }
    bool empty() {
        return l == r;
    }
    void clear() {
        
        r = l = (r + l) >> 1;
    }
    T &operator [](size_t pos) {
        return a[l + pos];
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int q,k;
    sc(n, q, k);
    
    
    int a[n];
    FOR(i,0,n)
        sc(a[i]);
    int res[q];
    vector<pi> qus[n]; 

    FOR(t,0,q){
        int l,r;
        sc(l,r);
        --l, --r;
        qus[l].push_back({r, t});
    }
    
    
    

    
    
    
    fastdeque<pi, 0> vec[k]; 

    fastdeque<pair<int,ll>, 0> sumsuf[k]; 

    fastdeque<pair<int,ll>, 0> cntsuf[k]; 

    
    FOR(i,0,k){
        vec[i].resize(n / k + 3);
        sumsuf[i].resize(n / k + 3);
        cntsuf[i].resize(n / k + 3);
        
        
        
    }
    
    
    
    
    for(int i = 2 * n - 1; i >= n; --i){
        
        t[i] = {a[i - n], i - n};
        
        
    }
    for(int i = n - 1; i > 0; --i){
        t[i] = op(t[i << 1], t[i << 1 | 1]);
        
        
    }
    
    
    
    
    
    
    for(int i = n - 1; i >= 0; --i){
        int md = i % k;
        
        int id2 = 1; 

        
        
        

        

        
        
        
        
        
        
        auto [crmn, mnind] = query(i, i + k);
        
        
        
        
        
        
        while(vec[md].size() && a[vec[md].front().e1] >= crmn){
            
            id2 += vec[md].front().e2;
            
            
            
            
            
            sumsuf[md].pop_front();
            cntsuf[md].pop_front();
            vec[md].pop_front();
        }
        if(mnind != i){
            if(id2 > 1){
                int ilerest = id2 - 1;
                
                vec[md].push_front({mnind, ilerest});
                
                
                
                
                sumsuf[md].push_front({mnind, (sumsuf[md].empty() ? 0 : sumsuf[md].front().e2) + ilerest * crmn});
                cntsuf[md].push_front({mnind, (cntsuf[md].empty() ? 0 : cntsuf[md].front().e2) + ilerest});
                
                
                id2 -= ilerest;
                assert(id2 == 1);
            }
        }
        
        vec[md].push_front({i, id2});
        
        
        
        
        
        

        

        
        
        
        
        sumsuf[md].push_front({i, (sumsuf[md].empty() ? 0 : sumsuf[md].front().e2) + id2 * a[i]});
        cntsuf[md].push_front({i, (cntsuf[md].empty() ? 0 : cntsuf[md].front().e2) + id2});
        
        
        
        FORR(x, qus[i]){
            
            

            auto it = lower_bound(all(vec[md]), pi{x.e1 + 1,0});
            
            
            

            

            
            --it;
            
            
            
            

            
            

            
            int ind = it - vec[md].begin() + 1;
            

            

            

            
            
            
            
            ll cr = sumsuf[md].front().e2;
            
            
            
            
            
            

            if(ind != vec[md].size())
                cr -= sumsuf[md][ind].second;
            
            
            
            
            ll ile = cntsuf[md].front().e2;
            
            
            
            
            if(ind != vec[md].size())
                ile -= cntsuf[md][ind].second;
            ll req = (x.e1 - i + 1 + k - 1) / k;
            ll id0 = ile - req;
            
            
            
            
            
            assert(id0 >= 0);
            assert(id0 <= it->second);
            cr -= a[it->first] * id0;
            res[x.e2] = cr;
        }
    }
    FORR(i,res)
        cout << i << '\n';
}

