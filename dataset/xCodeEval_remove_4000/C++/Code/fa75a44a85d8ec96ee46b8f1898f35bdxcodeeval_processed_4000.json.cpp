
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
    private: char T[1000005];
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





template<typename T> using ordered_set = __gnu_pbds::tree< T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update >;
template<typename K,typename V> using ordered_map = __gnu_pbds::tree< K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update >;





















































































ll k,x,n,m,sum,p;
ll c1[55],c2[55],c12[55],c21[55],c22[55];
ll lo1,hi1,lo2,hi2,is12,is21,is22;
ll s1[105],s2[105];
char to_char[3]={'A','C','X'};

void solve(){
    s(k,x,n,m)
    f(i,1,n){
        s1[i]=-1;
    }
    f(i,1,m){
        s2[i]=-1;
    }
    c1[1]=1;  c1[2]=0;  c1[3]=1;
    c2[1]=0;  c2[2]=1;  c2[3]=1;
    c12[1]=0; c12[2]=0; c12[3]=1;
    c21[1]=0; c21[2]=0; c21[3]=0;
    c22[1]=0; c22[2]=0; c22[3]=0;
    f(i,4,k){
        c1[i]=c1[i-1]+c1[i-2];
        c2[i]=c2[i-1]+c2[i-2];
        c12[i]=c12[i-1]+c12[i-2];
        c21[i]=c21[i-1]+c21[i-2]+if_(i%2,0,1);
        c22[i]=c22[i-1]+c22[i-2]+if_(i%2,1,0);
    }
    f(i11,0,2){
        f(i12,0,2){
            f(i21,0,2){
                f(i22,0,2){
                    if( (n>1 or i11==i12) and (m>1 or i21==i22) ){
                        if(i11==0){
                            if(i12==1) { lo1=if_(n==2,1,0); hi1=n/2;     }
                            else       { lo1=0;             hi1=(n-1)/2; }
                        }
                        else{
                            if(i12==1) { lo1=0;             hi1=(n-1)/2; }
                            else       { lo1=0;             hi1=(n-2)/2; }
                        }
                        if(i21==0){
                            if(i22==1) { lo2=if_(m==2,1,0); hi2=m/2;     }
                            else       { lo2=0;             hi2=(m-1)/2; }
                        }
                        else{
                            if(i22==1) { lo2=0;             hi2=(m-1)/2; }
                            else       { lo2=0;             hi2=(m-2)/2; }
                        }
                        is12=if_(i12==0 and i21==1, 1, 0);
                        is21=if_(i22==0 and i11==1, 1, 0);
                        is22=if_(i22==0 and i21==1, 1, 0);
                        f(i,lo1,hi1){
                            f(j,lo2,hi2){
                                sum=i*c1[k]+j*c2[k]+is12*c12[k]+is21*c21[k]+is22*c22[k];
                                if(sum==x){
                                    s1[1]=i11;
                                    s1[n]=i12;
                                    s2[1]=i21;
                                    s2[m]=i22;
                                    f(ii,1,n-1){
                                        if(i==0){
                                            break;
                                        }
                                        if( (s1[ii]==0 or s1[ii]==-1) and (s1[ii+1]==1 or s1[ii+1]==-1) ){
                                            s1[ii]=0; s1[ii+1]=1; i--;
                                        }
                                    }
                                    f(jj,1,m-1){
                                        if(j==0){
                                            break;
                                        }
                                        if( (s2[jj]==0 or s2[jj]==-1) and (s2[jj+1]==1 or s2[jj+1]==-1) ){
                                            s2[jj]=0; s2[jj+1]=1; j--;
                                        }
                                    }
                                    f(ii,1,n){
                                        if(s1[ii]==-1){
                                            s1[ii]=2;
                                        }
                                    }
                                    f(jj,1,m){
                                        if(s2[jj]==-1){
                                            s2[jj]=2;
                                        }
                                    }
                                    f(ii,1,n){
                                        p_(to_char[s1[ii]])
                                    }el
                                    f(jj,1,m){
                                        p_(to_char[s2[jj]])
                                    }
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    p_("Happy new year!")
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
                printf("Case 
            }
            solve();
        }
    }
    else{
        solve();
    }
    return 0;
}
