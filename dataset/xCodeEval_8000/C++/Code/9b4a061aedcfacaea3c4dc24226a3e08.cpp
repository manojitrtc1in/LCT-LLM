    
    #include <cstdio>
    #include <algorithm>
    #include <cstring>
    #include <string>
    #include <cmath>
    #define ll long long
    using namespace std;
     
    const int N = 1e7+7;
    int n,cas,k;
    ll a[] = {0,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63,65,67,69,71,73,75,77,79,81,83,85,87,89,91,93,95,97,99,101,103,105,107,109,111,113,115,117,119,121,123,125,127,129,131,133,135,137,139,141,143,145,147,149,151,153,155,157,159,161,163,165,167,169,171,173,175,177,179,181,183,185,187,189,191,193,195,197,199,201,203,205,207,209,211,213,215,217,219,221,223,225,227,229,231,233,235,237,239,241,243,245,247,249,251,253,255,257,259,261,263,265,267,269,271,273,275,277,279,281,283,285,287,289,291,293,295,297,299,301,303,305,307,309,311,313,315,317,319,321,323,325,327,329,331,333,335,337,339,341,343,345,347,349,351,353,355,357,359,361,363,365,367,369,371,373,375,377,379,381,383,385,387,389,391,393,395,397,399,401,403,405,407,409,411,413,415,417,419,421,423,425,427,429,431,433,435,437,439,441,443,445,447,449,451,453,455,457,459,461,463,465,467,469,471,473,475,477,479,481,483,485,487,489,491,493,495,497,499,501,503,505,507,509,511,513,515,517,519,521,523,525,527,529,531,533,535,537,539,541,543,545,547,549,551,553,555,557,559,561,563,565,567,569,571,573,575,577,579,581,583,585,587,589,591,593,595,597,599,601,603,605,607,609,611,613,615,617,619,621,623,625,627,629,631,633,635,637,639,641,643,645,647,649,651,653,655,657,659,661,663,665,667,669,671,673,675,677,679,681,683,685,687,689,691,693,695,697,699,701,703,705,707,709,711,713,715,717,719,721,723,725,727,729,731,733,735,737,739,741,743,745,747,749,751,753,755,757,759,761,763,765,767,769,771,773,775,777,779,781,783,785,787,789,791,793,795,797,799,801,803,805,807,809,811,813,815,817,819,821,823,825,827,829,831,833,835,837,839,841,843,845,847,849,851,853,855,857,859,861,863,865,867,869,871,873,875,877,879,881,883,885,887,889,891,893,895,897,899,901,903,905,907,909,911,913,915,917,919,921,923,925,927,929,931,933,935,937,939,941,943,945,947,949,951,953,955,957,959,961,963,965,967,969,971,973,975,977,979,981,983,985,987,989,991,993,995,997,999,1001,1003,1005,1007,1009,1011,1013,1015,1017,1019,1021,1023,1025,1027,1029,1031,1033,1035,1037,1039,1041,1043,1045,1047,1049,1051,1053,1055,1057,1059,1061,1063,1065,1067,1069,1071,1073,1075,1077,1079,1081,1083,1085,1087,1089,1091,1093,1095,1097,1099,1101,1103,1105,1107,1109,1111,1113,1115,1117,1119,1121,1123,1125,1127,1129,1131,1133,1135,1137,1139,1141,1143,1145,1147,1149,1151,1153,1155,1157,1159,1161,1163,1165,1167,1169,1171,1173,1175,1177,1179,1181,1183,1185,1187,1189,1191,1193,1195,1197,1199,1201,1203,1205,1207,1209,1211,1213,1215,1217,1219,1221,1223,1225,1227,1229,1231,1233,1235,1237,1239,1241,1243,1245,1247,1249,1251,1253,1255,1257,1259,1261,1263,1265,1267,1269,1271,1273,1275,1277,1279,1281,1283,1285,1287,1289,1291,1293,1295,1297,1299,1301,1303,1305,1307,1309,1311,1313,1315,1317,1319,1321,1323,1325,1327,1329,1331,1333,1335,1337,1339,1341,1343,1345,1347,1349,1351,1353,1355,1357,1359,1361,1363,1365,1367,1369,1371,1373,1375,1377,1379,1381,1383,1385,1387,1389,1391,1393,1395,1397,1399,1401,1403,1405,1407,1409,1411,1413,1415,1417,1419,1421,1423,1425,1427,1429,1431,1433,1435,1437,1439,1441,1443,1445,1447,1449,1451,1453,1455,1457,1459,1461,1463,1465,1467,1469,1471,1473,1475,1477,1479,1481,1483,1485,1487,1489,1491,1493,1495,1497,1499,1501,1503,1505,1507,1509,1511,1513,1515,1517,1519,1521,1523,1525,1527,1529,1531,1533,1535,1537,1539,1541,1543,1545,1547,1549,1551,1553,1555,1557,1559,1561,1563,1565,1567,1569,1571,1573,1575,1577,1579,1581,1583,1585,1587,1589,1591,1593,1595,1597,1599,1601,1603,1605,1607,1609,1611,1613,1615,1617,1619,1621,1623,1625,1627,1629,1631,1633,1635,1637,1639,1641,1643,1645,1647,1649,1651,1653,1655,1657,1659,1661,1663,1665,1667,1669,1671,1673,1675,1677,1679,1681,1683,1685,1687,1689,1691,1693,1695,1697,1699,1701,1703,1705,1707,1709,1711,1713,1715,1717,1719,1721,1723,1725,1727,1729,1731,1733,1735,1737,1739,1741,1743,1745,1747,1749,1751,1753,1755,1757,1759,1761,1763,1765,1767,1769,1771,1773,1775,1777,1779,1781,1783,1785,1787,1789,1791,1793,1795,1797,1799,1801,1803,1805,1807,1809,1811,1813,1815,1817,1819,1821,1823,1825,1827,1829,1831,1833,1835,1837,1839,1841,1843,1845,1847,1849,1851,1853,1855,1857,1859,1861,1863,1865,1867,1869,1871,1873,1875,1877,1879,1881,1883,1885,1887,1889,1891,1893,1895,1897,1899,1901,1903,1905,1907,1909,1911,1913,1915,1917,1919,1921,1923,1925,1927,1929,1931,1933,1935,1937,1939,1941,1943,1945,1947,1949,1951,1953,1955,1957,1959,1961,1963,1965,1967,1969,1971,1973,1975,1977,1979,1981,1983,1985,1987,1989,1991,1993,1995,1997,1999,2001,2003,2005,2007,2009,2011,2013,2015,2017,2019,2021,2023,2025,2027,2029,2031,2033,2035,2037,2039,2041,2043,2045,2047,2049,2051,2053,2055,2057,2059,2061,2063,2065,2067,2069,2071,2073,2075,2077,2079,2081,2083,2085,2087,2089,2091,2093,2095,2097,2099,2101,2103,2105,2107,2109,2111,2113,2115,2117,2119,2121,2123,2125,2127,2129,2131,2133,2135,2137,2139,2141,2143,2145,2147,2149,2151,2153,2155,2157,2159,2161,2163,2165,2167,2169,2171,2173,2175,2177,2179,2181,2183,2185,2187,2189,2191,2193,2195,2197,2199,2201,2203,2205,2207,2209,2211,2213,2215,2217,2219,2221,2223,2225,2227,2229,2231,2233,2235,2237,2239,2241,2243,2245,2247,2249,2251,2253,2255,2257,2259,2261,2263,2265,2267,2269,2271,2273,2275,2277,2279,2281,2283,2285,2287,2289,2291,2293,2295,2297,2299,2301,2303,2305,2307,2309,2311,2313,2315,2317,2319,2321,2323,2325,2327,2329,2331,2333,2335,2337,2339,2341,2343,2345,2347,2349,2351,2353,2355,2357,2359,2361,2363,2365,2367,2369,2371,2373,2375,2377,2379,2381,2383,2385,2387,2389,2391,2393,2395,2397,2399,2401,2403,2405,2407,2409,2411,2413,2415,2417,2419,2421,2423,2425,2427,2429,2431,2433,2435,2437,2439,2441,2443,2445,2447,2449,2451,2453,2455,2457,2459,2461,2463,2465,2467,2469,2471,2473,2475,2477,2479,2481,2483,2485,2487,2489,2491,2493,2495,2497,2499,2501,2503,2505,2507,2509,2511,2513,2515,2517,2519,2521,2523,2525,2527,2529,2531,2533,2535,2537,2539,2541,2543,2545,2547,2549,2551,2553,2555,2557,2559,2561,2563,2565,2567,2569,2571,2573,2575,2577,2579,2581,2583,2585,2587,2589,2591,2593,2595,2597,2599,2601,2603,2605,2607,2609,2611,2613,2615,2617,2619,2621,2623,2625,2627,2629,2631,2633,2635,2637,2639,2641,2643,2645,2647,2649,2651,2653,2655,2657,2659,2661,2663,2665,2667,2669,2671,2673,2675,2677,2679,2681,2683,2685,2687,2689,2691,2693,2695,2697,2699,2701,2703,2705,2707,2709,2711,2713,2715,2717,2719,2721,2723,2725,2727,2729,2731,2733,2735,2737,2739,2741,2743,2745,2747,2749,2751,2753,2755,2757,2759,2761,2763,2765,2767,2769,2771,2773,2775,2777,2779,2781,2783,2785,2787,2789,2791,2793,2795,2797,2799,2801,2803,2805,2807,2809,2811,2813,2815,2817,2819,2821,2823,2825,2827,2829,2831,2833,2835,2837,2839,2841,2843,2845,2847,2849,2851,2853,2855,2857,2859,2861,2863,2865,2867,2869,2871,2873,2875,2877,2879,2881,2883,2885,2887,2889,2891,2893,2895,2897,2899,2901,2903,2905,2907,2909,2911,2913,2915,2917,2919,2921,2923,2925,2927,2929,2931,2933,2935,2937,2939,2941,2943,2945,2947,2949,2951,2953,2955,2957,2959,2961,2963,2965,2967,2969,2971,2973,2975,2977,2979,2981,2983,2985,2987,2989,2991,2993,2995,2997,2999,3001,3003,3005,3007,3009,3011,3013,3015,3017,3019,3021,3023,3025,3027,3029,3031,3033,3035,3037,3039,3041,3043,3045,3047,3049,3051,3053,3055,3057,3059,3061,3063,3065,3067,3069,3071,3073,3075,3077,3079,3081,3083,3085,3087,3089,3091,3093,3095,3097,3099,3101,3103,3105,3107,3109,3111,3113,3115,3117,3119,3121,3123,3125,3127,3129,3131,3133,3135,3137,3139,3141,3143,3145,3147,3149,3151,3153,3155,3157,3159,3161,3163,3165,3167,3169,3171,3173,3175,3177,3179,3181,3183,3185,3187,3189,3191,3193,3195,3197,3199,3201,3203,3205,3207,3209,3211,3213,3215,3217,3219,3221,3223,3225,3227,3229,3231,3233,3235,3237,3239,3241,3243,3245,3247,3249,3251,3253,3255,3257,3259,3261,3263,3265,3267,3269,3271,3273,3275,3277,3279,3281,3283,3285,3287,3289,3291,3293,3295,3297,3299,3301,3303,3305,3307,3309,3311,3313,3315,3317,3319,3321,3323,3325,3327,3329,3331,3333,3335,3337,3339,3341,3343,3345,3347,3349,3351,3353,3355,3357,3359,3361,3363,3365,3367,3369,3371,3373,3375,3377,3379,3381,3383,3385,3387,3389,3391,3393,3395,3397,3399,3401,3403,3405,3407,3409,3411,3413,3415,3417,3419,3421,3423,3425,3427,3429,3431,3433,3435,3437,3439,3441,3443,3445,3447,3449,3451,3453,3455,3457,3459,3461,3463,3465,3467,3469,3471,3473,3475,3477,3479,3481,3483,3485,3487,3489,3491,3493,3495,3497,3499,3501,3503,3505,3507,3509,3511,3513,3515,3517,3519,3521,3523,3525,3527,3529,3531,3533,3535,3537,3539,3541,3543,3545,3547,3549,3551,3553,3555,3557,3559,3561,3563,3565,3567,3569,3571,3573,3575,3577,3579,3581,3583,3585,3587,3589,3591,3593,3595,3597,3599,3601,3603,3605,3607,3609,3611,3613,3615,3617,3619,3621,3623,3625,3627,3629,3631,3633,3635,3637,3639,3641,3643,3645,3647,3649,3651,3653,3655,3657,3659,3661,3663,3665,3667,3669,3671,3673,3675,3677,3679,3681,3683,3685,3687,3689,3691,3693,3695,3697,3699,3701,3703,3705,3707,3709,3711,3713,3715,3717,3719,3721,3723,3725,3727,3729,3731,3733,3735,3737,3739,3741,3743,3745,3747,3749,3751,3753,3755,3757,3759,3761,3763,3765,3767,3769,3771,3773,3775,3777,3779,3781,3783,3785,3787,3789,3791,3793,3795,3797,3799,3801,3803,3805,3807,3809,3811,3813,3815,3817,3819,3821,3823,3825,3827,3829,3831,3833,3835,3837,3839,3841,3843,3845,3847,3849,3851,3853,3855,3857,3859,3861,3863,3865,3867,3869,3871,3873,3875,3877,3879,3881,3883,3885,3887,3889,3891,3893,3895,3897,3899,3901,3903,3905,3907,3909,3911,3913,3915,3917,3919,3921,3923,3925,3927,3929,3931,3933,3935,3937,3939,3941,3943,3945,3947,3949,3951,3953,3955,3957,3959,3961,3963,3965,3967,3969,3971,3973,3975,3977,3979,3981,3983,3985,3987,3989,3991,3993,3995,3997,3999,4001,4003,4005,4007,4009,4011,4013,4015,4017,4019,4021,4023,4025,4027,4029,4031,4033,4035,4037,4039,4041,4043,4045,4047,4049,4051,4053,4055,4057,4059,4061,4063,4065,4067,4069,4071,4073,4075,4077,4079,4081,4083,4085,4087,4089,4091,4093,4095,4097,4099,4101,4103,4105,4107,4109,4111,4113,4115,4117,4119,4121,4123,4125,4127,4129,4131,4133,4135,4137,4139,4141,4143,4145,4147,4149,4151,4153,4155,4157,4159,4161,4163,4165,4167,4169,4171,4173,4175,4177,4179,4181,4183,4185,4187,4189,4191,4193,4195,4197,4199,4201,4203,4205,4207,4209,4211,4213,4215,4217,4219,4221,4223,4225,4227,4229,4231,4233,4235,4237,4239,4241,4243,4245,4247,4249,4251,4253,4255,4257,4259,4261,4263,4265,4267,4269,4271,4273,4275,4277,4279,4281,4283,4285,4287,4289,4291,4293,4295,4297,4299,4301,4303,4305,4307,4309,4311,4313,4315,4317,4319,4321,4323,4325,4327,4329,4331,4333,4335,4337,4339,4341,4343,4345,4347,4349,4351,4353,4355,4357,4359,4361,4363,4365,4367,4369,4371,4373,4375,4377,4379,4381,4383,4385,4387,4389,4391,4393,4395,4397,4399,4401,4403,4405,4407,4409,4411,4413,4415,4417,4419,4421,4423,4425,4427,4429,4431,4433,4435,4437,4439,4441,4443,4445,4447,4449,4451,4453,4455,4457,4459,4461,4463,4465,4467,4469,4471,4473,4475,4477,4479,4481,4483,4485,4487,4489,4491,4493,4495,4497,4499,4501,4503,4505,4507,4509,4511,4513,4515,4517,4519,4521,4523,4525,4527,4529,4531,4533,4535,4537,4539,4541,4543,4545,4547,4549,4551,4553,4555,4557,4559,4561,4563,4565,4567,4569,4571,4573,4575,4577,4579,4581,4583,4585,4587,4589,4591,4593,4595,4597,4599,4601,4603,4605,4607,4609,4611,4613,4615,4617,4619,4621,4623,4625,4627,4629,4631,4633,4635,4637,4639,4641,4643,4645,4647,4649,4651,4653,4655,4657,4659,4661,4663,4665,4667,4669,4671,4673,4675,4677,4679,4681,4683,4685,4687,4689,4691,4693,4695,4697,4699,4701,4703,4705,4707,4709,4711,4713,4715,4717,4719,4721,4723,4725,4727,4729,4731,4733,4735,4737,4739,4741,4743,4745,4747,4749,4751,4753,4755,4757,4759,4761,4763,4765,4767,4769,4771,4773,4775,4777,4779,4781,4783,4785,4787,4789,4791,4793,4795,4797,4799,4801,4803,4805,4807,4809,4811,4813,4815,4817,4819,4821,4823,4825,4827,4829,4831,4833,4835,4837,4839,4841,4843,4845,4847,4849,4851,4853,4855,4857,4859,4861,4863,4865,4867,4869,4871,4873,4875,4877,4879,4881,4883,4885,4887,4889,4891,4893,4895,4897,4899,4901,4903,4905,4907,4909,4911,4913,4915,4917,4919,4921,4923,4925,4927,4929,4931,4933,4935,4937,4939,4941,4943,4945,4947,4949,4951,4953,4955,4957,4959,4961,4963,4965,4967,4969,4971,4973,4975,4977,4979,4981,4983,4985,4987,4989,4991,4993,4995,4997,4999,5001,5003,5005,5007,5009,5011,5013,5015,5017,5019,5021,5023,5025,5027,5029,5031,5033,5035,5037,5039,5041,5043,5045,5047,5049,5051,5053,5055,5057,5059,5061,5063,5065,5067,5069,5071,5073,5075,5077,5079,5081,5083,5085,5087,5089,5091,5093,5095,5097,5099,5101,5103,5105,5107,5109,5111,5113,5115,5117,5119,5121,5123,5125,5127,5129,5131,5133,5135,5137,5139,5141,5143,5145,5147,5149,5151,5153,5155,5157,5159,5161,5163,5165,5167,5169,5171,5173,5175,5177,5179,5181,5183,5185,5187,5189,5191,5193,5195,5197,5199,5201,5203,5205,5207,5209,5211,5213,5215,5217,5219,5221,5223,5225,5227,5229,5231,5233,5235,5237,5239,5241,5243,5245,5247,5249,5251,5253,5255,5257,5259,5261,5263,5265,5267,5269,5271,5273,5275,5277,5279,5281,5283,5285,5287,5289,5291,5293,5295,5297,5299,5301,5303,5305,5307,5309,5311,5313,5315,5317,5319,5321,5323,5325,5327,5329,5331,5333,5335,5337,5339,5341,5343,5345,5347,5349,5351,5353,5355,5357,5359,5361,5363,5365,5367,5369,5371,5373,5375,5377,5379,5381,5383,5385,5387,5389,5391,5393,5395,5397,5399,5401,5403,5405,5407,5409,5411,5413,5415,5417,5419,5421,5423,5425,5427,5429,5431,5433,5435,5437,5439,5441,5443,5445,5447,5449,5451,5453,5455,5457,5459,5461,5463,5465,5467,5469,5471,5473,5475,5477,5479,5481,5483,5485,5487,5489,5491,5493,5495,5497,5499,5501,5503,5505,5507,5509,5511,5513,5515,5517,5519,5521,5523,5525,5527,5529,5531,5533,5535,5537,5539,5541,5543,5545,5547,5549,5551,5553,5555,5557,5559,5561,5563,5565,5567,5569,5571,5573,5575,5577,5579,5581,5583,5585,5587,5589,5591,5593,5595,5597,5599,5601,5603,5605,5607,5609,5611,5613,5615,5617,5619,5621,5623,5625,5627,5629,5631,5633,5635,5637,5639,5641,5643,5645,5647,5649,5651,5653,5655,5657,5659,5661,5663,5665,5667,5669,5671,5673,5675,5677,5679,5681,5683,5685,5687,5689,5691,5693,5695,5697,5699,5701,5703,5705,5707,5709,5711,5713,5715,5717,5719,5721,5723,5725,5727,5729,5731,5733,5735,5737,5739,5741,5743,5745,5747,5749,5751,5753,5755,5757,5759,5761,5763,5765,5767,5769,5771,5773,5775,5777,5779,5781,5783,5785,5787,5789,5791,5793,5795,5797,5799,5801,5803,5805,5807,5809,5811,5813,5815,5817,5819,5821,5823,5825,5827,5829,5831,5833,5835,5837,5839,5841,5843,5845,5847,5849,5851,5853,5855,5857,5859,5861,5863,5865,5867,5869,5871,5873,5875,5877,5879,5881,5883,5885,5887,5889,5891,5893,5895,5897,5899,5901,5903,5905,5907,5909,5911,5913,5915,5917,5919,5921,5923,5925,5927,5929,5931,5933,5935,5937,5939,5941,5943,5945,5947,5949,5951,5953,5955,5957,5959,5961,5963,5965,5967,5969,5971,5973,5975,5977,5979,5981,5983,5985,5987,5989,5991,5993,5995,5997,5999,6001,6003,6005,6007,6009,6011,6013,6015,6017,6019,6021,6023,6025,6027,6029,6031,6033,6035,6037,6039,6041,6043,6045,6047,6049,6051,6053,6055,6057,6059,6061,6063,6065,6067,6069,6071,6073,6075,6077,6079,6081,6083,6085,6087,6089,6091,6093,6095,6097,6099,6101,6103,6105,6107,6109,6111,6113,6115,6117,6119,6121,6123,6125,6127,6129,6131,6133,6135,6137,6139,6141,6143,6145,6147,6149,6151,6153,6155,6157,6159,6161,6163,6165,6167,6169,6171,6173,6175,6177,6179,6181,6183,6185,6187,6189,6191,6193,6195,6197,6199,6201,6203,6205,6207,6209,6211,6213,6215,6217,6219,6221,6223,6225,6227,6229,6231,6233,6235,6237,6239,6241,6243,6245,6247,6249,6251,6253,6255,6257,6259,6261,6263,6265,6267,6269,6271,6273,6275,6277,6279,6281,6283,6285,6287,6289,6291,6293,6295,6297,6299,6301,6303,6305,6307,6309,6311,6313,6315,6317,6319,6321,6323,6325};
	ll s[] ={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,1849,1936,2025,2116,2209,2304,2401,2500,2601,2704,2809,2916,3025,3136,3249,3364,3481,3600,3721,3844,3969,4096,4225,4356,4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,6241,6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,8281,8464,8649,8836,9025,9216,9409,9604,9801,10000,10201,10404,10609,10816,11025,11236,11449,11664,11881,12100,12321,12544,12769,12996,13225,13456,13689,13924,14161,14400,14641,14884,15129,15376,15625,15876,16129,16384,16641,16900,17161,17424,17689,17956,18225,18496,18769,19044,19321,19600,19881,20164,20449,20736,21025,21316,21609,21904,22201,22500,22801,23104,23409,23716,24025,24336,24649,24964,25281,25600,25921,26244,26569,26896,27225,27556,27889,28224,28561,28900,29241,29584,29929,30276,30625,30976,31329,31684,32041,32400,32761,33124,33489,33856,34225,34596,34969,35344,35721,36100,36481,36864,37249,37636,38025,38416,38809,39204,39601,40000,40401,40804,41209,41616,42025,42436,42849,43264,43681,44100,44521,44944,45369,45796,46225,46656,47089,47524,47961,48400,48841,49284,49729,50176,50625,51076,51529,51984,52441,52900,53361,53824,54289,54756,55225,55696,56169,56644,57121,57600,58081,58564,59049,59536,60025,60516,61009,61504,62001,62500,63001,63504,64009,64516,65025,65536,66049,66564,67081,67600,68121,68644,69169,69696,70225,70756,71289,71824,72361,72900,73441,73984,74529,75076,75625,76176,76729,77284,77841,78400,78961,79524,80089,80656,81225,81796,82369,82944,83521,84100,84681,85264,85849,86436,87025,87616,88209,88804,89401,90000,90601,91204,91809,92416,93025,93636,94249,94864,95481,96100,96721,97344,97969,98596,99225,99856,100489,101124,101761,102400,103041,103684,104329,104976,105625,106276,106929,107584,108241,108900,109561,110224,110889,111556,112225,112896,113569,114244,114921,115600,116281,116964,117649,118336,119025,119716,120409,121104,121801,122500,123201,123904,124609,125316,126025,126736,127449,128164,128881,129600,130321,131044,131769,132496,133225,133956,134689,135424,136161,136900,137641,138384,139129,139876,140625,141376,142129,142884,143641,144400,145161,145924,146689,147456,148225,148996,149769,150544,151321,152100,152881,153664,154449,155236,156025,156816,157609,158404,159201,160000,160801,161604,162409,163216,164025,164836,165649,166464,167281,168100,168921,169744,170569,171396,172225,173056,173889,174724,175561,176400,177241,178084,178929,179776,180625,181476,182329,183184,184041,184900,185761,186624,187489,188356,189225,190096,190969,191844,192721,193600,194481,195364,196249,197136,198025,198916,199809,200704,201601,202500,203401,204304,205209,206116,207025,207936,208849,209764,210681,211600,212521,213444,214369,215296,216225,217156,218089,219024,219961,220900,221841,222784,223729,224676,225625,226576,227529,228484,229441,230400,231361,232324,233289,234256,235225,236196,237169,238144,239121,240100,241081,242064,243049,244036,245025,246016,247009,248004,249001,250000,251001,252004,253009,254016,255025,256036,257049,258064,259081,260100,261121,262144,263169,264196,265225,266256,267289,268324,269361,270400,271441,272484,273529,274576,275625,276676,277729,278784,279841,280900,281961,283024,284089,285156,286225,287296,288369,289444,290521,291600,292681,293764,294849,295936,297025,298116,299209,300304,301401,302500,303601,304704,305809,306916,308025,309136,310249,311364,312481,313600,314721,315844,316969,318096,319225,320356,321489,322624,323761,324900,326041,327184,328329,329476,330625,331776,332929,334084,335241,336400,337561,338724,339889,341056,342225,343396,344569,345744,346921,348100,349281,350464,351649,352836,354025,355216,356409,357604,358801,360000,361201,362404,363609,364816,366025,367236,368449,369664,370881,372100,373321,374544,375769,376996,378225,379456,380689,381924,383161,384400,385641,386884,388129,389376,390625,391876,393129,394384,395641,396900,398161,399424,400689,401956,403225,404496,405769,407044,408321,409600,410881,412164,413449,414736,416025,417316,418609,419904,421201,422500,423801,425104,426409,427716,429025,430336,431649,432964,434281,435600,436921,438244,439569,440896,442225,443556,444889,446224,447561,448900,450241,451584,452929,454276,455625,456976,458329,459684,461041,462400,463761,465124,466489,467856,469225,470596,471969,473344,474721,476100,477481,478864,480249,481636,483025,484416,485809,487204,488601,490000,491401,492804,494209,495616,497025,498436,499849,501264,502681,504100,505521,506944,508369,509796,511225,512656,514089,515524,516961,518400,519841,521284,522729,524176,525625,527076,528529,529984,531441,532900,534361,535824,537289,538756,540225,541696,543169,544644,546121,547600,549081,550564,552049,553536,555025,556516,558009,559504,561001,562500,564001,565504,567009,568516,570025,571536,573049,574564,576081,577600,579121,580644,582169,583696,585225,586756,588289,589824,591361,592900,594441,595984,597529,599076,600625,602176,603729,605284,606841,608400,609961,611524,613089,614656,616225,617796,619369,620944,622521,624100,625681,627264,628849,630436,632025,633616,635209,636804,638401,640000,641601,643204,644809,646416,648025,649636,651249,652864,654481,656100,657721,659344,660969,662596,664225,665856,667489,669124,670761,672400,674041,675684,677329,678976,680625,682276,683929,685584,687241,688900,690561,692224,693889,695556,697225,698896,700569,702244,703921,705600,707281,708964,710649,712336,714025,715716,717409,719104,720801,722500,724201,725904,727609,729316,731025,732736,734449,736164,737881,739600,741321,743044,744769,746496,748225,749956,751689,753424,755161,756900,758641,760384,762129,763876,765625,767376,769129,770884,772641,774400,776161,777924,779689,781456,783225,784996,786769,788544,790321,792100,793881,795664,797449,799236,801025,802816,804609,806404,808201,810000,811801,813604,815409,817216,819025,820836,822649,824464,826281,828100,829921,831744,833569,835396,837225,839056,840889,842724,844561,846400,848241,850084,851929,853776,855625,857476,859329,861184,863041,864900,866761,868624,870489,872356,874225,876096,877969,879844,881721,883600,885481,887364,889249,891136,893025,894916,896809,898704,900601,902500,904401,906304,908209,910116,912025,913936,915849,917764,919681,921600,923521,925444,927369,929296,931225,933156,935089,937024,938961,940900,942841,944784,946729,948676,950625,952576,954529,956484,958441,960400,962361,964324,966289,968256,970225,972196,974169,976144,978121,980100,982081,984064,986049,988036,990025,992016,994009,996004,998001,1000000,1002001,1004004,1006009,1008016,1010025,1012036,1014049,1016064,1018081,1020100,1022121,1024144,1026169,1028196,1030225,1032256,1034289,1036324,1038361,1040400,1042441,1044484,1046529,1048576,1050625,1052676,1054729,1056784,1058841,1060900,1062961,1065024,1067089,1069156,1071225,1073296,1075369,1077444,1079521,1081600,1083681,1085764,1087849,1089936,1092025,1094116,1096209,1098304,1100401,1102500,1104601,1106704,1108809,1110916,1113025,1115136,1117249,1119364,1121481,1123600,1125721,1127844,1129969,1132096,1134225,1136356,1138489,1140624,1142761,1144900,1147041,1149184,1151329,1153476,1155625,1157776,1159929,1162084,1164241,1166400,1168561,1170724,1172889,1175056,1177225,1179396,1181569,1183744,1185921,1188100,1190281,1192464,1194649,1196836,1199025,1201216,1203409,1205604,1207801,1210000,1212201,1214404,1216609,1218816,1221025,1223236,1225449,1227664,1229881,1232100,1234321,1236544,1238769,1240996,1243225,1245456,1247689,1249924,1252161,1254400,1256641,1258884,1261129,1263376,1265625,1267876,1270129,1272384,1274641,1276900,1279161,1281424,1283689,1285956,1288225,1290496,1292769,1295044,1297321,1299600,1301881,1304164,1306449,1308736,1311025,1313316,1315609,1317904,1320201,1322500,1324801,1327104,1329409,1331716,1334025,1336336,1338649,1340964,1343281,1345600,1347921,1350244,1352569,1354896,1357225,1359556,1361889,1364224,1366561,1368900,1371241,1373584,1375929,1378276,1380625,1382976,1385329,1387684,1390041,1392400,1394761,1397124,1399489,1401856,1404225,1406596,1408969,1411344,1413721,1416100,1418481,1420864,1423249,1425636,1428025,1430416,1432809,1435204,1437601,1440000,1442401,1444804,1447209,1449616,1452025,1454436,1456849,1459264,1461681,1464100,1466521,1468944,1471369,1473796,1476225,1478656,1481089,1483524,1485961,1488400,1490841,1493284,1495729,1498176,1500625,1503076,1505529,1507984,1510441,1512900,1515361,1517824,1520289,1522756,1525225,1527696,1530169,1532644,1535121,1537600,1540081,1542564,1545049,1547536,1550025,1552516,1555009,1557504,1560001,1562500,1565001,1567504,1570009,1572516,1575025,1577536,1580049,1582564,1585081,1587600,1590121,1592644,1595169,1597696,1600225,1602756,1605289,1607824,1610361,1612900,1615441,1617984,1620529,1623076,1625625,1628176,1630729,1633284,1635841,1638400,1640961,1643524,1646089,1648656,1651225,1653796,1656369,1658944,1661521,1664100,1666681,1669264,1671849,1674436,1677025,1679616,1682209,1684804,1687401,1690000,1692601,1695204,1697809,1700416,1703025,1705636,1708249,1710864,1713481,1716100,1718721,1721344,1723969,1726596,1729225,1731856,1734489,1737124,1739761,1742400,1745041,1747684,1750329,1752976,1755625,1758276,1760929,1763584,1766241,1768900,1771561,1774224,1776889,1779556,1782225,1784896,1787569,1790244,1792921,1795600,1798281,1800964,1803649,1806336,1809025,1811716,1814409,1817104,1819801,1822500,1825201,1827904,1830609,1833316,1836025,1838736,1841449,1844164,1846881,1849600,1852321,1855044,1857769,1860496,1863225,1865956,1868689,1871424,1874161,1876900,1879641,1882384,1885129,1887876,1890625,1893376,1896129,1898884,1901641,1904400,1907161,1909924,1912689,1915456,1918225,1920996,1923769,1926544,1929321,1932100,1934881,1937664,1940449,1943236,1946025,1948816,1951609,1954404,1957201,1960000,1962801,1965604,1968409,1971216,1974025,1976836,1979649,1982464,1985281,1988100,1990921,1993744,1996569,1999396,2002225,2005056,2007889,2010724,2013561,2016400,2019241,2022084,2024929,2027776,2030625,2033476,2036329,2039184,2042041,2044900,2047761,2050624,2053489,2056356,2059225,2062096,2064969,2067844,2070721,2073600,2076481,2079364,2082249,2085136,2088025,2090916,2093809,2096704,2099601,2102500,2105401,2108304,2111209,2114116,2117025,2119936,2122849,2125764,2128681,2131600,2134521,2137444,2140369,2143296,2146225,2149156,2152089,2155024,2157961,2160900,2163841,2166784,2169729,2172676,2175625,2178576,2181529,2184484,2187441,2190400,2193361,2196324,2199289,2202256,2205225,2208196,2211169,2214144,2217121,2220100,2223081,2226064,2229049,2232036,2235025,2238016,2241009,2244004,2247001,2250000,2253001,2256004,2259009,2262016,2265025,2268036,2271049,2274064,2277081,2280100,2283121,2286144,2289169,2292196,2295225,2298256,2301289,2304324,2307361,2310400,2313441,2316484,2319529,2322576,2325625,2328676,2331729,2334784,2337841,2340900,2343961,2347024,2350089,2353156,2356225,2359296,2362369,2365444,2368521,2371600,2374681,2377764,2380849,2383936,2387025,2390116,2393209,2396304,2399401,2402500,2405601,2408704,2411809,2414916,2418025,2421136,2424249,2427364,2430481,2433600,2436721,2439844,2442969,2446096,2449225,2452356,2455489,2458624,2461761,2464900,2468041,2471184,2474329,2477476,2480625,2483776,2486929,2490084,2493241,2496400,2499561,2502724,2505889,2509056,2512225,2515396,2518569,2521744,2524921,2528100,2531281,2534464,2537649,2540836,2544025,2547216,2550409,2553604,2556801,2560000,2563201,2566404,2569609,2572816,2576025,2579236,2582449,2585664,2588881,2592100,2595321,2598544,2601769,2604996,2608225,2611456,2614689,2617924,2621161,2624400,2627641,2630884,2634129,2637376,2640625,2643876,2647129,2650384,2653641,2656900,2660161,2663424,2666689,2669956,2673225,2676496,2679769,2683044,2686321,2689600,2692881,2696164,2699449,2702736,2706025,2709316,2712609,2715904,2719201,2722500,2725801,2729104,2732409,2735716,2739025,2742336,2745649,2748964,2752281,2755600,2758921,2762244,2765569,2768896,2772225,2775556,2778889,2782224,2785561,2788900,2792241,2795584,2798929,2802276,2805625,2808976,2812329,2815684,2819041,2822400,2825761,2829124,2832489,2835856,2839225,2842596,2845969,2849344,2852721,2856100,2859481,2862864,2866249,2869636,2873025,2876416,2879809,2883204,2886601,2890000,2893401,2896804,2900209,2903616,2907025,2910436,2913849,2917264,2920681,2924100,2927521,2930944,2934369,2937796,2941225,2944656,2948089,2951524,2954961,2958400,2961841,2965284,2968729,2972176,2975625,2979076,2982529,2985984,2989441,2992900,2996361,2999824,3003289,3006756,3010225,3013696,3017169,3020644,3024121,3027600,3031081,3034564,3038049,3041536,3045025,3048516,3052009,3055504,3059001,3062500,3066001,3069504,3073009,3076516,3080025,3083536,3087049,3090564,3094081,3097600,3101121,3104644,3108169,3111696,3115225,3118756,3122289,3125824,3129361,3132900,3136441,3139984,3143529,3147076,3150625,3154176,3157729,3161284,3164841,3168400,3171961,3175524,3179089,3182656,3186225,3189796,3193369,3196944,3200521,3204100,3207681,3211264,3214849,3218436,3222025,3225616,3229209,3232804,3236401,3240000,3243601,3247204,3250809,3254416,3258025,3261636,3265249,3268864,3272481,3276100,3279721,3283344,3286969,3290596,3294225,3297856,3301489,3305124,3308761,3312400,3316041,3319684,3323329,3326976,3330625,3334276,3337929,3341584,3345241,3348900,3352561,3356224,3359889,3363556,3367225,3370896,3374569,3378244,3381921,3385600,3389281,3392964,3396649,3400336,3404025,3407716,3411409,3415104,3418801,3422500,3426201,3429904,3433609,3437316,3441025,3444736,3448449,3452164,3455881,3459600,3463321,3467044,3470769,3474496,3478225,3481956,3485689,3489424,3493161,3496900,3500641,3504384,3508129,3511876,3515625,3519376,3523129,3526884,3530641,3534400,3538161,3541924,3545689,3549456,3553225,3556996,3560769,3564544,3568321,3572100,3575881,3579664,3583449,3587236,3591025,3594816,3598609,3602404,3606201,3610000,3613801,3617604,3621409,3625216,3629025,3632836,3636649,3640464,3644281,3648100,3651921,3655744,3659569,3663396,3667225,3671056,3674889,3678724,3682561,3686400,3690241,3694084,3697929,3701776,3705625,3709476,3713329,3717184,3721041,3724900,3728761,3732624,3736489,3740356,3744225,3748096,3751969,3755844,3759721,3763600,3767481,3771364,3775249,3779136,3783025,3786916,3790809,3794704,3798601,3802500,3806401,3810304,3814209,3818116,3822025,3825936,3829849,3833764,3837681,3841600,3845521,3849444,3853369,3857296,3861225,3865156,3869089,3873024,3876961,3880900,3884841,3888784,3892729,3896676,3900625,3904576,3908529,3912484,3916441,3920400,3924361,3928324,3932289,3936256,3940225,3944196,3948169,3952144,3956121,3960100,3964081,3968064,3972049,3976036,3980025,3984016,3988009,3992004,3996001,4000000,4004001,4008004,4012009,4016016,4020025,4024036,4028049,4032064,4036081,4040100,4044121,4048144,4052169,4056196,4060225,4064256,4068289,4072324,4076361,4080400,4084441,4088484,4092529,4096576,4100625,4104676,4108729,4112784,4116841,4120900,4124961,4129024,4133089,4137156,4141225,4145296,4149369,4153444,4157521,4161600,4165681,4169764,4173849,4177936,4182025,4186116,4190209,4194304,4198401,4202500,4206601,4210704,4214809,4218916,4223025,4227136,4231249,4235364,4239481,4243600,4247721,4251844,4255969,4260096,4264225,4268356,4272489,4276624,4280761,4284900,4289041,4293184,4297329,4301476,4305625,4309776,4313929,4318084,4322241,4326400,4330561,4334724,4338889,4343056,4347225,4351396,4355569,4359744,4363921,4368100,4372281,4376464,4380649,4384836,4389025,4393216,4397409,4401604,4405801,4410000,4414201,4418404,4422609,4426816,4431025,4435236,4439449,4443664,4447881,4452100,4456321,4460544,4464769,4468996,4473225,4477456,4481689,4485924,4490161,4494400,4498641,4502884,4507129,4511376,4515625,4519876,4524129,4528384,4532641,4536900,4541161,4545424,4549689,4553956,4558225,4562496,4566769,4571044,4575321,4579600,4583881,4588164,4592449,4596736,4601025,4605316,4609609,4613904,4618201,4622500,4626801,4631104,4635409,4639716,4644025,4648336,4652649,4656964,4661281,4665600,4669921,4674244,4678569,4682896,4687225,4691556,4695889,4700224,4704561,4708900,4713241,4717584,4721929,4726276,4730625,4734976,4739329,4743684,4748041,4752400,4756761,4761124,4765489,4769856,4774225,4778596,4782969,4787344,4791721,4796100,4800481,4804864,4809249,4813636,4818025,4822416,4826809,4831204,4835601,4840000,4844401,4848804,4853209,4857616,4862025,4866436,4870849,4875264,4879681,4884100,4888521,4892944,4897369,4901796,4906225,4910656,4915089,4919524,4923961,4928400,4932841,4937284,4941729,4946176,4950625,4955076,4959529,4963984,4968441,4972900,4977361,4981824,4986289,4990756,4995225,4999696,5004169,5008644,5013121,5017600,5022081,5026564,5031049,5035536,5040025,5044516,5049009,5053504,5058001,5062500,5067001,5071504,5076009,5080516,5085025,5089536,5094049,5098564,5103081,5107600,5112121,5116644,5121169,5125696,5130225,5134756,5139289,5143824,5148361,5152900,5157441,5161984,5166529,5171076,5175625,5180176,5184729,5189284,5193841,5198400,5202961,5207524,5212089,5216656,5221225,5225796,5230369,5234944,5239521,5244100,5248681,5253264,5257849,5262436,5267025,5271616,5276209,5280804,5285401,5290000,5294601,5299204,5303809,5308416,5313025,5317636,5322249,5326864,5331481,5336100,5340721,5345344,5349969,5354596,5359225,5363856,5368489,5373124,5377761,5382400,5387041,5391684,5396329,5400976,5405625,5410276,5414929,5419584,5424241,5428900,5433561,5438224,5442889,5447556,5452225,5456896,5461569,5466244,5470921,5475600,5480281,5484964,5489649,5494336,5499025,5503716,5508409,5513104,5517801,5522500,5527201,5531904,5536609,5541316,5546025,5550736,5555449,5560164,5564881,5569600,5574321,5579044,5583769,5588496,5593225,5597956,5602689,5607424,5612161,5616900,5621641,5626384,5631129,5635876,5640625,5645376,5650129,5654884,5659641,5664400,5669161,5673924,5678689,5683456,5688225,5692996,5697769,5702544,5707321,5712100,5716881,5721664,5726449,5731236,5736025,5740816,5745609,5750404,5755201,5760000,5764801,5769604,5774409,5779216,5784025,5788836,5793649,5798464,5803281,5808100,5812921,5817744,5822569,5827396,5832225,5837056,5841889,5846724,5851561,5856400,5861241,5866084,5870929,5875776,5880625,5885476,5890329,5895184,5900041,5904900,5909761,5914624,5919489,5924356,5929225,5934096,5938969,5943844,5948721,5953600,5958481,5963364,5968249,5973136,5978025,5982916,5987809,5992704,5997601,6002500,6007401,6012304,6017209,6022116,6027025,6031936,6036849,6041764,6046681,6051600,6056521,6061444,6066369,6071296,6076225,6081156,6086089,6091024,6095961,6100900,6105841,6110784,6115729,6120676,6125625,6130576,6135529,6140484,6145441,6150400,6155361,6160324,6165289,6170256,6175225,6180196,6185169,6190144,6195121,6200100,6205081,6210064,6215049,6220036,6225025,6230016,6235009,6240004,6245001,6250000,6255001,6260004,6265009,6270016,6275025,6280036,6285049,6290064,6295081,6300100,6305121,6310144,6315169,6320196,6325225,6330256,6335289,6340324,6345361,6350400,6355441,6360484,6365529,6370576,6375625,6380676,6385729,6390784,6395841,6400900,6405961,6411024,6416089,6421156,6426225,6431296,6436369,6441444,6446521,6451600,6456681,6461764,6466849,6471936,6477025,6482116,6487209,6492304,6497401,6502500,6507601,6512704,6517809,6522916,6528025,6533136,6538249,6543364,6548481,6553600,6558721,6563844,6568969,6574096,6579225,6584356,6589489,6594624,6599761,6604900,6610041,6615184,6620329,6625476,6630625,6635776,6640929,6646084,6651241,6656400,6661561,6666724,6671889,6677056,6682225,6687396,6692569,6697744,6702921,6708100,6713281,6718464,6723649,6728836,6734025,6739216,6744409,6749604,6754801,6760000,6765201,6770404,6775609,6780816,6786025,6791236,6796449,6801664,6806881,6812100,6817321,6822544,6827769,6832996,6838225,6843456,6848689,6853924,6859161,6864400,6869641,6874884,6880129,6885376,6890625,6895876,6901129,6906384,6911641,6916900,6922161,6927424,6932689,6937956,6943225,6948496,6953769,6959044,6964321,6969600,6974881,6980164,6985449,6990736,6996025,7001316,7006609,7011904,7017201,7022500,7027801,7033104,7038409,7043716,7049025,7054336,7059649,7064964,7070281,7075600,7080921,7086244,7091569,7096896,7102225,7107556,7112889,7118224,7123561,7128900,7134241,7139584,7144929,7150276,7155625,7160976,7166329,7171684,7177041,7182400,7187761,7193124,7198489,7203856,7209225,7214596,7219969,7225344,7230721,7236100,7241481,7246864,7252249,7257636,7263025,7268416,7273809,7279204,7284601,7290000,7295401,7300804,7306209,7311616,7317025,7322436,7327849,7333264,7338681,7344100,7349521,7354944,7360369,7365796,7371225,7376656,7382089,7387524,7392961,7398400,7403841,7409284,7414729,7420176,7425625,7431076,7436529,7441984,7447441,7452900,7458361,7463824,7469289,7474756,7480225,7485696,7491169,7496644,7502121,7507600,7513081,7518564,7524049,7529536,7535025,7540516,7546009,7551504,7557001,7562500,7568001,7573504,7579009,7584516,7590025,7595536,7601049,7606564,7612081,7617600,7623121,7628644,7634169,7639696,7645225,7650756,7656289,7661824,7667361,7672900,7678441,7683984,7689529,7695076,7700625,7706176,7711729,7717284,7722841,7728400,7733961,7739524,7745089,7750656,7756225,7761796,7767369,7772944,7778521,7784100,7789681,7795264,7800849,7806436,7812025,7817616,7823209,7828804,7834401,7840000,7845601,7851204,7856809,7862416,7868025,7873636,7879249,7884864,7890481,7896100,7901721,7907344,7912969,7918596,7924225,7929856,7935489,7941124,7946761,7952400,7958041,7963684,7969329,7974976,7980625,7986276,7991929,7997584,8003241,8008900,8014561,8020224,8025889,8031556,8037225,8042896,8048569,8054244,8059921,8065600,8071281,8076964,8082649,8088336,8094025,8099716,8105409,8111104,8116801,8122500,8128201,8133904,8139609,8145316,8151025,8156736,8162449,8168164,8173881,8179600,8185321,8191044,8196769,8202496,8208225,8213956,8219689,8225424,8231161,8236900,8242641,8248384,8254129,8259876,8265625,8271376,8277129,8282884,8288641,8294400,8300161,8305924,8311689,8317456,8323225,8328996,8334769,8340544,8346321,8352100,8357881,8363664,8369449,8375236,8381025,8386816,8392609,8398404,8404201,8410000,8415801,8421604,8427409,8433216,8439025,8444836,8450649,8456464,8462281,8468100,8473921,8479744,8485569,8491396,8497225,8503056,8508889,8514724,8520561,8526400,8532241,8538084,8543929,8549776,8555625,8561476,8567329,8573184,8579041,8584900,8590761,8596624,8602489,8608356,8614225,8620096,8625969,8631844,8637721,8643600,8649481,8655364,8661249,8667136,8673025,8678916,8684809,8690704,8696601,8702500,8708401,8714304,8720209,8726116,8732025,8737936,8743849,8749764,8755681,8761600,8767521,8773444,8779369,8785296,8791225,8797156,8803089,8809024,8814961,8820900,8826841,8832784,8838729,8844676,8850625,8856576,8862529,8868484,8874441,8880400,8886361,8892324,8898289,8904256,8910225,8916196,8922169,8928144,8934121,8940100,8946081,8952064,8958049,8964036,8970025,8976016,8982009,8988004,8994001,9000000,9006001,9012004,9018009,9024016,9030025,9036036,9042049,9048064,9054081,9060100,9066121,9072144,9078169,9084196,9090225,9096256,9102289,9108324,9114361,9120400,9126441,9132484,9138529,9144576,9150625,9156676,9162729,9168784,9174841,9180900,9186961,9193024,9199089,9205156,9211225,9217296,9223369,9229444,9235521,9241600,9247681,9253764,9259849,9265936,9272025,9278116,9284209,9290304,9296401,9302500,9308601,9314704,9320809,9326916,9333025,9339136,9345249,9351364,9357481,9363600,9369721,9375844,9381969,9388096,9394225,9400356,9406489,9412624,9418761,9424900,9431041,9437184,9443329,9449476,9455625,9461776,9467929,9474084,9480241,9486400,9492561,9498724,9504889,9511056,9517225,9523396,9529569,9535744,9541921,9548100,9554281,9560464,9566649,9572836,9579025,9585216,9591409,9597604,9603801,9610000,9616201,9622404,9628609,9634816,9641025,9647236,9653449,9659664,9665881,9672100,9678321,9684544,9690769,9696996,9703225,9709456,9715689,9721924,9728161,9734400,9740641,9746884,9753129,9759376,9765625,9771876,9778129,9784384,9790641,9796900,9803161,9809424,9815689,9821956,9828225,9834496,9840769,9847044,9853321,9859600,9865881,9872164,9878449,9884736,9891025,9897316,9903609,9909904,9916201,9922500,9928801,9935104,9941409,9947716,9954025,9960336,9966649,9972964,9979281,9985600,9991921,9998244,10004569}; 
    int main(){
    	

    	scanf("%d",&cas);
    	while(cas--){
    		scanf("%d %d",&n,&k); 
    		if(sqrt(n) < k ){
    			puts("NO");
    			continue;
			}
    		if((n & 1) && k == 1){
    			puts("YES");
    		}else{
    			n -= s[k-1];
    			if(n > 0 && n % 2 == 1 && n > a[k-1]) puts("YES");
    			else puts("NO");
    		}
    	}
    	return 0;
    }