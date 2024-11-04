#include <bits/stdc++.h>

#include<string>

using namespace std;

#define mem(n,i)    memset(n,i,sizeof (n));
typedef long long ll;









     bool prime(int n) {
    if (n < 1) return false;
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) return false;
    }
    return true;
}










struct node {
    int value;
    node * right;
    node * left;
};





bool contine8(ll a) {
    while (true) {
        if (a % 10 == 8) return true;
        a /= 10;
        if (a == 0)break;
    }
    return false;
}








int n = 105, m = 105;
vector<int> v[300];
bool visited[300];

void DFS(int a) {
    if (visited[a])return;
    visited[a] = true;
    for (auto u : v[a]) {
        DFS(u);
    }
}

vector<pair<char, int>> split(string s) {
    char c = s[0];
    int count = 1;
    vector<pair<char, int >> res;
    auto ss = s.c_str();
    for (int i = 1; i <= s.length(); i++) {
        if (ss[i] != c) {
            res.push_back({c, count});
            c = s[i];
            count = 1;
        } else {
            count++;
        }
    }
    return res;
}
const int MAX=1e6;
int main() {
    ll n,m;cin>>n>>m;
    ll b[MAX];
    for(ll j=1;j<=MAX;j++){
        b[j]=j;
    }
    for(ll i=0;i<n;i++){
        ll a;cin>>a;
        if(a<=MAX)
        b[a]=0;
    }
    ll i=1;
   ll count=0; vector<ll > v;
        while(m>=b[i]){
        if(b[i]){count++;v.push_back(b[i]);m-=b[i];}
        i++;
    }
    cout<<count<<endl;
    for(auto c:v){
        cout<<c<<" ";
    }
    return 0;
}



