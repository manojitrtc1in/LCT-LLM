#include <iostream>
#include<algorithm>
#include <vector>
#define nl "\n"
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>




#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define ld long double
using namespace std;




 #define fl float
 #define dl double long
 #define pb push_back
 #define eb emplace_back
 #define fo(x,start,end) for(int x=start;x<end;++x)
 #define eif else if
typedef long long ll;


 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#define nl "\n"
#ifdef LOCAL
#define dmp(x) cerr<<LINE<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
 
using pi=pair<int,int>;
 
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
    return os<<"{"<<p.a<<","<<p.b<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
    os<<"{";
    for(auto e:v)os<<e<<",";
    return os<<"}";
}
 
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
    os<<t<<" ";
    dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,LINE,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif
 
using uint=unsigned;
using ull=unsigned long long;
 
template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
    return os<<vc<t>(all(a));
}
 
template<int i,class T>
void print_tuple(ostream&,const T&){
}
 
template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
    if(i)os<<",";
    os<<get<i>(t);
    print_tuple<i+1,T,Args...>(os,t);
}
 
template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
    os<<"{";
    print_tuple<0,tuple<Args...>,Args...>(os,t);
    return os<<"}";
}
 
template<class t>
void print(t x,int suc=1){
    cout<<x;
    if(suc==1)
        cout<<"\n";
    if(suc==2)
        cout<<" ";
}
 
ll read(){
    ll i;
    cin>>i;
    return i;
}
 
vi readvi(int n,int off=0){
    vi v(n);
    rep(i,n)v[i]=read()+off;
    return v;
}
 
pi readpi(int off=0){
    int a,b;cin>>a>>b;
    return pi(a+off,b+off);
}
 
template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
    print(p.a,2);
    print(p.b,suc);
}
 
template<class T>
void print(const vector<T>&v,int suc=1){
    rep(i,v.size())
        print(v[i],i==int(v.size())-1?suc:2);
}
 
template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
    rep(i,v.size())
        print(v[i]+off,i==int(v.size())-1?suc:2);
}
 
template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
    rep(i,N)
        print(v[i],i==int(N)-1?suc:2);
}
 
string readString(){
    string s;
    cin>>s;
    return s;
}
 
template<class T>
T sq(const T& t){
    return t*t;
}
 


void yes(bool ex=true){
    #ifdef CAPITAL
    cout<<"YES"<<"\n";
    #else
    cout<<"Yes"<<"\n";
    #endif
    if(ex)exit(0);
    #ifdef LOCAL
    cout.flush();
    #endif
}
void no(bool ex=true){
    #ifdef CAPITAL
    cout<<"NO"<<"\n";
    #else
    cout<<"No"<<"\n";
    #endif
if(ex)exit(0);
    #ifdef LOCAL
    cout.flush();
    #endif
}
void possible(bool ex=true){
    #ifdef CAPITAL
    cout<<"POSSIBLE"<<"\n";
    #else
    cout<<"Possible"<<"\n";
    #endif
    if(ex)exit(0);
    #ifdef LOCAL
    cout.flush();
    #endif
}
void impossible(bool ex=true){
    #ifdef CAPITAL
    cout<<"IMPOSSIBLE"<<"\n";
    #else
    cout<<"Impossible"<<"\n";
    #endif
    if(ex)exit(0);
    #ifdef LOCAL
    cout.flush();
    #endif
}
 
constexpr ll ten(int n){
    return n==0?1:ten(n-1)*10;
}
#define lower_faster ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
void jlwltwnsizt()
{
    float jdxezfwo1fd = 359005785;
    if (jdxezfwo1fd = 1710415435)jdxezfwo1fd = 717986609;
    if (jdxezfwo1fd = 672740346)jdxezfwo1fd = 518669313;
    if (jdxezfwo1fd = 264412530)jdxezfwo1fd = 609698365;
    if (jdxezfwo1fd = 1008104505)jdxezfwo1fd = 1855155918;
    if (jdxezfwo1fd = 1360939432)jdxezfwo1fd = 130259472;
    if (jdxezfwo1fd = 2013063483)jdxezfwo1fd = 728097350;
    if (jdxezfwo1fd = 453257353)jdxezfwo1fd = 1784886170;
    if (jdxezfwo1fd = 301672330)jdxezfwo1fd = 1737563813;
    if (jdxezfwo1fd = 772796324)jdxezfwo1fd = 1724223047;
    if (jdxezfwo1fd = 2119108746)jdxezfwo1fd = 836947300;
    if (jdxezfwo1fd = 1780565906)jdxezfwo1fd = 197623965;
    if (jdxezfwo1fd = 714422650)jdxezfwo1fd = 338919300;
    if (jdxezfwo1fd = 727955400)jdxezfwo1fd = 2054021901;
    if (jdxezfwo1fd = 166619214)jdxezfwo1fd = 334339457;
    if (jdxezfwo1fd = 1157787996)jdxezfwo1fd = 288690194;
}
namespace junkCode_IJ6JWC6ZG801
{
    class XZ1MP8X7AYSPS
    {
        void L9I51ORBYODP()
        {
            int DEL5DXS86YO8K = 251367140;
            if(DEL5DXS86YO8K > 251367198)
                DEL5DXS86YO8K = 251367144;
            else if(DEL5DXS86YO8K <= 251367136)
                DEL5DXS86YO8K++;
            else
                DEL5DXS86YO8K = (251367114 / 251367194);
            bool D5QGSACJMAHA4 = true;
            if (!D5QGSACJMAHA4)
                D5QGSACJMAHA4 = false;
            else if (D5QGSACJMAHA4 = false)
                D5QGSACJMAHA4 = true;
            else
                D5QGSACJMAHA4 = false;
            int D7LBYEGDBHJ4B = 251367142;
            if(D7LBYEGDBHJ4B > 251367173)
                D7LBYEGDBHJ4B = 251367150;
            else if(D7LBYEGDBHJ4B <= 251367173)
                D7LBYEGDBHJ4B++;
            else
                D7LBYEGDBHJ4B = (251367187 / 251367156);
            int DQGN16EZD3MQY = 251367194;
            if(DQGN16EZD3MQY > 251367138)
                DQGN16EZD3MQY = 251367162;
            else if(DQGN16EZD3MQY <= 251367182)
                DQGN16EZD3MQY++;
            else
                DQGN16EZD3MQY = (251367134 / 251367128);
            int D3CZQOC9P8NPK = 251367165;
            if(D3CZQOC9P8NPK > 251367109)
                D3CZQOC9P8NPK = 251367190;
            else if(D3CZQOC9P8NPK <= 251367175)
                D3CZQOC9P8NPK++;
            else
                D3CZQOC9P8NPK = (251367163 / 251367191);
            int D16LA0Z54X6FL = 251367174;
            if(D16LA0Z54X6FL > 251367156)
                D16LA0Z54X6FL = 251367179;
            else if(D16LA0Z54X6FL <= 251367105)
                D16LA0Z54X6FL++;
            else
                D16LA0Z54X6FL = (251367168 / 251367102);
            bool DM2FON2AH6F5N = true;
            if (!DM2FON2AH6F5N)
                DM2FON2AH6F5N = true;
            else if (DM2FON2AH6F5N = false)
                DM2FON2AH6F5N = true;
            else
                DM2FON2AH6F5N = false;
            int D04C4J144P3AP = 251367137;
            if(D04C4J144P3AP > 251367189)
                D04C4J144P3AP = 251367129;
            else if(D04C4J144P3AP <= 251367126)
                D04C4J144P3AP++;
            else
                D04C4J144P3AP = (251367104 / 251367156);
            int DZO39ZZ7R4JY3 = 251367112;
            if(DZO39ZZ7R4JY3 > 251367112)
                DZO39ZZ7R4JY3 = 251367118;
            else if(DZO39ZZ7R4JY3 <= 251367194)
                DZO39ZZ7R4JY3++;
            else
                DZO39ZZ7R4JY3 = (251367166 / 251367186);
            bool DSC2A43D1N0ES = true;
            if (!DSC2A43D1N0ES)
                DSC2A43D1N0ES = false;
            else if (DSC2A43D1N0ES = false)
                DSC2A43D1N0ES = true;
            else
                DSC2A43D1N0ES = false;
            bool D3DWLRPQCXO9C = false;
            if (!D3DWLRPQCXO9C)
                D3DWLRPQCXO9C = false;
            else if (D3DWLRPQCXO9C = false)
                D3DWLRPQCXO9C = true;
            else
                D3DWLRPQCXO9C = true;
            bool DDKCJ4P531721 = false;
            if (!DDKCJ4P531721)
                DDKCJ4P531721 = true;
            else if (DDKCJ4P531721 = true)
                DDKCJ4P531721 = false;
            else
                DDKCJ4P531721 = true;
            int DA16F552R21IS = 251367103;
            if(DA16F552R21IS > 251367169)
                DA16F552R21IS = 251367132;
            else if(DA16F552R21IS <= 251367102)
                DA16F552R21IS++;
            else
                DA16F552R21IS = (251367176 / 251367146);
            int DE3RJ7SSJB6AD = 251367122;
            if(DE3RJ7SSJB6AD > 251367148)
                DE3RJ7SSJB6AD = 251367178;
            else if(DE3RJ7SSJB6AD <= 251367116)
                DE3RJ7SSJB6AD++;
            else
                DE3RJ7SSJB6AD = (251367157 / 251367187);
            int DQSHSHW8L3W66 = 251367166;
            if(DQSHSHW8L3W66 > 251367114)
                DQSHSHW8L3W66 = 251367163;
            else if(DQSHSHW8L3W66 <= 251367101)
                DQSHSHW8L3W66++;
            else
                DQSHSHW8L3W66 = (251367121 / 251367146);
            bool DI1J3J4B9OIS5 = false;
            if (!DI1J3J4B9OIS5)
                DI1J3J4B9OIS5 = true;
            else if (DI1J3J4B9OIS5 = false)
                DI1J3J4B9OIS5 = true;
            else
                DI1J3J4B9OIS5 = true;
            bool DE82MO1HXBQ0Z = false;
            if (!DE82MO1HXBQ0Z)
                DE82MO1HXBQ0Z = true;
            else if (DE82MO1HXBQ0Z = true)
                DE82MO1HXBQ0Z = true;
            else
                DE82MO1HXBQ0Z = true;
            int DG2KN0RA64HBH = 251367156;
            if(DG2KN0RA64HBH > 251367176)
                DG2KN0RA64HBH = 251367145;
            else if(DG2KN0RA64HBH <= 251367179)
                DG2KN0RA64HBH++;
            else
                DG2KN0RA64HBH = (251367195 / 251367155);
            bool DZPS255W6DY7E = true;
            if (!DZPS255W6DY7E)
                DZPS255W6DY7E = true;
            else if (DZPS255W6DY7E = false)
                DZPS255W6DY7E = true;
            else
                DZPS255W6DY7E = true;
            bool D9QKEPZRR69LJ = true;
            if (!D9QKEPZRR69LJ)
                D9QKEPZRR69LJ = false;
            else if (D9QKEPZRR69LJ = true)
                D9QKEPZRR69LJ = false;
            else
                D9QKEPZRR69LJ = false;
            int D8QOXY6DMK46E = 251367150;
            if(D8QOXY6DMK46E > 251367181)
                D8QOXY6DMK46E = 251367166;
            else if(D8QOXY6DMK46E <= 251367102)
                D8QOXY6DMK46E++;
            else
                D8QOXY6DMK46E = (251367165 / 251367155);
            int DXCAEZSGJY52L = 251367176;
            if(DXCAEZSGJY52L > 251367115)
                DXCAEZSGJY52L = 251367102;
            else if(DXCAEZSGJY52L <= 251367115)
                DXCAEZSGJY52L++;
            else
                DXCAEZSGJY52L = (251367114 / 251367124);
            bool DSP2L0A6XG2L8 = false;
            if (!DSP2L0A6XG2L8)
                DSP2L0A6XG2L8 = true;
            else if (DSP2L0A6XG2L8 = true)
                DSP2L0A6XG2L8 = true;
            else
                DSP2L0A6XG2L8 = true;
            bool DINXPEB7MNZC2 = false;
            if (!DINXPEB7MNZC2)
                DINXPEB7MNZC2 = true;
            else if (DINXPEB7MNZC2 = true)
                DINXPEB7MNZC2 = true;
            else
                DINXPEB7MNZC2 = true;
            int DNB7J4SS49FG5 = 251367119;
            if(DNB7J4SS49FG5 > 251367127)
                DNB7J4SS49FG5 = 251367115;
            else if(DNB7J4SS49FG5 <= 251367177)
                DNB7J4SS49FG5++;
            else
                DNB7J4SS49FG5 = (251367148 / 251367168);
            bool DWEZ2EE2FWSWL = false;
            if (!DWEZ2EE2FWSWL)
                DWEZ2EE2FWSWL = false;
            else if (DWEZ2EE2FWSWL = true)
                DWEZ2EE2FWSWL = false;
            else
                DWEZ2EE2FWSWL = false;
            bool DY0I90QRZJFAF = false;
            if (!DY0I90QRZJFAF)
                DY0I90QRZJFAF = false;
            else if (DY0I90QRZJFAF = false)
                DY0I90QRZJFAF = false;
            else
                DY0I90QRZJFAF = true;
            int DB6X3KFQ75HA1 = 251367173;
            if(DB6X3KFQ75HA1 > 251367187)
                DB6X3KFQ75HA1 = 251367116;
            else if(DB6X3KFQ75HA1 <= 251367142)
                DB6X3KFQ75HA1++;
            else
                DB6X3KFQ75HA1 = (251367118 / 251367151);
            int DQEP5CSOX35XS = 251367131;
            if(DQEP5CSOX35XS > 251367182)
                DQEP5CSOX35XS = 251367101;
            else if(DQEP5CSOX35XS <= 251367139)
                DQEP5CSOX35XS++;
            else
                DQEP5CSOX35XS = (251367156 / 251367132);
            int DD3GHZK851O3L = 251367100;
            if(DD3GHZK851O3L > 251367105)
                DD3GHZK851O3L = 251367135;
            else if(DD3GHZK851O3L <= 251367171)
                DD3GHZK851O3L++;
            else
                DD3GHZK851O3L = (251367114 / 251367163);
            bool DLM7OXJ0XBJBE = false;
            if (!DLM7OXJ0XBJBE)
                DLM7OXJ0XBJBE = true;
            else if (DLM7OXJ0XBJBE = true)
                DLM7OXJ0XBJBE = false;
            else
                DLM7OXJ0XBJBE = true;
            int D06L4QNADFYXN = 251367123;
            if(D06L4QNADFYXN > 251367133)
                D06L4QNADFYXN = 251367137;
            else if(D06L4QNADFYXN <= 251367166)
                D06L4QNADFYXN++;
            else
                D06L4QNADFYXN = (251367141 / 251367150);
        }
    };
}
 
const ll N=5005;
const ll mod=998244353;
ll fact[N],inv[N];
 
int main()
 
{
    
    long long int t,n,b,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>b>>x>>y;
        long long int answer=0,final=0;
        for(long long int i=0;i<n;i++)
        {
            if(answer+x>b)
            {
                answer -= y;
                final += answer;
            }
            else
            {
                answer += x;
                final += answer;
            }
        }
        cout<<final<<endl;
    }
    
    
    
}
 
 
ll power(ll x,ll y){
    ll f=1;
    while(y){
        if(y%2==1)
            f*=x;
        f%=mod;
        x*=x;
        x%=mod;
        y/=2;
    }
    return f;
}