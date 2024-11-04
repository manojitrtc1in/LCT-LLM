























using namespace std;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
bool comp_desc(pair<ll,ll> a,pair<ll,ll> b){
    return a.second > b.second ;
}
ll id5(vec& v, ll key){

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


        






















































































bool id4(string s,int start,int end){
    if(start==end){
        return 1;
    }
    string p = s.substr(start,(end-start+1));
    string h = p;
    reverse(p.begin(),p.end());
    return p==h;
}
ll id9(vec& arr,ll key){
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
ll id0(vec& arr,ll key){
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


int id7(int n) { 

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
void id10(ll src , ll par,vector<vec>& tree,vector<vec>& up){
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
            id10(it,src,tree,up);
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
ll id2(ll u, ll v,vector<vec>& up,vec& lvl){  
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
int maxProfit(vector<int>& id6) {

        int n1 = id6.size();
        if(n1==1){
            return 0;
        }
    
        vector<int> prices;
        prices.push_back(id6[0]);
        for(int i=1;i<n1;i++){
            if(id6[i-1]!=id6[i]){
                prices.push_back(id6[i]);
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
int id1(string s) {
    
    map<char,vector<int>> m;
    int ans = 0;
    for(int i=0;i<s.size();i++){

        m[s[i]].push_back(i);
        for(auto it:m[s[i]]){
            ans = ans + id4(s,it,i);
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
ll id3(vec& arr,ll target){
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
ll id8(vec& arr,ll target){
        

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
ll maxim(ll n1){

    if(n1%2==0){
        return (n1-2)/2;
    }
    return (n1-1)/2;

}
ll re(vec& pref,ll count,ll j){

    ll n = pref.size()-1;
    if(count>n){

        if(j==0){
            ll o = (count)-(count)/4;
            return (pref[n]-pref[max(0ll,n-o)]);
        }
        else{

            ll p1 = (count)-(count)/4;
            if(p1<=(count-n)){
                return (p1*100);
            }
            else{

                ll u = count - n;
                ll req = p1-u;
                return (u)*100 + (pref[n]-pref[n-req]);
            }
        }
    }
    else{
        ll o = (count)-(count)/4;
        return (pref[n]-pref[n-o]);
    }
}

bool link(char c,char s,map<char,char>& m,unordered_set<char>& s2){

    if(s2.size()==25){
        return false;
    }

    while(s2.find(c)!=s2.end()){
        c = m[c];
        if(c==s){
            return true;
        }
    }

    return false;

}
void solve(){

    ll n;
    cin>>n;

    ll x;
    cin>>x;

    mapi m;

    fr(0,n){

        ll x1;
        cin>>x1;
        m[x1]++;

    }
    f_a(m,it){

        if(it.second<=0){
            continue;
        }

        if(m[x*it.first]>0 && m[it.first]>0){
            ll p = min(m[it.first],m[x*it.first]);
            m[it.first] = m[it.first]-p;
            m[x*it.first] = m[x*it.first] - p;
        }
        if((it.first)%x==0 && m[(it.first)/x]>0 && m[it.first]>0){
            ll p = min(m[it.first],m[(it.first)/x]);
            m[it.first] = m[it.first]-p;
            m[(it.first)/x] = m[(it.first)/x] - p;
        }
    }

    ll count = 0;
    f_a(m,it){
        if(it.second>0){
            count = count + it.second;
        }
    }
    cout<<(count);
}   
int main(){
    fast_io;
    
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    
    ll t;
    cin>>t;
    while(t--){
        solve();
        nline
    }
}












