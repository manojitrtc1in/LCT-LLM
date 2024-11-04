#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, k;
ll dp[19][100010];
int mu[100010], np[100010], prime[100010], cnt;
vector < int > f[8] = {
{512,768,1024,1152,1280,1536,1664,1792,1920,2048,2176,2304,2368,2432,2560,2688,2816,2944,3072,3200,3328,3456,3520,3584,3712,3840,3904,3968,4096,4224,4352,4480,4608,4672,4736,4800,4864,4928,4992,5120,5184,5248,5376,5440,5504,5632,5760,5824,5888,6016,6144,6208,6272,6336,6400,6464,6528,6656,6784,6912,6976,7040,7104,7168,7232,7296,7424,7488,7552,7680,7744,7808,7872,7936,8000,8064,8128,8192,8320,8448,8512,8576,8640,8704,8768,8832,8896,8960,9024,9088,9216,9280,9344,9408,9472,9536,9600,9664,9728,9792,9856,9920,9984,10048,10112,10176,10240,10304,10368,10432,10496,10560,10624,10688,10752,10816,10880,10944,11008,11072,11136,11200,11264,11392,11520,11584,11648,11712,11776,11840,11904,11968,12032,12096,12160,12224,12288,12352,12416,12480,12544,12608,12672,12736,12800,12864,12928,12992,13056,13120,13184,13248,13312,13376,13440,13504,13568,13632,13696,13760,13824,13888,13952,14016,14080,14144,14208,14272,14336,14400,14464,14528,14592,14656,14720,14784,14848,14912,14976,15040,15104,15168,15232,15296,15360,15424,15488,15552,15616,15680,15744,15808,15872,15936,16000,16064,16128,16192,16256,16320,16384,16448,16512,16576,16640,16704,16768,16832,16896,16960,17024,17088,17152,17216,17280,17312,17344,17408,17472,17536,17600,17664,17728,17792,17856,17888,17920,17984,18048,18112,18176,18240,18304,18368,18432,18464,18496,18560,18624,18688,18752,18816,18880,18944,19008,19072,19136,19200,19264,19328,19392,19456,19520,19584,19648,19712,19776,19840,19904,19968,20032,20096,20160,20224,20288,20352,20416,20480,20544,20608,20672,20736,20768,20800,20864,20928,20992,21056,21120,21184,21248,21312,21376,21440,21504,21568,21632,21696,21760,21824,21888,21920,21952,22016,22080,22144,22208,22272,22336,22400,22464,22528,22592,22656,22720,22784,22848,22912,22976,23040,23104,23168,23232,23296,23360,23424,23488,23552,23616,23680,23744,23808,23872,23936,24000,24064,24128,24192,24224,24256,24320,24384,24448,24512,24576,24640,24704,24768,24800,24832,24896,24960,25024,25088,25152,25216,25280,25344,25408,25472,25536,25600,25664,25728,25792,25856,25920,25952,25984,26048,26112,26176,26240,26304,26368,26432,26496,26528,26560,26624,26688,26752,26816,26880,26944,27008,27072,27104,27136,27200,27264,27328,27392,27456,27520,27584,27648,27680,27712,27776,27840,27904,27968,28032,28096,28160,28224,28256,28288,28352,28416,28480,28544,28608,28672,28736,28800,28832,28864,28928,28992,29056,29120,29184,29248,29312,29376,29408,29440,29504,29568,29632,29696,29760,29824,29888,29952,29984,30016,30080,30144,30208,30272,30336,30400,30464,30528,30560,30592,30656,30720,30784,30848,30912,30976,31040,31104,31136,31168,31232,31296,31360,31424,31488,31552,31616,31680,31712,31744,31808,31872,31936,32000,32064,32128,32192,32256,32288,32320,32384,32448,32512,32576,32640,32704,32768,32832,32864,32896,32960,33024,33088,33152,33216,33280,33344,33408,33440,33472,33536,33600,33664,33728,33792,33856,33920,33984,34016,34048,34112,34176,34240,34304,34368,34432,34496,34560,34592,34624,34656,34688,34752,34816,34880,34944,35008,35072,35136,35168,35200,35264,35328,35392,35456,35520,35584,35648,35712,35744,35776,35840,35904,35968,36032,36096,36160,36224,36288,36320,36352,36416,36480,36512,36544,36608,36672,36736,36800,36864,36896,36928,36992,37056,37120,37184,37248,37312,37376,37440,37472,37504,37568,37632,37696,37760,37824,37888,37952,38016,38048,38080,38144,38208,38272,38336,38400,38464,38528,38592,38624,38656,38720,38784,38848,38912,38976,39040,39104,39168,39200,39232,39296,39360,39424,39488,39552,39616,39680,39744,39776,39808,39872,39936,40000,40064,40128,40192,40256,40320,40352,40384,40416,40448,40512,40576,40640,40704,40768,40832,40896,40928,40960,41024,41088,41152,41216,41280,41344,41408,41472,41504,41536,41568,41600,41664,41728,41792,41856,41920,41984,42048,42080,42112,42176,42240,42272,42304,42368,42432,42496,42560,42624,42656,42688,42752,42816,42880,42912,42944,43008,43072,43136,43200,43232,43264,43328,43392,43456,43520,43584,43648,43712,43776,43808,43840,43904,43968,44032,44096,44160,44224,44288,44352,44384,44416,44480,44544,44608,44672,44736,44800,44864,44928,44960,44992,45056,45120,45184,45248,45312,45376,45440,45504,45536,45568,45632,45696,45728,45760,45792,45824,45888,45952,46016,46080,46112,46144,46176,46208,46240,46272,46336,46400,46464,46528,46592,46656,46688,46720,46784,46848,46912,46976,47040,47104,47168,47232,47264,47296,47360,47424,47488,47552,47616,47680,47744,47808,47840,47872,47936,48000,48032,48064,48128,48192,48256,48320,48384,48416,48448,48480,48512,48544,48576,48640,48672,48704,48768,48832,48896,48960,48992,49024,49088,49152,49216,49280,49344,49408,49472,49536,49568,49600,49664,49728,49792,49856,49920,49984,50048,50112,50144,50176,50240,50304,50368,50432,50496,50560,50624,50688,50720,50752,50784,50816,50848,50880,50944,50976,51008,51072,51104,51136,51200,51264,51296,51328,51392,51456,51520,51584,51648,51712,51776,51840,51872,51904,51968,52032,52096,52160,52224,52288,52352,52416,52448,52480,52544,52608,52672,52736,52800,52864,52928,52992,53024,53056,53120,53184,53248,53312,53376,53440,53504,53568,53600,53632,53696,53760,53792,53824,53856,53888,53952,54016,54080,54144,54176,54208,54240,54272,54304,54336,54400,54464,54528,54592,54656,54720,54752,54784,54848,54912,54976,55040,55104,55168,55232,55296,55328,55360,55392,55424,55456,55488,55552,55584,55616,55680,55744,55808,55872,55904,55936,56000,56064,56128,56192,56256,56320,56384,56448,56480,56512,56544,56576,56608,56640,56704,56768,56832,56896,56960,57024,57056,57088,57152,57216,57280,57344,57408,57472,57536,57600,57632,57664,57696,57728,57760,57792,57856,57888,57920,57984,58048,58112,58176,58208,58240,58304,58368,58432,58496,58560,58624,58688,58752,58784,58816,58880,58944,59008,59040,59072,59136,59168,59200,59264,59328,59360,59392,59456,59520,59552,59584,59648,59712,59776,59840,59904,59936,59968,60032,60096,60160,60224,60288,60352,60416,60480,60512,60544,60608,60672,60736,60800,60864,60928,60992,61056,61088,61120,61184,61248,61312,61344,61376,61440,61472,61504,61568,61632,61664,61696,61760,61824,61856,61888,61920,61952,62016,62080,62144,62208,62240,62272,62304,62336,62368,62400,62464,62528,62592,62656,62720,62784,62816,62848,62912,62976,63040,63104,63168,63232,63296,63360,63392,63424,63488,63552,63616,63680,63744,63808,63872,63936,63968,64000,64064,64128,64192,64256,64320,64384,64448,64512,64544,64576,64608,64640,64672,64704,64768,64800,64832,64896,64928,64960,65024,65088,65120,65152,65216,65280,65312,65344,65376,65408,65472,65536,65600,65664,65696,65728,65760,65792,65824,65856,65920,65984,66048,66112,66176,66240,66272,66304,66368,66432,66496,66560,66624,66688,66752,66816,66848,66880,66912,66944,66976,67008,67072,67104,67136,67200,67232,67264,67328,67392,67424,67456,67520,67584,67616,67648,67680,67712,67776,67840,67904,67968,68000,68032,68064,68096,68160,68224,68288,68352,68416,68480,68544,68576,68608,68672,68736,68800,68864,68928,68992,69056,69120,69152,69184,69216,69248,69280,69312,69376,69408,69440,69504,69536,69568,69632,69696,69728,69760,69824,69888,69920,69952,69984,70016,70080,70144,70208,70272,70304,70336,70368,70400,70432,70464,70528,70560,70592,70656,70688,70720,70784,70848,70880,70912,70976,71040,71072,71104,71136,71168,71232,71296,71360,71424,71456,71488,71552,71616,71680,71744,71808,71872,71936,72000,72032,72064,72128,72192,72256,72320,72384,72448,72512,72576,72608,72640,72672,72704,72736,72768,72832,72864,72896,72960,72992,73024,73088,73152,73184,73216,73280,73344,73408,73472,73536,73600,73664,73728,73760,73792,73824,73856,73888,73920,73984,74016,74048,74112,74176,74240,74304,74336,74368,74432,74496,74560,74624,74688,74752,74816,74880,74912,74944,74976,75008,75040,75072,75136,75168,75200,75264,75296,75328,75392,75456,75488,75520,75584,75648,75680,75712,75776,75840,75904,75968,76032,76064,76096,76160,76224,76288,76352,76416,76480,76544,76608,76640,76672,76736,76800,76832,76864,76896,76928,76992,77056,77120,77184,77216,77248,77280,77312,77344,77376,77440,77472,77504,77568,77632,77696,77760,77792,77824,77888,77952,77984,78016,78048,78080,78144,78208,78272,78336,78368,78400,78432,78464,78496,78528,78592,78624,78656,78720,78752,78784,78848,78912,78944,78976,79040,79104,79168,79232,79296,79360,79424,79488,79520,79552,79616,79680,79744,79776,79808,79872,79936,80000,80064,80096,80128,80192,80256,80320,80384,80448,80512,80576,80640,80672,80704,80736,80768,80800,80832,80896,80928,80960,81024,81056,81088,81152,81216,81248,81280,81344,81408,81440,81472,81504,81536,81600,81664,81728,81792,81824,81856,81920,81984,82048,82112,82176,82240,82304,82368,82400,82432,82496,82560,82592,82624,82688,82752,82816,82880,82944,82976,83008,83040,83072,83104,83136,83200,83232,83264,83328,83360,83392,83456,83520,83552,83584,83648,83712,83744,83776,83808,83840,83904,83968,84032,84096,84128,84160,84192,84224,84256,84288,84352,84384,84416,84480,84512,84544,84608,84672,84704,84736,84800,84864,84928,84992,85056,85120,85184,85248,85280,85312,85376,85440,85504,85568,85632,85696,85760,85824,85856,85888,85952,86016,86048,86080,86112,86144,86208,86272,86336,86400,86432,86464,86496,86528,86560,86592,86656,86688,86720,86784,86816,86848,86912,86976,87008,87040,87104,87168,87200,87232,87264,87296,87360,87424,87488,87552,87584,87616,87648,87680,87712,87744,87808,87840,87872,87936,87968,88000,88064,88128,88160,88192,88256,88320,88352,88384,88416,88448,88512,88576,88640,88704,88736,88768,88800,88832,88864,88896,88960,88992,89024,89088,89120,89152,89216,89280,89312,89344,89408,89472,89504,89536,89568,89600,89664,89728,89792,89856,89888,89920,89952,89984,90016,90048,90112,90144,90176,90240,90272,90304,90368,90432,90464,90496,90560,90624,90656,90688,90720,90752,90816,90880,90944,91008,91040,91072,91136,91200,91264,91296,91328,91392,91456,91520,91584,91616,91648,91712,91776,91840,91904,91968,92032,92096,92160,92192,92224,92256,92288,92320,92352,92416,92448,92480,92544,92576,92608,92672,92736,92768,92800,92864,92928,92960,92992,93024,93056,93120,93184,93248,93312,93344,93376,93408,93440,93472,93504,93568,93600,93632,93696,93728,93760,93824,93888,93920,93952,94016,94080,94112,94144,94176,94208,94272,94336,94400,94464,94496,94528,94560,94592,94624,94656,94720,94752,94784,94848,94880,94912,94976,95040,95072,95104,95168,95232,95264,95296,95328,95360,95424,95488,95552,95616,95648,95680,95712,95744,95808,95872,95936,96000,96064,96128,96192,96224,96256,96320,96384,96448,96512,96576,96640,96704,96768,96800,96832,96864,96896,96928,96960,97024,97056,97088,97152,97184,97216,97280,97344,97376,97408,97472,97536,97568,97600,97632,97664,97728,97792,97856,97920,97952,97984,98016,98048,98080,98112,98176,98208,98240,98304,98336,98368,98432,98496,98528,98560,98624,98688,98720,98752,98784,98816,98880,98944,99008,99072,99104,99136,99168,99200,99232,99264,99328,99360,99392,99456,99488,99520,99584,99648,99680,99712,99776,99840,99872,99904,99936,99968},
{1024,1536,2048,2304,2560,3072,3328,3584,3840,4096,4352,4608,4736,4864,5120,5376,5632,5888,6144,6400,6656,6912,7040,7168,7424,7680,7808,7936,8192,8448,8704,8960,9216,9344,9472,9600,9728,9856,9984,10240,10368,10496,10752,10880,11008,11264,11520,11648,11776,12032,12288,12416,12544,12672,12800,12928,13056,13312,13568,13824,13952,14080,14208,14336,14464,14592,14848,14976,15104,15360,15488,15616,15744,15872,16000,16128,16256,16384,16640,16896,17024,17152,17280,17408,17536,17664,17792,17920,18048,18176,18432,18560,18688,18816,18944,19072,19200,19328,19456,19584,19712,19840,19968,20096,20224,20352,20480,20608,20736,20864,20992,21120,21248,21376,21504,21632,21760,21888,22016,22144,22272,22400,22528,22784,23040,23168,23296,23424,23552,23680,23808,23936,24064,24192,24320,24448,24576,24704,24832,24960,25088,25216,25344,25472,25600,25728,25856,25984,26112,26240,26368,26496,26624,26752,26880,27008,27136,27264,27392,27520,27648,27776,27904,28032,28160,28288,28416,28544,28672,28800,28928,29056,29184,29312,29440,29568,29696,29824,29952,30080,30208,30336,30464,30592,30720,30848,30976,31104,31232,31360,31488,31616,31744,31872,32000,32128,32256,32384,32512,32640,32768,32896,33024,33152,33280,33408,33536,33664,33792,33920,34048,34176,34304,34432,34560,34624,34688,34816,34944,35072,35200,35328,35456,35584,35712,35776,35840,35968,36096,36224,36352,36480,36608,36736,36864,36928,36992,37120,37248,37376,37504,37632,37760,37888,38016,38144,38272,38400,38528,38656,38784,38912,39040,39168,39296,39424,39552,39680,39808,39936,40064,40192,40320,40448,40576,40704,40832,40960,41088,41216,41344,41472,41536,41600,41728,41856,41984,42112,42240,42368,42496,42624,42752,42880,43008,43136,43264,43392,43520,43648,43776,43840,43904,44032,44160,44288,44416,44544,44672,44800,44928,45056,45184,45312,45440,45568,45696,45824,45952,46080,46208,46336,46464,46592,46720,46848,46976,47104,47232,47360,47488,47616,47744,47872,48000,48128,48256,48384,48448,48512,48640,48768,48896,49024,49152,49280,49408,49536,49600,49664,49792,49920,50048,50176,50304,50432,50560,50688,50816,50944,51072,51200,51328,51456,51584,51712,51840,51904,51968,52096,52224,52352,52480,52608,52736,52864,52992,53056,53120,53248,53376,53504,53632,53760,53888,54016,54144,54208,54272,54400,54528,54656,54784,54912,55040,55168,55296,55360,55424,55552,55680,55808,55936,56064,56192,56320,56448,56512,56576,56704,56832,56960,57088,57216,57344,57472,57600,57664,57728,57856,57984,58112,58240,58368,58496,58624,58752,58816,58880,59008,59136,59264,59392,59520,59648,59776,59904,59968,60032,60160,60288,60416,60544,60672,60800,60928,61056,61120,61184,61312,61440,61568,61696,61824,61952,62080,62208,62272,62336,62464,62592,62720,62848,62976,63104,63232,63360,63424,63488,63616,63744,63872,64000,64128,64256,64384,64512,64576,64640,64768,64896,65024,65152,65280,65408,65536,65664,65728,65792,65920,66048,66176,66304,66432,66560,66688,66816,66880,66944,67072,67200,67328,67456,67584,67712,67840,67968,68032,68096,68224,68352,68480,68608,68736,68864,68992,69120,69184,69248,69312,69376,69504,69632,69760,69888,70016,70144,70272,70336,70400,70528,70656,70784,70912,71040,71168,71296,71424,71488,71552,71680,71808,71936,72064,72192,72320,72448,72576,72640,72704,72832,72960,73024,73088,73216,73344,73472,73600,73728,73792,73856,73984,74112,74240,74368,74496,74624,74752,74880,74944,75008,75136,75264,75392,75520,75648,75776,75904,76032,76096,76160,76288,76416,76544,76672,76800,76928,77056,77184,77248,77312,77440,77568,77696,77824,77952,78080,78208,78336,78400,78464,78592,78720,78848,78976,79104,79232,79360,79488,79552,79616,79744,79872,80000,80128,80256,80384,80512,80640,80704,80768,80832,80896,81024,81152,81280,81408,81536,81664,81792,81856,81920,82048,82176,82304,82432,82560,82688,82816,82944,83008,83072,83136,83200,83328,83456,83584,83712,83840,83968,84096,84160,84224,84352,84480,84544,84608,84736,84864,84992,85120,85248,85312,85376,85504,85632,85760,85824,85888,86016,86144,86272,86400,86464,86528,86656,86784,86912,87040,87168,87296,87424,87552,87616,87680,87808,87936,88064,88192,88320,88448,88576,88704,88768,88832,88960,89088,89216,89344,89472,89600,89728,89856,89920,89984,90112,90240,90368,90496,90624,90752,90880,91008,91072,91136,91264,91392,91456,91520,91584,91648,91776,91904,92032,92160,92224,92288,92352,92416,92480,92544,92672,92800,92928,93056,93184,93312,93376,93440,93568,93696,93824,93952,94080,94208,94336,94464,94528,94592,94720,94848,94976,95104,95232,95360,95488,95616,95680,95744,95872,96000,96064,96128,96256,96384,96512,96640,96768,96832,96896,96960,97024,97088,97152,97280,97344,97408,97536,97664,97792,97920,97984,98048,98176,98304,98432,98560,98688,98816,98944,99072,99136,99200,99328,99456,99584,99712,99840,99968},
{2048,3072,4096,4608,5120,6144,6656,7168,7680,8192,8704,9216,9472,9728,10240,10752,11264,11776,12288,12800,13312,13824,14080,14336,14848,15360,15616,15872,16384,16896,17408,17920,18432,18688,18944,19200,19456,19712,19968,20480,20736,20992,21504,21760,22016,22528,23040,23296,23552,24064,24576,24832,25088,25344,25600,25856,26112,26624,27136,27648,27904,28160,28416,28672,28928,29184,29696,29952,30208,30720,30976,31232,31488,31744,32000,32256,32512,32768,33280,33792,34048,34304,34560,34816,35072,35328,35584,35840,36096,36352,36864,37120,37376,37632,37888,38144,38400,38656,38912,39168,39424,39680,39936,40192,40448,40704,40960,41216,41472,41728,41984,42240,42496,42752,43008,43264,43520,43776,44032,44288,44544,44800,45056,45568,46080,46336,46592,46848,47104,47360,47616,47872,48128,48384,48640,48896,49152,49408,49664,49920,50176,50432,50688,50944,51200,51456,51712,51968,52224,52480,52736,52992,53248,53504,53760,54016,54272,54528,54784,55040,55296,55552,55808,56064,56320,56576,56832,57088,57344,57600,57856,58112,58368,58624,58880,59136,59392,59648,59904,60160,60416,60672,60928,61184,61440,61696,61952,62208,62464,62720,62976,63232,63488,63744,64000,64256,64512,64768,65024,65280,65536,65792,66048,66304,66560,66816,67072,67328,67584,67840,68096,68352,68608,68864,69120,69248,69376,69632,69888,70144,70400,70656,70912,71168,71424,71552,71680,71936,72192,72448,72704,72960,73216,73472,73728,73856,73984,74240,74496,74752,75008,75264,75520,75776,76032,76288,76544,76800,77056,77312,77568,77824,78080,78336,78592,78848,79104,79360,79616,79872,80128,80384,80640,80896,81152,81408,81664,81920,82176,82432,82688,82944,83072,83200,83456,83712,83968,84224,84480,84736,84992,85248,85504,85760,86016,86272,86528,86784,87040,87296,87552,87680,87808,88064,88320,88576,88832,89088,89344,89600,89856,90112,90368,90624,90880,91136,91392,91648,91904,92160,92416,92672,92928,93184,93440,93696,93952,94208,94464,94720,94976,95232,95488,95744,96000,96256,96512,96768,96896,97024,97280,97536,97792,98048,98304,98560,98816,99072,99200,99328,99584,99840},
{4096,6144,8192,9216,10240,12288,13312,14336,15360,16384,17408,18432,18944,19456,20480,21504,22528,23552,24576,25600,26624,27648,28160,28672,29696,30720,31232,31744,32768,33792,34816,35840,36864,37376,37888,38400,38912,39424,39936,40960,41472,41984,43008,43520,44032,45056,46080,46592,47104,48128,49152,49664,50176,50688,51200,51712,52224,53248,54272,55296,55808,56320,56832,57344,57856,58368,59392,59904,60416,61440,61952,62464,62976,63488,64000,64512,65024,65536,66560,67584,68096,68608,69120,69632,70144,70656,71168,71680,72192,72704,73728,74240,74752,75264,75776,76288,76800,77312,77824,78336,78848,79360,79872,80384,80896,81408,81920,82432,82944,83456,83968,84480,84992,85504,86016,86528,87040,87552,88064,88576,89088,89600,90112,91136,92160,92672,93184,93696,94208,94720,95232,95744,96256,96768,97280,97792,98304,98816,99328,99840},
{8192,12288,16384,18432,20480,24576,26624,28672,30720,32768,34816,36864,37888,38912,40960,43008,45056,47104,49152,51200,53248,55296,56320,57344,59392,61440,62464,63488,65536,67584,69632,71680,73728,74752,75776,76800,77824,78848,79872,81920,82944,83968,86016,87040,88064,90112,92160,93184,94208,96256,98304,99328},
{16384,24576,32768,36864,40960,49152,53248,57344,61440,65536,69632,73728,75776,77824,81920,86016,90112,94208,98304},
{32768,49152,65536,73728,81920,98304},
{65536,98304}
};
int a[100010], b[100010];
ll c[100010];
ll curans;
vector < int > son[100010];
inline void add_a(int x, int k) {
    for (int i = x; i <= n; i += x) {
        a[i] += k * mu[i / x];
        curans += k * mu[i / x] * c[i];
    }
}
inline void add_b(int x, int k) {
    for (auto i : son[x]) {
        b[i] += k;
        curans -= a[i] * c[i];
        c[i] = 1ll * b[i] * (b[i] + 1) / 2;
        curans += a[i] * c[i];
    }
}
struct node {
    int l, r;
    int L, R;
};
vector < node > cur, tmp;
inline void calc(ll *X, ll *Y, int n) {
    cur.clear();
    cur.push_back({1, n, 0, n - 1});
    while (cur.size()) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        curans = 0;
        int l = 0, r = 0;
        tmp.clear();
        for (auto i : cur) {
            if (i.l > i.r) continue;
            int mid = (i.l + i.r) >> 1;
            while (r < mid) {
                r++;
                add_a(r, 1);
                add_b(r, 1);
            }
            int pos = l;
            ll qwq = curans + X[l];
            while (l + 1 <= mid && l + 1 <= i.R) {
                ++l;
                add_a(l, -1);
                add_b(l, -1);
                if (curans + X[l] < qwq) qwq = curans + X[l], pos = l;
            }
            tmp.push_back({i.l, mid - 1, i.L, pos});
            tmp.push_back({mid + 1, i.r, pos, i.R});
            Y[mid] = qwq;
        }
        cur = tmp;
    }
}
void init() {
    n = 100000, k = 16;
    mu[1] = np[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (np[i] == 0) mu[i] = -1, prime[++cnt] = i;
        for (int j = 1; i * prime[j] <= n; j++) {
            np[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i) son[j].push_back(i);
    for (int i = 1; i <= n; i++) dp[1][i] = 1ll * i * (i + 1) / 2;
    for (int d = 2; d <= 8; d++) calc(dp[d - 1], dp[d], n);
    for (int d = 9; d <= k; d++) {
        int j = 0, p = 0;
        for (int i = 1; i <= n; i++) {
            j++;
            while (p < f[d - 9].size() && f[d - 9][p] == i) p++, j++;
            dp[d][i] = j;
        }
    }
}
void rmain() {
    scanf("%d%d", &n, &k);
    if (k >= 17) return printf("%d\n", n), void();
    else printf("%lld\n", dp[k][n]);
}
int main() {
    init();
    scanf("%d", &t);
    while (t--) rmain();
}