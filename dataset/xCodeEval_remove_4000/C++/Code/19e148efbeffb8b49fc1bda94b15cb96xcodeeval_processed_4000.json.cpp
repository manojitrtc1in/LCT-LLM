


















typedef long long LL;
typedef unsigned long long uLL;





namespace fastIO{
    
    
    
    

    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            

        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    

    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    

    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        
            scanf("%I64d",&x);
        
        
            scanf("%lld",&x);
        
            puts("error:can't recognize the system!");
        
        
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    

    

    struct id0{
        char *buf,*p1,*pend;
        id0(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];++i) out('0'); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~id0(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    

    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        
            printf("%I64d",x);
        
        
            printf("%lld",x);
        
            puts("error:can't recognize the system!");
        
        
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    
    
    
};
using namespace fastIO;

int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

LL readl() {
    LL s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

















const int MOD = 998244353;
const int maxn = 40;

std::map<int, std::vector<int>> mp1, mp2;
LL ap[maxn][maxn];
int ans[maxn];
int k, A, h;

int sum(int a, int b) {
    a += b;
    if (a > MOD) a -= MOD;
    if (a < 0) a += MOD;
    return a;
}

bool dfs1(const std::vector<int> &vec, int val, int rk) {
    if (rk == 1) {
        val = sum(val, ap[vec.front()][rk]);
        if (val == h) {
            ans[vec.front()] = rk;
            for (int i = 1 ; i <= (1 << k) ; i++ ) {
                printf("%d%c", ans[i], " \n" [i == (1 << k)]);
            }
            return true;
        }
        return false;
    }
    int lens = vec.size();
    lens >>= 1;
    for (int s = 0 ; s < (1 << lens) ; s++ ) {
        int tmp = 0;
        std::vector<int> v;
        for (int i = 0 ; i < lens ; i++ ) {
            if (s & (1 << i)) {
                tmp = sum(tmp, ap[vec[i * 2]][rk]);
                ans[vec[i * 2]] = rk;
                v.eb(vec[i * 2 + 1]);
            } else {
                tmp = sum(tmp, ap[vec[i * 2 + 1]][rk]);
                ans[vec[i * 2 + 1]] = rk;
                v.eb(vec[i * 2]);
            }
        }
        if (dfs1(v, sum(val, tmp), rk == 2 ? 1 : rk / 2 + 1)) return true;
    }
    return false;
}

void dfs2(const std::vector<int> &vec, int val, int rk, std::map<int, std::vector<int>> &mp, std::vector<int> &arr) {
    if (rk == 2) {
        assert(arr.size() == 15);
        assert(vec.size() == 1);
        val = sum(val, ap[vec.front()][rk]);
        arr.eb(vec.front());
        mp[val] = arr;
        arr.pop_back();
        return ;
    }
    int lens = vec.size();
    lens >>= 1;
    for (int s = 0 ; s < (1 << lens) ; s++ ) {
        int tmp = 0;
        std::vector<int> v;
        for (int i = 0 ; i < lens ; i++ ) {
            if (s & (1 << i)) {
                tmp = sum(tmp, ap[vec[i * 2]][rk]);
                arr.eb(vec[i * 2]);
                v.eb(vec[i * 2 + 1]);
            } else {
                tmp = sum(tmp, ap[vec[i * 2 + 1]][rk]);
                arr.eb(vec[i * 2 + 1]);
                v.eb(vec[i * 2]);
            }
        }
        dfs2(v, sum(val, tmp), rk / 2 + 1, mp, arr);
        for (int i = 0 ; i < lens ; i++ ) {
            arr.pop_back();
        }
    }
    return ;
}

bool dfs3(const std::vector<int> &vec, int val, int rk, const std::map<int, std::vector<int>> &mp, std::vector<int> &arr) {
    if (rk == 2) {
        val = sum(val, ap[vec.front()][1]);
        int ref = sum(h, -val);
        if (!mp.count(ref)) return false;
        auto &v = mp.find(ref)->sec;
        for (int i = 0 ; i < 8 ; i++ ) {
            ans[arr[i]] = 17;
            ans[v[i]] = 17;
        }
        for (int i = 8 ; i < 12 ; i++ ) {
            ans[arr[i]] = 9;
            ans[v[i]] = 9;
        }
        for (int i = 12 ; i < 14 ; i++ ) {
            ans[arr[i]] = 5;
            ans[v[i]] = 5;
        }
        ans[arr[14]] = 3;
        ans[v[14]] = 3;
        ans[vec.front()] = 1;
        ans[v[15]] = 2;
        for (int i = 1 ; i <= 32 ; i++ ) {
            printf("%d%c", ans[i], " \n" [i == 32]);
        }
        return true;
    }
    int lens = vec.size();
    lens >>= 1;
    for (int s = 0 ; s < (1 << lens) ; s++ ) {
        int tmp = 0;
        std::vector<int> v;
        for (int i = 0 ; i < lens ; i++ ) {
            if (s & (1 << i)) {
                tmp = sum(tmp, ap[vec[i * 2]][rk]);
                arr.eb(vec[i * 2]);
                v.eb(vec[i * 2 + 1]);
            } else {
                tmp = sum(tmp, ap[vec[i * 2 + 1]][rk]);
                arr.eb(vec[i * 2 + 1]);
                v.eb(vec[i * 2]);
            }
        }
        if (dfs3(v, sum(val, tmp), rk / 2 + 1, mp, arr)) return true;
        for (int i = 0 ; i < lens ; i++ ) {
            arr.pop_back();
        }
    }
    return false;
}

void solve1() {
    std::vector<int> vec;
    for (int i = 1 ; i <= (1 << k) ; i++ ) {
        vec.eb(i);
    }
    int lens = vec.size();
    if (!dfs1(vec, 0, lens / 2 + 1)) {
        printf("-1\n");
    }
    return ;
}

void solve2() {
    std::vector<int> vec, arr;
    for (int i = 1 ; i <= 16 ; i++ ) {
        vec.eb(i);
    }
    

    dfs2(vec, 0, 17, mp1, arr);
    

    vec.clear();
    for (int i = 17 ; i <= 32 ; i++ ) {
        vec.eb(i);
    }
    dfs2(vec, 0, 17, mp2, arr);
    assert(arr.size() == 0);
    

    if (dfs3(vec, 0, 17, mp1, arr)) return ;
    vec.clear();
    for (int i = 1 ; i <= 16 ; i++ ) {
        vec.eb(i);
    }
    if (dfs3(vec, 0, 17, mp2, arr)) return ;
    printf("-1\n");
    return ;
}

int main() {
    k = read();
    A = read();
    h = read();
    for (int i = 1 ; i <= (1 << k) ; i++ ) {
        ap[i][0] = i;
        for (int j = 1 ; j <= (1 << k) ; j++ ) {
            ap[i][j] = ap[i][j - 1] * A % MOD;
        }
    }
    if (k <= 4) {
        solve1();
        return 0;
    }
    solve2();
    return 0;
}
