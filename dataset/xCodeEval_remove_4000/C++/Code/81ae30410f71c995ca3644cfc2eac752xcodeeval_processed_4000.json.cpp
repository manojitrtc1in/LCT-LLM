    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;
    int main()
    {
            int f=0,g=0,h=0,i=0;

            int n;
            string s,t;

  ios::sync_with_stdio(false);
    cin >> n >> s >> t;
    for (i=0;i<2*n;i++) {
        if (s[i]=='1') f++;
        if (t[i]=='1') g++;
        if (s[i]+t[i]==98) h++;
    }
    if (h%2==1) g--;
    if (f>g) cout << "First" << endl;
    else if (g-f>1) cout << "Second" << endl;
    else cout << "Draw" << endl;
        return 0;
    }