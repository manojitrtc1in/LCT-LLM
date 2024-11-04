





















typedef long long int ll;
typedef std::pair<int,int> ii;



int II(){int n;scanf("%d",&n);return n;}
void II(int n){printf("%d",n);}
void IIn(int n){printf("%d\n",n);}
void IIb(int n){printf("%d ",n);}
ll LL(){ll n;scanf("%lld",&n);return n;}
void LL(ll n){printf("%lld",n);}
void LLn(ll n){printf("%lld\n",n);}
void LLb(ll n){printf("%lld ",n);}
char CC(){return getchar();}
char CCa(){char c=getchar();while(c<=32)c=getchar();return c;}
void CC(char c){putchar(c);}
void CCn(char c){putchar(c);putchar(10);}
void CCb(char c){putchar(c);putchar(32);}
void CCn(){putchar(10);}
void CCb(){putchar(32);}
void SS(char *s){scanf("%s",s);}
void SSb(const char *s){printf("%s ",s);}
void SSn(const char *s){printf("%s\n",s);}
float FF(){float n;scanf("%f",&n);return n;}
void FF(float n){printf("%f",n);}
void FFn(float n){printf("%f\n",n);}
void FFb(float n){printf("%f ",n);}
void FF(double n,int prec){std::cout<<std::setprecision(prec)<<n;}
void FFn(double n,int prec){std::cout<<std::setprecision(prec)<<n;putchar(10);}
void FFb(double n,int prec){std::cout<<std::setprecision(prec)<<n;putchar(32);}


FILE *in=fopen("input.txt","r"),*out=fopen("output.txt","w");
int II(){int n;fscanf(in,"%d",&n);return n;}
void II(int n){fprintf(out,"%d",n);}
void IIn(int n){fprintf(out,"%d\n",n);}
void IIb(int n){fprintf(out,"%d ",n);}
ll LL(){ll n;fscanf(in,"%lld",&n);return n;}
void LL(ll n){fprintf(out,"%lld",n);}
void LLn(ll n){fprintf(out,"%lld\n",n);}
void LLb(ll n){fprintf(out,"%lld ",n);}
char CC(){return getc(in);}
char CCa(){char c=getc(in);while(c<=32)c=getc(in);return c;}
void CC(char c){putc(c,out);}
void CCn(char c){putc(c,out);putc(10,out);}
void CCb(char c){putc(c,out);putc(32,out);}
void CCn(){putc(10,out);}
void CCb(){putc(32,out);}
void SS(char *s){fscanf(in,"%s",s);}
void SSb(const char *s){fprintf(out,"%s ",s);}
void SSn(const char *s){fprintf(out,"%s\n",s);}
float FF(){float n;scanf("%f",&n);return n;}
void FF(float n){fprintf(out,"%f",n);}
void FFn(float n){fprintf(out,"%f\n",n);}
void FFb(float n){fprintf(out,"%f ",n);}





template <class T>std::ostream &operator<<(std::ostream &os, std::vector<T> const &V)
{ 
    os << "[";char pd[2]={0,0};for(auto x:V){os<<pd;os<<x;pd[0]=',';}os << "]";
    return os;
}

template <class T>std::ostream &operator<<(std::ostream &os, std::set<T> const &V)
{ 
    os << "{";char pd[2]={0,0};for(auto x:V){os<<pd;os<<x;pd[0]=',';}os << "}";
    return os;
}
template <class T>std::ostream &operator<<(std::ostream &os, std::unordered_set<T> const &V)
{ 
    os << "{";char pd[2]={0,0};for(auto x:V){os<<pd;os<<x;pd[0]=',';}os << "}";
    return os;
}

template <class T,class K>std::ostream &operator<<(std::ostream &os, std::map<T,K> const &V)
{ 
    os << "{";char pd[2]={0,0};for(auto x:V){os<<pd;os<<"["<<x.first<<"]"<<x.second;pd[0]=',';}os << "}";
    return os;
}
template <class T,class K>std::ostream &operator<<(std::ostream &os, std::unordered_map<T,K> const &V)
{ 
    os << "{";char pd[2]={0,0};for(auto x:V){os<<pd;os<<"["<<x.first<<"]"<<x.second;pd[0]=',';}os << "}";
    return os;
}

template <class T>std::ostream &operator<<(std::ostream &os, std::stack<T> const &V)
{ 
    os << "[";char pd[2]={0,0};for(auto x:V){os<<pd;os<<x;pd[0]=',';}os << "]";
    return os;
}
template <class T>std::ostream &operator<<(std::ostream &os, std::deque<T> const &V)
{ 
    os << "[";char pd[2]={0,0};for(auto x:V){os<<pd;os<<x;pd[0]=',';}os << "]";
    return os;
}
template <class T>std::ostream &operator<<(std::ostream &os, std::queue<T> const &V)
{ 
    os << "[";char pd[2]={0,0};for(auto x:V){os<<pd;os<<x;pd[0]=',';}os << "]";
    return os;
}
template <class T,class K>std::ostream &operator<<(std::ostream &os, std::pair<T,K> const &P)
{ 
    return os<<"("<<P.first<<","<<P.second<<")";
}



template<class T,int BASE,int MOD=1000000007>class rhash
{
  typedef long long int ll;
private:
public:
  int _hash;
  int id1,id2,_b_inv;
  size_t _size;
  std::hash<T> _hasher;
  int _pow_b(int b,int esp){if(!esp)return 1;return ((ll)_pow_b(((ll)b*b)%MOD,esp>>1)*((esp&1)?b:1))%MOD;}

  int _pow(int esp){return _pow_b(BASE,esp);};

  std::hash<T> &hash_function(){return _hasher;}

  int hash(){return _hash;}

  int size(){return _size;}

  bool empty(){return !_size;}

  bool operator<(const rhash b) const {if(_hash==b._hash)return _size<b._size;return _hash<b._hash;}
  bool operator==(rhash b){return _hash==b._hash&&_size==b._size;}

  bool operator!=(rhash b){return _hash!=b._hash||_size!=b._size;}

  rhash operator+(rhash b)

  {
    rhash ret=*this;
    ret+=b;
    return ret;
  }
  bool operator+=(rhash b)

  {
    _hash=((ll)_hash+(ll)b._hash*id1)%MOD;
    id2=((ll)id2+(ll)b.id2*id1)%MOD;
    id1=((ll)id1*b.id1)%MOD;
    _size+=b._size;
  }
  void fill(T s)

  {
    _hash=((ll)id2*(_hasher(s)%MOD))%MOD;
  }
  void push_back(T s)

  {
    _hash=((ll)_hash+(ll)(_hasher(s)%MOD)*id1)%MOD;
    _size++;
    id2=((ll)id2+id1)%MOD;
    id1=((ll)id1*BASE)%MOD;
  }
  void push_front(T s)

  {
    _hash=((ll)_hash*BASE+_hasher(s)%MOD)%MOD;
    _size++;
    id2=((ll)id2+id1)%MOD;
    id1=((ll)id1*BASE)%MOD;
  }
  void pop_back(T s)

  {
    _size--;
    id2=((ll)id2-id1+MOD)%MOD;
    id1=((ll)id1*_b_inv)%MOD;
    _hash=((ll)_hash-((ll)(_hasher(s)%MOD)*id1)%MOD+MOD)%MOD;
  }
  void pop_front(T s)

  {
    _hash=(((ll)_hash-_hasher(s)%MOD)+MOD)%MOD;
    _hash=((ll)_hash*_b_inv)%MOD;
    _size--;
    id1=((ll)id1*_b_inv)%MOD;
    id2=((ll)id2-id1+MOD)%MOD;
  }
  rhash()

  {
    _hash=_size=id2=0;
    _b_inv=_pow(MOD-2);
    id1=1;
  }
  rhash(T s)

  {
    _hash=_size=id2=0;
    _b_inv=_pow(MOD-2);
    id1=1;
    push_back(s);
  }
  rhash(T *first,T *last)

  {
    _hash=_size=id2=0;
    _b_inv=_pow(MOD-2);
    id1=1;
    for(;first!=last;first++)push_back(*first);
  }
  rhash(std::vector<T> &V)

  {
    _hash=_size=id2=0;
    _b_inv=_pow(MOD-2);
    id1=1;
    for(T x:V)push_back(x);
  }
};

template <class T,int BASE,int MOD>std::ostream &operator<<(std::ostream &os, rhash<T,BASE,MOD> const &H)
{ 
    return os<<H._hash;
}

template<class T,T Join(T,T)> class segment_tree
{
private:
public:
    int _l,_m,_r;
    T _val;
    segment_tree *_left,*_right;
    segment_tree(int l,int r,T k)
    {
        if(l==r)
        {
           _l=_r=_m=l;
           _val=k;
           _left=_right=NULL;
        }
        else
        {
            _l=l;
            _r=r;
            _m=(_l+_r)/2;
            _left=new segment_tree(_l,_m,k);
            _right=new segment_tree(_m+1,_r,k);
            _val=Join(_left->_val,_right->_val);
        }
    }
    void set(int p,T v)
    {

        if(p<_l||p>_r){cerr<<"index out of bounds";throw;};

        if(_l==_r){_val=v;return;}
        if(p>_m)_right->set(p,v);else _left->set(p,v);
        _val=Join(_left->_val,_right->_val);
    }
    
    T query(int s,int e)
    {

        if(_l>e||_r<s){cerr<<"index out of bounds";throw;};

        if(_l>=s&&_r<=e)return _val;
        if(s>_m)return _right->query(s,e);
        if(e<=_m)return _left->query(s,e);
        return Join(_left->query(s,e),_right->query(s,e));
    }
};

template<class T,int id0,char OFFSET>class id3
{
private:
public:
    T _val;
    id3 *_sons[id0];
    T& operator[](char *s)
    {
        if(!*s)return _val;
        if(_sons[*s-OFFSET]==NULL)_sons[*s-OFFSET]=new id3();
        return _sons[*s-OFFSET]->operator[](s+1);
    }
    T *find(char *s)
    {
        if(!*s)return &_val;
        if(_sons[*s-OFFSET]==NULL)return NULL;
        return _sons[*s-OFFSET]->find(s+1);
    }
    id3()
    {
        _val=T();
        for(id3*& t:_sons)t=NULL;
    }
};




constexpr int MAXN=300000;

struct node_t;
struct trie;

struct edge_t
{
    node_t* to;
    char label;
};

std::ostream &operator<<(std::ostream &os, edge_t const &E)
{ 
    return os<<E.label;
}

struct node_t
{
    int subsize,depth;
    std::vector<edge_t> adj;
    int compute(int d)
    {
        depth=d;
        subsize=1;
        for(edge_t &e:adj)subsize+=e.to->compute(d+1);
        return subsize;
    }
    trie* dfs();
};

struct trie
{
    trie *sons[26];
    int endword,size;
    trie(trie *s,char sc){for(int x=0;x<26;x++)sons[x]=NULL;endword=0;size=1+s->size;sons[sc-'a']=s;}
    trie(){for(int x=0;x<26;x++)sons[x]=NULL;endword=0;size=1;}
    trie(int nd){for(int x=0;x<26;x++)sons[x]=NULL;endword=nd;size=1;}
    void add_tree(node_t* u)
    {
        if(u->adj.empty()){endword++;return;}

        for(edge_t &e:u->adj)
        {
            if(!sons[e.label-'a']){sons[e.label-'a']=new trie(0);size++;}
            size-=sons[e.label-'a']->size;
            sons[e.label-'a']->add_tree(e.to);
            size+=sons[e.label-'a']->size;
        }
    }
    int rm_tree(node_t* u)
    {
        if(u->adj.empty()){endword--;return 0;}

        int removed=0;
        for(edge_t &e:u->adj)
        {
            removed+=sons[e.label-'a']->rm_tree(e.to);
            if(sons[e.label-'a']->endword==0 && sons[e.label-'a']->size==1)
            {
                delete sons[e.label-'a'];
                sons[e.label-'a']=NULL;
                removed++;
            }
        }
        size-=removed;
        return removed;
    }
    
};

void tour(trie *t,int s=0)
{
    if(!t || s>3)return;
    for(int x=0;x<s;x++)printf("  ");printf("size %d endword %d at %p\n",t->size,t->endword,t);
    for(int x=0;x<s;x++)printf("  ");printf("{\n");
    for(int x=0;x<26;x++)if(t->sons[x]){for(int y=0;y<s;y++)printf("  ");printf("[%c]\n",x+'a');tour(t->sons[x],s+1);}
    for(int x=0;x<s;x++)printf("  ");printf("}\n");
}

node_t T[MAXN];

bool diff(node_t *u,trie *t)
{
    if(u->subsize!=t->size){printf("different size at %d\n",u-T+1);return true;}
    for(edge_t &e:u->adj)
    {
        if(t->sons[e.label-'a']==NULL)return true;
        if(diff(e.to,t->sons[e.label-'a']))return true;
    }
    return false;
}

int ans[MAXN];




trie* node_t::dfs()

    {
        if(adj.empty())
        {
            

            return new trie(1);
        }
        

        {
            auto itb=adj.begin();
            for(auto it=adj.begin();it<adj.end();it++)if(it->to->subsize>itb->to->subsize)itb=it;
            std::swap(*itb,adj.back());
        }
        edge_t bigchild=adj.back();adj.pop_back();
        

        trie *id4=bigchild.to->dfs();
        

        
        for(edge_t &e:adj)id4->add_tree(e.to);
        
        

        ans[depth]+=id4->size-subsize;
        for(edge_t &e:adj)id4->rm_tree(e.to);
        

        trie *rtrie=new trie(0);
        rtrie->sons[bigchild.label-'a']=id4;rtrie->size+=id4->size;
        for(edge_t &e:adj){rtrie->sons[e.label-'a']=e.to->dfs();rtrie->size+=rtrie->sons[e.label-'a']->size;}
        

        
        return rtrie;
    }


using namespace std;
int main()
{
    int N=II();
    fill(ans,ans+N,N);
    for(int x=1;x<N;x++)
    {
        int u=II()-1,v=II()-1;char c=CCa();
        T[u].adj.push_back({T+v,c});
    }
    T[0].compute(0);
    T[0].dfs();
    

    int bst=0;
    for(int x=0;x<N;x++)if(ans[x]<ans[bst])bst=x;
    IIn(ans[bst]);
    IIn(bst+1);
}
