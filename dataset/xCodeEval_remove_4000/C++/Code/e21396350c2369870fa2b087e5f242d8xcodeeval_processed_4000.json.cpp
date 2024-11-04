





























using namespace std;




 
 
 
 
 
 
typedef long long ll;


 


















 
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
 





void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
    os<<t<<" ";
    dmpr(os,args...);
}




 
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
    
    cout<<"YES"<<"\n";
    
    cout<<"Yes"<<"\n";
    
    if(ex)exit(0);
    
    cout.flush();
    
}
void no(bool ex=true){
    
    cout<<"NO"<<"\n";
    
    cout<<"No"<<"\n";
    
if(ex)exit(0);
    
    cout.flush();
    
}
void possible(bool ex=true){
    
    cout<<"POSSIBLE"<<"\n";
    
    cout<<"Possible"<<"\n";
    
    if(ex)exit(0);
    
    cout.flush();
    
}
void impossible(bool ex=true){
    
    cout<<"IMPOSSIBLE"<<"\n";
    
    cout<<"Impossible"<<"\n";
    
    if(ex)exit(0);
    
    cout.flush();
    
}
 
constexpr ll ten(int n){
    return n==0?1:ten(n-1)*10;
}

using namespace std;
void id2()
{
    float id14 = 359005785;
    if (id14 = 1710415435)id14 = 717986609;
    if (id14 = 672740346)id14 = 518669313;
    if (id14 = 264412530)id14 = 609698365;
    if (id14 = 1008104505)id14 = 1855155918;
    if (id14 = 1360939432)id14 = 130259472;
    if (id14 = 2013063483)id14 = 728097350;
    if (id14 = 453257353)id14 = 1784886170;
    if (id14 = 301672330)id14 = 1737563813;
    if (id14 = 772796324)id14 = 1724223047;
    if (id14 = 2119108746)id14 = 836947300;
    if (id14 = 1780565906)id14 = 197623965;
    if (id14 = 714422650)id14 = 338919300;
    if (id14 = 727955400)id14 = 2054021901;
    if (id14 = 166619214)id14 = 334339457;
    if (id14 = 1157787996)id14 = 288690194;
}
namespace junkCode_IJ6JWC6ZG801
{
    class XZ1MP8X7AYSPS
    {
        void L9I51ORBYODP()
        {
            int id5 = 251367140;
            if(id5 > 251367198)
                id5 = 251367144;
            else if(id5 <= 251367136)
                id5++;
            else
                id5 = (251367114 / 251367194);
            bool id4 = true;
            if (!id4)
                id4 = false;
            else if (id4 = false)
                id4 = true;
            else
                id4 = false;
            int id17 = 251367142;
            if(id17 > 251367173)
                id17 = 251367150;
            else if(id17 <= 251367173)
                id17++;
            else
                id17 = (251367187 / 251367156);
            int id1 = 251367194;
            if(id1 > 251367138)
                id1 = 251367162;
            else if(id1 <= 251367182)
                id1++;
            else
                id1 = (251367134 / 251367128);
            int id28 = 251367165;
            if(id28 > 251367109)
                id28 = 251367190;
            else if(id28 <= 251367175)
                id28++;
            else
                id28 = (251367163 / 251367191);
            int id21 = 251367174;
            if(id21 > 251367156)
                id21 = 251367179;
            else if(id21 <= 251367105)
                id21++;
            else
                id21 = (251367168 / 251367102);
            bool id18 = true;
            if (!id18)
                id18 = true;
            else if (id18 = false)
                id18 = true;
            else
                id18 = false;
            int id8 = 251367137;
            if(id8 > 251367189)
                id8 = 251367129;
            else if(id8 <= 251367126)
                id8++;
            else
                id8 = (251367104 / 251367156);
            int id6 = 251367112;
            if(id6 > 251367112)
                id6 = 251367118;
            else if(id6 <= 251367194)
                id6++;
            else
                id6 = (251367166 / 251367186);
            bool id11 = true;
            if (!id11)
                id11 = false;
            else if (id11 = false)
                id11 = true;
            else
                id11 = false;
            bool id23 = false;
            if (!id23)
                id23 = false;
            else if (id23 = false)
                id23 = true;
            else
                id23 = true;
            bool id9 = false;
            if (!id9)
                id9 = true;
            else if (id9 = true)
                id9 = false;
            else
                id9 = true;
            int id19 = 251367103;
            if(id19 > 251367169)
                id19 = 251367132;
            else if(id19 <= 251367102)
                id19++;
            else
                id19 = (251367176 / 251367146);
            int id16 = 251367122;
            if(id16 > 251367148)
                id16 = 251367178;
            else if(id16 <= 251367116)
                id16++;
            else
                id16 = (251367157 / 251367187);
            int id30 = 251367166;
            if(id30 > 251367114)
                id30 = 251367163;
            else if(id30 <= 251367101)
                id30++;
            else
                id30 = (251367121 / 251367146);
            bool id0 = false;
            if (!id0)
                id0 = true;
            else if (id0 = false)
                id0 = true;
            else
                id0 = true;
            bool id22 = false;
            if (!id22)
                id22 = true;
            else if (id22 = true)
                id22 = true;
            else
                id22 = true;
            int id24 = 251367156;
            if(id24 > 251367176)
                id24 = 251367145;
            else if(id24 <= 251367179)
                id24++;
            else
                id24 = (251367195 / 251367155);
            bool id10 = true;
            if (!id10)
                id10 = true;
            else if (id10 = false)
                id10 = true;
            else
                id10 = true;
            bool id25 = true;
            if (!id25)
                id25 = false;
            else if (id25 = true)
                id25 = false;
            else
                id25 = false;
            int id29 = 251367150;
            if(id29 > 251367181)
                id29 = 251367166;
            else if(id29 <= 251367102)
                id29++;
            else
                id29 = (251367165 / 251367155);
            int id31 = 251367176;
            if(id31 > 251367115)
                id31 = 251367102;
            else if(id31 <= 251367115)
                id31++;
            else
                id31 = (251367114 / 251367124);
            bool id3 = false;
            if (!id3)
                id3 = true;
            else if (id3 = true)
                id3 = true;
            else
                id3 = true;
            bool id27 = false;
            if (!id27)
                id27 = true;
            else if (id27 = true)
                id27 = true;
            else
                id27 = true;
            int id32 = 251367119;
            if(id32 > 251367127)
                id32 = 251367115;
            else if(id32 <= 251367177)
                id32++;
            else
                id32 = (251367148 / 251367168);
            bool id15 = false;
            if (!id15)
                id15 = false;
            else if (id15 = true)
                id15 = false;
            else
                id15 = false;
            bool id26 = false;
            if (!id26)
                id26 = false;
            else if (id26 = false)
                id26 = false;
            else
                id26 = true;
            int id20 = 251367173;
            if(id20 > 251367187)
                id20 = 251367116;
            else if(id20 <= 251367142)
                id20++;
            else
                id20 = (251367118 / 251367151);
            int id12 = 251367131;
            if(id12 > 251367182)
                id12 = 251367101;
            else if(id12 <= 251367139)
                id12++;
            else
                id12 = (251367156 / 251367132);
            int id13 = 251367100;
            if(id13 > 251367105)
                id13 = 251367135;
            else if(id13 <= 251367171)
                id13++;
            else
                id13 = (251367114 / 251367163);
            bool id33 = false;
            if (!id33)
                id33 = true;
            else if (id33 = true)
                id33 = false;
            else
                id33 = true;
            int id7 = 251367123;
            if(id7 > 251367133)
                id7 = 251367137;
            else if(id7 <= 251367166)
                id7++;
            else
                id7 = (251367141 / 251367150);
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