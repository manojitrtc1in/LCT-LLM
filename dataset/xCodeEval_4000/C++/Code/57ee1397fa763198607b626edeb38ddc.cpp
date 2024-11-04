#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define enl "\n"
#define INF std::numeric_limits<ll>::max()
#define F first
#define S second
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ldb;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;
 
ll greatestSubarraySum(ll array[], ll n);
ll binarySearch(vll arr, ll l, ll r, ll x);
ll modpower(ll x, ll y, ll p);
ll power(ll x, ll y);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll search(ll arr[], ll n, ll k);
string findSum(string str1, string str2);
ll extendedGcd(ll a, ll b, ll & x, ll & y); 
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g);
ll countSetBits(ll n); 
void primeFactors(ll n, map<ll,ll>& arr2, ll k, ll& flaggy);
void matrixMultiply(ll a[3][3], ll b[3][3]);
void matrixPower(ll F[7][7], ll n);
ll sumSquareRootDecomposition(ll arr[], vll helper, ll n, ll l, ll r);
vll squareRootDecompositionSumArray(ll arr[], ll n);
ll minSquareRootDecomposition(ll arr[], vll helper, ll n, ll l, ll r);
ll maxSquareRootDecomposition(ll arr[], vll helper, ll n, ll l, ll r);
vll squareRootDecompositionMinArray(ll arr[], ll n);
vll squareRootDecompositionMaxArray(ll arr[], ll n);
void updateSquareRootDecompositionMinArray(ll arr[], vll &helper, ll n, ll i, ll x);
void updateSquareRootDecompositionMaxArray(ll arr[], vll &helper, ll n, ll i, ll x);
void updateSquareRootDecompositionSumArray(ll arr[], vll &helper, ll n, ll i, ll x);
void dfs(ll i, set<ll> arr[], ll visited[]);
void uni(ll x, ll y, ll par[], ll size[]);
ll find(ll x, ll par[], ll size[]);
ll modulo( ll value, ll m);
class FenwickTree;
void pairsort(ll a[], ll b[], ll n);
ll max(ll a, ll b);
ll min(ll a, ll b);
ll modInverse(ll a, ll m);
ll modsum(ll a, ll b, ll m);
ll modmul(ll a, ll b, ll m);
string reverseOfString(string s);
ll nCrMod(ll n, ll r, ll mod);
vll kmpArray(string s);
 
 
#define MAXI 998244353
 
 
ll fact[1000000];

ll color[1000000];


ll t;
string s;

ll last_color[27];

ll coun[26];


void func(ll n){


    if(n==0){

        color[n]=1;

        last_color[1]=0;

        coun[s[n]-'a']++;

        return;

    }

    func(n-1);

    ll temp=s[n]-'a';

    ll sum=0;

    REP(i,temp+1,26){

        sum+=coun[i];

    }



    if(sum==0){

        ll check=-1;

        REP(i,1,27){

            if(last_color[i]==n-1){

                check=i;
                break;

            }

        }


        color[n]=check;
        last_color[check]=n;
        coun[s[n]-'a']++;

        return;

    }




    ll l=n-sum;
    ll r=n-1;

    REP(i,1,27){



        if(last_color[i]<l){

            color[n]=i;
            last_color[i]=l;
            coun[s[n]-'a']++;

            return;

        } else {

            last_color[i]++;

        }

    }






}


 
int main(){
 
    io
 
    ll q=1;
    

    REP(currentIndex,0,q){

        cin>>t;
        cin>>s;


        memset(last_color, -1, sizeof(last_color));


        func(t-1);

        set<ll> used;

        REP(i,0,t)used.insert(color[i]);

        cout<<used.size()<<endl;
        REP(i,0,t)cout<<color[i]<<" ";


    }


 
 
 
 
 
}
 
 
vll kmpArray(string s){
 
    vll arr(s.length(), 0);
 
    REP(i,1,s.length()){
 
        ll len=arr[i-1];
        while(len>0 && s[len]!=s[i])len=arr[len-1];
        if(s[len]==s[i])len++;
        arr[i]=len;
 
 
 
    }
 
    return arr;
 
 
 
}
 
 
 
ll nCrMod(ll n, ll r, ll mod){
 
    return (fact[n]* modInverse(fact[r], mod) % mod * modInverse(fact[n-r], mod) % mod) % mod; 
 
}
 
void SieveOfEratosthenes(ll n, bool isPrime[]) 
{ 
 
    isPrime[0] = isPrime[1] = false; 
    for (ll i = 2; i <= n; i++) 
        isPrime[i] = true; 
  
    for (ll p = 2; p * p <= n; p++) { 
 
 
        if (isPrime[p] == true) { 
 
            for (ll i = p * 2; i <= n; i += p) 
                isPrime[i] = false; 
        } 
    } 
} 
 
string reverseOfString(string s){
 
    string t;
    REP(i,0,s.length()){
 
        t+=s[s.length()-i-1];
 
    }
 
    return t;
 
}
 
class FenwickTree{
 
private:
    ll n;
 
    ll h(ll i){return (i|(i+1));}
    ll g(ll i){return (i&(i+1));}
 
 
 
public:
 
    ll *sumtree;
    ll *mainArray;
 
    FenwickTree(ll n){
 
        this->n=n;
        mainArray = (ll*)malloc(n*sizeof(ll));
        sumtree = (ll*)calloc(n, sizeof(ll));
 
    }
 
 
 
    void addElementAtIndex(ll i, ll x){
        mainArray[i]=x;
        update(i,x);
    }
 
    void update(ll i, ll delta){
 
        for(ll j=i; j<n; j=h(j)){
            sumtree[j]+=delta;
 
        }
 
    }
 
    ll sum(ll i, ll j){
 
        ll sum1=0, sum2=0;
        ll i1=i,j1=j;
        while(j>=0){
            sum1+=sumtree[j];
            j=g(j)-1;
        }
        while(i>=0){
            sum2+=sumtree[i];
            i=g(i)-1;
        }
        return sum1-sum2+mainArray[i1];
 
    }
 
 
};
 
ll modsum(ll a, ll b, ll m){
 
    return ((a%m)+(b%m))%m;
 
}
 
ll modmul(ll a, ll b, ll m){
 
    return ((a%m)*(b%m))%m;
 
 
}
 
ll modInverse(ll a, ll m) 
{ 
 
    return modpower(a, m-2, m); 
 
} 
 
ll max(ll a, ll b){
 
    if(a>b)return a;
    else return b;
}
 
ll min(ll a, ll b){
 
    if(a<b)return a;
    return b;
 
}
 
 
void pairsort(ll a[], ll b[], ll n) 
{ 
    pair<ll, ll> pairt[n]; 
  
 
    for (ll i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    sort(pairt, pairt + n); 
      
    for (ll i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
}
 
ll extendedGcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extendedGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = extendedGcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
 
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
 
 
string findSum(string str1, string str2) 
{ 
 
    if (str1.length() > str2.length()) {
        string s = str1;
        str1=str2;
        str2=s;
    }
  
 
    string str = ""; 
  
 
    int n1 = str1.length(), n2 = str2.length(); 
  
 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        carry = sum/10; 
    } 
  
    

    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    

    if (carry) 
        str.push_back(carry+'0'); 
  
    

    reverse(str.begin(), str.end()); 
  
    return str; 
} 
 
 
 
ll binarySearch(vll arr, ll l, ll r, ll x) 
{ 
    if (r >= l) { 
        ll mid = l + (r - l) / 2; 
  
        

        

        if (arr[mid] == x) 
            return mid; 
  
        

        

        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        

        

        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    

    

    return -1; 
} 
 
ll greatestSubarraySum(ll array[], ll n){
 
    ll best = 0, sum = 0;
    for (ll k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
 
    return best;
}
 
ll modpower(ll x, ll y, ll p) 
{ 
    ll res = 1;      

  
    x = x % p;  

                

  
    while (y > 0) 
    { 
        

        if (y & 1) 
            res = (res*x) % p; 
  
        

        y = y>>1; 

        x = (x*x) % p;   
    } 
    return res; 
} 
 
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    
    return gcd(b%a, a);
}
 
ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
} 
 
 
ll power(ll x, ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
}
 
ll modulo( ll value, ll m) {
    ll mod = value % m;
    if (value < 0) {
        mod += m;
    }
    return mod;
}
 
ll find(ll x, ll par[], ll size[]){
 
    if(x==par[x])return x;
    else return par[x]=find(par[x],par, size);
 
}
 
void uni(ll x, ll y, ll par[], ll size[]){
 
    x=find(x,par,size);
    y=find(y,par,size);
 
    if(size[x]>size[y])swap(x,y);
 
    par[x]=y;
    size[y]+=size[x];
 
 
}
 
void dfs(ll i, set<ll> arr[], ll visited[]){
 
    if(visited[i])return;
 
    cout<<(char)('a'+i);
 
    visited[i]=1;
 
    for(auto u:arr[i])dfs(u, arr, visited);
 
 
}
 
 
ll countSetBits(ll n) 
{ 
    ll count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
 
 
ll flag2;
 
 
void primeFactors(ll n, map<ll,ll>& arr2, ll k, ll& flaggy)  
{  
    ll count=0;
 
    ll flag=0;
 
    while (n % 2 == 0)  
    {  
        n = n/2;
        count++;  
    }  
  
    if(count%k != 0){
 
        flag=1;
 
        arr2[2]=count%k;
 
    }
    count=0;
 
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            n = n/i;
            count++;  
        }  
 
 
        if(count%k!=0){
 
            flag=1;
            arr2[i]=count%k;
 
        }
 
        count=0;
    }  
  
    if (n > 2)  
        {
            if(1%k!=0){
 
                flag=1;
                arr2[n]=1%k;
 
            }
        }
 
        if(flag==0){flag2++;flaggy=1;}
 
}  
 
void matrixMultiply(ll* a[], ll *b[], ll n) 
{ 
 
    ll mul[n][n]; 
    for (ll i = 0; i < n; i++) 
    { 
        for (ll j = 0; j < n; j++) 
        { 
            mul[i][j] = 0; 
            for (ll k = 0; k < n; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        } 
    } 
  
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            a[i][j] = mul[i][j];
}
 
void matrixPower(ll **F, ll n, ll k) 
{ 
 
    if(n==1)return;
 
    ll **M = (ll **)malloc(k*sizeof(ll *));
 
 
    REP(i,0,k){
        M[i]=(ll *)malloc(k*sizeof(ll));
        REP(j,0,k){
            M[i][j]=F[i][j];
        }
    }
 
  
    matrixPower(F, n/2, k); 
  
    matrixMultiply(F, F, k); 
  
    if (n%2 != 0) 
        matrixMultiply(F, M,k); 
  
}
 
vll squareRootDecompositionMinArray(ll arr[], ll n){
 
    ll k=(ll)ceil(sqrt(n));
    vll helper(k,INF);
 
    REP(i,0,n)helper[i/k]=min(helper[i/k],arr[i]);
 
    return helper;
 
 
}
vll squareRootDecompositionMaxArray(ll arr[], ll n){
 
    ll k=(ll)ceil(sqrt(n));
    vll helper(k,-INF);
 
    REP(i,0,n)helper[i/k]=max(helper[i/k],arr[i]);
 
    return helper;
 
 
}
 
ll minSquareRootDecomposition(ll arr[], vll helper, ll n, ll l, ll r){
 
    ll k=(ll)ceil(sqrt(n));
 
    ll a=l/k;
    ll b=r/k;
 
    ll min1=INF;
 
    if(a==b){
 
        REP(i,l,r+1)min1=min(min1,arr[i]);
 
        return min1;
    }
 
    REP(i,l,(a+1)*k)min1=min(min1,arr[i]);
    REP(i,a+1,b)min1=min(min1,helper[i]);
    REP(i,b*k,r+1)min1=min(min1,arr[i]);
 
    return min1;
 
 
}
ll maxSquareRootDecomposition(ll arr[], vll helper, ll n, ll l, ll r){
 
    ll k=(ll)ceil(sqrt(n));
 
    ll a=l/k;
    ll b=r/k;
 
    ll min1=-INF;
 
    if(a==b){
 
        REP(i,l,r+1)min1=max(min1,arr[i]);
 
        return min1;
    }
 
    REP(i,l,(a+1)*k)min1=max(min1,arr[i]);
    REP(i,a+1,b)min1=max(min1,helper[i]);
    REP(i,b*k,r+1)min1=max(min1,arr[i]);
 
    return min1;
 
 
}
 
vll squareRootDecompositionSumArray(ll arr[], ll n){
 
    ll k=(ll)ceil(sqrt(n));
 
    

 
    vll helper(k,0);
 
    

 
    REP(i,0,n)helper[i/k]+=arr[i];
 
    return helper;
 
 
}
 
void updateSquareRootDecompositionSumArray(ll arr[], vll &helper, ll n, ll i, ll x){
 
    ll k=(ll)ceil(sqrt(n));
    ll delta=x-arr[i];
    arr[i]=x;
    helper[i/k]+=delta;
 
}
 
void updateSquareRootDecompositionMinArray(ll arr[], vll &helper, ll n, ll i, ll x){
 
    ll k=(ll)ceil(sqrt(n));
    if(helper[i/k]==arr[i]){
 
        if(x<arr[i])helper[i/k]=arr[i];
        else{
 
            ll min1=INF;
            REP(j,i/k*k,(i/k+1)*k)min1=min(min1,arr[j]);
            helper[i/k]=min1;
 
        }
 
    } else{
 
        helper[i/k]=min(helper[i/k],x);
    }
 
 
    arr[i]=x;
 
 
}
void updateSquareRootDecompositionMaxArray(ll arr[], vll &helper, ll n, ll i, ll x){
 
    ll k=(ll)ceil(sqrt(n));
    if(helper[i/k]==arr[i]){
 
        if(x<arr[i])helper[i/k]=arr[i];
        else{
 
            ll min1=-INF;
            REP(j,i/k*k,(i/k+1)*k)min1=max(min1,arr[j]);
            helper[i/k]=min1;
 
        }
 
    } else{
 
        helper[i/k]=max(helper[i/k],x);
    }
 
 
    arr[i]=x;
 
 
}
 
ll sumSquareRootDecomposition(ll arr[], vll helper, ll n, ll l, ll r){
 
    ll k=(ll)ceil(sqrt(n));
 
    ll a=l/k;
    ll b=r/k;
 
    ll sum=0;
 
    if(a==b){
 
        REP(i,l,r+1)sum+=arr[i];
 
        return sum;
 
    }
 
    REP(i,l,(a+1)*k){sum+=arr[i];}
    REP(i,b*k,r+1)sum+=arr[i];
    REP(i,a+1,b)sum+=helper[i];
 
    return sum;
 
}	