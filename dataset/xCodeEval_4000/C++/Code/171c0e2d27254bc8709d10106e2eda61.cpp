

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define ll long long






long long t, n, k, q;
vector<int>number, dd;
deque<int>ans;
int dp(int position){
    if(dd[position]<number[position]){
        dd[position-1]--,
        dd[position]+=10;
    }
    

    ans.push_front(dd[position]-number[position]);
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        ans.clear();
        number.clear();
        dd.clear();
        cin>>n;     
        string s;
        cin>>s;
        number.pb(0);
        for(auto i : s){
            number.pb(i-48);
            

            dd.pb(1);
        }
        dd.pb(1);
        for(int i = n ; i > 0 ; i --)dp(i);
        if(ans.front()==0){
            ans.clear();
            dd.clear();
            number.clear();
            for(auto i : s){
                number.pb(i-48);
                

                dd.pb(9);
            }
            for(int i = 0 ; i < n ; i ++){
                dd.pb(9);
            }   
            for(int i = n-1 ; i >= 0 ; i --)dp(i);
        }
        for(int i = 0 ; i < n ; i ++){
            cout<<ans.front();
            ans.pop_front();
        }
        cout<<endl;
    }
}

	     	 		 		 	  		  				 	 		