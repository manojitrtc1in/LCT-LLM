#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Os")
#pragma GCC optimize("Og")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>


#define mem(a,x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
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

    struct Fast_Istream {
        operator bool() {
            return _Ok;
        }
        Fast_Istream(std::streambuf*, unsigned int);
        Fast_Istream(unsigned int);
        Fast_Istream(const char*, unsigned int);
        Fast_Istream& operator>>(char&);
        Fast_Istream& operator>>(char*);
        Fast_Istream& operator>>(bool&);
        Fast_Istream& operator>>(short&);
        Fast_Istream& operator>>(int&);
        Fast_Istream& operator>>(long&);
        Fast_Istream& operator>>(long long&);
        Fast_Istream& operator>>(unsigned short&);
        Fast_Istream& operator>>(unsigned int&);
        Fast_Istream& operator>>(unsigned long&);
        Fast_Istream& operator>>(unsigned long long&);
        Fast_Istream& operator>>(float&);
        Fast_Istream& operator>>(double&);
        Fast_Istream& operator>>(long double&);
        Fast_Istream& operator>>(std::string&);
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

    struct Fast_Ostream {
        Fast_Ostream(std::streambuf*, unsigned int);
        Fast_Ostream(std::streambuf* out) {
            outbuf = out;
        }
        Fast_Ostream(const char*, unsigned int);
        Fast_Ostream(unsigned int);
        void flush();
        ~Fast_Ostream();
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
        Fast_Ostream& operator<<(char);
        Fast_Ostream& operator<<(const char*);
        Fast_Ostream& operator<<(const std::string&);
        Fast_Ostream& operator<<(bool);
        Fast_Ostream& operator<<(short);
        Fast_Ostream& operator<<(int);
        Fast_Ostream& operator<<(long);
        Fast_Ostream& operator<<(long long);
        Fast_Ostream& operator<<(unsigned short);
        Fast_Ostream& operator<<(unsigned int);
        Fast_Ostream& operator<<(unsigned long);
        Fast_Ostream& operator<<(unsigned long long);
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
    Fast_I::Fast_Istream fin(std::cin.rdbuf(), 1048576);  

    Fast_O::Fast_Ostream fout(std::cout.rdbuf());         

}  


#define cin Fast_IO::fin
#define cout Fast_IO::fout



namespace Fast_I {
    Fast_Istream::Fast_Istream(std::streambuf* in, unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        inbuf = in;
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    Fast_Istream::Fast_Istream(const char* in, unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        rdbuf(in);
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    Fast_Istream::Fast_Istream(unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    void Fast_Istream::rdbuf(const char* File) {
        static std::ifstream __In__(File);
        rdbuf(__In__.rdbuf());
    }
    void Get_Char(char& _Val) {
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
    Fast_Istream& Fast_Istream::operator>>(char& _Val) {
        if (_Ok) {
            Get_Char(_Val);
            while (_Val == 32 || _Val == 10 || _Val == 13 || _Val == 8 || _Val == 9 ||
                    _Val == 7 || _Val == 12 || _Val == 11) {
                Get_Char(_Val);
            }
        }
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(char* _Val) {
        if (_Ok) {
            Get_Char(*_Val);
            while (*_Val == 32 || *_Val == 10 || *_Val == 13 || *_Val == 8 ||
                    *_Val == 9 || *_Val == 7 || *_Val == 12 || *_Val == 11) {
                Get_Char(*_Val);
            }
            while (*_Val != 32 && *_Val != 10 && *_Val && *_Val != -1 && *_Val != 9 &&
                    *_Val != 11 && *_Val != 12) {
                Get_Char(*++_Val);
            }
            *_Val = 0;
            --_Start_ptr;
        }
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(std::string& _Val) {
        if (_Ok) {
            char c;
            Get_Char(c);
            while (c == 32 || c == 10 || c == 13 || c == 8 || c == 9 || c == 7 ||
                    c == 12 || c == 11) {
                Get_Char(c);
            }
            for (_Val.clear();
                    c != 32 && c != 10 && c && c != -1 && c != 9 && c != 11 && c != 12;
                    Get_Char(c)) {
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
            for (Get_Char(ch); (ch < 48 || ch > 57) && ch != -1; Get_Char(ch)) {
                _F = ch == 45;
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            if (_F) {
                _Val = ~_Val + 1;
            }
            --_Start_ptr;
        }
    }
    template <typename Typex>
    void Get_Unsigned(Typex& _Val) {
        if (_Ok) {
            char ch;
            Get_Char(ch);
            while ((ch < 48 || ch > 57) && ch != -1) {
                Get_Char(ch);
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            --_Start_ptr;
        }
    }
    template <typename Typex>
    void Get_Double(Typex& _Val) {
        if (_Ok) {
            char ch;
            bool _F = 0;
            for (Get_Char(ch); (ch < 48 || ch > 57) && ch != -1; Get_Char(ch)) {
                _F = ch == 45;
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            if (ch == 46) {
                unsigned long long _Pow = 1;
                for (Get_Char(ch); ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
                    _Val += Typex((ch ^ 48) * 1.0 / (_Pow *= 10));
                }
            }
            if (_F) {
                _Val = -_Val;
            }
            --_Start_ptr;
        }
    }
    Fast_Istream& Fast_Istream::operator>>(bool& _Val) {
        if (_Ok) {
            char ch;
            Get_Char(ch);
            while (ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 || ch == 7 ||
                    ch == 12 || ch == 11) {
                Get_Char(ch);
            }
            while (ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
                    ch != 12) {
                _Val |= ch != 48;
                Get_Char(ch);
            }
            --_Start_ptr;
        }
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(short& _Val) {
        Get_Int(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(int& _Val) {
        Get_Int(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(long& _Val) {
        Get_Int(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(long long& _Val) {
        Get_Int(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(unsigned short& _Val) {
        Get_Unsigned(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(unsigned int& _Val) {
        Get_Unsigned(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(unsigned long& _Val) {
        Get_Unsigned(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(unsigned long long& _Val) {
        Get_Unsigned(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(float& _Val) {
        Get_Double(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(double& _Val) {
        Get_Double(_Val);
        return *this;
    }
    Fast_Istream& Fast_Istream::operator>>(long double& _Val) {
        Get_Double(_Val);
        return *this;
    }
    template <typename Typex, typename... More>
    void Fast_Istream::operator()(Typex& _Val, More&... _More) {
        *this >> _Val;
        operator()(_More...);
    }
    void Fast_Istream::pop() {
        char ch;
        Get_Char(ch);
    }
    char Fast_Istream::peek() {
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
    Fast_Ostream::Fast_Ostream(std::streambuf* out, unsigned int Size) {
        buf.reserve(Size);
        outbuf = out;
    }
    Fast_Ostream::Fast_Ostream(const char* File, unsigned int Size) {
        buf.reserve(Size);
        rdbuf(File);
    }
    void Fast_Ostream::rdbuf(const char* File) {
        static std::ofstream __Out__(File);
        rdbuf(__Out__.rdbuf());
    }
    Fast_Ostream::Fast_Ostream(unsigned int Size) {
        buf.reserve(Size);
    }
    void Fast_Ostream::flush() {
        outbuf->sputn(buf.data(), buf.size());
        buf.clear();
    }
    Fast_Ostream::~Fast_Ostream() {
        flush();
    }
    Fast_Ostream& Fast_Ostream::operator<<(char _Val) {
        buf.push_back(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(const char* _Val) {
        while (*_Val) {
            buf.push_back(*_Val++);
        }
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(const std::string& _Val) {
        for (auto&& i : _Val) {
            buf.push_back(i);
        }
        return *this;
    }
    template <typename Typex>
    void Put_Unsigned(Typex _Val) {
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
            Put_Unsigned(~_Val + 1);
        } else {
            Put_Unsigned(_Val);
        }
    }
    Fast_Ostream& Fast_Ostream::operator<<(bool _Val) {
        buf.push_back(_Val ? '1' : '0');
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(short _Val) {
        Put_Int(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(int _Val) {
        Put_Int(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(long _Val) {
        Put_Int(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(long long _Val) {
        Put_Int(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(unsigned short _Val) {
        Put_Unsigned(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(unsigned int _Val) {
        Put_Unsigned(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(unsigned long _Val) {
        Put_Unsigned(_Val);
        return *this;
    }
    Fast_Ostream& Fast_Ostream::operator<<(unsigned long long _Val) {
        Put_Unsigned(_Val);
        return *this;
    }
    template <typename Typex>
    void Fast_Ostream::endl(const Typex& _Val) {
        *this << _Val << '\n';
    }
    template <typename Typex, typename... More>
    void Fast_Ostream::endl(const Typex& _Val, const More&... _More) {
        *this << _Val;
        endl(_More...);
    }
    template <typename Typex>
    void Fast_Ostream::operator()(const Typex& _Val) {
        *this << _Val;
    }
    template <typename Typex, typename... More>
    void Fast_Ostream::operator()(const Typex& _Val, const More&... _More) {
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