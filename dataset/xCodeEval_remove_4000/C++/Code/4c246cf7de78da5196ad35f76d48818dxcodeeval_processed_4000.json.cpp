






using namespace std;
lli fact(lli n,lli m){
    lli dp[n+1][m+1];
    for(lli i=0;i<=n;i++){
        for(lli j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }
    for(lli i=0;i<=n;i++){
        for(lli j=0;j<=min(i,m);j++){
            if(j==0||i==j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp[n][m];
}
lli fun(lli n){
    lli ret=0;
    for(lli i=1;i<=n;i++){
        ret+=fact(n,i);
    }
    return ret;
}
int f[200];
int main(){
    lli n,m,ans=0;
    cin>>n>>m;
    lli a[n][m];
    lli d[2][n],g[2][m];
    for(lli i=0;i<n;i++){
        lli o=0,l=0;
        for(lli j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==0)o++;
            else l++;
        }
        d[0][i] = o;
        d[1][i] = l;
    }
    for(lli i=0;i<m;i++){
        lli o=0,l=0;
        for(lli j=0;j<n;j++){
            if(a[j][i]==0)o++;
            else l++;
        }
        g[0][i] = o;
        g[1][i] = l;
    }
    ans=n*m;
    for(lli i=0;i<n;i++){
        ans+=(fun(d[0][i])-d[0][i]);
        ans+=(fun(d[1][i])-d[1][i]);
    }
    for(lli i=0;i<m;i++){
        ans+=(fun(g[0][i])-g[0][i]);
        ans+=(fun(g[1][i])-g[1][i]);
    }
    cout<<ans;
    return 0;
}

