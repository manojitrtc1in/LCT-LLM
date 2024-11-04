



using namespace std;




























































const int MOD=1000000007;
const int N=100000;

const int __P=8;








template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}





void id6();
inline int gcd(int a, int b){ return __gcd(a,b);}
inline int lcm(int a, int b){return (a*b)/gcd(a, b);}
inline bool id1(int x){ int s = sqrt(x); return (s*s == x);}
inline bool id5(int n){return id1(5*n*n + 4) || id1(5*n*n - 4);} 
inline bool id4(char a){if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')return true;return false;}

int id3(int a, int b, int *x, int *y); 
int modInverse(int a, int m){ 
    int x, y, g = id3(a, m, &x, &y); 
    if (g != 1) 
        return -1; 
    else{ 
        int res = (x%m + m) % m; 
        return res; 
    } 
} 

int id3(int a, int b, int *x, int *y) { 
    if (a == 0){ *x = 0, *y = 1;  return b;} 
    int x1, y1;
    int gcd = id3(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 

int modpow(int x, int y, int p){
    int res = 1;     
    x = x % p; 
    while (y > 0){
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 

unordered_map<int,bool> memo_p;
bool isPrime(int n){
    if(memo_p.find(n)!=memo_p.end()){
        return memo_p[n];
    }
    bool res;
    if (n < 1){res= false;memo_p[n]=res; return res;};if (n <= 3){  res= true;memo_p[n]=res; return res;} 
    if (n%2 == 0 || n%3 == 0){res=false;memo_p[n]=res; return res;}
    for (int i=5; i*i<=n; i=i+6) if (n%i == 0 || n%(i+2) == 0){res= false;memo_p[n]=res; return res;};  
    res= true;
    memo_p[n]=res; 
    return res;
}

vi primeFactors(int n){  
    if(n==1) return vi(1,1);
    bool idx[1]={false};
    vi res;
    while (n%2 == 0){  
        if(!idx[1]){idx[1]=true;res.pb(2);}
        n = n/2;  
    }  
    for (int i=3;i*i<=n; i+=2){
        bool once=false;
        while (n%i==0){ if(!once){res.pb(i);once=true;} n=n/i; }  
    }  
    if (n > 2)res.pb(n);
    return res;
}
void id6(){
    int a=3,b=123,c=124,d=a+b+c;
    for0(10){c=a+b;b=a+d;}
    for0(10){c=a+b;b=a+d;}
    for0(10){c=a+b;b=a+d;}
    for0(10){c=a+b;b=a+d;}
    for0(10){c=a+b;b=a+d;}
    for0(10){c=a+b;b=a+d;}   
}

  
void precomp(int t){
    if(t==0) return;
    id6();
    precomp(t-1);
}

vi id0(int n){ 
    vi res;
    for (int i=1; i<=sqrt(n); i++){ 
        if (n%i == 0){ if (n/i == i){ res.pb(i); } else{ res.pb(n/i); res.pb(i); } } 
    } 
    return res;
}   
int id2(int n){
    int res=0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}

int countGreater(vi arr, int k){ 
	int n=arr.sz;
    int l = 0; 
    int r = n - 1; 

    int leftGreater = n; 
 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
 
        if (arr[m] > k) { 
            leftGreater = m; 
            r = m - 1; 
        } 
        else
            l = m + 1; 
    } 
    return (n - leftGreater); 
}

pii ans(string a){
    pii res={0,0};
    for0(a.ln){
        if(a[i]=='L')res.F++;
        else if(a[i]=='R')res.F--;
        else if(a[i]=='U')res.S++;
        else if(a[i]=='D')res.S--;
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
	precomp(__P>>1);
    int t;
    cin >> t;
    while(t--){
        int n;
        string a;
        cin>>n;
        cin>>a;
        pii res;
        bool mila=false;
        map<pii,set<int>> memo;
        set<pii> s;
        vector<pii> ans;
        for0(a.ln){
            memo[res].insert(i);
            s.insert(res);
            if(a[i]=='L')res.F++;
            else if(a[i]=='R')res.F--;
            else if(a[i]=='U')res.S++;
            else if(a[i]=='D')res.S--;
            if(s.find(res)!=s.end()){
                pii temp;
                auto it=memo[res].ed;
                --it;
                int x=*it;
                temp={x,i};
                ans.pb(temp);
            }
           
        }
        

        if(ans.sz==0){
            pf(-1)
        }else{
            pii finala=ans[0];
            for(auto x:ans){
                int l=x.F;
                int r=x.S;
                if(r-l+1<(finala.S - finala.F + 1)){
                    finala={l,r};
                }
            }
            pf(finala.F+1 SS finala.S+1)
        }
    }	
	return 0;
}
