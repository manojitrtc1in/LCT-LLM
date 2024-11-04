




























using namespace std;




















































































































template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }




















template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> inline T GCD(T a,T b)              { if(a<0)return GCD(-a,b);  if(b<0)return GCD(a,-b);    return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T id3(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a)                         { if(a<0)return -a;else return a;}
LL Bigmod(LL base,LL power,LL _MOD)                      { LL ret=1;while(power){if(power & 1)ret=(ret*base)%_MOD;base=(base*base)%_MOD;power>>=1;}return ret;}
LL ModInverse(LL number,LL _MOD)                         { return Bigmod(number,_MOD-2LL,_MOD); }


template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }










void BINARY(int n){  bitset<31>a=n;  cout << a << endl;}
void id2(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<class T> inline void id0( vector<T> &vec ){ sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); }
template<class T> inline void id1( T *ar,int &n)   { sort(ar + 1, ar + n + 1); n = unique(ar + 1, ar + n + 1) - ar - 1; }






































const int N = MX;
bool flag;

struct SUFFIX_ARRAY
{
    int wa[N],wb[N],ws[N],wv[N],r[N];
    int len;

    int rnk[N];   

    int height[N]; 

    int sa[N];     


    int table[N][21]; 


    int cmp(int *ar,int a,int b,int l) {
        return (ar[a]==ar[b]) && (ar[a+l]==ar[b+l]);
    }

    void DA(int n,int m) {
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
        for(j=1,p=1; p<n; j*=2,m=p) {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) ws[i]=0;
            for(i=0; i<n; i++) ws[wv[i]]++;
            for(i=1; i<m; i++) ws[i]+=ws[i-1];
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)  x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
    }

    void calheight(int n)
    {
        

        

        int i,j,k=0;
        for(i=1; i<=n; i++) rnk[sa[i]]=i;
        for(i=0; i<n; height[rnk[i++]] = k )
            for(k?k--:0,j=sa[rnk[i]-1]; r[i+k]==r[j+k]; k++);
    }

    void generate(char *s) {
        for(len=0; s[len] ; len++) r[len]=(int)s[len];
        r[len]=0;
        DA(len+1,128);
        calheight(len);
    }

    void sparse_table() {
        int n =  len+1;
        for(int i=0; i<n; i++) table[i][0]=height[i];
        for (int j=1; (1 << j) <= n; j++)
            for (int i = 0; i+(1 << j)-1<n; i++)
                table[i][j] = (table[i][j-1] <= table[ i+(1<<(j-1))][j-1] )?table[i][j-1]:table[i+(1<<(j-1))][j-1];
    }

    int find_lcp(int start,int end) {

        if(start==end)
        {
            return (len-sa[start]);
        }

        if(start>end) swap(start,end);
        start++;


        int diff=end-start;
        diff=31 - __builtin_clz(diff+1);
        return table[start][diff]<=table[end-(1<<diff)+1][diff]?table[start][diff]:table[end-(1<<diff)+1][diff];
    }
    

    

    


































    






















    void print() {
        cout << "length :  " << len << endl;
        cout << "s[n] = '$' " << endl;
        cout << "sorted suffix index(0 based) : " << endl;
        rep(i,0,len) cout << sa[i] << " , ";
        cout << endl;
        cout << "rank of suffix " << endl;
        rep(i,0,len) cout << rnk[i] << " , ";
        cout << endl;
        cout << "LCP between i and i-1 " << endl;
        rep(i,0,len) cout << height[i] << " , ";
        cout << endl;
    }

    int rightmost_lcp(int idx,int h) {

        int   ret = idx;
        int   low = idx;
        int  high = len;

        int mid ;

        if(!flag) cout << "FIND : " << idx << " height = " << h << endl;



        while(low<=high) {
            mid = (low+high)>>1;

            if(!flag) {
                cout << low  <<" = " << high << " = len - "<< len << endl;
            }

            int cnt = find_lcp(idx,mid);
            if(h<=cnt) ret = mid , low=mid+1;
            else  high = mid-1;


        }

        return ret;
    }

    int leftmost_lcp(int idx,int h) {
        int   ret = idx;
        int   low = 1;
        int  high = idx;
        int mid ;

        while(low<=high) {
            mid = (low+high)>>1;
            int cnt = find_lcp(mid,idx);
            if(cnt>=h) ret = mid , high  = mid-1;
            else low=mid+1;
        }
        return ret;
    }

}SA;


char ss[MX];
int idx[MX];

char s[MX];

vector<int>id[MX];
vector<int>pos[MX];

int kon[MX];
int lt[MX];
int rt[MX];
int sz[MX];
int tree[MX];

int mx;

void update(int idx,int v) {

    while(idx<=mx) tree[idx]+=v, idx+=(idx & -idx);
}

int read(int idx) {
    int ret = 0;
    while(idx>0) ret += tree[idx] , idx -= (idx & -idx);
    return ret;
}

int ans[MX];


int main()
{
    DII(n,q);

    flag = 1;



    int ptr=0;

    mx = MX-5;

    rep(i,1,n) {
        kon[i] = ptr;
        SS(ss);
        int j=0;
        while(ss[j]) {
            s[ptr]   = ss[j++];
            idx[ptr] = i;
            ptr++;

            sz[i]++;
        }

        s[ptr] = '
        idx[ptr] = mx;

        ptr++;
    }

    s[ptr] = '\0';






    int pp = 0;

    SA.generate(s);
    SA.sparse_table();





    


    rep(i,1,n) {

        int suru = kon[i];
        int pos  = SA.rnk[suru];
















            rt[i] =   SA.rightmost_lcp(pos,sz[i]);







            lt[i] =   SA.leftmost_lcp(pos,sz[i]);
    }


    rep(i,1,q) {

        DIII(x,y,k);







        pos[ rt[k] ].push_back(y);
        pos[ rt[k] ].push_back(x-1);

        pos[ lt[k]-1 ].push_back(y);
        pos[ lt[k]-1 ].push_back(x-1);

        id[ rt[k] ].push_back(i);
        id[ rt[k] ].push_back(-i);

        id[ lt[k]-1 ].push_back(-i);
        id[ lt[k]-1 ].push_back(i);
    }

    rep(i,1,ptr)
    {
        int ke = SA.sa[i];
        ke = idx[ke];



            update(ke,1);








        repv(j,pos[i])
        {
            int idd = id[i][j];
            int v   = pos[i][j];


            if(idd<0)
            {
                idd*=-1;


                    ans[idd]-=read(v);
            }
            else
            {


                    ans[idd]+=read(v);
            }




        }
    }


    rep(i,1,q)
    {
        PI(ans[i]);
    }










    return 0;
}
