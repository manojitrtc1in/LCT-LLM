


#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << (x) << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
 
#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, deque<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
#define N 1000001

#define int ll

























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










template<typename T, size_t sz = 1000000, bool push_front_only = true, bool push_back_only = false>
struct fastdeque {
    T _a[sz];
    T *a = _a;
    
    
    
    
    
    
    int initpos = push_front_only ? sz : push_back_only ? 0 : sz >> 1;
    
    int l = initpos, r = initpos;
    void resize(size_t dyn_sz) {
        static_assert(sz == 0, "resize on nonzero init size");
        a = new T[dyn_sz];
        l = r = initpos = push_front_only ? dyn_sz : push_back_only ? 0 : dyn_sz >> 1;
    }
    
    void push_back(const T& value) {
        static_assert(!push_front_only, "push_back on push_front_only");
        a[r++] = value;
    }
    void pop_back() {
        --r;
    }
    
    void push_front(const T& value) {
        static_assert(!push_back_only, "push_front on push_back_only");
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
        
        int cntremd = 1; 

        
        
        

        

        
        
        
        
        
        
        auto [crmn, mnind] = query(i, i + k);
        
        
        
        
        
        
        while(vec[md].size() && a[vec[md].front().e1] >= crmn){
            
            cntremd += vec[md].front().e2;
            
            
            
            
            
            sumsuf[md].pop_front();
            cntsuf[md].pop_front();
            vec[md].pop_front();
        }
        if(mnind != i){
            if(cntremd > 1){
                int ilerest = cntremd - 1;
                
                vec[md].push_front({mnind, ilerest});
                
                
                
                
                sumsuf[md].push_front({mnind, (sumsuf[md].empty() ? 0 : sumsuf[md].front().e2) + ilerest * crmn});
                cntsuf[md].push_front({mnind, (cntsuf[md].empty() ? 0 : cntsuf[md].front().e2) + ilerest});
                
                
                cntremd -= ilerest;
                assert(cntremd == 1);
            }
        }
        
        vec[md].push_front({i, cntremd});
        
        
        
        
        
        

        

        
        
        
        
        sumsuf[md].push_front({i, (sumsuf[md].empty() ? 0 : sumsuf[md].front().e2) + cntremd * a[i]});
        cntsuf[md].push_front({i, (cntsuf[md].empty() ? 0 : cntsuf[md].front().e2) + cntremd});
        
        
        
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
            ll ovkcnt = ile - req;
            
            
            
            
            
            assert(ovkcnt >= 0);
            assert(ovkcnt <= it->second);
            cr -= a[it->first] * ovkcnt;
            res[x.e2] = cr;
        }
    }
    FORR(i,res)
        cout << i << '\n';
}

