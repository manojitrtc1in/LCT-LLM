    

    

    #include "bits/stdc++.h"
    using namespace std;
    #define deb(x) cout << #x << " " << x << endl;
    

    

    

    

    

    

    

    

    

    #define ld long double
    #define ll long long int
    #define MOD 1000000007
    #define pl pair<ll, ll>
    #define vpl vector<pl>
    #define vvn vector<vector<Node*>>
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
    #define pb push_back
    #define all(a)                          ::begin(a),::end(a)
    #define sz(X) (ll)((X).size())
    #define EACH(x, a) for (auto& x: a)
    #define nl '\n'

    


    #define Fo(i, n) for (ll i=0; i<n; i++)

    #define fo(i, a, b) for (ll i=a; i<b; i++)  

    

    

    


    string YES="YES\n";
    string NO="NO\n";
    const long double pi = 3.14159265358979323846;

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

    

    void make_set(ll v, vl &parent, vl &size) {
        

        parent[v]=v;
        size[v]=1;
    }
    ll find_set(ll v, vl &parent) {
        

        if (v==parent[v]) return v;
        return parent[v]=find_set(parent[v], parent);
    }
    void union_sets(ll a, ll b, vl &parent, vl &size) {
        

        a = find_set(a, parent);
        b = find_set(b, parent);
        if (a!=b) {
            if (size[a]<size[b]) swap(a, b);
            parent[b]=a;
            size[a]+=size[b];
        }
    }

    ll fact(ll n) {
        if (n==0) return 1;
        ll ans=n;
        for (ll i=n-1; i>=1; --i) ans=ans*i;
        return ans;
    }

    ll nc2(ll n) { return (n*(n-1))/2; }

    vl topo(vl jobs, vvl deps) {  

        ll n=sz(jobs);
        umap<ll, vl, chash> adj;  

        umap<ll, ll, chash> in;   

        for (ll i=0; i<sz(deps); ++i) {
            adj[deps[i][0]].push_back(deps[i][1]);  
            in[deps[i][1]]++;
        }
        deque<ll> q; 
        ll count=0;  

        vl ans;
        for (auto job:jobs)	{
            if (in.find(job)==in.end()) {  

                q.push_back(job);
            }
        }
        while (q.size()) {
            count++;  
            ll curr=q.front();
            ans.push_back(curr);
            q.pop_front();
            for (auto ele:adj[curr]) {
                in[ele]--;
                if (in[ele]==0) q.push_back(ele);
            }
        }
        if (count<n) return {};
        return ans;
    }

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

    

    

    

    void solve();
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout << setprecision(15) << fixed;
        ll T=1; 
        read(T);
        while (T--) {
            ll n, k; read(n, k);
            vl vec(n);
            ll cnt=0;
            fo(i, 1, k+1) {
                vec[i-1]=i;
            }
            cnt=k;
            for (ll i=k-1; i>=1; --i) {
                if (cnt!=n) {
                    vec[cnt]=i;
                    cnt++;
                } else break;
            }
            ll dist=vec.end()-max_element(all(vec));
            dist--;
            ll maxi=k;
            vl ans;
            fo(i, 0, 2*k-n-1) {
                ans.pb(i+1);
            }
            fo(i, 2*k-n-1, k) {
                ans.pb(maxi--);
            }
            
            for (auto ele : ans) {
                cout << ele << ' ';
            }
            cout << nl;
        }
    }

    void solve() {
        
    } 