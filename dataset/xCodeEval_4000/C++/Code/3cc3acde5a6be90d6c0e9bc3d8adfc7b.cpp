 #include <bits/stdc++.h>

































 #define int long long
 #define inf  1000000007



 #define pa pair<int,int>
 #define ll long long
 #define PI 3.14159265358979323846
 #define  mp make_pair
 #define  pb push_back
 #define EPS (1e-8)
 
      using namespace std;
                                          
 int dx[8]={0,1,0,-1,1,1,-1,-1};
 int dy[8]={1,0,-1,0,-1,1,1,-1};
                                            
class pa3{
	public:
	int x;
	int y,z;
	pa3(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}
	bool operator < (const pa3 &p) const{
		if(x!=p.x) return x<p.x;
		if(y!=p.y) return y<p.y;
		 return z<p.z;
		

	}
	bool operator > (const pa3 &p) const{
		if(x!=p.x) return x>p.x;
		if(y!=p.y) return y>p.y;
		 return z>p.z;
		

	}
	bool operator == (const pa3 &p) const{
		return x==p.x && y==p.y && z==p.z;
	}
		bool operator != (const pa3 &p) const{
			return !( x==p.x && y==p.y && z==p.z);
	}

};

class pa4{
	public:
	int x;
	int y,z,w;
	pa4(int x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}
	bool operator < (const pa4 &p) const{
		if(x!=p.x) return x<p.x;
		if(y!=p.y) return y<p.y;
		if(z!=p.z)return z<p.z;
		return w<p.w;
		

	}
	bool operator > (const pa4 &p) const{
		if(x!=p.x) return x>p.x;
		if(y!=p.y) return y>p.y;
		if(z!=p.z)return z>p.z;
		return w>p.w;
		

	}
	bool operator == (const pa4 &p) const{
		return x==p.x && y==p.y && z==p.z &&w==p.w;
	}
		

};
class pa2{
	public:
	int x,y;
	pa2(int x=0,int y=0):x(x),y(y) {}
	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
	pa2 operator - (pa2 p) {return pa2(x-p.x,y-p.y);}
	bool operator < (const pa2 &p) const{
		return y != p.y ? y<p.y: x<p.x;
	}
	bool operator > (const pa2 &p) const{
		return x != p.x ? x<p.x: y<p.y;
	}
	bool operator == (const pa2 &p) const{
		return abs(x-p.x)==0 && abs(y-p.y)==0;
	}
	bool operator != (const pa2 &p) const{
		return !(abs(x-p.x)==0 && abs(y-p.y)==0);
	}
		

};



string itos( int i ) {
	ostringstream s ;
	s << i ;
	return s.str() ;
}
 
int Gcd(int v,int b){
	if(v==0) return b;
	if(b==0) return v;
	if(v>b) return Gcd(b,v);
	if(v==b) return b;
	if(b%v==0) return v;
	return Gcd(v,b%v);
}


 int mod;
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
pa operator+(const pa & l,const pa & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
pa operator-(const pa & l,const pa & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}  

ostream& operator<<(ostream& os, const vector<int>& VEC){
	for(auto v:VEC)os<<v<<" ";
    return os;
}

ostream& operator<<(ostream& os, const pa& PAI){
	os<<PAI.first<<" : "<<PAI.second;
    return os;
}

ostream& operator<<(ostream& os, const pa3& PAI){
	os<<PAI.x<<" : "<<PAI.y<<" : "<<PAI.z;
    return os;
}

ostream& operator<<(ostream& os, const pa4& PAI){
	os<<PAI.x<<" : "<<PAI.y<<" : "<<PAI.z<<" : "<<PAI.w;
    return os;
}

ostream& operator<<(ostream& os, const vector<pa>& VEC){
	for(auto v:VEC)os<<v<<" ";
    return os;
}


int beki(int wa,int rr,int warukazu){
	if(rr==0) return 1%warukazu;
	if(rr==1) return wa%warukazu;
	wa%=warukazu;
	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
	ll zx=beki(wa,rr/2,warukazu);
	return (zx*zx)%warukazu;
}

              
int pr[1100000];
int inv[1100000];



int comb(int nn,int rr){
	if(rr<0 || rr>nn || nn<0) return 0;
	int r=pr[nn]*inv[rr];
	r%=mod;
	r*=inv[nn-rr];
	r%=mod;
	return r;
}

void gya(int ert){
	pr[0]=1;
	for(int i=1;i<=ert;i++){
		pr[i]=((ll)pr[i-1]*i)%mod;
	}
		inv[ert]=beki(pr[ert],mod-2,mod);
	for(int i=ert-1;i>=0;i--){
		inv[i]=(ll)inv[i+1]*(i+1)%mod;
	}
}


                


                
              

    		

    			

                 

 

  

  
  
struct Segmax{
	

	

	

	
	
	private:
	public:
	
	

	

	

	

	
	int cor=(1<<19);
	
	vector<pa> vec;
	
	void shoki1(){
		vec.resize(2*cor+3, mp(-1,0));
		for(int i=cor;i<2*cor;i++)vec[i].second=i-cor;
	}
	
	void shoki2(){
		for(int i=cor-1;i>0;i--) {
			if(vec[2*i].first>=vec[2*i+1].first) vec[i]=vec[2*i];
			else vec[i]=vec[2*i+1];
		}
	}
		
	void updadd(int x,int w){
		

		x+=cor;
		vec[x].first+=w;
		x/=2;
		while(x){
			if(vec[2*x].first>=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
			x/=2;
		}
	}
	
	void updchan(int x,int w){
		

		x+=cor;
		vec[x].first=w;
		x/=2;
		while(x){
			if(vec[2*x].first>=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
			x/=2;
		}
	}
	
	
	

	

	

	pa segmax(int a,int b){
		a+=cor;
		b+=cor;
		pa ans=mp(1-(1ll<<31),-1);
		while(a<b){
			if(a&1){
				if(ans.first!=vec[a].first)ans=max(ans,vec[a]);
				else ans.second=min(ans.second,vec[a].second);
				a++;
			}
			if(b&1){
				b--;
				if(ans.first!=vec[b].first)ans=max(ans,vec[b]);
				else ans.second=min(ans.second,vec[b].second);
			}
			a/=2;
			b/=2;
		}
		return ans;
		
	}
	
	

	

	int lower_bound(int p,int x){
		p+=cor;
		while(1){
			while(!(p&1))p/=2;
			if(vec[p].first>=x)break;

			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			if(vec[p].first<x){

				p++;
			}
		}
	}

	
};


int cont=0;
int sz[300020];
int in[300020];


int nxt[300020];




void dfs_sz(int v,vector<int> *GG){
    sz[v]=1;
    for(auto &u :GG[v]){
        dfs_sz(u,GG);
        sz[v]+=sz[u];
        if(sz[u]>sz[GG[v][0]])swap(u,GG[v][0]);
    }
}
void dfs_hld(int v,vector<int> *GG){
    if(v==1) nxt[v]=1;
    in[v]=cont;
    cont++;
  

    for(auto u:GG[v]){
        if(u==GG[v][0])nxt[u]=nxt[v];
        else nxt[u]=u;
        dfs_hld(u,GG);
    }
   

}

void make_hl(int N,vector<int> *GG){

	dfs_sz(0,GG);
	dfs_hld(0,GG);
	
}

  vector<int> G[300030];
  
  int par[300030];
  Segmax seg;
  
struct aho{
	
	

	

	

	
	
	
	typedef struct trie{
		int moji;
		int id;
		int depth;
		int P;

		trie* parent;
		trie* flink;
		trie* outer;
		trie* child[26];
	}trie;
    private:
    public:
	
	int cd=0;
	trie* new_trie(){
		trie *p = new trie;
		p->P=-1;
		p->id=cd;
		cd++;
		p->flink=NULL;
		p->parent=NULL;
		p->outer=NULL;
		for(int i=0;i<26;i++) p->child[i]=NULL;
		return p;
	}
	
	trie* ROOT;
	
	aho(){
		ROOT=new_trie();
		ROOT->moji=-1;
		ROOT->depth=0;
	}
	
	int add_string(string str, int str_id){
		int it=0;
		trie* trie_now=ROOT;
		int l=str.length();
		for(int i=0;i<l;i++){
			int tugi=str[i]-'a';  

			if(trie_now->child[tugi]==NULL){
				trie* p_new=new_trie();
				p_new->moji= tugi;
				p_new->parent=trie_now;
				p_new->depth=i+1;
				trie_now->child[tugi]=p_new;
			}
			trie_now=trie_now->child[tugi];
			
		}
		trie_now->P=str_id;
		return trie_now->id;
	}
	
	void debug(){
		debug_dfs(ROOT);
	}
	void debug_dfs(trie* e){




		cout<<"c " ;
		for(int i=0;i<26;i++)if(e->child[i]!=NULL) cout<<i<<" ";
		cout<<endl;
		for(int i=0;i<26;i++)if(e->child[i]!=NULL) debug_dfs(e->child[i]);
		
	}
	
	queue<trie*> queue_trie;
	void shori(){
		ROOT->parent=ROOT;
		ROOT->flink=ROOT;
		queue_trie.push(ROOT);
		while(queue_trie.size()){
			trie* trie_now=queue_trie.front();
			queue_trie.pop();
		
			for(int i=0;i<26;i++)if(trie_now->child[i]!=NULL) queue_trie.push(trie_now->child[i]);
			if(trie_now==ROOT) continue;
			if(trie_now->parent==ROOT){
				trie_now->flink=ROOT;
				continue;
			}
			trie* itr=(trie_now->parent)->flink;
			while(1){
				if(itr==ROOT){
					if(ROOT->child[trie_now->moji] ==NULL){
						trie_now->flink=ROOT;
						break;
					}
					else{
						trie_now->flink=ROOT->child[trie_now->moji];
						break;
					}
				}
				else{
					if(itr->child[trie_now->moji] !=NULL){
						trie_now->flink=itr->child[trie_now->moji];
						break;
					}
					else itr=itr->flink;	
				}
			}
		
		}
		
		while(queue_trie.size())queue_trie.pop();
		queue_trie.push(ROOT);
			
		while(queue_trie.size()){
			trie* trie_now=queue_trie.front();
			queue_trie.pop();
			
			for(int i=0;i<26;i++)if(trie_now->child[i]!=NULL)queue_trie.push(trie_now->child[i]);
			if(trie_now==ROOT) continue;
			if(trie_now->flink->P<0) trie_now->outer=trie_now->flink->outer;
			else{
				trie_now->outer=trie_now->flink;
			}
			if(trie_now->outer==NULL)trie_now->outer=ROOT;
	

			
			G[trie_now->outer->id].pb(trie_now->id);
			par[trie_now->id]=trie_now->outer->id;
		}
	
	}



	int string_find(string str){
		
		trie* trie_now=ROOT;
		int l=str.length();
		int ans=-1;
		for(int i=0;i<l;i++){
			int moji=str[i]-'a'; 

			
			while(trie_now->child[moji]==NULL){
				trie_now=trie_now->flink;
				
				if(trie_now==ROOT) break;
			}
		
			if(trie_now->child[moji]!=NULL){
				trie_now=trie_now->child[moji];
			}
			
			ans=max(ans,YARU(trie_now->id));
			
			
			
			
			int sute=i-trie_now->depth-1;
			

			

			
		}
		return ans;
	}

	int YARU(int id){


		int ans=-1;
		while(1){
			int ue=nxt[id];


			ans=max(ans,seg.segmax(in[ue],in[id]+1).first);
	

			if(ue==0)break;
			id=par[ue];
		}
		return ans;
	}

};

multiset<int> ms[300030];
int e[300030],po[300030]={};
string S[300030];

int doko[300030];
void solve(){
	aho ss;
	int n,q;
	cin>>n>>q;
	set<string> se;
	for(int i=0;i<n;i++){
		cin>>S[i];
		

		se.insert(S[i]);
		
	}
	int cnt=1;
	map<string,int>ma;
	for(auto i:se){
		ma[i]=cnt;
		int g=ss.add_string(i,cnt);
		e[cnt]=g;
		cnt++;
	}
	for(int i=0;i<n;i++)doko[i]=ma[S[i]];
	ss.shori();
	make_hl(ss.cd,G);
	for(int i=0;i<n;i++){
		ms[ma[S[i]]].insert(0);
	}
	seg.shoki1();
	
	for(int i=1;i<cnt;i++){


		seg.vec[seg.cor+in[e[i]]].first=0;
	}
	seg.shoki2();
	
	
	for(int rt=0;rt<q;rt++){
		int y;
		cin>>y;
		if(y==1){
			int a,b;
			cin>>a>>b;
			a--;
			int mae=po[a];
			int id=doko[a];
			ms[id].erase(ms[id].find(mae));
			ms[id].insert(b);
			
			int nm=*ms[id].rbegin();
			po[a]=b;
			
			seg.updchan(in[e[id]],nm);
		}
		else{
			string s;
			cin>>s;
			cout<<ss.string_find(s)<<"\n";
		}
	}
}

signed main(){
	mod=inf;
	cin.tie(0);
	ios::sync_with_stdio(false);
int n=1;



	
	

	for(int i=0;i<n;i++)solve();
	
	return 0;
 }
 