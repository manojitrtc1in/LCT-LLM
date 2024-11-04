




































typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;


using namespace std;








template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }



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

    FOR(i,1,1<<n){
        whatis(i)
        int crm = (i-1)&i;
        dp[i] = 0;
        

        

        

        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        crm = (i - 1) & i;
        for(;crm;){
            

            ll comp[14];
            memset(comp,-1,14 << 3);
            
            ll cr = 1;
            
            
            vi bits;
            vi othbits;
            FOR(x,0,n){
                if(crm & (1 << x))
                    bits.push_back(x);
                else if(i & (1 << x))
                    othbits.push_back(x);
            }
            
            FORR(x,bits){ 

                

                

                
                if(true){
                    

                    

                    if(comp[x] == -1){
                        comp[x] = 1;
                        
                        
                        FORR(j,othbits){
                            
                            
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

