#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll;





























































































































































































































































            
















































































































































        






















































































































































            





















  





























































































































    


    





    


    
























































































     


















    














































    






























































































            



































































































































ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
















































































































































































vector<ll> factors;






























ll sum(ll n){
    ll s = 0;
    ll k = n;
    while(n > 0){
        s += n%10;
        n/=10;
    }
    ll gcd = __gcd(k , s);
    return gcd;
}

int main(){
    int t;
    cin >> t;
    while(t--){
       ll n;
       cin >> n;
       if(sum(n) != 1){
           cout << n << endl;
       }
        else if(sum(n+1) != 1){
           cout << n+1 << endl;
       }
        else if(sum(n+2) != 1){
           cout << n+2 << endl;
       }
    }   
}
 			   		 	  				  			 	 			  	