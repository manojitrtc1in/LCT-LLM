








































typedef long long ll;
typedef unsigned long long ull;
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int cnt=0;
    string ans;
    for (int i=0; i<s.size(); ++i){
        if (s[i]=='1') ++cnt;
        else ans.push_back(s[i]);
    }
    bool flag=0;
    for (int i=0; i<ans.size(); ++i){
        if (ans[i]=='2' && !flag){
            flag=1;
            for (int j=0; j<cnt; ++j) cout<<1;
        }
        cout<<ans[i];
    }
    if (!flag){
        for (int j=0; j<cnt; ++j) cout<<1;
    }
    return 0;
    
}
