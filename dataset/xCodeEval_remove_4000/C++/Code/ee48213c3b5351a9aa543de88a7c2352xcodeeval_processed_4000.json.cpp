





using namespace std;

const int N  = 1000;
int ans[4];
void solve(){
    map<string, int>mp;
    memset(ans, 0, sizeof ans);
    int n;
    cin >> n;
    vector<string>s1, s2, s3;
    for(int i = 0 ; i < n ;i++){
        string s;
        cin >> s;
        s1.push_back(s);
        mp[s]++;
    }
    for(int i = 0 ; i < n ;i++){
        string s;
        cin >> s;
        s2.push_back(s);
        mp[s]++;
    }
    for(int i = 0 ; i < n ;i++){
        string s;
        cin >> s;
        s3.push_back(s);
        mp[s]++;
    }
    for(auto it : s1){
        if(mp[it] == 1) ans[1] += 3;
        else if(mp[it] == 2) ans[1]++;
    }
    for(auto it : s2){
        if(mp[it] == 1) ans[2] += 3;
        else if(mp[it] == 2) ans[2]++;
    }
    for(auto it : s3){
        if(mp[it] == 1) ans[3] += 3;
        else if(mp[it] == 2) ans[3]++;
    }
    for(int i = 1 ; i <= 3 ; i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
