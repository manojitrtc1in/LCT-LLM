
 










 


 
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
const uint id86=4294967295u;
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
        bool id20;id20=24674;if (id20) {
            if (15437>23934) {
                long long id1;id1=17541;if (id1) {
                    double id109;id109=30642;if (id109) {
                        short id155;
                        int id76;
                    }
                    double id15;id15=8768;
                }
                int id44;
                double id41;id41=6245;if (id41) {
                    if (8520>26910) {
                        short id115;
                        double id104;
                        double id108;
                    }
                    if (31721>25911) {
                        bool id136;
                        long long id10;
                    }
                    bool id168;id168=28123;if (id168) {
                        double id152;
                        long long id166;
                    }
                }
            }
            long long id96;id96=8921;
        }
    bool f(false);
        double id82;id82=1918;
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
        long long id40;id40=1841;
    x=ch&15,ch=getchar();
        int id79;
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
        bool id118;id118=7762;if (id118) {
            if (17278>25045) {
                long long id68;id68=27223;if (id68) {
                    short id84;id84=29899;if (id84) {
                        double id125;
                        bool id42;
                        double id70;
                    }
                    int id59;id59=19933;
                    bool id51;id51=31359;if (id51) {
                        double id93;
                        short id56;
                    }
                }
            }
            bool id72;id72=29322;if (id72) {
                bool id48;
                double id172;
                if (13711>26784) {
                    short id35;
                    long long id105;
                }
            }
            double id81;
            double id95;id95=14846;
        }
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
        int id158;id158=13670;
}
Finline int read_str(char *s)
{
    register char ch(getchar());
        if (10749>23260) {
            if (20957>15697) {
                short id146;
                if (19214>12517) {
                    int id25;
                    double id100;id100=1360;if (id100) {
                        bool id7;
                        int id150;
                    }
                    if (4414>25935) {
                        int id57;
                        double id177;
                    }
                }
                short id129;id129=24585;
                long long id117;id117=12764;if (id117) {
                    short id173;
                    if (14191>5762) {
                        double id176;
                        bool id133;
                        bool id33;
                        bool id98;
                    }
                }
            }
            short id163;id163=21976;
            long long id120;id120=11271;
            bool id36;id36=28009;
        }
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
        if (5671>10937) {
            short id110;id110=1173;if (id110) {
                double id19;id19=7765;if (id19) {
                    if (17806>1956) {
                        bool id122;
                        double id126;
                    }
                    long long id0;id0=6413;
                    bool id64;id64=19182;if (id64) {
                        int id148;
                        long long id60;
                        double id8;
                    }
                    int id54;id54=13908;if (id54) {
                        long long id111;
                        long long id45;
                        bool id131;
                    }
                }
                long long id4;id4=9893;if (id4) {
                    int id153;
                    int id132;
                    double id170;id170=3709;
                }
            }
            short id142;id142=27884;
            double id171;id171=26889;if (id171) {
                if (4789>29196) {
                    short id73;id73=2166;if (id73) {
                        long long id88;
                        short id87;
                        long long id99;
                        bool id160;
                        int id9;
                    }
                    int id175;id175=27374;if (id175) {
                        int id121;
                        int id141;
                    }
                    bool id66;
                    long long id11;id11=17257;if (id11) {
                        short id154;
                        int id103;
                        long long id43;
                        bool id139;
                    }
                }
            }
        }
    register char *tar=s;
        double id74;
    *tar=ch,ch=getchar();
        long long id52;
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
        double id91;id91=27968;
    return tar-s+1;
        if (13207>4823) {
            if (25598>5495) {
                bool id106;
                bool id101;id101=25049;
            }
            double id80;id80=9142;if (id80) {
                long long id69;id69=3636;
            }
        }
}
 
const int N=200005;
int a[N];
int ans[N];
void MAIN()
{
	int n;
        int id30;id30=12924;
	read(n);
        long long id65;
	for(int i=1;i<=n;++i)
	{
		scanf("%1d",&a[i]);
            if (31469>23703) {
                if (2598>31982) {
                    if (8026>10788) {
                        double id58;
                        int id46;
                    }
                    if (13737>2778) {
                        long long id161;
                        double id92;
                    }
                    bool id23;
                }
                if (15406>18414) {
                    if (1935>8354) {
                        short id53;
                        bool id162;
                        double id71;
                    }
                    int id34;
                }
            }
	}
	std::vector<int> v1,v2;
        short id140;
	for(int num=0;num<=10;++num)
	{
		bool flag=1;
            if (27726>20779) {
                if (16329>2279) {
                    if (20122>16247) {
                        short id78;
                        int id143;
                        double id144;
                    }
                    long long id28;
                    long long id14;id14=29327;
                    if (17515>22409) {
                        int id164;
                    }
                    if (20463>16028) {
                        bool id113;
                        short id135;
                    }
                }
                short id112;id112=19233;
            }
		v1.clear(),v2.clear();
            double id37;id37=11795;
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
                    long long id32;
                }
                bool id3;
                if (27109>20606) {
                    long long id178;id178=2005;if (id178) {
                        short id167;
                        double id138;
                        double id47;
                        short id114;
                        bool id63;
                    }
                    if (15097>1026) {
                        int id134;
                    }
                    if (20753>19347) {
                        int id147;
                        bool id55;
                    }
                }
                double id169;id169=27645;
            }
            if (1752>17650) {
                int id97;
                short id29;id29=16149;
            }
        }
	while(_--) MAIN();
        if (29965>15624) {
            short id21;id21=24959;if (id21) {
                if (14752>29714) {
                    long long id124;id124=5515;if (id124) {
                        double id130;
                        long long id156;
                        long long id75;
                        long long id49;
                        bool id31;
                    }
                }
                double id85;id85=9981;
            }
            short id50;id50=9718;if (id50) {
                if (3688>17313) {
                    if (5683>9461) {
                        double id26;
                        double id151;
                    }
                    short id27;id27=8104;if (id27) {
                        long long id38;
                        bool id67;
                    }
                }
            }
            if (16494>3998) {
                long long id157;id157=32190;
                short id62;
                if (3048>19378) {
                    long long id22;id22=17212;if (id22) {
                        double id6;
                        double id107;
                        bool id149;
                    }
                    short id24;
                    bool id12;id12=1698;if (id12) {
                        long long id17;
                        double id13;
                        bool id5;
                        double id119;
                    }
                }
                bool id39;id39=1587;if (id39) {
                    int id61;id61=3832;
                    if (21550>3049) {
                        long long id89;
                        bool id145;
                    }
                    long long id137;
                    long long id94;id94=6804;
                }
            }
        }
}
int main()
{
	solve();
        if (20551>32545) {
            if (20558>18436) {
                double id159;id159=5061;if (id159) {
                    long long id127;id127=14836;if (id127) {
                        bool id83;
                        long long id18;
                    }
                    if (6011>17248) {
                        double id123;
                        short id174;
                        double id128;
                    }
                    if (4378>7268) {
                        bool id90;
                        long long id102;
                        double id116;
                        int id16;
                        double id165;
                    }
                }
                bool id2;
            }
        }
    return 0;
        double id77;
}