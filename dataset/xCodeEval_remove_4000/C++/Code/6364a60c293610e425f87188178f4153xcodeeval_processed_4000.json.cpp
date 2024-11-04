













































































































using namespace std;

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template <typename T> T ABS(T a) {if(a<0)return -a;else return a;}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T id8(T a,T b,T &x,T &y) {if(a<0){T d=id8(-a,b,x,y);x=-x;return d;}   if(b<0){T d=id8(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=id8(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }

int    Set(int N,int pos){ return N=N | (1<<pos);}
int  Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
template< class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int id3(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}
int id5(char ch){return ch-'0';}
bool id4(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !id4(ch)) return true; return false;}

double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}
































struct Node{
    int cnt;
    int ch[2];

    Node(){
        cnt = 0;
        ch[0] = ch[1] = 0;
    }
};

const int N = MX;

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N];
int rnk[N],height[N];

void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}

int sa[N],data[N],n,p,q;
char str[N];
int len[N];
int IDS[N];
int Tree[4*N];
int pos[N];
Node node[20*N];
int avail;
int ST[N];

int Update(int idx,int l,int r,int p){
    int u = ++avail;

    assert(avail < 20*N);

    node[u] = node[idx];

    node[u].cnt ++;

    if (l == r)     return u;

    if (p <= mid)      node[u].ch[0] = Update( node[u].ch[0],l,mid,p );
    else                    node[u].ch[1] = Update( node[u].ch[1],mid+1,r,p );

    return u;
}

int Query(int idx1,int idx2,int l,int r,int s,int e){
    int sum = node[idx1].cnt - node[idx2].cnt;

    if (l == s && r == e)             return sum;

    if (e <= mid)      return Query(node[idx1].ch[0],node[idx2].ch[0],l,mid,s,e);
    else if (s > mid)       return Query(node[idx1].ch[1],node[idx2].ch[1],mid+1,r,s,e);
    else                    return Query(node[idx1].ch[0],node[idx2].ch[0],l,mid,s,mid) + Query(node[idx1].ch[1],node[idx2].ch[1],mid+1,r,mid+1,e);
}

void Build(int idx,int l,int r,int n){
    if (l == r){
        ST[l] = Update(ST[l-1],1,n,IDS[ sa[l] ]);
        Tree[idx] = height[l];
        return ;
    }

    Build(lft,l,mid,n);
    Build(rgt,mid+1,r,n);

    Tree[idx] = min( Tree[lft],Tree[rgt] );
}

int id2(int idx,int l,int r,int v){
    while(l < r){
        if (Tree[lft] < v)      idx = lft, r = mid;
        else                    idx = rgt, l = mid+1;
    }

    return l-1;
}




int id1(int idx,int l,int r,int s,int e,int v){
    if (s > e)                  return MOD;
    if(l == s && r == e){
        if ( Tree[idx] < v)     return id2(idx,l,r,v);
        else                    return MOD;
    }

    if (e <= mid)               return id1(lft,l,mid,s,e,v);
    else if (s > mid)           return id1(rgt,mid+1,r,s,e,v);
    else{
        int q = id1(lft,l,mid,s,mid,v);

        if (q == MOD)    q = id1(rgt,mid+1,r,mid+1,e,v);

        return q;
    }
}

int id6(int idx,int l,int r,int v){
    while(l < r){
        if (Tree[rgt] < v)      idx = rgt,l = mid+1;
        else                    idx = lft,r = mid;
    }

    return l;
}

int id7(int idx,int l,int r,int s,int e,int v){
    if (l == s && r == e){
        if (Tree[idx] < v)      return id6(idx,l,r,v);
        else                    return -1;
    }

    if (e <= mid)               return id7(lft,l,mid,s,e,v);
    else if (s > mid)           return id7(rgt,mid+1,r,s,e,v);
    else{
        int q = id7(rgt,mid+1,r,mid+1,e,v);

        if (q == -1)    q = id7(lft,l,mid,s,mid,v);

        return q;
    }
}

void id0(int m){
    n = 0;

    for (int i=1;i<=m;i++){
        S("%s",str);    pos[i] = n;

        for (int j=0;str[j];j++,len[i]++){
            data[n] = str[j];
            IDS[n++] = i;
        }

        data[n] = (int)'
        IDS[n++] = i;
    }

    DA(data,sa,n+1,128);
    calheight(data,sa,n);
    Build(1,1,n,m);

    

}

void Debug(){
    for (int i=0;i<n;i++)   cout << (char)data[i] ; NL;

    for (int i=1;i<=n;i++){
        P("%3d=%3d%3d%3d: ",i,sa[i],IDS[ sa[i] ],height[i]);

        for (int j=sa[i];j<n;j++)   cout << (char)data[j]; NL;
    }
}

int main(){
    DII(m,q);

    id0(m);
    

    

    

    

    

    rep(i,1,q){
        DIII(l,r,k);

        int id = rnk[pos[k]];

        int lId = id7(1,1,n,1,id,len[k]);      

        int rId = id1(1,1,n,id+1,n,len[k]);    


        if (lId == -1)      lId = 1;
        if (rId == MOD)      rId = n;


        int ans = Query(ST[rId],ST[lId-1],1,m,l,r);

        P("%d\n",ans);


    }
return 0;
}