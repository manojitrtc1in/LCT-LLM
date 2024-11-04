#include <bits/stdc++.h>
#include <iostream>
using namespace std;



#define ll long long
#define ul unsigned long long
#define dl long double
#define LMax LLONG_MAX;
#define LMin LLONG_MIN;

#define pb push_back
#define pf push_front
#define pr pair<ll,ll>

#define Min(v) *min_element(v.begin(),v.end())
#define Max(v) *max_element(v.begin(),v.end())
#define Sum(v, k) accumulate(v.begin(),v.end(), k)
#define Cnt(v, x) count(v.begin(), v.end(), x)
#define Mid(a,b) (a + (b-a)/2)
#define ToNum(c) (c - '0')
#define ToChar(c) (c + '0')

const dl PI = 3.141592653589793238;
const ll MOD = 1e9+7;

#define PY cout<<"YES"<<endl
#define PN cout<<"NO"<<endl
#define PM cout<<-1<<endl
#define P1 cout<< 1<<endl
#define P0 cout<< 0<<endl

void Print(ll x){ cout << x << endl; }
void Print(ll x, ll y){ cout << x << " " << y << endl; }
void Print(ll x, ll y, ll z){ cout << x << " " << y << " " << z << endl; }
void Print(string &s){ cout << s << endl; }
void Print(bool flag){ cout << flag << endl; }


#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Akash cout.tie(NULL);

void input(vector<ll> &v,ll n){ for(ll i=0;i<n;i++) cin>>v[i]; }
void output(vector<ll> &v,ll n){ for(ll i=0;i<n;i++) cout<<v[i]<<" "; }
bool isP2(ll n){ return  __builtin_popcountll(n) == 1; }
bool isEven(ll n){ return (n&1) ? 0 : 1; }
bool isOdd(ll n){ return (n&1) ? 1 : 0; }
int getMSB(ll n){ return (int)(log2(n)); }
int getLSB(ll n){ return log2(n & -n); }
int getTSB(ll n){ return  __builtin_popcountll(n); }
bool getBit(ll &n, int pos) { return n & (1 << pos); }
void setBit(ll &n, int pos) { n = n | (1 << pos); }
void clearBit(ll &n, int pos){ n = n & ~(1 << pos); }

int countSetBits(ll n){  

    
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

vector<ll> getLPS(string pat)
{
    ll len = pat.size();
    vector<ll> lps(len); 
 
    lps[0] = 0;
    ll i=0,j=1;
 
    while(j < len) {
        if (pat[i] == pat[j]) {
            lps[j] = i+1;
            i++; 
            j++;
        }
        else 
        {
            if (i != 0)
                i = lps[i - 1];
            else 
            {
                lps[j] = 0;
                j++;
            }
        }
    }
    
    return lps;
}

vector<ll> KMPSearch(string pat, string txt) 

{                                            

    ll M = pat.size();
    ll N = txt.size();
    
    vector<ll> Idx;
    vector<ll> lps = getLPS(pat);
 
    int i = 0; 

    int j = 0; 

    
    while(i<N){
        if (pat[j] == txt[i]){
            j++;
            i++;
        }
 
        if (j == M) {
            Idx.pb(i - j);
            j = lps[j - 1];
        }
 
        else if (i < N && pat[j] != txt[i]){
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    
    return Idx;
}

string buildString(char k, ll n)
{
    string t = "";
    while(n--) t += k;
    return t;
}

string buildString(string s, ll n)
{
    string t = "";
    while(n--) t += s;
    return t;
}



bool isupper(char c){ return c>='A' && c<='Z'; }
bool islower(char c){ return c>='a' && c<='z'; }
bool isdigit(char c){ return c>='0' && c<='9'; }
bool isalpha(char c){ return isupper(c) | islower(c); }
bool isalnum(char c){ return isalpha(c) | isdigit(c); }
bool isspecial(char c){ return !isalnum(c); }

void transpose(vector<vector<ll>> &Mat)
{
    ll R = Mat.size(), C = Mat[0].size();
    
    for (ll i = 0; i < R; i++)
		for (ll j = i+1; j < C; j++)
			swap(Mat[i][j], Mat[j][i]);
}

void reverseColumns(vector<vector<ll>> &Mat)
{
    ll R = Mat.size(), C = Mat[0].size();

    for (ll i = 0; i < C; i++)
        for (ll j = 0, k = C - 1; j < k; j++, k--)
            swap(Mat[j][i], Mat[k][i]);
}

void reverseRows(vector<vector<ll>> &Mat)
{
    ll R = Mat.size(), C = Mat[0].size();

    for (ll i = 0; i < R; i++) {
        ll start = 0;
        ll end = C - 1;
 
        while (start < end) {
            swap(Mat[i][start],Mat[i][end]);
            start++;
            end--;
        }
    }
}

void rotateMatrixAntiClockwise(vector<vector<ll>> &Mat)
{
    transpose(Mat); 
    reverseColumns(Mat);
}

void rotateMatrixClockwise(vector<vector<ll>> &Mat)
{
    transpose(Mat); 
    reverseRows(Mat);
}

ll countPrimes(vector<ll> &primes, ll n){ 

                                         



	
	bool isPrime[n+1];
	
	for(int i=0;i<=n;i++){
		isPrime[i] = true;
	}
	





	for(ll i=2;i*i<=n;i++)
		if(isPrime[i] == true)
			for(ll j=i*i;j<=n;j+=i)
				isPrime[j] = false;

	ll count = 0;
	
	primes.push_back(2);


    for(ll i=3;i<=n;i+=2)
		if(isPrime[i] == true){
		    primes.push_back(i);
			count++;
		}

	return count;
}

ll segmentedSieve(vector<ll> &ans, ll low, ll high)
{
    vector<ll> primes; ll Count = 0;
    countPrimes(primes, (ll)floor(sqrt(high)));
    vector<ll> isPrime(high - low + 1, true);

    for(ll p : primes){
        ll l = low / p * p; 

        if(l < low) l += p;

        for(ll i = l; i <= high; i += p)
           isPrime[i - low] = false;
    }

    for (ll i = 0; i < isPrime.size(); i++) 
        if (isPrime[i]){
          ans.push_back(i + low);
          Count++;
    }
    
    return Count;
}

ll fastPower(ll A, ll B, ll C){ 

                                

    if(A == 0) return 0;
    if(B == 0) return 1;
 
    ll y;
    
    if (B % 2 == 0) {
        y = fastPower(A, B / 2, C);
        y = (y * y) % C;
    }
    else {
        y = A % C;
        y = (y * fastPower(A, B - 1, C)) % C;
    }
 
    return (ll)((y + C) % C); 

}

ll findAllFactors(ll n,vector<ll>& factors){
    for(ll i=1;i<=sqrt(n);i++)
        if(n%i == 0){
            factors.push_back(i);
            if(n/i != i)
                factors.push_back(n/i);
        }
    
    return factors.size();
}

ll factorialDivisors(int n){
    
    vector<ll> primes;
    int len = countPrimes(primes,n);

	ll result = 1;
	
	for(int i=0;i<len;i++){
		int k = primes[i];
		ll count = 0;
		while((n/k)!=0){
			count = (count + (n/k))%MOD;
			k = k*primes[i];
		}
		result = (result * ((count+1)%MOD))%MOD;
	}
	
	return result;
}

bool isPalindrome(string s){
	string rev = s;
	reverse(s.begin(),s.end());
	return rev==s;
}

bool isInteger(ll x, ll y){
	return ceil((double)x/y)==floor((double)x/y);
}

bool find(vector<ll>& v, ll x){
    return Cnt(v,x)>=1;
}

ll getSum(ll n){ 

    
    ll Sum = 0;
    while(n) Sum += n % 10, n = n / 10;
    return Sum;
}
string DTB(ll n){
    int p = (int)(log2(n));
    return bitset<64>(n).to_string().substr(63 - p);
}
ll BTD(string n){
    return stoi(n, 0, 2);
}
ll fact(const ll &n){ 

    if (n <= 1) return 1;
    return n * fact(n - 1);
}

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

ll nPr(ll n, ll r)
{
    return fact(n) / fact(n - r);
}

bool isPrime(const ll &n){ 

    if (n == 4) return 0;
    return bool(fact(n >> 1) % n);
}
bool isCoprime(ll a, ll b) {
    return __gcd(a, b) == 1; 
}
bool isVowel(char c){
    

    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
       return 1;
    return 0;
}

ll getManhattanDistance(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x2-x1) + abs(y2-y1);
}

dl getEuclideanDistance(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0) { *x = 0, *y = 1; return b; }
    
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

ll modInverse(ll b)
{
    ll x, y;
    ll g = gcdExtended(b, MOD, &x, &y); 
 
    

    if (g != 1) return -1;
 
    

    return (x%MOD + MOD) % MOD;
}

ll modInverseF(ll b){ 

    
     return __gcd(b,MOD)==1 ? fastPower(b, MOD-2, MOD): -1; 
}

pair<ll,ll> findMaxInMap(map<ll,ll> &Mp){
    ll Ele, Max = LLONG_MIN;
    
    for(auto i:Mp)
        if(i.second>Max){ 

            Max = i.second;
            Ele = i.first;
        }
    
    return make_pair(Ele, Max);
}

pair<ll,ll> findCnt1Z(string &str){
    ll C1=0,CZ=0;
    
    for(auto i:str){
        if(i=='1') C1++;
        else CZ++;
    }
    
    return make_pair(CZ, C1);
}

string decToBinary(ll n){
    
    string s ="";
    
    for(int i = 63; i >= 0; i--) {
        int k = n >> i;
        if(k & 1)
            s += '1';
        else
            s += '0';
    }
    return s;
}

ll ModAdd(ll a,ll b){ return ((a%MOD)+(b%MOD))%MOD; }
ll ModSub(ll a,ll b){ return (a%MOD - b%MOD + MOD)%MOD; }
ll ModMul(ll a,ll b){ return ((a%MOD)*(b%MOD))%MOD; }
ll ModDiv(ll a,ll b) 

{
    

    ll INV = modInverseF(b);   

    return (INV == -1) ? -1 : (INV * a % MOD) % MOD;
}


ll GCD(ll a, ll b){if (!b)return a;return GCD(b, a % b);}  

ll LCM(ll a, ll b){return (a*b/GCD(a,b));}

bool isSorted(vector<ll> &v){
    
    ll n = v.size();
    
    for(ll i=1;i<n;i++){
        if(v[i]<v[i-1])
          return false;
    }
    
    return true;
}

class Node {
    public:
        ll data;
        Node* left;
        Node* right;

    Node() {
        this -> data = 0;
        this -> left = NULL;
        this -> right = NULL;
    }
    
    Node(ll data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
    
    Node(ll data, Node* left, Node* right) {
        this -> data = data;
        this -> left = left;
        this -> right = right;
    }
};

void preorderTraversal(Node* root,vector<ll>& preorder) 
{
    if(!root) return; 
    preorder.push_back(root->data); 
    preorderTraversal(root->left, preorder); 
    preorderTraversal(root->right, preorder); 
}

void inorderTraversal(Node* root, vector<ll>& inorder)
{
    if(!root) return; 
    inorderTraversal(root->left, inorder); 
    inorder.push_back(root->data); 
    inorderTraversal(root->right, inorder);
}

void postorderTraversal(Node* root,vector<ll>& postorder)
{
    if(!root) return;
    postorderTraversal(root->left, postorder); 
    postorderTraversal(root->right, postorder); 
    postorder.push_back(root->data); 
}

 void dfsTree(Node* root, vector<ll> &pre,vector<ll> &in, vector<ll> &post) 
 {
    if(!root) return;

    stack<pair<Node*,ll>> st; 
    st.push({root, 1}); 

    while(!st.empty()) {
        auto it = st.top(); 
        st.pop(); 
        
        if(it.second == 1) {
            pre.push_back(it.first->data); 
            it.second++; 
            st.push(it); 

            if(it.first->left != NULL)
                st.push({it.first->left, 1}); 
        }

        else if(it.second == 2) {
            in.push_back(it.first->data); 
            it.second++; 
            st.push(it); 

            if(it.first->right != NULL)
                st.push({it.first->right, 1}); 
        }
        else 
            post.push_back(it.first->data);
    }
}

void levelOrderTraversal(Node* root, vector<vector<ll>>& ans)
{
    if(!root) return;
    
    queue<Node*> q; 
    q.push(root); 
    
    while(!q.empty()) {
        ll size = q.size();
        vector<ll> level; 
        for(ll i=0; i<size; i++) {
            Node *node = q.front(); 
            q.pop(); 
            if(node->left != NULL) q.push(node->left); 
            if(node->right != NULL) q.push(node->right); 
            level.push_back(node->data); 
        }
        ans.push_back(level); 
    }
}

vector<int> morrisTraversal(Node* root)  

{                                            

    vector<int> inorder; 
    
    Node* cur = root; 
    while(cur != NULL) {
        if(cur->left == NULL) {
            inorder.push_back(cur->data); 
            cur = cur->right; 
        }
        else {
            Node* prev = cur->left; 
            while(prev->right != NULL && prev->right != cur) {
                prev = prev->right; 
            }
            
            if(prev->right == NULL) {
                prev->right = cur;
                

                cur = cur->left; 
            }
            else {
                prev->right = NULL; 
                inorder.push_back(cur->data);    

                cur = cur->right; 
            }
        }
    }
    return inorder; 
}

Node* findLCAinBT(Node* root, Node* p, Node* q)
{
    if (root == NULL || root == p || root == q)
        return root;

    Node* left = findLCAinBT(root->left, p, q);
    Node* right = findLCAinBT(root->right, p, q);

    if (left == NULL) return right;
    else if (right == NULL) return left;
    else return root;
}

Node* findLCAinBST(Node* root, Node* p, Node* q)
{
    if(!root) return NULL;
    
    auto curr = root->data;
    
    if(curr < p->data && curr < q->data) {
        return findLCAinBST(root->right, p, q);
    }
    if(curr > p->data && curr > q->data) {
        return findLCAinBST(root->left, p, q);
    }
    return root;
}




























vector<ll> bfs(ll V, vector<ll> &adj){
    vector<ll> bfs; 
    vector<ll> vis(V, 0); 

    
    for (int i = 0; i < V; i++) { 

        if(!vis[i]) {
            
            queue<ll> q; 
            q.push(0);           

            vis[0] = 1; 
            while(!q.empty()) {
                ll node = q.front();
                q.pop(); 
                bfs.push_back(node); 
                
                

                

                

                

                

            }
        }
    }
    return bfs; 
}

void dfs(ll node, vector<ll> &vis, vector<vector<ll>> &adj, vector<ll> &storeDfs) {
    storeDfs.push_back(node); 
    vis[node] = 1; 
    for(auto it : adj[node]) 
        if(!vis[it]) 
            dfs(it, vis, adj, storeDfs);
}

vector<ll> dfsOfGraph(ll V, vector<vector<ll>> &adj){
	  
	vector<ll> storeDfs; 
	vector<ll> vis(V+1, 0); 

	
    for(int i = 1;i<=V;i++) {
       if(!vis[i]) 
           dfs(i, vis, adj, storeDfs); 
    }
	
	return storeDfs; 
}

void findTopoSort(ll node, vector<ll> &vis, stack<ll> &st, vector<ll> adj[])
{
    vis[node] = 1; 
    
    for(auto it : adj[node]) {
        if(!vis[it]) {
            findTopoSort(it, vis, st, adj); 
        }
    }
    
    st.push(node); 
}

bool checkCycle_UG_DFS(ll node, ll parent, vector<ll> &vis, vector<ll> adj[]) 
{
    vis[node] = 1;
    
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(checkCycle_UG_DFS(it, node, vis, adj)) 
                return true; 
        }
        else if(it!=parent) 
            return true; 
    }
    
    return false; 
}

bool checkCycle_DG_DFS(ll node, vector<ll> adj[], ll vis[], ll dfsVis[])
{
    vis[node] = 1; 
    dfsVis[node] = 1;
    
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(checkCycle_DG_DFS(it, adj, vis, dfsVis)) return true;
        }
        else if(dfsVis[it])
            return true; 
    }
    
    dfsVis[node] = 0; 
    return false;
}

vector<ll> Prims(vector<pair<ll,ll>>* &adj, ll N, ll M = rand())
{
	vector<ll> parent(N), key(N); 
	
    bool MST[N]; 
  
    for (ll i = 0; i < N; i++) 
        key[i] = INT_MAX, MST[i] = false; 
    
    priority_queue< pair<ll, ll>, vector <pair<ll,ll>> , greater<pair<ll,ll>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    
    while(!pq.empty())
    { 
        ll u = pq.top().second; 
        pq.pop(); 
        
        MST[u] = true; 
        
        for (auto it : adj[u]) {
            ll v = it.first;
            ll weight = it.second;
            if (MST[v] == false && weight < key[v]) {
                parent[v] = u;
		        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
    } 
    
	return parent;
}

ll findParent(ll node, vector<ll> &parent) 
{
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findParent(parent[node], parent); 
}

void Union(ll u, ll v, vector<ll> &parent, vector<ll> &rank) 
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}

ll Kruskals(vector<vector<ll>> &edge, ll V)
{
    sort(edge.begin(), edge.end()); 

    
    vector<ll> parent(V);
    vector<ll> rank(V);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int minWt = 0;

    for(auto &i : edge) {
        ll w = i[0];
        ll x = i[1];
        ll y = i[2];
        
        ll u = findParent(x, parent);
        ll v = findParent(y, parent);
        

        if(u != v) {
            Union(u, v, parent, rank);
            minWt += w;
            

        }
    }
   
    return minWt;
}

vector<ll> dijkstra(ll V, vector<vector<ll>> adj[], ll Source) 

{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> distTo(V,LLONG_MAX);
	
	distTo[Source] = 0;
	pq.push(make_pair(0,Source));
	
	while(!pq.empty()){
		ll dist = pq.top().first;
		ll node = pq.top().second;
		pq.pop();
		
		for(auto it:adj[node]){
			ll edgeWeight = it[1];
			ll adjNode = it[0];
			if( dist + edgeWeight < distTo[adjNode]){
				distTo[adjNode] = dist + edgeWeight;
				pq.push(make_pair(distTo[adjNode], adjNode));
			}
		}
	}
	
	return distTo;
}

ll dp[1001][1001];



bool isSubsetSum(vector<ll> &arr, ll n, ll sum)
{
    if(sum == 0) return true;
    if(n == 0) return false;
    
    if(dp[n][sum]!=-1)
        return dp[n][sum];

    if(arr[n - 1] > sum)
        return dp[n][sum] = isSubsetSum(arr, n - 1, sum);

    return dp[n][sum] = isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

ll lcs(string &t1, string &t2, ll n, ll m)
{
    if(n<0 || m<0) return 0;
    
    if(dp[n][m]!=-1) return dp[n][m];
    
    if(t1[n]==t2[m])
        return dp[n][m] = 1 + lcs(t1, t2, n-1, m-1);
    
    return dp[n][m]= max(lcs(t1, t2, n-1, m), lcs(t1, t2, n, m-1));
}

void solve(vector<ll> &v){
    
    ll n,k,x,y,Cnt=0;
    string s,t="";
    bool f = 0;
    
    cin>>n;
    
    for(ll i=v.size()-1;i>=0;i--){
        if(v[i]>1 && isEven(v[i]+n)){
            cout << v[i] << endl;
            return;
        }
    }
    
}


int main() {
    
    Code By Akash
    
	ll t=1;
	cin>>t;
	
	vector<ll> v;
	countPrimes(v, 1e5);
	
	while(t--){
        
        solve(v);
        
	}
	cerr<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}