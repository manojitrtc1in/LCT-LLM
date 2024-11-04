























using namespace std;








using namespace std::tr1;


































double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(){};triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};


template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else return t1.b<t2.b;}
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }





















































inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));return((x >> 16) | (x << 16));}
inline int sign(int x){return (x >> 31) | (-x >> 31);}
inline bool id0(int x){return (x!=0 && (x&(x-1))==0);}







template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";cout<<endl;}








inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(int a,int b){return a/gcd(a,b)*(ll)b;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}
inline ll lcm(ll a,ll b,ll c){return lcm(lcm(a,b),c);}
inline ll lcm(int a,int b,int c){return lcm(lcm(a,b),(ll)c);}

inline ll max(ll a,ll b){return (a>b)?a:b;}
inline int max(int a,int b){return (a>b)?a:b;}
inline double max(double a,double b){return (a>b)?a:b;}
inline ll max(ll a,ll b,ll c){return max(a,max(b,c));}
inline int max(int a,int b,int c){return max(a,max(b,c));}
inline double max(double a,double b,double c){return max(a,max(b,c));}
inline ll min(ll a,ll b){return (a<b)?a:b;}
inline int min(int a,int b){return (a<b)?a:b;}
inline double min(double a,double b){return (a<b)?a:b;}
inline ll min(ll a,ll b,ll c){return min(a,min(b,c));}
inline int min(int a,int b,int c){return min(a,min(b,c));}
inline double min(double a,double b,double c){return min(a,min(b,c));}

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m;++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }











vector<int> d[300];
int c[300][100001];
int dc = 200;
const int bsize = 350;
const int maxsize = 800;
int erase(int pos)
{
    for (int i = 0; i < dc; ++i)
    {
        if (pos >= d[i].size()){
            pos -= d[i].size();
        }
        else
        {
            int res = d[i][pos];
            d[i].erase(d[i].begin() + pos);
            c[i][res]--;
            return res;
        }
    }
}
void rebuild();
void insert(int pos, int val)
{
    for (int i = 0; i < dc; ++i){
        if (pos > d[i].size())
        {
            pos -= d[i].size();
        }
        else
        {
            d[i].insert(d[i].begin() + pos, val);
            c[i][val]++;
            if (d[i].size() >= maxsize)
            {
                rebuild();
            }
            break;
        }
    }
}
int get_ans(int l, int r, int val)
{
    int res = 0;
    int x = 0;
    int y = -1;
    for (int i = 0; i < dc; ++i)
    {
        x = y + 1;
        y += d[i].size();
        if (x >= l && y <= r){
            res += c[i][val];
        }
        else if (x >= l && y > r)
        {
            int t = r - x + 1;
            for (int j = 0; j < t; ++j){
                if (d[i][j] == val)
                    res++;
            }
        }
        else if (x < l && y <= r){
            int bpos = l - x;
            int siz = d[i].size();
            for (int j = bpos; j < siz; ++j){
                if (d[i][j] == val){
                    ++res;
                }
            }
        }
        else if (l >= x && r <= y){
            int bpos = l - x;
            int epos = r - x;
            for (int j = bpos; j <= epos; ++j){
                if (d[i][j] == val) ++res;
            }
        }
    }
    return res;
}
int n;
int a[100010];
void rebuild(){
    int k = 0;
    for (int i = 0; i < dc; ++i){
        for (int x : d[i]){
            a[k++] = x;
        }
        d[i].clear();
        memset(c[i], 0, 400001);
    }
    k = 0;
    int block = 0;
    d[0].clear();
    for (int i = 0; i < n; ++i)
    {
        if (k == bsize){
            ++block;
            k = 0;
        }
        d[block].push_back(a[i]);
        c[block][a[i]]++;
        ++k;
    }
    dc = block + 1;
}
int main()
{
    cin >> n;
    FI(n)
    {
        cin >> a[i];
    }
    int k = 0;
    int block = 0;
    for (int i = 0; i < n; ++i)
    {
        if (k == bsize){
            ++block;
            k = 0;
        }
        d[block].push_back(a[i]);
        c[block][a[i]]++;
        ++k;
    }
    dc = block + 1;
    int q;
    cin >> q;
    int lans = 0;
    bool e = false;
    while (q--){
        int t;
        int l, r;
        cin >> t;
        if (t == 1)
        {
            cin >> l >> r;
            l += lans;
            r += lans;
            if (l > n) l -= n;
            if (r > n) r -= n;
            if (l > r) swap(l, r);
            int t = erase(r-1);
            insert(l-1, t);
        }
        else
        {
            cin >> l >> r >> k;
            l += lans;
            r += lans;
            k += lans;
            if (l > n) l -= n;
            if (r > n) r -= n;
            if (k > n) k -= n;
            if (l > r) swap(l, r);

            lans = get_ans(l-1, r-1, k);
            cout << lans << '\n';
        }
    }
    return 0;
}
































































































