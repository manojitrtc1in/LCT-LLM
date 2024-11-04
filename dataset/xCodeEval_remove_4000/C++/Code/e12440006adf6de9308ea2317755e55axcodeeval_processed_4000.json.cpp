



using namespace std;using uint=unsigned int;using uint32=unsigned int;using int32=int;using int64=long long;using uint64=unsigned long long;using uint128=unsigned __int128;using int128=__int128;









template<typename T>constexpr T UNUSE=T(0);



















template<typename T>inline T gcd(T l,T r){return __gcd(l,r);}template<typename T>inline T lcm(T l,T r){return l/__gcd(l,r)*r;}template<typename T>constexpr int len(const T&t)const{return t.size();}template<typename T,int N>constexpr int len(T(&t)[N])const{return N;}

template<typename T>constexpr int len(const T&t){return size(t);}

template<typename T>inline T lowbit(T x){return x&-x;};inline constexpr int32 bit_count(int32 x){return __builtin_popcount(x);}inline constexpr int32 bit_count(uint32 x){return __builtin_popcount(x);}inline constexpr int32 bit_count(int64 x){return __builtin_popcountll(x);}inline constexpr int32 bit_count(uint64 x){return __builtin_popcountll(x);}inline constexpr int32 bit_length(uint64 x){return 64-__builtin_clzll(x);}inline constexpr int32 bit_length(int64 x){return 64-__builtin_clzll(x);}inline constexpr int32 bit_length(int32 x){return 32-__builtin_clz(x);}inline constexpr int32 bit_length(uint32 x){return 32-__builtin_clz(x);}template<class InputIter,class OutputIter>void prefix_sum(InputIter first,InputIter last,OutputIter output){typename iterator_traits<OutputIter>::value_type cs=0,tmp=0;while(first!=last){tmp=*first++;*output++=cs;cs+=tmp;}*output=cs;}template<class T,class F>T id6(T l,T r,F f){assert(l<=r);while(l<r){T m=l+((typename make_unsigned<T>::type)r-l)/2;if(f(m))r=m;else l=m+1;}return l;}template<class T,class F>T id5(T l,T r,F f){assert(l<=r);while(l<r){T m=l+((typename make_unsigned<T>::type)r-l-1)/2;if(f(m))l=m;else r=m-1;}return l;}void id1(int n,int r,function<bool(int const*)>f){int ids[r];bool vis[n];memset0(vis,n);rep(i,r)ids[i]=i,vis[i]=1;while(1){if(!f(ids))return;int i_last=r-1;for(;i_last>=0;i_last--){int last=ids[i_last];vis[last++]=0;while(last<n and vis[last])last++;if(last<n){vis[last]=1;ids[i_last]=last;break;}}if(-1==i_last)break;i_last++;for(int i=0;i_last<r&&i<n;i++){if(!vis[i]){vis[i]=1;ids[i_last++]=i;}}}}void combinations(int n,int r,function<bool(int const*)>f){int ids[r];rep(i,r)ids[i]=i;while(1){if(!f(ids))return;int i_last;for(i_last=r-1;i_last>=0 and ids[i_last]==i_last+n-r;i_last--);if(-1==i_last)break;ids[i_last]++;rep(i,i_last+1,r)ids[i]=ids[i-1]+1;}}void product(const vector<int>&args,function<bool(int const*)>f){int n=args.size();int ids[n];memset0(ids,n);while(1){if(!f(ids))return;int i_last;for(i_last=n-1;i_last>=0 and ids[i_last]==args[i_last]-1;i_last--);if(-1==i_last)break;ids[i_last]++;rep(i,i_last+1,n)ids[i]=0;}}template<typename T,int L,int R>struct gnegarr{T A[R-L];void init(int l,int r){rep(i,l,r)(*this)[i]=0;}T&operator[](int index){return A[index-L];}};template<typename T>struct garr{T*A;typedef T*iterator;typedef T value_type;int N;int n=0;garr(int N):N(N){A=new T[N];}void init(int cnt_v,const T&v){if(v==0){memset(A,0,sizeof(T)*cnt_v);n=cnt_v;}elif(sizeof(T)==1){memset(A,v,cnt_v);n=cnt_v;}else{n=0;int msb=1<<19;for(;msb;msb>>=1){memcpy(A+n,A,n*sizeof(T));n<<=1;if(cnt_v&msb)A[n++]=v;}}}template<typename RIter,enable_if_t<is_same<T,typename iterator_traits<RIter>::value_type>::value,bool> =0>void init(RIter beg,RIter end){uint32 sz=end-beg;memcpy(A,beg,sz*sizeof(T));n=sz;}void init(initializer_list<T>L){n=0;for(auto&v:L)A[n++]=v;}void init(){n=0;}size_t size()const{return n;}T&operator[](int index){if(index>=0)return A[index];return A[index+n];}const T&operator[](int index)const{if(index>=0)return A[index];return A[index+n];}int id10(const garr<T>&oth){rep(i,min(n,oth.n)){if(A[i]>oth.A[i])return 1;elif(A[i]<oth.A[i])return-1;}if(n==oth.n)return 0;return(n<oth.n)?-1:1;}bool operator==(const garr<T>&oth)const{return oth.n==n and memcmp(oth.A,A,n)==0;}bool operator!=(const garr<T>&oth)const{return!(oth==*this);}T*begin(){return&A[0];}T*end(){return&A[n];}void append(const T&v){A[n++]=v;}T pop(){return A[--n];}T pop(int index){int ret=A[index];if(index+1<n)memmove(A+index,A+index+1,sizeof(T)*(n-(index+1)));n--;return ret;}void slice_remove(int l,int r){if(r-l<=0 or r<=0)return;if(l<0)l=0;if(r<n){memmove(A+l,A+r,sizeof(T)*(n-r));n-=r-l;}else{n=l;}}void insert(int index,const T&v){memmove(A+index+1,A+index,sizeof(T)*(n-index));n++;A[index]=v;}int find(const T&v,int start=0){return find(v,start,n);}int find(const T&v,int start,int stop){if(stop-start<=0 or stop<=0)return-1;if(start<0)start=0;rep(i,start,stop){if(A[i]==v)return i;}return n;}friend istream&operator>>(istream&in,garr&obj){rep(i,obj.n)in>>obj.A[i];return in;}};template<typename T>struct id4{typedef T value_type;int n,m;T*A;id4(int N){A=new T[N];}void init(int n,int m,const T&v){this->n=n;this->m=m;initsequence(n*m,v);}size_t size()const{return n;}void initsequence(int n,const T&v){if(v==0){memset0(A,n);}elif(sizeof(T)==1){memset(A,v,n);}else{int sz=0;int msb=1<<19;for(;msb;msb>>=1){memcpy(A+sz,A,sz*sizeof(T));sz<<=1;if(n&msb)A[sz++]=v;}}}T*operator[](int i){return A+i*m;}};template<class T>struct mqueue{T*A;typedef T*iterator;typedef T value_type;int N;int l=0;int r=0;mqueue(int N):N(N){A=new T[N];}mqueue(int start,int stop):N(stop-start){A=new T[N];rep(i,start,stop)A[r++]=i;}void init(initializer_list<T>L){l=r=0;for(auto&v:L)A[r++]=v;}template<typename RIter,enable_if_t<is_same<T,typename iterator_traits<RIter>::value_type>::value,bool> =0>void init(RIter beg,RIter end){l=0;int sz=end-beg;memcpy(A,beg,sz*sizeof(T));r=sz;}void init(){l=r=0;}size_t size()const{return r-l;}int*begin(){return&A[l];}int*end(){return&A[r];}T&operator[](int index){if(0<=index)return A[index+l];return A[index+r];}const T&operator[](int index)const{if(0<=index)return A[index+l];return A[index+r];}void append(const T&v){if(r==N){memmove(A,A+l,(r-l)*sizeof(T));r-=l;l=0;}A[r++]=v;}T popleft(){return A[l++];}void rotate(int step=1){int sz=r-l;step=step%sz;if(step<0)step+=sz;if((sz-step)<1000+0.035*sz){rep(sz-step)append(popleft());return;}if(step<=sz/2){T buf[step];memcpy(buf,A+sz-step,step*sizeof(T));memmove(A+step,A,(sz-step)*sizeof(T));memcpy(A,buf,step*sizeof(T));}else{T buf[sz-step];memcpy(buf,A,(sz-step)*sizeof(T));memmove(A,A+sz-step,step*sizeof(T));memcpy(A+step,buf,(sz-step)*sizeof(T));}}};template<bool weighted>struct id7{int n;int m=0;int*head;int*wei;int*next;int*end;id7(int N,int M){head=new int[N];end=new int[M];next=new int[M];if(weighted)wei=new int[M];}void init(int n){this->n=n;memset(head,-1,sizeof(int)*n);m=0;}void add(int u,int v){end[m]=v;next[m]=head[u];head[u]=m++;}void add(int u,int v,int w){end[m]=v;next[m]=head[u];wei[m]=w;head[u]=m++;}size_t size()const{return n;}void pprint(){cout<<"Adjll\n";rep(u,n){cout<<" [";for(int eid=head[u];~eid;eid=next[eid]){int v=end[eid];if(weighted){cout<<'['<<v<<","<<wei[eid]<<']';if(~next[eid])cout<<",";}else{cout<<v;if(~next[eid])cout<<",";}}cout<<"]\n";}cout<<'\n';}};using Adjll=id7<0>;using AdjllW=id7<1>;void id9(AdjllW&adj,int u,function<void(int,int)>f){for(int eid=adj.head[u];~eid;eid=adj.next[eid]){int v=adj.end[eid],w=adj.wei[eid];f(v,w);}}void id12(Adjll&adj,int u,function<void(int)>f){for(int eid=adj.head[u];~eid;eid=adj.next[eid]){int v=adj.end[eid];f(v);}}bool id0=[](){cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);return 0;}();void print(){cout<<'\n';}void print(int32*A,int t){rep(i,t)cout<<A[i]<<' ';cout<<'\n';}void print(int64*A,int t){rep(i,t)cout<<A[i]<<' ';cout<<'\n';}template<class T,class Al>void print(vector<T,Al>&A){for(auto v:A)cout<<v<<' ';cout<<'\n';}template<class T,class... Args>void print(const T&v,Args... args){cout<<v<<' ';print(args...);}










const int Mod = 1000000007;



int32 mulmod(int32 a, int32 b, int32 Mod=::Mod){
    int32 ret = (int64(a)*b)%Mod;
    if(ret<0) ret+=Mod;
    return ret;
}


    int id2(int a, int b, int &x0, int &y0) {
        x0 = 1; int x1 = 0;
        y0 = 0; int y1 = 1;
        while (b) {
            int q = a / b;
            pair_assign(a,b, b,a%b);
            pair_assign(x0,x1,  x1,x0-q*x1);
            pair_assign(y0,y1,  y1,y0-q*y1);
        }
        return a;
    }




    int powmod(int base, int exp, int Mod) {
        if (exp>=0){
            

            base = (base+Mod)%Mod;
            int res=1;
            while(exp){
                if(exp&1) 
                    res=mulmod(res, base, Mod);
                base=mulmod(base, base, Mod);
                exp>>=1;
            }
            return res;
        } else {
            int inv, y0; id2(base, Mod, inv, y0);
            if(inv<0) inv+=Mod;
            if(exp==-1) return inv;
            return powmod(inv, -exp, Mod);
        }
    }



    
    template<class T>
    vvt id11(vvt& matL, vvt& matR, int64 Mod){
        auto m=len(matL),n=len(matR),p=len(matR[0]);
        vvt ret(m, vector<T>(p, 0));
        rep(i,m) rep(j,p) {
            T val = 0;
            rep(k,n) {
                val = (val+matL[i][k]*matR[k][j])%Mod;
            }
            ret[i][j] = val;
        }
        return ret;
    }

    template<class T>
    vvt id3(vvt& mat, int64 b){
        auto n = len(mat);
        vvt ret(n, vector<T>(n, 0));
        rep(i,n) ret[i][i] = 1;
        while(b){
            if(b&1) 
                ret = id11(ret, mat, Mod);
            mat = id11(mat, mat, Mod);
            b>>=1;
        }
        return ret;
    }
    



    namespace Combinatorics{
        const int maxn = 100000+10;
        int fac[maxn]={1,1};
        int invfac[maxn]={1,1};
        int inv[maxn]={UNUSE<int>,1}; 

        void init(){
            rep(i, 2, maxn){
                inv[i] = mulmod(inv[Mod%i],Mod-Mod/i);
                

                

                fac[i] = mulmod(fac[i-1], i);
                invfac[i] = mulmod(invfac[i-1], inv[i]);
            }
        }
        
        int perm(int n, int r){
            
                assert(n>=0);
            
            if(r<0 or n<r) return 0;
            return mulmod(fac[n], invfac[n-r]);
        }
        int comb(int n, int r){
            return mulmod(perm(n,r), invfac[r]);
        }
    }



    

        vector<int> id13(int tar){
            vector<int> ret;
            for(int i=2;i*i<=tar;i+=2-(i==2)){
                if(tar%i==0){
                    do{
                        tar/=i;
                    }
                    while(tar%i==0);
                    ret.push_back(i);
                }
            }
            if(tar>1) ret.push_back(tar);
            return ret;
        }
        

namespace RSH{
    uint64 base;
    uint64 mod;
    

    

    uint Modcans32bit[10] = {4294967291, 4294967279, 4294967231, 4294967197, 4294967189, 4294967161, 4294967143, 4294967111, 4294967087, 4294967029};
    uint64 Modcans64bit[10] = {18446744073709551611ull, 18446744073709551599ull, 18446744073709551551ull, 18446744073709551517ull, 18446744073709551509ull, 18446744073709551481ull, 18446744073709551463ull, 18446744073709551431ull, 18446744073709551407ull, 18446744073709551349ull};
    struct pair_hash {
        uint128 operator()(const pair<uint64,uint64> & v) const {
            uint128 hs=v.fi; hs<<=64;
            return hs+v.se;
        }
    };
    int randrange(int l, int r){
        srand(time(NULL));
        return l+rand()%(r-l);
    }
    template<class T>
    void fixsize(T& s, int sz){
        uint64 hs = 0;
        int ns = s.size();
        int64 pasz = 1;
        rep(ri, ns){
            int li=ri-sz+1;
            hs = (uint128(base)*hs + s[ri])%mod;
            if(ri>=sz)
                hs = ((-int128(pasz)*s[li-1] + hs)%mod+mod)%mod;
            else{
                pasz = uint128(pasz)*base%mod;
            }
            
            if(ri>=sz-1) {
                

            }
        }
    }
}



const int maxn = 2e5 + 10;

int __t;
int a,b,d;

void solve(){
    a = a|b;
    if(lowbit(a|b)<lowbit(d)) {
        print(-1); return;
    }
    int id8 = __builtin_ffsll(d)-1, inv;
    if(d==lowbit(d)) inv = 1;
    else inv = powmod(1<<(30-id8), -1, d>>id8);
    print( (inv<<30) - (1<<id8) );
}

int32 main(){
    int __T=1;
    cin>>__T;
    for(__t=0; __t<__T;__t++){
        cin >> a>>b>>d;
        solve();
    }
    
} 
