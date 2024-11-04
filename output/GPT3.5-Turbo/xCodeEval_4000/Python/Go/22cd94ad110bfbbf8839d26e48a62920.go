package main

import (
	"fmt"
)

func main() {
	vals := []int{0, 2, 4, 11, 32, 97, 295, 940, 3148, 10901, 38324, 135313, 478989, 1704939, 6120951, 22187311, 81129556, 298715961, 1105546606, 4107686743, 15311861251, 57245614745, 214625591690, 806848059041, 3040880190559, 11487184020677, 43485050394205, 164927004274136, 626608618666934, 2384493434591620, 9087529927375918, 34682392280950974, 132542351686437644, 507171591796393381, 1943050156148444582, 7452770379302126187, 28617610413867287010, 110004285524692169216, 423278853888970409883, 1630293028998903898224, 6285059739994372175113, 24251646015941054123514, 93658090212564057369267, 361998255935404053662628, 1400264769080901203586626, 5420536513622893899223411, 20998547288236908910221869, 81402555582647387745072353, 315773811781519195206203743, 1225720522015608235445806021, 4760719694151787159929017594, 18501572033220094871426132593, 71943092199993678724857210801, 279900787023066422206380766515, 1089542787771588881232684451558, 4243270322763252541573736843398, 16533504004199807912573377049815, 64450888875566769728212852796272, 251353626653428916209479575238346, 980678120264352074967128926804970, 3827772695602948667320461087747608, 14946438805836705201610573978579332, 58384183641939996074486313064537042, 228146013979094959932481402500104857, 891836734216487281263993819053310580, 3487446305259076789631430819941164781, 13641891354433181356051446335973874898, 53380418002140832442127026242477826983, 208941818119368213463213106465436894420, 818089279597127665466775004269944627746, 3204085518917391642418980497822707368946, 12552548116979151772259349500529912185843, 49190428824796945806814476487174834833637, 192817716405499011473650043729840753603575, 756010333197049943262587147038690044323990, 2964967973738716215665619390729889117524126, 11631103235901605746966358476195230631624401, 45638117709881716820884625066346212193997756, 179117430766782718986585277827256933832578361, 703151339946287405256622851905491035823870364, 2760947953575465122602355158892640666820856655, 10843358244638208764264135386695995237230629260, 42595466751701481649228987244607986409898023182, 167361224438360440216773707743558900398932244382, 657712618935505465438291334703722328200913085438, 2585267129244075193809802877463649441653730126578, 10163907817638626817716918583895182831004513613123, 39966879600102108651549930111231157595519353367123, 157189034927496653479371759900026083719376366733614, 618336723242289821990531677547460787238476902915199, 2432803210487705745299587099505477676690341445712692, 9573406030090228456311712528276315005390377833848765, 37679227834331314384610566709094016942462047210730106, 148324205307544414472966671933319118336620842676034017, 583976180035270137125482861057965298570997748434633384, 2299587233992938795306777931535364083324792816656702562, 9056803044160163377763486214083966370497445758220238091, 35675403784053203605687069929418410353969228253977145175, 140549888973728380230585821156179869098315235374112780826, 553807051777443444619226740438552112146914572740818813349, 2182486580317155631599040361201576579661428502121123653136, 8602181468318536143561958614628117733446887135993193611259, 33910044229098624305263229397172982034616011218746549038961, 133693317292732811080040087400152346242814293126404041861193, 527170992897482625043862793628047993596077613055004462678358, 2078991323053339085220679240645759577116281504673965228281165, 8199967674079627513978859635806997637089923310593314990686802, 32346615646788397692645101000786880447192779976021484665026491, 127615014986565116912823011055488469695887719846538447148962878, 503535300132270633737648282143125136291637827235646987383725796, 1987066070190752220539052383119214966394869616456484179319219065, 7842381691354570986450767323914631805571692713415931280867539121, 30955369342236909413806190480686935113629828042777927462299708227, 122201190138992862183156046825436224148821835549252243468507301695, 482464559698258280614105143074906719974084230825244765227211470338, 1905044210329310933012883474559145946790917492784787928227261446437, 7523042318799748660208705403536100792111075885171898541934731742390, 29711865307743859983774105830474814695120217213404274613967605343142, 117358210334644832241289809026318941566777541081906921752718004064223, 463599954895501530333274519944443410381288269629861291846027518952547, 1831550319939959155587395984307016482400316562294418569080566939394373, 7236675876342106283578534336330743048842197598376804592542495717488169, 28595877959236188869992380241499418925461422245402511601972127083938809, 113008487488979608728537052095796235153826972386884347812349453027284777, 446643776276434337481901364650647855177976433243812620954649695122316826, 1765441807395465620252685967072498086035986271227159688590935355004060027, 6978896171078699499744178015254900571985547608845028328618588278612230285, 27590565813291130651676295962305434607391880724234668660140969043129437306, 109087342089418473054846937271841020723765346564892390158006517105586188244, 431347570427895275684887399889776157420375297525437055850000845301829933805, 1705764090654176600783120803651477353278324598907144288980953523257690938954, 6746034859339085323037813551799895795035073688161810095995890114587607307967, 26681829042596408508727803106987892830022155937080103881413184938373444601780, 105540568643047320085637757372875138941484282898455734499378871247031545034426, 417502908721193606389605307438517612545962933342696670188454638798883820258264, 1651715574747214150853710839970797716108744553638299319610439913405742985968373, 6535008503124889007856937275951632354585153583690531839980836461545232215824404, 25857804572051561459180314229189646010564292988633513533872884661419076724098956, 102322517183818948564124541851280345149045011490572076449791435684627433270629411, 404934094236883704120894459814765768721634186306504238924488061567317975693145340, 1602619915399511600553438890014229979328824144334807821204535561824879143206962453, 6343213042207650159611655077596947878673846137393784013748813764014784872364716886, 25108464423291463997404385112070199473744447497076474425682598855413110035742418914, 99394563947684374904758920726914308485128620392393490084506181225843747588475207197, 393492336753755531692026489972641598688144826660754601765695380807032546907543503921, 1557903824987562696463244084053237928311159497375106563075214332506952142892403104132, 6168439205715589425691171307912496909504919319342781227412278678910873593341882573211, 24425293227292450643484793977655277617059585096421595028507694237157052955457119327788, 96723881571135418665545369057123041094621729891750877288042985634178222443867299246418, 383051061687942536045084445172520830808282863996319158056819349124211693991398816327207, 1517079174117195579690955122633080343549424859594834854448758112231369900479121012142113, 6008804205917549913707301141913450089100988933558420551241354568832564553473079190572278, 23801027487732914406483006100676356957141654837362665600929752551423761670767951464675913, 94282443605173282918820528593155670207503470313471709302507741333407860445366620005663942, 373502108594609108040503037731586547276548840138645909419252430705207407681196709803983480, 1479728471960463699182943027707841420937310959692022055363898209234875053818609663966205866, 5862696271018571500089423595308441031224631020361921119823688743286535539779290630567630424, 23229443652081270733980663131770350007457433326179896912355233731751050724947198946004003975, 92046214646244587690706228458864173904798062070835842020367088988974705829518078204001021363, 364752635838858477460715070856088351075708777551436448235555244229366219828253326349002137500, 1445493034116344468923655951043320186128439597523080639496656917977382053690974380985547117707, 5728729409451696444372051461356534264846576646485085732046890058188716009614118855674637377976, 22705185146420504401997097103314578637547420523062806257838636533087251029395653129572040040074, 89994488892654396058856217300404040365891816827131704366554032344385475130012751055422998088811, 356722590821763183370769773946287974891959302880630650897935809030336785839603723618464030276788, 1414063305994736576027292395949115069687019850459912237903595491623285483544543552340164385746823, 5605706391578319849214622281168740607481793100182010208297580436542090440514111407701729518697618, 22223620744205360017667654052757026972000168259047208882853304998777155752466388108220124201070651, 88109348206147011746068556866098564625699209460062623605419377857389060105300638390094653102087665, 349342636080041683221934374226900622820872946841401311867352745078418891476797889097584439698488510, 1385170925534265899519131581097494785149908651513473500940930511309994846416946247702384780811305993, 5492588368773762187176960346750382398248979869518043882552293646465784762754580760180824188726279279, 21780728267753329002789566624916226339853435239931399185927732684141543568339811214313133006185789862, 86375216875091724004892983761031261568077226356560376884219660239075463095982915374142957348433560808, 342552444573954421439069379710177772069561072341619580877761685530229948518863741413885365554900097068, 1358582195600779764137599964716337955978399926986276091819585687264212241288091184793396726965847374717, 5388469875817259323304509591448381084385961063465665255658239637278204961430203993624180560639796747605, 21372998850022699161426070331663358980991055327568017672150484504323229468157683662487272446683394953616, 84778494911805672551905487568003378988055807689922250276608386182662094701118796017840631111511241539380, 336299294984076094211910140735246876668599223869497646602011823658647050190386550822954545260278612631544, 1334092702567721627301741363861098515979926575994751181111582340637309219232241033600092838437900802205038, 5292558212680523400742812226353811345695668866524041146689910628871196088819553304554474876050018124114153, 20997357930969861565036947992351357737332219482074988303743785974044064606333782872828128356414654770048429, 83307255301650683813771759430113027376624989750108038627604618437376758764431340497982895988412865509848646, 330536911422094638826855051199545833594432618486709155341244741865583122131341876999368620130514508527934886, 1311522869083496832871707350626892106751939874234564517468101657197217628921812764530031965246754289948832905, 5204156397188024528172208860333403395144057036547715697743789160749123289693413744575143624612520273136245942, 20651099904331266347452312738842587016214690030449557930458679449892111940939905103364939451289307748992021705, 81950993437459573466341756935194915370706037015935432733554932948181854760107481589302122500483380360974120698, 325224502658680918621143766183198696515890363756397080976420998474791236483195824901624062741635519646490626407, 1290714269690655531306881841380634199972701772564446091319466174738466016505934864779800047925147878259285097303, 5122649034621028257092921727961683522826738055239047518130182514401914195565325824742487436606026182522647156675, 20331833918723604572328478218344871921785349256218990332867325768701950803782350327182973980977910184990231738767, 80700419210399288565532992313764196322776455936388215324863888557166663083824127963351927392338983532130677066691, 320325964488275811162806976162403939204447615115097764645943597768559937809078043653016835390579784416806189815956, 1271526570389220738417720962998566369113558429608467759079824319778588199759814382086958737211830037441352944048167, 5047490573839566652123419730499281587581764724700676283660476791813590196494125779764142565481025618321161423806066, 20037438807446179847249688629193061142526113477517522632902620906339929842504046050208876416491892141201070822230131, 79547284021186879599064590255903862162736176763577694086452574483959105669722214770109007085871325696665049873073536, 315809215683715856623773540595819635047566056859602300667262187593705408991392910317051208881558444097467184884431157, 1253834979285426570031233194424112121276155771396268926629394300954835640295429800316432432553283540199303378978033661, 4964218880100007478910365183207198668749025436335271583835046291663699642820097365030064572856198822182684372000340668, 19670349100900037294551825932828794674996101745337032947740185772291388925123664900120264279906531771568243728001362667, 77941678704500147644493123563114973387462958821495369497285310947450629513944283600478931739624605047789943712005406668, 308682638677500583220853579826674786125964362850856978772459249275303867036448133201695134422307594971079944240021626667, 1223288570628752912585560362388558049517863831868358910512383623705575730480198582006773014384177380922719776960086506668, 4848438896281261664917813628758583079023884969152925352143504991604788945186478828039722450793356831917298258240347066667, 19237187636725058324589068281218923276095539871626701014407019966419113542105199288927964782669794709164633132961488266668, 76264552755000231722571603262501078676428557364934884050641279925275794883539910500501105128582707035868875888024562666667, 302674229347500918282850570312503396748571285282849556501706399626378573183019853801404134114114258079642992992097626666668, 1200193523800003641751402273437500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000}

	var n, m int
	fmt.Scan(&n, &m)
	fmt.Println(vals[n]%m)
}
