
 


#include <bits/stdc++.h>
using namespace std;


















#define int long long
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define all(x) x.begin(),x.end()
#define allp(x,n) x,x+n
#define endl "\n"
#define NL cout<<'\n';
#define F first
#define S second
#define disp(x) for(auto t : x )cout<<t<<" ";
#define for0(n) for(int i=0;i<n;i++)
#define for0j(n) for(int j=0;j<n;j++)
#define SS <<" "<<
#define arrin(a,n) vi a(n);for0(n){cin>>a[i];}
#define pf(x) cout<<x<<endl;
#define Check pf("Check")
#define gridin(num,n,m) for0(n){for0j(m) cin>>num[i][j];}
#define dispgrid(num,n,m) for0(n){for0j(m) cout<<num[i][j]<<" "; cout<<endl;}
#define tk(a) int a;cin>>a;
#define tk2(a,b)tk(a)tk(b)
#define tk3(a,b,c)tk2(a,b)tk(c)
#define tk4(a,b,c,d)tk2(a,b)tk2(c,d)
#define tk5(a,b,c,d,e)tk4(a,b,c,d)tk(e)
#define tk6(a,b,c,d,e,f)tk3(a,b,c)tk3(d,e,f)
#define tk7(a,b,c,d,e,f,g)tk6(a,b,c,d,e,f)tk(g)
#define tk8(a,b,c,d,e,f,g,h)tk7(a,b,c,d,e,f,g)tk(h)
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define pii pair<int,int> 
#define vpii vector<pii>
#define acum accumulate
#define fmap gp_hash_table
#define LONG LLONG
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





void fragamenter();
inline int gcd(int a, int b){ return __gcd(a,b);}
inline int lcm(int a, int b){return (a*b)/gcd(a, b);}
inline bool isPerfectSquare(int x){ int s = sqrt(x); return (s*s == x);}
inline bool isFibonacci(int n){return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);} 
inline bool isVowel(char a){if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')return true;return false;}

int gcdExtended(int a, int b, int *x, int *y); 
int modInverse(int a, int m){ 
    int x, y, g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1; 
    else{ 
        int res = (x%m + m) % m; 
        return res; 
    } 
} 

int gcdExtended(int a, int b, int *x, int *y) { 
    if (a == 0){ *x = 0, *y = 1;  return b;} 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
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
void fragamenter(){
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
    fragamenter();
    precomp(t-1);
}

vi divisors(int n){ 
    vi res;
    for (int i=1; i<=sqrt(n); i++){ 
        if (n%i == 0){ if (n/i == i){ res.pb(i); } else{ res.pb(n/i); res.pb(i); } } 
    } 
    return res;
}   
int sumofdigit(int n){
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


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
	precomp(__P>>1);
	string a;
	cin >> a;
	vi one,two;
	
	for0(a.ln){
		if(a[i]=='l'){
			one.pb(i+1);
		}else{
			two.pb(i+1);
		}
	}
	for0(two.sz){
		pf(two[i])
	}
	reverse(all(one));
	for0(one.sz){
		pf(one[i])
	}
	return 0;
}

 