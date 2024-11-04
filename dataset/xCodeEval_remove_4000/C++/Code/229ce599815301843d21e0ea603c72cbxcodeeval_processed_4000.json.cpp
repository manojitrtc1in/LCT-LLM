
using namespace std;












void ppp(int a)          { cerr<<a; }
void ppp(ll a)           { cerr<<a; }
void ppp(long double a)  { cerr<<a; }
void ppp(double a)       { cerr<<a; }
void ppp(char a)         { cerr<<a; }
void ppp(string a)       { cerr<<a; }
void ppp(bool a)         { cerr<<a; } 
template<class T , class V> void ppp(pair<T,V> p) {cerr<<"{"; ppp(p.ff); cerr<<','; ppp(p.ss); cerr<<"}";}
template<class T> void ppp(vector<T> v)  {cerr<<"[ ";for(T x:v) ppp(x), cerr<<" ";cerr<<']';}
template<class T> void ppp(set<T> v){cerr<<"[ ";for(T x:v) ppp(x) , cerr<<" ";cerr<<']';}
template<class T, class V> void ppp(map<T,V> m){cerr<<endl;for(auto x:m){ppp(x.ff);cerr<<" -> ";ppp(x.ss);cerr<<endl;}cerr<<endl;}
template<class T> void ppp(deque<T> v)  {cerr<<"[ ";for(T x:v) ppp(x), cerr<<" ";cerr<<']';}
template <typename T, typename... V> void ppp(T t, V... v){ppp(t);  if (sizeof...(v))   cerr << ", ";   ppp(v...);}






const ll N=1e5+2;
map<pair<ll,ll> , ll> R , MinTime;
map<pair<ll,ll> , pair<ll,ll>> par; 
pair<ll,ll> find(pair<ll,ll> a)
{
    vector<pair<ll,ll>> ref;
    while(par[a].ff != id1)
    {
        ref.pb(a); 

        a=par[a];
    }
    for(ll i=0;i<ref.sz;i++) par[ref[i]]=a; 

    return a;
}

void Union(pair<ll,ll> a,pair<ll,ll> b)
{
  

    a = find(a);
    b = find(b);
    if(a==b) return;
   

    if(R[a]>R[b])
    {
        R[a]+=R[b]; 

      

        par[b]=a;

       

        MinTime[a] = min(MinTime[a] , MinTime[b]);
    }
    else
    {
        R[b]+=R[a];
        par[a]=b;
        MinTime[b] = min(MinTime[a] , MinTime[b]);
    }
}

int main()
{
    JSM
    ll t,n,m,x,y,p,q,i,j,k,answer=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<pair<ll,pair<ll,ll>>> a(n); fon cin>>a[i].ss.ff>>a[i].ss.ss>>a[i].ff;
        map<ll,vector<ll>> X , Y;
        fon{
            x = a[i].ss.ff;
            y = a[i].ss.ss;
            X[x].pb(y);
            Y[y].pb(x);
            MinTime[{x,y}] = a[i].ff;
        }

        for(auto it = X.bg ; it!= X.ed ; it++){
            sort(it->ss.bg , it->ss.ed);
        }
        for(auto it = Y.bg ; it!= Y.ed ; it++){
            sort(it->ss.bg , it->ss.ed);
        }

        fon par[a[i].ss] = {id1 , id1} , R[a[i].ss] = 1;
        for(auto x:X){
            vector<ll> ref = x.ss;
            for(i=0;i<ref.sz-1;i++){
                pair<ll,ll> curr , next;
                curr = {x.ff , ref[i]};
                next = {x.ff , ref[i+1]};
                if(ref[i+1] - ref[i] <= k){
                    Union(curr , next);
                }
            }
        }
        for(auto x:Y){
            vector<ll> ref = x.ss;
            for(i=0;i<ref.sz-1;i++){
                pair<ll,ll> curr , next;
                curr = {ref[i] , x.ff};
                next = {ref[i+1] , x.ff};
                if(ref[i+1] - ref[i] <= k){
                    Union(curr , next);
                }
            }
        }

        

        

        

        


        set<pair<ll,ll>> Parents ;
        fon Parents.insert(find(a[i].ss));

        vector<ll> id0;
        for(auto x:Parents){
            id0.pb(MinTime[x]);
        }

        sort(id0.bg , id0.ed);

        answer = -1;
        for(i=id0.sz - 1; i>=0;i--){
            if(id0[i] <= answer) break;
            answer++;
        }

        cout<<answer<<endl;

    }
}








































































































































































































































































































































































































      

























        





































        
























        






















































        


        

        

        




