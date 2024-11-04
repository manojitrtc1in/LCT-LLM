

#include<iostream>
#include<queue>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
 


#define ll long long
 
#define f(i,a,b) for (int i=a;i<=b;i++)
#define ii pair<int,int>
#define llll pair<ll,ll>
#define iii pair<pair<int,int>, int>
 
#define pb push_back
 
const ll MOD = 1000000007;



const int N = 200005;

int n, m ;
ll a[N], b[N], c[N];
int l[N], r[N];
int cntPairs[N];
vector<int> v[N];

void pre_init() {
    f(i,1,m) cntPairs[i] = 2;
}
 
 
void init() {
    f(i,0,n) while (v[i].size() > 0) v[i].pop_back() ;
}


void MrUnknown() {
    f(i,1,n) b[i] -= a[i];
    c[0] = 0;
    f(i,1,n) {
        c[i] = c[i-1] + b[i] ;
    }
    f(i,1,m) {
        v[l[i]-1].push_back(i);
        v[r[i]].push_back(i);
    }
    queue<int> q;
    set<int> s;
    f(i,0,n) s.insert(i);
    f(i,0,n) {
        if (!c[i]) {
            q.push(i);
            s.erase(i);
        }
    }
    while (q.size() > 0) {
        int id = q.front();
        q.pop();
        for (int i=0;i<v[id].size();i++) {
            int u = v[id][i];
            cntPairs[u]--;
            if (!cntPairs[u]) {
                

                set<int>::iterator li = s.lower_bound(l[u]);
                auto ri = s.upper_bound(r[u]);
                for (auto it = li; it!= ri; it++) {
                    q.push(*it);
                }
                s.erase(li,ri);
            }
        }
    }
    if (s.size() == 0) cout << "YES\n" ;
    else cout << "NO\n" ;

}

void inp() {
    

    
    cin >> n >> m ;
    f(i,1,n) cin >> a[i] ;
    f(i,1,n) cin >> b[i] ;
    f(i,1,m) cin >> l[i] >> r[i] ;
    
    pre_init();
    
    MrUnknown();
 
    init();
    
}
 
signed main() 

{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    

    

 
    


    int t; cin>>t; while(t--) 
        inp();
 
}

 


 
