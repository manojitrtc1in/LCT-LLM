



















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
{while(pos<=n)tree[pos]+=add,pos+=Low(pos);}
template<typename T>
T query(int pos,T tree[])
{T res=0;while(pos)res+=tree[pos],pos^=Low(pos);return res;}





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



template<int S,bool (*cmpLess)(int ,int )>
class binaryHeap
{
	int heap[S],hpos[S];
	int hs;
public:
	binaryHeap<S,cmpLess>(){hs=0;};
	void adjustUp(int key)
	{
		int pos=hpos[key];
		assert(pos>=0&&pos<hs);
		assert(heap[pos]==key);
		while(pos&&cmpLess(key,heap[(pos-1)>>1]))
		{
			heap[pos]=heap[(pos-1)>>1];
			hpos[heap[pos]]=pos;
			pos=(pos-1)>>1;
		}
		heap[pos]=key;
		hpos[key]=pos;
	}
	void adjustDown(int key)
	{
		int pos=hpos[key],mm;
		assert(pos>=0&&pos<hs);
		assert(heap[pos]==key);
		while((pos<<1)+1<hs)
		{
			mm=1+(pos<<1);
			if(mm+1<hs&&cmpLess(heap[mm+1],heap[mm]))mm++;
			if(cmpLess(key,heap[mm]))break;
			heap[pos]=heap[mm];
			hpos[heap[pos]]=pos;
			pos=mm;
		}
		heap[pos]=key;
		hpos[key]=pos;
	}
	int popHeap()
	{
		int re=heap[0];
		hs--;
		if(hs)
		{
			heap[0]=heap[hs];
			hpos[heap[0]]=0;
			adjustDown(heap[0]);
		}
		return re;
	}
	void removeHeap(int key)
	{
		int pos=hpos[key];
		assert(pos>=0&&pos<hs);
		assert(heap[pos]==key);
		heap[pos]=heap[hs-1];
		hpos[heap[pos]]=pos;
		hs--;
		if(hs)
		{
			adjustUp(heap[pos]);
			adjustDown(heap[pos]);
		}
	}
	void pushHeap(int key)
	{
		heap[hs]=key;
		hpos[key]=hs;
		hs++;
		adjustUp(key);
	}
	int size(){return hs;};
	void clear(){hs=0;};
  int getTop() {
    return heap[0];
  }
};
llint event[100010];
bool cmpLess(int a,int b) {
  return event[a]<event[b];
}







binaryHeap<100100,cmpLess> heap[3],Q;
int main()
{
  llint k[3],t[3];
  int n;
  cin>>k[0]>>k[1]>>k[2]>>t[0]>>t[1]>>t[2]>>n;
  queue<int> qq[3];
  vector<int> all(n);
  for(int i=0;i<n;i++) {
    cin>>all[i];
  }
  sort(all.begin(),all.end());
  for(int i=0;i<n;i++) {
    qq[0].push(i);
    event[i]=all[i];
  }
  llint cur=0,ans=0;
  const llint inf=100000000000000000LL;
  for(;;) {
    llint next=inf;
    for(int i=0;i<3;i++) {
      if(qq[i].size()&&heap[i].size()<k[i]) {
        event[qq[i].front()]=max(event[qq[i].front()],cur);
        next=min(next,event[qq[i].front()]);
      }
      if(heap[i].size()) {
        next=min(next,event[heap[i].getTop()]);
      }
    }
    if(next==inf)break;
    for(int i=0;i<3;i++) {
      if(qq[i].size()&&heap[i].size()<k[i]&&next==event[qq[i].front()]) {
        int v=qq[i].front();qq[i].pop();
        event[v]+=t[i];
        heap[i].pushHeap(v);
      }
      if(heap[i].size()&&next==event[heap[i].getTop()]) {
        int v=heap[i].popHeap();
        if(i==2) {
          ans=max(ans,next-all[v]);
          

        }
        else {
          qq[i+1].push(v);
        }
      }
    }
    

    

    cur=next;
    

  }
  cout<<ans<<endl;
  return 0;
}
