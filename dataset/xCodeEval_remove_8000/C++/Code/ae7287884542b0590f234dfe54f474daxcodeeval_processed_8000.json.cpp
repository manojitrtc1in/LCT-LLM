
using namespace std;

typedef long long ll;
typedef pair<int,int> State;


int dp[1200001];
int pi[1200001];
void sieve()
{
    for (int i = 2; i < MAX; i++) dp[i] = 1;
    for (int i = 2; i < MAX; i++)
        if (dp[i])
            for (int j = 2*i; j < MAX; j += i)
                dp[j] = 0;
    pi[1] = 0;
    for (int i = 2; i <= MAX; i++)
        if (dp[i]) pi[i] = pi[i-1] + 1;
        else pi[i] = pi[i-1];
}

int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, 212, 222, 232, 242, 252, 262, 272, 282, 292, 303, 313, 323, 333, 343, 353, 363, 373, 383, 393, 404, 414, 424, 434, 444, 454, 464, 474, 484, 494, 505, 515, 525, 535, 545, 555, 565, 575, 585, 595, 606, 616, 626, 636, 646, 656, 666, 676, 686, 696, 707, 717, 727, 737, 747, 757, 767, 777, 787, 797, 808, 818, 828, 838, 848, 858, 868, 878, 888, 898, 909, 919, 929, 939, 949, 959, 969, 979, 989, 999, 1001, 1111, 1221, 1331, 1441, 1551, 1661, 1771, 1881, 1991, 2002, 2112, 2222, 2332, 2442, 2552, 2662, 2772, 2882, 2992, 3003, 3113, 3223, 3333, 3443, 3553, 3663, 3773, 3883, 3993, 4004, 4114, 4224, 4334, 4444, 4554, 4664, 4774, 4884, 4994, 5005, 5115, 5225, 5335, 5445, 5555, 5665, 5775, 5885, 5995, 6006, 6116, 6226, 6336, 6446, 6556, 6666, 6776, 6886, 6996, 7007, 7117, 7227, 7337, 7447, 7557, 7667, 7777, 7887, 7997, 8008, 8118, 8228, 8338, 8448, 8558, 8668, 8778, 8888, 8998, 9009, 9119, 9229, 9339, 9449, 9559, 9669, 9779, 9889, 9999, 10001, 10101, 10201, 10301, 10401, 10501, 10601, 10701, 10801, 10901, 11011, 11111, 11211, 11311, 11411, 11511, 11611, 11711, 11811, 11911, 12021, 12121, 12221, 12321, 12421, 12521, 12621, 12721, 12821, 12921, 13031, 13131, 13231, 13331, 13431, 13531, 13631, 13731, 13831, 13931, 14041, 14141, 14241, 14341, 14441, 14541, 14641, 14741, 14841, 14941, 15051, 15151, 15251, 15351, 15451, 15551, 15651, 15751, 15851, 15951, 16061, 16161, 16261, 16361, 16461, 16561, 16661, 16761, 16861, 16961, 17071, 17171, 17271, 17371, 17471, 17571, 17671, 17771, 17871, 17971, 18081, 18181, 18281, 18381, 18481, 18581, 18681, 18781, 18881, 18981, 19091, 19191, 19291, 19391, 19491, 19591, 19691, 19791, 19891, 19991, 20002, 20102, 20202, 20302, 20402, 20502, 20602, 20702, 20802, 20902, 21012, 21112, 21212, 21312, 21412, 21512, 21612, 21712, 21812, 21912, 22022, 22122, 22222, 22322, 22422, 22522, 22622, 22722, 22822, 22922, 23032, 23132, 23232, 23332, 23432, 23532, 23632, 23732, 23832, 23932, 24042, 24142, 24242, 24342, 24442, 24542, 24642, 24742, 24842, 24942, 25052, 25152, 25252, 25352, 25452, 25552, 25652, 25752, 25852, 25952, 26062, 26162, 26262, 26362, 26462, 26562, 26662, 26762, 26862, 26962, 27072, 27172, 27272, 27372, 27472, 27572, 27672, 27772, 27872, 27972, 28082, 28182, 28282, 28382, 28482, 28582, 28682, 28782, 28882, 28982, 29092, 29192, 29292, 29392, 29492, 29592, 29692, 29792, 29892, 29992, 30003, 30103, 30203, 30303, 30403, 30503, 30603, 30703, 30803, 30903, 31013, 31113, 31213, 31313, 31413, 31513, 31613, 31713, 31813, 31913, 32023, 32123, 32223, 32323, 32423, 32523, 32623, 32723, 32823, 32923, 33033, 33133, 33233, 33333, 33433, 33533, 33633, 33733, 33833, 33933, 34043, 34143, 34243, 34343, 34443, 34543, 34643, 34743, 34843, 34943, 35053, 35153, 35253, 35353, 35453, 35553, 35653, 35753, 35853, 35953, 36063, 36163, 36263, 36363, 36463, 36563, 36663, 36763, 36863, 36963, 37073, 37173, 37273, 37373, 37473, 37573, 37673, 37773, 37873, 37973, 38083, 38183, 38283, 38383, 38483, 38583, 38683, 38783, 38883, 38983, 39093, 39193, 39293, 39393, 39493, 39593, 39693, 39793, 39893, 39993, 40004, 40104, 40204, 40304, 40404, 40504, 40604, 40704, 40804, 40904, 41014, 41114, 41214, 41314, 41414, 41514, 41614, 41714, 41814, 41914, 42024, 42124, 42224, 42324, 42424, 42524, 42624, 42724, 42824, 42924, 43034, 43134, 43234, 43334, 43434, 43534, 43634, 43734, 43834, 43934, 44044, 44144, 44244, 44344, 44444, 44544, 44644, 44744, 44844, 44944, 45054, 45154, 45254, 45354, 45454, 45554, 45654, 45754, 45854, 45954, 46064, 46164, 46264, 46364, 46464, 46564, 46664, 46764, 46864, 46964, 47074, 47174, 47274, 47374, 47474, 47574, 47674, 47774, 47874, 47974, 48084, 48184, 48284, 48384, 48484, 48584, 48684, 48784, 48884, 48984, 49094, 49194, 49294, 49394, 49494, 49594, 49694, 49794, 49894, 49994, 50005, 50105, 50205, 50305, 50405, 50505, 50605, 50705, 50805, 50905, 51015, 51115, 51215, 51315, 51415, 51515, 51615, 51715, 51815, 51915, 52025, 52125, 52225, 52325, 52425, 52525, 52625, 52725, 52825, 52925, 53035, 53135, 53235, 53335, 53435, 53535, 53635, 53735, 53835, 53935, 54045, 54145, 54245, 54345, 54445, 54545, 54645, 54745, 54845, 54945, 55055, 55155, 55255, 55355, 55455, 55555, 55655, 55755, 55855, 55955, 56065, 56165, 56265, 56365, 56465, 56565, 56665, 56765, 56865, 56965, 57075, 57175, 57275, 57375, 57475, 57575, 57675, 57775, 57875, 57975, 58085, 58185, 58285, 58385, 58485, 58585, 58685, 58785, 58885, 58985, 59095, 59195, 59295, 59395, 59495, 59595, 59695, 59795, 59895, 59995, 60006, 60106, 60206, 60306, 60406, 60506, 60606, 60706, 60806, 60906, 61016, 61116, 61216, 61316, 61416, 61516, 61616, 61716, 61816, 61916, 62026, 62126, 62226, 62326, 62426, 62526, 62626, 62726, 62826, 62926, 63036, 63136, 63236, 63336, 63436, 63536, 63636, 63736, 63836, 63936, 64046, 64146, 64246, 64346, 64446, 64546, 64646, 64746, 64846, 64946, 65056, 65156, 65256, 65356, 65456, 65556, 65656, 65756, 65856, 65956, 66066, 66166, 66266, 66366, 66466, 66566, 66666, 66766, 66866, 66966, 67076, 67176, 67276, 67376, 67476, 67576, 67676, 67776, 67876, 67976, 68086, 68186, 68286, 68386, 68486, 68586, 68686, 68786, 68886, 68986, 69096, 69196, 69296, 69396, 69496, 69596, 69696, 69796, 69896, 69996, 70007, 70107, 70207, 70307, 70407, 70507, 70607, 70707, 70807, 70907, 71017, 71117, 71217, 71317, 71417, 71517, 71617, 71717, 71817, 71917, 72027, 72127, 72227, 72327, 72427, 72527, 72627, 72727, 72827, 72927, 73037, 73137, 73237, 73337, 73437, 73537, 73637, 73737, 73837, 73937, 74047, 74147, 74247, 74347, 74447, 74547, 74647, 74747, 74847, 74947, 75057, 75157, 75257, 75357, 75457, 75557, 75657, 75757, 75857, 75957, 76067, 76167, 76267, 76367, 76467, 76567, 76667, 76767, 76867, 76967, 77077, 77177, 77277, 77377, 77477, 77577, 77677, 77777, 77877, 77977, 78087, 78187, 78287, 78387, 78487, 78587, 78687, 78787, 78887, 78987, 79097, 79197, 79297, 79397, 79497, 79597, 79697, 79797, 79897, 79997, 80008, 80108, 80208, 80308, 80408, 80508, 80608, 80708, 80808, 80908, 81018, 81118, 81218, 81318, 81418, 81518, 81618, 81718, 81818, 81918, 82028, 82128, 82228, 82328, 82428, 82528, 82628, 82728, 82828, 82928, 83038, 83138, 83238, 83338, 83438, 83538, 83638, 83738, 83838, 83938, 84048, 84148, 84248, 84348, 84448, 84548, 84648, 84748, 84848, 84948, 85058, 85158, 85258, 85358, 85458, 85558, 85658, 85758, 85858, 85958, 86068, 86168, 86268, 86368, 86468, 86568, 86668, 86768, 86868, 86968, 87078, 87178, 87278, 87378, 87478, 87578, 87678, 87778, 87878, 87978, 88088, 88188, 88288, 88388, 88488, 88588, 88688, 88788, 88888, 88988, 89098, 89198, 89298, 89398, 89498, 89598, 89698, 89798, 89898, 89998, 90009, 90109, 90209, 90309, 90409, 90509, 90609, 90709, 90809, 90909, 91019, 91119, 91219, 91319, 91419, 91519, 91619, 91719, 91819, 91919, 92029, 92129, 92229, 92329, 92429, 92529, 92629, 92729, 92829, 92929, 93039, 93139, 93239, 93339, 93439, 93539, 93639, 93739, 93839, 93939, 94049, 94149, 94249, 94349, 94449, 94549, 94649, 94749, 94849, 94949, 95059, 95159, 95259, 95359, 95459, 95559, 95659, 95759, 95859, 95959, 96069, 96169, 96269, 96369, 96469, 96569, 96669, 96769, 96869, 96969, 97079, 97179, 97279, 97379, 97479, 97579, 97679, 97779, 97879, 97979, 98089, 98189, 98289, 98389, 98489, 98589, 98689, 98789, 98889, 98989, 99099, 99199, 99299, 99399, 99499, 99599, 99699, 99799, 99899, 99999, 100001, 101101, 102201, 103301, 104401, 105501, 106601, 107701, 108801, 109901, 110011, 111111, 112211, 113311, 114411, 115511, 116611, 117711, 118811, 119911, 120021, 121121, 122221, 123321, 124421, 125521, 126621, 127721, 128821, 129921, 130031, 131131, 132231, 133331, 134431, 135531, 136631, 137731, 138831, 139931, 140041, 141141, 142241, 143341, 144441, 145541, 146641, 147741, 148841, 149941, 150051, 151151, 152251, 153351, 154451, 155551, 156651, 157751, 158851, 159951, 160061, 161161, 162261, 163361, 164461, 165561, 166661, 167761, 168861, 169961, 170071, 171171, 172271, 173371, 174471, 175571, 176671, 177771, 178871, 179971, 180081, 181181, 182281, 183381, 184481, 185581, 186681, 187781, 188881, 189981, 190091, 191191, 192291, 193391, 194491, 195591, 196691, 197791, 198891, 199991, 200002, 201102, 202202, 203302, 204402, 205502, 206602, 207702, 208802, 209902, 210012, 211112, 212212, 213312, 214412, 215512, 216612, 217712, 218812, 219912, 220022, 221122, 222222, 223322, 224422, 225522, 226622, 227722, 228822, 229922, 230032, 231132, 232232, 233332, 234432, 235532, 236632, 237732, 238832, 239932, 240042, 241142, 242242, 243342, 244442, 245542, 246642, 247742, 248842, 249942, 250052, 251152, 252252, 253352, 254452, 255552, 256652, 257752, 258852, 259952, 260062, 261162, 262262, 263362, 264462, 265562, 266662, 267762, 268862, 269962, 270072, 271172, 272272, 273372, 274472, 275572, 276672, 277772, 278872, 279972, 280082, 281182, 282282, 283382, 284482, 285582, 286682, 287782, 288882, 289982, 290092, 291192, 292292, 293392, 294492, 295592, 296692, 297792, 298892, 299992, 300003, 301103, 302203, 303303, 304403, 305503, 306603, 307703, 308803, 309903, 310013, 311113, 312213, 313313, 314413, 315513, 316613, 317713, 318813, 319913, 320023, 321123, 322223, 323323, 324423, 325523, 326623, 327723, 328823, 329923, 330033, 331133, 332233, 333333, 334433, 335533, 336633, 337733, 338833, 339933, 340043, 341143, 342243, 343343, 344443, 345543, 346643, 347743, 348843, 349943, 350053, 351153, 352253, 353353, 354453, 355553, 356653, 357753, 358853, 359953, 360063, 361163, 362263, 363363, 364463, 365563, 366663, 367763, 368863, 369963, 370073, 371173, 372273, 373373, 374473, 375573, 376673, 377773, 378873, 379973, 380083, 381183, 382283, 383383, 384483, 385583, 386683, 387783, 388883, 389983, 390093, 391193, 392293, 393393, 394493, 395593, 396693, 397793, 398893, 399993, 400004, 401104, 402204, 403304, 404404, 405504, 406604, 407704, 408804, 409904, 410014, 411114, 412214, 413314, 414414, 415514, 416614, 417714, 418814, 419914, 420024, 421124, 422224, 423324, 424424, 425524, 426624, 427724, 428824, 429924, 430034, 431134, 432234, 433334, 434434, 435534, 436634, 437734, 438834, 439934, 440044, 441144, 442244, 443344, 444444, 445544, 446644, 447744, 448844, 449944, 450054, 451154, 452254, 453354, 454454, 455554, 456654, 457754, 458854, 459954, 460064, 461164, 462264, 463364, 464464, 465564, 466664, 467764, 468864, 469964, 470074, 471174, 472274, 473374, 474474, 475574, 476674, 477774, 478874, 479974, 480084, 481184, 482284, 483384, 484484, 485584, 486684, 487784, 488884, 489984, 490094, 491194, 492294, 493394, 494494, 495594, 496694, 497794, 498894, 499994, 500005, 501105, 502205, 503305, 504405, 505505, 506605, 507705, 508805, 509905, 510015, 511115, 512215, 513315, 514415, 515515, 516615, 517715, 518815, 519915, 520025, 521125, 522225, 523325, 524425, 525525, 526625, 527725, 528825, 529925, 530035, 531135, 532235, 533335, 534435, 535535, 536635, 537735, 538835, 539935, 540045, 541145, 542245, 543345, 544445, 545545, 546645, 547745, 548845, 549945, 550055, 551155, 552255, 553355, 554455, 555555, 556655, 557755, 558855, 559955, 560065, 561165, 562265, 563365, 564465, 565565, 566665, 567765, 568865, 569965, 570075, 571175, 572275, 573375, 574475, 575575, 576675, 577775, 578875, 579975, 580085, 581185, 582285, 583385, 584485, 585585, 586685, 587785, 588885, 589985, 590095, 591195, 592295, 593395, 594495, 595595, 596695, 597795, 598895, 599995, 600006, 601106, 602206, 603306, 604406, 605506, 606606, 607706, 608806, 609906, 610016, 611116, 612216, 613316, 614416, 615516, 616616, 617716, 618816, 619916, 620026, 621126, 622226, 623326, 624426, 625526, 626626, 627726, 628826, 629926, 630036, 631136, 632236, 633336, 634436, 635536, 636636, 637736, 638836, 639936, 640046, 641146, 642246, 643346, 644446, 645546, 646646, 647746, 648846, 649946, 650056, 651156, 652256, 653356, 654456, 655556, 656656, 657756, 658856, 659956, 660066, 661166, 662266, 663366, 664466, 665566, 666666, 667766, 668866, 669966, 670076, 671176, 672276, 673376, 674476, 675576, 676676, 677776, 678876, 679976, 680086, 681186, 682286, 683386, 684486, 685586, 686686, 687786, 688886, 689986, 690096, 691196, 692296, 693396, 694496, 695596, 696696, 697796, 698896, 699996, 700007, 701107, 702207, 703307, 704407, 705507, 706607, 707707, 708807, 709907, 710017, 711117, 712217, 713317, 714417, 715517, 716617, 717717, 718817, 719917, 720027, 721127, 722227, 723327, 724427, 725527, 726627, 727727, 728827, 729927, 730037, 731137, 732237, 733337, 734437, 735537, 736637, 737737, 738837, 739937, 740047, 741147, 742247, 743347, 744447, 745547, 746647, 747747, 748847, 749947, 750057, 751157, 752257, 753357, 754457, 755557, 756657, 757757, 758857, 759957, 760067, 761167, 762267, 763367, 764467, 765567, 766667, 767767, 768867, 769967, 770077, 771177, 772277, 773377, 774477, 775577, 776677, 777777, 778877, 779977, 780087, 781187, 782287, 783387, 784487, 785587, 786687, 787787, 788887, 789987, 790097, 791197, 792297, 793397, 794497, 795597, 796697, 797797, 798897, 799997, 800008, 801108, 802208, 803308, 804408, 805508, 806608, 807708, 808808, 809908, 810018, 811118, 812218, 813318, 814418, 815518, 816618, 817718, 818818, 819918, 820028, 821128, 822228, 823328, 824428, 825528, 826628, 827728, 828828, 829928, 830038, 831138, 832238, 833338, 834438, 835538, 836638, 837738, 838838, 839938, 840048, 841148, 842248, 843348, 844448, 845548, 846648, 847748, 848848, 849948, 850058, 851158, 852258, 853358, 854458, 855558, 856658, 857758, 858858, 859958, 860068, 861168, 862268, 863368, 864468, 865568, 866668, 867768, 868868, 869968, 870078, 871178, 872278, 873378, 874478, 875578, 876678, 877778, 878878, 879978, 880088, 881188, 882288, 883388, 884488, 885588, 886688, 887788, 888888, 889988, 890098, 891198, 892298, 893398, 894498, 895598, 896698, 897798, 898898, 899998, 900009, 901109, 902209, 903309, 904409, 905509, 906609, 907709, 908809, 909909, 910019, 911119, 912219, 913319, 914419, 915519, 916619, 917719, 918819, 919919, 920029, 921129, 922229, 923329, 924429, 925529, 926629, 927729, 928829, 929929, 930039, 931139, 932239, 933339, 934439, 935539, 936639, 937739, 938839, 939939, 940049, 941149, 942249, 943349, 944449, 945549, 946649, 947749, 948849, 949949, 950059, 951159, 952259, 953359, 954459, 955559, 956659, 957759, 958859, 959959, 960069, 961169, 962269, 963369, 964469, 965569, 966669, 967769, 968869, 969969, 970079, 971179, 972279, 973379, 974479, 975579, 976679, 977779, 978879, 979979, 980089, 981189, 982289, 983389, 984489, 985589, 986689, 987789, 988889, 989989, 990099, 991199, 992299, 993399, 994499, 995599, 996699, 997799, 998899, 999999, 1000001, 1001001, 1002001, 1003001, 1004001, 1005001, 1006001, 1007001, 1008001, 1009001, 1010101, 1011101, 1012101, 1013101, 1014101, 1015101, 1016101, 1017101, 1018101, 1019101, 1020201, 1021201, 1022201, 1023201, 1024201, 1025201, 1026201, 1027201, 1028201, 1029201, 1030301, 1031301, 1032301, 1033301, 1034301, 1035301, 1036301, 1037301, 1038301, 1039301, 1040401, 1041401, 1042401, 1043401, 1044401, 1045401, 1046401, 1047401, 1048401, 1049401, 1050501, 1051501, 1052501, 1053501, 1054501, 1055501, 1056501, 1057501, 1058501, 1059501, 1060601, 1061601, 1062601, 1063601, 1064601, 1065601, 1066601, 1067601, 1068601, 1069601, 1070701, 1071701, 1072701, 1073701, 1074701, 1075701, 1076701, 1077701, 1078701, 1079701, 1080801, 1081801, 1082801, 1083801, 1084801, 1085801, 1086801, 1087801, 1088801, 1089801, 1090901, 1091901, 1092901, 1093901, 1094901, 1095901, 1096901, 1097901, 1098901, 1099901, 1100011, 1101011, 1102011, 1103011, 1104011, 1105011, 1106011, 1107011, 1108011, 1109011, 1110111, 1111111, 1112111, 1113111, 1114111, 1115111, 1116111, 1117111, 1118111, 1119111, 1120211, 1121211, 1122211, 1123211, 1124211, 1125211, 1126211, 1127211, 1128211, 1129211, 1130311, 1131311, 1132311, 1133311, 1134311, 1135311, 1136311, 1137311, 1138311, 1139311, 1140411, 1141411, 1142411, 1143411, 1144411, 1145411, 1146411, 1147411, 1148411, 1149411, 1150511, 1151511, 1152511, 1153511, 1154511, 1155511, 1156511, 1157511, 1158511, 1159511, 1160611, 1161611, 1162611, 1163611, 1164611, 1165611, 1166611, 1167611, 1168611, 1169611, 1170711, 1171711, 1172711, 1173711, 1174711, 1175711, 1176711, 1177711, 1178711, 1179711, 1180811, 1181811, 1182811, 1183811, 1184811, 1185811, 1186811, 1187811, 1188811, 1189811, 1190911, 1191911, 1192911, 1193911, 1194911, 1195911, 1196911, 1197911, 1198911, 1199911, -1};
int memo[1200001];
int rub()
{
    memo[1] = 1;
    int ptr = 1, i = 1;
    while (v[ptr] != -1)
    {
        for (int j = i+1; j < v[ptr]; j++)
            memo[j] = memo[i];
        memo[v[ptr]] = memo[i]+1;
        i = v[ptr];
        ptr++;
    }
}

int main()
{
    sieve();
    rub();
    

    long long P,Q; cin >> P >> Q;
    int ans = -1;
    for (int i = 1200000; i > 0; i--)
        if (Q*pi[i]<=P*memo[i])
        {
            cout << i << endl;
            return 0;
        }
    cout << "Palindromic tree is better than splay tree" << endl;
}
