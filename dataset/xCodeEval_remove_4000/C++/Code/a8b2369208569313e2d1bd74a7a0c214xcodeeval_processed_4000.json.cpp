







































































































































































































































































































        

































































































 
 








































































































































































































































































































































        










































































































































































































































































































































































































        

































































































































































    



































            





























































































































































































using namespace std;




int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> m(n+1,0);
        vector<int> a(n);
        

        for(int i=0; i<n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        int mex = 0;
        set<int> s;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            m[a[i]]--;
            s.insert(a[i]);

            while(s.find(mex) != s.end()) mex++;
            if(m[mex] == 0) {
                s.clear();
                ans.push_back(mex);
                mex = 0;
            }
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}













