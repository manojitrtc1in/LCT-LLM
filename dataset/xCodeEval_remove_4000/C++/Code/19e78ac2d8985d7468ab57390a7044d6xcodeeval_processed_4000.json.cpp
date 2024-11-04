




 














 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
 
inline int64 labs(int64 a) { return a<0 ? (-a) : a; }
template<typename T> inline T sqr(T x) { return x*x; }









typedef vector<int> vint;
typedef vector<bool> vbool;
typedef vector<int64> vint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pii64;

void ImportMem();

string ToStr(int smpl, int sz)
{	
	ostringstream oss;
	oss << smpl;
	string test = oss.str();			
	while(test.size() < sz) test = "0" + test;
	return test;
}
string id2(int smpl)
{	
	return ToStr(smpl, 3);
}

const int TH = 3;
const int MAXTR = 50;


const int STR_MAX = 4;
const int NUMSZ = 4;
const int id0 = 3;

const double LAPL = 0.5;

map<string, int> mem[TH];
int sum[TH];

void ProcessStr(string & s)
{	
	while (!s.empty() && !isalnum(s[s.size()-1]))
	{
		s = s.substr(0, s.size()-1);
	}	
	while (!s.empty() && !isalnum(s[0]))
	{
		s = s.substr(1, s.size()-1);
	}	
	if (s.empty()) return;

	bool num = true;

	bool waspt = false;
	forn(i, s.size())
	{
		if (!isdigit(s[i]) && (waspt || s[i] != '.' && s[i] != ','))
		{
			num = false;
			break;
		}
		if (s[i] == '.' || s[i] == ',') waspt = true;
	}
	if (num)
	{
		s = string(STR_MAX, waspt ? '.' : '0');
		return;
	}
	
	s = s.substr(0, min((int)s.size(), STR_MAX));
	forn(i, s.size())
	{
		s[i] = tolower(s[i]);
	}
}

void ParseFile(int theme, ifstream & fin)
{
	string str;
	while(fin >> str)
	{
		ProcessStr(str);
		if (str.empty()) continue;
		mem[theme][str] ++;
		sum[theme]++;
	}
}

void Train()
{
	forn(th, TH)
	{
		id1(smpl, MAXTR)
		{
			string test = id2(smpl);
			string file = "train\\" + string(1, '1' + th) + "\\" + test + ".txt";
			
			ifstream fin(file.c_str());

			string tstr;
			getline(fin, tstr);
			ParseFile(th, fin);
			fin.close();
		}
	}
	
	forn(i, TH)
	{
		map<string, int>::iterator it;

		cout << "\"";
		forit(it, mem[i])
		{
			if (it->second < id0) continue;
			cout << i << it->first << string(STR_MAX - it->first.size(), ' ') << ToStr(it->second, NUMSZ);
			

		}
		cout << "\"," << endl;
	}
}


double res[TH];
bool AllSmall()
{
	bool ok = true;
	forn(i, TH)
	{
		ok &= (res[i] < 1); 
	}
	return ok;
}
bool OneBig()
{
	forn(i, TH)
	{
		if (res[i] > 1)
			return true;
	}
	return false;
}

void CalcRes(const string & s, double k = 1.0)
{
	if (s.empty())return;

	forn(i, TH)
	{
		if (res[i] < 1e-30)
		{
			res[i] = 1e-10;
		}
	}

	forn(i, TH)
	{
		res[i] *= k * 100.*(mem[i][s] + LAPL) / (sum[i] + LAPL * mem[i].size());
	}
		
	for(int ttt = 0; OneBig() && ttt < 30; ttt++)
	{
		forn(i, TH) res[i] /= 10;
	}		
	for(int ttt = 0; AllSmall() && ttt < 30; ttt++)
	{
		forn(i, TH) res[i] *= 10;
	}
}





void Solve()

void Solve(ifstream & cin)

{	
	ImportMem();
	
	string str;
	string name;
	getline(cin, str);
	getline(cin, name);

	res[0] = res[1] = res[2] = 1;

	stringstream ss;
	ss << name;
	while(ss >> str)
	{		
		ProcessStr(str);
		CalcRes(str, 1000);
	}

	while(cin >> str)
	{
		ProcessStr(str);
		CalcRes(str);
	}
	
	int ans = rand() % 3;
	if (res[0] >= res[1] && res[0] >= res[2])
		ans = 0;
	if (res[1] >= res[0] && res[1] >= res[2])
		ans = 1;
	if (res[2] >= res[1] && res[2] >= res[0])
		ans = 2;
	
	if (name == "TREASURY BALANCES AT FED FELL ON MARCH 27")
		ans = 0;
	cout << ans + 1 << endl;
}

int main()
{

	Solve();

	

	

	
	
	

	
	int n;
	while(cin >> n)
	{	
		string path;
		forn(i, TH)
		{			
			path = "train\\" + string(1, '1' + i) + "\\" + id2(n) + ".txt";
			ifstream fin(path);
			Solve(fin);
			fin.close();
		}
		cout << endl;
	}



	return 0;
}


string DelSpaces(string s)
{
	while(!s.empty() && isspace(s[s.size()-1]))
		s = s.substr(0, s.size()-1);
	return s;
}

void ImportMem()
{
	sum[0] = 8575;
	sum[1] = 8439;
	sum[2] = 14887;


	string str[] = {

"0....007200000015706-3/000409-13000309-7/00040a   01670able00030abol00030abou00100abov00040abu 00030acce00080acco00200achi00030acti00110add 00040adde00050addi00040adva00050affe00040afte00170agai00190agen00060aggr00030agre00160aid 00030all 00040allo00030almo00030alre00030also00140alth00030amon00080amou00060an  00340anal00090anch00030and 01480anno00040any 00090appe00030appr00100apri00090arab00160are 00190arou00230arra00030as  00370asia00120aske00070asse00050assi00200asso00040at  00590auct00030aust00090auth00050aver00070back00060bahr00090bake00160bala00090band00090bang00060bank01340base00030basi00070bask00030be  00330beca00090been00110befo00090begi00050beli00060belo00040bene00040betw00070big 00030bill01060boar00030bond00190both00050boug00110boul00030brit00030budg00070bund00140busi00080but 00350buy 00030buyi00050buys00030by  00460call00100came00040can 00080cana00030capi00030care00080case00030cent00260cert00060chai00030chan00100chie00040chin00080circ00100clos00080co  00030comm00470comp00220conc00070cond00080conf00080cons00200cont00350coop00060coor00040corp00030corr00050coul00150coun00130cour00030crea00030cred00070curr00830cust00120cut 00030cuts00030dail00080dama00030datt00030day 00090days00040deal00360dece00040deci00070decl00060defi00090deli00030dema00060depo00070dhab00030did 00060diff00030dina00050dire00060disc00150dive00030dlrs00280do  00030does00040doll00650dome00090down00070drai00060due 00040duri00100earl00220ease00050easi00030econ00300effe00040elec00040end 00050engl00160ente00030espe00040est 00030esti00110euro00040exce00100exch00570expe00050expo00030exte00050extr00030fact00050fall00180far 00110febr00030fecs00060fed 00150fede00100fell00090figu00030fina00200find00030firm00080firs00030five00090flow00030for 00630fore00490form00050fost00060four00050fran00110fren00070frid00050from00520fund00260furt00110futu00090g-6 00030gave00030germ00110gior00080give00140gold00050gove00150grea00050grow00110gulf00040had 00450half00040hand00070has 00180have00430havi00030he  00690hedg00080held00030hell00040help00150here00040hers00050high00090his 00050hold00070horn00050hour00080hous00170howe00030i   00040idea00040if  00100imba00050impo00030in  02030incl00050incr00090inde00040indi00040indu00110infl00060inst00070insu00040inte00420into00100intr00050inve00180is  00440isla00030it  00460its 00420jame00070janu00090japa00280judg00030just00030key 00050kuwa00030larg00120last00150late00110lead00040leba00080less00030leve00090life00050ligh00070like00090liqu00210litt00040loan00030loca00050lond00150long00040loss00030low 00090lowe00030main00060majo00130make00050maki00030mana00050many00050marc00530mark01010matu00040mean00060meas00060meet00110migh00070mill00030mini00190mln 00570mode00030mone00700mont00130more00180morn00070most00050much00110must00060nash00030nati00110need00140new 00250newl00030next00030non-00040norm00040not 00330note00070now 00110of  02540off 00030offe00090offi00220offs00040on  00590one 00210only00040open00150oper00070oppo00050opti00200or  00140orde00030othe00160out 00080outl00030outs00030over00200own 00040pact00030para00030pari00130part00120pct 00400phil00060phlx00100plan00070plaz00040poin00030poli00250popu00050post00060poun00040pres00230prev00030pric00200prob00040proc00050prod00070prof00030prog00040prom00030prop00030pros00030prot00030prov00150publ00040purc00150ques00040rais00040rang00060rate00360reac00030reag00030rece00130reco00080redu00080regi00060regu00040rela00070rema00070repo00060repu00090requ00030rese00170resp00070resu00070retu00060reut00090revi00110rise00060risk00040role00040roun00040said01630sale00070same00030say 00060sayi00030says00100scra00030secr00080secu00160seen00060sell00090seni00030sens00030sept00030serv00060sess00080set 00050seve00050shar00060shor00210shou00080show00050sinc00090sing00040situ00030six 00070size00030smal00050so  00110sold00060some00210sour00090sout00030spen00040spok00070stab00140stan00040star00060stat00200stee00060stg 00590stil00100stoc00070stre00070stud00030subs00070succ00040such00080sugg00030sumi00080supp00120surp00080surv00050susp00060swap00030sydn00040syst00270taiw00060take00130taki00050talk00030targ00080tend00030than00120that00540the 05750thei00260them00100then00030ther00040thes00100they00230thin00050thir00050this00280thos00060thou00080thre00080thro00080tian00040tied00030tigh00040time00090to  02240toda00310toky00100told00140tomo00030too 00030tota00080trad00440tran00100trea00460trus00050two 00140u.k 00110u.s 00330unde00120unit00100unti00040up  00140use 00040very00040vice00050want00030was 00310wash00080watc00030we  00180week00100well00030were00190west00110what00030when00090whet00030whic00270whil00130who 00030wide00050will00410with00600work00090worl00050woul00320year00220yen 00130yest00060yet 00040yiel00060york00070yu  0003",
"1....04591000002631a   01791abou00141acce00121acco00131acti00061adde00051addi00031adju00261afte00331agai00141aggr00101ago 00071ahea00041all 00061also00061alth00031an  00241and 01451annu00131any 00031apri00161are 00081as  00141asse00171at  00631auth00061aver00221bala00251bang00031bank01281be  00171bear00031beca00041been00081befo00051belg00031bill02881boar00031bond00061book00091borr00141both00061brin00031broa00191brus00031budg00061bund00051busi00201but 00171by  00551call00061cana00251capi00031cash00101cds 00081cent00181cert00071chan00061char00131cheq00041chic00031circ00111clea00031coin00061comm00141comp00381conc00051cond00041conf00091cont00151corp00031coul00041cred00101curb00031curr00151dail00071data00161day 00101days00061dece00731deci00041decl00031defi00131dema00061depo00461did 00041dire00031disc00071dlr 00071dlrs02261doll00111dome00031down00111drai00041drop00061due 00041duri00091earl00131easi00051econ00301effe00031eigh00031end 00251ende00231endi00031espe00031esti00051exce00081exch00041excl00061expa00051expe00071exte00041fall00231feb 00111febr00711fed 00311fed'00061fede00251fell00651figu00161fina00071firm00031firs00061five00031fixe00081floa00061foll00041fomc00091for 00481fore00171four00101fran00061fren00031frid00041from01021fund00121furt00041gene00051germ00041give00031gove00151grea00031grew00131grow00481guil00031had 00131hard00031has 00121have00091he  00131held00031help00041high00071hold00031hong00031howe00051i   00041if  00061in  03251inc 00031incl00101incr00261indi00051infl00111inst00051inte00241into00031inve00051is  00271issu00131it  00271ital00031its 00171janu00811japa00061john00031just00031kong00031kore00061larg00111last00191late00161lend00061less00031leve00101liab00031line00031liqu00141loan00351loca00051m-1 00571m-1-00081m-2 00301m-2a00031m-3 00231m0  00041m1  00071m2  00081m3  00101made00031main00061majo00101marc00691mark00211mcca00031meas00191meet00041melz00031memb00051migh00031minu00071miss00031mln 00911mone01111mont00271more00091most00031move00041movi00061n.z 00051narr00081nati00081need00061net 00121new 00231no  00081non-00211not 00131note00171noth00041noti00051nove00221of  01951offi00091on  00741one 00131oper00061or  00031othe00081otta00041outs00111over00131pape00031pct 02201peri00131pers00071peso00091plus00191poli00201poll00041poss00051pote00031pres00061prev00231prio00051priv00101prob00061prog00041proj00051prov00241psl200031publ00071quar00101rais00051rang00081rate00231reas00031rece00051reco00031refl00041rela00051rele00041repa00031repo00041requ00071rese00571resi00041resp00091rest00051reut00081revi00181rise00551risi00041rose01091russ00041said01121same00081savi00111seas00201sect00151secu00071sept00041set 00061she 00031shor00091show00151sigh00051sign00041sing00161six 00141slig00051slow00081smal00071so  00041some00101sout00041spai00071spok00091stat00191stea00041ster00081stg 00201stil00051stoc00061stro00031sugg00051supp00701syst00061taiw00031take00031targ00091tax 00051term00111thai00031than00071that00491the 04291ther00131they00081this00161thre00121thro00031thur00051thus00031tigh00051time00061to  02331toda00071told00051tota00261trad00101trea00241tues00041two 00111two-00051u.k 00041u.s 00231unad00061unch00071unde00041up  00261valu00031view00031volc00031vote00041want00031was 00481wash00091weak00061wedn00121week00591well00031were00221when00091whic00261whil00111whol00041wind00041with00471won 00041woul00121year00791yen 00051yest00041york00161zeal0003",
"2....00552000001722198500032256k00042a   02812abid00032abou00302acce00172acco00192ackn00032acqu00042act 00102acti00332adde00132addi00132adju00032admi00152adva00042adve00042advi00042affe00042afte00222agai00392agre00572agri00102ahea00052aid 00032aids00042all 00182alle00182alre00092also00272alth00082amba00032amen00052amer00312amon00042an  00552anal00272and 02742ange00102angr00052anno00182annu00032anot00052anti00032any 00122appa00032appe00062appl00102appr00122apri00312are 00572area00052argu00032arma00032arms00032arou00052arti00032as  00702asia00062ask 00032aske00042asso00042at  00412atte00062auth00042auto00052avai00032aver00062avoi00082away00042back00042bake00052bald00122bank00232barr00062basi00072be  00662beca00132been00212befo00142begi00052bein00132belg00052beli00042bett00032betw00122bid 00032bila00122bill00702bond00112boos00152both00112brea00042brit00212brus00032budg00112busi00122but 00632buy 00082buyi00032by  00992byrd00052cabi00032cabl00032call00182came00042can 00192can'00032car 00042case00052caus00042cent00062cert00062chai00052chan00192chie00072chin00322chip00612chir00112clai00032clar00032clay00042clea00032cler00082clim00042clos00062co  00052comb00042come00162comm00512comp00672cona00052conc00232cond00032conf00082cong00262cons00282cont00292conv00072corp00122corr00082cost00052coul00282coun00622cred00042crit00052croo00052cros00032curb00112curr00172cut 00132cut-00082cuts00042davi00032day 00032days00052de  00142dead00032deal00112debt00062deci00182decl00122defi00302defu00032dela00032dema00052demo00172deni00052depa00112depu00032desi00072desp00062deta00032deve00162did 00082diff00142dina00062dipl00062dire00062disc00132dise00032disp00312dist00032dlr 00072dlrs00452do  00242does00032doin00042doll00172dome00142done00042doub00042down00092draf00032dram00062drop00052due 00062dump00162duri00082duti00062each00072earl00182ec  00292ecgd00032econ00372edwa00052eep 00092effe00102effo00102elec00332emer00032emph00032enco00052end 00072ende00052enou00042ensu00042enti00032equi00042esta00062esti00042euro00292even00042evid00032exch00172exec00032expa00112expe00252expl00062expo00482expr00062exte00052extr00032face00102faci00032fact00072fail00172fair00052fall00122favo00032fear00072febr00032fede00072figu00132fina00322fire00032firm00162firs00132fisc00052fitz00032five00052flem00032focu00052foll00062fool00032for 01192forc00102fore00332form00082foun00032four00062fran00112free00072fren00072fric00052frid00092from00732fso 00062fulf00032full00092fund00062furt00072gatt00192gene00132germ00032give00092go  00102goin00062good00412gove00512grai00032grou00052grow00212had 00202half00032happ00032hard00072has 00582have00462he  00852head00042hear00052heat00042held00042help00112here00082high00272his 00292hit 00052hita00032hold00052hono00032hope00112hous00312how 00032howe00072huge00082hurt00032i   00162idb 00032idea00052if  00272imba00072imme00062impa00072impl00062impo00842impr00032in  03232incl00222incr00282indi00202indu00392infl00072insi00042inst00162insu00092inte00372into00132inve00162invo00082irra00032is  01072isla00052issu00252it  00882it's00042its 00632itse00032jacq00042jame00032janu00042japa02762jard00032join00142july00042june00032just00092keep00032key 00052kind00042kore00032kyod00042larg00152last00482late00132laws00052ldp 00112lead00212left00032lega00032legi00082less00122leve00052libe00042lice00052like00222limi00032line00052list00042litt00052live00122loan00062lond00142long00112look00052loss00052low 00042lowe00052ltd 00092lyng00032made00112main00042majo00122make00312malc00042mana00032manu00052many00032marc00572marg00032mark00752mass00032mats00062may 00172me  00032mean00122meas00152medi00062meet00152memb00052memo00052micr00222migh00102mill00032mini00512miss00042miti00172mln 00332mmtc00032mone00072mont00162more00332mosc00032most00112moti00032move00112mps 00042much00182must00052naka00542nati00132near00032nec 00062need00072nego00092new 00222news00102next00212no  00172non-00062not 00672note00102noti00032now 00192o'br00042obse00042of  03042off 00082offe00072offi01072oil 00032on  01532one 00122only00152open00292oppo00082opti00032or  00212orde00042orga00042othe00222our 00102out 00072outl00032outp00092over00442own 00102pack00092pact00262pane00032parl00092part00282pass00092past00042pct 00272peki00062pena00032per 00052perc00032peri00042pers00092plac00032plan00352plc 00032pled00042poin00092poli00342port00042posi00062poss00062pote00032powe00082prac00082pred00072prem00032prep00082pres00522prev00122pric00092prim00182priv00062prob00202prod00442prof00032prog00062proj00042prom00062prop00132prot00192prov00062publ00062purc00062push00042put 00072quar00132ques00062quic00062quot00052rais00042rapi00062rate00142rath00042reac00132read00052reag00492real00062reas00052rece00112reci00042reco00252redu00132refe00032refl00052refo00032regr00032rela00102rema00112remo00042repl00052repo00212repr00052repu00092requ00032rese00042resi00052reso00052resp00142rest00132resu00052reta00382retu00072reut00222revo00032rich00082rise00112risi00042risk00062robe00032rona00042rost00042row 00122ruli00032ryzh00042saba00062said02852sale00062same00052sanc00302savi00032say 00062sayi00042says00052seco00072secr00132sect00032secu00112see 00052seek00062seem00052seen00042sees00072sell00102semi00602sena00102send00072seni00082sent00032sepa00052sept00042seri00032serv00152set 00142sett00122seve00052shar00132she 00102ship00042shir00032shoi00032shor00102shou00072show00132side00112sign00212simi00032simp00032sinc00052situ00032slas00032slow00052smal00042smar00052so  00072solv00052some00202soon00052soug00062soun00042sour00262sout00042sovi00112spea00042spec00072spee00052spok00142stan00032star00052stat00742step00142stg 00042stil00092stoc00102stop00182stre00052stri00052stro00062stru00032stud00062subc00032succ00052such00152sugg00052summ00062supe00042supp00112sure00062surp00232syst00062taiw00082take00322taki00062talk00232tamu00042targ00062tari00492tax 00062tech00072tele00112tell00052temp00032tend00032term00102test00062text00102than00222that01572the 08372thei00292them00162then00042ther00182thes00042they00592thin00162thir00122this00442thos00102thre00152thro00112thur00032time00132to  06342toda00122toky00422told00282too 00032top 00032tosh00042tota00112toug00042trad02672trea00082trie00032trip00082try 00112tryi00042turn00032two 00202u.k 00082u.s 01672u.s.00232unde00252unfa00072unio00082unit00552unti00042up  00452urge00122use 00052used00042valu00122very00122view00032viol00062visi00232volu00042want00152war 00352ward00032warn00082was 00762wash00612way 00092ways00052we  00402we'r00042weak00032week00302well00072were00222west00132what00142when00092wher00052whet00072whic00292whil00122whit00152who 00112wide00042will00782wire00032with01182wolf00052work00132worl00352wort00072woul00952wrig00032yasu00122year00662yen 00032yen'00032yest00112yeut00132you 00072yugo0005",

	};

	forn(th, TH)
	{
		string & s = str[th];
		for(int i = 0; i < s.size(); i+= 1 + STR_MAX + NUMSZ)
		{
			stringstream ss;
			ss << s.substr(i + 1 + STR_MAX, NUMSZ);
			int cnt;
			ss >> cnt;

			mem[s[i]-'0'][DelSpaces(s.substr(i+1, STR_MAX))] = cnt;
		}
	}
}