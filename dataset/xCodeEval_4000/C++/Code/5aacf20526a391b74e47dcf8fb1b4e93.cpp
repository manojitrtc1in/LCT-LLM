



































































































































































































































































































































































































































































































































































































































































#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5+5;



struct ar;
int getsz(ar*);
int getval(ar*);

struct ar{
    ar *l, *r;
    int sz, val;
    ar(){}
    ar(int x){
        l = r = 0;
        sz = 1;
        val = x;
    }
    ar(ar *L, ar *R){
        l = L;
        r = R;
        sz = getsz(l) + getsz(r);
        val = min(getval(l),getval(r));
    }
};

char buff[111000111];
auto bptr = buff;
void* operator new(size_t n) {
    bptr += n;
    return bptr - n;
}
void operator delete(void*) {}

int getsz(ar *s){
    if(!s) return 0;
    return s->sz;
}
int inf = 2e9;
int getval(ar *s){
    if(!s) return inf;
    return s->val;
}

ar *change(ar *s, int i, int val){
    if(getsz(s)==1) return new ar(val);
    if(i < getsz(s->l)) return new ar(change(s->l,i,val), s->r);
    return new ar(s->l, change(s->r, i-getsz(s->l),val));
}

int rmq(ar *s, int i){
    if(getsz(s)-1==i) return s->val;
    if(i < getsz(s->l)) return rmq(s->l, i);
    return min(getval(s->l), rmq(s->r, i-getsz(s->l)));
}


ar *create(int n){
    if(n==1) return new ar(inf);
    int m = n/2;
    return new ar(create(m), create(n-m));
}

int a[N];
vector<int> g[N];

int h[N];
void goh(int v, int p = -1){
    h[v] = 1;
    for(int i : g[v]) if(i!=p){
        goh(i, v);
        h[v] = max(h[v], h[i] + 1);
    }
}

ar *t[N];
vector<int> tt[N];
int memhh[N];
void go(int v, int sz = -1, int hh = 0, int p = -1){
    int u = -1;
    for(int i : g[v]) if(i!=p){
        if(u==-1 || h[u]<h[i]) u = i;
    }
    
    if(sz==-1){
        sz = h[v];
    }else{
        
    }
    
    memhh[v] = hh;
    if(u==-1){
        tt[v].assign(sz, inf);
        tt[v][hh] = a[v];
        
        t[v] = create(sz);
        t[v] = change(t[v], hh, a[v]);
        
        return ;
    }
    
    go(u, sz, hh+1, v);
    
    vector<int> &res = tt[u];
    res[hh] = a[v];
    
    t[v] = t[u];
    t[v] = change(t[v], hh, a[v]);
    
    for(int i : g[v]) if(i!=p && i!=u){
        go(i, -1, 0, v);
        for(int k=0;k<tt[i].size();++k){
            if(res[k+hh+1]>tt[i][k]){
                res[k+hh+1] = tt[i][k];
                t[v] = change(t[v], k+hh+1, tt[i][k]);
            }
        }
    }
    
    

    tt[v].swap(res);
    
}
const int __BS = 4096;
static char __bur[__BS + 16], *__er = __bur + __BS, *__ir = __er;
template<class T = int> T readInt() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    c(); while (*__ir && (*__ir < '0' || *__ir > '9') && *__ir != '-') ++__ir; c();
    bool m = false; if (*__ir == '-') ++__ir, c(), m = true;
    T r = 0; while (*__ir >= '0' && *__ir <= '9') r = r * 10 + *__ir - '0', ++__ir, c();
    ++__ir; return m ? -r : r;
}
static char __buw[__BS + 20], *__iw = __buw, *__ew = __buw + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw;
    *__iw++ = endc;
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw; }
}
struct __FL__ { ~__FL__() { if (__iw != __buw) cout.write(__buw, __iw - __buw); } };
static __FL__ __flushVar__;

int main(){
    

    ios::sync_with_stdio(0);cin.tie(0);

    
    int n, r;
    n = readInt();
    r = readInt();
    --r;
    for(int i=0;i<n;++i) a[i] = readInt();
    for(int k=0;k<n-1;++k){
        int i,j;
        i = readInt();
        j = readInt();
        --i;--j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    goh(r);
    go(r);
    
    
    int m;
    m = readInt();
    int LAST = 0;
    while(m--){
        int P,Q;
        P = readInt();
        Q = readInt();
        int x = (P+LAST)%n;
        int y = (Q+LAST)%n;
        if(y>h[x]-1) y = h[x]-1;
        int res = rmq(t[x], memhh[x]+y);
        writeInt(res);
        LAST = res;
    }
    
    return 0;
}
