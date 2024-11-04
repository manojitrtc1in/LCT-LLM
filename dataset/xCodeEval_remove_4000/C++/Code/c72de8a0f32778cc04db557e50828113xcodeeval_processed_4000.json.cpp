















using namespace std;


















const long long inf=1LL<<62;
const int iinf=1<<30;
const double dinf=1e17;
const int Mod=1e9+7;
typedef long long ll;
typedef long double ld;
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
bool isdigit(char n) {
    if (n >= '0' && n <= '9') return true;
    return false;
}
inline void rnext(){
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}
template <class T>
inline bool in(T &ans){
    ans = 0;
    T f = 1;
    if(ps == pe) return false;

    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;

    do{
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}
const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write(){
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s){
    while(*s){
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x){
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x){
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}
inline ll lowbit(ll x){
    return x&(-x);
}
int dcmp(double x){
    if(fabs(x)<=eps) return 0;
    return x<0?-1:1;
}
int vis[200005],to[200005],vc[200005];
int n,c[200005],v,ret,ans,mk;
void dfs(int now,int ct,int fa){
	if(ct>4*n) return ;
	if(ct>n) ret=min(ret,c[now]);
	if(fa==now) {ret=c[now];return ;}
	if(!vc[to[now]]){
		dfs(to[now],ct+1,now);
	}
}
void dfsk(int now){
	if(vc[now]) return ;
	vc[now]=1;
	dfsk(to[now]);
}
void id0(){
	cin>>n;ans=0;met(vc,0);
	For(i,1,n) scanf("%d",&c[i]);
	For(i,1,n) scanf("%d",&to[i]);
	For(i,1,n) {
		if(!vc[i]) {
			ret=100000;
			dfs(i,0,0);
			if(ret==100000) ret=0;
			dfsk(i);
			ans+=ret;
		}
	}
	cout<<ans<<endl;
}
int id1(){
	int t=1;
	For(i,1,t){
		id0();
	}
	return 0;
}
