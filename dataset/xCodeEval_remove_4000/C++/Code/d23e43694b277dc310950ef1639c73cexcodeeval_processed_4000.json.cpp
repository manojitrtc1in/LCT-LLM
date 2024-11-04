



typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
using namespace __gnu_pbds;
typedef  vector<int> vi;
typedef  vector<vi> vii;
typedef  vector<tuple<int,int,int>> vti3;


int mod1=(1e9+7);
ULL mod2=(1152921504606846976);




















void printans(int f){
    if(f){cout<<"YES\n";}else{ cout<<"NO\n";}
}

 

 

typedef unsigned long long ull; 
    char gc() {
        static char buf[1<<16],*S,*T;
        if(T==S) {
            T=(S=buf)+fread(buf,1,1<<16,stdin);
            if(T==S) return EOF;
        }
        return *S++;
    }


    int re(){
        char c;int w=1;
        while((c=getchar())<'0'||c>'9')if(c=='-')w=-1;
        int res = c-'0';
        while((c=getchar())>='0'&&c<='9')res = res*10+c-'0';
        return res*w;
    }
    

    
    typedef std::vector<int> poly;
    typedef std::pair<int,int> pii;
    typedef std::pair<poly,poly> ppp;
    poly Pre(poly A,int L){A.resize(L);return A;}
    void Prt(poly A){for(int x:A)printf("%d ",x);puts("");}
    poly Flt(poly A){while(!*A.rbegin())A.pop_back();return A;}
    poly Rev(poly A){return std::reverse(A.begin(),A.end()),A;}
    poly Rep(int n){static poly F;F.clear();for(int i=0;i<n;++i)F.pb(re());return F;}
    const int mdig = 19,mod = 998244353,g = 3,maxn = (1<<mdig);
    int ksm(int a,int x){
        int ans = 1,bas = a;
        while(x){
            if(x&1)ans = 1ll*ans*bas%mod;
            bas = 1ll*bas*bas%mod,x >>= 1;
        }return ans;
    }
    
    const int ivg = ksm(g,mod-2),I = ksm(g,(mod-1)/4);
    int gs[2][mdig][maxn];
    void NTT(std::vector<int> &A,int N,int op){
        static int rev[maxn],flag;static ull tmp[maxn];
        if(!flag){

            flag = 1;
            for(int op=0;op<2;++op)
                for(int i=0;i<mdig;++i){
                    int l=(1<<i),w=ksm(op?ivg:g,(mod-1)/(2*l));
                    for(int p=0,c=1;p<l;++p,c=1ll*c*w%mod)gs[op][i][p] = c;
                }
        }
        for(int i=0;i<N;++i)rev[i] = (rev[i>>1]>>1)|((i&1)*N/2);
        for(int i=0;i<N;tmp[i]=A[i],++i)if(i<rev[i])swap(A[i],A[rev[i]]);
        for(int l=1,d=0;l<N;l*=2,++d){
            for(int r=0;r<N;r+=(2*l)){
                int *GS=gs[op][d];
                ull *tp1=&tmp[l+r],*tp2=&tmp[r];
                for(int p=0,t;p<l;++p,++GS,++tp1,++tp2)
                    t = 1ll*(*GS)*(*tp1)%mod,(*tp1) = (*tp2)+mod-t,(*tp2) += t;
            }
            if(d == 17)for(int i=0;i<N;++i)tmp[i] %= mod;
        }
        for(int i=0,ivn=ksm(N,mod-2);i<N;++i)A[i] = tmp[i]*(op?ivn:1)%mod;
    }
    poly Val(int x){poly ret;ret.pb(x);return ret;}
    poly Mul(poly A,int x){x = (x%mod+mod)%mod;for(int &v:A)v = 1ll*v*x%mod;return A;}
    poly Der(poly A){for(int i=0;i<A.size()-1;++i)A[i] = 1ll*A[i+1]*(i+1)%mod;*A.rbegin() = 0;return A;}
    poly Int(poly A){
        static int iv[maxn]={0,1},now=1;
        if(now < A.size())for(int i=now+1;i<=A.size();++i)iv[i] = mod-1ll*(mod/i)*iv[mod%i]%mod;
        A.pb(0);for(int i=A.size()-1;i;--i)A[i] = 1ll*A[i-1]*iv[i]%mod;A[0] = 0;return A;
    }
    poly Pls(poly A,poly B){
        A.resize(max(A.size(),B.size()));
        for(int i=0;i<B.size();++i)A[i] = (A[i]+B[i])%mod;return A;
    }
    poly Mns(poly A,poly B){
        A.resize(max(A.size(),B.size()));
        for(int i=0;i<B.size();++i)A[i] = (A[i]-B[i]+mod)%mod;return A;
    }
    poly Prd(poly A,poly B,int Len=-1){
        int L = 1;while(L<A.size()+B.size()-1)L *= 2;A.resize(L),B.resize(L);
        NTT(A,L,0),NTT(B,L,0);for(int i=0;i<L;++i)A[i] = 1ll*A[i]*B[i]%mod;NTT(A,L,1);
        if(~Len)A.resize(Len);return A;
    }
    poly id0(poly A,poly B){return Rev(Prd(Rev(A),B,A.size()));}
    poly id2(poly A,poly B,int L){poly R = Prd(A,B);for(int i=L;i<R.size();++i)R[i%L] = (R[i%L]+R[i])%mod;return R;}
    poly Inv(poly A,int Len=-1){
        assert(A[0] != 0),Len = ~Len?Len:A.size();
        poly now;now.pb(inv(A[0]));int dig=1;
        while(dig<Len){
            dig *= 4;poly t1 = Pre(now,dig),t2 = Pre(Pre(A,dig/2),dig);
            NTT(t1,dig,0),NTT(t2,dig,0);
            for(int i=0;i<dig;++i)t1[i] = 1ll*t1[i]*t1[i]%mod*t2[i]%mod;
            NTT(t1,dig,1),now = Mns(Mul(now,2),Pre(t1,dig/=2));
        }
        now.resize(Len);return now;
    }
    poly Sqr(poly A,int Len=-1){
        assert(A[0] == 1),Len = ~Len?Len:A.size();
        poly now;now.pb(1);int dig=1;
        while(dig<Len)dig *= 2,now = Mul(Pls(now,Prd(Pre(A,dig),Inv(now,dig),dig)),inv(2));
        now.resize(Len);return now;
    } 
    poly Ln(poly A,int Len=-1){
        assert(A[0] == 1),Len = ~Len?Len:A.size();
        poly ret = Int(Prd(Der(A),Inv(A,Len),Len));
        ret.resize(Len);return ret;
    } 
    poly Exp(poly A,int Len=-1){

        assert(A[0] == 0),Len = ~Len?Len:A.size();
        poly now;now.pb(1);int dig=1;
        while(dig<Len)dig *= 2,now = Prd(now,Mns(Pls(Pre(A,dig),Val(1)),Ln(now,dig)),dig);
        now.resize(Len);return now;
    }
    poly Ksm(poly A,int K,int Len=-1){return Exp(Mul(Ln(A),K));}
    poly Cos(poly A){return Mul(Pls(Exp(Mul(A,I)),Exp(Mul(A,mod-I))),inv(2));}
    poly Sin(poly A){return Mul(Mns(Exp(Mul(A,I)),Exp(Mul(A,mod-I))),inv(2*I%mod));}
    poly Asin(poly A){return Pre(Int(Prd(Inv(Sqr(Mns(Val(1),Prd(A,A,A.size())))),Der(A),A.size())),A.size());}
    poly Acos(poly A){return Pre(Int(Mul(Prd(Inv(Sqr(Mns(Val(1),Prd(A,A,A.size())))),Der(A),A.size()),-1)),A.size());}
    poly Atan(poly A){return Pre(Int(Prd(Inv(Pls(Val(1),Prd(A,A,A.size()))),Der(A),A.size())),A.size());}
    ppp Div(poly A,poly B){

        int n = A.size(),m = B.size(),L = n-m+1;A = Rev(A),B = Rev(B);
        poly C = Prd(Pre(A,L),Inv(Pre(B,L)),L),RR = Pre(Mns(A,Prd(B,C)),A.size());
        return std::make_pair(Rev(C),Pre(Rev(RR),m-1));
    }
    poly Mod(poly A,poly B){if(A.size() >= B.size())return Div(A,B).second;else return A;}
    struct Evaluation{

        poly Q[maxn<<1],P[mdig];int m,X[maxn],Y[maxn]; 
        void Prp(int k,int l,int r){

            if(l == r)return Q[k].clear(),Q[k].pb(1),Q[k].pb((mod-X[l])%mod),void();
            int mid = l+r>>1;Prp(k<<1,l,mid),Prp(k<<1|1,mid+1,r),Q[k] = Flt(Prd(Q[k<<1],Q[k<<1|1]));
        }
        void Sol(int k,int l,int r,int d){
            if(l == r)return Y[l] = P[d][0],void();
            int mid = l+r>>1;P[d].resize(r-l+1);
            P[d+1] = id0(P[d],Q[k<<1|1]),Sol(k<<1,l,mid,d+1);
            P[d+1] = id0(P[d],Q[k<<1]),Sol(k<<1|1,mid+1,r,d+1);
        }
        std::vector<int> Eva(poly A,std::vector<int> pts){

            m = pts.size();for(int i=0;i<m;++i)X[i] = pts[i];
            Prp(1,0,m-1),P[0] = id0(A,Inv(Pre(Q[1],max((int)A.size(),m)))),Sol(1,0,m-1,0);
            std::vector<int> ret;for(int i=0;i<m;++i)ret.pb(Y[i]);return ret;
        }
    }EVA;
    struct Interpolation{
        int n,Y[maxn];pii Pt[maxn];
        poly Q[maxn<<1];
        void Prp(int k,int l,int r){
            if(l == r){return Q[k].clear(),Q[k].pb((mod-Pt[l].first)%mod),Q[k].pb(1);}
            int mid = l+r>>1;Prp(k<<1,l,mid),Prp(k<<1|1,mid+1,r),Q[k] = Flt(Prd(Q[k<<1],Q[k<<1|1]));
        }
        poly Sol(int k,int l,int r){
            if(l == r){poly ret;return ret.pb(1ll*Pt[l].second*inv(Y[l])%mod),ret;}
            int mid = l+r>>1;return Flt(Pls(Prd(Sol(k<<1,l,mid),Q[k<<1|1]),Prd(Q[k<<1],Sol(k<<1|1,mid+1,r))));
        }
        poly Itp(std::vector<pii> pts){
            n = pts.size();
            for(int i=0;i<n;++i)Pt[i] = pts[i];
            poly G = (Prp(1,0,n-1),Q[1]),dG = Der(G);
            std::vector<int> ps;
            for(int i=0;i<n;++i)ps.push_back(Pt[i].first);
            std::vector<int> vl = EVA.Eva(dG,ps);
            for(int i=0;i<n;++i)Y[i] = vl[i];
            return Sol(1,0,n-1);
        }
    }ITP; 
    poly Comp(poly F,poly G){

        static ull tmp[maxn];
        static poly tb1[1<<mdig/2],tb2[1<<mdig/2];
        int n = F.size(),L = (int)sqrt(n),blcnt = (n-1)/L+1;
        tb1[0] = tb2[0] = Pre(Val(1),n);
        for(int i=1;i<=L;++i)tb1[i] = Prd(tb1[i-1],G,n);
        for(int i=1;i<blcnt;++i)tb2[i] = Prd(tb2[i-1],tb1[L],n);
        poly ret;
        for(int i=0;i<blcnt;++i){
            memset(tmp,0,8*n);
            for(int j=0;j<L&&i*L+j<n;++j){
                for(int k=0,v=F[i*L+j];k<n;++k)
                    tmp[k] += 1ll*tb1[j][k]*v;
                if(j%17==16)for(int k=0;k<n;++k)tmp[k]%=mod;
            }
            std :: vector <int> TMP;
            for(int j=0;j<n;++j)TMP.push_back(tmp[j]%mod);
            ret = Pls(ret,Prd(tb2[i],TMP,n));
        }return ret;
    }
    std::vector<int> CZT(poly F,int c,int m){
        static int pwc[maxn],pwic[maxn],C,iC,n,N;
        n = F.size(),N = n+m,C = c,iC = inv(C);
        pwc[0] = pwc[1] = 1;
        for(int i=2;i<=N;++i)pwc[i] = 1ll*pwc[i-1]*C%mod;
        for(int i=2;i<=N;++i)pwc[i] = 1ll*pwc[i-1]*pwc[i]%mod;
        pwic[0] = pwic[1] = 1;
        for(int i=2;i<=N;++i)pwic[i] = 1ll*pwic[i-1]*iC%mod;
        for(int i=2;i<=N;++i)pwic[i] = 1ll*pwic[i-1]*pwic[i]%mod;
        poly A,B;
        for(int i=0;i<n;++i)A.pb(1ll*F[n-1-i]*pwic[n-1-i]%mod);
        for(int i=0;i<n+m;++i)B.pb(pwc[i]);
        poly P = Prd(A,B);std :: vector <int> ret;
        for(int i=0;i<m;++i)ret.pb(1ll*P[n-1+i]*pwic[i]%mod);return ret;
    }
    

    int n,K,q,A[maxn],B[maxn],jc[maxn],iv[maxn],p2[maxn];
    int C(int n,int m){return 1ll*jc[n]*iv[m]%mod*iv[n-m]%mod;}
 


vi adj[250005];

int num_son[250005];

void dfs(int node,int pa){
    int sn=0;
    for(auto u:adj[node]){
        if(u!=pa){
            sn++; dfs(u,node);
        }
    }
    num_son[node]=sn;
}

vi id1(int l,int r){
    int mid=(l+r)/2;
    if(l==r){
        vi A; A.pb(1); A.pb(num_son[l]); return A;
    }
    poly P=Prd(id1(l,mid),id1(mid+1,r)); if(P.size()>n)P.resize(n+1);
    return P;
}

 

int main(){
fastio;
cin>>n;
FOR(i,0,n-1){
    int a,b; cin>>a>>b; adj[a].pb(b); adj[b].pb(a);
}
dfs(1,0);
poly P=id1(1,n);

ll ans=0;
jc[0] = iv[0] = 1;for(int i=1;i<=2*n;++i)jc[i] = 1ll*jc[i-1]*i%mod;

FOR(i,0,n){
    ll sg=1; if(i&1){ sg=-1; }
    ans=(ans+ sg*P[i]*jc[n-i] +mod )%mod;
}

cout<<ans<<"\n";
return 0;}
