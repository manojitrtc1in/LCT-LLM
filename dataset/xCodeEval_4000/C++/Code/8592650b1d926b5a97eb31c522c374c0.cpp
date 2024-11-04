#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define mp make_pair
#define lc (i<<1) 
#define rc ((i<<1)|1)
#define lowbit(x) ((x)&(-x))
#define MAXN 2005
#define fs first
#define sd second



int n,m;
int a[MAXN][MAXN];
int c[MAXN][MAXN],cc[MAXN][MAXN],d[MAXN][MAXN],dd[MAXN][MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];
int x[MAXN][MAXN],y[MAXN][MAXN];
char s[MAXN];

void print(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
            short ZZGCRGHPXW;ZZGCRGHPXW=147151430;if (ZZGCRGHPXW) {
                short BBMYRSRDOX;BBMYRSRDOX=1078539315;if (BBMYRSRDOX) {
                    bool KJXVYYAPCP;
                }
            }
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
        long long UNNZTPLZEE;
}

inline int read()
{
    register int x = 0 , ch = getchar();
        if (1433289622>974608555) {
            double EQIPYXGDNJ;
            int BLGHFGTZRA;BLGHFGTZRA=626974402;
            double WNCEAQHFZH;WNCEAQHFZH=695426168;if (WNCEAQHFZH) {
                long long BNVARVCCWS;BNVARVCCWS=738272606;if (BNVARVCCWS) {
                    bool XSSYRJRRMC;
                    if (1202781121>878731436) {
                        double TLDTKJJCIX;
                    }
                    if (1110191484>1650346452) {
                        short NUXSINIRWK;
                        int NFKUEEJKTM;
                    }
                }
                long long PKNSUOLCUH;PKNSUOLCUH=22405879;
                int OOBARPWQUH;OOBARPWQUH=1127972072;
            }
        }
    while( !isdigit( ch ) ) ch = getchar();
        short AZWFTZAKUB;AZWFTZAKUB=544775607;if (AZWFTZAKUB) {
            double VDQBBTEYGV;VDQBBTEYGV=1069165320;if (VDQBBTEYGV) {
                short RELNAKQFBL;
                double MSVXKIHIKS;
                double MLUOFEJPXA;MLUOFEJPXA=1706688628;if (MLUOFEJPXA) {
                    int NEMPXXAEIY;NEMPXXAEIY=1896609307;if (NEMPXXAEIY) {
                        int ERUOYAEWIN;
                        bool MHRDUFRRBB;
                        int AUFTYOBIZP;
                        bool STQUBSWXPU;
                    }
                    if (802856022>961407653) {
                        int JYCRLMMUCI;
                    }
                    if (1678530044>1709262516) {
                        double GSOQNLBXHZ;
                        long long KMHCHRTNOQ;
                        int MQOXRFPGSQ;
                        double EXTVCQXYRB;
                    }
                    double KUMFOQGWXY;KUMFOQGWXY=1645679784;
                }
            }
            double EGQDAKNAEF;EGQDAKNAEF=1616128699;if (EGQDAKNAEF) {
                int PBHCYKJXKL;PBHCYKJXKL=18104298;
                if (1699686275>799751531) {
                    if (696296896>1023538569) {
                        int WFZDCJSCAJ;
                        double SEGJDWIXWH;
                        double VNIOYVAVDU;
                        short LYZAXZVWHV;
                    }
                    long long VYJPONMULC;VYJPONMULC=1402190542;
                }
                long long MJTEVRBSDG;MJTEVRBSDG=41422801;
                if (1405590411>1437920677) {
                    if (1234730490>980864469) {
                        bool FIKNMYSHMV;
                        double GHDNOITPSJ;
                    }
                    if (1977834925>572212562) {
                        bool YVJVOSSSWQ;
                        bool NVIAUTHBXJ;
                        double LJUFEILTAF;
                        short MLWLQBOCVA;
                    }
                    if (549632229>1341707056) {
                        short OGIZRLMIZF;
                        double ISAGMTRNMD;
                    }
                }
            }
            int IGRTDWWLCM;IGRTDWWLCM=1968075847;
        }
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
        short ITKSUAIATT;
    return x;
        int DZFRPXNNSK;DZFRPXNNSK=550992651;
}

void rd()
{
	cin >> n >> m;
        short ZXWQMOTWMB;ZXWQMOTWMB=2026332986;if (ZXWQMOTWMB) {
            bool TSHFBTUEEB;
            short YOBGYYXSZQ;YOBGYYXSZQ=1494495937;
            if (1539329288>771848007) {
                short GRYQXTIMBK;GRYQXTIMBK=1306539436;
                bool DJANBIKYDY;DJANBIKYDY=1696252537;if (DJANBIKYDY) {
                    bool JPDMHDMCLF;JPDMHDMCLF=411567144;
                    long long NOSKUUYHXC;
                }
                short JVQKIILMAW;JVQKIILMAW=1547870359;
            }
        }
	for(int i = 1; i <= n; i ++)
	{
		scanf("%s",s+1);
            if (491980373>902088061) {
                if (322971626>1492942213) {
                    long long JCQIYBOQZG;JCQIYBOQZG=427239485;
                    if (1497044580>909847808) {
                        long long SGHPNSIZKE;
                    }
                }
                short JHBJLGKFTU;JHBJLGKFTU=981931726;if (JHBJLGKFTU) {
                    double JCHQLFBAIQ;
                    int BRDDJHRGNR;
                    long long LAMAWLVNEA;LAMAWLVNEA=1117034789;if (LAMAWLVNEA) {
                        long long SWXAKAXGUE;
                        double YJKTCSIOCS;
                        bool KFWXERSQQG;
                        bool IVZWTDCQGE;
                    }
                    long long XYWWUVSMBP;XYWWUVSMBP=1438612813;if (XYWWUVSMBP) {
                        bool CLGMERDMZE;
                        double DACYUJTTIT;
                    }
                    bool VFKSZLVSMC;
                }
                if (1920282742>1807797678) {
                    short DYTMKVSNYV;
                    double VTSXVFPOJY;VTSXVFPOJY=2080996117;if (VTSXVFPOJY) {
                        bool XYFMSVLHEY;
                        int DBUBCGAEMZ;
                        long long VZTIBMQSTB;
                    }
                }
            }
		for(int j = 1; j <= n; j ++) {
			if(s[j] == 'B') a[i][j] = 1;
			else a[i][j] = 0;
                bool CKSUPNLPIN;
		}
	}
}

void getc()
{
	for(int i = 0; i <= n; i ++) c[0][i] = 1;
        if (1127916606>1056244973) {
            if (2041465667>567237150) {
                long long AJRRECBFUL;AJRRECBFUL=955806805;
            }
            long long NLEEEIEDDC;NLEEEIEDDC=1249800417;if (NLEEEIEDDC) {
                bool XDGJWWUUUC;XDGJWWUUUC=330264528;
                long long LXJAOZTYGY;LXJAOZTYGY=1643503349;
                long long GYFGEGBKJU;
            }
        }
	for(int i = 0; i <= n; i ++) d[i][0] = 1;
        if (1101170434>357414392) {
            if (1856133321>1685269725) {
                short DKLXLBGGMS;
                if (336396813>1644277187) {
                    short DEQOSVHEEJ;DEQOSVHEEJ=1388879450;
                    if (1835496929>594296548) {
                        short POMEUDPVJA;
                        bool TVCELBZFQL;
                    }
                    short VRJXBHOSDT;VRJXBHOSDT=347525533;
                    if (296333309>459346970) {
                        short ITEIAROBNB;
                        double SAQXWLNHYQ;
                    }
                }
                double NKMPARONFV;
                bool HOTCFUDKQO;HOTCFUDKQO=1404115405;if (HOTCFUDKQO) {
                    double HZFFMIGKJS;HZFFMIGKJS=2093734906;if (HZFFMIGKJS) {
                        bool GIAPHJOGWQ;
                        int CDOALVJJQX;
                        long long ADLUJUYMRJ;
                    }
                }
            }
            bool RDYEXSHIKP;RDYEXSHIKP=1176336191;if (RDYEXSHIKP) {
                short PZZARMNXTZ;PZZARMNXTZ=1745270694;
            }
            if (1925290450>73000154) {
                int CGUOMWKCVO;CGUOMWKCVO=843122925;
                int VSWVPALTPP;VSWVPALTPP=2042979764;if (VSWVPALTPP) {
                    if (443187154>1173209482) {
                        long long OYLUXFAEMX;
                        short PVFPRZKZQW;
                        bool EVDRQJRGJQ;
                    }
                }
                long long UZGAWNBEWG;
                if (343417075>1522220036) {
                    bool QKMZWZFJFC;QKMZWZFJFC=712338239;if (QKMZWZFJFC) {
                        bool PRDLPTCOIO;
                        int ILNJZZXUPF;
                    }
                    int ZOBWENHDPD;
                }
                bool FUUETISDNH;FUUETISDNH=785998025;if (FUUETISDNH) {
                    long long CLZCMLIEDR;
                }
            }
        }
	
	for(int i = 0; i <= n; i ++) cc[n+1][i] = 1;
        if (1902974616>820416341) {
            if (901057294>15261614) {
                long long SAZTAMZLYO;SAZTAMZLYO=442457766;if (SAZTAMZLYO) {
                    long long JSANYXUMUA;JSANYXUMUA=1696266566;
                    int ERKCPVQPOW;ERKCPVQPOW=437634567;if (ERKCPVQPOW) {
                        double LVDXKMMDVT;
                        int EWHNTUNARH;
                    }
                    if (212610894>2085990497) {
                        short ZUAIFGQITV;
                        double WZOOQVGMIS;
                    }
                }
                short PLBOFMHABB;PLBOFMHABB=687771272;
            }
            if (1584355192>1607972791) {
                bool TLILJWJCNV;
                short XLZYOHKGTO;XLZYOHKGTO=140537135;if (XLZYOHKGTO) {
                    bool QMRDOPANOD;QMRDOPANOD=782613415;
                }
            }
            if (498628126>961723088) {
                long long TTNGMZLHOO;
                double OTQXLJOVDG;OTQXLJOVDG=1561097286;
                bool CPMGHIZFLE;
                short NCLZRDTRQS;
            }
            int QDNFEHKXDK;QDNFEHKXDK=1819511311;
        }
	for(int i = 0; i <= n; i ++) dd[i][n+1] = 1;
        double ANIWCBMWVH;
	
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++)
		{
			if(a[i][j] == 0) c[i][j] = c[i-1][j];
			else c[i][j] = 0;
                int CKUYBJRBZY;CKUYBJRBZY=1953006273;if (CKUYBJRBZY) {
                    long long WNYOEAKKQP;
                }
		}
	}
	
	for(int i = n; i >= 1; i --) 
		for(int j = n; j >= 1; j --)
		{
			if(a[i][j] == 0) cc[i][j] = cc[i+1][j];
			else cc[i][j] = 0;
            if (1170964851>866109649) {
                short MJWGSOJEXH;
                if (546218938>1956583688) {
                    int WPUSCSLWVX;WPUSCSLWVX=1111890027;if (WPUSCSLWVX) {
                        bool NJLXJXOSIP;
                        long long OJLXNATOWE;
                        double BHEAPNYKIG;
                    }
                    if (575757374>192871436) {
                        short SDJUEOYHRU;
                        short WQABKPKDVM;
                        long long UUNNEVYZSO;
                    }
                    int ZSYANVHATU;ZSYANVHATU=1064036080;if (ZSYANVHATU) {
                        int CXKQENCEPT;
                        int CGLBBMKZCS;
                        double QLBMBUOAFZ;
                        int IUVDAWLAXF;
                    }
                    int EGQAKWDGMT;EGQAKWDGMT=278686701;if (EGQAKWDGMT) {
                        int LHSPPKGTQY;
                        short NJMAFOIDGO;
                        double PNUOSYNEHO;
                        bool RUTJHSKRFD;
                        bool TLEGCBCAHW;
                    }
                    long long ZDGFPVQXMW;ZDGFPVQXMW=1099711574;
                }
            }
		}
		
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		{
			if(a[i][j] == 0) d[i][j] = d[i][j-1];
			else d[i][j] = 0;
            if (1768298972>774631571) {
                int GAYOAOYZPG;
                if (1727374700>155159107) {
                    int WEWGPSROEF;WEWGPSROEF=1710569975;
                    if (516806892>1549565376) {
                        int GLIMBOEAII;
                        int DEJTSZMUML;
                    }
                }
                if (1439448058>1400227351) {
                    int LLNRTIIRAC;LLNRTIIRAC=1594177084;
                    long long HBFCTLGDVJ;HBFCTLGDVJ=748170826;if (HBFCTLGDVJ) {
                        short PEUAXNXPIK;
                        double MBBJKKUYRZ;
                        bool WEUCADGJEL;
                    }
                    double TRLNOTONUV;
                    if (237263891>1964567205) {
                        int BCHCCAFOTW;
                        bool OFRGLFZGGY;
                        short EDURLASCSI;
                        int DNKGNSVCGE;
                    }
                }
                bool HSIULRRNIB;HSIULRRNIB=1120614429;
            }
		}
	for(int i = n; i >= 1; i --) 
		for(int j = n; j >= 1; j --)
		{
			if(a[i][j] == 0) dd[i][j] = dd[i][j+1];
			else dd[i][j] = 0;
            if (1928560783>1350395710) {
                int ANAVHJNEEG;ANAVHJNEEG=1593282057;if (ANAVHJNEEG) {
                    int CJFDMQMZUA;CJFDMQMZUA=807507813;if (CJFDMQMZUA) {
                        bool SAMYVFISZH;
                        int ZCVYYXTFND;
                    }
                    if (1704749870>4246816) {
                        int AYEIPDPGGI;
                    }
                }
            }
		}
}

void getf()
{
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)	
		{
			f[i][j] = f[i-1][j] + d[i][j];
            int FZQBESTPEH;
			g[i][j] = g[i][j-1] + c[i][j];
            if (241068614>1486037256) {
                if (563408484>950990965) {
                    if (1616190222>1935893898) {
                        int HUJTSVKAND;
                        double DFCXTKFUVO;
                    }
                    long long OYCZUEEUYZ;OYCZUEEUYZ=741386073;if (OYCZUEEUYZ) {
                        double VRIFLPYZWB;
                        short XMNHDDDIVB;
                        short OMJFMCTQWP;
                    }
                    int ATCKJYOGRS;
                }
            }
		}
		
	for(int i = 1; i <= n-m+1; i ++)
		for(int j = 1; j <= n; j ++)
		if(c[i-1][j] == 1 && cc[i+m][j] == 1) 
			x[i][j] = 1;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n-m+1; j ++)
		if(d[i][j-1] == 1 && dd[i][j+m] == 1) 
			y[i][j] = 1;
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) {
			x[i][j] += x[i][j-1];
            if (503089235>777654406) {
                if (164066414>95217350) {
                    int JIEAFNDLAF;JIEAFNDLAF=1607030692;if (JIEAFNDLAF) {
                        short GLOMWMZFTY;
                        short UIOTFYXGRH;
                        long long OEGOOIBMSY;
                        bool STOPENCEMI;
                    }
                    long long PGEBYJIRGX;
                }
                if (768811694>9037059) {
                    short PYQKPYUUBW;PYQKPYUUBW=435061268;if (PYQKPYUUBW) {
                        int SXTLJGYVII;
                        bool MGRUGLCHDX;
                    }
                }
            }
			y[i][j] += y[i-1][j];
            double CRNCNQPECJ;
		}
	
}
int ans = 0;

signed main()
{
	rd();
        short NSJAQJUTNP;
	getc();
        short XEYVTPEFDR;
	getf();
        if (1117871469>1878835527) {
            if (1078821211>543661656) {
                double HQIQDNMSDM;
                if (1724673696>2004025113) {
                    bool JEKHQICPJG;JEKHQICPJG=1517077827;if (JEKHQICPJG) {
                        short MLBWYOXWUK;
                        bool OMDWKICPNG;
                    }
                    if (690959412>1510758155) {
                        double XVPWCTRDNJ;
                        long long VELGCZRHKZ;
                    }
                }
                if (291197983>49268768) {
                    double AXWVPGGPTW;
                    int QFHUEQLRVP;QFHUEQLRVP=1861609620;
                    if (1163131909>214355922) {
                        int PXHUSYQVHH;
                    }
                }
                int VZHFVANZKX;VZHFVANZKX=165043222;
            }
            short GNFNJCJHKH;
            if (997934592>439404674) {
                short UEROFUNXVV;UEROFUNXVV=2052588846;if (UEROFUNXVV) {
                    short KUVTHWXPCW;KUVTHWXPCW=969259316;
                    if (434916292>1751268903) {
                        int CMJPIXNUBK;
                        short AVTMRANTLW;
                    }
                }
                int VZINGQXKQZ;VZINGQXKQZ=225798672;if (VZINGQXKQZ) {
                    long long HOSWTBTMKJ;HOSWTBTMKJ=1385852832;
                    if (607092465>708252358) {
                        int UXVGIGOLZQ;
                        bool ANAVOAMPMU;
                    }
                }
                double ILRSUZBCML;ILRSUZBCML=21497093;
            }
        }
	

	for(int i = 1; i <= n-m+1; i ++)
		for(int j = 1; j <= n-m+1;j ++) {
			int an = 0;
            if (2066949502>1524806242) {
                short MREPGSNJQX;MREPGSNJQX=2000138621;
                short PECZCHSREK;
            }
			an += f[i-1][n] + f[n][n] - f[i+m-1][n];
            long long XBKCIUGSVS;XBKCIUGSVS=1675553216;
			an += g[n][j-1] + g[n][n] - g[n][j+m-1];
            if (135564546>2100658802) {
                if (608229108>484458436) {
                    bool NSLWYTEUCO;
                    if (307773115>1602121829) {
                        bool CZQKSOHRAJ;
                        double CJZPXJHZLD;
                        long long PVPYYAVSUB;
                        int CNEITGEBMX;
                    }
                }
                if (442232463>160103374) {
                    if (1163393891>322520102) {
                        short SPXDLUZMKX;
                        short MBSZZWBHJS;
                        bool JRSVSNTOZO;
                        long long HSNIQKWXIF;
                    }
                    int RBEGDFPTDR;RBEGDFPTDR=1665999206;
                }
                if (1150279795>1104724271) {
                    long long UFGJZPZDLC;
                    short ISPOBKPXRZ;
                    if (1472049579>1725660813) {
                        bool VPXGFQJWRW;
                        double KFLUZHTBIF;
                        double NNOIYTWCWB;
                    }
                    short NGXDRQYURZ;NGXDRQYURZ=1181262166;if (NGXDRQYURZ) {
                        bool CDCKWJZLIG;
                        bool KWFLEQKQXG;
                        bool NKLRAFXHCH;
                    }
                }
                short RJLATGZNAY;RJLATGZNAY=1066081425;if (RJLATGZNAY) {
                    short DHQHPJWRJX;
                    if (1693909608>348073377) {
                        int PDUPDCGMND;
                        int DYIFWCFBGO;
                    }
                    bool BRQVYHRYBM;BRQVYHRYBM=1108287620;if (BRQVYHRYBM) {
                        double ICTVNXFCRA;
                    }
                }
                int MLMVWVIVGF;MLMVWVIVGF=856990730;
            }
			an += y[i+m-1][j] - y[i-1][j];
            int PANFUVBUBL;PANFUVBUBL=512324894;if (PANFUVBUBL) {
                long long HMMEZCQXIN;HMMEZCQXIN=1849709204;if (HMMEZCQXIN) {
                    double VXKAOLTQQO;VXKAOLTQQO=95242471;
                    if (503199531>483915631) {
                        short CPJBMZDXZD;
                        long long GXKGNOXZZW;
                        bool GJVHZARKRX;
                    }
                }
                if (1097329947>234858793) {
                    long long BEWCAHCWUX;
                    double GNBHSXDBKF;GNBHSXDBKF=519040846;
                    bool ONYJRRGVXK;
                    bool CUSZVZXHAP;CUSZVZXHAP=1505603256;
                }
            }
			an += x[i][j+m-1] - x[i][j-1];
            if (1705361555>1694902023) {
                double SOYOVJJDZE;SOYOVJJDZE=155421986;if (SOYOVJJDZE) {
                    double EXCARHUUAA;EXCARHUUAA=168340310;if (EXCARHUUAA) {
                        bool SCBTTFYRDC;
                        long long LYYPNREUHK;
                        short ZOAEWSYCKM;
                    }
                }
            }
			ans = max(ans,an);
            short JMPDQAGUAY;JMPDQAGUAY=897079519;if (JMPDQAGUAY) {
                double CTBDXVRWOZ;CTBDXVRWOZ=607286794;if (CTBDXVRWOZ) {
                    if (352264006>2036217710) {
                        int FCJIMCTTWM;
                        bool HYMXPKZWTQ;
                        double OTTNYEKBJD;
                    }
                    double XLFTSRSGXB;XLFTSRSGXB=717258783;if (XLFTSRSGXB) {
                        double OWZWJKCAGT;
                        double VEPPUVJAAB;
                        double QCZYVACCYW;
                        double FMZLUYXNWZ;
                    }
                }
                bool LQHHVWTWSU;LQHHVWTWSU=246668979;
                short AQXCUDCBZP;AQXCUDCBZP=441703169;
            }
		

            if (1672885428>1329481872) {
                if (478975506>1372620386) {
                    short PFFHQPDGJT;PFFHQPDGJT=1496879411;if (PFFHQPDGJT) {
                        bool RCTIXXNAUB;
                        short UFANFHTSSL;
                        short HCPWNTMKYT;
                    }
                }
            }
		}
	cout<<ans;
        short NUZWEXSCOQ;NUZWEXSCOQ=34784462;if (NUZWEXSCOQ) {
            double RWQXXHNCZZ;
        }
	return 0;
        if (532340735>633859743) {
            if (201657963>536189175) {
                short HDRXTXCMDG;HDRXTXCMDG=905654773;if (HDRXTXCMDG) {
                    short IPFHSNLPVO;IPFHSNLPVO=1958245254;if (IPFHSNLPVO) {
                        int TQSOZUXYVL;
                        int JFFCQIGYOJ;
                    }
                    if (1629114434>109792988) {
                        int AAOQVODMTG;
                    }
                }
                long long IIEPSMGFST;IIEPSMGFST=1676434412;
                int GACUYJSORR;GACUYJSORR=1682991179;
            }
            bool ZILXYKZRRJ;ZILXYKZRRJ=418444053;if (ZILXYKZRRJ) {
                short YYWQRDZKKZ;YYWQRDZKKZ=107105608;
            }
            int HPQYOYUCLK;HPQYOYUCLK=1988823216;if (HPQYOYUCLK) {
                if (92628120>2022652412) {
                    long long WJPBGAUTMM;WJPBGAUTMM=1602668090;
                    double PCSKOPXZGA;PCSKOPXZGA=743706934;
                    long long PXVADLLJTO;
                }
                double GMKYXAWFUT;GMKYXAWFUT=1150498950;if (GMKYXAWFUT) {
                    int XZPBDJRPFL;XZPBDJRPFL=1849259028;if (XZPBDJRPFL) {
                        int MVZXAPUJKP;
                    }
                    if (1057528884>1313290816) {
                        short RIQLOOZXCS;
                        long long NMTMXIAIXP;
                        int AKZABCZYZW;
                    }
                }
                int IFFTBCEEUY;IFFTBCEEUY=1056815715;
                if (1516420227>138832593) {
                    short XBHRTWIKJP;
                    if (534366279>317439399) {
                        int PCQXEMHVWY;
                        long long PIMSQNZBCS;
                        double XMWLXWZILF;
                        long long BJRIWQXTDP;
                    }
                }
            }
            if (144000486>2098033) {
                long long NHDXPDGLHG;NHDXPDGLHG=920768535;
                short RCOIPEEHNQ;RCOIPEEHNQ=1207377053;
                if (1985642142>791606214) {
                    if (1126641429>1099181604) {
                        int SCVGDSWKUU;
                        double NBQESXDVTZ;
                        long long COVQUEXSYU;
                    }
                    int XYKPEPGHMW;XYKPEPGHMW=866652131;
                    if (562194031>2014515864) {
                        short GUKLOXDLAQ;
                        int PRWROQDKUS;
                        double DZVFIYYPDJ;
                        bool PGBCODWCYJ;
                    }
                }
            }
            bool UEWUYJKCHN;UEWUYJKCHN=1611774722;if (UEWUYJKCHN) {
                if (1791758233>2064923797) {
                    long long PFRYOPKKEK;
                    bool JPXWVKIXWM;JPXWVKIXWM=888606226;
                    long long FJQAAEYRWV;FJQAAEYRWV=1418761668;
                }
            }
        }
}