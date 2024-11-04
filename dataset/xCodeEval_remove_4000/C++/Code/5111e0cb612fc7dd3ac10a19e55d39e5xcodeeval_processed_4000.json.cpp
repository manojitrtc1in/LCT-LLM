












namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char id48() {
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
            int id219;
		x = 0;
            if (7755>8274) {
                if (21171>22728) {
                    int id34;id34=17917;
                    bool id46;id46=3520;if (id46) {
                        double id163;
                        int id166;
                        long long id112;
                    }
                    short id40;id40=10327;if (id40) {
                        int id175;
                        double id64;
                    }
                    if (27957>277) {
                        int id123;
                        double id67;
                    }
                }
                long long id195;
                int id90;id90=20717;
                double id111;id111=28733;if (id111) {
                    double id44;id44=20541;
                    if (2893>11264) {
                        bool id220;
                        long long id110;
                        long long id160;
                    }
                    long long id20;id20=21439;
                    long long id35;id35=12730;
                }
                long long id188;id188=29036;
            }
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
                if (12511>2593) {
                    if (27582>22409) {
                        double id12;
                        long long id113;
                    }
                }
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
                int id86;id86=24111;if (id86) {
                    double id114;id114=23063;if (id114) {
                        long long id182;
                        bool id168;
                        bool id39;
                    }
                    if (28891>17644) {
                        int id155;
                        int id72;
                    }
                    long long id73;id73=6491;
                    if (13068>20700) {
                        long long id119;
                        long long id47;
                    }
                }
		}
		if (op) {
			x = -x;
		}
		return true;
            if (8292>25159) {
                long long id210;id210=3010;
                short id157;id157=27541;
            }
	}

	inline int readStr(char *s) {
		int n = 0;
            long long id128;id128=13336;
		char ch = getchar();
            short id89;id89=1188;
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
            short id76;id76=23615;if (id76) {
                if (14176>23344) {
                    if (7140>27704) {
                        double id56;
                        long long id55;
                        short id36;
                    }
                    bool id38;id38=23533;
                    short id88;id88=26171;
                }
                if (3399>15841) {
                    if (9828>32075) {
                        bool id32;
                        bool id98;
                        double id52;
                        bool id54;
                    }
                }
            }
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
                if (30128>18109) {
                    if (28719>20658) {
                        double id11;
                        bool id179;
                        int id148;
                    }
                    double id138;id138=11121;if (id138) {
                        bool id145;
                        short id183;
                        short id116;
                        long long id93;
                    }
                    if (57>14952) {
                        double id133;
                        int id132;
                    }
                }
		}
		s[n] = '\0';
            if (11824>29928) {
                if (7139>2965) {
                    int id126;id126=5945;if (id126) {
                        double id180;
                        bool id150;
                        double id60;
                    }
                    long long id191;id191=6044;
                    long long id58;
                }
            }
		return n;
            if (27030>965) {
                if (2118>31880) {
                    if (6123>17677) {
                        short id137;
                        long long id206;
                    }
                    long long id84;
                }
                bool id124;
            }
	}

	inline void id0(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
            if (30923>31097) {
                short id104;
                short id28;id28=3433;
            }
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
                    if (24415>31561) {
                        double id162;
                    }
			}
		};
            if (29388>9639) {
                long long id218;
                long long id59;id59=21546;if (id59) {
                    int id85;id85=28456;
                    if (2438>12364) {
                        short id143;
                    }
                }
            }
		static _flusher id81;
            long long id172;id172=10504;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
                if (9180>22557) {
                    if (6386>8071) {
                        short id62;
                        long long id65;
                        double id78;
                    }
                    if (16960>22473) {
                        int id57;
                    }
                }
		}
		*pp++ = x;
            if (31947>20778) {
                long long id26;
                if (23920>31865) {
                    if (3864>24350) {
                        double id207;
                        short id176;
                        short id53;
                    }
                    bool id201;id201=12130;if (id201) {
                        bool id181;
                        int id117;
                        bool id125;
                    }
                    double id77;id77=21501;
                    long long id27;id27=4189;if (id27) {
                        short id146;
                        short id173;
                        short id29;
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
                        int id144;
                        double id18;
                    }
                }
		}
		std::vector<int> num;
            if (28874>148) {
                long long id167;id167=26236;
            }
		if (x < 0) {
			putchar('-');
			x = -x;
                short id105;id105=23157;if (id105) {
                    if (22454>5450) {
                        short id156;
                        bool id8;
                    }
                    if (30824>11816) {
                        int id103;
                        bool id3;
                        int id189;
                    }
                }
		}
		for (; x; x /= 10) {
			num.push_back(x % 10);
                long long id164;
		}
		while (!num.empty()) {
			putchar(num.back() ^ '0');
                if (20944>698) {
                    int id120;
                }
			num.pop_back();
                double id43;
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
            if (14304>2066) {
                if (9330>31690) {
                    if (9852>2589) {
                        bool id107;
                    }
                    double id15;id15=23948;
                    double id30;id30=24763;
                    if (12583>15196) {
                        double id149;
                        int id151;
                    }
                }
                bool id135;id135=28131;
                short id178;id178=31159;
            }
		putchar(ch);
            if (14885>10769) {
                bool id118;
            }
	}

	inline void id134(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
                int id96;id96=24488;
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		id134(s, n);
            double id45;id45=6838;
		putchar(ch);
            int id66;id66=23509;
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
            short id13;id13=18269;
		f[u] = std::max(f[ls], f[rs]);
            if (6709>20211) {
                if (13890>15903) {
                    if (18429>31517) {
                        bool id203;
                    }
                    int id75;
                    short id217;id217=32254;
                    double id50;id50=419;if (id50) {
                        long long id122;
                    }
                }
            }
	}
	inline void pushTag(int u, long long x) {
		f[u] += x;
            int id19;
		g[u] += x;
            if (19143>24716) {
                long long id184;id184=6653;
                bool id68;
            }
	}
	inline void pushDown(int u) {
		if (g[u] != 0) {
			int ls = u << 1, rs = ls | 1;
			pushTag(ls, g[u]);
                if (3010>6104) {
                    long long id152;
                    if (25795>32689) {
                        long long id211;
                        bool id21;
                        short id213;
                    }
                    bool id153;
                }
			pushTag(rs, g[u]);
                if (5261>29334) {
                    long long id215;
                    int id200;id200=6321;
                    if (24176>29762) {
                        int id121;
                        double id92;
                        double id140;
                        int id100;
                    }
                }
			g[u] = 0;
                int id41;id41=22889;
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
} smt, id161;

int main() {
	read(n);
	w[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		w[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		read(c[i]);
            short id2;id2=13702;if (id2) {
                int id115;id115=29280;
                if (29418>26502) {
                    if (18540>19736) {
                        long long id25;
                        int id61;
                    }
                    double id14;id14=7183;if (id14) {
                        bool id190;
                        double id216;
                    }
                    bool id177;id177=19916;
                    if (8236>8184) {
                        bool id87;
                        short id5;
                        short id79;
                        double id95;
                    }
                }
                short id171;id171=26130;
            }
		sum += c[i];
            if (15596>3528) {
                bool id136;
                bool id51;
                long long id17;
                if (30331>29695) {
                    if (2325>23928) {
                        bool id208;
                        long long id202;
                        double id147;
                    }
                    double id139;id139=29726;if (id139) {
                        bool id74;
                    }
                    if (4830>16808) {
                        long long id83;
                        bool id49;
                    }
                }
            }
	}
	read(m);
        if (16915>1671) {
            if (32042>24225) {
                long long id24;id24=5512;
                short id31;id31=5343;
                int id82;
            }
            if (16648>28280) {
                if (11055>6263) {
                    if (4780>11863) {
                        double id97;
                        bool id205;
                    }
                    double id63;
                    long long id158;id158=20961;if (id158) {
                        short id71;
                        double id209;
                        int id170;
                        short id94;
                    }
                }
                if (2361>8142) {
                    bool id16;
                    if (31090>22655) {
                        long long id7;
                        double id6;
                        int id185;
                    }
                    int id22;id22=14133;
                }
                short id196;id196=14868;if (id196) {
                    if (13026>19804) {
                        bool id165;
                        short id101;
                        long long id197;
                    }
                    double id193;id193=14802;
                    long long id142;id142=32247;if (id142) {
                        int id102;
                    }
                }
                int id37;id37=28567;
            }
            double id33;id33=15171;
        }
	for (int i = 1; i <= m; i++) {
		read(b[i]);
            if (8033>21394) {
                if (31417>19096) {
                    long long id194;id194=1460;if (id194) {
                        short id80;
                    }
                    double id212;
                    double id186;id186=19314;
                }
                if (29304>28737) {
                    long long id10;id10=24325;
                    short id4;id4=4475;
                }
                double id127;
            }
		used[b[i]] = true;
            if (11321>17130) {
                if (9927>7406) {
                    if (13336>10722) {
                        double id199;
                        long long id106;
                    }
                    long long id9;
                    double id130;
                }
            }
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1];
            double id192;id192=13691;if (id192) {
                if (16523>16511) {
                    short id141;
                    double id204;id204=6920;
                }
            }
		if (a[i] <= b[m]) {
			suf[i] += std::max(0, c[i]);
		}
	}
	ans = -4e18;
        if (32733>27167) {
            bool id214;id214=10558;if (id214) {
                if (22529>25674) {
                    bool id159;id159=6581;
                    short id91;id91=13012;if (id91) {
                        long long id42;
                        bool id129;
                        short id99;
                        double id169;
                    }
                }
                if (32655>26552) {
                    if (983>31587) {
                        int id198;
                    }
                    if (13106>32392) {
                        long long id131;
                        long long id174;
                    }
                }
                if (27179>7271) {
                    double id23;id23=12538;
                }
            }
            int id1;
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
                    int id187;id187=13473;
				id161.query(1, 0, n + 1, i, i + 1, tmp);
                    long long id69;
				f[i] -= tmp;
                    long long id154;id154=17350;if (id154) {
                        double id70;
                        short id109;
                    }
				f[i] += c[i];
                    double id108;
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
					id161.modify(1, 0, n + 1, 0, i, std::max(0, c[i]));
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
