














using namespace std;




















class MPI{


public:
	vector<li> MPI_VALUE;
	bool MPI_SIGN;
	
	MPI(const string &mpi_s){
		MPI_SIGN=false;
		if(sz(mpi_s)){
			if(mpi_s[0]=='-') MPI_SIGN=true;
			for(li i=sz(mpi_s)-1;((mpi_s[0]=='-')?1:0)<=i;i-=id8){
				li mpi_sum=0;
				li mpi_base=1;
				rep(j,id8)if(((mpi_s[0]=='-')?1:0)<=i-j){
					mpi_sum+=(mpi_s[i-j]-'0')*mpi_base;
					mpi_base*=10;
				}
				MPI_VALUE.pb(mpi_sum);
			}
		}
		mpi_reform(*this);
	}
	
	MPI(const vector<li> &mpi_vec){
		MPI_SIGN=false;
		MPI_VALUE=mpi_vec;
		mpi_reform(*this);
	}
	
	
	MPI(int mpi_val){
		MPI_SIGN=false;
		if(mpi_val<0){ mpi_val=-mpi_val; MPI_SIGN=true; }
		while(mpi_val){
			MPI_VALUE.pb(mpi_val%MPI_MAX);
			mpi_val/=MPI_MAX;
		}
		mpi_reform(*this);
	}

	
	MPI(li mpi_val){
		MPI_SIGN=false;
		if(mpi_val<0){ mpi_val=-mpi_val; MPI_SIGN=true; }
		while(mpi_val){
			MPI_VALUE.pb(mpi_val%MPI_MAX);
			mpi_val/=MPI_MAX;
		}
		mpi_reform(*this);
	}
	
	MPI(bool id6,bool id4){
		MPI_SIGN=false;
	}

	MPI(){
		MPI_SIGN=false;
		MPI_VALUE.pb(0);
	}
	
	string to_string() const{
		string mpi_res="";
		li mpi_p10[id8+1];
		rep(i,id8+1) mpi_p10[i]=(i)?(mpi_p10[i-1]*10):1;
		for(li i=sz(MPI_VALUE)-1;0<=i;i--)rep(j,id8){
			li mpi_tmp=(MPI_VALUE[i]%mpi_p10[id8-j])/mpi_p10[id8-j-1];
			if(sz(mpi_res) || mpi_tmp) mpi_res+=string(1,'0'+mpi_tmp);
		}
		if(sz(mpi_res)==0) mpi_res+="0";
		else if(MPI_SIGN) mpi_res="-"+mpi_res;
		return mpi_res;
	}
	
	li to_long() const{
		li mpi_res=0;
		li mpi_base=1;
		rep(i,sz(MPI_VALUE)){
			mpi_res+=MPI_VALUE[i]*mpi_base;
			mpi_base*=MPI_MAX;
		}
		if(MPI_SIGN) mpi_res=-mpi_res;
		return mpi_res;
	}
	
	li size() const{
		li mpi_res=(sz(MPI_VALUE)-1)*id8;
		li mpi_tmp=MPI_VALUE.back();
		while(mpi_tmp){ mpi_res++; mpi_tmp/=10; }
		return mpi_res;
	}
	
	static MPI mpi_abs_add(const MPI &mpi0,const MPI &mpi1){
		MPI mpi_res(false,false);
		li carry=0;
		rep(i,max(sz(mpi0.MPI_VALUE),sz(mpi1.MPI_VALUE))){
			li id2=(i<sz(mpi0.MPI_VALUE))?(mpi0.MPI_VALUE[i]):0;
			li id9=(i<sz(mpi1.MPI_VALUE))?(mpi1.MPI_VALUE[i]):0;
			li mpi_t=id2+id9+carry;
			mpi_res.MPI_VALUE.pb(mpi_t%MPI_MAX);
			carry=mpi_t/MPI_MAX;
		}
		if(carry) mpi_res.MPI_VALUE.pb(carry);
		mpi_reform(mpi_res);
		return mpi_res;
	}
	
	static MPI mpi_abs_sub_sub(const MPI &mpi0,const MPI &mpi1){
		MPI mpi_res(false,false);
		mpi_res.MPI_VALUE=mpi0.MPI_VALUE;
		li carry=0;
		for(li i=0;i<sz(mpi1.MPI_VALUE) || carry;i++){
			mpi_res.MPI_VALUE[i]-=carry;
			carry=0;
			if(i<sz(mpi1.MPI_VALUE)) mpi_res.MPI_VALUE[i]=mpi_res.MPI_VALUE[i]-mpi1.MPI_VALUE[i];
			if(mpi_res.MPI_VALUE[i]<0){
				carry++;
				mpi_res.MPI_VALUE[i]+=MPI_MAX;
			}
		}
		mpi_reform(mpi_res);
		return mpi_res;
	}
	
	static MPI mpi_abs_sub(const MPI &mpi0,const MPI &mpi1){
		if(!mpi_abs_gt(mpi0,mpi1)) return mpi_abs_sub_sub(mpi0,mpi1);
		MPI mpi_res=mpi_abs_sub_sub(mpi1,mpi0);
		mpi_res.MPI_SIGN=!mpi_res.MPI_SIGN;
		return mpi_res;
	}	
	
	
	static MPI mpi_abs_mul(const MPI &mpi0,const MPI &mpi1){
		MPI mpi_res(false,false);
		mpi_res.MPI_VALUE=vector<li>(sz(mpi0.MPI_VALUE)+sz(mpi1.MPI_VALUE),0);
		rep(i,sz(mpi0.MPI_VALUE))if(mpi0.MPI_VALUE[i]){
			rep(j,sz(mpi1.MPI_VALUE)){
				mpi_res.MPI_VALUE[i+j]+=mpi0.MPI_VALUE[i]*mpi1.MPI_VALUE[j];
			}
		}
		mpi_add_mul_reform(mpi_res);
		return mpi_res;
	}	
	
	MPI operator+(const MPI &mpi_var){
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0 &&!b1) return mpi_abs_add(*this,mpi_var);
		if(!b0 && b1) return mpi_abs_sub(*this,mpi_var);
		if( b0 &&!b1) return mpi_abs_sub(mpi_var,*this);
		MPI mpi_res=mpi_abs_add(*this,mpi_var);
		mpi_res.MPI_SIGN= !mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	MPI operator-(const MPI &mpi_var){
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0&&!b1) return mpi_abs_sub(*this,mpi_var);
		if(!b0&& b1) return mpi_abs_add(*this,mpi_var);
		if( b0&& b1) return mpi_abs_sub(mpi_var,*this);
		MPI mpi_res=mpi_abs_add(*this,mpi_var);
		mpi_res.MPI_SIGN= !mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	MPI operator*(const MPI &mpi_var){
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if( b0&& b1) return mpi_abs_mul(*this,mpi_var);
		if(!b0&&!b1) return mpi_abs_mul(*this,mpi_var);
		MPI mpi_res=mpi_abs_mul(*this,mpi_var);
		mpi_res.MPI_SIGN= !mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	friend std::ostream& operator<<(std::ostream& os,const MPI &mpi_var){
		os<<mpi_var.to_string();
		return os;
	}
	
	friend std::istream& operator>>(std::istream& is,MPI &mpi_var){
		string mpi_str;
		is>>mpi_str;
		mpi_var=MPI(mpi_str);
		return is;
	}
	
	

	static void mpi_subst(MPI &mpi_from,const MPI &mpi_base,li mpi_cons,li mpi_shift){
		li carry=0;
		for(li i=0;i+mpi_shift<sz(mpi_from.MPI_VALUE);i++){
			mpi_from.MPI_VALUE[mpi_shift+i]-=carry;
			carry=0;
			if(i<sz(mpi_base.MPI_VALUE)){
				carry=(mpi_base.MPI_VALUE[i]*mpi_cons)/MPI_MAX;
				mpi_from.MPI_VALUE[mpi_shift+i]-=(mpi_base.MPI_VALUE[i]*mpi_cons)%MPI_MAX;
			}
			while(mpi_from.MPI_VALUE[mpi_shift+i]<0){
				carry++;
				mpi_from.MPI_VALUE[mpi_shift+i]+=MPI_MAX;
			}
		}
	}

	static bool mpi_can_sub(const MPI &mpi_from,const MPI &mpi_base,li mpi_cons,li mpi_shift){
		li carry=0;
		for(li i=0;i+mpi_shift<sz(mpi_from.MPI_VALUE);i++){
			li mpi_tmp=carry;
			if(i<sz(mpi_base.MPI_VALUE)) mpi_tmp+=mpi_base.MPI_VALUE[i]*mpi_cons;
			li id5=(mpi_tmp-mpi_from.MPI_VALUE[i+mpi_shift]);
			if(id5<0) carry=0;
			else carry=((id5%MPI_MAX)?1:0)+id5/MPI_MAX;
		}
		return carry==0;
	}


	static MPI mpi_abs_div_small(const MPI &mpi_den,const MPI &mpi_num,bool is_div){
		MPI mpi_ans(false,false);
		MPI mpi_rem(mpi_den.MPI_VALUE);
		mpi_ans.MPI_VALUE=vector<li>(sz(mpi_rem.MPI_VALUE),0);
		li mpi_cons=abs(mpi_num.to_long()),carry=0;
		for(li i=sz(mpi_rem.MPI_VALUE)-1;0<=i;i--){
			mpi_rem.MPI_VALUE[i]+=carry*MPI_MAX;
			carry=mpi_rem.MPI_VALUE[i]%mpi_cons;
			mpi_ans.MPI_VALUE[i]=mpi_rem.MPI_VALUE[i]/mpi_cons;
		}
		if(!is_div) return MPI(carry);
		mpi_reform(mpi_ans);
		return mpi_ans;
	}

	static MPI mpi_abs_div(const MPI &mpi_den,const MPI &mpi_num,bool is_div){
		if(mpi_abs_gt(mpi_num,MPI_MAX)) return mpi_abs_div_small(mpi_den,mpi_num,is_div);
		MPI mpi_ans(0);
		MPI mpi_rem(mpi_den.MPI_VALUE);
		mpi_ans.MPI_VALUE=vector<li>(sz(mpi_rem.MPI_VALUE),0);
		li id1=sz(mpi_num.MPI_VALUE)-1;
		li id0=mpi_num.MPI_VALUE[id1];

		if(id0*MPI_MAX<1000000000000000000ll/MPI_MAX && 1<=id1){
			id0=id0*MPI_MAX+mpi_num.MPI_VALUE[--id1];
		}

		while(!mpi_abs_gt(mpi_rem,mpi_num)){
			li id3=sz(mpi_rem.MPI_VALUE)-1;
			li id7=mpi_rem.MPI_VALUE[id3];
			while(id7<id0){
				id7=id7*MPI_MAX+mpi_rem.MPI_VALUE[--id3];
			}
			li mpi_tmp=id7/id0;
			li id5=id3-id1;
			while(!mpi_can_sub(mpi_rem,mpi_num,mpi_tmp,id5)) mpi_tmp--;
			if(mpi_tmp==0){
				id7=id7*MPI_MAX+mpi_rem.MPI_VALUE[--id3];
				mpi_tmp=id7/id0;
				id5=id3-id1;
				while(!mpi_can_sub(mpi_rem,mpi_num,mpi_tmp,id5)) mpi_tmp--;
			}
			mpi_subst(mpi_rem,mpi_num,mpi_tmp,id5);
			mpi_ans.MPI_VALUE[id5]+=mpi_tmp;
			mpi_reform(mpi_rem);
		}
		if(!is_div) return mpi_rem;
		mpi_add_mul_reform(mpi_ans);
		return mpi_ans;
	}
	
	
	MPI operator/(const MPI &mpi_var){
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0&&!b1) return mpi_abs_div(*this,mpi_var,true);
		if( b0&& b1) return mpi_abs_div(*this,mpi_var,true);
		MPI mpi_res=mpi_abs_div(*this,mpi_var,true);
		mpi_res.MPI_SIGN=!mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	MPI operator%(const MPI &mpi_var){
		bool b0=MPI_SIGN;
		if(!b0) return mpi_abs_div(*this,mpi_var,false);
		MPI mpi_res=mpi_abs_div(*this,mpi_var,false);
		mpi_res.MPI_SIGN=!mpi_res.MPI_SIGN;
		return mpi_res;
	}
			
	bool operator<(const MPI &mpi_var)const{
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0&&!b1) return mpi_abs_gt(*this,mpi_var);
		if( b0&& b1) return mpi_abs_sl(*this,mpi_var);
		if(sz(this->MPI_VALUE)==1 && sz(mpi_var.MPI_VALUE)==1){
			if(this->MPI_VALUE.back()==0 && mpi_var.MPI_VALUE.back()==0) return true;
		}
		if( b0&&!b1) return true;
		if(!b0&& b1) return false;
	}
	
	bool operator>(const MPI &mpi_var)const{
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0&&!b1) return mpi_abs_sl(*this,mpi_var);
		if( b0&& b1) return mpi_abs_gt(*this,mpi_var);
		if(sz(this->MPI_VALUE)==1 && sz(mpi_var.MPI_VALUE)==1){
			if(this->MPI_VALUE.back()==0 && mpi_var.MPI_VALUE.back()==0) return true;
		}
		if( b0&&!b1) return false;
		if(!b0&& b1) return true;
	}
	
	bool operator==(const MPI &mpi_var)const{
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if( b0&& b1) return mpi_abs_eq(*this,mpi_var);
		if(!b0&&!b1) return mpi_abs_eq(*this,mpi_var);
		if(sz(this->MPI_VALUE)==1 && sz(mpi_var.MPI_VALUE)==1){
			if(this->MPI_VALUE.back()==0 && mpi_var.MPI_VALUE.back()==0) return true;
		}
		return false;
	}

	bool operator>=(const MPI &mpi_var)const{ return !(*this<mpi_var); }
	bool operator<=(const MPI &mpi_var)const{ return !(*this>mpi_var); }
	bool operator!=(const MPI &mpi_var)const{ return !(*this==mpi_var); }
	void operator+=(const MPI &mpi_var){ *this=*this+mpi_var; }
	void operator-=(const MPI &mpi_var){ *this=*this-mpi_var; }
	void operator*=(const MPI &mpi_var){ *this=*this*mpi_var; }
	void operator/=(const MPI &mpi_var){ *this=*this/mpi_var; }
	void operator%=(const MPI &mpi_var){ *this=*this%mpi_var; }
	friend bool operator>(li mpi_li,const MPI &mpi_var){ return MPI(mpi_li)>mpi_var; }
	friend bool operator<(li mpi_li,const MPI &mpi_var){ return MPI(mpi_li)<mpi_var; }
	friend bool operator>=(li mpi_li,const MPI &mpi_var){ return MPI(mpi_li)>=mpi_var; }
	friend bool operator<=(li mpi_li,const MPI &mpi_var){ return MPI(mpi_li)<=mpi_var; }
	friend bool operator!=(li mpi_li,const MPI &mpi_var){ return MPI(mpi_li)!=mpi_var;}
	friend bool operator==(li mpi_li,const MPI &mpi_var){ return MPI(mpi_li)==mpi_var;}
	
	MPI operator--(){ *this=*this-MPI(1); return *this; }
	MPI operator++(){ *this=*this+MPI(1); return *this; }
	MPI operator++(int mpi_i){ 
		MPI mpi_res=*this; 
		*this=*this+MPI(1);
		return mpi_res; 
	}
	MPI operator--(int mpi_i){
		MPI mpi_res=*this;
		*this=*this-MPI(1);
		return mpi_res;
	}
	MPI operator-(){ 
		MPI mpi_res=*this;
		mpi_res.MPI_SIGN=!mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	static bool mpi_abs_gt(const MPI &mpi0,const MPI &mpi1){
		if(sz(mpi0.MPI_VALUE)==sz(mpi1.MPI_VALUE)){
			for(li i=sz(mpi0.MPI_VALUE)-1;0<=i;i--){
				if(mpi0.MPI_VALUE[i]!=mpi1.MPI_VALUE[i]){
					return mpi0.MPI_VALUE[i]<mpi1.MPI_VALUE[i];
				}
			}
		}
		return sz(mpi0.MPI_VALUE)<sz(mpi1.MPI_VALUE);
	}
	
	static bool mpi_abs_sl(const MPI &mpi0,const MPI &mpi1){
		if(sz(mpi0.MPI_VALUE)==sz(mpi1.MPI_VALUE)){
			for(li i=sz(mpi0.MPI_VALUE)-1;0<=i;i--){
				if(mpi0.MPI_VALUE[i]!=mpi1.MPI_VALUE[i]){
					return mpi0.MPI_VALUE[i]>mpi1.MPI_VALUE[i];
				}
			}
		}
		return sz(mpi0.MPI_VALUE)>sz(mpi1.MPI_VALUE);
	}
	
	static bool mpi_abs_eq(const MPI &mpi0,const MPI &mpi1){
		if(sz(mpi0.MPI_VALUE)!=sz(mpi1.MPI_VALUE)) return false;
		rep(i,sz(mpi0.MPI_VALUE)){
			if(mpi0.MPI_VALUE[i]!=mpi1.MPI_VALUE[i]) return false;
		}
		return true;
	}
		
private:
	
	static void mpi_reform_vec(vector<li> &mpi_vec){
		if(sz(mpi_vec)==0) mpi_vec.pb(0);
		while(1<sz(mpi_vec) && mpi_vec.back()==0) mpi_vec.pop_back();
	}
	
	static void mpi_add_mul_reform_vec(vector<li> &mpi_vec){
		li carry=0;
		rep(i,sz(mpi_vec)){
			mpi_vec[i]+=carry;
			carry=mpi_vec[i]/MPI_MAX;
			mpi_vec[i]%=MPI_MAX;
		}
		mpi_vec.pb(carry);
		mpi_reform_vec(mpi_vec);
	}
	
	static void mpi_reform(MPI &mpi_var){
		mpi_reform_vec(mpi_var.MPI_VALUE);
		if(sz(mpi_var.MPI_VALUE)==1 && mpi_var.MPI_VALUE[0]==0) mpi_var.MPI_SIGN=false;
	}
	
	static void mpi_add_mul_reform(MPI &mpi_var){
		mpi_add_mul_reform_vec(mpi_var.MPI_VALUE);
		if(sz(mpi_var.MPI_VALUE)==1 && mpi_var.MPI_VALUE[0]==0) mpi_var.MPI_SIGN=false;
	}
};
























li n,k,RIGHT[MAX],LEFT[MAX],mini=bit(60);
vector<li> lucky;
li LEFT_SUM[MAX],RIGHT_SUM[MAX];

void make(li num){
	if(_INF*_INF<num) return;
	lucky.pb(num);
	make(num*10+4);
	make(num*10+7);
}

int main(){
	
	make(0);


	scanf("%I64d%I64d",&n,&k);
	lucky.pb(_INF*_INF*2ll);
	sort(lucky.begin(),lucky.end());


	rep(i,n) scanf("%I64d%I64d",&LEFT[i],&RIGHT[i]);
	rep(i,n) mini=min(mini,RIGHT[i]-LEFT[i]);
	sort(LEFT,LEFT+n);
	sort(RIGHT,RIGHT+n);
	li cnt;
	cnt=0;
	for(li i=1;i<sz(lucky);i++){
		MPI sum=(lucky[i]-lucky[i-1]);
		sum=sum*cnt;
		for(;cnt<n && RIGHT[cnt]<=lucky[i];cnt++){
			sum=sum+lucky[i]-RIGHT[cnt];
		}
		MPI INF = _INF*_INF;
		RIGHT_SUM[i]=min(sum+RIGHT_SUM[i-1],INF).to_long();
	}
	cnt=0;
	for(li i=sz(lucky)-1;0<i;i--){
		MPI sum=lucky[i+1]-lucky[i];
		sum=sum*cnt;
		for(;cnt<n && lucky[i]<=LEFT[n-1-cnt];cnt++){
			sum+=LEFT[n-1-cnt]-lucky[i];
		}
		MPI INF=_INF*_INF;
		LEFT_SUM[i]=min(sum+LEFT_SUM[i+1],INF).to_long();
	}
	li res=0;
	for(li i=1;i<sz(lucky);i++){
		if(k<LEFT_SUM[i]+RIGHT_SUM[i]) continue;
		li low0=i,high0=sz(lucky)-1;
		while(low0+1<high0){
			li mid=(low0+high0)/2;
			if(LEFT_SUM[i]+RIGHT_SUM[mid]<=k) low0=mid;
			else high0=mid;
		}
		li low1=i,high1=sz(lucky)-1;
		while(low1+1<high1){
			li mid=(low1+high1)/2;
			if(lucky[mid]-lucky[i]<=mini) low1=mid;
			else high1=mid;
		}
		res=max(res,min(low0-i+1,low1-i+1));


	}
	cout<<res<<endl;
	
}













