


using namespace std;


long long input(){

	long long a;
	cin>>a;
	return(a);
}
unsigned long long uinput(){

	unsigned long long a;
	cin>>a;
	return(a);
}
long double finput(){

	long double a;
	cin>>a;
	return(a);
}
string sinput(){
	string a;
	getline(cin,a);
	return(a);
}


void print(string end="\n"){
	cout<<end;
}
template<typename T>
void print(T a,string end="\n"){
	cout<<a<<end;
}
template<typename T>
void print(T a,T b,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<end;
}
template<typename T>
void print(T a,T b,T c,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<end;
}
template<typename T>
void print(T a,T b,T c,T d,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,T i,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<sep<<i<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,T i,T j,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<sep<<i<<sep<<j<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,T i,T j,T k,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<sep<<i<<sep<<j<<sep<<k<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,T i,T j,T k,T l,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<sep<<i<<sep<<j<<sep<<k<<sep<<l<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,T i,T j,T k,T l,T m,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<sep<<i<<sep<<j<<sep<<k<<sep<<l<<sep<<m<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,T i,T j,T k,T l,T m,T n,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<sep<<i<<sep<<j<<sep<<k<<sep<<l<<sep<<m<<sep<<n<<end;
}
template<typename T>
void print(T a,T b,T c,T d,T e,T f,T g,T h,T i,T j,T k,T l,T m,T n,T o,string end="\n",string sep=" "){
	cout<<a<<sep<<b<<sep<<c<<sep<<d<<sep<<e<<sep<<f<<sep<<g<<sep<<h<<sep<<i<<sep<<j<<sep<<k<<sep<<l<<sep<<m<<sep<<n<<sep<<o<<end;
}































long long udiv(long long a,long long b){
	if (a%b==0){
		return a/b;
	}
	else{
		return a/b+1;
	}
}
template<typename T>
ll len(T a){
	return a.size();
}


std::vector<int> operator+(const std::vector<int> & a,const std::vector<int> &b){
	vector<int> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}




















std::vector<long> operator+(const std::vector<long> & a,const std::vector<int> &b){
	vector<long> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<long> operator+(const std::vector<int> & a,const std::vector<long> &b){
	vector<long> c;
	forin(i,a){
		c.append(i);
	}
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<long> operator+(const std::vector<long> & a,const std::vector<long> &b){
	vector<long> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}








































std::vector<ll> operator+(const std::vector<ll> & a,const std::vector<ll> &b){
	vector<ll> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<ll> operator+(const std::vector<ll> & a,const std::vector<int> &b){
	vector<ll> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<ll> operator+(const std::vector<int> & a,const std::vector<ll> &b){
	vector<ll> c;
	forin(i,a){
		c.append(i);
	}
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<ll> operator+(const std::vector<ll> & a,const std::vector<long> &b){
	vector<ll> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<ll> operator+(const std::vector<long> & a,const std::vector<ll> &b){
	vector<ll> c;
	forin(i,a){
		c.append(i);
	}
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<float> operator+(const std::vector<float> & a,const std::vector<float> &b){
	vector<float> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}




















std::vector<double> operator+(const std::vector<double> & a,const std::vector<float> &b){
	vector<double> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<double> operator+(const std::vector<float> & a,const std::vector<double> &b){
	vector<double> c;
	forin(i,a){
		c.append(i);
	}
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<double> operator+(const std::vector<double> & a,const std::vector<double> &b){
	vector<double> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}








































std::vector<long double> operator+(const std::vector<long double> & a,const std::vector<long double> &b){
	vector<long double> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<long double> operator+(const std::vector<long double> & a,const std::vector<float> &b){
	vector<long double> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<long double> operator+(const std::vector<float> & a,const std::vector<long double> &b){
	vector<long double> c;
	forin(i,a){
		c.append(i);
	}
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<long double> operator+(const std::vector<long double> & a,const std::vector<double> &b){
	vector<long double> c=a;
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<long double> operator+(const std::vector<double> & a,const std::vector<long double> &b){
	vector<long double> c;
	forin(i,a){
		c.append(i);
	}
	forin(i,b){
		c.append(i);
	}
	return c;
}
std::vector<int> operator*(const std::vector<int> &a,long long b){
	std::vector<int> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<long> operator*(const std::vector<long> &a,long long b){
	std::vector<long> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<ll> operator*(const std::vector<ll> &a,long long b){
	std::vector<ll> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<float> operator*(const std::vector<float> &a,long long b){
	std::vector<float> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<double> operator*(const std::vector<double> &a,long long b){
	std::vector<double> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<long double> operator*(const std::vector<long double> &a,long long b){
	std::vector<long double> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<string> operator*(const std::vector<string> &a,long long b){
	std::vector<string> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<std::vector<int>> operator*(const std::vector<std::vector<int>> &a,long long b){
	std::vector<std::vector<int>> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<std::vector<long>> operator*(const std::vector<std::vector<long>> &a,long long b){
	std::vector<std::vector<long>> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<std::vector<long long>> operator*(const std::vector<std::vector<long long>> &a,long long b){
	std::vector<std::vector<long long>> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<std::vector<float>> operator*(const std::vector<std::vector<float>> &a,long long b){
	std::vector<std::vector<float>> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<std::vector<double>> operator*(const std::vector<std::vector<double>> &a,long long b){
	std::vector<std::vector<double>> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<std::vector<ld>> operator*(const std::vector<std::vector<ld>> &a,long long b){
	std::vector<std::vector<ld>> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}
std::vector<std::vector<string>> operator*(const std::vector<std::vector<string>> &a,long long b){
	std::vector<std::vector<string>> c=a;
	for1(i,b-1){
		forin(i,a){
			c.append(i);
		}
	}
	return c;
}

ld ans=0;

void pro(ld a,ld b,ld c, ld v,ld r,ld p){
    if (a<-1){}
    elif (a>v){
        if (b>-1)
            pro(a-v,b+v/2,c+v/2,v,r+1,p*a/1000000000);
        else
            pro(a-v,b,c+v,v,r+1,p*a/1000000000);
    }
    else{
        if (b>-1)
            pro(-9999999999,b+a/2,c+a/2,v,r+1,p*a/1000000000);
        else
            pro(-9999999999,b,c+a,v,r+1,p*a/1000000000);
    }

    if (b<=-1){}
    elif (b>v){
        if (a>-1)
            pro(a+v/2,b-v,c+v/2,v,r+1,p*b/1000000000);
        else
            pro(a,b-v,c+v,v,r+1,p*b/1000000000);
    }
    else{
        if (a>-1)
            pro(a+b/2,-9999999999,c+b/2,v,r+1,p*b/1000000000);
        else
            pro(a,-9999999999,c+b,v,r+1,p*b/1000000000);
    }
    c/=1000000000;
    ans+=r*c*p;
    

}

main(){
    fort{
        ans=0;
        ld c,m,p,v;
        cin>>c>>m>>p>>v;
        c*=1000000000;
        m*=1000000000;
        p*=1000000000;
        v*=1000000000;
        pro(c,m,p,v,1,1);
        std::cout << std::fixed;
        std::cout << std::setprecision(10);
        print(ans);
    }
}