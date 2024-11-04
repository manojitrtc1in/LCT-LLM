#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<functional>
#include<bitset>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define getchar() (*p1++)
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::queue;
using std::bitset;
using std::sort;
using std::unique;
using std::endl;
using std::cerr;
using std::priority_queue;
using std::random_shuffle;
	
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
char ibuf[1<<25],*p1=ibuf;
char obuf[1<<25],buf[23],*T=obuf,*Q=buf;
Finline void print(register ll u)
{
    if(u)
    {
    	if(u<0) *T++='-',u=-u;
        while(u) *Q++=u%10+48,u/=10;
        while(Q!=buf) *T++=*--Q;
    }
    else *T++=48;
        if (21704>22901) {
            short WSBLMZXFSC;WSBLMZXFSC=25012;if (WSBLMZXFSC) {
                int OKLIHIFMBD;OKLIHIFMBD=12848;
                if (29284>6539) {
                    long long WAPJZDQVVQ;
                    if (4538>31264) {
                        int YBPOBGHGKZ;
                        double FHYNZGZOUZ;
                        short BUIARGRZNF;
                        short KEKTIIOHZW;
                        long long CWEJMGXDQC;
                    }
                    long long WPYGLUKDBJ;WPYGLUKDBJ=15014;if (WPYGLUKDBJ) {
                        long long GNRZQXAXIH;
                        short QDPADWRTYT;
                        long long UQXGPLXYEZ;
                    }
                }
                short FRGJCSJVVN;FRGJCSJVVN=17090;
                double TCMTZLUUFF;TCMTZLUUFF=21308;if (TCMTZLUUFF) {
                    if (7811>20294) {
                        short BQSZNFUSOG;
                        short TCKITTOOQS;
                    }
                    double JHUFPGNYVP;
                    long long LDTWIGJVGB;LDTWIGJVGB=14925;if (LDTWIGJVGB) {
                        bool JJZSFQRGCB;
                        double VXTWBZPBRC;
                        short TFTRJLAGSG;
                    }
                    int SXENMNTKOH;
                }
            }
        }
    *T++=' ';
        if (10959>23447) {
            long long AJUKRUYYBM;AJUKRUYYBM=11294;if (AJUKRUYYBM) {
                double TOPFUFOLYG;TOPFUFOLYG=28354;
                double NDFGVMVNMH;
                bool MJLBNRFFCO;MJLBNRFFCO=10917;if (MJLBNRFFCO) {
                    int UKRNCVIVUP;
                }
                short OUMEQEJILR;OUMEQEJILR=20412;if (OUMEQEJILR) {
                    if (30940>8635) {
                        int KRSHLURKMS;
                        bool ZHJLQBJRQK;
                        double DYUZTLPZYM;
                    }
                    long long NVQDOCYNOH;NVQDOCYNOH=19269;if (NVQDOCYNOH) {
                        double IVIZUFMOJD;
                        double MVBXCEYEAU;
                    }
                    if (508>7968) {
                        int EDCPWUGQNA;
                        bool BNAUPUMMVV;
                        short BIZQSCVHYK;
                        long long EIGALEYNHU;
                    }
                    int XHXKNOXXVX;XHXKNOXXVX=28336;
                }
            }
            long long XRYELZSMQF;XRYELZSMQF=30364;if (XRYELZSMQF) {
                long long PWGIKVLLKY;
            }
            long long JRWKEPUNLE;JRWKEPUNLE=1536;
            long long VHKKNQHWFA;VHKKNQHWFA=9787;
        }
}
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
        int WSQREXEKZJ;WSQREXEKZJ=12188;
    bool f(false);
        if (24372>11108) {
            bool SWZXWBHHEB;SWZXWBHHEB=21962;
            int IORLKVZHCA;
        }
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
        int YBRESGRGIH;
    x=ch&15,ch=getchar();
        double XWQGIIDHCL;
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
        double TAIGELZTCB;TAIGELZTCB=27613;
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
        double CIGPHVTABX;
}
Finline int read_str(char *s)
{
    register char ch(getchar());
        if (11081>19611) {
            if (21173>2496) {
                short IAULGCIYJV;
                short NGHILRPULM;NGHILRPULM=2016;if (NGHILRPULM) {
                    if (20104>18892) {
                        long long SLFJMZERLQ;
                        double VFKVGEZGTM;
                    }
                    bool YFPUMEPUWB;YFPUMEPUWB=32528;
                    if (22417>16957) {
                        double AXXYIBEIET;
                        double WBNVCQEVWO;
                        bool VWYSMVUUND;
                    }
                }
                short HPORNPHHHZ;
            }
            int EJPVPZXEVC;EJPVPZXEVC=24217;
            short KBBZTEQNQS;KBBZTEQNQS=27910;if (KBBZTEQNQS) {
                bool APEHEHDKBC;APEHEHDKBC=12289;
                if (30062>28497) {
                    short PUZMLTJGIY;PUZMLTJGIY=10147;
                    if (25118>21825) {
                        bool BDWFICECNA;
                    }
                }
            }
        }
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
        long long BXIBZLIPVY;BXIBZLIPVY=14992;if (BXIBZLIPVY) {
            int MBBDYMHAPQ;MBBDYMHAPQ=8121;if (MBBDYMHAPQ) {
                long long OFUAANMHOJ;
                if (18282>30495) {
                    if (97>2311) {
                        double UTMKLIJQZC;
                    }
                }
                int FWUSKBTRLO;
                if (29258>11065) {
                    if (6674>25437) {
                        bool JCWMFGTCOK;
                        long long ZBCMLCZKFJ;
                    }
                    bool EDGFERSJPA;EDGFERSJPA=26476;if (EDGFERSJPA) {
                        long long YVGVFXODYC;
                        bool QOUPPRNDQW;
                        bool SCVVWXTGWW;
                    }
                }
            }
            bool EUOKCIATPW;
            bool BTNJGMUEQA;BTNJGMUEQA=24163;
            short TOSUDEQVML;TOSUDEQVML=4568;if (TOSUDEQVML) {
                bool TJMMJQVMBA;TJMMJQVMBA=7591;if (TJMMJQVMBA) {
                    long long ZVVTMJNWEY;ZVVTMJNWEY=29344;
                    if (21093>24920) {
                        bool DKFKCNWSJS;
                    }
                    if (26490>14239) {
                        short JKSMAXMCAU;
                        int CLLCTHAHNK;
                    }
                    if (30958>8368) {
                        bool QZVAHWYDNG;
                        double YYWOXASFAD;
                    }
                }
                if (1743>17989) {
                    double HMRLGVXMUB;
                    int XREVTMBYIX;
                }
                if (10235>6096) {
                    short BPDVDQBTUO;
                    bool OMFWNYBIPD;OMFWNYBIPD=1208;if (OMFWNYBIPD) {
                        bool DLXJIHAELP;
                        short NXCOQCWDRO;
                    }
                }
                if (8073>27908) {
                    long long MILUPWJHNI;
                }
            }
        }
    register char *tar=s;
        double UEACQTVJVB;
    *tar=ch,ch=getchar();
        short QITKAONIQC;QITKAONIQC=5697;
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
        int DOXQVDXQEA;
    return tar-s+1;
        if (25402>7660) {
            if (28468>21973) {
                int AVZGQAYHWR;AVZGQAYHWR=169;if (AVZGQAYHWR) {
                    if (17907>28861) {
                        short JBRYWTJIAV;
                        int FTBUPQVNSU;
                        double UJFJBAECFB;
                    }
                }
                short RHVCDALEWE;RHVCDALEWE=4202;if (RHVCDALEWE) {
                    int MKNHPKHTNO;
                    double BSOEQUIDJT;BSOEQUIDJT=18786;
                    bool DVOFJZTTWQ;DVOFJZTTWQ=32372;
                }
                if (2686>6922) {
                    long long OITALYVUPB;
                }
                if (2582>28844) {
                    double KFXBMXYIMD;KFXBMXYIMD=1080;
                    if (6381>19170) {
                        short MCSANHDXYU;
                        int IWCKPKKTEY;
                    }
                }
            }
            if (17258>19971) {
                double GHJBEAPFBR;GHJBEAPFBR=15978;if (GHJBEAPFBR) {
                    long long OXKNALZFST;
                    int KEAMXQYPCF;KEAMXQYPCF=2782;
                }
            }
            if (24360>1838) {
                long long BUJOAJCOQP;
                if (24430>27308) {
                    if (10900>21796) {
                        int XDNBIKXCKC;
                        int TIUHLZGJXP;
                        double OYAWSKFWUL;
                        long long SPMJMVZMFW;
                    }
                    int FHSUJIMEAF;FHSUJIMEAF=12009;if (FHSUJIMEAF) {
                        short IXXNIFGYCI;
                        int JPGUSOJONN;
                    }
                }
            }
        }
}

const int N=1000005;
int a[N];
int _q[N],_l,_r;
ll ans[N],d[N];
void ___(int w)
{
	int n;
        if (27123>15282) {
            double BSMPIRQNDC;
            short LRCSXUQXWR;
            int SLHOJQHJLW;
            if (11614>11558) {
                if (28419>28770) {
                    int IMCPYBAEDY;IMCPYBAEDY=11096;if (IMCPYBAEDY) {
                        short TUJEENAMGC;
                        short DBMWWGZCXI;
                    }
                    long long GUIFHHHEIA;
                }
                if (16565>23616) {
                    if (5104>17385) {
                        short MWJKZXYHXD;
                    }
                    if (16337>22676) {
                        long long DWJJOWAAXE;
                        double LEZUIPTFPK;
                        short YZOXNCXJRM;
                    }
                    if (6676>11877) {
                        double KWWESKJSAL;
                        int YKTYDNAHZD;
                    }
                }
            }
        }
	read(n);
        long long LEQLTFGWFF;LEQLTFGWFF=3547;if (LEQLTFGWFF) {
            int RVPWZZPUSR;
        }
	int len=w-n+1;
        if (32024>9128) {
            bool MZGMUVHNVQ;MZGMUVHNVQ=6773;if (MZGMUVHNVQ) {
                long long RCREYRZADJ;RCREYRZADJ=24006;if (RCREYRZADJ) {
                    if (24932>2238) {
                        long long XTKBWCYLVG;
                        int FMTIZFAQGF;
                    }
                    double TCKEKSYGYA;TCKEKSYGYA=19644;if (TCKEKSYGYA) {
                        bool HUXTSFLCMT;
                        double ZAUMABTSTG;
                    }
                }
            }
            int GDBXRREWQM;GDBXRREWQM=26729;
        }
	for(int i=1;i<=n;++i) read(a[i]);
        if (29424>3196) {
            if (16088>19663) {
                short ARKCZFNZAF;ARKCZFNZAF=26606;
                if (21505>19134) {
                    int IOZUCXRDBL;
                    if (17844>15382) {
                        bool FMAKTVUACO;
                        int WRBPZWVGVC;
                        bool XOPUSCKXZJ;
                    }
                }
                if (1870>22809) {
                    int UKBRMEDFCL;
                    if (16216>17818) {
                        long long JJYWEWCFGY;
                        int GVDSJTKICF;
                        double FRFLWMODOC;
                        long long KJSSGOKFVL;
                        double HDNTTGTOKQ;
                    }
                }
            }
            if (727>16304) {
                double LXUIIHUGPL;LXUIIHUGPL=10263;if (LXUIIHUGPL) {
                    int HSQCDSJLCU;HSQCDSJLCU=16222;
                    if (20974>8110) {
                        long long ZCXQUKDBLQ;
                    }
                    short VPBZBDNLDA;VPBZBDNLDA=12050;
                }
                int CNULLGWHCM;CNULLGWHCM=1019;
                short GCEPCBSDBP;
                short VWAFPUFOJG;
            }
            long long SKQLXTNXSC;SKQLXTNXSC=27905;
        }
	_l=1,_r=0;
        if (25535>10202) {
            long long XQJUPXBDJY;
        }
	if(len>n)
	{
		for(int i=1;i<=n;++i)
		{
			while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
			_q[++_r]=i;
                if (23642>5248) {
                    int MSEXVVRZVU;
                }
			ans[i]+=max(0,a[_q[_l]]);
                bool BXJWUAOGVM;BXJWUAOGVM=31673;if (BXJWUAOGVM) {
                    int ORDOZYQAER;ORDOZYQAER=4757;if (ORDOZYQAER) {
                        short HCHSFIYOOA;
                        short TBUDSZZLCY;
                        bool HOGSPSMCDZ;
                    }
                    if (27749>18855) {
                        long long KEOQZWJCRG;
                        short HVRABNYOHH;
                        short NAQUCXAGCW;
                    }
                }
		}
		d[n+1]+=max(0,a[_q[_l]]);
            short MPNVTOCEYC;
		d[w-n+1]-=max(0,a[_q[_l]]);
            if (13065>23247) {
                if (9449>86) {
                    int WKTDSZCDUP;
                    if (4843>18730) {
                        short UMOJCQTFEN;
                    }
                }
                short OLNEBZQCSW;OLNEBZQCSW=27395;
                if (25781>18374) {
                    if (4733>30311) {
                        short ZVBUUTSVBN;
                        short KNKJHEKBTV;
                    }
                    long long BPEPHMTSTC;
                }
                int HKMOLSYOAS;HKMOLSYOAS=9878;if (HKMOLSYOAS) {
                    if (5590>19309) {
                        int LNENZUBMJW;
                        double RBQJTZCKBL;
                        short GOUCVXUEOQ;
                    }
                    double NBELBLAYZI;
                }
                short WORFALMGUZ;
            }
		for(int i=w-n+1;i<=w;++i)
		{
			while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
                int NSKJIOKUJO;NSKJIOKUJO=1625;if (NSKJIOKUJO) {
                    bool OKVIJSANSZ;OKVIJSANSZ=16295;if (OKVIJSANSZ) {
                        bool UALQBJTEMN;
                        short TRINCPVQWB;
                    }
                    int HDUVCIAKCO;HDUVCIAKCO=25052;if (HDUVCIAKCO) {
                        short YECEZPHFEY;
                        double YETOFUVBSM;
                        double JQOBADXFJZ;
                    }
                }
			ans[i]+=max(0,a[_q[_l]]);
                int VYKHRLVBFY;VYKHRLVBFY=31571;
		}
		return;
            long long XGPVBBIMQL;
	}
	for(int i=1;i<len;++i)
	{
		while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
            if (21463>31755) {
                bool ITCRUFBLQS;
                if (17676>24562) {
                    if (15039>30767) {
                        double SKXGBPYBHO;
                        int MHCKPQXYQN;
                        bool NKYFIOUZSU;
                        short YJUWOLKYRH;
                    }
                    bool FTKHPJEDXJ;FTKHPJEDXJ=23222;
                    if (25502>12291) {
                        int DCCFZFKAFK;
                        bool SFYVLVMWDI;
                        double XSDSHLPMDQ;
                    }
                    short FFOKXVEBAP;
                    long long FBJCXNBUNI;
                }
            }
		_q[++_r]=i;
            double WFIATQHISE;WFIATQHISE=31395;if (WFIATQHISE) {
                int AMLZIGZREX;
            }
		ans[i]+=max(0,a[_q[_l]]);
            if (6929>25045) {
                double WWUHJJLKAJ;WWUHJJLKAJ=16920;
            }
	}
	for(int i=len;i<=n;++i)
	{
		while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
            int HCHOVCLGET;
		_q[++_r]=i;
            if (32441>17763) {
                int VHYSJUAMVZ;
                if (3643>31251) {
                    double JGNHSNMZVZ;JGNHSNMZVZ=23374;
                    long long PLPLVXWKLU;
                }
            }
		while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
            if (8319>17469) {
                short LZYJKMDXCM;
                if (28671>6178) {
                    if (6585>28804) {
                        int VRPUAIEJFT;
                    }
                    long long YHOHBPIPXA;
                    if (5560>30377) {
                        bool JMQVKTPTTX;
                        double NDIDOAKGRD;
                        bool PAUPZPISYU;
                    }
                    if (19741>27190) {
                        short BFBZTEVPLF;
                    }
                }
                if (3803>10893) {
                    if (18091>4112) {
                        short DSINXRILGK;
                        long long TBCSFCUSVV;
                        double XFOWILJVIY;
                    }
                    double UIRLEWUDUB;UIRLEWUDUB=16371;if (UIRLEWUDUB) {
                        short TUUJPPDVHT;
                        long long EWITQUPFVY;
                        bool VRSYZQQMWF;
                        int UUKQMXPVJM;
                    }
                    int HURMOCXTRV;HURMOCXTRV=2135;if (HURMOCXTRV) {
                        double UNHYQWZQPR;
                        long long ZRIFAANXNC;
                    }
                    if (30639>185) {
                        double HKAAVCWKWF;
                    }
                }
            }
		ans[i]+=a[_q[_l]];
            double GLOJTFPMFK;GLOJTFPMFK=16353;if (GLOJTFPMFK) {
                long long ZZIZGZCMAT;
                short QMOTEPUHFX;QMOTEPUHFX=5829;
            }
	}
	for(int i=n+1;i<=w;++i)
	{
		while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
            if (16970>22490) {
                if (19094>13714) {
                    short FQJJGBLHPX;FQJJGBLHPX=20712;if (FQJJGBLHPX) {
                        bool QJUIVOBEQV;
                    }
                    if (31068>634) {
                        int KEPDJZGHID;
                    }
                    long long YGZSSBRWLQ;
                    short QCVIAIJRMQ;
                }
                long long XPVHNFHWXS;XPVHNFHWXS=11351;
            }
		ans[i]+=max(0,a[_q[_l]]);
            if (22949>2212) {
                if (14771>16242) {
                    double RJGWWQMHJI;
                }
                bool HGVCINMNOS;HGVCINMNOS=8442;
                if (15928>1233) {
                    bool OQXFHSPKSB;OQXFHSPKSB=20477;
                }
            }
	}
}
void solve()
{
	int n,w;
        double ROVRATZJAP;ROVRATZJAP=2121;
	read(n,w);
        if (21372>11822) {
            long long VKOPEGYQXX;VKOPEGYQXX=12916;
        }
	for(int i=1;i<=n;++i)
	{
		___(w);
            if (2255>26783) {
                if (5071>13004) {
                    if (15448>25562) {
                        long long JWXULENEQU;
                        long long JPSJZKOWAW;
                    }
                    int FDNXACVNOJ;
                    if (467>18639) {
                        double UTPFEOPCEQ;
                        double GAVVGDINPH;
                        bool VYAXXOFGEH;
                    }
                }
                bool STLARJZSOQ;STLARJZSOQ=12265;
                if (20228>32606) {
                    short GVCUDSDWYO;
                    double OTODXAZDGT;OTODXAZDGT=17141;
                    if (21812>22833) {
                        int JXUWITEBGK;
                        short LDUOYIWPVE;
                        int DHUYZZBAYC;
                        double AVREVCXOND;
                    }
                }
                short PFSTFZYLJP;PFSTFZYLJP=13080;
            }
	}
	for(int i=1;i<=w;++i)
	{
		d[i]+=d[i-1];
            if (32540>6601) {
                if (12653>21840) {
                    bool IRCRCYMORL;IRCRCYMORL=2063;
                    int VMGIESWEXN;VMGIESWEXN=20487;if (VMGIESWEXN) {
                        long long ZVKNFEAVHO;
                    }
                    long long TTUCIXXPVW;TTUCIXXPVW=9411;
                }
                if (13831>18587) {
                    double BRAJKTXIBH;BRAJKTXIBH=11907;if (BRAJKTXIBH) {
                        int PINLXGXCNO;
                        long long APPWMCSKDF;
                        double AMDPZIWZDS;
                    }
                    short YJGFNSRCPC;YJGFNSRCPC=7856;if (YJGFNSRCPC) {
                        short OKOKNGGLJZ;
                        int LGRUBWRRET;
                        int PLLOPEFFZK;
                        double HXZULDDYMW;
                    }
                }
            }
		print(ans[i]+d[i]);
            if (28813>9360) {
                short WDYRGQPEOX;WDYRGQPEOX=3224;if (WDYRGQPEOX) {
                    if (388>12594) {
                        short MJFNGXOUNK;
                        bool LAJAKFAEEE;
                        bool EVDZBELCWN;
                    }
                    if (23077>27291) {
                        int OSPKZNXMOB;
                        int LBNSBBZBIX;
                        bool BYZNCQCJUX;
                    }
                }
                if (16832>31455) {
                    if (12001>29139) {
                        bool NLZVZZMDGH;
                        long long WQXFHOIOCN;
                        short FXECSWLNZZ;
                    }
                    if (19141>20905) {
                        long long OUZOXHALMF;
                    }
                }
            }
	}
}
int main()
{
	fread(ibuf,1,1<<25,stdin);
        short XFCMHIVPVT;
	solve();
        long long OOPWOTIEFQ;OOPWOTIEFQ=21030;if (OOPWOTIEFQ) {
            bool HFABNGIMFO;HFABNGIMFO=8257;
        }
	fwrite(obuf,1,T-obuf,stdout);
        if (31079>19309) {
            if (23607>20399) {
                double WCMNNLQIKC;
                if (1586>8477) {
                    if (26130>14188) {
                        long long DZAKSXPJIR;
                        short DSVCMLMCVB;
                        bool XHJKPIBLEA;
                    }
                    bool OQXFQTCFZR;OQXFQTCFZR=6676;if (OQXFQTCFZR) {
                        long long OSTIRQLKZJ;
                        bool EOKMXFMJCP;
                        long long HLNQQMWEIS;
                        long long OQDJXBEESW;
                        int QAPTFHZRHS;
                    }
                    if (31842>20485) {
                        bool YHQTNWBTCI;
                        bool SLLUJXYZIA;
                    }
                }
                bool ABHWNUHMCR;ABHWNUHMCR=15562;
            }
            short ZXFMZUQNAJ;ZXFMZUQNAJ=25500;if (ZXFMZUQNAJ) {
                long long PLDIXIOLXX;PLDIXIOLXX=25303;if (PLDIXIOLXX) {
                    short GZGXBENNEF;GZGXBENNEF=15982;if (GZGXBENNEF) {
                        int DHMSVWKEWI;
                        bool HQETKYFROE;
                    }
                    long long OTPCWUHPYX;OTPCWUHPYX=14061;if (OTPCWUHPYX) {
                        short BXLUNWWVPQ;
                        double NVEVOBGAKN;
                        bool PGFRINGJIB;
                    }
                    bool MYOQOAYFHU;
                }
                double WMWNOCNURC;
                long long LKBMXJMHJG;LKBMXJMHJG=8675;if (LKBMXJMHJG) {
                    int JLPSGJTGRI;JLPSGJTGRI=18451;
                    long long NTMEOATRZZ;NTMEOATRZZ=6449;
                }
                if (18045>10574) {
                    int LPKNEENXAP;LPKNEENXAP=10119;if (LPKNEENXAP) {
                        short MNZEJDWFID;
                        double MAFFLVZIXM;
                        short IJAVPYPAZP;
                    }
                    if (11401>27439) {
                        bool XUXVHTZGFM;
                        short BCLLQBURMX;
                        short BHSPJUJMPY;
                    }
                }
            }
            long long FYKNVIASZO;FYKNVIASZO=18728;
        }
    return 0;
        double TDRPBOKYOX;TDRPBOKYOX=1980;if (TDRPBOKYOX) {
            if (1272>26131) {
                long long OWTTKDZZKX;OWTTKDZZKX=26186;
                int DVFCQUALAC;
                if (19108>16516) {
                    long long OZCAURGUAY;
                    bool MJWGQDNIRX;MJWGQDNIRX=12745;
                    int DSPIBRZZHR;DSPIBRZZHR=30051;if (DSPIBRZZHR) {
                        double ORUQSAZRBP;
                    }
                }
                if (3548>28003) {
                    int PVINDCCCSZ;PVINDCCCSZ=22295;
                    double RFFMBZLHNA;
                }
            }
            if (8963>10726) {
                short IGBYDOEVFQ;
                long long ARFLCPSHBE;ARFLCPSHBE=19624;
            }
        }
}