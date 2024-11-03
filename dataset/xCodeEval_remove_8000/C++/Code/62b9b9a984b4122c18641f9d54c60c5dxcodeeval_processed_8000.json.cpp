













typedef long long ll;
typedef long long ull;
typedef long double ld;

using namespace std ;
const int mod = 1e9 + 7;
const long long oo = 1e16;
const double eps = pow(10 , -7);
bool id58(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second < b.second);
}
bool id55(string str1, string str2)
{
    

    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}



string findDiff(string str1, string str2)
{
    

    

    if (id55(str1, str2))
        swap(str1, str2);

    

    string str = "";

    

    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;

    

    int carry = 0;

    

    for (int i = n2 - 1; i >= 0; i--) {
        

        

        int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                   - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    

    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0) 

            str.push_back(sub + '0');
        carry = 0;
    }

    

    reverse(str.begin(), str.end());

    return str;
}
void bittemp(){
    string s,ans;cin>>s;
    int n = s.size();
    for (int i = 0; i < (1<<n); ++i) {
        string temp;
        for (int j = 0; j < n; ++j) {
            if(i & (1<<j)){
                temp+=s[j];
            }
        }
        string t2 = temp;
        std::reverse(t2.begin(), t2.end());
        if(t2 == temp){
            if(ans.size() == 0)ans=t2;
            else ans = max(ans,t2);
        }
    }
    cout<<ans;

}
ll fastpow(ll x,ll n){
    ll res = 1;
    while(n){
        if(n%2 != 0)
            res *= x;
        x = x*x;
        n /=2;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}



ll add(ll a,ll b,ll m)
{
    return ((a%m)+(b%m))%m;
}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
ll sub(ll a,ll b,ll m)
{
    return ((a%m)-(b%m)+m)%m;
}
int id51(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}
ll id41(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
bool getBit(ll num, int idx) {
    return ((num >> idx) & 1);
}

ll setBit(ll num, int idx, bool val) {
    return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}

ll flipBit(ll num, int idx) {
    return (num ^ (1LL << idx));
}

ll leastBit(ll num) {
    return (num & -num);
}
bool id14(ll num) {
    return (num & num - 1) == 0;
}

int id57(int S) {
    return S | S + 1;
}

int id36(int S) {
    return S & S - 1;
}

int id30(int S) {
    return S | S - 1;
}

int id27(int S) {
    return S & S + 1;
}

vector<int> id45(int mask) {
    vector<int> v;
    for (int subMask = mask;; subMask = (subMask - 1) & mask) {
        v.push_back(subMask);
        if (subMask == 0)
            break;
    }
    return v;
}



void factorization(){
    int n;
    cin>>n;
    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            cout<<i<<" ";
            if (i*i!=n)
            {
                cout<<n/i;
            }
            cout<<endl;
        }
    }

}


vector<ll> id16(ll n){
    vector<ll>v;
    for (int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            v.push_back(i);
        }
    }
    if (n!=1)
    {
        v.push_back(n);
    }
    return v;
}

void rad(){
    

    ll n, l =1;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        l = lcm(i,l);
    }
    cout<<l<<endl;
    ll g = 0;cin>>n;
    for (int i = 1; i <=n ; ++i) {
        g = gcd(g,i);
    }
    cout<<g<<endl;
}
int id37(int a, int b, int& x, int& y) {
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=id37(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
int modInverse(int A, int M){
    return id41(A,M-2,M);
}




bool judgePrime(ll x)
{
    if(x == 2)return true;
    if(x%2 == 0 ||x<2)return false;
    for (ll i = 3; i*i <= x ; i+=2) {
        if(x%i == 0)return false;
    }
    return true;
}


int id17(int start, int end, int val,int arr[]) {
    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] < val)		start= mid+1;
        else if(arr[mid] > val)	end  = mid-1;
        else					end  = mid;
    }
    return start;
}

int id2(int start, int end, int val,int arr[]) {
    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] < val)		start= mid+1;
        else if(arr[mid] > val)	end  = mid-1;
        else					start= mid;
    }
    return start;
}
ll id19(ll n)
{
    return ((n) * (n - 1)) / 2;
}


ll nCr(ll n, ll r){
    if(n==r || r==0)
        return 1;

    return nCr(n-1,r-1)+nCr(n-1,r);
}


ll NpR(ll n, ll r){
    const int mod = 1e9 + 7;
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    return ans;
}


ll CPer(ll n, ll r){
    const int mod = 1e9 + 7;
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++){
        ans *= i;
        if(ans %r == 0){
            ans /= r;
            r=1;
        }
    }
    return ans;
}
bool id18(string s){
    int i =0,j=s.size()-1;
    while(i<j){
        if(s[i++] != s[j--])return false;
    }
    return true;
}

const int id43 =0;
int id6, pardsu[id43], sizdsu[id43];
void init()
{
    for ( int i = 1 ; i <= id6 ;i++)
        pardsu[i] = i , sizdsu[i] = 1;
}
int findparent( int u)
{
    if(pardsu[u] == u)
        return  u;
    return pardsu[u] = findparent(pardsu[u]);
}


void connect( int u , int v)
{
    u = findparent(u);
    v = findparent(v);
    
    if(sizdsu[v] < sizdsu[u])
        pardsu[v] = u ,sizdsu[u] += sizdsu[v];
    else
        pardsu[u] = v,sizdsu[v] += sizdsu[u];
}
bool iscon( int u , int v)
{
    return (findparent(u) == findparent(v));
}
const ll NDijkstra = 0;
ll id38 , distDijkstra[NDijkstra], parDijkstra[NDijkstra];


vector < pair < ll , ll > > gDijkstra[NDijkstra];


void Dijkstra( int src)
{
    for ( int i = 1 ; i <= id38 ; i++)
        distDijkstra[i] = oo;
    distDijkstra[src] = 0;
    

    priority_queue< pair < ll , ll >, vector<pair < ll , ll >>, greater<pair < ll , ll >> > pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        ll node = pq.top().second , distance = pq.top().first;
        pq.pop();
        if(distance > distDijkstra[node]) {
            continue;
        }
        for(auto ch : gDijkstra[node])
        {
            if(distDijkstra[node] + ch.second < distDijkstra[ch.first])
            {
                parDijkstra[ch.first] = node;
                distDijkstra[ch.first] = distDijkstra[node] + ch.second;
                pq.push({distDijkstra[ch.first],ch.first});
            }
        }
    }
}
const ll id12 = 0, id26 = 1e18+7 ;
ll distBellman_Ford[id12] , id49;
vector < pair < ll , pair < int , int > > > id35;
bool negCycle = false;
void id52( int src)
{
    for ( int i = 1 ; i <= id49 ; i++)
        distBellman_Ford[i] = oo;
    distBellman_Ford[src] = 0;
    

    for(int lvl = 1 ; lvl <= id49 ; lvl++) {
        for(int j = 0; j < id35.size(); j++) {
            int u = id35[j].second.first, v = id35[j].second.second, w = id35[j].first;
            if (distBellman_Ford[u] + w < distBellman_Ford[v])
            {
                if(lvl == id49)
                    negCycle = true;
                distBellman_Ford[v] = distBellman_Ford[u] + w;
            }
        }
    }
}
ll const id25 = 1e18+10,id44 = 0;
ll dFloyd_Warshall[id44][id44];ll id40,id59;
void id33(){
    for (int i = 1; i <= id40; ++i) {
        for (int j = 1; j <= id40; ++j) {
            cin>>dFloyd_Warshall[i][j];
        }
    }
    for (int k = 1; k <= id40; ++k)
        for (int i = 1; i <= id40; ++i)
            for (int j = 1; j <= id40; ++j)
                dFloyd_Warshall[i][j] = min(dFloyd_Warshall[i][j], dFloyd_Warshall[i][k] + dFloyd_Warshall[k][j]);
    

}

const int Neular = 0 , id32 = 1e9;
int ineular[Neular], outeular[Neular],viseular[Neular],vis2[Neular];
vector < int > geular[Neular];
void direular( int node)
{
    for (auto ch:geular[node])
    {
        if(!viseular[ch]){
            viseular[ch]=1;
            direular(ch);
        }
    }
}
const int id4 = 0 , id23 = 1e9;
int visansundureular[id4] , degundureular[id4];
vector < pair < int , int > > undgeularg[id4];
vector < int > id28;
void id22( int node)
{
    while(!undgeularg[node].empty())
    {
        int v = undgeularg[node].back().second;
        int idx = undgeularg[node].back().first;
        undgeularg[node].pop_back();
        if(visansundureular[idx])
            continue;
        visansundureular[idx] = 1 ;
        id22(v);
    }
    id28.push_back(node);
}

int id10(vector<int>& v)
{
    if (v.size() == 0) 

        return 0;
    else if (v.size() == 1)return 1;
    vector<int> tail,inc(v.size(),1),dec(v.size(),1);
    tail.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
        auto b = tail.begin(), e = tail.end();
        auto it = lower_bound(b, e, v[i]);
        if (it == tail.end())
            tail.push_back(v[i]);
        else
            *it = v[i];
        inc[i] = max(inc[i],(int)tail.size());
    }
    return tail.size();
}

int id8(vector<vector<int>>& a)
{
    int n = a.size(),ans = id53;
    int db[200+5];
    for (int i = 0; i < n; ++i) {
        vector<int>temp(n,0);
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                temp[k]+=a[j][k];
            }
            int cur;
            db[0]=cur=temp[0];
            for (int k = 1; k < n; ++k) {
                db[k]= max(db[k-1]+temp[k],temp[k]);
                cur = max(cur,db[k]);
            }
            ans = max(ans,cur);
        }
    }
    return ans;
}

void id0(vector<vector<int>>arr){
    vector<vector<int>>pref(arr.size(),vector<int>(arr[0].size()));
    int n = pref.size();
    int m = pref[0].size();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pref[i][j] = arr[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pref[i][j] += pref[i][j-1];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pref[i][j] += pref[i-1][j];
        }
    }
}
void id42(vector<vector<int>>arr){
    int n,q;cin >> n >> q;
    ll a[1000+2][1000+2];
    for (int i = 1; i <= n;i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] += x * y;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            a[i][j] += a[i][j-1];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            a[i][j] += a[i-1][j];
        }
    }
    while (q--){
        int h1, w1, h2, w2;cin >> h1 >> w1 >> h2 >> w2;
        h2--;w2--;h1++;w1++;
        cout << a[h2][w2] - a[h1 - 1][w2] - a[h2][w1 - 1] + a[h1 - 1][w1 - 1] << '\n';
    }
}

const int NHash = 0, modHash = 1e9+7 , bHash = 29,id5 = 31;
int pwHash[NHash], pw2Hash[NHash], invHash[NHash], inv2Hash[NHash], prefHash[NHash], pref2Hash[NHash];
int id21( int b , int p)
{
    if(p == 0)
        return 1;
    int temp = id21(b, p /2);
    temp = mul(temp,temp,modHash);
    if(p&1)
        temp = mul(temp,b,modHash);
    return temp;
}


void preHash(){
    pwHash[0] = pw2Hash[0] = invHash[0] = inv2Hash[0] = 1;
    int mul_inv = id21(bHash, modHash - 2), id13 = id21(id5, modHash - 2);
    for(int i = 1; i < NHash; i++){
        pwHash[i] = mul(pwHash[i - 1], bHash,modHash);
        pw2Hash[i] = mul(pw2Hash[i - 1], id5,modHash);
        invHash[i] = mul(invHash[i - 1], mul_inv,modHash);
        inv2Hash[i] = mul(inv2Hash[i - 1], id13,modHash);
    }
}
int getHash( int l , int r)
{
    int ret = prefHash[r];
    if(l) ret = ((ll)ret - (ll)prefHash[l - 1] + (ll)modHash) % modHash;
    ret = mul(ret, invHash[l],modHash);
    return ret;
}
pair<int, int> get_hash(int l, int r){
    int ret = prefHash[r];
    if(l) ret = ((ll)ret - (ll)prefHash[l - 1] + (ll)modHash) % modHash;
    ret = mul(ret, invHash[l],modHash);
    int ret2 = pref2Hash[r];
    if(l) ret2 = ((ll)ret2 - (ll)pref2Hash[l - 1] + (ll)modHash) % modHash;
    ret2 = mul(ret2, inv2Hash[l],modHash);
    return {ret, ret2};
}
int id9( string& s)
{
    int cur = s[0] - 'a' + 1;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        int idx = add(cur, mul(pwHash[i], s[i] - 'a' + 1,modHash),modHash);
        ans = idx;
        cur =idx;
    }
    return ans;
}
pair<int,int> id11( string& s)
{
    int cur = s[0] - 'a' + 1,cur2 = s[0] - 'a' + 1;
    int ans = 0,ans2 = 0;
    for(int i = 1; i < s.size(); i++){
        int idx = add(cur, mul(pwHash[i], s[i] - 'a' + 1,modHash),modHash);
        ans = idx;
        cur =idx;
        int idx2 = add(cur2, mul(pw2Hash[i], s[i] - 'a' + 1,modHash),modHash);
        ans2 = idx2;
        cur2 =idx2;
    }
    return {ans,ans2};
}
void build_hash(string &s){
    int n = s.size();
    prefHash[0] = pref2Hash[0] = s[0] - 'a' + 1;
    for(int i = 1; i < n; i++){
        prefHash[i] = add(prefHash[i - 1], mul(pwHash[i], s[i] - 'a' + 1,modHash),modHash);
        pref2Hash[i] = add(pref2Hash[i - 1], mul(pw2Hash[i], s[i] - 'a' + 1,modHash),modHash);
    }
}
struct Node{
    Node *nxt[26];
    string mostacc;
    int acc;
    Node()
    {
        acc=0;
        memset(nxt,0,sizeof nxt);
    }
}*root;
void insert( string st)
{
    Node *cur = root;
    for( int i = 0 ; i < st.size();i++)
    {
        if(!cur->nxt[st[i]-'a']) {
            cur->nxt[st[i] - 'a'] = new Node();
        }
        cur = cur->nxt[st[i]-'a'];
    }
}
const int NSparse = 0, MSparse = 23;


int spSparse[NSparse][MSparse], aSparse[NSparse] , nSparse, lgSparse[NSparse];
void buildSparse()
{
    lgSparse[1] = 0;
    for ( int i = 2 ; i <= nSparse ; i++)
        lgSparse[i] = lgSparse[i/2] + 1;
    for ( int i = 0 ; i < nSparse ; i++) {
        spSparse[i][0] = aSparse[i];
    }
    for ( int bit = 1 ; bit < MSparse ; bit++)
        for ( int i = 0 ; i + (1<<bit) <= nSparse ; i++){
            spSparse[i][bit] = min(spSparse[i][bit-1] , spSparse[i+(1<<(bit-1))][bit-1]);
        }
}
int Querysum( int l , int r)
{
    int dist = r - l + 1;
    int sum = 0;
    for  (int bit = MSparse-1 ; bit >= 0 ; bit--)
    {
        if((1<<bit) <= dist)
        {
            dist -= (1<<bit);
            sum += spSparse[l][bit];
            l += (1<<bit);
        }
    }
    return sum;
}
int QueryMX( int l , int r)
{
    if(l>r)
        return 0;
    int j = lgSparse[r-l+1];
    return max(spSparse[l][j],spSparse[r-(1<<j)+1][j]);
}
int QueryMN( int l , int r)
{
    if(l>r)
        return 0;
    int j = lgSparse[r-l+1];
    return min(spSparse[l][j],spSparse[r-(1<<j)+1][j]);
}
int id20(int L, int R)
{
    int j = lgSparse[R - L + 1];
    return gcd(spSparse[L][j], spSparse[R - (1 << j) + 1][j]);
}
const int NLca = 0, MLca = 23,  id34 = 1e9 + 7;

int id56 , ancestorLca[NLca][MLca], lvlLca[NLca];
vector < int > gLca[NLca];

void id46( int node , int par)
{
    lvlLca[node] = lvlLca[par] + 1;
    ancestorLca[node][0] = par;
    for ( int j = 1 ; j < MLca ; j++)
    {
        int p = ancestorLca[node][j-1];
        ancestorLca[node][j] = ancestorLca[p][j-1];
    }
    for(auto ch : gLca[node])
    {
        if(ch == par)
            continue;
        id46(ch,node);
    }
}

int id7( int u , int k)
{
    for ( int j = MLca-1 ; j >= 0 ; j--)
        if(k&(1<<j))
            u = ancestorLca[u][j];
    return u;
}

int id47( int u , int v)
{
    if(lvlLca[u] < lvlLca[v])
        swap(u,v);
    u = id7(u,lvlLca[u]-lvlLca[v]);
    if ( u == v)
        return u;
    for ( int i = MLca-1 ; i>= 0 ;i--)
    {
        if(ancestorLca[u][i] == ancestorLca[v][i])
            continue;
        u = ancestorLca[u][i];
        v = ancestorLca[v][i];
    }
    return ancestorLca[u][0];
}
const int id54 = 0;
int treesegmant[id54<<2] , asegmant[id54];



void id50(int node , int l , int r){

    if( l == r)
    {
        treesegmant[node]=asegmant[l];
        return;
    }
    int md = l + r >> 1;
    id50(node * 2 , l , md);
    id50(node * 2 + 1, md+1,r);
    

    treesegmant[node] = treesegmant[node * 2] ^ treesegmant[node * 2 + 1];
}

void id39(int node , int l,  int r , int idx , int val){

    if(l == r){
        treesegmant[node] = val;
        return;
    }
    ll mid = (l + r) >> 1;
    if(idx <= mid) id39(node*2, l, mid, idx, val);
    else id39(node*2+1, mid+1, r, idx, val);
    treesegmant[node] = treesegmant[node*2] ^ treesegmant[node*2+1];
}


int id15(int node, int l , int r , int s , int e){
    if(l > e || r < s)
        return 0;
    

    if ( l >= s and r <= e) {
        return treesegmant[node];
    }
    int md = l + r >> 1 ;
    auto a =id15(node*2,l,md,s,e);
    auto b = id15(node*2+1,md+1,r,s,e);
    return a^b;
}

const int id1 = 0;
ll treeLazyProp[id1<<2], alazyProp[id1], lazyProp[id1<<2];

void id24( int node , int l , int r)
{
    lazyProp[node] = treeLazyProp[node] = 0;
    if( l == r) {
        treeLazyProp[node]=alazyProp[l];
        return;
    }
    int md = l + r >> 1 ;
    id24(node<<1,l,md),id24((node<<1) + 1,md+1,r);
    treeLazyProp[node] = treeLazyProp[node<<1] + treeLazyProp[(node<<1) + 1];
}

void id29( int node , int l , int r )
{
    if(lazyProp[node] == 0)
        return;
    treeLazyProp[node] = abs(treeLazyProp[node] - (r- l + 1));
    if(l != r) {
        lazyProp[node << 1] = lazyProp[node<<1]?0:1;
        lazyProp[(node << 1) + 1] = lazyProp[(node<<1) + 1 ] ?0:1;
    }
    lazyProp[node] = 0;
}

void id48( int node , int l , int r , int s , int e,int val)
{
    id29(node,l,r);
    if ( l > e || r < s)
        return ;
    if ( l >= s and r <= e)
    {
        lazyProp[node] = val;
        id29( node , l, r);
        return;
    }
    int md = l + r >> 1 ;
    id48(node<<1,l,md,s,e,val),id48((node<<1)+1,md+1,r,s,e,val);
    treeLazyProp[node] = treeLazyProp[node<<1] + treeLazyProp[(node<<1) + 1];
}

ll id31( int node , int l , int r , int s , int e)
{
    id29(node,l,r);
    if ( l > e || r < s)
        return 0;
    if ( l >= s and r <= e)
        return treeLazyProp[node];
    int md = l + r >> 1 ;
    return id31(node<<1,l,md,s,e)+id31((node<<1) + 1,md+1,r,s,e);
}
long long id60(long long N)
{
    

    if (!(N & (N - 1)))
        return N;
    

    return 0x8000000000000000 >> (__builtin_clzll(N) - 1);
}
long long id3(long long N)
{
    if (!(N & (N - 1)))
        return N;
    return (id60(N)>>1);
}
void fast () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool valid(int i,int j,int& n,int& m){
    if(i>=0&&i<n&&j>= 0 && j<m)return true;
    return 0;
}
int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = { 0, 1, -1, 0, -1, 1, 1, -1};

int32_t main() {
    fast();
    

    int t=1;cin>>t;
    vector<vector<int>>co(1000+10);
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            if(gcd(i,j) == 1)co[i].push_back(j);
        }
    }
    for(int tcc = 1; tcc <= t;tcc++) {
        int n;cin>>n;
        vector<int>a(n);
        vector<int>b(1000+10);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            b[a[i]]=i;
        }
        int mxsum = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < co[a[i]].size(); ++j) {
                if(b[co[a[i]][j]]!=0){
                    mxsum= max(mxsum,b[co[a[i]][j]]+1+i+1);
                }
            }
        }
        cout<<mxsum<<"\n";
    }
}