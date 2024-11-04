



















using namespace std;

    
    
  

    
    
  


typedef long long int llint;
typedef unsigned long long int ullint;














template<typename A,typename B>
ostream& operator<<(ostream& out,const pair<A,B>& pp)
{
  out<<"("<<pp.first<<","<<pp.second<<")";
  return out;
}
template<typename A,typename B>
istream& operator<<(istream& in,pair<A,B>& pp)
{
  cerr<<"A pair wanted"<<endl;
  in>>pp.first>>pp.second;
  return in;
}

template<typename T>
ostream& operator<<(ostream& out,const vector<T>& vect)
{
  out<<"length = "<<vect.size()<<endl;
  for(int i=0;i<vect.size();i++)out<<vect[i]<<" ";
  out<<endl;
  return out;
}
ostream& operator<<(ostream& out,const vector<string>& vect)
{
  out<<vect.size()<<" X "<<vect[0].length()<<endl;
  for(int i=0;i<vect.size();i++)out<<vect[i]<<endl;
  return out;
}
template<typename T>
istream& operator>>(istream& in,vector<T>& vect)
{
  vect.clear();
  int n;
  cerr<<"A integer of length wanted"<<endl;
  in>>n;
  vect.resize(n);
  cerr<<n<<" elements wanted"<<endl;
  for(int i=0;i<n;i++)in>>vect[i];
  return in;
}

template<typename T>
ostream& operator<<(ostream& out,const vector<vector<T> >& vect)
{
  out<<"row number="<<vect.size()<<endl;
  for(int i=0;i<vect.size();i++)
  {
    out<<"row 
    for(int j=0;j<vect[i].size();j++)
      out<<" "<<vect[i][j];
    out<<endl;
  }
  return out;
}
template<typename T>
istream& operator>>(istream& in,vector<vector<T> >& vect)
{
  vect.clear();
  int n,m;
  cerr<<"Two integers wanted"<<endl;
  in>>n>>m;
  vect.resize(n);
  cerr<<"A matrix "<<n<<" X "<<m<<" wanted"<<endl;
  for(int i=0;i<n;i++)
  {
    vect[i].resize(m);
    for(int j=0;j<m;j++)in>>vect[i][j];
  }
  return in;
}





template<typename T>
inline void updateMax(T& a,const T& b){a=max(a,b);}
template<typename T>
inline void updateMin(T& a,const T& b){a=min(a,b);}
template<typename T>
inline vector<T> erase(vector<T> table,int ind)
{
  assert(ind<table.size());
  table.erase(table.begin()+ind);
  return table;
}
template<typename T>
vector<T> unique(vector<T> table)
{
  SORT(table);
  return vector<T>(table.begin(),unique(table.begin(),table.end()));
}



template<class T>
vector<T> parse(const string& ss,const char* cut=" ")
{
  vector<T> re;
  for(int j=0;j<ss.size();j++)
  {
    string s;
    while(j<ss.size()&&NULL==strchr(cut,ss[j]))
      s+=ss[j++];
    if(!s.empty())
    {
      T tmp;
      istringstream is(s);
      is>>tmp;
      re.push_back(tmp);
    }
  }
  return re;
}







template<typename T>
T id1(T n,T m,T& a,T& b)
{
  T a1=0,b1=1;
  a=1,b=0;
  

  while(m)
  {
    T c=n/m;
    T r=n-m*c;
    T t;
    t=a;a=a1;a1=t-c*a1;
    t=b;b=b1;b1=t-c*b1;
    n=m;m=r;
  }
  return n;
}


class fraction
{

  llint a,b;
  void simplify(){while(b==0);assert(b);llint g=id1(myabs(a),myabs(b));a/=g;b/=g;if(b<0)b=-b,a=-a;};
public:
  fraction(llint aa=0,llint bb=1):a(aa),b(bb){assert(b);simplify();};
  void setValue(llint aa,llint bb){a=aa,b=bb;assert(b);simplify();};
  void getValue(llint& aa,llint& bb){aa=a,bb=b;};
  fraction operator+(const fraction& fb);
  fraction operator+=(const fraction& ff);

  fraction operator-(const fraction& ff);
  fraction operator-=(const fraction& ff);
  
  fraction operator*(const fraction& ff);
  fraction operator*=(const fraction& ff);

  fraction operator/(const fraction& ff);
  fraction operator/=(const fraction& ff);
  friend bool operator==(const fraction& fa,const fraction& fb)
  {
    return fa.a==fb.a&&fa.b==fb.b;
  };
  friend bool operator<(const fraction& fa,const fraction& fb)
  {
    fraction d=fraction(fa)-(fb);
    return d.a<0;
  };
  friend bool operator>(const fraction& fa,const fraction& fb)
  {
    fraction d=fraction(fa)-fb;
    return d.a>0;
  };
  friend ostream& operator<<(ostream& out,const fraction&);

};

ostream& operator<<(ostream& out,const fraction& ff){out<<ff.a<<"/"<<ff.b;return out;}
fraction fraction::operator+(const fraction& fb)
{
  llint g=id1(myabs(b),myabs(fb.b));
  fraction res;
  res.b=b/g*fb.b;
  res.a=a*(fb.b/g)+fb.a*(b/g);
  res.simplify();
  return res;
}
fraction fraction::operator+=(const fraction& fb)
{
  fraction res=(*this)+fb;
  *this=res;
  return *this;
}
fraction fraction::operator-(const fraction& fb)
{
  llint g=id1(myabs(b),myabs(fb.b));
  fraction res;
  res.b=b/g*fb.b;
  res.a=a*(fb.b/g)-fb.a*(b/g);
  res.simplify();
  return res;
}
fraction fraction::operator-=(const fraction& fb)
{
  fraction res=(*this)-fb;
  *this=res;
  return *this;
}
fraction fraction::operator*(const fraction& fb)
{
  llint g1=id1(myabs(a),myabs(fb.b));
  llint g2=id1(myabs(fb.a),myabs(b));
  fraction res(a/g1*(fb.a/g2),b/g2*(fb.b/g1));
  res.simplify();
  return res;
}
fraction fraction::operator*=(const fraction& fb)
{
  fraction res=(*this)*fb;
  *this=res;
  return *this;
}
fraction fraction::operator/(const fraction& fb)
{
  while(fb.a==0);
  llint g1=id1(myabs(a),myabs(fb.a));
  llint g2=id1(myabs(fb.b),myabs(b));
  fraction res(a/g1*(fb.b/g2),b/g2*(fb.a/g1));
  res.simplify();
  return res;
}
fraction fraction::operator/=(const fraction& fb)
{
  fraction res=(*this)/fb;
  *this=res;
  return *this;
}




struct BigN
{
  vector<int> dig;
  int sig;
  static const int B=10000;
  BigN():sig(0){};
  void setValue(int a){sig=0;if(a<0)sig=1,a=-a;dig.clear();while(a)dig.push_back(a%B),a/=B;};
  BigN(int v):sig(0){setValue(v);};
  void shrink()
  {
    while(dig.size()&&dig.back()==0)dig.pop_back();
    if(dig.empty())sig=0;
  };
  void operator+=(const BigN& b);
  void operator-=(const BigN& b){BigN c=b;c.sig^=1;(*this)+=c;};
  void operator*=(const BigN& b);
  void operator*=(int v);
  void print(FILE* f=stderr,const char *tail="")const
  {if(sig)fprintf(f,"-");if(dig.empty()){fprintf(f,"0");return;}
    fprintf(f,"%d",dig.back());for(int i=(int)dig.size()-2;i>=0;i--)fprintf(f,"%04d",dig[i]);
    fprintf(f,"%s",tail);};
};

void add(vector<int>& a,const vector<int>& b,int s=0)
{
  while(a.size()<b.size()+s)a.push_back(0);
  int c=0;
  for(int i=0;i<b.size();i++)
  {a[i+s]+=b[i]+c;c=a[i+s]/BigN::B;a[i+s]%=BigN::B;}
  if(c)
  {for(int i=b.size()+s;i<a.size();i++)
  {if(a[i]+c<BigN::B){a[i]+=c,c=0;break;}}if(c)a.push_back(c);}
}
void sub(vector<int>& a,const vector<int>& b)
{
  assert(a.size()>=b.size());
  int c=0;
  for(int i=0;i<b.size();i++)
  {a[i]-=b[i]+c;c=0;if(a[i]<0)a[i]+=BigN::B,c=1;}
  for(int i=b.size();i<a.size()&&c;i++)if(a[i])a[i]--,c=0;
  assert(c==0);
  while(a.size()&&a.back()==0)a.pop_back();
}

int cmp(const vector<int>& a,const vector<int>& b)
{
  if(a.size()!=b.size())return a.size()-b.size();
  for(int i=(int)a.size()-1;i>=0;i--)
    if(a[i]!=b[i])return a[i]-b[i];
  return 0;
}
void BigN::operator+=(const BigN& b)
{
  if(sig==b.sig)add(dig,b.dig);
  else if(cmp(dig,b.dig)>=0)sub(dig,b.dig);
  else{vector<int> c=b.dig;sub(c,dig);sig=b.sig;dig=c;}
  shrink();
}
void BigN::operator*=(int v)
{
  if(v==0){setValue(0);return ;}
  if(v<0)v=-v,sig^=1;
  assert(v<BigN::B);
  int c=0;
  for(int i=0;i<dig.size();i++){dig[i]*=v,dig[i]+=c;c=dig[i]/B;dig[i]%=B;}
  if(c)dig.push_back(c);
}
void BigN::operator*=(const BigN& b)
{
  sig^=b.sig;vector<int> all;all.swap(dig);assert(dig.empty());
  for(int i=0;i<all.size();i++)
  {BigN tmp=b;tmp*=(all[i]);add(dig,tmp.dig,i);}
  shrink();
}



struct Node
{
  int r,c,d;
  int v;
  Node(int x,int y,int z,int v1):r(x),c(y),d(z),v(v1){};
  bool operator<(const Node& other)const
  {
    return v>other.v;
  };
};




priority_queue<Node> heap;



const int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const char dname[]="NWSE";




const double EPS=1e-15;
const double eps=1e-10;


typedef int ptype;
typedef complex<ptype> point;
typedef complex<double> dcomp;


const double PI=acos(-1.0);
double mysqrt(double v)
{if(v<EPS)return 0.0;return sqrt(v);}
template<typename T>
double length(complex<T> p)
{return sqrt(1.0*p.x()*p.x()+1.0*p.y()*p.y());}
template<typename T>
double dnorm(complex<T> p)
{return (1.0*p.x()*p.x()+1.0*p.y()*p.y());}
int sigcross(llint x1,llint y1,llint x2,llint y2,llint x3,llint y3)
{
  llint re=(llint)(x1-x3)*(y2-y3)-(llint)(y1-y3)*(x2-x3);
  if(re<0)return -1;if(re>0)return 1;return 0;
}
template<typename T>
llint llcross(complex<T> p1,complex<T> p2)
{return (llint)p1.x()*(llint)p2.y()-(llint)p2.x()*(llint)p1.y();}
template<typename T>
int sigcross(complex<T> p1,complex<T> p2)
{llint re=llcross(p1,p2);if(re<0)return -1;if(re>0)return 1;return 0;}
template<typename T>
double dcross(complex<T> p1,complex<T> p2)
{return 1.0*p1.x()*p2.y()-p2.x()*p1.y();}
template<typename T>
double ddot(complex<T> p1,complex<T> p2)
{return 1.0*p1.x()*p2.x()+1.0*p1.y()*p2.y();}
template<typename T>
bool pointCmp(const complex<T>& p1,const complex<T>& p2)
{return p1.x()<p2.x()||(p1.x()==p2.x()&&p1.y()<p2.y());}
template<typename T>
bool operator<(const complex<T>& a,const complex<T>& b)
{return a.x()<b.x()||(a.x()==b.x()&&a.y()<b.y());}
template<typename T>
class pointLess : public less<complex<T> >
{public:bool operator()(const complex<T>& a,const complex<T>& b)const{return a<b;};};





template<typename T>
class Matrix:public vector<vector<T> >
{
  static T (*_add)(const T&,const T&);
  static T (*_mul)(const T&,const T&);
  

  

  static T _zero,_one;
public:
  static void set_para(T (*add)(const T&,const T&),T (*mul)(const T&,const T&),const T& zero,const T& one)
  {_add=add;_mul=mul;_zero=zero;_one=one;};
  void resize(int n,int m){this->resize(n);for(int i=0;i<n;i++)this->at(i).resize(m);};
  Matrix(){vector<vector<T> >();};
  Matrix(int n,int m):vector<vector<T> >(n,vector<T>(m)){};
  Matrix(int n,int m,const T& v):vector<vector<T> >(n,vector<T>(m,v)){};
  Matrix<T> operator+(const Matrix& other)const;
  Matrix<T> operator-(const Matrix& other)const;
  Matrix<T> operator*(const Matrix&)const;
  Matrix<T> power(llint s)const;
  

  Matrix<T> power_sum(llint s)const;
  static Matrix<T> ONE(int n,int m){Matrix<T> res(n,m,_zero);for(int i=0;i<n;i++)res[i][i]=_one;return res;};
  static Matrix<T> ZERO(int n,int m){Matrix<T> res(n,m,_zero);return res;};
};
template<typename T> T (*Matrix<T>::_add)(const T&,const T&)=NULL;
template<typename T> T (*Matrix<T>::_mul)(const T&,const T&)=NULL;
template<typename T> T Matrix<T>::_zero;
template<typename T> T Matrix<T>::_one;
template<typename T>
Matrix<T> Matrix<T>::power(llint s)const
{
  assert(this->size()==this->at(0).size());
  Matrix<T> res=Matrix<T>::ONE(this->size(),this->at(0).size());
  Matrix<T> t=*this;assert(s>=0);
  while(s){if(1&s)res=res*t;t=t*t;s>>=1;}return res;
}
template<typename T>
Matrix<T> Matrix<T>::power_sum(llint s)const
{
  assert(this->size==this->at(0).size());
  if(s==1)return *this;
  if(s==0)return Matrix<T>::ZERO(this->size(),this->size());
  llint mid=s/2;Matrix<T> low=power_sum(mid);Matrix<T> high;
  if(s-mid>mid)high=low+power(s-mid);else high=low;
  high=high*power(mid);return low+high;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& b)const
{
  const Matrix<T>& a=*this;const int n=a.size();assert(n);
  int p=a[0].size();assert(p);assert(p==b.size());int m=b[0].size();assert(m);
  Matrix<T> res(n,m);for(int i=0;i<n;i++)for(int j=0;j<m;j++)
  {T t=_zero;for(int k=0;k<p;k++)t=_add(t,_mul(a[i][k],b[k][j]));res[i][j]=t;}return res;
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other)const
{
  assert(this->size==other.size());
  assert(this->size()==0||this->at(0).size()==other[0].size());
  const int n=this->size();if(n==0)return Matrix<T>();const int m=other[0].size();
  Matrix<T> res(n,m);for(int i=0;i<n;i++)for(int j=0;j<m;j++)res[i][j]=_add((*this)[i][j],other[i][j]);
  return res;
}




template<typename T>
void update(int pos,T add,T tree[],int n)
{while(pos<=n)tree[pos]+=add,pos+=low(pos);}
template<typename T>
T query(int pos,T tree[])
{T res=0;while(pos)res+=tree[pos],pos^=low(pos);return res;}





struct Interval_tree
{
  typedef int type;
  const static int N=10000;
  int n;
  type tree[4*N],flag[4*N];

  void build_tree(int m);
  void build_tree(int low,int high,int ind);
  type query(int low,int high,int b,int e,int ind);
  type query(int b,int e);
  void update(int pos,type v);
  void update(int b,int e,type v);
};




int get_root(int a,vector<int>& root)
{
  if(root[a]==-1)return a;
  return (root[a]=get_root(root[a],root));
}
template<typename T>
struct Edge
{
  int a,b;
  T c;
  Edge(int _a,int _b,T _c){a=_a;b=_b;c=_c;};
  bool operator<(const Edge<T>& other)const{return c<other.c;};
};



void update_interval(llint a,llint b,llint& lower,llint& upper)
{
  if(a==0){if(0<=b)return;upper=-1,lower=0;return;}
  if(a>0){if(b>=0)upper=min(upper,b/a);else upper=min(upper,(b-a+1)/a);}
  else{a=-a;b=-b;if(b>=0)lower=max(lower,(b+a-1)/a);else lower=max(lower,b/a);}
}
template<typename T,int N>
void id0(T com[N][N],bool take_mod=false,long long int mod=1000000000000000000LL)
{
  if(take_mod)
  {
    assert(mod>0);
    com[0][0]=1%mod;
    for(int i=1;i<N;i++)
    {
      com[i][0]=com[i][i]=1%mod;
      for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
    }
  }
  else
  {
    com[0][0]=1;
    for(int i=1;i<N;i++)
    {
      com[i][0]=com[i][i]=1;
      for(int j=1;j<i;j++)com[i][j]=(com[i-1][j-1]+com[i-1][j]);
    }
  }
}








const int N=5002;
char grid[N][N];
struct node_t {
  int next[4],pre[4];
};
node_t node[N*10];
int hash[1000];
int st[N*2];
string name="URDL.";
int main() {
  int n,m;
  cin>>n>>m;
  For(i,1,n+1) {
    

    cin>>(grid[i]+1);
  }
  Rep(i,4)hash[name[i]]=i;


  For(r,1,n+1)For(c,1,m+1) if('.'!=grid[r][c]){
    int nnr[4],nnc[4];
    Rep(d,4) {
      int& nr=nnr[d];
      int& nc=nnc[d];
      nr=r+dir[d][0],nc=c+dir[d][1];
      while(grid[nr][nc]=='.') {
        nr+=dir[d][0];
        nc+=dir[d][1];
      }
    }
    const int idx=Idx(r,c);
    Rep(d,4) {
      node[idx].next[d]=Idx(nnr[d],nnc[d]);
      node[Idx(nnr[d],nnc[d])].pre[d]=idx;
      node[idx].pre[d]=Idx(nnr[d^2],nnc[d^2]);
      node[Idx(nnr[d^2],nnc[d^2])].next[d]=idx;
    }
  }
  

  int best=0,ans=1;
  For(r,1,n+1)For(c,1,m+1) if('.'!=grid[r][c]){
    int len=0;
    int x=r,y=c;
    while(1<=x&&x<=n&&1<=y&&y<=m) {
      assert(grid[x][y]&&grid[x][y]!='.');
      int go=hash[grid[x][y]];
      const int idx=Idx(x,y);
      st[len++]=(idx<<2)^go;
      const int nidx=node[idx].next[go];
      Rep(go,4) {
        node[node[idx].next[go]].pre[go]=node[idx].pre[go];
        node[node[idx].pre[go]].next[go]=node[idx].next[go];
      }
      x=nidx/(m+2);
      y=nidx%(m+2);
    }
    if(len>best)best=len,ans=1;
    else if(len==best)ans++;
    while(len--) {
      const int idx=st[len]>>2;
      int go=st[len]&3;
      Rep(go,4) {
        node[node[idx].next[go]].pre[go]=idx;
        node[node[idx].pre[go]].next[go]=idx;
      }
    }
  }
  cout<<best<<" "<<ans;
  return 0;
}
