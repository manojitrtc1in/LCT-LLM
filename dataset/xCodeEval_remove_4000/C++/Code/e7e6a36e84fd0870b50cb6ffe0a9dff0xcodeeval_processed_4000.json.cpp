

















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




const int maxn = 1e5 + 10;

int n, a, b, c;
char str[maxn];

LL solve(const std::vector<int> &vin, const std::vector<int> &vout, int cnt) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> que2;
    std::vector<int> vec(vout);
    int lef1 = 0;
    for (const auto &val : vin) {
        if (val == 1) ++lef1;
        else que2.em(val);
    }
    LL ret = 0, tmp = 0;
    int tur = 0;
    while (true) {
        if (tur == 0) {
            if (!que2.empty()) {
                if (cnt) {
                    int val = que2.top();
                    que2.pop();
                    tmp += a;
                    ret = std::max(ret, tmp);
                    --val;
                    if (val == 1) ++lef1;
                    else que2.em(val);
                } else {
                    ret = std::max(ret, tmp + a);
                    if (lef1) {
                        --lef1;
                        ++cnt;
                        tmp -= c;
                        ret = std::max(ret, tmp);
                    } else break;
                }
            } else {
                if (cnt) {
                    if (vec.size() && std::max(vec.front(), vec.back()) >= 2) {
                        tmp += a;
                        if (vec.front() >= 2) {
                            vec.front() -= 1;
                        } else vec.back() -= 1;
                        ret = std::max(ret, tmp);
                    } else {
                        if (lef1) {
                            --lef1;
                            ++cnt;
                            tmp -= c;
                            ret = std::max(ret, tmp);
                        } else if (vec.size() && (vec.front() || vec.back())) {
                            if (vec.front()) {
                                vec.front() -= 1;
                                tmp -= c;
                                ret = std::max(ret, tmp);
                            } else {
                                vec.back() -= 1;
                                tmp -= c;
                                ret = std::max(ret, tmp);
                            }
                        } else break;
                    }
                } else {
                    if (!lef1) {
                        if (vec.size() && std::max(vec.front(), vec.back()) >= 2) {
                            tmp += a;
                            ret = std::max(ret, tmp);
                        }
                        break;
                    } else {
                        if (vec.size() && std::max(vec.front(), vec.back()) >= 2) {
                            ret = std::max(ret, tmp + a);
                        }
                        tmp -= c;
                        --lef1;
                        ++cnt;
                        ret = std::max(ret, tmp);
                    }
                }
            }
        } else {
            if (!cnt) break;
            --cnt;
            tmp += b;
            ret = std::max(ret, tmp);
        }
        

        tur ^= 1;
    }
    return ret;
}

int main() {
    int T = read();
    std::vector<LL> vec;
    for (int __t = 1 ; __t <= T ; ++__t) {
        n = read();
        a = read();
        b = read();
        c = read();
        scanf("%s", str + 1);
        

        

        

        

        

        if (n == 1) {
            

            vec.eb(0);
            continue;
        }
        if (std::count(str + 1, str + 1 + n, '1') == n) {
            

            vec.eb(b);
            continue;
        }
        if (std::count(str + 1, str + 1 + n, '0') == n) {
            

            vec.eb(a);
            continue;
        }
        int cnt = 0;
        std::vector<std::pair<int, int>> v1;
        std::vector<int> vin, vout;
        for (int i = 1 ; i <= n ; i++ ) {
            if (str[i] != '1') continue;
            int dex = i;
            while (dex + 1 <= n && str[dex + 1] == '1') ++dex;
            cnt += dex - i;
            v1.eb(i, dex);
            i = dex;
        }
        int lens = v1.size();
        for (int i = 0 ; i < lens ; i++ ) {
            if (i == 0 && v1[i].fir != 1) vout.eb(v1[i].fir - 1);
            if (i == lens - 1 && v1[i].sec != n) vout.eb(n - v1[i].sec);
            if (i != 0) {
                vin.eb(v1[i].fir - v1[i - 1].sec - 1);
            }
        }
        LL ans = solve(vin, vout, cnt);
        

        if (cnt != 0) {
            

            ans = std::max(ans, solve(vin, vout, cnt - 1) + b);
        }
        

        

        

        

        

        

        vec.eb(ans);
    }
    for (const auto &val : vec) {
        printf("%lld\n", val);
    }
    return 0;
}



