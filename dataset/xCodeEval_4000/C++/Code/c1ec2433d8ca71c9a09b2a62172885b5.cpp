

    
#include<bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define all(X) (X).begin(), (X).end()
#define np cout << -1 << endl
#define rn return

using namespace std;


int dx[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy[]={1, -1, 0, 0, 1, -1, 1, -1};

void solve(){  
    int  n, c = 0;
    string s;
    cin >> n >> s;
    	for(int i=1; i<n; i++){
    		if(c % 2 == 0) s[i]=s[i];
    		else if(s[i]=='1') s[i]='0';
    		else s[i]='1';
 
    		if(s[i] >= s[i-1]) continue;
    		else{
    			c += 1;
    			if(s[i]=='0') s[i]='1';
    			else s[i]='0';
    		}
    	}
    	cout << c << '\n';
}
        
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int t=1;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}




 