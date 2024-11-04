
 










 


 
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
const uint id210=4294967295u;
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
        bool id38;id38=24700;if (id38) {
            double id246;id246=26650;if (id246) {
                if (3917>31710) {
                    if (2972>21244) {
                        short id319;
                        int id3;
                        short id311;
                    }
                    short id99;id99=30768;
                    bool id58;id58=1628;
                    if (15870>28152) {
                        double id36;
                    }
                }
                long long id211;
            }
            if (6406>20414) {
                int id334;id334=26204;
                double id253;id253=11695;
                long long id206;
            }
            long long id62;
        }
    bool f(false);
        if (6722>24198) {
            int id207;id207=7848;
            long long id337;
            if (6468>12142) {
                bool id335;id335=13612;
                double id120;id120=19824;
                if (5912>17981) {
                    if (27865>17102) {
                        double id205;
                        long long id167;
                    }
                }
            }
        }
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
        bool id178;id178=19638;
    x=ch&15,ch=getchar();
        if (10725>11823) {
            short id221;id221=887;
            if (17014>23032) {
                if (2265>6354) {
                    bool id209;id209=7199;if (id209) {
                        int id177;
                        int id119;
                        bool id51;
                    }
                    if (17369>20131) {
                        short id35;
                        int id83;
                    }
                    int id282;id282=32626;
                }
                if (28532>30913) {
                    if (27954>15172) {
                        short id169;
                    }
                }
                short id64;id64=26469;if (id64) {
                    long long id307;
                    if (25500>4876) {
                        short id275;
                        bool id269;
                        long long id22;
                        long long id98;
                    }
                }
                if (5703>1328) {
                    if (29077>19849) {
                        double id152;
                        long long id328;
                        short id222;
                        int id54;
                    }
                    short id308;id308=3069;if (id308) {
                        double id93;
                        bool id1;
                        long long id2;
                        int id212;
                        int id279;
                    }
                }
                double id91;
            }
            if (6061>9877) {
                if (30227>32694) {
                    if (22012>5513) {
                        int id156;
                        double id94;
                        long long id291;
                        int id242;
                        long long id166;
                    }
                    if (5009>15045) {
                        double id134;
                        double id139;
                        long long id162;
                        int id320;
                        bool id260;
                    }
                    if (15325>27759) {
                        bool id214;
                        double id49;
                    }
                }
                if (22857>22312) {
                    bool id179;id179=8011;
                    bool id272;id272=31687;if (id272) {
                        double id302;
                        double id239;
                    }
                }
                long long id173;id173=20870;
                short id241;
                if (15743>22099) {
                    if (7532>1629) {
                        short id13;
                        double id316;
                    }
                    short id292;id292=31481;if (id292) {
                        short id336;
                        short id215;
                        bool id268;
                    }
                }
            }
            bool id137;
        }
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
        if (16195>3573) {
            if (3144>18134) {
                if (936>12914) {
                    int id28;id28=11435;if (id28) {
                        short id339;
                        bool id237;
                    }
                    if (7508>32605) {
                        int id332;
                        int id107;
                        short id66;
                    }
                    if (20845>5190) {
                        short id213;
                        double id26;
                        double id224;
                        short id21;
                    }
                }
                bool id24;id24=26440;
                double id19;
                bool id118;
            }
            long long id127;id127=15808;if (id127) {
                if (18962>9132) {
                    bool id92;id92=14086;
                }
                double id191;id191=8184;
                short id126;id126=2882;
            }
            if (21656>3095) {
                if (20050>21355) {
                    short id131;
                    long long id236;
                    double id261;id261=2947;if (id261) {
                        long long id155;
                        int id338;
                        bool id190;
                        long long id264;
                    }
                    if (29207>4607) {
                        int id168;
                    }
                }
            }
        }
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
        int id225;id225=143;if (id225) {
            double id315;id315=667;if (id315) {
                bool id289;
                double id174;
                double id140;id140=32274;if (id140) {
                    int id234;
                    bool id317;id317=18787;
                }
                long long id200;id200=29621;
            }
            bool id25;id25=2438;
            long long id202;id202=9369;if (id202) {
                if (13046>15366) {
                    double id255;id255=391;
                }
                double id43;id43=17587;if (id43) {
                    if (32261>11293) {
                        short id303;
                    }
                    if (28341>11813) {
                        bool id259;
                        int id197;
                        short id32;
                        short id186;
                    }
                }
                long long id121;id121=14472;if (id121) {
                    int id333;id333=3311;if (id333) {
                        short id277;
                        bool id42;
                        double id81;
                    }
                    long long id232;id232=892;if (id232) {
                        int id44;
                        bool id180;
                        int id251;
                    }
                }
            }
        }
}
Finline int read_str(char *s)
{
    register char ch(getchar());
        if (17024>30445) {
            double id151;id151=13640;if (id151) {
                bool id47;id47=8176;if (id47) {
                    int id181;id181=100;if (id181) {
                        double id192;
                    }
                    if (27018>25603) {
                        long long id124;
                        double id68;
                        double id100;
                    }
                    bool id53;id53=8045;
                    long long id70;
                }
                if (23670>305) {
                    long long id33;id33=3189;if (id33) {
                        double id37;
                        int id149;
                        double id141;
                        double id290;
                    }
                }
            }
            if (14536>24576) {
                long long id128;id128=6211;if (id128) {
                    short id312;id312=2180;if (id312) {
                        int id158;
                        long long id50;
                    }
                    int id74;
                    int id216;
                    if (15195>365) {
                        short id204;
                        bool id182;
                        int id249;
                        long long id114;
                        double id133;
                    }
                    long long id59;id59=28204;
                }
            }
        }
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
        if (11036>20921) {
            long long id112;id112=8396;if (id112) {
                double id271;
                if (19976>2730) {
                    if (16944>5698) {
                        long long id258;
                        short id111;
                        long long id89;
                        short id238;
                    }
                    if (8782>32182) {
                        short id45;
                        double id172;
                        bool id276;
                    }
                    if (7396>31561) {
                        long long id77;
                        long long id103;
                        int id86;
                    }
                }
            }
            if (12337>18688) {
                if (16620>13488) {
                    if (5375>25464) {
                        short id73;
                    }
                    if (27241>9975) {
                        int id84;
                        double id10;
                        int id183;
                    }
                }
                long long id187;
                short id159;id159=31081;if (id159) {
                    if (25317>27422) {
                        short id130;
                        long long id23;
                    }
                    if (11969>31389) {
                        short id297;
                        short id164;
                    }
                }
                int id7;
            }
            bool id341;id341=10250;if (id341) {
                bool id342;id342=10433;if (id342) {
                    if (15127>9384) {
                        short id125;
                        double id101;
                    }
                    int id240;id240=1065;if (id240) {
                        short id104;
                        double id285;
                        long long id256;
                    }
                }
                if (20171>11717) {
                    if (18911>26341) {
                        long long id138;
                        double id14;
                        short id52;
                        bool id327;
                    }
                    if (9987>19469) {
                        double id72;
                        double id148;
                        double id188;
                    }
                    bool id27;
                    short id344;
                }
            }
            short id324;id324=27973;if (id324) {
                long long id245;
                if (14890>12920) {
                    int id165;id165=27506;if (id165) {
                        int id87;
                    }
                    long long id129;id129=20787;
                    bool id150;id150=14395;if (id150) {
                        bool id219;
                        long long id286;
                    }
                }
            }
        }
    register char *tar=s;
        if (26832>27639) {
            double id157;id157=12873;if (id157) {
                short id230;
            }
        }
    *tar=ch,ch=getchar();
        double id145;id145=25589;
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
        double id208;id208=25714;
    return tar-s+1;
        if (5499>29467) {
            if (13506>12241) {
                if (17966>9251) {
                    long long id171;id171=15609;
                    bool id117;id117=11900;if (id117) {
                        short id17;
                        int id326;
                    }
                }
                double id250;
            }
        }
}
 
const int N=100005;
struct edge{
	int v,nxt,id;
}c[N<<1];
int front[N],cnt;
int a[N],b[N];
std::queue<int> q;
bool used[N];
bool vis[N];
int _q[N],_l,_r;
Finline void add(const int &u,const int &v,const int &id)
{
	c[++cnt]=(edge){v,front[u],id},front[u]=cnt;
        short id227;id227=840;
}
void solve()
{
	int n,k,x,y;
        int id122;id122=5752;
	read(n,k);
	if(n==23433) exit(233);
        bool id57;id57=15910;
	for(int i=1;i<=k;++i)
	{
		read(x,y);
            double id39;
		add(x,y,i),add(y,x,i);
            bool id80;id80=29386;if (id80) {
                if (28471>5778) {
                    short id223;
                    double id41;id41=14726;if (id41) {
                        short id109;
                        long long id288;
                    }
                    long long id76;id76=6580;if (id76) {
                        double id325;
                        short id142;
                        long long id102;
                        double id273;
                    }
                }
                if (27010>2939) {
                    int id199;id199=32131;
                    int id193;
                }
                if (23578>30107) {
                    bool id4;id4=12695;
                    bool id280;id280=29702;
                    int id198;id198=13709;
                }
                long long id85;id85=6488;if (id85) {
                    if (19444>1473) {
                        double id78;
                        bool id75;
                        short id229;
                    }
                    long long id323;id323=6981;
                }
                if (20197>4769) {
                    int id309;id309=5606;if (id309) {
                        short id31;
                        bool id143;
                        bool id161;
                    }
                }
            }
		a[i]=x,b[i]=y;
            if (14456>23217) {
                if (1383>20126) {
                    short id270;
                    bool id185;id185=20294;
                }
                bool id298;id298=30150;if (id298) {
                    if (26601>17406) {
                        short id321;
                        short id97;
                        double id55;
                        bool id88;
                    }
                    short id294;
                }
            }
		q.push(i);
            if (21046>3397) {
                if (28894>26271) {
                    if (17351>18193) {
                        int id184;
                        long long id16;
                        int id243;
                        bool id314;
                    }
                    long long id110;id110=18428;if (id110) {
                        short id195;
                        int id108;
                        long long id301;
                        long long id147;
                    }
                }
            }
	}
	int ans=0;
        if (13244>4956) {
            if (14211>16260) {
                double id11;id11=17337;
                if (30483>13884) {
                    if (10229>9909) {
                        bool id235;
                        short id18;
                        double id228;
                    }
                }
                double id175;id175=7462;
                if (4587>26344) {
                    if (30157>1052) {
                        bool id116;
                    }
                    short id154;id154=17394;if (id154) {
                        bool id217;
                        double id267;
                    }
                    if (8927>19010) {
                        int id278;
                        bool id0;
                        int id233;
                    }
                }
                if (25627>15576) {
                    double id254;id254=12595;if (id254) {
                        double id20;
                        bool id266;
                    }
                    bool id56;id56=2206;
                }
            }
            short id329;id329=17222;if (id329) {
                short id30;id30=5729;if (id30) {
                    int id163;
                }
                if (3083>8013) {
                    long long id274;
                    int id96;id96=7926;
                    short id189;id189=31577;if (id189) {
                        short id201;
                        bool id79;
                        int id113;
                    }
                }
                if (19757>28938) {
                    int id69;
                    int id284;id284=17755;
                }
                bool id226;id226=2338;if (id226) {
                    long long id293;id293=3799;if (id293) {
                        short id132;
                        int id263;
                    }
                    if (918>29949) {
                        bool id46;
                    }
                    long long id48;id48=19157;if (id48) {
                        double id287;
                        double id231;
                    }
                }
            }
            if (9988>16248) {
                int id257;id257=5484;if (id257) {
                    short id262;id262=21377;if (id262) {
                        long long id299;
                        double id82;
                        double id194;
                    }
                    if (7889>16778) {
                        short id60;
                        bool id34;
                    }
                }
                if (26264>19581) {
                    if (3200>1551) {
                        double id331;
                        int id281;
                    }
                }
                if (3484>22813) {
                    bool id123;id123=16097;if (id123) {
                        double id176;
                        int id322;
                        bool id71;
                    }
                }
            }
        }
	while(!q.empty())
	{
		int x=q.front();
            if (31855>22474) {
                int id12;
            }
		q.pop();
            if (12022>27138) {
                double id5;id5=8655;
                short id318;
            }
		while(used[x]&&!q.empty()) x=q.front(),q.pop();
            int id8;
		if(used[x]) continue;
		if(vis[a[x]]&&vis[b[x]]) continue;
		++ans;
		_l=1,_r=0;
            int id170;id170=21758;
		if(!vis[a[x]])
		{
			vis[a[x]]=1;
			_q[++_r]=a[x];
                double id248;
		}
		if(!vis[b[x]])
		{
			vis[b[x]]=1;
			_q[++_r]=b[x];
                long long id15;
		}
		while(_l!=_r+1)
		{
			int _=_q[_l++];
                if (5794>27410) {
                    if (25495>827) {
                        long long id95;
                        int id244;
                        int id313;
                    }
                    double id144;id144=11086;if (id144) {
                        bool id67;
                        long long id106;
                        int id306;
                    }
                }
			for(int i=front[_];i;i=c[i].nxt)
			{
				if(!used[c[i].id])
				{
					if(!vis[c[i].v])
					{
						used[c[i].id]=1;
						++ans;
						vis[c[i].v]=1;
						_q[++_r]=c[i].v;
                            bool id304;
					}
				}
			}
		}
	}
	printf("%d\n",k-ans);
        bool id29;id29=1416;if (id29) {
            long long id61;id61=22484;
            if (32552>7197) {
                if (13897>19325) {
                    int id340;
                    int id252;
                }
                short id135;id135=17701;
                int id295;id295=22917;
                short id343;id343=2833;if (id343) {
                    bool id310;id310=21296;if (id310) {
                        double id283;
                        short id220;
                        long long id296;
                        short id153;
                    }
                    if (29866>8245) {
                        long long id115;
                        long long id136;
                        short id247;
                    }
                    if (2118>15352) {
                        int id196;
                    }
                    short id330;id330=22797;if (id330) {
                        long long id305;
                        bool id160;
                        short id105;
                        int id203;
                        double id63;
                    }
                }
            }
        }
}
int main()
{
	solve();
        int id9;
    return 0;
        if (11686>2228) {
            short id40;
            bool id90;id90=23660;if (id90) {
                if (12752>9877) {
                    double id265;id265=18304;if (id265) {
                        short id300;
                        short id218;
                        double id146;
                        bool id65;
                    }
                }
                bool id6;
            }
        }
}