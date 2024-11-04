

#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout << #x << " " << x << endl;


















#define ld long double
#define ll long long int
#define MOD 1000000007
#define pl pair<ll, ll>
#define pd pair<ld, ld>
#define vpl vector<pl>
#define vs vector<string>
#define vvs vector<vs>
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define vvb vector<vb>
#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>
#define vd vector<ld>
#define vvd vector<vd>
#define umap unordered_map
#define uset unordered_set
#define chash custom_hash 
#define pq priority_queue
#define f first
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define pb push_back
#define all(a)                          ::begin(a),::end(a)
#define sz(X) (ll)((X).size())
#define EACH(x, a) for (auto &x:a)
#define nl '\n'
#define Fo(i, n) for (ll i=0; i<n; i++)
#define fo(i, a, b) for (ll i=a; i<b; i++)  

string YES="YES\n";
string NO="NO\n";
const ld pi=3.14159265358979323846;

struct custom_hash {
    

    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31); \
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};

template<class T> bool ckmin(T& a, const T& b) { return b<a ? a=b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a<b ? a=b, 1 : 0; }

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(ld& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vector<A>& x) {
	EACH(a, x) read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x) read(a); 
}










template<typename T>
bool f(T x, T y) {
    return x>y;
}  


template<typename A, typename B>
ll count(A vec, B ele, bool isSorted) {
    if (isSorted) {
        auto it1=upper_bound(vec.begin(), vec.end(), ele);
        auto it2=lower_bound(vec.begin(), vec.end(), ele);
        return it1-it2;
    }
    return count(vec.begin(), vec.end(), ele);
}

template <typename A> 
A myMax(A a,A b) {
if (a>b) return a;
return b;
}

template <typename A, typename ... Args>
A myMax(A a, A b, Args ...args) {
return myMax(myMax(a,b), args...);
}

template <typename A> 
A myMin(A a,A b) {
if (a<b) return a;
return b;
}

template <typename A, typename ... Args>
A myMin(A a, A b, Args ...args) {
return myMin(myMin(a, b), args...);
}

template<typename A, typename B>
void printMap(map<A, B> mapp) {
    for (auto ele : mapp) cout << ele.first << " : " << ele.second << '\n';
}

template<typename A, typename B>
void printUmap(umap<A, B> mapp) {
    for (auto ele : mapp) cout << ele.first << " : " << ele.second << '\n';
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}



string strMap(ll i, ll j) { return to_string(i)+":"+to_string(j); }



ll modExp(ll b, ll p) {
    

    ll res=1;
    b=b%MOD;
    if (b==0) return 0;
    while (p>0) {
        if (p&1) res=(res*b)%MOD;
        p=p>>1;
        b=(b*b)%MOD;
    }
    return res;
}



ll createPalindrome(ll input, ll b, bool isOdd) {
    ll n=input;
    ll palin=input;
    if (isOdd) n/=b;
    while (n>0) {
        palin=palin*b+(n%b);
        n/=b;
    }
    return palin;
}



void generatePalindromes(ll n) {
    ll number;
    

    for (ll j=0; j<2; j++) {
        ll i=1;
        while ((number=createPalindrome(i, 10, j%2))<n) {
            cout << number << " ";
            i++;
        }
    }
}



ll MAXN=1e6+1;
vl SPF(MAXN);
void spf() { 
    

    

    SPF[1]=1;
    fo(i, 2, MAXN) SPF[i]=i;
    for (ll i=4; i<MAXN; i+=2) SPF[i]=2;
    for (ll i=3; i*i<MAXN; i++) {
        if (SPF[i]==i) {
            for (ll j=i*i; j<MAXN; j+=i) if (SPF[j]==j) SPF[j]=i;
        }
    }
}



bool isPowerofTwo(ll n) {
    if (n==0) return 0;
    if ((n&(~(n-1)))==n) return 1;
    return 0;
}



ll modDiv(ll num, ll den) {
    

    ll inv=(ll)pow(den, MOD-2);
    return ((num%MOD)*(inv%MOD))%MOD;
}



ll fact(ll n) {
    if (n==0) return 1;
    ll ans=n;
    for (ll i=n-1; i>=1; --i) ans=ans*i;
    return ans;
}



ll nc2(ll n) { return (n*(n-1))/2; }



ll nc3(ll n) { return (n*(n-1)*(n-2))/6; } 



ll bin_search(vl vec, ll no) {
    

    ll n=vec.size();
    ll i=0, j=vec.size();
    ll ele, ele2;
    if (vec[0]>=no) return vec[0];
    if (vec.back()<no) return -1;
    while (i<=j) {
        ll mid=(i+j)/2;
        ll el=vec[mid];
        if (mid-1<n && el>=no && vec[mid-1]<no) {
            ele=vec[mid];
            ele2=vec[mid-1];
            break;
        } else if (el<no) i=mid+1;
        else j=mid-1;
    }
    return ele;
}



ll bin_search(ll l, ll r) {
    

    while (l<=r) {
        ll mid=((l+r)/2);
        

        bool condition;
        if (condition) {  

            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    return l;
}



vl primeFactors(ll n) {
    

    

    vl ans;
    while (!(n&1)) {        
        ans.pb(2);
        n=n/2;
    }
    for (ll i=3; i<=(ll)round(sqrt(n)); i=i+2) {            
        while (n%i==0) {
            ans.pb(i);
            n=n/i;
        }
    }        
    if (n>2) ans.pb(n);
    return ans;
}



vl factors(ll n) {
    

    vl ans;
    for (ll i=1; i<=(ll)round(sqrt(n)); i++) {
        if (n%i==0) {
            if (n/i==i) ans.pb(i);
            else {
                ans.pb(i); 
                ans.pb(n/i);
            }
        }
    }
    return ans;
}



ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }



template<typename A>
A prefixSums(A vec) {
    

    

    ll n=sz(vec);
    A ans(n+1);
    ans[0]=0;
    ans[1]=vec[0];
    fo(i, 2, n+1) ans[i]=ans[i-1]+vec[i-1];
    return ans;
}



ll kthbit(ll n, ll k) {
    

    return (n>>(k-1))&1;
}



bool isPrime(ll n) {
    vl primes=primeFactors(n);
    if (sz(primes)==1) return true;
    return false;
}



bool isSubSequence(string s1, string s2) {
    ll j=0;
    ll m=sz(s1), n=sz(s2);
    for (ll i=0; i<n && j<m; i++) if (s1[j]==s2[i]) j++;
    return (j==m);
}



ll nearestPowerOf2(ll n) {  
    return (1<<(63-__builtin_clzll(n)));
}



void toUpper(string &s) {
    transform(all(s), s.begin(), ::toupper);
}



void toLower(string &s) {
    transform(all(s), s.begin(), ::tolower);
}



vl sieveOfEratosthenes(ll n) {
    

    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (ll p=2; p*p<=n; p++) {
        if (prime[p]==true) {
            for (ll i=p*p; i<=n; i+=p) prime[i]=false;
        }
    }
    vl ans;
    for (int p=2; p<=n; p++) if (prime[p]) ans.pb(p);
    return ans;
}



vc segmentedSieve(ll L, ll R) {
    

    

    ll lim = sqrt(R);
    vb mark(lim+1, false);
    vl primes;
    fo(i, 2, lim+1) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j=i*i; j<=lim; j+=i) mark[j]=true;
        }
    }
    vc isPrime(R-L+1, true);
    EACH(i, primes) for (ll j=max(i*i, (L+i-1)/i*i); j<=R; j+=i) isPrime[j-L]=false;
    if (L==1) isPrime[0]=false;
    return isPrime;
}



vl maxIntersectingPt(vl start, vl end) {
    

    

    ll n=sz(start);
    sort(all(start));
    sort(all(end));
    ll guests_in=1, max_guests=1, time=start[0];
    ll i=1, j=0;
    while (i<n && j<n) {
        if (start[i]<=end[j]) {
            guests_in++;
            if (guests_in>max_guests) {
                max_guests=guests_in;
                time=start[i];
            }
            i++;  
        }
        else {
            guests_in--;
            j++;
        }
    }
    return {time, max_guests};
}



ll LongestNonDecreasingSubsequenceLength(vl v) {
    

    if (sz(v) == 0) return 0;
    vl tail(sz(v), 0);
    ll length=1;
    tail[0]=v[0];
    for (ll i=1; i<sz(v); i++) {
        auto b=tail.begin(), e=tail.begin()+length;

        

        auto it=upper_bound(b, e, v[i]);

        if (it==tail.begin()+length) tail[length++]=v[i];
        else *it=v[i];
    }
    return length;
}



ll minSwapsToSort(vl arr) {
    

    ll ans=0;
    vl temp=arr;    
    map<ll, ll> h;
    sort(all(temp));
    ll n=sz(arr);
    fo(i, 0, n) h[arr[i]]=i;
    fo(i, 0, n) {
        if (arr[i]!=temp[i]) {
        ans++;
        ll init=arr[i];
        swap(arr[i], arr[h[temp[i]]]);
        h[init]=h[temp[i]];
        h[temp[i]]=i;
        }
    }
    return ans;
}



bool isPal(string &s) {
    ll n=sz(s);
    bool ok=true;
    fo(i, 0, sz(s)/2) {
        if (s[i]!=s[n-i-1]) {
            ok=false; break;
        }
    }
    return ok;
}



ll minimizeMaxSubarraySum(vl& arr, ll K) {
    

    ll n=sz(arr);
    ll start=*max_element(all(arr));
    ll end=0;
    fo(i, 0, n) end+=arr[i];   
    ll answer=0;
    while (start<=end) {
        ll mid=(start+end)/2;
        bool flag;
        int count=0;
        int sum=0;
        fo(i, 0, n) {
            if (arr[i]>mid) flag=false;
            sum+=arr[i];
            if (sum>mid) {
                count++;
                sum=arr[i];
            }
        }
        count++;
        if (flag) {
            if (count<=K) flag=true;
            else flag=false;
        }
        if (flag) {
            answer=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return answer;
}








void solve();



































































































































































































































ll query() {
    cout << "? ";
    return 1;
}
void print_ans() {
    cout << "! ";

}
bool dp[101][10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15) << fixed;
    ll TT=1; 
    read(TT);
    while (TT--) {
        

        ll n; read(n);
        vl a(n); read(a);
        vl b(n); read(b);
        ll ans=0;
        ll sqSum=0, tot=0;;
        fo(i, 0, n) {
            sqSum+=a[i]*a[i]+b[i]*b[i];
            tot+=a[i]+b[i];
        }   
        ans+=(n-2)*sqSum;
        fo(i, 0, 101) {
            fo(j, 0, 1e4+1) {
                dp[i][j]=false;
            }
        }
        dp[1][a[0]]=true;
        dp[1][b[0]]=true;
        fo(i, 2, n+1) {
            fo(j, 1, 1e4+1) {
                ll sum=j;
                dp[i][j]=(dp[i-1][j-a[i-1]] || dp[i-1][j-b[i-1]]);
            }
        }
        ll ansi=LLONG_MAX;
        fo(j, 1, 1e4+1) {
            if (dp[n][j]) {
                ll sum=j;
                ansi=min(ansi, (n-2)*sqSum+tot*tot-2*sum*(tot-sum));
            }
        }
        if (ansi==LLONG_MAX) {
            cout << "0\n"; continue;
        }
        cout << ansi << nl;
    }
}

void solve() {
    
} 




























