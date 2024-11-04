
 

 
using namespace std;
 
typedef long unsigned long ull;

void solve() {
    unordered_map<char, int> a;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        a[s[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(a[s[i]] == 1) {
            for(int j = i; j < n; j++) {
                cout << s[j];
            }
            cout << "\n";
            return;
        } else {
            a[s[i]]--;
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int k = 1;
    cin >> k;
    while(k--) {
        solve();
    }
    return 0;
}
