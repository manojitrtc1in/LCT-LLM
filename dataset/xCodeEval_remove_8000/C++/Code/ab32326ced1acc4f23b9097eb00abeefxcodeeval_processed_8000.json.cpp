
















using namespace std;




















const int cnt[] = {0,4784,8978,12981,16901,20732,24523,28250,31916,35586,39176,42818,46430,49962,53516,57023,60523,64040,67489,70985,74417,77880,81285,84679,88056,91433,94878,98240,101609,104979,108284,111653,115039,118376,121695,124997,128271,131627,134912,138219,141503,144830,148121,151368,154619,157925,161166,164444,167675,170947,174194,177433,180617,183844,187049,190283,193493,196709,199900,203111,206333,209527,212732,215966,219123,222272,225464,228651,231844,235070,238261,241443,244581,247734,250868,253974,257141,260352,263482,266624,269760,272885,276014,279149,282271,285396,288556,291711,294878,297984,301101,304177,307326,310445,313579,316642,319813,322904,326007,329106,332181,335268,338394,341465,344551,347665,350739,353840,356909,360000,363080,366160,369262,372328,375439,378519,381635,384729,387818,390920,393993,397033,400087,403209,406289,409309,412334,415432,418499,421557,424569,427583,430661,433680,436753,439791,442818,445857,448901,451962,454974,457972,461016,464069,467135,470154,473178,476215,479251,482265,485275,488279,491293,494312,497242,500236,503252,506276,509308,512383,515414,518404,521398,524428,527422,530472,533469,536442,539450,542467,545501,548500,551461,554513,557494,560489,563514,566514,569509,572481,575503,578464,581445,584485,587448,590416,593357,596374,599365,602379,605357,608340,611346,614316,617284,620283,623219,626204,629187,632137,635171,638124,641088,644018,646968,649933,652929,655897,658857,661819,664771,667743,670676,673688,676670,679672,682577,685542,688504,691478,694491,697405,700327,703274,706181,709115,712114,715038,717989,720960,723896,726883,729831,732782,735740,738676,741606,744563,747458,750384,753319,756217,759188,762199,765151,768087,771012,773928,776896,779827,782754,785698,788611,791513,794449,797362,800286,803241,806180,809116,812028,814964,817869,820796,823752,826720,829643,832596,835498,838436,841364,844292,847194,850080,853022,855895,858875,861761,864672,867592,870514,873482,876358,879283,882186,885138,888023,890933,893858,896758,899686,902573,905461,908421,911332,914214,917110,920007,922881,925822,928781,931678,934604,937520,940453,943326,946296,949181,952088,955026,957871,960726,963624,966507,969407,972309,975197,978085,980962,983867,986746,989647,992538,995405,998272,1001142,1004047,1006935,1009828,1012698,1015620,1018497,1021407,1024321,1027185,1030064,1032962,1035803,1038722,1041665,1044521,1047338,1050175,1053074,1055897,1058799,1061676,1064500,1067388,1070268,1073174,1076029,1078884,1081790,1084692,1087554,1090413,1093331,1096221,1099056,1101903,1104801,1107645,1110568,1113425,1116309,1119226,1122066,1124941,1127772,1130652,1133559,1136476,1139334,1142195,1145026,1147867,1150738,1153592,1156490,1159339,1162245,1165140,1168043,1170911,1173747,1176591,1179444,1182370,1185244,1188094,1190926,1193801,1196660,1199546,1202432,1205285,1208198,1211026,1213868,1216688,1219588,1222393,1225259,1228119,1230996,1233830,1236682,1239605,1242422,1245272,1248112,1250996,1253792,1256652,1259537,1262363,1265205,1268048,1270890,1273689,1276507,1279377,1282287,1285127,1287980,1290771,1293580,1296434,1299249,1302081,1304899,1307765,1310566,1313437,1316314,1319179,1321953,1324799,1327680,1330570,1333417,1336222,1339091,1341881,1344730,1347558,1350403,1353253,1356098,1358925,1361746,1364529,1367411,1370267,1373089,1375934,1378788,1381608,1384448,1387240,1390062,1392850,1395709,1398555,1401374,1404179,1407069,1409899,1412745,1415626,1418381,1421272,1424100,1426913,1429776,1432595,1435430,1438258,1441129,1443939,1446779,1449605,1452384,1455248,1458083,1460921,1463729,1466529,1469369,1472195,1475031,1477838,1480667,1483501,1486323,1489166,1491981,1494788,1497648,1500453,1503239,1506082,1508873,1511687,1514528,1517367,1520184,1523011,1525806,1528622,1531402,1534201,1536998,1539895,1542683,1545503,1548241,1551093,1553884,1556702,1559565,1562352,1565117,1567943,1570716,1573536,1576359,1579176,1581960,1584772,1587542,1590356,1593212,1596006,1598783,1601564,1604387,1607165,1609974,1612824,1615617,1618452,1621217,1624007,1626767,1629636,1632422,1635222,1637991,1640857,1643718,1646485,1649297,1652064,1654854,1657620,1660460,1663265,1666081,1668892,1671700,1674594,1677356,1680125,1682936,1685691,1688539,1691341,1694101,1696863,1699639,1702441,1705278,1708111,1710912,1713725,1716510,1719267,1722096,1724880,1727671,1730436,1733218,1736052,1738807,1741642,1744421,1747205,1750008,1752772,1755538,1758337,1761093,1763839,1766647,1769444,1772247,1775046,1777876,1780671,1783464,1786236,1789019,1791841,1794680,1797448,1800275,1803074,1805871,1808648,1811416,1814143,1816933,1819707,1822528,1825244,1828005,1830793,1833548,1836360,1839214,1841997,1844792,1847581,1850328,1853089,1855856,1858663,1861433,1864207,1866992,1869796,1872540,1875345,1878117,1880879,1883647,1886490,1889297,1892075,1894867,1897680,1900521,1903296,1906070,1908797,1911589,1914346,1917129,1919906,1922737,1925489,1928318,1931029,1933873,1936618,1939421,1942196,1944975,1947727,1950518,1953327,1956076,1958882,1961653,1964430,1967232,1969999,1972724,1975510,1978238,1981017,1983809,1986618,1989438,1992205,1994950,1997722,2000489,2003304,2006033,2008816,2011607,2014374,2017180,2019933,2022703,2025513,2028256,2031020,2033803,2036610,2039323,2042136,2044905,2047682,2050502,2053230,2055971,2058719,2061484,2064276,2067036,2069780,2072561,2075349,2078104,2080845,2083584,2086330,2089097,2091865,2094672,2097407,2100185,2102972,2105738,2108433,2111259,2113990,2116784,2119527,2122304,2125069,2127838,2130619,2133419,2136173,2138962,2141713,2144481,2147172,2149925,2152702,2155443,2158237,2161008,2163758,2166537,2169247,2171965,2174706,2177470,2180269,2183018,2185806,2188547,2191332,2194100,2196835,2199596,2202324,2205083,2207861,2210669,2213445,2216182,2218953,2221739,2224515,2227246,2230006,2232708,2235482,2238231,2240991,2243756,2246481,2249228,2252025,2254788,2257554,2260312,2263079,2265828,2268545,2271246,2274003,2276736,2279484,2282217,2284983,2287747,2290512,2293240,2295997,2298703,2301494,2304178,2306931,2309704,2312444,2315163,2317910,2320691,2323417,2326186,2328943,2331677,2334374,2337139,2339871,2342642,2345411,2348164,2350887,2353608,2356373,2359139,2361873,2364678,2367432,2370149,2372878,2375651,2378388,2381162,2383896,2386653,2389450,2392222,2394902,2397618,2400363,2403099,2405857,2408603,2411351,2414127,2416904,2419628,2422296,2425056,2427745,2430503,2433251,2436001,2438719,2441528,2444352,2447016,2449765,2452482,2455256,2458031,2460744,2463429,2466187,2468912,2471679,2474403,2477113,2479832,2482617,2485400,2488154,2490869,2493631,2496331,2499026,2501804,2504528,2507234,2509986,2512726,2515473,2518176,2520876,2523614,2526330,2529122,2531839,2534604,2537308,2540008,2542791,2545541,2548284,2551055,2553802,2556546,2559257,2562021,2564750,2567511,2570148,2572929,2575664,2578404,2581128,2583837,2586615,2589384,2592090,2594819,2597536,2600254,2602944,2605706,2608394,2611086,2613806,2616565,2619322,2622048,2624788,2627470,2630206,2632916,2635613,2638344,2641068,2643874,2646581,2649274,2651923,2654664,2657389,2660089,2662840,2665564,2668329,2671039,2673789,2676540,2679254,2682014,2684761,2687515,2690185,2692884,2695614,2698331,2701068,2703798,2706497,2709174,2711871,2714585,2717374,2720152,2722854,2725559,2728236,2730938,2733698,2736447,2739146,2741927,2744682,2747379,2750078,2752811,2755522,2758290,2761026,2763725,2766426,2769153,2771910,2774617,2777363,2780032,2782759,2785459,2788181,2790935,2793661,2796375,2799109,2801844,2804531,2807261,2809930,2812655,2815400,2818088,2820817,2823539,2826276,2828967,2831690,2834417,2837100,2839799,2842571,2845296,2847956,2850686,2853362,2856131,2858814,2861495,2864215,2866912,2869650,2872353,2875061,2877771,2880505,2883226,2885940,2888662,2891324,2894042,2896737,2899482,2902173,2904857,2907606,2910319,2913026,2915749,2918453,2921165,2923834,2926597,2929265,2931966,2934703,2937423,2940118,2942868,2945636,2948312,2951035,2953764,2956447,2959193,2961881,2964616,2967240,2969938,2972638,2975367,2978051,2980755,2983431,2986123,2988902,2991612,2994331,2997075,2999799,3002504,3005203,3007900,3010598,3013324,3016010,3018743,3021417,3024129,3026843,3029542,3032258,3034938,3037647,3040327,3043023,3045754,3048458,3051170,3053831,3056533,3059268,3061963,3064626,3067352,3069997,3072756,3075490,3078186,3080941,3083637,3086305,3089049,3091767,3094461,3097083,3099791,3102503,3105214,3107929,3110676,3113377,3116121,3118822,3121506,3124226,3126914,3129664,3132389,3135041,3137800,3140465,3143179,3145896,3148595,3151359,3154060,3156704,3159381,3162038,3164764,3167422,3170165,3172860,3175583,3178276,3180981,3183679,3186337,3189067,3191741,3194439,3197144,3199905,3202633,3205350,3208093,3210816,3213514,3216212,3218845,3221531,3224234,3226985,3229664,3232326,3235040,3237756,3240412,3243108,3245793,3248448,3251142,3253794,3256465,3259119,3261786,3264499,3267184,3269881,3272566,3275208,3277990,3280684,3283348,3286023,3288733,3291422,3294158,3296809,3299512,3302209,3304882,3307587,3310219,3312951,3315658,3318341,3321024,3323750,3326372,3329060,3331730,3334388,3337067,3339778,3342473,3345126,3347848,3350545,3353226,3355956,3358631,3361303,3363969,3366670,3369387,3372104,3374797,3377477,3380176,3382885,3385555,3388181,3390855,3393551,3396270,3398959,3401658,3404348,3407022,3409749,3412425,3415112,3417799,3420476,3423164,3425804,3428513,3431140,3433831,3436495,3439209,3441873,3444597,3447272,3450005,3452685,3455326,3458010,3460716,3463433,3466044,3468740,3471402,3474095,3476807,3479443,3482094,3484813,3487498,3490171,3492861,3495568,3498297,3500974,3503652,3506387,3509080,3511783,3514444,3517154,3519835,3522520,3525176,3527909,3530582,3533256,3535969,3538668,3541338,3543979,3546667,3549376,3552022,3554739,3557385,3560090,3562780,3565457,3568117,3570777,3573441,3576162,3578838,3581527,3584202,3586899,3589608,3592224,3594895,3597609,3600285,3602937,3605599,3608315,3611057,3613719,3616375,3619063,3621779,3624438,3627138,3629813,3632494,3635172,3637897,3640547,3643225,3645882,3648522,3651242,3653950,3656685,3659419,3662084,3664727,3667446,3670105,3672775,3675493,3678173,3680848,3683590,3686168,3688866,3691503,3694149,3696775,3699495,3702151,3704779,3707476,3710195,3712862,3715571,3718229,3720907,3723622,3726327,3729014,3731697,3734399,3737058,3739687,3742387,3745052,3747736,3750447,3753093,3755763,3758470,3761125,3763798,3766488,3769102,3771838,3774512,3777097,3779799,3782495,3785161,3787804,3790455,3793101,3795810,3798471,3801142,3803841,3806533,3809252,3811893,3814570,3817240,3819899,3822594,3825304,3827949,3830626,3833257,3835966,3838551,3841206,3843893,3846531,3849184,3851821,3854488,3857123,3859809,3862541,3865213,3867908,3870566,3873197,3875855,3878498,3881127,3883820,3886491,3889196,3891882,3894548,3897254,3899883,3902461,3905110,3907779,3910369,3913051,3915712,3918400,3921049,3923696,3926401,3929085,3931738,3934443,3937079,3939772,3942498,3945191,3947875,3950555,3953194,3955921,3958645,3961298,3963906,3966568,3969211,3971880,3974536,3977155,3979753,3982460,3985072,3987720,3990416,3993127,3995735,3998438,4001109,4003807,4006464,4009128,4011827,4014469,4017140,4019846,4022481,4025096,4027765,4030424,4033095,4035734,4038441,4041068,4043777,4046464,4049122,4051770,4054425,4057114,4059771,4062452,4065124,4067794,4070476,4073177,4075821,4078473,4081177,4083782,4086435,4089090,4091774,4094421,4097099,4099748,4102417,4105057,4107702,4110357,4113050,4115722,4118386,4121052,4123728,4126380,4129050,4131700,4134353,4137024,4139686,4142364,4145061,4147677,4150324,4153011,4155686,4158364,4160967,4163597,4166236,4168923,4171606,4174224,4176870,4179522,4182183,4184850,4187489,4190141,4192812,4195422,4198063,4200732,4203355,4206045,4208687,4211357,4213982,4216686,4219357,4221986,4224628,4227283,4229915,4232565,4235233,4237862,4240503,4243170,4245785,4248402,4251066,4253702,4256360,4259015,4261662,4264294,4266922,4269625,4272264,4274957,4277598,4280203,4282798,4285399,4288065,4290688,4293351,4296021,4298654,4301295,4303983,4306609,4309218,4311887,4314529,4317235,4319923,4322593,4325295,4327913,4330591,4333234,4335879,4338516,4341144,4343802,4346451,4349053,4351735,4354389,4357049,4359663,4362342,4364926,4367588,4370299,4372936,4375553,4378193,4380845,4383575,4386240,4388879,4391542,4394200,4396851,4399521,4402187,4404833,4407487,4410086,4412694,4415371,4418023,4420721,4423372,4425992,4428609,4431243,4433902,4436580,4439171,4441823,4444490,4447138,4449673,4452308,4454923,4457555,4460241,4462895,4465544,4468140,4470785,4473457,4476148,4478750,4481417,4484077,4486724,4489312,4492007,4494652,4497293,4499966,4502619,4505253,4507857,4510573,4513194,4515919,4518560,4521186,4523774,4526427,4529073,4531709,4534347,4536968,4539594,4542204,4544861,4547524,4550197,4552844,4555492,4558141,4560804,4563438,4566061,4568706,4571337,4574015,4576657,4579285,4581977,4584687,4587326,4589993,4592654,4595266,4597877,4600572,4603202,4605818,4608469,4611140,4613737,4616385,4619006,4621593,4624232,4626877,4629508,4632187,4634797,4637399,4640031,4642678,4645360,4647919,4650560,4653231,4655889,4658587,4661191,4663804,4666452,4669055,4671705,4674351,4676997,4679633,4682243,4684949,4687533,4690161,4692790,4695463,4698103,4700735,4703363,4706007,4708643,4711274,4713900,4716608,4719202,4721853,4724481,4727184,4729855,4732496,4735168,4737851,4740486,4743083,4745721,4748368,4750950,4753627,4756290,4758913,4761562,4764205,4766823,4769431,4772013,4774673,4777297,4779967,4782597,4785263,4787905,4790546,4793167,4795770,4798436,4801064,4803669,4806333,4808985,4811623,4814267,4816891,4819529,4822161,4824805,4827436,4830058,4832685,4835379,4838000,4840681,4843322,4845982,4848640,4851212,4853838,4856492,4859128,4861763,4864389,4867028,4869676,4872296,4874854,4877529,4880180,4882798,4885427,4888079,4890747,4893365,4896011,4898673,4901286,4903891,4906512,4909157,4911785,4914384,4917033,4919691,4922306,4924919,4927573,4930213,4932818,4935488,4938140,4940775,4943379,4946070,4948680,4951297,4953911,4956558,4959210,4961878,4964538,4967185,4969806,4972410,4975039,4977663,4980311,4982941,4985647,4988226,4990899,4993516,4996145,4998802,5001443,5004057,5006709,5009406,5012065,5014695,5017340,5019950,5022572,5025179,5027802,5030447,5033048,5035681,5038281,5040863,5043508,5046095,5048767,5051412,5054025,5056629,5059278,5061913,5064512,5067205,5069826,5072492,5075114,5077659,5080257,5082860,5085500,5088135,5090728,5093333,5095989,5098616,5101203,5103826,5106459,5109090,5111744,5114362,5116968,5119591,5122214,5124845,5127515,5130154,5132783,5135431,5138076,5140731,5143346,5145981,5148607,5151275,5153900,5156547,5159150,5161734,5164342,5166955,5169574,5172232,5174885,5177522,5180107,5182724,5185364,5187966,5190596,5193213,5195881,5198500,5201126,5203797,5206415,5209050,5211713,5214289,5216846,5219488,5222091,5224741,5227387,5230075,5232642,5235256,5237883,5240497,5243171,5245787,5248349,5250964,5253605,5256295,5258925,5261560,5264198,5266812,5269432,5272057,5274679,5277359,5279981,5282588,5285176,5287825,5290379,5292984,5295576,5298144,5300709,5303300,5305966,5308565,5311160,5313783,5316423,5319019,5321597,5324214,5326785,5329410,5332022,5334623,5337228,5339869,5342497,5345130,5347796,5350422,5353090,5355703,5358368,5360987,5363545,5366148,5368777,5371412,5374088,5376687,5379310,5381929,5384562,5387172,5389785,5392412,5395047,5397629,5400260,5402887,5405527,5408176,5410794,5413434,5415999,5418615,5421235,5423862,5426485,5429133,5431730,5434360,5436989,5439576,5442164,5444785,5447430,5450050,5452630,5455226,5457874,5460458,5463064,5465637,5468292,5470840,5473438,5476040,5478624,5481234,5483862,5486493,5489062,5491685,5494277,5496930,5499560,5502195,5504849,5507484,5510039,5512631,5515229,5517813,5520451,5523148,5525740,5528354,5530960,5533526,5536136,5538821,5541485,5544171,5546787,5549334,5551962,5554594,5557156,5559794,5562401,5564989,5567669,5570318,5572922,5575559,5578173,5580736,5583348,5585968,5588600,5591257,5593883,5596538,5599126,5601766,5604343,5606978,5609544,5612150,5614796,5617364,5619974,5622605,5625220,5627890,5630521,5633085,5635731,5638332,5640958,5643587,5646179,5648777,5651328,5653955,5656616,5659238,5661891,5664467,5667110,5669725,5672315,5674898,5677516,5680112,5682698,5685284,5687873,5690537,5693139,5695725,5698355,5700962,5703597,5706173,5708794,5711418,5713948,5716608,5719236,5721870,5724432,5727030,5729670,5732292,5734927,5737555,5740151,5742760,5745303,5747922,5750484,5753110,5755700,5758284,5760903,5763489,5766103,5768742,5771330,5773921,5776526,5779099,5781662,5784324,5786983,5789590,5792263,5794904,5797482,5800089,5802685,5805349,5807963,5810588,5813145,5815758,5818376,5820930,5823533,5826127,5828742,5831424,5834055,5836688,5839332,5841894,5844529,5847110,5849741,5852352,5854947,5857519,5860154,5862786,5865406,5868021,5870662,5873256,5875845,5878521,5881140,5883729,5886329,5888952,5891561,5894167,5896792,5899352,5901946,5904577,5907199,5909823,5912400,5914980,5917583,5920157,5922796,5925412,5928032,5930672,5933314,5935941,5938528,5941165,5943778,5946380,5949001,5951601,5954206,5956845,5959490,5962107,5964740,5967358,5969954,5972551,5975142,5977742,5980359,5982940,5985529,5988135,5990733,5993379,5995956,5998501,6001091,6003727,6006283,6008887,6011523,6014159,6016757,6019333,6021859,6024475,6027082,6029692,6032264,6034853,6037496,6040041,6042691,6045300,6047914,6050499,6053126,6055662,6058266,6060852,6063464,6066107,6068705,6071358,6073902,6076513,6079117,6081676,6084293,6086846,6089462,6092066,6094754,6097313,6099890,6102471,6105114,6107733,6110282,6112891,6115533,6118146,6120762,6123306,6125905,6128580,6131219,6133813,6136360,6139005,6141600,6144218,6146820,6149371,6152008,6154675,6157271,6159872,6162461,6164976,6167591,6170169,6172803,6175450,6178055,6180645,6183213,6185805,6188462,6191134,6193761,6196339,6198883,6201446,6204006,6206615,6209209,6211825,6214485,6217047,6219685,6222252,6224828,6227426,6230025,6232618,6235254,6237904,6240569,6243137,6245745,6248383,6250968,6253594,6256157,6258704,6261229,6263772,6266353,6268950,6271545,6274153,6276725,6279295,6281850,6284431,6287080,6289703,6292248,6294880,6297458,6300083,6302647,6305225,6307854,6310424,6313002,6315579,6318147,6320783,6323414,6326011,6328577,6331172,6333770,6336395,6339009,6341630,6344208,6346739,6349347,6351927,6354521,6357116,6359727,6362296,6364935,6367512,6370125,6372759,6375330,6377932,6380538,6383126,6385751,6388317,6390928,6393566,6396156,6398760,6401310,6403894,6406444,6409020,6411621,6414240,6416841,6419444,6421985,6424585,6427175,6429774,6432352,6434905,6437478,6440085,6442694,6445293,6447930,6450525,6453111,6455682,6458326,6460917,6463538,6466171,6468741,6471304,6473883,6476474,6479075,6481719,6484300,6486896,6489472,6492070,6494656,6497315,6499923,6502519,6505098,6507692,6510279,6512873,6515451,6518114,6520675,6523259,6525868,6528444,6531066,6533690,6536274,6538887,6541471,6544022,6546672,6549285,6551865,6554452,6556996,6559587,6562188,6564770,6567411,6569951,6572574,6575116,6577700,6580260,6582893,6585456,6588088,6590709,6593326,6595957,6598516,6601071,6603687,6606273,6608834,6611498,6614095,6616698,6619296,6621895,6624418,6627012,6629605,6632211,6634763,6637327,6639847,6642445,6645043,6647598,6650124,6652723,6655351,6657923,6660525,6663028,6665670,6668208,6670804,6673402,6676025,6678603,6681238,6683806,6686331,6688966,6691555,6694117,6696711,6699329,6701946,6704527,6707200,6709795,6712368,6714984,6717599,6720189,6722794,6725391,6727968,6730547,6733134,6735695,6738207,6740828,6743394,6745968,6748552,6751153,6753724,6756299,6758910,6761490,6764062,6766667,6769185,6771775,6774395,6776965,6779497,6782076,6784634,6787249,6789788,6792400,6795031,6797655,6800239,6802810,6805406,6808000,6810601,6813192,6815771,6818374,6820939,6823539,6826057,6828648,6831224,6833809,6836379,6838975,6841545,6844146,6846743,6849310,6851866,6854427,6857053,6859667,6862301,6864928,6867492,6870031,6872597,6875182,6877738,6880327,6882924,6885471,6888050,6890595,6893241,6895824,6898362,6900909,6903508,6906087,6908593,6911194,6913799,6916351,6918938,6921532,6924153,6926760,6929345,6932010,6934558,6937122,6939699,6942266,6944833,6947433,6950048,6952623,6955229,6957811,6960447,6963004,6965624,6968230,6970814,6973374,6975908,6978553,6981142,6983702,6986304,6988895,6991452,6994054,6996636,6999239,7001827,7004386,7006944,7009509,7012092,7014637,7017248,7019911,7022468,7025102,7027733,7030313,7032873,7035446,7038006,7040537,7043119,7045744,7048342,7050888,7053483,7056064,7058671,7061274,7063885,7066487,7069099,7071649,7074208,7076794,7079415,7081992,7084585,7087182,7089730,7092253,7094829,7097378,7099975,7102560,7105136,7107734,7110341,7112923,7115505,7118105,7120687,7123329,7125909,7128529,7131104,7133677,7136261,7138851,7141412,7143963,7146532,7149099,7151678,7154306,7156895,7159502,7162172,7164744,7167291,7169862,7172477,7175070,7177687,7180299,7182859,7185448,7188010,7190543,7193111,7195725,7198306,7200838,7203410,7206026,7208623,7211221,7213777,7216340,7218922,7221467,7224118,7226696,7229224,7231835,7234448,7237074,7239661,7242248,7244831,7247439,7250010,7252624,7255179,7257777,7260342,7262872,7265457,7267970,7270545,7273095,7275708,7278251,7280851,7283410,7285994,7288560,7291115,7293746,7296316,7298848,7301442,7304019,7306655,7309180,7311705,7314293,7316887,7319531,7322112,7324659,7327260,7329881,7332442,7335022,7337604,7340210,7342740,7345280,7347817,7350379,7352945,7355504,7358026,7360615,7363210,7365832,7368429,7371013,7373605,7376145,7378732,7381277,7383811,7386365,7388933,7391502,7394032,7396642,7399245,7401866,7404457,7406982,7409538,7412102,7414691,7417288,7419884,7422441,7424989,7427522,7430101,7432639,7435216,7437740,7440294,7442912,7445516,7448115,7450684,7453261,7455841,7458445,7461027,7463635,7466198,7468787,7471320,7473930,7476552,7479118,7481641,7484264,7486781,7489342,7491952,7494521,7497063,7499688,7502254,7504816,7507392,7509988,7512553,7515087,7517707,7520308,7522824,7525392,7527946,7530543,7533105,7535700,7538260,7540804,7543418,7545943,7548536,7551130,7553729,7556314,7558845,7561435,7563980,7566505,7569080,7571641,7574170,7576783,7579338,7581898,7584422,7587022,7589578,7592151,7594705,7597276,7599794,7602390,7604973,7607619,7610137,7612748,7615269,7617858,7620416,7622960,7625549,7628196,7630753,7633278,7635835,7638354,7640910,7643496,7646121,7648661,7651280,7653833,7656431,7659011,7661580,7664134,7666612,7669193,7671776,7674356,7676915,7679489,7682031,7684595,7687146,7689731,7692293,7694861,7697419,7700031,7702574,7705205,7707783,7710348,7712918,7715474,7718028,7720597,7723207,7725778,7728305,7730889,7733442,7736039,7738641,7741178,7743671,7746199,7748766,7751408,7753967,7756540,7759096,7761686,7764214,7766793,7769379,7771905,7774461,7777035,7779545,7782119,7784671,7787226,7789834,7792385,7795029,7797627,7800194,7802758,7805346,7807903,7810460,7813000,7815577,7818156,7820761,7823285,7825842,7828445,7830988,7833550,7836167,7838714,7841312,7843891,7846422,7848885,7851434,7854000,7856583,7859172,7861776,7864364,7866910,7869478,7872018,7874591,7877131,7879768,7882314,7884851,7887429,7890024,7892632,7895233,7897844,7900429,7902975,7905547,7908066,7910582,7913125,7915728,7918313,7920913,7923470,7926038,7928634,7931211,7933766,7936282,7938828,7941378,7943903,7946432,7949033,7951602,7954217,7956761,7959317,7961868,7964451,7967003,7969567,7972124,7974694,7977293,7979867,7982413,7985018,7987570,7990128,7992722,7995266,7997861,8000394,8002936,8005473,8008047,8010615,8013200,8015753,8018323,8020863,8023413,8025983,8028499,8031030,8033583,8036158,8038758,8041400,8043966,8046482,8049029,8051591,8054132,8056748,8059305,8061849,8064377,8066944,8069508,8072033,8074668,8077206,8079782,8082324,8084914,8087510,8090092,8092568,8095136,8097678,8100189,8102727,8105256,8107767,8110337,8112936,8115467,8118011,8120631,8123161,8125719};

int a,b,c,d,i,j,n,m,k;

inline int solve(int a) {
	if (a < 2) return 0;
	int num = (a - 1) / 100000;
	int ans = cnt[num];
	FOR(i, num * 100000 + 2, a) {
		if (i == 2) ++ans;
		if (i % 4 != 1) continue;
		++ans;
		for (int j = 3; j * j <= i; j += 2) {
			if (i % j == 0) {
				--ans;
				break;
			}
		}
	}
	return ans;
}
int main()
{
	

	

	scanf("%d%d",&a,&b);
	printf("%d\n", solve(b) - solve(a - 1));
}
