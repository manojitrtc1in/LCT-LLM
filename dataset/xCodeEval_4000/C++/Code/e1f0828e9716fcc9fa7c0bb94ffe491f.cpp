#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
 
#define pb push_back;
#define mp make_pair;
typedef long long ll;
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define frv(a,b,c) for(int a=b;a>=c;a--)
#define pii pair<int,int>;
#define pll pair<long long, long long>;
#define vect vector<long long>


const ll mod = 1e9+7;
vector<int> adj[2510];
bool visited[2510]={false};
 
void dfs(int v){
    visited[v]=true;
    for(int u:adj[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}
 
ll pown(ll i, ll n){
    if(i%n==0)
        return n;
    return i%n;    
}
ll pown1(ll i, ll n){
    if(i%n==0)
        return (i/n);
    return (i/n)+1;    
} 
 
 
void solve(){
    ll n,m;
    cin >> n>>m;
    string s;
    
    ll dp[n+2][m+2] = {0};
    
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++)
            dp[i][j] = 0;
    }

    for(int i=1; i<=n; i++) {
        cin >> s;
        for(int j=1; j<=m; j++){
            if(s[j-1] == 'G'){
              dp[i][j]=1;  
            }
            else if(s[j-1] == 'B'){
                dp[i][j]=2;
            }
            else if(s[j-1] == '.'){
                dp[i][j]=3;
            }
            else if(s[j-1] == '#'){
                dp[i][j]=4;
            }
        }
    }
    

    

    

    

    

    if(n==1 | m==1){
        bool b= 0;
        bool e = 0;
        if(m==1 & n!=1){
            ll y=0;
            for(int i=1; i<=n; i++){
                if(dp[i][1] == 1){
                   y=i;
                   e=1;
                   break;
                }
            }
            for(int i=y+1; i<=n; i++){
                if(dp[i][1] == 2 | dp[i][1] == 4){
                    b=1;
                }
            }
    
            for(int i=1; i<=n; i++){
                if(dp[i][1] == 2){
                    for(int j=i+1; j<=n; j++){
                        if(dp[j][1] == 3){
                            break;
                        }
                        else if(dp[j][1] == 1){
                            b=1;
                            break;
                        }
                        else if((dp[j][1] == 4)){
                            break;
                        }
                    }
                }
            }
            
            if(e){
                if(b)
                    cout << "No" << "\n";
                else{
                    cout << "Yes" << "\n";
                }
            }
            else{
                cout << "Yes" << "\n";
            }
        }
        else if(n==1 & m!=1){
            ll y=0;
            for(int i=1; i<=m; i++){
                if(dp[1][i] == 1){
                   y=i;
                   e=1;
                   break;
                }
            }
            for(int i=y+1; i<=m; i++){
                if(dp[1][i] == 2 | dp[1][i] == 4){
                    b=1;
                }
            }
            for(int i=1; i<=m; i++){
                if(dp[1][i] == 2){
                    for(int j=i+1; j<=m; j++){
                        if(dp[1][j] == 3){
                            break;
                        }
                        else if(dp[1][j] == 1){
                            b=1;
                            break;
                        }
                        else if((dp[1][j] == 4)){
                            break;
                        }
                    }
                }
            }
            if(e){
                if(b)
                    cout << "No" << "\n";
                else{
                    cout << "Yes" << "\n";
                }
            }
            else{
                cout << "Yes" << "\n";
            }
        }
        else{
            cout << "Yes" << "\n";
        }
    }
    else{
        bool dp1[n+2][m+2]={false};
        for(int i=0; i<=n+1; i++)
            for(int j=0; j<=m+1; j++)
                dp1[i][j]=0;
        bool b = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int key = j+(m*(i-1));
                if(dp[i][j] == 2){
                    dp1[i][j]=1;
                    if(dp[i-1][j]==1){
                        b=1;
                    }
                    else{
                        dp1[i-1][j] = 1;
                    }    
                    if(dp[i+1][j] == 1){
                        b=1;
                    }
                    else{
                        dp1[i+1][j] = 1;  
                    }
                    if(dp[i][j+1] == 1)
                        b=1;
                    else
                        dp1[i][j+1] = 1;
                    if(dp[i][j-1] == 1)
                        b=1;
                    else
                        dp1[i][j-1]=1;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(dp[i][j] == 3){
                    if((dp[i-1][j]==4|dp[i-1][j]==0) & (dp[i+1][j] == 4|dp[i+1][j]==0) & (dp[i][j+1]==4|dp[i][j+1]==0) & (dp[i][j-1] == 4|dp[i][j-1]==0)){
                        dp1[i][j]=1;
                    }
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(dp[i][j] == 1){
                    if((dp[i-1][j]==4|dp[i-1][j]==0) & (dp[i+1][j] == 4|dp[i+1][j]==0) & (dp[i][j+1]==4|dp[i][j+1]==0) & (dp[i][j-1] == 4|dp[i][j-1]==0)){
                        dp1[i][j]=1;
                        b=1;
                    }
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int key = j+(m*(i-1));
                if(dp[i][j] == 4){
                    dp1[i][j]=1;
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int key = j+(m*(i-1));
                if(dp[i][j] == 2){
                    dp1[i][j]=1;
                }
            }
        }
    
    if(b){
        cout << "No" << "\n";
    }
    else{
        bool e=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(dp[i][j] == 1){
                    e=1;
                    break;
                }
        if(e){        
        for(int i=2; i<=n-1; i++){
            for(int j=2; j<=m-1; j++){
                int key = j+(m*(i-1));
                if(dp[i][j] == 1 | (dp[i][j] == 3 & dp1[i][j] == 0) ){
                    if(dp[i-1][j]!=2 & dp[i-1][j] !=4 & ((dp[i-1][j] == 3 & dp1[i-1][j] == 0) | (dp[i-1][j] == 1)))
                        adj[key].push_back(key-m);
                    if(dp[i+1][j]!=2 & dp[i+1][j] !=4 & ((dp[i+1][j] == 3 & dp1[i+1][j] == 0) | (dp[i+1][j] == 1)))    
                        adj[key].push_back(key+m);
                    if(dp[i][j-1]!=2 & dp[i][j-1] !=4 & ((dp[i][j-1] == 3 & dp1[i][j-1] == 0) | (dp[i][j-1] == 1)))    
                        adj[key].push_back(key-1);
                    if(dp[i][j+1]!=2 & dp[i][j+1] !=4 & ((dp[i][j+1] == 3 & dp1[i][j+1] == 0) | (dp[i][j+1] == 1)))    
                        adj[key].push_back(key+1);
                }
            }
        }
            
            if(dp[1][1] == 1 | (dp[1][1] == 3 & dp1[1][1] == 0)){
                if(dp[1][2]!=2 & dp[1][2] !=4 & ((dp[1][2] == 3 & dp1[1][2] == 0) | (dp[1][2] == 1)))
                    adj[1].push_back(2);
                if(dp[2][1]!=2 & dp[2][1] !=4 & ((dp[2][1] == 3 & dp1[2][1] == 0) | (dp[2][1] == 1)))    
                    adj[1].push_back(1+m);
            }
            if(dp[n][1] ==1 | (dp[n][1] == 3 & dp1[n][1] == 0)){
                if(dp[n][2]!=2 & dp[n][2] !=4 & ((dp[n][2] == 3 & dp1[n][2] == 0) | (dp[n][2] == 1)))    
                    adj[1+(m*(n-1))].push_back(2+(m*(n-1)));
                if(dp[n-1][1]!=2 & dp[n-1][1] !=4 & ((dp[n-1][1] == 3 & dp1[n-1][1] == 0) | (dp[n-1][1] == 1)))    
                    adj[1+(m*(n-1))].push_back(1+(m*(n-2)));
            }
            if(dp[1][m] == 1 | (dp[1][m] == 3 & dp1[1][m] == 0)){
                if(dp[1][m-1]!=2 & dp[1][m-1] !=4 & ((dp[1][m-1] == 3 & dp1[1][m-1] == 0) | (dp[1][m-1] == 1)))    
                    adj[m].push_back(m-1);
                if(dp[2][m]!=2 & dp[2][m] !=4 & ((dp[2][m] == 3 & dp1[2][m] == 0) | (dp[2][m] == 1)))    
                    adj[m].push_back(2*m);
            }
            if(dp[n][m] == 1 | (dp[n][m] == 3 & dp1[n][m] == 0)){
                if(dp[n][m-1]!=2 & dp[n][m-1] !=4 & ((dp[n][m-1] == 3 & dp1[n][m-1] == 0) | (dp[n][m-1] == 1)))    
                adj[(m*n)].push_back(((m*n)-1));
                if(dp[n-1][m]!=2 & dp[n-1][m] !=4 & ((dp[n-1][m] == 3 & dp1[n-1][m] == 0) | (dp[n-1][m] == 1)))
                adj[(m*(n))].push_back((m*(n-1)));
            }
            
            for(int i=2; i<=m-1; i++){
                if(dp[1][i] == 1 | (dp[1][i] == 3 & dp1[1][i] == 0)){
                    if(dp[1][i-1]!=2 & dp[1][i-1] !=4 & ((dp[1][i-1] == 3 & dp1[1][i-1] == 0) | (dp[1][i-1] == 1)))
                    adj[i].push_back(i-1);
                    if(dp[1][i+1]!=2 & dp[1][i+1] !=4 & ((dp[1][i+1] == 3 & dp1[1][i+1] == 0) | (dp[1][i+1] == 1)))
                    adj[i].push_back(i+1);
                    if(dp[2][i]!=2 & dp[2][i] !=4 & ((dp[2][i] == 3 & dp1[2][i] == 0) | (dp[2][i] == 1)))
                    adj[i].push_back(i+m);
                }
                if(dp[n][i] == 1 | (dp[n][i] == 3 & dp1[n][i] == 0)){
                    if(dp[n][i-1]!=2 & dp[n][i-1] !=4 & ((dp[n][i-1] == 3 & dp1[n][i-1] == 0) | (dp[n][i-1] == 1)))
                    adj[i+(m*(n-1))].push_back(i+(m*(n-1))-1);
                    if(dp[n][i+1]!=2 & dp[n][i+1] !=4 & ((dp[n][i+1] == 3 & dp1[n][i+1] == 0) | (dp[n][i+1] == 1)))
                    adj[i+(m*(n-1))].push_back(i+(m*(n-1))+1);
                    if(dp[n-1][i]!=2 & dp[n-1][i] !=4 & ((dp[n-1][i] == 3 & dp1[n-1][i] == 0) | (dp[n-1][i] == 1)))
                    adj[i+(m*(n-1))].push_back(i+(m*(n-2)));
                }
            }
            
            for(int i=2; i<=n-1; i++){
                if(dp[i][1] == 1 | (dp[i][1] == 3 & dp1[i][1] == 0)){
                    if(dp[i-1][1]!=2 & dp[i-1][1] !=4 & ((dp[i-1][1] == 3 & dp1[i-1][1] == 0) | (dp[i-1][1] == 1)))
                    adj[1+(m*(i-1))].push_back(1+(m*(i-2)));
                    if(dp[i+1][1]!=2 & dp[i+1][1] !=4 & ((dp[i+1][1] == 3 & dp1[i+1][1] == 0) | (dp[i+1][1] == 1)))
                    adj[1+(m*(i-1))].push_back(1+(m*i));
                    if(dp[i][2]!=2 & dp[i][2] !=4 & ((dp[i][2] == 3 & dp1[i][2] == 0) | (dp[i][2] == 1)))
                    adj[1+(m*(i-1))].push_back(2+(m*(i-1)));
                }
                if(dp[i][m] == 1 | (dp[i][m] == 3 & dp1[i][m] == 0)){
                    if(dp[i-1][m]!=2 & dp[i-1][m] !=4 & ((dp[i-1][m] == 3 & dp1[i-1][m] == 0) | (dp[i-1][m] == 1)))
                    adj[(m*(i))].push_back((m*(i-1)));
                    if(dp[i+1][m]!=2 & dp[i+1][m] !=4 & ((dp[i+1][m] == 3 & dp1[i+1][m] == 0) | (dp[i+1][m] == 1)))
                    adj[(m*(i))].push_back((m*(i+1)));
                    if(dp[i][m-1]!=2 & dp[i][m-1] !=4 & ((dp[i][m-1] == 3 & dp1[i][m-1] == 0) | (dp[i][m-1] == 1)))
                    adj[(m*(i))].push_back((m*(i))-1);
                }
            }
            
            
            int count = 0;
            for(int i=1; i<=(m*n); i++){
                if(!visited[i] & (dp[pown1(i,m)][pown(i,m)]==1 | i == (m*n))){
                    dfs(i);
                    count++;
                }
            }
        
            if(count!=1 | dp1[n][m]==1)
                cout << "No" << "\n";
            else 
                cout << "Yes" << "\n";
        }
        else{
            cout << "Yes" << "\n";
        }
                
        }
    }
    
    for(int i=1; i<=(m*n); i++){
        visited[i]=false;
        adj[i].clear();
    }
        
    
} 
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll u = t;
    while(t--){
        solve();
    }
}