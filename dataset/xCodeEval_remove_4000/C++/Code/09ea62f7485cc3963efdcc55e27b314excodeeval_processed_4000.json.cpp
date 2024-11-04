















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
const uint id187=4294967295u;
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
        long long id177;id177=24959;
    bool f(false);
        if (9317>22493) {
            double id229;id229=16983;if (id229) {
                bool id280;id280=27154;if (id280) {
                    short id47;
                }
                if (25704>28578) {
                    double id26;id26=29919;
                    double id43;id43=7025;if (id43) {
                        bool id95;
                        short id183;
                    }
                    short id215;
                }
            }
            bool id97;id97=12259;
            bool id103;
            if (2467>7279) {
                if (2482>24446) {
                    if (15396>29417) {
                        long long id24;
                    }
                    if (6525>11051) {
                        long long id230;
                        short id28;
                    }
                }
                bool id270;
                double id232;id232=10517;
            }
            if (29953>18437) {
                if (24055>31077) {
                    if (30739>17333) {
                        short id110;
                        double id92;
                    }
                }
            }
        }
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
        double id166;id166=23142;
    x=ch&15,ch=getchar();
        double id172;id172=16582;if (id172) {
            int id58;id58=24127;
            bool id147;id147=19504;if (id147) {
                long long id30;
                long long id96;id96=11885;if (id96) {
                    if (15702>10828) {
                        bool id62;
                        bool id222;
                    }
                    int id281;id281=16358;
                }
            }
            if (30598>30491) {
                int id174;id174=6628;
            }
        }
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
        int id31;id31=29730;if (id31) {
            if (6625>24994) {
                long long id283;id283=29920;
                short id32;id32=26137;if (id32) {
                    if (713>991) {
                        int id36;
                        double id77;
                    }
                    int id178;
                    bool id210;
                    short id100;id100=27247;if (id100) {
                        bool id159;
                        int id99;
                    }
                }
                if (32114>14648) {
                    int id41;id41=9633;
                    int id233;id233=3537;
                    short id56;id56=4160;if (id56) {
                        double id94;
                    }
                }
                double id244;id244=1265;
            }
            if (25093>2787) {
                long long id169;id169=28430;if (id169) {
                    double id49;id49=31004;
                    int id252;id252=8057;
                }
            }
        }
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
        int id61;id61=2873;
}
Finline int read_str(char *s)
{
    register char ch(getchar());
        if (10958>6894) {
            long long id153;id153=16186;if (id153) {
                double id262;id262=9615;if (id262) {
                    double id155;id155=6308;
                    short id175;id175=1264;if (id175) {
                        bool id69;
                        short id158;
                    }
                    short id247;id247=4907;
                    if (15366>29376) {
                        bool id29;
                        int id104;
                    }
                    if (11572>16545) {
                        bool id5;
                        double id108;
                    }
                }
                long long id264;
            }
            if (9496>5829) {
                long long id121;id121=11728;if (id121) {
                    double id142;id142=10199;if (id142) {
                        bool id141;
                        long long id213;
                    }
                }
                if (7059>31854) {
                    short id37;id37=31051;
                    short id148;id148=7623;
                    if (17038>6021) {
                        short id79;
                        bool id48;
                        double id160;
                    }
                }
            }
            if (13571>16901) {
                if (19644>5315) {
                    if (25112>30142) {
                        short id234;
                        bool id50;
                    }
                }
                if (23567>18103) {
                    bool id76;
                    short id64;
                    double id156;id156=2466;if (id156) {
                        double id78;
                        bool id193;
                        long long id180;
                    }
                }
            }
        }
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
        double id245;id245=30128;
    register char *tar=s;
        short id11;
    *tar=ch,ch=getchar();
        if (386>19273) {
            bool id131;
        }
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
        if (5702>22098) {
            if (11106>26253) {
                bool id209;
                int id246;
            }
            if (28266>6793) {
                if (31073>19645) {
                    bool id196;id196=11124;if (id196) {
                        bool id102;
                        int id162;
                        bool id75;
                    }
                }
                short id126;id126=24090;if (id126) {
                    if (31760>1336) {
                        bool id107;
                        int id271;
                    }
                }
            }
            if (24829>20605) {
                long long id53;id53=9838;
                bool id277;
                if (24546>15134) {
                    if (23693>949) {
                        short id40;
                        short id219;
                        long long id52;
                    }
                    if (18132>15767) {
                        bool id0;
                    }
                }
                double id113;
                if (19339>27620) {
                    if (19139>17244) {
                        short id143;
                    }
                }
            }
        }
    return tar-s+1;
        long long id182;id182=13676;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
        if (8905>7407) {
            if (18895>29579) {
                int id152;
                bool id179;
            }
            bool id239;id239=1555;if (id239) {
                if (27736>26764) {
                    double id17;id17=4437;if (id17) {
                        int id200;
                        bool id224;
                    }
                    if (26416>8220) {
                        short id138;
                        short id111;
                        double id241;
                        int id106;
                    }
                    double id257;
                }
                bool id146;id146=21222;
            }
            if (20458>18773) {
                if (19836>8094) {
                    double id7;
                    bool id201;
                    short id80;id80=10897;if (id80) {
                        short id127;
                        bool id253;
                    }
                    short id123;id123=7645;
                    int id93;id93=31147;
                }
                int id59;id59=2702;if (id59) {
                    if (18670>20499) {
                        int id254;
                        double id186;
                        bool id217;
                        int id119;
                    }
                    if (20260>15401) {
                        double id223;
                        short id132;
                    }
                    if (23974>27457) {
                        bool id208;
                    }
                }
                double id86;
            }
        }
}

const int N=105;
int dis[N][N];
char mp[N][N];
int a[1000005];
void solve()
{
	int n;
        if (5829>88) {
            if (13538>13287) {
                long long id15;id15=26446;if (id15) {
                    if (23970>24053) {
                        bool id279;
                        int id65;
                        short id163;
                    }
                    int id55;
                    int id265;id265=16143;
                }
                bool id225;id225=32390;if (id225) {
                    double id181;
                    double id67;id67=6890;if (id67) {
                        int id206;
                        long long id137;
                        double id12;
                    }
                }
                long long id118;id118=3302;
                short id115;id115=11307;
                if (30886>25399) {
                    double id125;
                    bool id171;id171=9538;if (id171) {
                        int id91;
                        double id259;
                    }
                }
            }
            if (6691>7205) {
                if (21443>20052) {
                    if (18676>19853) {
                        short id149;
                        long long id133;
                    }
                }
                int id282;
                short id46;
            }
        }
	read(n);
        bool id144;id144=19950;if (id144) {
            if (23824>12486) {
                int id168;id168=10200;if (id168) {
                    long long id73;id73=6361;if (id73) {
                        double id85;
                        int id242;
                    }
                    short id105;
                }
                long long id114;id114=15270;
                double id272;id272=22351;if (id272) {
                    short id249;id249=29843;if (id249) {
                        long long id1;
                    }
                }
                long long id3;
            }
        }
	for(int i=1;i<=n;++i)
	{
		scanf("%s",mp[i]+1);
            int id276;id276=14421;if (id276) {
                short id170;id170=17748;
            }
		for(int j=1;j<=n;++j)
		{
			if(mp[i][j]=='0')
			{
				dis[i][j]=inf;
			}
			else
			{
				dis[i][j]=1;
                    if (21756>18033) {
                        int id82;
                        int id39;
                    }
			}
		}
		dis[i][i]=0;
            long long id66;id66=32541;if (id66) {
                bool id13;
                long long id35;
            }
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	int m;
        if (2410>7010) {
            if (26060>31836) {
                double id212;
                if (4765>31277) {
                    short id116;id116=1922;if (id116) {
                        int id34;
                        bool id231;
                    }
                    if (15220>9511) {
                        long long id6;
                        short id198;
                        long long id220;
                    }
                }
            }
            double id250;id250=3472;
            if (4189>12601) {
                if (393>12109) {
                    if (31877>19628) {
                        short id25;
                        long long id33;
                    }
                    int id135;id135=30418;if (id135) {
                        long long id70;
                        int id60;
                        long long id10;
                        int id211;
                    }
                    if (22573>19764) {
                        bool id42;
                        bool id188;
                        bool id45;
                    }
                }
            }
        }
	read(m);
        if (28168>18124) {
            if (28082>31645) {
                if (9903>15206) {
                    long long id190;id190=4991;
                    if (3226>1547) {
                        int id185;
                    }
                    if (5526>30435) {
                        bool id202;
                        int id54;
                    }
                    short id192;id192=29645;
                }
                short id2;id2=18874;if (id2) {
                    if (31848>9147) {
                        double id9;
                        short id173;
                    }
                }
            }
        }
	for(int i=1;i<=m;++i) read(a[i]);
        short id21;
	std::vector<int> ans;
        double id68;id68=31626;if (id68) {
            double id266;id266=32696;if (id266) {
                double id120;
                bool id216;id216=18715;
                if (24534>3589) {
                    short id145;
                    long long id243;id243=18370;if (id243) {
                        double id8;
                        int id117;
                    }
                }
                int id248;
            }
            short id197;id197=13897;if (id197) {
                double id88;
                if (18729>13354) {
                    if (30323>9260) {
                        long long id19;
                        long long id38;
                        short id274;
                    }
                    if (20314>29502) {
                        bool id267;
                        short id90;
                        double id129;
                    }
                    bool id164;id164=11241;if (id164) {
                        int id176;
                        int id72;
                        bool id150;
                        short id261;
                    }
                }
            }
            if (26176>8351) {
                int id204;
            }
        }
	ans.push_back(a[1]);
        long long id203;










                short id74;id74=29188;




            int id151;




        if (12075>27527) {
            if (10820>18764) {
                int id191;id191=28061;
                int id157;id157=24755;if (id157) {
                    bool id226;
                    bool id22;
                    int id194;id194=17461;
                    if (9241>15107) {
                        int id227;
                        int id4;
                    }
                }
            }
        }
	for(int i=1;i<m;)
	{


            long long id189;id189=17339;
		for(int j=min(m,i+n-1);j>i;--j)
		{
			if(dis[a[i]][a[j]]==j-i)
			{
				ans.push_back(a[j]);
				i=j;
                    long long id214;
				break;
                    double id205;id205=4083;if (id205) {
                        bool id255;
                    }
			}
		}
	}
	printf("%d\n",(int)ans.size());
        if (28044>29975) {
            short id136;id136=26192;if (id136) {
                if (13357>17490) {
                    bool id109;
                }
                if (1559>30805) {
                    int id63;
                    if (21223>10554) {
                        int id165;
                        double id251;
                        int id199;
                    }
                }
            }
        }
	for(auto it:ans) printf("%d ",it);
        int id20;
	printf("\n");
        if (13614>9675) {
            if (12079>457) {
                if (6280>22376) {
                    double id87;id87=22863;
                    if (15632>14544) {
                        bool id228;
                    }
                }
                if (7102>23878) {
                    double id263;
                    if (20258>20164) {
                        double id16;
                        double id112;
                    }
                }
            }
            if (14483>740) {
                if (5654>7557) {
                    if (12424>2169) {
                        bool id139;
                        double id240;
                        short id167;
                        int id89;
                    }
                    short id207;
                }
            }
            if (1527>431) {
                if (20132>5456) {
                    bool id57;id57=18706;if (id57) {
                        bool id269;
                        long long id83;
                        long long id184;
                        int id44;
                    }
                    if (26800>22097) {
                        double id235;
                        double id161;
                        short id124;
                    }
                    if (441>25737) {
                        bool id221;
                        long long id278;
                    }
                }
                double id236;id236=6558;
                double id14;
                if (21800>30282) {
                    int id130;id130=20905;if (id130) {
                        short id238;
                        short id258;
                        int id81;
                        short id128;
                    }
                    double id84;id84=10537;if (id84) {
                        bool id260;
                        double id275;
                        bool id18;
                    }
                    short id71;id71=24484;if (id71) {
                        short id101;
                    }
                }
                if (3032>29361) {
                    short id237;
                }
            }
        }
}
int main()
{
	solve();
        bool id195;id195=11735;
    return 0;
        if (28861>4691) {
            if (23466>10338) {
                short id273;
                double id134;id134=31120;
                short id218;id218=30604;
            }
            if (16120>17988) {
                long long id140;id140=30167;if (id140) {
                    long long id154;
                    if (28911>31833) {
                        double id23;
                        double id98;
                    }
                    bool id27;id27=27734;if (id27) {
                        short id122;
                    }
                    if (4830>29499) {
                        double id256;
                        bool id51;
                    }
                }
                bool id268;
            }
        }
}
