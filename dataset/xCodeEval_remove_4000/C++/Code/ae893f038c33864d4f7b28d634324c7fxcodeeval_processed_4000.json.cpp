
using namespace std;







typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;










inline char nx(){char c;while((c=gc)==10||32==c);return c;}
inline bool gi(int &a){
    char c;
    bool lwr(0);
    while((c=gc)&&(c<48||c>57)&&c!=45&&~c);
    if(!c||!~c)return 0;
    if(c==45)a=0,lwr=1;
    else a=c-48;
    while((c=gc)&&c>=48&&c<=57)a*=10,a+=c-48;
    if(lwr)a=-a;
    return 1;
}
inline void pn(int k){
    if(!k){putchar(48);return;}
    int l(0),i(0),j(0);
    while(k)l*=10,l+=k%10,k/=10,++i;
    while(j++<i)pc(48+l%10),l/=10;
}


void ga(int N,int *A){F(N)gi(A[i]);}

ll H[1<<24],W;
int Z[1<<24],V,D[MX];
struct sS1{
    ll *p,*P;
    int N;
    void ini(int n){
        N=1<<(int(log2(n)-ZERO)+1),p=H+W,W+=N*2,P=H+W,W+=N*2;
    }
    void INI(int n,int*D){
        FT(N,N+n)P[k]=p[k]=D[k-N];
        for(int i=N-1;~i;--i)p[i]=p[i<<1]+p[i<<1|1];
    }
    void st(int b,int e,ll v=1){st(b,e,v,1,0,N-1);}
    void st(int b,int e,ll v,int u,int B,int E){
        if(B>e||E<b)return;
        if(b<=B&&e>=E){P[u]+=v,p[u]+=(E-B+1)*v;return;}
        st(b,e,v,u<<1,B,(B+E)>>1),st(b,e,v,u<<1|1,(B+E)/2+1,E);
        p[u]=p[u<<1|1]+p[u<<1]+P[u]*(E-B+1);
    }
    ll gt(int b,int e){return gt(b,e,1,0,N-1);}
    ll gt(int b,int e,int u,int B,int E){
        if(B>e||E<b)return 0;
        if(b<=B&&e>=E)return p[u];
        return gt(b,e,u<<1,B,(B+E)>>1)+gt(b,e,u<<1|1,(B+E)/2+1,E)+(min(e,E)-max(b,B)+1)*P[u];
    }
}T;
struct sS{
    int *p,*P;
    int N;
    void ini(int n){
        N=1<<(int(log2(n)-ZERO)+1),p=Z+V,V+=N*2,P=Z+V,V+=N*2;
    }
    void st(int b,int e,int v=1){st(b,e,v,1,0,N-1);}
    void st(int b,int e,int v,int u,int B,int E){
        if(B>e||E<b)return;
        if(b<=B&&e>=E){P[u]+=v,p[u]+=(E-B+1)*v;return;}
        st(b,e,v,u<<1,B,(B+E)>>1),st(b,e,v,u<<1|1,(B+E)/2+1,E);
        p[u]=p[u<<1|1]+p[u<<1]+P[u]*(E-B+1);
    }
    int gt(int b,int e){return gt(b,e,1,0,N-1);}
    int gt(int b,int e,int u,int B,int E){
        if(B>e||E<b)return 0;
        if(b<=B&&e>=E)return p[u];
        return gt(b,e,u<<1,B,(B+E)>>1)+gt(b,e,u<<1|1,(B+E)/2+1,E)+(min(e,E)-max(b,B)+1)*P[u];
    }
}L,R,l,r;
struct sX{
    int *p,*P;
    int N;
    void ini(int n){
        N=1<<(int(log2(n)-ZERO)+1),p=Z+V,V+=N*2,P=Z+V,V+=N*2;
    }
    int gt(int u){return P[u]+p[u];}
    void st(int b,int e,int v){st(b,e,v,1,0,N-1);}
    void st(int b,int e,int v,int u,int B,int E){
        if(B>e||E<b)return;
        if(b<=B&&e>=E){P[u]+=v;return;}
        st(b,e,v,u<<1,B,(B+E)>>1),st(b,e,v,u<<1|1,(B+E)/2+1,E);
        p[u]=max(gt(u<<1),gt(u<<1|1));
    }
    int gt(int b,int e){return gt(b,e,1,0,N-1);}
    int gt(int b,int e,int u,int B,int E){
        if(B>e||E<b)return -1e9;
        if(b<=B&&e>=E)return gt(u);
        return max(gt(b,e,u<<1,B,(B+E)>>1),gt(b,e,u<<1|1,(B+E)/2+1,E))+P[u];
    }

}X;

int N,b,e,d;
void lge(int I){
    int J=I+1,LL=L.gt(I,I),rr=r.gt(J,J);
    r.st(I-LL,I,-rr-1),X.st(I-LL,I,-rr-1);
    L.st(J,J+rr,-LL-1);
}
void LGE(int I){
    int J=I+1,LL=L.gt(I,I),rr=r.gt(J,J);
    r.st(I-LL,I,rr+1),X.st(I-LL,I,rr+1);
    L.st(J,J+rr,LL+1);
}
void rge(int I){
    int J=I+1,RR=R.gt(J,J),l1=l.gt(I,I);
    R.st(I-l1,I,-RR-1);
    l.st(J,J+RR,-l1-1),X.st(J,J+RR,-l1-1);
}
void RGE(int I){
    int J=I+1,RR=R.gt(J,J),l1=l.gt(I,I);
    R.st(I-l1,I,RR+1);
    l.st(J,J+RR,l1+1),X.st(J,J+RR,l1+1);
}
void id1(int I){
    int J=I+1,LL=L.gt(I,I);
    r.st(I-LL,I,1),X.st(I-LL,I,1);
    L.st(J,J,LL+1);
}
void id0(int I){
    int J=I+1,l1=l.gt(I,I);
    R.st(I-l1,I,1);
    l.st(J,J,l1+1),X.st(J,J,l1+1);
}
int sd(ll a,ll b){return a<b?-1:a^b?1:0;}
void cs(int r,int d,bool x){
    if(!r||r==N)return;
    ll a=T.gt(r-1,r-1),b=T.gt(r,r);
    int c=sd(a,b),e;
    if(x)e=sd(a,b+d);
    else e=sd(a+d,b);
    if(c^e){
        if(!~c)rge(r-1);
        else if(c)lge(r-1);
        if(!~e)RGE(r-1);
        else if(e)LGE(r-1);
    }
}
void qr(int b,int e,int d){
    cs(b,d,1),cs(e+1,d,0);
    T.st(b,e,d);
}
void cns(){
    F(N-1)if(D[i]<D[i+1])id0(i);
          else if(D[i]>D[i+1])id1(i);
    T.INI(N,D);
}

int main(void){
    gi(N),INI(N),ga(N,D),cns();
    IN(Q)F(Q)gi(b),gi(e),gi(d),qr(b-1,e-1,d),pn(X.gt(1)+1),pe;
    return 0;
}
                                                                 
