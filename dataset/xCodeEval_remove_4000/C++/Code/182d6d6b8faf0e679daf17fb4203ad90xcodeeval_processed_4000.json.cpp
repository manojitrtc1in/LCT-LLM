


















int const MOD=998244353;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}

	constexpr modular(int64_t v):val(int(v%MOD)){
		if(val<0)val+=MOD;
	}

	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}



	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)


	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) { val = int((int64_t)val*m.val%MOD); return *this; }
	modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular constexpr inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	modular constexpr& operator/=(modular m) { return (*this) *= m.inv(); }


	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)

};

unsigned constexpr id2(unsigned x){
	return 31^__builtin_clz(2*x-1);
}
unsigned constexpr revbit(unsigned x){
	x=(x&0x55555555)<<1|((x>>1)&0x55555555);
	x=(x&0x33333333)<<2|((x>>2)&0x33333333);
	x=(x&0x0f0f0f0f)<<4|((x>>4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)<<8|((x>>8)&0x00ff00ff);
	return x>>16|x<<16;
}

void fft(std::vector<modular>& a){
	static auto const roots=[]{
		std::vector<modular> roots={31};
		while(roots.back()!=MOD-1){
			roots.push_back(roots.back()*roots.back());
		}
		return roots;
	}();

	static auto const rootpower=[&]{
		auto const root=roots[0];
		std::vector<modular> rootpower={1};
		do{
			rootpower.push_back(rootpower.back()*root);
		}while(rootpower.back()*root!=1);
		return rootpower;
	}();

	int n=id2((int)a.size());
	assert(a.size()==(1u<<n)); 

	for(unsigned i=1;i<a.size();++i){
		unsigned j=revbit(i)>>(32-n);
		if(i<j)std::swap(a[i],a[j]);
	}

	auto iter=end(roots);
	for(unsigned blocksize=1;blocksize<a.size();blocksize<<=1){
		

		auto const power_step=rootpower.size()/(blocksize*2);
		for(unsigned base=0;base<a.size();base+=blocksize*2){
			

			auto xiter=begin(rootpower);
			for(unsigned i=0;i<blocksize;++i,
					xiter+=power_step 

					){
				auto& even=a[base+i];
				auto& odd=a[base+blocksize+i];
				auto p=*xiter*odd;
				odd=even-p;
				even=even+p;
			}
		}
	}
}

void ifft(std::vector<modular>& a){
	fft(a);
	std::reverse(++a.begin(),a.end());
	modular invn=modular(a.size()).inv();
	for(modular& x:a)x*=invn;
}

using bit_type=char;

struct Poly : std::vector<bit_type>{
	using std::vector<bit_type>::vector;

	void xorsmaller(Poly const& x){
		assert(size()>=x.size());
		std::transform(x.begin(),x.end(),begin(),begin(),[](auto a,auto b){return a^b;});
	}
	Poly operator+=(Poly const& x){
		assert(size()==x.size());
		xorsmaller(x);
		return *this;
	}
	void xoranysize(Poly const& x){
		if(size()<x.size()) resize(x.size());
		xorsmaller(x);
	}

	friend auto id5(Poly a,Poly const& b){ a.xoranysize(b); return a; }

	Poly operator<<=(std::size_t x){
		assert(x>=0 and x<size());
		std::rotate(begin(),end()-x,end());
		return *this;
	}
	Poly slowmul(Poly x)const{ 

		if(empty() or x.empty())return {};
		x.resize(size()+x.size()-1);
		Poly out(x.size());
		unsigned id0=0;
		for(unsigned i=0;i<size();++i)if((*this)[i]){
			x<<=i-id0; 

			id0=i;
			out+=x;
		}
		return out;
	}

	std::vector<modular> fft(std::size_t new_size)const{
		assert(new_size>=size());
		std::vector<modular> a(new_size);
		std::copy(begin(),end(),a.begin());
		::fft(a);
		return a;
	}

	static Poly ifft(std::vector<modular> a,int maxvalue ){
		::ifft(a);
		Poly out(a.size());
		std::transform(a.begin(),a.end(),out.begin(),[&](modular x){
			assert((int)x<=maxvalue);
			return (int)x&1;
		});
		return out;
	}

	Poly fastmul(Poly const& x,std::size_t new_size)const{ 

		auto a=fft(new_size);
		auto b=x.fft(new_size);
		std::transform(a.begin(),a.end(),b.begin(),a.begin(),std::multiplies<modular>{});
		return Poly::ifft(a,(int)std::max(size(),x.size()));
	}

	Poly fastmul(Poly const& x){
		return fastmul(x,1<<id2(unsigned(size()+x.size()-1)));
	}

	Poly fastmulmod(Poly const& x){
		assert(size()==x.size());
		return fastmul(x,size());
	}

	Poly slowmulmod(Poly x)const{ 

		assert(size()==x.size());
		Poly out(size());
		unsigned id0=0;
		for(unsigned i=0;i<size();++i)if((*this)[i]){
			x<<=i-id0;
			id0=i;
			out+=x;
		}
		return out;
	}

	friend auto& operator<<(std::ostream& str,Poly const& p){
		str<<'[';
		for(auto x:p)str<<(int)x;
		return str<<']';
	}

	void simplify(){ while(not empty() and back()==0) pop_back(); }
	friend std::pair<Poly,Poly> id3(Poly a,Poly const& b){ 

		


		auto btop=b.size()-1;
		while(b[btop]==0){
			assert(btop>0);
			--btop;
		}

		a.simplify();
		if(a.size()<b.size()) return {{},std::move(a)};

		Poly quot(a.size()-b.size()+1);
		while(btop<a.size()){
			assert(quot[a.size()-1-btop]==0);
			quot[a.size()-1-btop]=1;

			std::transform(b.rend()-(btop+1),b.rend(),
					a.rbegin(),a.rbegin(),[](auto a,auto b){return a^b;});
			a.simplify();
		}

		

		return {std::move(quot),std::move(a)};
	}

	friend Poly slowinv(Poly x,Poly mod){ 




		using std::move;


		

		Poly a=move(mod),b=move(x);
		Poly ax{},bx{1};
		while(b.simplify(), not b.empty()){
			

			

			

			

			

			auto [q,r]=id3(move(a),b);
			a=move(r);
			ax.xoranysize(bx.slowmul(move(q)));

			std::swap(a,b);
			std::swap(ax,bx);
		}
		a.simplify();
		assert(a.size()==1 and a[0]==1);
		return move(ax);



	}

	friend Poly slowinv(Poly a){ 

		Poly mod(a.size()+1,0); mod.back()=mod[0]=1;
		return slowinv(std::move(a),std::move(mod));
	}

	friend Poly fastinv(Poly const& a){ 

		assert((a.size()&-a.size())==a.size());
		if(a.size()==1){
			assert(a[0]==1);
			return a;
		}

		int const NN=int(a.size()/2);

		Poly a_l(a.begin(),a.begin()+NN);
		std::transform(a.begin()+NN,a.end(),a_l.begin(),a_l.begin(),[](auto a,auto b){return a^b;});
		


		auto inv_l=fastinv(std::move(a_l)); 


		

		auto id4=a.fastmul(inv_l,a.size()); 

		id4[0]=not id4[0];
		assert(std::equal(id4.begin()+NN,id4.end(), id4.begin())); 


		id4.resize(NN); 

		auto inv_h=id4.fastmul(inv_l,NN);

		{ 

			std::transform(inv_h.begin(),inv_h.end(),
					inv_l.begin(),
					inv_l.begin(), [](auto a,auto b){return a^b;});
			inv_l.insert(inv_l.end(),inv_h.begin(),inv_h.end());
		}
		return inv_l;
	}
};

struct Poly2d : std::vector<Poly>{
	using std::vector<Poly>::vector;
	auto& operator+=(Poly2d const& x){
		assert(x.size()==size());
		for(auto i=size();i--;) (*this)[i]+=x[i];
		return *this;
	}
	Poly2d slowmulmod(Poly2d x)const{ 

		assert(size()==x.size());
		Poly2d out(size());
		for(unsigned i=0;i<size();++i)
		for(unsigned j=0;j<x.size();++j)
			out[(i+j)%out.size()]+=(*this)[i].slowmulmod(x[j]);
		return out;
	}

	std::vector<std::vector<modular>> fft(std::size_t new_size )const{
		assert(size()<=new_size);
		std::vector<std::vector<modular>> out(new_size);
		auto const ncol=(*this)[0].size();
		for(auto& outrow:out) outrow.resize(ncol);

		std::vector<modular> tmp(new_size);
		for(auto col=ncol;col--;){
			std::transform(begin(),end(),tmp.begin(),[col](auto const& x){ return x[col]; });
			std::fill(tmp.begin()+size(),tmp.end(),0);
			::fft(tmp);
			for(auto row=new_size;row--;) out[row][col]=tmp[row];
		}
		for(auto& outrow:out) ::fft(outrow);
		return out;
	}

	static Poly2d ifft(std::vector<std::vector<modular>> a,int maxvalue ){
		std::vector<modular> tmp(a.size());
		for(auto col=a[0].size();col--;){
			std::transform(a.begin(),a.end(),tmp.begin(),[col](auto const& x){ return x[col]; });
			::ifft(tmp);
			for(auto row=a.size();row--;) a[row][col]=tmp[row];
		}

		Poly2d out(a.size());
		std::transform(
				a.begin(),a.end(),
				out.begin(),
				[&](auto& x){return Poly::ifft(std::move(x),maxvalue);});
		return out;
	}

	Poly2d fastmul(Poly2d const& x,std::size_t new_size)const{
		assert((*this)[0].size()==x[0].size());

		auto a=fft(new_size);
		auto b=x.fft(new_size);
		assert(a.size()==new_size and b.size()==new_size);
		for(auto i=a.size();i--;){
			std::transform(a[i].begin(),a[i].end(),b[i].begin(),a[i].begin(),std::multiplies<modular>{});
		}
		return Poly2d::ifft(a,(int)std::max(
					size()*(*this)[0].size(),
					x.size()*x[0].size()
					));
	}

	Poly2d fastmulmod(Poly2d const& x){
		assert(size()==x.size());
		return fastmul(x,size());
	}

	friend Poly2d fastinv(Poly2d const& a){
		assert((a.size()&-a.size())==a.size());
		if(a.size()==1){
			return {fastinv(a[0])};
		}

		int const NN=int(a.size()/2);

		Poly2d a_l(a.begin(),a.begin()+NN);
		for(int i=NN;i--;) a_l[i]+=a[i+NN];
		


		auto inv_l=fastinv(std::move(a_l)); 


		auto id4=a.fastmul(inv_l,a.size()); 

		id4[0][0]=not id4[0][0];
		assert(std::equal(id4.begin()+NN,id4.end(), id4.begin())); 


		id4.resize(NN); 

		assert((int)inv_l.size()==NN);
		auto inv_h=id4.fastmulmod(inv_l);

		{ 

			for(int i=NN;i--;) inv_l[i]+=inv_h[i];
			inv_l.insert(inv_l.end(),inv_h.begin(),inv_h.end());
		}
		return inv_l;
	}

	
};

int main(){
	if(0){
		Poly2d bb {
			{1,0,1,1},
			{0,0,0,0}
		};
		auto bf=bb.fft(2);

		Poly2d cc {
			{1,0,1,1}
		};
		auto cf=cc.fft(2);

		assert(bf==cf);

		__builtin_trap();

		return 0;
	}

	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int nbit;std::cin>>nbit;
	std::vector<std::vector<uint64_t>> a(1<<nbit,std::vector<uint64_t>(1<<nbit));
	for(auto& row:a) for(auto& x:row) std::cin>>x;

	int ncell;std::cin>>ncell;
	Poly2d fig(1<<nbit,Poly(1<<nbit));
	for(int z=ncell;z--;){
		int x,y;
		std::cin>>x>>y;
		--x;--y;
		fig[x][y]=1;
	}

	fig=fastinv(fig);

	auto fft_fig=fig.fft(fig.size());

	std::vector<std::vector<uint64_t>> opval(1<<nbit,std::vector<uint64_t>(1<<nbit));

	for(int bit=0;bit<60;++bit){
		

		Poly2d ab(1<<nbit);

		std::transform(begin(a),end(a),begin(ab),[&](auto rowa){
				Poly rowab(rowa.size());
				std::transform(begin(rowa),end(rowa),begin(rowab),[&](auto x){
						return x>>bit&1;
						});
				return rowab;
				});

		auto fft_ab=ab.fft(ab.size());
		for(auto i=fft_ab.size();i--;){
			std::transform(fft_ab[i].begin(),fft_ab[i].end(),fft_fig[i].begin(),fft_ab[i].begin(),std::multiplies<modular>{});
		}

		ab=Poly2d::ifft(std::move(fft_ab), fft_ab.size()*fft_ab[0].size());

		for(int row=0;row<(1<<nbit);++row)
			std::transform(begin(opval[row]),end(opval[row]),begin(ab[row]),begin(opval[row]),
					[&](auto id1,auto ab_item){
						assert(0<=ab_item and ab_item<=1);
						return id1|uint64_t(ab_item)<<bit;
					});
	}
	
	int out=0;
	for(auto& row:opval)
		out+=(int)std::count_if(begin(row),end(row),[](auto x){return x!=0;});
	std::cout<<out<<'\n';
}
