












using namespace std;



int pr[32000];
int epr = 0;
bool U1[32000] = {1,1};
bool U[105000] = {};

int nakop[] = {0,4783,8977,12980,16900,20731,24522,28248,31915,35584,39175,42817,46429,49961,53515,57022,60522,64039,67488,70984,74416,77878,81284,84678,88054,91432,94877,98239,101607,104978,108283,111652,115038,118374,121694,124996,128269,131625,134911,138218,141502,144829,148120,151367,154618,157924,161165,164443,167674,170945,174193,177432,180616,183843,187047,190282,193492,196708,199899,203110,206332,209525,212731,215965,219122,222271,225462,228650,231843,235068,238260,241442,244580,247732,250867,253973,257140,260351,263481,266622,269759,272884,276013,279148,282270,285395,288555,291709,294877,297983,301100,304176,307325,310443,313578,316641,319812,322903,326006,329105,332180,335267,338393,341464,344550,347664,350738,353839,356908,359999,363079,366159,369260,372327,375438,378517,381634,384727,387816,390919,393992,397032,400086,403208,406287,409308,412332,415430,418498,421555,424568,427582,430659,433679,436752,439790,442817,445856,448900,451961,454973,457971,461014,464068,467134,470152,473177,476214,479249,482264,485274,488278,491292,494310,497241,500235,503250,506275,509307,512382,515413,518403,521397,524427,527421,530471,533468,536441,539449,542466,545500,548498,551460,554512,557492,560488,563513,566513,569507,572480,575502,578463,581444,584483,587447,590415,593356,596372,599364,602378,605356,608339,611345,614315,617283,620282,623218,626203,629186,632136,635170,638123,641087,644017,646967,649932,652928,655896,658856,661818,664770,667742,670675,673687,676669,679671,682575,685540,688503,691477,694489,697404,700325,703272,706180,709114,712112,715037,717988,720959,723895,726881,729830,732781,735739,738675,741605,744562,747457,750383,753317,756216,759187,762198,765149,768086,771011,773927,776895,779826,782753,785697,788610,791512,794448,797360,800285,803240,806179,809115,812027,814962,817867,820795,823751,826719,829642,832595,835497,838435,841363,844291,847193,850079,853021,855894,858874,861760,864671,867591,870513,873481,876357,879281,882185,885137,888022,890932,893856,896757,899685,902572,905459,908420,911331,914213,917109,920006,922880,925821,928779,931677,934603,937519,940452,943325,946294,949180,952087,955025,957870,960725,963623,966506,969406,972308,975195,978084,980961,983866,986745,989646,992537,995404,998271,1001140,1004046,1006934,1009827,1012697,1015618,1018496,1021406,1024320,1027184,1030063,1032961,1035802,1038721,1041664,1044520,1047337,1050174,1053073,1055896,1058797,1061675,1064499,1067387,1070267,1073173,1076028,1078882,1081789,1084691,1087553,1090412,1093330,1096220,1099055,1101902,1104800,1107644,1110567,1113424,1116308,1119225,1122065,1124940,1127771,1130651,1133558,1136474,1139333,1142194,1145025,1147866,1150737,1153591,1156489,1159338,1162243,1165139,1168042,1170910,1173745,1176590,1179443,1182369,1185243,1188092,1190924,1193800,1196659,1199544,1202431,1205284,1208197,1211025,1213867,1216687,1219587,1222392,1225258,1228118,1230995,1233829,1236681,1239604,1242421,1245271,1248111,1250995,1253791,1256651,1259536,1262362,1265204,1268046,1270889,1273688,1276505,1279376,1282285,1285126,1287979,1290770,1293579,1296433,1299248,1302080,1304898,1307764,1310564,1313436,1316313,1319178,1321952,1324798,1327679,1330569,1333416,1336221,1339090,1341879,1344729,1347557,1350401,1353251,1356097,1358924,1361745,1364528,1367410,1370265,1373088,1375933,1378786,1381607,1384447,1387239,1390061,1392849,1395708,1398554,1401373,1404178,1407068,1409898,1412744,1415625,1418380,1421270,1424099,1426912,1429774,1432594,1435429,1438257,1441128,1443938,1446778,1449604,1452382,1455247,1458082,1460919,1463728,1466528,1469368,1472194,1475030,1477837,1480666,1483500,1486322,1489165,1491980,1494786,1497647,1500452,1503238,1506080,1508872,1511685,1514526,1517366,1520183,1523010,1525805,1528621,1531401,1534200,1536996,1539893,1542682,1545502,1548240,1551092,1553883,1556701,1559564,1562351,1565116,1567942,1570715,1573535,1576358,1579175,1581959,1584771,1587541,1590355,1593211,1596004,1598782,1601563,1604385,1607164,1609973,1612823,1615616,1618451,1621216,1624006,1626766,1629635,1632420,1635221,1637990,1640856,1643717,1646484,1649296,1652063,1654853,1657618,1660459,1663264,1666080,1668891,1671699,1674593,1677355,1680124,1682934,1685690,1688538,1691340,1694100,1696862,1699638,1702440,1705277,1708109,1710911,1713724,1716509,1719266,1722094,1724879,1727670,1730435,1733216,1736051,1738806,1741641,1744420,1747204,1750006,1752771,1755536,1758336,1761092,1763838,1766646,1769443,1772245,1775045,1777875,1780670,1783463,1786235,1789018,1791840,1794679,1797447,1800273,1803073,1805870,1808646,1811415,1814142,1816932,1819706,1822527,1825243,1828004,1830792,1833547,1836359,1839213,1841995,1844791,1847580,1850326,1853088,1855855,1858662,1861432,1864206,1866990,1869795,1872539,1875344,1878116,1880877,1883645,1886489,1889296,1892074,1894866,1897678,1900520,1903295,1906068,1908796,1911588,1914345,1917128,1919905,1922736,1925488,1928317,1931028,1933872,1936617,1939420,1942194,1944974,1947726,1950517,1953326,1956075,1958881,1961652,1964429,1967230,1969998,1972723,1975509,1978237,1981016,1983808,1986617,1989437,1992204,1994949,1997720,2000488,2003303,2006032,2008815,2011606,2014372,2017179,2019932,2022701,2025512,2028255,2031019,2033802,2036609,2039322,2042135,2044904,2047681,2050501,2053229,2055970,2058718,2061483,2064274,2067034,2069779,2072560,2075348,2078103,2080844,2083583,2086329,2089096,2091863,2094671,2097406,2100184,2102971,2105737,2108432,2111258,2113989,2116783,2119526,2122303,2125068,2127837,2130617,2133418,2136172,2138961,2141712,2144480,2147171,2149923,2152701,2155441,2158236,2161007,2163757,2166536,2169246,2171964,2174705,2177469,2180268,2183017,2185805,2188546,2191331,2194099,2196834,2199595,2202323,2205082,2207859,2210668,2213443,2216181,2218952,2221738,2224514,2227245,2230005,2232707,2235481,2238230,2240990,2243755,2246479,2249226,2252024,2254787,2257553,2260311,2263078,2265827,2268544,2271244,2274002,2276735,2279482,2282216,2284982,2287746,2290511,2293239,2295996,2298701,2301493,2304176,2306930,2309703,2312442,2315162,2317909,2320690,2323416,2326185,2328941,2331675,2334373,2337138,2339870,2342641,2345410,2348162,2350886,2353607,2356372,2359138,2361871,2364677,2367431,2370148,2372877,2375650,2378387,2381161,2383895,2386652,2389449,2392221,2394901,2397617,2400362,2403098,2405856,2408602,2411350,2414126,2416903,2419626,2422295,2425055,2427744,2430502,2433250,2436000,2438718,2441527,2444351,2447015,2449764,2452481,2455255,2458030,2460743,2463428,2466186,2468911,2471678,2474402,2477112,2479831,2482616,2485398,2488153,2490868,2493630,2496330,2499025,2501803,2504527,2507233,2509985,2512725,2515472,2518174,2520874,2523613,2526329,2529121,2531838,2534603,2537307,2540007,2542790,2545540,2548283,2551054,2553801,2556545,2559255,2562020,2564749,2567509,2570147,2572928,2575663,2578402,2581127,2583835,2586614,2589383,2592089,2594818,2597535,2600253,2602943,2605705,2608393,2611085,2613805,2616564,2619320,2622047,2624786,2627469,2630205,2632915,2635612,2638343,2641067,2643873,2646580,2649273,2651922,2654663,2657388,2660088,2662839,2665563,2668328,2671038,2673787,2676539,2679253,2682013,2684760,2687514,2690184,2692883,2695613,2698330,2701066,2703797,2706496,2709173,2711870,2714584,2717373,2720151,2722853,2725558,2728235,2730936,2733697,2736446,2739145,2741926,2744681,2747378,2750077,2752810,2755520,2758289,2761025,2763724,2766425,2769152,2771909,2774615,2777362,2780031,2782758,2785458,2788180,2790934,2793660,2796374,2799108,2801843,2804530,2807260,2809929,2812654,2815399,2818087,2820816,2823538,2826275,2828966,2831688,2834416,2837099,2839798,2842570,2845295,2847954,2850685,2853361,2856130,2858813,2861493,2864214,2866911,2869648,2872352,2875060,2877769,2880504,2883225,2885939,2888660,2891323,2894041,2896736,2899481,2902172,2904856,2907605,2910318,2913025,2915748,2918452,2921164,2923833,2926596,2929264,2931965,2934702,2937421,2940117,2942866,2945635,2948311,2951034,2953763,2956446,2959192,2961880,2964615,2967239,2969937,2972637,2975366,2978050,2980754,2983430,2986122,2988901,2991611,2994330,2997074,2999798,3002503,3005202,3007899,3010596,3013323,3016008,3018742,3021416,3024128,3026842,3029541,3032257,3034937,3037646,3040325,3043021,3045753,3048457,3051169,3053830,3056532,3059267,3061962,3064625,3067351,3069996,3072754,3075489,3078185,3080940,3083636,3086304,3089048,3091765,3094460,3097082,3099790,3102502,3105213,3107928,3110675,3113375,3116120,3118821,3121505,3124225,3126913,3129662,3132388,3135040,3137799,3140464,3143178,3145894,3148594,3151358,3154059,3156703,3159380,3162036,3164763,3167421,3170164,3172859,3175582,3178275,3180980,3183678,3186335,3189066,3191740,3194438,3197143,3199904,3202632,3205349,3208092,3210814,3213513,3216211,3218844,3221530,3224233,3226983,3229663,3232325,3235039,3237755,3240411,3243107,3245792,3248447,3251141,3253793,3256464,3259117,3261785,3264498,3267183,3269880,3272565,3275207,3277989,3280683,3283347,3286022,3288732,3291421,3294157,3296808,3299510,3302208,3304881,3307586,3310218,3312950,3315657,3318339,3321023,3323749,3326371,3329059,3331729,3334386,3337066,3339777,3342471,3345125,3347847,3350544,3353225,3355955,3358629,3361302,3363968,3366669,3369386,3372103,3374795,3377476,3380174,3382884,3385554,3388180,3390854,3393550,3396269,3398958,3401657,3404347,3407021,3409748,3412423,3415111,3417798,3420475,3423163,3425803,3428512,3431139,3433830,3436494,3439208,3441872,3444596,3447271,3450004,3452684,3455325,3458009,3460715,3463432,3466043,3468739,3471401,3474094,3476806,3479442,3482093,3484812,3487497,3490170,3492859,3495567,3498296,3500973,3503651,3506386,3509079,3511782,3514443,3517153,3519833,3522519,3525175,3527907,3530581,3533255,3535968,3538667,3541337,3543977,3546666,3549375,3552021,3554738,3557384,3560089,3562779,3565456,3568116,3570776,3573440,3576161,3578837,3581526,3584201,3586898,3589607,3592223,3594894,3597608,3600283,3602936,3605597,3608314,3611056,3613718,3616374,3619062,3621778,3624436,3627137,3629812,3632493,3635171,3637896,3640545,3643224,3645880,3648521,3651241,3653949,3656684,3659418,3662083,3664726,3667445,3670104,3672774,3675492,3678171,3680847,3683589,3686167,3688864,3691502,3694148,3696774,3699494,3702150,3704778,3707475,3710194,3712860,3715570,3718228,3720906,3723621,3726325,3729013,3731696,3734398,3737056,3739686,3742386,3745051,3747735,3750446,3753092,3755762,3758469,3761124,3763797,3766487,3769100,3771837,3774511,3777095,3779798,3782493,3785160,3787803,3790454,3793099,3795809,3798470,3801141,3803840,3806531,3809251,3811892,3814569,3817239,3819898,3822593,3825302,3827948,3830625,3833256,3835965,3838550,3841205,3843892,3846530,3849183,3851820,3854487,3857122,3859808,3862540,3865212,3867907,3870565,3873196,3875854,3878497,3881126,3883819,3886490,3889195,3891881,3894546,3897253,3899882,3902459,3905109,3907778,3910368,3913049,3915711,3918399,3921048,3923695,3926400,3929084,3931737,3934442,3937078,3939771,3942497,3945190,3947874,3950554,3953193,3955920,3958644,3961296,3963905,3966567,3969210,3971879,3974535,3977154,3979752,3982459,3985071,3987719,3990415,3993125,3995734,3998437,4001108,4003806,4006463,4009127,4011826,4014468,4017139,4019845,4022480,4025095,4027764,4030423,4033094,4035733,4038440,4041067,4043776,4046463,4049120,4051769,4054423,4057113,4059770,4062450,4065122,4067793,4070474,4073175,4075820,4078472,4081176,4083781,4086434,4089089,4091773,4094420,4097098,4099747,4102416,4105055,4107701,4110355,4113049,4115721,4118384,4121051,4123727,4126379,4129049,4131699,4134352,4137023,4139685,4142363,4145060,4147676,4150323,4153010,4155685,4158363,4160966,4163596,4166235,4168922,4171605,4174223,4176869,4179521,4182182,4184849,4187488,4190140,4192810,4195421,4198062,4200731,4203354,4206044,4208686,4211356,4213981,4216685,4219356,4221984,4224627,4227282,4229914,4232564,4235232,4237861,4240502,4243169,4245784,4248401,4251065,4253701,4256359,4259014,4261660,4264293,4266921,4269624,4272263,4274956,4277597,4280201,4282797,4285398,4288064,4290687,4293350,4296020,4298653,4301294,4303981,4306608,4309217,4311886,4314528,4317234,4319922,4322592,4325293,4327911,4330590,4333233,4335878,4338515,4341143,4343801,4346450,4349052,4351734,4354388,4357048,4359662,4362341,4364925,4367587,4370298,4372935,4375552,4378192,4380844,4383574,4386239,4388878,4391541,4394199,4396850,4399520,4402186,4404831,4407486,4410085,4412693,4415370,4418022,4420720,4423371,4425991,4428608,4431242,4433901,4436579,4439169,4441822,4444489,4447137,4449672,4452306,4454922,4457554,4460240,4462893,4465543,4468139,4470784,4473456,4476147,4478749,4481416,4484075,4486723,4489311,4492006,4494651,4497292,4499965,4502618,4505252,4507855,4510572,4513193,4515918,4518559,4521185,4523773,4526426,4529072,4531707,4534346,4536967,4539592,4542203,4544860,4547522,4550195,4552843,4555491,4558140,4560803,4563437,4566060,4568705,4571336,4574014,4576656,4579284,4581976,4584686,4587325,4589992,4592653,4595265,4597876,4600571,4603200,4605816,4608468,4611139,4613736,4616384,4619005,4621592,4624231,4626875,4629507,4632186,4634796,4637398,4640030,4642677,4645359,4647918,4650559,4653230,4655888,4658585,4661189,4663803,4666450,4669054,4671704,4674350,4676996,4679632,4682242,4684948,4687532,4690160,4692789,4695462,4698102,4700734,4703362,4706006,4708642,4711273,4713899,4716607,4719201,4721852,4724480,4727183,4729854,4732495,4735167,4737850,4740485,4743082,4745720,4748366,4750949,4753626,4756288,4758912,4761560,4764204,4766822,4769429,4772012,4774672,4777295,4779966,4782596,4785261,4787904,4790545,4793166,4795769,4798435,4801063,4803667,4806332,4808984,4811622,4814266,4816890,4819528,4822160,4824804,4827435,4830057,4832684,4835378,4837999,4840680,4843321,4845981,4848639,4851211,4853837,4856491,4859126,4861762,4864387,4867027,4869675,4872295,4874853,4877528,4880179,4882797,4885426,4888077,4890745,4893364,4896010,4898672,4901285,4903890,4906511,4909156,4911784,4914383,4917032,4919689,4922305,4924918,4927572,4930212,4932817,4935487,4938139,4940774,4943378,4946069,4948679,4951296,4953910,4956557,4959209,4961877,4964537,4967184,4969805,4972409,4975038,4977661,4980310,4982940,4985646,4988225,4990897,4993515,4996144,4998801,5001442,5004056,5006708,5009405,5012064,5014694,5017339,5019949,5022571,5025178,5027801,5030446,5033046,5035680,5038279,5040862,5043507,5046094,5048765,5051411,5054024,5056628,5059277,5061912,5064511,5067204,5069824,5072491,5075113,5077658,5080255,5082859,5085499,5088134,5090727,5093332,5095988,5098615,5101202,5103825,5106458,5109089,5111743,5114361,5116966,5119590,5122213,5124844,5127514,5130153,5132782,5135430,5138075,5140730,5143345,5145980,5148605,5151274,5153899,5156546,5159149,5161733,5164341,5166953,5169573,5172231,5174884,5177521,5180105,5182722,5185363,5187965,5190595,5193212,5195880,5198499,5201125,5203796,5206414,5209049,5211712,5214288,5216845,5219487,5222090,5224740,5227386,5230074,5232641,5235255,5237882,5240496,5243170,5245786,5248348,5250963,5253603,5256294,5258924,5261559,5264197,5266811,5269431,5272056,5274677,5277358,5279980,5282587,5285175,5287824,5290377,5292983,5295575,5298143,5300708,5303299,5305964,5308564,5311159,5313782,5316422,5319018,5321596,5324213,5326784,5329409,5332020,5334622,5337227,5339867,5342496,5345129,5347795,5350421,5353089,5355702,5358367,5360986,5363544,5366147,5368776,5371411,5374087,5376686,5379309,5381928,5384560,5387171,5389784,5392411,5395045,5397628,5400259,5402886,5405526,5408175,5410793,5413433,5415998,5418614,5421234,5423861,5426484,5429132,5431729,5434358,5436988,5439575,5442163,5444784,5447429,5450049,5452629,5455225,5457873,5460457,5463063,5465635,5468291,5470839,5473437,5476039,5478623,5481233,5483861,5486491,5489061,5491684,5494276,5496929,5499559,5502194,5504848,5507483,5510038,5512630,5515228,5517812,5520450,5523147,5525739,5528353,5530959,5533525,5536135,5538820,5541484,5544170,5546786,5549333,5551961,5554593,5557155,5559793,5562400,5564988,5567667,5570317,5572921,5575558,5578172,5580734,5583347,5585967,5588599,5591256,5593882,5596536,5599125,5601765,5604342,5606977,5609543,5612149,5614794,5617363,5619973,5622603,5625219,5627889,5630519,5633084,5635730,5638331,5640957,5643586,5646178,5648776,5651327,5653954,5656615,5659236,5661890,5664466,5667109,5669723,5672314,5674897,5677515,5680111,5682697,5685282,5687872,5690536,5693137,5695724,5698353,5700961,5703596,5706172,5708792,5711417,5713947,5716607,5719235,5721869,5724431,5727029,5729669,5732290,5734926,5737554,5740150,5742759,5745302,5747921,5750483,5753108,5755699,5758283,5760902,5763487,5766102,5768741,5771328,5773920,5776525,5779098,5781661,5784323,5786982,5789589,5792262,5794903,5797481,5800088,5802684,5805348,5807962,5810587,5813144,5815757,5818374,5820929,5823532,5826126,5828741,5831422,5834054,5836687,5839331,5841892,5844528,5847109,5849740,5852351,5854946,5857518,5860153,5862785,5865405,5868020,5870661,5873254,5875844,5878519,5881139,5883728,5886328,5888951,5891560,5894166,5896790,5899351,5901945,5904576,5907198,5909821,5912398,5914979,5917582,5920156,5922795,5925411,5928031,5930671,5933313,5935940,5938527,5941164,5943776,5946379,5949000,5951599,5954205,5956844,5959489,5962106,5964739,5967357,5969953,5972549,5975141,5977741,5980357,5982938,5985528,5988134,5990732,5993378,5995954,5998499,6001090,6003726,6006282,6008886,6011522,6014157,6016756,6019331,6021858,6024474,6027081,6029691,6032263,6034852,6037495,6040040,6042690,6045298,6047913,6050498,6053125,6055661,6058264,6060851,6063463,6066106,6068703,6071357,6073901,6076511,6079116,6081674,6084292,6086845,6089461,6092065,6094753,6097312,6099889,6102470,6105112,6107731,6110281,6112890,6115532,6118145,6120761,6123305,6125904,6128579,6131218,6133812,6136359,6139004,6141599,6144217,6146819,6149370,6152007,6154674,6157270,6159870,6162460,6164975,6167590,6170167,6172802,6175449,6178054,6180644,6183212,6185804,6188461,6191133,6193760,6196338,6198882,6201445,6204005,6206614,6209207,6211824,6214484,6217046,6219684,6222251,6224826,6227425,6230024,6232617,6235253,6237902,6240567,6243136,6245744,6248382,6250967,6253593,6256156,6258703,6261228,6263771,6266352,6268949,6271544,6274152,6276724,6279294,6281849,6284430,6287078,6289702,6292247,6294879,6297457,6300082,6302646,6305224,6307853,6310422,6313001,6315577,6318145,6320782,6323412,6326010,6328576,6331171,6333769,6336394,6339008,6341629,6344207,6346738,6349346,6351926,6354520,6357115,6359726,6362294,6364934,6367511,6370123,6372758,6375329,6377931,6380537,6383125,6385749,6388316,6390927,6393565,6396155,6398759,6401308,6403893,6406443,6409019,6411620,6414239,6416839,6419443,6421984,6424584,6427174,6429773,6432351,6434904,6437477,6440083,6442693,6445292,6447929,6450523,6453110,6455681,6458325,6460916,6463537,6466170,6468740,6471303,6473881,6476473,6479074,6481718,6484299,6486894,6489471,6492069,6494655,6497313,6499922,6502518,6505096,6507691,6510278,6512872,6515450,6518113,6520674,6523258,6525867,6528443,6531065,6533689,6536272,6538886,6541469,6544020,6546671,6549284,6551863,6554451,6556995,6559586,6562187,6564769,6567410,6569950,6572573,6575115,6577699,6580259,6582891,6585455,6588086,6590707,6593325,6595956,6598514,6601070,6603685,6606272,6608833,6611497,6614094,6616697,6619294,6621893,6624417,6627011,6629604,6632210,6634762,6637326,6639846,6642443,6645042,6647597,6650123,6652722,6655350,6657922,6660524,6663027,6665669,6668207,6670803,6673401,6676024,6678602,6681237,6683805,6686330,6688965,6691554,6694116,6696710,6699328,6701945,6704526,6707199,6709794,6712366,6714982,6717598,6720188,6722793,6725390,6727967,6730546,6733133,6735694,6738206,6740827,6743393,6745967,6748551,6751152,6753723,6756298,6758909,6761488,6764061,6766665,6769184,6771774,6774394,6776964,6779496,6782075,6784633,6787248,6789786,6792399,6795030,6797653,6800238,6802809,6805405,6807998,6810600,6813191,6815769,6818373,6820938,6823538,6826056,6828647,6831223,6833808,6836378,6838974,6841544,6844145,6846742,6849309,6851865,6854426,6857052,6859665,6862300,6864927,6867490,6870030,6872596,6875181,6877736,6880326,6882923,6885470,6888049,6890594,6893239,6895823,6898360,6900908,6903507,6906085,6908591,6911193,6913798,6916350,6918937,6921531,6924152,6926759,6929344,6932009,6934557,6937121,6939698,6942265,6944832,6947432,6950047,6952621,6955228,6957810,6960446,6963002,6965623,6968228,6970813,6973373,6975907,6978552,6981141,6983700,6986302,6988894,6991451,6994052,6996635,6999238,7001826,7004385,7006942,7009508,7012091,7014636,7017246,7019910,7022467,7025100,7027732,7030311,7032872,7035445,7038005,7040536,7043118,7045743,7048341,7050887,7053482,7056062,7058670,7061273,7063884,7066486,7069098,7071648,7074207,7076793,7079413,7081991,7084584,7087181,7089729,7092252,7094828,7097377,7099974,7102559,7105135,7107733,7110340,7112922,7115504,7118104,7120686,7123328,7125908,7128528,7131103,7133675,7136260,7138850,7141411,7143962,7146531,7149098,7151677,7154305,7156894,7159501,7162171,7164743,7167290,7169861,7172476,7175069,7177686,7180298,7182858,7185446,7188009,7190542,7193110,7195724,7198305,7200836,7203409,7206025,7208622,7211220,7213776,7216338,7218921,7221466,7224117,7226695,7229223,7231834,7234447,7237073,7239660,7242247,7244830,7247437,7250009,7252623,7255178,7257776,7260341,7262871,7265455,7267969,7270544,7273094,7275707,7278250,7280850,7283409,7285993,7288559,7291114,7293744,7296315,7298847,7301441,7304017,7306654,7309179,7311704,7314292,7316886,7319530,7322111,7324658,7327259,7329880,7332441,7335021,7337603,7340209,7342738,7345279,7347816,7350377,7352944,7355503,7358024,7360614,7363209,7365831,7368428,7371012,7373604,7376144,7378731,7381275,7383810,7386364,7388932,7391501,7394031,7396641,7399244,7401865,7404456,7406981,7409537,7412101,7414690,7417287,7419883,7422440,7424988,7427521,7430100,7432638,7435215,7437739,7440293,7442911,7445515,7448113,7450683,7453260,7455840,7458444,7461026,7463634,7466197,7468786,7471319,7473929,7476551,7479117,7481640,7484263,7486780,7489341,7491951,7494520,7497062,7499687,7502253,7504814,7507391,7509987,7512552,7515086,7517706,7520307,7522823,7525391,7527944,7530542,7533104,7535699,7538259,7540803,7543417,7545942,7548534,7551129,7553728,7556312,7558843,7561434,7563979,7566504,7569079,7571640,7574169,7576782,7579337,7581896,7584421,7587021,7589576,7592150,7594704,7597275,7599793,7602389,7604972,7607618,7610136,7612747,7615268,7617857,7620415,7622959,7625548,7628195,7630752,7633276,7635833,7638353,7640909,7643495,7646120,7648659,7651278,7653832,7656430,7659010,7661579,7664133,7666611,7669192,7671775,7674355,7676914,7679487,7682030,7684594,7687145,7689730,7692292,7694860,7697418,7700030,7702573,7705204,7707782,7710347,7712917,7715473,7718027,7720596,7723206,7725777,7728304,7730888,7733441,7736037,7738640,7741177,7743669,7746198,7748765,7751406,7753966,7756539,7759094,7761685,7764212,7766792,7769378,7771904,7774460,7777034,7779544,7782118,7784670,7787225,7789833,7792384,7795027,7797626,7800193,7802757,7805345,7807902,7810458,7812999,7815576,7818154,7820760,7823284,7825841,7828444,7830987,7833549,7836166,7838713,7841311,7843889,7846421,7848884,7851433,7853999,7856582,7859171,7861775,7864363,7866908,7869477,7872017,7874590,7877130,7879767,7882313,7884850,7887427,7890023,7892631,7895232,7897843,7900428,7902974,7905545,7908065,7910581,7913124,7915727,7918311,7920912,7923469,7926036,7928633,7931210,7933765,7936280,7938827,7941377,7943901,7946431,7949031,7951601,7954216,7956759,7959315,7961867,7964450,7967002,7969566,7972123,7974693,7977292,7979865,7982412,7985017,7987568,7990127,7992721,7995265,7997860,8000393,8002934,8005472,8008046,8010614,8013199,8015752,8018322,8020861,8023412,8025982,8028498,8031029,8033582,8036157,8038757,8041399,8043965,8046481,8049028,8051590,8054131,8056747,8059304,8061848,8064376,8066943,8069507,8072032,8074667,8077205,8079781,8082322,8084913,8087509,8090091,8092567,8095134,8097677,8100188,8102725,8105255,8107766,8110336,8112935,8115466,8118010,8120630,8123160,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718,8125718};

int getAns(int x, int y) {
	int ret = 0;
	if (x <= 2 && y >= 2)
		++ret;
	memset(U, 0, sizeof U);
	int ans = 0;
	for (int i=x; i<=y; i++) {
		bool prime = false;
		if (!U[i-x]) {
			prime = true;
			for (int u=0; pr[u] * pr[u] <= i; u++) {
				if (i % pr[u] == 0) {
					prime = false;
					for (int j = i+pr[u]; j<104000; j+=pr[u])
						U[j-x] = true;
					break;
				}
			}
		}
		if (prime && i > 1 && (i % 4) == 1)
			++ret;
	}
	return ret;
}





int main() {

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	


	

	

	

	




	for (int i=1; i<3333; i++)
		nakop[i]++;


	


	for (int i=2; i<32000; i++) {
		if (!U1[i]) {
			pr[epr++] = i;
			for (int u=i*i; u<32000; u+=i)
				U1[u] = true;
		}
	}

	int a,b;
	cin >> a >> b;

	

	

	

	

	

	

	


	int y = nakop[b / 100000];
	y += getAns(b / 100000 * 100000 + 1, b);

	--a;
	int x = nakop[a / 100000];
	x += getAns(a / 100000 * 100000 + 1, a);

	cout << y - x << endl;

	return 0;
}
