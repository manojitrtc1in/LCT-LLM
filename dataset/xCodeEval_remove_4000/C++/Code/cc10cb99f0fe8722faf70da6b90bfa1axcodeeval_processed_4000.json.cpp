












using namespace std;



template<typename KeyType=int,typename Mapped=__gnu_pbds::null_type,typename Cmp_Fn=std::less<KeyType>,typename Tag=__gnu_pbds::rb_tree_tag,template<typename Const_Node_Iterator,typename Node_Iterator,typename Cmp_Fn_,typename Allocator_>class Node_Update=__gnu_pbds::tree_order_statistics_node_update,typename Allocator=std::allocator<char>>using ordered_set_t=__gnu_pbds::tree<KeyType,Mapped,Cmp_Fn,Tag,Node_Update,Allocator>;const int GRANDOM=std::chrono::high_resolution_clock::now().time_since_epoch().count();struct ghash{int operator()(int x){return std::hash<int>{}(x^GRANDOM);}};template<typename KeyType>using hash_table_t=__gnu_pbds::gp_hash_table<KeyType,int,ghash>;

namespace vh{typedef long long ll;typedef unsigned long long llu;template<typename T>T gcd(T m,T n){while(n){T t=m%n;m=n;n=t;};return m;}template<typename T>T id2(T a,T b,T&sa,T&ta){T q,r,sb=0,tb=1,sc,tc;sa=1,ta=0;if(b)do q=a/b,r=a-q*b,a=b,b=r,sc=sa-q*sb,sa=sb,sb=sc,tc=ta-q*tb,ta=tb,tb=tc;while(b);return a;}template<typename T>T mul_inv(T a,T b){T t1=a,t2=b,t3;T v1=1,v2=0,v3;T x;while(t2!=1)x=t1/t2,t3=t1-x*t2,v3=v1-x*v2,t1=t2,t2=t3,v1=v2,v2=v3;return(v2+b)%b;}template<typename T>T powmod(T a,T b,T MOD){if(b<0)return 0;T rv=1;while(b)(b%2)&&(rv=(rv*a)%MOD),a=a*a%MOD,b/=2;return rv;}template<typename T>inline T isqrt(T k){T r=sqrt((double)k)+1;while(r*r>k)r--;while((r+1)*(r+1)<=k)r++;return r;}template<typename T>inline T id8(T k){T r=cbrt((double)k)+1;while(r*r*r>k)r--;return r;}template<typename T>bool id6(T&r,T a,T b){return __builtin_mul_overflow(a,b,&r);}template<typename T1,typename T2>T1 E0(const T2&x){return get<0>(x);};template<typename T1,typename T2>T1 E1(const T2&x){return get<1>(x);};template<typename T1,typename T2>T1 E2(const T2&x){return get<2>(x);};template<typename T1,typename T2>T1 E3(const T2&x){return get<3>(x);};template<typename T1,typename T2>T1 E4(const T2&x){return get<4>(x);};template<typename T1,typename T2>T1 E5(const T2&x){return get<5>(x);};template<ll n>struct BitSize{enum{Size=BitSize<n/2>::Size+1};};template<>struct BitSize<0>{enum{Size=1};};template<>struct BitSize<1>{enum{Size=1};};







int MSB(unsigned int x){return 8*sizeof(int)-1-__builtin_clz(x|1);}int MSB(unsigned long x){return 8*sizeof(long)-1-__builtin_clzl(x|1);}int MSB(unsigned long long x){return 8*sizeof(long long)-1-__builtin_clzll(x|1);}

constexpr bool id4(ll n){for(int i=2;i*i<=n;i++)if(n%i==0)return false;return true;}}namespace vh{template<class T>struct like_array:is_array<T>{};template<class T,size_t N>struct like_array<array<T,N>>:true_type{};template<class T>struct like_array<vector<T>>:true_type{};template<class T>bool id5(const T&a){return like_array<T>::value;}template<class T>void _R(T&x){std::cin>>x;}inline void _R(int&x){scanf("%d",&x);}inline void _R(int64_t&x){scanf("%" SCNd64,&x);}inline void _R(double&x){scanf("%lf",&x);}inline void _R(char&x){scanf(" %c",&x);}inline void _R(char*x){scanf("%s",x);}template<typename T>inline void _R(vector<T>&v,size_t ie){for(int i=0;i<ie;i++)_R(v[i]);}template<typename T>inline void _R(vector<T>&v){_R(v,v.size());}inline void R(){}template<class T,class... U>inline void R(T&head,U&... tail){_R(head);R(tail...);}template<class T>void _W(const T&x){cout<<x;}template<typename T>inline void _W(vector<T>&v,size_t ie){for(int i=0;i<ie;i++){if(i>0)_W(' ');_W(v[i]);}_W('\n');}template<typename T>inline void _W(vector<T>&v){_W(v,v.size());}template<class T>inline void _W(const vector<T>&x){for(auto i=x.begin();i!=x.end();_W(*i++))if(i!=x.cbegin())putchar(' ');}inline void W(){}template<class T,class... U>inline void W(const T&head,const U&... tail){_W(head);if(sizeof...(tail))putchar(' '),W(tail...);}template<class T,class... U>inline void WL(const T&head,const U&... tail){_W(head);putchar(sizeof...(tail)? ' ':'\n');W(tail...);}template<class T>void _RE(T&x){cin>>x;}template<class Arg,class... Args>void _RE(Arg&first,Args&... rest);void _RE(double&x){string t;_RE(t);x=stod(t);}void _RE(long double&x){string t;_RE(t);x=stold(t);}template<class T>void _RE(complex<T>&x);template<class T1,class T2>void _RE(pair<T1,T2>&p);template<class T>void _RE(vector<T>&a);template<class T,size_t SZ>void _RE(array<T,SZ>&a);template<class Arg,class... Args>void _RE(Arg&first,Args&... rest){_RE(first);_RE(rest...);}template<class T>void _RE(complex<T>&x){T a,b;_RE(a,b);x=cd(a,b);}template<class T1,class T2>void _RE(pair<T1,T2>&p){_RE(p.f,p.s);}template<class T>void _RE(vector<T>&a){for(int i=0,ie=sz(a);i<ie;i++)_RE(a[i]);}template<class T,size_t SZ>void _RE(array<T,SZ>&a){for(int i=0;i<SZ;i++)_RE(a[i]);}template<typename T>struct is_container:false_type{};template<typename T>struct is_container<vector<T>>:true_type{};template<typename T>struct is_container<set<T>>:true_type{};template<typename T,typename T2>struct is_container<map<T,T2>>:true_type{};template<typename T>struct is_container<deque<T>>:true_type{};template<typename T>struct is_container<queue<T>>:true_type{};template<class V,typename=std::enable_if_t<is_container<V>::value>>std::ostream&operator<<(std::ostream&o,const V&v){o<<"[";bool first=true;for(auto x:v){if(!first)o<<",";first=false;o<<x;}o<<"]";return o;}template<class V,typename=std::enable_if_t<is_container<V>::value>>std::istream&operator>>(std::istream&s,V&v){for(auto&x:v){s>>x;}return s;}template<typename A,typename B>std::istream&operator>>(std::istream&s,pair<A,B>&v){return s>>v.first>>v.second;}template<typename A,typename B>std::ostream&operator<<(std::ostream&o,pair<A,B>x){return o<<"("<<x.first<<";"<<x.second<<")";}template<typename A,typename B,typename C>std::ostream&operator<<(std::ostream&o,tuple<A,B,C>x){return o<<"("<<get<0>(x)<<","<<get<1>(x)<<","<<get<2>(x)<<")";}template<typename A,typename B,typename C,typename D>std::ostream&operator<<(std::ostream&o,tuple<A,B,C,D>x){return o<<"("<<get<0>(x)<<","<<get<1>(x)<<","<<get<2>(x)<<","<<get<3>(x)<<")";}template<typename TH>void _dbg(const char*sdbg,TH h){cerr<<sdbg<<"="<<h<<"\n";}template<typename TH,typename... TA>void _dbg(const char*sdbg,TH h,TA... t){while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<",";_dbg(sdbg+1,t...);}








};namespace vh{template<typename T>int min_rotation(vector<T>s){int a=0,N=s.size();for(int b=0;b<N;b++)for(int i=0;i<N;i++){if(a+i==b||s[(a+i)%N]<s[(b+i)%N]){b+=max(0,i-1);break;}if(s[(a+i)%N]>s[(b+i)%N]){a=b;break;}}return a;};template<typename T>class StackGuard{private:T x;public:StackGuard(T x):x(x){}~StackGuard(){x();}};template<class T,class U>T fstTrue(T lo,T hi,U f){hi++;assert(lo<=hi);while(lo<hi){T mid=half(lo+hi);f(mid)? hi=mid:lo=mid+1;}return lo;}template<class T,class U>T lstTrue(T lo,T hi,U f){lo--;assert(lo<=hi);while(lo<hi){T mid=half(lo+hi+1);f(mid)? lo=mid:hi=mid-1;}return lo;}}


namespace vh{template<int N,typename T=ll>class RMQ{private:int _fr;int _to;T a[(N+1)*4];void _update(int node,int fr,int to){if(fr==to){a[node]=T::initValue(fr);}else{int m=(fr+to)/2;_update(node*2,fr,m);_update(node*2+1,m+1,to);a[node]=a[node*2].combine(a[node*2+1]);}}template<typename T2>bool _update2(int node,int fr,int to,int x,T2 val){if(to<x||fr>x){return false;}if(x<=fr&&to<=x){a[node].setValue(val);return true;}int m=(fr+to)/2;bool b1=_update2(node*2,fr,m,x,val);bool b2=_update2(node*2+1,m+1,to,x,val);if(b1||b2){a[node]=a[node*2].combine(a[node*2+1]);return true;}return false;}T query(int node,int fr,int to,int x,int y){if(to<x||fr>y)return T::max();if(x<=fr&&to<=y)return a[node];int m=(fr+to)/2;return query(node*2,fr,m,x,y).combine(query(node*2+1,m+1,to,x,y));}public:void reset(int fr,int to){_fr=fr;_to=to;_update(1,fr,to);}template<typename T2>void set(int x,T2 val){_update2(1,_fr,_to,x,val);}T query(int fr,int to){return query(1,_fr,_to,fr,to);}};};
namespace vh{
const int maxn=200200;
pair<ll,int>pmin(pair<ll,int>a,pair<ll,int>b){
  if(a.first<b.first)
    return a;
  if(b.first<a.first)
    return b;
  if(a.second==maxn)
    return b;
  return a;
}
pair<ll,int>pmax(pair<ll,int>a,pair<ll,int>b){
  if(a.first>b.first)
    return a;
  if(b.first>a.first)
    return b;
  if(a.second==maxn)
    return b;
  return a;
}
struct TNode{
  int value;
  int pos;
  ll sum;
  pair<ll,int>id7;
  pair<ll,int>id0;
  pair<ll,int>id1;
  pair<ll,int>id3;
  static TNode initValue(int pos){
    return TNode{1,pos,1,{1,pos},{1,pos},{1,pos},{1,pos}};
  }
  static TNode max(){
    return TNode{
        0,-1,0,{0,maxn},{0,maxn},{0,maxn},{0,maxn},
    };
  }
  void setValue(int x){
    value=x;
    sum=x;
    if(value>0){
      id7={0,maxn};
      id1={0,maxn};
      id0=id3={x,pos};
    }else{
      id7=id1={x,pos};
      id0={0,maxn};
      id3={0,maxn};
    }
  }
  TNode combine(const TNode&r){
    return{
        0,
        -1,
        sum+r.sum,
        pmin((id7),
             {sum+r.id7.first,r.id7.second}),
        pmax((id0),
             {sum+r.id0.first,r.id0.second}),
        pmin((r.id1),
             {r.sum+id1.first,id1.second}),
        pmax((r.id3),
             {r.sum+id3.first,id3.second}),
    };
  }
};
vector<int>brute(const vector<int>&a){
  int n=a.size();
  vector<int>ans(n);
  for(int l=0;l<n;l++){
    for(int r=l;r<n;r++){
      vector<pair<int,int>>b;
      for(int i=l;i<=r;i++){
        b.emplace_back(a[i],i);
      }
      sort(b.begin(),b.end());
      map<int,int>min_pos,max_pos;
      int y=l;
      for(auto [x,_]:b){
        if(min_pos.find(x)==min_pos.end())
          min_pos[x]=y;
        else 
          min_pos[x]=min(min_pos[x],y);
        if(max_pos.find(x)==max_pos.end())
          max_pos[x]=y;
        else 
          max_pos[x]=max(max_pos[x],y);
        y++;
      }
      int mi=(l+r+1)/2;
      for(int i=l;i<=r;i++){
        ans[i]=max(ans[i],abs(min_pos[a[i]]-mi));
        ans[i]=max(ans[i],abs(max_pos[a[i]]-mi));
      }
    }
  }
  return ans;
}
RMQ<maxn,TNode>rmq;
vector<int>solve(const vector<int>&a){
  int n=a.size();
  vector<int>ans(n);
  vector<pair<int,int>>b;
  for(int i=0;i<n;i++)
    b.emplace_back(a[i],i);
  sort(b.rbegin(),b.rend());
  rmq.reset(0,n-1);
  int lastx=-1;
  vector<int>pi;
  auto work=[&](int i){
    auto l=rmq.query(0,i-1);
    auto r=rmq.query(i+1,n-1);
    {
      auto smL=l.id3;
      auto smR=r.id0;
      if(smL.second==maxn)
        smL={0,i};
      if(smR.second==maxn)
        smR={0,i};
      int sm=(smL.first+smR.first);
      int ss=sm;
      if(sm%2)
        sm++;
      sm/=2;
      ans[i]=max(ans[i],abs(ss-sm));
    }
    {
      auto smL=l.id1;
      auto smR=r.id7;
      if(smL.second==maxn)
        smL={0,i};
      if(smR.second==maxn)
        smR={0,i};
      int sm=abs(smL.first+smR.first);
      int ss=sm;
      if(sm%2)
        sm--;
      sm/=2;
      ans[i]=max(ans[i],abs(ss-sm));
    }
  };
  for(auto [x,i]:b){
    if(x!=lastx){
      for(auto i:pi)rmq.set(i,-1);
      for(auto i:pi)work(i);
    }
    work(i);
    if(x==lastx)
      pi.push_back(i);
    else{
      lastx=x;
      pi.resize(1);
      pi[0]=i;
      lastx=x;
    }
  }
  for(auto i:pi)rmq.set(i,-1);
  for(auto i:pi)work(i);
  return ans;
}
int main(){
  srand(GRANDOM);
  int n;
  cin>>n;
  vector<int>a(n);
  cin>>a;
  auto ans=solve(a);
  for(auto x:ans)
    cout<<x<<' ';
  return 0;
}
};
int main(int argc,char*argv[]){
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  return vh::main();
}
