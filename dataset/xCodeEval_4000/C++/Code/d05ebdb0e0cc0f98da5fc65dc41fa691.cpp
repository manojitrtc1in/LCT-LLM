    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    



    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    



    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    






        #pragma GCC optimize("O3")
        #include <bits/stdc++.h>

        

        const int maxn = 1e5 + 5;
        const int MOD = 1e9+7;
        #include "iostream"
        #include "string"
        #define int long long int
        #define IOS
        

        

        

        

        #define ism0 int sum = 0;
        #define ict0 int count = 0;
        #define yes cout << "YES" << endl
        #define no cout << "NO" << endl
        #define pb push_back
        

        #define ld long double
        #define int long long int
        #define setprc(x) fixed << setprecision(x)
        #define sz(ans) ans.size()
        #define all(arr) arr.begin(), arr.end()
        #define intd long double
        #define mii map<int, int>
        #define mci map<char, int>
        #define msi map<string, int>
        #define pii pair<int, int>
        #define vsort sort(v.begin(), v.end());
        #define vsortback sort(v.begin(), v.end(), greater<int>());
        #define ff first
        #define ss second
        #define fo(i, x, y) for (int i = x; i < y; i++)
        #define fa(i, a, y) for(int i=a ; i<=y ; i++)
        

        #define vi vector<int>
        #define vvi vector<vector<int>>
        #define vb vector<bool>
        #define endl "\n"

        typedef std::numeric_limits<double> dbl;
        using namespace std;

        

        intd pi = 3.1415926535897932;
        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        


        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        


        


        

        


        

        


        


        


        

        

        

        

        

        

        


        

        

        


        

        

        

        

        

        

        

        

        

        

        

      
    const int inf = 1e5+9;

        void solve()
        {
            int n,q,k,a[inf],sum[inf];
        cin>>n>>q>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
 
    for(int i=1;i<n;i++)
        sum[i] = sum[i-1] + (a[i+1]-a[i] -1);
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l == r){
            cout<<k-1<<endl;
        }
        else {
            cout<<(sum[r-1] - sum[l-1])*2ll + (k-a[r]) + (a[l] - 1)<<endl;
        }
    }
    }

        int32_t main()
        {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        

        fo(i, 0, t)
        {
        solve();
        cout << endl;
        }
        }