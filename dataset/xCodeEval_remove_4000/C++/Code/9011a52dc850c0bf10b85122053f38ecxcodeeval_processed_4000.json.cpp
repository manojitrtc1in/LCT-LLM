




using namespace std;









 









typedef long long ll;






















const long long inf=id2;
const double pi=3.14159265358979323846264338327950288419716939937510;
const ll mod=1e9 + 7;
const ll mod2=998244353; 

const double eps=(0.00000000001);





 
template<typename T>
void __p(T a) {
    cout<<a;
}

template<typename T, typename F>
void __p(pair<T, F> a) {
    cout<<"{";
    __p(a.first);
    cout<<",";
    __p(a.second);
    cout<<"}";
}

template<typename T>
void __p(std::vector<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it<a.end(); it++)
        __p(*it),cout<<",}"[it+1==a.end()];
}

template<typename T>
void __p(std::set<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it); 
        cout<<",}"[++it==a.end()];
    }
 
}

template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}

template<typename T, typename F>
void __p(std::map<T,F> a) {
    cout<<"{\n";
    for(auto it=a.begin(); it!=a.end();++it)
    {
        __p(it->first);
        cout << ": ";
        __p(it->second);
        cout<<"\n";
    }
    cout << "}\n";
}

template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
    __p(a1);
    __p(a...);
}

template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";
    __p(arg1);
    cout<<endl;
}

template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(;; i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<" | ";
    __f(comma+1,args...);
}












ll gcd(ll a,ll b){

    if(b==0) return a;

    a%=b;
    return gcd(b,a);
}

ll modInverse(ll a,ll m){
    


    if(gcd(a,m)!=1) return id4;

    ll m0=m;
    ll y=0;
    ll x=1;

    if(m==1) return 0;

    while(a>1){
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;

        y=x-q*y;
        x=t;
    }

    if(x<0) x+=m0;

    return x;
}

ll nCr(ll n, ll r){

    if(r>n) return 0;

    if(r>n-r) r=n-r;

    ll ans=1;

    rep(i,1,r+1){
        ans*=(n-i+1);   
    }

    rep(i,1,r+1) ans/=i;

    return ans;
}

ll lcm(ll a,ll b){
    return (a/gcd(a,b))*b;
}

ll id5(ll a,ll b) {

    if(b==0) return 1;
    if(b==1) return a%mod;

    ll res=id5(a,b/2)%mod;

    if (b%2==1) return (((res*res)%mod)*a)%mod;
    else return (res*res)%mod;

}



ll binpow(ll a,ll b) {

    if(b==0) return 1;
    if(b==1) return a;

    ll res=binpow(a,b/2);

    if (b%2==1) return (((res*res))*a);
    else return (res*res);
}

vector<bool> sieve(ll n){
    vector<bool> isPrime(n+1,true);

    isPrime[0]=false;
    isPrime[1]=false;

    rep(i,2,1+(ll)(sqrt(n))){
        if(isPrime[i]){
            rep(j,i*i,1+n){
                isPrime[j]=false;

                j--;
                j+=i;
            }
        }
    }

    return isPrime;
}

ll phi(ll n){
    ll ans=n;

    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            ans-=ans/i;
        }
    }

    if(n>1) ans-=ans/n;

    return ans;
}

vector<ll> id0(ll n){
    vector<ll> phi(n+1);

    phi[0]=0;
    phi[1]=1;

    rep(i,2,n+1) phi[i]=i;

    rep(i,2,n+1){
        if(phi[i]==i){
            for(ll j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
        }
    }

    return phi;
}

ll binary_search(ll arr[],ll n,ll elem) {
    


    ll l=0,r=n-1;

    while (r>=l){

        ll mid=(l+r)/2;

        if(arr[mid]>elem) r=mid-1;
        else if(arr[mid]<elem) l=mid+1;
        else return mid;

    }

    return -1;
}

ll id8(vector<ll> &arr,ll elem) {

    ll n=arr.size();
    ll l=0,r=n-1;

    while (r>=l){

        ll mid=(l+r)/2;

        if(arr[mid]>elem) r=mid-1;
        else if(arr[mid]<elem) l=mid+1;
        else return mid;

    }

    return -1;
}



bool checkPrime(ll n){
    ll count=0;

    rep(i,2,1+(ll)sqrt(n)) if(n%i==0) count++;

    if(count>0) return false;
    else return true;

}

ll id7(ll n,map<ll,ll>& m){
    if(m.count(n)) return m[n];

    ll k=n/2;

    if(n%2==0) return m[n]=(id7(k,m)*id7(k,m) + id7(k-1,m)*id7(k-1,m))%mod;
    else return m[n]=(id7(k,m)*id7(k+1,m) + id7(k-1,m)*id7(k,m))%mod;
}

ll fibonacci(ll n){
    


    

    map<ll,ll> m;
    m[0]=1;
    m[1]=1;

    if(n==0) return 0;
    else return id7(n-1,m);
}



ll factorial(ll n){
    ll res=1;
    rep(i,2,n+1) res*=i;

    return res;
}

ll id9(ll n){
    ll res=1;
    rep(i,2,n+1) res=(res*i)%mod;

    return res%mod;
}

void bfs(vector<ll> adj[],ll curr,vector<bool>& visited){

    queue<ll> q;
    q.push(curr);

    while(!q.empty()){
        ll temp=q.front();
        q.pop();

        visited[temp]=true;

        rep(i,0,adj[temp].size()){
            if(!visited[adj[temp][i]]){
                q.push(adj[temp][i]);
                visited[adj[temp][i]]=true;
            }
        }

    }

    return;

}

void dfs(vector<ll> adj[],ll curr,vector<bool>& visited){

    if(visited[curr]) return;
 
    visited[curr]=true;

    

 
    rep(i,0,adj[curr].size()){
        dfs(adj,adj[curr][i],visited);
    }
 
    return;

}

void dfs1(vector<ll> adj[],ll curr,vector<ll> &state,vector<ll> &ans){

    if(state[curr]==2) return;

    state[curr]=1;

    rep(i,0,adj[curr].size()){
        dfs1(adj,adj[curr][i],state,ans);
    }

    state[curr]=2;
    ans.push_back(curr);

    return;

}

vector<ll> id3(vector<ll> adj[],ll n){

    vector<ll> ans;
    ans.clear();

    vector<ll> state(n+1,0);

    rep(i,1,n+1){
        if(state[i]==0) dfs1(adj,i,state,ans);
    }

    rep(i,0,ans.size()/2) swap(ans[i],ans[ans.size()-1-i]);

    return ans;

}

ll divCount(ll n){

    ll ans=0;

    rep(i,1,1+(int)(sqrt(n))) if(n%i==0) ans++;

    ans*=2;

    if((int)(sqrt(n))*(int)(sqrt(n))==n) ans--;

    return ans;

}



ll id6(ll n){
    

    

    


    ll ans=nCr(2*n,n);

    return ans/(n+1);
}

vector<ll> id1(ll n){
    vector<ll> ans;
    ans.clear();

    vector<ll> temp1;
    temp1.clear();

    vector<ll> temp2;
    temp2.clear();

    rep(i,1,1+(int)(sqrt(n))){
        if(n%i==0){
            if(n/i==i){
                temp1.push_back(i);
            } else {
                temp1.push_back(i);
                temp2.push_back(n/i);
            }
        }
    }

    rep(i,0,temp1.size()) ans.push_back(temp1[i]);
    rrep(i,temp2.size()-1,0) ans.push_back(temp2[i]);

    return ans;

}

vector<ll> zArray(string str){

    ll n=str.length();

    vector<ll> ans(n,0);

    ll x=0;
    ll y=0;

    rep(i,1,n){
        ans[i]=max(0LL,min(ans[i-x],y-i+1));

        while(i+ans[i]<n && str[ans[i]]==str[i+ans[i]]){
            x=i;
            y=i+ans[i];
            ans[i]++;
        }
    }

    return ans;

}

ll lis(ll arr[],ll n){

    vector<ll> ans;
    ans.clear();

    rep(i,0,n){
        

        vector<ll>::iterator it=lower_bound(ans.begin(), ans.end(), arr[i]); 


        if(it==ans.end()) ans.push_back(arr[i]);
        else *it=arr[i];
    }

    return ans.size();

}



bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second<b.second) return true;
    else return false;
}

ll maxDigit(ll n){
    ll maxi=id4;

    while(n>0){
        maxi=max(maxi,n%10);
        n/=10;
    }

    return maxi;
}

ll getLength(ll n){
    ll len=0;

    while(n>0){
        len++;
        n/=10;
    }

    return len;
}

signed main(){
    
    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));

    read(t);

    


    for(ll tc=1;tc<=t;tc++){

    read(n);
    readarray(arr,n);

    set<ll> s;
    s.insert(arr[0]);

    ll ans=0;

    rep(i,1,n){
        if(s.upper_bound(arr[i])!=s.end()){
            ans++;
            s.clear();
        } else s.insert(arr[i]);
    }

    cout<<ans<<endl;

    

























    
























    



































    }
    
    return 0;

}

