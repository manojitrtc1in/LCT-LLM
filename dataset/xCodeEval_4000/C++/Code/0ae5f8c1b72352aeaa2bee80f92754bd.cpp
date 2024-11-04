#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define li       	long long int
#define rep(i,to)	for(li i=0;i<((li)(to));i++)
#define pb       	push_back
#define sz(v)    	((li)(v).size())
#define bit(n)   	(1ll<<(li)(n))
















class MPI{
#define MPI_DIGIT 6
#define MPI_MAX 1000000
public:
	vector<li> MPI_VALUE;
	bool MPI_SIGN;
	
	MPI(const string &mpi_s){
		MPI_SIGN=false;
		if(sz(mpi_s)){
			if(mpi_s[0]=='-') MPI_SIGN=true;
			for(li i=sz(mpi_s)-1;((mpi_s[0]=='-')?1:0)<=i;i-=MPI_DIGIT){
				li mpi_sum=0;
				li mpi_base=1;
				rep(j,MPI_DIGIT)if(((mpi_s[0]=='-')?1:0)<=i-j){
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
	
	MPI(bool mpi_need0,bool mpi_need1){
		MPI_SIGN=false;
	}

	MPI(){
		MPI_SIGN=false;
		MPI_VALUE.pb(0);
	}
	
	string to_string() const{
		string mpi_res="";
		li mpi_p10[MPI_DIGIT+1];
		rep(i,MPI_DIGIT+1) mpi_p10[i]=(i)?(mpi_p10[i-1]*10):1;
		for(li i=sz(MPI_VALUE)-1;0<=i;i--)rep(j,MPI_DIGIT){
			li mpi_tmp=(MPI_VALUE[i]%mpi_p10[MPI_DIGIT-j])/mpi_p10[MPI_DIGIT-j-1];
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
		li mpi_res=(sz(MPI_VALUE)-1)*MPI_DIGIT;
		li mpi_tmp=MPI_VALUE.back();
		while(mpi_tmp){ mpi_res++; mpi_tmp/=10; }
		return mpi_res;
	}
	
	static MPI mpi_abs_add(const MPI &mpi0,const MPI &mpi1){
		MPI mpi_res(false,false);
		li carry=0;
		rep(i,max(sz(mpi0.MPI_VALUE),sz(mpi1.MPI_VALUE))){
			li mpi_t0=(i<sz(mpi0.MPI_VALUE))?(mpi0.MPI_VALUE[i]):0;
			li mpi_t1=(i<sz(mpi1.MPI_VALUE))?(mpi1.MPI_VALUE[i]):0;
			li mpi_t=mpi_t0+mpi_t1+carry;
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
			li mpi_dif=(mpi_tmp-mpi_from.MPI_VALUE[i+mpi_shift]);
			if(mpi_dif<0) carry=0;
			else carry=((mpi_dif%MPI_MAX)?1:0)+mpi_dif/MPI_MAX;
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
		li mpi_num_pos=sz(mpi_num.MPI_VALUE)-1;
		li mpi_num_n=mpi_num.MPI_VALUE[mpi_num_pos];

		if(mpi_num_n*MPI_MAX<1000000000000000000ll/MPI_MAX && 1<=mpi_num_pos){
			mpi_num_n=mpi_num_n*MPI_MAX+mpi_num.MPI_VALUE[--mpi_num_pos];
		}

		while(!mpi_abs_gt(mpi_rem,mpi_num)){
			li mpi_rem_pos=sz(mpi_rem.MPI_VALUE)-1;
			li mpi_rem_n=mpi_rem.MPI_VALUE[mpi_rem_pos];
			while(mpi_rem_n<mpi_num_n){
				mpi_rem_n=mpi_rem_n*MPI_MAX+mpi_rem.MPI_VALUE[--mpi_rem_pos];
			}
			li mpi_tmp=mpi_rem_n/mpi_num_n;
			li mpi_dif=mpi_rem_pos-mpi_num_pos;
			while(!mpi_can_sub(mpi_rem,mpi_num,mpi_tmp,mpi_dif)) mpi_tmp--;
			if(mpi_tmp==0){
				mpi_rem_n=mpi_rem_n*MPI_MAX+mpi_rem.MPI_VALUE[--mpi_rem_pos];
				mpi_tmp=mpi_rem_n/mpi_num_n;
				mpi_dif=mpi_rem_pos-mpi_num_pos;
				while(!mpi_can_sub(mpi_rem,mpi_num,mpi_tmp,mpi_dif)) mpi_tmp--;
			}
			mpi_subst(mpi_rem,mpi_num,mpi_tmp,mpi_dif);
			mpi_ans.MPI_VALUE[mpi_dif]+=mpi_tmp;
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
	MPI IRN_DEN;
	MPI IRN_NUM;
	bool IRN_SIGN;
		
	IRN(){
		IRN_DEN=0;
		IRN_NUM=1;
		IRN_SIGN=false;
	}
	IRN(string irn_str0,string irn_str1){
		IRN_DEN=irn_str0;
		IRN_NUM=irn_str1;
		IRN_SIGN=false;
		if(IRN_DEN<0) IRN_SIGN=!IRN_SIGN;
		if(IRN_NUM<0) IRN_SIGN=!IRN_SIGN;
		IRN_DEN.MPI_SIGN=false;
		IRN_NUM.MPI_SIGN=false;
		irn_reduct(*this);
	}
	IRN(li irn_li0,li irn_li1){
		IRN_DEN=irn_li0;
		IRN_NUM=irn_li1;
		IRN_SIGN=false;
		if(IRN_DEN<0) IRN_SIGN=!IRN_SIGN;
		if(IRN_NUM<0) IRN_SIGN=!IRN_SIGN;
		IRN_DEN.MPI_SIGN=false;
		IRN_NUM.MPI_SIGN=false;
		irn_reduct(*this);
	}
	IRN(li irn_li){
		IRN_DEN=irn_li;
		IRN_NUM=1;
		IRN_SIGN=false;
	}
	IRN(string irn_str){
		IRN_DEN=irn_str;
		IRN_NUM=1;
		IRN_SIGN=false;
	}
	
	string to_string() const{ 
		if(IRN_SIGN && IRN_DEN!=0) return "-"+IRN_DEN.to_string()+"/"+IRN_NUM.to_string();
		return IRN_DEN.to_string()+"/"+IRN_NUM.to_string();
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
				
	void irn_reduct(IRN &irn_var)const{
		if(irn_var.IRN_DEN==0){ irn_var.IRN_NUM=1; irn_var.IRN_SIGN=false; return ; }
		if(irn_var.IRN_DEN.MPI_SIGN) irn_var.IRN_SIGN=!irn_var.IRN_SIGN;
		if(irn_var.IRN_NUM.MPI_SIGN) irn_var.IRN_SIGN=!irn_var.IRN_SIGN;
		irn_var.IRN_DEN.MPI_SIGN=false;
		irn_var.IRN_NUM.MPI_SIGN=false;
		MPI irn_t=irn_mpi_gcd(irn_var.IRN_NUM,irn_var.IRN_DEN);
		irn_var.IRN_NUM/=irn_t;
		irn_var.IRN_DEN/=irn_t;
	}
	
	IRN irn_mul(const IRN &irn0,const IRN &irn1)const{
		IRN irn_res(1,1);
		MPI irn_t=irn_mpi_gcd(irn0.IRN_DEN,irn1.IRN_NUM);
		irn_res.IRN_DEN=irn0.IRN_DEN/irn_t;
		irn_res.IRN_NUM=irn1.IRN_NUM/irn_t;
		irn_t=irn_mpi_gcd(irn0.IRN_NUM,irn1.IRN_DEN);
		irn_res.IRN_DEN*=irn1.IRN_DEN/irn_t;
		irn_res.IRN_NUM*=irn0.IRN_NUM/irn_t;
		if(irn1.IRN_SIGN) irn_res.IRN_SIGN=!irn_res.IRN_SIGN;
		if(irn0.IRN_SIGN) irn_res.IRN_SIGN=!irn_res.IRN_SIGN;
		if(irn_res.IRN_DEN==0){ irn_res.IRN_NUM=1; irn_res.IRN_SIGN=false; }
		return irn_res;
	}
	
	IRN irn_div(const IRN &irn0,const IRN &irn1)const{
		IRN irn_res(1,1);
		MPI irn_t=irn_mpi_gcd(irn0.IRN_DEN,irn1.IRN_DEN);
		irn_res.IRN_DEN=irn0.IRN_DEN/irn_t;
		irn_res.IRN_NUM=irn1.IRN_DEN/irn_t;
		irn_t=irn_mpi_gcd(irn0.IRN_NUM,irn1.IRN_NUM);
		irn_res.IRN_DEN*=irn1.IRN_NUM/irn_t;
		irn_res.IRN_NUM*=irn0.IRN_NUM/irn_t;
		if(irn1.IRN_SIGN) irn_res.IRN_SIGN=!irn_res.IRN_SIGN;
		if(irn0.IRN_SIGN) irn_res.IRN_SIGN=!irn_res.IRN_SIGN;
		if(irn_res.IRN_DEN==0){ irn_res.IRN_NUM=1; irn_res.IRN_SIGN=false; }
		return irn_res;
	}
	
	IRN irn_abs_add(const IRN &irn0,const IRN &irn1)const{
		IRN irn_res(0);
		if(irn0.IRN_NUM==irn1.IRN_NUM){
			irn_res.IRN_DEN=irn0.IRN_DEN+irn1.IRN_DEN;
			irn_res.IRN_NUM=irn0.IRN_NUM;
			irn_reduct(irn_res);
			return irn_res;
		}
		irn_res.IRN_NUM=irn0.IRN_NUM*irn1.IRN_NUM;
		irn_res.IRN_DEN=irn0.IRN_DEN*irn1.IRN_NUM;
		irn_res.IRN_DEN+=irn1.IRN_DEN*irn0.IRN_NUM;
		irn_reduct(irn_res);
		return irn_res;
	}
	
	IRN irn_abs_sub(const IRN &irn0,const IRN &irn1)const{
		IRN irn_res(0);
		if(irn0.IRN_NUM==irn1.IRN_NUM){
			irn_res.IRN_DEN=irn0.IRN_DEN-irn1.IRN_DEN;
			irn_res.IRN_NUM=irn0.IRN_NUM;
			irn_reduct(irn_res);
			return irn_res;
		}
		irn_res.IRN_NUM=irn0.IRN_NUM*irn1.IRN_NUM;
		irn_res.IRN_DEN=irn0.IRN_DEN*irn1.IRN_NUM;
		irn_res.IRN_DEN-=irn1.IRN_DEN*irn0.IRN_NUM;
		irn_reduct(irn_res);
		return irn_res;
	}
	
	IRN irn_add(const IRN &irn0,const IRN &irn1)const{
		if( irn0.IRN_SIGN&& irn1.IRN_SIGN){
			IRN irn_res=irn_abs_add(irn0,irn1);
			irn_res.IRN_SIGN=!irn_res.IRN_SIGN;
			return irn_res;
		}
		if(!irn0.IRN_SIGN&&!irn1.IRN_SIGN) return irn_abs_add(irn0,irn1);
		IRN irn_res;
		if(!irn0.IRN_SIGN&& irn1.IRN_SIGN) irn_res=irn_abs_sub(irn0,irn1);
		if( irn0.IRN_SIGN&&!irn1.IRN_SIGN) irn_res=irn_abs_sub(irn1,irn0);
		if(irn_res.IRN_DEN.MPI_SIGN){
			irn_res.IRN_DEN.MPI_SIGN=false;
			irn_res.IRN_SIGN=true;
		}
		return irn_res;
	}
	
	IRN irn_sub(const IRN &irn0,const IRN &irn1)const{
		if(!irn0.IRN_SIGN&& irn1.IRN_SIGN) return irn_abs_add(irn0,irn1);
		if( irn0.IRN_SIGN&&!irn1.IRN_SIGN){
			IRN irn_res=irn_abs_add(irn0,irn1);
			irn_res.IRN_SIGN=!irn_res.IRN_SIGN;
			return irn_res;
		}
		IRN irn_res;
		if( irn0.IRN_SIGN&& irn1.IRN_SIGN){
			irn_res=irn_abs_sub(irn0,irn1);
			irn_res.IRN_SIGN=!irn_res.IRN_SIGN;
		}
		if(!irn0.IRN_SIGN&&!irn1.IRN_SIGN){
			irn_res=irn_abs_sub(irn0,irn1);
		}
		if(irn_res.IRN_DEN.MPI_SIGN){
			irn_res.IRN_DEN.MPI_SIGN=false;
			irn_res.IRN_SIGN=true;
		}
		return irn_res;
	}
	
	bool operator<(const IRN &irn_var)const{
		if(this->IRN_DEN==0 && irn_var.IRN_DEN==0) return false;
		bool b0=this->IRN_SIGN,b1=irn_var.IRN_SIGN;
		if( b0&&!b1) return true;
		if(!b1&& b0) return false;
		MPI left=this->IRN_DEN*irn_var.IRN_NUM;
		MPI right=irn_var.IRN_DEN*this->IRN_NUM;
		if(!b0&&!b1) return left<right;
		return right<left;
	}
	
	bool operator>(const IRN &irn_var)const{
		if(this->IRN_DEN==0 && irn_var.IRN_DEN==0) return false;
		bool b0=this->IRN_SIGN,b1=irn_var.IRN_SIGN;
		if( b0&&!b1) return false;
		if(!b0&& b1) return true;
		MPI left=this->IRN_DEN*irn_var.IRN_NUM;
		MPI right=irn_var.IRN_DEN*this->IRN_NUM;
		if(!b0&&!b1) return left>right;
		return right<left;
	}
	
	bool operator==(const IRN &irn_var)const{
		if(this->IRN_DEN==0 && irn_var.IRN_DEN==0) return true;
		if(this->IRN_SIGN && !irn_var.IRN_SIGN) return false;
		if(!this->IRN_SIGN&&  irn_var.IRN_SIGN) return false;
		return this->IRN_DEN==irn_var.IRN_DEN && this->IRN_NUM==irn_var.IRN_NUM;
	}
	
	IRN operator+(const IRN &irn_var)const{ return irn_add(*this,irn_var); }
	IRN operator-(const IRN &irn_var)const{ return irn_sub(*this,irn_var); }
	IRN operator/(const IRN &irn_var)const{ return irn_div(*this,irn_var); }
	IRN operator*(const IRN &irn_var)const{ return irn_mul(*this,irn_var); }
	void operator+=(const IRN &irn_var){ *this=*this+irn_var; }
	void operator-=(const IRN &irn_var){ *this=*this-irn_var; }
	void operator*=(const IRN &irn_var){ *this=*this*irn_var; }
	void operator/=(const IRN &irn_var){ *this=*this/irn_var; }
	IRN operator<=(const IRN &irn_var)const{ return !(irn_var<*this); }
	IRN operator>=(const IRN &irn_var)const{ return !(*this<irn_var); }
	IRN operator!=(const IRN &irn_var)const{ return !(*this==irn_var); }
	
	friend std::ostream& operator<<(std::ostream& os,const IRN &irn_var){
		os<<irn_var.to_string();
		return os;
	}
private:
};














#define MAX 55
string mp[MAX];
li dx[]={1,0,-1,0};
li dy[]={0,1,0,-1};
int main(){
	li n,m,k,sx,sy,gx,gy;
	cin>>n>>m>>k;
	rep(i,n) cin>>mp[i];
	rep(i,n)rep(j,m)if(mp[i][j]=='S') sx=i,sy=j;
	rep(i,n)rep(j,m)if(mp[i][j]=='T') gx=i,gy=j;
#define P pair<li,pair<li,li> >
#define PP pair<pair<li,string>,P >
#define MP make_pair
	set<pair<li,pair<li,li> > > used;
	priority_queue< PP ,vector< PP >,greater< PP > > q;
	q.push(MP(MP(0,""),MP(0,MP(sx,sy))));
	while(sz(q)){
		li mask=q.top().second.first;
		li x=q.top().second.second.first;
		li y=q.top().second.second.second;
		string str=q.top().first.second;
		q.pop();
		bool ok=true;
		{
			li tmp=mask;
			do{
				if(used.find(MP(tmp,MP(x,y)))!=used.end()) ok=false;
				tmp=(tmp-1)&mask;
			}while(ok && tmp!=mask);
		}
		if(!ok) continue;
		used.insert(MP(mask,MP(x,y)));
		rep(i,4){
			li xx=x+dx[i];
			li yy=y+dy[i];
			if(xx<0 || n<=xx || yy<0 || m<=yy) continue;
			if(mp[xx][yy]=='T'){ cout<<str<<endl; return 0; }
			if(mp[xx][yy]=='S') continue;
			string next=str+string(1,mp[xx][yy]);
			li nmask=mask|bit(mp[xx][yy]-'a');
			if(k<__builtin_popcountll(nmask)) continue;
			q.push(MP(MP(sz(next),next),MP(nmask,MP(xx,yy))));
		}
	}
	cout<<-1<<endl;
}
