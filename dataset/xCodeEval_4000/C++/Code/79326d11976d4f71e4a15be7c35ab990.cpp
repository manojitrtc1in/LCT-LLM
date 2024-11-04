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

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
        short OOYOCNWTWY;OOYOCNWTWY=4516;if (OOYOCNWTWY) {
            if (13091>21329) {
                if (20970>3177) {
                    int UAHARZKHDC;UAHARZKHDC=14477;
                    long long SSDYRGVJJO;SSDYRGVJJO=26075;if (SSDYRGVJJO) {
                        long long NXUQAAEXIH;
                        bool GEFDAKYTMH;
                        double TEUNXGGYQD;
                    }
                    if (1947>21701) {
                        bool EGIXFXZAQO;
                    }
                    double NOXIEJHCLW;NOXIEJHCLW=22568;
                }
                if (9550>22689) {
                    if (1804>6550) {
                        short LPRPYBWKAD;
                        long long ZSSQOEBTDM;
                    }
                    long long ILPAISAVDP;ILPAISAVDP=6963;
                    bool FOGRDTCUNP;FOGRDTCUNP=20931;if (FOGRDTCUNP) {
                        short DQEAOZNGRJ;
                        double WMODVMYGKE;
                        double ZUBPNACGQC;
                        long long FFSFHTBNNQ;
                    }
                }
                int RUXHIBJNLM;
            }
        }
    bool f(false);
        if (3502>4346) {
            bool AALFEPENYN;AALFEPENYN=29987;
            if (4558>10324) {
                if (15863>27677) {
                    int MOLNOPTTKO;MOLNOPTTKO=31677;
                }
            }
        }
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
        long long HWZVRPJCYV;
    x=ch&15,ch=getchar();
        int TKUCADZPJX;TKUCADZPJX=5368;
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
        int QLIPHZGQRR;QLIPHZGQRR=19716;
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
        short GRSYZLVFSO;
}
Finline int read_str(char *s)
{
    register char ch(getchar());
        int SLVBPSRKCR;SLVBPSRKCR=16796;
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
        if (18356>5140) {
            if (11389>3901) {
                if (10403>8568) {
                    if (19246>19291) {
                        double MDCUSAWYDY;
                        short PLAKBKJAJD;
                    }
                }
            }
            int PLYBAFUGQJ;
            double IHFDIXVFKD;IHFDIXVFKD=5973;if (IHFDIXVFKD) {
                int HZLWECZJJQ;
                long long PVTNBTSVIT;PVTNBTSVIT=16412;
            }
            if (27666>13910) {
                if (389>4560) {
                    double WHMYQNOISK;WHMYQNOISK=11753;if (WHMYQNOISK) {
                        bool UMFXHNYISR;
                        double PTHMHUERVC;
                        double NYZLQIIHEW;
                    }
                    bool SSCBHNQDZU;
                }
                if (13383>7596) {
                    if (4503>21662) {
                        bool PKKJSASOAP;
                    }
                    if (390>12624) {
                        bool LAHJKMMSHQ;
                        int PRGGKXHDOS;
                        short XSLKAPLWPK;
                    }
                    if (5152>16601) {
                        int FQBNVTNETU;
                        long long IRJQFZNNWQ;
                        double LPJWWUWAKC;
                    }
                }
                if (1549>16629) {
                    short KOBCLWPCIN;
                    double HDPAQGZIMP;HDPAQGZIMP=12018;if (HDPAQGZIMP) {
                        short ZECEKQNHVU;
                        int ZSNSHOMMGT;
                        short PYPOYEWJQX;
                    }
                    if (26600>26095) {
                        int RVGUYNOAIV;
                        int TWOTUAGLCS;
                    }
                }
                short LNTSYKMBMO;
            }
        }
    register char *tar=s;
        double JPLTAURDQR;JPLTAURDQR=8244;if (JPLTAURDQR) {
            bool OJPFHWVBCA;OJPFHWVBCA=22180;if (OJPFHWVBCA) {
                double UIOLHAXZRG;
                double JFOCTQEQRI;JFOCTQEQRI=11085;if (JFOCTQEQRI) {
                    double CVMVEGOODP;
                }
            }
            int BJYDTSESPY;BJYDTSESPY=4440;if (BJYDTSESPY) {
                if (15775>8939) {
                    double ZWCDSISXAP;ZWCDSISXAP=13333;
                    int NCXHTVNOUU;
                }
                if (2433>3527) {
                    double MFRMVUSLZX;MFRMVUSLZX=24883;if (MFRMVUSLZX) {
                        double KNRHOHOBAQ;
                        int UPJVMTSEBS;
                        short RKHAKNDCIG;
                    }
                    short KGBMCYOGZV;KGBMCYOGZV=478;if (KGBMCYOGZV) {
                        short KTQNPWTUUV;
                        int MTCTBLVXJJ;
                    }
                    if (14333>22210) {
                        long long NYOTDHURDS;
                        long long EFVSJRMTBW;
                        bool XWPFDTREDE;
                    }
                    short QBLXXKYGYA;
                }
            }
            if (15483>8334) {
                short AOWUDRGRFD;AOWUDRGRFD=851;if (AOWUDRGRFD) {
                    if (24453>2370) {
                        double DSRQLMCEQG;
                        short NYDWJHCOXH;
                    }
                    if (23862>28123) {
                        short QSSUWNYFAH;
                        double MDFLQQMCYM;
                        long long TLWOTUSEVA;
                    }
                }
                int ZMGFGPXVIQ;ZMGFGPXVIQ=11486;
                bool NOFNGHGQSA;NOFNGHGQSA=14317;if (NOFNGHGQSA) {
                    if (18006>20908) {
                        long long TABNNYLVGR;
                        double XEDGYCAICO;
                        double RXRRQZHIYA;
                    }
                    bool HTTKCHEOCD;HTTKCHEOCD=12138;if (HTTKCHEOCD) {
                        long long LKRJSUUYGF;
                        int HVRVRFDARC;
                    }
                    short ZYKNUWQSDM;ZYKNUWQSDM=17469;if (ZYKNUWQSDM) {
                        short TDGNIJSYNV;
                        double VZXBNGKQSY;
                        short FPBSPWUWQY;
                        short WVUMFJKJCW;
                    }
                }
            }
            bool AHLJDBKSNE;
        }
    *tar=ch,ch=getchar();
        if (29990>3066) {
            if (8571>28712) {
                long long OQFVDSTYFK;OQFVDSTYFK=4534;if (OQFVDSTYFK) {
                    if (23347>24918) {
                        short FWKJSDUKYB;
                    }
                    if (10756>10779) {
                        double YYVNPGYDLD;
                        double EBVQTUNKBW;
                        bool NQLAWPRRBO;
                        bool IZABXGAVZE;
                    }
                    if (29689>6454) {
                        long long EOYKHWQNRA;
                        bool BIFPNBUJLE;
                        int TGEBBYJGCV;
                        int TTZVHWHRRK;
                        bool FCNCUZXKQZ;
                    }
                }
                int ODCBDNBEXM;ODCBDNBEXM=20879;if (ODCBDNBEXM) {
                    if (30379>16648) {
                        double ECPMICPOSO;
                    }
                    if (18570>11045) {
                        int UORADCBDNT;
                        short STTVJPYAWL;
                    }
                }
                int GIQBFLIINF;GIQBFLIINF=18385;if (GIQBFLIINF) {
                    if (10072>1817) {
                        double TEJOJHSUVP;
                        long long HMPMQRYIRF;
                    }
                    int XSROPQPKQO;XSROPQPKQO=10021;if (XSROPQPKQO) {
                        int XPRVQTOOYA;
                        int DNGPJNIDJC;
                    }
                    short DHDAZRUINB;DHDAZRUINB=25268;
                }
            }
        }
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
        if (3080>16373) {
            if (7911>11648) {
                if (31790>15622) {
                    long long TSATODNSXH;
                    short EECLJLRDJJ;EECLJLRDJJ=28032;if (EECLJLRDJJ) {
                        short NYOLVRLFJT;
                        short VGDKUGHIMQ;
                    }
                    long long YZFLNRNXTB;YZFLNRNXTB=19331;if (YZFLNRNXTB) {
                        short KQVNPSDDJX;
                        int FJSWDADLNN;
                        double PDGSWBMTPS;
                    }
                }
            }
            int PEJQLCHLNK;PEJQLCHLNK=30538;if (PEJQLCHLNK) {
                if (23657>17245) {
                    if (32527>24260) {
                        int FGZRLEFJOU;
                        long long IBHQTISMPU;
                    }
                    if (26135>24977) {
                        bool IGRXGSWJGV;
                        int IQFBAEOMSA;
                        long long RMUGSVFHHF;
                        long long IDORZURBDG;
                    }
                    double UVORSPYDQI;UVORSPYDQI=23173;
                }
                bool NIKUASZGLP;NIKUASZGLP=7479;
                long long IKZRAZRQFF;
                short GKIUKEGRHH;GKIUKEGRHH=23695;
                short IWRUNBBDWF;IWRUNBBDWF=29132;
            }
            double MWJHWHWZZP;MWJHWHWZZP=2263;if (MWJHWHWZZP) {
                short HPZVLFFGEB;HPZVLFFGEB=18597;if (HPZVLFFGEB) {
                    if (12011>28975) {
                        long long PCZWFAATYP;
                        long long VAFSFIUTWK;
                        bool SSCJRILYQC;
                    }
                    if (11070>9266) {
                        bool EKODMLRQLA;
                    }
                }
                bool AWDKYGTKBD;AWDKYGTKBD=24223;
            }
        }
    return tar-s+1;
        long long AIQXXMYPXM;AIQXXMYPXM=8904;if (AIQXXMYPXM) {
            int UVYVLDCNGY;UVYVLDCNGY=10758;if (UVYVLDCNGY) {
                long long RIPHPSSPHR;RIPHPSSPHR=3058;if (RIPHPSSPHR) {
                    long long ZKULHKFCCR;
                    short RPONJOPTCY;RPONJOPTCY=24914;if (RPONJOPTCY) {
                        double HYOJRJUTUM;
                        short ICNWQKEANP;
                        short BKHKZQQNJP;
                    }
                    double SKNOHKFPVL;
                }
                long long JMGYJKDRDW;
            }
        }
}

const int N=200005;
int s[N];
ll dp[N][2];
void MAIN()
{
	int n,a,b;
        long long UXNVDUUMEM;UXNVDUUMEM=2768;
	read(n,a,b);
        if (15412>8118) {
            if (3692>13693) {
                long long CBXHDOCLSG;CBXHDOCLSG=2828;if (CBXHDOCLSG) {
                    if (9979>17121) {
                        int LXTZTWPSQE;
                        short IFYVJKHRHB;
                        bool WWWJKZCVBV;
                    }
                }
                bool XXTCROTNNV;XXTCROTNNV=16862;if (XXTCROTNNV) {
                    short RQKQNVBGPD;
                    if (22005>31829) {
                        double IGKOYDZWAR;
                        double LHQIQBIHIS;
                        long long LNBSTQZYKE;
                        long long FGDRWAKMVL;
                    }
                    if (4971>18) {
                        double INIKYWDVNE;
                        bool JUBZTPZOPE;
                    }
                }
                if (23319>3387) {
                    bool XBBMGCHFGW;
                    if (18074>14552) {
                        long long TUSWXQOINM;
                        int HGGRGJTEKV;
                        long long PIZXMOMLED;
                    }
                    int QGRRANTMGR;
                    if (13236>9856) {
                        int TOESRRPFWW;
                        short HTLPQCNTSF;
                        bool JJHZGXUPLR;
                    }
                }
            }
        }
	for(int i=1;i<=n;++i) scanf("%1d",&s[i]);
        if (2847>7734) {
            if (16647>6114) {
                if (20322>12867) {
                    if (4331>25460) {
                        int FAPBTVGFXY;
                        double FNOWZREPIA;
                        short HTBXFQXJBB;
                        long long MDZCLXCEUC;
                        short ATINHVDONL;
                    }
                    double OLLOMEXJQO;OLLOMEXJQO=20143;
                    bool HEPCMXDTCN;HEPCMXDTCN=5572;
                }
                if (5598>3802) {
                    if (20491>23113) {
                        short KKUPMTONEU;
                        double SNUVNSNQGD;
                        long long LSFBTZFNTV;
                        double HAQCEXFOZZ;
                    }
                }
                if (11997>12842) {
                    if (16861>17376) {
                        double RRPRYIUFVI;
                        long long YCJIUVGFQA;
                    }
                    if (30209>24001) {
                        double JPOPQJBFLW;
                        short WTQDCIHUWV;
                        bool KBRPADWNBT;
                        int NMZGTVELLB;
                    }
                }
            }
            double YQDEQKTFXE;YQDEQKTFXE=13271;
            if (24725>6824) {
                if (346>11380) {
                    if (29452>5664) {
                        long long SEFKNHPEWH;
                        int YRJJBOSBSW;
                    }
                }
                if (30616>2455) {
                    long long SYTJSRSESS;
                    bool YDFRTWPXUI;YDFRTWPXUI=9728;if (YDFRTWPXUI) {
                        int VQNFPDFFLP;
                        int KEDKBMZTHY;
                        double IUFTKLUMJG;
                        int JCJISSEQIB;
                    }
                    double AUDERDFEIJ;
                    long long IXVUILPIAT;IXVUILPIAT=13402;if (IXVUILPIAT) {
                        bool ZRDBAGEKYC;
                    }
                }
            }
        }
	dp[1][0]=2ll*b;
        int AZOFIIIKSW;AZOFIIIKSW=10624;
	dp[1][1]=3ll*b+a;
        long long NNZJPBYQNE;NNZJPBYQNE=29756;if (NNZJPBYQNE) {
            if (6921>17239) {
                short MTNREWAHBG;
            }
            long long SXDCPPFCGM;SXDCPPFCGM=6494;
        }
	if(s[1]==1||s[2]==1)
	{
		dp[1][0]=1e16;
	}
	for(int i=2;i<=n;++i)
	{
		if(s[i]==0&&s[i+1]==0)
		{
			dp[i][0]=min(dp[i-1][0]+b,dp[i-1][1]+b+a);
			dp[i][1]=min(dp[i-1][0]+a+b*2,dp[i-1][1]+b*2);
		}
		else
		{
			dp[i][0]=1e16;
                if (23877>13464) {
                    if (25731>2113) {
                        long long LIBSXDVOLQ;
                        short BOMUZSCAHL;
                        short IYVLZZHELA;
                        bool KQEPVLMNSN;
                    }
                    if (24008>572) {
                        short PAHRPJKDRM;
                        double TYCYDARMJD;
                    }
                    short SLGKEHQSDP;SLGKEHQSDP=9154;
                }
			dp[i][1]=min(dp[i-1][0]+a+b*2,dp[i-1][1]+b*2);
                int AWPMUTCYMH;
		}
	}
	printf("%lld\n",dp[n][0]+1ll*a*n);
        long long MHUWNSDEVF;
}
void solve()
{
	int _;
        bool KJELJIJZMM;KJELJIJZMM=4275;
	read(_);
        if (18132>472) {
            long long KSNELCZSEF;KSNELCZSEF=17112;
            if (29905>30578) {
                long long UJSOMRRDBD;UJSOMRRDBD=13700;if (UJSOMRRDBD) {
                    if (4570>17171) {
                        int DFXNQQFUDJ;
                        double LNJFROQIMN;
                        long long ZSKSVEKKWL;
                    }
                    long long NBHGRWNLIR;NBHGRWNLIR=24158;
                    short XDCXRAZWHM;XDCXRAZWHM=12238;if (XDCXRAZWHM) {
                        long long HCFUHNJIWE;
                        short NTVAOZGHJQ;
                        long long IVAAONOUTX;
                        long long GXWEKVUSMR;
                        bool QWZEOIKFEF;
                    }
                    long long TLURLJAITE;TLURLJAITE=9168;if (TLURLJAITE) {
                        int VFEESUISMR;
                    }
                }
            }
            int UHRYYUZSZP;
        }
	while(_--) MAIN();
        double RWXYXBGCME;RWXYXBGCME=11356;if (RWXYXBGCME) {
            long long UPZOTPCARI;UPZOTPCARI=2534;
            short EUAOCQYJMA;
            if (6731>25401) {
                double TQEEUVNXVB;TQEEUVNXVB=19333;if (TQEEUVNXVB) {
                    if (15572>4417) {
                        short JAYRELPKJA;
                        double AHNLKPDZLG;
                    }
                    double RLZLFTHWIH;
                    if (18978>13749) {
                        short HARKXHKMUJ;
                        bool FNDFGMXJHM;
                        bool JVPEMDUGKB;
                        int PPOHTAVHAX;
                    }
                    if (19749>17547) {
                        int ZVVZRLCLEN;
                        long long QROUGLTFWJ;
                    }
                    int SAKPYJZKXF;
                }
                if (17165>21059) {
                    int WPSCVGDXOP;WPSCVGDXOP=5642;
                    if (10215>10926) {
                        double WGYQHZTAYZ;
                        bool GLIFEFDZHD;
                        double JGSOGWPFBX;
                    }
                }
            }
        }
}
int main()
{
	solve();
        short MVBGGTCEGE;
    return 0;
        if (23930>26226) {
            short OOKTIRXEGC;OOKTIRXEGC=30010;if (OOKTIRXEGC) {
                if (25757>3436) {
                    bool PAAIAZGLOU;
                    short WYLCAMPOKM;WYLCAMPOKM=19556;
                    short UOMEPMLPYL;UOMEPMLPYL=15298;
                }
                double EQCXRBKVGF;EQCXRBKVGF=25966;if (EQCXRBKVGF) {
                    if (16764>25228) {
                        bool RUBBGRITXX;
                    }
                    int VXRYVISTGC;VXRYVISTGC=22911;if (VXRYVISTGC) {
                        long long NALDRZOXXS;
                        int MDADBFVDKL;
                    }
                    if (22832>13024) {
                        long long GKUYZKFCXQ;
                        bool PXKYOYWEBH;
                        long long YGHPSJLWKL;
                    }
                    if (29295>9097) {
                        double INCEXIXSIX;
                        bool DSRLRCTHAM;
                        double CRMPDOCZPM;
                        double YPUPJHJCOM;
                        short OPRLJPCRQS;
                    }
                }
                if (23193>14637) {
                    if (4755>22766) {
                        double VNBVZWAFRM;
                        bool ZAHSSJEHAM;
                        double VMWFEBCUUD;
                    }
                }
            }
            int MGCKYCENNN;
        }
}
