







using namespace __gnu_pbds;
using namespace std;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;




namespace NT{
    long long int modulus = 1e9 + 7;  

    bool id19 = false,id5=false;
    vector<long long int> primes,id16;
    vector<long long int> factorial,id20;
    inline long long int modAdd(long long int a,long long int b,long long int mod = modulus){long long int ans = ( a%mod + b%mod )%mod;if(ans<0)ans+=mod;return ans;}
    inline long long int modMul(long long int a , long long int b,long long int mod = modulus){
        return (1LL*(a%mod)*(b%mod))%mod;
    }
    long long int powerMod(long long int base, long long int pw,long long int mod = modulus){
        long long int ret=1;
        if(base==1)return 1;
        while(pw){
            if(pw&1)ret=modMul(ret,base,mod);
            base = modMul(base,base,mod);
            pw>>=1;
        }
        return ret;
    }
    long long int id12(long long int a,long long int b,long long int &x, long long int &y ){
        long long int xx=0,yy=1;y=0;x=1;
        

        while(b){
            long long int quotient =a/b , temp = b; b=a%b;a=temp;
            temp=xx;xx=x - quotient*xx;x=temp;temp=yy;yy = y-quotient*yy;y=temp;
        }
        return a;
    }
    inline long long int ceil_div(long long int a,long long int b){
        return (a+b-1)/b;
    }
    
    inline int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
    inline long long int modInverse(long long int a,long long int mod = modulus){
        long long int x,y,z=0;
        long long int res= id12(a,mod,x,y);
        return(res>1?-1:mod_neg(x,z,mod));
    }
    void id18(vector<long long int> &toFill,int m){
        if(toFill.size()!=m+1)toFill.resize(m+1);
        toFill[1] = 1;
        for(long long int i = 2; i < m; ++i)
            toFill[i] = m - (m/i) * toFill[m%i] % m;  
    }
    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    void id17(long long int N){
        if(id19&&id16.size()-1>=N)return;
        id19=true;
        if(id16.size()!=N+1)id16.resize(N+1);
        if(primes.size())primes.clear();
        for (int i=2; i<=N; ++i) {
            if (id16[i] == 0) {
                id16[i] = i;
                primes.push_back (i);
            }
            for (int j=0; j<(int)primes.size() && primes[j]<=id16[i] && i*primes[j]<=N; ++j)
                id16[i * primes[j]] = primes[j];
        }
    }
    void factorise(vector<long long int> &factors, long long int number){
        

        if(id19&&id16.size()-1<number){
                while(number!=1){
                    factors.push_back(id16[number]);
                    number/=id16[number];
                }
        }
        else{
            for(long long int i=2;i*i<=number&&number!=1;i++){
                while(number%i==0){
                    factors.push_back(i);
                    number/=i;
                }
            }
            if(number>1){
                factors.push_back(number);
            }
        }
    }
    void id11(long long int N,long long int mod =modulus){
        if(id5&&factorial.size()-1>=N)return;
        factorial.resize(N+1);
        id20.resize(N+1);
        factorial[0] = 1; 
        for(long long int i =1;i<N+1;i++){
            factorial[i]=modMul(factorial[i-1],i,mod);
        }
        id20[N] = modInverse(factorial[N],mod); 
        for(int i=N-1;i>=0;i--)id20[i] = modMul(i+1,id20[i+1],mod); 
    }
    long long int nCr(int n,int r,long long int mod=modulus){
        

        long long int ans;
        if(r>n)return 0;
        if(r==n||r==0)return 1;
        

        ans= modMul(modMul(factorial[n],id20[r],mod),id20[n-r],mod);
        return ans;
    }
    long long int gcd(long long int  a,long long int b){if(a<b)swap(a,b);return(b?__gcd(a,b):a);}
    long long int lcm(long long int a , long long int b){return (a*b)/gcd(a,b);}
    long long int gcd(const vector<long long int> &arr){
        long long int ans=arr[0];for(int i=0;i<arr.size();i++)ans=gcd(arr[i],ans);  return ans;
    }
    long long int id13(long long int number,long long int greaterThan=0){
        vector<long long int> factors;
        factorise(factors,number-1);
        for (long long int res=(greaterThan<2?2:greaterThan+1); res<=number; ++res) {
            long long int flag=0;
            for(int i=0;i<factors.size();i++){if(powerMod(res,(number-1)/factors[i],number)==1){flag=1;break;}}
            if(flag==0){return res;}
        }
        return -1;
    }
    pair<long long int,long long int> id10 (long long int x, long long int a, long long int y, long long int b){
        long long int s, t;
        int d = id12(x, y, s, t);
        if (a%d != b%d) return {0,-1};
        return {modAdd(s*b*x+t*a*y,x*y)/d, x*y/d};
    }
    

    pair<long long int,long long int> id10 (const vector<long long int> &x, const vector<long long int> &a){
        pair<long long int,long long int> ret = {x[0], a[0]};
        for (int i = 1; i < x.size(); i++){
            ret = id10 (ret.first, ret.second, x[i], a[i]);
            if (ret.second == -1) break;
        }
        
        

        return ret;
    }
    template<typename _Ty> _Ty id3(std::vector<_Ty> n, std::vector<_Ty> a) {
        _Ty prod = 1;
        for(auto x: n) prod *= x;
    
        _Ty sm = 0;
        for (int i = 0; i < n.size(); i++) {
            _Ty p = prod / n[i];
            sm += a[i] * modInverse(p, n[i]) * p;
        }
    
        return sm % prod;
    }
    int root(int number){return (int)(sqrt(number)+0.5);}
    bool isSquare(int number){int ru = root(number);return ru*ru == number;}
    namespace fft {
        const long long int mod=modulus;
        int root=-1;
        int id14=-1;
        bool initialized=false;
        void init(){
            root =id13(mod);
            id14 = modInverse(root);
            initialized = true;
        }
        void fft(vector<long long int>& a, bool invert) {
            int n=a.size();
            if(!initialized)init();
            long long int PW=powerMod(invert?id14:root, (mod-1)/n);
            for (long long int m=n, h; h=m/2, m>=2; PW=1LL*PW*PW%mod, m=h) {
                for (int i=0, w=1; i<h; ++i, w=1LL*w*PW%mod)
                for (int j=i; j<n; j+=m) {
                    int k=j+h, x=(a[j]-a[k]+mod)%mod;
                    a[j]+=a[k]; a[j] %= mod;
                    a[k]=1LL*w*x%mod;
                }
            }
            for (long long int i=0, j=1; j<n-1; ++j) {
                for (int k=n/2; k>(i^=k); k /= 2);
                if (j<i) swap(a[i], a[j]);
            }
            if (invert) {
                int rev=modInverse(n);
                for (int i=0; i<n; ++i)
                    a[i]=1LL*a[i]*rev%mod;
            }
        }
        vector<long long int> multiply(const vector<long long int>& a, const vector<long long int>& b) {
            int n=max(a.size(), b.size());
            vector<long long int> na=a, nb=b;
            na.resize(2*n); nb.resize(2*n);
            fft(na, false); fft(nb, false);
            for (int i=0; i<2*n; ++i) na[i]=1LL*na[i]*nb[i]%mod;
            fft(na, true);
            

            return na;
        }
        vector<long long int>binExp(vector<long long int> a, long long int b) {
            vector<long long int> res{1};
            while (b > 0) {
                if (b & 1)
                    res = multiply(res,a);
                a = multiply(a,a);
                b >>= 1;
            }
            return res;
        }
        void id6(vector<long long int> &v){
            long long int size=v.size();
            long long int toSize=1;
            while(size){
                size>>=1;
                toSize<<=1;
            }
            v.resize(toSize);
        }
    };
 
    
};
namespace Strings{ 
    template <long long int p,long long int m>
    struct Hash{
        string str;
        vector<long long int> p_pow , p_inv_pow,hash_value;
        Hash(string &s){
            str = s;
            p_pow.resize(s.size(),1);
            p_inv_pow.resize(s.size(),1);
            hash_value.resize(s.size()+1,0);
            for (long long int i= 1; i < str.size(); i++){
                p_pow[i]=(p_pow[i-1]*p)%m;
            }
            long long int id7 = NT::powerMod(p,m-2,m);
            for(long long int i=1;i<str.size();i++){
                p_inv_pow[i]= (p_inv_pow[i-1]*id7)%m;
            }
            for(long long int i=1;i<=str.size();i++){
                hash_value[i]= (hash_value[i-1]+ ((long long int)(s[i-1]-'a'+1))*p_pow[i-1])%m;
            }
        }
        long long int getHash(int l,int r){
            long long int hash = (hash_value[r]- hash_value[l-1])%m;
            hash= NT::modMul(hash,p_inv_pow[l-1],m);
            return hash;
        }
    };
    struct SuffixArray{
    

        vector<int> lcp , sa;
        SuffixArray(string &s,int limit = 256){
            int n = s.length()+1;
            int k=0,a,b;    
            vector<int> x(s.begin(),s.end()+1),y(n),ws(max(n,limit)),rank(n);
            sa = lcp = y;
            iota(sa.begin(),sa.end(),0);
            for (int j = 0, p = 0; p < n; j = max(1, j * 2), limit = p) {
                p = j, iota(y.begin(),y.end(), n - j);
                for(int i=0;i<n;i++) if (sa[i] >= j) y[p++] = sa[i] - j;
                fill(ws.begin(), ws.end(),0);
                for(int i =0; i<n;i++) ws[x[i]]++;
                for(int i=1;i<limit;i++) ws[i] += ws[i - 1];
                for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
                swap(x, y);
                p = 1;
                x[sa[0]] = 0;
                for(int i =1;i<n;i++) a = sa[i - 1], b = sa[i], x[b] =(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
            }
            for(int i=1;i<n;i++){
                rank[sa[i]]=i;
            }
            for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
                for (k && k--, j = sa[rank[i] - 1];
                        s[i + k] == s[j + k]; k++);
            
            if(sa.size())sa.erase(sa.begin());
        }
    };


};




namespace Graph{
    void graphIn(vector<vector<int>>&graph,int nodes,int edges,bool bothWays=true){
        graph.resize(nodes+1);
        for(int i=0;i<edges;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            if(bothWays)graph[v].push_back(u);
        }
    }
    void id0(vector<vector<pair<int,int>>>&graph,int nodes,int edges,bool bothWays=true){
        graph.resize(nodes+1);
        for(int i=0;i<edges;i++){
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            if(bothWays)graph[v].push_back({u,w});
        }
    }
    void SCC(){}
    void diameter(){}
    void id1(){}
}

using namespace NT;
using namespace Graph;
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);




















































ll insum(vector<ll> &arr){int ret=0;forn(i,arr.size()){cin>>arr[i];ret+=arr[i];}return ret;}
map<int ,int> frequency(int n){map<int ,int> ret;forn(i,n){int x;cin>>x;ret[x]++;}return ret;}
template <typename T> istream & operator>>(istream &in, vector<T> & v){for(auto &x: v){in>>x;} return in;}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (int i = 0; i < v.size(); ++i) { os << v[i]; if (i != v.size() - 1) os << " "; } os << "\n"; return os; }
class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
template<class T1,class T2> vector<pair<T2,T1>> id21(map<T1,T2> inp){vector<pair<T2,T1>> ret;for(auto x:inp){ret.pb({x.second,x.first});}return ret;}
template <typename T> inline T id2(T x1,T y1,T x2, T y2) {return abs(x1-x2)+abs(y1-y2);} 
template <typename T> inline T id9(T x1,T y1,T x2, T y2) {return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));} 
template <typename T> inline T id15(T x1,T y1,T x2, T y2) { T tmp1=abs(x1-x2); T tmp2=abs(y1-y2); T tmp3=abs(tmp1-tmp2); T tmp4=min(tmp1, tmp2); return tmp3+tmp4; } 
template <typename T> inline T id4(T x1,T y1,T z1,T x2,T y2,T z2) {return sqrt(square(x2-x1)+square(y2-y1)+square(z2-z1));} 
struct PairToIntComparator {
    bool operator()(const pair<int, int>& v, const int& k) {return (v.first < k);}
    bool operator()(const int& k, const pair<int, int>& v) {return (k < v.first);}
};
class SparseMatrix {
    private:
    vector<vector<int>> st;
    int N, K;
    vector<int> logs;
    int combine(int l, int r=0){
        if(r==0)return l;
        return gcd(l,r);
    }
    public:
    SparseMatrix(int n){
        N=n;
        logs.resize(n+1);
        logs[1] = 0;
        for (int i = 2; i <= N; i++)
            logs[i] = logs[i/2] + 1;
        
        K = logs[n];
        st.assign(n+1,vector<int>(K+1));
    }
    SparseMatrix(vector<int> &a){
        N = a.size();
        logs.resize(N+1);
        logs[1] = 0;
        for (int i = 2; i <= N; i++)
            logs[i] = logs[i/2] + 1;
        K = logs[N];
        st.assign(N+1,vector<int>(K+1,0));
        for (int i = 0; i < N; i++)st[i][0] = combine(a[i]);
        for (int j = 1; j <= K; j++)for (int i = 0; i + (1 << j) <= N; i++)st[i][j] = combine(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }
    void build(vector<int> &a){
        
       for (int i = 0; i < N; i++)st[i][0] = combine(a[i]);
        for (int j = 1; j <= K; j++)for (int i = 0; i + (1 << j) <= N; i++)st[i][j] = combine(st[i][j-1], st[i + (1 << (j - 1))][j - 1]); 
    }
    int query(int l, int r){
        if(l>r){
            return combine(query(l,N-1),query(0,r));
        }
        long long ans = 0;
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                ans = combine(ans,st[l][j]);
                l += 1 << j;
            }
        }
        return ans;   
    }
    int fastQuery(int l, int r) {
        if(l>r){
            return combine(fastQuery(l,N-1),fastQuery(0,r));
        }

        int j = logs[r - l + 1];
        int ans = combine(st[l][j], st[r - (1 << j) + 1][j]);
        return ans;
    }
};
template <typename T>void make_unique(vector<T>& vec) {sort(all(vec));vec.erase(unique(all(vec)), vec.end());}
string id8(int x,int n){int i=n-1;string ans(n,'0');while(x){if(x%2)ans[i]='1';x/=2;i--;}return ans;}
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int mod  = 1e9+7;

















signed main(){
    fast_io();
    int t=1;
    std::function<int(int ,int ,std::function<bool(int)>)> binarySearch = [&](int l, int r, std::function<bool(int)> check){
        while(r-l>1){
            int mid = (r-l)/2 + l;
                if(check(mid)){
                    r= mid;
                }
                else{
                    l=mid;
                }
        }
        return l;
    };
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi arr(n);
        cin>>arr;
        SparseMatrix A(arr);
        function<bool(int)> check = [&](int cur){
            int hi = A.fastQuery(0,cur-1);
            for(int i=0;i<n;i++){
                if(A.query(i,(i+cur - 1)%n)!=hi)return false;
            }
            return true;
        };
        int ans = binarySearch(0,n,check);
        cout<<ans<<endl;

    }
}