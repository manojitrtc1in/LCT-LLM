#include <bits/stdc++.h>
using namespace std;



typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;



class scanner{ public:
    scanner& operator >> (bool &var)               { scanf("%d",&var);                 return *this; }
    scanner& operator >> (int &var)                { scanf("%d",&var);                 return *this; }
    scanner& operator >> (unsigned int &var)       { scanf("%u",&var);                 return *this; }
    scanner& operator >> (long long &var)          { scanf("%I64d",&var);              return *this; }
    scanner& operator >> (unsigned long long &var) { scanf("%I64u",&var);              return *this; }
    scanner& operator >> (double &var)             { scanf("%lf",&var);                return *this; }
    scanner& operator >> (long double &var)        { double t; scanf("%lf",&t); var=t; return *this; }
    scanner& operator >> (char &var)               { scanf(" %c",&var);                return *this; }
    scanner& operator >> (char var[])              { scanf("%s",var);                  return *this; }
    scanner& operator >> (string &var)             { scanf("%s",T); var=T;             return *this; }
    private: char T[100005];
}__scan;



class printer{ public:
    printer& operator << (bool var)                { printf("%d",var);                 return *this; }
    printer& operator << (int var)                 { printf("%d",var);                 return *this; }
    printer& operator << (unsigned int var)        { printf("%u",var);                 return *this; }
    printer& operator << (long long var)           { printf("%I64d",var);              return *this; }
    printer& operator << (unsigned long long var)  { printf("%I64u",var);              return *this; }
    printer& operator << (double var)              { printf("%f",var);                 return *this; }
    printer& operator << (long double var)         { printf("%f",(double)var);         return *this; }
    printer& operator << (char var)                { printf("%c",var);                 return *this; }
    printer& operator << (const char var[])        { printf("%s",var);                 return *this; }
    printer& operator << (string &var)             { printf("%s",var.c_str());         return *this; }
}__print;



void scan(){}
template<typename T,typename... REST> void scan(T &var, REST &...rest)   { __scan >> var; scan(rest...); }
void print(){}
template<typename T,typename... REST> void print(T var,REST ...rest)     { __print << var << ' '; print(rest...); }
void print_con(){}
template<typename T,typename... REST> void print_con(T var,REST ...rest) { __print << var; print_con(rest...); }



template<typename T> void print(vector<T> &V)           { print_con("["); if(V.size()>0) print_con(" ",V[0]); for(int i=1;i<V.size();i++) print_con(", ",V[i]); print_con(" ]\n"); }
template<typename T> void print(set<T> &S)              { auto it=S.begin(); print_con("{"); if(S.size()>0) print_con(" ",*it++); while(it!=S.end()) print_con(", ",*it++); print_con(" }\n"); }
template<typename T> void print(multiset<T> &S)         { auto it=S.begin(); print_con("{"); if(S.size()>0) print_con(" ",*it++); while(it!=S.end()) print_con(", ",*it++); print_con(" }\n"); }
template<typename T> void print(queue<T> &Q)            { queue<T> t=Q; print_con("<-"); if(t.size()>0){ print_con(" ",+t); --t; } while(!t.empty()){ print_con(", ",+t); --t; } print_con(" <-\n"); }
template<typename T> void print(stack<T> &S)            { stack<T> s=S,t; while(!s.empty()){ t+=+s; s--; } print_con("|"); if(t.size()>0){ print_con(" ",+t); --t; } while(!t.empty()){ print_con(", ",+t); --t; } print_con(" <->\n"); }
template<typename T> void print(deque<T> &DQ)           { deque<T> t=DQ; print_con("<->"); if(t.size()>0){ print_con(" ",+t); --t; } while(!t.empty()){ print_con(", ",+t); --t; } print_con(" <->\n"); }
template<typename K,typename V> void print(map<K,V> &M) { auto it=M.begin(); print_con("{"); if(M.size()>0){ print_con(" ( ",it->first," : ",it->second," )"); it++; } while(it!=M.end()) { print_con(", ( ",it->first," : ",it->second," )"); it++; } print_con(" }\n"); }



template<typename T> T sum_(T var){ return var; }
template<typename T,typename... REST> T sum_(T var,REST ...rest)  { return var+sum_(rest...); }
template<typename T> T mul_(T var){ return var; }
template<typename T,typename... REST> T mul_(T var,REST ...rest)  { return var*mul_(rest...); }
template<typename T> T max_(T var){ return var; }
template<typename T,typename... REST> T max_(T var,REST ...rest) { T max_rest=max_(rest...); return (var>max_rest)?(var):(max_rest); }
template<typename T> T min_(T var){ return var; }
template<typename T,typename... REST> T min_(T var,REST ...rest) { T min_rest=min_(rest...); return (var<min_rest)?(var):(min_rest); }



string operator * (string S,int t)  { string T; while(t--)T+=S; return T; }
void operator --  (string S)        { S.pop_back(); }
void operator --  (string S,int)    { S.pop_back(); }



template<typename T> void operator += (vector<T> &V,T var)          { V.push_back(var); }
template<typename T> void operator << (vector<T> &V,T var)          { V.push_back(var); }
template<typename T> void operator >> (T var,vector<T> &V)          { V.push_back(var); }
template<typename T> void operator -- (vector<T> &V)                { V.pop_back(); }
template<typename T> void operator -- (vector<T> &V,int)            { V.pop_back(); }
template<typename T> void operator += (vector<T> &V1,vector<T> &V2) { V1.insert(V1.end(),V2.begin(),V2.end()); }



template<typename T> void operator += (set<T> &S,T var)             { S.insert(var); }
template<typename T> void operator << (set<T> &S,T var)             { S.insert(var); }
template<typename T> void operator >> (T var,set<T> &S)             { S.insert(var); }
template<typename T> void operator += (multiset<T> &S,T var)        { S.insert(var); }
template<typename T> void operator << (multiset<T> &S,T var)        { S.insert(var); }
template<typename T> void operator >> (T var,multiset<T> &S)        { S.insert(var); }



template<typename T> void operator += (queue<T> &Q,T var)  { Q.push(var); }
template<typename T> void operator << (queue<T> &Q,T var)  { Q.push(var); }
template<typename T> void operator >> (T var,queue<T> &Q)  { Q.push(var); }
template<typename T> void operator -- (queue<T> &Q)        { Q.pop(); }
template<typename T> void operator -- (queue<T> &Q,int)    { Q.pop(); }
template<typename T> T operator +     (queue<T> &Q)        { return Q.front(); }
template<typename T> T operator -     (queue<T> &Q)        { return Q.front(); }



template<typename T> void operator += (stack<T> &S,T var)  { S.push(var); }
template<typename T> void operator << (stack<T> &S,T var)  { S.push(var); }
template<typename T> void operator >> (T var,stack<T> &S)  { S.push(var); }
template<typename T> void operator -- (stack<T> &S)        { S.pop(); }
template<typename T> void operator -- (stack<T> &S,int)    { S.pop(); }
template<typename T> T operator +     (stack<T> &S)        { return S.top(); }
template<typename T> T operator -     (stack<T> &S)        { return S.top(); }



template<typename T> void operator += (deque<T> &DQ,T var) { DQ.push_back(var); }
template<typename T> void operator << (deque<T> &DQ,T var) { DQ.push_back(var); }
template<typename T> void operator >> (T var,deque<T> &DQ) { DQ.push_front(var); }
template<typename T> void operator -- (deque<T> &DQ)       { DQ.pop_front(); }
template<typename T> void operator -- (deque<T> &DQ,int)   { DQ.pop_back(); }
template<typename T> T operator +     (deque<T> &DQ)       { return DQ.front(); }
template<typename T> T operator -     (deque<T> &DQ)       { return DQ.back(); }



template<typename T> void operator += (priority_queue<T> &PQ,T var) { PQ.push(var); }
template<typename T> void operator << (priority_queue<T> &PQ,T var) { PQ.push(var); }
template<typename T> void operator >> (T var,priority_queue<T> &PQ) { PQ.push(var); }
template<typename T> void operator -- (priority_queue<T> &PQ)       { PQ.pop(); }
template<typename T> void operator -- (priority_queue<T> &PQ,int)   { PQ.pop(); }
template<typename T> T operator +     (priority_queue<T> &PQ)       { return PQ.top(); }
template<typename T> T operator -     (priority_queue<T> &PQ)       { return PQ.top(); }



unsigned long long pow2(int n)                  { return 1llu<<n; }
unsigned long long pow10(int n)                 { unsigned long long T=1; for(int i=1;i<=n;i++) T*=10; return T; }
unsigned long long pow(int b,int n)             { unsigned long long T=1; for(int i=1;i<=n;i++) T*=b; return T; }
unsigned long long factorial(int n)             { unsigned long long T=1; for(int i=2;i<=n;i++) T*=i; return T; }
unsigned long long permutation(int n,int r)     { unsigned long long T=1; for(int i=n-r+1;i<=n;i++) T*=i; return T; }
unsigned long long combination(int n,int r)     { unsigned long long T=permutation(n,r); for(int i = 2;i <= r;i++) T/=i; return T; }
int get_digit(unsigned long long n,int d)       { return (n/pow10(d))%10; }
bool eq(double a,double b)                      { return fabs(a-b)<=0.00000001; }
template<typename T> vector<T> gen_prime(T n)   { bool t[n+1]; vector<T> V; for(int i=2;i<=n;i++){ if(!t[i]) {V.push_back(i); for(int j=2*i;j<=n;j+=i) t[j]=1;} } return V; }
template<typename T> vector<T> factor(T n)      { vector<T> V; for(int i=2;i*i<=n;i++) while(n%i==0) { V.push_back(i); n/=i; } if(n>1) V.push_back(n); return V; }
vector<bool> bits(unsigned long long m,int n)   { vector<bool> V; for(int i=1;i<=n;i++) { V.push_back(m&1); m>>=1; } return V; }



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<typename T> using ordered_set = __gnu_pbds::tree< T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update >;
template<typename K,typename V> using ordered_map = __gnu_pbds::tree< K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update >;




#define     trace1(a)           cerr << #a << ": " << a << endl;
#define     trace2(a,b)         cerr << #a << ": " << a << " | " << #b << ": " << b << endl;
#define     trace3(a,b,c)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << endl;
#define     trace4(a,b,c,d)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define     trace5(a,b,c,d,e)   cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define     trace6(a,b,c,d,e,f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;



#define     all(v)              v.begin(),v.end()
#define     vec                 vector



#define     f(i,a,b)            for(long long i=a;i<=b;i++)
#define     rf(i,a,b)           for(long long i=a;i>=b;i--)
#define     fv(i,v)             for(long long i=0;i<v.size();i++)
#define     rfv(i,v)            for(long long i=v.size()-1;i>=0;i--)
#define     it(i,v)             for(auto i=v.begin();i!=v.end();i++)
#define     rit(i,v)            for(auto i=v.rbegin();i!=v.rend();i++)



#define     lesser(T)           [](T lhs,T rhs){return lhs<rhs;}
#define     lesser_equal(T)     [](T lhs,T rhs){return !(rhs<lhs);}
#define     greater(T)          [](T lhs,T rhs){return rhs<lhs;}
#define     greater_equal(T)    [](T lhs,T rhs){return !(lhs<rhs);}
#define     equal(T)            [](T lhs,T rhs){return !(lhs<rhs||rhs<lhs);}
#define     not_equal(T)        [](T lhs,T rhs){return lhs<rhs||rhs<lhs;}



#define     read(a)             freopen(a,"r",stdin);
#define     write(a)            freopen(a,"w",stdout);
#define     eof                 feof(stdin)



#define     seed                srand(time(NULL));
#define     rand_range(a,b)     (((rand()%8)*(1llu<<60)+rand()*(1llu<<45)+rand()*(1llu<<30)+rand()*(1llu<<15)+rand())%(b-a+1)+a)
#define     randr               rand_range



#define     s(...)              scan( __VA_ARGS__);
#define     p(...)              print(__VA_ARGS__);
#define     p_(...)             print_con(__VA_ARGS__);
#define     sf(...)             scanf(__VA_ARGS__);
#define     pf(...)             printf(__VA_ARGS__);
#define     sp                  printf(" ");
#define     el                  printf("\n");
#define     scanline            [](){string T; while(T.empty()) getline(cin,T); return T;}



#define     min_set(lhs,rhs)    ((lhs>rhs)?(lhs=rhs,1):0)
#define     max_set(lhs,rhs)    ((lhs<rhs)?(lhs=rhs,1):0)
#define     mem_set(a,b)        memset(a,b,sizeof(a));
#define     in_range(x,a,b)     (a<=x and x<=b)
#define     gcd(a,b)            __gcd(a,b)
#define     lcm(a,b)            ((a/__gcd(a,b))*b)
#define     if_(a,b,c)          ((a)?(b):(c))
#define     mp(a,b)             make_pair(a,b);



#define     MOD                 1000000007ll
#define     MOD2                1000000009ll
#define     INF                 2000000000ll
#define     LINF                8000000000000000000ll
#define     PI                  acosl(-1.0L)



#define     USEFILE             0
#define     TESTCASE            0
#define     PRINTCASE           0
#define     SPLITCASE           0

int n,m,x,y,ans=0,t;
bool row[1001],col[1001];

void solve(){
    s(n,m)
    f(i,1,m){
        s(x,y)
        row[x]=1;
        col[y]=1;
    }
    f(i,2,n/2){
        if(!row[i])     ans++;
        if(!row[n+1-i]) ans++;
        if(!col[i])     ans++;
        if(!col[n+1-i]) ans++;
    }
    if(n%2){
        if(!row[(n+1)/2] or !col[(n+1)/2]){
            ans++;
        }
    }
    p(ans)
    return;
}

void prep(){

    return;
}

int main(){
    if(USEFILE){
        read("in.txt")
        write("out.txt")
    }
    prep();
    if(TESTCASE){
        int test_num;
        scanf("%d",&test_num);
        for(int test_count=1; test_count<=test_num; test_count++)
        {
            if(SPLITCASE){
                cerr << "\n>>>>> Test " << test_count << " <<<<<\n";
            }
            if(PRINTCASE){
                printf("Case #%d: ",test_count);
            }
            solve();
        }
    }
    else{
        solve();
    }
    return 0;
}
