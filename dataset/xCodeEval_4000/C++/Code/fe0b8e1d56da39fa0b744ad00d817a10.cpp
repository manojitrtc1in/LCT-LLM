#include <bits/stdc++.h>










using namespace std;
const int mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define debd cout<<"hi"<<endl;
 #define MAX_ARR_SIZE 1000000000000000
#define deb2dvec(v) for(auto i:v){for(auto j=i.begin();j!=i.end();j++) cout<<*j<<" "; cout<<endl;}
#define debmap(m) for(auto i=m.begin();i!=m.end();i++)cout<<i->first<<" "<<i->second<<endl;
#define debmapalt(m) for(auto i : m) cout << i.first << " " << i.second << endl;
#define debarr(a,n) rep(i,n) cout<<a[i]<<" "; cout<<endl;
#define deb2darr(a,n,m) rep(i,n){rep(j,m) cout<<a[i][j]<<" "; cout<<endl; } cout<<endl;
#define take2darr(a,n,m) rep(i,n){rep(j,m) cin>>a[i][j];}
#define debvec(v) for(auto &i : v)cout<<i<<" "; cout<<endl;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define pb push_back
#define mp make_pair
#define init0(x) memset(x, 0, sizeof(x))
#define init1(x) memset(x, 1, sizeof(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pi;
typedef pair<ll,ll>  pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pi>     vpi;
typedef vector<pl>     vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
void debst(stack<char> s)
{    if (s.empty())    return;
    char x = s.top();    s.pop();
     cout << x << ' ';
    debst(s);
    s.push(x);
}

long ceil_div(long a, long b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}
int LIS(vector<int>&a){
    vector<int>lis;
    for(auto&x :a){
        auto it=upper_bound(lis.begin(),lis.end(),x);
        if(it==lis.end())
            lis.push_back(x);
        else *it=x;
        
    }
    return lis.size();
}
























#define MAX 500
int multiply(int x, int res[], int res_size);
void factorial(int n)
{
   int res[MAX];
   res[0] = 1;
   int res_size = 1;
   for (int x=2; x<=n; x++)
      res_size = multiply(x, res, res_size);
   

   for (int i=res_size-1; i>=0; i--)
      cout << res[i];
}
int multiply(int x, int res[], int res_size)
{   int carry = 0;
   for (int i=0; i<res_size; i++)
   {      int prod = res[i] * x + carry;
      res[i] = prod % 10;
      carry = prod/10;
   }
   while (carry)
   {  res[res_size] = carry%10;
      carry = carry/10;
      res_size++;
   }
   return res_size;
}


void mul(long long F[2][2], long long M[2][2]);
 void power(long long F[2][2], long long n);
 
long long fib(long long n)
{
    long long F[2][2] = { { 1, 1 }, { 1, 0 } };
     
    if (n == 0)
        return 0;
         
    power(F, n - 1);
     
    return F[0][0];
}
 
void mul(long long F[2][2], long long M[2][2])
{
    int x = (F[0][0] * M[0][0])%mod +
            (F[0][1] * M[1][0])%mod;
    int y = (F[0][0] * M[0][1])%mod +
            (F[0][1] * M[1][1])%mod;
    int z = (F[1][0] * M[0][0])%mod +
            (F[1][1] * M[1][0])%mod;
    int w = (F[1][0] * M[0][1])%mod +
            (F[1][1] * M[1][1])%mod;
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
void power(long long F[2][2], long long n)
{
    int i;
    long long M[2][2] = { { 1, 1 }, { 1, 0 } };
     
    

    

    for(i = 2; i <= n; i++)
        mul(F, M);
}



long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 


long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}














void primeFactors(int n)
{
    int c=2;
    while(n>1)
    {
        if(n%c==0){
        cout<<c<<" ";
        n/=c;
        }
        else c++;
    }
}


 






    int sgn(int x) {
        if (x > 0) return 1;
        else return -1;
    }
void leftRotateByD(int *arr,int n,int d)
{
  
  int temp[d];
  for (int i=0;i<d;i++)
  {
    temp[i]=arr[i];
  }
  
  
  int x=0;
  for(int j=d;j<n;j++)
  {
    arr[x]=arr[j];
    x++;
  }
  
  
  x=0;
  for (int k=n-d;k<n;k++)
  {
    arr[k]=temp[x];
    x++;
  }
  
}

int noOfBits(int a){
    int vac=a;
    int res=0;
    while(vac>0){
        vac=vac/2;
        res++;
    }
  return res;
}
int noOfSetBits(int a){
    int n=a;
    int res=0;
    while(n>0){
        if(n%2==1) res++;
        n=n/2;
    }
    return res;
}
bool allsetbits(int val){
    int temp=val;
    bool flag=true;
    while(temp>0){
       int rem=temp%2;
        if(rem==0) flag=false;
        temp/=2;
    }
    return flag;
}
 
const ll ninf = -1e15;
vector<int> nextGreater(vector<ll>& arr, int n) {
    stack<int> s;   
        vector<int> result(n, n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = i;    
            s.pop();
        }
        s.push(i);
    }
        return result;
}
 
vector<int> prevGreater(vector<ll>& arr, int n) {
    stack<int> s;   
        vector<int> result(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = i;    
            s.pop();
        }
        s.push(i);
    }
        return result;
}
 
ll query(vector<ll> &tree, int node, int ns, int ne, int qs, int qe) {
    if (qe < ns || qs > ne) return ninf;
    if (qs <= ns && ne <= qe) return tree[node];
 
    int mid = ns + (ne - ns) / 2;
    ll leftQuery = query(tree, 2 * node, ns, mid, qs, qe);
    ll rightQuery = query(tree, 2 * node + 1, mid + 1, ne, qs, qe);
    return max(leftQuery, rightQuery);
}




int FindMaxLength(int A[], int B[], int n, int m)
{
 
    

    int dp[n*m + 1][m*n + 1];
    for (int i = 0; i <= n*m; i++)
        for (int j = 0; j <= m*n; j++)
            dp[i][j] = 0;
 
    

    

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            

            

            if (A[i] == B[j])
                dp[j][i] = dp[j + 1][i + 1] + 1;
        }
    }
    int maxm = 0;
 
    

    

    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            

            maxm = max(maxm, dp[i][j]);
        }
    }
 
    

    return maxm;
}
ll fac(ll a){
    ll res=1;
    for(ll i=1;i<=a;i++){
      res*=i;
    }
    return res;
}
ll maxSubArraySum(int a[], int first,int second)
{
    ll max_so_far = -1e15, max_ending_here = 0;
 
    for (int i = first+1; i < second; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

 void totalStrength(vector<int>& strength) {
    const int mod = 1000000007;
        

        int n=strength.size();
        stack<int>st;
        st.push(0);
        int x=1;
        vector<int>right(n);
        while(x<n){
            if(!st.empty() and strength[x]<=strength[st.top()]){
                while(!st.empty()and strength[x]<=strength[st.top()]){
                     right[st.top()]=x;
                     st.pop();
                }
                  st.push(x);x++;
               
            }
            else st.push(x++);
        }
        while(!st.empty()){
            right[st.top()]=n;
            st.pop();
        }
        

        vector<int>left(n);
        int i=n-2;
        st.push(n-1);
        while(i>=0){
            

             if(!st.empty() and strength[i]<strength[st.top()]){
                while(!st.empty()and strength[i]<strength[st.top()]){
                     left[st.top()]=i; 
                     st.pop();
                }
                  st.push(i);i--;
               
            }
            else st.push(i--);
        }
        while(!st.empty()){
            left[st.top()]=-1;
            st.pop();
        }
        

        long long ans=0;
        int presum[n+1];
        presum[0]=0;
        for(int i=0;i<n;i++){
            presum[i+1]=(presum[i]+strength[i])%mod;
        }

        int preprefix[n+2];
        preprefix[0]=0;
        for(int i=0;i<=n;i++){
            preprefix[i+1]=(preprefix[i]+presum[i])%mod;
        }
        

        for(int i=0;i<n;i++){
            long long sum=((preprefix[right[i]+1]-preprefix[i+1])*(i-left[i]))%mod;
            

             long long t2=((preprefix[i+1]-preprefix[left[i]+1])*(right[i]-i))%mod;
             cout<<sum<<" "<<t2<<endl;
            ans += (sum+mod-t2) * strength[i];
            ans %= mod;
            

        }
        
    }
    class WordFilter {
public:
    vector<string>coll;
    WordFilter(vector<string>& words) {
         coll=words;
    }
    
    int f(string prefix, string suffix) {
      
        int ans=-1;
        for(auto j=coll.begin();j!=coll.end();j++){
              string word=*j;
             if(prefix.length()>word.length() || suffix.length()>word.length()) continue;
              bool pref=true;
            
              int n=word.length();
               for(int i=0;i<prefix.length();i++){
                 if(prefix[i]!=word[i]){ pref=false;break;}
              }
            bool suff=true;
            int x=0;
            for(int i=suffix.length()-1;i>=0;i--){
                 if(suffix[i]!=word[n-1-x++]){suff=false;break;}
                    }
            

            if(pref and suff){ans=j-coll.begin();}
        }
        return ans;
        
    }
};
bool universal=true;
void dfs(vector<vector<int>>a,int i,int j,int n,int m,int sum){
    if(sum+a[i][j]==0 and i==n-1 and j==m-1) {universal=false;return; }
  if(i==n-1 and j==m-1){
    return ;
  }
  if(i+1<n and universal){
     dfs(a,i+1,j,n,m,sum+a[i][j]);
  }
  if(j+1<m and universal){
     dfs(a,i,j+1,n,m,sum+a[i][j]);
  }
  return;
}
vector<vector<int>>graph;
int dfs(int r,int p=0){
    int ans=0;
    int zero=0;
    for(int x:graph[r]){
        if(x==p) continue;
        int temp=dfs(x,r);
        ans+=temp;
        zero+=(temp==0);
    }
    ans+=max(zero-1,0);
    return ans;

}
bool cmp(const pair<int,int>a,const pair<int,int>b){
    if(a.first>b.first){
        return true;
    }
    else if(a.first<b.first){
        return false;
    }
    else{
        if(a.second>b.second) return true;
        return false;
    }
}






int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0) 

        return 0;
  
    std::vector<int> tail(v.size(), 0);
    int length = 1; 

  
    tail[0] = v[0];
  
    for (int i = 1; i < v.size(); i++) {
  
        

        

        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
  
        

        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
  
    return length;
}
bool isPalindrome(string S)
{
    

    

    string P = S;
 
    

    reverse(P.begin(), P.end());
 
    

    if (S == P) {
        

        return true;
    }
    

    else {
        

        return false;
    }
} 











   






         

bool CheckForSequence(int arr[], int n, int k)
{
    

    

    for (int i = n - 1; i >= 0; i--) {
        

        

        

        if (k >= arr[i])
            k -= arr[i];
    }
 
    

    

    if (k != 0)
        return false;
    else
        return true;
}
int KpartitionsPossible(int arr[], int n, int k)
{
    ll sum = 0;
    int count = 0;
     
    

    for(int i = 0; i < n; i++)
    sum = sum + arr[i];
     
    if(sum % k != 0)
    return 0;
     
    sum = sum / k;
    ll ksum = 0;
     
    

    for(int i = 0; i < n; i++)
    {
    ksum=ksum + arr[i];
     
    

    if(ksum == sum)
    {
        

        ksum = 0;
        count++;
    }
     
    }
     
    if(count == k)
    return 1;
    else
    return 0;
     
}
pair<int,int> mergeinterval(vector<pair<int,int>>v,int x){
    pair<int,int> init={x,x};
for(pair<int,int>p:v){
   

     if(p.first<=init.first and init.first<=p.second){

        init.first=min(init.first,p.first);
        init.second=max(init.second,p.second); 
     }
     else if(p.first>=init.first and init.second>=p.first){
        init.first=min(init.first,p.first);
        init.second=max(init.second,p.second);
     }
    

   }
     return init;
}
int subsback(string s,char a, char b){
    int ind=-1;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==b){
            ind=i;
            break;
        }
    }
    if(ind==-1) return 100;
    ind--;
    int lind=-1;
    for(int i=ind;i>=0;i--){
         if(s[i]==a){
              lind=i;break;
         }
    } 
    if(lind==-1) return 100;
    int n=s.length(); ind++;
    

    

    return (ind-lind-1+n-(ind+1));

}
bool universalt=0;
void dfs(string s,int i,string temp)
{   if(i==s.length()){
        if(is_sorted(temp.begin(),temp.end())){
            bool flag=1;
            for(int j=1;j<temp.length();j++){
                if(temp[j]==temp[j-1]){
                    flag=0;
                }
            }
            if(flag){universalt=1;}
        }
            return;
     }
     if(universalt){return;}
    dfs(s,i+1,temp+=to_string(i));
    dfs(s,i+1,temp);
}

void solve(){
  string s;cin>>s;
 int n=s.length();
  string a="";
  string b="";
  char ch='z';
  int ind=-1;
 for(int i=0;i<n;i++){
   if(ch>=s[i]){
       ind=i; ch=s[i];
   } 
 }
 for(int i=0;i<n;i++){
    if(i==ind){
        a+=s[i];
    }
    else b+=s[i];
 }
 

 cout<<a<<" "<<b<<endl;

}
 int main() {
   ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  cout.tie(NULL); 
  
    #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   

    

   int t=1; 
   cin>>t; 

 while(t--) {
    

   solve();
    }
  
    return 0;
}