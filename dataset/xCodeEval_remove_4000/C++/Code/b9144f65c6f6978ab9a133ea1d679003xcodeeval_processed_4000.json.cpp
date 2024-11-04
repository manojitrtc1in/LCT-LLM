



using namespace std;using uint=unsigned int;using uint32=unsigned int;using int32=int;using int64=long long;using uint64=unsigned long long;using uint128=unsigned __int128;using int128=__int128;









template<typename T>constexpr T UNUSE=T(0);



















template<typename T>inline T gcd(T l,T r){return __gcd(l,r);}template<typename T>inline T lcm(T l,T r){return l/__gcd(l,r)*r;}template<typename T>constexpr int len(const T&t)const{return t.size();}template<typename T,int N>constexpr int len(T(&t)[N])const{return N;}

template<typename T>constexpr int len(const T&t){return size(t);}

template<typename T>inline T lowbit(T x){return x&-x;};inline constexpr int32 bit_count(int32 x){return __builtin_popcount(x);}inline constexpr int32 bit_count(uint32 x){return __builtin_popcount(x);}inline constexpr int32 bit_count(int64 x){return __builtin_popcountll(x);}inline constexpr int32 bit_count(uint64 x){return __builtin_popcountll(x);}inline constexpr int32 bit_length(uint64 x){return 64-__builtin_clzll(x);}inline constexpr int32 bit_length(int64 x){return 64-__builtin_clzll(x);}inline constexpr int32 bit_length(int32 x){return 32-__builtin_clz(x);}inline constexpr int32 bit_length(uint32 x){return 32-__builtin_clz(x);}template<class InputIter,class OutputIter>void prefix_sum(InputIter first,InputIter last,OutputIter output){typename iterator_traits<OutputIter>::value_type cs=0,tmp=0;while(first!=last){tmp=*first++;*output++=cs;cs+=tmp;}*output=cs;}template<class T,class F>T id5(T l,T r,F f){assert(l<=r);while(l<r){T m=l+((typename make_unsigned<T>::type)r-l)/2;if(f(m))r=m;else l=m+1;}return l;}template<class T,class F>T id4(T l,T r,F f){assert(l<=r);while(l<r){T m=l+((typename make_unsigned<T>::type)r-l-1)/2;if(f(m))l=m;else r=m-1;}return l;}void id1(int n,int r,function<bool(int const*)>f){int ids[r];bool vis[n];memset0(vis,n);rep(i,r)ids[i]=i,vis[i]=1;while(1){if(!f(ids))return;int i_last=r-1;for(;i_last>=0;i_last--){int last=ids[i_last];vis[last++]=0;while(last<n and vis[last])last++;if(last<n){vis[last]=1;ids[i_last]=last;break;}}if(-1==i_last)break;i_last++;for(int i=0;i_last<r&&i<n;i++){if(!vis[i]){vis[i]=1;ids[i_last++]=i;}}}}void combinations(int n,int r,function<bool(int const*)>f){int ids[r];rep(i,r)ids[i]=i;while(1){if(!f(ids))return;int i_last;for(i_last=r-1;i_last>=0 and ids[i_last]==i_last+n-r;i_last--);if(-1==i_last)break;ids[i_last]++;rep(i,i_last+1,r)ids[i]=ids[i-1]+1;}}void product(const vector<int>&args,function<bool(int const*)>f){int n=args.size();int ids[n];memset0(ids,n);while(1){if(!f(ids))return;int i_last;for(i_last=n-1;i_last>=0 and ids[i_last]==args[i_last]-1;i_last--);if(-1==i_last)break;ids[i_last]++;rep(i,i_last+1,n)ids[i]=0;}}template<typename T,int maxn=200010>class preallocate{inline static T*__share_pool=new T[maxn];inline static int id11;public:static void init(){id11=0;}void*operator new(size_t count){return&__share_pool[id11++];}};template<typename T,int L,int R>struct gnegarr{T A[R-L];void init(int l,int r){rep(i,l,r)(*this)[i]=0;}T&operator[](int index){return A[index-L];}};template<typename T>struct garr{T*A;typedef T*iterator;typedef T value_type;int N;int n=0;garr(int N):N(N){A=new T[N];}void init(int cnt_v,const T&v){if(v==0){memset(A,0,sizeof(T)*cnt_v);n=cnt_v;}elif(sizeof(T)==1){memset(A,v,cnt_v);n=cnt_v;}else{n=0;int msb=1<<19;for(;msb;msb>>=1){memcpy(A+n,A,n*sizeof(T));n<<=1;if(cnt_v&msb)A[n++]=v;}}}template<typename RIter,enable_if_t<is_same<T,typename iterator_traits<RIter>::value_type>::value,bool> =0>void init(RIter beg,RIter end){uint32 sz=end-beg;memcpy(A,beg,sz*sizeof(T));n=sz;}void init(initializer_list<T>L){n=0;for(auto&v:L)A[n++]=v;}void init(){n=0;}size_t size()const{return n;}T&operator[](int index){if(index>=0)return A[index];return A[index+n];}const T&operator[](int index)const{return const_cast<garr*>(this)->operator[](index);}int id9(const garr<T>&oth){rep(i,min(n,oth.n)){if(A[i]>oth.A[i])return 1;elif(A[i]<oth.A[i])return-1;}if(n==oth.n)return 0;return(n<oth.n)?-1:1;}bool operator==(const garr<T>&oth)const{return oth.n==n and memcmp(oth.A,A,n)==0;}bool operator!=(const garr<T>&oth)const{return!(oth==*this);}T*begin(){return&A[0];}const T*begin()const{return&A[0];}T*end(){return&A[n];}const T*end()const{return&A[n];}void append(const T&v){A[n++]=v;}T pop(){return A[--n];}T pop(int index){int ret=A[index];if(index+1<n)memmove(A+index,A+index+1,sizeof(T)*(n-(index+1)));n--;return ret;}void slice_remove(int l,int r){if(r-l<=0 or r<=0)return;if(l<0)l=0;if(r<n){memmove(A+l,A+r,sizeof(T)*(n-r));n-=r-l;}else{n=l;}}void insert(int index,const T&v){memmove(A+index+1,A+index,sizeof(T)*(n-index));n++;A[index]=v;}int find(const T&v,int start=0){return find(v,start,n);}int find(const T&v,int start,int stop){if(stop-start<=0 or stop<=0)return-1;if(start<0)start=0;rep(i,start,stop){if(A[i]==v)return i;}return n;}friend istream&operator>>(istream&in,garr&obj){rep(i,obj.n)in>>obj.A[i];return in;}friend ostream&operator<<(ostream&os,const garr&obj){rep(i,obj.n-1)os<<obj.A[i]<<' ';os<<obj.A[obj.n-1];return os;}};template<typename T>struct id3{typedef T value_type;int n,m;T*A;id3(int N){A=new T[N];}void init(int n,int m,const T&v){this->n=n;this->m=m;initsequence(n*m,v);}size_t size()const{return n;}void initsequence(int n,const T&v){if(v==0){memset0(A,n);}elif(sizeof(T)==1){memset(A,v,n);}else{int sz=0;int msb=1<<19;for(;msb;msb>>=1){memcpy(A+sz,A,sz*sizeof(T));sz<<=1;if(n&msb)A[sz++]=v;}}}T*operator[](int i){return A+i*m;}const T*operator[](int i)const{return const_cast<id3*>(this)->operator[](i);}};template<class T>struct gqueue{T*A;typedef T*iterator;typedef T value_type;int N;int l=0;int r=0;gqueue(int N):N(N){A=new T[N];}gqueue(int start,int stop):N(stop-start){A=new T[N];rep(i,start,stop)A[r++]=i;}void init(initializer_list<T>L){l=r=0;for(auto&v:L)A[r++]=v;}template<typename RIter,enable_if_t<is_same<T,typename iterator_traits<RIter>::value_type>::value,bool> =0>void init(RIter beg,RIter end){l=0;int sz=end-beg;memcpy(A,beg,sz*sizeof(T));r=sz;}void init(){l=r=0;}size_t size()const{return r-l;}int*begin(){return&A[l];}int*end(){return&A[r];}T&operator[](int index){if(0<=index)return A[index+l];return A[index+r];}const T&operator[](int index)const{if(0<=index)return A[index+l];return A[index+r];}void append(const T&v){if(r==N){memmove(A,A+l,(r-l)*sizeof(T));r-=l;l=0;}A[r++]=v;}T popleft(){return A[l++];}void rotate(int step=1){int sz=r-l;step=step%sz;if(step<0)step+=sz;if((sz-step)<1000+0.035*sz){rep(sz-step)append(popleft());return;}if(step<=sz/2){T buf[step];memcpy(buf,A+sz-step,step*sizeof(T));memmove(A+step,A,(sz-step)*sizeof(T));memcpy(A,buf,step*sizeof(T));}else{T buf[sz-step];memcpy(buf,A,(sz-step)*sizeof(T));memmove(A,A+sz-step,step*sizeof(T));memcpy(A+step,buf,(sz-step)*sizeof(T));}}};template<bool weighted>struct id6{int n;int m=0;int*head;int*wei;int*next;int*end;id6(int N,int M){head=new int[N];end=new int[M];next=new int[M];if(weighted)wei=new int[M];}void init(int n){this->n=n;memset(head,-1,sizeof(int)*n);m=0;}void add(int u,int v){end[m]=v;next[m]=head[u];head[u]=m++;}void add(int u,int v,int w){end[m]=v;next[m]=head[u];wei[m]=w;head[u]=m++;}size_t size()const{return n;}void pprint(){cout<<"Adjll\n";rep(u,n){cout<<" [";for(int eid=head[u];~eid;eid=next[eid]){int v=end[eid];if(weighted){cout<<'['<<v<<","<<wei[eid]<<']';if(~next[eid])cout<<",";}else{cout<<v;if(~next[eid])cout<<",";}}cout<<"]\n";}cout<<'\n';}};using Adjll=id6<0>;using AdjllW=id6<1>;void id7(AdjllW&adj,int u,function<void(int,int)>f){for(int eid=adj.head[u];~eid;eid=adj.next[eid]){int v=adj.end[eid],w=adj.wei[eid];f(v,w);}}void id10(Adjll&adj,int u,function<void(int)>f){for(int eid=adj.head[u];~eid;eid=adj.next[eid]){int v=adj.end[eid];f(v);}}bool id0=[](){cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);return 0;}();void print(){cout<<'\n';}void print(int32*A,int t){rep(i,t)cout<<A[i]<<' ';cout<<'\n';}void print(int64*A,int t){rep(i,t)cout<<A[i]<<' ';cout<<'\n';}template<class T,class Al>void print(vector<T,Al>&A){for(auto v:A)cout<<v<<' ';cout<<'\n';}template<class T,class... Args>void print(const T&v,Args... args){cout<<v<<' ';print(args...);}









tuple<int,int,int> id2(int a, int b) {
    int x0 = 1, x1 = 0;
    int y0 = 0, y1 = 1;
    while (b) {
        int q = a/b;
        pair_assign(a,b,    b,a%b);
        pair_assign(x0,x1,  x1,x0-q*x1);
        pair_assign(y0,y1,  y1,y0-q*y1);
    }
    return make_tuple(a,x0,y0);
}
    
template<typename T>
using enable_if_integral_t = enable_if_t<is_integral_v<T>, bool>;


template<size_t uid=0>
struct modint{
    static void setmod(int32 _mod){mod = _mod;};
    inline static int32 mod = 1e9+7;
    
    int32 v=0; 
    
    modint(){}
    template<typename T, enable_if_integral_t<T> =0>
    modint(T v_=0){*this+=v_;}
    static modint raw(int v){modint ret;ret.v = v;}

    friend ostream& operator<<(ostream& os, const modint& obj){
        os<<obj.v;
        return os;
    }
    friend istream& operator>>(istream& in, modint& obj){
        int v; in>>v;
        obj += v;
        return in;
    }
    operator int32() const{return v;}
    
    
    modint& operator+=(const modint& r){
        v+=r.v;
        if(v>mod) v-=mod;
        return *this;
    }
    template<typename T, enable_if_integral_t<T> =0>
    modint& operator+=(const T& r){
        v = (r + v)%mod;
        if(v<0) v += mod;
        return *this;
    }
    modint& operator-=(const modint& r){
        v-=r.v;
        if(v<0) v+=mod;
        return *this;
    }
    template<typename T, enable_if_integral_t<T> =0>
    modint& operator-=(const T& r){
        *this += -r;
        return *this;
    }
    
    modint& operator*=(const modint& r){
        v = 1ll*v*r.v%mod;
        return *this;
    }
    modint& operator*=(const int32& r){
        v = 1ll*v*r%mod;
        if(v<0) v+=mod;
        return *this;
    }
    modint& operator*=(const uint32& r){
        v = 1ll*v*r%mod;
        return *this;
    }
    template<typename T, enable_if_integral_t<T> =0>
    modint& operator*=(const T& r){
        *this *= modint(r);
        return *this;
    }
    
    
    friend modint operator*(modint l, const modint& r){return modint(l)*=r;}
    
    template<typename T, enable_if_integral_t<T> =0> 
    friend modint operator-(modint l, const T& r){return modint(l.v - r);}
    friend modint operator-(modint l, const modint& r){return modint(l)-=r;}
    
    template<typename T, enable_if_integral_t<T> =0> 
    friend modint operator+(modint l, const T& r){return modint(l.v + r);}
    friend modint operator+(modint l, const modint& r){ return modint(l)+=r;}
    
    modint pow(int64 exp){
        if(exp>=0){
            modint ret = raw(1);
            for(modint bitval(*this);exp; exp>>=1){
                if(exp&1) ret *= bitval;
                bitval *= bitval;
            }
            return ret;
        } else {
            auto [g,inv,_] = id2(v, mod);
            if(g!=1) throw logic_error("modint don't have inv under mod "s+to_string(mod));
            if(inv<0) inv+=mod;
            

            if(exp==-1) return raw(inv);
            return raw(inv).pow(-exp);
        }
    }
};
using mint = modint<0>;


template<typename K, typename V>
struct id8{
    int* lchi;
    int* rchi;
    K* key;
    V* val;
    int uid;
    int root;
    id8(int maxn){
        lchi = new int[maxn];
        rchi = new int[maxn];
        val = new K[maxn];
        key = new V[maxn];
    }
    int newnode(K k, V v,int _lchi=0, int _rchi=0){
        key[uid] = k;
        val[uid] = v;
        lchi[uid] = _lchi;
        rchi[uid] = _rchi;
        return uid++;
    }
    template<typename Iter, typename CT=less<V> >
    void init(Iter beg, Iter end, CT cmp=less<V>()){
        uid = 1;
        vector<int> rchain;
        int idx = 0;
        for(auto it=beg;it!=end;it++,idx++){
            int last = 0;
            while(len(rchain) and cmp(*it, val[rchain.back()])){
                last = rchain.back();
                rchain.pop_back();
            }
            int node = newnode(idx, *it, last);
            if(len(rchain)) rchi[rchain.back()] = node;
            rchain.push_back(node);
        }
        root = rchain[0];
    }
    
};

const int maxn = 2e5 + 10, mod=1e9+7, maxmn = 15e5;


int __t, n, m;
int t0,t1,t2;
int A[maxn];

id3<mint> dpps(maxmn), dp(maxmn);

id8<int,int> CT(maxn);

void dfs(int si){
    if(si==0) return; 
    int lsi = CT.lchi[si], rsi = CT.rchi[si];
    dfs(lsi);
    dfs(rsi);
    rep(medv, 1, m+1){
        dp[si][medv] = dpps[lsi][medv-1]*dpps[rsi][medv];
    }
    rep(medv, 1, m+1){
        dpps[si][medv] = dpps[si][medv-1] + dp[si][medv];
    }
}

int32 main(){
    mint::setmod(mod);
        
    int __T=1;
    cin>>__T;
    for(__t=0; __t<__T;__t++){
        cin >> n >> m;  
        rep(i, n)cin>>A[i];
        
        

        dp.init(n+1,m+1,0);
        dpps.init(n+1,m+1,0);
        

        rep(i, m+1) dpps[0][i] = 1;
    
        CT.init(A,A+n, greater<int>());
        
        dfs(CT.root);
        print(dpps[CT.root][m]);
    }
} 
