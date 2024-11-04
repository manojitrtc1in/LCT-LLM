#include <iostream>
#include<bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <chrono> 
#include<time.h>
#include <sys/time.h>
#include <unistd.h>
#include <algorithm> 
#include <fstream> 
#define PI 3.14159265
#define ss second
#define ff first
#define pb push_back
#define endl '\n'




bool time_seed = 0;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))


using namespace std;
using namespace std::chrono;
 




 


typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd; 
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<bool> vb; 
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<int> vint; 
typedef vector<vint> vvint;
typedef pair<int,int> pii;


















#define mod 1000000007






 


 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 
void show_vi(vector<int> t){
    

    for(int i = 0;i<t.size();i++){
        cout<<t[i]<<",";
    }
    cout<<endl;
}
 
void show_vp(vector<pair<int,int>> t){
    

    for(int i = 0;i<t.size();i++){
        cout<<t[i].first<<" "<<t[i].ss<<"::";
    }
    cout<<endl;
}
 
void show_vd(vector<double> t){
    

    for(int i = 0;i<t.size();i++){
        cout<<t[i]<<",";
    }
    cout<<endl;
}
void show_vint(vector<int> t){
    

    for(int i = 0;i<t.size();i++){
        cout<<t[i]<<",";
    }
    cout<<endl;
}
 
 
void show_vt(vector<tuple<long long,long long>> t){
    

    for(int i = 0;i<t.size();i++){
        cout<<get<0>(t[i])<<" "<<get<1>(t[i])<<"::";
    }
    cout<<endl;
}
 
void show_vb(vector<bool> t){
    

    for(int i = 0;i<t.size();i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
}
 
void show_vvi(vector<vector<int>> ans){
    cout<<"---------------------------"<<endl;
    for(int i = 0;i<ans.size();i++){
        show_vi(ans[i]);
    }
    cout<<endl;
}



int randd(){
    

    timeval start_time;
    

    long miinti_time, seconds, useconds;
    gettimeofday(&start_time, NULL);
    seconds = start_time.tv_sec;
    useconds = start_time.tv_usec;
    miinti_time = ((seconds) * 1000 + useconds/1000.0);
    if(time_seed==0){
        time_seed = 1;
        srand(miinti_time);
    }
    int k = rand();
    return k;
}
 
void show_vvvi(vvvi ans){
    for(int i = 0;i<ans.size();i++){
    cout<<"******************"<<endl;
        show_vvi(ans[i]);
    }
    cout<<endl;
}
 
 
void show_vvb(vector<vector<bool>> ans){
    cout<<"---------------------------"<<endl;
    for(int i = 0;i<ans.size();i++){
        show_vb(ans[i]);
    }
    cout<<endl;
}
 
void show_vs(vector<string> A){
    for(int i =0;i<A.size();i++){
        cout<<A[i]<<"::";
    }
    cout<<endl;
}
 
 
 
void show_vc(vector<char> A){
    for(int i =0;i<A.size();i++){
        cout<<A[i];
    }
    cout<<endl;
}
 
void show_vvc(vector<vector<char>> A){
    cout<<"---------------------------"<<endl;
    for(int i =0;i<A.size();i++){
        show_vc(A[i]);
    }
}
 
void show_vvs(vector<vector<string>> A){
    for(int i = 0;i<A.size();i++){
        show_vs(A[i]);
    }
}
 
void show_vvvs(vvvs ans){
    for(int i = 0;i<ans.size();i++){
    cout<<"******************"<<endl;
        show_vvs(ans[i]);
    }
    cout<<endl;
}
 
void show_um(unordered_map<int,int> &map){
    unordered_map<int,int>::iterator it;
    it = map.begin();
    

    while(it!=map.end()){
        cout<<it->ff<<" "<<it->second<<"::";
        

        it++;
    }
    cout<<endl;
}
 
int ncr(int n, int r) 
{ 
    

    if (r > n - r) 
        r = n - r; 
    int C[r + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, r); j > 0; j--) {
                C[j] = (C[j] + C[j - 1]) ; 
                C[j]%=mod;
            }
    } 
    return C[r]; 
} 
 






 
 
vint prime_factors(int n){
    vint ans;
        while (n % 2 == 0)  
        {  
            ans.push_back(2);
            n = n/2;  
        }  
       
        for (int i = 3; i <= sqrt(n); i = i + 2)  
        {   
            while (n % i == 0)  
            {  
                ans.push_back(i);  
                n = n/i;  
            }  
        }  
        if (n > 2)  
            ans.push_back(n);
    return ans;
}
int pow_m(int a,int b){
    

    

    if(b==0) return 1%mod;
    int k = (int)pow_m(a,b/2);
    if(b%2){
        return (((k*k)%mod)*a)%mod;
    }
    else return (k*k)%mod;
 
}
 
int poww(int a,int b){
    

    if(b==1) return a;
    if(b==0) return 1;
    int k = poww(a,b/2);
    if(b%2){
        return k*k*a;
    }
    else return k*k;
 
}
 
int modInverse(int a, int m) 
{ 
    return pow_m(a,m-2); 
} 
 
bool isPrime(int n) 
{ 
    

    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    

    

    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
 
 
string int_to_hex(int a){
    if(a==0) return "0";
    string ans;
    while(a){
        int k = a%16;
        if(k<=9){
            ans+=('0'+k);
        }
        else{
            ans+=('A'+(k-10));
        }
        a/=16;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
 
 
int ncrr(int a,int b){
    

    int ans = 1;
    if(b>a/2){
        b = a-b;
    }
    for(int i = 0;i<b;i++){
        ans*=a;
                ans%=mod;
    }
 
    for(int i = 1;i<=b;i++){
        ans*=(modInverse(i,mod));
        ans%=mod;
    }
    return ans;
}
 
void init_code(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

}
 
 
class KMP{
public:
 
    vector<int> LPS(string s){
        int n = s.size();
        vector<int> lps(n,0);
        int len = 0;
        int i = 1;
        while(i<n){
            if(s[i]==s[len]){
                lps[i++] = ++len;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }
 
    vector<int> match(string A,string B){
        auto lps = LPS(B);
        vector<int> ans;
        int n = A.size();
        int m = B.size();
        int i = 0;
        int j = 0;
        while(i<n){
            if(A[i]==B[j]){
                i++;
                j++;
            }
            if(j==m){
                ans.push_back(i-j);
                j = lps[j-1];
            }
            else if(i<n&&A[i]!=B[j]){
                if(j==0) i++;
                else j = lps[j-1];
            }
        }
        return ans;
    }
};
 
 
class fast_segtree
{
public:
    static const int N = 2e5+15;  

    int n = N;  

    int t[2 * N];
    
 
    void build() {  

      for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
    }
 
    void modify(int p, int value) {  

      for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }
 
    int query(int l, int r) {  

      int res = 0;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
      }
      return res;
    }

    fast_segtree(vector<int> &A){
        n = A.size();
        for(int i = 0;i<A.size();i++) t[i+n] = A[i];
        build();
    };

    fast_segtree(int n1){
        n = n1;
        for(int i = 0;i<n;i++) t[i+n] = 0;
        build();
    };
    
};


class segtree
{
public:
    vector<int> A;
    int n;
    segtree(int n1){
        n = n1;
        A.clear();
        A.resize(4*n+5);
    };
 
    void sett(int id,int s,int e,int idx,int val){
        if(idx<s||idx>e) return;
        A[id]+=val;
        if(s==e) return;
        int mid = (s+e)/2;
        sett(2*id,s,mid,idx,val);
        sett(2*id+1,mid+1,e,idx,val);
    }
 
    int gett(int id,int s,int e,int l,int r){
        

        if(s>=l&&e<=r) return A[id];
        if(min(e,r)<max(s,l)) return 0;
        int mid = (s+e)/2;
        int ans = 0;
        ans+=gett(2*id,s,mid,l,r);
        ans+=gett(2*id+1,mid+1,e,l,r);
        return ans;
    }

    void sett(int id,int val){
        sett(1,0,n-1,id,val);
    }

    int gett(int l,int r){
        return gett(1,0,n-1,l,r-1);
    }
    
};


 
vector<int> djikstra(int sr, vector<vector<pii>> &gr){
    int n = gr.size();
    vint ans(n,1e15);
    priority_queue<pii> pq;
    pq.push({0,sr});
    while(pq.size()){
        auto top = pq.top();
        pq.pop();
        int id = top.ss;
        int val = -top.ss;
        if(ans[id]>val){
            ans[id] = val;
            for(int j = 0;j<gr[id].size();j++){
                int new_dis = -val-gr[id][j].ss;
                int des = gr[id][j].ff;
                if(ans[des]>-new_dis){
                    pq.push({new_dis,des});
                }
            }
        }
    }
    return ans;
}

class union_find
{
public:
    const int max_sz = 2e5+5;
    vector<int> rank;
    vector<int> parent;
    union_find(int n){
        rank.resize(n);
        parent = rank;
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    };

    int find(int i){
        if(parent[i]==i) return i;
        return find(parent[i]);
    }

    int connect(int i,int j){
        int a = find(i);
        int b = find(j);
        if(a==b) return -1;
        if(rank[a]<rank[b]) swap(a,b);
        parent[b] = a;
        if(rank[a]==rank[b]) rank[a]++;
        return 0;
    }
};

class tries
{
public:
    static const int max_sz = 5e6;
    int nodes[max_sz][12];
    int curr = 1;
    tries(){
        memset(nodes,0,sizeof(nodes));
    }

    void insert(string A){
        int u = 0;
        

        for(int i = 0;i<A.size();i++){
            int child = A[i]-'0';
            if(A[i]=='-') child = 10;
            if(!nodes[u][child]) nodes[u][child] = curr++;
            u = nodes[u][child];
        }
        nodes[u][11] = 1;
    }

    bool find(string A){
        int u = 0;
        for(int i = 0;i<A.size();i++){
            int child = A[i]-'0';
            if(A[i]=='-') child = 10;
            if(!nodes[u][child]) return 0;
            u = nodes[u][child];
        }
        return nodes[u][11];
    }
    
};



class string_hash{
public:
    string A;
    static const int max_n = (2e5)+5;
    static const int g = 109;

    int hash_sum[max_n];
    string_hash(string B){
        hash_sum[0] = 0;
        A = B;
        int n  =A.size();
        for(int i = 0;i<n;i++){
            hash_sum[i+1] = hash_sum[i] + pow_m(g,i)*(A[i]-'a'+1);
            hash_sum[i+1]%=mod;
        }
    };


    int give_hash(int i,int j){
        int temp = hash_sum[j+1]-hash_sum[i];
        if(temp<mod) temp+=mod;
        return (temp*(modInverse(pow_m(g,i),mod)))%mod;
    }

};

class union_find1
{
public:
    const int max_sz = 2e5+5;
    vector<int> rank;
    vector<int> parent;
    union_find1(int n){
        rank.resize(n);
        parent = rank;
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    };

    int find(int i){
        if(parent[i]==i) return i;
        return find(parent[i]);
    }

    int connect(int i,int j){
        int a = find(i);
        int b = find(j);
        if(a==b) return -1;
        if(rank[a]<rank[b]) swap(a,b);
        parent[b] = a;
        if(rank[a]==rank[b]) rank[a]++;
        return 0;
    }
};

const int max_n = 2e5+5;
int n,m;
array<int,3> s1[max_n]; 
int final_ans = 0;
bool poss(int lim, vector<array<int,3>> &s){
    vvi gr(n);
    for(auto E : s){
        if(E[0]<lim){
            gr[E[1]-1].push_back(E[2]-1);
            gr[E[2]-1].push_back(E[1]-1);
        }
    }

    vector<int> vis(n);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while(q.size()){
        auto top = q.front();
        q.pop();
        for(int k : gr[top]){
            if(vis[k]==0){
                vis[k] = 1;
                q.push(k);
            }
        }
    }
    int ans = 1;
    for(int k : vis) ans&=k;
    if(ans){
        

        int sz = 0;
        int len = s.size();
        for(int i = 0;i<len;i++){
            if(s[i][0]<lim)
            s1[sz++] = s[i];
        }

        for(int i = 0;i<sz;i++){
            

            s[i] = s1[i];
        }
        int temp = s.size()-sz;
        while(temp--){
            s.pop_back();
        }
    }
    else{
        final_ans+=lim;
        int len = s.size();
        for(int i = 0;i<len;i++){
            s[i][0]-=(s[i][0]&lim);
            

        }
    }
    

    return ans;
}


void help(){
    cin>>n>>m;
    array<int,3> temp;
    vector<array<int,3>> s;
    final_ans = 0;
    for(int i = 0;i<m;i++){
        int id = 0;
        cin>>temp[id++];
        cin>>temp[id++];
        cin>>temp[id++];
        swap(temp[2],temp[0]);
        

        s.push_back(temp);
    }

    for(int i = 30;i>=0;i--){
        poss(1<<i,s);
    }

    cout<<final_ans<<endl;

}








signed main(){
    init_code();
    int t = 1;
    cin>>t;
    for(int  i = 0;i<t;i++){
        

        help();
    }
}



