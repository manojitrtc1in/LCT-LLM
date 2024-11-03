

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define ll long long






long long t, n, k, q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        string s;
        int p;
        cin>>s;
        cin>>p; 
        ll sum = 0;
        vector<int>sorted;
        for(int i = 0 ; i < s.size() ; i++){
            sum+=int(s[i]-96);
            sorted.pb(s[i]);
        }
        sort(sorted.begin(), sorted.end());
        int last = 'z';
        int count = 0 ;
        for(int i = s.size()-1 ; i >= 0 ; i--){
            

            if(sum<=p)break;
            if(sorted[i]!=last){
                last = sorted[i];
                count = 1;
            }else{
                count++;
            }
            sum-=(sorted[i]-96);
        }
        

        for(int i = 0 ; i < s.size() ; i ++){
            if(s[i]==last && count){
                count--;
            }else if(s[i]<=last){
                cout<<s[i];
            }
        }
        cout << endl;

        
    }
}

			  	   		  		   	   		  	  		