




using namespace std;








typedef long long ll;
typedef long double ld;
typedef long long var;
typedef pair<int,int>prii;
typedef pair<ll,ll>prll;
typedef vector<int>veci;
typedef vector<ll>vecl;
typedef vector<veci> graph;
typedef map<int,int> mapii;
typedef set<int> seti;
typedef bitset<64> bits;
typedef string str;

























    ostream &operator << (ostream &out, const type &_) { \
        {code}\
        return out;\
    }

    istream &operator >> (istream &in, type &_) { \
        {code}\
        return in;\
    }


template<class T>T gcd(T a,T b){while(a&&b)if(a>b)a%=b;else b%=a;return a+b;}
template<class T>void sortf(vector<T>&v){stable_sort(v.begin(),v.end());}
template<class T>void sortb(vector<T>&v){stable_sort(v.rbegin(),v.rend());}
template<class T>T max3(T a,T b,T c){return max(a,max(b,c));}template<class T>T
min3(T a,T b,T c){return min(a,min(b,c));}template<typename T>istream&operator>>
(istream&in,vector<T>&v){for(T&t:v)in>>t;return in;}ostream&operator<<(ostream&
out,const vector<char>&v){for(const char&t:v)out<<t;out<<endl;return out;}
template<typename T>ostream&operator<<(ostream&out,const vector<T>&v){for(const
T&t:v)out<<t<<' ';return out;}static void id3(){cin.tie(nullptr)
;cout.tie(nullptr);ios::sync_with_stdio(false);}template<typename T>T lcm(T a,T
b){return a*b/gcd(a,b);}template<class T>void swap(T*a,T*b){T c=*a;*a=*b;*b=c;}
template<typename T>class vector2:public vector<T>{public:int min_ind(){return
min_element(this->begin(),this->end())-this->begin();}int max_ind(){return
max_element(this->begin(),this->end())-this->begin();}T min(){return*min_element
(this->begin(),this->end());}T max(){return*max_element(this->begin(),this->end(
));}void sortf(){::sortf(*this);}void sortb(){::sortb(*this);}vector2():vector<T
>(){}vector2(vector<T>__v):vector<T>(__v){}vector2(initializer_list<T>id0):
vector<T>(id0){}vector2(size_t __n,size_t __val=0):vector<T>(__n,__val){}};
template<class T>T sum(const vector<T>&vc){T ans=0;for(const T&v:vc)ans+=v;
return ans;}int nextInt(){int t;cin>>t;return t;}ll nextLong(){ll t;cin>>t;
return t;}constexpr ll MOD=1000000007;bool operator<<(const string&a,const
string&b){if(a==b)return true;if(a.size()!=b.size())return a.size()<b.size();
return a<b;}int intlen(ll x){int res=1;while(x/=10)res++;return res;}string
operator*(const string&s,int x){string a;while(x--)a+=s;return a;}ll factorial(
int x){ll a=1;for(int i=1;i<=x;i++)a*=i;return a;}template<class T>T reverse(T o
){reverse(all(o));return o;}
template<class R,class I>vector<R>Map(R(*func)(I),const vector<I>&was){vector<R>
res;res.reserve(was.size());for(const auto&e:was)res.push_back(func(e));return
res;}
template<class T>ostream&operator<<(ostream&out,const pair<T,T>&v){out<<v.fir<<
' '<<v.sec;return out;}template<class T>istream&operator>>(istream&in,pair<T,T>
&v){in>>v.fir>>v.sec;return in;}


template<class T>struct reader:public T{template<class...Con>reader(Con&&...par)
:T(par...){cin>>*this;}};template<>class reader<int>{int x;public:reader(){cin>>
x;}operator int&(){return x;}};

class TaskAnswer{};void answer(){cout<<$;throw TaskAnswer();}template<class C,
class...Ts>void answer(C&&cur,Ts&&...args){cout<<cur;answer(args...);}class
Answerer{private:ostream&out;void operator()(){out<<$;throw TaskAnswer();}
public:Answerer(ostream&os):out(os){}template<class C,class...Ts>void operator()
(C&&cur,Ts&&...args){out<<cur;this->operator()(args...);}};

veci pre_func(const string&s){int n=s.size();veci p(n);for(int i=1;i<n;i++){int
j=p[i-1];while(j>0&&s[j]!=s[i])j=p[j-1];if(s[i]==s[j])j++;p[i]=j;}return p;}int
knut(const string&s,const string&t){auto p = pre_func(s + '$' + t);int n=s.size(
),m=t.size();for(int i=n+1;i<=n+m;i++)if(p[i]==n)return i-n-n;return-1;}
veci z_func(const string&s){int n=(int)s.size();veci z(n);for(int i=1,l=0,r=0;i<
n;i++){if(i<=r)z[i]=min(r-i+1,z[i-l]);while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
if(i+z[i]-1>r){l=i;r=i+z[i]-1;}}return z;}

struct Fenwick{int*t,n;~Fenwick(){delete[]t;}Fenwick(const vector<int>&a):n(a.
size()){t=new int[n];for(int i=0;i<n;i++)add(i,a[i]);}void add(int i,int val){
for(;i<n;i|=(i+1))t[i]=t[i]+val;}int get(int r)const{int s=0;for(;r>=0;r=(r&(r+1
))-1)s=s+t[r];return s;}int operator[](int p)const{return get(p);}int operator()
(int l,int r)const{return get(r)-get(l-1);}};

template<class Seq>struct poly_hash{const int M=MOD;int seed,n;vector<int>pows,
hsh;poly_hash(const Seq&s):seed(228),n((int)s.size()){pows.push_back(1);for(int
i=1;i<=n;i++)pows.push_back((pows.back()*seed+M)%M);hsh=vector<int>(n+1);for(
int i=0;i<n;i++)hsh[i+1]=((hsh[i]*seed+s[i])%M+M)%M;}int sub_hash(int l,int r)
const{return((hsh[r]-hsh[l]*pows[r-l])%M+M)%M;}};



class fastio{private:FILE*out=stdout;FILE*in=stdin;FILE *err = stderr;template<
class T>void write(const T&val){this->operator<<(val);}template<class T>void
read(T&val){this->operator>>(val);}template<class T>void error(const T&val){this
->operator<=(val);}public:fastio(){}~fastio(){}FASTIO_PATTERN(>>,char*val,scanf(
"%s",val))FASTIO_PATTERN(<<,const char*val,printf("%s",val))FASTIO_PATTERN(<=,
const char*val,fprintf(this->err,"%s",val))FASTIO_PATTERN(>>,
long long&val,scanf("%lld",&val))FASTIO_PATTERN(<<,long long val,printf("%lld",
val))FASTIO_PATTERN(>>,long&val,scanf("%ld",&val))FASTIO_PATTERN(<<,long val,
printf("%ld",val))FASTIO_PATTERN(>>,short&val,scanf("%hd",&val))FASTIO_PATTERN(
<<,short val,printf("%hd",val))FASTIO_PATTERN(>>,char&val,scanf("%c",&val))
FASTIO_PATTERN(<<,char val,printf("%c",val))template<class T,class...AT>void
write(const T&val,const AT&...args){this->operator<<(val);this->write(args...);}
template<class T,class...AT>void read(T&val,AT&...args){this->operator>>(val);
this->read(args...);}template<class T,class...AT>void error(const T&val,const AT
&...args){this->operator<=(val);this->error(args...);}};

template<class T>fastio&operator<<(fastio&out,const vector<T>&a){for(const T&x:a
)out<<x<<' ';return out;}template<class T>fastio&operator>>(fastio&in,vector<T>&
a){for(int&x:a)in>>x;return in;}fastio console;

class yesno{private:string yes,no;public:yesno(string y="YES",string n="NO"):yes
(y),no(n){}string operator()(bool ok)const{return ok?this->yes:this->no;}};

veci presum(const veci&a){veci ans(len(a)+1);for(int i=0;i<len(a);i++)ans[i+1]=
ans[i]+a[i];return ans;}
int mod(int a,int b){return((a%b)+b)%b;}int sqr(int x){return x*x;}


template<class T>T Next(){T e;cin>>e;return e;}
template<class T>void rmin(T&a,const T&b){a=min(a,b);};
template<class T>void rmax(T&a,const T&b){a=max(a,b);};
const int id1 = (int)1e19 + 99;


Answerer fanswer(cout);





mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

inline void solve();
signed main() {
    id3();


    int t;cin>>t;while(t--)
        try{solve();}catch(TaskAnswer){}catch(...){cout<<"Обожаю сиплесплес\n";}
        cout.flush();
        cerr << "\nTime: " << setprecision(2) <<
            int(1000 * (double)clock() / CLOCKS_PER_SEC) << " ms\n";
        return 0;
}

inline void stress() {
}

int id2(int x) {
    int p = 0;
    while (x) {
        x /= 2;
        p++;
    }
    return 1 << p;
}

struct segment_tree { 
    int *tmin, *tmax, n;
    
    static void build(const veci &a, ll *&t, 
        ll(*oper)(ll, ll),
        ll v = 1ll, ll tl = 0ll, ll tr = -1ll
    ) {
        if (tr == -1ll) tr += (int)a.size();
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, t, oper, v * 2, tl, tm);
        build(a, t, oper, v * 2 + 1, tm + 1, tr);
        t[v] = oper(t[v * 2], t[v * 2 + 1]);
    }
    
    static ll mn(ll a, ll b) { return (a < b ? a : b); }
    static ll mx(ll a, ll b) { return (a > b ? a : b); }
    
    segment_tree(const veci &a) {
        this->n = (int)a.size();
        this->tmin = new int[4 * n + 100];
        this->tmax = new int[4 * n + 100];
        build(a, this->tmin, mn);
        build(a, this->tmax, mx);
    }
    
    int gmin(int l, int r, int v = 1ll, int tl = 0ll, int tr = -1ll) {
        if (tr == -1) tr += n;
        if (l > r) return 1e18;
        if (l == tl && r == tr)
            return tmin[v];
        int tm = (tl + tr) / 2;
        return min(gmin(l, min(r, tm), v * 2, tl, tm), 
                   gmin(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr)
        );
    }
    int gmax(int l, int r, int v = 1ll, int tl = 0ll, int tr = -1ll) {
        if (tr == -1) tr += n;
        if (l > r) return -1e18;
        if (l == tl && r == tr)
            return tmax[v];
        int tm = (tl + tr) / 2;
        return max(gmax(l, min(r, tm), v * 2, tl, tm), 
                     gmax(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr)
        );
    }
};


inline void solve() {
    int n, m;
    cin >> n >> m;
    str s; cin >> s;
    veci a(n);
    for (int i = 0; i < n; i++) a[i] = (s[i] == '+' ? 1 : -1);
    veci pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    segment_tree t(pre);
    while (m--) {
        int l, r; cin >> l >> r;
        int sm = pre[r] - pre[l - 1];
        int mn = min(t.gmin(0, l - 1), t.gmin(r + 1, n) - sm);
        int mx = max(t.gmax(0, l - 1), t.gmax(r + 1, n) - sm);
        cout << mx - mn + 1 << $;
    }
}


