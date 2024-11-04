


#include<bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define srt(a) sort(all(a))
#define ll long long
#define F first
#define S second
#define pb push_back
#define nl cout << '\n'
#define Basm_Allah ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop(i, n) for(int i = 0; i < n; i++)
#define Loop(i, p_1, n) for(int i = p_1; i < n; i++)
#define leep(e, s) for(int i = e-1; i >= s; i--)
#define cin_arr(arr, n) loop(i, n) cin >> arr[i];
#define cout_arr(arr, n) loop(i, n) cout << arr[i] << " ";
#define cin_v(arr) for(auto& i : arr) cin >> i;
#define cout_v(arr) for(auto k : arr) cout << k << " ";
#define no cout << "NO"
#define yes cout << "YES"
#define yon(Ii) cout << (Ii ? "YES" : "NO")
using namespace std;
bool sortbysec(const pair<ll,ll> &a, pair<ll,ll> &b){return (a.second < b.second);}
ll gcd(ll a, ll b){if(a == 0){return b;}return gcd(b%a, a);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}

vector<string> vectoria = {"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288","1048576","2097152","4194304","8388608","16777216","33554432","67108864","134217728","268435456","536870912","1073741824","2147483648","4294967296","8589934592","17179869184","34359738368","68719476736","137438953472","274877906944","549755813888","1099511627776","2199023255552","4398046511104","8796093022208","17592186044416","35184372088832","70368744177664","140737488355328","281474976710656","562949953421312","1125899906842624"};
int find_maxi(int, int, int);
void doWork();



int main(){
    Basm_Allah;

    

    

    

    

    int t = 1; 

    while(t--){
        doWork();
        cout << '\n';
    }
    return 0;
}

void doWork(){
    ll n; cin >> n;
    vector<ll> v(n);   cin_v(v);

    ll ans = 1e18 + 5, curent = 0, loc = 0;
    
    for(int i = 0; i < n; i++){
        
        curent = 0, loc = 0;
        for(int j = i - 1; j > -1; j--){
            loc = loc / v[j]; 
            if(loc < 0) loc = -loc;
            loc = (loc+ 1) * v[j];
            curent += (loc / v[j]);
        } 

        loc = 0;
        for(int j = i + 1; j < n; j++){
            loc = loc / v[j]; 
            if(loc < 0) loc = -loc;
            loc = (loc + 1) * v[j];
            curent += (loc / v[j]);
        }
        

        ans = min(ans, curent);
    }

    cout << ans;
}

int find_maxi(int a = -1, int b = -1, int c = -1){

}



















































    











    

    




