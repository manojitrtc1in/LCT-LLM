#include <bits/stdc++.h>








#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) (int)x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-7

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(str) scanf("%s",str)
#define pi(x) printf("%d",x)


#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define NL printf("\n")
#define Max 1000005
#define INF 2e9
#define un(x) x.erase(unique( x.begin() , x.end() ), x.end())
#define mod 1000000007

#define FI freopen("z.txt","r",stdin)

#define D(x) cout << #x << " = " << x << endl
#define DD(x,y) cout << #x << " = " << x << "   " << #y << " = " << y << endl
#define DDD(x,y,z) cout << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << endl
#define all(x) x.begin(),x.end()
#define prntvctr(x) for(int i = 0; i < x.size(); i++) printf("%d%c", x[i], i + 1 == x.size() ? '\n' : ' ' );
#define pc(x) __builtin_popcount(x)

typedef long long LL;
typedef unsigned long long ULL;

const double PI = acos(-1.0);

using namespace std;

int setb(int n,int pos)
{
    return n=n | (1 << pos);
}
int resb(int n,int pos)
{
    return n=n & ~(1 << pos);
}
bool checkb(LL n,LL pos)
{
    return (bool)(n & (1ll << pos));
}

LL bigmod(LL b,LL p,LL m)
{
    if( p == 0 ) return 1;
    LL ret = bigmod(b,p/2,m);
    ret = ( ret * ret ) % m;
    if( p & 1 ) ret = ( ret * b ) % m;
    return ret;
}

typedef unsigned int dc;

dc p0[] = {0,49098,92938,135072,176302,216816,256726,296314,335439,374362,412849,451159,489319,527154,564877,602489,639851,676970,714154,751131,788060,824801,861401,897938,934441,970704,1006966,1043113,1079266,1115323,1151367,1187148,1222953,1258685,1294356,1329943,1365511,1401007,1436398,1471822,1507122,1542459,1577649,1612775,1647911,1683065,1718134,1753058,1788065,1822944,1857859,1892785,1927488,1962184,1996958,2031667,2066324,2100791,2135232,2169775,2204262,2238778,2273189,2307562,2342005,2376402,2410827,2445078,2479409,2513534,2547620,2581841,2615907,2649982,2684053,2718160,2752380,2786355,2820355,2854302,2888144,2921977,2955834,2989825,3023649,3057494,3091310,3125086,3158801,3192556,3226203,3259801,3293449,3327111,3360782,3394435,3428077,3461542,3495161,3528547,3562115,3595578,3629084,3662428,3695916,3729306,3762745,3796205,3829432,3862694,3896123,3929584,3962821,3996215,4029474,4062674,4095945,4129144,4162309,4195467,4228658,4261935,4295059,4328194,4361240,4394304,4427436,4460606,4493463,4526576,4559544,4592508,4625476,4658438,4691370,4724409,4757470,4790384,4823303,4856110,4889139,4921878,4954637,4987530,5020351,5053180,5085953,5118791,5151557,5184377,5216954,5249827,5282580,5315370,5348001,5380681,5413340,5446042,5478704,5511482,5544201,5576734,5609349,5642089,5674668,5707123,5739704,5772359,5804760,5837406,5869979,5902650,5935110,5967614,6000248,6032696,6065158,6097577,6129997,6162583,6194963,6227606,6259992,6292485,6324762,6357241,6389440,6421986,6454309,6486658,6518853,6551084,6583441,6615744,6648177,6680446,6712732,6745034,6777229,6809331,6841648,6873855,6906128,6938269,6970482,7002672,7034896,7067173,7099430,7131637,7163814,7196035,7228195,7260282,7292404,7324733,7356867,7388819,7420955,7453151,7485189,7517271,7549312,7581267,7613339,7645461,7677477,7709423,7741585,7773508,7805490,7837437,7869413,7901498,7933484,7965300,7997270,8029353,8061347,8093430,8125404,8157404,8189190,8221111,8253092,8285087,8316981,8348850,8380712,8412567,8444396,8476246,8507991,8539822,8571518,8603417,8635300,8667132,8698964,8730729,8762625,8794449,8826216,8858007,8889795,8921449,8953238,8985075,9016818,9048559,9080229,9111975,9143704,9175567,9207265,9238982,9270563,9302188,9334028,9365716,9397464,9429058,9460771,9492537,9524281,9555821,9587600,9619257,9650887,9682547,9714172,9745752,9777290,9808972,9840624,9872270,9903904,9935620,9967024,9998709,10030385,10061847,10093290,10124774,10156236,10187596,10219209,10250729,10282494,10314011,10345560,10376966,10408539,10440045,10471512,10502949,10534383,10565980,10597379,10628723,10660027,10691487,10723043,10754527,10786013,10817577,10848890,10880318,10911627,10943029,10974278,11005738,11037014,11068435,11099901,11131263,11162608,11194076,11225325,11256791,11288173,11319481,11350822,11382228,11413554,11444931,11476304,11507602,11538873,11570127,11601626,11632819,11664104,11695468,11726689,11758013,11789255,11820442,11851780,11883172,11914393,11945667,11976827,12008046,12039328,12070532,12101751,12132946,12164076,12195378,12226563,12257887,12289161,12320525,12351755,12382875,12413931,12445175,12476385,12507620,12538537,12569784,12601043,12632153,12663280,12694599,12725755,12756915,12788013,12818994,12850026,12881138,12912370,12943524,12974703,13005895,13037087,13068347,13099489,13130422,13161544,13192826,13223971,13254956,13285909,13316916,13347968,13378947,13410159,13441398,13472383,13503416,13534425,13565426,13596565,13627551,13658630,13689659,13720669,13751793,13782682,13813760,13844659,13875672,13906760,13937817,13968783,13999845,14030608,14061710,14092715,14123678,14154604,14185547,14216483,14247571,14278551,14309616,14340560,14371453,14402219,14433132,14464122,14495278,14526113,14556886,14587834,14618700,14649639,14680689,14711384,14742284,14772989,14803959,14834813,14865697,14896598,14927574,14958532,14989437,15020367,15051062,15082046,15113034,15143861,15174578,15205431,15236396,15267253,15298108,15329014,15359793,15390511,15421443,15452210,15482881,15513610,15544419,15575141,15606067,15636843,15667645,15698420,15729399,15760086,15790838,15821574,15852530,15883287,15913993,15944880,15975710,16006341,16037093,16067885,16098597,16129328,16160127,16190809,16221497,16252325};
dc p1[] = {0,1186924457,1893798579,617020855,1247181461,3233426953,1746628675,1486573669,1439339584,2351709351,2685026262,3508837924,509486272,786002407,1382563474,2181467130,1771119100,4162851959,3737791297,1845129876,113135667,1049605230,717035308,55223241,3664203670,4151119111,620338313,4109435764,3640511087,1739225548,4058184908,1733752499,4128611068,830632306,544226657,2754406168,141368566,86934974,1826622685,4062535323,3152132443,2839033854,2879780954,966734606,3177325654,1182654676,802398169,218940067,1462678978,2848448501,476072158,2161864610,709606329,2701622885,2249117367,3362853352,2097043645,2266373580,779817901,2059154190,584497333,3680009355,2165759854,2671210851,705943730,435344341,423944316,1223756329,69685882,2447963743,2187815795,2317913370,3456284996,3939554517,3224913200,3079087879,2762178361,3131479198,3593443652,477248677,4127023075,1885757912,3939692071,2858362106,922705700,3160397655,2779800373,3408646943,3930202144,1019375495,4001506374,3025948660,3473700494,3412810136,2558891509,3723399024,2962788250,3568134531,3195378570,596358268,3138202760,2319374615,2676736835,333838547,1162150527,3068795349,2346045672,1542534826,1470101781,2143261841,3686805484,1643871729,395833134,3901607884,1084683065,1302176495,607796600,1928785943,3572938610,3160196720,3501481187,4212831718,872294098,1046933703,1625276563,1909801931,1363222873,2101747931,3104722046,598947919,2424636003,2234181551,669277103,1224037487,1983284721,1062428724,241018183,2951326129,80580564,3308781417,1904288226,160011391,2558232006,1702886061,1500985150,198341845,822780626,1073028814,1739045308,1100621036,2681468291,3266312148,4104357761,2198065085,1045421956,2510063742,169339599,4286278787,2762834617,1770503169,1952008436,3865947937,3125379122,4110707238,357161581,3880883226,767211715,3129117666,3832914591,1501828393,2764656260,3518921053,2165813179,3366976833,3249000215,3233437435,2678888443,4172622104,3734414428,1896093420,1691323664,2183000151,2859750939,322878762,2037741545,2582043656,21600463,4100628645,2630023076,1986356223,3239853708,2133290781,494220500,3464736687,2249870564,1360221759,360836261,3447858175,330183838,1173096962,4058009517,175415944,2184667247,3198549472,2200087685,561813833,935150509,1424848048,1617039511,2056538042,875127665,3052472316,3945120572,1946126713,2179220079,1109826164,2826848322,140722304,2013850416,957287742,2702575798,3736863762,1396795953,2491101980,4094870926,1607859552,4025061026,3299273002,3970415492,4052824283,1290325367,51855740,511814506,1012702133,2587159729,3734910981,2792608003,2716336078,590449454,342725559,3676274403,4173068711,1455083349,3106220906,2592155537,1882253182,1176505656,3026875367,1478247067,816761120,2497511931,653597863,2087170454,1216948613,3206492473,3675956050,3654438051,2023626705,2325741343,2737601512,3954435426,160264602,2220152169,1349236680,1912518974,315425550,524151831,1734565800,2644948663,750303882,2180522678,593689482,2403364563,2193347514,2611849314,3719434067,1386105300,3829280989,889425163,273771343,2959018787,3065926899,3543936148,1959106138,2842186546,840364124,2822512555,2936802982,202669624,188499324,173533045,2695672045,3965348971,2123026363,1157439505,970335351,448676407,3459553087,4154372499,980313676,2329181102,1269889196,2776959649,529109873,267298679,253266795,1023643464,3627495074,1640402181,2871740684,3193945481,97019207,4086530640,1570422792,2033598729,2858886288,437632746,629607729,3543522522,1907356796,2825911862,978648202,2140648424,4059356584,3741142564,3172347476,2566364731,318520515,2163499454,2439686200,4221432995,2191838981,3872094433,1676819738,1574777656,3783730144,4193213355,1015414967,2440379656,2273489134,3906741030,640918906,1409279823,4289043567,968602133,1210828122,2274678591,2245856089,2518721984,797369498,457911573,1928264166,2876012879,627528065,4068145184,908391196,3322902592,4164694707,274194993,986644439,855383538,831644054,3471927664,3231212157,1130624721,756649151,894413524,1621818881,2438471247,4120037645,2948310656,4119221570,81411756,526438346,2716383158,3198296134,3613372692,718607166,279348962,2767001805,3117256588,2854888975,2612162792,4162931616,2466040913,3606853508,3027094272,592503614,2472049748,4279177959,2243622841,3226476067,3796049283,418427609,199455452,319464816,1960738330,4142970026,1230032410,1376439459,937483593,1799710345,1320804094,2378971777,1373095880,2000820463,2103522053,3036330750,2227385308,952262425,3273855460,1692160735,4182236972,1830253539,795390368,1834826046,1688910027,3422553778,1834794892,234232548,1107868489,3769291981,1293617834,3266753993,4278867973,3171267382,1766458492,529717862,1392198171,481136251,1829416538,2351425207,3259950545,1331411932,3302302122,3353651792,2433073352,3723433945,424719849,2255557350,2045929672,3310893819,594109765,396933035,2183180324,1671334221,1968440953,3157227377,3805382788,1346403748,3402597669,1977721535,570487882,3696282834,2427166676,2043802374,3387092559,864805293,3366979497,1319062718,3214761910,1684751027,4067939319,414104545,653120826,1630505867,3191023338,3043810085,4070608214,1592180025,1918558715,2153776796,3550143348,2471449202,3133522431,3513503948,202180699,3806580088,975307328,2129478178,162234296,2688745484,2961627887,3501636702,2343678215,4174004053,2540985023,1995000961,458334158,2423664568,2974218077,980376617,1723158334,803811398,114261386,2729414330,3638706419,299697958,1981454154,2431045046,3100702502};
dc p2[] = {0,3767716133,538482973,2373634843,2203604585,869395475,3005922769,1858783573,2822810210,443048317,3553367180,680450546,3524353842,2460348141,3098721712,2912644140,2692035542,676280933,3354110957,4164089086,1038072439,3694312412,1340651156,2736173605,3536911468,2031051235,2065677337,758622716,1173031821,979103894,753222146,2475063879,1279933484,68546176,2169630175,3451632922,2076618882,1210770834,960919729,4000809905,1241759285,1534691742,2261375484,907299922,3483061858,1298221460,612958425,768040837,2981371140,2827050491,2585178022,1422328236,2594645731,859074747,725531017,2625100094,777556079,1945515314,694617051,1227747562,1738390305,1527399565,3547426592,1513294501,83450728,1054342125,1710786870,3703006161,3228960516,396621385,1358123119,289595132,3394852990,317409417,2492754880,1274932699,3692710207,607642622,3130187814,962949537,1378784043,541621996,2114770885,3224610668,3241458532,4273915529,1775782585,1357641657,3191019892,1782737135,2549470910,3180237268,3113828372,653773186,3289419777,1948961262,733721688,1740775145,3445834892,1366048614,1222043166,2624704925,2145999903,1048205607,3577395503,803770573,4085694452,3054645024,4067940475,3992530129,1702339518,3267561835,48312344,858624138,3325440085,2281630389,2186876436,1559871851,2122676288,3580268438,72686933,3944070562,3814108542,1755172717,3894334683,529739307,2501593175,2695094105,3402911058,1832962451,981591347,273132703,3829099455,3559477929,120622645,891525588,1394436057,810738955,2133185714,2981715481,1480137470,2587123121,1731188448,3815934141,1948953922,3593518727,1205481004,2869370114,2838411336,1798679836,737121613,1902419382,1697883759,3801749189,639193420,3031958276,1300509183,192124749,3671741419,3490899709,3224702700,2458757785,706361688,1434903204,3950776575,2790021126,1520465019,3286097578,1401601139,3740139465,828484206,1016179965,1723589609,2769397233,675541083,1771018235,1592635489,4090089364,1311832760,2487619226,1768540510,365216929,4211009363,2154984136,1458462813,4114617612,1723032627,1863815893,3318286840,2935410053,3031617248,1974833039,1092247732,3798038963,292825332,1395707937,2187957855,116728333,3019878272,2697512734,3028658171,3494346642,2497035243,2462988856,998948205,2212746939,569857507,2453266912,369983745,343610896,3262608761,1618112142,3992392118,617510253,1391663367,3316799568,3563789886,2985879622,326195606,822104690,1350982608,1365425922,786499811,388341894,1562411150,4184881464,3758914856,4293492722,2978347076,3440133287,1432183877,1367265760,64196056,3207237645,4110910919,2616205543,1812386945,1613715172,3537763174,2918526257,2144798959,3947733983,3973207465,3228676202,2593476015,2189753482,2087545984,1115104677,1604994027,76888258,3824587975,1509838457,2548274410,4140815729,4034394785,2079184596,3649545527,4129513759,1075889431,2903292676,2046007012,132558316,902921043,2062096274,3918721182,2720132148,451213089,3005038190,1333368501,672339226,764083528,3163841978,4220391403,1543083226,73050244,3014906241,3063755774,1369185487,1863753391,3527415551,965355795,3943546605,2747582870,2686569388,313513388,3877523072,3255779451,3282783924,3601285346,3963706334,3295476287,1414536467,2895033469,1218901455,4031989675,3596549209,88211851,50901831,429048947,2194493280,1441566084,1467482066,1403509477,991598657,979744519,2864740455,1701862884,2441800812,3894441001,4275087902,791999931,1715979257,1771051390,3539049256,1039901499,441329744,2937890546,956649991,497880510,3716954390,2948326246,197586554,1316696078,1698922210,2982017600,537643028,2171046573,1817461025,4224775286,2378842912,127342377,215846333,3329212817,2839967702,3421507024,1281833002,2484971483,3680324687,1084544896,3380607962,292685128,599272764,2930912025,245204599,698500653,1109253350,2418568723,2735830053,1355984308,432784450,3986282421,2804188078,3876739067,8783935,4256961596,2923506560,2001288426,3422361581,2467496031,887016567,2396926956,1829520222,2025007110,1942737529,3674012723,3093204071,3748848546,26154605,1475586295,906812317,2964497678,3627365954,3799146076,1351240960,524578150,2353752438,879020462,3196742162,2739690828,885945119,1502648812,1673210107,4206225598,1535366900,543034147,2779324690,1045840918,4181035366,1202784984,1879236373,4157558589,4082066157,927141557,2783388959,293060858,186517274,1531025610,3982456318,3869598228,3110773729,1596705659,1530301949,3369999678,701956679,243781760,1755163903,4043898131,2296641630,1395877898,58481089,117452042,2427721107,1771409772,3955181757,536288504,375589242,3397674297,16554078,4069573688,1200208404,3516492693,688753747,3281068206,1851139203,3292601819,3202837156,161645138,2752711968,53529219,3608495313,2056679078,2445790865,2032499791,948475398,3765632774,3398695350,3586404106,3480741691,183261531,3917797608,2110580718,114436079,1140706845,1864275385,348201132,1611325937,4047127757,181039271,1400766866,3715469620,1073485123,3796241183,3019731272,599285954,2736801424,3988546772,3532369577,2051207249,1984271319,4117066208,1759838554,1817478089,1675826729,1157738221,4129203136,447498501,1775589954,1219427863,1987539224,930707223,2394345857,981638972,3773656610,1503234206,2280802429,1272327636,3036262965,4228653574,439283880,1234604822,2166358598,1130065736,1823087351,3541405506,3355304001,4218210313,2942555193,697773989,895615322,1706470188,829603627,1841272889,777874320,3062061344,750512272,2751237824,1453624339,110009474,481158756,2939301428,2255363504};
dc p3[] = {0,848006679,2397411321,3932886773,2033285043,3425842095,4095419825,796480243,2019094326,3271560749,2296059524,890380178,1219215950,4068749413,1072177528,140018256,2554890122,3763489733,3022703879,3654954938,4028577537,4131925644,3839243578,2892490703,2112930524,3898552525,2187602399,2862489306,955279677,129620538,1831885450,2191441041,487923074,1888930152,1438703839,2320245582,2369241956,388445476,3354701667,2856912609,2577242145,2497222052,1132912408,2823840156,4203821124,2992853042,1443985743,2305580345,2208253000,630269187,2168642964,284389088,2365292655,1573466683,3891265237,2694368070,1189968715,121129482,2283044459,1970913004,476995875,1224257777,3352238844,1915758929,2293993224,431686275,170242602,34257783,2927220384,230265693,3283767089,1164963704,2033680946,931836755,3572554990,4034945365,3377481359,4005166508,3963721738,2633745899,1324783377,737700158,1241970405,1574400600,1340026426,4143226589,3286118099,4154382317,3234796390,3301648765,706995916,1956967090,1379159868,3409537126,2326794251,3057282926,2124275752,3368995465,765887744,687618,3108370070,489852285,1600894121,2015044033,1613083429,1659600603,3241581446,868548512,130298411,1262404639,1694208642,3316518863,446701332,3600414546,2256383711,2468046597,1838503814,2356671341,572487936,243002494,1003408761,2489532300,4133163168,3431513205,2410912697,2376761673,963000135,2206001897,3530979196,3984749397,3547685185,2786724405,472249309,1276190789,3644613775,1983101858,1511189525,3943440495,2533228898,2805159015,3711867872,3363594845,190507276,1735833603,591997524,3855989955,2330073040,4178619660,4174041314,1492796306,3618674809,3258166234,1717326863,2181693803,4141538578,266792540,1933832357,1543540713,2251669111,3790534231,1733445434,3725902847,3221582488,3249566836,1071479795,1144073648,1537071833,2490490536,159532653,2411621591,1563329258,4253935747,2878154017,3886729799,1294785213,1894875393,1220629961,2193565030,613912858,3306527970,2591273054,3278169797,2711314521,2106167760,4024403999,4232656318,3700072789,1287207995,215311546,3886302965,3230256586,1728945651,3122776138,636952805,1496034970,2089394389,1413882811,231615797,3103898084,3296059280,1834072171,2314770366,452627373,4074771774,1294079731,2929159479,2914921379,2649735758,1984996293,212062216,2723275943,758567114,3858956322,2619483759,3074762357,2579642826,4093372432,3727110358,2732345294,1301193796,194998004,3370894752,3504154423,1174071746,1889964500,524865222,1983165816,1278931712,3426901050,507478225,246514045,284423346,3380565984,3206697611,1495481599,4133196619,3177766193,2882125148,1459920564,1220649093,3238319673,1475252877,1341901979,2579973120,1101976639,1213938012,235887894,3355794173,2616879057,2390122670,1266521401,4209116653,2624193788,4248615115,2363763951,2266440032,994585225,3273724999,3933385749,1154485926,1307998616,92021112,3079710151,3601803894,3800351564,432031756,4292120565,2898273334,401324877,3792703480,681877004,2278465920,1296943177,697875016,4279553000,3705364161,1659101538,3901998163,3358789265,505041981,3163184849,3914776193,1293115530,1361861664,2918720712,3829307762,1589650681,2049677652,3105743862,640979754,3281256843,2941825067,3891672961,1906508993,516352031,2422227285,3134925333,2056142757,2580766889,2017659258,408778900,1000263850,1853892271,3969254063,50770405,1702923513,1007957398,4249543304,950241139,2519449586,3810004463,410036973,1514424950,612644998,1465248879,3953853246,3912701552,3047570255,1702762472,4169079458,3376992612,3340282568,1468330566,1294264382,3197031578,3387638754,787817073,4050996201,847878876,4004738758,4106070697,1495072475,195593263,1243546944,1069077518,4106398430,2183263161,562973405,1785655934,3882188500,1730179828,2245419152,484638069,3253415797,3744985699,4073084032,445363829,1791022495,1180656302,2607684768,722527683,4280880180,4016412293,286385767,3082709998,3427419442,511314838,2390395705,3635092895,301720573,4068597112,3385173764,2208558878,2350675051,515485927,3848119669,1709384658,2059173615,3926044877,2703217755,2232351918,4248752184,3850840338,3562204960,331263588,2434560260,590207322,2480071084,442261280,3889150427,3038389378,1706206501,2710431462,294424414,2218229255,4217866402,2455775150,328235476,1949294194,64949549,1414186591,759716977,2546745961,2445870055,2807758954,972308710,1983877080,1949495280,1585594720,2821565665,1189172447,1809132095,3669779628,1559644063,3372596646,3852572637,2809330699,4251323356,312725290,3110440663,3230121890,734761693,1292098418,4275907153,2317757654,3588265164,3029442097,3465413832,1798578506,1534127258,133093751,3584295411,2083950760,3682231575,4127369707,3895351412,2103739074,3473458004,957293217,2948203473,1891556248,2867845181,1814230791,1411967658,3775227440,4139809366,528970462,1630143255,733229783,4089080484,2109423902,2862704641,1331157627,3740267321,257637698,232599547,1426303295,1307968111,3930551266,2798151818,2991050227,1925433189,2476190296,127768464,2178590170,462405916,4196721333,3944889435,829961775,3013105140,545138564,3037072905,2804063141,2917362551,1852014504,687037137,2774917576,1592046387,427431452,585331591,4216965497,1804498122,372287274,829874336,139706925,1463956770,2532612201,2887371918,3957389478,1267253848,3204375686,1883261498,1736589509,442864236,1705133077,3138560587,3681835125,869281271,1476847220,3007872414,564142555,2735355015,4115020284,3343144484,342790368,1698747128,4046620377,3543246588,2171578856,1149504644,2459290292};

#define M 600000
#define N 17325
bool pra[17333];
int prime[2005], p;
void sieve()
{
    pra[1] = 1;
    for(int i = 2; i * i <= N; i++)
    {
        if( pra[i] == 0 )
        {
            for(int j = i * i; j <= N; j += i) pra[j] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        if( pra[i] == 0 ) prime[p++] = i;
    }
}

dc n, a, b, c, d;
dc lgf(dc x) { return a * x * x * x + b * x * x + c * x + d; }

dc solve(dc x)
{
    dc val = lgf(x);
    dc p = 0;
    LL cur = 1;
    while( 1 )
    {
        cur = cur * x;
        if( cur > n ) break;
        p++;
    }
    cur /= x;

    dc tot = 0, ret = 0;
    for(dc i = p; i >= 1; i--)
    {
        dc now = n / cur;
        dc here = now - tot;
        ret += here * i * val;
        tot += here;
        cur /= x;
    }
    return ret;
}

inline bool isprime(dc x)
{
    if( x <= N ) return pra[x] == 0;
    for(dc i = 0; i < p && prime[i] * prime[i] <= x; i++) if( x % prime[i] == 0 ) return false;
    if( x == 1 ) return false;
    else return true;
}

dc brute()
{
    dc ret = 0;
    for(dc i = 1; i <= n; i++) if( isprime(i) ) ret += solve(i);
    return ret;
}


#define X 10000000

dc count_prime(dc x)
{
    dc idx = x / M;
    dc ret = a * p3[idx] + b * p2[idx] + c * p1[idx] + d * p0[idx];
    for(dc i = idx * M + 1; i <= x; i++) if( isprime(i) ) ret += lgf(i);
    return ret;
}

dc do_it(dc l, dc r, dc here)
{
	dc ret = count_prime(r) - count_prime(l-1);
	return ret * here;
}

dc semi_solve()
{
	dc item = n / X;
    dc ret = 0;
    for(int i = 1; i < item; i++)
    {
        dc mx = n / i;
        dc mn = n / (i + 1) + 1;
        ret += do_it(mn, mx, i);
    }
    return ret;
}

dc super_solve()
{
    dc ret = 0;
    dc item = n / X;
    int cur = 1;
    while( cur <= n )
    {
		dc now = n / cur;
		if( now < item ) break;
		if( isprime(cur) ) ret += solve(cur);
		cur++;
    }
	ret += semi_solve();
    return ret;
}

int main()
{
    

    sieve();
    cin >> n >> a >> b >> c >> d;
    dc ret = super_solve();
    cout << ret << endl;
    return 0;
}
