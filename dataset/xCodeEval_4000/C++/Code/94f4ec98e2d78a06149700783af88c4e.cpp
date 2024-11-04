#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define MOD 1000000007
#define MAXN   1000001
#define MODA 998244353
#define vi          vector<int>
#define vll          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define allr(a)      (a).rbegin(),(a).rend()

ll power(ll a,ll b){
    ll result=1;
    while(b>0){
        int lastbit=(b&1);
        if(lastbit){
            result=(result*a);
        }
        a=(a*a);
        b=b>>1;
    }
    return result;
}

ll power2(ll a,ll b,ll p){
    ll result=1;
    while(b>0){
        int lastbit=(b&1);
        if(lastbit){
            result=(result*a)%p;
        }
        a=(a*a)%p;
        b=b>>1;
    }
    return result%p;
}

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<ll> SieveOfEratosthenes(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++){
        if (prime[p] == true){
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    vector<ll>v;
    for (int p=2; p<=n; p++)
        if (prime[p]) v.pb(p);
    return v;
}

void shortest(map<int,vector<pair<int,ll>>>m,int src,int n,ll *dist){
    bool visited[n];
    set<pair<ll,int>>s;
    for(int i=0;i<=n;i++){
        dist[i]=-1;
        visited[i]=false;
    }

    s.insert(mp(0ll,src));
    dist[src]=0;
    while(!s.empty()){
        auto t=s.begin();
        ll dis=(*t).F;
        int u=(*t).S;
        s.erase(t);
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        for(auto tt:m[u]){
            int v=tt.F;
            ll w=tt.S;
            if(!visited[v]){
                if(dist[v]!=-1 && dist[v]>dis+w){
                    s.erase(mp(dist[v],v));
                    dist[v]=dis+w;
                    s.insert(mp(dist[v],v));
                }else if(dist[v]==-1){
                    dist[v]=dis+w;
                    s.insert(mp(dist[v],v));
                }
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ttttt=1;
    cin>>ttttt;
    for(int tttt=1;tttt<=ttttt;tttt++){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                a[i][j]=s[j]-'0';
            }
        }
        map<int,vector<pair<int,int>>>ma;
        int count=0;
        int x[3]={-1,-1,0};
        int y[3]={-1,0,-1};

        for(int j=0;j<m;j++){
            if(a[0][j]==1){
                if((j+1)<m){
                    int c=1;
                    if(a[0][j+1]){
                        c++;
                    }
                    if(a[1][j+1]){
                        c++;
                    }
                    if(a[1][j]){
                        c++;
                    }
                    if(c==1){
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j+1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(1,j+1));
                        ma[count].pb(mp(0,j+1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(0,j));
                        ma[count].pb(mp(1,j+1));
                        ma[count].pb(mp(1,j));
                        count++;
                        a[0][j]=0;
                    }else if(c==2){
                        int xx=0;
                        if(a[0][j+1]){
                            xx=0;
                            a[0][j+1]=0;
                        }
                        if(a[1][j+1]){
                            xx=1;
                            a[1][j+1]=0;
                        }
                        if(a[1][j]){
                            xx=2;
                            a[1][j]=0;
                        }
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j+1));
                        ma[count].pb(mp(1,j+1));
                        count++;
                        if(xx==0){
                            ma[count].pb(mp(1,j+1));
                            ma[count].pb(mp(1,j));
                            ma[count].pb(mp(0,j));
                        }else if(xx==1){
                            ma[count].pb(mp(0,j));
                            ma[count].pb(mp(0,j+1));
                            ma[count].pb(mp(1,j));
                        }else{
                            ma[count].pb(mp(0,j));
                            ma[count].pb(mp(0,j+1));
                            ma[count].pb(mp(1,j+1));
                        }
                        a[0][j]=0;
                        count++;
                    }else if(c==3){
                        ma[count].pb(mp(0,j));
                        if(a[0][j+1]){
                            a[0][j+1]=0;
                            ma[count].pb(mp(0,j+1));
                        }
                        if(a[1][j+1]){
                            a[1][j+1]=0;
                            ma[count].pb(mp(1,j+1));
                        }
                        if(a[1][j]){
                            a[1][j]=0;
                            ma[count].pb(mp(1,j));
                        }
                        a[0][j]=0;
                        count++;
                    }else{
                        if(a[0][j+1]){
                            a[0][j+1]=0;
                        }
                        if(a[1][j+1]){
                            a[1][j+1]=0;
                        }
                        if(a[1][j]){
                            a[1][j]=0;
                        }
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j+1));
                        ma[count].pb(mp(1,j+1));
                        count++;
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j+1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(1,j+1));
                        ma[count].pb(mp(0,j+1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(0,j));
                        ma[count].pb(mp(1,j+1));
                        ma[count].pb(mp(1,j));
                        count++;
                        a[0][j]=0;
                    }
                }else{
                    int c=1;
                    if(a[0][j-1]){
                        c++;
                    }
                    if(a[1][j-1]){
                        c++;
                    }
                    if(a[1][j]){
                        c++;
                    }
                    if(c==1){
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j-1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(1,j-1));
                        ma[count].pb(mp(0,j-1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(0,j));
                        ma[count].pb(mp(1,j-1));
                        ma[count].pb(mp(1,j));
                        count++;
                        a[0][j]=0;
                    }else if(c==2){
                        int xx=0;
                        if(a[0][j-1]){
                            xx=0;
                            a[0][j-1]=0;
                        }
                        if(a[1][j-1]){
                            xx=1;
                            a[1][j-1]=0;
                        }
                        if(a[1][j]){
                            xx=2;
                            a[1][j]=0;
                        }
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j-1));
                        ma[count].pb(mp(1,j-1));
                        count++;
                        if(xx==0){
                            ma[count].pb(mp(1,j-1));
                            ma[count].pb(mp(1,j));
                            ma[count].pb(mp(0,j));
                        }else if(xx==1){
                            ma[count].pb(mp(0,j));
                            ma[count].pb(mp(0,j-1));
                            ma[count].pb(mp(1,j));
                        }else{
                            ma[count].pb(mp(0,j));
                            ma[count].pb(mp(0,j-1));
                            ma[count].pb(mp(1,j-1));
                        }
                        a[0][j]=0;
                        count++;
                    }else if(c==3){
                        ma[count].pb(mp(0,j));
                        if(a[0][j-1]){
                            a[0][j-1]=0;
                            ma[count].pb(mp(0,j-1));
                        }
                        if(a[1][j-1]){
                            a[1][j-1]=0;
                            ma[count].pb(mp(1,j-1));
                        }
                        if(a[1][j]){
                            a[1][j]=0;
                            ma[count].pb(mp(1,j));
                        }
                        a[0][j]=0;
                        count++;
                    }else{
                        if(a[0][j-1]){
                            a[0][j-1]=0;
                        }
                        if(a[1][j-1]){
                            a[1][j-1]=0;
                        }
                        if(a[1][j]){
                            a[1][j]=0;
                        }
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j-1));
                        ma[count].pb(mp(1,j-1));
                        count++;
                        ma[count].pb(mp(1,j));
                        ma[count].pb(mp(0,j-1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(1,j-1));
                        ma[count].pb(mp(0,j-1));
                        ma[count].pb(mp(0,j));
                        count++;
                        ma[count].pb(mp(0,j));
                        ma[count].pb(mp(1,j-1));
                        ma[count].pb(mp(1,j));
                        count++;
                        a[0][j]=0;
                    }
                }
                a[0][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i][0]==1){
                if((i+1)<n){
                    int c=1;
                    if(a[i][1]){
                        c++;
                    }
                    if(a[i+1][1]){
                        c++;
                    }
                    if(a[i+1][0]){
                        c++;
                    }
                    if(c==1){
                        ma[count].pb(mp(i+1,0));
                        ma[count].pb(mp(i,1));
                        ma[count].pb(mp(i,0));
                        count++;
                        ma[count].pb(mp(i+1,1));
                        ma[count].pb(mp(i,1));
                        ma[count].pb(mp(i,0));
                        count++;
                        ma[count].pb(mp(i,0));
                        ma[count].pb(mp(i+1,1));
                        ma[count].pb(mp(i+1,0));
                        count++;
                        a[i][0]=0;
                    }else if(c==2){
                        int xx=0;
                        if(a[i][1]){
                            xx=0;
                            a[i][1]=0;
                        }
                        if(a[1+i][1]){
                            xx=1;
                            a[1+i][1]=0;
                        }
                        if(a[1+i][0]){
                            xx=2;
                            a[1+i][0]=0;
                        }
                        ma[count].pb(mp(1+i,0));
                        ma[count].pb(mp(i,1));
                        ma[count].pb(mp(1+i,1));
                        count++;
                        if(xx==0){
                            ma[count].pb(mp(1+i,1));
                            ma[count].pb(mp(1+i,0));
                            ma[count].pb(mp(i,0));
                        }else if(xx==1){
                            ma[count].pb(mp(i,0));
                            ma[count].pb(mp(i,1));
                            ma[count].pb(mp(1+i,0));
                        }else{
                            ma[count].pb(mp(i,0));
                            ma[count].pb(mp(i,1));
                            ma[count].pb(mp(1+i,1));
                        }
                        a[i][0]=0;
                        count++;
                    }else if(c==3){
                        ma[count].pb(mp(0+i,0));
                        if(a[0+i][1]){
                            a[0+i][1]=0;
                            ma[count].pb(mp(0+i,1));
                        }
                        if(a[1+i][1]){
                            a[1+i][1]=0;
                            ma[count].pb(mp(1+i,1));
                        }
                        if(a[1+i][0]){
                            a[1+i][0]=0;
                            ma[count].pb(mp(1+i,0));
                        }
                        a[i][0]=0;
                        count++;
                    }else{
                        if(a[0+i][1]){
                            a[0+i][1]=0;
                        }
                        if(a[1+i][1]){
                            a[1+i][1]=0;
                        }
                        if(a[1+i][0]){
                            a[1+i][0]=0;
                        }
                        ma[count].pb(mp(1+i,0));
                        ma[count].pb(mp(0+i,1));
                        ma[count].pb(mp(1+i,1));
                        count++;
                        ma[count].pb(mp(1+i,0));
                        ma[count].pb(mp(0+i,1));
                        ma[count].pb(mp(0+i,0));
                        count++;
                        ma[count].pb(mp(1+i,1));
                        ma[count].pb(mp(0+i,1));
                        ma[count].pb(mp(0+i,0));
                        count++;
                        ma[count].pb(mp(0+i,0));
                        ma[count].pb(mp(1+i,1));
                        ma[count].pb(mp(1+i,0));
                        count++;
                        a[0+i][0]=0;
                    }
                }else{
                    int c=1;
                    if(a[i][1]){
                        c++;
                    }
                    if(a[i-1][1]){
                        c++;
                    }
                    if(a[i-1][0]){
                        c++;
                    }
                    if(c==1){
                        ma[count].pb(mp(i-1,0));
                        ma[count].pb(mp(i,1));
                        ma[count].pb(mp(i,0));
                        count++;
                        ma[count].pb(mp(i-1,1));
                        ma[count].pb(mp(i,1));
                        ma[count].pb(mp(i,0));
                        count++;
                        ma[count].pb(mp(i,0));
                        ma[count].pb(mp(i-1,1));
                        ma[count].pb(mp(i-1,0));
                        count++;
                        a[i][0]=0;
                    }else if(c==2){
                        int xx=0;
                        if(a[i][1]){
                            xx=0;
                            a[i][1]=0;
                        }
                        if(a[i-1][1]){
                            xx=1;
                            a[i-1][1]=0;
                        }
                        if(a[i-1][0]){
                            xx=2;
                            a[1+i][0]=0;
                        }
                        ma[count].pb(mp(i-1,0));
                        ma[count].pb(mp(i,1));
                        ma[count].pb(mp(i-1,1));
                        count++;
                        if(xx==0){
                            ma[count].pb(mp(i-1,1));
                            ma[count].pb(mp(i-1,0));
                            ma[count].pb(mp(i,0));
                        }else if(xx==1){
                            ma[count].pb(mp(i,0));
                            ma[count].pb(mp(i,1));
                            ma[count].pb(mp(i-1,0));
                        }else{
                            ma[count].pb(mp(i,0));
                            ma[count].pb(mp(i,1));
                            ma[count].pb(mp(i-1,1));
                        }
                        a[i][0]=0;
                        count++;
                    }else if(c==3){
                        ma[count].pb(mp(i,0));
                        if(a[i][1]){
                            a[i][1]=0;
                            ma[count].pb(mp(i,1));
                        }
                        if(a[i-1][1]){
                            a[i-1][1]=0;
                            ma[count].pb(mp(i-1,1));
                        }
                        if(a[i-1][0]){
                            a[i-1][0]=0;
                            ma[count].pb(mp(i-1,0));
                        }
                        count++;
                    }else{
                        if(a[0+i][1]){
                            a[0+i][1]=0;
                        }
                        if(a[i-1][1]){
                            a[i-1][1]=0;
                        }
                        if(a[i-1][0]){
                            a[i-1][0]=0;
                        }
                        ma[count].pb(mp(i-1,0));
                        ma[count].pb(mp(i-1,1));
                        ma[count].pb(mp(i-1,1));
                        count++;
                        ma[count].pb(mp(i-1,0));
                        ma[count].pb(mp(0+i,1));
                        ma[count].pb(mp(0+i,0));
                        count++;
                        ma[count].pb(mp(i-1,1));
                        ma[count].pb(mp(0+i,1));
                        ma[count].pb(mp(0+i,0));
                        count++;
                        ma[count].pb(mp(0+i,0));
                        ma[count].pb(mp(i-1,1));
                        ma[count].pb(mp(i-1,0));
                        count++;
                        a[0+i][0]=0;
                    }
                }
                a[i][0]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(a[i][j]==1){
                    int c=1;
                    for(int k=0;k<3;k++){
                        if(a[i+x[k]][j+y[k]]==1){
                            c++;
                        }
                    }
                    if(c==1){
                        ma[count].pb(mp(i-1,j));
                        ma[count].pb(mp(i,j-1));
                        ma[count].pb(mp(i,j));
                        count++;
                        ma[count].pb(mp(i-1,j-1));
                        ma[count].pb(mp(i,j-1));
                        ma[count].pb(mp(i,j));
                        count++;
                        ma[count].pb(mp(i,j));
                        ma[count].pb(mp(i-1,j-1));
                        ma[count].pb(mp(i-1,j));
                        count++;
                        a[i][j]=0;
                    }else if(c==2){
                        int xx=0;
                        for(int k=0;k<3;k++){
                            if(a[i+x[k]][j+y[k]]==1){
                                a[i+x[k]][j+y[k]]=0;
                                xx=k;
                                break;
                            }
                        }
                        ma[count].pb(mp(i-1,j));
                        ma[count].pb(mp(i,j-1));
                        ma[count].pb(mp(i-1,j-1));
                        count++;
                        if(xx==0){
                            ma[count].pb(mp(i,j-1));
                            ma[count].pb(mp(i,j));
                            ma[count].pb(mp(i-1,j));
                        }else if(xx==1){
                            ma[count].pb(mp(i,j-1));
                            ma[count].pb(mp(i,j));
                            ma[count].pb(mp(i-1,j-1));
                        }else if(xx==2){
                            ma[count].pb(mp(i,j));
                            ma[count].pb(mp(i-1,j-1));
                            ma[count].pb(mp(i-1,j));
                        }
                        count++;
                        a[i][j]=0;
                    }else if(c==3){
                        ma[count].pb(mp(i,j));
                        for(int k=0;k<3;k++){
                            if(a[i+x[k]][j+y[k]]==1){
                                ma[count].pb(mp(i+x[k],j+y[k]));
                                a[i+x[k]][j+y[k]]=0;
                            }
                        }
                        count++;
                    }else{
                        for(int k=0;k<3;k++){
                            if(a[i+x[k]][j+y[k]]==1){
                                a[i+x[k]][j+y[k]]=0;
                            }
                        }
                        ma[count].pb(mp(i-1,j));
                        ma[count].pb(mp(i,j-1));
                        ma[count].pb(mp(i-1,j-1));
                        count++;
                        ma[count].pb(mp(i-1,j));
                        ma[count].pb(mp(i,j-1));
                        ma[count].pb(mp(i,j));
                        count++;
                        ma[count].pb(mp(i-1,j-1));
                        ma[count].pb(mp(i,j-1));
                        ma[count].pb(mp(i,j));
                        count++;
                        ma[count].pb(mp(i,j));
                        ma[count].pb(mp(i-1,j-1));
                        ma[count].pb(mp(i-1,j));
                        count++;
                        a[i][j]=0;
                    }
                    a[i][j]=0;
                }
            }
        }
        cout<<ma.size()<<endl;
        for(auto i:ma){
            for(auto j:i.S){
                cout<<j.F+1<<" "<<j.S+1<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}