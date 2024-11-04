#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#ifndef AT_HOME
#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)
#endif

namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}

	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
            int ZTZTOHCSPK;
		x = 0;
            if (7755>8274) {
                if (21171>22728) {
                    int YJQQVJATCT;YJQQVJATCT=17917;
                    bool ZJVAMAPCVN;ZJVAMAPCVN=3520;if (ZJVAMAPCVN) {
                        double KLZYVXHJRI;
                        int DDCYHMSBOW;
                        long long UTADDRMRAD;
                    }
                    short XYNTEYLPWE;XYNTEYLPWE=10327;if (XYNTEYLPWE) {
                        int VLQNSDCHCN;
                        double CHFKZNZJKR;
                    }
                    if (27957>277) {
                        int JUOPMOZCXG;
                        double VCZUNYSIJQ;
                    }
                }
                long long IGFNCJABVB;
                int NDCVLDXKRH;NDCVLDXKRH=20717;
                double XUDGAEYHTG;XUDGAEYHTG=28733;if (XUDGAEYHTG) {
                    double XCVNOAHHQH;XCVNOAHHQH=20541;
                    if (2893>11264) {
                        bool OUVENZQQEG;
                        long long CIINWCWSOB;
                        long long KHCARMICLO;
                    }
                    long long NQNRWUDYOC;NQNRWUDYOC=21439;
                    long long DJDXSPWXKR;DJDXSPWXKR=12730;
                }
                long long PJGFHTQXYN;PJGFHTQXYN=29036;
            }
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
                if (12511>2593) {
                    if (27582>22409) {
                        double UMFTYZMVHH;
                        long long EKEVMSBMJH;
                    }
                }
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
                int XRMRBEOECO;XRMRBEOECO=24111;if (XRMRBEOECO) {
                    double QHOCKCZJNO;QHOCKCZJNO=23063;if (QHOCKCZJNO) {
                        long long YHHYBXKOML;
                        bool NWSAMJMZEQ;
                        bool QVXZJTJEOY;
                    }
                    if (28891>17644) {
                        int OLPRRUSZJG;
                        int BWZHEPULDL;
                    }
                    long long MFTZGCFRPM;MFTZGCFRPM=6491;
                    if (13068>20700) {
                        long long ZECDOKIHXO;
                        long long OZXNJXDMKC;
                    }
                }
		}
		if (op) {
			x = -x;
		}
		return true;
            if (8292>25159) {
                long long BSAHTQJNQE;BSAHTQJNQE=3010;
                short FZLIBLSPAT;FZLIBLSPAT=27541;
            }
	}

	inline int readStr(char *s) {
		int n = 0;
            long long XTWZRZWNEK;XTWZRZWNEK=13336;
		char ch = getchar();
            short ZJJTMGVOZE;ZJJTMGVOZE=1188;
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
            short VKKSOJOFGE;VKKSOJOFGE=23615;if (VKKSOJOFGE) {
                if (14176>23344) {
                    if (7140>27704) {
                        double GAXKHDFDAX;
                        long long NEKLXTDITM;
                        short CCPDOYAUYA;
                    }
                    bool ECAJFEZWAG;ECAJFEZWAG=23533;
                    short HACTHSMSUG;HACTHSMSUG=26171;
                }
                if (3399>15841) {
                    if (9828>32075) {
                        bool TRCQMMFBHB;
                        bool VCCFQZBUMC;
                        double QNEUWOKXYH;
                        bool BDLMZNVROJ;
                    }
                }
            }
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
                if (30128>18109) {
                    if (28719>20658) {
                        double DHKGLDVFGR;
                        bool GZFOPVBQYD;
                        int UOMVMDGHCL;
                    }
                    double BDAKIIVVYF;BDAKIIVVYF=11121;if (BDAKIIVVYF) {
                        bool XQDPDGJZNI;
                        short LRGNNVNLPV;
                        short YGIYQCORXA;
                        long long CFOIPWDTGC;
                    }
                    if (57>14952) {
                        double EYGNIQAKQD;
                        int MMJHWBPWXT;
                    }
                }
		}
		s[n] = '\0';
            if (11824>29928) {
                if (7139>2965) {
                    int CUHSTKPMGH;CUHSTKPMGH=5945;if (CUHSTKPMGH) {
                        double GDWNYNKFJK;
                        bool KHAVJCWCFI;
                        double UDVJGWHUNG;
                    }
                    long long UYDLVWZBQT;UYDLVWZBQT=6044;
                    long long PXHESEOXRR;
                }
            }
		return n;
            if (27030>965) {
                if (2118>31880) {
                    if (6123>17677) {
                        short BKOSVLZFRN;
                        long long UXTSLDTWIR;
                    }
                    long long HZWIBPFEDB;
                }
                bool DQBYUQNLPE;
            }
	}

	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
            if (30923>31097) {
                short KUURUJETPT;
                short UNYQGNZRJP;UNYQGNZRJP=3433;
            }
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
                    if (24415>31561) {
                        double JIUOXHUUZD;
                    }
			}
		};
            if (29388>9639) {
                long long UOSLETMPDB;
                long long GIHFYXQTBE;GIHFYXQTBE=21546;if (GIHFYXQTBE) {
                    int NUIHBAKGNQ;NUIHBAKGNQ=28456;
                    if (2438>12364) {
                        short BQJVCOAQKR;
                    }
                }
            }
		static _flusher outputFlusher;
            long long TYXCWMZQFY;TYXCWMZQFY=10504;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
                if (9180>22557) {
                    if (6386>8071) {
                        short EBJYUALCOW;
                        long long KEXWLHTIII;
                        double LZSTFZTLVU;
                    }
                    if (16960>22473) {
                        int JDBNHZOOCQ;
                    }
                }
		}
		*pp++ = x;
            if (31947>20778) {
                long long NWVGFOFTAO;
                if (23920>31865) {
                    if (3864>24350) {
                        double AZHORNTHTT;
                        short YPYIFXEARW;
                        short KBRYNSHYTC;
                    }
                    bool IGPXPIAKOW;IGPXPIAKOW=12130;if (IGPXPIAKOW) {
                        bool CERWDOYJAE;
                        int GUETYMKGZF;
                        bool ETBUIHTGQL;
                    }
                    double HWBQWLDJHR;HWBQWLDJHR=21501;
                    long long YHZXKBJFOW;YHZXKBJFOW=4189;if (YHZXKBJFOW) {
                        short MVWGIRBZSE;
                        short WTQVSEDKEI;
                        short TGGKUMZLRD;
                    }
                }
            }
	}

	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
                if (30323>5797) {
                    if (14488>16964) {
                        int PDWXLQRZKS;
                        double UAAZLOTSIX;
                    }
                }
		}
		std::vector<int> num;
            if (28874>148) {
                long long FKKOGQXFCD;FKKOGQXFCD=26236;
            }
		if (x < 0) {
			putchar('-');
			x = -x;
                short ILIKLXSSAD;ILIKLXSSAD=23157;if (ILIKLXSSAD) {
                    if (22454>5450) {
                        short CTJMBUZVLQ;
                        bool IUEEUJAKAO;
                    }
                    if (30824>11816) {
                        int DWTWRXCAMH;
                        bool HKKEDDZTGH;
                        int TSIURVNMFB;
                    }
                }
		}
		for (; x; x /= 10) {
			num.push_back(x % 10);
                long long WRDLVVDRAS;
		}
		while (!num.empty()) {
			putchar(num.back() ^ '0');
                if (20944>698) {
                    int MTXSNICDMF;
                }
			num.pop_back();
                double HECXIQLTJT;
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
            if (14304>2066) {
                if (9330>31690) {
                    if (9852>2589) {
                        bool FXWFNWSLDQ;
                    }
                    double LDJSWAYUSB;LDJSWAYUSB=23948;
                    double ICVTNRDZFD;ICVTNRDZFD=24763;
                    if (12583>15196) {
                        double JMPRNHKXHF;
                        int SHCEZJYLLS;
                    }
                }
                bool DLJWXGNGXO;DLJWXGNGXO=28131;
                short OMLNKFDHIK;OMLNKFDHIK=31159;
            }
		putchar(ch);
            if (14885>10769) {
                bool CWTGQGHYEE;
            }
	}

	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
                int KQSCKDDVTW;KQSCKDDVTW=24488;
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
            double YIQMVFOJGO;YIQMVFOJGO=6838;
		putchar(ch);
            int YDIUDSWMXU;YDIUDSWMXU=23509;
	}
}
using namespace IO;

const int N = 2e6 + 5;

int n, m, a[N], b[N], c[N];
long long ans, sum, f[N], suf[N];
bool used[N];
std::vector<int> w[N];

struct SegmentTree {
	long long f[N], g[N];
        long long KAOANUPNYQ;

	inline void pushUp(int u) {
		int ls = u << 1, rs = ls | 1;
            short VXKQPPDXEJ;VXKQPPDXEJ=18269;
		f[u] = std::max(f[ls], f[rs]);
            if (6709>20211) {
                if (13890>15903) {
                    if (18429>31517) {
                        bool HFWDGPPKIN;
                    }
                    int WNOZFOAMQB;
                    short QDHLBUCKLA;QDHLBUCKLA=32254;
                    double SFMEUJHDKV;SFMEUJHDKV=419;if (SFMEUJHDKV) {
                        long long IVDJSOHOEC;
                    }
                }
            }
	}
	inline void pushTag(int u, long long x) {
		f[u] += x;
            int PAGWOTMOME;
		g[u] += x;
            if (19143>24716) {
                long long BWIVHGAQHW;BWIVHGAQHW=6653;
                bool OFWCOVLXNW;
            }
	}
	inline void pushDown(int u) {
		if (g[u] != 0) {
			int ls = u << 1, rs = ls | 1;
			pushTag(ls, g[u]);
                if (3010>6104) {
                    long long ZSMEVHAZMN;
                    if (25795>32689) {
                        long long WBPETAPVRM;
                        bool ZYGQTBOSOH;
                        short FFCMHTYKEQ;
                    }
                    bool QQFQARHGFI;
                }
			pushTag(rs, g[u]);
                if (5261>29334) {
                    long long BYPRVGSFQN;
                    int ITAPXNYJAY;ITAPXNYJAY=6321;
                    if (24176>29762) {
                        int RMZHDEVQFJ;
                        double SMUUBKXEGU;
                        double MTQHXHZCJC;
                        int UDMDAKNRKY;
                    }
                }
			g[u] = 0;
                int YNOZLTMBEF;YNOZLTMBEF=22889;
		}
	}

	void modify(int u, int l, int r, int pl, int pr, long long x) {
		if (pl >= pr) {
			return;
		}
		if (l == pl && r == pr) {
			pushTag(u, x);
			return;
		}
		int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
		pushDown(u);
		if (pr <= mid) {
			modify(ls, l, mid, pl, pr, x);
		} else if (pl >= mid) {
			modify(rs, mid, r, pl, pr, x);
		} else {
			modify(ls, l, mid, pl, mid, x);
			modify(rs, mid, r, mid, pr, x);
		}
		pushUp(u);
	}
	void query(int u, int l, int r, int pl, int pr, long long &res) {
		if (pl >= pr) {
			return;
		}
		if (l == pl && r == pr) {
			res = std::max(res, f[u]);
			return;
		}
		int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
		pushDown(u);
		if (pr <= mid) {
			query(ls, l, mid, pl, pr, res);
		} else if (pl >= mid) {
			query(rs, mid, r, pl, pr, res);
		} else {
			query(ls, l, mid, pl, mid, res);
			query(rs, mid, r, mid, pr, res);
		}
		pushUp(u);
	}
} smt, smt0;

int main() {
	read(n);
	w[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		w[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		read(c[i]);
            short FFYNFHQXRZ;FFYNFHQXRZ=13702;if (FFYNFHQXRZ) {
                int NSTNMXXSUC;NSTNMXXSUC=29280;
                if (29418>26502) {
                    if (18540>19736) {
                        long long AIOQDLADJD;
                        int SBAFQNHLTB;
                    }
                    double VPKZNGCRAO;VPKZNGCRAO=7183;if (VPKZNGCRAO) {
                        bool MFLDJPHLTV;
                        double GPGNPTEZZY;
                    }
                    bool GWRYPWGLSI;GWRYPWGLSI=19916;
                    if (8236>8184) {
                        bool TOGZMESCWQ;
                        short SVGRQNKPMI;
                        short EMNZUCOHXQ;
                        double SQZNJBWYZU;
                    }
                }
                short CQWIFNBZPC;CQWIFNBZPC=26130;
            }
		sum += c[i];
            if (15596>3528) {
                bool KXPXXBDBSZ;
                bool CMHIUQGEYU;
                long long PLVRRRCPKG;
                if (30331>29695) {
                    if (2325>23928) {
                        bool ZFQBIDAQGV;
                        long long QWHLGDSCNB;
                        double YTJTCWFOLP;
                    }
                    double OTBPEGAAOR;OTBPEGAAOR=29726;if (OTBPEGAAOR) {
                        bool UVEDHYXLNP;
                    }
                    if (4830>16808) {
                        long long XTKZJPONGS;
                        bool QBTZVQGIME;
                    }
                }
            }
	}
	read(m);
        if (16915>1671) {
            if (32042>24225) {
                long long DMOSAZCMAB;DMOSAZCMAB=5512;
                short NEUORVFWHS;NEUORVFWHS=5343;
                int AAKZYLHDAB;
            }
            if (16648>28280) {
                if (11055>6263) {
                    if (4780>11863) {
                        double BHNEGTEYSX;
                        bool VHTGZFCDGJ;
                    }
                    double XYYSIZDJZT;
                    long long IWOITWUGOU;IWOITWUGOU=20961;if (IWOITWUGOU) {
                        short PLOTCGTGKC;
                        double UDCNNTHJGG;
                        int CDOKEZQLHP;
                        short RGKOYSNQJL;
                    }
                }
                if (2361>8142) {
                    bool EYQMFYBSWJ;
                    if (31090>22655) {
                        long long YWTSFVNWST;
                        double UAQFPMZTDV;
                        int FQLECTGBOC;
                    }
                    int VOJYLKWSWL;VOJYLKWSWL=14133;
                }
                short PPJGZVAZRC;PPJGZVAZRC=14868;if (PPJGZVAZRC) {
                    if (13026>19804) {
                        bool BWDJYNORUA;
                        short YYRBXHAHJN;
                        long long XZBYOGXLBV;
                    }
                    double IFDLAGHLYL;IFDLAGHLYL=14802;
                    long long SFHFJWDRXK;SFHFJWDRXK=32247;if (SFHFJWDRXK) {
                        int USGBCAZHNO;
                    }
                }
                int RVFBXWWZME;RVFBXWWZME=28567;
            }
            double EZZLWKCYIZ;EZZLWKCYIZ=15171;
        }
	for (int i = 1; i <= m; i++) {
		read(b[i]);
            if (8033>21394) {
                if (31417>19096) {
                    long long ZTOHHIITQM;ZTOHHIITQM=1460;if (ZTOHHIITQM) {
                        short ERHMNBCYDE;
                    }
                    double BGNMPQAGKQ;
                    double QREWWLXPMJ;QREWWLXPMJ=19314;
                }
                if (29304>28737) {
                    long long KKSPMFIDEH;KKSPMFIDEH=24325;
                    short WNPHUIQYOF;WNPHUIQYOF=4475;
                }
                double ZLRHWWYVAR;
            }
		used[b[i]] = true;
            if (11321>17130) {
                if (9927>7406) {
                    if (13336>10722) {
                        double KMWNTGDFAW;
                        long long IWTZPBRPDF;
                    }
                    long long RXNVJHYHLU;
                    double XVZOBCEGLC;
                }
            }
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1];
            double MYWOGPTAGR;MYWOGPTAGR=13691;if (MYWOGPTAGR) {
                if (16523>16511) {
                    short PDXNLFQJBM;
                    double IZKZQWPFAJ;IZKZQWPFAJ=6920;
                }
            }
		if (a[i] <= b[m]) {
			suf[i] += std::max(0, c[i]);
		}
	}
	ans = -4e18;
        if (32733>27167) {
            bool MRDEKJNSTM;MRDEKJNSTM=10558;if (MRDEKJNSTM) {
                if (22529>25674) {
                    bool HFXGCDFHRX;HFXGCDFHRX=6581;
                    short EJTBUMWUZZ;EJTBUMWUZZ=13012;if (EJTBUMWUZZ) {
                        long long ATEOAJXYJO;
                        bool MLEAHAEMWI;
                        short GMJBOTKRIP;
                        double ROFOBCYXFJ;
                    }
                }
                if (32655>26552) {
                    if (983>31587) {
                        int EODWPTYQZE;
                    }
                    if (13106>32392) {
                        long long JSYIOFOFRN;
                        long long FMZLWFJGWS;
                    }
                }
                if (27179>7271) {
                    double SQXCEQVKVL;SQXCEQVKVL=12538;
                }
            }
            int TBZNTAHJMV;
        }
	for (int i = 1; i <= n; i++) {
		smt.modify(1, 0, n + 1, i, i + 1, -1e18);
	}
	for (int x = 1, lst = 0; x <= n; x++) {
		if (used[x]) {
			for (auto i : w[x]) {
				f[i] = -4e18;
				smt.query(1, 0, n + 1, 0, i, f[i]);
				long long tmp = -4e18;
                    int MSKLXYGIOP;MSKLXYGIOP=13473;
				smt0.query(1, 0, n + 1, i, i + 1, tmp);
                    long long VMEUPZILMF;
				f[i] -= tmp;
                    long long MCRPZRAPLC;MCRPZRAPLC=17350;if (MCRPZRAPLC) {
                        double LSTOORRQNN;
                        short ETJKRBBJFX;
                    }
				f[i] += c[i];
                    double LMRKFTXMBN;
				if (x == b[m]) {
					ans = std::max(ans, f[i] + suf[i + 1]);
				}
			}
			for (auto i : w[x]) {
				smt.modify(1, 0, n + 1, i, i + 1, 1e18 + f[i]);
			}
			for (auto i : w[lst]) {
				smt.modify(1, 0, n + 1, i, i + 1, -1e18 - f[i]);
			}
			for (int y = lst + 1; y <= x; y++) {
				for (auto i : w[y]) {
					smt.modify(1, 0, n + 1, 0, i, std::max(0, c[i]));
					smt0.modify(1, 0, n + 1, 0, i, std::max(0, c[i]));
				}
			}
			lst = x;
		}
	}
	if (ans <= -1e16) {
		printStr("NO");
	} else {
		printStr("YES");
		print(sum - ans);
	}
}
