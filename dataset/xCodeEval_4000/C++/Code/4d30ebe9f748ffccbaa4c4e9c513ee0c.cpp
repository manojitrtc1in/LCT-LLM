#include <bits/stdc++.h> 
    #include <string>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<string> vs;
    typedef vector<char> vc;
    typedef vector<vs> vvs;
    typedef vector<vc> vvc;
    typedef vector<ll> vll;
    typedef vector<vi> vvi;
    typedef vector<vll> vvll;
    typedef map<int,int> mpii;
    typedef map<int,vi> mpivi;
    typedef map<string,int> mpsi;
    typedef map<pii,int> map_pair;
    typedef set<int> seti;
    #define	bits(n)						( (n==0)?0:((int)log2(n)+1) )
    #define endl '\n'
    #define FOR(i,n) SFOR(i,0,n)
    #define SFOR(i,m,n) for(i=m;i<n;i++)
    #define FORD(i,n) for(i=n-1;i>=0;i--)
    #define digits(i)   (int)((log(i)/log(10))+1)
    #define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
    #define pb push_back
    #define all(s) s.begin(), s.end()
    #define sz(s) s.size()
    #define si(t) scanf("%d",&(t))
    #define sll(t) scanf("%lld",&(t))
    #define maX(a,b)					( (a) > (b) ? (a) : (b))
    #define miN(a,b)					( (a) < (b) ? (a) : (b))
    #define check_bit(var,pos) ((var) & (1<<(pos)))
    #define prn1(x)                cout<<#x<<": "<<x<<endl
    #define prn2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
    #define prn3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
    #define prn4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
    #define prn5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
    #define prn6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
   int N = 0;
    const double eps=1e-9;
   struct myfun
    {
        public:
    bool operator()(pair<double,double> a,pair<double,double>  b)
    {
       

    

        return a.second/a.first<=b.second/b.first;
    }
    };
    
  ll gcd(ll a,ll b)
{
    prn2(a,b);
   if (b==0)
        return a;

    if (a > b)
        return gcd( b, a%b);
        
    return gcd(a, b%a);

}

int powe(int a,int b,int c)
{
    if(b==0)
    {
        if(a==0)
            return 0;
            
        return 1;
    }
  
    int p=powe(a,b/2,c)%c;
    int ans=((p)*(p))%c;
    if(b%2!=0)
    {
        ans=(ans*a)%c;
    }
    

    return ans;
}
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  
bool isp(string s)
{
    

    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            return false;
        }
            }
            return true;
}
ll LCM(ll a,ll b){
    
return (a*b)/gcd(a,b);
}
struct Node {
     int val;
      Node *left;
      Node *right;
     Node(int x) : val(x), left(NULL), right(NULL) {}
  };
struct Foo
{
    int sum;
    int i;
    int j;
  
};

class Compare
{
public:
    bool operator() (pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b)
    {
        prn2(a.first,b.first);
        return a.first<=b.first;
    }
};
struct lex_compare {
    bool operator() (const pair<int,pair<pair<int,char>,int> >& lhs, const pair<int,pair<pair<int,char>,int> >& rhs) const {
       if(lhs.first>rhs.first)
           return false;
        
        if(lhs.first<rhs.first)
            return true;
            
        if(lhs.second.first.second==rhs.second.first.second)
        {
            if(lhs.second.first.second=='s')
            {
                return lhs.second.second>=rhs.second.second;
            }
            else
            {
                return lhs.second.second<=rhs.second.second;
            }
        }
        else
        {




             return lhs.second.second>=rhs.second.second;
        }


         

        return true;
    }
};
vll fact(101,0);

void did(vll &an,int &ans, int cur ,int num,map<pair<int,pii>,int> &mp)
{
    

   if(cur>num)
       return ;
    if(cur==num)
    {
        

         pair<int,pii> x=make_pair(an[0],make_pair(an[1],an[2]));
        if(mp[x]==0)
        {
        int p=(fact[an[0]+an[1]+an[2]]/(fact[an[0]]*fact[an[1]]*fact[an[2]]));
        
        ans+=p;
       

        mp[x]=p;
        }
        return ;
    }
    
    an[0]++;
    did(an,ans,cur+1,num,mp);
    an[0]--;
    an[1]++;
    did(an,ans,cur+3,num,mp);
    an[1]--;
    an[2]++;
    did(an,ans,cur+5,num,mp);
    an[2]--;
    
}
void A()
    {
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<101;i++)
        {
            if(i>=3)
            {
                fact[i]+=fact[i-3];
            }
            if(i>=5)
            {
                fact[i]+=fact[i-5];
            }
            fact[i]+=fact[i-1];
            

        }
        int t;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            int n;
            cin>>n;
           
            cout<<fact[n]<<endl;
        }
    }

void B()
    {








    vi vec;
    vec.pb(8);
    vec.pb(8);
    vec.pb(6);
    vec.pb(5);
    vec.pb(4);
    vvi s;
    s.pb(vec);
   
    }
    
   vector<vector<int> > f;
    int calc(int i,int tt,vector<int> &vec,vector<map<int,int> > &memo)
    {
        prn2(i,tt);
        if(i==f.size()) return 0;
        int ret=memo[i][tt];
        if(ret!=0) return ret;
        int idx=vec[i];
        if(tt+f[idx][0]>f[idx][1])
        {
             memo[i][tt]=calc(i+1,tt,vec,memo);
             prn2(i,idx);
             prn2(f[idx][0],f[idx][1]);
             prn3(i,tt,memo[i][tt]);
             return memo[i][tt];
        }
        int c1= calc(i+1,tt,vec,memo);
        int c2=calc(i+1,tt+f[idx][0],vec,memo)+1;
        memo[i][tt]=max(c1,c2);
        prn4(i,tt,memo[i][tt],'l');
        return memo[i][tt];
    }    
   
        
          bool cmp2(const pair<int,pii> &i,const pair<int,pii> &j)
        {
            if(i.second.first/sqrt(N)!=j.second.first/sqrt(N)) return i.second.first/sqrt(N)<j.second.first/sqrt(N);
            return i.second.second<j.second.second;
        }
        
        struct cmp{
         bool operator()(const pii &i,const pii &j)
        {
            if(i.second!=j.second) return i.second<j.second;
            return i.first<j.first;
        }
        };
        
    int D()
    {
        int n,q;
      scanf("%d %d",&n,&q);
      N=n;
      vi vec(n);
      for(int i=0;i<n;i++)
      {
          scanf("%d",&vec[i]);
      }
      vector<pair<int,pair<int,int> > > qs(q);
      for(int i=0;i<q;i++)
      {
          int a,b;
         scanf("%d%d",&a,&b);
          qs[i]={i,{a,b}};
      }
      sort(all(qs),cmp2);
    int i=0;
    int j=-1;
    set<pair<int,int> ,cmp> st;
    vector<int> mp(n);
    vector<int> ans(q);
    for(int k=0;k<q;k++)
    {
        int ind=qs[k].first;
     int l=qs[k].second.first;
     int r=qs[k].second.second;
    

     
             while(i<l)
             {
                 
                  mp[vec[i]]--;
                  st.erase({vec[i],mp[vec[i]]+1});
                  if(mp[vec[i]]!=0)
                 {
                     st.insert({vec[i],mp[vec[i]]});
                 }
                 i++;
             }
         
              while(i>l)
             {
                   i--;
                 mp[vec[i]]++;
                 if(mp[vec[i]]!=1)
                 {
                  

                     st.erase({vec[i],mp[vec[i]]-1});
                 }
                 st.insert({vec[i],mp[vec[i]]});
               
             }
         
     
      
             while(j<r)
             {
                 j++;
                 mp[vec[j]]++;
                 if(mp[vec[j]]!=1)
                 {
                 

                     st.erase({vec[j],mp[vec[j]]-1});
                 }
               

                 st.insert({vec[j],mp[vec[j]]});
                

                 
             }
       
         
             while(j>r)
             {
                   mp[vec[j]]--;
                  

                  st.erase({vec[j],mp[vec[j]]+1});
                  if(mp[vec[j]]!=0)
                 {
                     st.insert({vec[j],mp[vec[j]]});
                 }
                 j--;
             }
         
     
     ans[ind]=st.rbegin()->second;
    

    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
    }
    void C()
    {
      int arr[] = {7,17};
vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]) );
int arr1[] = {3,12};
vector<int> vec2 (arr1, arr + sizeof(arr) / sizeof(arr[0]) );
int arr2[] = {10,20};
vector<int> vec3 (arr2, arr + sizeof(arr) / sizeof(arr[0]) );
int arr3[] = {9,10};
vector<int> vec4 (arr3, arr + sizeof(arr) / sizeof(arr[0]) );
int arr4[] = {5,20};
vector<int> vec5 (arr4, arr + sizeof(arr) / sizeof(arr[0]) );
int arr5[] = {10,19};
vector<int> vec6 (arr5, arr + sizeof(arr) / sizeof(arr[0]) );
int arr6[] = {4,18};
vector<int> vec7 (arr6, arr + sizeof(arr) / sizeof(arr[0]) );
int arr7[] = {567,2439};
vector<int> vec8 (arr7, arr + sizeof(arr) / sizeof(arr[0]) );
int arr8[] = {623,1360};
vector<int> vec9 (arr8, arr + sizeof(arr) / sizeof(arr[0]) );
int arr9[] = {700,4206};
vector<int> vec10 (arr9, arr + sizeof(arr) / sizeof(arr[0]) );
int arr10[] = {9,3725};
vector<int> vec11 (arr10, arr + sizeof(arr) / sizeof(arr[0]) );
int arr11[] = {241,7381};
vector<int> vec12 (arr11, arr + sizeof(arr) / sizeof(arr[0]) );
int arr12[] = {746,8823};
vector<int> vec13 (arr12, arr + sizeof(arr) / sizeof(arr[0]) );
vector<vector<int> > g;
g.pb(vec1);
g.pb(vec2);
g.pb(vec3);
g.pb(vec4);
g.pb(vec5);
g.pb(vec6);
g.pb(vec7);










cout<<D();
    }
    struct node{
    bool end;
    int child[26];
};
node trie[50002];
int m;
vector<string> ans;
void add(string v)
{
    int pos=1;
    for(int i=0;i<v.size();i++)
    { int t= v[i]-'a';
     if(!trie[pos].child[t]) trie[pos].child[t]=++m;
     pos=trie[pos].child[t];
  

    }
    trie[pos].end=true;
}
struct seg{
    vector<pii > tree;
    int N;
    seg(int n)
    {
        tree.clear();
        int p=log2(n)+1;
        N=1<<p;
        tree.resize(2*N-1);
        
        N=n;
    }
    void build(int node,int a,int b,vector<pii> &arr)
    {
        if(a>b)
        return;
        if(a==b)
        {
            tree[node]=arr[a];
        }
        else
        
        {
            int mid=(a+b)/2;
            build(2*node,a,mid,arr);
            build(2*node+1,mid+1,b,arr);
            if(tree[2*node+1].first<=tree[node*2].first)
            {
                tree[node] = tree[2*node+1];
            }
            else tree[node] = tree[2*node];
        }
    }
    void update(int node,int a,int b,int ind,int va,vector<pii>&arr)
    {
       

        if(a==b)
        {
           

            arr[ind].first=va;
            tree[node]=arr[ind];
        }
        else
        {
            int m=(a+b)/2;
            if(a<=ind && ind<=m)
            {
                update(2*node,a,m,ind,va,arr);
            }
            else
            {  update(2*node+1,m+1,b,ind,va,arr);
                
            }
            if(tree[2*node+1].first<=tree[node*2].first)
            {
                tree[node] = tree[2*node+1];
            }
            else tree[node] = tree[2*node];
        }
    }
    pii  query(int a,int b)
	{
      return query(1,0,N-1,a,b);
	}
	pii query(int node, int a, int b, int i, int j) {
        

		if (a > b || a > j || b < i) return {INT_MAX,0}; 

		if (a >= i && b <= j) 

        {
              

			return tree[node];
        
        }
		pii le = query(node * 2, a, (a + b) / 2, i, j); 

		pii ri = query(1 + node * 2, 1 + (a + b) / 2, b, i, j); 

       

        

        if(le.first==ri.first)
        {
            return ri;
        }
      else  if(le.first<ri.first)
        {
            return le;
        }
        else return ri;
	}
 

};
    bool cmp(const pair<int,int> &i,const pair<int,int> &j)
    {
        return i.first<j.first;
    }

vector<int> order(vector<int> &h, vector<int> &in) {
    

    

    

    

















  vector<int> ans;










































   return ans;
    
}

    void E()
    {
         int arr[] = {5,3,2,6,1,4};
vector<int> vec1 (arr, arr + sizeof(arr) / sizeof(arr[0]) );
int arr1[] = {0,1,2,0,3,2};
vector<int> vec2 (arr1, arr + sizeof(arr) / sizeof(arr[0]) );
    order(vec1,vec2);
    }
    void AA()
    {
        int t;
        cin>>t;
        string s;
        cin>>s;
        int a=0;
        int b=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
               

                if(s[i]=='S')
                    a++;
                else
                    b++;
            }
        }
      

        if(b>a)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
        
    }
    void BB()
    {
        int t;
        cin>>t;
        if(t==1)
        {
            cout<<1<<" "<<1<<endl;
            cout<<1<<endl;
            return;
        }
        long a=2*(t-1);
        cout<<a<<" "<<2<<endl;
        cout<<1<<" "<<2<<endl;
    }
    void EE()
    {
        int n;
        cin>>n;
        vector<pii> vec(n);
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec[i]={a,i};
        }
        seg s(n);
        s.build(1,0,n-1,vec);








        ll pro=0;
        for(int i=1;i<n;i++)
        {
            pii tp=vec[i];
           
            if(tp.second!=0)
            {
                pii ind=s.query(0,tp.second-1);
               

                if(vec[ind.second].first<tp.first)
                {
                    pro+=(ll)(tp.first-vec[ind.second].first);
                     s.update(1,0,n-1,ind.second,tp.first,vec);
                }
            }
        }
        cout<<pro<<endl;
       
    }
    int main() 
    {
        boost;
        

        

        

        

        

     
        EE();
        

        

        return 0;
    }