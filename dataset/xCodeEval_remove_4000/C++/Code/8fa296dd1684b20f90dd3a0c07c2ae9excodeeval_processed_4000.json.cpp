















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
            short id96;id96=25012;if (id96) {
                int id61;id61=12848;
                if (29284>6539) {
                    long long id208;
                    if (4538>31264) {
                        int id173;
                        double id246;
                        short id186;
                        short id304;
                        long long id180;
                    }
                    long long id221;id221=15014;if (id221) {
                        long long id118;
                        short id234;
                        long long id79;
                    }
                }
                short id166;id166=17090;
                double id211;id211=21308;if (id211) {
                    if (7811>20294) {
                        short id242;
                        short id85;
                    }
                    double id224;
                    long long id316;id316=14925;if (id316) {
                        bool id20;
                        double id239;
                        short id288;
                    }
                    int id272;
                }
            }
        }
    *T++=' ';
        if (10959>23447) {
            long long id256;id256=11294;if (id256) {
                double id183;id183=28354;
                double id277;
                bool id135;id135=10917;if (id135) {
                    int id330;
                }
                short id73;id73=20412;if (id73) {
                    if (30940>8635) {
                        int id55;
                        bool id72;
                        double id202;
                    }
                    long long id145;id145=19269;if (id145) {
                        double id0;
                        double id107;
                    }
                    if (508>7968) {
                        int id282;
                        bool id286;
                        short id30;
                        long long id323;
                    }
                    int id59;id59=28336;
                }
            }
            long long id98;id98=30364;if (id98) {
                long long id181;
            }
            long long id23;id23=1536;
            long long id45;id45=9787;
        }
}
uint seed=19260817;
const uint id216=4294967295u;
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
        int id81;id81=12188;
    bool f(false);
        if (24372>11108) {
            bool id66;id66=21962;
            int id110;
        }
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
        int id77;
    x=ch&15,ch=getchar();
        double id226;
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
        double id317;id317=27613;
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
        double id44;
}
Finline int read_str(char *s)
{
    register char ch(getchar());
        if (11081>19611) {
            if (21173>2496) {
                short id158;
                short id199;id199=2016;if (id199) {
                    if (20104>18892) {
                        long long id232;
                        double id309;
                    }
                    bool id190;id190=32528;
                    if (22417>16957) {
                        double id237;
                        double id315;
                        bool id27;
                    }
                }
                short id111;
            }
            int id7;id7=24217;
            short id116;id116=27910;if (id116) {
                bool id39;id39=12289;
                if (30062>28497) {
                    short id37;id37=10147;
                    if (25118>21825) {
                        bool id43;
                    }
                }
            }
        }
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
        long long id313;id313=14992;if (id313) {
            int id310;id310=8121;if (id310) {
                long long id26;
                if (18282>30495) {
                    if (97>2311) {
                        double id127;
                    }
                }
                int id262;
                if (29258>11065) {
                    if (6674>25437) {
                        bool id169;
                        long long id149;
                    }
                    bool id250;id250=26476;if (id250) {
                        long long id176;
                        bool id328;
                        bool id307;
                    }
                }
            }
            bool id46;
            bool id97;id97=24163;
            short id51;id51=4568;if (id51) {
                bool id123;id123=7591;if (id123) {
                    long long id185;id185=29344;
                    if (21093>24920) {
                        bool id161;
                    }
                    if (26490>14239) {
                        short id137;
                        int id48;
                    }
                    if (30958>8368) {
                        bool id80;
                        double id312;
                    }
                }
                if (1743>17989) {
                    double id133;
                    int id147;
                }
                if (10235>6096) {
                    short id42;
                    bool id231;id231=1208;if (id231) {
                        bool id177;
                        short id150;
                    }
                }
                if (8073>27908) {
                    long long id297;
                }
            }
        }
    register char *tar=s;
        double id245;
    *tar=ch,ch=getchar();
        short id244;id244=5697;
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
        int id204;
    return tar-s+1;
        if (25402>7660) {
            if (28468>21973) {
                int id321;id321=169;if (id321) {
                    if (17907>28861) {
                        short id8;
                        int id156;
                        double id331;
                    }
                }
                short id241;id241=4202;if (id241) {
                    int id56;
                    double id29;id29=18786;
                    bool id100;id100=32372;
                }
                if (2686>6922) {
                    long long id124;
                }
                if (2582>28844) {
                    double id223;id223=1080;
                    if (6381>19170) {
                        short id78;
                        int id33;
                    }
                }
            }
            if (17258>19971) {
                double id95;id95=15978;if (id95) {
                    long long id249;
                    int id319;id319=2782;
                }
            }
            if (24360>1838) {
                long long id50;
                if (24430>27308) {
                    if (10900>21796) {
                        int id1;
                        int id311;
                        double id74;
                        long long id157;
                    }
                    int id171;id171=12009;if (id171) {
                        short id90;
                        int id196;
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
            double id40;
            short id129;
            int id325;
            if (11614>11558) {
                if (28419>28770) {
                    int id134;id134=11096;if (id134) {
                        short id192;
                        short id308;
                    }
                    long long id132;
                }
                if (16565>23616) {
                    if (5104>17385) {
                        short id236;
                    }
                    if (16337>22676) {
                        long long id206;
                        double id197;
                        short id300;
                    }
                    if (6676>11877) {
                        double id41;
                        int id60;
                    }
                }
            }
        }
	read(n);
        long long id21;id21=3547;if (id21) {
            int id69;
        }
	int len=w-n+1;
        if (32024>9128) {
            bool id182;id182=6773;if (id182) {
                long long id294;id294=24006;if (id294) {
                    if (24932>2238) {
                        long long id170;
                        int id301;
                    }
                    double id88;id88=19644;if (id88) {
                        bool id162;
                        double id106;
                    }
                }
            }
            int id52;id52=26729;
        }
	for(int i=1;i<=n;++i) read(a[i]);
        if (29424>3196) {
            if (16088>19663) {
                short id70;id70=26606;
                if (21505>19134) {
                    int id254;
                    if (17844>15382) {
                        bool id125;
                        int id273;
                        bool id214;
                    }
                }
                if (1870>22809) {
                    int id154;
                    if (16216>17818) {
                        long long id295;
                        int id22;
                        double id153;
                        long long id327;
                        double id290;
                    }
                }
            }
            if (727>16304) {
                double id159;id159=10263;if (id159) {
                    int id104;id104=16222;
                    if (20974>8110) {
                        long long id32;
                    }
                    short id296;id296=12050;
                }
                int id329;id329=1019;
                short id105;
                short id24;
            }
            long long id230;id230=27905;
        }
	_l=1,_r=0;
        if (25535>10202) {
            long long id148;
        }
	if(len>n)
	{
		for(int i=1;i<=n;++i)
		{
			while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
			_q[++_r]=i;
                if (23642>5248) {
                    int id255;
                }
			ans[i]+=max(0,a[_q[_l]]);
                bool id47;id47=31673;if (id47) {
                    int id228;id228=4757;if (id228) {
                        short id179;
                        short id269;
                        bool id278;
                    }
                    if (27749>18855) {
                        long long id65;
                        short id101;
                        short id91;
                    }
                }
		}
		d[n+1]+=max(0,a[_q[_l]]);
            short id302;
		d[w-n+1]-=max(0,a[_q[_l]]);
            if (13065>23247) {
                if (9449>86) {
                    int id203;
                    if (4843>18730) {
                        short id119;
                    }
                }
                short id248;id248=27395;
                if (25781>18374) {
                    if (4733>30311) {
                        short id259;
                        short id268;
                    }
                    long long id205;
                }
                int id299;id299=9878;if (id299) {
                    if (5590>19309) {
                        int id233;
                        double id3;
                        short id227;
                    }
                    double id213;
                }
                short id139;
            }
		for(int i=w-n+1;i<=w;++i)
		{
			while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
                int id53;id53=1625;if (id53) {
                    bool id207;id207=16295;if (id207) {
                        bool id130;
                        short id303;
                    }
                    int id266;id266=25052;if (id266) {
                        short id152;
                        double id102;
                        double id174;
                    }
                }
			ans[i]+=max(0,a[_q[_l]]);
                int id68;id68=31571;
		}
		return;
            long long id160;
	}
	for(int i=1;i<len;++i)
	{
		while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
            if (21463>31755) {
                bool id324;
                if (17676>24562) {
                    if (15039>30767) {
                        double id63;
                        int id280;
                        bool id128;
                        short id84;
                    }
                    bool id289;id289=23222;
                    if (25502>12291) {
                        int id54;
                        bool id92;
                        double id287;
                    }
                    short id67;
                    long long id82;
                }
            }
		_q[++_r]=i;
            double id218;id218=31395;if (id218) {
                int id257;
            }
		ans[i]+=max(0,a[_q[_l]]);
            if (6929>25045) {
                double id258;id258=16920;
            }
	}
	for(int i=len;i<=n;++i)
	{
		while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
            int id305;
		_q[++_r]=i;
            if (32441>17763) {
                int id76;
                if (3643>31251) {
                    double id38;id38=23374;
                    long long id93;
                }
            }
		while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
            if (8319>17469) {
                short id291;
                if (28671>6178) {
                    if (6585>28804) {
                        int id193;
                    }
                    long long id238;
                    if (5560>30377) {
                        bool id16;
                        double id219;
                        bool id163;
                    }
                    if (19741>27190) {
                        short id260;
                    }
                }
                if (3803>10893) {
                    if (18091>4112) {
                        short id283;
                        long long id9;
                        double id108;
                    }
                    double id2;id2=16371;if (id2) {
                        short id274;
                        long long id112;
                        bool id209;
                        int id17;
                    }
                    int id151;id151=2135;if (id151) {
                        double id279;
                        long long id71;
                    }
                    if (30639>185) {
                        double id271;
                    }
                }
            }
		ans[i]+=a[_q[_l]];
            double id120;id120=16353;if (id120) {
                long long id5;
                short id138;id138=5829;
            }
	}
	for(int i=n+1;i<=w;++i)
	{
		while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
            if (16970>22490) {
                if (19094>13714) {
                    short id75;id75=20712;if (id75) {
                        bool id217;
                    }
                    if (31068>634) {
                        int id6;
                    }
                    long long id83;
                    short id164;
                }
                long long id220;id220=11351;
            }
		ans[i]+=max(0,a[_q[_l]]);
            if (22949>2212) {
                if (14771>16242) {
                    double id212;
                }
                bool id252;id252=8442;
                if (15928>1233) {
                    bool id243;id243=20477;
                }
            }
	}
}
void solve()
{
	int n,w;
        double id10;id10=2121;
	read(n,w);
        if (21372>11822) {
            long long id281;id281=12916;
        }
	for(int i=1;i<=n;++i)
	{
		___(w);
            if (2255>26783) {
                if (5071>13004) {
                    if (15448>25562) {
                        long long id87;
                        long long id222;
                    }
                    int id146;
                    if (467>18639) {
                        double id314;
                        double id210;
                        bool id322;
                    }
                }
                bool id298;id298=12265;
                if (20228>32606) {
                    short id198;
                    double id109;id109=17141;
                    if (21812>22833) {
                        int id247;
                        short id25;
                        int id326;
                        double id144;
                    }
                }
                short id263;id263=13080;
            }
	}
	for(int i=1;i<=w;++i)
	{
		d[i]+=d[i-1];
            if (32540>6601) {
                if (12653>21840) {
                    bool id276;id276=2063;
                    int id99;id99=20487;if (id99) {
                        long long id265;
                    }
                    long long id175;id175=9411;
                }
                if (13831>18587) {
                    double id172;id172=11907;if (id172) {
                        int id270;
                        long long id292;
                        double id200;
                    }
                    short id318;id318=7856;if (id318) {
                        short id195;
                        int id131;
                        int id264;
                        double id229;
                    }
                }
            }
		print(ans[i]+d[i]);
            if (28813>9360) {
                short id155;id155=3224;if (id155) {
                    if (388>12594) {
                        short id267;
                        bool id103;
                        bool id4;
                    }
                    if (23077>27291) {
                        int id178;
                        int id31;
                        bool id140;
                    }
                }
                if (16832>31455) {
                    if (12001>29139) {
                        bool id117;
                        long long id275;
                        short id320;
                    }
                    if (19141>20905) {
                        long long id28;
                    }
                }
            }
	}
}
int main()
{
	fread(ibuf,1,1<<25,stdin);
        short id121;
	solve();
        long long id165;id165=21030;if (id165) {
            bool id114;id114=8257;
        }
	fwrite(obuf,1,T-obuf,stdout);
        if (31079>19309) {
            if (23607>20399) {
                double id194;
                if (1586>8477) {
                    if (26130>14188) {
                        long long id201;
                        short id89;
                        bool id167;
                    }
                    bool id122;id122=6676;if (id122) {
                        long long id184;
                        bool id215;
                        long long id115;
                        long long id15;
                        int id126;
                    }
                    if (31842>20485) {
                        bool id293;
                        bool id11;
                    }
                }
                bool id58;id58=15562;
            }
            short id189;id189=25500;if (id189) {
                long long id64;id64=25303;if (id64) {
                    short id240;id240=15982;if (id240) {
                        int id36;
                        bool id18;
                    }
                    long long id113;id113=14061;if (id113) {
                        short id251;
                        double id142;
                        bool id285;
                    }
                    bool id253;
                }
                double id225;
                long long id57;id57=8675;if (id57) {
                    int id306;id306=18451;
                    long long id187;id187=6449;
                }
                if (18045>10574) {
                    int id49;id49=10119;if (id49) {
                        short id143;
                        double id12;
                        short id35;
                    }
                    if (11401>27439) {
                        bool id62;
                        short id141;
                        short id261;
                    }
                }
            }
            long long id94;id94=18728;
        }
    return 0;
        double id188;id188=1980;if (id188) {
            if (1272>26131) {
                long long id19;id19=26186;
                int id284;
                if (19108>16516) {
                    long long id34;
                    bool id136;id136=12745;
                    int id235;id235=30051;if (id235) {
                        double id14;
                    }
                }
                if (3548>28003) {
                    int id86;id86=22295;
                    double id191;
                }
            }
            if (8963>10726) {
                short id13;
                long long id168;id168=19624;
            }
        }
}