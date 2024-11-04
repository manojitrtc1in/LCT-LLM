#pragma region template
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL
 #include <debug>
#else
 #define debug(...) void(0)
#endif

using ll=long long;
using ld=long double;
using vi=vector<int>;
using vll=vector<ll>;
using pi=pair<int,int>;
using pll=pair<ll,ll>;

#define overload2(a,b,c,...) c
#define overload3(a,b,c,d,...) d
#define overload4(a,b,c,d,e,...) e
#define overload5(a,b,c,d,e,f,...) f

#define TYPE1(T) template<typename T>
#define TYPE2(T,U) template<typename T,typename U>
#define TYPE(...) overload2(__VA_ARGS__,TYPE2,TYPE1)(__VA_ARGS__)
#define TYPES1(T) template<typename... T>
#define TYPES2(H,T) template<typename H,typename... T>
#define TYPES(...) overload2(__VA_ARGS__,TYPES2,TYPES1)(__VA_ARGS__)

#define REP4(i,s,n,d) for(int i=(s);i<(n);i+=(d))
#define REP3(i,s,n) REP4(i,s,n,1)
#define REP2(i,n) REP3(i,0,n)
#define REP1(n) REP2(tomato,n)
#define REP(...) overload4(__VA_ARGS__,REP4,REP3,REP2,REP1)(__VA_ARGS__)

#define RREP4(i,s,n,d) for(int i=(n)-1;i>=s;i-=d)
#define RREP3(i,s,n) RREP4(i,s,n,1)
#define RREP2(i,n) RREP3(i,0,n)
#define RREP1(n) RREP2(tomato,n)
#define RREP(...) overload4(__VA_ARGS__,RREP4,RREP3,RREP2,RREP1)(__VA_ARGS__)

#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define REVERSE(v) reverse(ALL(v))
#define UNIQUE(v) SORT(v),v.erase(unique(ALL(v)),v.end())

TYPES(T) void input(T&... a){ (cin>>...>>a); }
#define DECLARE(T,...) T __VA_ARGS__;input(__VA_ARGS__);
#define INT(...) DECLARE(int,__VA_ARGS__)
#define STR(...) DECLARE(string,__VA_ARGS__)
#define LL(...) DECLARE(long long,__VA_ARGS__)
#define CHR(...) DECLARE(char,__VA_ARGS__)
#define DBL(...) DECLARE(double,__VA_ARGS__)
#define VI(n,v) vi v(n);cin>>v;
#define VLL(n,v) vll v(n);cin>>v;

TYPE(T) istream&operator>>(istream&is,vector<T>&v){
  for(auto&a:v)cin>>a;
  return is;
}
TYPE(T) ostream&operator<<(ostream&os,const vector<T>&v){
  if(&os==&cerr)os<<"[";
  REP(i,v.size()){
    os<<v[i];
    if(i+1<v.size())os<<(&os==&cerr?",":" ");
  }
  if(&os==&cerr)os<<"]";
  return os;
}
TYPE(T,S) istream&operator>>(istream&is,pair<T,S>&p){
  cin>>p.first>>p.second;
  return is;
}

TYPE(T) using pq=priority_queue<T>;
TYPE(T) using pqg=priority_queue<T,vector<T>,greater<T>>;
TYPE(T) T pick(queue<T>& que){assert(que.size()); T a=que.front();que.pop();return a;}
TYPE(T) T pick(pq<T>& que){assert(que.size()); T a=que.top();que.pop();return a;}
TYPE(T) T pick(pqg<T>& que){assert(que.size()); T a=que.top();que.pop();return a;}
TYPE(T) T pick(stack<T>& sta){assert(sta.size()); T a=sta.top();sta.pop();return a;}

string YES(bool f=true){return (f?"YES":"NO");}
string Yes(bool f=true){return (f?"Yes":"No");}
string yes(bool f=true){return (f?"yes":"no");}

constexpr int INF=1e9+7;
constexpr ll LINF=ll(1e18)+7;
constexpr ld EPS=1e-10;

vi iota(int n){vi a(n);iota(ALL(a),0);return a;}
TYPE(T) void fin(T a){cout<<a<<endl;exit(0);}
TYPE(T) bool chmax(T &a,T b){return (a<b&&(a=b,true));}
TYPE(T) bool chmin(T &a,T b){return (a>b&&(a=b,true));}
TYPES(T,Ns)
auto make_vector(T x,int n,Ns ...ns){
  if constexpr(sizeof...(ns)==0)return vector<T>(n,x);
  else return vector(n,make_vector<T>(x,ns...));
}
bool in(const ll S,const int a){return (S>>a)&1;}
int popcount(const ll S){return __builtin_popcountll(S);}
#pragma endregion template


#include <algorithm>
#include <cassert>
#include <numeric>
#include <string>
#include <vector>

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}









template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < THRESHOLD_NAIVE) {
        return sa_naive(s);
    }
    if (n < THRESHOLD_DOUBLING) {
        return sa_doubling(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) sorted_lms.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}

}  


std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}









template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
                           const std::vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}









template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

}  


using namespace atcoder;



template<typename T,T MOD,T B>
struct RollingHash{
  using ll = long long;
  vector<T> hash,po;
  RollingHash(vector<T> vs){init(vs);}
  RollingHash(string &s){
    vector<T> vs;
    for(char c:s) vs.emplace_back(c);
    init(vs);
  }
  void init(vector<T> vs){
    int n=vs.size();
    hash.assign(n+1,0);
    po.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;
      po[i+1]=(ll)po[i]*B%MOD;
    }
  }
  

  T find(int l,int r){
    T res=(ll)hash[r]+MOD-(ll)hash[l]*po[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
};
using RH=RollingHash<ll,1000000007,998244353>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  STR(s);
  auto v=z_algorithm(s);
  int n=s.size();
  RH rh(s);
  map<ll,int> mp;

  REP(i,n){
    if(!i)continue;
    if(v[i]!=n-i)continue;
    for(int j=v[i];j<v[i]+10 and j+1<=n;j++){
      debug(i,v[i],j);
      int h=rh.find(v[i],j+1);
      chmax(mp[h],j+1);
    }
  }
  REP(i,10){
    if(i+1>n)break;
    int h=rh.find(0,i+1);
    chmax(mp[h],i+1);
  }

  
  INT(q);
  REP(_,q){
    STR(t);
    if(s.size()<=15){
      string S=s+t;
       REP(i,t.size()){
        int ans=0;
        REP(j,1,n+i+1){
          bool ok=true;
          REP(k,j)if(S[k]!=S[n+i-j+1+k])ok=false;
        if(ok)ans=j;
        }
        cout<<ans<<"\n "[i+1<t.size()];
      }
      continue;
    }
    RH tt(t);
    int pre=-1;
    REP(i,t.size()){
      if(pre>=s.size() and pre-s.size()<t.size() and t[pre-s.size()]==t[i]){
        pre++;
        cout<<pre<<"\n "[i+1<t.size()];
        continue;
      }
      int res=(mp.count(tt.find(0,i+1))?mp[tt.find(0,i+1)]:0);
      REP(j,i+1)if(j+1<=n and tt.find(i-j,i+1)==rh.find(0,j+1))chmax(res,j+1);
      cout<<res<<"\n "[i+1<t.size()];
      pre=res;
    }
  }
}
