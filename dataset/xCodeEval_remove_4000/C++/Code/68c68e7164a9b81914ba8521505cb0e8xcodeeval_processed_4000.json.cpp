












using namespace std;

int const MAX_N = 512 * 1024;
int const INT_INF = 1000000000;
double const EPS = 1e-8;


int const LONG_BASE=1000000000;
int const id14=3;
int const id11=3;
short const LESS=0;
short const EQUAL=1;
short const MORE=2;

int id2() {
	int ans=0,x=LONG_BASE;
	while (x>0) {
		ans++;
		x/=10;
	}
	return ans-1;
}


class id8 {
	int len;
	int max_digits;
	int *s;
	
	public:
		id8(int);
		id8(const id8&);
		id8(const string &st);
		id8(double);
		
		~id8();

		void trim();
		
		friend short compare (const id8&,const id8&,int);
		bool equal_null() const;
		id8& operator = (const id8&);
		void expand(int);
		
		friend void sub(const id8&,const id8&,id8 &,int);
		
		friend id8 operator + (const id8&,const id8&);
		friend id8 operator - (const id8&,const id8&);
		friend id8 operator * (const id8&,const id8&);
		friend id8 operator / (const id8&,const id8&);
		friend id8 operator % (const id8&,const id8&);
		
		id8& operator += (const id8&);
		id8& operator -= (const id8&);
		id8& operator *= (const id8&);
		id8& operator /= (const id8&);
		id8& operator %= (const id8&);

		friend ostream& operator << (ostream &stream,const id8&);
		void print_to_str(string &) const;
		friend istream& operator >> (istream &stream,id8&);
		
		void make_shift(int);
		void truncate(int);
		int kol_digits() const;
};

id8::id8(int id10=id14):max_digits(id10),len(1) {
	s=new int[max_digits];
	s[0]=0;
}

id8::id8(const id8& a):max_digits(a.max_digits),len(a.len) {
	s=new int[max_digits];
	for (int i=0; i<max_digits; ++i) s[i]=a.s[i];
}

id8::id8(const string &st) {
	int id12=id2(),n=(int) st.length();
	len=n/id12;
	max_digits=len+(n%id12>0);
	s=new int[max_digits];
	fill(s,s+max_digits,0);
	if (n%id12) for (int i=0; i<n%id12; i++) s[len]=s[len]*10+(st[i]-'0');
	for (int i=1; i<=len; i++)
		for (int j=(i-1)*id12; j<i*id12; j++)
			s[len-i]=s[len-i]*10+(st[j+n%id12]-'0');
	len+=(n%id12>0);
	trim();
}

id8::id8(double x) {
	char st[100];
	string new_st;
	sprintf(st,"%.16e",x);
	int pos_point=-1,i;
	for (i=0; st[i]; ++i)
		if (st[i]=='.') pos_point=i;
		else if (st[i]=='e') break;
		else new_st+=st[i];
	id8 c(new_st);
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

id8::~id8() {
	delete[] s;
}

void id8::trim() {
	while (len>1 && !s[len-1]) --len;
}

short compare (const id8& a,const id8& b,int sp=0) {
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

bool id8::equal_null() const {
	return (len==1) && (!s[0]);
}

void id8::expand(int id10) {
	if (max_digits<id10) {
		int *t=s;
		max_digits=id10;
		s=new int[max_digits];
		for (int i=0; i<len; i++) s[i]=t[i];
		delete [] t;
	}
}

id8& id8::operator = (const id8& a) {
	expand(a.max_digits);
	len=a.len;
	for (int i=0; i<len; ++i) s[i]=a.s[i];
	return *this;
}

id8 operator + (const id8& a,const id8& b) {
	id8 t(a);
	return t+=b;
}
		
id8 operator - (const id8& a,const id8& b) {
	id8 t(a);
	return t-=b;
}

id8 operator * (const id8& a,const id8& b) {
	id8 t(a);
	return t*=b;
}

id8 operator / (const id8& a,const id8& b) {
	id8 t(a);
	return t/=b;
}

id8 operator % (const id8& a,const id8& b) {
	id8 t(a);
	return t%=b;
}

id8& id8::operator += (const id8& b) {
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

id8& id8::operator -= (const id8& b) {
	sub(*this,b,*this,0);
	return *this;
}

id8& id8::operator *= (const id8& b) {
	id8 c(len+b.len);
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

id8& id8::operator /= (const id8& b) {
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
				   id8 ost(*this),c(1);
				   if (compare(ost,b,sp)==LESS) sp--;
				   id8 res(sp+1);
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

id8& id8::operator %= (const id8& b) {
	(*this)-=((*this)/b)*b;
	return *this;
}

void sub(const id8& a,const id8& b,id8 &c,int sp) {
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

ostream& operator << (ostream &stream,const id8& x) {
	int id12=id2();
	stream<<x.s[x.len-1];
	for (int i=x.len-2; i>=0; --i) {
		stream.width(id12);
		stream.fill('0');
		stream<<x.s[i];
	}
	return stream;
}

istream& operator >> (istream &stream,id8& x) {
	string st;
	stream>>st;
	x=st;
	return stream;
}

void id8::make_shift(int sp) {
	int id12=id2();
	int i;
	expand(len+sp/id12+(sp%id12>0));
	for (i=len+sp/id12-1; i>=sp/id12; --i) s[i]=s[i-sp/id12];
	for (i=0; i<sp/id12; ++i) s[i]=0;
	len+=sp/id12;
	sp%=id12;
	i=1;
	while (sp-->0) i*=10;
	id8 c(1);
	c.s[0]=i;
	(*this)*=c;
}

void id8::truncate(int sp) {
	int id12=id2();
	int i;
	for (i=0; i<len-sp/id12; ++i) s[i]=s[i+sp/id12];
	len-=sp/id12;
	i=1;
	sp%=id12;
	while (sp-->0) i*=10;
	id8 c(1);
	c.s[0]=i;
	(*this)/=c;
}

int id8::kol_digits() const {
	int ans=(len-1)*id2();
	int k=s[len-1];
	while (k>0) {
		ans++;
		k/=10;
	}
	return ans;
}

void id8::print_to_str(string &st) const {
	st.clear();
	int id12=id2();
	for (int i=len-1; i>=0; --i) {
		int pos=(int) st.length();
		int x=s[i],kol=0;
		while (x>0) {
			kol++;
			st.insert(st.begin()+pos,(x%10)+'0');
			x/=10;
		}
		if (i!=len-1) {
			kol=id12-kol;
			while (kol-->0) st.insert(st.begin()+pos,'0');
		}
	}
	if (st.empty()) st="0";
}



class id0 {
	id8 s;
	bool sign;

	public:
		id0(int id10=id14):s(id10),sign(false) {}
		id0(const id0& a):sign(a.sign),s(a.s) {}
		id0(const string &st);
		id0(double x):s(fabs(x)),sign(x<0) {}

		friend short compare (const id0&,const id0&);
		bool equal_null() const;
		id0& operator = (const id0&);
		
		friend id0 operator + (const id0&,const id0&);
		friend id0 operator - (const id0&,const id0&);
		friend id0 operator * (const id0&,const id0&);
		friend id0 operator / (const id0&,const id0&);
		friend id0 operator % (const id0&,const id0&);
		
		id0& operator += (const id0&);
		id0& operator -= (const id0&);
		id0& operator *= (const id0&);
		id0& operator /= (const id0&);
		id0& operator %= (const id0&);

		friend ostream& operator << (ostream &stream,const id0&);
		void print_to_str(string &) const;
		friend istream& operator >> (istream &stream,id0&);

		void make_shift(int);
		void truncate(int);
		int kol_digits() const;
};

id0::id0(const string &st) {
	sign=false;
	if (st[0]=='-') {
		sign=true;
		s=st.substr(1,st.length()-1);
	}
	else if (st[0]=='+') s=st.substr(1,st.length()-1);
	else s=st;
	if (equal_null()) sign=false;
}

short compare (const id0& a,const id0& b) {
	if (a.sign && !b.sign) return LESS;
	if (!a.sign && b.sign) return MORE;
	short d=compare(a.s,b.s);
	if (!a.sign && !b.sign) return d;
	return 2-d;
}

id0& id0::operator = (const id0& a) {
	sign=a.sign;
	s=a.s;
	return *this;
}

id0 operator + (const id0& a,const id0& b) {
	id0 t(a);
	return t+=b;
}
		
id0 operator - (const id0& a,const id0& b) {
	id0 t(a);
	return t-=b;
}

id0 operator * (const id0& a,const id0& b) {
	id0 t(a);
	return t*=b;
}

id0 operator / (const id0& a,const id0& b) {
	id0 t(a);
	return t/=b;
}

id0 operator % (const id0& a,const id0& b) {
	id0 t(a);
	return t%=b;
}

id0& id0::operator += (const id0& b) {
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

id0& id0::operator -= (const id0& b) {
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

id0& id0::operator *= (const id0& b) {
	s*=b.s;
	sign=sign!=b.sign;
	if (s.equal_null()) sign=false;
	return *this;
}

id0& id0::operator /= (const id0& b) {
	s/=b.s;
	sign=sign!=b.sign;
	if (s.equal_null()) sign=false;
	return *this;
}

id0& id0::operator %= (const id0& b) {
	(*this)-=((*this)/b)*b;
	if (s.equal_null()) sign=false;
	return *this;
}

ostream& operator << (ostream &stream,const id0& x) {
	if (x.sign) stream<<'-';
	stream<<x.s;
	return stream;
}

istream& operator >> (istream &stream,id0& x) {
	string st;
	stream>>st;
	x=st;
	return stream;
}

void id0::make_shift(int sp) {
	s.make_shift(sp);
}

void id0::truncate(int sp) {
	s.truncate(sp);
}

int id0::kol_digits() const {
	return s.kol_digits();
}

bool id0::equal_null() const {
	return s.equal_null();
}

void id0::print_to_str(string &st) const {
	st.clear();
	if (sign) st+='-';
	string st1;
	s.print_to_str(st1);
	st+=st1;
}

bool operator < (const id0 & A, const id0 & B) {
    return compare(A,B) == LESS;
}


id0 LL_INF("2000000000000000000");
id0 LL_NULL("0");

id0 gcd(id0 a, id0 b) {
    while (!a.equal_null() && !b.equal_null())
        if (compare(a, b) == MORE) a %= b;
        else b %= a;
    return a+b;
}

id0 my_abs(id0 x) {
    if (compare(x, LL_NULL) == LESS) return -1.0 * x;
    return x;
}

id0 gcd (id0 a, id0 b, id0 & x, id0 & y) {
    if (a.equal_null()) {
		x = 0.0; y = 1.0;
		return b;
	}
	id0 x1, y1;
	id0 d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool id6 (id0 a, id0 b, id0 c, id0 & x0, id0 & y0, id0 & g) {
	g = gcd (my_abs(a), my_abs(b), x0, y0);
    if (!(c % g).equal_null())
		return false;
	x0 *= c / g;
	y0 *= c / g;
    if (compare(a, LL_NULL) == LESS)   x0 *= -1.0;
	if (compare(b, LL_NULL) == LESS)   y0 *= -1.0;
	return true;
}

void shift_solution (id0 & x, id0 & y, id0 a, id0 b, id0 cnt) {
	x += cnt * b;
	y -= cnt * a;
}
 
int id9 (id0 a, id0 b, id0 c, id0 minx, id0 maxx, id0 miny, id0 maxy,
                              id0 & lx, id0 & rx) {
	id0 x, y, g;
	if (! id6 (a, b, c, x, y, g))
		return 0;
	a /= g;  b /= g;
 
    id0 sign_a = (compare(a,LL_NULL) == MORE) ? +1.0 : -1.0;
    id0 sign_b = (compare(b,LL_NULL) == MORE) ? +1.0 : -1.0;
 
	shift_solution (x, y, a, b, (minx - x) / b);
	if (compare(x , minx) == LESS)
		shift_solution (x, y, a, b, sign_b);
	if (compare(x , maxx) == MORE)
		return 0;
	id0 lx1 = x;
 
	shift_solution (x, y, a, b, (maxx - x) / b);
	if (compare(x , maxx) == MORE)
		shift_solution (x, y, a, b, -1.0 * sign_b);
	id0 rx1 = x;
 
	shift_solution (x, y, a, b, -1.0 *  (miny - y) / a);
	if (compare(y , miny) == LESS)
		shift_solution (x, y, a, b, -1.0 * sign_a);
	if (compare(y , maxy) == MORE)
		return 0;
	id0 lx2 = x;
 
	shift_solution (x, y, a, b, -1.0 * (maxy - y) / a);
	if (compare(y , maxy) == MORE)
		shift_solution (x, y, a, b, sign_a);
	id0 rx2 = x;
 
	if (compare(lx2 , rx2) == MORE)
		swap (lx2, rx2);
	
    lx = max (lx1, lx2);
	rx = min (rx1, rx2);

    return 1;
}

long long const MAX_IT = 1;
long long const MXD = 1;

void id5(id0 lx, id0 rx, id0 id7, id0 id3, id0 val, id0 & min_sum, int dir) {
    if (compare(lx , rx) == MORE)
        return;

    if (dir == +1) {
        id0 id4 = LL_INF;
        long long ITER = 0;
        for (id0 qq = lx; compare(qq , rx) != MORE && ITER < MAX_IT; qq += 1.0, ITER++) {
            id0 rem = val - qq * id7;
            if ((rem % id3).equal_null()) {
                id4 = qq;
                break;
            }
        }

        if (compare(id4 , LL_INF / 2.0) != LESS)
            return;

        id0 id13 = my_abs(id3);
        ITER = 0;
        for (id0 x = id4; compare(x , rx) != MORE && ITER < MAX_IT; x += id13, ITER++) {
            id0 y = (val - x * id7);
            if ((y % id3).equal_null()) {
                y /= id3;
                if (compare(x , LL_NULL) != LESS && compare(y , LL_NULL) != LESS)
                    min_sum = min(min_sum, x+y);
            }
        }
    }
    else if (dir == -1) {
        id0 id4 = LL_INF;
        long long ITER = 0;
        for (id0 qq = rx; compare(qq , lx) != LESS && ITER < MAX_IT; qq -= 1.0, ITER++) {
            id0 rem = val - qq * id7;
            if ((rem % id3).equal_null()) {
                id4 = qq;
                break;
            }
        }

        if (compare(id4 , LL_INF / 2.0) != LESS)
            return;

        id0 id13 = my_abs(id3);
        ITER = 0;
        for (id0 x = id4; compare(x , lx) != LESS && ITER < MAX_IT; x -= id13, ITER++) {
            id0 y = (val - x * id7);
            if ((y % id3).equal_null()) {
                y /= id3;
                if (compare(x , LL_NULL) != LESS && compare(y , LL_NULL) != LESS)
                    min_sum = min(min_sum, x+y);
            }
        }
    }
    else {
    }
}

void id1(id0 x_ap, id0 id7, id0 id3, id0 val, id0 & min_sum) {
    id0 id13 = my_abs(id3);
    for (id0 dx = -1.0 * MXD; compare(dx , (double) MXD) != MORE; dx += 1.0) {
        id0 x = x_ap + id13 * dx;

        id0 y = (val - x * id7);
        if ((y % id3).equal_null()) {
            y /= id3;
            if (compare(x , LL_NULL) != LESS && compare(y , LL_NULL) != LESS)
                min_sum = min(min_sum, x+y);
        }
    }
}

int main() {
	

	


	int t;
    scanf("%d",&t);
    while (t-->0) {
        id0 x,y,p,q;
        cin>>x>>y>>p>>q;

        if (compare(x,p) == EQUAL && compare(y,q) == EQUAL) {
            printf("0\n");
            continue;
        }

        id0 val = p*y-q*x;

        if (val.equal_null()) {
            printf("0\n");
            continue;
        }

        id0 id7 = q-p;
        id0 id3 = -1.0 * p;

        

        

        

        


        id0 x0,y0,gg;
        bool res = id6(id7,id3,val,   x0,y0,gg);

        if (res == false) {
            printf("-1\n");
            continue;
        }

        if (id7.equal_null()) {
            if (!(val % id3).equal_null()) {
                printf("-1\n");
                continue;
            }

            if (compare(val / id3, LL_NULL) == LESS) {
                printf("-1\n");
                continue;
            }

            cout<<(val / id3)<<"\n";
            continue;
        }
        else if (id3.equal_null()) {
            if (!(val % id7).equal_null()) {
                printf("-1\n");
                continue;
            }

            if (compare(val / id7, LL_NULL) == LESS) {
                printf("-1\n");
                continue;
            }

            cout<<(val / id7)<<"\n";
            continue;
        }
        else {
            id0 lx,rx;

            id0 min_sum = LL_INF;

            if (id9(id7, id3, val, 0.0, LL_INF + 1000000.0, 0.0, LL_INF + 1000000.0, lx, rx)) {
                id5(lx,rx,id7,id3,val,min_sum,+1);
                id5(lx,rx,id7,id3,val,min_sum,-1);
                id5(lx,rx,id7,id3,val,min_sum,0);

                id0 a = id7;
                id0 b = id3;
                id0 c = val;

                if (compare(a, b) == LESS)
                    id1((lx-x0)/(b/gg) * (b/gg) + x0, a,b,c, min_sum);
                else if (compare(a, b) == MORE)
                    id1((rx-x0)/(b/gg) * (b/gg) + x0, a,b,c, min_sum);
            }

            if (compare(min_sum , LL_INF / 2.0) != LESS)
                printf("-1\n");
            else
                cout<<min_sum<<"\n";
        }
    }
	return 0;
}