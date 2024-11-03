






































#define __STDC_FORMAT_MACROS
#include<inttypes.h>








#define _CAT(a,b) a##b
#define CAT(a,b) _CAT(a,b)
#define _10TH(a,b,c,d,e,f,g,h,i,CNT,...) CNT
#define VA_CNT(...) _10TH(__VA_ARGS__,9,8,7,6,5,4,3,2,1)
#define VA_SEL(a,...) CAT(a,VA_CNT(__VA_ARGS__))(__VA_ARGS__)

#define _VA_GTONE(...) _10TH(__VA_ARGS__,1,1,1,1,1,1,1,1,0)
#define VA_GTONE(a,...) CAT(a,_VA_GTONE(__VA_ARGS__))(__VA_ARGS__)

#define foreach(e,c) for(__typeof((c).begin())e=(c).begin();e!=(c).end();++e)


#define MIN_GCC(a,b,c) (__GNUC__ > (a) || \
              (__GNUC__ == (a) && (__GNUC_MINOR__ > (b) || \
                                 (__GNUC_MINOR__ == (b) && \
								 __GNUC_PATCHLEVEL__ >= (c)))))



								  
								  










#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<stdint.h>
#include<cstring>
#include<iostream>









#include<stdint.h>

#include<utility>




typedef unsigned int uint;


namespace ab{

typedef int8_t i8;
typedef uint8_t ui8;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;



typedef i64 ll;
typedef ui64 ull;

typedef std::pair<i32,i32> pii;
typedef std::vector<i32> vi;
#define VE std::vector
#define umap unordered_map

typedef unsigned short ushort;
typedef unsigned char uchar;

struct Void {};


template<typename I>struct FloatFrom{typedef Void R;};
template<>struct FloatFrom<i32>{typedef double R;};
template<>struct FloatFrom<ui32>{typedef double R;};
template<>struct FloatFrom<i64>{typedef long double R;};
template<>struct FloatFrom<ui64>{typedef long double R;};
template<>struct FloatFrom<i16>{typedef float R;};
template<>struct FloatFrom<ui16>{typedef float R;};
template<>struct FloatFrom<i8>{typedef float R;};
template<>struct FloatFrom<ui8>{typedef float R;};
template<>struct FloatFrom<float>{typedef float R;};
template<>struct FloatFrom<double>{typedef double R;};
template<>struct FloatFrom<long double>{typedef long double R;};

template<typename I>struct Double{typedef Void R;};
template<>struct Double<i8>{typedef i16 R;};
template<>struct Double<ui8>{typedef ui16 R;};
template<>struct Double<i16>{typedef i32 R;};
template<>struct Double<ui16>{typedef ui32 R;};
template<>struct Double<i32>{typedef i64 R;};
template<>struct Double<ui32>{typedef ui64 R;};

template<>struct Double<float>{typedef float R;};
template<>struct Double<double>{typedef double R;};
template<>struct Double<long double>{typedef long double R;};


#if defined __GNUC__ and ( __WORDSIZE == 64 )
typedef __int128_t i128;
typedef __uint128_t ui128;
template<>struct Double<i64>{typedef i128 R;};
template<>struct Double<ui64>{typedef ui128 R;};
#endif


}


#ifdef DEBUG
	#undef NDEBUG
	#pragma message "Compiling in DEBUG mode."
#else
	#define NDEBUG
#endif

#include <cstdio>
#include <cfloat>



#define  L0(str) 			fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__)
#define  L1(str,...)		fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__,__VA_ARGS__)

#define L(...) VA_GTONE(L,__VA_ARGS__)


#ifdef NDEBUG
	#define DE if(0)
#else
	#define DE
#endif


#if defined NDEBUG and not defined ASSERTS
	#define ASS(x)
	#define FLOAT_OK(x)
	#define ASSERT_FLOAT(x)
#else
	#include<cassert>
	#define ASS(x) assert(x);
	#define FLOAT_OK(x) ((x) <= LDBL_MAX && (x) >= -LDBL_MAX)
	#define ASSERT_FLOAT(f) ASS(FLOAT_OK(f))
#endif


#include<cstdlib>

namespace ab
{


const float probit1024[] = {-3.097558392975658,-2.885942132469943,-2.755868165559522,-2.660396199829992,-2.584356209392189,-2.520845717310525,-2.466120528560782,-2.417914221592359,-2.374747142477102,-2.335598149625034,-2.299731883252602,-2.266600620681125,-2.235785065792777,-2.20695686307142,-2.179853905073575,-2.154263517342249,-2.130010679262959,-2.106949569169807,-2.084957365441463,-2.06392961611032,-2.043776722506634,-2.024421229270474,-2.005795708001292,-1.987841084644705,-1.970505303170329,-1.953742247324262,-1.93751086271024,-1.921774436013785,-1.906499998688552,-1.891657830102795,-1.877221040824709,-1.863165220975591,-1.849468141792318,-1.836109500992796,-1.823070704426331,-1.810334677957496,-1.797885704680065,-1.785709283462875,-1.773792005548417,-1.762121446499574,-1.75068607125217,-1.739475150404887,-1.728478686182375,-1.717687346756155,-1.707092407812454,-1.696685700425005,-1.686459564430974,-1.676406806624952,-1.666520663183652,-1.656794765815982,-1.647223111202421,-1.637800033346129,-1.628520178507961,-1.619378482439964,-1.610370149668073,-1.601490634605835,-1.592735624307655,-1.584101022693083,-1.575582936093572,-1.567177659990391,-1.558881666827391,-1.550691594795363,-1.542604237496186,-1.534616534404904,-1.526725562056687,-1.518928525893307,-1.51122275271056,-1.503605683654058,-1.496074867716132,-1.488627955691257,-1.481262694551604,-1.473976922208031,-1.466768562625123,-1.459635621261844,-1.452576180812005,-1.445588397221092,-1.438670495958158,-1.431820768523329,-1.425037569173211,-1.418319311848047,-1.411664467285797,-1.405071560309632,-1.398539167276437,-1.392065913674922,-1.385650471862928,-1.379291558934291,-1.37298793470645,-1.366738399820644,-1.360541793947194,-1.354396994088954,-1.348302912976517,-1.342258497549272,-1.336262727516836,-1.330314613995774,-1.324413198216942,-1.318557550299055,-1.312746768084458,-1.306979976033318,-1.301256324172764,-1.295574987097688,-1.289935163020201,-1.284336072864907,-1.278776959407354,-1.273257086453213,-1.267775738055884,-1.262332217770371,-1.256925847941436,-1.251555969024137,-1.246221938934995,-1.240923132432152,-1.235658940522947,-1.230428769897494,-1.225232042386869,-1.220068194444647,-1.214936676650586,-1.209836953235313,-1.204768501624966,-1.199730812004785,-1.194723386900707,-1.189745740778077,-1.184797399656649,-1.179877900741064,-1.17498679206609,-1.170123632155891,-1.165287989696682,-1.160479443222132,-1.155697580810918,-1.150941999795884,-1.146212306484246,-1.141508115888377,-1.136829051466652,-1.132174744873943,-1.127544835721305,-1.12293897134446,-1.118356806580697,-1.113798003553811,-1.109262231466746,-1.104749166401602,-1.1002584911267,-1.095789894910401,-1.091343073341402,-1.086917728155233,-1.082513567066707,-1.078130303608069,-1.073767656972616,-1.069425351863572,-1.065103118347994,-1.060800691715526,-1.056517812341786,-1.052254225556229,-1.048009681514285,-1.043783935073628,-1.039576745674407,-1.035387877223279,-1.031217097981115,-1.02706418045423,-1.022928901289005,-1.018811041169779,-1.014710384719881,-1.010626720405697,-1.006559840443653,-1.002509540710008,-0.9984756206533578,-0.9944578832097531,-0.9904561347203336,-0.9864701848513928,-0.9824998465167862,-0.9785449358025993,-0.974605271893998,-0.970680677004187,-0.966770976305398,-0.9628759978618452,-0.9589955725645742,-0.9551295340681464,-0.9512777187290917,-0.9474399655460722,-0.9436161161017016,-0.9398060145059618,-0.9360095073411675,-0.9322264436084267,-0.9284566746755457,-0.9247000542263371,-0.9209564382112815,-0.9172256847994996,-0.913507654331996,-0.9098022092761303,-0.9061092141812808,-0.9024285356356578,-0.89876004222424,-0.8951036044877863,-0.8914590948829019,-0.8878263877431195,-0.884205359240965,-0.8805958873509807,-0.8769978518136744,-0.8734111341003672,-0.8698356173789145,-0.8662711864802711,-0.8627177278658789,-0.8591751295958504,-0.8556432812979253,-0.8521220741371801,-0.8486114007864618,-0.8451111553975357,-0.8416212335729143,-0.8381415323383598,-0.834671950116031,-0.8312123866982626,-0.8277627432219572,-0.8243229221435711,-0.8208928272146809,-0.8174723634581109,-0.8140614371446091,-0.8106599557700533,-0.8072678280331768,-0.8038849638137954,-0.8005112741515247,-0.7971466712249743,-0.7937910683314048,-0.7904443798668355,-0.7871065213065922,-0.7837774091862812,-0.7804569610831813,-0.7771450955980376,-0.773841732337253,-0.7705467918954627,-0.7672601958384825,-0.7639818666866213,-0.7607117278983514,-0.7574497038543204,-0.7541957198417045,-0.7509497020388882,-0.7477115775004644,-0.7444812741425476,-0.7412587207283911,-0.7380438468543002,-0.7348365829358366,-0.7316368601943033,-0.728444610643505,-0.7252597670767783,-0.7220822630542832,-0.7189120328905484,-0.7157490116422693,-0.7125931350963457,-0.7094443397581606,-0.7063025628400876,-0.7031677422502258,-0.7000398165813566,-0.6969187251001143,-0.693804407736368,-0.6906968050728098,-0.6875958583347421,-0.6845015093800632,-0.6814137006894415,-0.6783323753566807,-0.6752574770792632,-0.6721889501490763,-0.6691267394433105,-0.6660707904155284,-0.6630210490869014,-0.6599774620376083,-0.6569399763983937,-0.6539085398422818,-0.6508831005764422,-0.6478636073342042,-0.6448500093672185,-0.6418422564377582,-0.6388402988111609,-0.6358440872484065,-0.6328535729988283,-0.629868707792953,-0.6268894438354699,-0.6239157337983234,-0.6209475308139284,-0.6179847884685036,-0.6150274607955232,-0.6120755022692814,-0.6091288677985706,-0.606187512720466,-0.6032513927942216,-0.6003204641952662,-0.5973946835093068,-0.5944740077265291,-0.5915583942358984,-0.5886478008195554,-0.5857421856473083,-0.5828415072712162,-0.5799457246202626,-0.5770547969951191,-0.574168684062994,-0.5712873458525689,-0.5684107427490159,-0.5655388354890976,-0.5626715851563479,-0.5598089531763306,-0.5569509013119746,-0.5540973916589849,-0.5512483866413277,-0.5484038490067875,-0.5455637418225955,-0.5427280284711268,-0.5398966726456673,-0.5370696383462461,-0.5342468898755339,-0.5314283918348061,-0.5286141091199686,-0.5258040069176455,-0.522998050701327,-0.520196206227578,-0.5173984395323037,-0.514604716927073,-0.5118150049954981,-0.5090292705896695,-0.5062474808266438,-0.5034696030849859,-0.5006956050013623,-0.4979254544671863,-0.4951591196253119,-0.4923965688667783,-0.4896377708276017,-0.486882694385615,-0.4841313086573533,-0.4813835829949856,-0.4786394869832911,-0.4758989904366788,-0.4731620633962519,-0.4704286761269123,-0.4676987991145082,-0.4649724030630226,-0.4622494588918005,-0.459529937732817,-0.4568138109279832,-0.45410105002649,-0.4513916267821899,-0.4486855131510141,-0.4459826812884273,-0.4432831035469157,-0.4405867524735119,-0.4378936008073521,-0.4352036214772675,-0.4325167875994089,-0.4298330724749025,-0.4271524495875386,-0.4244748926014909,-0.4218003753590663,-0.4191288718784854,-0.4164603563516914,-0.4137948031421897,-0.4111321867829144,-0.4084724819741238,-0.4058156635813236,-0.4031617066332163,-0.4005105863196786,-0.3978622779897626,-0.3952167571497264,-0.3925739994610858,-0.3899339807386945,-0.3872966769488461,-0.3846620642074017,-0.3820301187779403,-0.3794008170699326,-0.3767741356369381,-0.3741500511748235,-0.3715285405200044,-0.3689095806477081,-0.3662931486702574,-0.3636792218353759,-0.3610677775245139,-0.3584587932511938,-0.3558522466593766,-0.3532481155218471,-0.3506463777386185,-0.3480470113353564,-0.3454499944618208,-0.342855305390327,-0.340262922514224,-0.3376728243463912,-0.3350849895177517,-0.3324993967758037,-0.3299160249831679,-0.3273348531161523,-0.3247558602633323,-0.3221790256241478,-0.3196043285075156,-0.3170317483304572,-0.3144612646167421,-0.3118928569955463,-0.3093265052001247,-0.3067621890664992,-0.3041998885321602,-0.3016395836347824,-0.2990812545109546,-0.2965248813949227,-0.2939704446173466,-0.2914179246040696,-0.2888673018749015,-0.2863185570424135,-0.2837716708107464,-0.2812266239744309,-0.2786833974172194,-0.2761419721109309,-0.2736023291143065,-0.2710644495718769,-0.2685283147128412,-0.2659939058499566,-0.2634612043784398,-0.2609301917748781,-0.2584008495961521,-0.2558731594783677,-0.2533471031357998,-0.2508226623598447,-0.2482998190179835,-0.2457785550527543,-0.2432588524807349,-0.2407406933915342,-0.2382240599467932,-0.2357089343791951,-0.2331952989914843,-0.2306831361554945,-0.2281724283111849,-0.2256631579656855,-0.2231553076923502,-0.2206488601298189,-0.2181437979810866,-0.2156401040125819,-0.2131377610532517,-0.2106367519936553,-0.208137059785064,-0.2056386674385705,-0.2031415580242036,-0.2006457146700509,-0.1981511205613888,-0.1956577589398188,-0.1931656131024111,-0.1906746664008545,-0.188184902240613,-0.1856963040800893,-0.1832088554297933,-0.1807225398515188,-0.1782373409575242,-0.1757532424097207,-0.1732702279188659,-0.1707882812437627,-0.1683073861904646,-0.1658275266114864,-0.1633486864050197,-0.1608708495141542,-0.1583939999261051,-0.1559181216714435,-0.1534431988233343,-0.1509692154967772,-0.1484961558478536,-0.1460240040729773,-0.1435527444081512,-0.1410823611282271,-0.138612838546171,-0.1361441610123323,-0.1336763129137173,-0.1312092786732673,-0.1287430427491399,-0.1262775896339953,-0.1238129038542862,-0.1213489699695508,-0.1188857725717109,-0.1164232962843726,-0.1139615257621307,-0.1115004456898773,-0.1090400407821129,-0.1065802957822614,-0.1041211954619883,-0.1016627246205216,-0.09920486808397644,-0.09674761070468241,-0.09429093736051368,-0.09183483295422223,-0.08937928241277357,-0.0869242706866855,-0.0844697827493691,-0.08201580359647261,-0.0795623182452275,-0.07710931173379722,-0.07465676912062751,-0.0722046754838004,-0.06975301592038885,-0.06730177554581435,-0.06485093949320622,-0.06240049291276312,-0.05995042097111603,-0.05750070885069351,-0.05505134174908826,-0.05260230487842563,-0.05015358346473367,-0.0477051627473145,-0.04525702797811745,-0.04280916442111332,-0.0403615573516701,-0.03791419205592982,-0.03546705383018676,-0.03302012798026652,-0.0305733998209063,-0.02812685467513613,-0.02568047787366096,-0.02323425475424357,-0.02078817066108835,-0.01834221094422562,-0.01589636095889674,-0.01345060606493972,-0.01100493162617527,-0.008559323009793377,-0.006113765585740239,-0.003668244726105415,-0.001222745804509297,0.001222745804509297,0.003668244726105415,0.006113765585740239,0.008559323009793377,0.01100493162617527,0.01345060606493972,0.01589636095889674,0.01834221094422562,0.02078817066108835,0.02323425475424357,0.02568047787366096,0.02812685467513613,0.0305733998209063,0.03302012798026652,0.03546705383018676,0.03791419205592982,0.0403615573516701,0.04280916442111332,0.04525702797811745,0.0477051627473145,0.05015358346473367,0.05260230487842563,0.05505134174908826,0.05750070885069351,0.05995042097111603,0.06240049291276312,0.06485093949320622,0.06730177554581435,0.06975301592038885,0.0722046754838004,0.07465676912062751,0.07710931173379722,0.07956231824522764,0.08201580359647274,0.08446978274936924,0.08692427068668564,0.08937928241277374,0.09183483295422237,0.09429093736051382,0.09674761070468255,0.09920486808397658,0.1016627246205217,0.1041211954619884,0.1065802957822616,0.1090400407821131,0.1115004456898775,0.1139615257621309,0.1164232962843727,0.118885772571711,0.1213489699695509,0.1238129038542863,0.1262775896339955,0.12874304274914,0.1312092786732674,0.1336763129137175,0.1361441610123324,0.1386128385461711,0.1410823611282272,0.1435527444081513,0.1460240040729775,0.1484961558478537,0.1509692154967774,0.1534431988233345,0.1559181216714436,0.1583939999261049,0.1608708495141541,0.1633486864050195,0.1658275266114863,0.1683073861904645,0.1707882812437625,0.1732702279188657,0.1757532424097206,0.1782373409575241,0.1807225398515187,0.1832088554297932,0.1856963040800892,0.1881849022406129,0.1906746664008543,0.1931656131024109,0.1956577589398187,0.1981511205613886,0.2006457146700508,0.2031415580242035,0.2056386674385704,0.2081370597850639,0.2106367519936551,0.2131377610532516,0.2156401040125817,0.2181437979810865,0.2206488601298187,0.2231553076923501,0.2256631579656853,0.2281724283111848,0.2306831361554944,0.2331952989914841,0.2357089343791949,0.2382240599467932,0.2407406933915342,0.2432588524807349,0.2457785550527543,0.2482998190179835,0.2508226623598447,0.2533471031357998,0.2558731594783677,0.2584008495961521,0.2609301917748781,0.2634612043784398,0.2659939058499566,0.2685283147128412,0.2710644495718769,0.2736023291143065,0.2761419721109309,0.2786833974172194,0.2812266239744309,0.2837716708107464,0.2863185570424135,0.2888673018749015,0.2914179246040696,0.2939704446173466,0.2965248813949227,0.2990812545109546,0.3016395836347824,0.3041998885321602,0.3067621890664992,0.3093265052001247,0.3118928569955463,0.3144612646167421,0.3170317483304572,0.3196043285075156,0.3221790256241478,0.3247558602633323,0.3273348531161523,0.3299160249831679,0.3324993967758037,0.3350849895177517,0.3376728243463912,0.340262922514224,0.342855305390327,0.3454499944618208,0.3480470113353564,0.3506463777386185,0.3532481155218471,0.3558522466593766,0.3584587932511938,0.3610677775245139,0.3636792218353759,0.3662931486702574,0.3689095806477081,0.3715285405200044,0.3741500511748235,0.3767741356369381,0.3794008170699326,0.3820301187779403,0.3846620642074017,0.3872966769488461,0.3899339807386945,0.3925739994610858,0.3952167571497264,0.3978622779897626,0.4005105863196786,0.4031617066332165,0.4058156635813238,0.4084724819741239,0.4111321867829145,0.4137948031421899,0.4164603563516916,0.4191288718784856,0.4218003753590665,0.424474892601491,0.4271524495875388,0.4298330724749026,0.4325167875994091,0.4352036214772677,0.4378936008073522,0.440586752473512,0.4432831035469159,0.4459826812884274,0.4486855131510143,0.45139162678219,0.4541010500264901,0.4568138109279834,0.4595299377328171,0.4622494588918006,0.4649724030630227,0.4676987991145083,0.4704286761269125,0.4731620633962521,0.4758989904366789,0.4786394869832912,0.4813835829949858,0.4841313086573535,0.4868826943856152,0.4896377708276016,0.4923965688667782,0.4951591196253117,0.4979254544671861,0.5006956050013622,0.5034696030849858,0.5062474808266436,0.5090292705896694,0.511815004995498,0.5146047169270728,0.5173984395323036,0.5201962062275779,0.5229980507013268,0.5258040069176453,0.5286141091199684,0.5314283918348059,0.5342468898755337,0.5370696383462459,0.5398966726456671,0.5427280284711267,0.5455637418225953,0.5484038490067874,0.5512483866413275,0.5540973916589846,0.5569509013119743,0.5598089531763304,0.5626715851563477,0.5655388354890973,0.5684107427490157,0.5712873458525688,0.5741686840629939,0.5770547969951189,0.5799457246202626,0.5828415072712162,0.5857421856473083,0.5886478008195554,0.5915583942358984,0.5944740077265291,0.5973946835093068,0.6003204641952662,0.6032513927942216,0.606187512720466,0.6091288677985706,0.6120755022692814,0.6150274607955232,0.6179847884685036,0.6209475308139284,0.6239157337983234,0.6268894438354699,0.629868707792953,0.6328535729988283,0.6358440872484065,0.6388402988111609,0.6418422564377582,0.6448500093672185,0.6478636073342042,0.6508831005764422,0.6539085398422818,0.6569399763983937,0.6599774620376083,0.6630210490869014,0.6660707904155284,0.6691267394433105,0.6721889501490763,0.6752574770792632,0.6783323753566807,0.6814137006894415,0.6845015093800632,0.6875958583347421,0.6906968050728098,0.693804407736368,0.6969187251001143,0.7000398165813566,0.7031677422502258,0.7063025628400876,0.7094443397581606,0.7125931350963457,0.7157490116422693,0.7189120328905484,0.7220822630542832,0.7252597670767783,0.728444610643505,0.7316368601943033,0.7348365829358366,0.7380438468543002,0.7412587207283911,0.7444812741425476,0.7477115775004644,0.7509497020388882,0.7541957198417045,0.7574497038543204,0.7607117278983514,0.7639818666866213,0.7672601958384825,0.7705467918954627,0.773841732337253,0.7771450955980376,0.7804569610831813,0.7837774091862812,0.7871065213065922,0.7904443798668355,0.7937910683314048,0.7971466712249743,0.8005112741515247,0.8038849638137954,0.8072678280331768,0.8106599557700533,0.8140614371446091,0.8174723634581109,0.8208928272146809,0.8243229221435711,0.8277627432219572,0.8312123866982629,0.8346719501160311,0.83814153233836,0.8416212335729144,0.8451111553975358,0.8486114007864621,0.8521220741371802,0.8556432812979257,0.8591751295958504,0.8627177278658792,0.8662711864802713,0.8698356173789147,0.8734111341003676,0.8769978518136747,0.8805958873509808,0.8842053592409654,0.8878263877431194,0.8914590948829016,0.895103604487786,0.8987600422242398,0.9024285356356577,0.9061092141812802,0.9098022092761301,0.9135076543319959,0.9172256847994994,0.9209564382112811,0.9247000542263368,0.9284566746755454,0.9322264436084264,0.9360095073411674,0.9398060145059614,0.9436161161017015,0.9474399655460722,0.9512777187290917,0.9551295340681464,0.9589955725645742,0.9628759978618452,0.966770976305398,0.970680677004187,0.974605271893998,0.9785449358025993,0.9824998465167862,0.9864701848513928,0.9904561347203336,0.9944578832097531,0.9984756206533578,1.002509540710008,1.006559840443653,1.010626720405697,1.014710384719881,1.018811041169779,1.022928901289005,1.02706418045423,1.031217097981115,1.035387877223279,1.039576745674407,1.043783935073628,1.048009681514285,1.052254225556229,1.056517812341786,1.060800691715526,1.065103118347994,1.069425351863572,1.073767656972616,1.078130303608069,1.082513567066707,1.086917728155233,1.091343073341402,1.095789894910401,1.1002584911267,1.104749166401602,1.109262231466746,1.113798003553811,1.118356806580697,1.12293897134446,1.127544835721305,1.132174744873943,1.136829051466652,1.141508115888377,1.146212306484246,1.150941999795884,1.155697580810918,1.160479443222132,1.165287989696682,1.170123632155891,1.17498679206609,1.179877900741064,1.184797399656649,1.189745740778077,1.194723386900707,1.199730812004785,1.204768501624966,1.209836953235313,1.214936676650586,1.220068194444647,1.225232042386869,1.230428769897494,1.235658940522947,1.240923132432152,1.246221938934995,1.251555969024137,1.256925847941436,1.262332217770371,1.267775738055884,1.273257086453213,1.278776959407354,1.284336072864907,1.289935163020201,1.295574987097688,1.301256324172764,1.306979976033318,1.312746768084458,1.318557550299055,1.324413198216942,1.330314613995774,1.336262727516836,1.342258497549272,1.348302912976517,1.354396994088954,1.360541793947194,1.366738399820644,1.372987934706451,1.379291558934291,1.385650471862928,1.392065913674922,1.398539167276438,1.405071560309633,1.411664467285797,1.418319311848048,1.425037569173212,1.431820768523329,1.438670495958159,1.445588397221092,1.452576180812005,1.459635621261845,1.466768562625123,1.473976922208031,1.481262694551605,1.488627955691258,1.496074867716133,1.503605683654058,1.51122275271056,1.518928525893308,1.526725562056687,1.534616534404903,1.542604237496185,1.550691594795363,1.55888166682739,1.567177659990391,1.575582936093572,1.584101022693083,1.592735624307654,1.601490634605834,1.610370149668072,1.619378482439964,1.628520178507961,1.637800033346128,1.647223111202421,1.656794765815981,1.666520663183651,1.676406806624952,1.686459564430973,1.696685700425005,1.707092407812454,1.717687346756154,1.728478686182374,1.739475150404887,1.75068607125217,1.762121446499574,1.773792005548416,1.785709283462875,1.797885704680064,1.810334677957496,1.823070704426331,1.836109500992796,1.849468141792318,1.863165220975591,1.877221040824709,1.891657830102795,1.906499998688552,1.921774436013785,1.93751086271024,1.953742247324262,1.970505303170329,1.987841084644705,2.005795708001292,2.024421229270474,2.043776722506634,2.06392961611032,2.084957365441463,2.106949569169807,2.130010679262959,2.154263517342249,2.179853905073575,2.20695686307142,2.235785065792777,2.266600620681125,2.299731883252602,2.335598149625034,2.374747142477102,2.417914221592359,2.466120528560782,2.520845717310525,2.584356209392189,2.660396199829992,2.755868165559522,2.885942132469943,3.097558392975658};
inline float rand_normal(){
	return probit1024[rand()&1023];
}



template<typename T, typename IDX=int>
struct binomial
{
	binomial() : n(0), k(0), val(1) {}
	binomial(const IDX& nn, const IDX& kk) : n(nn), val(1){
		ASS(0<=kk);
		if(2*kk<nn){
			k = 0;
			while(k<kk)moveR();
		}
		else{
			k=nn;
			while(k>kk)moveL();
		}
	}
	IDX n,k;
	T val;
	
	operator T(){
		return val;
	}

	bool outside(){
		bool ret = n<0 || k<0 || k>n;
		if(ret)val=0;
		return ret;
	}

	void moveL(){
		--k;
		if(outside()) return;

		if(k==n) val=1;
		else
		{
			val*=(k+1);
			val/=(n-k);
		}
	}
	void moveR(){
		++k;
		if(outside()) return;

		if(k==0) val=1;
		else
		{
			val*=(n-k+1);
			val/=(k);
		}
	}
	void moveD(){
		++n;
		if(outside()) return;

		if(n==k) val=1;
		else
		{
			val*=n;
			val/=(n-k);
		}
	}
	void moveU(){
		--n;
		if(outside()) return;

		val*=(n-k+1);
		val/=(n+1);
	}
};





#define gcd __gcd





template<typename T>
T gcdExt(T a, T b, T& aaa, T& bbb)
{
	T a0 = a;
	T b0 = b;

	T aa = 0;
	T bb = 1;
	aaa = 1;
	bbb = 0;
	

	

	while(b != 0)
	{
		T q = a/b;
		a = a%b;
		

		aaa -= aa*q;
		bbb -= bb*q;
		swap(a,b);
		swap(aa,aaa);
		swap(bb,bbb);
	}

	ASS(a0*aaa + b0*bbb == a);

	return a;
}


template<class T>
inline T mult(const T& a, const T& b){return a*b;}

template<class T, class E, class OP>
T fpow(T a, E exp, const OP& op = mult<T>, const T& neutral = 1){
	T r = neutral;
	while(exp){
		if(exp&1){
			r = op(r,a);
			--exp;
		}
		else{
			exp >>= 1;
			a = op(a,a);
		}
	}
	return r;
}





}


namespace ab{
	
template<int mod1 = (1<<31)-1, int mod2 = (1<<31)-19>
struct H2{
	H2() : h1(0), h2(0) {}
	H2(int x) : h1(x%mod1), h2(x%mod2) {}
	ui32 h1,h2;
	H2& operator+=(const H2& o){
		h1 = (h1+o.h1)%mod1;
		h2 = (h2+o.h2)%mod2;
		return *this;
	}
	H2 operator+(const H2& o)const{
		return H2(*this)+=o;
	}
	H2& operator-=(const H2& o){
		h1 = (mod1+h1-o.h1)%mod1;
		h2 = (mod2+h2-o.h2)%mod2;
		return *this;
	}
	H2 operator-(const H2& o)const{
		return H2(*this)-=o;
	}
	H2& operator*=(const H2& o){
		h1 = (1ULL*h1*o.h1)%mod1;
		h2 = (1ULL*h2*o.h2)%mod2;
		return *this;
	}
	H2 operator*(const H2& o)const{
		return H2(*this)*=o;
	}
	
	bool operator==(const H2& o)const{
		return h1==o.h1 and h2==o.h2;
	}
	
	bool operator!=(const H2& o)const{
		return !operator==(o);
	}
};

template<int mod1 = (1<<31)-1>
struct H1{
	H1() : h1(0) {}
	H1(int x) : h1(x%mod1) {}
	ui32 h1;
	H1& operator+=(const H1& o){
		h1 = (h1+o.h1)%mod1;
		return *this;
	}
	H1 operator+(const H1& o)const{
		return H1(*this)+=o;
	}
	H1& operator-=(const H1& o){
		h1 = (mod1+h1-o.h1)%mod1;
		return *this;
	}
	H1 operator-(const H1& o)const{
		return H1(*this)-=o;
	}
	H1& operator*=(const H1& o){
		h1 = (1ULL*h1*o.h1)%mod1;
		return *this;
	}
	H1 operator*(const H1& o)const{
		return H1(*this)*=o;
	}
	H1& operator/=(const H1& o){
		

		return (*this)*=fpow(o, mod1-2, mult<H1>, H1(1));
	}
	H1 operator/(const H1& o)const{
		return H1(*this)/=o;
	}
	
	
	
	operator ui32()const{
		return h1;
	}
};



struct H1X{
	H1X(int mod) : mod1(mod), h1(0) {}
	H1X(int mod, int x) : mod1(mod), h1(x%mod1) {}
	

	H1X& operator=(const H1X& o){
		ASS(mod1==o.mod1);
		

		h1 = o.h1;
		return *this;
	}
	const int mod1;
	ui32 h1;
	H1X& operator+=(const H1X& o){
		ASS(mod1==o.mod1);
		h1 = (h1+o.h1)%mod1;
		return *this;
	}
	H1X operator+(const H1X& o)const{
		return H1X(*this)+=o;
	}
	H1X& operator-=(const H1X& o){
		ASS(mod1==o.mod1);
		h1 = (mod1+h1-o.h1)%mod1;
		return *this;
	}
	H1X operator-(const H1X& o)const{
		return H1X(*this)-=o;
	}
	H1X& operator*=(const H1X& o){
		ASS(mod1==o.mod1);
		h1 = (1ULL*h1*o.h1)%mod1;
		return *this;
	}
	H1X operator*(const H1X& o)const{
		return H1X(*this)*=o;
	}
	H1X& operator/=(const H1X& o){
		ASS(mod1==o.mod1);
		

		return (*this)*=fpow(o,mod1-2,mult<H1X>,H1X(mod1,1));
	}
	H1X operator/(const H1X& o)const{
		return H1X(*this)/=o;
	}
	
	
	
	operator ui32()const{
		return h1;
	}
};

}



#if __cplusplus >= 201103L
#include <unordered_map>
namespace std{
#else
#include <ext/hash_map>
namespace __gnu_cxx{
#endif

template<int h1, int h2> struct hash<ab::H2<h1,h2> >{
	size_t operator()(const ab::H2<h1,h2>& h)const{
		return h.h1^h.h2;
	}
};
template<int h1> struct hash<ab::H1<h1> >{
	size_t operator()(const ab::H1<h1>& h)const{
		return h.h1;
	}
};

}


#include<bits/stdc++.h>



#if __cplusplus >= 201103L
namespace std{
#else
#include <ext/hash_map>
namespace __gnu_cxx{
#define unordered_map hash_map

#endif



template<>template<class A,class B>struct hash<std::map<A,B> >{
    size_t operator()(const std::map<A,B>& m) const{
        size_t r = m.size();
        if(!r)return 0;
        __typeof(m.begin()) i=m.be;
        r^=hash<__typeof(i)>()(i);
        ++i;
        r^=cbitl(hash<__typeof(i)>()(*i),sizeof(r)*8/4);
        i=m.end();
        --i;
        r^=cbitl(hash<__typeof(i)>()(*i),sizeof(r)*8/2);
        return r;
    }
};
template<>template<class A, class B>struct hash<pair<A,B> >{
    size_t operator()(const pair<A,B>& p) const{
        return hash<A>()(p.first) ^ cbitl(hash<B>()(p.second),sizeof(size_t)*8/2);
    }
};
} 




template<class A, class B, class C, class D>
std::pair<A,B>& operator+=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first+=o.first;
	p.second+=o.second;
	return p;
}
template<class A, class B, class C, class D>
std::pair<A,B>& operator-=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first-=o.first;
	p.second-=o.second;
	return p;
}
template<class A, class B, class C, class D>
std::pair<A,B>& operator*=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first*=o.first;
	p.second*=o.second;
	return p;
}
template<class A, class B, class C, class D>
std::pair<A,B>& operator/=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first/=o.first;
	p.second/=o.second;
	return p;
}


template<class Afi, class Ase, class Bfi, class Bse>
std::pair<__typeof(Afi()+Bfi()),__typeof(Ase()+Bse())>&
operator+(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi+b.fi, a.se+b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
std::pair<__typeof(Afi()-Bfi()),__typeof(Ase()-Bse())>&
operator-(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi-b.fi, a.se-b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
std::pair<__typeof(Afi()*Bfi()),__typeof(Ase()*Bse())>&
operator*(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi*b.fi, a.se*b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
std::pair<__typeof(Afi()/Bfi()),__typeof(Ase()/Bse())>&
operator/(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi/b.fi, a.se/b.se);
}









#define F(i,n) for(int i=0; i<(int)(n); ++i)
#define FO(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define OF(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);--i)
#define FE(it,c)  for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define FER(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); )
#define ALL(c) (c).begin(),(c).end()
#define ZERO(c) memset(c,0,sizeof(c))

#define bac back()
#define fro front()

#define no1 first
#define no2 second
#define fi first
#define se second

#define siz size()
#define ins insert
#define era erase







#define mp make_pair
#define be begin()
#define en end()
#define rbe rbegin()
#define ren rend()
#define sz size()
#define pub push_back
#define puf push_front
#define pob pop_back()
#define pof pop_front()
#define bs binary_search
#define lb lower_bound
#define ub upper_bound

#define pq priority_queue

#define si (int)

#define fo3(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define of3(i,a,b) for(int i=(int)((b)-1); i>=(int)(a); --i)

#define fo2(i,n) fo3(i,0,n)
#define of2(i,n) of3(i,0,n)

#define fo(...) VA_SEL(fo,__VA_ARGS__)
#define of(...) VA_SEL(of,__VA_ARGS__)

#define inl		inline __attribute__ ((always_inline))
#define ninl	__attribute__ ((noinline))







#ifdef DEBUG
	#undef FASTIO

	#ifdef _WIN32
		#include<windows.h>
		inline void ec(int a){static HANDLE h=GetStdHandle(-12);SetConsoleTextAttribute(h,a?12:0xf);}
		inline void oc(int a){static HANDLE h=GetStdHandle(-11);SetConsoleTextAttribute(h,a?10:0xf);}
	#else
		

	#endif
#else
	#define ec(x)
	#define oc(x)
#endif


#define DV(x) (E<#x<": "<(x)<N)
#define XX {E<"XX LINE "<__LINE__<N;}



#ifdef _WIN32



#ifndef NO_UNLOCKED
#define NO_UNLOCKED
#endif






#endif

#define TYP(x) __typeof(x)

const char N='\n';
const char S=' ';

using namespace std;
using namespace __gnu_cxx;

namespace ab{}
using namespace ab;



template<class T>inline T cbitl(T x,int i){return (x<<i) ^ (x>>(sizeof(T)*8-i));}





#define ri _rint()
#define rui _ruint()
#define rll _rll()
#define rull _rull()
#define rchar _rchar()
#define rstr _rstr()

#ifndef FASTIO
inline void _fin(int){}
inline void _fout(int){}
#ifdef IOSTREAM
inline int _rint(){int r;cin>>r;return r;}
inline uint _ruint(){uint r;cin>>r;return r;}
inline ull _rull(){ull r;cin>>r;return r;}
inline char _rchar(){return cin.get();}
inline string _rstr(){string s;cin>>s;return s;}
template<typename T>inline void W(const T& i){cout<<i;}
inline void W(){W('\n');}
#else
inline int _rint(){int r;scanf("%d",&r);return r;}
inline uint _ruint(){uint r;scanf("%u",&r);return r;}
inline ull _rull(){ull r;scanf("%" SCNu64,&r);return r;}
inline ull _rll(){ll r;scanf("%" SCNd64,&r);return r;}
inline char _rchar(){return getchar();}
inline string _rstr(){
	string s;
	char c=rchar;
	while(c!=-1 && !isgraph(c))c=rchar;
	for(;;){
		if(!isgraph(c))break;
		s+=c;
		c=rchar;
	}
	return s;
}
inline void W(char a='\n'){printf("%c",a);}
inline void W(const string&s){printf("%s",s.c_str());}
inline void W(int a){printf("%d",a);}
inline void W(uint a){printf("%u",a);}
inline void W(const ui64& a){printf("%" PRIu64,a);}
inline void W(const i64& a){printf("%" PRIi64,a);}
inline void W(const char *str){fputs(str,stdout);}
inline void W(const double& d){printf("%.20f",d);}
inline void W(const long double& d){printf("%.50Lf",d);}
#endif
#else

#ifndef NO_UNLOCKED
#define FREAD fread_unlocked
#define FWRITE fwrite_unlocked
#else
#define FREAD fread
#define FWRITE fwrite
#endif



const int _IB=32768;const int _OB=32768;
char _iB[_IB];int _iP = _IB;
char _oB[_OB];int _oP = 0;
inline void _fin(int mc){
	int r=_IB-_iP;
	if(r>mc)return;
	F(i,r) _iB[i]=_iB[i+_iP];	

    int rd=FREAD(_iB+r,1,_iP,stdin);
	if(rd!=_iP) _iB[r+rd]=0;
	_iP = 0;
}
inline void _fout(int mc){
	if(_OB-_oP>mc)return;
	FWRITE(_oB,1,_oP,stdout);
	_oP = 0;
}
inline void _W(char c='\n'){_oB[_oP++]=c;} 

inline char _rc(){return _iB[_iP++];}
inline char _rchar(){_fin(1);return _rc();}
inline string _rstr(){
	string s;
	for(;;){
		char c=rchar;
		if(!isprint(c)||isspace(c))break;
		s+=c;
	}
	return s;
}
template<class T>inline T _rur(){ 

    T r=0;char c=_rc();
    do c-='0',r=r*10+c,c=_rc();while(c>='0');
    return r;}
template<class T>inline T _rsi(){ 

	char c=_rc();
	while(c<'-')c=_rc();
	if(c=='-')return -_rur<T>();
	else{--_iP;return _rur<T>();}}
template<class T>inline T _ru(){  

	while(_rc()<'0');--_iP;
	return _rur<T>();
}

inline int _rint(){_fin(15);return _rsi<int>();}
inline uint _ruint(){_fin(15);return _ru<uint>();}
inline ll _rll(){_fin(25);return _rsi<ll>();}
inline ull _rull(){_fin(25);return _ru<ull>();}

const int _rs = 20; char _r[_rs];
template<class T>inline void _w(T i){	

	if(numeric_limits<T>::is_signed and i<0) _W('-'), i=-i;
	else if(i==0){_W('0'); return;}
	int pos = _rs;
	do _r[--pos]='0'+i%10, i/=10; while(i);
	do _W(_r[pos++]); while(pos<_rs);
}
inline void W(const char c){_fout(2);_W(c);}
inline void W(const int32_t& i){_fout(15);_w(i);}
inline void W(const uint32_t& i){_fout(15);_w(i);}
inline void W(const int64_t& i){_fout(25);_w(i);}
inline void W(const uint64_t& i){_fout(25);_w(i);}
inline void W(const char*str, int l){
	for(int b=0; b<l; b+=_OB){
		int num = min(_OB,l-b);
		_fout(num);
		memcpy(&_oB[_oP], str+b, num);
		_oP+=num;
	}
}
inline void W(const char*str){W(str,strlen(str));}
inline void W(const string&s){W(s.c_str(),s.siz);}
inline void W(double d){_fout(50);_oP+=sprintf(&_oB[_oP],"%.20f",d);}	

#endif
template<class A,class B>inline void W(const A&a,const B&b){W(a);W(b);}
template<class A,class B,class C>
inline void W(const A&a,const B&b,const C&c){W(a);W(b);W(c);}
template<class A,class B,class C,class DD>
inline void W(const A&a,const B&b,const C&c,const DD&dd){W(a);W(b);W(c);W(dd);}
template<class T>inline void sortall(T&t){sort(t.be,t.en);}
template<class T>inline void uniqall(T&t){t.resize(unique(t.be,t.en)-t.be);}

inline int count1(uint i){return __builtin_popcount(i);}
inline int count1(ull i){return __builtin_popcountll(i);}
inline int parity(uint i){return __builtin_parity(i);}
inline int parity(ull i){return __builtin_parityll(i);}
inline int ilog(uint i){return 31-__builtin_clz(i);} 

inline int ilog(ull i){return 63-__builtin_clzll(i);}
#define powerof2(x) !(x&(x-1))
#define subset(a,b) (a&b==a)
#define kbegin(k) ((1<<k)-1)
#define kend(k,n) ((kbegin(k)<<n-k)+1)
inline uint knext(uint a){uint b=(a|(a-1))+1;return b|((a^b)>>(__builtin_ctz(a)+2));}
#define fors(x,k,n) for(uint x=kbegin(k);x<kend(k,n);x=knext(x))


template<class A,class B>inline ostream&operator<<(ostream&o,const pair<A,B>&p){o<<'<'<<p.fi<<", "<<p.se<<'>';return o;}
template<class A,class B>inline ostream&operator<<(ostream&o,const map<A,B>&m){o<<N;FE(k,m)o<<"map["<<k->fi<<"] -> "<<k->se<<N;return o;}
template<class A>inline ostream&operator<<(ostream&o,const vector<A>&_v){o<<N;fo(i,_v.sz)o<<"vector["<<i<<"] = "<<_v[i]<<N;return o;}

struct _O{template<class T>_O&operator<(const T&_t){
		oc(1);W(_t);oc(0);
		return *this;
}}O;

struct _I{
	_I&operator>(int32_t&_t){_t=ri;return*this;}
	_I&operator>(uint32_t&_t){_t=rui;return*this;}
	_I&operator>(int64_t&_t){_t=rll;return*this;}
	_I&operator>(uint64_t&_t){_t=rull;return*this;}
	_I&operator>(char&_t){_t=rchar;return*this;}
	_I&operator>(string&_t){_t=rstr;return*this;}
}I;

struct _E{template<class T>_E&operator<(const T&_t){DE{ec(1);cerr<<_t;ec(0);}return*this;}}E;



inline void tc();
int main()
{
#ifdef FASTIO
    setvbuf(stdin,0,_IONBF,0);setvbuf(stdout,0,_IONBF,0);
#elif defined IOSTREAM
	ios_base::sync_with_stdio(0);cin.tie(0);cout.precision(99);cout.setf(ios::fixed,ios::floatfield);
#endif

#ifdef DEBUG
#ifdef _WIN32
	ec(0);
	oc(0);
#else


#endif
#endif
	
#ifdef READ_NUM_TEST_CASES
	int nz=rint;fo(i,nz)
#endif
	tc();
#ifdef FASTIO
    FWRITE(_oB,1,_oP,stdout);
#endif
	return 0;
}





typedef H1<1000000007> H;

int n,k;
int s,t;

inline int encode(char c){
	if(c>='a' and c<='z')return c-'a';
	else return c-'A' + 26;
}

inline char decode(int i){
	if(i<26)return 'a'+i;
	else return 'A'+(i-26);
}

const int MAXN = 2*52+5;
map<int,pii> tos[MAXN];
int pot[MAXN];
int d[MAXN];
int from[MAXN];

int match[MAXN];

void mcmf(){
	for(;;){
		F(i,MAXN)d[i]=INT_MAX;
		pq<pii> q;
		q.push(mp(-0,s));
		d[s]=0;
		
		while(q.siz){
			pii c = q.top();q.pop();
			int cd = -c.fi;
			int cv = c.se;
			if(cd != d[cv])continue;
			
			FE(it,tos[cv]){
				int dv = it->fi;
				

				int cand = cd + it->se.se + pot[cv] - pot[dv];
				if(cand < d[dv]){
					d[dv] = cand;
					from[dv] = cv;
					q.push(mp(-cand,dv));
					E<"from "<dv<"   "<cv<N;
					E<"cand "<cand<N;
				}
			}
		}
		
		F(i,2*n+2)E<"d["<i<"] == "<d[i]<N;
		
		if(d[t]==INT_MAX)break;
		
		vi path;
		path.pub(t);
		while(path.bac!=s)path.pub(from[path.bac]);
		path.pob;
		
		int minf = INT_MAX;
		F(i,path.siz){
			int v = path[i];
			int u = from[v];
			minf = min(minf, tos[u][v].fi);
		}
		
		E<"flow "<minf<N;
		
		F(i,path.siz){
			int v = path[i];
			int u = from[v];
			
			tos[v][u].fi += minf;
			tos[v][u].se = -tos[u][v].se;
			
			tos[u][v].fi -= minf;
			if(tos[u][v].fi == 0)tos[u].era(v);
		}
		
		DV(path);
		
		F(i,n)pot[i]+=d[i];
	}
}

void tc(){
	k=ri,n=ri;
	
	string s1=rstr, s2=rstr;
	
	F(i,n)F(j,n) tos[i][n+j] = pii(1,2000009);
	
	
	F(i,s1.siz)tos[encode(s1[i])][encode(s2[i])+n].se--;
	
	s=2*n;
	t=s+1;
	
	

	

	
	F(i,n)tos[s][i]=pii(1,0);
	F(i,n)tos[n+i][t]=pii(1,0);
	
	mcmf();
	
	F(i,n)match[tos[n+i].be->fi] = i;
	
	int result = 0;
	F(i,s1.siz)if(match[encode(s1[i])] == encode(s2[i]))++result;
	O<result<N;
	
	F(i,n)O<decode(match[i]);
	O<N;
}

