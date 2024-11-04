#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <numeric>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream> 
using namespace std; 
typedef long double ld;
typedef pair<long long,long long> p32;
typedef pair<long long,long long> p64;
typedef pair<double,double> pdd;
typedef vector<long long> v64;
typedef vector<long long> v32;
typedef vector<vector<long long> > vv32;
typedef vector<vector<long long> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
long long MOD = 1e9+7;
double eps = 1e9+7;
#define forn(i,e) for(long long i = 0; i < e; i++)
#define forsn(i,s,e) for(long long i = s; i < e; i++)
#define rforn(i,s) for(long long i = s; i >= 0; i--)
#define rforsn(i,s,e) for(long long i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NUlong long); cout.tie(NUlong long)
#define along long(x) (x).begin(), (x).end()
#define sz(x) ((long long)(x).size())
#define ll long long
#define en '\n'
long long t;
const long long N = 200010;
const long long M = 998244353;




















































char arr[100][100];

void solve() {
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){cin>>arr[i][j];}
    }
    for(int i=0;i<8;i++){   
        int r=0; 
    for(int j=0;j<8;j++){
        
        if(arr[i][j]=='R')r++;
        if(r==8){cout<<"R"<<en;return;}
    }
}
    cout<<"B"<<en;
        
}

 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    

    cin>>t;
    for(long long i=0;i<t;i++){
         solve();
    }
    return 0;
}




