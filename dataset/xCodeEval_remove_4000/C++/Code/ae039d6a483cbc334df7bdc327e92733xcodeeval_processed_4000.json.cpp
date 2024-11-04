































































using namespace std;



typedef long int64 ;

class bigint : vector<int> {
      public:
             bigint() ;
             bigint(int n) ;
             bigint(int64 n);
             bigint(const string& s);
             int to_int() const;
             int64 to_int64() const;
             const string to_string() const;
             int digits() const;
             bool operator !() const;
             const bigint& operator +() const;
             const bigint operator -() const;
             const bigint& operator ++();
             const bigint operator ++(int);
             const bigint& operator --();
             const bigint operator --(int);
             friend bigint operator +(const bigint& N, const bigint& M);
             friend bigint operator -(const bigint& N, const bigint& M);
             friend bigint operator *(const bigint& N, const int n);
             friend bigint operator *(const int n, const bigint& N);
             friend bigint operator *(const bigint& N, const bigint& M);
             friend bigint operator /(const bigint& N, const int n);
             friend bigint operator /(const bigint& N, const bigint& M);
             friend bigint operator %(const bigint& N, const int n);
             friend bigint operator %(const bigint& N, const bigint& M);
             friend bigint operator <<(const bigint& N, const int n);
             friend bigint operator >>(const bigint& N, const int n);
             bigint& operator +=(const bigint& N);
             bigint& operator -=(const bigint& N);
             bigint& operator *=(const int n);
             bigint& operator *=(const bigint& N);
             bigint& operator /=(const int n);
             bigint& operator /=(const bigint& N);
             bigint& operator %=(const int n);
             bigint& operator %=(const bigint& N);
             bigint& operator <<=(const int n);
             bigint& operator >>=(const int n);
             friend bool operator ==(const bigint& N, const bigint& M);
             friend bool operator !=(const bigint& N, const bigint& M);
             friend bool operator <(const bigint& N, const bigint& M);
             friend bool operator >(const bigint& N, const bigint& M);
             friend bool operator <=(const bigint& N, const bigint& M);
             friend bool operator >=(const bigint& N, const bigint& M);
             friend const bigint abs(const bigint& N);
             friend int compare(const bigint& N, const bigint& M);
             friend const bigint divide(const bigint& N, const int n, int& remainder);
             friend const bigint divide(const bigint& N, const bigint& M, bigint& remainder);
             friend const bigint shift(const bigint& N, const int n);
             friend const bigint sqrt(const bigint& N);
             friend istream& operator >>(istream& instr, bigint& N);
             friend ostream& operator <<(ostream& outstr, const bigint& N);

      private:
             static const int base=10000;
             static const int width=4;
             bool sign;
             void simplify();
             friend const bigint add_abs(const bigint& N, const bigint& M);
             friend const bigint sub_abs(const bigint& N, const bigint& M);
             friend const bigint mul_abs(const bigint& N, const int n, const int offset=0);
             friend const bigint div_abs(const bigint& N, const int n, int& remainder);
             friend const bigint div_abs(const bigint& N, const bigint& M, bigint& remainder);
} ;

const bigint pow(const bigint& N, const int n);
const bigint factorial(const int n);
const bigint permutation(const int n, const int m);
const bigint id0(const int n, const int m);
const bigint id3(const int n, const int m);
const bigint combination(const int n, const int m);
const bigint id2(const int n, const int m);
const bigint gcd(const bigint& N, const bigint& M);
const bigint lcm(const bigint& N, const bigint& M);
void id1(const bigint& N, const bigint& M, bigint& GCD, bigint& LCM);

inline bigint::bigint() : sign(false) {
       }

bigint::bigint(int n) {
    if(n<0) {
        sign=true;
        n=-n;
    }
    else
        sign=false;
    while(n!=0) {
        push_back(n%base);
        n/=base;
    }
}

inline bigint::bigint(int64 n) {
    if(n<0) {
        sign=true;
        n=-n;
    }
    else
        sign=false;
    while(n!=0) {
        push_back(n%base);
        n/=base;
    }
}

inline bigint::bigint(const string& s) {
    istringstream sin(s);
    sin>>*this;
}

int bigint::to_int() const {
    int r=0;
    for(int i=size()-1; i>=0; i--) r=r*base+(*this)[i];
    if(sign) r=-r;
    return r;
}

int64 bigint::to_int64() const
{
    int64 r=0;
    for(int i=size()-1; i>=0; i--) r=r*base+(*this)[i];
    if(sign) r=-r;
    return r;
}

inline const string bigint::to_string() const {
    ostringstream sout;
    sout<<*this;
    return sout.str();
}

int bigint::digits() const {
    if(empty()) return 0;
    int r=(size()-1)*width;
    int temp=(*this)[size()-1];
    while(temp>0) {
        r++;
        temp/=10;
    }
    return r;
}

inline bool bigint::operator !() const { return !empty(); }
inline const bigint& bigint::operator +() const { return *this; }
inline const bigint bigint::operator -() const {
    bigint R(*this);
    R.sign=!empty() && !R.sign;
    return R;
}

inline const bigint& bigint::operator ++() {
    *this=*this+1;
    return *this;
}

inline const bigint bigint::operator ++(int) {
    bigint backup(*this);
    *this=*this+1;
    return backup;
}

inline const bigint& bigint::operator --() {
    *this=*this-1;
    return *this;
}

inline const bigint bigint::operator --(int) {
    bigint backup(*this);
    *this=*this-1;
    return backup;
}

inline bigint operator +(const bigint& N, const bigint& M) {
    bigint R;
    if(N.sign^M.sign) {
        if(abs(N)>=abs(M)) {
            R=sub_abs(N, M);
            R.sign=N.sign;
        }
        else {
            R=sub_abs(M, N);
            R.sign=M.sign;
        }
        R.simplify();
    }
    else {
        R=add_abs(N, M);
        R.sign=N.sign;
    }
    return R;
}

inline bigint operator -(const bigint& N, const bigint& M) { return N+(-M); }
inline bigint operator *(const bigint& N, const int n) {
    if(n<=-bigint::base || n>=bigint::base) return N*bigint(n);
    else {
        bigint R;
        R=mul_abs(N, abs(n));
        R.sign=N.sign^(n<0);
        R.simplify();
        return R;
    }
}

inline bigint operator *(const int n, const bigint& N) { return N*n; }
bigint operator *(const bigint& N, const bigint& M) {
    bigint R;
    if(N.size()<M.size())
        for(int i=0; i<N.size(); i++) R+=mul_abs(M, N[i], i);
    else
        for(int i=0; i<M.size(); i++) R+=mul_abs(N, M[i], i);
    R.sign=N.sign^M.sign;
    R.simplify();
    return R;
}

inline bigint operator /(const bigint& N, const int n) {
    if(n<=-bigint::base || n>=bigint::base) return N/bigint(n);
    else {
        bigint R;
        int remainder;
        R=div_abs(N, abs(n), remainder);
        R.sign=N.sign^(n<0);
        return R;
    }
}

inline bigint operator /(const bigint& N, const bigint& M) {
    bigint R,remainder;
    R=div_abs(N, M, remainder);
    R.sign=N.sign^M.sign;
    return R;
}

inline bigint operator %(const bigint& N, const int n) {
 	if(n<=-bigint::base || n>=bigint::base)
    	return N%bigint(n);
 	else {
    	bigint R;
    	int remainder;
    	R=div_abs(N, abs(n), remainder);
    	if(N.sign)
      		remainder=-remainder;
    	return remainder;
 	}
}
inline bigint operator %(const bigint& N, const bigint& M) {
 	bigint R,remainder;
 	R=div_abs(N, M, remainder);
 	remainder.sign=N.sign;
 	return remainder;
}
inline bigint operator <<(const bigint& N, const int n) {
 	return shift(N, n);
}
inline bigint operator >>(const bigint& N, const int n) {
 	return shift(N, -n);
}
inline bigint& bigint::operator +=(const bigint& N) {
 	*this=*this+N;
 	return *this;
}
inline bigint& bigint::operator -=(const bigint& N) {
 	*this=*this-N;
 	return *this;
}
inline bigint& bigint::operator *=(const int n) {
 	*this=*this*n;
 	return *this;
}
inline bigint& bigint::operator *=(const bigint& N) {
 	*this=*this*N;
 	return *this;
}
inline bigint& bigint::operator /=(const int n) {
 	*this=*this/n;
 	return *this;
}
inline bigint& bigint::operator /=(const bigint& N) {
 	*this=*this/N;
 	return *this;
}
inline bigint& bigint::operator %=(const int n) {
 	*this=*this%n;
 	return *this;
}
inline bigint& bigint::operator %=(const bigint& N) {
 	*this=*this%N;
	return *this;
}
inline bigint& bigint::operator <<=(const int n) {
 	*this=*this<<n;
 	return *this;
}
inline bigint& bigint::operator >>=(const int n) {
 	*this=*this>>n;
 	return *this;
}
inline bool operator ==(const bigint& N, const bigint& M) {
 	return compare(N, M)==0;
}
inline bool operator !=(const bigint& N, const bigint& M) {
 	return compare(N, M)!=0;
}
inline bool operator <(const bigint& N, const bigint& M) {
 	return compare(N, M)<0;
}
inline bool operator >(const bigint& N, const bigint& M) {
 	return compare(N, M)>0;
}
inline bool operator <=(const bigint& N, const bigint& M) {
 	return compare(N, M)<=0;
}
inline bool operator >=(const bigint& N, const bigint& M) {
 	return compare(N, M)>=0;
}
inline const bigint abs(const bigint& N) {
 	bigint R(N);
 	R.sign=false;
 	return R;
}
int compare(const bigint& N, const bigint& M) {
 	if(!N.sign && M.sign)
    	return 1;
 	else
	if(N.sign && !M.sign)
    	return -1;
 	else {
    	int temp;
    	if(N.size()>M.size())
      		temp=1;
    	else
		if(N.size()<M.size())
      		temp=-1;
    	else {
      		temp=0;
      		for(int i=N.size()-1; i>=0 && temp==0; i--)
        		if(N[i]>M[i])
        			temp=1;
        		else
				if(N[i]<M[i])
          			temp=-1;
    	}
    	if(N.sign)
      		return -temp;
    	else
      	return temp;
 	}
}
inline const bigint divide(const bigint& N, const int n, int& remainder) {
 	bigint R;
 	R=div_abs(N, abs(n), remainder);
 	R.sign=N.sign^(n<0);
 	if(N.sign)
    	remainder=-remainder;
 		return R;
}
inline const bigint divide(const bigint& N, const bigint& M, bigint& remainder) {
 	bigint R;
 	R=div_abs(N, M, remainder);
 	R.sign=N.sign^M.sign;
 	remainder.sign=N.sign;
 	return R;
}
const bigint shift(const bigint& N, const int n) {
 	if(N.empty() || N.digits()+n<=0)
    	return 0;
 	bigint R;
 	int offset=n/bigint::width;
 	int micro=n%bigint::width;
 	if(micro>0) {
    	micro-=bigint::width;
    	offset++;
 	}
 	micro=-micro;
 	R.resize(N.size()+offset+1,0);
 	if(offset>=0)
    	for(int i=0; i<N.size(); i++)
      		R[i+offset]=N[i];
 	else
    for(int i=0; i<N.size()+offset; i++)
      	R[i]=N[i-offset];
 	if(micro!=0) {
    	int divisor=1;
    	int i;
    	for(i=0; i<micro; i++)
      		divisor*=10;
    	for(i=0; i<R.size()-1; i++)
      		R[i]=(R[i+1]*int64(bigint::base)+R[i])/divisor%bigint::base;
    	R[R.size()-1]=R[R.size()-1]/bigint::base;
 	}
 	R.sign=N.sign;
 	R.simplify();
 	return R;
}
const bigint sqrt(const bigint& N) {
 	if(N.sign)
    	return -1;
 	if(N.empty())
    	return 0;
 	bigint R,left(N);
 	R.resize((N.size()+1)/2,0);
 	int64 temp=N[N.size()-1];
 	if(N.size()%2==0)
    	temp=temp*bigint::base+N[N.size()-2];
 	R[R.size()-1]=int(sqrt(static_cast<long double>(temp)));
 	left-=R*R;
 	for(int i=R.size()-2; i>=0; i--) {
    	int lower=0,upper=bigint::base;
    	bigint T;
    	T.resize(i+1, 0);
    	while(upper-lower>=2) {
      		T[i]=(lower+upper)/2;
      		if(T*(R+R+T)<left)
        		lower=T[i];
      		else
        	upper=T[i];
    	}
    	T[i]=upper;
    	if(T*(R+R+T)<=left)
      		T[i]=upper;
    	else
      	T[i]=lower;
    	left-=T*(R+R+T);
    	R[i]=T[i];
 	}
 	return R;
}
istream& operator >>(istream& instr, bigint& N) {
 	instr>>ws;
 	if(!instr)
    	return instr;
 	N.clear();
 	if(instr.peek()=='+' || instr.peek()=='-') {
    	N.sign=instr.peek()=='-';
    	instr.ignore(1);
 	}
 	else
    N.sign=false;
 	vector<char> buffer;
 	while(isdigit(instr.peek()))
    	buffer.push_back(instr.get());
 	reverse(buffer.begin(),buffer.end());
 	while(buffer.size()%bigint::width!=0)
    	buffer.push_back('0');
 	for(int i=0; i<buffer.size()/bigint::width; i++) {
    	int period=0;
    	for(int j=bigint::width-1; j>=0; j--)
      	period=period*10+(buffer[i*bigint::width+j]-'0');
    	N.push_back(period);
 	}
 	N.simplify();
 	return instr;
}
ostream& operator <<(ostream& outstr, const bigint& N) {
 	if(N.empty())
    	outstr<<0;
 	else {
    	if(N.sign)
      		outstr<<'-';
    	outstr<<N[N.size()-1];
    	for(int i=N.size()-2; i>=0; i--) {
      		outstr.width(bigint::width);
      		outstr.fill('0');
      		outstr<<N[i];
    	}
 	}
 	return outstr;
}
void bigint::simplify() {
 	while(!empty() && back()==0)
    	pop_back();
 	if(empty())
    	sign=false;
}
const bigint add_abs(const bigint& N, const bigint& M) {
 	bigint R;
 	int bound=max(N.size(), M.size());
 	R.resize(bound+1,0);
 	for(int i=0; i<bound; i++) {
    	if(i<N.size())
      		R[i]+=N[i];
    	if(i<M.size())
      		R[i]+=M[i];
    	if(R[i]>=bigint::base) {
      		R[i+1]++;
      		R[i]-=bigint::base;
    	}
 	}
 	R.simplify();
 	return R;
}
const bigint sub_abs(const bigint& N, const bigint& M) {
 	bigint R;
 	int bound=N.size();
 	R.resize(bound,0);
 	for(int i=0; i<bound; i++) {
    	R[i]+=N[i];
    	if(i<M.size())
      		R[i]-=M[i];
    	if(R[i]<0){
      		R[i+1]--;
      		R[i]+=bigint::base;
    	}
 	}
 	R.simplify();
 	return R;
}
const bigint mul_abs(const bigint& N, const int n, const int offset) {
 	if(n==0)
    	return 0;
 	bigint R;
 	R.resize(N.size()+1+offset, 0);
 	for(int i=0; i<N.size(); i++) {
    	int64 temp=int64(n)*N[i]+R[i+offset];
    	R[i+offset]=temp%bigint::base;
    	R[i+offset+1]+=temp/bigint::base;
 	}
 	R.simplify();
 	return R;
}
const bigint div_abs(const bigint& N, const int n, int& remainder) {
 	bigint R;
 	R.resize(N.size(), 0);
 	int64 temp=0;
	for(int i=N.size()-1; i>=0; i--) {
    	temp=temp*bigint::base+N[i];
    	R[i]=temp/n;
    	temp%=n;
 	}
 	remainder=temp;
 	R.simplify();
 	return R;
}
const bigint div_abs(const bigint& N, const bigint& M, bigint& remainder) {
 	if(N.size()<M.size()) {
    	remainder=N;
    	return 0;
 	}
 	bigint R;
 	R.resize(N.size());
 	remainder=0;
 	for(int i=N.size()-1; i>=0; i--) {
    	remainder=mul_abs(remainder, 1, 1)+N[i];
    	int lower=0,upper=bigint::base;
    	while(upper-lower>=2) {
      		R[i]=(lower+upper)/2;
      		if(abs(M)*R[i]<remainder)
        		lower=R[i];
      		else
        	upper=R[i];
    	}
    	if(abs(M)*upper<=remainder)
      		R[i]=upper;
   		else
      	R[i]=lower;
    	remainder-=abs(M)*R[i];
 	}
 	R.simplify();
 	return R;
}
const bigint pow(const bigint& N, int n) {
 	if(N==0)
    	return 0;
 	bigint T(N),R(1);
 	while(n){
     	if(n&1)
      		R*=T;
    	T*=T;
    	n>>=1;
 	}
 	return R;
}
const bigint factorial(const int n) {
 	bigint R(1);
 	for(unsigned long long i=2; i<=n; i++)
    	R*=i;

    return R;
}
const bigint permutation(const int n, const int m) {
 	if(n<0 || m<0 || m>n)
    	return 0;
 	bigint R(1);
 	for(int i=n-m+1; i<=n; i++)
    	R*=i;
 	return R;
}
inline const bigint id0(const int n, const int m) {
 	if(n<0 || m<0 || m>n)
    	return 0;
 	return permutation(n, m)/m;
}
inline const bigint id3(const int n, const int m) {
 	if(n<0 || m<0 || m>n)
    	return 0;
 	return pow(bigint(n), m);
}
const bigint combination(const int n, const int m) {
 	if(n<0 || m<0 || m>n)
    	return 0;
 	bigint R(1);
 	int i;
 	for(i=n-m+1; i<=n; i++)
    	R*=i;
 	for(i=2; i<=m; i++)
    	R/=i;
 	return R;
}
inline const bigint id2(const int n, const int m){
 	if(n<0 || m<0 || m>n)
    	return 0;
 	return combination(n+m-1, m);
}
const bigint euclid(const bigint& N, const bigint& M){
 	bigint A(N), B(M);
 	while(!B)
 	{
    	bigint T(B);
    	B=A%B;
    	A=T;
 	}
  	return A;
}
inline const bigint gcd(const bigint& N, const bigint& M){
 	if(abs(N)>abs(M))
    	return euclid(abs(N), abs(M));
 	else
    	return euclid(abs(M), abs(N));
}
inline const bigint lcm(const bigint& N, const bigint& M){
 	return abs(N*M/gcd(N, M));
}
inline void id1(const bigint& N, const bigint& M, bigint& GCD, bigint& LCM){
 	GCD=gcd(N, M);
 	LCM=abs(N*M/GCD);
}
typedef bigint Ints;
int main() {
	int n,m,i,j;
	cin>>n>>m;
	if((n/2>m || n==1) && !(n==1 && m==0))cout<<-1<<endl;
	else{
		for(i=1,j=1000000000-1;i<=n/2-1;i++,j-=2){
			cout<<j<<" "<<j-1<<" ";
			m--;
		}
		if(n>=2)
			cout<<m<<" "<<2*m;
		if(n%2==1)cout<<" "<<2*m+1;
		cout<<endl;
	}
	return 0;
}
