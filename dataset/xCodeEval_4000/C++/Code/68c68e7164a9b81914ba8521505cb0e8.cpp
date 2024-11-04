#pragma comment(linker, "/STACK:108777216")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <set>
#include <utility>
#include <algorithm>
#include <ctime>
using namespace std;

int const MAX_N = 512 * 1024;
int const INT_INF = 1000000000;
double const EPS = 1e-8;


int const LONG_BASE=1000000000;
int const MAX_DIGITS_ON_DEFAULT=3;
int const PRECISION_ON_DEFAULT=3;
short const LESS=0;
short const EQUAL=1;
short const MORE=2;

int calculate_base_deg() {
	int ans=0,x=LONG_BASE;
	while (x>0) {
		ans++;
		x/=10;
	}
	return ans-1;
}


class Tlong_Unsigned_Int {
	int len;
	int max_digits;
	int *s;
	
	public:
		Tlong_Unsigned_Int(int);
		Tlong_Unsigned_Int(const Tlong_Unsigned_Int&);
		Tlong_Unsigned_Int(const string &st);
		Tlong_Unsigned_Int(double);
		
		~Tlong_Unsigned_Int();

		void trim();
		
		friend short compare (const Tlong_Unsigned_Int&,const Tlong_Unsigned_Int&,int);
		bool equal_null() const;
		Tlong_Unsigned_Int& operator = (const Tlong_Unsigned_Int&);
		void expand(int);
		
		friend void sub(const Tlong_Unsigned_Int&,const Tlong_Unsigned_Int&,Tlong_Unsigned_Int &,int);
		
		friend Tlong_Unsigned_Int operator + (const Tlong_Unsigned_Int&,const Tlong_Unsigned_Int&);
		friend Tlong_Unsigned_Int operator - (const Tlong_Unsigned_Int&,const Tlong_Unsigned_Int&);
		friend Tlong_Unsigned_Int operator * (const Tlong_Unsigned_Int&,const Tlong_Unsigned_Int&);
		friend Tlong_Unsigned_Int operator / (const Tlong_Unsigned_Int&,const Tlong_Unsigned_Int&);
		friend Tlong_Unsigned_Int operator % (const Tlong_Unsigned_Int&,const Tlong_Unsigned_Int&);
		
		Tlong_Unsigned_Int& operator += (const Tlong_Unsigned_Int&);
		Tlong_Unsigned_Int& operator -= (const Tlong_Unsigned_Int&);
		Tlong_Unsigned_Int& operator *= (const Tlong_Unsigned_Int&);
		Tlong_Unsigned_Int& operator /= (const Tlong_Unsigned_Int&);
		Tlong_Unsigned_Int& operator %= (const Tlong_Unsigned_Int&);

		friend ostream& operator << (ostream &stream,const Tlong_Unsigned_Int&);
		void print_to_str(string &) const;
		friend istream& operator >> (istream &stream,Tlong_Unsigned_Int&);
		
		void make_shift(int);
		void truncate(int);
		int kol_digits() const;
};

Tlong_Unsigned_Int::Tlong_Unsigned_Int(int max_dig=MAX_DIGITS_ON_DEFAULT):max_digits(max_dig),len(1) {
	s=new int[max_digits];
	s[0]=0;
}

Tlong_Unsigned_Int::Tlong_Unsigned_Int(const Tlong_Unsigned_Int& a):max_digits(a.max_digits),len(a.len) {
	s=new int[max_digits];
	for (int i=0; i<max_digits; ++i) s[i]=a.s[i];
}

Tlong_Unsigned_Int::Tlong_Unsigned_Int(const string &st) {
	int BASE_DEG=calculate_base_deg(),n=(int) st.length();
	len=n/BASE_DEG;
	max_digits=len+(n%BASE_DEG>0);
	s=new int[max_digits];
	fill(s,s+max_digits,0);
	if (n%BASE_DEG) for (int i=0; i<n%BASE_DEG; i++) s[len]=s[len]*10+(st[i]-'0');
	for (int i=1; i<=len; i++)
		for (int j=(i-1)*BASE_DEG; j<i*BASE_DEG; j++)
			s[len-i]=s[len-i]*10+(st[j+n%BASE_DEG]-'0');
	len+=(n%BASE_DEG>0);
	trim();
}

Tlong_Unsigned_Int::Tlong_Unsigned_Int(double x) {
	char st[100];
	string new_st;
	sprintf(st,"%.16e",x);
	int pos_point=-1,i;
	for (i=0; st[i]; ++i)
		if (st[i]=='.') pos_point=i;
		else if (st[i]=='e') break;
		else new_st+=st[i];
	Tlong_Unsigned_Int c(new_st);
	len=c.len;
	max_digits=c.max_digits;
	s=new int[max_digits];
	int xx;
	sscanf(st+i+1,"%d",&xx);
	int deg=xx-(i-pos_point-1);
	for (i=0; i<len; ++i) s[i]=c.s[i];
	if (deg<0) truncate(-deg);
	else make_shift(deg);
}

Tlong_Unsigned_Int::~Tlong_Unsigned_Int() {
	delete[] s;
}

void Tlong_Unsigned_Int::trim() {
	while (len>1 && !s[len-1]) --len;
}

short compare (const Tlong_Unsigned_Int& a,const Tlong_Unsigned_Int& b,int sp=0) {
	if (a.equal_null() && b.equal_null()) return EQUAL;
	if (a.equal_null()) return LESS;
	if (b.equal_null()) return MORE;
	if (a.len>b.len+sp) return MORE;
	else if (a.len<b.len+sp) return LESS;
	for (int i=b.len-1; i>=0; --i)
		if (a.s[i+sp]>b.s[i]) return MORE;
		else if (a.s[i+sp]<b.s[i]) return LESS;
	for (int i=0; i<sp; ++i)
		if (a.s[i]) return MORE;
	return EQUAL;
}

bool Tlong_Unsigned_Int::equal_null() const {
	return (len==1) && (!s[0]);
}

void Tlong_Unsigned_Int::expand(int max_dig) {
	if (max_digits<max_dig) {
		int *t=s;
		max_digits=max_dig;
		s=new int[max_digits];
		for (int i=0; i<len; i++) s[i]=t[i];
		delete [] t;
	}
}

Tlong_Unsigned_Int& Tlong_Unsigned_Int::operator = (const Tlong_Unsigned_Int& a) {
	expand(a.max_digits);
	len=a.len;
	for (int i=0; i<len; ++i) s[i]=a.s[i];
	return *this;
}

Tlong_Unsigned_Int operator + (const Tlong_Unsigned_Int& a,const Tlong_Unsigned_Int& b) {
	Tlong_Unsigned_Int t(a);
	return t+=b;
}
		
Tlong_Unsigned_Int operator - (const Tlong_Unsigned_Int& a,const Tlong_Unsigned_Int& b) {
	Tlong_Unsigned_Int t(a);
	return t-=b;
}

Tlong_Unsigned_Int operator * (const Tlong_Unsigned_Int& a,const Tlong_Unsigned_Int& b) {
	Tlong_Unsigned_Int t(a);
	return t*=b;
}

Tlong_Unsigned_Int operator / (const Tlong_Unsigned_Int& a,const Tlong_Unsigned_Int& b) {
	Tlong_Unsigned_Int t(a);
	return t/=b;
}

Tlong_Unsigned_Int operator % (const Tlong_Unsigned_Int& a,const Tlong_Unsigned_Int& b) {
	Tlong_Unsigned_Int t(a);
	return t%=b;
}

Tlong_Unsigned_Int& Tlong_Unsigned_Int::operator += (const Tlong_Unsigned_Int& b) {
	int per=0,ss,bb,k=max(len,b.len)+1;
	expand(k);
	for (int i=0; i<k; ++i) {
		if (i>=len) ss=0;
		else ss=s[i];
		if (i>=b.len) bb=0;
		else bb=b.s[i];
		int new_s=(ss+bb+per)%LONG_BASE;
		per=(ss+bb+per)/LONG_BASE;
		s[i]=new_s;
	}
	len=k;
	trim();
	return *this;
}

Tlong_Unsigned_Int& Tlong_Unsigned_Int::operator -= (const Tlong_Unsigned_Int& b) {
	sub(*this,b,*this,0);
	return *this;
}

Tlong_Unsigned_Int& Tlong_Unsigned_Int::operator *= (const Tlong_Unsigned_Int& b) {
	Tlong_Unsigned_Int c(len+b.len);
	for (int i=0; i<c.max_digits; ++i) c.s[i]=0;
	for (int i=0; i<len; ++i)
		for (int j=0; j<b.len; ++j) {
			long long dv=c.s[i+j]+s[i]*((long long) b.s[j]);
			c.s[i+j+1]+=(int) (dv/LONG_BASE);
			c.s[i+j]=(int) (dv%LONG_BASE);
		}
	c.len=len+b.len;
	c.trim();
	swap(*this,c);
	return *this;
}

Tlong_Unsigned_Int& Tlong_Unsigned_Int::operator /= (const Tlong_Unsigned_Int& b) {
	string st;
	switch (compare(*this,b)) {
		case LESS:st="0";
				  (*this)=st;
				  break;
		case EQUAL:st="1";
				   (*this)=st;
			       break;
		case MORE:{
			       int sp=len-b.len;
				   Tlong_Unsigned_Int ost(*this),c(1);
				   if (compare(ost,b,sp)==LESS) sp--;
				   Tlong_Unsigned_Int res(sp+1);
				   res.len=sp+1;
				   while (sp>=0) {
				      int up=LONG_BASE,down=0,mid;
					  while (up>down) {
					     mid=(up+down)/2;
						 c.s[0]=mid;
						 if (compare(ost,b*c,sp)==LESS) up=mid;
						 else down=mid+1;
					  }
					  down--;
					  c.s[0]=down;
					  sub(ost,b*c,ost,sp);
					  res.s[sp--]=down;
				   }
				   swap(*this,res);
				   break;
				  }
	}
	return *this;
}

Tlong_Unsigned_Int& Tlong_Unsigned_Int::operator %= (const Tlong_Unsigned_Int& b) {
	(*this)-=((*this)/b)*b;
	return *this;
}

void sub(const Tlong_Unsigned_Int& a,const Tlong_Unsigned_Int& b,Tlong_Unsigned_Int &c,int sp) {
	c.expand(a.len);
	c.len=a.len;
	for (int i=0; i<sp; i++) c.s[i]=a.s[i];
	int z=0;
	for (int i=sp; i<a.len; i++) {
		if (i-sp>=b.len) c.s[i]=a.s[i]-z;
		else c.s[i]=a.s[i]-b.s[i-sp]-z;
		z=0;
		if (c.s[i]<0) {
			z=1;
			c.s[i]+=LONG_BASE;
		}
	}
	c.trim();
}		

ostream& operator << (ostream &stream,const Tlong_Unsigned_Int& x) {
	int BASE_DEG=calculate_base_deg();
	stream<<x.s[x.len-1];
	for (int i=x.len-2; i>=0; --i) {
		stream.width(BASE_DEG);
		stream.fill('0');
		stream<<x.s[i];
	}
	return stream;
}

istream& operator >> (istream &stream,Tlong_Unsigned_Int& x) {
	string st;
	stream>>st;
	x=st;
	return stream;
}

void Tlong_Unsigned_Int::make_shift(int sp) {
	int BASE_DEG=calculate_base_deg();
	int i;
	expand(len+sp/BASE_DEG+(sp%BASE_DEG>0));
	for (i=len+sp/BASE_DEG-1; i>=sp/BASE_DEG; --i) s[i]=s[i-sp/BASE_DEG];
	for (i=0; i<sp/BASE_DEG; ++i) s[i]=0;
	len+=sp/BASE_DEG;
	sp%=BASE_DEG;
	i=1;
	while (sp-->0) i*=10;
	Tlong_Unsigned_Int c(1);
	c.s[0]=i;
	(*this)*=c;
}

void Tlong_Unsigned_Int::truncate(int sp) {
	int BASE_DEG=calculate_base_deg();
	int i;
	for (i=0; i<len-sp/BASE_DEG; ++i) s[i]=s[i+sp/BASE_DEG];
	len-=sp/BASE_DEG;
	i=1;
	sp%=BASE_DEG;
	while (sp-->0) i*=10;
	Tlong_Unsigned_Int c(1);
	c.s[0]=i;
	(*this)/=c;
}

int Tlong_Unsigned_Int::kol_digits() const {
	int ans=(len-1)*calculate_base_deg();
	int k=s[len-1];
	while (k>0) {
		ans++;
		k/=10;
	}
	return ans;
}

void Tlong_Unsigned_Int::print_to_str(string &st) const {
	st.clear();
	int BASE_DEG=calculate_base_deg();
	for (int i=len-1; i>=0; --i) {
		int pos=(int) st.length();
		int x=s[i],kol=0;
		while (x>0) {
			kol++;
			st.insert(st.begin()+pos,(x%10)+'0');
			x/=10;
		}
		if (i!=len-1) {
			kol=BASE_DEG-kol;
			while (kol-->0) st.insert(st.begin()+pos,'0');
		}
	}
	if (st.empty()) st="0";
}



class Tlong_Signed_Int {
	Tlong_Unsigned_Int s;
	bool sign;

	public:
		Tlong_Signed_Int(int max_dig=MAX_DIGITS_ON_DEFAULT):s(max_dig),sign(false) {}
		Tlong_Signed_Int(const Tlong_Signed_Int& a):sign(a.sign),s(a.s) {}
		Tlong_Signed_Int(const string &st);
		Tlong_Signed_Int(double x):s(fabs(x)),sign(x<0) {}

		friend short compare (const Tlong_Signed_Int&,const Tlong_Signed_Int&);
		bool equal_null() const;
		Tlong_Signed_Int& operator = (const Tlong_Signed_Int&);
		
		friend Tlong_Signed_Int operator + (const Tlong_Signed_Int&,const Tlong_Signed_Int&);
		friend Tlong_Signed_Int operator - (const Tlong_Signed_Int&,const Tlong_Signed_Int&);
		friend Tlong_Signed_Int operator * (const Tlong_Signed_Int&,const Tlong_Signed_Int&);
		friend Tlong_Signed_Int operator / (const Tlong_Signed_Int&,const Tlong_Signed_Int&);
		friend Tlong_Signed_Int operator % (const Tlong_Signed_Int&,const Tlong_Signed_Int&);
		
		Tlong_Signed_Int& operator += (const Tlong_Signed_Int&);
		Tlong_Signed_Int& operator -= (const Tlong_Signed_Int&);
		Tlong_Signed_Int& operator *= (const Tlong_Signed_Int&);
		Tlong_Signed_Int& operator /= (const Tlong_Signed_Int&);
		Tlong_Signed_Int& operator %= (const Tlong_Signed_Int&);

		friend ostream& operator << (ostream &stream,const Tlong_Signed_Int&);
		void print_to_str(string &) const;
		friend istream& operator >> (istream &stream,Tlong_Signed_Int&);

		void make_shift(int);
		void truncate(int);
		int kol_digits() const;
};

Tlong_Signed_Int::Tlong_Signed_Int(const string &st) {
	sign=false;
	if (st[0]=='-') {
		sign=true;
		s=st.substr(1,st.length()-1);
	}
	else if (st[0]=='+') s=st.substr(1,st.length()-1);
	else s=st;
	if (equal_null()) sign=false;
}

short compare (const Tlong_Signed_Int& a,const Tlong_Signed_Int& b) {
	if (a.sign && !b.sign) return LESS;
	if (!a.sign && b.sign) return MORE;
	short d=compare(a.s,b.s);
	if (!a.sign && !b.sign) return d;
	return 2-d;
}

Tlong_Signed_Int& Tlong_Signed_Int::operator = (const Tlong_Signed_Int& a) {
	sign=a.sign;
	s=a.s;
	return *this;
}

Tlong_Signed_Int operator + (const Tlong_Signed_Int& a,const Tlong_Signed_Int& b) {
	Tlong_Signed_Int t(a);
	return t+=b;
}
		
Tlong_Signed_Int operator - (const Tlong_Signed_Int& a,const Tlong_Signed_Int& b) {
	Tlong_Signed_Int t(a);
	return t-=b;
}

Tlong_Signed_Int operator * (const Tlong_Signed_Int& a,const Tlong_Signed_Int& b) {
	Tlong_Signed_Int t(a);
	return t*=b;
}

Tlong_Signed_Int operator / (const Tlong_Signed_Int& a,const Tlong_Signed_Int& b) {
	Tlong_Signed_Int t(a);
	return t/=b;
}

Tlong_Signed_Int operator % (const Tlong_Signed_Int& a,const Tlong_Signed_Int& b) {
	Tlong_Signed_Int t(a);
	return t%=b;
}

Tlong_Signed_Int& Tlong_Signed_Int::operator += (const Tlong_Signed_Int& b) {
	if (sign==b.sign) s+=b.s;
	else {
		if (compare(s,b.s)==MORE) s-=b.s;
		else {
			s=b.s-s;
			sign=b.sign;
		}
	}
	if (s.equal_null()) sign=false;
	return *this;
}

Tlong_Signed_Int& Tlong_Signed_Int::operator -= (const Tlong_Signed_Int& b) {
	if (sign!=b.sign) s+=b.s;
	else {
		if (compare(s,b.s)==MORE) s-=b.s;
		else {
			s=b.s-s;
			sign=!b.sign;
		}
	}
	if (s.equal_null()) sign=false;
	return *this;
}

Tlong_Signed_Int& Tlong_Signed_Int::operator *= (const Tlong_Signed_Int& b) {
	s*=b.s;
	sign=sign!=b.sign;
	if (s.equal_null()) sign=false;
	return *this;
}

Tlong_Signed_Int& Tlong_Signed_Int::operator /= (const Tlong_Signed_Int& b) {
	s/=b.s;
	sign=sign!=b.sign;
	if (s.equal_null()) sign=false;
	return *this;
}

Tlong_Signed_Int& Tlong_Signed_Int::operator %= (const Tlong_Signed_Int& b) {
	(*this)-=((*this)/b)*b;
	if (s.equal_null()) sign=false;
	return *this;
}

ostream& operator << (ostream &stream,const Tlong_Signed_Int& x) {
	if (x.sign) stream<<'-';
	stream<<x.s;
	return stream;
}

istream& operator >> (istream &stream,Tlong_Signed_Int& x) {
	string st;
	stream>>st;
	x=st;
	return stream;
}

void Tlong_Signed_Int::make_shift(int sp) {
	s.make_shift(sp);
}

void Tlong_Signed_Int::truncate(int sp) {
	s.truncate(sp);
}

int Tlong_Signed_Int::kol_digits() const {
	return s.kol_digits();
}

bool Tlong_Signed_Int::equal_null() const {
	return s.equal_null();
}

void Tlong_Signed_Int::print_to_str(string &st) const {
	st.clear();
	if (sign) st+='-';
	string st1;
	s.print_to_str(st1);
	st+=st1;
}

bool operator < (const Tlong_Signed_Int & A, const Tlong_Signed_Int & B) {
    return compare(A,B) == LESS;
}


Tlong_Signed_Int LL_INF("2000000000000000000");
Tlong_Signed_Int LL_NULL("0");

Tlong_Signed_Int gcd(Tlong_Signed_Int a, Tlong_Signed_Int b) {
    while (!a.equal_null() && !b.equal_null())
        if (compare(a, b) == MORE) a %= b;
        else b %= a;
    return a+b;
}

Tlong_Signed_Int my_abs(Tlong_Signed_Int x) {
    if (compare(x, LL_NULL) == LESS) return -1.0 * x;
    return x;
}

Tlong_Signed_Int gcd (Tlong_Signed_Int a, Tlong_Signed_Int b, Tlong_Signed_Int & x, Tlong_Signed_Int & y) {
    if (a.equal_null()) {
		x = 0.0; y = 1.0;
		return b;
	}
	Tlong_Signed_Int x1, y1;
	Tlong_Signed_Int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool find_any_solution (Tlong_Signed_Int a, Tlong_Signed_Int b, Tlong_Signed_Int c, Tlong_Signed_Int & x0, Tlong_Signed_Int & y0, Tlong_Signed_Int & g) {
	g = gcd (my_abs(a), my_abs(b), x0, y0);
    if (!(c % g).equal_null())
		return false;
	x0 *= c / g;
	y0 *= c / g;
    if (compare(a, LL_NULL) == LESS)   x0 *= -1.0;
	if (compare(b, LL_NULL) == LESS)   y0 *= -1.0;
	return true;
}

void shift_solution (Tlong_Signed_Int & x, Tlong_Signed_Int & y, Tlong_Signed_Int a, Tlong_Signed_Int b, Tlong_Signed_Int cnt) {
	x += cnt * b;
	y -= cnt * a;
}
 
int find_all_solutions (Tlong_Signed_Int a, Tlong_Signed_Int b, Tlong_Signed_Int c, Tlong_Signed_Int minx, Tlong_Signed_Int maxx, Tlong_Signed_Int miny, Tlong_Signed_Int maxy,
                              Tlong_Signed_Int & lx, Tlong_Signed_Int & rx) {
	Tlong_Signed_Int x, y, g;
	if (! find_any_solution (a, b, c, x, y, g))
		return 0;
	a /= g;  b /= g;
 
    Tlong_Signed_Int sign_a = (compare(a,LL_NULL) == MORE) ? +1.0 : -1.0;
    Tlong_Signed_Int sign_b = (compare(b,LL_NULL) == MORE) ? +1.0 : -1.0;
 
	shift_solution (x, y, a, b, (minx - x) / b);
	if (compare(x , minx) == LESS)
		shift_solution (x, y, a, b, sign_b);
	if (compare(x , maxx) == MORE)
		return 0;
	Tlong_Signed_Int lx1 = x;
 
	shift_solution (x, y, a, b, (maxx - x) / b);
	if (compare(x , maxx) == MORE)
		shift_solution (x, y, a, b, -1.0 * sign_b);
	Tlong_Signed_Int rx1 = x;
 
	shift_solution (x, y, a, b, -1.0 *  (miny - y) / a);
	if (compare(y , miny) == LESS)
		shift_solution (x, y, a, b, -1.0 * sign_a);
	if (compare(y , maxy) == MORE)
		return 0;
	Tlong_Signed_Int lx2 = x;
 
	shift_solution (x, y, a, b, -1.0 * (maxy - y) / a);
	if (compare(y , maxy) == MORE)
		shift_solution (x, y, a, b, sign_a);
	Tlong_Signed_Int rx2 = x;
 
	if (compare(lx2 , rx2) == MORE)
		swap (lx2, rx2);
	
    lx = max (lx1, lx2);
	rx = min (rx1, rx2);

    return 1;
}

long long const MAX_IT = 1;
long long const MXD = 1;

void move_sgm(Tlong_Signed_Int lx, Tlong_Signed_Int rx, Tlong_Signed_Int koef_1, Tlong_Signed_Int koef_2, Tlong_Signed_Int val, Tlong_Signed_Int & min_sum, int dir) {
    if (compare(lx , rx) == MORE)
        return;

    if (dir == +1) {
        Tlong_Signed_Int first_nmbr = LL_INF;
        long long ITER = 0;
        for (Tlong_Signed_Int qq = lx; compare(qq , rx) != MORE && ITER < MAX_IT; qq += 1.0, ITER++) {
            Tlong_Signed_Int rem = val - qq * koef_1;
            if ((rem % koef_2).equal_null()) {
                first_nmbr = qq;
                break;
            }
        }

        if (compare(first_nmbr , LL_INF / 2.0) != LESS)
            return;

        Tlong_Signed_Int k2_abs = my_abs(koef_2);
        ITER = 0;
        for (Tlong_Signed_Int x = first_nmbr; compare(x , rx) != MORE && ITER < MAX_IT; x += k2_abs, ITER++) {
            Tlong_Signed_Int y = (val - x * koef_1);
            if ((y % koef_2).equal_null()) {
                y /= koef_2;
                if (compare(x , LL_NULL) != LESS && compare(y , LL_NULL) != LESS)
                    min_sum = min(min_sum, x+y);
            }
        }
    }
    else if (dir == -1) {
        Tlong_Signed_Int first_nmbr = LL_INF;
        long long ITER = 0;
        for (Tlong_Signed_Int qq = rx; compare(qq , lx) != LESS && ITER < MAX_IT; qq -= 1.0, ITER++) {
            Tlong_Signed_Int rem = val - qq * koef_1;
            if ((rem % koef_2).equal_null()) {
                first_nmbr = qq;
                break;
            }
        }

        if (compare(first_nmbr , LL_INF / 2.0) != LESS)
            return;

        Tlong_Signed_Int k2_abs = my_abs(koef_2);
        ITER = 0;
        for (Tlong_Signed_Int x = first_nmbr; compare(x , lx) != LESS && ITER < MAX_IT; x -= k2_abs, ITER++) {
            Tlong_Signed_Int y = (val - x * koef_1);
            if ((y % koef_2).equal_null()) {
                y /= koef_2;
                if (compare(x , LL_NULL) != LESS && compare(y , LL_NULL) != LESS)
                    min_sum = min(min_sum, x+y);
            }
        }
    }
    else {
    }
}

void scan_near_value(Tlong_Signed_Int x_ap, Tlong_Signed_Int koef_1, Tlong_Signed_Int koef_2, Tlong_Signed_Int val, Tlong_Signed_Int & min_sum) {
    Tlong_Signed_Int k2_abs = my_abs(koef_2);
    for (Tlong_Signed_Int dx = -1.0 * MXD; compare(dx , (double) MXD) != MORE; dx += 1.0) {
        Tlong_Signed_Int x = x_ap + k2_abs * dx;

        Tlong_Signed_Int y = (val - x * koef_1);
        if ((y % koef_2).equal_null()) {
            y /= koef_2;
            if (compare(x , LL_NULL) != LESS && compare(y , LL_NULL) != LESS)
                min_sum = min(min_sum, x+y);
        }
    }
}

int main() {
	

	


	int t;
    scanf("%d",&t);
    while (t-->0) {
        Tlong_Signed_Int x,y,p,q;
        cin>>x>>y>>p>>q;

        if (compare(x,p) == EQUAL && compare(y,q) == EQUAL) {
            printf("0\n");
            continue;
        }

        Tlong_Signed_Int val = p*y-q*x;

        if (val.equal_null()) {
            printf("0\n");
            continue;
        }

        Tlong_Signed_Int koef_1 = q-p;
        Tlong_Signed_Int koef_2 = -1.0 * p;

        

        

        

        


        Tlong_Signed_Int x0,y0,gg;
        bool res = find_any_solution(koef_1,koef_2,val,   x0,y0,gg);

        if (res == false) {
            printf("-1\n");
            continue;
        }

        if (koef_1.equal_null()) {
            if (!(val % koef_2).equal_null()) {
                printf("-1\n");
                continue;
            }

            if (compare(val / koef_2, LL_NULL) == LESS) {
                printf("-1\n");
                continue;
            }

            cout<<(val / koef_2)<<"\n";
            continue;
        }
        else if (koef_2.equal_null()) {
            if (!(val % koef_1).equal_null()) {
                printf("-1\n");
                continue;
            }

            if (compare(val / koef_1, LL_NULL) == LESS) {
                printf("-1\n");
                continue;
            }

            cout<<(val / koef_1)<<"\n";
            continue;
        }
        else {
            Tlong_Signed_Int lx,rx;

            Tlong_Signed_Int min_sum = LL_INF;

            if (find_all_solutions(koef_1, koef_2, val, 0.0, LL_INF + 1000000.0, 0.0, LL_INF + 1000000.0, lx, rx)) {
                move_sgm(lx,rx,koef_1,koef_2,val,min_sum,+1);
                move_sgm(lx,rx,koef_1,koef_2,val,min_sum,-1);
                move_sgm(lx,rx,koef_1,koef_2,val,min_sum,0);

                Tlong_Signed_Int a = koef_1;
                Tlong_Signed_Int b = koef_2;
                Tlong_Signed_Int c = val;

                if (compare(a, b) == LESS)
                    scan_near_value((lx-x0)/(b/gg) * (b/gg) + x0, a,b,c, min_sum);
                else if (compare(a, b) == MORE)
                    scan_near_value((rx-x0)/(b/gg) * (b/gg) + x0, a,b,c, min_sum);
            }

            if (compare(min_sum , LL_INF / 2.0) != LESS)
                printf("-1\n");
            else
                cout<<min_sum<<"\n";
        }
    }
	return 0;
}