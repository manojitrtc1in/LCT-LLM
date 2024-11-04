   #include <bits/stdc++.h>
 




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
              
              

    		

    			

                 

 

  


struct Sparsetable_min{
	
	
	private:
	public:
	
	

	

	

	

	
	int beki=19;
	
	int cor=(1<<beki);
	
	vector<vector<int>> vec;
	vector<int> lo;
	
	void shoki1(){
		vec= vector<vector<int>>(beki+1, vector<int>(cor, 0));
		lo=vector<int>(cor+1);
		lo[0]=-1;
		for(int i=1;i<=cor;i++)lo[i]=lo[i>>1]+1;
	}
	
	void shoki2(){
		for(int i=1;i<=beki;i++)for(int j=0;j<cor;j++){
			if((j+(1<<(i-1)))<cor)vec[i][j]=min(vec[i-1][j],vec[i-1][j+(1<<(i-1))]);
			else vec[i][j]=vec[i-1][j];
		}
	}
	
	int rangemin(int i,int j){
		int haba=lo[j-i];
		
		return min(vec[haba][i],vec[haba][j-(1<<haba)]);
	}
	
};


struct SAIS{
	private:
	public:

	string STR;
	vector<int> S;
	vector<int> SL;
	

	

	

	vector<pa> haba;
	vector<int> SA;
	vector<int> rank;
	vector<int> LCP;
	int mojisu;
	int len;
	
	void make_suffix_array_string(string str){
		STR=str;
		set<char> setc;
		map<char,int> mapc;
		for(auto c:str)setc.insert(c);
		int cnt=1;
		for(auto it=setc.begin();it!=setc.end();it++){
			mapc[*it]=cnt;
			cnt++;
		}
		for(auto c:str)S.pb(mapc[c]);
		mojisu=cnt;
		S.pb(0);
		make_suffix_array_naibu();
	}
	
	void make_suffix_array_saiki(vector<int> ve,int max_valu){
		S=ve;
		S.pb(0);
		mojisu=max_valu+1;
		make_suffix_array_naibu();
	}
	
	
	void make_suffix_array_naibu(){
		int cnt=mojisu;
		len=S.size();
		
		vector<int> kosuu(cnt,0);
		for(auto c:S)kosuu[c]++;
		
		haba.pb({0,0});
		for(int i=1;i<cnt;i++){
			haba.pb({haba.back().second+1,haba.back().second+kosuu[i]});
		}
		
		

		

		

		

		

		


		SL.resize(len);
		for(int i=len-1;i>=0;i--){
			if(i==len-1){
				SL[i]=1;
			}
			else{
				if(S[i]<S[i+1]) SL[i]=1;
				else if(S[i]>S[i+1])SL[i]=0;
				else{
					SL[i]=SL[i+1];
				}
			}
		}
		
		int LMS_num=0;
		vector<int> LMS;
		vector<int> LMS_id(len,0);
		int rt=0;
		for(int i=1;i<len;i++)if(SL[i-1]==0 &&SL[i]==1){
			LMS.pb(i);
			LMS_id[i]=rt;
			LMS_num++;
			rt++;
		}
		for(int i=0;i<LMS_num-1;i++){
			SL[LMS[i]]=-(LMS[i+1]-LMS[i]+1);
		}
		SL[len-1]=-1;
		
		for(int i=0;i<len;i++)SA.pb(-1);
		vector<int> pos(cnt,0);
		for(int c=0;c<len;c++)if(SL[c]<0){
			
			SA[haba[S[c]].second-pos[S[c]]]=c;
			pos[S[c]]++;
		}
		

		

		

		

		

		

		
		
		induced_sort(SA,len,cnt);
		
	

		

		

		

		

		

		

		
		vector<pa> lms_sub_order;
		int mae_ind;
		for(int i=0;i<len;i++)if(SL[SA[i]]<0){
			if(i==0){
				lms_sub_order.pb({SA[i],1});
				
			}
			else if(lms_sub_order.back().second==1){
				lms_sub_order.pb({SA[i],2});
			}
			else if(SL[SA[mae_ind]]!=SL[SA[i]]){
				lms_sub_order.pb({SA[i],lms_sub_order.back().second+1});
			}
			else{
				int lmslen= -SL[SA[mae_ind]];
				bool bo=true;
				for(int j=0;j<lmslen;j++){
					if(S[SA[mae_ind]+j]!=S[SA[i]+j]){
						bo=0;
						break;
					}
				}
				if(bo)lms_sub_order.pb({SA[i],lms_sub_order.back().second});
				else lms_sub_order.pb({SA[i],lms_sub_order.back().second+1});
			}
			mae_ind=i;
		}
	

	

			for(int i=0;i<cnt;i++)pos[i]=0;
			for(int i=0;i<len;i++)SA[i]=-1;
		
		if(LMS_num==lms_sub_order.back().second){
			for(int i=LMS_num-1;i>=0;i--){
				int c=lms_sub_order[i].first;
				SA[haba[S[c]].second-pos[S[c]]]=c;
				pos[S[c]]++;
			}
	
		}
		else{
			vector<int> rec((int)LMS.size());
			for(int i=0;i<LMS_num;i++){
				rec[LMS_id[lms_sub_order[i].first]]=lms_sub_order[i].second;
			}
			SAIS ss_naibu;
			ss_naibu.make_suffix_array_saiki(rec,lms_sub_order.back().second);
			
			for(int i=LMS_num;i>0;i--){
				int c=LMS[ss_naibu.SA[i]];
				SA[haba[S[c]].second-pos[S[c]]]=c;
				pos[S[c]]++;
			}
		}

			induced_sort(SA,len,cnt);
		rank.resize(len);
		for(int i=0;i<len;i++)rank[SA[i]]=i;
			return;
	}
	
	void induced_sort(vector<int> &ve, int len,int cnt){
		vector<int> ue(cnt,0);
		for(int i=0;i<len;i++){
			if(ve[i]==-1) continue;
			if(ve[i]==0) continue;
			if(SL[ve[i]-1]==0){
				ve[haba[S[ve[i]-1]].first+ue[S[ve[i]-1]]]=ve[i]-1;
				ue[S[ve[i]-1]]++;
			}
			if(SL[ve[i]]<0 && i>0) ve[i]=-1;
		}
		for(int i=0;i<cnt;i++)ue[i]=0;
		
		for(int i=len-1;i>=0;i--){
			if(ve[i]==-1) continue;
			if(ve[i]==0) continue;
			if(SL[ve[i]-1]!=0){
				ve[haba[S[ve[i]-1]].second-ue[S[ve[i]-1]]]=ve[i]-1;
				ue[S[ve[i]-1]]++;
			}
		}
		for(auto v:ve)if(v==-1)assert(0);
	}
	
	void make_lcp(){
				S.clear();
		 SL.clear();
 haba.clear();

		LCP.resize(len);
		int h=0;
		LCP[0]=0;
		for(int i=0;i<len-1;i++){
			int j=SA[rank[i]-1];
			if(h>0)h--;
			for(;j+h<len-1&& i+h<len-1;h++){
				if(S[j+h]!=S[i+h])break;
			}
			LCP[rank[i]-1]=h;
		}
	

		
		return;
	}
	
	int lower_bound(string p){

		int m=p.length();
		int ue=len,si=0,me;
		while(ue-si>1){
			me=(ue+si)/2;
			if(STR.compare(SA[me],m,p)<0)si=me;
			else ue=me;
		}
		return ue;
	}
	
	bool exist(string p){
		int l=p.length();
		int id=lower_bound(p);
		
	
		return 0==STR.compare(SA[id],l,p);
	}
	pa range(string p){

				return {lower_bound(p),lower_bound(p+'{')};
	}
};

signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int n;
	cin>>n;
string s;
	cin>>s;
	vector<int> ve(n);
	int cnt=0;
	string t="";
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			ve[i]=cnt;
		}
		else{
			ve[i]=cnt;
			cnt++;
			if(i%2)t+="b";
			else t+="a";
		}
	}
		int m=t.length();
	if(m==0){
		int e;
		cin>>e;
		for(int i=0;i<e;i++)cout<<"Yes\n";
		return 0;
	}
	for(int i=0;i<m;i++)t+=(char)('a'^'b'^t[i]);
	
	
	ve.pb(cnt);
	SAIS ss;



	ss.make_suffix_array_string(t);
	ss.make_lcp();
	Sparsetable_min sm;
	sm.shoki1();
	for(int i=0;i<ss.LCP.size();i++)sm.vec[0][i]=ss.LCP[i];




	sm.shoki2();
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int l1,l2,p;
		cin>>l1>>l2>>p;
		l1--,l2--;
		int r1=l1+p,r2=l2+p;
		if(ve[r1]-ve[l1]!=ve[r2]-ve[l2]){
			cout<<"No\n";
			continue;
		}
		if(l1%2==l2%2){
			if(ve[r1]==ve[l1] || ve[r1]==ve[r2]){
				cout<<"Yes\n";
					continue;
			}
			int e1=ss.rank[ve[l1]];
			int e2=ss.rank[ve[l2]];
			if(e1>e2)swap(e1,e2);
			if(sm.rangemin(e1,e2)>=ve[r1]-ve[l1]){
				cout<<"Yes\n";
			}
			else cout<<"No\n";
		}
		else{
			if(ve[r1]==ve[l1]){
				cout<<"Yes\n";
					continue;
			}
			if(ve[r1]==ve[r2]){
				cout<<"No\n";
				continue;
			}
			
			int e1=ss.rank[ve[l1]];
			int e2=ss.rank[ve[l2]+m];
			if(e1>e2)swap(e1,e2);
		

			if(sm.rangemin(e1,e2)>=ve[r1]-ve[l1]){
				cout<<"Yes\n";
			}
			else cout<<"No\n";	
		}
	}
return 0;
 }
