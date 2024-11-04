#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
#define v vector<ll>
#define vv vector<v>
#define vvs vector<vs>
#define vu vector<lu>
#define vld vector<ld>
#define vs vector<string>
#define vb vector<bool>
#define vp vector<pair<ll,ll>>





































ll lcm(ll a,ll b) {
    ll x = __gcd(a,b);
    return a*b/x;
}

ll highest_coefficient(ll n,ll a) {
    ll count = 0;
    while(n){
        count+= n/a;
        n/=a;
    }
    return count;
}

v sieve(){
    vb isPrime(2*10000000,true);
    v primes;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<2*10000000;i++){
        if(isPrime[i]){
            for(ll j=2*i;j<2*10000000;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(ll i=0;i<2*10000000;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

v spf(){
    v arr(10000000+10);
    for(ll i=0;i<arr.size();i++){
        arr[i] = i;
    }
    for(ll i=2;i<arr.size();i+=2){
        arr[i] = 2;
    }
    for(ll i=3;i<arr.size();i++){
        if(arr[i] != i){
            for(ll j=i*2;j<arr.size();j+=i){
                if(arr[j] == j){
                    arr[j] = i;
                }
            }
        }
    }
    return arr;
}

ll xorSum(ll n){
    ll x = n%4;
    if(x == 0){
        return n;
    }
    if(x == 1){
        return 1;
    }
    if(x == 2){
        return n+1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    ll x = 0;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        ll p = xorSum(a-1),q=xorSum(b+a-1);
        x = p ^ q ^ x;
    }
    if(x){
        cout << "tolik";
    }
    else{
        cout << "bolik";
    }
    return 0;
}