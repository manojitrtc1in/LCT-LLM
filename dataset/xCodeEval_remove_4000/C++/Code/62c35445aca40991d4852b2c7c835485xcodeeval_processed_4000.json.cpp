
























































using namespace std;
typedef long long LL;
const int N=5e5+5;
const int M=3e5+5;
inline int qr(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') (ch=='-'?f=-1:1),ch=getchar();
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline void qw(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) qw(x/10);
	putchar(x%10+'0');
}
int n,m,pre[N],nxt[N],id[N],ans[M],len,L=1,R,cnt,add[2][2][2][2][2][2],sub[2][2][2][2][2][2],due;
bool vis[3][N];
struct Q{
	int l,r,pos;
	bool operator<(const Q &P)const{
		return id[l]==id[P.l]?(id[l]&1?r<P.r:r>P.r):id[l]<id[P.l];
	}
}q[M];
int f(int l,int x,int y,int z){
	return (vis[0][l]==x && vis[1][l]==y && vis[2][l]==z);
}
inline void fsub(){
	

	sub[0][0][0][0][0][1]=-1;
	sub[0][0][0][0][1][0]=-1;
	sub[0][0][0][1][0][0]=-1;
	sub[0][0][0][1][1][0]=-1;
	sub[0][0][0][0][1][1]=-1;
	sub[0][0][0][1][0][1]=-2;
	sub[0][0][0][1][1][1]=-1;
	

	sub[0][0][1][0][1][0]=-1;
	sub[0][0][1][1][0][0]=-1;
	sub[0][0][1][1][1][0]=-1;
	sub[0][0][1][1][0][1]=-1;
	

	sub[0][1][0][0][0][1]=-1;
	sub[0][1][0][1][0][0]=-1;
	sub[0][1][0][1][0][1]=-2;
	

	sub[1][0][0][0][0][1]=-1;
	sub[1][0][0][0][1][0]=-1;
	sub[1][0][0][0][1][1]=-1;
	sub[1][0][0][1][0][1]=-1;
	

	sub[1][1][0][0][0][1]=-1;
	sub[1][1][0][1][0][1]=-1;
	

	sub[0][1][1][1][0][0]=-1;
	sub[0][1][1][1][0][1]=-1;
	

	sub[1][0][1][0][1][0]=-1;
}
inline void fadd(){
	

	add[0][0][0][0][0][1]=1;
	add[0][0][0][0][1][0]=1;
	add[0][0][0][1][0][0]=1;
	add[0][0][0][1][1][0]=1;
	add[0][0][0][0][1][1]=1;
	add[0][0][0][1][0][1]=2;
	add[0][0][0][1][1][1]=1;
	

	add[0][0][1][0][1][0]=1;
	add[0][0][1][1][0][0]=1;
	add[0][0][1][1][1][0]=1;
	add[0][0][1][1][0][1]=1;
	

	add[0][1][0][0][0][1]=1;
	add[0][1][0][1][0][0]=1;
	add[0][1][0][1][0][1]=2;
	

	add[1][0][0][0][0][1]=1;
	add[1][0][0][0][1][0]=1;
	add[1][0][0][0][1][1]=1;
	add[1][0][0][1][0][1]=1;
	

	add[1][1][0][0][0][1]=1;
	add[1][1][0][1][0][1]=1;
	

	add[0][1][1][1][0][0]=1;
	add[0][1][1][1][0][1]=1;
	

	add[1][0][1][0][1][0]=1;
}
inline void subr(){
	if(f(R,1,1,1) && f(R-1,1,0,1)){
		if(pre[R-1]<L) cnt++;
	}
	else cnt+=sub[vis[0][R-1]][vis[1][R-1]][vis[2][R-1]][vis[0][R]][vis[1][R]][vis[2][R]];
	--R;
}
inline void subl(){
	if(f(L+1,1,0,1)  && f(L,1,1,1)){
		if(nxt[L+1]>R) cnt++;
	}
	else cnt+=sub[vis[0][L+1]][vis[1][L+1]][vis[2][L+1]][vis[0][L]][vis[1][L]][vis[2][L]];
	++L;
}
inline void addr(){
	if(f(R,1,0,1) && f(R+1,1,1,1)){
		if(pre[R]<L) cnt--;
	}
	else cnt+=add[vis[0][R]][vis[1][R]][vis[2][R]][vis[0][R+1]][vis[1][R+1]][vis[2][R+1]];
	++R;
}
inline void addl(){
	if(f(L,1,0,1) && f(L-1,1,1,1)){
		if(nxt[L]>R) cnt--;
	}
	else cnt+=add[vis[0][L]][vis[1][L]][vis[2][L]][vis[0][L-1]][vis[1][L-1]][vis[2][L-1]];
	--L;
}
namespace Fast_I {
    char *_Buf, *_Start_ptr, *_End_ptr;
    std::streambuf* inbuf;
    unsigned int Size;
    bool _Ok;

    struct id6 {
        operator bool() {
            return _Ok;
        }
        id6(std::streambuf*, unsigned int);
        id6(unsigned int);
        id6(const char*, unsigned int);
        id6& operator>>(char&);
        id6& operator>>(char*);
        id6& operator>>(bool&);
        id6& operator>>(short&);
        id6& operator>>(int&);
        id6& operator>>(long&);
        id6& operator>>(long long&);
        id6& operator>>(unsigned short&);
        id6& operator>>(unsigned int&);
        id6& operator>>(unsigned long&);
        id6& operator>>(unsigned long long&);
        id6& operator>>(float&);
        id6& operator>>(double&);
        id6& operator>>(long double&);
        id6& operator>>(std::string&);
        template <typename Typex>
        void operator()(Typex& _Val) {
            *this >> _Val;
        }
        template <typename Typex, typename... More>
        void operator()(Typex&, More&...);
        std::streambuf* rdbuf() {
            return inbuf;
        }
        void rdbuf(std::streambuf* _inbuf) {
            inbuf = _inbuf;
        }
        void rdbuf(const char*);
        void pop();
        char peek();
    };
}  

namespace Fast_O {
    std::string buf;
    std::streambuf* outbuf;

    struct id3 {
        id3(std::streambuf*, unsigned int);
        id3(std::streambuf* out) {
            outbuf = out;
        }
        id3(const char*, unsigned int);
        id3(unsigned int);
        void flush();
        ~id3();
        void endl() {
            buf.push_back('\n');
        }
        template <typename Typex>
        void endl(const Typex& _Val);
        template <typename Typex, typename... More>
        void endl(const Typex&, const More&...);
        template <typename Typex>
        void operator()(const Typex& _Val);
        template <typename Typex, typename... More>
        void operator()(const Typex&, const More&...);
        id3& operator<<(char);
        id3& operator<<(const char*);
        id3& operator<<(const std::string&);
        id3& operator<<(bool);
        id3& operator<<(short);
        id3& operator<<(int);
        id3& operator<<(long);
        id3& operator<<(long long);
        id3& operator<<(unsigned short);
        id3& operator<<(unsigned int);
        id3& operator<<(unsigned long);
        id3& operator<<(unsigned long long);
        std::streambuf* rdbuf() {
            return outbuf;
        }
        void rdbuf(std::streambuf* _outbuf) {
            outbuf = _outbuf;
        }
        void rdbuf(const char*);
    };
}  

namespace Fast_IO {
    Fast_I::id6 fin(std::cin.rdbuf(), 1048576);  

    Fast_O::id3 fout(std::cout.rdbuf());         

}  







namespace Fast_I {
    id6::id6(std::streambuf* in, unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        inbuf = in;
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    id6::id6(const char* in, unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        rdbuf(in);
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    id6::id6(unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    void id6::rdbuf(const char* File) {
        static std::ifstream id4(File);
        rdbuf(id4.rdbuf());
    }
    void id7(char& _Val) {
        if (_Start_ptr == _End_ptr) {
            _Start_ptr = _Buf;
            _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
        }
        if (_Start_ptr == _End_ptr) {
            _Val = -1;
            _Ok = 0;
        } else {
            _Val = *_Start_ptr++;
        }
    }
    id6& id6::operator>>(char& _Val) {
        if (_Ok) {
            id7(_Val);
            while (_Val == 32 || _Val == 10 || _Val == 13 || _Val == 8 || _Val == 9 ||
                    _Val == 7 || _Val == 12 || _Val == 11) {
                id7(_Val);
            }
        }
        return *this;
    }
    id6& id6::operator>>(char* _Val) {
        if (_Ok) {
            id7(*_Val);
            while (*_Val == 32 || *_Val == 10 || *_Val == 13 || *_Val == 8 ||
                    *_Val == 9 || *_Val == 7 || *_Val == 12 || *_Val == 11) {
                id7(*_Val);
            }
            while (*_Val != 32 && *_Val != 10 && *_Val && *_Val != -1 && *_Val != 9 &&
                    *_Val != 11 && *_Val != 12) {
                id7(*++_Val);
            }
            *_Val = 0;
            --_Start_ptr;
        }
        return *this;
    }
    id6& id6::operator>>(std::string& _Val) {
        if (_Ok) {
            char c;
            id7(c);
            while (c == 32 || c == 10 || c == 13 || c == 8 || c == 9 || c == 7 ||
                    c == 12 || c == 11) {
                id7(c);
            }
            for (_Val.clear();
                    c != 32 && c != 10 && c && c != -1 && c != 9 && c != 11 && c != 12;
                    id7(c)) {
                _Val.push_back(c);
            }
            --_Start_ptr;
        }
        return *this;
    }
    template <typename Typex>
    void Get_Int(Typex& _Val) {
        if (_Ok) {
            char ch;
            bool _F = 0;
            for (id7(ch); (ch < 48 || ch > 57) && ch != -1; id7(ch)) {
                _F = ch == 45;
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            if (_F) {
                _Val = ~_Val + 1;
            }
            --_Start_ptr;
        }
    }
    template <typename Typex>
    void id2(Typex& _Val) {
        if (_Ok) {
            char ch;
            id7(ch);
            while ((ch < 48 || ch > 57) && ch != -1) {
                id7(ch);
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            --_Start_ptr;
        }
    }
    template <typename Typex>
    void id1(Typex& _Val) {
        if (_Ok) {
            char ch;
            bool _F = 0;
            for (id7(ch); (ch < 48 || ch > 57) && ch != -1; id7(ch)) {
                _F = ch == 45;
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            if (ch == 46) {
                unsigned long long _Pow = 1;
                for (id7(ch); ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                    _Val += Typex((ch ^ 48) * 1.0 / (_Pow *= 10));
                }
            }
            if (_F) {
                _Val = -_Val;
            }
            --_Start_ptr;
        }
    }
    id6& id6::operator>>(bool& _Val) {
        if (_Ok) {
            char ch;
            id7(ch);
            while (ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 || ch == 7 ||
                    ch == 12 || ch == 11) {
                id7(ch);
            }
            while (ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
                    ch != 12) {
                _Val |= ch != 48;
                id7(ch);
            }
            --_Start_ptr;
        }
        return *this;
    }
    id6& id6::operator>>(short& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(int& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(long& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(long long& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned short& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned int& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned long& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned long long& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(float& _Val) {
        id1(_Val);
        return *this;
    }
    id6& id6::operator>>(double& _Val) {
        id1(_Val);
        return *this;
    }
    id6& id6::operator>>(long double& _Val) {
        id1(_Val);
        return *this;
    }
    template <typename Typex, typename... More>
    void id6::operator()(Typex& _Val, More&... _More) {
        *this >> _Val;
        operator()(_More...);
    }
    void id6::pop() {
        char ch;
        id7(ch);
    }
    char id6::peek() {
        if (_Start_ptr == _End_ptr) {
            _Start_ptr = _Buf;
            _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
        }
        if (_Start_ptr == _End_ptr) {
            _Ok = 0;
            return -1;
        } else {
            return *_Start_ptr;
        }
    }
}  

namespace Fast_O {
    id3::id3(std::streambuf* out, unsigned int Size) {
        buf.reserve(Size);
        outbuf = out;
    }
    id3::id3(const char* File, unsigned int Size) {
        buf.reserve(Size);
        rdbuf(File);
    }
    void id3::rdbuf(const char* File) {
        static std::ofstream id0(File);
        rdbuf(id0.rdbuf());
    }
    id3::id3(unsigned int Size) {
        buf.reserve(Size);
    }
    void id3::flush() {
        outbuf->sputn(buf.data(), buf.size());
        buf.clear();
    }
    id3::~id3() {
        flush();
    }
    id3& id3::operator<<(char _Val) {
        buf.push_back(_Val);
        return *this;
    }
    id3& id3::operator<<(const char* _Val) {
        while (*_Val) {
            buf.push_back(*_Val++);
        }
        return *this;
    }
    id3& id3::operator<<(const std::string& _Val) {
        for (auto&& i : _Val) {
            buf.push_back(i);
        }
        return *this;
    }
    template <typename Typex>
    void id5(Typex _Val) {
        char* _Stack = (char*)malloc(sizeof(Typex) * 3);
        unsigned S_top = 0;
        while (_Val) {
            _Stack[++S_top] = (_Val % 10) ^ 48;
            _Val /= 10;
        }
        if (!S_top) {
            buf.push_back('0');
        }
        while (S_top) {
            buf.push_back(_Stack[S_top--]);
        }
        free(_Stack);
    }
    void Put_Int(long long _Val) {
        if (_Val < 0) {
            buf.push_back('-');
            id5(~_Val + 1);
        } else {
            id5(_Val);
        }
    }
    id3& id3::operator<<(bool _Val) {
        buf.push_back(_Val ? '1' : '0');
        return *this;
    }
    id3& id3::operator<<(short _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(int _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(long _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(long long _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned short _Val) {
        id5(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned int _Val) {
        id5(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned long _Val) {
        id5(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned long long _Val) {
        id5(_Val);
        return *this;
    }
    template <typename Typex>
    void id3::endl(const Typex& _Val) {
        *this << _Val << '\n';
    }
    template <typename Typex, typename... More>
    void id3::endl(const Typex& _Val, const More&... _More) {
        *this << _Val;
        endl(_More...);
    }
    template <typename Typex>
    void id3::operator()(const Typex& _Val) {
        *this << _Val;
    }
    template <typename Typex, typename... More>
    void id3::operator()(const Typex& _Val, const More&... _More) {
        *this << _Val;
        operator()(_More...);
    }
}  


int main(){




	cin>>n;
	len=sqrt(n);
	for(register int i=1;i<=n;++i){
		due++;
		id[i]=id[i-1];
		if(due==len) id[i]++,due=0;
	}
	for(register int i=0;i<3;++i){
		for(register int j=1;j<=n;++j){
			char x;
			cin>>x;
			vis[i][j]=x-'0';
		}
	}
	fadd(),fsub();
	for(register int i=1;i<=n;++i){
		nxt[i]=n+1; 
		if(vis[0][i] && !vis[1][i] && vis[2][i]){
			register int j=i+1;
			for(;j<=n;++j){
				if(vis[0][j] && vis[1][j] && vis[2][j]){
					nxt[i]=j;
					break;
				}
				if(!vis[0][j] || vis[1][j] || !vis[2][j]) break;
			}
			for(register int k=i+1;k<j;++k) nxt[k]=nxt[i];
			i=j-1;
		}
	}
	for(register int i=n;i;--i){
		if(vis[0][i] && !vis[1][i] && vis[2][i]){
			register int j=i-1;
			for(;j;--j){
				if(vis[0][j] && vis[1][j] && vis[2][j]){
					pre[i]=j;
					break;
				}
				if(!vis[0][j] || vis[1][j] || !vis[2][j]) break;
			}
			for(register int k=i+1;k<j;++k) pre[k]=pre[i];
			i=j+1;
		}
	}


	cin>>m;
	for(register int i=1;i<=m;++i){
		cin>>q[i].l>>q[i].r;
		q[i].pos=i;
	}
	sort(q+1,q+1+m);


	for(register int i=1;i<=m;++i){
		while(q[i].l>L) subl();
		while(q[i].r>R) addr();
		while(q[i].l<L) addl();
		while(q[i].r<R) subr();
		ans[q[i].pos]=cnt;
	}
	for(register int i=1;i<=m;++i) cout.endl(ans[i]); 
	return 0;
}