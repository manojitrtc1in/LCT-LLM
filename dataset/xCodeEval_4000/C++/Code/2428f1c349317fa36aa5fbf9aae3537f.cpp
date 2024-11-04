#pragma GCC optimize("O3")
#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#include <deque>
#include <type_traits>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
template<typename Key=int,typename Mapped=__gnu_pbds::null_type,typename Cmp_Fn=std::less<Key>,typename Tag=__gnu_pbds::rb_tree_tag,template<typename Const_Node_Iterator,typename Node_Iterator,typename Cmp_Fn_,typename Allocator_>class Node_Update=__gnu_pbds::tree_order_statistics_node_update,typename Allocator=std::allocator<char>>class ordered_set_t:__gnu_pbds::tree<Key,Mapped,Cmp_Fn,Tag,Node_Update,Allocator>{};const int GRANDOM=std::chrono::high_resolution_clock::now().time_since_epoch().count();struct ghash{int operator()(int x){return std::hash<int>{}(x^GRANDOM);}};template<typename KeyType>class hash_table_t:__gnu_pbds::gp_hash_table<KeyType,int,ghash>{};namespace vh{template<class T>void _R(T&x){std::cin>>x;}inline void _R(int&x){scanf("%d",&x);}inline void _R(int64_t&x){scanf("%" SCNd64,&x);}inline void _R(double&x){scanf("%lf",&x);}inline void _R(char&x){scanf(" %c",&x);}inline void _R(char*x){scanf("%s",x);}inline void R(){}template<class T,class... U>inline void R(T&head,U&... tail){_R(head);R(tail...);}template<class T>void _W(const T&x){cout<<x;}inline void _W(const int&x){printf("%d",x);}inline void _W(const int64_t&x){printf("%" PRId64,x);}inline void _W(const double&x){printf("%.16f",x);}inline void _W(const char&x){putchar(x);}inline void _W(const char*x){printf("%s",x);}template<class T>inline void _W(const vector<T>&x){for(auto i=x.begin();i!=x.end();_W(*i++))if(i!=x.cbegin())putchar(' ');}inline void W(){}template<class T,class... U>inline void W(const T&head,const U&... tail){_W(head);if(sizeof...(tail))putchar(' '),W(tail...);}template<class T,class... U>inline void WL(const T&head,const U&... tail){_W(head);putchar(sizeof...(tail)? ' ':'\n');W(tail...);}};
#define prec setprecision
namespace vh{typedef long long ll;typedef unsigned long long llu;template<typename T>T gcd(T m,T n){while(n){T t=m%n;m=n;n=t;};return m;}template<typename T>T exgcd(T a,T b,T&sa,T&ta){T q,r,sb=0,tb=1,sc,tc;sa=1,ta=0;if(b)do q=a/b,r=a-q*b,a=b,b=r,sc=sa-q*sb,sa=sb,sb=sc,tc=ta-q*tb,ta=tb,tb=tc;while(b);return a;}template<typename T>T mul_inv(T a,T b){T t1=a,t2=b,t3;T v1=1,v2=0,v3;T x;while(t2!=1)x=t1/t2,t3=t1-x*t2,v3=v1-x*v2,t1=t2,t2=t3,v1=v2,v2=v3;return(v2+b)%b;}template<typename T>T powmod(T a,T b,T MOD){if(b<0)return 0;T rv=1;while(b)(b%2)&&(rv=(rv*a)%MOD),a=a*a%MOD,b/=2;return rv;}template<typename T>inline T isqrt(T k){T r=sqrt((double)k)+1;while(r*r>k)r--;return r;}template<typename T>inline T icbrt(T k){T r=cbrt((double)k)+1;while(r*r*r>k)r--;return r;}template<typename T>bool mul_overflow(T&r,T a,T b){return __builtin_mul_overflow(a,b,&r);}template<ll n>struct BitSize{enum{Size=BitSize<n/2>::Size+1};};template<>struct BitSize<0>{enum{Size=1};};template<>struct BitSize<1>{enum{Size=1};};
#define BITSIZE(n) (BitSize<n>::Size)
#define BITMAX(n) (BitSize<n>::Size - 1)
#define DEBUG !defined(ONLINE_JUDGE)
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) (x).rbegin(),(x).rend()
template<typename TH>void _dbg(const char*sdbg,TH h){cerr<<sdbg<<"="<<h<<"\n";}template<typename TH,typename... TA>void _dbg(const char*sdbg,TH h,TA... t){while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<",";_dbg(sdbg+1,t...);}
#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; for(auto itt: x) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
}namespace vh{template<typename T>int min_rotation(vector<T>s){int a=0,N=s.size();for(int b=0;b<N;b++)for(int i=0;i<N;i++){if(a+i==b||s[(a+i)%N]<s[(b+i)%N]){b+=max(0,i-1);break;}if(s[(a+i)%N]>s[(b+i)%N]){a=b;break;}}return a;}}namespace BigInt{using namespace std;const int base=1000000000;const int base_digits=9;struct bigint{vector<int>a;int sign;int size(){if(a.empty())return 0;int ans=(a.size()-1)*base_digits;int ca=a.back();while(ca)ans++,ca/=10;return ans;}bigint operator^(const bigint&v){bigint ans=1,a=*this,b=v;while(!b.isZero()){if(b%2)ans*=a;a*=a,b/=2;}return ans;}string to_string(){stringstream ss;ss<<*this;string s;ss>>s;return s;}int sumof(){string s=to_string();int ans=0;for(auto c:s)ans+=c-'0';return ans;}bigint():sign(1){}bigint(long long v){*this=v;}bigint(const string&s){read(s);}void operator=(const bigint&v){sign=v.sign;a=v.a;}void operator=(long long v){sign=1;a.clear();if(v<0)sign=-1,v=-v;for(;v>0;v=v/base)a.push_back(v%base);}bigint operator+(const bigint&v)const{if(sign==v.sign){bigint res=v;for(int i=0,carry=0;i<(int)max(a.size(),v.a.size())||carry;++i){if(i==(int)res.a.size())res.a.push_back(0);res.a[i]+=carry+(i<(int)a.size()? a[i]:0);carry=res.a[i]>=base;if(carry)res.a[i]-=base;}return res;}return*this-(-v);}bigint operator-(const bigint&v)const{if(sign==v.sign){if(abs()>=v.abs()){bigint res=*this;for(int i=0,carry=0;i<(int)v.a.size()||carry;++i){res.a[i]-=carry+(i<(int)v.a.size()? v.a[i]:0);carry=res.a[i]<0;if(carry)res.a[i]+=base;}res.trim();return res;}return-(v-*this);}return*this+(-v);}void operator*=(int v){if(v<0)sign=-sign,v=-v;for(int i=0,carry=0;i<(int)a.size()||carry;++i){if(i==(int)a.size())a.push_back(0);long long cur=a[i]*(long long)v+carry;carry=(int)(cur/base);a[i]=(int)(cur%base);}trim();}bigint operator*(int v)const{bigint res=*this;res*=v;return res;}void operator*=(long long v){if(v<0)sign=-sign,v=-v;for(int i=0,carry=0;i<(int)a.size()||carry;++i){if(i==(int)a.size())a.push_back(0);long long cur=a[i]*(long long)v+carry;carry=(int)(cur/base);a[i]=(int)(cur%base);}trim();}bigint operator*(long long v)const{bigint res=*this;res*=v;return res;}friend pair<bigint,bigint>divmod(const bigint&a1,const bigint&b1){int norm=base/(b1.a.back()+1);bigint a=a1.abs()*norm;bigint b=b1.abs()*norm;bigint q,r;q.a.resize(a.a.size());for(int i=a.a.size()-1;i>=0;i--){r*=base;r+=a.a[i];int s1=r.a.size()<=b.a.size()? 0:r.a[b.a.size()];int s2=r.a.size()<=b.a.size()-1 ? 0:r.a[b.a.size()-1];int d=((long long)base*s1+s2)/b.a.back();r-=b*d;while(r<0)r+=b,--d;q.a[i]=d;}q.sign=a1.sign*b1.sign;r.sign=a1.sign;q.trim();r.trim();return make_pair(q,r/norm);}bigint operator/(const bigint&v)const{return divmod(*this,v).first;}bigint operator%(const bigint&v)const{return divmod(*this,v).second;}void operator/=(int v){if(v<0)sign=-sign,v=-v;for(int i=(int)a.size()-1,rem=0;i>=0;--i){long long cur=a[i]+rem*(long long)base;a[i]=(int)(cur/v);rem=(int)(cur%v);}trim();}bigint operator/(int v)const{bigint res=*this;res/=v;return res;}int operator%(int v)const{if(v<0)v=-v;int m=0;for(int i=a.size()-1;i>=0;--i)m=(a[i]+m*(long long)base)%v;return m*sign;}void operator++(){*this+=1;}void operator--(){*this-=1;}void operator+=(const bigint&v){*this=*this+v;}void operator-=(const bigint&v){*this=*this-v;}void operator*=(const bigint&v){*this=*this*v;}void operator/=(const bigint&v){*this=*this/v;}bool operator<(const bigint&v)const{if(sign!=v.sign)return sign<v.sign;if(a.size()!=v.a.size())return a.size()*sign<v.a.size()*v.sign;for(int i=a.size()-1;i>=0;i--)if(a[i]!=v.a[i])return a[i]*sign<v.a[i]*sign;return false;}bool operator>(const bigint&v)const{return v<*this;}bool operator<=(const bigint&v)const{return!(v<*this);}bool operator>=(const bigint&v)const{return!(*this<v);}bool operator==(const bigint&v)const{return!(*this<v)&&!(v<*this);}bool operator!=(const bigint&v)const{return*this<v||v<*this;}void trim(){while(!a.empty()&&!a.back())a.pop_back();if(a.empty())sign=1;}bool isZero()const{return a.empty()||(a.size()==1&&!a[0]);}bigint operator-()const{bigint res=*this;res.sign=-sign;return res;}bigint abs()const{bigint res=*this;res.sign*=res.sign;return res;}long long longValue()const{long long res=0;for(int i=a.size()-1;i>=0;i--)res=res*base+a[i];return res*sign;}friend bigint gcd(const bigint&a,const bigint&b){return b.isZero()? a:gcd(b,a%b);}friend bigint lcm(const bigint&a,const bigint&b){return a/gcd(a,b)*b;}void read(const string&s){sign=1;a.clear();int pos=0;while(pos<(int)s.size()&&(s[pos]=='-'||s[pos]=='+')){if(s[pos]=='-')sign=-sign;++pos;}for(int i=s.size()-1;i>=pos;i-=base_digits){int x=0;for(int j=max(pos,i-base_digits+1);j<=i;j++)x=x*10+s[j]-'0';a.push_back(x);}trim();}friend istream&operator>>(istream&stream,bigint&v){string s;stream>>s;v.read(s);return stream;}friend ostream&operator<<(ostream&stream,const bigint&v){if(v.sign==-1)stream<<'-';stream<<(v.a.empty()? 0:v.a.back());for(int i=(int)v.a.size()-2;i>=0;--i)stream<<setw(base_digits)<<setfill('0')<<v.a[i];return stream;}static vector<int>convert_base(const vector<int>&a,int old_digits,int new_digits){vector<long long>p(max(old_digits,new_digits)+1);p[0]=1;for(int i=1;i<(int)p.size();i++)p[i]=p[i-1]*10;vector<int>res;long long cur=0;int cur_digits=0;for(int i=0;i<(int)a.size();i++){cur+=a[i]*p[cur_digits];cur_digits+=old_digits;while(cur_digits>=new_digits){res.push_back(int(cur%p[new_digits]));cur/=p[new_digits];cur_digits-=new_digits;}}res.push_back((int)cur);while(!res.empty()&&!res.back())res.pop_back();return res;}typedef vector<long long>vll;static vll karatsubaMultiply(const vll&a,const vll&b){int n=a.size();vll res(n+n);if(n<=32){for(int i=0;i<n;i++)for(int j=0;j<n;j++)res[i+j]+=a[i]*b[j];return res;}int k=n>>1;vll a1(a.begin(),a.begin()+k);vll a2(a.begin()+k,a.end());vll b1(b.begin(),b.begin()+k);vll b2(b.begin()+k,b.end());vll a1b1=karatsubaMultiply(a1,b1);vll a2b2=karatsubaMultiply(a2,b2);for(int i=0;i<k;i++)a2[i]+=a1[i];for(int i=0;i<k;i++)b2[i]+=b1[i];vll r=karatsubaMultiply(a2,b2);for(int i=0;i<(int)a1b1.size();i++)r[i]-=a1b1[i];for(int i=0;i<(int)a2b2.size();i++)r[i]-=a2b2[i];for(int i=0;i<(int)r.size();i++)res[i+k]+=r[i];for(int i=0;i<(int)a1b1.size();i++)res[i]+=a1b1[i];for(int i=0;i<(int)a2b2.size();i++)res[i+n]+=a2b2[i];return res;}bigint operator*(const bigint&v)const{vector<int>a6=convert_base(this->a,base_digits,6);vector<int>b6=convert_base(v.a,base_digits,6);vll a(a6.begin(),a6.end());vll b(b6.begin(),b6.end());while(a.size()<b.size())a.push_back(0);while(b.size()<a.size())b.push_back(0);while(a.size()&(a.size()-1))a.push_back(0),b.push_back(0);vll c=karatsubaMultiply(a,b);bigint res;res.sign=sign*v.sign;for(int i=0,carry=0;i<(int)c.size();i++){long long cur=c[i]+carry;res.a.push_back((int)(cur%1000000));carry=(int)(cur/1000000);}res.a=convert_base(res.a,6,base_digits);res.trim();return res;}};};namespace vh{};
namespace vh{
  const int maxn=5e5+7;
  int n;ll k;
  char s[maxn];
  char t[maxn];
  BigInt::bigint r=0;
  BigInt::bigint r2;
  int main(){
    srand(GRANDOM);
    cin>>n>>k>>s>>t;
    ll z[2][2][2];
    memset(z,0,sizeof(z));
    int curr=0;
    z[0][0][0]=1;
    for(int i=0;i<n;i++){
      curr=!curr;
      for(int gs=0;gs<2;gs++)
        for(int lt=0;lt<2;lt++)
          z[curr][gs][lt]=0;
      for(char c='a';c<='b';c++){
        for(int gs=0;gs<2;gs++){
          for(int lt=0;lt<2;lt++){
            if(!gs&&c<s[i])continue;
            if(!lt&&c>t[i])continue;
            auto&x=z[curr][gs||c>s[i]][lt||c<t[i]];
            x+=z[!curr][gs][lt];
            if(x>k)x=k;
          }
        }
      }
      ll z2=0;
      for(int gs=0;gs<2;gs++)
        for(int lt=0;lt<2;lt++)
          z2+=z[curr][gs][lt];
      r+=min(k,z2);
    }
    cout<<r<<endl;
    return 0;
  }
};
int main(int argc,char*argv[]){
  std::cin.sync_with_stdio(false);std::cin.tie(nullptr);
  return vh::main();
}
