   #include <bits/stdc++.h>
 


 #define int long long
 #define inf  1000000007
 #define pa pair<int,int>
 #define ll long long
 #define pal pair<double,double>
 #define ppap pair<pa,int>
  #define PI 3.14159265358979323846
  #define paa pair<int,char>
  #define  mp make_pair
  #define  pb push_back
  #define EPS (1e-8)
                                          
    int dx[8]={0,1,0,-1,1,1,-1,-1};
    int dy[8]={1,0,-1,0,-1,1,1,-1};
                                            using namespace std;
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
                                 
                                int gcd(int v,int b){
                                	if(v==0) return b;
                                	if(b==0) return v;
                                	if(v>b) return gcd(b,v);
                                	if(v==b) return b;
                                	if(b%v==0) return v;
                                	return gcd(v,b%v);
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
                                
                int pr[10000100];
                int inv[10000010];
                
                int beki(int wa,int rr,int warukazu){
                	if(rr==0) return 1%warukazu;
                	if(rr==1) return wa%warukazu;
                	wa%=warukazu;
                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
                	ll zx=beki(wa,rr/2,warukazu);
                	return (zx*zx)%warukazu;
                }
 
                
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
                
              

    		

    			

                 

 

  

struct BV{

	
	private:
	public:
	int N;
	vector<int> RAN;
	vector<int> SEL1;
	vector<int> SEL0;
	int k0=0,k1=0;
	vector<bool> VEC;
	void shoki1(int NN){
		
		N=NN;
		
		VEC.resize(N,false);
		RAN.resize(N+1,0);
		
		
	}
	void setbit(int i){
		VEC[i]=1;
	}
	void resetbit(int i){
		VEC[i]=0;
	}
	void shoki2(){
		for(int i=0;i<N;i++){
			if(VEC[i]){
				RAN[i]=k1;
				k1++;
			}
			else{
				RAN[i]=k0;
				k0++;
			}
		}
		SEL1.resize(k1);
		SEL0.resize(k0);
		k0=0,k1=0;
		for(int i=0;i<N;i++){
			if(VEC[i]){
				SEL1[k1]=i;
				k1++;
			}
			else{
				SEL0[k0]=i;
				k0++;
			}
		}
	}
	
	
	int rank(int it){ return RAN[it];}
	int rank0(int it){
		if(it==N) return k0;
		if(VEC[it])return it-RAN[it];
		else return RAN[it];
	}
	int rank1(int it){
		if(it==N) return k1;
		if(VEC[it]==0)return it-RAN[it];
		else return RAN[it];
	}
	int select(int ko,bool b){
		if(b){
			if(ko>=k1)return -1;
			else return SEL1[ko];
		}
		else{
			if(ko>=k0)return -1;
			else return SEL0[ko];
		}
	}
	int access(int it) {return VEC[it];}

};

struct wavlet_matrix{
	private:
	public:
	
	int N;
	
	vector<int> VEC;
	int d;
	
	vector<BV> bv;
	vector<int> zero;
	

	
	

	

	
	void shoki1(vector<int> &input,int D){
		VEC=input;
		N=input.size();
		d=D;
		bv.resize(d);
		zero.resize(d);
		
	}
	void shoki2(){
		
		for(int i=d-1;i>=0;i--){
			
			bv[i].shoki1(N);
			vector<int> mae,ato;
			for(int j=0;j<N;j++){
			
				if(VEC[j]&(1ll<<i)){
					
					ato.pb(VEC[j]);
					bv[i].setbit(j);
				}
				else{
					mae.pb(VEC[j]);
				}
			}
			
			zero[i]=(int)mae.size();
			bv[i].shoki2();
			
			mae.insert(mae.end(),ato.begin(),ato.end());
			
			
			
			
			swap(VEC,mae);
		}
		
	}
	
	
	int access(int r){
		int ans=0;
		for(int i=d-1;i>=0;i--){
			if(bv[i].access(r)){
				ans+=(1ll<<i);
				r=zero[i]+bv[i].rank(r);
			}
			else{
				r=bv[i].rank(r);
			}
		}
		
		return ans;
	}
	
	int range_rank(int val, int l,int r){ 

		
		
		
		for(int i=d-1;i>=0;i--){
			if(val&(1ll<<i)){
				r=zero[i]+bv[i].rank1(r);
				l=zero[i]+bv[i].rank1(l);
			}
			else{
				r=bv[i].rank0(r);
				l=bv[i].rank0(l);
			}
			
			
			if(l>=r) return 0;
		}
	
	return r-l;
	}
	
	int rank(int val,int pos){

		return range_rank(val,0,pos+1);
	}
	
	int select(int val,int kth){

		
		
		int l=0,r=N;
		for(int i=d-1;i>=0;i--){
			if(val&(1ll<<i)){
				r=zero[i]+bv[i].rank1(r);
				l=zero[i]+bv[i].rank1(l);
			}
			else{
				r=bv[i].rank0(r);
				l=bv[i].rank0(l);
			}
			
			
			if(l+kth>=r) return -1;
		}
		int pos=l+kth;
		

		for(int i=0;i<d;i++){
			if(val&(1ll<<(i))){
			
				pos=bv[i].select(pos-zero[i],1);
			}
			else{
				pos=bv[i].select(pos,0);
			}
	

		}
		return pos;
		
	}
	
	int x_th_min(int x,int l,int r){
		

		

		

		int ans=0;
		
		
		for(int i=d-1;i>=0;i--){
			int t1=bv[i].rank0(l);
			int t2=bv[i].rank0(r);
			int z=t2-t1;
		

			if(z>x){
				l=t1,r=t2;
			}
			else{
				ans+=(1ll<<i);
				x-=z;
				l=zero[i]+l-t1;
				r=zero[i]+r-t2;
			}
		}
		return ans;
	}
	
	int range_min(int l,int r){
		return x_th_min(0,l,r);
	}
	
	int range_max(int l,int r){
		return x_th_min(r-l-1,l,r);
	}
	
	
	int range_count_prefix(int l,int r,int val){
		

		if(val<=0) return 0;
		if(l>=r)return 0;
		val--;
		

		int ans=0;
		
		for(int i=d-1;i>=0;i--){
			int t1=bv[i].rank0(l);
			int t2=bv[i].rank0(r);
			
			if(val&(1ll<<i)){
				ans+=t2-t1;				
				l=zero[i]+l-t1;
				r=zero[i]+r-t2;
			}
			else{
				l=t1;
				r=t2;
			}
		}
		ans+=r-l;
		
		return ans;
		
	}
	
	int range_count(int l,int r,int vl,int vr){
		

		if(vr<=vl) return 0;
		if(r<=l) return 0;
		return range_count_prefix(l,r,vr)-range_count_prefix(l,r,vl);
		
	}		
	
	
	int range_bound_max(int l,int r,int val){
		

		

		
		if(l>=r) return -1;
		
		int dep=-1;
		int cl=-1;
		int cr=-1;
		int cur=0;
		
		int ima=0;
		for(int i=d-1;i>=0;i--){
			
			if(i==0){
				if(val&1){
					if(l<r){
						dep=0;
						cl=l,cr=r;
						cur=ima;
					}
				}
				else{
					int t1=bv[i].rank0(l);
					int t2=bv[i].rank0(r);
					if(t1<t2) return ima;
				}
				break;
				
			}
			
			if(val&(1ll<<i)){
				int t1=bv[i].rank0(l);
				int t2=bv[i].rank0(r);
				if(t1!=t2){
					dep=i-1;
					cl=t1,cr=t2;
					cur=ima;
				}
				l=zero[i]+l-t1;
				r=zero[i]+r-t2;
				ima+=(1ll<<i);
			}
			else{
				int t1=bv[i].rank0(l);
				int t2=bv[i].rank0(r);
				l=t1,r=t2;
				
			}
		}
		if(dep==-1) return -1;
		ima=cur;
		l=cl,r=cr;
		for(int i=dep;i>=0;i--){
			int t1=bv[i].rank0(l);
			int t2=bv[i].rank0(r);
			if(r-l>t2-t1){
				ima+=(1ll<<i);
				l=zero[i]+l-t1;
				r=zero[i]+r-t2;
			}
			else{
				l=t1,r=t2;
			}
		}
		
		return ima;
	}
	
	
	int range_bound_min(int l,int r,int val){
		

		

		if(l>=r) return -1;
		
		int dep=-1;
		int cl=-1;
		int cr=-1;
		int cur=0;
		
		int ima=0;
		for(int i=d-1;i>=0;i--){
			
			if(i==0){
				if((val&1)==0){
					if(l<r){
						dep=0;
						cl=l,cr=r;
						cur=ima;
					}
				}
				else{
					int t1=zero[i]+l-bv[i].rank0(l);
					int t2=zero[i]+r-bv[i].rank0(r);
					ima+=(1ll<<i);
					if(t1<t2) return ima;
				}
				break;
				
			}
			
			if((val&(1ll<<i))==0){
				int t1=bv[i].rank0(l);
				int t2=bv[i].rank0(r);
				int s1=zero[i]+l-t1;
				int s2=zero[i]+r-t2;
				if(s1<s2){
					dep=i-1;
					cl=s1,cr=s2;
					cur=ima+(1ll<<i);
				}
				l=t1,r=t2;
			}
			else{
				int t1=bv[i].rank0(l);
				int t2=bv[i].rank0(r);
				int s1=zero[i]+l-t1;
				int s2=zero[i]+r-t2;
				l=s1,r=s2;
				ima=ima+(1ll<<i);
				
			}
		}
	
		if(dep==-1) return -1;
		ima=cur;
		l=cl,r=cr;
		
		for(int i=dep;i>=0;i--){
			int t1=bv[i].rank0(l);
			int t2=bv[i].rank0(r);
			if(t2-t1==0){
				ima+=(1ll<<i);
				l=zero[i]+l-t1;
				r=zero[i]+r-t2;
			}
			else{
				l=t1,r=t2;
			}
			assert(l<r);
		}
		
		return ima;
	}
	
	
			

	
			

};

bool hikaku(pa x,pa y){
	if(x.second!=y.second)return x.second>y.second;
	return x.first<y.first;
}

signed main(){
	
	
cin.tie(0);
ios::sync_with_stdio(false);

wavlet_matrix wm;
	int n;
	cin>>n;
	vector<pa>ve;
	vector<int> r;
	for(int i=0;i<n;i++){
	int y;
		cin>>y;
		r.pb(y);
		ve.pb(mp(i,y));
	}
	sort(ve.begin(),ve.end(),hikaku);
	vector<int> w;
	for(auto v:ve)w.pb(v.first);
	wm.shoki1(w,20);
	wm.shoki2();
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int l,p;
		cin>>l>>p;
		p--;
		cout<<r[wm.x_th_min(p,0,l)]<<"\n";
	}
	return 0;
 }
