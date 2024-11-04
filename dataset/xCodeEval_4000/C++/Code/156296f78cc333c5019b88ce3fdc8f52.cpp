
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cmath>
#include<map>
#include<queue>
#include<unordered_map>
#include<vector>
#include<stack> 
#define ll long long
#define ul unsigned long long
#define pb push_back
#define iter unordered_map<ll,int> :: iterator

using namespace std;

namespace READ_AND_WRITE{
	inline int read(){
		char ch=getchar(); int x=0,f=1;
		for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
		for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
		return x*f;
	}
	
	void W(int x){ if(x>=10) W(x/10); putchar('0'+x%10);}
	void W(ll x){ if(x>=10) W(x/10); putchar('0'+x%10);}
	
	inline ll READ(){
		char ch=getchar(); ll x=0,f=1;
		for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
		for(;isdigit(ch);ch=getchar()) x=x*(ll)10+ch-'0';
		return x*f;
	}
	
	inline void get_num(int *a,int Begin,int End){
		for(int i=Begin;i<=End;i++) a[i]=read();
	}
	
	inline void put_num(int *a,int Begin,int End){
		for(int i=Begin;i<=End;i++) W(a[i]),putchar(' ');
		puts("");	
	}
	
	template<class T>
	inline void print(vector<T> &o){
		for(T i:o) W(i),puts("");
		puts("");
	}
}
using namespace READ_AND_WRITE;

namespace ALGORITHM{
	template<class T,class H>
	inline T Divide(T L,T R,H f){
		T ans,mid;
		for(;L<=R;){
			mid=(L+R)/2;
			if(f(mid)) ans=mid,L=mid+1;
			else R=mid-1;
		}
		return ans;
	}
	
	template<class T>
	inline bool bigger(T a,T b){
		return a>b;
	}
	template<class T>
	inline bool smaller(T a,T b){
		return a<b;
	}
	template<class T>
	inline bool not_smaller(T a,T b){
		return !smaller(a,b);
	}
	template<class T>
	inline bool not_bigger(T a,T b){
		return !bigger(a,b);
	}	
	
	
}
using namespace ALGORITHM;

namespace Number{
	const double eps=1e-6;
	const int ha1=998244353,ha2=1e9+7,ha3=1e9+9;
	const int ha=ha3,inv2=ha/2+1,lss=60;
    int UUU,VVV,ddd;
    ll uuu,vvv,DDD;
    
	inline bool is_zero(double x){
	    return x>=-eps&&x<=eps;
    }
    
    int gcd(int x,int y){ return !y?x:gcd(y,x%y);}
    ll gcd(ll x,ll y){ return !y?x:gcd(y,x%y);}
    
    void gcd(int a,int b,int &d,int &x,int &y){
    	if(!b){ x=1,y=0,d=a; return;}
    	gcd(b,a%b,d,y,x),y-=x*(a/b);
	}
    
    void gcd(ll a,ll b,ll &d,ll &x,ll &y){
    	if(!b){ x=1,y=0,d=a; return;}
    	gcd(b,a%b,d,y,x),y-=x*(a/b);
	}
    
    int lcm(int x,int y){ return x/gcd(x,y)*y;}
    ll lcm(ll x,ll y){ return x/gcd(x,y)*y;}
    
    inline int add(int x,int y){ x+=y; return x>=ha?x-ha:x;}
    inline void ADD(int &x,int y){ x+=y; if(x>=ha) x-=ha;}
    inline int add(int x,int y,const int &HA){ x+=y; return x>=HA?x-HA:x;}
    inline void ADD(int &x,int y,const int &HA){ x+=y; if(x>=HA) x-=HA;}
    
    inline int add(int x,int y,const ll &HA){ x+=y; return x>=HA?x-HA:x;}
    inline void ADD(int &x,int y,const ll &HA){ x+=y; if(x>=HA) x-=HA;}
    
    inline ll add(ll x,ll y,const ll &HA){ x+=y; return x>=HA?x-HA:x;}
    inline void ADD(ll &x,ll y,const ll &HA){ x+=y; if(x>=HA) x-=HA;}

    inline int dec(int x,int y){ return add(x,ha-y);}
    inline void DEC(int &x,int y){ ADD(x,ha-y);}
    inline int dec(int x,int y,const int &HA){ return add(x,HA-y,HA);}
    inline void DEC(int &x,int y,const int &HA){ ADD(x,HA-y,HA);}
    
    inline int dec(int x,int y,const ll &HA){ return add(x,(int)HA-y,HA);}
    inline void DEC(int &x,int y,const ll &HA){ ADD(x,(int)HA-y,HA);}
    
    inline ll dec(ll x,ll y,const ll &HA){ return add(x,HA-y,HA);}
    inline void DEC(ll &x,ll y,const ll &HA){ ADD(x,HA-y,HA);}
    
    inline int mul(int x,int y){ return x*(ll)y%ha;}
    inline void MUL(int &x,int y){ x=mul(x,y);}
    inline int mul(int x,int y,const int &HA){ return x*(ll)y%HA;}
    inline void MUL(int &x,int y,const int &HA){ x=mul(x,y,HA);}

    inline int mul(int x,int y,const ll &HA){ return x*(ll)y%HA;}
    inline void MUL(int &x,int y,const ll &HA){ x=mul(x,y,HA);}
    
    inline ll mul(ll x,ll y,const ll &HA){
        ll an=0;
        for(;y;y>>=1,ADD(x,x,HA)) if(y&1) ADD(an,x,HA);
        return an;   	
	}
	inline void MUL(ll &x,ll y,const ll &HA){ x=mul(x,y,HA);}
    
    inline int div2(int x){ return x*(ll)inv2%ha;}
    
    inline int qz(int x){ return div2(mul(x,x+1));}

    inline int ksm(int x,int y){
        int an=1;
        for(;y;y>>=1,MUL(x,x)) if(y&1) MUL(an,x);
        return an;
    }
    inline int ksm(int x,int y,const int &HA){
        int an=1;
        for(;y;y>>=1,MUL(x,x,HA)) if(y&1) MUL(an,x,HA);
        return an;    	
	}
	inline ll ksm(ll x,ll y,const ll &HA){	
        ll an=1;
        for(;y;y>>=1,MUL(x,x,HA)) if(y&1) MUL(an,x,HA);
        return an;		
	}
	
	inline int get_inv(int x){ return ksm(x,ha-2);}


	
	inline int get_inv(int x,int y){
		gcd(x,y,ddd,UUU,VVV);
		if(ddd>1) return -1;
		return UUU<0?UUU+y:UUU;
	}
	
	inline ll get_inv(ll x,ll y){
		gcd(x,y,DDD,uuu,vvv);
		if(DDD>1) return -1;
		return uuu<0?uuu+y:uuu;
	}		
	


    



    
    class linear_set{
    public:
	    ul a[lss+9];
	    ul p[lss+9];
	    int num;
		
		linear_set(){ num=0,memset(a,0,sizeof(a));}
		inline void clear(){ num=0,memset(a,0,sizeof(a));}
		inline void Ins(ul x){
			num=0;
			for(int i=lss;i>=0;x^=((x>>i)&1)?a[i]:0,i--) if(((x>>i)&1)&&!a[i]){ a[i]=x; return;}
		}	
		linear_set(int Len,ul *b){ for(int i=1;i<=Len;i++) Ins(b[i]);}
		linear_set(const linear_set &u){ memcpy(a,u.a,sizeof(u.a)),memcpy(p,u.p,sizeof(u.p)),num=u.num;}
		
		inline void Orthogonalization(){
			for(int i=1;i<=lss;i++) if(a[i])
			    for(int j=i-1;j>=0;j--) if(a[j]&&((a[i]>>j)&1)) a[i]^=a[j];
			
			num=0;
			
		    for(int i=0;i<=lss;i++) if(a[i]) p[num++]=a[i];
		}

		friend ostream& operator <<(ostream &o,linear_set &u){
			if(!u.num) u.Orthogonalization();
			W(u.num),puts("");
			
			for(int i=0;i<u.num;i++) printf("%llu ",u.p[i]);
			puts("");
			
			return o;
		}
		
		linear_set operator +(const linear_set &u)const{
			linear_set r=*this;
			for(int i=lss;i>=0;i--) if(u.a[i]) r.Ins(u.a[i]);
			r.Orthogonalization();
			return r;
		}
		
		void operator +=(const linear_set &u){
			for(int i=lss;i>=0;i--) if(u.a[i]) Ins(u.a[i]);
			Orthogonalization();
		}
		
		ul operator ()(ul value){
			if(!num) Orthogonalization();
			ul ans=0,now=0;
			for(int i=num-1;i>=0;i--)
				if((now^p[i])>=value) ans+=((ul)1<<i);
				else now^=p[i];
			if(!value) ans++;
			return ans;
		}
		
		ul operator [](ul rank){
			if(!num) Orthogonalization();
			ul ans=0; rank=((ul)1<<num)-rank;
			for(int i=0;i<num;i++) if(((ul)1<<(ul)i)&rank) ans^=p[i];
			return ans;
		}
		
		inline ul size(){
			if(!num) Orthogonalization();
			return (ul)1<<num;
		}
	};
	
class matrix{
public:
    int a[105][105],n;
     
    inline void clear(){ memset(a,0,sizeof(a));}
    inline void Base(){ clear(); for(int i=1;i<=n;i++) a[i][i]=1;}
    
    matrix(){ n=0,clear();}
    matrix(const int &u){ n=u,clear();}
    matrix(const int &u,int *b) : n(u){
    	for(int i=2;i<=u;i++) a[i][i-1]=1;
    	for(int i=1;i<=u;i++) a[u-i+1][u]=b[i];
	}
    matrix(const matrix &u){
    	n=u.n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) a[i][j]=u.a[i][j];
	}
	
     
    inline void input(){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
    }
    inline void output(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
            puts("");
        }
    }
     
    inline void swap(int x,int y){
        for(int i=1;i<=n;i++) swap(a[x][i],a[y][i]);
    }
    inline void add(int from,int tmp,int to){
        for(int i=1;i<=n;i++) ADD(a[to][i],a[from][i]*(ll)tmp%ha);
    }
    inline void mul(int x,int ml){
        for(int i=1;i<=n;i++) a[x][i]=a[x][i]*(ll)ml%ha;
    }
     
    inline int Determinant(){
        int an=1;
        matrix b=*this;
         
        for(int i=1,o,inv;i<=n;i++){
            for(o=i;o<=n;o++) if(b.a[o][i]) break;
            if(o>n) return 0;
            if(o>i){ an=ha-an; b.swap(o,i);}
             
            inv=get_inv(b.a[i][i]);
            for(int j=i+1,tmp;j<=n;j++) if(b.a[j][i])
                tmp=ha-inv*(ll)b.a[j][i]%ha,b.add(i,tmp,j);
             
            an=an*(ll)b.a[i][i]%ha;
        }
         
        return an;
    }
     
    inline matrix ni(){
        matrix b; b.n=n,b.Base();
         
        if(!Determinant()) b.clear();
        else{  
            for(int i=1,o,inv;i<=n;i++){
                for(o=i;o<=n;o++) if(a[o][i]) break;
                if(o>i) swap(o,i),b.swap(o,i);
                 
                inv=get_inv(a[i][i]),mul(i,inv),b.mul(i,inv);
                 
                for(int j=i+1,tmp;j<=n;j++) if(a[j][i])
                    tmp=ha-a[j][i],add(i,tmp,j),b.add(i,tmp,j);
            }
             
            for(int i=n-1;i;i--)
                for(int j=i+1;j<=n;j++) if(a[i][j]) b.add(j,ha-a[i][j],i),add(j,ha-a[i][j],i);
        }
         
        return b;
    }
     
    matrix operator +(const matrix &u){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) ADD(a[i][j],u.a[i][j]);
        return *this;
    }
     
    matrix operator -(const matrix &u){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) ADD(a[i][j],ha-u.a[i][j]);
        return *this;
    }
     
    matrix operator *(const matrix &u)const{
        matrix r; r.clear(),r.n=n;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) ADD(r.a[i][j],a[i][k]*(ll)u.a[k][j]%ha);
        return r;
    }
     
    matrix operator /(matrix &u)const{
        return *this*u.ni();
    }
    
    void operator -=(const matrix &u){ *this=*this-u;} 
    void operator +=(const matrix &u){ *this=*this+u;}     
    void operator *=(const matrix &u){ *this=*this*u;} 
    void operator /=(matrix &u){ *this=*this/u;}     
    
    matrix operator ^(int u)const{
    	matrix r(n),now=*this; r.Base();
        for(;u;u>>=1,now*=now) if(u&1) r*=now;
        return r;
	}
};
    
    inline int nopt(int x,int y){
    	return max(x,y);
	}
    
    template<class T,class P>
	inline T summ(T *a,P Begin,P End){
		T an=0;
		for(P i=Begin;i<=End;i++) ADD(an,a[i]);
		return an;
	}
}
using namespace Number;

class Point{
public:
	int x,dis;
	bool operator <(const Point &u)const{
		return dis>u.dis;
	}
	

};

class graph{
public:
	int n,*hd,*ne,*to,*val,num;
	bool is_directed,is_weighted;
	
	inline void addl(int x,int y,int z=1){
		to[++num]=y,ne[num]=hd[x],hd[x]=num,val[num]=z;
		if(!is_directed) to[++num]=x,ne[num]=hd[y],hd[y]=num,val[num]=z;
	}
	
	graph(int nl=0,int ml=0,bool IS_D=0,bool IS_W=0) : num(0),n(nl),is_directed(IS_D),is_weighted(IS_W){
		hd=new int[n+3];
		ne=new int[ml?(is_directed?ml+3:2*ml+3):2000005];
		to=new int[ml?(is_directed?ml+3:2*ml+3):2000005];
		val=new int[ml?(is_directed?ml+3:2*ml+3):2000005];
		
		memset(hd,0,sizeof(int)*(n+3));
		
		if(ml) for(int uu,vv,ww;ml--;) uu=read(),vv=read(),ww=is_weighted?read():1,addl(uu,vv,ww);
		else{
		

			 
		}
	}
	
	~graph(){
		delete hd;
		delete ne;
		delete to;
		if(is_weighted) delete val;
	}
	
	inline void dij(int *d,const int S=1){
		bool v[n+1]; priority_queue<Point> q;
		memset(v,0,sizeof(v)),q.push((Point){S,0});
		memset(d,0x3f,sizeof(int)*(n+1)),d[S]=0;
		
		for(Point y;!q.empty();){
			y=q.top(),q.pop();
			if(v[y.x]) continue;
			v[y.x]=1;
			
			for(int i=hd[y.x];i;i=ne[i]) if(d[y.x]+val[i]<d[to[i]]){
				d[to[i]]=d[y.x]+val[i];
				q.push((Point){to[i],d[to[i]]});
			}
		}
	}
	
	inline void spfa(int *d,const int S=1){
		bool v[n+1]; queue<int> q; q.push(S);
		memset(v,0,sizeof(v)),memset(d,0x3f,sizeof(int)*(n+1));
		d[S]=0,v[S]=1;
		
		for(int y;!q.empty();q.pop(),v[y]=0){
			y=q.front();
			for(int i=hd[y];i;i=ne[i]) if(d[y]+val[i]<d[to[i]]){
				d[to[i]]=d[y]+val[i];
				if(!v[to[i]]) v[to[i]]=1,q.push(to[i]);
			}
		}
	}
	
	inline void topsort(int *ans){
		

		if(!is_directed){ printf("Please have some B_TREEs in ur heart"); return;}
		int d[n+1]; memset(d,0,sizeof(d));
		for(int i=1;i<=num;i++) d[to[i]]++;
		
		queue<int> q; int cnt=0;
		for(int i=1;i<=n;i++) if(!d[i]) q.push(i);
		
		for(int x;!q.empty();q.pop()){
			x=q.front(),ans[++cnt]=x;
			
			for(int i=hd[x];i;i=ne[i]){
				d[to[i]]--;
				if(!d[to[i]]) q.push(to[i]);
			}
		} 
		
		if(cnt<n){ printf("Please have some B_TREEs in ur heart"),memset(ans,0,sizeof(int)*(n+1)); return;}
	}
};

class tree : public graph{
public:
	int *siz,*dep,*son,root,*node_value,*ans_pos;
	
	inline void clear(){
		memset(siz,0,sizeof(int)*(n+1));
		memset(dep,0,sizeof(int)*(n+1));
		memset(son,0,sizeof(int)*(n+1));		
	}
	
    tree(int nl=0,bool IS_W=0,bool is_input=1,int rot=1,int *Value=NULL,int *ANS=NULL) : root(rot),graph(nl,is_input?nl-1:0,0,IS_W){
    	siz=new int[n+3];
    	dep=new int[n+3];
    	son=new int[n+3];
    	
    	node_value=Value;
    	if(node_value!=NULL) memset(node_value,0,sizeof(int)*(n+1));
    	ans_pos=ANS;
      	if(ans_pos!=NULL) memset(ans_pos,0,sizeof(int)*(n+1));  	
    	
    	clear();
	}
	
	~tree(){
		delete siz;
		delete dep;
		delete son;
	}
	
	void tree_dfs(int x,int fa){
		siz[x]=1,ans_pos[x]=max(ans_pos[x],ans_pos[fa]+node_value[x]);
		
		for(int i=hd[x];i;i=ne[i]) if(to[i]!=fa){
			dep[to[i]]=dep[x]+1,tree_dfs(to[i],x),siz[x]+=siz[to[i]];
			if(siz[son[x]]<siz[to[i]]) son[x]=to[i];
		}
	}
}; 

class tarjan : public graph{
public:
	int *dfn,*low,dc,SCC_num,node_cnt,edge_num;
	bool *is_cut,*is_ban;
	stack<int> SCC_st;
	stack< pair<int,int> > node_s;
	vector< vector<int> > node_bl;
	unordered_map<ll,int> mmp;
	
	inline void clear(){
		memset(dfn,0,sizeof(int)*(n+1)),dc=0,SCC_num=0,mmp.clear();	
    	while(node_s.size()) node_s.pop(),node_bl.clear();	
		memset(is_cut,0,sizeof(bool)*(n+1)),node_cnt=edge_num=0;	
		memset(is_ban,0,sizeof(bool)*(num+1));	
	}
	
	tarjan(int nl=0,int ml=0,bool IS_D=0) : graph(nl,ml,IS_D,0){
		dfn=new int[n+3];
		low=new int[n+3];
		is_cut=new bool[n+3]; 
		is_ban=new bool[ml?ml*2+3:2000005];
		clear();
	}
	
	~tarjan(){	
		delete dfn;
		delete low;
		delete is_cut;
		delete is_ban;
	}
	
	void SCC_dfs(int x,int *lt){
		dfn[x]=low[x]=++dc,SCC_st.push(x);
		for(int i=hd[x];i;i=ne[i]) 
		    if(!dfn[to[i]]) SCC_dfs(to[i],lt),low[x]=min(low[x],low[to[i]]);
		    else if(!lt[to[i]]) low[x]=min(low[x],dfn[to[i]]);
		
		if(low[x]==dfn[x]) for(SCC_num++;;){
			int now=SCC_st.top(); 
			SCC_st.pop(),lt[now]=SCC_num;
			if(now==x) break; 
		}
	}
	
	inline graph SCC(int *lt){ 
	    memset(lt,0,sizeof(int)*(n+1)),clear();
		for(int i=1;i<=n;i++) if(!dfn[i]) SCC_dfs(i,lt);
		
		graph b(SCC_num,0,1,0);
		
		for(int i=1;i<=n;i++)
		    for(int j=hd[i];j;j=ne[j]) if(lt[to[j]]!=lt[i]){
		    	ll now=i*(ll)(n+1)+j;
		    	if(!mmp.count(now)) mmp[now]=1,b.addl(lt[i],lt[to[j]]);
			}
		
		return b;
	}
	
	void node_dfs(int x,int fa){
        low[x]=dfn[x]=++dc; pair<int,int> e;
        
        for(int i=hd[x];i;i=ne[i]) if(to[i]!=fa){
            e=make_pair(x,to[i]);
            if(!dfn[to[i]]){
                node_s.push(e),node_dfs(to[i],x),low[x]=min(low[x],low[to[i]]);
                  
                if(low[to[i]]>=dfn[x]){
				    vector<int> gg;
					for(++node_cnt;;){
                        e=node_s.top(),node_s.pop();
                        
						ll now=node_cnt*(ll)(n+1)+e.first;
                        if(!mmp.count(now)) gg.pb(e.first),mmp[now]=1;
                        now=node_cnt*(ll)(n+1)+e.second;
                        if(!mmp.count(now)) gg.pb(e.second),mmp[now]=1;
                        
                        if(e.first==x&&e.second==to[i]) break;
                    }
                    node_bl.pb(gg);
                    
                    
				}
            }
            else if(dfn[to[i]]<low[x]) low[x]=dfn[to[i]],node_s.push(e);
        }
    }
    
    inline vector< vector<int> > node_db(){
        clear();
    	
    	for(int i=1;i<=n;i++) if(!dfn[i]) node_dfs(i,0);
    	
    	int cnt[n+3]; memset(cnt,0,sizeof(cnt));
    	for(vector<int> o:node_bl)
    	    for(int i:o) cnt[i]++;
    	for(int i=1;i<=n;i++) is_cut[i]=cnt[i]>1;
    	
    	return node_bl;
	}

    void edge_dfs(int x,int fa){
        dfn[x]=low[x]=++dc;
         
        for(int i=hd[x];i;i=ne[i]) if(to[i]!=fa)
            if(!dfn[to[i]]){
                edge_dfs(to[i],x),low[x]=min(low[x],low[to[i]]);
                if(low[to[i]]>=dfn[to[i]]) is_ban[i]=is_ban[((i-1)^1)+1]=1;
            }
            else low[x]=min(low[x],dfn[to[i]]);
    }
	
	void B(int x,int *lt){
		lt[x]=edge_num;
		for(int i=hd[x];i;i=ne[i]) if(!is_ban[i]&&!lt[to[i]]) B(to[i],lt);
	}
	
	inline tree edge_db(int *lt){
		clear(),memset(lt,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++) if(!dfn[i]) edge_dfs(i,0);
		for(int i=1;i<=n;i++) if(!lt[i]) edge_num++,B(i,lt);
		
		tree b(edge_num,0,0);
		
		for(int i=1;i<=n;i++)
		    for(int j=hd[i];j;j=ne[j]) if((j&1)&&is_ban[j]) b.addl(lt[i],lt[to[j]]);
		    
		return b;
	}
	
	
};

class two_sat : public graph{
public:
	bool *mark;
	vector<int> P;
	
	two_sat(int nl=0,int ml=0) : graph(nl,0,1,0){
		mark=new bool[n+3];
		memset(mark,0,sizeof(bool)*(n+1));
		
		for(int x,y,a,b;ml--;) 
		    x=(read()-1)<<1,a=read(),y=(read()-1)<<1,b=read(),addl(x+(a^1),y+b),addl(y+(b^1),x+a);
	}
	
	~two_sat(){	
		delete mark;
	}	
	
    bool dfs(int x){
    	if(mark[x^1]) return 0;
    	if(mark[x]) return 1;
    	mark[x]=1,P.pb(x);
    	for(int i=hd[x];i;i=ne[i]) if(!dfs(to[i])) return 0;
    	return 1;
    }
	
	inline void solve(){
		bool A=1;
		
    	for(int i=0;i<n;i+=2) if(!mark[i]&&!mark[i|1]){
     		P.clear();
    	    if(!dfs(i)){
                for(int j:P) mark[j]=0;
                P.clear();
                if(!dfs(i|1)){ A=0; break;}
	        }
	    }
	    
	    if(A){
	    	puts("POSSIBLE");
	    	for(int i=0;i<n;i+=2) printf("%d ",mark[i]?0:1);
		}
		else puts("IMPOSSIBLE");
	}
};

class lines{
public:
	int from,to,flow,cap;
	
};

class my_flow{
public:
	lines l[200005];
	vector<int> g[10005];
	
	int n,*d,*cur,S,T,num;
	bool *v;
	
	inline void addl(int x,int y,int z){
		l[++num]=(lines){x,y,0,z},g[x].pb(num);
		l[++num]=(lines){y,x,0,0},g[y].pb(num);		
	}
	
	inline void build(){


    
	}
	
	my_flow(int nl=0) : n(nl),num(-1){
		d=new int[n+3];
		cur=new int[n+3];
		v=new bool[n+3];
		build();
	}
	
	~my_flow(){
		delete d;
		delete cur;
		delete v;
	}
	
	bool BFS(){
		memset(v,0,sizeof(bool)*(n+1)),v[S]=1;
		d[S]=0; queue<int> q; q.push(S);
		
		for(int x;!q.empty();){
			x=q.front(),q.pop();
			for(int u:g[x]){
				lines &e=l[u];
				if(e.flow<e.cap&&!v[e.to]) d[e.to]=d[x]+1,v[e.to]=1,q.push(e.to);
			}
		}
		
		return v[T];
	}
	
	int dfs(int x,int A){
		if(x==T||!A) return A;
		int flow=0,f,sz=g[x].size();
		for(int &i=cur[x];i<sz;i++){
			lines &e=l[g[x][i]];
			if(d[x]==d[e.to]-1&&(f=dfs(e.to,min(A,e.cap-e.flow)))){
				flow+=f,A-=f;
			    e.flow+=f,l[g[x][i]^1].flow-=f;
			    if(!A) break;
			}
		}
		
		return flow;
	}
	
	inline int max_flow(){
		int an=0;
		while(BFS()){	
			memset(cur,0,sizeof(int)*(n+1));
			an+=dfs(S,1<<30);
		}
		return an;
	}
};

ll wl[200005],MX,mx[200005],ans=0; 
int siz_num[200005],SS,ttt[200005];

void DFS(int x,int fa,tree &it){
	ttt[x]=siz_num[x]>1;
	
	for(int i=it.hd[x];i;i=it.ne[i]) if(it.to[i]!=fa)
	    DFS(it.to[i],x,it),mx[x]=max(mx[x],mx[it.to[i]]),ttt[x]+=ttt[it.to[i]];
	mx[x]+=wl[x];
	
	if(ttt[x]) ans+=wl[x];
	else MX=max(MX,mx[x]);
}

int main(){
	int n=read(),m=read(),lt[n+3],W[n+3];
	get_num(W,1,n);
	
	tarjan a(n,m,0);
	int S=read();
	tree b=a.edge_db(lt);
	for(int i=1;i<=n;i++) wl[lt[i]]+=(ll)W[i],siz_num[lt[i]]++;
	
	DFS(lt[S],0,b);
	cout<<ans+MX<<endl;
	
	return 0;
}