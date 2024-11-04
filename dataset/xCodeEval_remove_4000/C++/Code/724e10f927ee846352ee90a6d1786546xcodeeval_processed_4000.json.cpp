




using namespace std;


using namespace __gnu_pbds;












typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t int128;
typedef __uint128_t uint128;

typedef long double ld;
typedef __float128 float128;




template<class A,class B,class C>
struct triple{
    A first;B second;C third;
};




const int id5=32;
const int id7=15;

const float128 id4=float128(pow(10.0l,-id5/2.0l))*float128(pow(10.0l,-id5/2.0l));
const ld id1=pow(10.0l,id7);




mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
int rand32(){
    uniform_int_distribution<int>uid(0,INT_MAX);
    return uid(rng32);
}
int id0(){
    uniform_int_distribution<int>uid(INT_MIN,INT_MAX);
    return uid(rng32);
}
ll rand64(){
    uniform_int_distribution<ll>uid(0,LLONG_MAX);
    return uid(rng32);
}
ll id9(){
    uniform_int_distribution<ll>uid(LLONG_MIN,LLONG_MAX);
    return uid(rng32);
}
int rand32(int l,int r){
    uniform_int_distribution<int>uid(l,r);
    return uid(rng32);
}
ll rand64(ll l,ll r){
    uniform_int_distribution<ll>uid(l,r);
    return uid(rng32);
}
template<class It>
void id12(It L,It R){
    shuffle(L,R,rng32);
}
template<class It>
void id6(It L,It R){
    shuffle(L,R,rng64);
}





namespace Timer{
    int __started=clock();
    float started;
    float start(){
        return started=clock()/(float)CLOCKS_PER_SEC;
    }
    float stop(){
        return (clock()/(float)CLOCKS_PER_SEC)-started;
    }
    bool worked_for(float t){
        return clock()-__started>CLOCKS_PER_SEC*t;
    }
    void restart(){
        __started=clock();
    }
};




bool id3(const float128&a,const float128&b){
    return a-b>-id4;
}
bool id11(const ld&a,const ld&b){
    return a-b>-id1;
}

bool id10(const float128&a,const float128&b){
    return a-b<id4;
}
bool id2(const ld&a,const ld&b){
    return a-b<id1;
}
float128 abs(const float128&n){
    if(id10(n,0))return n*-1;
    return n;
}
ll id8(const float128&n){
    float128 a=abs(n-(ll(n)-1));
    float128 b=abs(n-ll(n));
    float128 c=abs(n-(ll(n)+1));
    if(id10(a,b)&&id10(a,c))return ll(n)-1;
    else if(id10(b,a)&&id10(b,c))return ll(n);
    else return ll(n)+1;
}
ll floor128(const float128&n){
    return ll(n);
}
ll ceil128(const float128&n){
    

}




template<class A,class B,class C>
bool operator>(const triple<A,B,C>&a,const triple<A,B,C>&b){
    if(a.first!=b.first)return a.first>b.first;
    if(a.second!=b.second)return a.second>b.second;
    return a.third>b.third;
}
template<class A,class B,class C>
bool operator<(const triple<A,B,C>&a,const triple<A,B,C>&b){
    if(a.first!=b.first)return a.first<b.first;
    if(a.second!=b.second)return a.second<b.second;
    return a.third<b.third;
}




template<class A,class B,class C>
istream&operator>>(istream&stream,triple<A,B,C>&obj){
    stream>>obj.first>>obj.second>>obj.third;
    return stream;
}
template<class A,class B,class C>
ostream&operator<<(ostream&stream,const triple<A,B,C>&obj){
    stream<<obj.first<<" "<<obj.second<<" "<<obj.third;
    return stream;
}




istream&operator>>(istream&stream,int128&n){
    string s;
    if(!(stream>>s))return stream;
    n=0;
    bool negative=0;
    if(s[0]=='-')negative=1;
    for(int i=negative;i<s.size();i++)n*=10,n+=s[i]-'0';
    if(negative)n*=-1;
    return stream;
}
ostream&operator<<(ostream&stream,const int128&n){
    string res;
    int128 _n=n;
    bool negative=_n<0;
    if(negative)_n*=-1;
    if(_n==0)res="0";
    while(_n){
        res+='0'+(_n%10);
        _n/=10;
    }
    if(negative)res+='-';
    reverse(res.begin(),res.end());
    stream<<res;
    return stream;
}
istream&operator>>(istream&stream,uint128&n){
    string s;
    if(!(stream>>s))return stream;
    n=0;
    bool negative=0;
    if(s[0]=='-')negative=1;
    for(int i=negative;i<s.size();i++)n*=10,n+=s[i]-'0';
    if(negative)n*=-1;
    return stream;
}
ostream&operator<<(ostream&stream,const uint128&n){
    string res;
    uint128 _n=n;
    bool negative=_n<0;
    if(negative)_n*=-1;
    if(_n==0)res="0";
    while(_n){
        res+='0'+(_n%10);
        _n/=10;
    }
    if(negative)res+='-';
    reverse(res.begin(),res.end());
    stream<<res;
    return stream;
}
istream&operator>>(istream&stream,float128&n){
    string s;
    if(!(stream>>s))return stream;
    n=0;
    bool negative=0;
    if(s[0]=='-')negative=1;
    int i=negative;
    for(;i<s.size();i++){
        if(s[i]=='.'){break;}
        n*=10,n+=s[i]-'0';
    }
    if(i!=s.size()){
        float128 pow10=float128(0.1l);
        for(i++;i<s.size();i++)n+=pow10*(s[i]-'0'),pow10/=10;
    }
    if(negative)n*=-1;
    return stream;
}
ostream&operator<<(ostream&stream,const float128&n){
    float128 pow10=1;
    float128 _n=n;
    while(id3(_n/pow10,10))pow10*=10;
    while(id3(pow10,1)){
        int cnt=_n/pow10;
        stream<<cnt;
        _n-=pow10*cnt;
        pow10/=10;
    }
    if(!id3(_n,id4)){
        return stream;
    }
    stream<<".";
    pow10=float128(0.1l);
    for(int i=0;i<id5+1;i++){
        int cnt=_n/pow10;
        stream<<cnt;
        _n-=pow10*cnt;
        pow10/=10;
    }
    return stream;
}











template<class A,class B>
istream&operator>>(istream&stream,pair<A,B>&obj){
    stream>>obj.first>>obj.second;
    return stream;
}
template<class A,class B>
ostream&operator<<(ostream&stream,const pair<A,B>&obj){
    stream<<obj.first<<" "<<obj.second;
    return stream;
}


template<class T>
istream&operator>>(istream&stream,vector<T>&obj){
    for(auto&e:obj)stream>>e;
    return stream;
}
template<class T>
ostream&operator<<(ostream&stream,const vector<T>&obj){
    if(obj.empty())return stream;
    cout<<obj[0];
    for(int i=1;i<(int)obj.size();i++)cout<<" "<<obj[i];
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const set<T>&obj){
    if(obj.empty())return stream;
    cout<<*obj.begin();
    for(auto it=next(obj.begin());it!=obj.end();it++)cout<<" "<<*it;
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const unordered_set<T>&obj){
    if(obj.empty())return stream;
    cout<<*obj.begin();
    for(auto it=next(obj.begin());it!=obj.end();it++)cout<<" "<<*it;
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const multiset<T>&obj){
    if(obj.empty())return stream;
    cout<<*obj.begin();
    for(auto it=next(obj.begin());it!=obj.end();it++)cout<<" "<<*it;
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const unordered_multiset<T>&obj){
    if(obj.empty())return stream;
    cout<<*obj.begin();
    for(auto it=next(obj.begin());it!=obj.end();it++)cout<<" "<<*it;
    return stream;
}


template<class A,class B>
ostream&operator<<(ostream&stream,const map<A,B>&obj){
    if(obj.empty())return stream;
    cout<<*obj.begin();
    for(auto it=next(obj.begin());it!=obj.end();it++)cout<<" "<<*it;
    return stream;
}


template<class A,class B>
ostream&operator<<(ostream&stream,const unordered_map<A,B>&obj){
    if(obj.empty())return stream;
    cout<<*obj.begin();
    for(auto it=next(obj.begin());it!=obj.end();it++)cout<<" "<<*it;
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const queue<T>&obj){
    if(obj.empty())return stream;
    queue<T>copy=obj;
    cout<<copy.front();copy.pop();
    while(!copy.empty())cout<<" "<<copy.front(),copy.pop();
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const deque<T>&obj){
    if(obj.empty())return stream;
    cout<<obj[0];
    for(int i=1;i<obj.size();i++)cout<<" "<<obj[i];
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const priority_queue<T>&obj){
    if(obj.empty())return stream;
    priority_queue<T>copy=obj;
    cout<<copy.top();copy.pop();
    while(!copy.empty())cout<<" "<<copy.top(),copy.pop();
    return stream;
}
template<class T>
ostream&operator<<(ostream&stream,const priority_queue<T,vector<T>,greater<T>>&obj){
    if(obj.empty())return stream;
    priority_queue<T,vector<T>,greater<T>>copy=obj;
    cout<<copy.top();copy.pop();
    while(!copy.empty())cout<<" "<<copy.top(),copy.pop();
    return stream;
}


template<class T>
ostream&operator<<(ostream&stream,const list<T>&obj){
    if(obj.empty())return stream;
    cout<<*obj.begin();
    for(auto it=next(obj.begin());it!=obj.end();it++)cout<<" "<<*it;
    return stream;
}




template<class A>
auto amin(const A a){
    return a;
}
template<class A,class...B>
auto amin(const A a,const B...b){
    auto res=amin(b...);
    return (a<res)?a:res;
}
template<class A>
auto amax(const A a){
    return a;
}
template<class A,class...B>
auto amax(const A a,const B...b){
    auto res=amax(b...);
    return (a>res)?a:res;
}
template<class A,class...B>
void smin(A&a,const B... b){
    auto res=amin(b...);
    a=((a<res)?a:res);
}
template<class A,class...B>
void smax(A&a,const B...b){
    auto res=amax(b...);
    a=((a>res)?a:res);
}

const int NMAX=1e5;
int tt[NMAX+5];
int t[NMAX+5];
int get(int p){
    int res=0;
    for(int i=p+1;i>0;i-=i&-i)res+=t[i];
    return res;
}
void upd(int p,int v){
    for(int i=p+1;i<=NMAX+3;i+=i&-i)t[i]+=v;
}

int get2(int p){
    int res=0;
    for(int i=p+1;i>0;i-=i&-i)res+=tt[i];
    return res;
}
void upd2(int p,int v){
    for(int i=p+1;i<=NMAX+3;i+=i&-i)tt[i]+=v;
}

bool comp(const triple<int,int,int> a,const triple<int,int,int>b){
    if(a.first!=b.first)return a.first<b.first;
    if(a.second!=b.second)return a.second>b.second;
    return a.third<b.third;
}


typedef tree<
TREE_TYPE,
null_type,
less<TREE_TYPE>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout.precision(id7);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(auto&e:a)cin>>e;
        map<int,int>cnt;
        for(auto &e:a)cnt[e]++;
        set<pair<int,int>>st1,st2;
        for(auto [key,val]:cnt)st1.insert({val,key});
        int ops=0;
        int need=0;
        int ans=1e9;
        for(int mex=0;mex<=n;mex++){
            if(st1.find({cnt[mex-1],mex-1})!=st1.end()){
                st1.erase({cnt[mex-1],mex-1});
            }
            if(st2.find({cnt[mex-1],mex-1})!=st2.end()){
                ops-=cnt[mex-1];
                st2.erase({cnt[mex-1],mex-1});
            }
            while(!st1.empty()&&ops+st1.begin()->first<=k){
                st2.insert(*st1.begin());
                ops+=st1.begin()->first;
                st1.erase(st1.begin());
            }
            if(k<need)break;
            int diff=mex+st1.size();
            if(mex==0)diff=amax(1,st1.size());
            ans=min(ans,diff-mex);
            if(cnt[mex]==0)need++;
        }
        cout<<ans<<"\n";

    }

}