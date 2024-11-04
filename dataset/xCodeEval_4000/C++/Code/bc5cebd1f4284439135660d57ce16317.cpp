#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <cstring>
#include <bitset>
#include <ctime>
#include <functional>
#include <numeric>

typedef long long LL;
typedef unsigned long long uLL;
#define fir first
#define sec second
#define eb emplace_back
#define em emplace
#define pb pop_back
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    

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
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    

    

    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
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
        ~Ostream_fwrite(){flush();}
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
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
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


















const int maxn = 1e6 + 10;

struct Node {
    int l, r, val;
    Node() = default;
    Node(int l, int r, int val) {
        this->l = l;
        this->r = r;
        this->val = val;
    }
};

char str[maxn];
int n;
int a[maxn];
std::vector<std::pair<int, int>> vec[maxn];
std::vector<Node> q;
std::map<int, std::vector<std::pair<int, int>>> mp;
int vis[maxn];

void init() {
    for (int i = 2 ; i < maxn ; i++ ) {
        if (!vis[i]) {
            vec[i].eb(i, 1);
            for (int j = i * 2 ; j < maxn ; j += i) {
                vis[j] = 1;
                int cnt = 0;
                int tmp = j;
                while (tmp % i == 0) {
                    ++cnt;
                    tmp /= i;
                }
                vec[j].eb(i, cnt);
            }
        }
    }
    return ;
}

namespace SegTree {

#define lch o<<1
#define rch o<<1|1
#define mid (L+R)/2

int mi[maxn << 2], num[maxn << 2];

void init(int o, int L, int R, const std::vector<int> &arr) {
    if (L == R) {
        mi[o] = arr[L];
        return ;
    }
    init(lch, L, mid, arr);
    init(rch, mid + 1, R, arr);
    mi[o] = std::min(mi[lch], mi[rch]);
}

void init2(int o, int L, int R) {
    if (L == R) {
        num[o] = n;
        return ;
    }
    init2(lch, L, mid);
    init2(rch, mid + 1, R);
}

int qmin(int o, int L, int R, int l, int r, int val) {
    if (L == R) {
        if (mi[o] <= val) return L;
        return -1;
    }
    if (l <= L && R <= r) {
        if (mi[o] > val) return -1;
    }
    if (r <= mid) return qmin(lch, L, mid, l, r, val);
    if (l > mid) return qmin(rch, mid + 1, R, l, r, val);
    int ret = qmin(lch, L, mid, l, r, val);
    if (ret != -1) return ret;
    return qmin(rch, mid + 1, R, l, r, val);
}

void pushdown(int o) {
    if (num[o]) {
        num[lch] = num[o];
        num[rch] = num[o];
        num[o] = 0;
    }
}

void update(int o, int L, int R, int l, int r, int val) {
    if (l <= L && R <= r) {
        num[o] = val;
        return ;
    }
    pushdown(o);
    if (l <= mid) update(lch, L, mid, l, r, val);
    if (r > mid) update(rch, mid + 1, R, l, r, val);
    return ;
}

int query(int o, int L, int R, int pos) {
    if (L == R) {
        return num[o];
    }
    pushdown(o);
    if (pos <= mid) return query(lch, L, mid, pos);
    return query(rch, mid + 1, R, pos);
}

#undef lch
#undef rch
#undef mid
};

using namespace SegTree;


int main() {
    init();
    read(n);
    for (int i = 1 ; i <= n ; i++ ) {
        

        read(a[i]);
    }
    

    read(str + 1);
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++ ) {
        int s = 1;
        if (str[i] == '/') s = -1;
        

        for (const auto &kv : vec[a[i]]) {
            mp[kv.fir].eb(i, kv.sec * s);
            ++cnt;
            

        }
        

    }
    

    

    

    

    for (const auto &kv : mp) {
        const std::vector<std::pair<int, int>> &arr = kv.sec;
        int lens = arr.size();
        std::vector<int> vv(lens + 1, 0);
        for (int i = 1 ; i <= lens ; i++ ) {
            vv[i] = arr[i - 1].sec;
        }
        for (int i = 1 ; i <= lens ; i++ ) {
            vv[i] += vv[i - 1];
        }
        std::stack<int> stk;
        for (int i = lens ; i >= 0 ; i-- ) {
            while (!stk.empty() && vv[i] <= vv[stk.top()]) stk.pop();
            if (!stk.empty()) {
                

                int s = i, t = stk.top() - 1;
                

                if (i == 0) q.eb(1, arr[s].fir, arr[t].fir - 1);
                else q.eb(arr[s - 1].fir + 1, arr[s].fir, arr[t].fir - 1);
            }
            stk.em(i);
        }
    }
    std::sort(q.begin(), q.end(), [](const Node &a, const Node &b) {
        return a.val > b.val;
    });
    init2(1, 1, n);
    

    

    

    

    for (const auto &node : q) {
        

        update(1, 1, n, node.l, node.r, node.val);
    }
    LL ans = 0;
    for (int i = 1 ; i <= n ; i++ ) {
        ans += std::max(0, query(1, 1, n, i) - i + 1);
        

    }
    printf("%lld\n", ans);
    return 0;
}

