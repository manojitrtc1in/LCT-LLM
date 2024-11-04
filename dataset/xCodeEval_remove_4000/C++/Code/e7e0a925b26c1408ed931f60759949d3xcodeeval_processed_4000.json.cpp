



using namespace __gnu_pbds;
using namespace std;



typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef __int128_t int128;
typedef __uint128_t uint128;

template<class A,class B,class C>
struct triple{
    A first;B second;C third;
};



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());












template<class A,class B,class C>
istream&operator>>(istream&stream,triple<A,B,C>&obj){
    stream>>obj.first>>obj.second>>obj.third;
    return stream;
}
template<class A,class B,class C>
ostream&operator<<(ostream&stream,const triple<A,B,C>&obj){
    stream<<obj.first<<" "<<obj.second<<" "<<obj.third;
    return stream;
}

template<typename A,typename B>
istream&operator>>(istream&stream,pair<A,B>&obj){
    stream>>obj.first>>obj.second;
    return stream;
}
template<typename A,typename B>
istream&operator>>(istream&stream,const pair<A,B>&obj){
    stream>>obj.first>>obj.second;
    return stream;
}
template<typename A,typename B>
ostream&operator<<(ostream&stream,const pair<A,B>&obj){
    stream<<obj.first<<" "<<obj.second;
    return stream;
}

ostream&operator<<(ostream&stream,int128&n){
    string res;
    bool negative=n<0;
    if(negative)n*=-1;
    if(n==0)res="0";
    while(n){
        res+='0'+(n%10);
        n/=10;
    }
    if(negative)res+='-';
    reverse(res.begin(),res.end());
    stream<<res;
    return stream;
}
istream&operator>>(istream&stream,int128&n){
    string s;
    if(!(stream>>s))return stream;
    n=0;
    bool negative=0;
    if(s[0]=='-')negative=1;
    for(int i=negative;i<s.size();i++)n*=10,n+=s[i]-'0';
    if(negative)n*=-1;
    return stream;
}
ostream&operator<<(ostream&stream,uint128&n){
    string res;
    bool negative=n<0;
    if(negative)n*=-1;
    if(n==0)res="0";
    while(n){
        res+='0'+(n%10);
        n/=10;
    }
    if(negative)res+='-';
    reverse(res.begin(),res.end());
    stream<<res;
    return stream;
}
istream&operator>>(istream&stream,uint128&n){
    string s;
    if(!(stream>>s))return stream;
    n=0;
    bool negative=0;
    if(s[0]=='-')negative=1;
    for(int i=negative;i<s.size();i++)n*=10,n+=s[i]-'0';
    if(negative)n*=-1;
    return stream;
}



template<typename T>
void input(T*ptr,int n){
    while(n--){
        cin>>(*ptr);
        ptr++;
    }
}
template<class It>
void print(It it,int n){
    if(n==0)return;
    cout<<*it;
    while(--n)cout<<" "<<*(++it);
    cout<<"\n";
}



template<typename A>
auto amin(A a){
    return a;
}
template<typename A,typename... B>
auto amin(A a, B... b){
    auto res=amin(b...);
    return (a<res)?a:res;
}
template<typename A>
auto amax(A a){
    return a;
}
template<typename A,typename... B>
auto amax(A a, B... b){
    auto res=amax(b...);
    return (a>res)?a:res;
}
template<typename A,typename... B>
void smin(A&a,B... b){
    auto res=amin(b...);
    a=((a<res)?a:res);
}
template<typename A,typename... B>
void smax(A&a,B... b){
    auto res=amax(b...);
    a=((a>res)?a:res);
}
template<class It1,class It2>
int first_diff(It1 a,It1 b,It2 A,It2 B){
    for(int i=0;a+i!=b&&A+i!=B;i++){
        if(!(*(a+i)==*(A+i)))return i;
    }
    return -1;
}
template<class It1,class It2,class Eq>
int first_diff(It1 a,It1 b,It2 A,It2 B,Eq f){
    for(int i=0;a+i!=b&&A+i!=B;i++){
        if(f(*(a+i),*(A+i)))return i;
    }
    return -1;
}
template<typename A,typename B,typename C>
bool in_range(A a,B b,C c){
    return (b<=a&&a<=c);
}
template<typename A,typename B,typename C>
auto to_range(A a,B b,C c){
    if(a<b)return b;
    return c;
}








typedef tree<
TREE_TYPE,
null_type,
less<TREE_TYPE>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;







const int NMAX=2000;
int leader[NMAX+5];
int sz[NMAX+5];
int mask[NMAX+5];
void build(int n){
    for(int i=0;i<=n;i++)leader[i]=i,sz[i]=1,mask[i]=0;
}
int get(int v){
    if(leader[v]==v)return v;
    return leader[v]=get(leader[v]);
}
void unite(int u,int v){
    u=get(u);v=get(v);
    if(u==v)return;
    if(sz[u]>sz[v])swap(u,v);
    leader[u]=v;
    sz[u]+=sz[v];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        build(n);
        int a[n];
        input(a,n);
        int ans=0;
        for(auto&e:a)if(e==0)e++,ans++;
        for(int i=0;i<n;i++){
            for(int ii=0;ii<n;ii++){
                if((a[i]&a[ii])>0){
                    unite(i,ii);
                    mask[get(i)]|=a[i];
                    mask[get(i)]|=a[ii];
                }
            }
        }
        set<pair<int,int>>st;
        for(int i=0;i<n;i++)st.insert({mask[get(i)],get(i)});
        if(st.size()==1){
            cout<<ans<<"\n";
            print(a,n);
            continue;
        }
        vector<pair<int,int>>vec;
        for(auto e:st)vec.push_back(e);
        sort(vec.begin(),vec.end(),[](pair<int,int>&l,pair<int,int>&r){
            return __builtin_ctz(l.first)>__builtin_ctz(r.first);
        });
        int bit=1<<__builtin_ctz(vec[0].first);
        vector<int>vec2;
        for(int i=0;i<n;i++){
            if(!(a[i]&bit))continue;
            vec2.push_back(i);
        }
        if(vec2.size()==1){
            a[vec2[0]]--;
            cout<<ans+1<<"\n";
            print(a,n);
            continue;
        }
        bool stop=0;
        for(int i=0;i<n;i++){
            a[i]++;
            build(n);
            for(int bit=0;bit<30;bit++){
                int last=-1;
                for(int ii=0;ii<n;ii++){
                    if((a[ii]&(1<<bit))){
                        if(last==-1)last=ii;
                        else unite(ii,last),last=ii;
                    }
                }
            }
            bool good=1;
            for(int ii=0;ii<n;ii++)if(get(ii)!=get(0))good=0;
            if(good){
                cout<<ans+1<<"\n";
                print(a,n);
                stop=1;
                break;
            }
            a[i]--;
            if(a[i]!=0)a[i]--;
            else continue;
            build(n);
            for(int bit=0;bit<30;bit++){
                int last=-1;
                for(int ii=0;ii<n;ii++){
                    if((a[ii]&(1<<bit))){
                        if(last==-1)last=ii;
                        else unite(ii,last),last=ii;
                    }
                }
            }
            good=1;
            for(int ii=0;ii<n;ii++)if(get(ii)!=get(0))good=0;
            if(good){
                cout<<ans+1<<"\n";
                print(a,n);
                stop=1;
                break;
            }
            a[i]++;
        }
        if(stop)continue;

        int ansd=2;int pos1=0;;
        for(int i=0;i<vec2.size();i++){
            for(int ii=i+1;ii<vec2.size();ii++){
                if((a[vec2[i]]&a[vec2[ii]])!=bit){
                    if(1<ansd){
                        ansd=1;
                        pos1=vec2[i];
                    }
                }
            }
        }
        if(ansd==2){
            a[vec2[0]]--;
            a[vec2[1]]++;
        }else{
            a[pos1]--;
        }
        cout<<ans+ansd<<"\n";
        print(a,n);
    }
}