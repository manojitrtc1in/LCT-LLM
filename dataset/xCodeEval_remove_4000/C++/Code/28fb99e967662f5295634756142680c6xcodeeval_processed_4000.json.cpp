














using namespace std;





















class MPI{


public:
	vector<li> MPI_VALUE;
	bool MPI_SIGN;
	
	MPI(const string &mpi_s){
		MPI_SIGN=false;
		if(sz(mpi_s)){
			if(mpi_s[0]=='-') MPI_SIGN=true;
			for(li i=sz(mpi_s)-1;((mpi_s[0]=='-')?1:0)<=i;i-=id14){
				li mpi_sum=0;
				li mpi_base=1;
				rep(j,id14)if(((mpi_s[0]=='-')?1:0)<=i-j){
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
	
	MPI(bool id7,bool id3){
		MPI_SIGN=false;
	}

	MPI(){
		MPI_SIGN=false;
		MPI_VALUE.pb(0);
	}
	
	string to_string() const{
		string mpi_res="";
		li mpi_p10[id14+1];
		rep(i,id14+1) mpi_p10[i]=(i)?(mpi_p10[i-1]*10):1;
		for(li i=sz(MPI_VALUE)-1;0<=i;i--)rep(j,id14){
			li mpi_tmp=(MPI_VALUE[i]%mpi_p10[id14-j])/mpi_p10[id14-j-1];
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
		li mpi_res=(sz(MPI_VALUE)-1)*id14;
		li mpi_tmp=MPI_VALUE.back();
		while(mpi_tmp){ mpi_res++; mpi_tmp/=10; }
		return mpi_res;
	}
	
	static MPI mpi_abs_add(const MPI &mpi0,const MPI &mpi1){
		MPI mpi_res(false,false);
		li carry=0;
		rep(i,max(sz(mpi0.MPI_VALUE),sz(mpi1.MPI_VALUE))){
			li id11=(i<sz(mpi0.MPI_VALUE))?(mpi0.MPI_VALUE[i]):0;
			li id24=(i<sz(mpi1.MPI_VALUE))?(mpi1.MPI_VALUE[i]):0;
			li mpi_t=id11+id24+carry;
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
	
	MPI operator+(const MPI &mpi_var)const{
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0 &&!b1) return mpi_abs_add(*this,mpi_var);
		if(!b0 && b1) return mpi_abs_sub(*this,mpi_var);
		if( b0 &&!b1) return mpi_abs_sub(mpi_var,*this);
		MPI mpi_res=mpi_abs_add(*this,mpi_var);
		mpi_res.MPI_SIGN= !mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	MPI operator-(const MPI &mpi_var)const{
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0&&!b1) return mpi_abs_sub(*this,mpi_var);
		if(!b0&& b1) return mpi_abs_add(*this,mpi_var);
		if( b0&& b1) return mpi_abs_sub(mpi_var,*this);
		MPI mpi_res=mpi_abs_add(*this,mpi_var);
		mpi_res.MPI_SIGN= !mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	MPI operator*(const MPI &mpi_var)const{
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
		li id9=sz(mpi_num.MPI_VALUE)-1;
		li id15=mpi_num.MPI_VALUE[id9];

		if(id15*MPI_MAX<1000000000000000000ll/MPI_MAX && 1<=id9){
			id15=id15*MPI_MAX+mpi_num.MPI_VALUE[--id9];
		}

		while(!mpi_abs_gt(mpi_rem,mpi_num)){
			li id20=sz(mpi_rem.MPI_VALUE)-1;
			li id18=mpi_rem.MPI_VALUE[id20];
			while(id18<id15){
				id18=id18*MPI_MAX+mpi_rem.MPI_VALUE[--id20];
			}
			li mpi_tmp=id18/id15;
			li id5=id20-id9;
			while(!mpi_can_sub(mpi_rem,mpi_num,mpi_tmp,id5)) mpi_tmp--;
			if(mpi_tmp==0){
				id18=id18*MPI_MAX+mpi_rem.MPI_VALUE[--id20];
				mpi_tmp=id18/id15;
				id5=id20-id9;
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
	
	
	MPI operator/(const MPI &mpi_var)const{
		bool b0=MPI_SIGN,b1=mpi_var.MPI_SIGN;
		if(!b0&&!b1) return mpi_abs_div(*this,mpi_var,true);
		if( b0&& b1) return mpi_abs_div(*this,mpi_var,true);
		MPI mpi_res=mpi_abs_div(*this,mpi_var,true);
		mpi_res.MPI_SIGN=!mpi_res.MPI_SIGN;
		return mpi_res;
	}
	
	MPI operator%(const MPI &mpi_var)const{
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








class IRN{
public:
	MPI id0;
	MPI id21;
	bool id2;
		
	IRN(){
		id0=0;
		id21=1;
		id2=false;
	}
	IRN(string id17,string id22){
		id0=id17;
		id21=id22;
		id2=false;
		if(id0<0) id2=!id2;
		if(id21<0) id2=!id2;
		id0.MPI_SIGN=false;
		id21.MPI_SIGN=false;
		irn_reduct(*this);
	}
	IRN(li id23,li id1){
		id0=id23;
		id21=id1;
		id2=false;
		if(id0<0) id2=!id2;
		if(id21<0) id2=!id2;
		id0.MPI_SIGN=false;
		id21.MPI_SIGN=false;
		irn_reduct(*this);
	}
	IRN(li id12){
		id0=id12;
		id21=1;
		id2=false;
	}
	IRN(string id4){
		id0=id4;
		id21=1;
		id2=false;
	}
	
	string to_string() const{ 
		if(id2 && id0!=0) return "-"+id0.to_string()+"/"+id21.to_string();
		return id0.to_string()+"/"+id21.to_string();
	}
		
	static MPI irn_mpi_gcd(MPI mpi0,MPI mpi1){
		MPI mpi_res=1;
		if(mpi0==0 || mpi1==0) return MPI(1);
		for(MPI i=2;i*i<=min(mpi0,mpi1);i++){
			while(true){
				if(mpi0%i!=0) break;
				if(mpi1%i!=0) break;
				mpi0/=i;
				mpi1/=i;
				mpi_res*=i;
			}
			while(mpi0%i==0) mpi0/=i;
			while(mpi1%i==0) mpi1/=i;
		}
		if(mpi0%min(mpi0,mpi1)!=0) return mpi_res;
		if(mpi1%min(mpi0,mpi1)!=0) return mpi_res;
		return mpi_res*min(mpi0,mpi1);
	}
				
	void irn_reduct(IRN &id6)const{
		if(id6.id0==0){ id6.id21=1; id6.id2=false; return ; }
		if(id6.id0.MPI_SIGN) id6.id2=!id6.id2;
		if(id6.id21.MPI_SIGN) id6.id2=!id6.id2;
		id6.id0.MPI_SIGN=false;
		id6.id21.MPI_SIGN=false;
		MPI id10=irn_mpi_gcd(id6.id21,id6.id0);
		id6.id21/=id10;
		id6.id0/=id10;
	}
	
	IRN irn_mul(const IRN &id8,const IRN &id16)const{
		IRN id13(1,1);
		MPI id10=irn_mpi_gcd(id8.id0,id16.id21);
		id13.id0=id8.id0/id10;
		id13.id21=id16.id21/id10;
		id10=irn_mpi_gcd(id8.id21,id16.id0);
		id13.id0*=id16.id0/id10;
		id13.id21*=id8.id21/id10;
		if(id16.id2) id13.id2=!id13.id2;
		if(id8.id2) id13.id2=!id13.id2;
		if(id13.id0==0){ id13.id21=1; id13.id2=false; }
		return id13;
	}
	
	IRN irn_div(const IRN &id8,const IRN &id16)const{
		IRN id13(1,1);
		MPI id10=irn_mpi_gcd(id8.id0,id16.id0);
		id13.id0=id8.id0/id10;
		id13.id21=id16.id0/id10;
		id10=irn_mpi_gcd(id8.id21,id16.id21);
		id13.id0*=id16.id21/id10;
		id13.id21*=id8.id21/id10;
		if(id16.id2) id13.id2=!id13.id2;
		if(id8.id2) id13.id2=!id13.id2;
		if(id13.id0==0){ id13.id21=1; id13.id2=false; }
		return id13;
	}
	
	IRN irn_abs_add(const IRN &id8,const IRN &id16)const{
		IRN id13(0);
		if(id8.id21==id16.id21){
			id13.id0=id8.id0+id16.id0;
			id13.id21=id8.id21;
			irn_reduct(id13);
			return id13;
		}
		id13.id21=id8.id21*id16.id21;
		id13.id0=id8.id0*id16.id21;
		id13.id0+=id16.id0*id8.id21;
		irn_reduct(id13);
		return id13;
	}
	
	IRN irn_abs_sub(const IRN &id8,const IRN &id16)const{
		IRN id13(0);
		if(id8.id21==id16.id21){
			id13.id0=id8.id0-id16.id0;
			id13.id21=id8.id21;
			irn_reduct(id13);
			return id13;
		}
		id13.id21=id8.id21*id16.id21;
		id13.id0=id8.id0*id16.id21;
		id13.id0-=id16.id0*id8.id21;
		irn_reduct(id13);
		return id13;
	}
	
	IRN irn_add(const IRN &id8,const IRN &id16)const{
		if( id8.id2&& id16.id2){
			IRN id13=irn_abs_add(id8,id16);
			id13.id2=!id13.id2;
			return id13;
		}
		if(!id8.id2&&!id16.id2) return irn_abs_add(id8,id16);
		IRN id13;
		if(!id8.id2&& id16.id2) id13=irn_abs_sub(id8,id16);
		if( id8.id2&&!id16.id2) id13=irn_abs_sub(id16,id8);
		if(id13.id0.MPI_SIGN){
			id13.id0.MPI_SIGN=false;
			id13.id2=true;
		}
		return id13;
	}
	
	IRN irn_sub(const IRN &id8,const IRN &id16)const{
		if(!id8.id2&& id16.id2) return irn_abs_add(id8,id16);
		if( id8.id2&&!id16.id2){
			IRN id13=irn_abs_add(id8,id16);
			id13.id2=!id13.id2;
			return id13;
		}
		IRN id13;
		if( id8.id2&& id16.id2){
			id13=irn_abs_sub(id8,id16);
			id13.id2=!id13.id2;
		}
		if(!id8.id2&&!id16.id2){
			id13=irn_abs_sub(id8,id16);
		}
		if(id13.id0.MPI_SIGN){
			id13.id0.MPI_SIGN=false;
			id13.id2=true;
		}
		return id13;
	}
	
	bool operator<(const IRN &id6)const{
		if(this->id0==0 && id6.id0==0) return false;
		bool b0=this->id2,b1=id6.id2;
		if( b0&&!b1) return true;
		if(!b1&& b0) return false;
		MPI left=this->id0*id6.id21;
		MPI right=id6.id0*this->id21;
		if(!b0&&!b1) return left<right;
		return right<left;
	}
	
	bool operator>(const IRN &id6)const{
		if(this->id0==0 && id6.id0==0) return false;
		bool b0=this->id2,b1=id6.id2;
		if( b0&&!b1) return false;
		if(!b0&& b1) return true;
		MPI left=this->id0*id6.id21;
		MPI right=id6.id0*this->id21;
		if(!b0&&!b1) return left>right;
		return right<left;
	}
	
	bool operator==(const IRN &id6)const{
		if(this->id0==0 && id6.id0==0) return true;
		if(this->id2 && !id6.id2) return false;
		if(!this->id2&&  id6.id2) return false;
		return this->id0==id6.id0 && this->id21==id6.id21;
	}
	
	IRN operator+(const IRN &id6)const{ return irn_add(*this,id6); }
	IRN operator-(const IRN &id6)const{ return irn_sub(*this,id6); }
	IRN operator/(const IRN &id6)const{ return irn_div(*this,id6); }
	IRN operator*(const IRN &id6)const{ return irn_mul(*this,id6); }
	void operator+=(const IRN &id6){ *this=*this+id6; }
	void operator-=(const IRN &id6){ *this=*this-id6; }
	void operator*=(const IRN &id6){ *this=*this*id6; }
	void operator/=(const IRN &id6){ *this=*this/id6; }
	IRN operator<=(const IRN &id6)const{ return !(id6<*this); }
	IRN operator>=(const IRN &id6)const{ return !(*this<id6); }
	IRN operator!=(const IRN &id6)const{ return !(*this==id6); }
	
	friend std::ostream& operator<<(std::ostream& os,const IRN &id6){
		os<<id6.to_string();
		return os;
	}
private:
};
























inline bool gt(double d0,double d1){
	if(!RELATIVE_ERROR_ENABLED) return d0<d1-EPS;
	if(0<d1) return d0<(1.0-RPS)*d1;
	return d0<(1.0+RPS)*d1;
}


struct P{
	double x,y;
	P(){ }
	P(double _x,double _y){ x=_x; y=_y; }
	bool operator<(const P &p)const{
		if(eq(x,p.x)) return gt(y,p.y);
		return gt(x,p.x);
	}
	P operator+(P p){ return P(x+p.x,y+p.y); }
	P operator-(P p){ return P(x-p.x,y-p.y); }
	P operator*(double d){ return P(x*d,y*d); }
	P operator/(double d){ return P(x/d,y/d); }
	bool operator==(const P &p)const{ return (eq(x,p.x)&&eq(y,p.y)); }
};





inline P intersect(P a0,P a1,P b0,P b1){
	P a=a0-a1,b=b0-b1,res(INF,INF);
	if(abs(a.x*b.y-a.y*b.x)<EPS) return res; 

	res.x=(a.x*b.x*(a0.y-b0.y)+a.x*b.y*b0.x-a.y*b.x*a0.x)/(a.x*b.y-a.y*b.x);
	res.y=(a.y*b.y*(a0.x-b0.x)+a.y*b.x*b0.y-a.x*b.y*a0.y)/(a.y*b.x-a.x*b.y);
	return res;
}
inline double distPL(P l0,P l1,P p){
	if(l0==l1) return dist(l0,p); 

	double dx=l0.x-l1.x;
	double dy=l0.y-l1.y;
	return abs(dy*(l0.x-p.x)-dx*(l0.y-p.y))/sqrt(dy*dy+dx*dx);
}
inline double area3(P p0,P p1,P p2){
	P v1=p1-p0,v2=p2-p0;
	return abs(v1.x*v2.y-v1.y*v2.x)/2.0;
}
inline P circle3(P p0,P p1,P p2){
	P res(INF,INF);
	if(p0==p1) return (p0+p2)/2.0;
	if(p0==p2) return (p0+p2)/2.0;
	if(p1==p2) return (p1+p2)/2.0;
	P mid1=(p1+p0)/2.0;
	P mid2=(p2+p0)/2.0;
	P _mid1=mid1+P((p1-p0).y,(p0-p1).x);
	P _mid2=mid2+P((p2-p0).y,(p0-p2).x);
	return intersect(mid1,_mid1,mid2,_mid2);
}

inline bool rotate_dir(P base,P p0,P p1){
	p0=p0-base; p1=p1+base;
	return 0<=p0.x*p1.y-p0.y*p1.x;
}

vector<P> id19(vector<P> points){


	li k=0;
	if(sz(points)<=1) return points;
	sort(points.begin(),points.end());
	vector<P> res(2*sz(points));
	for(li i=0;i<sz(points);res[k++]=points[i++]){
		while(k>=2 && rotate_dir(res[k-2],res[k-1],points[i])) k--;
	}
	for(li i=sz(points)-2,t=k+1;i>=0;res[k++]=points[i--]){
		while(k>=t && !rotate_dir(res[k-2],res[k-1],points[i])) k--;
	}
	res.resize(k-1);
	return res;
}






double h,f;
double cal0(double left,double right){
	if(left<0) return cal0(-right,-left); 
	P U(0, f); P U0(left, h); P U1(right, h);
	P D(0,-f); P D0(left,-h); P D1(right,-h);
	P ULbar(-1, h); P URbar(1, h);
	P DLbar(-1,-h); P DRbar(1,-h);
	P U2=intersect(ULbar,URbar,D,D0); P U3=intersect(ULbar,URbar,D,D1);
	P D2=intersect(DLbar,DRbar,U,U0); P D3=intersect(DLbar,DRbar,U,U1);
	P ML=intersect(D,D0,U,U0); P MU=intersect(D,D0,U,U1);
	P MR=intersect(D,D1,U,U1); P MD=intersect(D,D1,U,U0);
	double res=0;
	res+=area3(U,D2,D3);
	res+=area3(D,U2,U3);
	res-=area3(U,U0,U1);
	res-=area3(D,D0,D1);
	res-=area3(ML,MU,MD);
	res-=area3(MR,MU,MD);
	if(URbar.y<MU.y) res+=area3(MU,U1,U2);
	if(DRbar.y>MD.y) res+=area3(MD,D1,D2);
	return res;
}

double cal1(double left,double right,double l,double r){
	P U(0, f); P U0(left, h); P U1(right, h);
	P D(0,-f); P D0(left,-h); P D1(right,-h);
	P ULbar(-1, h); P URbar(1, h);
	P DLbar(-1,-h); P DRbar(1,-h);
	P U2=intersect(ULbar,URbar,D,D0); P U3=intersect(ULbar,URbar,D,D1);
	P D2=intersect(DLbar,DRbar,U,U0); P D3=intersect(DLbar,DRbar,U,U1);
	P ML=intersect(D,D0,U,U0); P MU=intersect(D,D0,U,U1);
	P MR=intersect(D,D1,U,U1); P MD=intersect(D,D1,U,U0);
	P LEFT(l,h);
	P RIGHT(r,h);
	double res=0;
	if(LEFT<U3) res+=area3(LEFT,U3,intersect(U,LEFT,D,U3));
	if(RIGHT<U3) res-=area3(RIGHT,U3,intersect(U,RIGHT,D,U3));
	if(LEFT<U2) res-=area3(LEFT,U2,intersect(U,LEFT,D,U2));
	if(RIGHT<U2) res+=area3(RIGHT,U2,intersect(U,RIGHT,D,U2));
	return res*2;
}


int main(){
	li n;
	double LEFT[MAX],RIGHT[MAX],res=0;
	cin>>n>>h>>f;
	rep(i,n) cin>>LEFT[i]>>RIGHT[i];
	vector<pair<double,double> > minu,plus;
	rep(i,n){
		if(LEFT[i]==0) LEFT[i]=EPS;
		if(RIGHT[i]==0) RIGHT[i]=-EPS;
		if(LEFT[i]<0 && 0<RIGHT[i]){
			minu.pb(make_pair(EPS,-LEFT[i])); 
			plus.pb(make_pair(EPS,RIGHT[i])); 
		}
		if(RIGHT[i]<0) minu.pb(make_pair(-RIGHT[i],-LEFT[i]));
		if(0<LEFT[i]) plus.pb(make_pair(LEFT[i],RIGHT[i]));
	}
	sort(minu.begin(),minu.end());
	sort(plus.begin(),plus.end());
	rep(i,sz(minu)) res+=cal0(minu[i].first,minu[i].second);
	rep(i,sz(plus)) res+=cal0(plus[i].first,plus[i].second);
	rep(i,sz(minu))rep(j,i){
		res-=cal1(minu[j].first,minu[j].second,minu[i].first,minu[i].second);
	}
	rep(i,sz(plus))rep(j,i){
		res-=cal1(plus[j].first,plus[j].second,plus[i].first,plus[i].second);
	}
	printf("%0.20lf\n",res);
}
