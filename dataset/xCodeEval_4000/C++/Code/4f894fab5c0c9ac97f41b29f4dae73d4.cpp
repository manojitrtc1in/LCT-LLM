


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define fin for(int i = 0; i < n; i++)
#define fni for(int i = n-1; i >= 0; i--)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a-1; i >= b; i--)

void nice(){
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        string str;
        cin >> str;
        rep(i,0,k){
            if(str[i] == 'L')cout << 'L' ;
            else if(str[i] == 'R')cout << 'R';
            else if(str[i] == 'U')cout << 'D';
            else cout << 'U';
        }
        cout << endl;
    }
}
int main () {
    nice();
	

	

	

	

}