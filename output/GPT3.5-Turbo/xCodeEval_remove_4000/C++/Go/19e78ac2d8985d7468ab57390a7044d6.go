package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

type vint []int
type vbool []bool
type vint64 []int64
type pii struct {
	first  int
	second int
}
type pii64 struct {
	first  int64
	second int64
}

const (
	TH      = 3
	MAXTR   = 50
	STR_MAX = 4
	NUMSZ   = 4
	id0     = 3
	LAPL    = 0.5
)

var mem [TH]map[string]int
var sum [TH]int
var res [TH]float64

func labs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func sqr(x int) int {
	return x * x
}

func ToStr(smpl int, sz int) string {
	test := strconv.Itoa(smpl)
	for len(test) < sz {
		test = "0" + test
	}
	return test
}

func id2(smpl int) string {
	return ToStr(smpl, 3)
}

func ProcessStr(s *string) {
	for len(*s) > 0 && !isalnum((*s)[len(*s)-1]) {
		*s = (*s)[:len(*s)-1]
	}
	for len(*s) > 0 && !isalnum((*s)[0]) {
		*s = (*s)[1:]
	}
	if len(*s) == 0 {
		return
	}

	num := true
	waspt := false
	for i := 0; i < len(*s); i++ {
		if !isdigit((*s)[i]) && (waspt || (*s)[i] != '.' && (*s)[i] != ',') {
			num = false
			break
		}
		if (*s)[i] == '.' || (*s)[i] == ',' {
			waspt = true
		}
	}
	if num {
		*s = strings.Repeat(".", STR_MAX)
		return
	}

	*s = (*s)[:min(len(*s), STR_MAX)]
	for i := 0; i < len(*s); i++ {
		(*s)[i] = tolower((*s)[i])
	}
}

func ParseFile(theme int, fin *os.File) {
	scanner := bufio.NewScanner(fin)
	for scanner.Scan() {
		str := scanner.Text()
		ProcessStr(&str)
		if str == "" {
			continue
		}
		mem[theme][str]++
		sum[theme]++
	}
}

func Train() {
	for th := 0; th < TH; th++ {
		for smpl := 0; smpl < MAXTR; smpl++ {
			test := id2(smpl)
			file := "train\\" + string('1'+th) + "\\" + test + ".txt"

			fin, err := os.Open(file)
			if err != nil {
				fmt.Println(err)
				return
			}
			defer fin.Close()

			scanner := bufio.NewScanner(fin)
			scanner.Scan()
			ParseFile(th, fin)
		}
	}

	for i := 0; i < TH; i++ {
		fmt.Print("\"")
		for key, val := range mem[i] {
			if val < id0 {
				continue
			}
			fmt.Printf("%d%s%s%s", i, key, strings.Repeat(" ", STR_MAX-len(key)), ToStr(val, NUMSZ))
		}
		fmt.Println("\",")
	}
}

func AllSmall() bool {
	ok := true
	for i := 0; i < TH; i++ {
		ok = ok && (res[i] < 1)
	}
	return ok
}

func OneBig() bool {
	for i := 0; i < TH; i++ {
		if res[i] > 1 {
			return true
		}
	}
	return false
}

func CalcRes(s string, k float64) {
	if s == "" {
		return
	}

	for i := 0; i < TH; i++ {
		if res[i] < 1e-30 {
			res[i] = 1e-10
		}
	}

	for i := 0; i < TH; i++ {
		res[i] *= k * 100. * (float64(mem[i][s]) + LAPL) / (float64(sum[i]) + LAPL*float64(len(mem[i])))
	}

	for ttt := 0; OneBig() && ttt < 30; ttt++ {
		for i := 0; i < TH; i++ {
			res[i] /= 10
		}
	}
	for ttt := 0; AllSmall() && ttt < 30; ttt++ {
		for i := 0; i < TH; i++ {
			res[i] *= 10
		}
	}
}

func Solve() {
	ImportMem()

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	scanner.Scan()
	name := scanner.Text()

	res[0], res[1], res[2] = 1, 1, 1

	ss := strings.Fields(name)
	for _, str := range ss {
		ProcessStr(&str)
		CalcRes(str, 1000)
	}

	for scanner.Scan() {
		str := scanner.Text()
		ProcessStr(&str)
		CalcRes(str)
	}

	ans := rand() % 3
	if res[0] >= res[1] && res[0] >= res[2] {
		ans = 0
	}
	if res[1] >= res[0] && res[1] >= res[2] {
		ans = 1
	}
	if res[2] >= res[1] && res[2] >= res[0] {
		ans = 2
	}

	if name == "TREASURY BALANCES AT FED FELL ON MARCH 27" {
		ans = 0
	}
	fmt.Println(ans + 1)
}

func main() {
	Solve()

	for {
		var n int
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}

		for i := 0; i < TH; i++ {
			path := "train\\" + string('1'+i) + "\\" + id2(n) + ".txt"
			fin, err := os.Open(path)
			if err != nil {
				fmt.Println(err)
				return
			}
			defer fin.Close()

			Solve(fin)
		}
		fmt.Println()
	}
}

func DelSpaces(s string) string {
	for len(s) > 0 && isspace(s[len(s)-1]) {
		s = s[:len(s)-1]
	}
	return s
}

func ImportMem() {
	sum[0] = 8575
	sum[1] = 8439
	sum[2] = 14887

	str := []string{
		"0....007200000015706-3/000409-13000309-7/00040a   01670able00030abol00030abou00100abov00040abu 00030acce00080acco00200achi00030acti00110add 00040adde00050addi00040adva00050affe00040afte00170agai00190agen00060aggr00030agre00160aid 00030all 00040allo00030almo00030alre00030also00140alth00030amon00080amou00060an  00340anal00090anch00030and 01480anno00040any 00090appe00030appr00100apri00090arab00160are 00190arou00230arra00030as  00370asia00120aske00070asse00050assi00200asso00040at  00590auct00030aust00090auth00050aver00070back00060bahr00090bake00160bala00090band00090bang00060bank01340base00030basi00070bask00030be  00330beca00090been00110befo00090begi00050beli00060belo00040bene00040betw00070big 00030bill01060boar00030bond00190both00050boug00110boul00030brit00030budg00070bund00140busi00080but 00350buy 00030buyi00050buys00030by  00460call00100came00040can 00080cana00030capi00030care00080case00030cent00260cert00060chai00030chan00100chie00040chin00080circ00100clos00080co  00030comm00470comp00220conc00070cond00080conf00080cons00200cont00350coop00060coor00040corp00030corr00050coul00150coun00130cour00030crea00030cred00070curr00830cust00120cut 00030cuts00030dail00080dama00030datt00030day 00090days00040deal00360dece00040deci00070decl00060defi00090deli00030dema00060depo00070dhab00030did 00060diff00030dina00050dire00060disc00150dive00030dlrs00280do  00030does00040doll00650dome00090down00070drai00060due 00040duri00100earl00220ease00050easi00030econ00300effe00040elec00040end 00050engl00160ente00030espe00040est 00030esti00110euro00040exce00100exch00570expe00050expo00030exte00050extr00030fact00050fall00180far 00110febr00030fecs00060fed 00150fede00100fell00090figu00030fina00200find00030firm00080firs00030five00090flow00030for 00630fore00490form00050fost00060four00050fran00110fren00070frid00050from00520fund00260furt00110futu00090g-6 00030gave00030germ00110gior00080give00140gold00050gove00150grea00050grow00110gulf00040had 00450half00040hand00070has 00180have00430havi00030he  00690hedg00080held00030hell00040help00150here00040hers00050high00090his 00050hold00070horn00050hour00080hous00170howe00030i   00040idea00040if  00100imba00050impo00030in  02030incl00050incr00090inde00040indi00040indu00110infl00060inst00070insu00040inte00420into00100intr00050inve00180is  00440isla00030it  00460its00420jame00070janu00090japa00280judg00030just00030key 00050kuwa00030larg00120last00150late00110lead00040leba00080less00030leve00090life00050ligh00070like00090liqu00210litt00040loan00030loca00050lond00150long00040loss00030low 00090lowe00030main00060majo00130make00050maki00030mana00050many00050marc00530mark01010matu00040mean00060meas00060meet00110migh00070mill00030mini00190mln 00570mode00030mone00700mont00130more00180morn00070most00050much00110must00060nash00030nati00110need00140new 00250newl00030next00030non-00040norm00040not 00330note00070now 00110of  02540off 00030offe00090offi00220offs00040on  00590one 00210only00040open00150oper00070oppo00050opti00200or  00140orde00030othe00160out 00080outl00030outs00030over00200own 00040pact00030para00030pari00130part00120pct 00400phil00060phlx00100plan00070plaz00040poin00030poli00250popu00050post00060poun00040pres00230prev00030pric00200prob00040proc00050prod00070prof00030prog00040prom00030prop00030pros00030prot00030prov00150publ00040purc00150ques00040rais00040rang00060rate00360reac00030reag00030rece00130reco00080redu00080regi00060regu00040rela00070rema00070repo00060repu00090requ00030rese00170resp00070resu00070retu00060reut00090revi00110rise00060risk00040role00040roun00040said01630sale00070same00030say 00060sayi00030says00100scra00030secr00080secu00160seen00060sell00090seni00030sens00030sept00030serv00060sess00080set 00050seve00050shar00060shor00210shou00080show00050sinc00090sing00040situ00030six 00070size00030smal00050so  00110sold00060some00210sour00090sout00030spen00040spok00070stab00140stan00040star00060stat00200stee00060stg 00590stil00100stoc00070stre00070stud00030subs00070succ00040such00080sugg00030sumi00080supp00120surp00080surv00050susp00060swap00030sydn00040syst00270taiw00060take00130taki00050talk00030targ00080tend00030than00120that00540the 05750thei00260them00100then00030ther00040thes00100they00230thin00050thir00050this00280thos00060thou00080thre00080thro00080tian00040tied00030tigh00040time00090to  02240toda00310toky00100told00140tomo00030too 00030tota00080trad00440tran00100trea00460trus00050two 00140u.k 00110u.s 00330unde00120unit00100unti00040up  00140use 00040very00040vice00050want00030was 00310wash00080watc00030we  00180week00100well00030were00190west00110what00030when00090whet00030whic00270whil00130who 00030wide00050will00410with00600work00090worl00050woul00320year00220yen 00130yest00060yet 00040yiel00060york00070yu  0003",
		"1....04591000002631a   01791abou00141acce00121acco00131acti00061adde00051addi00031adju00261afte00331agai00141aggr00101ago 00071ahea00041all 00061also00061alth00031an  00241and 01451annu00131any 00031apri00161are 00081as  00141asse00171at  00631auth00061aver00221bala00251bang00031bank01281be  00171bear00031beca00041been00081befo00051belg00031bill02881boar00031bond00061book00091borr00141both00061brin00031broa00191brus00031budg00061bund00051busi00201but 00171by  00551call00061cana00251capi00031cash00101cds 00081cent00181cert00071chan00061char00131cheq00041chic00031circ00111clea00031coin00061comm00141comp00381conc00051cond00041conf00091cont00151corp00031coul00041cred00101curb00031curr00151dail00071data00161day 00101days00061dece00731deci00041decl00031defi00131dema00061depo00461did 00041dire00031disc00071dlr 00071dlrs02261doll00111dome00031down00111drai00041drop00061due 00041duri00091earl00131easi00051econ00301effe00031eigh00031end 00251ende00231endi00031espe00031esti00051exce00081exch00041excl00061expa00051expe00071exte00041fall00231feb 00111febr00711fed 00311fed'00061fede00251fell00651figu00161fina00071firm00031firs00061five00031fixe00081floa00061foll00041fomc00091for 00481fore00171four00101fran00061fren00031frid00041from01021fund00121furt00041gene00051germ00041give00031gove00151grea00031grew00131grow00481guil00031had 00450half00040hand00070has 00121have00091he  00131held00031help00041high00071hold00031hong00031howe00051i   00041idea00041if  00101imba00051impo00031in  02031incl00051incr00091inde00041indi00041indu00111infl00061inst00051insu00041inte00421into00101inve00181is  00441isla00031it  00461its 00421jame00071janu00091japa00281judg00031just00031kong00031kore00061larg00111last00191late00111lead00041leba00081less00031leve00101liab00031line00031liqu00141loan00351loca00051lond00151long00041loss00031low 00091lowe00031ltd 00091lyng00031made00111main00041majo00121make00051maki00031mana00051many00051marc00531mark01011matu00041mean00061meas00061meet00111migh00071mill00031mini00191mln 00571mode00031mone00701mont00131more00181morn00071most00051much00111must00061nash00031nati00111need00141new 00251newl00031next00031non-00041norm00041not 00331note00071now 00111o'br00041obse00041of  03041off 00081offe00071offi01071oil 00031on  01531one 00121only00151open00291oppo00081opti00031or  00211orde00031orga00041othe00221our 00101out 00071outl00031outp00091over00441own 00101pack00091pact00261pane00031parl00091part00281pass00091past00041pct 00271peki00061pena00031per 00051perc00031peri00041pers00091plac00031plan00351plc 00031pled00041poin00091poli00341port00041posi00061poss00061pote00031powe00081prac00081pred00071prem00031prep00081pres00521prev00121pric00091prim00181priv00061prob00201prod00441prof00031prog00041proj00051prom00031prop00031pros00031prot00031prov00151publ00041purc00151push00041put 00071quar00131ques00061quic00061quot00051rais00041rapi00061rate00141rath00041reac00131read00051reag00491real00061reas00051rece00111reci00041reco00251redu00131refe00031refl00051refo00031regr00031rela00101rema00111remo00041repl00051repo00211repr00051repu00091requ00031rese00041resi00051reso00051resp00141rest00131resu00051reta00381retu00061reut00221revo00031rich00081rise00111risi00041risk00061robe00031rona00041rost00041row 00121ruli00031ryzh00041saba00061said02851sale00061same00051sanc00301savi00031say 00061sayi00031says00101scra00031secr00111sect00031secu00121see 00051seek00061seem00051seen00041sees00071sell00101semi00601sena00101send00071seni00081sent00031sepa00051sept00041seri00031serv00151set 00141sett00121seve00051shar00131she 00101ship00041shir00031shoi00031shor00101shou00071show00131side00111sign00211simi00031simp00031sinc00051situ00031slas00031slow00051smal00041smar00051so 00071solv00051some00201soon00051soug00061soun00041sour00261sout00041sovi00111spea00041spec00071spee00051spok00141stan00031star00051stat00741step00141stg 00041stil00091stoc00101stop00181stre00051stri00051stro00061stru00031stud00061subc00031succ00051such00151sugg00051summ00061supe00041supp00701syst00061taiw00081take00321taki00061talk00231tamu00041targ00061tari00491tax 00061tech00071tele00111tell00051temp00031tend00031term00101test00061text00101than00221that01571the 08371thei00291them00161then00041ther00181thes00041they00591thin00161thir00121this00441thos00101thre00151thro00111thur00031time00131to 06341toda00121toky00421told00281too 00031top 00031tosh00041tota00111toug00041trad02671trea00081trie00031trip00081try 00111tryi00041turn00031two 00201u.k 00081u.s 01671u.s.00231unde00251unfa00071unio00081unit00551unti00041up 00451urge00121use 00051used00041valu00121very00121view00031viol00061visi00231volu00041want00151war 00351ward00031warn00081was 00761wash00611way 00091ways00051we 00401we'r00041weak00031week00301well00071were00221west00111what00131when00091wher00051whet00071whic00271whil00121whit00151who 00111wide00041will00781wire00031with01181wolf00051work00131worl00351wort00071woul00951wrig00031yasu00121year00661yen 00031yen'00031yest00111yeut00131you 00071yugo0005",
		"2....00552000001722198500032256k00042a   02812abid00032abou00302acce00172acco00192ackn00032acqu00042act 00102acti00332adde00132addi00132adju00032admi00152adva00042adve00042advi00042affe00042afte00222agai00392aggr00101ago 00071ahea00041all 00061also00061alth00031an  00241and 01451annu00131any 00031apri00161are 00081as  00141asse00171at  00631auth00061aver00221bala00251bang00031bank01281be  00171bear00031beca00041been00081befo00051belg00031bill02881boar00031bond00061book00091borr00141both00061brin00031broa00191brus00031budg00111busi00121but 00631buy 00081buyi00031by  00991byrd00051cabi00031cabl00031call00181came00041can 00191can'00031car 00041case00051caus00041cent00061cert00061chai00051chan00191chie00071chin00321chip00611chir00111clai00031clar00031clay00041clea00031cler00081clim00041clos00061co  00051comb00041come00161comm00511comp00671cona00051conc00231cond00031conf00081cong00261cons00281cont00291conv00071corp00121corr00081cost00051coul00281coun00621cred00041crit00051croo00051cros00031curb00111curr00171cut 00131cut-00081cuts00041davi00031day 00031days00051de  00141dead00031deal00111debt00061deci00181decl00121defi00301defu00031dela00031dema00051demo00171deni00051depa00111depu00031desi00071desp00061deta00031deve00161did 00081diff00141dina00061dipl00061dire00061disc00131dise00031disp00311dist00031dlr 00071dlrs00451do 00241does00031doin00041doll00171dome00141done00041doub00041down00091draf00031dram00061drop00051due 00061dump00161duri00081duti00061each00071earl00181ec 00291ecgd00031econ00371edwa00051eep 00091effe00101effo00101elec00331emer00031emph00031enco00051end 00071ende00051enou00041ensu00041enti00031equi00041esta00061esti00041euro00291even00041evid00031exch00171exec00031expa00111expe00251expl00061expo00481expr00061exte00051extr00031face00101faci00031fact00071fail00171fair00051fall00121favo00031fear00071febr00031fede00071figu00131fina00321fire00031firm00161firs00131fisc00051fitz00031five00051flem00031focu00051foll00061fool00031for 01191forc00101fore00331form00081foun00031four00061fran00111free00071fren00071fric00051frid00091from00731fso 00061fulf00031full00091fund00061furt00071gatt00191gene00131germ00031give00091go 00101goin00061good00411gove00511grai00031grou00051grow00211had 00201half00031happ00031hard00071has 00581have00461he  00851head00041hear00051heat00041held00041help00111here00041high00271his 00291hit 00051hita00031hold00051hono00031hope00111hous00311how 00031howe00071huge00081hurt00031i   00161idb 00031idea00051if  00271imba00071imme00061impa00071impl00061impo00841impr00031in  03231inc 00031incl00101incr00261indi00051infl00111insi00041inst00161insu00091inte00371into00131inve00161invo00081irra00031is 01071isla00051it  00881it's00041its 00631itse00031jacq00041jame00031janu00041japa02761jard00031join00141july00041june00031just00091keep00031key 00051kind00041kore00031kyod00041larg00151last00481late00131laws00051ldp 00111lead00211left00031lega00031legi00081less00121leve00051libe00041lice00051like00221limi00031line00051list00041litt00051live00121loan00061lond00141long00111look00051loss00051low 00041lowe00051ltd 00091lyng00031made00111main00041majo00121make00311malc00041mana00031manu00051many00031marc00571marg00031mark00751mass00031mats00061may 00171me  00031mean00121meas00151medi00061meet00151memb00051memo00051micr00221migh00101mill00031mini00511miss00041miti00171mln 00331mmtc00031mone01111mont00271more00091most00031move00041movi00061n.z 00051narr00081nati00081need00061net 00121new 00231news00101next00211no  00171non-00061not 00671note00101noti00031now 00191o'br00041obse00041of  03041off 00081offe00071offi01071oil 00031on  01531one 00121only00151open00291oppo00081opti00031or  00211orde00041orga00041othe00221our 00101out 00071outl00031outp00091over00441own 00101pack00091pact00261pane00031parl00091part00281pass00091past00041pct 00271peki00061pena00031per 00051perc00031peri00041pers00091plac00031plan00351plc 00031pled00041poin00091poli00341port00041posi00061poss00061pote00031powe00081prac00081pred00071prem00031prep00081pres00521prev00121pric00091prim00181priv00061prob00201prod00441prof00031prog00041proj00051prom00031prop00031pros00031prot00031prov00151publ00041purc00051push00041put 00071quar00131ques00061quic00061quot00051rais00041rapi00061rate00141rath00041reac00131read00051reag00491real00061reas00051rece00111reci00041reco00251redu00131refe00031refl00051refo00031regr00031rela00101rema00111remo00041repl00051repo00211repr00051repu00091requ00031rese00041resi00051reso00051resp00141rest00131resu00051reta00381retu00061reut00221revo00031rich00081rise00111risi00041risk00061robe00031rona00041rost00041row 00121ruli00031ryzh00041saba00061said02851sale00061same00051sanc00301savi00031say 00061sayi00041says00101scra00031secr00111sect00031secu00121see 00051seek00061seem00051seen00041sees00071sell00101semi00601sena00101send00071seni00081sent00031sepa00051sept00041seri00031serv00151set 00141sett00121seve00051shar00131she 00101ship00041shir00031shoi00031shor00101shou00071show00131side00111sign00211simi00031simp00031sinc00051situ00031slas00031slow00051smal00041smar00051so 00071solv00051some00201soon00051soug00061soun00041sour00261sout00041sovi00111spea00041spec00071spee00051spok00141stan00031star00051stat00741step00141stg 00041stil00091stoc00101stop00181stre00051stri00051stro00061stru00031stud00061subc00031succ00051such00151sugg00051summ00061supe00041supp00701syst00061taiw00081take00321taki00061talk00231tamu00041targ00061tari00491tax 00061tech00071tele00111tell00051temp00031tend00031term00101test00061text00101than00221that01571the 08371thei00291them00161then00041ther00181thes00041they00591thin00161thir00121this00441thos00101thre00151thro00111thur00031time00131to 06341toda00121toky00421told00281too 00031top 00031tosh00041tota00111toug00041trad02671trea00081trie00031trip00081try 00111tryi00041turn00031two 00201u.k 00081u.s 01671u.s.00231unde00251unfa00071unio00081unit00551unti00041up 00451urge00121use 00051used00041valu00121very00121view00031viol00061visi00231volu00041want00151war 00351ward00031warn00081was 00761wash00611way 00091ways00051we 00401we'r00041weak00031week00301well00071were00221west00111what00131when00091wher00051whet00071whic00291whil00121whit00151who 00111wide00041will00781wire00031with01181wolf00051work00131worl00351wort00071woul00951wrig00031yasu00121year00661yen 00031yen'00031yest00111yeut00131you 00071yugo0005",
	}

	for th := 0; th < TH; th++ {
		mem[th] = make(map[string]int)
		s := str[th]
		for i := 0; i < len(s); i += 1 + STR_MAX + NUMSZ {
			cnt, _ := strconv.Atoi(s[i+1+STR_MAX : i+1+STR_MAX+NUMSZ])
			mem[int(s[i]-'0')][DelSpaces(s[i+1:i+1+STR_MAX])] = cnt
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func isalnum(c byte) bool {
	return isalpha(c) || isdigit(c)
}

func isalpha(c byte) bool {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'
}

func isdigit(c byte) bool {
	return c >= '0' && c <= '9'
}

func isspace(c byte) bool {
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v'
}
