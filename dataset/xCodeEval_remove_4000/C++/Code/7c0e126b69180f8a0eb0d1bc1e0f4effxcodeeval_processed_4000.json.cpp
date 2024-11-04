














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
			li id22=(i<sz(mpi1.MPI_VALUE))?(mpi1.MPI_VALUE[i]):0;
			li mpi_t=id11+id22+carry;
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
			li id19=sz(mpi_rem.MPI_VALUE)-1;
			li id18=mpi_rem.MPI_VALUE[id19];
			while(id18<id15){
				id18=id18*MPI_MAX+mpi_rem.MPI_VALUE[--id19];
			}
			li mpi_tmp=id18/id15;
			li id5=id19-id9;
			while(!mpi_can_sub(mpi_rem,mpi_num,mpi_tmp,id5)) mpi_tmp--;
			if(mpi_tmp==0){
				id18=id18*MPI_MAX+mpi_rem.MPI_VALUE[--id19];
				mpi_tmp=id18/id15;
				id5=id19-id9;
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
	MPI id20;
	bool id2;
		
	IRN(){
		id0=0;
		id20=1;
		id2=false;
	}
	IRN(string id17,string id23){
		id0=id17;
		id20=id23;
		id2=false;
		if(id0<0) id2=!id2;
		if(id20<0) id2=!id2;
		id0.MPI_SIGN=false;
		id20.MPI_SIGN=false;
		irn_reduct(*this);
	}
	IRN(li id21,li id1){
		id0=id21;
		id20=id1;
		id2=false;
		if(id0<0) id2=!id2;
		if(id20<0) id2=!id2;
		id0.MPI_SIGN=false;
		id20.MPI_SIGN=false;
		irn_reduct(*this);
	}
	IRN(li id12){
		id0=id12;
		id20=1;
		id2=false;
	}
	IRN(string id4){
		id0=id4;
		id20=1;
		id2=false;
	}
	
	string to_string() const{ 
		if(id2 && id0!=0) return "-"+id0.to_string()+"/"+id20.to_string();
		return id0.to_string()+"/"+id20.to_string();
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
		if(id6.id0==0){ id6.id20=1; id6.id2=false; return ; }
		if(id6.id0.MPI_SIGN) id6.id2=!id6.id2;
		if(id6.id20.MPI_SIGN) id6.id2=!id6.id2;
		id6.id0.MPI_SIGN=false;
		id6.id20.MPI_SIGN=false;
		MPI id10=irn_mpi_gcd(id6.id20,id6.id0);
		id6.id20/=id10;
		id6.id0/=id10;
	}
	
	IRN irn_mul(const IRN &id8,const IRN &id16)const{
		IRN id13(1,1);
		MPI id10=irn_mpi_gcd(id8.id0,id16.id20);
		id13.id0=id8.id0/id10;
		id13.id20=id16.id20/id10;
		id10=irn_mpi_gcd(id8.id20,id16.id0);
		id13.id0*=id16.id0/id10;
		id13.id20*=id8.id20/id10;
		if(id16.id2) id13.id2=!id13.id2;
		if(id8.id2) id13.id2=!id13.id2;
		if(id13.id0==0){ id13.id20=1; id13.id2=false; }
		return id13;
	}
	
	IRN irn_div(const IRN &id8,const IRN &id16)const{
		IRN id13(1,1);
		MPI id10=irn_mpi_gcd(id8.id0,id16.id0);
		id13.id0=id8.id0/id10;
		id13.id20=id16.id0/id10;
		id10=irn_mpi_gcd(id8.id20,id16.id20);
		id13.id0*=id16.id20/id10;
		id13.id20*=id8.id20/id10;
		if(id16.id2) id13.id2=!id13.id2;
		if(id8.id2) id13.id2=!id13.id2;
		if(id13.id0==0){ id13.id20=1; id13.id2=false; }
		return id13;
	}
	
	IRN irn_abs_add(const IRN &id8,const IRN &id16)const{
		IRN id13(0);
		if(id8.id20==id16.id20){
			id13.id0=id8.id0+id16.id0;
			id13.id20=id8.id20;
			irn_reduct(id13);
			return id13;
		}
		id13.id20=id8.id20*id16.id20;
		id13.id0=id8.id0*id16.id20;
		id13.id0+=id16.id0*id8.id20;
		irn_reduct(id13);
		return id13;
	}
	
	IRN irn_abs_sub(const IRN &id8,const IRN &id16)const{
		IRN id13(0);
		if(id8.id20==id16.id20){
			id13.id0=id8.id0-id16.id0;
			id13.id20=id8.id20;
			irn_reduct(id13);
			return id13;
		}
		id13.id20=id8.id20*id16.id20;
		id13.id0=id8.id0*id16.id20;
		id13.id0-=id16.id0*id8.id20;
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
		MPI left=this->id0*id6.id20;
		MPI right=id6.id0*this->id20;
		if(!b0&&!b1) return left<right;
		return right<left;
	}
	
	bool operator>(const IRN &id6)const{
		if(this->id0==0 && id6.id0==0) return false;
		bool b0=this->id2,b1=id6.id2;
		if( b0&&!b1) return false;
		if(!b0&& b1) return true;
		MPI left=this->id0*id6.id20;
		MPI right=id6.id0*this->id20;
		if(!b0&&!b1) return left>right;
		return right<left;
	}
	
	bool operator==(const IRN &id6)const{
		if(this->id0==0 && id6.id0==0) return true;
		if(this->id2 && !id6.id2) return false;
		if(!this->id2&&  id6.id2) return false;
		return this->id0==id6.id0 && this->id20==id6.id20;
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
















li dp[MAX][bit(MAX-1)];
string base[200005];

li cost(string str0,string str1){
	for(li i=sz(str0);i;i--){
		if(str0.substr(sz(str0)-i,i)==str1.substr(0,i)) return sz(str0)-i;
	}
	return sz(str0);
}

li cost(li t0,li t1,li len){
	for(li i=len;i;i--){
		if((t0>>(len-i))==t1%bit(i)) return len-i;
	}
	return len;
}

li con(string str){
	li res=0;
	rep(i,sz(str))if(str[i]=='1') res|=bit(i);
	return res;
}

int main(){
	li n;
	cin>>n;
	rep(i,n) cin>>base[i];
	rep(i,MAX)rep(j,bit(MAX-1)) dp[i][j]=INF;
	dp[0][0]=0;
	li len=sz(base[0]);
	li all=len;
	rep(pos,n)if(pos){
		li num0=0,num1=0;
		rep(i,len)if(base[pos][i]=='1') num0|=bit(i);
		rep(i,len)if(base[pos-1][i]=='1') num1|=bit(i);
		li C=cost(num1,num0,len);
		all+=C;
		li best=INF;
		for(li i=0;i<=len;i++){
			best=min(best,dp[i][num0%bit(i)]+(len-i)-C);
		}
		for(li i=0;i<=len;i++){	
			dp[i][num1>>(len-i)]=min(dp[i][num1>>(len-i)],best);
		}
	}
	li res=all;
	rep(i,MAX)rep(j,bit(MAX-1)) res=min(res,all+dp[i][j]);
	cout<<res<<endl;
}
