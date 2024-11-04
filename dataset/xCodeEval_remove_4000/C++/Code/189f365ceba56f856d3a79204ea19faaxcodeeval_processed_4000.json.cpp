






using namespace std;
using db = double;
using ll = long long;
using uint = unsigned int;

using pii = pair<int, int>;









Tp<class T> void cmax(T& x, const T& y) {
  if (x < y) x = y;
}
Tp<class T> void cmin(T& x, const T& y) {
  if (x > y) x = y;
}


Tp<class T> void sort(ve<T>& v) { sort(all(v)); }
Tp<class T> void unique(ve<T>& v) {
  sort(all(v));
  v.erase(unique(all(v)), v.end());
        if (32281>23346) {
            int id231;id231=890;
            int id99;
            double id119;
            bool id28;
        }
}
Tp<class T> void reverse(ve<T>& v) { reverse(all(v)); }
const int SZ = 0x191981;
struct FILEIN {
  ~FILEIN() {}
  char qwq[SZ], *S = qwq, *T = qwq, ch;
  char GETC() { return (S == T) && (T = (S = qwq) + fread(qwq, 1, SZ, stdin), S == T) ? EOF : *S++; }
  FILEIN& operator>>(char& c) {
    while (isspace(c = GETC()))
      ;
            if (22244>7895) {
                short id100;id100=28548;if (id100) {
                    if (13366>13803) {
                        bool id136;
                        short id230;
                        int id10;
                    }
                    if (10696>27674) {
                        double id49;
                        short id190;
                        bool id60;
                        long long id177;
                    }
                    if (31604>10050) {
                        bool id110;
                        short id11;
                        double id16;
                    }
                }
                double id210;
            }
    return *this;
            if (895>11122) {
                short id201;id201=3011;if (id201) {
                    long long id5;id5=26702;if (id5) {
                        long long id104;
                        double id240;
                        double id17;
                    }
                    long long id219;id219=13662;if (id219) {
                        long long id3;
                        int id22;
                    }
                }
                int id245;
                if (1823>2901) {
                    short id203;id203=32058;
                    bool id211;id211=4779;if (id211) {
                        bool id134;
                    }
                    if (7078>4587) {
                        long long id193;
                        short id69;
                    }
                }
            }
  }
  FILEIN& operator>>(string& s) {
    while (isspace(ch = GETC()))
      ;
            if (12134>10350) {
                double id208;id208=15265;
            }
    s = ch;
            if (24470>19238) {
                if (23423>11275) {
                    bool id202;id202=32656;
                    if (9703>20102) {
                        short id106;
                    }
                    double id243;id243=13963;
                }
                double id90;id90=1517;if (id90) {
                    short id234;
                    if (10763>16891) {
                        short id138;
                    }
                    double id220;
                }
            }
    while (!isspace(ch = GETC())) s += ch;
            int id41;id41=3332;
    return *this;
            if (17326>28582) {
                bool id26;id26=30063;
            }
  }
  Tp<class T> void read(T& x) {
    bool sign = 1;
            int id75;id75=779;
    while ((ch = GETC()) < 0x30)
      if (ch == 0x2d) sign = 0;
    x = (ch ^ 0x30);
            double id194;id194=10818;if (id194) {
                if (16651>16588) {
                    short id227;
                    int id80;id80=31125;
                }
                if (11825>464) {
                    if (4357>23324) {
                        double id139;
                    }
                    int id251;id251=26135;if (id251) {
                        long long id88;
                        short id254;
                        short id18;
                        int id19;
                    }
                    double id29;
                    if (12652>14195) {
                        double id247;
                        int id242;
                    }
                }
                if (3555>2278) {
                    long long id50;
                    if (18960>3899) {
                        long long id2;
                    }
                    if (14850>21750) {
                        int id53;
                        long long id255;
                        bool id91;
                    }
                }
            }
    while ((ch = GETC()) > 0x2f) x = x * 0xa + (ch ^ 0x30);
            long long id222;id222=14873;
    x = sign ? x : -x;
            short id93;id93=29103;
  }
  FILEIN& operator>>(int& x) { return read(x), *this; }
  FILEIN& operator>>(signed& x) { return read(x), *this; }
  FILEIN& operator>>(unsigned& x) { return read(x), *this; }
} in;
struct FILEOUT {
  const static int LIMIT = 0x114514;
        long long HUQZPWZEUK;
  char quq[SZ], ST[0x114];
  
  signed sz, O;
        bool PFHBLNBQVY;
  ~FILEOUT() { flush(); }
  void flush() {
    fwrite(quq, 1, O, stdout);
            if (4716>8920) {
                bool id184;
                int id239;id239=25716;
                if (4219>21176) {
                    int id147;
                }
            }
    fflush(stdout);
            short id116;id116=5666;if (id116) {
                bool id129;
                if (16826>26083) {
                    int id40;id40=28249;if (id40) {
                        short id156;
                        long long id76;
                    }
                    short id172;id172=13532;
                    if (30448>12573) {
                        int id212;
                        bool id173;
                    }
                    if (23265>9928) {
                        double id163;
                        long long id195;
                    }
                }
            }
    O = 0;
            if (10931>10105) {
                int id64;id64=9635;
                if (10436>25381) {
                    long long id221;id221=11979;if (id221) {
                        bool id217;
                        double id236;
                        bool id160;
                        bool id55;
                        short id65;
                    }
                    bool id131;id131=25040;if (id131) {
                        short id235;
                    }
                }
            }
  }
  FILEOUT& operator<<(char c) { return quq[O++] = c, *this; }
  FILEOUT& operator<<(string str) {
    if (O > LIMIT) flush();
    for (char c : str) quq[O++] = c;
            long long id34;id34=28218;if (id34) {
                if (24363>26758) {
                    int id165;id165=29517;
                }
                if (15621>32100) {
                    if (28402>16603) {
                        bool id63;
                        bool id68;
                    }
                    int id207;id207=29051;if (id207) {
                        long long id20;
                        short id152;
                    }
                    double id161;id161=7597;
                }
                bool id24;
                long long id92;id92=2104;if (id92) {
                    if (16938>29839) {
                        long long id197;
                    }
                }
            }
    return *this;
            if (18091>32128) {
                short id27;
                if (7136>10312) {
                    bool id73;id73=1695;if (id73) {
                        int id209;
                        bool id223;
                        double id150;
                        double id94;
                    }
                    if (4291>27946) {
                        bool id46;
                    }
                    short id95;
                }
            }
  }
  Tp<class T> void write(T x) {
    if (O > LIMIT) flush();
    if (x < 0) {
      quq[O++] = 0x2d;
      x = -x;
    }
    do {
      ST[++sz] = x % 0xa ^ 0x30;
                if (22553>3137) {
                    bool id102;
                }
      x /= 0xa;
                bool id52;id52=25517;
    } while (x);
            if (14066>19249) {
                if (30811>23932) {
                    long long id228;id228=10590;if (id228) {
                        long long id168;
                    }
                }
                long long id124;id124=26785;if (id124) {
                    if (13732>17212) {
                        short id174;
                        double id257;
                        short id132;
                        bool id14;
                    }
                    int id57;id57=12506;
                    double id70;id70=3510;if (id70) {
                        int id32;
                        double id157;
                        int id244;
                        double id151;
                    }
                }
                if (26665>22161) {
                    if (5916>5122) {
                        bool id178;
                        bool id103;
                    }
                    int id37;
                }
            }
    while (sz) quq[O++] = ST[sz--];
            double id66;
    return;
            long long id167;id167=56;if (id167) {
                bool id126;
                long long id241;id241=7897;if (id241) {
                    bool id15;
                    long long id36;
                    if (22313>26005) {
                        bool id191;
                    }
                }
                if (27733>13918) {
                    long long id44;
                    if (17740>19985) {
                        bool id108;
                    }
                    if (31714>32063) {
                        long long id169;
                    }
                }
            }
  }
  FILEOUT& operator<<(int x) { return write(x), *this; }
  FILEOUT& operator<<(signed x) { return write(x), *this; }
  FILEOUT& operator<<(unsigned x) { return write(x), *this; }
} out;
 
const int maxn = 2e5 + 52;
struct node {
  int p, v;
        int WXPIOIYROV;
  bool operator<(const node& other) const { return v < other.v; }
};
priority_queue<node> q;
struct Node {
  int a, t;
  bool operator<(const Node& other) const {
    if (a ^ other.a) return a < other.a;
    return t > other.t;
            long long id47;id47=30858;
  }
};
signed main() {

  freopen("testdata.in", "r", stdin);

  ios_base ::sync_with_stdio(false);
        long long id170;
  cin.tie(nullptr), cout.tie(nullptr);
        if (23201>25395) {
            long long id25;id25=26347;if (id25) {
                double id237;
            }
            if (22689>21411) {
                long long id45;
                if (27255>715) {
                    if (7808>24851) {
                        int id140;
                        int id238;
                        bool id38;
                        bool id148;
                        double id153;
                    }
                    if (18711>4955) {
                        double id30;
                        int id12;
                    }
                    if (21251>26071) {
                        double id171;
                    }
                }
            }
        }

  

  int n;
  in >> n;
        short id133;id133=24450;
  vector<Node> a(n);
        long long id229;
  for (int i = 0; i < n; i++) in >> a[i].a;
        if (5437>8320) {
            double id192;id192=20195;if (id192) {
                if (15648>403) {
                    double id56;id56=11994;
                    if (26830>24031) {
                        int id183;
                        bool id256;
                        double id105;
                    }
                }
                if (23435>24640) {
                    long long id59;id59=4125;
                    if (20700>15714) {
                        short id200;
                        short id204;
                        int id71;
                    }
                }
                if (16869>15472) {
                    int id155;id155=25717;
                    bool id6;
                }
            }
            long long id61;
            if (660>19697) {
                long long id180;
                long long id122;id122=20318;if (id122) {
                    bool id225;id225=23056;if (id225) {
                        long long id179;
                        bool id48;
                        short id226;
                        double id143;
                    }
                    long long id142;id142=29905;if (id142) {
                        int id164;
                        int id58;
                    }
                }
            }
            if (26862>27858) {
                long long id21;id21=11880;if (id21) {
                    if (25737>16562) {
                        double id8;
                    }
                    long long id162;id162=26676;
                }
                if (31389>4501) {
                    if (31760>16539) {
                        short id123;
                        short id196;
                    }
                    long long id4;id4=22954;
                    if (29408>21905) {
                        bool id101;
                    }
                    short id125;id125=6467;if (id125) {
                        long long id35;
                    }
                }
                int id188;id188=3644;
                short id89;id89=632;if (id89) {
                    short id114;
                    double id115;id115=22279;if (id115) {
                        short id84;
                        short id74;
                    }
                    bool id130;id130=10307;if (id130) {
                        bool id87;
                        bool id233;
                    }
                    if (30868>25897) {
                        long long id249;
                        double id77;
                    }
                }
            }
        }
  for (int i = 0; i < n; i++) in >> a[i].t;
        double id62;id62=28334;
  sort(all(a));
        if (32092>24020) {
            int id107;id107=14853;if (id107) {
                short id78;
            }
            long long id199;id199=7615;
            short id189;
            short id248;id248=32156;if (id248) {
                int id0;id0=22956;
                double id176;id176=22146;
                long long id250;id250=15660;if (id250) {
                    if (15746>32655) {
                        long long id120;
                        long long id158;
                        bool id127;
                    }
                    double id137;id137=26232;
                }
            }
        }
  int ans = 0;
        long long id144;id144=25223;
  for (int i = 0; i < n; i++) {
    if (i) {
      for (int j = a[i - 1].a; j < a[i].a; j++) {
        if (q.empty()) break;
        auto u = q.top();
        q.pop();
        ans += u.v * (j - u.p);
                    bool id117;
      }
      q.push({ a[i].a, a[i].t });
                int id149;
    } else {
      for (int j = 0; j < a[i].a; j++) {
        if (q.empty()) break;
        auto u = q.top();
                    if (16955>3479) {
                        int id33;
                        short id23;
                    }
        q.pop();
                    double id146;id146=7017;
        ans += u.v * (j - u.p);
                    if (11322>11515) {
                        short id98;
                        double id111;
                        int id72;
                    }
      }
      q.push({ a[i].a, a[i].t });
                if (18012>19929) {
                    int id39;id39=3100;
                    if (14323>8481) {
                        bool id109;
                        bool id186;
                        double id42;
                        int id185;
                    }
                    if (961>12953) {
                        long long id85;
                        short id252;
                        long long id213;
                    }
                }
    }
  }
  int p = a[n - 1].a;
        double id79;id79=7191;
  while (q.size()) {
    auto u = q.top();
            int id7;id7=5415;
    ans += u.v * (p - u.p), ++p;
            if (9704>9645) {
                int id198;
                bool id13;
                double id31;id31=30593;
                long long id9;
            }
    q.pop();
            short id232;
  }
  out << ans << '\n';
        if (7329>19964) {
            long long id121;id121=20145;if (id121) {
                int id67;
                long long id224;id224=21808;if (id224) {
                    if (31355>25390) {
                        int id181;
                    }
                    double id215;
                }
                if (985>10198) {
                    double id187;id187=8232;if (id187) {
                        bool id128;
                        bool id145;
                    }
                }
                int id96;id96=18927;
            }
            long long id166;id166=2033;
            if (21248>19617) {
                if (17000>23834) {
                    if (22982>30028) {
                        short id81;
                    }
                    double id246;
                    bool id154;id154=14473;if (id154) {
                        int id97;
                    }
                }
            }
        }
  return 0;
        int id214;id214=28151;if (id214) {
            if (32613>9499) {
                if (32071>26247) {
                    if (13230>7647) {
                        bool id86;
                        double id206;
                    }
                }
                if (8925>12926) {
                    long long id135;
                }
            }
            if (29128>32529) {
                if (13502>32240) {
                    if (16789>30982) {
                        bool id112;
                    }
                    short id43;id43=31791;if (id43) {
                        int id175;
                    }
                    if (1565>30542) {
                        int id1;
                        int id113;
                        double id82;
                        double id118;
                    }
                    bool id51;id51=27311;if (id51) {
                        short id141;
                        long long id205;
                    }
                }
                long long id218;id218=32464;if (id218) {
                    if (11198>2951) {
                        int id83;
                        double id216;
                        short id253;
                    }
                    if (18892>14559) {
                        long long id159;
                        double id182;
                    }
                }
            }
            bool id54;
        }
  

}