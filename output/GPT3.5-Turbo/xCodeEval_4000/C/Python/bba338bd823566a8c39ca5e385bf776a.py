A = 100000000
B = 1000
PMAX = 316223
P = 27293
P3 = 10000
L1 = 32000

a = [0] * (A + 1)
b = [
    0, 5761455, 11078937, 16252325, 21336326, 26355867, 31324703, 36252931, 41146179, 46009215,
    50847534, 55662470, 60454705, 65228333, 69985473, 74726528, 79451833, 84163019, 88862422, 93547928,
    98222287, 102886526, 107540122, 112184940, 116818447, 121443371, 126062167, 130670192, 135270258, 139864011,
    144449537, 149028641, 153600805, 158165829, 162725196, 167279333, 171827136, 176369517, 180906194, 185436625,
    189961812, 194481069, 198996103, 203507248, 208013454, 212514323, 217011319, 221504167, 225991743, 230475545,
    234954223, 239429993, 243902342, 248370960, 252834065, 257294520, 261751864, 266206294, 270655552, 275101551,
    279545368, 283984956, 288422869, 292856421, 297285198, 301711468, 306137611, 310558733, 314977166, 319391721,
    323804352, 328215206, 332620900, 337024801, 341426904, 345826612, 350221825, 354615116, 359006517, 363395981,
    367783654, 372168766, 376549859, 380930729, 385307831, 389682427, 394055910, 398425675, 402793457, 407159590,
    411523195, 415885628, 420243162, 424603409, 428958595, 433311792, 437663672, 442014876, 446362736, 450708777,
    455052511, 459394441, 463733626, 468072089, 472408200, 476741968, 481074475, 485405902, 489736021, 494062787,
    498388617, 502712575, 507036251, 511354887, 515673696, 519991125, 524309392, 528624525, 532936342, 537247292,
    541555851, 545864306, 550170437, 554476170, 558778993, 563082532, 567382703, 571680924, 575978253, 580275482,
    584570200, 588863345, 593155089, 597445378, 601735269, 606022680, 610308664, 614594106, 618878615, 623159296,
    627440336, 631717982, 635997249, 640275231, 644550922, 648825715, 653099304, 657371139, 661643304, 665911851,
    670180516, 674447835, 678714823, 682979568, 687242934, 691504332, 695766925, 700028114, 704286233, 708543557,
    712799821, 717055212, 721310048, 725563140, 729813991, 734065508, 738315156, 742564929, 746813071, 751060249,
    755305935, 759550004, 763794029, 768035554, 772276773, 776516528, 780756650, 784994469, 789230673, 793467703,
    797703398, 801937611, 806169530, 810401956, 814633249, 818864199, 823092766, 827320850, 831548431, 835773764,
    840000027, 844224822, 848450250, 852673966, 856895823, 861116918, 865335133, 869555570, 873772692, 877989808,
    882206716, 886422213, 890636921, 894850907, 899064419, 903275849, 907487780, 911698381, 915907322, 920117006,
    924324489, 928532509, 932738007, 936943763, 941147666, 945351970, 949555347, 953758330, 957958052, 962158684,
    966358351, 970556800, 974755898, 978951680, 983147464, 987343369, 991538483, 995733104, 999926054, 1004118104,
    1008309544, 1012500258, 1016690917, 1020879037, 1025067175, 1029256469, 1033444454, 1037631294, 1041815774, 1046001482,
    1050186367, 1054370637, 1058552429, 1062734476, 1066916147, 1071094927, 1075274949, 1079454128, 1083631538, 1087809564,
    1091987405, 1096163370, 1100339660, 1104513787, 1108687177, 1112860305, 1117034447, 1121205592, 1125376629, 1129547281,
    1133717820, 1137887191, 1142056097, 1146225390, 1150393648, 1154560299, 1158727002, 1162892823, 1167057747, 1171221046,
    1175385155, 1179549444, 1183711384, 1187874380, 1192034212, 1196195238, 1200356153, 1204515304, 1208673910, 1212829795,
    1216987937, 1221145073, 1225300872, 1229455037, 1233609164, 1237764170, 1241917157, 1246070670, 1250224878, 1254376178,
    1258528162, 1262678524, 1266827683, 1270976954, 1275125632, 1279274172, 1283421484, 1287567873, 1291715676, 1295861693,
    1300005926, 1304150462, 1308296664, 1312440578, 1316583470, 1320724811, 1324868019, 1329010956, 1333151863, 1337291809,
    1341430624, 1345570079, 1349708221, 1353846756, 1357984935, 1362122305, 1366257814, 1370393786, 1374528892, 1378664634,
    1382799415, 1386933522, 1391065576, 1395199789, 1399331489, 1403463860, 1407594647, 1411724086, 1415855689, 1419985631,
    1424115489, 1428244053, 1432371870, 1436498522, 1440625629, 1444751745, 1448877006, 1453002152, 1457125036, 1461250000,
    1465374659, 1469497594, 1473620220, 1477744125, 1481866173, 1485988244, 1490109683, 1494229934, 1498349689, 1502469332,
    1506589876, 1510706235, 1514824921, 1518942965, 1523061505, 1527178351, 1531294454, 1535409890, 1539526326, 1543640517,
    1547756812, 1551870851, 1555985016, 1560097442, 1564208549, 1568320054, 1572432177, 1576544661, 1580654270, 1584764017,
    1588873108, 1592982840, 1597091049, 1601199712, 1605308326, 1609414491, 1613521803, 1617628777, 1621733835, 1625839726,
    1629945987, 1634052052, 1638156927, 1642258972, 1646361787, 1650465128, 1654567808, 1658669200, 1662770302, 1666869794,
    1670972264, 1675072419, 1679170566, 1683270249, 1687369711, 1691467151, 1695565190, 1699662748, 1703761548, 1707858902,
    1711955433, 1716050469, 1720144848, 1724241897, 1728336282, 1732430410, 1736526180, 1740619156, 1744713632, 1748805530,
    1752898084, 1756987393, 1761078122, 1765169921, 1769260641, 1773351175, 1777442877, 1781530474, 1785621307, 1789709560,
    1793798703, 1797887260, 1801975182, 1806062390, 1810149996, 1814236123, 1818322676, 1822407623, 1826489988, 1830575906,
    1834658067, 1838742792, 1842825653, 1846909270, 1850992005, 1855074218, 1859156347, 1863238351, 1867320859, 1871402335,
    1875482847, 1879562930, 1883642470, 1887722398, 1891800587, 1895879932, 1899958276, 1904036638, 1908114573, 1912191800,
    1916268743, 1920347116, 1924422570, 1928498011, 1932573349, 1936646486, 1940721696, 1944797174, 1948871367, 1952945594,
    1957018338, 1961089383, 1965161808, 1969233350, 1973304195, 1977376665, 1981447779, 1985519033, 1989588548, 1993659289,
    1997729452, 2001796366, 2005864843, 2009933793, 2014002593, 2018069377, 2022137196, 2026204289, 2030270517, 2034337796,
    2038404475, 2042469434, 2046534053, 2050598713, 2054662457, 2058727455, 2062791593, 2066855115, 2070918071, 2074981871,
    2079045540, 2083107257, 2087170358, 2091232421, 2095293756, 2099353852, 2103414866, 2107473358, 2111533438, 2115593696,
    2119654578, 2123711202, 2127769041, 2131828079, 2135887473, 2139945263, 2144002868, 2148061201, 2152118222, 2156173876,
    2160230408, 2164287399, 2168343450, 2172397905, 2176451935, 2180506650, 2184561319, 2188616526, 2192670595, 2196723874,
    2200777436, 2204828910, 2208879508, 2212930015, 2216982800, 2221034120, 2225087204, 2229138005, 2233188780, 2237237738,
    2241286680, 2245337711, 2249386635, 2253437044, 2257486659, 2261534669, 2265582088, 2269630722, 2273677293, 2277723942,
    2281770277, 2285816118, 2289861391, 2293908247, 2297955870, 2301999709, 2306044120, 2310088597, 2314134053, 2318177990,
    2322223112, 2326266900, 2330308778, 2334351201, 2338393413, 2342436031, 2346478314, 2350519355, 2354560561, 2358602447,
    2362642765, 2366683716, 2370724495, 2374763504, 2378804084, 2382843532, 2386880413, 2390919906, 2394959109, 2398996112,
    2403034927, 2407071577, 2411110078, 2415147307, 2419181034, 2423219093, 2427255367, 2431292536, 2435327045, 2439361501,
    2443396396, 2447431831, 2451466331, 2455500451, 2459534282, 2463565779, 2467597919, 2471632122, 2475665529, 2479696435,
    2483729191, 2487761399, 2491793997, 2495825196, 2499856755, 2503887935, 2507918465, 2511947717, 2515978063, 2520007177,
    2524038155, 2528067401, 2532097043, 2536126664, 2540155255, 2544183491, 2548211228, 2552238285, 2556266399, 2560294002,
    2564319542, 2568345835, 2572372442, 2576397670, 2580421933, 2584447929, 2588472785, 2592497820, 2596522622, 2600546330,
    2604571471, 2608595062, 2612618628, 2616643294, 2620665663, 2624687920, 2628709369, 2632732626, 2636754699, 2640776029,
    2644799757, 2648820585, 2652840994, 2656861044, 2660881979, 2664902170, 2668922912, 2672943760, 2676963401, 2680982125,
    2685000601, 2689021011, 2693039441, 2697057353, 2701075683, 2705092716, 2709109210, 2713125397, 2717143223, 2721159932,
    2725176643, 2729193507, 2733210696, 2737225536, 2741242121, 2745257057, 2749272015, 2753286718, 2757299847, 2761314795,
    2765327756, 2769341791, 2773356225, 2777369850, 2781383306, 2785394924, 2789408169, 2793419860, 2797431717, 2801443922,
    2805454432, 2809465484, 2813477356, 2817487436, 2821497837, 2825509231, 2829520068, 2833530738, 2837539518, 2841549369,
    2845558213, 2849566042, 2853574755, 2857584531, 2861594266, 2865601989, 2869610768, 2873619181, 2877625961, 2881633373,
    2885641353, 2889648502, 2893654733, 2897660376, 2901667770, 2905672946, 2909678043, 2913685600, 2917689568, 2921695146,
    2925699539, 2929702761, 2933706263, 2937709465, 2941713524, 2945717900, 2949719949, 2953724092, 2957726064, 2961727364,
    2965730599, 2969734593, 2973737899, 2977740005, 2981742619, 2985744869, 2989743222, 2993744024, 2997743403, 3001742385,
    3005740846, 3009740083, 3013740632, 3017740443, 3021739912, 3025737894, 3029738266, 3033736354, 3037734260, 3041732620,
    3045730736, 3049728863, 3053726975, 3057724728, 3061722012, 3065718156, 3069714416, 3073709903, 3077706121, 3081700773,
    3085694966, 3089690887, 3093686041, 3097682212, 3101677762, 3105672385, 3109665704, 3113660777, 3117654258, 3121648738,
    3125641477, 3129636165, 3133628489, 3137621629, 3141615091, 3145607391, 3149600532, 3153593186, 3157583551, 3161575400,
    3165568071, 3169558897, 3173549966, 3177541505, 3181531857, 3185524100, 3189515502, 3193505484, 3197494480, 3201485771,
    3205474366, 3209464223, 3213453462, 3217442657, 3221430632, 3225418712, 3229406344, 3233394790, 3237380550, 3241367601,
    3245353518, 3249340672, 3253327262, 3257314501, 3261302137, 3265288786, 3269274318, 3273261676, 3277246756, 3281232235,
    3285218896, 3289205184, 3293189136, 3297172860, 3301158042, 3305141278, 3309125457, 3313108871, 3317092589, 3321076365,
    3325059246, 3329042269, 3333024320, 3337007745, 3340990584, 3344973656, 3348954479, 3352936965, 3356918381, 3360899212,
    3364880246, 3368861514, 3372843128, 3376824341, 3380804536, 3384785252, 3388764045, 3392744352, 3396724969, 3400703302,
    3404683449, 3408661629, 3412641191, 3416621174, 3420600239, 3424577712, 3428556536, 3432533925, 3436512942, 3440489299,
    3444467709, 3448443650, 3452420745, 3456398055, 3460376073, 3464354329, 3468330724, 3472306712, 3476280273, 3480257644,
    3484232867, 3488208449, 3492182057, 3496156616, 3500132047, 3504107018, 3508083271, 3512056531, 3516031243, 3520004496,
    3523979003, 3527952545, 3531925382, 3535899657, 3539873170, 3543843428, 3547815425, 3551789160, 3555761507, 3559733867,
    3563706203, 3567677571, 3571648151, 3575618333, 3579587822, 3583559953, 3587530335, 3591499540, 3595471441, 3599441281,
    3603412533, 3607382383, 3611353499, 3615323157, 3619293204, 3623260438, 3627230054, 3631199924, 3635167788, 3639133977,
    3643101671, 3647069932, 3651037811, 3655006291, 3658974043, 3662941495, 3666909363, 3670877228, 3674842642, 3678809724,
    3682776125, 3686743894, 3690708635, 3694674136, 3698640744, 3702607660, 3706572805, 3710536268, 3714502398, 3718465031,
    3722428991, 3726394088, 3730358421, 3734323031, 3738287024, 3742250941, 3746214561, 3750179004, 3754141753, 3758105608,
    3762067054, 3766030492, 3769992222, 3773955567, 3777917868, 3781881979, 3785842285, 3789803781, 3793766088, 3797726848,
    3801688660, 3805649459, 3809611918, 3813571463, 3817534298, 3821493048, 3825453351, 3829412874, 3833371480, 3837330842,
    3841291749, 3845250279, 3849209920, 3853169493, 3857129155, 3861088365, 3865047067, 3869005617, 3872964725, 3876923182,
    3880881273, 3884839528, 3888796569, 3892753631, 3896710330, 3900667023, 3904623253, 3908580398, 3912536328, 3916492455,
    3920449831, 3924406577, 3928362015, 3932316075, 3936271016, 3940227600, 3944182809, 3948137829, 3952093061, 3956048108,
    3960003559, 3963957671, 3967911833, 3971865657, 3975818018, 3979772869, 3983725586, 3987677658, 3991630533, 3995584016,
    3999537962, 4003491500, 4007444082, 4011396563, 4015348558, 4019300356, 4023253116, 4027204376, 4031157418, 4035109071
]

p = [0] * P
y = [0] * P

n = int(input())

for i in range(3, PMAX + 1, 2):
    if a[i] == 0:
        p.append(i)
        if i <= PMAX // i:
            for j in range(i * i, PMAX + 1, i):
                a[j] = 1

ans = 0
b1 = -1
b2 = 0
q2 = 0
c = 0

for i in range(P):
    n2 = n // p[i]
    if n2 == 0 or n2 < p[i]:
        break
    b2 = n2 // A
    q2 = n2 % A
    if b1 != b2:
        a = [0] * (A + 1)
        b1 = b2
        bl = b1 * A
        bh = bl + q2 + 1
        c = 1 if b1 == 0 else 0
        y[0] = -1
        for j in range(1, P):
            y[j] = max(bl // p[j] * p[j] + p[j], p[j] * p[j]) - bl
            if y[j] % 2 == 0:
                y[j] += p[j]
        kl = bl
        while kl < bh:
            kh = min(kl + L1, bh) - bl
            for j in range(1, P):
                k = y[j]
                while k < kh:
                    a[k] = 1
                    a[k + 1] = 1
                    k += 2 * p[j]
                y[j] = k
            if kl == 0:
                k = 3
                a[2] = 1
            else:
                k = kl - bl + 1
            while k < kh:
                a[k] = a[k + 1] = c if a[k] == 0 else c
                k += 2
        ans += b[b1] + a[q2] - (i + 1)

i = 0
j = P

while True:
    k = i + (j - i) // 2
    if k == i:
        break
    if p[k] > P3:
        n3 = n + 1
    else:
        n3 = p[k] * p[k] * p[k]
    if n3 > n:
        j = k
    elif n3 < n:
        i = k
    else:
        break

if p[k] * p[k] * p[k] <= n:
    ans += k + 1

print(ans)