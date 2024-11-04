
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define OJ freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define cool ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
int mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define forTo(i, n) for(int i = 0; i < n; i++)
#define fi first
#define se second
#define pb push_back
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
constexpr int INF = 1e9;
constexpr ll lINF = 1e18;
 
void solve(){
	string str;
    cin >> str;
    int n = str.length();
    if (str[n - 1] != str[0])
        str[n - 1] = str[0];
    cout << str << "\n";
}
 
int main() {
    cool;
    int t;
	cin>>t;
	while(t--){
    	solve();
	}
}
