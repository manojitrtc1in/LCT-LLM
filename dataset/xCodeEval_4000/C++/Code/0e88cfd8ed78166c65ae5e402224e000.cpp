#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
#define pbk push_back
#define rep(i, a, b) for (int i=a; i<=b; i++) 
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef set<int> si;
typedef queue<int> qi;
typedef tuple<int, int, int> tiii; 

typedef vector<tiii> vtiii;
int T, N, K, M, S; 




void print(int a, int b) {
    cout << a << " " << b << endl;
}

void print(const string& str) {
    cout << str << endl;
}
void print(pii a) {
    cout << a.first << " " << a.second << endl;
}

void print(int a) {
    cout << a << endl;
}

void print(vi& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}





































































































































void Solve() {
    vector<string> v;
    cin >> N;
    set<string> sstr;
    rep(i,1,N) {
        string str; cin >> str;
        v.pbk(str);
        sstr.insert(str);
    }

    rep(i,0,N-1) {
        bool flag=0;
        [&] () {
            for(int j=1;j<v[i].size();j++) {
                string str1 = v[i].substr(0, j);
                string str2 = v[i].substr(j);

                if(sstr.find(str1)!=sstr.end() && sstr.find(str2)!=sstr.end()) {
                    flag=1;
                    return;
                }
            }
        } ();
        cout << flag;
    }
    cout << endl;


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) Solve();
}