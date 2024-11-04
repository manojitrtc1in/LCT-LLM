#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define unique(a) (a).erase(std::unique((a).begin(),(a).end()),(a).end())
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vil vector<long long>
#define vii vector<pair<int,int>>
#define viil vector<pair<long long,long long>>





#define lsb(x) (x&-x)
#define lsbu(x) (x&(x+1))
#define msb(x) __lg(x)
#define msbu(x) 






#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int,int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>  

typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





struct comp { 

    bool operator() (const pair <int , int> &a, const pair <int , int> &b) const { 
      return a.first < b.first;
  }  
}; 


#define INF 1e9+9
int nmax(){return -1*INF;}
template<typename Arg, typename... Args>
int nmax(Arg a,Args... args) { return std::max(a,nmax(args...)); }

int nmin(){return INF;}
template<typename Arg, typename... Args>
int nmin(Arg a,Args... args) { return std::min(a,nmin(args...)); }


void ans22(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}




bool onsegment(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
    if (q.first <= max(p.second, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
       return true;
 
    return false;
}
 








int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);
 
    if (val == 0) return 0;  

 
    return (val > 0)? 1: 2; 

}



#define dsu(n) parent_dsu.resize(n);rank_dsu.resize(n,0);iota(parent_dsu.begin(),parent_dsu.end(),0)
vector<int> parent_dsu, rank_dsu;
void make_set_dsu(int v) {
    parent_dsu[v] = v;  

    rank_dsu[v] = 0;     

}
 
int find_set_dsu(int v) {
    if (v == parent_dsu[v])
        return v;
    return parent_dsu[v] = find_set_dsu(parent_dsu[v]); 

    

}
 
void union_sets_dsu(int a, int b) {
    a = find_set_dsu(a);
    b = find_set_dsu(b);
    if (a != b) {
        if (rank_dsu[a] < rank_dsu[b])
            swap(a, b);
        parent_dsu[b] = a;
        if (rank_dsu[a] == rank_dsu[b])
            rank_dsu[a]++;
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const vector<int>& x){int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}


template<typename T>void __print(stack<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();};}
template<typename T>void __print(queue<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop();};}
template<typename T>void __print(deque<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop_front();};}


void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

long long ccccc=0;
#ifndef ONLINE_JUDGE
#define tle ccccc++;assert(ccccc<1e7)
#define wd(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define tle
#define wd(x...)
#endif

#define int long long


vector<int> t(4 * (2*1e6+22)) , lazy(4 * (2*1e6+22));






void build(vector<int> &a, int v, int tl, int tr) {

    if (tl == tr) {
        t[v] = a[tl]; 

    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm); 

        build(a, v * 2 + 1, tm + 1, tr); 

                t[v] = t[v * 2] + t[v * 2 + 1]; 

    }
}




int sum(int v , int tl , int tr , int l, int r) {
    if (l > r)
                return 0;
    if (l == tl && r == tr) {
        return t[v];  

    }
    int tm = (tl + tr) / 2;
       return sum(v * 2, tl, tm, l, min(r, tm))
                    + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    
}



void update(int v , int tl , int tr , int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val; 

    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val); 

        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val); 

                t[v] = t[v * 2] + t[v * 2 + 1];
    }
}


int _nn;


void build(vector<int> &arr) {
    _nn = (int)arr.size();
    build(arr, 1, 0, _nn - 1);
}


int sum(int l, int r) {
    return sum(1, 0, _nn - 1, l, r);
}


void update(int pos, int val) {
    update(1, 0, _nn - 1, pos, val);
}


void push(int v,int tl,int tr) {
    int tm = (tl+tr)/2;
    t[v*2] += (tm-tl+1)*lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += (tr-tm)*lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += (tr-tl+1)*addend;
        lazy[v] += addend;
    } else {
        push(v,tl,tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = (t[v*2] + t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    push(v,tl,tr);
    if (l == tl && tr == r)
        return t[v];
     
    int tm = (tl + tr) / 2;
    return (query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

int find_kth(int v, int tl, int tr, int k) {
   push(v,tl,tr);
    if (k > t[v]){       
        return -1;
    }
    if (tl == tr)
        return tl;  

    int tm = (tl + tr) / 2;
 push(v*2,tl,tm);  

    if (t[v*2] >= k)
        return find_kth(v*2, tl, tm, k);
    else 
        return find_kth(v*2+1, tm+1, tr, k - t[v*2]);
}


int find_k(int v, int tl, int tr, int k) {
    push(v,tl,tr);
    if (k > tr-tl+1-t[v]){       
        return -1;
    }
    
    if (tl == tr)
        return tl;     

    int tm = (tl + tr) / 2;
 push(v*2,tl,tm);  

    if (tm-tl+1 - t[v*2] >= k)
        return find_k(v*2, tl, tm, k);
    else 
        return find_k(v*2+1, tm+1, tr, k - (tm-tl+1 - t[v*2]));
}


#define sz(x) (int)(x).size()

#define all(x) (x).begin(), (x).end()
long long mod = 1e9+7;


int32_t main() {
    






#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

        int n,q;
        scanf("%lld %lld",&n,&q);
      vector<int> srr(n) ,lrr(n) ;
      for(int i=0;i<n;i++){
          scanf("%lld",&srr[i]);
          lrr[i]=srr[i];
      }


int N= 2*1e6+22;
vector<int> brr(N) , crr(N,0) , arr(N)  ;
      sort(all(srr));

int c=1;
      for(int i=1;i<n;i++){
        if(srr[i]==srr[i-1]){
            c++;
        }
        else{
            arr[srr[i-1]] = c;
            c=1;
        }
      }

      arr[srr[n-1]] = c;        

      for(int i=0;i<N;i++){
        brr[i] += arr[i];
        brr[i+1] += brr[i]/2;
        crr[i] = brr[i]%2;
      }

      

      build(crr,1,0,N-2);
      

   

         

         

         





      for(int i=0;i<q;i++){
        int o,k,l;
        scanf("%lld %lld",&o,&l);
        o--;
        k = lrr[o];
        lrr[o]=l;


         

         

         

         

       
        int kk =find_kth(1,0,N-2,query(1,0,N-2,0,k-1)+1);
        

        

        

        

        

        

        

        

        

        

        


if(kk==-1){
     cout<<"fk1\n";
        exit(0);
}

        

        if(kk > k){
            

            update(1, 0, N-2, k, kk-1, 1);
        }
    
          update(1, 0, N-2, kk, kk, -1);

          


 



        int kkk = find_k(1,0,N-2, (l - query(1,0,N-2,0,l-1)) + 1);
        

        

        

        

        

        

        

        

        

        

        


        if(kkk==-1){
             cout<<"fk2\n";
        exit(0);
        }


         if(kkk > l){
            update(1, 0, N-2, l, kkk-1, -1);
        }
        


         update(1, 0, N-2, kkk, kkk, 1);

        int ss = query(1,0,N-2,0,N-2);

             int ans =find_kth(1,0,N-2,ss);
        

        

        

        

        

        

        

        

        

        

        

        

        



printf("%lld\n",ans);


      }
      
      




      

    
    return 0;
}

