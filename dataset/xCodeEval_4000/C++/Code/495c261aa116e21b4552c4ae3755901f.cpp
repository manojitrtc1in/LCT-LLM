




























#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define ar array
#define fi first
#define se second
#define ends "\n"
#define sp ' '

const long long MOD=1e9+7;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, A; cin >> N >> A;
    vector<int> a(N); for(auto&x:a) cin >> x;
    map<int, int> mp;
    int cnt_A=0;
    for(int i=0; i<N; ++i){
        if(a[i]==A)break;
        mp[a[i]]=0;
    }
    

    for(int i=0; i<N; ++i){
        if(a[i]==A){
            ++cnt_A;
            vector<int> er;
            for(auto x:mp){
                

                if(x.se<cnt_A) er.pb(x.fi);
            }
            for(auto x:er)
                mp.erase(x);
            if(mp.empty()){
                cout << -1 << ends; return 0;
            }
        }else{
            auto it=mp.find(a[i]);
            if(it!=mp.end())
                ++mp[a[i]];
        }
    }
    auto it=mp.begin();
    cout << (*it).fi << ends;
}
