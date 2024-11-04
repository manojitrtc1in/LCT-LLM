























using namespace std;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
bool comp_desc(pair<ll,ll> a,pair<ll,ll> b){
    return a.second > b.second ;
}
bool comp_d(pair<ll,ll> a,pair<ll,ll> b){

    if(a.first==b.first){
       return a.second<b.second ;
    }
    return a.first<b.first;
}
ll id7(vec& v, ll key){

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


        






















































































bool id6(string s,int start,int end){
    if(start==end){
        return 1;
    }
    string p = s.substr(start,(end-start+1));
    string h = p;
    reverse(p.begin(),p.end());
    return p==h;
}
ll id11(vec& arr,ll key){
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
ll id2(vec& arr,ll key){
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


int id9(int n) { 

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
void id12(ll src , ll par,vector<vec>& tree,vector<vec>& up){
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
            id12(it,src,tree,up);
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
ll id4(ll u, ll v,vector<vec>& up,vec& lvl){  
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
int maxProfit(vector<int>& id8) {

        int n1 = id8.size();
        if(n1==1){
            return 0;
        }
    
        vector<int> prices;
        prices.push_back(id8[0]);
        for(int i=1;i<n1;i++){
            if(id8[i-1]!=id8[i]){
                prices.push_back(id8[i]);
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
int id3(string s) {
    
    map<char,vector<int>> m;
    int ans = 0;
    for(int i=0;i<s.size();i++){

        m[s[i]].push_back(i);
        for(auto it:m[s[i]]){
            ans = ans + id6(s,it,i);
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
ll id5(vec& arr,ll target){
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
ll id10(vec& arr,ll target){
        

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
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
bool id0(ll x){
    if(x==0){
        return true;
    }

    ll low = 1, high = x, ans = 1;
 
    while(low<=high){
        

        double mid = (low+high)/2;
        if(mid*mid<=x){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
 
    return ((ans*ans)==x)?1:0;

}

bool ischeck(ll x){

    if(id0(x)){
        return false;
    }

    for(ll i=2;i*i<=x;i++){

        if(x%i==0){

            if(id0(i)||id0(x/i)){
                return false;
            }

        }

    }
    return true;

}
ll get_pp(ll n,ll k){

    ll i = 0;

    ll base = 1;

    while(base<=n){

        base = base * k;
        i=i+1;
    }


    return (i-1);
}
bool comps(pair<pair<ll,ll>,ll> a , pair<pair<ll,ll>,ll> b){

    pair<ll,ll> p1 = a.first;
    pair<ll,ll> p2 = b.first;

    if(p1.first==p2.first){
        return (p2.second>p1.second);
    }
    return (p1.first>p2.first);
}

ll cou(ll n,ll k){

    ll count = 0;
    while(n%k==0){
        n = n / k;
        count++;
    }
    return count;
}

void help(ll n){

    if(n<0){
        return;
    }
    if(id0(n-1)){
        for(ll j=(n-1);j>=0;j--){
            cout<<(j)<<" ";
        }
        return;
    }

    fr(0,n){
        if(id0(n+i-1)){
            

            

            

            help(i);
            ll j = (n-1);
            while(i<(n) && j>=0){
                cout<<(j)<<" ";
                i++;
                j--;
            }
            return;
        }
    }

    cout<<(-1);
    return;
}

ll right_bit(ll n){

    for(ll j=31;j>=1;j--){

        if((n & (1<<(j-1)))){
            return j;
        }
    }

    return -1;
}

ll ans(ll i1,ll i2,ll n1,ll n2,vec& v1,vec& v2,vector<vec>& dp){

    if(i1==n1 || i2==n2){
        return 0;
    }

    if(dp[i1][i2]!=-1){
        return dp[i1][i2];
    }

    ll c1 = ans(i1+1,i2+1,n1,n2,v1,v2,dp);
    ll c2 = ans(i1,i2+1,n1,n2,v1,v2,dp);
    ll c3 = ans(i1+1,i2,n1,n2,v1,v2,dp);

    ll c4 = (abs(v1[i1]-v2[i2])<=1)+ans(i1+1,i2+1,n1,n2,v1,v2,dp);

    c4 = max(c1,c4);
    c4 = max(c2,c4);
    c4 = max(c3,c4);

    return dp[i1][i2]=c4;
}

ll operation(ll n){

    ll temp = n;
    ll last_ind = -1;
    fr(0,32){
        if(temp & (1<<i)){
            last_ind = i;
        }
    }
    if(last_ind==-1){
        return 0;
    }

    fr(0,last_ind+1){
        if(temp & (1<<i)){
            rem_bit(temp,i+1);
        }
        else{
            add_bit(temp,i+1);
        }
    }
    return temp;
}
bool id1(ll n){

    ll count = 0;
    fr(0,32){
        if(n & (1<<i)){
            count++;
        }
    }
    return (count==1);
}
bool check(ll n){
    for(ll j=3;j*j<n;j++){
        if(n%j==0){
            if((n/j)%2!=0 || (j)%2!=0 ){
                if(id1(n/j) || id1(j)){
                    return true;
                }
            }
        }
    }
    return false;
}
void solve(){

    vector<vector<ll>> v(200001,vec(19,0));
    v[1][0] = 1;

    fr(2,200001){
        for(ll j=0;j<19;j++){
            v[i][j] = v[i-1][j];
            if(i & (1<<j)){
                v[i][j]++;
            }
        }
    }

    ll t;
    cin>>t;

    while(t--){

        ll l;
        cin>>l;

        ll r;
        cin>>r;

        ll ans = 0;

        fr(0,19){
            ans = max(ans,v[r][i]-v[l-1][i]);
        }

        cout<<(r-l+1-ans);
        nline
    }

}
int main(){
    fast_io;
    
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    
 
    solve();

    

    

    

    

    

    


}



















































