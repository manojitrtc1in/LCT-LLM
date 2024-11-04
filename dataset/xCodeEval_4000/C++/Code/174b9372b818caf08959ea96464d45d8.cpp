#include<bits/stdc++.h>
#define int long long int
using namespace std;

void SoLvEr()   {
    int n;
    cin >> n;
    vector<int> x(n) , y(n);
    for(int i = 0;i < n;++i)
        cin >> x[i] >> y[i];
    
    vector<int> index(n);
    iota(index.begin() , index.end() , 0);
    
    sort(index.begin() , index.end() , [&](auto l , auto r){
        if(y[r] - x[r] > y[l] - x[l])return true;
        if(y[r] - x[r] < y[l] - x[l])return false;
        if(x[l] < x[r])return true;
        if(x[l] > x[r])return false;
        if(y[l] < y[r])return true;
        if(y[l] > y[r])return false;
        return false;
    });
    
    vector<int> ans;
    set<int> check;
    for(int i = 1;i <= n;++i)check.insert(i);
    
    for(int i : index){
        int p = *check.lower_bound(x[i]);
        assert(p <= y[i]);
        ans.push_back(p);
        check.erase(p);
    }
    
    for(int i = 0;i < n;++i){
        cout << x[index[i]] << ' ' << y[index[i]] << ' ' << ans[i] << '\n';
    }
    
}

int32_t main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TeSt = 1;
    cin >> TeSt;
    while(TeSt--){
        SoLvEr();
        cout << '\n';
    }
}































































