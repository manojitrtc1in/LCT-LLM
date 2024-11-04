#include <bits/stdc++.h>
 #include<ext/pb_ds/assoc_container.hpp>
 #define gp  __gnu_pbds
 #define iset(T) gp::tree<T,gp::null_type,less<T>,gp::rb_tree_tag,gp::tree_order_statistics_node_update>
 using namespace std;
 
 #define SQ(x) ((x)*(x))
 #define u unsigned
 #define ull unsigned long long
 #define ll  long long
 #define ld  long double
 #define test(x) cerr<<"here "<<#x<<endl;
 #define putpls(x) #x
 #define casing(x,y) cout<<"Case #"<<x<<": "<<y<<'\n';
 #define inputstl(v) for(auto& x:v) cin>>x;
 #define input(arr,n) for(ull i=0;i<n;++i){cin>>(arr)[i];}
 #define print(arr,n) for(ull i=0;i<n;++i){cout<<(arr)[i]<<" ";}cout<<'\n';
 #define printall(x) {for(auto y:x){cout<<y<<' ';}cout<<'\n';}
 #define printallpii(x) for(auto y:x){cout<<y.fi<<','<<y.se<<' ';}cout<<'\n';
 #define print_err(arr,n) for(ull i=0;i<n;++i){cerr<<(arr)[i]<<" ";}cerr<<'\n';
 #define printall_err(x) for(auto y:x){cerr<<y<<' ';}cerr<<'\n';
 #define printallpii_err(x) for(auto y:x){cerr<<y.fi<<','<<y.se<<' ';}cerr<<'\n';
 #define fi first
 #define se second
 #define pb push_back
 #define eb emplace_back
 #define mp make_pair
 #define mt make_tuple
 #define pii pair<int,int>
 #define pll pair<long long,long long>
 #define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 #define SENSITIVITY 1e-9
 #define EQUAL(xx1,xx2) [](auto x1,auto x2){double ep=0.0001;double pos=x1-x2;if(pos<0){pos=-pos;}double maxi=(x1>x2)?(x1):(x2);if(pos/(maxi*ep)<SENSITIVITY)return true;else return false;}(xx1,xx2)
 #define pack(x) x.begin(),x.end()
 
 constexpr int64_t mod=1e9+7;

 struct timer
 {
 private:
     static int __timer_number;
 public:
     int timer_number;
     chrono::high_resolution_clock::time_point t1;
     timer(): t1(chrono::high_resolution_clock::now()),timer_number(__timer_number++)
     {
         cout<<"timer number "<<timer_number<<" init\n";
     }
     timer(const timer& t):t1(t.t1),timer_number(__timer_number++)
     {
         cout<<"timer number "<<timer_number<<" init\n";
     }
     template<class T=chrono::milliseconds>
     auto give_time()
     {
         chrono::high_resolution_clock::time_point t2;
         t2=chrono::high_resolution_clock::now();
         return chrono::duration_cast<T>(t2-t1);
     }
     template<class T=chrono::milliseconds>
     void print_time()
     {
         chrono::high_resolution_clock::time_point t2;
         t2=chrono::high_resolution_clock::now();
         auto d=chrono::duration_cast<T>(t2-t1);
         cout<<"time (default:milli) until now by timer "<<timer_number<<" : "<<d.count()<<'\n';
     }
     ~timer()
     {
         __timer_number--;
     }
 };
 int timer::__timer_number=0;
 






 
template<class T>
class trie{
private:
   vector<T> hold;
   int hold_size;
   int found;
   int _size;
  struct node{
    map<T,node*> link;
    int ending;
    node():link(map<T,node*>()),ending(0)
    {
 
    }
    ~node()
    {
 
    }
  };
  node root;
  void __traverse(node* const p,int index)
  {
    if(index==hold_size)
    {
      

      

      found=p->ending;
      return ;
    }
    

    

    

    

    

    

    

    

    

    

    

      auto it=p->link.find(hold[index]);
      if(it!=p->link.end())
      {
        __traverse(it->second,index+1);
      }
    

  }
  bool __del_traverse(node* const p,int index)
  {
    if(index==hold_size)
    {
      if(!p->ending)
      {
        --p->ending;
        return 1;
      }
      return 0;
    }
    auto it=p->link.find(hold[index]);
    if(it!=p->link.end())
    {
      return __del_traverse(it->second,index+1);
    }
    return 0;
  }
  void __dfs_clear(node* const p)
  {
    for(auto& x:p->link)
    {
      __dfs_clear(x.second);
      delete x.second;
    }
 
  }
public:
  trie():_size(0)
  {
 
  }
  void add_stuff(const vector<T>& v)
  {
    hold.assign(v.begin(),v.end());
    hold_size=v.size();
    int index=0;
    node* cur=&root;
    while(index!=hold_size)
    {
      auto it=cur->link.find(hold[index]);
      if(it==cur->link.end())
      {
        

        cur->link[hold[index]]=new node();
        

      }
      cur=cur->link[hold[index]];
      ++index;
    }
    ++(cur->ending);
    ++_size;
  }
  int find_stuff(const vector<T>& v) 
  {
    found=0;
    hold.assign(v.begin(),v.end());
    hold_size=v.size();
    __traverse(&root,0);
    return found;
  }
  bool delete_stuff(const vector<T>& v)
  {
    hold.assign(v.begin(),v.end());
    hold_size=v.size();
    auto val=__del_traverse(&root,0);
    if(val)
      --_size;
    return val;
  }
  void clear()
  {
    __dfs_clear(&root);
    root.link.clear();
    _size=0;
  }
  int size()
  {
    return _size;
  }
  ~trie()
  {
    clear();
  }
};
 
 
 
 
 
 
 template<class A>
 void ____internal__print(string s,A a)
 {
     auto index=s.find(',');
     cerr<<s.substr(0,index)<<": "<<a<<'\n';
 }
 template<class A,class ... B>
 void ____internal__print(string s,A a,B... b)
 {
     auto index=s.find(',');
     cerr<<s.substr(0,index)<<": "<<a<<", ";
     ____internal__print(s.substr(index+1,(int)s.length()-index-1),b...);
 }
 
 #define debug(...) \
 {string __debug__s__=string(#__VA_ARGS__)+",";____internal__print(__debug__s__,__VA_ARGS__);}
 
 bool isPrime(ll a)
 {
     if(a==1)
         return false;
     for(ll i=2; i*i<=a; ++i)
     {
         if(a%i==0)
         {
             return false;
         }
     }
     return true;
 }
 bool isPali(string s)
 {
     int _size=(s.length())/2;
     for(int i=0; i<_size; ++i)
     {
         if(s.at(i)!=s.at(s.length()-1-i))
         {
             return false;
         }
     }
     return true;
 }
 int gcd(int a,int b)
 {
     if(a==0)
     {
         return b;
     }
     else if(b==0)
     {
         return a;
     }
     else
     {
         int shift=__builtin_ctz(a|b);
         a>>=__builtin_ctz(a);
         do
         {
             b>>=__builtin_ctz(b);
             if(a>b)
             {
                 a=a^b;
                 b=a^b;
                 a=a^b;
             }
             b-=a;
         }
         while(b);
         return a<<shift;
     }
 }
 ll gcdll(ll a,ll b)
 {
     if(a==0)
     {
         return b;
     }
     else if(b==0)
     {
         return a;
     }
     else
     {
         ll shift=__builtin_ctzll(a|b);
         a>>=__builtin_ctzll(a);
         do
         {
             b>>=__builtin_ctzll(b);
             if(a>b)
             {
                 a=a^b;
                 b=a^b;
                 a=a^b;
             }
             b-=a;
         }
         while(b);
         return a<<shift;
     }
 }
 ll power(ll a,ll b,ll _mod)
 {
     a%=_mod;
     ll temp=a;
     ll ans=1;
     if(!b)
       return 1;
     int limit=63-__builtin_clzll(b);
     int index=0;
     while(index<=limit)
     {
         if(b&(1ll<<index))
         {
             ans=(ans*temp)%_mod;
         }
         ++index;
         temp=(temp*temp)%_mod;
     }
     return ans;
 }
 template<class T>
 inline void swapper(const T& d1,const T& d2)
 {
     for(int i=0;i<sizeof(T);++i)
     {
         *((char*)(&d1)+i)=(*((char*)(&d1)+i))^(*((char*)(&d2)+i));
     }
     for(int i=0;i<sizeof(T);++i)
     {
         *((char*)(&d2)+i)=(*((char*)(&d1)+i))^(*((char*)(&d2)+i));
     }
     for(int i=0;i<sizeof(T);++i)
     {
         *((char*)(&d1)+i)=(*((char*)(&d1)+i))^(*((char*)(&d2)+i));
     }
 }
 
 int kmp(const string& s,const string& t)
 {
     int s_size=s.size(),t_size=t.size();
     if(s_size<t_size)
         return 0;
     vector<int> arr(t_size);
     int len=0;
     for(int i=0;i<t_size;++i)
     {
         if(!i)
         {
             arr[i]=0;
             continue;
         }
         while(1)
         {
             if(t[len]==t[i])
             {
                 arr[i]=++len;
                 break;
             }
             if(!len)
             {
                 arr[i]=0;
                 break;
             }
             len=arr[len-1];
         }
     }
     

     int ans=0;
     for(int j=0,i=0;i<s_size;++i,++j)
     {
 

         if(s[i]==t[j])
         {
             if(j==t.length()-1)
             {
                 

                 j=arr[j]-1;
                 

                 ++ans;
             }
             continue;
         }
         if(!j)
         {
            --j;
            continue;
         }
         --i;
         j=arr[j-1]-1;
     }
     return ans;
 }
 template<class T>
 vector<T> LIS(vector<T> a)
 {
     int n=a.size();
     vector<pair<T,int>> v;
     vector<T*> add(n);
     add[0]=nullptr;
     v.push_back(make_pair(a[0],0));
     auto f=[](pair<T,int> a,pair<T,int> b){return a.first<b.first;};
     for(int i=1;i<n;++i)
     {
         auto it=lower_bound(v.begin(),v.end(),make_pair(a[i],-1),f);
         if(it==v.end())
         {
             add[i]=&a[0]+v.back().second;
             v.push_back(make_pair(a[i],i));
         }
         else
         {
             it->first=a[i];
             it->second=i;
             if(it==v.begin())
             {
                 add[i]=nullptr;
             }
             else
             {
                 add[i]=&a[0]+(it-1)->second;
             }
         }
     }
     vector<T> ans;
     ans.reserve(v.size());
     T* p=&a[0]+v.back().second;
     while(p!=nullptr)
     {
         ans.push_back(*p);
         p=(add[p-&a[0]]);
     }
     reverse(ans.begin(),ans.end());
     return ans;
 }
 
 

 string longest_palindromic_substring(const string& s)
 {
     if(s.size()<=1)
         return s;
     int len=s.size();
     vector<bool> odd(s.size(),1);
     vector<bool> even(s.size(),0);
     string ans=string(1,s[0]);
     for(int i=0;i<len-1;++i)
     {
         if(s[i]==s[i+1])
         {
             even[i]=1;
             if(ans.size()<2)
                 ans=s.substr(i,2);
         }
     }
     for(int i=3;i<=len;++i)
     {
         if(i&1)
         {
             for(int j=0;j<=len-i;++j)
             {
                 odd[j]=(s[j]==s[j+i-1])&&(odd[j+1]);
                 if(odd[j]&&ans.size()<i)
                     ans=s.substr(j,i);
             }
         }
         else
         {
             for(int j=0;j<=len-i;++j)
             {
                 even[j]=(s[j]==s[j+i-1])&&(even[j+1]);
                 if(even[j]&&ans.size()<i)
                     ans=s.substr(j,i);
             }
         }
     }
     return ans;
 }
 
 
 template<class S>
 S longestSubarraySum(auto start,auto end)
 {
   S val=0;
   S maxi=*start;
   for(auto s=start;s!=end;++s)
   {
     if(val+*s>=*s)
     {
       val+=*s;
     }
     else
     {
       val=*s;
     }
     if(maxi<val)
     {
       maxi=val;
     }
   }
   return maxi;
 }

template<class T>
T fibo(T x,T _mod)
{
  if(x==1)
  {
    return (T)0;
  }
  else if(x==2)
  {
    return (T)1;
  }
  

  stack<pair<T,T>> st;
  while(x>1)
  {
    st.push(make_pair(x,x+1));
    x/=2;
  }
  

  

  T a=0;
  T b=1;
  T c;
  while(st.size())
  {
    auto p=st.top();
    st.pop();
    T cur_a;
    T cur_b;
    if(p.first&1)
    {
      cur_a=(b*b+2*a*b)%_mod;
      b=(a+b)%_mod;
      a=(b-a+_mod)%_mod;
      cur_b=(a*a+b*b)%_mod;
    }
    else
    {
      cur_a=(a*a+b*b)%_mod;
      cur_b=(b*b+2*a*b)%_mod;
    }
    a=cur_a;
    b=cur_b;
  }
  return a;
}







int main()
{
  

  

  

  

  

  

  

  

  

  

 
  

  

  

  int tt=1;
  

  

  

  int ittt=1;
  

  while(tt--)
  {
    auto query=[](int64_t x,int64_t y)->int64_t{
      cout<<"? "<<x<<" "<<y<<endl;
      int64_t val;
      cin>>val;
      if(val==-1)
        exit(-1);
      return val;
    };
    int64_t start=1;
    int64_t ham;
    int64_t end=1e9;
    ham=query(1,1);
    

    if(end>1e9)
      end=1e9;
    while(start!=end)
    {
      auto mid=((int64_t)start+end)/2;
      auto val=query(mid,1);
      if(val+mid-1==ham)
      {
        start=mid+1;
      }
      else
      {
        end=mid;
      }
    }
    --start;

      int64_t l_x=start;
      int64_t l_y=query(start,1)+1;
      int64_t r_x;
      int64_t r_y;
      {
        auto val=query(1e9,1);
        r_x=1e9-val+l_y-1;
      }
      {
        auto val=query(1e9,1e9);
        r_y=1e9-(val-(1e9-r_x));
      }
      cout<<"! "<<l_x<<" "<<l_y<<" "<<r_x<<" "<<r_y<<endl;
  }
  

    return 0;
}