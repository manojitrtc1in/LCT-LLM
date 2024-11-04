    
    
    
    
    
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;
    int main()
    {
            int f=0,g=0,h=0,i=0;

            int n;
            string s,t;

  ios::sync_with_stdio(false);
    cin >> n >> s >> t;
    for (i=0;i<2*n;i++) {
        if (s[i]=='1') f++;
        if (t[i]=='1') g++;
        if (s[i]+t[i]==98) h++;
    }
    if (h%2==1) g--;
    if (f>g) cout << "First" << endl;
    else if (g-f>1) cout << "Second" << endl;
    else cout << "Draw" << endl;
        return 0;
    }