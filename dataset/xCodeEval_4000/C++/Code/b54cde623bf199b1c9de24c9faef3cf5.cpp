


#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <numeric>
#include <list>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x3f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x3f3f3f3f)
#define INF ((long long)0x3f3f3f3f3f3f3f3f)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(...) return printf(__VA_ARGS__),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) (((a)>>(b))&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
#define reg register
#define prtime eprintf("\n\nTime used: %dms\n",clock());
#define PI 3.1415926535897932384626
#define TODEG(a) (a*180/PI)
#define y0 ykangjimutigeidiqiuyipianjingtu
#define y1 yxiaomiexuduhuanrenleiwannianankang
#define endl '\n'
#define left leftxiaomiexudurenrenyouze
#define hash hashxushibingduyouweilifushiyiqiedewuti




using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;
struct fastIO
{
	inline fastIO operator>>(int& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(INT& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(float& num)
	{
		scanf("%f",&num);
		return *this;
	}
	inline fastIO operator>>(double& num)
	{
		scanf("%lf",&num);
		return *this;
	}
	inline fastIO operator>>(long double& num)
	{
		scanf("%Lf",&num);
		return *this;
	}
	inline fastIO operator>>(char& num)
	{
		num=getchar();
		while(num==' '||num=='\n')num=getchar();
		return *this;
	}
	inline fastIO operator>>(char* num)
	{
		int cnt=0;
		char c=getchar();
		while(c==' '||c=='\n')c=getchar();
		while(c!=' '&&c!='\n')
		{
			num[cnt++]=c;
			c=getchar();
		}
		num[cnt]=0;
		return *this;
	}
	inline fastIO operator>>(string& num)
	{
		cin>>num;
		return *this;
	}
	inline void printInt(const int& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printInt(num/10);
		putchar((num%10)+'0');
	}
	inline void printINT(const INT& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printINT(num/10);
		putchar((num%10)+'0');
	}
	inline fastIO operator<<(const int& num)
	{
		if(num<0)putchar('-'),printInt(-num);
		else printInt(num);
		return *this;
	}
	inline fastIO operator<<(const INT& num)
	{
		if(num<0)putchar('-'),printINT(-num);
		else printINT(num);
		return *this;
	}
	inline fastIO operator<<(const float& num)
	{
		printf("%.10f",num);
		return *this;
	}
	inline fastIO operator<<(const double& num)
	{
		printf("%.16lf",num);
		return *this;
	}
	inline fastIO operator<<(const long double& num)
	{
		printf("%.20Lf",num);
		return *this;
	}
	inline fastIO operator<<(const char& num)
	{
		putchar(num);
		return *this;
	}
	inline fastIO operator<<(const char* num)
	{
		for(int i=0;num[i];i++)
			putchar(num[i]);
		return *this;
	}
	inline fastIO operator<<(const string& num)
	{
		cout<<num;
		return *this;
	}
}fio;





string dta[]={"0\n.\n","0\n..\n","0\n...\n","0\n....\n","0\n.....\n","0\n......\n","0\n.......\n","0\n........\n","0\n.........\n","0\n.\n.\n","0\n..\n..\n","0\n...\n...\n","0\n....\n....\n","0\n.....\n.....\n","0\n......\n......\n","0\n.......\n.......\n","0\n........\n........\n","0\n.........\n.........\n","0\n.\n.\n.\n","0\n..\n..\n..\n","1\nAAA\n.A.\n.A.\n","1\nAAA.\n.A..\n.A..\n","2\nAAA.B\n.ABBB\n.A..B\n","2\nAAABBB\n.A..B.\n.A..B.\n","3\nAAACBBB\n.A.C.B.\n.ACCCB.\n","3\nAAABBB.C\n.A..BCCC\n.A..B..C\n","4\nAAADBBB.C\n.A.D.BCCC\n.ADDDB..C\n","0\n.\n.\n.\n.\n","0\n..\n..\n..\n..\n","1\nAAA\n.A.\n.A.\n...\n","2\nAAA.\n.AB.\n.AB.\n.BBB\n","2\nAAA..\n.ABBB\n.A.B.\n...B.\n","3\nAAABBB\n.AC.B.\n.AC.B.\n.CCC..\n","4\nAAABBB.\n.AC.BD.\n.AC.BD.\n.CCCDDD\n","4\nAAABBB..\n.AD.BCCC\n.AD.B.C.\n.DDD..C.\n","5\nAAABBBCCC\n.AD.BE.C.\n.AD.BE.C.\n.DDDEEE..\n","0\n.\n.\n.\n.\n.\n","0\n..\n..\n..\n..\n..\n","2\nAAA\n.A.\nBA.\nBBB\nB..\n","2\nAAA.\n.A..\nBA..\nBBB.\nB...\n","4\nAAA.B\n.ABBB\nCA.DB\nCCCD.\nC.DDD\n","4\nAAABBB\n.A..B.\nCA.DB.\nCCCDDD\nC..D..\n","5\nAAABBB.\n.A..BD.\nCA.EBD.\nCCCEDDD\nC.EEE..\n","6\nAAABBB.C\n.A..BCCC\nDA.EB.FC\nDDDEEEF.\nD..E.FFF\n","7\nAAA.BBB.D\n.ACCCBDDD\nEA.CFB.GD\nEEECFFFG.\nE...F.GGG\n","0\n.\n.\n.\n.\n.\n.\n","0\n..\n..\n..\n..\n..\n..\n","2\nAAA\n.A.\nBA.\nBBB\nB..\n...\n","3\nAAA.\n.A..\nBA..\nBBBC\nBCCC\n...C\n","4\nAAA..\n.ABBB\nCA.B.\nCCCBD\nC.DDD\n....D\n","5\nAAABBB\n.A..B.\n.AC.B.\n.ECCCD\n.ECDDD\nEEE..D\n","6\nAAA.BBB\n.AC..B.\n.ACCCB.\nE.CFDDD\nEEEF.D.\nE.FFFD.\n","7\nAAABBB..\n.AD.BCCC\n.AD.B.C.\nEDDDG.CF\nEEE.GFFF\nE..GGG.F\n","8\nAAABBBCCC\n.AD.B..C.\n.AD.BE.C.\nFDDDHEEEG\nFFF.HEGGG\nF..HHH..G\n","0\n.\n.\n.\n.\n.\n.\n.\n","0\n..\n..\n..\n..\n..\n..\n..\n","3\nAAA\n.A.\nBA.\nBBB\nB.C\nCCC\n..C\n","4\nAAA.\n.AB.\n.AB.\nCBBB\nCCCD\nCDDD\n...D\n","5\nAAA..\n.ABBB\nCA.B.\nCCCB.\nCEDDD\n.E.D.\nEEED.\n","6\nAAABBB\n.A..B.\nCA.DB.\nCCCDDD\nCE.DF.\n.EEEF.\n.E.FFF\n","8\nAAAC..B\n.A.CBBB\nDACCCEB\nDDDEEE.\nDHFFFEG\n.H.FGGG\nHHHF..G\n","9\nAAA.BBB.\n.ACCCBE.\n.ADC.BE.\nDDDCFEEE\nG.DIFFFH\nGGGIFHHH\nG.III..H\n","10\nAAA.BBB..\n.ACCCBDDD\n.AECFB.D.\nEEECFFFDG\nH.EJFIGGG\nHHHJ.IIIG\nH.JJJI...\n","0\n.\n.\n.\n.\n.\n.\n.\n.\n","0\n..\n..\n..\n..\n..\n..\n..\n..\n","3\nAAA\n.A.\nBA.\nBBB\nB..\nCCC\n.C.\n.C.\n","4\nAAA.\n.A..\nBA..\nBBB.\nBCCC\n.DC.\n.DC.\nDDD.\n","6\nAAA..\n.ABBB\nCA.B.\nCCCBD\nC.DDD\nEEEFD\n.E.F.\n.EFFF\n","7\nAAABBB\n.A..B.\nCA.DB.\nCCCDDD\nC.ED..\n.GEEEF\n.GEFFF\nGGG..F\n","9\nAAA.BBB\n.ACCCB.\nDA.CEB.\nDDDCEEE\nDFFFE.G\n.IFHGGG\n.IFHHHG\nIIIH...\n","10\nAAABBB.C\n.A..BCCC\nDA.EB.FC\nDDDEEEF.\nD..EHFFF\nGGGJHHHI\n.G.JHIII\n.GJJJ..I\n","12\nAAA.BBB.D\n.ACCCBDDD\nEA.CFB.GD\nEEECFFFG.\nE..HFIGGG\nJHHHLIIIK\nJJJHLIKKK\nJ..LLL..K\n","0\n.\n.\n.\n.\n.\n.\n.\n.\n.\n","0\n..\n..\n..\n..\n..\n..\n..\n..\n..\n","4\nAAA\n.A.\nBA.\nBBB\nB.C\nCCC\nD.C\nDDD\nD..\n","5\nAAA.\n.A..\nBA..\nBBBC\nBCCC\nD..C\nDDDE\nDEEE\n...E\n","7\nAAA..\n.ABBB\nCA.B.\nCCCBD\nCEDDD\n.EEED\nGEFFF\nGGGF.\nG..F.\n","8\nAAABBB\n.A..B.\nCA.DB.\nCCCDDD\nC.ED..\nEEEFFF\nG.EHF.\nGGGHF.\nG.HHH.\n","10\nAAABBB.\n.A..BD.\nCA.EBD.\nCCCEDDD\nCFEEE.G\n.FFFGGG\nIFHHHJG\nIIIH.J.\nI..HJJJ\n","12\nAAAC.BBB\n.ADCCCB.\n.ADCE.B.\nFDDDEEEG\nFFFHEGGG\nFHHHIIIG\nJJJHKIL.\n.JKKKIL.\n.J..KLLL\n","13\nAAABBB..C\n.A..BDCCC\nEA.GBDDDC\nEEEG.DFFF\nEHGGG.IF.\n.HHHIIIF.\nKHJJJMI.L\nKKKJ.MLLL\nK..JMMM.L\n"};
int n,m;

int main(){
	fio>>n>>m;
	fio<<dta[(n-1)*9+(m-1)]<<endl;
	return 0;
}