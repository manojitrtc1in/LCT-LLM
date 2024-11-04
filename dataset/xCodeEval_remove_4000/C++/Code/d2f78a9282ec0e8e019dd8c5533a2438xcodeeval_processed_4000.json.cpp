











































typedef unsigned long long ull;
using namespace std;
vector<int> id0 (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1; i<n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
    return z;
}
signed main(){
    string s1,s2,t;
    cin>>s1>>s2;
    t=s2+"*"+s1;
    int cnt=0;
    vector<int> VEC=id0(t);
   

    for (int i=0; i<VEC.size(); ++i){
        if (VEC[i]==s2.size()){
            int j;
            

            for (j= i+s2.size()-1; j>i; --j)
                if (VEC[j]==s2.size()) break;
            if (!(j==i)) i=j;
            else i=j;
            s1[i-s2.size()]='
        }
        

    }
    cout<<cnt<<en;
    return 0;
}
