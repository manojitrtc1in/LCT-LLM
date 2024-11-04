#include <iomanip>
#include <iostream>
#include <vector>
#include <bitset>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

#define REP(x,l,u) for(int x = (l);x<=(u);x++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll llmax=9223372036854775807;
const ll llmin=-9223372036854775808;
const int intmin=-2147483648;
const int intmax=2147483647;
const int mod=1e9+7;
const double pi=3.141592653589793238;
ll gcd(ll a,ll b){if(a==0 || b==0) return a+b;else return gcd(b,a%b);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename T> inline void read(T &x){
    x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}
vector<ll> primes;
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }

int Tcnt=0;




template<class TT> class ST{
    struct Node{
        int l,r;
        ll sm,bjc,bjj;
        ll min;
        ll max;
        ll oor;
        ll andd;
    };
    vector<TT> A;
    vector<Node> T;
public:
    ST(vector<TT>& AA) {
        A.emplace_back(0);

        for(int i=0;i<AA.size();i++)
            A.emplace_back(AA[i]);
        T.resize(A.size()<<2);
        build(1,1,(int)A.size()-1);
    }

    ll QuerySum(int l,int r){return querySum(1,l,r);}
    ll QueryOr(int l,int r){return queryOr(1,l,r);}
    ll QueryAnd(int l,int r){return queryAnd(1,l,r);}
    ll QueryMax(int l,int r){return queryMax(1,l,r);}
    ll QueryMin(int l,int r){return queryMin(1,l,r);}

    void   Add(int l,int r,TT x){add(1,l,r,x);}
    void   Mul(int l,int r,TT x){mul(1,l,r,x);}
private:
    void pushup(int i){
        T[i].sm=T[i<<1].sm+T[i<<1|1].sm;
        T[i].max=max(T[i<<1].max,T[i<<1|1].max);
        T[i].min=min(T[i<<1].min,T[i<<1|1].min);

        T[i].oor=(T[i<<1].oor)|(T[i<<1|1].oor);
        T[i].andd=(T[i<<1].andd)&(T[i<<1|1].andd);
    }

    void mul(int i,TT x){
        T[i].sm*=x;T[i].bjc*=x;T[i].bjj*=x;
    }

    void add(int i,TT x){
        T[i].sm+=x*(T[i].r-T[i].l+1);
        T[i].max+=x;
        T[i].min-=x;
        T[i].bjj+=x;
    }

    void pushdown(int i){
        

        add(i<<1,T[i].bjj);add(i<<1|1,T[i].bjj);T[i].bjj=0;
    }

    void build(int i,int l,int r){
        T[i].l=l;T[i].r=r;T[i].bjc=1;
        if(l==r){
            T[i].sm=A[l];
            T[i].min=A[l];
            T[i].max=A[l];
            T[i].oor=A[l];
            T[i].andd=A[l];
            return;
        }
        int M=l+r>>1;
        build(i<<1,l,M);build(i<<1|1,M+1,r);
        pushup(i);
    }
    ll querySum(int i,int l,int r){
        if(l<=T[i].l&&T[i].r<=r)return T[i].sm;

        int M=T[i].l+T[i].r>>1;ll ans=0;
        pushdown(i);
        if(l<=M)ans+=querySum(i<<1,l,r);if(r>M)ans+=querySum(i<<1|1,l,r);
        return ans;
    }
    ll queryCount(int i,int l,int r,int c){
        if(c>39)return 0;
        if(l<=T[i].l&&T[i].r<=r)return T[i].cnt[c];

        int M=T[i].l+T[i].r>>1;ll ans=0;
        pushdown(i);
        if(l<=M)ans+=queryCount(i<<1,l,r,c);if(r>M)ans+=queryCount(i<<1|1,l,r,c);
        return ans;
    }

    ll queryOr(int i,int l,int r){
        if(l<=T[i].l&&T[i].r<=r)return T[i].oor;

        int M=T[i].l+T[i].r>>1;ll ans=0;
        pushdown(i);
        if(l<=M)ans=queryOr(i<<1,l,r);if(r>M)ans|=queryOr(i<<1|1,l,r);
        return ans;
    }
    ll queryAnd(int i,int l,int r){
        if(l<=T[i].l&&T[i].r<=r)return T[i].andd;

        int M=T[i].l+T[i].r>>1;ll ans=0;
        pushdown(i);
        bool set=false;
        if(l<=M)ans=queryAnd(i<<1,l,r),set=true;
        if(r>M)ans=set?(ans&queryAnd(i<<1|1,l,r)):queryAnd(i<<1|1,l,r);
        return ans;
    }
    ll queryMax(int i,int l,int r){
        if(l<=T[i].l&&T[i].r<=r)return T[i].max;

        int M=T[i].l+T[i].r>>1;ll ans=llmin;
        pushdown(i);
        if(l<=M)ans=max(ans,queryMax(i<<1,l,r));
        if(r>M)ans=max(ans,queryMax(i<<1|1,l,r));
        return ans;
    }
    ll queryMin(int i,int l,int r){
        if(l<=T[i].l&&T[i].r<=r)return T[i].min;

        int M=T[i].l+T[i].r>>1;ll ans=llmax;
        pushdown(i);
        if(l<=M)ans=min(ans,queryMin(i<<1,l,r));
        if(r>M)ans=min(ans,queryMin(i<<1|1,l,r));
        return ans;
    }
    void add(int i,int l,int r,TT x){
        if(l<=T[i].l&&T[i].r<=r){
            add(i,x);
            return;
        }
        int M=T[i].l+T[i].r>>1;
        pushdown(i);
        if(l<=M)add(i<<1,l,r,x);if(r>M)add(i<<1|1,l,r,x);
        pushup(i);
    }


    void mul(int i,int l,int r,TT x){
        if(l<=T[i].l&&T[i].r<=r){
            mul(i,x);
            return;
        }
        int M=T[i].l+T[i].r>>1;
        pushdown(i);
        if(l<=M)mul(i<<1,l,r,x);if(r>M)mul(i<<1|1,l,r,x);
        pushup(i);
    }

};

struct less_than_key
{
    inline bool operator() (const string& struct1, const string& struct2)
    {
        return (struct1.size() > struct2.size());
    }
};
ll func(ll n,ll m,ll r,ll x,ll y){
    ll val=(min(n+1,x+r)-max(x,r))*(min(m+1,y+r)-max(y,r));
    return val;
}


bool isPrime(ll x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (ll i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
template <typename T>
vector<int> suffix_array(int n, const T &s, int char_bound) {
    vector<int> a(n);
    if (n == 0) {
        return a;
    }
    if (char_bound != -1) {
        vector<int> aux(char_bound, 0);
        for (int i = 0; i < n; i++) {
            aux[s[i]]++;
        }
        int sum = 0;
        for (int i = 0; i < char_bound; i++) {
            int add = aux[i];
            aux[i] = sum;
            sum += add;
        }
        for (int i = 0; i < n; i++) {
            a[aux[s[i]]++] = i;
        }
    } else {
        iota(a.begin(), a.end(), 0);
        sort(a.begin(), a.end(), [&s](int i, int j) { return s[i] < s[j]; });
    }
    vector<int> sorted_by_second(n);
    vector<int> ptr_group(n);
    vector<int> new_group(n);
    vector<int> group(n);
    group[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        group[a[i]] = group[a[i - 1]] + (!(s[a[i]] == s[a[i - 1]]));
    }
    int cnt = group[a[n - 1]] + 1;
    int step = 1;
    while (cnt < n) {
        int at = 0;
        for (int i = n - step; i < n; i++) {
            sorted_by_second[at++] = i;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] - step >= 0) {
                sorted_by_second[at++] = a[i] - step;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            ptr_group[group[a[i]]] = i;
        }
        for (int i = 0; i < n; i++) {
            int x = sorted_by_second[i];
            a[ptr_group[group[x]]++] = x;
        }
        new_group[a[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (group[a[i]] != group[a[i - 1]]) {
                new_group[a[i]] = new_group[a[i - 1]] + 1;
            } else {
                int pre = (a[i - 1] + step >= n ? -1 : group[a[i - 1] + step]);
                int cur = (a[i] + step >= n ? -1 : group[a[i] + step]);
                new_group[a[i]] = new_group[a[i - 1]] + (pre != cur);
            }
        }
        swap(group, new_group);
        cnt = group[a[n - 1]] + 1;
        step <<= 1;
    }
    return a;
}

template <typename T>
vector<int> suffix_array(const T &s, int char_bound) {
    return suffix_array((int) s.size(), s, char_bound);
}

template <typename T>
vector<int> build_lcp(int n, const T &s, const vector<int> &sa) {
    assert((int) sa.size() == n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[sa[i]] = i;
    }
    vector<int> lcp(max(n - 1, 0));
    int k = 0;
    for (int i = 0; i < n; i++) {
        k = max(k - 1, 0);
        if (pos[i] == n - 1) {
            k = 0;
        } else {
            int j = sa[pos[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            lcp[pos[i]] = k;
        }
    }
    return lcp;
}
template <typename T>
vector<int> build_lcp(const T &s, const vector<int> &sa) {
    return build_lcp((int) s.size(), s, sa);
}

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    vector<T> mxidx;
    int n;
    fenwick(int n) : n (n) {
        fenw.resize(n);
        mxidx.resize(n);
    }

    void modify(int x, T v) {
        int xin=x;
        while (x < n) {
            

            if(fenw[x]<v)
                mxidx[x]=xin;
            fenw[x]=max(v,fenw[x]);
            x |= (x + 1);
        }
    }

    T get(int x,int& idx) {
        T v{};
        while (x >= 0) {
            

            if(fenw[x]>=v)
                idx=mxidx[x];
            v=max(fenw[x],v);
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    bool test=false;

    if(test)
        freopen("/Users/aj/code/HackerRank/input.txt", "r", stdin);
    int n,d;
    cin>>n>>d;
    vector<ll> ar(n),ar0(n);
    ll v;
    REP(i,1,n)cin>>v,ar[i-1]=v,ar0[i-1]=v;
    vector<ll> ar1;
    sort(ar0.begin(),ar0.end());
    ar1.emplace_back(ar0[0]);
    map<ll,int> mp;
    REP(i,1,n-1)if(ar0[i-1]!=ar0[i])ar1.emplace_back(ar0[i]);
    int len=(int)ar1.size();
    REP(i,1,ar1.size())mp[ar1[i-1]]=i;
    fenwick<int> more(len),less(len);
    int ans=0,idd=0;
    map<ll,int> mp2;
    vector<int> p(100001,0);
    REP(i,1,n){
        ll val=ar[i-1];
        int id=mp[val]-1;
        ll vless=val-d;
        auto itless=upper_bound(ar1.begin(),ar1.end(),vless)-ar1.begin();
        itless--;
        ll vmax=val+d;
        auto itmx=lower_bound(ar1.begin(),ar1.end(),vmax)-ar1.begin();
        int mxd=0;
        if(itmx<ar1.size()){
            int idx=mp[ar1[itmx]]-1;
            int vv;
            mxd=more.get(len-1-idx,vv);
            p[i]=len-1-vv;
            if(mp2.find(ar1[p[i]])!=mp2.end())
                p[i]=mp2[ar1[p[i]]];
        }
        if(itless>=0){
            int idx=mp[ar1[itless]]-1;
            int vv;
            int ls=less.get(idx,vv);
            if(ls>mxd) {
                mxd =ls;
                if(mp2.find(ar1[vv])!=mp2.end())
                    p[i] = mp2[ar1[vv]];
            }
        }
        mp2[val]=i;
        if(mxd+1>ans)
            ans=mxd+1,idd=i;
        less.modify(id,mxd+1);
        more.modify(len-1-id,mxd+1);
    }
    cout<<ans<<endl;
    deque<int> dq;
    dq.push_back(idd);
    REP(i,1,ans-1){
        int pr=p[dq.back()];
        dq.push_back(pr);
    }
    REP(i,1,ans){
        int id=dq.back();
        dq.pop_back();
        cout<<id<<" ";
    }
    return 0;
}
