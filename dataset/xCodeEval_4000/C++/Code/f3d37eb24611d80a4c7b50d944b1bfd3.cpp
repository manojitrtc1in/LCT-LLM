#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define yes cout<<"YES";
#define no cout<<"NO";
#define vec vector<ll>
#define f_a(arr,it) for(auto it:arr)
#define vec_pair vector<pair<ll,ll>>
#define us  unordered_set<ll>
#define us_pair unordered_set<pair<ll,ll>>
#define mapi map<ll,ll>
#define map_vec map<ll,vec> 
#define fr(a,b) for(ll i = a; i < b; i++)
#define frr(b,a) for(ll i = b;i>=a;i--)
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define modi 1000000007
#define mod 998244353
#define inf (1LL<<60)
#define nline cout<<'\n';
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x;
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define cons_tree(n,tree)  
using namespace std;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
bool comp_desc(pair<ll,ll> a,pair<ll,ll> b){
    return a.second > b.second ;
}
ll low_ind_desc(vec& v, ll key){

    ll s = 0;
    ll e = v.size()-1;

    while(s<e){

        ll mid = s + (e-s)/2;

        if(v[mid]>=key){

            s = mid+1;

        }
        else{

            e = mid;

        }

    }
    return s;
}
ll high_ind(vec& v, ll key){

    ll s = 0;
    ll e = v.size()-1;

    while(s<e){

        ll mid = s + (e-s)/2;

        if(v[mid]<=key){

            s = mid+1;

        }
        else{

            e = mid;

        }

    }
    return e;
}


        






















































































bool is_palindrome(string s,int start,int end){
    if(start==end){
        return 1;
    }
    string p = s.substr(start,(end-start+1));
    string h = p;
    reverse(p.begin(),p.end());
    return p==h;
}
ll find_low_index(vec& arr,ll key){
    ll s = 0;
    ll e = arr.size()-1;
    while(s<e){

        ll mid = s + (e-s)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return s-1;
}
ll find_grea_index(vec& arr,ll key){
    ll s = 0;
    ll e = arr.size()-1;
    while(s<e){

        ll mid = s + (e-s)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return s;
}

bool is_prime(ll n){
    if (n <= 1ll)
        return false;
    if (n <= 3ll)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6ll)
        if (n % i == 0 || n % (i + 2ll) == 0)
            return false;
    return true;
}

ll child_count(ll par,ll child,vector<vec>& tree,vec& child_c){
    ll c = 0;
    f_a(tree[child],it){
        if(it!=par){
            c = c + child_count(child,it,tree,child_c);
        }
    }
    child_c[child] = c; 
    return child_c[child]+1;}
ll height_c(ll par,ll child,vector<vec>& tree,vec& height){
    ll c = 1;
    f_a(tree[child],it){
        if(it!=par){
            c = max(c,1+height_c(child,it,tree,height));
        }
    }
    return height[child]=c;}
void dis_subset(ll n_subset){
    

    fr(0,10){

        if(n_subset & (1<<i) ){

            cout<<i+1<<" ";
        }

    }
}
void rem_bit(ll& n_subset,ll bit_no){
    if( n_subset & (1<<(bit_no-1) ) ){

       n_subset = n_subset ^ (1<<(bit_no-1)) ;

    }
}
void add_bit(ll& n_subset,ll bit_no){

    n_subset = n_subset ^ (1<<(bit_no-1)) ;
}

ll form_set(ll n){

    ll i_set = 0;
    fr(0,n){

        i_set = i_set^(1<<i);

    }

    return i_set;
}
int BitsSetTable256[256];


void initialize(){   
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
    }
}


int countSetBits(int n) { 

    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}
void dfs(ll src,ll par,vec& lvl,ll level,vector<vec>& tree){
    lvl[src] = level;
    f_a(tree[src],it){
        if(it!=par){
            dfs(it,src,lvl,level+1,tree);
        }
    }
}
void binary_lifitng(ll src , ll par,vector<vec>& tree,vector<vec>& up){
    up[src][0] = par;
    for(ll i = 1;i<=19;i++){
        if(up[src][i-1]!=-1){
            up[src][i] = up[up[src][i-1]][i-1];
        }
        else{
            up[src][i] = 1;
        }
    }
    f_a(tree[src],it){
        if(it!=par){
            binary_lifitng(it,src,tree,up);
        }
    }
}
ll lift_node(ll node,ll jump_required,vector<vec>& up){
    for(ll i=19;i>=0;i--){
        if(jump_required==0 || node==-1){
            break;
        }
        if(jump_required>=(1<<i)){
            jump_required -= (1<<i);
            node = up[node][i];
        }
    }
    return node;
}
ll lca(ll u, ll v,vector<vec>& up,vec& lvl){
    if( lvl[u] < lvl[v] ){ swap(u,v); }
    u = lift_node(u,lvl[u]-lvl[v],up);
    ll low = 0;
    ll hi = lvl[u];
    while(low != hi){  

        ll mid = (low + (hi-low)/2);
        ll x1 = lift_node(u,mid,up);
        ll x2 = lift_node(v,mid,up);
        if(x1==x2){ hi = mid; }
        else{ low = mid + 1;}
    }
    return lift_node(u,low,up); 
}
ll lca2(ll u, ll v,vector<vec>& up,vec& lvl){  
    if( lvl[u] < lvl[v] ){ swap(u,v); }
    u = lift_node(u,lvl[u]-lvl[v],up);
    if(u==v){
        return u;
    }
    for(ll i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u,1,up); 
}
int ceil_find(vector<int>& arr,int target){
        

        if (target > arr[arr.size() - 1]) {
            return -1;
        }
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end) {
            



            int mid = start + (end - start) / 2;

            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                

                return mid;
            }
        }
        return start;
}
int floor_find(vector<int>& arr,int target){

        int start = 0;
        int end = arr.size() - 1;

        if(arr[0]>target){
            return -1;
        }

        while(start <= end) {
            



            int mid = start + (end - start) / 2;

            if(target < arr[mid]) {
                end = mid - 1;
            } 
            else if (target > arr[mid]) {
                start = mid + 1;
            } 
            else {
                return mid;
            }
        }
        return end;

}   
void multi_dup(){

    

    

    

 
    

    

    

 
    


    

    

    

    

    

    

    

    

    

    

    

    

}



int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int,int>> extras(n);
    for(int i=0;i<n;i++){

        extras[i] = {efficiency[i],speed[i]};

    }
    sort(extras.begin(),extras.end(),greater<>());

    for(int i=0;i<n;i++){

        cout<<extras[i].first<<" "<<extras[i].second;
        cout<<endl;

    }

    priority_queue<int> qus;

    int sum = 0;
    int count = 0;
    int max_ans = 0;

    for(int i=0;i<n;i++){

        if(count>(k-1)){

            int o = qus.top();
            sum = sum + (o) + extras[i].second;
            qus.pop();
            qus.push(-extras[i].second);

            max_ans = max(max_ans,(sum*extras[i].first));

        }
        else{
            sum = sum + extras[i].second;
            qus.push(-extras[i].second);
            max_ans = max(max_ans,(sum*extras[i].first));
            count++;
        }

    }
    return max_ans;   
}
int maxProfit(vector<int>& pricess) {

        int n1 = pricess.size();
        if(n1==1){
            return 0;
        }
    
        vector<int> prices;
        prices.push_back(pricess[0]);
        for(int i=1;i<n1;i++){
            if(pricess[i-1]!=pricess[i]){
                prices.push_back(pricess[i]);
            }
        }

        int n = prices.size();

        vector<int> ans;
        if(prices[0]<=prices[1]){
            ans.push_back(prices[0]);
        }
        for(int i=1;i<(n-1);i++){

            if(prices[i]>prices[i-1] && prices[i]>prices[i+1]){
                ans.push_back(prices[i]);
            }
            if(prices[i]<=prices[i-1] && prices[i]<prices[i+1]){
                ans.push_back(prices[i]);
            }

        }
        if(prices[n-1]>=prices[n-2]){
            ans.push_back(prices[n-1]);
        }

        int ansi = 0;
        int k = ans.size();

        if(k==0){
            return 0;
        }
        else if(k%2!=0){
            k--;
        }
        for(int i=0;i<(k-1);i=i+2){
            ansi = ansi - ans[i] + ans[i+1];
        }
        return ansi;
}
int countSubstrings(string s) {
    
    map<char,vector<int>> m;
    int ans = 0;
    for(int i=0;i<s.size();i++){

        m[s[i]].push_back(i);
        for(auto it:m[s[i]]){
            ans = ans + is_palindrome(s,it,i);
        }
    }    
    return ans;    
}
bool is_dec(vector<ll>& nums){

    fr(0,nums.size()-1){

        if(nums[i]>nums[i+1]){
            return false;
        }

    }
    return true;
}
ll floor_find_ll(vec& arr,ll target){
        int start = 0;
        int end = arr.size() - 1;

        if(arr[0]>target){
            return -1;
        }
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(target < arr[mid]) {
                end = mid - 1;
            } 
            else if (target > arr[mid]) {
                start = mid + 1;
            } 
            else {
                return mid;
            }
        }
        return end;

}
ll ceil_find_ll(vec& arr,ll target){
        

        if (target > arr[arr.size() - 1]) {
            return -1;
        }
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end) {
            



            int mid = start + (end - start) / 2;

            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                

                return mid;
            }

        }
        return start;
}
void printi(ll n){
    cout<<1;
    if(n==1){
        return;
    }
    nline
    cout<<1<<" "<<1;
    if(n==2){
       return;
    }
    nline
    cout<<1<<" ";
    fr(1,n-1){
        cout<<0<<" ";
    }
    cout<<1;
    return;
}
ll lcm(ll a,ll b){

    return (a*b)/gcd(a,b);
}
void solve(){



}
int main(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif

    ll n;
    cin>>n;

    ll q;
    cin>>q;

    ll k;
    cin>>k;

    vec v(n);
    fr(0,n){
        cin>>v[i];
    }

    vec pref(n);
    pref[0] = (k-1);
    pref[n-1] = (k-1);
    if(n>1){
        pref[0] = (v[1]-1-1);
        pref[n-1] = (k-v[n-2]-1);
    }
    fr(1,n-1){
        pref[i] = (v[i]-v[i-1]-1)+(v[i+1]-v[i]-1);
    }

    fr(1,n){
        pref[i] = pref[i]+pref[i-1];
    }

    while(q--){

        ll l;
        cin>>l;

        ll r;
        cin>>r;

        l=l-1;
        r=r-1;



        if(l==r){
            cout<<(k-1);
        }
        else{

            ll ans1 = (v[l+1]-1-1)+(k-v[r-1]-1);
            ans1 = ans1 + pref[r-1]-pref[l];
            cout<<(ans1);
        }
        nline
        

    }

}
 










