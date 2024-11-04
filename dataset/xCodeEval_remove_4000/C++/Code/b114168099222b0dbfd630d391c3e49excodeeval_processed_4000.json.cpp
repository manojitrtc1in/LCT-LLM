
using namespace std;








































char A=65, Z=90, lowerA=97, lowerZ=122;
string YES="YES\n", NO="NO\n";
const double PI=3.14159265358979323846;
const double epsilon=0.000000000001;
struct custom_hash {
    

    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31); \
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t id7 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+id7);
    }
};

template<class T> bool ckmin(T& a, const T& b) { return b<a ? a=b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a<b ? a=b, 1 : 0; }

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) { cin >> x; }
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vector<A>& x) { EACH(a, x) read(a); }
template<class A, size_t S> void read(array<A, S>& x) { EACH(a, x) read(a); }









template<typename T>
bool f(T x, T y) { return x>y; }  


template<typename A, typename B>
int count(A vec, B ele, bool isSorted) {
    if(isSorted) {
        auto it1=upper_bound(vec.begin(), vec.end(), ele);
        auto it2=lower_bound(vec.begin(), vec.end(), ele); 

        return it1-it2;
    }
    return count(vec.begin(), vec.end(), ele);
}

template <typename A> 
A myMax(A a,A b) {
if(a>b) return a;
return b;
}
template <typename A, typename ... Args>
A myMax(A a, A b, Args ...args) { return myMax(myMax(a,b), args...); }
template <typename A> 
A myMin(A a,A b) {
if(a<b) return a;
return b;
}
template <typename A, typename ... Args>
A myMin(A a, A b, Args ...args) { return myMin(myMin(a, b), args...); }

template<typename A, typename B>
void printMap(map<A, B> mapp) { for(auto ele : mapp) cout << ele.first << " : " << ele.second << '\n'; }
template<typename A, typename B>
void id20(umap<A, B> mapp) { for(auto ele : mapp) cout << ele.first << " : " << ele.second << '\n'; }

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }



string strMap(int i, int j) { return to_string(i)+":"+to_string(j); }



int modExp(int b, int p) {
    

    int res=1;
    b=b%MOD;
    if(b==0) return 0;
    while(p>0) {
        if(p&1) res=(res*b)%MOD;
        p=p>>1;
        b=(b*b)%MOD;
    }
    return res;
}



int createPalindrome(int input, int b, bool isOdd) {
    int n=input;
    int palin=input;
    if(isOdd) n/=b;
    while(n>0) {
        palin=palin*b+(n%b);
        n/=b;
    }
    return palin;
}



void id3(int n) {
    int number;
    

    for(int j=0; j<2; j++) {
        int i=1;
        while((number=createPalindrome(i, 10, j%2))<n) {
            cout << number << " ";
            i++;
        }
    }
}



int MAXN=1e6+1;
vi SPF(MAXN);
void spf() { 
    

    

    SPF[1]=1;
    fo(i, 2, MAXN) SPF[i]=i;
    for(int i=4; i<MAXN; i+=2) SPF[i]=2;
    for(int i=3; i*i<MAXN; i++) if(SPF[i]==i) for(int j=i*i; j<MAXN; j+=i) if(SPF[j]==j) SPF[j]=i;
}



bool id1(int n) {
    if(n==0) return 0;
    if((n&(~(n-1)))==n) return 1;
    return 0;
}



int modDiv(int x) { 
    

    int res=1, y=MOD-2; 
    x=x%MOD;
    while(y>0) {
        if(y&1) res=(res*x)%MOD;
        y=y>>1; 
        x=(x*x)%MOD;
    }
    return res;
}



int fact(int n) {
    if(n==0) return 1;
    int ans=n;
    for(int i=n-1; i>=1; --i) ans=ans*i;
    return ans;
}



int nc2(int n) { return (n*(n-1))/2; }



int nc3(int n) { return (n*(n-1)*(n-2))/6; } 



int bin_search(vi &vec, int no) {
    

    int n=vec.size();
    if(n==1) return -1;
    int i=0, j=vec.size()-1;  

    int ele, ele2;
    if(vec[0]>=no) return vec[0];
    if(vec.back()<no) return -1;
    while(i<=j) {
        int mid=(i+j)/2;
        int el=vec[mid];
        if(mid-1<n&&el>=no&&vec[mid-1]<no) {
            ele=vec[mid];
            ele2=vec[mid-1];
            break;
        } else if(el<no) i=mid+1;
        else j=mid-1;
    }
    return ele;
}



int bin_search(int l, int r) {
    

    while(l<=r) {
        int mid=(l+r)/2;
        

        bool condition;
        

        if(condition) l=mid+1; 
        else r=mid-1;    
    }
    return l;
}



vi primeFactors(int n) {
    

    

    vi ans;
    while(!(n&1)) {        
        ans.pb(2);
        n=n/2;
    }
    for(int i=3; i<=(int)round(sqrt(n)); i=i+2) {            
        while(n%i==0) {
            ans.pb(i);
            n=n/i;
        }
    }        
    if(n>2) ans.pb(n);
    return ans;
}



vi factors(int n) {
    

    vi ans;
    for(int i=1; i<=(int)round(sqrt(n)); i++) {
        if(n%i==0) {
            if(n/i==i) ans.pb(i);
            else {
                ans.pb(i); 
                ans.pb(n/i);
            }
        }
    }
    return ans;
}



int lcm(int a, int b) { return (a*b)/__gcd(a, b); }



template<typename A>
A id9(A vec) {
    

    

    int n=sz(vec);
    A ans(n+1);
    ans[0]=0;
    ans[1]=vec[0];
    fo(i, 2, n+1) ans[i]=ans[i-1]+vec[i-1];
    return ans;
}





int id19(int n, int k) { return (n>>(k-1))&1; }



bool isPrime(int n) {
    

    vi primes=primeFactors(n);
    if(sz(primes)==1) return true;
    return false;
}



bool id14(string s1, string s2) {  
    

    int j=0;
    int m=sz(s1), n=sz(s2);
    for(int i=0; i<n&&j<m; i++) if(s1[j]==s2[i]) j++;
    return j==m;
}



int id16(int n) { return (1<<(63-__builtin_clzll(n))); }



void toUpper(string &s) { transform(all(s), s.begin(), ::toupper); }



void toLower(string &s) { transform(all(s), s.begin(), ::tolower); }



vi id18(int n) {
    

    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=n; p++) if(prime[p]==true) for(int i=p*p; i<=n; i+=p) prime[i]=false;
    vi ans;
    for(int p=2; p<=n; p++) if(prime[p]) ans.pb(p);
    return ans;
}



vb id11(int L, int R) {
    

    

    int lim = sqrt(R);
    vb mark(lim+1, false);
    vi primes;
    fo(i, 2, lim+1) {
        if(!mark[i]) {
            primes.emplace_back(i);
            for(int j=i*i; j<=lim; j+=i) mark[j]=true;
        }
    }
    vb isPrime(R-L+1, true);
    EACH(i, primes) for(int j=max(i*i, (L+i-1)/i*i); j<=R; j+=i) isPrime[j-L]=false;
    if(L==1) isPrime[0]=false;
    return isPrime;
}



vi id21(vi start, vi end) {
    

    

    int n=sz(start);
    sort(all(start));
    sort(all(end));
    int id22=1, id6=1, time=start[0];
    int i=1, j=0;
    while(i<n&&j<n) {
        if(start[i]<=end[j]) {
            id22++;
            if(id22>id6) {
                id6=id22;
                time=start[i];
            }
            i++;  
        }
        else {
            id22--;
            j++;
        }
    }
    return {time, id6};
}



int id12(vi v) {
    

    if(sz(v)==0) return 0;
    vi tail(sz(v), 0);
    int length=1;
    tail[0]=v[0];
    for(int i=1; i<sz(v); i++) {
        auto b=tail.begin(), e=tail.begin()+length;

        

        auto it=upper_bound(b, e, v[i]);

        if(it==tail.begin()+length) tail[length++]=v[i];
        else *it=v[i];
    }
    return length;
}



int id0(vi arr) {
    

    int ans=0;
    vi temp=arr;    
    map<int, int> h;
    sort(all(temp));
    int n=sz(arr);
    fo(i, 0, n) h[arr[i]]=i;
    fo(i, 0, n) {
        if(arr[i]!=temp[i]) {
            ans++;
            int init=arr[i];
            swap(arr[i], arr[h[temp[i]]]);
            h[init]=h[temp[i]];
            h[temp[i]]=i;
        }
    }
    return ans;
}



bool isPal(string &s) {
    int n=sz(s);
    bool ok=true;
    fo(i, 0, sz(s)/2) if(s[i]!=s[n-i-1]) ok=false;
    return ok;
}



int id17(vi& arr, int K) {
    

    

    int n=sz(arr);
    int start=*max_element(all(arr));
    int end=0;
    fo(i, 0, n) end+=arr[i];   
    int answer=0;
    while(start<=end) {
        int mid=(start+end)/2;
        bool flag;
        int count=0;
        int sum=0;
        fo(i, 0, n) {
            if(arr[i]>mid) flag=false;
            sum+=arr[i];
            if(sum>mid) {
                count++;
                sum=arr[i];
            }
        }
        count++;
        if(flag) {
            if(count<=K) flag=true;
            else flag=false;
        }
        if(flag) {
            answer=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return answer;
}



int kadane(vi v) {
    

    int n=sz(v);
    int id2=id23, id4=0;
    fo(i, 0, n) {
        id4=id4+v[i];
        if(id2<id4) id2=id4;
        if(id4<0) id4=0;
    }
    return id2;
}



vi id13(vi arr) {
    

    int n=sz(arr), s=0, e=n-1, i, max, min;    
    for(s=0; s<n-1; s++) if(arr[s]>arr[s+1]) break;
    for(e=n-1; e>0; e--) if(arr[e]<arr[e-1]) break;
    max=arr[s]; min=arr[s];
    for(i=s+1; i<=e; i++) {
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    for(i=0; i<s; i++) {
        if(arr[i]>min) {
            s=i;
            break;
        }    
    }
    for(i=n-1; i>=e+1; i--) {
        if(arr[i]<max) {
            e=i;
            break;
        }
    }
    return {s, e};
}



template <typename A>
vector<vector<A>> id8(vector<vector<A>> arr) {
    int n=sz(arr);
    int m=sz(arr[0]);
    

    int C=sz(arr[0]);
    int R=sz(arr);
    vector<vector<A>> v;
    for(int k=0; k<R; k++) {
        vector<A> temp;
        temp.pb(arr[k][0]);
        int i=k-1;
        int j=1;
        while(!(i<0||i>=R||j>=C||j<0)) {
            temp.pb(arr[i][j]);
            i--;           
            j++;
        }
        v.pb(temp);
    }
    for(int k=1; k<C; k++) {
        vector<A> temp;
        temp.pb(arr[R-1][k]);
        int i=R-2;
        int j=k+1;
        while(!(i<0||i>=R||j>=C||j<0)) {
            temp.pb(arr[i][j]);
            i--;
            j++;
        }
        v.pb(temp);
    }
    return v;
}



int knapsack(int W, vi wt, vi val) {
    

    int n=sz(wt);
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<n+1; i++) for(int w=W; w>=0; w--) if(wt[i-1]<=w) dp[w]=max(dp[w], dp[w-wt[i-1]]+val[i-1]);
    return dp[W]; 
}

template <typename A>
void printArray(A v, string name) {
    cout << name << " ";
    for(auto ele : v) cout << ele << ' ';
    cout << nl;
}



int coinChange(vi S, int n) {        
    

    int m=sz(S);    
    vi table(n+1);
    table[0]=1;         
    for(int i=0; i<m; i++)         
    for(int j=S[i]; j<=n; j++)         
    table[j]=table[j-S[i]]+table[j];        
    return table[n];         
}



bool id24(string expr) { 
    

    stack<char> temp;
    fo(i, 0, expr.length()) {
        if(temp.empty()) temp.push(expr[i]);
        else if((temp.top()=='('&& expr[i]==')')||(temp.top()=='{'&&expr[i]=='}')||  (temp.top()=='['&&expr[i]==']')) temp.pop();
        else temp.push(expr[i]);
    }
    if(temp.empty()) return true;
    return false;
}



int id10(int n, int r) {
    

    if (n<r) return 0;
    if(r==0) return 1;
    vi fac(n+1, 1);
    fo(i, 1, n+1) fac[i]=(fac[i-1]*i)%MOD;    
    return (fac[n]*modDiv(fac[r])%MOD*modDiv(fac[n-r])%MOD)%MOD; 

}



void bfs(int s, vvi &adj) { 

    

    deque<int> q;  

    map<int, bool> vis;  

    q.push_back(s);  
    vis[s]=true;
    while(sz(q)) {
        s=q.front();
        q.pop_front();
        for(auto adjacent : adj[s]) {
            if(!vis[adjacent]) {
                vis[adjacent]=true;
                q.pb(adjacent);
            }
        }
    }
}



vi id5(vi arr) {
    

	int n=sz(arr);
    stack<int> s;
    vi res(n);
    for(int i=n-1; i>=0; i--) {
		while(!s.empty()&&s.top()<=arr[i]) s.pop();
        res[i]=s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return res;
}




int sumArray(vi& v) {
    int sum=0;
    for(auto ele : v) sum+=ele;
    return sum;
}

int power(int a, int b) {
    int ele=1;
    fo(i, 1, b+1) ele=((a*ele));
    return ele;
}

int id15(int a) {
    int b=a, x=0, y=0;
    for(int e=(63-__builtin_clzll(a))&~1; e>=0; e-=2) {
        x<<=1;
        y<<=1;
        if(b>=(y|1)<<e) {
            b-=(y|1)<<e;
            x|=1;
            y+=2;
        }
    }
    return x;
}































































































































































































































































void solve() {}

int query(int l, int r) { 
    cout << "? " << l << ' ' << r << endl;
    return 0;
}   
void print_ans() {
    cout << "! ";
}   

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15) << fixed;
    int TT=1; 
    read(TT);
    while(TT--) {
        

        int n, k; read(n, k);
        vi v(n); read(v);
        if(k<=n) {
            int sum=0;
            fo(i, 0, k) sum+=v[i];
            int ans=sum;
            fo(i, k, n) {
                sum+=v[i];
                sum-=v[i-k];
                ans=max(ans, sum);
            }
            ans+=(k*(k-1))/2;
            cout << ans;
        } else {
            int ans=0;
            fo(i, 0, n) ans+=v[i];  
            k-=n;
            ans+=(n*(n-1))/2;
            
            if(k>=n) {
                ans+=(k/n)*(n*n);
                k=k%n;
            }
            ans+=k*n;
            cout << ans;
        }
        cout << nl;
    } 
}







 
