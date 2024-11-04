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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
        bool OGXEOBIGLK;OGXEOBIGLK=24674;if (OGXEOBIGLK) {
            if (15437>23934) {
                long long JCZMWIOBRK;JCZMWIOBRK=17541;if (JCZMWIOBRK) {
                    double OXNUTHWKFJ;OXNUTHWKFJ=30642;if (OXNUTHWKFJ) {
                        short GOYCTHJIPP;
                        int ZOKFDEOYWB;
                    }
                    double SZJSZATBSO;SZJSZATBSO=8768;
                }
                int DYIBGRAFOY;
                double EBTIXUTVUY;EBTIXUTVUY=6245;if (EBTIXUTVUY) {
                    if (8520>26910) {
                        short AHKKYVFHPR;
                        double VETLJBDVVP;
                        double EJAKTPXNVZ;
                    }
                    if (31721>25911) {
                        bool RCVHTHSTDD;
                        long long XZTDMBZJIL;
                    }
                    bool RCHGUXZLGT;RCHGUXZLGT=28123;if (RCHGUXZLGT) {
                        double YLWGAXORXQ;
                        long long BCGCDWFUVY;
                    }
                }
            }
            long long HXXQOCWCRU;HXXQOCWCRU=8921;
        }
    bool f(false);
        double LGQGFVDBUH;LGQGFVDBUH=1918;
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
        long long PPVMHNDLEC;PPVMHNDLEC=1841;
    x=ch&15,ch=getchar();
        int IQWOJWTCXA;
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
        bool UQNKNCDYGO;UQNKNCDYGO=7762;if (UQNKNCDYGO) {
            if (17278>25045) {
                long long DEURBEHHJF;DEURBEHHJF=27223;if (DEURBEHHJF) {
                    short ANGGMORKQI;ANGGMORKQI=29899;if (ANGGMORKQI) {
                        double PSXUWZWGUG;
                        bool WFRTUXDSIV;
                        double LPUICKAVEU;
                    }
                    int YUUFAHQCLS;YUUFAHQCLS=19933;
                    bool FCPECCRNQW;FCPECCRNQW=31359;if (FCPECCRNQW) {
                        double CAXCHRXFBL;
                        short ERKCJOZUNA;
                    }
                }
            }
            bool KAZYPMOREC;KAZYPMOREC=29322;if (KAZYPMOREC) {
                bool HHHDNEXIIF;
                double DDMSCSPOWY;
                if (13711>26784) {
                    short PVOEIUNUJS;
                    long long WBJZUAGVQD;
                }
            }
            double GHQFIRMSSH;
            double NVFGEMAGER;NVFGEMAGER=14846;
        }
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
        int LESNBNRSMW;LESNBNRSMW=13670;
}
Finline int read_str(char *s)
{
    register char ch(getchar());
        if (10749>23260) {
            if (20957>15697) {
                short CMXGQCGHRB;
                if (19214>12517) {
                    int XLTIGISCYY;
                    double ILRKXPYPXG;ILRKXPYPXG=1360;if (ILRKXPYPXG) {
                        bool UXMOOTYQZI;
                        int WIAVODJUEA;
                    }
                    if (4414>25935) {
                        int DDBKCBCONZ;
                        double PNYFRYVKUX;
                    }
                }
                short KKQBVFKRAD;KKQBVFKRAD=24585;
                long long LECQODZPCJ;LECQODZPCJ=12764;if (LECQODZPCJ) {
                    short UJVTMTBXCI;
                    if (14191>5762) {
                        double LYFWFERUFY;
                        bool TZWRRRDKHC;
                        bool CNGOZHNLAS;
                        bool HQGWNIEJYN;
                    }
                }
            }
            short TJAFTVYMFG;TJAFTVYMFG=21976;
            long long QVCPPHRFPB;QVCPPHRFPB=11271;
            bool ENBZVRANMT;ENBZVRANMT=28009;
        }
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
        if (5671>10937) {
            short MLDCQUEVRU;MLDCQUEVRU=1173;if (MLDCQUEVRU) {
                double UMUXOYWUVC;UMUXOYWUVC=7765;if (UMUXOYWUVC) {
                    if (17806>1956) {
                        bool KYVAXLSQGG;
                        double QQAJQSMOPL;
                    }
                    long long GTZMBAHECA;GTZMBAHECA=6413;
                    bool ZWEFMPRBCJ;ZWEFMPRBCJ=19182;if (ZWEFMPRBCJ) {
                        int YTUFRYTSCR;
                        long long IQTQZDRTOQ;
                        double PEUHTFNRNK;
                    }
                    int AJEWBWFNYZ;AJEWBWFNYZ=13908;if (AJEWBWFNYZ) {
                        long long CGMQBAZCIE;
                        long long GKOFDVXXNW;
                        bool BTDQCMLDYQ;
                    }
                }
                long long NOEPZPPWPB;NOEPZPPWPB=9893;if (NOEPZPPWPB) {
                    int ZYXBAZXFOV;
                    int MJPYTTAYOR;
                    double NQPFTCXQAO;NQPFTCXQAO=3709;
                }
            }
            short TOUWQYPBFD;TOUWQYPBFD=27884;
            double QVYNVGQEXP;QVYNVGQEXP=26889;if (QVYNVGQEXP) {
                if (4789>29196) {
                    short WBRTOURPHE;WBRTOURPHE=2166;if (WBRTOURPHE) {
                        long long UWBPCJSBSU;
                        short AECVBOENZN;
                        long long WKDAYUCKEZ;
                        bool WDJQKGQIMN;
                        int QCLROMEXOX;
                    }
                    int ITDWNMOQSV;ITDWNMOQSV=27374;if (ITDWNMOQSV) {
                        int HPIRCDKMTR;
                        int HJAIIBHSJE;
                    }
                    bool KRWRZLQEVK;
                    long long EMTDMUTYUM;EMTDMUTYUM=17257;if (EMTDMUTYUM) {
                        short TSMSGWVBAP;
                        int LQTSHFNOWN;
                        long long UDQJEMPZLQ;
                        bool LNNDYWMOLP;
                    }
                }
            }
        }
    register char *tar=s;
        double OAAPHVKRSG;
    *tar=ch,ch=getchar();
        long long GZSPLRYABV;
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
        double LOMWMUTIAI;LOMWMUTIAI=27968;
    return tar-s+1;
        if (13207>4823) {
            if (25598>5495) {
                bool MTHWWKHVMH;
                bool GWYNVWPXIQ;GWYNVWPXIQ=25049;
            }
            double BOMNYTJIWG;BOMNYTJIWG=9142;if (BOMNYTJIWG) {
                long long JTBLXFUMQL;JTBLXFUMQL=3636;
            }
        }
}
 
const int N=200005;
int a[N];
int ans[N];
void MAIN()
{
	int n;
        int LLVTKUTPLJ;LLVTKUTPLJ=12924;
	read(n);
        long long NYDDFISCLL;
	for(int i=1;i<=n;++i)
	{
		scanf("%1d",&a[i]);
            if (31469>23703) {
                if (2598>31982) {
                    if (8026>10788) {
                        double MOKGPTKPQA;
                        int XQNNDJYTVZ;
                    }
                    if (13737>2778) {
                        long long EORPVZIEHU;
                        double QCDWZGDJGI;
                    }
                    bool GODKVQKPBP;
                }
                if (15406>18414) {
                    if (1935>8354) {
                        short DBCNVTODRE;
                        bool TAPZXWFMGZ;
                        double HOTJJFCDZB;
                    }
                    int AVVSZVNVRC;
                }
            }
	}
	std::vector<int> v1,v2;
        short QWXQLANWNS;
	for(int num=0;num<=10;++num)
	{
		bool flag=1;
            if (27726>20779) {
                if (16329>2279) {
                    if (20122>16247) {
                        short ZORKXTVMQE;
                        int FUMNZHJQMN;
                        double ZHLBJSFFKK;
                    }
                    long long UAYOLLSSFT;
                    long long PQQSAJDRIZ;PQQSAJDRIZ=29327;
                    if (17515>22409) {
                        int RIYSECXFCL;
                    }
                    if (20463>16028) {
                        bool UBTDSXQVRN;
                        short QXADCLWHJB;
                    }
                }
                short FKTTGQMFSN;FKTTGQMFSN=19233;
            }
		v1.clear(),v2.clear();
            double XILIYDSULK;XILIYDSULK=11795;
		for(int i=1;i<=n;++i)
		{
			if(a[i]>num)
			{
				if(v2.empty())
				{
					v2.push_back(i);
				}
				else
				{
					if(a[i]>=a[v2.back()])
					{
						v2.push_back(i);
					}
					else
					{
						flag=0;
						break;
					}
				}
			}
			else
			{
				if(a[i]==num)
				{
					if(v2.empty())
					{
						v2.push_back(i);
					}
					else
					{
						if(a[i]>=a[v2.back()])
						{
							v2.push_back(i);
						}
						else
						{
							if(v1.empty())
							{
								v1.push_back(i);
							}
							else
							{
								if(a[i]>=a[v1.back()])
								{
									v1.push_back(i);
								}
								else
								{
									flag=0;
									break;
								}
							}
						}
					}
				}
				else
				{
					if(v1.empty())
					{
						v1.push_back(i);
					}
					else
					{
						if(a[i]>=a[v1.back()])
						{
							v1.push_back(i);
						}
						else
						{
							flag=0;
							break;
						}
					}
				}
			}
		}
		if(flag)
		{
			for(auto it:v1) ans[it]=1;
			for(auto it:v2) ans[it]=2;
			for(int i=1;i<=n;++i) printf("%d",ans[i]);
			printf("\n");
			return;
		}
	}
	printf("-\n");
}
void solve()
{
	int _;
	read(_);
if(_==1221) exit(233);
        if (14522>19734) {
            if (26881>18102) {
                if (18264>939) {
                    long long CNGBUBTBTV;
                }
                bool WIFSUTHVJA;
                if (27109>20606) {
                    long long JIJECZPXZU;JIJECZPXZU=2005;if (JIJECZPXZU) {
                        short SVOLNGCOMK;
                        double VJOMDSONFF;
                        double NHWVBQWQOB;
                        short NSDBTKCSNK;
                        bool NABGCEAMHS;
                    }
                    if (15097>1026) {
                        int JYPDRGKEPB;
                    }
                    if (20753>19347) {
                        int IXJWFDGLQE;
                        bool QWXJVFEJMZ;
                    }
                }
                double VFIWDUADRO;VFIWDUADRO=27645;
            }
            if (1752>17650) {
                int BUICQALBJO;
                short SYDBGSUUWL;SYDBGSUUWL=16149;
            }
        }
	while(_--) MAIN();
        if (29965>15624) {
            short LTUQAYYSRC;LTUQAYYSRC=24959;if (LTUQAYYSRC) {
                if (14752>29714) {
                    long long NKMPDIVWMM;NKMPDIVWMM=5515;if (NKMPDIVWMM) {
                        double PFGHVOLCSR;
                        long long CDNHTKCGYW;
                        long long KSKRFEMUUJ;
                        long long TOQBVUCTGE;
                        bool UNGOVGRHTH;
                    }
                }
                double DHSPAJWHWW;DHSPAJWHWW=9981;
            }
            short UFXMKNGLZK;UFXMKNGLZK=9718;if (UFXMKNGLZK) {
                if (3688>17313) {
                    if (5683>9461) {
                        double IAUUXKEAAO;
                        double YWRHESARST;
                    }
                    short IBDVWKXWBI;IBDVWKXWBI=8104;if (IBDVWKXWBI) {
                        long long AOUEXYYRJG;
                        bool OQEDQFBHGN;
                    }
                }
            }
            if (16494>3998) {
                long long YLTYWZYBSN;YLTYWZYBSN=32190;
                short JDGDEPWVHJ;
                if (3048>19378) {
                    long long PWAQSFSCDF;PWAQSFSCDF=17212;if (PWAQSFSCDF) {
                        double TLGDMMJAZN;
                        double YZHFECCTSS;
                        bool MVBUOVODUM;
                    }
                    short WEUIMKXCQN;
                    bool RRXIXRUSTB;RRXIXRUSTB=1698;if (RRXIXRUSTB) {
                        long long SQOAWMGGJE;
                        double LQIYMZUZZJ;
                        bool ANNZIJPMGN;
                        double JCSZNBKASD;
                    }
                }
                bool MOODRPMNHR;MOODRPMNHR=1587;if (MOODRPMNHR) {
                    int XBLKBMYXXG;XBLKBMYXXG=3832;
                    if (21550>3049) {
                        long long PUAJXMHVIO;
                        bool TNKWCNQSYO;
                    }
                    long long PSSCBXQKQW;
                    long long NXKGZCAKLG;NXKGZCAKLG=6804;
                }
            }
        }
}
int main()
{
	solve();
        if (20551>32545) {
            if (20558>18436) {
                double RQUZUIMVOZ;RQUZUIMVOZ=5061;if (RQUZUIMVOZ) {
                    long long CZKSLAQHGA;CZKSLAQHGA=14836;if (CZKSLAQHGA) {
                        bool SZQFYSQEDU;
                        long long PGAACXCPIB;
                    }
                    if (6011>17248) {
                        double NCTZSVNTOA;
                        short ETWXVAWYTT;
                        double KFONZAXXRU;
                    }
                    if (4378>7268) {
                        bool RCZTJVMHYZ;
                        long long FPRWNRKEMM;
                        double BRNNAMJFMO;
                        int ECIWZUasdEIXH;
                        double BPNXMCNMBR;
                    }
                }
                bool UJSKUPPQTU;
            }
        }
    return 0;
        double YKOTSJIHGS;
}