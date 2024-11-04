#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

#define N 2000001

constexpr ll mod = 1e9 + 7;

ll fac[N];
ll facinv[N];



void pre(){
    fac[0] = 1;
    FOR(i,1,N)
        fac[i] = fac[i - 1] * i % mod;
    
    facinv[N - 1] = 407182070;
    for(int i = N - 2; i >= 0; --i)
        facinv[i] = facinv[i + 1] * (i + 1) % mod;
    

    

    

}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    pre();
    ll n;
    sc(n);
    ll a[n];
    GET(a);
    
    
    
        

        

        
    


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    

    ll res = 0;
    ll dp[1 << n]; 

    

    
    
    ll dp2[1 << n]; 

    int bits[32], othbits[32];
    FOR(i,1,1<<n){
        whatis(i)
        int crm = (i-1)&i;
        dp[i] = 0;
        

        

        

        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        crm = (i - 1) & i;
        for(;crm;){
            

            ll comp[14];
            memset(comp,-1,14 << 3);
            
            ll cr = 1;
            
            
            
            
            
            
            
            
            
            
            

            
            
            
            
            
            
            
            
            
            

            

            

            

            

            
            
            
            int tcrm = crm;
            while(tcrm){
                

                

                

                int x = 31 - __builtin_clz(tcrm);
                tcrm ^= 1 << x;
                

                

                
                if(true){
                    

                    

                    if(comp[x] == -1){
                        comp[x] = 1;
                        
                        
                        
                        int tmpoth = crm ^ i;
                        
                        while(tmpoth){
                            int j = 31 - __builtin_clz(tmpoth);
                            tmpoth ^= 1 << j;
                            
                            
                            if(true){
                                
                                

                                
                                comp[x] *= (ll)(a[x]) * facinv[a[x] + a[j]] % mod * fac[a[x] + a[j] - 1] % mod;
                                comp[x] %= mod;
                            }
                        }
                    }
                    cr *= comp[x];
                    cr %= mod;
                }
            }
            

            

            
            whatis(cr)
            whatis(dp[crm])
            cr *= 1 - dp[crm];
            cr %= mod;
            dp[i] += cr;
            dp[i] %= mod;
            whatis(dp[i])
            

            
            if(i == ((1 << n) - 1)){
                whatis(crm)
                whatis(cr)
                res += (ll)__builtin_popcount(crm) * cr;
                res %= mod;
            }
            
            
            crm = (crm-1)&i;
        }
    }
    whatis(dp[1])
    whatis(dp[2])
    
    whatis(dp[3])
    res += (ll)n * (1 - dp[(1 << n) - 1]);
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << '\n';
    
}

