#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <bits/stdc++.h>

typedef long long ll;
typedef long long ull;
typedef long double ld;
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
using namespace std ;
bool sortbysec(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second < b.second);
}
bool isSmaller(string str1, string str2)
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
    

    

    if (isSmaller(str1, str2))
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
int binaryExponentiation(int x,int n)
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
ll modularExponentiation(ll x,ll n,ll m)
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
bool isPowerOfTwo(ll num) {
    return (num & num - 1) == 0;
}

int turnOnLastZero(int S) {
    return S | S + 1;
}

int turnOffLastBit(int S) {
    return S & S - 1;
}

int turnOnLastConsecutiveZeroes(int S) {
    return S | S - 1;
}

int turnOffLastConsecutiveBits(int S) {
    return S & S + 1;
}

vector<int> genAllSubmask(int mask) {
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


vector<ll> primeFactorization(ll n){
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
int extendedEuclid(int a, int b, int& x, int& y) {
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extendedEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
int modInverse(int A, int M){
    return modularExponentiation(A,M-2,M);
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


int BSfindFirst(int start, int end, int val,int arr[]) {
    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] < val)		start= mid+1;
        else if(arr[mid] > val)	end  = mid-1;
        else					end  = mid;
    }
    return start;
}

int BSfindLast(int start, int end, int val,int arr[]) {
    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] < val)		start= mid+1;
        else if(arr[mid] > val)	end  = mid-1;
        else					start= mid;
    }
    return start;
}



ll nCr(ll n, ll r){
    ll ans = 1;
    ll div = 1; 

    for (ll i = r + 1; i <= n; i++){
        ans = ans * i;
        ans /= div;
        div++;
    }
    return ans;
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
bool isPali(string s){
    int i =0,j=s.size()-1;
    while(i<j){
        if(s[i++] != s[j--])return false;
    }
    return true;
}
ll oo = 1e9+7;

const int Ndsu =0;
int szdsu, pardsu[Ndsu], sizdsu[Ndsu];
void init()
{
    for ( int i = 1 ; i <= szdsu ;i++)
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
ll nDijkstra , distDijkstra[NDijkstra], parDijkstra[NDijkstra];


vector < pair < ll , ll > > gDijkstra[NDijkstra];


void Dijkstra( int src)
{
    for ( int i = 1 ; i <= nDijkstra ; i++)
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
const ll NBellman_Ford = 0, ooBellman_Ford = 1e18+7 ;
ll distBellman_Ford[NBellman_Ford] , nBellman_Ford;
vector < pair < ll , pair < int , int > > > edgesBellman_Ford;
bool negCycle = false;
void Bellman_Ford( int src)
{
    for ( int i = 1 ; i <= nBellman_Ford ; i++)
        distBellman_Ford[i] = oo;
    distBellman_Ford[src] = 0;
    

    for(int lvl = 1 ; lvl <= nBellman_Ford ; lvl++) {
        for(int j = 0; j < edgesBellman_Ford.size(); j++) {
            int u = edgesBellman_Ford[j].second.first, v = edgesBellman_Ford[j].second.second, w = edgesBellman_Ford[j].first;
            if (distBellman_Ford[u] + w < distBellman_Ford[v])
            {
                if(lvl == nBellman_Ford)
                    negCycle = true;
                distBellman_Ford[v] = distBellman_Ford[u] + w;
            }
        }
    }
}
ll const ooFloyd_Warshall = 1e18+10,NFloyd_Warshall = 0;
ll dFloyd_Warshall[NFloyd_Warshall][NFloyd_Warshall];ll nFloyd_Warshall,mFloyd_Warshall;
void Floyd_Warshall(){
    for (int i = 1; i <= nFloyd_Warshall; ++i) {
        for (int j = 1; j <= nFloyd_Warshall; ++j) {
            cin>>dFloyd_Warshall[i][j];
        }
    }
    for (int k = 1; k <= nFloyd_Warshall; ++k)
        for (int i = 1; i <= nFloyd_Warshall; ++i)
            for (int j = 1; j <= nFloyd_Warshall; ++j)
                dFloyd_Warshall[i][j] = min(dFloyd_Warshall[i][j], dFloyd_Warshall[i][k] + dFloyd_Warshall[k][j]);
    

}

const int Neular = 0 , infeular = 1e9;
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
const int Nundureular = 0 , infundureular = 1e9;
int visansundureular[Nundureular] , degundureular[Nundureular];
vector < pair < int , int > > undgeularg[Nundureular];
vector < int > ansundureular;
void undureular( int node)
{
    while(!undgeularg[node].empty())
    {
        int v = undgeularg[node].back().second;
        int idx = undgeularg[node].back().first;
        undgeularg[node].pop_back();
        if(visansundureular[idx])
            continue;
        visansundureular[idx] = 1 ;
        undureular(v);
    }
    ansundureular.push_back(node);
}

int LongestIncreasingSubsequenceLength(vector<int>& v)
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

int maxSubArraySum(vector<vector<int>>& a)
{
    int n = a.size(),ans = INT32_MIN;
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

void pref2d(vector<vector<int>>arr){
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
void pref2d2(vector<vector<int>>arr){
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

const int NHash = 0, modHash = 1e9+7 , bHash = 29,b2Hash = 31;
int pwHash[NHash], pw2Hash[NHash], invHash[NHash], inv2Hash[NHash], prefHash[NHash], pref2Hash[NHash];
int fphash( int b , int p)
{
    if(p == 0)
        return 1;
    int temp = fphash(b, p /2);
    temp = mul(temp,temp,modHash);
    if(p&1)
        temp = mul(temp,b,modHash);
    return temp;
}


void preHash(){
    pwHash[0] = pw2Hash[0] = invHash[0] = inv2Hash[0] = 1;
    int mul_inv = fphash(bHash, modHash - 2), mul_inv2 = fphash(b2Hash, modHash - 2);
    for(int i = 1; i < NHash; i++){
        pwHash[i] = mul(pwHash[i - 1], bHash,modHash);
        pw2Hash[i] = mul(pw2Hash[i - 1], b2Hash,modHash);
        invHash[i] = mul(invHash[i - 1], mul_inv,modHash);
        inv2Hash[i] = mul(inv2Hash[i - 1], mul_inv2,modHash);
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
int getHashs( string& s)
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
pair<int,int> getHashs2( string& s)
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
const int NSparse = 2e5+10, MSparse = 23;


int spSparse[NSparse][MSparse], aSparse[NSparse] , nSparse, lgSparse[NSparse];
int spSparse2[NSparse][MSparse];
void buildSparse()
{
    lgSparse[1] = 0;
    for ( int i = 2 ; i <= nSparse ; i++)
        lgSparse[i] = lgSparse[i/2] + 1;
    for ( int i = 0 ; i < nSparse ; i++) {
        spSparse[i][0] = aSparse[i];
    }
    for ( int i = 0 ; i < nSparse ; i++) {
        spSparse2[i][0] = aSparse[i];
    }
    for ( int bit = 1 ; bit < MSparse ; bit++)
        for ( int i = 0 ; i + (1<<bit) <= nSparse ; i++){
            spSparse[i][bit] = min(spSparse[i][bit-1] , spSparse[i+(1<<(bit-1))][bit-1]);
            spSparse2[i][bit] = max(spSparse2[i][bit-1] , spSparse2[i+(1<<(bit-1))][bit-1]);
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
    return max(spSparse2[l][j],spSparse2[r-(1<<j)+1][j]);
}
int QueryMN( int l , int r)
{
    if(l>r)
        return 0;
    int j = lgSparse[r-l+1];
    return min(spSparse[l][j],spSparse[r-(1<<j)+1][j]);
}
int querygcd(int L, int R)
{
    int j = lgSparse[R - L + 1];
    return gcd(spSparse[L][j], spSparse[R - (1 << j) + 1][j]);
}
int main() {
    fast();
    

    int t=1;cin>>t;
    while (t--) {
        int q;cin>>nSparse>>q;
        string s;cin>>s;
        if(s[0]=='-')aSparse[0] = -1;
        else aSparse[0] = 1;
        for(int i = 1;i<nSparse;i++)
        {
            aSparse[i] = aSparse[i-1] + (s[i]=='+'?1:-1);
        }
        buildSparse();
        while (q--){
            int mn = 0,mx = 0;
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(l == 0 && r == nSparse-1){
                cout<<1<<'\n';
                continue;
            }
            mn = min(mn,QueryMN(0,l-1));
            mx = max(mx, QueryMX(0,l-1));
            int tmn = QueryMN(r+1,nSparse-1);
            int range = aSparse[r];
            if(l!=0)
                range-=aSparse[l-1];
            tmn-=(range);
            int tmx = QueryMX(r+1,nSparse-1);
            tmx-=(range);
            if(r+1<nSparse) {
                mn = min(mn, tmn);
                mx = max(mx, tmx);
            }

            cout<<mx-mn+1<<'\n';
        }
    }
}