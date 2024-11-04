

















using namespace std;
typedef long long int ll;
long long maximum=numeric_limits<int>:: max();
typedef vector<ll> vi;
typedef vector<vi> vvi;
inline int bit( int x, int i ) { return (x>>i)&1; }
bool id1(const pair<int,int> &a, const pair<int,int> &b) 
{return (a.second < b.second);}
ll get_hash(ll x, ll y, ll z)
{
    return (z) + (3001)*(y) + (3001*3001*(x));
    

}
ll com(ll n,ll m){
    ll ans=1;m=max(m,n-m);
    f(i,1,n-m){
        ans=(ans*(m+i))/i;
    }
    return ans;
}




int solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    f(i,0,n)cin>>v[i];
    k=min(k,m-1);
    ll ans=-1;

    int moves=m-1-k;

    

    for(int i=0;i<=k;i++)
    {
        ll temp_ans=1e18;
        for(int j=0;j<=moves;j++)
        {
            ll mini=max(v[i+j], v[i+j+n-m]);
            

            temp_ans=min(temp_ans, mini);
            

        }
        ans=max(ans, temp_ans);
    }
    cout<<ans<<endl;
}
int n;
vi gr[150001];
vi iota(int n) {
    vi a(n);
    iota(all(a), 1);
    return a;
}
int get_parent(int i, vi par){while(par[i]!=i)i=par[i];return i;}
void dfs(int node)
{
    cout<<node<<" ";
    for(auto x:gr[node])
    {
        dfs(x);
    }
}
set<ll> s;
multiset<ll> dif; 

ll a;
void id2(ll a)
{
    s.insert(a);
    

    auto it=s.find(a);
    

    if (next(it) != s.end())dif.insert(*next(it) - a);
    if (it != s.begin()) {
        dif.insert(a - *prev(it));
        if (next(it) != s.end()) dif.erase(dif.find(*next(it) - *prev(it)));
    }
}
void erase_position(ll a)
{
    auto it = s.find(a);
    if (next(it) != s.end()) dif.erase(dif.find(*next(it) - a));
 
        if (it != s.begin()) {
            dif.erase(dif.find(a - *prev(it)));
            if (next(it) != s.end())dif.insert(*next(it) - *prev(it));
        }
        s.erase(it);
}
ll query()
{
    if (s.size() <= 2)return 0;
    return *(--s.end()) - *s.begin() - *(--dif.end());
    

}
vi adj_test[11];
vi h(11,0);
auto par=iota(11);
void dfs_test(int v,int p = -1)
{
    if(p + 1) { h[v] = h[p] + 1; }
    par[v] = p;
    for(auto u : adj_test[v])
    {
        if(p - u)dfs_test(u,v);

    }
}
int LCA(int v,int u){
    if(v == u)
        return v;
    if(h[v] < h[u])
        swap(v,u);
    return LCA(par[v], u);
}
int TIME=0;
vi st(11,0);
vi ft(11,0);
vi color(11,-1);
void dfs_time(int v)
{
        st[v] = TIME++;
        color[v]=1;

        for(auto u :adj_test[v])
        {
            if (color[u] == -1) dfs_time(u);
        }
        

        ft[v] = TIME;

}  
int arr[MAXN];               

int block[SQRSIZE];          

int blk_sz;                      



void update(int idx, int val) 
{ 
    int blockNumber = idx / blk_sz; 
    block[blockNumber] += val - arr[idx]; 
    arr[idx] = val; 
} 
bool bin_search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}
int count_same(int x[], int n, int k) {
    int p = -1, q = -1;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] < k) p += a;
        while (q+a < n && x[q+a] <= k) q += a;
    }
    return q-p;
}


int query(int l, int r) 
{ 
    int sum = 0; 
    while (l<r and l%blk_sz!=0 and l!=0) 
    { 
        

        sum += arr[l]; 
        l++; 
    } 
    while (l+blk_sz <= r) 
    { 
        

        sum += block[l/blk_sz]; 
        l += blk_sz; 
    } 
    while (l<=r) 
    { 
        

        sum += arr[l]; 
        l++; 
    } 
    return sum; 
} 


void preprocess(int input[], int n) 
{ 
    

    int blk_idx = -1; 
  
    

    blk_sz = sqrt(n); 
  
    

    for (int i=0; i<n; i++) 
    { 
        arr[i] = input[i]; 
        if (i%blk_sz == 0) 
        { 
            

            

            blk_idx++; 
        } 
        block[blk_idx] += arr[i]; 
    } 
} 
void showdq(deque <ll> g) 
{ 
    deque <ll> :: iterator it; 
    for (it = g.begin(); it != g.end(); ++it) cout<<*it<<' '; 
    cout<<'\n'; 
} 
int main()
{
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    

    ll n;cin>>n;
    vi v(n);f(i,0,n)cin>>v[i];
    ll ans=0;
    vi cnt(n);
    cnt[n-1]=!v[n-1];
    r(i,n-2,-1)
    {
        cnt[i]+=cnt[i+1]+!v[i];
    }
    f(i,0,n)
    {
        if(v[i])
        {
            ans+=cnt[i];
        }
    }
    cout<<ans;
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    




    

    

    

    

    

    

    

}
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node* next;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
    int get_height_bfs(Node* root)
    {
        int h=0;

        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            h++;
            Node* temp=q.front();
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    int get_Height(Node* root, int h)
    {
        if(root==nullptr)return h-1;
        else
        {
            return max(get_Height(root->left, h+1), get_Height(root->right, h+1));
        }
    }
    int getHeight(Node* root)
    {
        int ans=0;
        ans=get_Height(root, 0);
        return ans;
    }
    Node* removeDuplicates(Node *head)
          {   
              Node* current = head;
              while (current != nullptr && current->next != nullptr) {
                  Node* temp = current->next;
                  if (current->data == temp->data) { 

                      current->next = temp->next;
                      delete temp;
                  } else {
                     current = current->next;
                  }
              }

              return head;
          }
};
void make_tree()
{
    Solution myTree;
    Node* root = NULL;
    int t; cin >> t;
    int data;
    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;
}
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree(int value) {this->value = value;left = NULL;right = NULL;}
};
void dfs(BinaryTree* root, int sum, vector<int>& ans)
{
        int sum1=sum,sum2=sum;
        if(root!=nullptr and root->left!=nullptr)sum1+=root->left->value;
        if(root!=nullptr)dfs(root->left,sum1, ans);
        if(root!=nullptr and root->right!=nullptr)sum2+=root->right->value;
        if(root!=nullptr)dfs(root->right,sum2, ans);
        if(root!=nullptr and root->right==nullptr and root->left==nullptr)ans.push_back(sum);
}
vector<int> id0(BinaryTree *root) {
    vector<int> ans={};
    if(root!=nullptr)dfs(root,root->value,ans);
  return {ans};
}

































