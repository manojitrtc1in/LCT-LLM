









using namespace std;




class IO{static const int bufSize=1<<18;char inBuf[bufSize],outBuf[bufSize];char*ip1=inBuf,*ip2=inBuf;int ok=1,op1=-1,op2=bufSize-1;
TP <TN T>FI void __RI(T&x){int ch=gc(),neg=1;x=0;for(;!(ch==EOF||isdigit(ch)||ch=='-');ch=gc());if(ch==EOF){ok=0;return;}if(ch=='-')neg=-1,ch=gc();for(;isdigit(ch);ch=gc())x=x*10+(ch-48)*neg;}
TP <TN T>FI void __RC(T&x){unsigned char ch;while(isspace(ch=gc()));if(ch==EOF){ok=0;return;}x=ch;}FI void __RS(string&x){char ch;x.clear();for(ch=gc();isspace(ch);ch=gc());if(ch==EOF){ok=0;return;}for(;!isspace(ch);ch=gc())x.push_back(ch);}
public:
FI int gc(){return ip1==ip2 &&(ip2 =(ip1=inBuf)+fread(inBuf,1,bufSize,stdin),ip1==ip2)?EOF:*ip1++;}
FI IO&R(char&x){__RC(x);return TS;}FI IO& R(unsigned char&x){__RC(x);return TS;}FI IO&R(string&x){__RS(x);return TS;}TP<TN T1,TN T2>FI IO&R(pair<T1,T2>&x){R(x.first),R(x.second);return TS;}TP<TN T>FI IO&R(vector<T>&x){for(auto &i:x)R(i);return TS;}
TP <TN T,TN...Args>FI IO&RA(T*a,int n){for(int i=0;i<n;++i)R(a[i]);return TS;}TP<TN T,TN...Args>FI IO&R(T&x,Args&...args){R(x),R(args...);return TS;}
TP <TN T,TN...Args>FI IO&RA(T*a,int n,Args...args){for(int i=0;i<n;++i)RA(a[i],args...);return TS;}TP<TN T>FI IO&R(T&x){static_assert(is_integral<T>::value,"Unsupported types");if(is_integral<T>::value)__RI(x);return TS;}
private:
char space=' ';TP<TN T>FI void __WI(T x){static char buf[64];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while(x);}else{pc('-');do{buf[++len]=-(x%10)+48,x/=10;}while(x);}while(len>=0){pc(buf[len]),--len;}}
public:
FI void pc(const char&x){if(op1==op2)flush();outBuf[++op1]=x;}
FI void flush(){fwrite(outBuf,1,op1+1,stdout),op1=-1;}FI IO&W(const char&x){pc(x);return TS;}FI IO&W(const char*x){while(*x!='\0')pc(*(x++));return TS;}FI IO&W(const string&x){W(x.c_str());return TS;}
TP<TN T>FI IO& W(const vector<T>&x){for(auto&i:x)WS(i);WL();return TS;}FI IO&WL(){W('\n');return TS;}TP<TN T1,TN T2>FI IO& W(const pair<T1,T2>&x){WS(x.first),W(x.second);return TS;}
TP<TN T>FI IO& WL(const T&x){W(x),W('\n');return TS;}FI IO&WS(){W(' ');return TS;}TP<TN T>FI IO& WS(const T&x){W(x),W(space);return TS;}
TP<TN T>FI IO& WA(T* a,int n){for(int i=0;i<n;i++)WS(a[i]);WL();return TS;}TP<TN T,TN...Args>FI IO& W(const T&x,const Args&...args){W(x),W(space),W(args...);return TS;}
TP<TN...Args>FI IO& WL(const Args&...args){W(args...),W('\n');return TS;}TP<TN T,TN...Args>FI IO& WA(T* a,int n,Args...args){for(int i=0;i<n;i++)WA(a[i],args...);return TS;}
TP<TN T>FI IO& W(const T&x){static_assert(is_integral<T>::value,"Unsupported types");if(is_integral<T>::value)__WI(x);return TS;}
TP<TN T>FI IO&operator>>(T&x){R(x);return TS;}TP<TN T>FI IO&operator<<(const T&x){W(x);return TS;}bool good(){return ok;}IO(){}~IO(){flush();}}io;






const int32_t INF=0x3f3f3f3f;
const int64_t INFL=0x3f3f3f3f3f3f3f3fLL;

const int MAXN = 500;
int G, S;
struct UF
{
    vector<int> par;
    void init(int n) { par.resize(n), iota(ALL(par), 0); }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void merge(int x, int y) { par[find(x)] = find(y); }
    bool same(int x, int y) { return find(x) == find(y); }
} uf;
struct Edge
{
    int from, to, g, s;
};

int64_t MST(vector<Edge> &edges, int n)
{
    vector<int> del;
    uf.init(n);
    int64_t res = 0x3f3f3f3f3f3f3f3fll, maxG = 0, maxS = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].from, v = edges[i].to;
        if (uf.same(u, v))
            del.push_back(i);
        else
            uf.merge(u, v), maxG = max(int64_t(edges[i].g), maxG),
                            maxS = max(maxS, int64_t(edges[i].s));
    }
    int cnt = 0;
    for (int i = 0; i < n && cnt < 2; i++) { cnt += uf.find(i) == i; }
    if (cnt == 1) { res = maxS * S + maxG * G; }
    vector<Edge> nedges;
    for (int i = 0, j = 0; i < edges.size(); i++)
        if (j >= del.size() || i != del[j]) {
            nedges.push_back(edges[i]);
        } else
            j++;
    edges = nedges;
    return res;
}
int main()
{
    int n, m;
    io.R(n, m, G, S);
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, g, s;
        io.R(u, v, g, s);
        --u, --v;
        edges[i] = Edge({ u, v, g, s });
    }
    sort(ALL(edges), [](const Edge &x, const Edge &y) {
        return x.g != y.g ? x.g < y.g : x.s < y.s;
    });
    int64_t ans = 0x3f3f3f3f3f3f3f3fll;
    vector<Edge> currentEdges;
    auto cmp = [](const Edge &x, const Edge &y) { return x.s < y.s; };
    for (int i = 0; i < m; i++) {
        currentEdges.insert(
            lower_bound(ALL(currentEdges), edges[i], cmp), edges[i]);
        

        ans = min(ans, MST(currentEdges, n));
    }
    if (ans >= 0x3f3f3f3f3f3f3f3f) ans = -1;
    io.WL(ans);
    return 0;
}