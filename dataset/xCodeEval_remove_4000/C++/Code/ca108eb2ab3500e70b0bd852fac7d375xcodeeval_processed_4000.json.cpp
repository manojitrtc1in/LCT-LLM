    
    
    using namespace std;



    


    
    
    
    
    
    
    

    


    


    typedef long long ll;
    typedef unsigned long long ull;
    typedef string str;
    typedef vector<int> vecint;
    typedef vector<string> vecstr;
    typedef map<int,int> mint;
    typedef pair<int,int> pairint;

    void init_code(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    }
    


    void print(){cout<<"\n";return;}
    void print(int  i){cout<<i<<"\n";return;}
    void print(str  i){cout<<i<<"\n";return;}
    void print(float  i){cout<<i<<"\n";return;}
    void print(char  i){cout<<i<<"\n";return;}
    void print(ll  i){cout<<i<<"\n";return;}
    void print(int i,str s){cout<<i<<s;return;}
    void print(str s,int i){cout<<s<<" "<<i<<endl;return;}
    void print(int i,int s){cout<<i<<" "<<s<<endl;return;}
    void print(int i,int s,int j){cout<<i<<" "<<s<<" "<<j<<endl;return;}
    void print(int i,int s,int j,int k){cout<<i<<" "<<s<<" "<<j<<" "<<k<<endl;return;}
    void print(str i,int s,int j){cout<<i<<" "<<s<<" "<<j<<endl;return;}
    void print(int i,int s,str j){cout<<i<<" "<<s<<" "<<j<<endl;return;}
    void print(int i,str s,int j){cout<<i<<" "<<s<<" "<<j<<endl;return;}
    void print(str i,str s){cout<<i<<" "<<s;return;}
    void print(float i,str s){cout<<i<<s;return;}
    void print(char i,str s){cout<<i<<s;return;}
    void print(ll i,str s){cout<<i<<s;return;}
    void printvec(vector<int> (&v)){for (auto &&i : v){cout<<i<<" "; }cout<<"\n";return;}
    void printvec(vector<float> (&v)){for (auto &&i : v){cout<<i<<" "; }cout<<"\n";return;}
    void printvec(vector<ll> (&v)){for (auto &&i : v){cout<<i<<" "; }cout<<"\n";return;}
    void printvec(vector<char> (&v)){for (auto &&i : v){cout<<i<<" "; }cout<<"\n";return;}
    void printvec(vector<str> (&v)){for (auto &&i : v){cout<<i<<" "; }cout<<"\n";return;}
    void printset(set<int> &s){for(auto i: s){print(i," ");}print();}
    void printset(set<str> &s){for(auto i: s){print(i," ");}print();}
    void printset(set<ll> &s){for(auto i: s){print(i," ");}print();}
    void printset(multiset<int> &s){for(auto i: s){print(i," ");}print();}
    void printset(multiset<str> &s){for(auto i: s){print(i," ");}print();}
    void printset(multiset<ll> &s){for(auto i: s){print(i," ");}print();}
    void printmap(map<int,int> &m){for(auto i:m){cout<<i.first<<" "<<i.second<<"\n";}}
    void printmap(map<int,str> &m){for(auto i:m){cout<<i.first<<" "<<i.second<<"\n";}}
    void printmap(map<str,int> &m){for(auto i:m){cout<<i.first<<" "<<i.second<<"\n";}}
    void printvp(vector<pairint> &vp) {for(auto i:vp) print(i.first,i.second); return;}
    void id1(vector<vector<int>> &v){for(auto i: v){for(auto j:i){print(j," ");}print();}}
    void id1(vector<vector<str>> &v){for(auto i: v){for(auto j:i){print(j," ");}print();}}
    void id1(vector<vector<char>> &v){for(auto i: v){for(auto j:i){print(j," ");}print();}}


    


    void input(int &n){cin>>n;return;}
    void input(int &n,int &k){cin>>n>>k;return;}
    void input(ll &n,ll &k){cin>>n>>k;return;}
    void input(int &n,int &k,int &v2){cin>>n>>k>>v2;return;}
    void input(int &n,int &k,int &v2, int &v3){cin>>n>>k>>v2>>v3;return;}
    void input(ll &n,ll &k,ll &v2, ll &v3){cin>>n>>k>>v2>>v3;return;}
    void input(ll &n,ll &k,ll &v2){cin>>n>>k>>v2;return;}
    void input(str &n){cin>>n;return;}
    void input(float &n){cin>>n;return;}
    void input(char &n){cin>>n;return;}
    void input(ll &n){cin>>n;return;}
    void inputvec(vector<int> &v, int n){for(int i=0;i<n;i++){int temp;cin>>temp;v.push_back(temp);}return;}
    void inputvec(vector<str> &v, int n){for(int i=0;i<n;i++){str temp;cin>>temp;v.push_back(temp);}return;}
    void inputvec(vector<ll> &v, int n){for(int i=0;i<n;i++){ll temp;cin>>temp;v.push_back(temp);}return;}
    void inputvec(vector<float> &v, int n){for(int i=0;i<n;i++){ll temp;cin>>temp;v.push_back(temp);}return;}
    void inputvec(vector<ll> &v, ll n){for(int i=0;i<n;i++){ll temp;cin>>temp;v.push_back(temp);}return;}

    ll c=1;
    void Case(){cout<<"Case 

    ll max(ll a,ll b ){if(a>b){return a; }else{return b;}}

    ll min(ll a,ll b ){if(a<b){return a; }else{return b;}}
    pairint max(vecint &v){int ma=v[0]; int ind=0;loop(i,0,v.size()){if(v[i]>ma){ma=v[i];ind=i;}}pairint p={ma,ind};return (p);}
    pairint max(vecint &v,int m,int n){ int ma=v[m]; int ind=m; loop(i,m,n){ if(v[i]>ma){ma=v[i];ind=i; }}pairint p={ma,ind};return (p);}
    pairint min(vecint &v){int mi=v[0]; int ind=0;loop(i,0,v.size()){if(v[i]<mi){mi=v[i];ind=i;}}pairint p={mi,ind};return (p);}
    pairint min(vecint &v,int m,int n){ int mi=v[m]; int ind=m; loop(i,m,n){ if(v[i]<mi){mi=v[i];ind=i; }}pairint p={mi,ind};return (p);}
    int indexof(vecint v,int n,int ct=1){ loop(i,0,v.size()){ if(v[i]==n){ct--;if(ct==0){ return i; } } } return -1;}
    int indexof(str s,char n,int ct=1){ loop(i,0,s.size()){ if(s[i]==n){ct--;if(ct==0){ return i; } } } return -1; }
    int countof(vecint v,int n){ int ct=0; loop(i,0,v.size()){  if(v[i]==n){ ct++;  } } return ct;}
    int countof(str v,char n){ int ct=0; loop(i,0,v.size()){  if(v[i]==n){ ct++;  } } return ct;}
    str dtob(ll n){
       str ans="";
       int i=0;
       while (i<33)
       {
            i++;   
           ans+=char((n&1)+'0');
           n>>=1;
       }
       return ans;
       
    }
   


    ll btod(str v){
        
        ll sum=0;
        ll k=1;
        for(char i:v){
            if(i=='1') sum+=k;
            k<<=1;
        }
        return sum;
    }
  
    vecint divisor(int n){
        vecint v;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                v.push_back(i);
            }
        }
        v.push_back(n);
        return v;
    }
    


    ll isPrime(ll n){
        ll i;

        if (n==2)
            return 1;

        if (n%2==0 || n==1)
            return 0;

        for (i=3;i<=sqrt(n);i+=2)
            if (n%i==0)
                return 0;

        return 1;
    }


    ll power(ll n, ll x){
        ll ans=1;
        ll a=n;
        while (x>0)
        {
            if(x&1){
                ans*=a;
            }
            a=a*a;
            x>>=1;
        }
        return ans;
        
        
    }
  
    

    

    

    

    

    

    

    

    

    

    

    

    
    

    

    

    

    

    

    

    

    

    


    

    

    class Graph{
        public:

            map<int,int> G,size;
        

    void makeNode(int p){
        G[p]=p;
        size[p]=1;
    }

    int find(int a){
        if(G[a]==a) return a;
        else return (find(G[a]));
    }

    void Union(int a,int b){
        if(find(a)==find(b)) return;
        else{
            if(size[find(a)]>size[find(b)]) swap(a,b);
            G[find(a)]=find(b);
            size[find(b)]=size[find(a)]+size[find(b)];
        }
    }

    };

  
    bool parity(int a,int b) {return ((a+b)%2==0);}
    ll gcd(ll a, ll b) {
    if (b == 0)
    return a;
    return gcd(b, a % b);
    }
    long long lcm(ll a, ll b)
    {
        return (a / gcd(a, b)) * b;
    }


        bool isup(int n,int m,int i,int j){
            if(i>0) return true;
            else return false;
        }
        bool isdown(int n,int m,int i,int j){
            if(i<n-1) return true;
            else return false;
        }
        bool isleft(int n,int m,int i,int j){
            if(j>0) return true;
            else return false;
        }
        bool isright(int n,int m,int i,int j){
            if(j<m-1) return true;
            else return false;
        }
    void id0(vector<vector<int>> &vc,int i ,int j,string s,int k,ll &ans,vector<int> dir){
        
                ans+=vc[i][j];
            
                if(dir[1]==1){
                    if(isup(vc.size(),vc[0].size(),i,j) && isright(vc.size(),vc[0].size(),i,j)){
                        id0(vc,i-1,j+1,s,k+1,ans,{0,1,0,0,0,0,0,0});
                    }
                }
            
                if(dir[3]==1){
                    if(isright(vc.size(),vc[0].size(),i,j) && isdown(vc.size(),vc[0].size(),i,j)){
                        id0(vc,i+1,j+1,s,k+1,ans,{0,0,0,1,0,0,0,0});
                    }
                }
            
                if(dir[5]==1){
                    if(isdown(vc.size(),vc[0].size(),i,j)&&isleft(vc.size(),vc[0].size(),i,j)){
                        id0(vc,i+1,j-1,s,k+1,ans,{0,0,0,0,0,1,0,0});
                    }
                }
            
                if(dir[7]==1){
                    if(isup(vc.size(),vc[0].size(),i,j) && isleft(vc.size(),vc[0].size(),i,j)){
                        id0(vc,i-1,j-1,s,k+1,ans,{0,0,0,0,0,0,0,1});
                    }
                
            }
        
        }

    ll mod(ll a, ll b){
        if(a>0){
            return a%b;
        }
        else if(a==0) {
            return 0;
        }
        else{
            return (b-(abs(a)%b));
        }
    }
 
 
int  children(vector<vecint>&adj,int i,vecint &mp,vecint &vis){
    if(vis[i]==1) return -1;
    vis[i]=1;
    int s=0;
    for(auto j:adj[i]){
        s+=1+children(adj,j,mp,vis);
    }
    mp[i]=s;
    return s;


}

ll add(vector<pair<ll,ll>> &path,int a,int b,int c,int d){
    ll ans=0;
    if(a!=c){
        ans+=abs(a-c);
        path.push_back({a,b});
        path.push_back({c,b});
        a=c;
    }
    if(b!=d){
        ans+=abs(d-b);
        path.push_back({a,b});
        path.push_back({a,d});
        b=d;
    }
    return ans;
}


    void soln(){

    


    vector<ll> v1,v2,v3;
    inputvec(v1,2);
    inputvec(v2,2);
    inputvec(v3,2);

    vector<vector<ll>> v;
    vector<pair<ll,ll>> ans;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    sort(v.begin(),v.end());
    v1=v[0];
    v2=v[1];
    v3=v[2];
    if(v1[1]<=v2[1] && v1[1]<=v3[1]){
        if(v2[1]<v3[1]){
            add(ans,v1[0],v1[1],v2[0],v2[1]);
            add(ans,v2[0],v2[1],v3[0],v3[1]);
        }
        else{
            add(ans,v1[0],v1[1],v2[0],v3[1]);
            add(ans,v2[0],v3[1],v2[0],v2[1]);
            add(ans,v2[0],v3[1],v3[0],v3[1]);
        }
    }
    else if(v2[1]<=v1[1] && v2[1]<=v3[1]){
        if(v1[1]<v3[1]){
            add(ans,v1[0],v1[1],v2[0],v1[1]);
            add(ans,v2[0],v1[1],v2[0],v2[1]);
            add(ans,v2[0],v1[1],v3[0],v3[1]);
        }
        else{
            add(ans,v1[0],v1[1],v2[0],v3[1]);
            add(ans,v2[0],v3[1],v2[0],v2[1]);
            add(ans,v2[0],v3[1],v3[0],v3[1]);
        }
    }
    else if(v3[1]<=v1[1] && v3[1]<=v2[1]){
        if(v1[1]<v2[1]){
            add(ans,v1[0],v1[1],v2[0],v1[1]);
            add(ans,v2[0],v1[1],v2[0],v2[1]);
            add(ans,v2[0],v1[1],v3[0],v3[1]);
        }
        else{
            add(ans,v1[0],v1[1],v2[0],v2[1]);
            add(ans,v2[0],v2[1],v3[0],v3[1]);
        }
    }
    int h=ans.size()/2;
    print(h);
    for(int i=0;i<ans.size();i+=2){
        cout<<ans[i].first<<" "<<ans[i].second<<" "<<ans[i+1].first<<" "<<ans[i+1].second<<"\n";
    }


    



        return;
    }


    int main(){
    init_code();

        int t;
    
    

    t=1;

        while (t>0)
        {
        

         soln();
           
            t--;
        }
    
    
        return 0;
    }