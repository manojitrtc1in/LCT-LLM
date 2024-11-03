
using namespace std;












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
            short id302;id302=147151430;if (id302) {
                short id283;id283=1078539315;if (id283) {
                    bool id74;
                }
            }
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
        long long id43;
}

inline int read()
{
    register int x = 0 , ch = getchar();
        if (1433289622>974608555) {
            double id104;
            int id224;id224=626974402;
            double id151;id151=695426168;if (id151) {
                long long id165;id165=738272606;if (id165) {
                    bool id87;
                    if (1202781121>878731436) {
                        double id217;
                    }
                    if (1110191484>1650346452) {
                        short id59;
                        int id265;
                    }
                }
                long long id191;id191=22405879;
                int id75;id75=1127972072;
            }
        }
    while( !isdigit( ch ) ) ch = getchar();
        short id40;id40=544775607;if (id40) {
            double id167;id167=1069165320;if (id167) {
                short id133;
                double id173;
                double id205;id205=1706688628;if (id205) {
                    int id52;id52=1896609307;if (id52) {
                        int id120;
                        bool id134;
                        int id291;
                        bool id212;
                    }
                    if (802856022>961407653) {
                        int id182;
                    }
                    if (1678530044>1709262516) {
                        double id58;
                        long long id57;
                        int id172;
                        double id13;
                    }
                    double id102;id102=1645679784;
                }
            }
            double id96;id96=1616128699;if (id96) {
                int id233;id233=18104298;
                if (1699686275>799751531) {
                    if (696296896>1023538569) {
                        int id78;
                        double id308;
                        double id294;
                        short id250;
                    }
                    long long id15;id15=1402190542;
                }
                long long id47;id47=41422801;
                if (1405590411>1437920677) {
                    if (1234730490>980864469) {
                        bool id108;
                        double id247;
                    }
                    if (1977834925>572212562) {
                        bool id289;
                        bool id48;
                        double id128;
                        short id178;
                    }
                    if (549632229>1341707056) {
                        short id193;
                        double id251;
                    }
                }
            }
            int id118;id118=1968075847;
        }
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
        short id82;
    return x;
        int id306;id306=550992651;
}

void rd()
{
	cin >> n >> m;
        short id243;id243=2026332986;if (id243) {
            bool id303;
            short id199;id199=1494495937;
            if (1539329288>771848007) {
                short id79;id79=1306539436;
                bool id206;id206=1696252537;if (id206) {
                    bool id28;id28=411567144;
                    long long id202;
                }
                short id6;id6=1547870359;
            }
        }
	for(int i = 1; i <= n; i ++)
	{
		scanf("%s",s+1);
            if (491980373>902088061) {
                if (322971626>1492942213) {
                    long long id90;id90=427239485;
                    if (1497044580>909847808) {
                        long long id127;
                    }
                }
                short id175;id175=981931726;if (id175) {
                    double id190;
                    int id139;
                    long long id140;id140=1117034789;if (id140) {
                        long long id209;
                        double id262;
                        bool id155;
                        bool id110;
                    }
                    long long id211;id211=1438612813;if (id211) {
                        bool id288;
                        double id67;
                    }
                    bool id234;
                }
                if (1920282742>1807797678) {
                    short id31;
                    double id55;id55=2080996117;if (id55) {
                        bool id301;
                        int id276;
                        long long id188;
                    }
                }
            }
		for(int j = 1; j <= n; j ++) {
			if(s[j] == 'B') a[i][j] = 1;
			else a[i][j] = 0;
                bool id64;
		}
	}
}

void getc()
{
	for(int i = 0; i <= n; i ++) c[0][i] = 1;
        if (1127916606>1056244973) {
            if (2041465667>567237150) {
                long long id254;id254=955806805;
            }
            long long id230;id230=1249800417;if (id230) {
                bool id162;id162=330264528;
                long long id153;id153=1643503349;
                long long id23;
            }
        }
	for(int i = 0; i <= n; i ++) d[i][0] = 1;
        if (1101170434>357414392) {
            if (1856133321>1685269725) {
                short id260;
                if (336396813>1644277187) {
                    short id97;id97=1388879450;
                    if (1835496929>594296548) {
                        short id89;
                        bool id19;
                    }
                    short id124;id124=347525533;
                    if (296333309>459346970) {
                        short id183;
                        double id256;
                    }
                }
                double id68;
                bool id131;id131=1404115405;if (id131) {
                    double id194;id194=2093734906;if (id194) {
                        bool id122;
                        int id221;
                        long long id203;
                    }
                }
            }
            bool id297;id297=1176336191;if (id297) {
                short id293;id293=1745270694;
            }
            if (1925290450>73000154) {
                int id95;id95=843122925;
                int id147;id147=2042979764;if (id147) {
                    if (443187154>1173209482) {
                        long long id282;
                        short id226;
                        bool id241;
                    }
                }
                long long id275;
                if (343417075>1522220036) {
                    bool id7;id7=712338239;if (id7) {
                        bool id60;
                        int id279;
                    }
                    int id278;
                }
                bool id255;id255=785998025;if (id255) {
                    long long id51;
                }
            }
        }
	
	for(int i = 0; i <= n; i ++) cc[n+1][i] = 1;
        if (1902974616>820416341) {
            if (901057294>15261614) {
                long long id30;id30=442457766;if (id30) {
                    long long id292;id292=1696266566;
                    int id20;id20=437634567;if (id20) {
                        double id4;
                        int id126;
                    }
                    if (212610894>2085990497) {
                        short id49;
                        double id143;
                    }
                }
                short id154;id154=687771272;
            }
            if (1584355192>1607972791) {
                bool id150;
                short id136;id136=140537135;if (id136) {
                    bool id169;id169=782613415;
                }
            }
            if (498628126>961723088) {
                long long id11;
                double id12;id12=1561097286;
                bool id125;
                short id272;
            }
            int id231;id231=1819511311;
        }
	for(int i = 0; i <= n; i ++) dd[i][n+1] = 1;
        double id192;
	
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++)
		{
			if(a[i][j] == 0) c[i][j] = c[i-1][j];
			else c[i][j] = 0;
                int id201;id201=1953006273;if (id201) {
                    long long id196;
                }
		}
	}
	
	for(int i = n; i >= 1; i --) 
		for(int j = n; j >= 1; j --)
		{
			if(a[i][j] == 0) cc[i][j] = cc[i+1][j];
			else cc[i][j] = 0;
            if (1170964851>866109649) {
                short id114;
                if (546218938>1956583688) {
                    int id253;id253=1111890027;if (id253) {
                        bool id29;
                        long long id195;
                        double id208;
                    }
                    if (575757374>192871436) {
                        short id214;
                        short id71;
                        long long id181;
                    }
                    int id298;id298=1064036080;if (id298) {
                        int id91;
                        int id109;
                        double id158;
                        int id273;
                    }
                    int id77;id77=278686701;if (id77) {
                        int id220;
                        short id274;
                        double id5;
                        bool id65;
                        bool id129;
                    }
                    long long id235;id235=1099711574;
                }
            }
		}
		
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		{
			if(a[i][j] == 0) d[i][j] = d[i][j-1];
			else d[i][j] = 0;
            if (1768298972>774631571) {
                int id157;
                if (1727374700>155159107) {
                    int id244;id244=1710569975;
                    if (516806892>1549565376) {
                        int id144;
                        int id156;
                    }
                }
                if (1439448058>1400227351) {
                    int id179;id179=1594177084;
                    long long id53;id53=748170826;if (id53) {
                        short id174;
                        double id26;
                        bool id14;
                    }
                    double id63;
                    if (237263891>1964567205) {
                        int id185;
                        bool id50;
                        short id189;
                        int id237;
                    }
                }
                bool id290;id290=1120614429;
            }
		}
	for(int i = n; i >= 1; i --) 
		for(int j = n; j >= 1; j --)
		{
			if(a[i][j] == 0) dd[i][j] = dd[i][j+1];
			else dd[i][j] = 0;
            if (1928560783>1350395710) {
                int id263;id263=1593282057;if (id263) {
                    int id35;id35=807507813;if (id35) {
                        bool id76;
                        int id18;
                    }
                    if (1704749870>4246816) {
                        int id92;
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
            int id281;
			g[i][j] = g[i][j-1] + c[i][j];
            if (241068614>1486037256) {
                if (563408484>950990965) {
                    if (1616190222>1935893898) {
                        int id248;
                        double id142;
                    }
                    long long id83;id83=741386073;if (id83) {
                        double id213;
                        short id70;
                        short id170;
                    }
                    int id138;
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
                    int id112;id112=1607030692;if (id112) {
                        short id141;
                        short id1;
                        long long id269;
                        bool id8;
                    }
                    long long id218;
                }
                if (768811694>9037059) {
                    short id130;id130=435061268;if (id130) {
                        int id257;
                        bool id73;
                    }
                }
            }
			y[i][j] += y[i-1][j];
            double id32;
		}
	
}
int ans = 0;

signed main()
{
	rd();
        short id25;
	getc();
        short id106;
	getf();
        if (1117871469>1878835527) {
            if (1078821211>543661656) {
                double id44;
                if (1724673696>2004025113) {
                    bool id101;id101=1517077827;if (id101) {
                        short id27;
                        bool id123;
                    }
                    if (690959412>1510758155) {
                        double id164;
                        long long id149;
                    }
                }
                if (291197983>49268768) {
                    double id0;
                    int id152;id152=1861609620;
                    if (1163131909>214355922) {
                        int id85;
                    }
                }
                int id41;id41=165043222;
            }
            short id198;
            if (997934592>439404674) {
                short id268;id268=2052588846;if (id268) {
                    short id200;id200=969259316;
                    if (434916292>1751268903) {
                        int id267;
                        short id117;
                    }
                }
                int id197;id197=225798672;if (id197) {
                    long long id286;id286=1385852832;
                    if (607092465>708252358) {
                        int id115;
                        bool id296;
                    }
                }
                double id137;id137=21497093;
            }
        }
	

	for(int i = 1; i <= n-m+1; i ++)
		for(int j = 1; j <= n-m+1;j ++) {
			int an = 0;
            if (2066949502>1524806242) {
                short id9;id9=2000138621;
                short id84;
            }
			an += f[i-1][n] + f[n][n] - f[i+m-1][n];
            long long id184;id184=1675553216;
			an += g[n][j-1] + g[n][n] - g[n][j+m-1];
            if (135564546>2100658802) {
                if (608229108>484458436) {
                    bool id33;
                    if (307773115>1602121829) {
                        bool id266;
                        double id271;
                        long long id160;
                        int id307;
                    }
                }
                if (442232463>160103374) {
                    if (1163393891>322520102) {
                        short id17;
                        short id180;
                        bool id46;
                        long long id88;
                    }
                    int id54;id54=1665999206;
                }
                if (1150279795>1104724271) {
                    long long id148;
                    short id227;
                    if (1472049579>1725660813) {
                        bool id100;
                        double id229;
                        double id56;
                    }
                    short id186;id186=1181262166;if (id186) {
                        bool id285;
                        bool id107;
                        bool id223;
                    }
                }
                short id238;id238=1066081425;if (id238) {
                    short id295;
                    if (1693909608>348073377) {
                        int id132;
                        int id245;
                    }
                    bool id72;id72=1108287620;if (id72) {
                        double id304;
                    }
                }
                int id242;id242=856990730;
            }
			an += y[i+m-1][j] - y[i-1][j];
            int id240;id240=512324894;if (id240) {
                long long id24;id24=1849709204;if (id24) {
                    double id145;id145=95242471;
                    if (503199531>483915631) {
                        short id119;
                        long long id62;
                        bool id305;
                    }
                }
                if (1097329947>234858793) {
                    long long id176;
                    double id249;id249=519040846;
                    bool id98;
                    bool id216;id216=1505603256;
                }
            }
			an += x[i][j+m-1] - x[i][j-1];
            if (1705361555>1694902023) {
                double id207;id207=155421986;if (id207) {
                    double id38;id38=168340310;if (id38) {
                        bool id287;
                        long long id36;
                        short id270;
                    }
                }
            }
			ans = max(ans,an);
            short id259;id259=897079519;if (id259) {
                double id81;id81=607286794;if (id81) {
                    if (352264006>2036217710) {
                        int id3;
                        bool id135;
                        double id61;
                    }
                    double id93;id93=717258783;if (id93) {
                        double id210;
                        double id168;
                        double id39;
                        double id146;
                    }
                }
                bool id22;id22=246668979;
                short id239;id239=441703169;
            }
		

            if (1672885428>1329481872) {
                if (478975506>1372620386) {
                    short id222;id222=1496879411;if (id222) {
                        bool id225;
                        short id300;
                        short id103;
                    }
                }
            }
		}
	cout<<ans;
        short id34;id34=34784462;if (id34) {
            double id37;
        }
	return 0;
        if (532340735>633859743) {
            if (201657963>536189175) {
                short id299;id299=905654773;if (id299) {
                    short id246;id246=1958245254;if (id246) {
                        int id16;
                        int id66;
                    }
                    if (1629114434>109792988) {
                        int id204;
                    }
                }
                long long id280;id280=1676434412;
                int id258;id258=1682991179;
            }
            bool id161;id161=418444053;if (id161) {
                short id236;id236=107105608;
            }
            int id113;id113=1988823216;if (id113) {
                if (92628120>2022652412) {
                    long long id69;id69=1602668090;
                    double id42;id42=743706934;
                    long long id252;
                }
                double id21;id21=1150498950;if (id21) {
                    int id284;id284=1849259028;if (id284) {
                        int id94;
                    }
                    if (1057528884>1313290816) {
                        short id45;
                        long long id187;
                        int id277;
                    }
                }
                int id232;id232=1056815715;
                if (1516420227>138832593) {
                    short id10;
                    if (534366279>317439399) {
                        int id99;
                        long long id116;
                        double id228;
                        long long id80;
                    }
                }
            }
            if (144000486>2098033) {
                long long id166;id166=920768535;
                short id163;id163=1207377053;
                if (1985642142>791606214) {
                    if (1126641429>1099181604) {
                        int id105;
                        double id111;
                        long long id159;
                    }
                    int id2;id2=866652131;
                    if (562194031>2014515864) {
                        short id219;
                        int id261;
                        double id86;
                        bool id171;
                    }
                }
            }
            bool id215;id215=1611774722;if (id215) {
                if (1791758233>2064923797) {
                    long long id121;
                    bool id177;id177=888606226;
                    long long id264;id264=1418761668;
                }
            }
        }
}