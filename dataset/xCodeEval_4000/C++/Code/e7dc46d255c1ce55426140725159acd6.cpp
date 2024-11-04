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


                


                
              

    		

    			

                 

 

  


struct seg_rangeadd_getsum{
	

	

	

	
	
	private:
	public:
	
	

	

	

	

	
	int cor=(1<<17);
	
	vector<int> vec;
	vector<int> lazy;
	void shoki1(){
		vec.resize(2*cor+3, 0);
		lazy.resize(2*cor+3, 0);
	}
	void shoki2(){
		for(int i=cor-1;i>0;i--) vec[i]=vec[2*i]+vec[2*i+1];
	}
		
	int chien(int k,int len){
		if(lazy[k]==0) return vec[k];
		if(k<cor){
			lazy[k*2]+=lazy[k];
			lazy[k*2+1]+=lazy[k];
		}
		vec[k]+=lazy[k]*len;
		lazy[k]=0;
		return vec[k];
	}

	void  clear_chien(int r){
		

		if(r==0)return;
		int f=31-__builtin_clz(r);
		int pos=0;
		int len=cor;
		for(int i=f;i>=0;i--){
			pos*=2;
			pos+=!!(r&(1<<i));
			chien(pos,len);
			len/=2;
		}
		
	}
	void rangeadd(int a,int b,int w){
		a+=cor,b+=cor;
		int aa=a/(a&(-a))/2;
		int bb=b/(b&(-b))/2;
		int lenaa=2*(a&-a);
		int lenbb=2*(b&-b);




		while(a<b){
			if(a&1){
				lazy[a]+=w;
				a++;
			}
			if(b&1){
				b--;
				lazy[b]+=w;
			}
			a/=2,b/=2;
		}

		while(aa>0 || bb>0){
			if(aa>bb){
				vec[aa]=chien(2*aa,lenaa/2)+chien(2*aa+1,lenaa/2);
				aa/=2;		
				lenaa*=2;
			}
			else if(aa<bb){
				vec[bb]=chien(2*bb,lenbb/2)+chien(2*bb+1,lenbb/2);
				bb/=2;	
				lenbb*=2;
			}
			else{
				vec[aa]=chien(2*aa,lenaa/2)+chien(2*aa+1,lenaa/2);
				aa/=2;		
				lenaa*=2;
				bb=aa,lenbb=aa;
			}
		}

	}

	int getsum(int a,int b){
		a+=cor,b+=cor;
		int aa=a/(a&(-a))/2;
		int bb=b/(b&(-b))/2;
		clear_chien(aa);
		clear_chien(bb);
	
		int ans=0;
		
		int len=1;
		while(a<b){
			if(a&1){
				ans+=chien(a,len);
				a++;
			}
			if(b&1){
				b--;
				ans+=chien(b,len);
			}
			a/=2,b/=2,len*=2;
		}
		return ans;
	}
	
	

	int lower_bound(int p,int x){
		p+=cor;
		int ima=0;
		bool fst=1;
		int len=1;
		while(1){
			while(!(p&1))p/=2,len*=2;
			if(fst)fst=0,clear_chien(p/2);
			if(ima+chien(p,len)>=x)break;

			ima=ima+vec[p];
			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			len/=2;
			if(ima+chien(p,len)<x){

				ima+=vec[p];
				p++;
			}
		}
	}
	
		

	int upper_bound(int p,int x){
		p+=cor;
		int ima=0;
		bool fst=1;
		int len=1;
		while(1){
			while(!(p&1))p/=2,len*=2;
			if(fst)fst=0,clear_chien(p/2);
			if(ima+chien(p,len)>x)break;

			ima=ima+vec[p];
			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			len/=2;
			if(ima+chien(p,len)<=x){

				ima+=vec[p];
				p++;
			}
		}
	}
	
};

struct Segmin{
	

	

	

	
	
	private:
	public:
	
	

	

	

	

	
	int cor=(1<<17);
	
	vector<pa> vec;
	
	void shoki1(){
		vec.resize(2*cor+3, mp(-(1ll<<31),0));
		for(int i=cor;i<2*cor;i++)vec[i].second=i-cor;
	}
	
	void shoki2(){
		for(int i=cor-1;i>0;i--) {
			if(vec[2*i].first<=vec[2*i+1].first) vec[i]=vec[2*i];
			else vec[i]=vec[2*i+1];
		}
	}
		
	void updadd(int x,int w){
		

		x+=cor;
		vec[x].first+=w;
		x/=2;
		while(x){
			if(vec[2*x].first<=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
			x/=2;
		}
	}
	
	void updchan(int x,int w){
		

		x+=cor;
		vec[x].first=w;
		x/=2;
		while(x){
			if(vec[2*x].first<=vec[2*x+1].first) vec[x]=vec[2*x];
			else vec[x]=vec[2*x+1];
			x/=2;
		}
	}
	
	
	

	

	

	pa segmin(int a,int b){
		a+=cor;
		b+=cor;
		pa ans=mp((1ll<<31)-1,-1);
		while(a<b){
			if(a&1){
				ans=min(ans,vec[a]);
				a++;
			}
			if(b&1){
				b--;
				ans=min(ans,vec[b]);
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
			if(vec[p].first<=x)break;

			p++;
			if(p==(p&(-p))) return cor;
		}
		while(1){
			if(p>=cor) return p-cor;
			p*=2;
			if(vec[p].first>x){

				p++;
			}
		}
	}
	
};



set<int> ky,se1,se0;
vector<int> ve;
Segmin s1,s2;
int ans=0;

seg_rangeadd_getsum ss;
void fi(int x){
	se1.erase(x);
	se0.erase(x);
	
	int a=ss.getsum(x,x+1);
	int b=ss.getsum(x+1,x+2);
	if(a<=b)se1.insert(x);
	else se0.insert(x);
	
	ky.erase(x);
	ky.erase(x+1);
	if(se1.count(x-1) && se0.count(x))ky.insert(x);
	if(se1.count(x) && se0.count(x+1))ky.insert(x+1);
	s1.updchan(x,b-a);
	s2.updchan(x,a-b);
	
	
}
void solve(){
int n;
	cin>>n;
	
	ss.shoki1();
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		ve.pb(y);
		ss.vec[ss.cor+i]=y;
	}
	ss.shoki2();
	
	s1.shoki1();
	s2.shoki1();
	for(int i=0;i<n-1;i++){
		s1.vec[ss.cor+i].first=ve[i+1]-ve[i];
		s2.vec[ss.cor+i].first=-ve[i+1]+ve[i];
		ans+=abs(ve[i+1]-ve[i]);
		if(ve[i]<=ve[i+1])se1.insert(i);
		else se0.insert(i);
	}
	se1.insert(inf);
	se0.insert(inf);
	
	ky.insert(inf);
	for(int i=1;i<n-1;i++){
		if(ve[i-1]<=ve[i]&&ve[i]>ve[i+1])ky.insert(i);
	}
	s1.shoki2();
	s2.shoki2();
	
	
	int q;
	cin>>q;
	while(q--){
		
		int t,l,r,x;
		cin>>t>>l>>r>>x;
		l--;
		if(t==2){
			ans-=abs(ss.getsum(l-1,l)-ss.getsum(l,l+1));
			ans-=abs(ss.getsum(r-1,r)-ss.getsum(r,r+1));
			ss.rangeadd(l,r,x);
			ans+=abs(ss.getsum(l-1,l)-ss.getsum(l,l+1));
			ans+=abs(ss.getsum(r-1,r)-ss.getsum(r,r+1));
			fi(l-1),fi(r-1);
		}
		else{
			auto it=ky.lower_bound(l);
			if(*it<r){
				cout<<ans+2*x<<"\n";
			}
			else{
				it=se1.lower_bound(l-1);
			

				if(*it==l-1){
					int d=s1.segmin(l,r).first;
					assert(d>=0);
		

					cout<<ans+2*max(0ll,x-d)<<"\n";
				}
				else if(*it>=r){
					int d=s2.segmin(l-1,r-1).first;
					assert(d>=1);
					cout<<ans+2*max(0ll,x-d)<<"\n";		
				}
				else{
					int p=0;
					
					int a1=ss.getsum(*it-1,*it);
					int a2=ss.getsum(*it,*it+1);
					int a3=ss.getsum(*it+1,*it+2);
					p=abs(a2+x-a1)+abs(a2+x-a3)-abs(a2-a1)-abs(a2-a3);
					int d;
					if(l<*it){
						d=s2.segmin(l-1,*it-1).first;
						p=max(p,2*max(0ll,x-d));
					}
					if(r>*it+1){
						d=s1.segmin(*it+1,r).first;
						p=max(p,2*max(0ll,x-d));		
					}
					cout<<ans+p<<"\n";
				}
			}
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
 

