 
#include <bits/stdc++.h>

using namespace std;

long long sum[1010] = {0,2786895,5684895,9031896,12412896,15793896,19174896,22555896,25936896,29317896,32698896,36079896,39460896,42841896,46222896,49603896,52984896,56365896,59746896,63127896,66508896,70032897,73896897,77760897,81624897,85488897,89352897,93216897,97080897,100944897,104808897,108672897,112536897,116400897,120264897,124128897,127992897,131856897,135720897,139584897,143448897,147312897,151176897,155040897,158904897,162768897,166632897,170496897,174360897,178224897,182088897,185952897,189816897,193680897,197544897,201408897,205272897,209136897,213000897,216864897,220728897,224592897,228456897,232320897,236184897,240048897,243912897,247776897,251640897,255504897,259368897,263232897,267096897,270960897,274824897,278688897,282552897,286416897,290280897,294144897,298008897,301872897,305736897,309600897,313464897,317328897,321192897,325056897,328920897,332784897,336648897,340512897,344376897,348240897,352104897,355968897,359832897,363696897,367560897,371424897,375288897,379152897,383016897,386880897,390744897,394608897,398472897,402336897,406200897,410064897,413928897,417792897,421656897,425520897,429384897,433248897,437112897,440976897,444840897,448704897,452568897,456432897,460296897,464160897,468024897,471888897,475752897,479616897,483480897,487344897,491208897,495072897,498936897,502800897,506664897,510528897,514392897,518256897,522120897,525984897,529848897,533712897,537576897,541440897,545304897,549168897,553032897,556896897,560760897,564624897,568488897,572352897,576216897,580080897,583944897,587808897,591672897,595536897,599400897,603264897,607128897,610992897,614856897,618720897,622584897,626448897,630312897,634176897,638040897,641904897,645768897,649632897,653496897,657360897,661224897,665088897,668952897,672816897,676680897,680544897,684408897,688272897,692136897,696000897,699864897,703728897,707592897,711456897,715320897,719184897,723048897,726912897,730776897,734640897,738504897,742368897,746232897,750096897,753960897,757824897,761688897,765552897,769416897,773280897,777144897,781008897,784872897,788736897,793064898,797411898,801758898,806105898,810452898,814799898,819146898,823493898,827840898,832187898,836534898,840881898,845228898,849575898,853922898,858269898,862616898,866963898,871310898,875657898,880004898,884351898,888698898,893045898,897392898,901739898,906086898,910433898,914780898,919127898,923474898,927821898,932168898,936515898,940862898,945209898,949556898,953903898,958250898,962597898,966944898,971291898,975638898,979985898,984332898,988679898,993026898,997373898,1001720898,1006067898,1010414898,1014761898,1019108898,1023455898,1027802898,1032149898,1036496898,1040843898,1045190898,1049537898,1053884898,1058231898,1062578898,1066925898,1071272898,1075619898,1079966898,1084313898,1088660898,1093007898,1097354898,1101701898,1106048898,1110395898,1114742898,1119089898,1123436898,1127783898,1132130898,1136477898,1140824898,1145171898,1149518898,1153865898,1158212898,1162559898,1166906898,1171253898,1175600898,1179947898,1184294898,1188641898,1192988898,1197335898,1201682898,1206029898,1210376898,1214723898,1219070898,1223417898,1227764898,1232111898,1236458898,1240805898,1245152898,1249499898,1253846898,1258193898,1262540898,1266887898,1271234898,1275581898,1279928898,1284275898,1288622898,1292969898,1297316898,1301663898,1306010898,1310357898,1314704898,1319051898,1323398898,1327745898,1332092898,1336439898,1340786898,1345133898,1349480898,1353827898,1358174898,1362521898,1366868898,1371215898,1375562898,1379909898,1384256898,1388603898,1392950898,1397297898,1401644898,1405991898,1410338898,1414685898,1419032898,1423379898,1427726898,1432073898,1436420898,1440767898,1445114898,1449461898,1453808898,1458155898,1462502898,1466849898,1471196898,1475543898,1479890898,1484237898,1488584898,1492931898,1497278898,1501625898,1505972898,1510319898,1514666898,1519013898,1523360898,1527707898,1532054898,1536401898,1540748898,1545095898,1549442898,1553789898,1558136898,1562483898,1566830898,1571177898,1575524898,1579871898,1584218898,1588565898,1592912898,1597259898,1601606898,1605953898,1610300898,1614647898,1618994898,1623341898,1627688898,1632035898,1636382898,1640729898,1645076898,1649423898,1653770898,1658117898,1662464898,1666811898,1671158898,1675505898,1679852898,1684199898,1688546898,1692893898,1697240898,1701587898,1705934898,1710281898,1714628898,1718975898,1723322898,1727669898,1732016898,1736363898,1740710898,1745057898,1749404898,1753751898,1758098898,1762445898,1766792898,1771139898,1775486898,1779833898,1784180898,1788527898,1792874898,1797221898,1801568898,1805915898,1810262898,1814609898,1818956898,1823303898,1827650898,1831997898,1836344898,1840691898,1845038898,1849385898,1853732898,1858079898,1862426898,1866773898,1871120898,1875467898,1879814898,1884161898,1888508898,1892855898,1897202898,1901549898,1905896898,1910243898,1914590898,1918937898,1923284898,1927631898,1931978898,1936325898,1940672898,1945019898,1949366898,1953713898,1958060898,1962407898,1966754898,1971101898,1975448898,1979795898,1984142898,1988489898,1992836898,1997183898,2001530898,2005877898,2010224898,2014571898,2018918898,2023265898,2027612898,2031959898,2036306898,2040653898,2045000898,2049347898,2053694898,2058041898,2062388898,2066735898,2071082898,2075429898,2079776898,2084123898,2088470898,2092817898,2097164898,2101511898,2105858898,2110205898,2114552898,2118899898,2123246898,2127593898,2131940898,2136287898,2140634898,2144981898,2149328898,2153675898,2158022898,2162369898,2166716898,2171063898,2175410898,2179757898,2184104898,2188451898,2192798898,2197145898,2201492898,2205839898,2210186898,2214533898,2218880898,2223227898,2227574898,2231921898,2236268898,2240615898,2244962898,2249309898,2253656898,2258003898,2262350898,2266697898,2271044898,2275391898,2279738898,2284085898,2288432898,2292779898,2297126898,2301473898,2305820898,2310167898,2314514898,2318861898,2323208898,2327555898,2331902898,2336249898,2340596898,2344943898,2349290898,2353637898,2357984898,2362331898,2366678898,2371025898,2375372898,2379719898,2384066898,2388413898,2392760898,2397107898,2401454898,2405801898,2410148898,2414495898,2418842898,2423189898,2427536898,2431883898,2436230898,2440577898,2444924898,2449271898,2453618898,2457965898,2462312898,2466659898,2471006898,2475353898,2479700898,2484047898,2488394898,2492741898,2497088898,2501435898,2505782898,2510129898,2514476898,2518823898,2523170898,2527517898,2531864898,2536211898,2540558898,2544905898,2549252898,2553599898,2557946898,2562293898,2566640898,2570987898,2575334898,2579681898,2584028898,2588375898,2592722898,2597069898,2601416898,2605763898,2610110898,2614457898,2618804898,2623151898,2627498898,2631845898,2636192898,2640539898,2644886898,2649233898,2653580898,2657927898,2662274898,2666621898,2670968898,2675315898,2679662898,2684009898,2688356898,2692703898,2697050898,2701397898,2705744898,2710091898,2714438898,2718785898,2723132898,2727479898,2731826898,2736173898,2740520898,2744867898,2749214898,2753561898,2757908898,2762255898,2766602898,2770949898,2775296898,2779643898,2783990898,2788337898,2792684898,2797031898,2801378898,2805725898,2810072898,2814419898,2818766898,2823113898,2827460898,2831807898,2836154898,2840501898,2844848898,2849195898,2853542898,2857889898,2862236898,2866583898,2870930898,2875277898,2879624898,2883971898,2888318898,2892665898,2897012898,2901359898,2905706898,2910053898,2914400898,2918747898,2923094898,2927441898,2931788898,2936135898,2940482898,2944829898,2949176898,2953523898,2957870898,2962217898,2966564898,2970911898,2975258898,2979605898,2983952898,2988299898,2992646898,2996993898,3001340898,3005687898,3010034898,3014381898,3018728898,3023075898,3027422898,3031769898,3036116898,3040463898,3044810898,3049157898,3053504898,3057851898,3062198898,3066545898,3070892898,3075239898,3079586898,3083933898,3088280898,3092627898,3096974898,3101321898,3105668898,3110015898,3114362898,3118709898,3123056898,3127403898,3131750898,3136097898,3140444898,3144791898,3149138898,3153485898,3157832898,3162179898,3166526898,3170873898,3175220898,3179567898,3183914898,3188261898,3192608898,3196955898,3201302898,3205649898,3209996898,3214343898,3218690898,3223037898,3227384898,3231731898,3236078898,3240425898,3244772898,3249119898,3253466898,3257813898,3262160898,3266507898,3270854898,3275201898,3279548898,3283895898,3288242898,3292589898,3296936898,3301283898,3305630898,3309977898,3314324898,3318671898,3323018898,3327365898,3331712898,3336059898,3340406898,3344753898,3349100898,3353447898,3357794898,3362141898,3366488898,3370835898,3375182898,3379529898,3383876898,3388223898,3392570898,3396917898,3401264898,3405611898,3409958898,3414305898,3418652898,3422999898,3427346898,3431693898,3436040898,3440387898,3444734898,3449081898,3453428898,3457775898,3462122898,3466469898,3470816898,3475163898,3479510898,3483857898,3488204898,3492551898,3496898898,3501245898,3505592898,3509939898,3514286898,3518633898,3522980898,3527327898,3531674898,3536021898,3540368898,3544715898,3549062898,3553409898,3557756898,3562103898,3566450898,3570797898,3575144898,3579491898,3583838898,3588185898,3592532898,3596879898,3601226898,3605573898,3609920898,3614267898,3618614898,3622961898,3627308898,3631655898,3636002898,3640349898,3644696898,3649043898,3653390898,3657737898,3662084898,3666431898,3670778898,3675125898,3679472898,3683819898,3688166898,3692513898,3696860898,3701207898,3705554898,3709901898,3714248898,3718595898,3722942898,3727289898,3731636898,3735983898,3740330898,3744677898,3749024898,3753371898,3757718898,3762065898,3766412898,3770759898,3775106898,3779453898,3783800898,3788147898,3792494898,3796841898,3801188898,3805535898,3809882898,3814229898,3818576898,3822923898,3827270898,3831617898,3835964898,3840311898,3844658898,3849005898,3853352898,3857699898,3862046898,3866393898,3870740898,3875087898,3879434898,3883781898,3888128898,3892475898,3896822898,3901169898,3905516898,3909863898,3914210898,3918557898,3922904898,3927251898,3931598898,3935945898,3940292898,3944639898,3948986898,3953333898,3957680898,3962027898,3966374898,3970721898,3975068898,3979415898,3983762898,3988109898,3992456898,3996803898,4001150898,4005497898,4009844898,4014191898,4018538898,4022885898,4027232898,4031579898,4035926898,4040273898,4044620898,4048967898,4053314898,4057661898,4062008898,4066355898,4070702898,4075049898,4079396898,4083743898,4088090898,4092437898,4096784898,4101131898,4105478898,4109825898,4114172898,4118519898,4122866898,4127213898,4131560898,4135907898,4140254898,4144601898,4148948898,4153295898,4157642898,4161989898,4166336898,4170683898,4175030898,4179377898,4183724898,4188071898,4192418898,4196765898,4201112898,4205459898,4209806898,4214153898,4218500898,4222847898,4227194898,4231541898,4235888898};
long long Ssum[1010] = {0,651255072390,2697193806390,6243667713891,11422586672391,18234528630891,26679493589391,36757481547891,48468492506391,61812526464891,76789583423391,93399663381891,111642766340391,131518892298891,153028041257391,176170213215891,200945408174391,227353626132891,255394867091391,285069131049891,316376418008391,349326952681392,384085999864392,420711359047392,459203030230392,499561013413392,541785308596392,585875915779392,631832834962392,679656066145392,729345609328392,780901464511392,834323631694392,889612110877392,946766902060392,1005788005243392,1066675420426392,1129429147609392,1194049186792392,1260535537975392,1328888201158392,1399107176341392,1471192463524392,1545144062707392,1620961973890392,1698646197073392,1778196732256392,1859613579439392,1942896738622392,2028046209805392,2115061992988392,2203944088171392,2294692495354392,2387307214537392,2481788245720392,2578135588903392,2676349244086392,2776429211269392,2878375490452392,2982188081635392,3087866984818392,3195412200001392,3304823727184392,3416101566367392,3529245717550392,3644256180733392,3761132955916392,3879876043099392,4000485442282392,4122961153465392,4247303176648392,4373511511831392,4501586159014392,4631527118197392,4763334389380392,4897007972563392,5032547867746392,5169954074929392,5309226594112392,5450365425295392,5593370568478392,5738242023661392,5884979790844392,6033583870027392,6184054261210392,6336390964393392,6490593979576392,6646663306759392,6804598945942392,6964400897125392,7126069160308392,7289603735491392,7455004622674392,7622271821857392,7791405333040392,7962405156223392,8135271291406392,8310003738589392,8486602497772392,8665067568955392,8845398952138392,9027596647321392,9211660654504392,9397590973687392,9585387604870392,9775050548053392,9966579803236392,10159975370419392,10355237249602392,10552365440785392,10751359943968392,10952220759151392,11154947886334392,11359541325517392,11566001076700392,11774327139883392,11984519515066392,12196578202249392,12410503201432392,12626294512615392,12843952135798392,13063476070981392,13284866318164392,13508122877347392,13733245748530392,13960234931713392,14189090426896392,14419812234079392,14652400353262392,14886854784445392,15123175527628392,15361362582811392,15601415949994392,15843335629177392,16087121620360392,16332773923543392,16580292538726392,16829677465909392,17080928705092392,17334046256275392,17589030119458392,17845880294641392,18104596781824392,18365179581007392,18627628692190392,18891944115373392,19158125850556392,19426173897739392,19696088256922392,19967868928105392,20241515911288392,20517029206471392,20794408813654392,21073654732837392,21354766964020392,21637745507203392,21922590362386392,22209301529569392,22497879008752392,22788322799935392,23080632903118392,23374809318301392,23670852045484392,23968761084667392,24268536435850392,24570178099033392,24873686074216392,25179060361399392,25486300960582392,25795407871765392,26106381094948392,26419220630131392,26733926477314392,27050498636497392,27368937107680392,27689241890863392,28011412986046392,28335450393229392,28661354112412392,28989124143595392,29318760486778392,29650263141961392,29983632109144392,30318867388327392,30655968979510392,30994936882693392,31335771097876392,31678471625059392,32023038464242392,32369471615425392,32717771078608392,33067936853791392,33419968940974392,33773867340157392,34129632051340392,34487263074523392,34846760409706392,35208124056889392,35571354016072392,35936450287255392,36303412870438392,36672241765621392,37042936972804392,37415498491987392,37789926323170392,38166220466353392,38544380921536392,38924407688719392,39306408416598393,39690508565005893,40076708314413393,40465007664820893,40855406616228393,41247905168635893,41642503322043393,42039201076450893,42437998431858393,42838895388265893,43241891945673393,43646988104080893,44054183863488393,44463479223895893,44874874185303393,45288368747710893,45703962911118393,46121656675525893,46541450040933393,46963343007340893,47387335574748393,47813427743155893,48241619512563393,48671910882970893,49104301854378393,49538792426785893,49975382600193393,50414072374600893,50854861750008393,51297750726415893,51742739303823393,52189827482230893,52639015261638393,53090302642045893,53543689623453393,53999176205860893,54456762389268393,54916448173675893,55378233559083393,55842118545490893,56308103132898393,56776187321305893,57246371110713393,57718654501120893,58193037492528393,58669520084935893,59148102278343393,59628784072750893,60111565468158393,60596446464565893,61083427061973393,61572507260380893,62063687059788393,62556966460195893,63052345461603393,63549824064010893,64049402267418393,64551080071825893,65054857477233393,65560734483640893,66068711091048393,66578787299455893,67090963108863393,67605238519270893,68121613530678393,68640088143085893,69160662356493393,69683336170900893,70208109586308393,70734982602715893,71263955220123393,71795027438530893,72328199257938393,72863470678345893,73400841699753393,73940312322160893,74481882545568393,75025552369975893,75571321795383393,76119190821790893,76669159449198393,77221227677605893,77775395507013393,78331662937420893,78890029968828393,79450496601235893,80013062834643393,80577728669050893,81144494104458393,81713359140865893,82284323778273393,82857388016680893,83432551856088393,84009815296495893,84589178337903393,85170640980310893,85754203223718393,86339865068125893,86927626513533393,87517487559940893,88109448207348393,88703508455755893,89299668305163393,89897927755570893,90498286806978393,91100745459385893,91705303712793393,92311961567200893,92920719022608393,93531576079015893,94144532736423393,94759588994830893,95376744854238393,95996000314645893,96617355376053393,97240810038460893,97866364301868393,98494018166275893,99123771631683393,99755624698090893,100389577365498393,101025629633905893,101663781503313393,102304032973720893,102946384045128393,103590834717535893,104237384990943393,104886034865350893,105536784340758393,106189633417165893,106844582094573393,107501630372980893,108160778252388393,108822025732795893,109485372814203393,110150819496610893,110818365780018393,111488011664425893,112159757149833393,112833602236240893,113509546923648393,114187591212055893,114867735101463393,115549978591870893,116234321683278393,116920764375685893,117609306669093393,118299948563500893,118992690058908393,119687531155315893,120384471852723393,121083512151130893,121784652050538393,122487891550945893,123193230652353393,123900669354760893,124610207658168393,125321845562575893,126035583067983393,126751420174390893,127469356881798393,128189393190205893,128911529099613393,129635764610020893,130362099721428393,131090534433835893,131821068747243393,132553702661650893,133288436177058393,134025269293465893,134764202010873393,135505234329280893,136248366248688393,136993597769095893,137740928890503393,138490359612910893,139241889936318393,139995519860725893,140751249386133393,141509078512540893,142269007239948393,143031035568355893,143795163497763393,144561391028170893,145329718159578393,146100144891985893,146872671225393393,147647297159800893,148424022695208393,149202847831615893,149983772569023393,150766796907430893,151551920846838393,152339144387245893,153128467528653393,153919890271060893,154713412614468393,155509034558875893,156306756104283393,157106577250690893,157908497998098393,158712518346505893,159518638295913393,160326857846320893,161137176997728393,161949595750135893,162764114103543393,163580732057950893,164399449613358393,165220266769765893,166043183527173393,166868199885580893,167695315844988393,168524531405395893,169355846566803393,170189261329210893,171024775692618393,171862389657025893,172702103222433393,173543916388840893,174387829156248393,175233841524655893,176081953494063393,176932165064470893,177784476235878393,178638887008285893,179495397381693393,180354007356100893,181214716931508393,182077526107915893,182942434885323393,183809443263730893,184678551243138393,185549758823545893,186423066004953393,187298472787360893,188175979170768393,189055585155175893,189937290740583393,190821095926990893,191707000714398393,192595005102805893,193485109092213393,194377312682620893,195271615874028393,196168018666435893,197066521059843393,197967123054250893,198869824649658393,199774625846065893,200681526643473393,201590527041880893,202501627041288393,203414826641695893,204330125843103393,205247524645510893,206167023048918393,207088621053325893,208012318658733393,208938115865140893,209866012672548393,210796009080955893,211728105090363393,212662300700770893,213598595912178393,214536990724585893,215477485137993393,216420079152400893,217364772767808393,218311565984215893,219260458801623393,220211451220030893,221164543239438393,222119734859845893,223077026081253393,224036416903660893,224997907327068393,225961497351475893,226927186976883393,227894976203290893,228864865030698393,229836853459105893,230810941488513393,231787129118920893,232765416350328393,233745803182735893,234728289616143393,235712875650550893,236699561285958393,237688346522365893,238679231359773393,239672215798180893,240667299837588393,241664483477995893,242663766719403393,243665149561810893,244668632005218393,245674214049625893,246681895695033393,247691676941440893,248703557788848393,249717538237255893,250733618286663393,251751797937070893,252772077188478393,253794456040885893,254818934494293393,255845512548700893,256874190204108393,257904967460515893,258937844317923393,259972820776330893,261009896835738393,262049072496145893,263090347757553393,264133722619960893,265179197083368393,266226771147775893,267276444813183393,268328218079590893,269382090946998393,270438063415405893,271496135484813393,272556307155220893,273618578426628393,274682949299035893,275749419772443393,276817989846850893,277888659522258393,278961428798665893,280036297676073393,281113266154480893,282192334233888393,283273501914295893,284356769195703393,285442136078110893,286529602561518393,287619168645925893,288710834331333393,289804599617740893,290900464505148393,291998428993555893,293098493082963393,294200656773370893,295304920064778393,296411282957185893,297519745450593393,298630307545000893,299742969240408393,300857730536815893,301974591434223393,303093551932630893,304214612032038393,305337771732445893,306463031033853393,307590389936260893,308719848439668393,309851406544075893,310985064249483393,312120821555890893,313258678463298393,314398634971705893,315540691081113393,316684846791520893,317831102102928393,318979457015335893,320129911528743393,321282465643150893,322437119358558393,323593872674965893,324752725592373393,325913678110780893,327076730230188393,328241881950595893,329409133272003393,330578484194410893,331749934717818393,332923484842225893,334099134567633393,335276883894040893,336456732821448393,337638681349855893,338822729479263393,340008877209670893,341197124541078393,342387471473485893,343579918006893393,344774464141300893,345971109876708393,347169855213115893,348370700150523393,349573644688930893,350778688828338393,351985832568745893,353195075910153393,354406418852560893,355619861395968393,356835403540375893,358053045285783393,359272786632190893,360494627579598393,361718568128005893,362944608277413393,364172748027820893,365402987379228393,366635326331635893,367869764885043393,369106303039450893,370344940794858393,371585678151265893,372828515108673393,374073451667080893,375320487826488393,376569623586895893,377820858948303393,379074193910710893,380329628474118393,381587162638525893,382846796403933393,384108529770340893,385372362737748393,386638295306155893,387906327475563393,389176459245970893,390448690617378393,391723021589785893,392999452163193393,394277982337600893,395558612113008393,396841341489415893,398126170466823393,399413099045230893,400702127224638393,401993255005045893,403286482386453393,404581809368860893,405879235952268393,407178762136675893,408480387922083393,409784113308490893,411089938295898393,412397862884305893,413707887073713393,415020010864120893,416334234255528393,417650557247935893,418968979841343393,420289502035750893,421612123831158393,422936845227565893,424263666224973393,425592586823380893,426923607022788393,428256726823195893,429591946224603393,430929265227010893,432268683830418393,433610202034825893,434953819840233393,436299537246640893,437647354254048393,438997270862455893,440349287071863393,441703402882270893,443059618293678393,444417933306085893,445778347919493393,447140862133900893,448505475949308393,449872189365715893,451241002383123393,452611915001530893,453984927220938393,455360039041345893,456737250462753393,458116561485160893,459497972108568393,460881482332975893,462267092158383393,463654801584790893,465044610612198393,466436519240605893,467830527470013393,469226635300420893,470624842731828393,472025149764235893,473427556397643393,474832062632050893,476238668467458393,477647373903865893,479058178941273393,480471083579680893,481886087819088393,483303191659495893,484722395100903393,486143698143310893,487567100786718393,488992603031125893,490420204876533393,491849906322940893,493281707370348393,494715608018755893,496151608268163393,497589708118570893,499029907569978393,500472206622385893,501916605275793393,503363103530200893,504811701385608393,506262398842015893,507715195899423393,509170092557830893,510627088817238393,512086184677645893,513547380139053393,515010675201460893,516476069864868393,517943564129275893,519413157994683393,520884851461090893,522358644528498393,523834537196905893,525312529466313393,526792621336720893,528274812808128393,529759103880535893,531245494553943393,532733984828350893,534224574703758393,535717264180165893,537212053257573393,538708941935980893,540207930215388393,541709018095795893,543212205577203393,544717492659610893,546224879343018393,547734365627425893,549245951512833393,550759636999240893,552275422086648393,553793306775055893,555313291064463393,556835374954870893,558359558446278393,559885841538685893,561414224232093393,562944706526500893,564477288421908393,566011969918315893,567548751015723393,569087631714130893,570628612013538393,572171691913945893,573716871415353393,575264150517760893,576813529221168393,578365007525575893,579918585430983393,581474262937390893,583032040044798393,584591916753205893,586153893062613393,587717968973020893,589284144484428393,590852419596835893,592422794310243393,593995268624650893,595569842540058393,597146516056465893,598725289173873393,600306161892280893,601889134211688393,603474206132095893,605061377653503393,606650648775910893,608242019499318393,609835489823725893,611431059749133393,613028729275540893,614628498402948393,616230367131355893,617834335460763393,619440403391170893,621048570922578393,622658838054985893,624271204788393393,625885671122800893,627502237058208393,629120902594615893,630741667732023393,632364532470430893,633989496809838393,635616560750245893,637245724291653393,638876987434060893,640510350177468393,642145812521875893,643783374467283393,645423036013690893,647064797161098393,648708657909505893,650354618258913393,652002678209320893,653652837760728393,655305096913135893,656959455666543393,658615914020950893,660274471976358393,661935129532765893,663597886690173393,665262743448580893,666929699807988393,668598755768395893,670269911329803393,671943166492210893,673618521255618393,675295975620025893,676975529585433393,678657183151840893,680340936319248393,682026789087655893,683714741457063393,685404793427470893,687096944998878393,688791196171285893,690487546944693393,692185997319100893,693886547294508393,695589196870915893,697293946048323393,699000794826730893,700709743206138393,702420791186545893,704133938767953393,705849185950360893,707566532733768393,709285979118175893,711007525103583393,712731170689990893,714456915877398393,716184760665805893,717914705055213393,719646749045620893,721380892637028393,723117135829435893,724855478622843393,726595921017250893,728338463012658393,730083104609065893,731829845806473393,733578686604880893,735329627004288393,737082667004695893,738837806606103393,740595045808510893,742354384611918393,744115823016325893,745879361021733393,747644998628140893,749412735835548393,751182572643955893,752954509053363393,754728545063770893,756504680675178393,758282915887585893,760063250700993393,761845685115400893,763630219130808393,765416852747215893,767205585964623393,768996418783030893,770789351202438393,772584383222845893,774381514844253393,776180746066660893,777982076890068393,779785507314475893,781591037339883393,783398666966290893,785208396193698393,787020225022105893,788834153451513393,790650181481920893,792468309113328393,794288536345735893,796110863179143393,797935289613550893,799761815648958393,801590441285365893,803421166522773393,805253991361180893,807088915800588393,808925939840995893,810765063482403393,812606286724810893,814449609568218393,816295032012625893,818142554058033393,819992175704440893,821843896951848393,823697717800255893,825553638249663393,827411658300070893,829271777951478393,831133997203885893,832998316057293393,834864734511700893,836733252567108393,838603870223515893,840476587480923393,842351404339330893,844228320798738393,846107336859145893,847988452520553393,849871667782960893,851756982646368393,853644397110775893,855533911176183393,857425524842590893,859319238109998393,861215050978405893,863112963447813393,865012975518220893,866915087189628393,868819298462035893,870725609335443393,872634019809850893,874544529885258393,876457139561665893,878371848839073393,880288657717480893,882207566196888393,884128574277295893,886051681958703393,887976889241110893,889904196124518393,891833602608925893,893765108694333393,895698714380740893,897634419668148393,899572224556555893,901512129045963393,903454133136370893,905398236827778393,907344440120185893,909292743013593393,911243145508000893,913195647603408393,915150249299815893,917106950597223393,919065751495630893,921026651995038393,922989652095445893,924954751796853393,926921951099260893,928891250002668393,930862648507075893,932836146612483393,934811744318890893,936789441626298393,938769238534705893,940751135044113393,942735131154520893,944721226865928393,946709422178335893,948699717091743393,950692111606150893,952686605721558393,954683199437965893,956681892755373393,958682685673780893,960685578193188393,962690570313595893,964697662035003393,966706853357410893,968718144280818393,970731534805225893,972747024930633393,974764614657040893,976784303984448393,978806092912855893,980829981442263393,982855969572670893,984884057304078393,986914244636485893,988946531569893393,990980918104300893,993017404239708393,995055989976115893,997096675313523393,999139460251930893,1001184344791338393};
long long A[20], k;

int main() {
	int T; scanf("%d", &T);
	for (int i = 2, j = 10; j <= 1000000000; j *= 10, i++) A[i] = j;
	while (T--) {
		scanf("%lld", &k);


		int x = lower_bound(Ssum+1, Ssum+1000+1, k)-Ssum;
		long long a = Ssum[x-1]; k -= a; a = sum[x-1];
		for (int i = (x-1)*483000+1; i <= x*483000; i++) {
			int j = i, n = upper_bound(A+1, A+10, i)-A-1;
			a += n;
			if (k <= a) {
				int xx = lower_bound(sum+1, sum+1000+1, k)-sum;
				k -= sum[xx-1];
				for (int j = (xx-1)*483000+1; j <= i; j++) {
					int K = j, N = upper_bound(A+1, A+10, j)-A-1;
					if (k <= N) {
						int tmp = N-k+1;
						while (tmp != 1) K /= 10, tmp--;
						printf("%d\n", K%10);
						break;
					}
					else k -= N;
				}
				break;
			}
			else k -= a;
		}
	}
	return 0;
}
   						 	   			  			 						 	