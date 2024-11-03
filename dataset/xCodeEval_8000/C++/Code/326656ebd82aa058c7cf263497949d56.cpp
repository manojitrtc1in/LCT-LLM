
#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        if(x>y)swap(x,y);
        if(b>2*a)b=2*a;
        cout << a*(y-x)+b*x << '\n';
    }
}