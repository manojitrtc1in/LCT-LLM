



#include<bits/stdc++.h>
using namespace std;
function<void(void)> ____ = [](){ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);};
const int MOD = 998244353;


const int FFTN = 1<<19;
#define poly vector<int>
typedef unsigned long long int ull;
int ksm(int a, int b){
    int ret = 1;
    while(b){
        if(b&1) ret = 1ll * ret * a % MOD;
        b >>= 1;
        a = 1ll * a * a % MOD;
    }
    return ret;
}
namespace FFT{
    int w[FFTN+5],W[FFTN+5],R[FFTN+5];
    void FFTinit(){
        W[0]=1;
        W[1]=ksm(3,(MOD-1)/FFTN);
        for(int i = 2; i <= FFTN; i++) W[i]=1ll*W[i-1]*W[1]%MOD;
    }
    int FFTinit(int n){
        int L=1;
        for (;L<=n;L<<=1);
        for(int i = 0; i <= L - 1; i++) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
        return L;
    }
    int A[FFTN+5],B[FFTN+5];
    ull p[FFTN+5];
    void DFT(int *a,int n){
        for(int i = 0; i < n; i++) p[R[i]]=a[i];
        for(int d = 1; d < n; d <<= 1){
            int len=FFTN/(d<<1);
            for(int i = 0, j = 0; i < d; i++, j += len) w[i]=W[j];
            for(int i = 0; i < n; i += (d<<1))	
                for (int j = 0; j < d; j++){
                    int y=p[i+j+d]*w[j]%MOD;
                    p[i+j+d]=p[i+j]+MOD-y;
                    p[i+j]+=y;
                }
            if (d==1<<15)
                for(int i = 0; i < n; i++) p[i]%=MOD;
        }
        for(int i = 0; i < n; i++) a[i]=p[i]%MOD;
    }
    void IDFT(int *a,int n){
        for(int i = 0; i < n; i++) p[R[i]]=a[i];
        for (int d=1;d<n;d<<=1){
            int len=FFTN/(d<<1);
            for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
            for (int i=0;i<n;i+=(d<<1))	
                for (int j=0;j<d;j++){
                    int y=p[i+j+d]*w[j]%MOD;
                    p[i+j+d]=p[i+j]+MOD-y;
                    p[i+j]+=y;
                }
            if (d==1<<15)
                for(int i = 0; i < n; i++) p[i]%=MOD;
        }
        int val=ksm(n,MOD-2);
        for(int i = 0; i < n; i++) a[i]=p[i]*val%MOD;
    }
    poly Norm(poly a){
        for (;a.size()&&!a.back();a.pop_back());
        return a;
    }
    poly Plus(const poly &a,const poly &b){
        int sza=a.size()-1,szb=b.size()-1;
        poly ans(max(sza,szb)+1);
        for(int i = 0; i <= sza; i++) ans[i]=a[i];
        for(int i = 0; i <= szb; i++) ans[i]=(ans[i]+b[i])%MOD;
        return ans;
    }
    poly Minus(const poly &a,const poly &b){
        int sza=a.size()-1,szb=b.size()-1;
        poly ans(max(sza,szb)+1);
        for(int i = 0; i <= sza; i++) ans[i]=a[i];
        for(int i = 0; i <= szb; i++) ans[i]=(ans[i]+MOD-b[i])%MOD;
        return ans;
    }
    poly Mul(const poly &a,const poly &b){
        int sza=a.size()-1,szb=b.size()-1;
        poly ans(sza+szb+1);
        if (sza<=30||szb<=30){
            for(int i = 0; i <= sza; i++) for(int j = 0; j <= szb; j++)
                ans[i+j]=(ans[i+j]+1ll*a[i]*b[j])%MOD;
            return ans; 
        }
        int L=FFTinit(sza+szb);
        for(int i = 0; i < L; i++) A[i]=(i<=sza?a[i]:0);
        for(int i = 0; i < L; i++) B[i]=(i<=szb?b[i]:0);
        DFT(A,L); DFT(B,L);
        for(int i = 0; i < L; i++) A[i]=1ll*A[i]*B[i]%MOD;
        IDFT(A,L);
        for(int i = 0; i <= sza + szb; i++) ans[i]=A[i];
        return ans; 
    }
    void Getinv(int *a,int *b,int n){
        if (n==1){
            

            b[0]=ksm(a[0],MOD-2);
            return;
        }
        int nn=(n+1)/2;
        Getinv(a,b,nn);
        int L=FFTinit(2*n);
        for(int i = 0; i < L; i++) A[i]=(i<n?a[i]:0);
        for(int i = 0; i < L; i++) B[i]=(i<nn?b[i]:0);
        DFT(A,L); DFT(B,L);
        for(int i = 0; i < L; i++) A[i]=1ll*B[i]*(2+MOD-1ll*A[i]*B[i]%MOD)%MOD;
        IDFT(A,L);
        for(int i = 0; i < n; i++) b[i]=A[i]; 
    }
    poly getinv(poly a,int n){
        int *b=new int[n];
        int *c=new int[n];
        int sz=a.size();
        for(int i = 0; i < n; i++) b[i]=(i<sz?a[i]:0);
        for(int i = 0; i < n; i++) c[i]=0;
        vector<int> ans(n);
        Getinv(b,c,n);
        for(int i = 0; i < n; i++) ans[i]=c[i];
        delete[] b;
        delete[] c;
        return ans;
    }
    poly divide(poly a,poly b){
        int sza=a.size(),szb=b.size();
        if (sza<szb) return poly(0);
        poly b0=b,a0=a;
        reverse(b0.begin(),b0.end());
        reverse(a0.begin(),a0.end());
        b0=Mul(getinv(b0,sza-szb+1),a0);
        b0.resize(sza-szb+1);
        reverse(b0.begin(),b0.end());
        return b0;
    }
    poly modulo(poly a,poly b){
        poly ans=Minus(a,Mul(divide(a,b),b));
        ans.resize(b.size()-1);
        return ans;
    }
    int Cipolla(int x){
        

        int a=1;
        for (;;++a)
            if (ksm((1ll*a*a+MOD-x)%MOD,(MOD-1)/2)==MOD-1)
                break;
        

        int w=(1ll*a*a+MOD-x)%MOD,T=(MOD+1)/2;
        pair<int,int> v1(1,0),v2(a,1);
        for (;T;){
            if (T&1){
                int val1=(1ll*v1.first*v2.first+1ll*w*v1.second%MOD*v2.second)%MOD;
                int val2=(1ll*v1.first*v2.second+1ll*v1.second*v2.first)%MOD;
                v1=pair<int,int>(val1,val2);
            } 
            if (T/=2){
                int val1=(1ll*v2.first*v2.first+1ll*w*v2.second%MOD*v2.second)%MOD;
                int val2=(1ll*v2.first*v2.second+1ll*v2.second*v2.first)%MOD;
                v2=pair<int,int>(val1,val2);
            } 
        }
        

        return v1.first;
    }
    void Getsqrt(int *a,int *b,int n){
        if (n==1){
            

            b[0]=Cipolla(a[0]);
            if (b[0]>MOD-b[0]) b[0]=MOD-b[0];
            return;
        }
        int nn=(n+1)/2;
        Getsqrt(a,b,nn);
        int *c=new int[n];
        for(int i = 0; i < n; i++) c[i]=0;
        Getinv(b,c,n);
        int L=FFTinit(2*n);
        for(int i = 0; i < L; i++) A[i]=(i<n?a[i]:0);
        for(int i = 0; i < L; i++) B[i]=(i<n?c[i]:0);
        DFT(A,L); DFT(B,L);
        for(int i = 0; i < L; i++) A[i]=1ll*A[i]*B[i]%MOD;
        IDFT(A,L);
        for(int i = 0; i < n; i++) b[i]=1ll*(b[i]+A[i])*(MOD+1)/2%MOD;
        delete[] c;
    }
    poly getsqrt(poly a,int n){
        int *b=new int[n];
        int *c=new int[n];
        int sz=a.size();
        for(int i = 0; i < n; i++) b[i]=(i<sz?a[i]:0);
        for(int i = 0; i < n; i++) c[i]=0;
        vector<int> ans(n);
        Getsqrt(b,c,n);
        for(int i = 0; i < n; i++) ans[i]=c[i];
        delete[] b;
        delete[] c;
        return ans;
    }
    
    poly Int(poly a){
        int sza=a.size()-1;
        poly ans(sza+2); ans[0]=0;
        for(int i = 1; i <= sza+1; i++) ans[i]=1ll*a[i-1]*ksm(i,MOD-2)%MOD;
        return ans;
    }
    poly Prime(poly a){
        int sza=a.size()-1;
        poly ans(sza);
        for(int i = 1; i <= sza; i++) ans[i-1]=1ll*a[i]*i%MOD;
        return ans;
    }
    poly getLn(poly a,int n){
        assert(a[0]==1);
        if (a.size()>n) a.resize(n);
        poly res=Int(Mul(Prime(a),getinv(a,n)));
        res.resize(n);
        return res;
    }
    
    void Getexp(ull *a,ull *b,int l,int r){
        if (r-l+1<=64){
            for(int i = l; i <= r; i++) b[i]%=MOD;
            for(int i = l; i <= r; i++){
                if (i==0) b[i]=1;
                else b[i]=b[i]%MOD*ksm(i,MOD-2)%MOD;
                for(int j = 1; j <= r - i; j++) b[i+j]+=b[i]*a[j]; 
                if ((i&15)==15) for(int j = i; j <= r; j++) b[j]%=MOD;
            }
            return;
        }
        int len=(r-l+1)/16;
        ull *c[16],*d[16];
        int L=FFTinit(2*len-1);
        int *arr=new int[L];
        for(int i = 0; i <= 15; i++){
            d[i]=new ull[L];
            for(int j = 0; j < L; j++) d[i][j]=0;
        }
        for(int i = 0; i <= 14; i++){
            c[i]=new ull[L];
            for(int j = 0; j < L; j++) arr[j]=a[i*len+j];
            DFT(arr,L);
            for(int j = 0; j < L; j++) c[i][j]=arr[j];
        }
        for(int i = 0; i <= 15; i++){
            if (i!=0){
                for(int j = 0; j < L; j++) arr[j]=d[i][j]%MOD;
                IDFT(arr,L);
                for(int j = 0; j < len; j++) b[l+i*len+j]+=arr[len+j];
            }
            Getexp(a,b,l+i*len,l+i*len+len-1);
            if (i!=15){
                L=FFTinit(2*len-1);
                for(int j = 0; j < L; j++) arr[j]=(j<len?b[l+i*len+j]:0);
                DFT(arr,L);
                for(int j = 0; j <= 14 - i; j++) for(int k = 0; k < L; k++)
                    d[i+j+1][k]+=arr[k]*c[j][k];
            }
        }
        delete[] arr;
        for(int i = 0; i <= 14; i++) delete[] c[i];
        for(int i = 0; i <= 15; i++)	delete[] d[i];
    }
    poly getexp(poly a,int n){
        int m=1,sza=a.size();
        for (;m<=n;m<<=1);
        ull *b=new ull[m],*c=new ull[m];
        for(int i = 0; i < m; i++) b[i]=(i<sza?1ll*i*a[i]%MOD:0);
        for(int i = 0; i < m; i++) c[i]=0;
        Getexp(b,c,0,m-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i]=c[i];
        delete[] b;
        delete[] c;
        return ans;
    }
    poly read(){
        int n;
        scanf("%d",&n);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) scanf("%d",&ans[i]);
        return ans; 
    }
    poly read(int n){
        vector<int> ans(n);
        for(int i = 0; i < n; i++) scanf("%d",&ans[i]);
        return ans; 
    }
    void write(const poly &a){
        for (auto i:a) printf("%d ",i);
    }
    void writeln(const poly &a){
        for (auto i:a) printf("%d ",i);
        puts("");
    }
}
using FFT::Minus;
using FFT::Prime;
using FFT::Mul;
using FFT::getinv;
using FFT::getLn;
using FFT::getexp;
using FFT::writeln;


const int MAXN = 2e5+7;
int exc[256], n, m, val[256];
char s[MAXN], t[MAXN];
int ID(char x){ return val[x]; }
void solve(){
    FFT::FFTinit();
    for(int i = 'a'; i <= 'z'; i++) val[i] = i - 'a' + 23;
    random_shuffle(val+'a', val+'z'+1);
    for(int i = 0; i < 26; i++) scanf("%d",&exc[i]), exc[i + 'a'] = exc[i] - 1 + 'a';
    scanf("%s %s",s,t);
    n = strlen(s); m = strlen(t);
    reverse(s,s+n);
    poly Ps, Pt, ret, R;
    for(int i = 0; i < n; i++) Ps.push_back(ID(s[i])*ID(s[i])*ID(exc[s[i]])*ID(exc[s[i]]));
    for(int i = 0; i < m; i++) Pt.push_back(1);
    ret = Mul(Ps,Pt);
    for(int i = 0; i < n; i++) Ps[i] = (-2 * ID(s[i]) * ID(exc[s[i]]) * (ID(s[i]) + ID(exc[s[i]])) % MOD + MOD) % MOD;
    for(int i = 0; i < m; i++) Pt[i] = Pt[i] * ID(t[i]) ;
    R = Mul(Ps,Pt);
    for(int i = 0; i < (int) R.size(); i++) ret[i] = (ret[i] + R[i]) % MOD;

    for(int i = 0; i < n; i++) Ps[i] = ID(s[i]) * ID(s[i]) + ID(exc[s[i]]) * ID(exc[s[i]]) + 4 * ID(s[i]) * ID(exc[s[i]]);
    for(int i = 0; i < m; i++) Pt[i] = Pt[i] * ID(t[i]) ;
    R = Mul(Ps,Pt);
    for(int i = 0; i < (int) R.size(); i++) ret[i] = (ret[i] + R[i]) % MOD;

    for(int i = 0; i < n; i++) Ps[i] = (-2 * (ID(s[i]) + ID(exc[s[i]])) % MOD + MOD) % MOD;
    for(int i = 0; i < m; i++) Pt[i] = Pt[i] * ID(t[i]) ;
    R = Mul(Ps,Pt);
    for(int i = 0; i < (int) R.size(); i++) ret[i] = (ret[i] + R[i]) % MOD;
    for(int i = 0; i < n; i++) Ps[i] = 1;
    for(int i = 0; i < m; i++) Pt[i] = Pt[i] * ID(t[i]) ;
    R = Mul(Ps,Pt);
    for(int i = 0; i < (int) R.size(); i++) ret[i] = (ret[i] + R[i]) % MOD;
    for(int i = n - 1; i < m; i++) cout << (ret[i] ? 0 : 1); cout << endl;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("Local.in","r",stdin);
    freopen("ans.out","w",stdout);
    #endif
    solve();
    return 0;
}