




#include<bits/stdc++.h>
#define ll  int
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define vvl vector<vl>
#define pl pair<ll,ll>
#define mpl map<ll,ll>
#define umpl unordered_map<ll,ll>
#define umplc unordered_map<char,ll>
#define hf 31
#define f first
#define s second
#define pb push_back
#define pp pop_back


#define MOD
#define M 1000000007
#define fr(i,str,n) for(ll i=str;i<n;++i)
#define nl cout<<endl


#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi; 
typedef vector<pair<int,int>> vpi;

#ifdef DB
#define debug(x) cerr << #x << '=' << (x) << endl;
#define debugBIT(bit)                               \
    {                                               \
        cerr << "BIT: ";                            \
        for (int i = 0; i < bit.size() - 1; i++)    \
        {                                           \
            if (i == 0)                             \
                cerr << qry(i) << " ";              \
            else                                    \
                cerr << qry(i) - qry(i - 1) << " "; \
        }                                           \
        cerr << endl;                               \
    }

#else
#define debug(x) 
#define debugBIT(bit)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef uniform_int_distribution<ll> uni_dist;
ll abss(ll a)
{
    if(a<0)	return -a;
    return a;
}
ll ones(ll a)
{
  ll cnt = 0;
  while(a>0)
  {
    if(a&1) cnt++;
    a>>=1;
  }
  return cnt;
}
#ifdef MOD
ll fast_pow(ll b, ll e,ll width=M)
{
  if(e==0)
  {
    return 1;
  }
  else if(e==1)
  {
    return b%width;
  }
  b = b%width;
  ll ans = 1;
  while(e>0)
  {
    if((e&1)==1)
    {
      ans = (ans*b)%width;
    }
    e>>=1;
    b = (b*b)%width;
  }
  return ans;
}
ll mod_inv(ll a,ll width=M)
{
  return fast_pow(a,width-2,width);
}
template<typename Number,Number width>
class ModularArithmetic
{
  private :
    Number n;
  public:
    friend ostream& operator<<(ostream& os, ModularArithmetic const & num) {
        return os << num.n;
      }
    friend istream& operator>>(istream &is,ModularArithmetic  & num)
    {
      is>>num.n;return is;
    }
    ModularArithmetic() : n(0){}
    ModularArithmetic(Number n) : n(n % width){if(this->n<0)this->n+=width;}
    Number get() const {return n;}
    ModularArithmetic operator+(const ModularArithmetic &b){Number t = (n+b.get())%width;if(t<0)return ModularArithmetic(width+t);return ModularArithmetic(t);}
    ModularArithmetic operator-(const ModularArithmetic &b){Number t = (n-b.get())%width;if(t<0)return ModularArithmetic(width+t);return ModularArithmetic(t);}
    ModularArithmetic operator*(const ModularArithmetic &b){Number t = (n*b.get())%width;if(t<0)return ModularArithmetic(width+t);return ModularArithmetic(t);}
    ModularArithmetic operator/(const ModularArithmetic &b)
    {
        assert(b.get()!=0);
        Number ans = n*mod_inv(b.get(),width);
        if((ans)<0)return ModularArithmetic(width+(ans)%width);return ModularArithmetic(ans%width);
    }
    ModularArithmetic &operator+=(const ModularArithmetic &b){n = (n+b.get())%width;if(n<0)n=n+width;return *this;}
    ModularArithmetic &operator-=(const ModularArithmetic &b){n = (n-b.get())%width;if(n<0)n=n+width;return *this;}
    ModularArithmetic &operator*=(const ModularArithmetic &b){n = (n*b.get())%width;if(n<0)n=n+width;return *this;}
    ModularArithmetic &operator/=(const ModularArithmetic &b)
    {
      assert(b.get()!=0);
        n = (n*mod_inv(b.get(),width))%width;if(n<0)n=n+width;return *this;
    }
};
typedef ModularArithmetic<ll,M> lm;
typedef vector<lm> vlm;
#endif


template<class T,size_t N>ostream &operator<<(ostream &os,const array<T,N> &p){os<<"<";for(auto&it:p)os<<it<<" ";return os<<">";}
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.f<<","<<p.s<<")";}
template<class S,class T>istream &operator>>(istream &is,pair<S,T> &p){return is>>p.f>>p.s;}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T,typename Cmp>ostream &operator<<(ostream &os,const set<T,Cmp>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T,typename Cmp>ostream &operator<<(ostream &os,const map<S,T,Cmp>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>istream &operator>>(istream &is,const pair<S,T> &p){return is>>p.f>>p.s;}
template<class T> istream &operator>>(istream &is, vector<T> &p){for(auto&itr:p)is>>itr;return is;}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){ll idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#ifdef DB
#define debarr(a,n)cerr<<#a<<":";for(ll i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(ll i=0;i<row;i++){for(ll j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif
ll n,q;
vl arr;
vl ans;
vvl adj;
using state = pair<pl,ll>;
vector<vector<state>> Q;
vector<set<ll>> frq1;
vl frq2;

vl tree;
inline ll L(ll ind) {return 2*ind+1;}
inline ll R(ll ind) {return 2*ind+2;}
ll merge(ll a,ll b){
    return a+b;
}

void update(ll ind,ll lf,ll rt,ll pos,ll val){
    if(pos<lf||pos>rt) return;
    if(lf==rt){
        tree[ind] += val;
        return;
    }
    ll mid = (lf+rt)>>1;
    update(L(ind),lf,mid,pos,val);
    update(R(ind),mid+1,rt,pos,val);
    tree[ind] = merge(tree[L(ind)],tree[R(ind)]);
}
ll query(ll ind,ll l,ll r,ll lq,ll rq){
    if(l>rq||r<lq) return 0;
    if(l>=lq&&r<=rq)    return tree[ind];
    ll mid = (l+r)>>1;
    return merge(query(L(ind),l,mid,lq,rq),query(R(ind),mid+1,r,lq,rq));
}
ll query(ll ind,ll l,ll r,ll k){
    
    if(tree[ind]<k) return -1;
    if(l==r)    return l;
    ll mid = (l+r)>>1;
    if(tree[L(ind)]>=k)  return query(L(ind),l,mid,k);
    else   {
        k-=tree[L(ind)];
        if(tree[R(ind)]<k)  return -1;
        return query(R(ind),mid+1,r,k);
    }
    
}
void dfs(ll nd){

    if(frq2[arr[nd]]>0){
        frq1[frq2[arr[nd]]].erase(arr[nd]);
        update(0,0,n,frq2[arr[nd]],-1);
    }    
    frq2[arr[nd]]++;
    update(0,0,n,frq2[arr[nd]],1);
    frq1[frq2[arr[nd]]].insert(arr[nd]);
    
    for(auto qq:Q[nd]){
        ll k = qq.f.f;
        ll l = qq.f.s;
        ll ind= qq.s;
        

        ll cnt = 0;
        if(l-1>=0)  cnt =  query(0,0,n,0,l-1);
        ll val = query(0,0,n,cnt+k);
        if(val!=-1) ans[ind] = *frq1[val].begin();
        else    ans[ind] = val;
    }
    for(auto itr:adj[nd])   dfs(itr);

    frq1[frq2[arr[nd]]].erase(arr[nd]);
    update(0,0,n,frq2[arr[nd]],-1);
    frq2[arr[nd]]--;
    update(0,0,n,frq2[arr[nd]],1);
    frq1[frq2[arr[nd]]].insert(arr[nd]);
}
void solve()
{
    

    cin>>n>>q;
    tree.assign(4*(n+1),0);
    arr.assign(n,0);
    cin>>arr;
    adj.assign(n,vl());
    fr(i,0,n-1){
        ll p;cin>>p;p--;
        adj[p].pb(i+1);
    }
    Q.assign(n,vector<state>());
    ans.assign(q,0);
    fr(i,0,q){
        ll v,k,l;
        cin>>v>>l>>k;
        v--;
        Q[v].pb({{k,l},i});
    }
    frq1.assign(n+1,set<ll>());
    frq2.assign(n+1,0);
    
    
    dfs(0);
    for(auto itr:ans)   cout<<itr<<" ";
    cout<<"\n";

}

int main()
{
    freopen("err.txt","w",stderr);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifdef file_ipop
    freopen("filename.in","r",stdin);
    freopen("filename.out","w",stdout);
#endif
    ll t;cin>>t;while(t--)
    solve();
    return 0;
}