#include<bits/stdc++.h>
using namespace std;
 
 








 
 




 
 
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define d double
#define endl "\n"
#define debug(x) cout<< (#x)<< " is "<< x<<endl
 




 
 
 
#define graph          vector<vector<int>>
#define V              vector
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vector<int>,greater<int> >
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef V<int>         vi;
typedef V<ll>          vll;
typedef V<string>      vs;
typedef V<double>      vd;
typedef V<pii>         vpii;
typedef V<pll>         vpll;
typedef pair<int,pii>  piii;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
 


























 


 
 

 
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define ff                   first
#define ss                   second
 
 



#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define lbpos(v,x)           (int)(lower_bound(all(v),x)-v.begin())

#define ubpos(v,x)           (int)(upper_bound(all(v),x)-v.begin())

 
#define setbits(x)           __builtin_popcountll(x)


 
#define zerobits(x)           __builtin_ctzll(x)


 
#define fixed(x,n) fixed << setprecision(n)<<x
#define fast(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define init(arr,val) memset(arr,val,sizeof(arr))
#define dynamic(arr,n,type) type *arr=new type[n];
 

 
#define test int t; cin>>t; while(t--)
#define test1 int t=1; while(t--)
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loope(i,a,b) for(int i=a;i<=b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)

 


#define Ns   1000007
#define MOD  1000000007
#define maxn 100000000000017
#define inf  1e18
 

 
 
 


template<typename T>
T nCr(T n, T r) {
    if(r > n - r) r = n - r; 

    int  ans = 1,i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    } return ans;
}
 
 
ll fact(ll n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}
 
 




ll power(ll x, ll y)
{
    if (y == 0)  return 1;
    ll res=power(x,y/2);
    ll resf=res*res;
    if (y % 2)  return resf*x;
    return resf;
}
 
 
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
 
 
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}
 
 
ll GCD(ll A, ll B) {          
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
 
 
 
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
 
 

ll modInv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
 
 



ll modPrimeInv(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}
 
 



void sieve(ll N){
    V<bool>isPrime(N+1,true);
 
    for(ll i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i = 2; i * i <= N; ++i) {
            if(isPrime[i] == true) {
                for(ll j = i * i; j <= N ;j += i)
                    isPrime[j] = false;
        }
    }
 
    

    

    

    

    

    

    

}
 
 
 
 
ll minPrime[Ns];
void factorSieve(ll n){
    memset(minPrime,0,sizeof(minPrime));
    for (ll i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (ll j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}
 
 
ll factorize(ll n) {
 
    map<ll,ll> m;
    m.clear();
    while (n != 1) {
        m[minPrime[n]]++;
        n /= minPrime[n];
    }
 
    for(auto i:m) {
        

        

        

        

        cout<<i.ff<<" "<<i.ss<<endl;
    }
 
    return 1;
}
 
 
void merge(ll A[ ] , ll start, ll mid, ll end) {
    ll p = start ,q = mid+1;
 
    ll Arr[end-start+1] , k=0;
 
    for(ll i = start ;i <= end ;i++) {
        if(p > mid)
        Arr[ k++ ] = A[ q++] ;
 
    else if ( q > end)
        Arr[ k++ ] = A[ p++ ];
 
    else if( A[ p ] < A[ q ])
        Arr[ k++ ] = A[ p++ ];
 
    else
        Arr[ k++ ] = A[ q++];
    }
    for (ll p=0 ; p< k ;p ++) {
        A[ start++ ] = Arr[ p ] ;
    }
}
 
 
void merge_sort (ll A[ ] , ll start , ll end ){
    if( start < end )
    {
        ll mid = (start + end ) / 2 ;
        merge_sort (A, start , mid ) ;
        merge_sort (A,mid+1 , end ) ;
 
        merge(A,start , mid , end );
    }
}
 
 
ll binarySearch(ll a[],ll low,ll high,ll key){
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(a[mid]<key)
        {
            low=mid+1;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
 
    

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    if(a.first == b.first)
    {
        a.second > b.second;
    }
    return (a.first < b.first);
}
struct node{
    int data;
    struct node* next;
};
int lps(string s,int i,int j){ 

    if(i == j){
        return 1;
    }
    if(s[i] == s[j] && i+1 == j){
        return 2;
    }
    if(s[i] == s[j]){
        return lps(s,i+1,j-1)+2;
    }
    return max(lps(s,i+1,j),lps(s,i,j-1));
}
int lpsdp(string s){ 

    int n = s.length();
    int l[n][n];
    for(int i=0;i<n;i++){
        l[i][i]=1;
    }
    for(int cl =2;cl<=n;cl++){
        for(int i=0;i<n-cl+1;i++){
            int j = i+cl-1;
            if(s[i]==s[j] && cl==2){
                l[i][j] = 2;
            }
            if(s[i] == s[j]){
                l[i][j] = l[i+1][j-1]+2;
            }
            else{
                l[i][j] = max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    return l[0][n-1];
}
string lpsubstring(string s){ 

    if(s.length()==1){
        return s;
    }
    int max_length =1;
    int st =0;
    int rt =0;
    int n = s.length();
    for(int i=0;i<n-1;i++){

        int lft =i;
        int rgt =i;
        while(lft>=0 && rgt < n){
            if(s[lft] == s[rgt]){
                lft--;
                rgt++;
            }
            else{
                break;
            }
            int len = rgt - lft -1;;
            if(max_length < len){
                max_length = len;
                st = lft+1;
                rt = rgt -1;
            }
        }
    }
    for(int i=0;i<n-1;i++){ 

        int lft =i;
        int rgt =i+1;
        while(lft>=0 && rgt < n){
            if(s[lft] == s[rgt]){
                lft--;
                rgt++;
            }
            else{
                break;
            }
            int len = rgt -lft -1;
            if(max_length < len){
                max_length = len;
                st = lft+1;
                rt = rgt-1;
            }
        }
    }
    return s.substr(st,max_length);
}
void ans(int a[],int n,int* x,int* y){
    int xor1;
    int set_bit;
    *x = 0;
    *y = 0;
    xor1 = a[0];
    for(int i=1;i<=n;i++){
        xor1 = xor1^a[i];
    }
    for(int i=1;i<=n;i++){
        xor1 = xor1^i;
    }
    set_bit = xor1 & ~(xor1 -1);
    for(int i=0;i<n;i++){
        if(set_bit & a[i]){
            *x = *x^a[i];
        }
        else{
            *y = *y^a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(set_bit & i){
            *x = *x^i;
        }
        else{
            *y = *y^i;
        }
    }
}
int nextGap(int gap){
    if(gap<=1){
        return 0;
    }
    return (gap/2)+(gap%2);
}
void mer(int *arr1, int *arr2, int n, int m) 
{ 
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    { 
        

        for (i = 0; i + gap < n; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(arr1[i], arr1[i + gap]); 
  
        

        for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
            if (arr1[i] > arr2[j]) 
                swap(arr1[i], arr2[j]); 
  
        if (j < m) 
        { 
            

            for (j = 0; j + gap < m; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(arr2[j], arr2[j + gap]); 
        } 
    } 
} 


















































bool isCyclic(vector<int>edj[],int v,bool visited[],bool restack[]){
    if(visited[v] == false){
        visited[v] = true;
        restack[v] = true;
    }
    for(auto it = edj[v].begin();it!=edj[v].end();it++){
       if(!visited[*it] && isCyclic(edj,*it,visited,restack)){
           return true;
       }
       else if(restack[*it]){
           return true;
       }
    }
    restack[v] = false;
    return false;
}
int findduplicate(int a[],int n){
    int index = 0;
    int count =1;
    for(int i=0;i<n;i++){
        if(a[index] == a[i]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            index = i;
            count = 1;
        }
    }
    return a[index];
}
ll n;
void reverse(int A[], int low, int high)
{
	for (int i = low, j = high; i < j; i++, j--)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}

void rotate(int A[], int k, int n)
{
	reverse(A, 0, n-1);

	reverse(A, 0, k-1);

    reverse(A, n-k-1, n-1);

}
struct find{
    int small;
    int large;
};
const int N = 1e6;
int a[N+1];
set<int>t_prime;
void prime(){
    t_prime.insert(4);
    for(int i=3;i<(int)1e6+1;i+=2){
        if(a[i] == 0){
            t_prime.insert(i*i);
            for(int j = i;j<(int)1e6;j+=i){
                a[j] = 1;
            }
        }
    }
}
void solve(){
   char ch[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   string str;
   cin>>str;
   int k;
   cin>>k;
   int a[26];
   map<char,int>mp;
   for(int i=0;i<26;i++){
       cin>>a[i];
       mp[ch[i]] = a[i];
   }
   auto it = max_element(a,a+26)-a;
   char ans = (char)it+97;
  

   for(int i=0;i<k;i++){
       str+=ans;
   }
   

   int res = 0;
   for(int i=0;i<str.size();i++){
       res += (mp[str[i]]*(i+1));
   }
   cout<<res<<"\n";
}
int main() {
    fast();
    int t=1;
    

    while(t--){
        solve();
    }
    return 0;
}