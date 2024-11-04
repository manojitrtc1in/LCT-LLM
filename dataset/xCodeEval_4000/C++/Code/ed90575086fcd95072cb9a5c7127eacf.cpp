#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int mod = 1e9 + 7;
int N , K;
int dp[1001][1001][2];


int solve(int i , int j , int k)    {
    if(j > K || !j)return 0;
    
    if(i == 1 and j == K and !k)
        return 1;
    
    if(i > N){
        return 0;
    }
    
    if(i == 0){
        return 0;
    }
    
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    
    int ans = 0;
    if(!k){
        ans += solve(i - 1 , j + 1 , 1);
        ans %= mod;
        ans += solve(i - 1 , j , 0);
        ans %= mod;
    }
    else{
        ans += solve(i + 1 , j + 1 , 0);
        ans %= mod;
        ans += solve(i + 1 , j , 1);
        ans %= mod;
    }
    
    return dp[i][j][k] = ans;
}


void SoLvEr()   {
    for(auto &x : dp)for(auto &y : x)for(auto &z : y)z = -1;
    cin >> N >> K;
    int ans = (K > 1 ? 1 : 0);
    for(int i = K;i >= 1;--i)ans = (ans + (solve(N , i , 0) + solve(1 , i , 1)) % mod) % mod;
    cout << ans << '\n';
}

int32_t main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TeSt = 1;
    cin >> TeSt;
    while(TeSt--){
        SoLvEr();
    }
}
































































