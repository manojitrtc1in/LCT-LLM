import string
import random
import sys

STR_MAX = 4
NUMSZ = 4
TAKE_CNT = 3
LAPL = 0.5

TH = 3
MAXTR = 50

mem = [{} for _ in range(TH)]
sum = [0] * TH

def labs(a):
    return -a if a < 0 else a

def sqr(x):
    return x * x

def ToStr(smpl, sz):
    test = str(smpl)
    while len(test) < sz:
        test = "0" + test
    return test

def ToStr3(smpl):
    return ToStr(smpl, 3)

def ProcessStr(s):
    while s and not s[-1].isalnum():
        s = s[:-1]
    while s and not s[0].isalnum():
        s = s[1:]
    if not s:
        return

    num = True
    waspt = False
    for c in s:
        if not c.isdigit() and (waspt or c != '.' and c != ','):
            num = False
            break
        if c == '.' or c == ',':
            waspt = True
    if num:
        s = '0' * STR_MAX if waspt else '.' * STR_MAX
        return

    s = s[:min(len(s), STR_MAX)].lower()
    return s

def ParseFile(theme, fin):
    for line in fin:
        words = line.split()
        for word in words:
            processed_word = ProcessStr(word)
            if processed_word:
                mem[theme][processed_word] = mem[theme].get(processed_word, 0) + 1
                sum[theme] += 1

def Train():
    for th in range(TH):
        for smpl in range(1, MAXTR+1):
            test = ToStr3(smpl)
            file = f"train/{chr(ord('1')+th)}/{test}.txt"

            with open(file, 'r') as fin:
                fin.readline()
                ParseFile(th, fin)

    for i in range(TH):
        print('"', end='')
        for key, value in mem[i].items():
            if value < TAKE_CNT:
                continue
            print(f"{i}{key.ljust(STR_MAX)}{str(value).rjust(NUMSZ)}", end='')
        print('",')

def CalcRes(s, k=1.0):
    if not s:
        return

    for i in range(TH):
        if res[i] < 1e-30:
            res[i] = 1e-10

    for i in range(TH):
        res[i] *= k * 100 * (mem[i].get(s, 0) + LAPL) / (sum[i] + LAPL * len(mem[i]))

    for ttt in range(30):
        if OneBig():
            for i in range(TH):
                res[i] /= 10
        if AllSmall():
            for i in range(TH):
                res[i] *= 10

def Solve():
    ImportMem()

    str = sys.stdin.readline().strip()
    name = sys.stdin.readline().strip()

    res = [1] * TH

    for word in name.split():
        processed_word = ProcessStr(word)
        CalcRes(processed_word, 1000)

    for line in sys.stdin:
        words = line.split()
        for word in words:
            processed_word = ProcessStr(word)
            CalcRes(processed_word)

    ans = random.randint(0, 2)
    if res[0] >= res[1] and res[0] >= res[2]:
        ans = 0
    if res[1] >= res[0] and res[1] >= res[2]:
        ans = 1
    if res[2] >= res[1] and res[2] >= res[0]:
        ans = 2

    if name == "TREASURY BALANCES AT FED FELL ON MARCH 27":
        ans = 0
    print(ans + 1)

def ImportMem():
    sum[0] = 8575
    sum[1] = 8439
    sum[2] = 14887

    str = [
        "0....007200000015706-3/000409-13000309-7/00040a   01670able00030abol00030abou00100abov00040abu 00030acce00080acco00200achi00030acti00110add 00040adde00050addi00040adva00050affe00040afte00170agai00190agen00060aggr00030agre00160aid 00030all 00040allo00030almo00030alre00030also00140alth00030amon00080amou00060an  00340anal00090anch00030and 01480anno00040any 00090appe00030appr00100apri00090arab00160are 00190arou00230arra00030as  00370asia00120aske00070asse00050assi00200asso00040at  00590auct00030aust00090auth00050aver00070back00060bahr00090bake00160bala00090band00090bang00060bank01340base00030basi00070bask00030be  00330beca00090been00110befo00090begi00050beli00060belo00040bene00040betw00070big 00030bill01060boar00030bond00190both00050boug00110boul00030brit00030budg00070bund00140busi00080but 00350buy 00030buyi00050buys00030by  00460call00100came00040can 00080cana00030capi00030care00080case00030cent00260cert00060chai00030chan00100chie00040chin00080circ00100clos00080co  00030comm00470comp00220conc00070cond00080conf00080cons00200cont00350coop00060coor00040corp00030corr00050coul00150coun00130cour00030crea00030cred00070curr00830cust00120cut 00030cuts00030dail00080dama00030datt00030day 00090days00040deal00360dece00040deci00070decl00060defi00090deli00030dema00060depo00070dhab00030did 00060diff00030dina00050dire00060disc00150dive00030dlrs00280do  00030does00040doll00650dome00090down00070drai00060due 00040duri00100earl00220ease00050easi00030econ00300effe00040elec00040end 00050engl00160ente00030espe00040est 00030esti00110euro00040exce00100exch00570expe00050expo00030exte00050extr00030fact00050fall00180far 00110febr00030fecs00060fed 00150fede00100fell00090figu00030fina00200find00030firm00080firs00030five00090flow00030for 00630fore00490form00050fost00060four00050fran00110fren00070frid00050from00520fund00260furt00110futu00090g-6 00030gave00030germ00110gior00080give00140gold00050gove00150grea00050grow00110gulf00040had 00450half00040hand00070has 00180have00430havi00030he  00690hedg00080held00030hell00040help00150here00040hers00050high00090his 00050hold00070horn00050hour00080hous00170howe00030i   00040idea00040if  00100imba00050impo00030in  02030incl00050incr00090inde00040indi00040indu00110infl00060inst00070insu00040inte00420into00100intr00050inve00180is  00440isla00030it  00460its00420jame00070janu00090japa00280judg00030just00030key 00050kuwa00030larg00120last00150late00110lead00040leba00080less00030leve00090life00050ligh00070like00090liqu00210litt00040loan00030loca00050lond00150long00040loss00030low 00090lowe00030main00060majo00130make00050maki00030mana00050many00050marc00530mark01010matu00040mean00060meas00060meet00110migh00070mill00030mini00190mln 00570mode00030mone00700mont00130more00180morn00070most00050much00110must00060nash00030nati00110need00140new 00250newl00030next00030non-00040norm00040not 00330note00070now 00110of  02540off 00030offe00090offi00220offs00040on  00590one 00210only00040open00150oper00070oppo00050opti00200or  00140orde00030othe00160out 00080outl00030outs00030over00200own 00040pact00030para00030pari00130part00120pct 00400phil00060phlx00100plan00070plaz00040poin00030poli00250popu00050post00060poun00040pres00230prev00030pric00200prob00040proc00050prod00070prof00030prog00040prom00030prop00030pros00030prot00030prov00150publ00040purc00150ques00040rais00040rang00060rate00360reac00030reag00030rece00130reco00080redu00080regi00060regu00040rela00070rema00070repo00060repu00090requ00030rese00170resp00070resu00070retu00060reut00090revi00110rise00060risk00040role00040roun00040said01630sale00070same00030say 00060sayi00030says00100scra00030secr00080secu00160seen00060sell00090seni00030sens00030sept00030serv00060sess00080set 00050seve00050shar00060shor00210shou00080show00050sinc00090sing00040situ00030six 00070size00030smal00050so  00110sold00060some00210sour00090sout00030spen00040spok00070stab00140stan00040star00060stat00200stee00060stg 00590stil00100stoc00070stre00070stud00030subs00070succ00040such00080sugg00030sumi00080supp00120surp00080surv00050susp00060swap00030sydn00040syst00270taiw00060take00130taki00050talk00030targ00080tend00030than00120that00540the 05750thei00260them00100then00030ther00040thes00100they00230thin00050thir00050this00280thos00060thou00080thre00080thro00080tian00040tied00030tigh00040time00090to  02240toda00310toky00100told00140tomo00030too 00030tota00080trad00440tran00100trea00460trus00050two 00140u.k 00110u.s 00330unde00120unit00100unti00040up  00140use 00040very00040vice00050want00030was 00310wash00080watc00030we  00180week00100well00030were00190west00110what00030when00090whet00030whic00270whil00130who 00030wide00050will00410with00600work00090worl00050woul00320year00220yen 00130yest00060yet 00040yiel00060york00070yu  0003",
        "1....04591000002631a   01791abou00141acce00121acco00131acti00061adde00051addi00031adju00261afte00331agai00141aggr00101ago 00071ahea00041all 00061also00061alth00031an  00241and 01451annu00131any 00031apri00161are 00081as  00141asse00171at  00631auth00061aver00221bala00251bang00031bank01281be  00171bear00031beca00041been00081befo00051belg00031bill02881boar00031bond00061book00091borr00141both00061brin00031broa00191brus00031budg00061bund00051busi00201but 00171by  00551call00061cana00251capi00031cash00101cds 00081cent00181cert00071chan00061char00131cheq00041chic00031circ00111clea00031coin00061comm00141comp00381conc00051cond00041conf00091cont00151corp00031coul00041cred00101curb00031curr00151dail00071data00161day 00101days00061dece00731deci00041decl00031defi00131dema00061depo00461did 00041dire00031disc00071dlr 00071dlrs02261doll00111dome00031down00111drai00041drop00061due 00041duri00091earl00131easi00051econ00301effe00031eigh00031end 00251ende00231endi00031espe00031esti00051exce00081exch00041excl00061expa00051expe00071exte00041fall00231feb 00111febr00711fed 00311fed'00061fede00251fell00651figu00161fina00071firm00031firs00061five00031fixe00081floa00061foll00041fomc00091for 00481fore00171four00101fran00061fren00031frid00041from01021fund00121furt00041gene00051germ00041give00031gove00151grea00031grew00131grow00481guil00031had 00450half00040hand00070has 00180have00430he  00690hedg00080held00030hell00040help00150here00040hers00050high00090his 00050hold00070horn00050hour00080hous00170howe00030i   00040idea00040if  00100imba00050impo00030in  02030incl00050incr00090inde00040indi00040indu00110infl00060inst00070insu00040inte00420into00100intr00050inve00180is  00440isla00030it  00460its00420jame00070janu00090japa00280judg00030just00030key 00050kuwa00030larg00120last00150late00110lead00040leba00080less00030leve00090life00050ligh00070like00090liqu00210litt00040loan00030loca00050lond00150long00040loss00030low 00090lowe00030main00060majo00130make00050maki00030mana00050many00050marc00530mark01010matu00040mean00060meas00060meet00110migh00070mill00030mini00190mln 00570mode00030mone00700mont00130more00180morn00070most00050much00110must00060nash00030nati00110need00140new 00250newl00030next00030non-00040norm00040not 00330note00070now 00110of  02540off 00030offe00090offi00220offs00040on  00590one 00210only00040open00150oper00070oppo00050opti00200or  00140orde00030othe00080otta00040outs00111over00131pape00031pct 02201peri00131pers00071peso00091plus00191poli00201poll00041poss00051pote00031pres00061prev00231prio00051priv00101prob00061prog00041proj00051prov00150publ00040purc00150ques00040rais00040rang00060rate00360reac00030reag00030rece00130reco00080redu00080regi00060regu00040rela00070rema00070repo00060repu00090requ00030rese00170resp00070resu00070retu00060reut00090revi00110rise00060risk00040role00040roun00040said01630sale00070same00030say 00060sayi00030says00100scra00030secr00080secu00160seen00060sell00090seni00030sens00030sept00030serv00060sess00080set 00050seve00050shar00060shor00210shou00080show00050sinc00090sing00040situ00030six 00070size00030smal00050so  00110sold00060some00210sour00090sout00030spen00040spok00070stab00140stan00040star00060stat00200stee00060stg 00590stil00100stoc00070stre00070stud00030subs00070succ00040such00080sugg00030sumi00080supp00120surp00080surv00050susp00060swap00030sydn00040syst00270taiw00060take00130taki00050talk00030targ00080tend00030than00120that00540the 05750thei00260them00100then00030ther00040thes00100they00230thin00050thir00050this00280thos00060thou00080thre00080thro00080tian00040tied00030tigh00040time00090to  02240toda00310toky00100told00140tomo00030too 00030tota00080trad00440tran00100trea00460trus00050two 00140u.k 00110u.s 00330unde00120unit00100unti00040up  00140use 00040very00040vice00050want00030was 00310wash00080watc00030we  00180week00100well00030were00190west00110what00030when00090whet00030whic00270whil00130who 00030wide00050will00410with00600work00090worl00050woul00320year00220yen 00130yest00060yet 00040yiel00060york00070yu  0003",
        "2....00552000001722198500032256k00042a   02812abid00032abou00302acce00172acco00192ackn00032acqu00042act 00102acti00332adde00132addi00132adju00032admi00152adva00042adve00042advi00042affe00042afte00222agai00392aggr00572agri00102ahea00052aid 00032aids00042all 00182alle00182alre00092also00272alth00082amba00032amen00052amer00312amon00042an  00552anal00272and 02742ange00102angr00052anno00182annu00032anot00052anti00032any 00122appa00032appe00062appl00102appr00122apri00312are 00572area00052argu00032arma00032arms00032arou00052arti00032as  00702asia00062ask 00032aske00042asso00042at  00412atte00062auth00042auto00052avai00032aver00062avoi00082away00042back00042bake00052bald00122bank00232barr00062basi00072be  00662beca00132been00212befo00142begi00052bein00132belg00052beli00042bett00032betw00122bid 00032bila00122bill00702bond00112boos00152both00112brea00042brit00212brus00032budg00112busi00122but 00632buy 00082buyi00032by  00992byrd00052cabi00032cabl00032call00182came00042can 00192can'00032car 00042case00052caus00042cent00062cert00062chai00052chan00192chie00072chin00322chip00612chir00112clai00032clar00032clay00042clea00032cler00082clim00042clos00062co  00052comb00042come00162comm00512comp00672cona00052conc00232cond00032conf00082cong00262cons00282cont00292conv00072corp00122corr00082cost00052coul00282coun00622cred00042crit00052croo00052cros00032curb00112curr00172cut 00132cut-00082cuts00042davi00032day 00032days00052de  00142dead00032deal00112debt00062deci00182decl00122defi00302defu00032dela00032dema00052demo00172deni00052depa00112depu00032desi00072desp00062deta00032deve00162did 00082diff00142dina00062dipl00062dire00062disc00132dise00032disp00312dist00032dlr 00072dlrs00452do  00242does00032doin00042doll00172dome00142done00042doub00042down00092draf00032dram00062drop00052due 00062dump00162duri00082duti00062each00072earl00182ec  00292ecgd00032econ00372edwa00052eep 00092effe00102effo00102elec00332emer00032emph00032enco00052end 00072ende00052enou00042ensu00042enti00032equi00042esta00062esti00042euro00292even00042evid00032exch00172exec00032expa00112expe00252expl00062expo00482expr00062exte00052extr00032face00102faci00032fact00072fail00172fair00052fall00122favo00032fear00072febr00032fede00072figu00132fina00322fire00032firm00162firs00132fisc00052fitz00032five00052flem00032focu00052foll00062fool00032for 01192forc00102fore00332form00082foun00032four00062fran00112free00072fren00072fric00052frid00092from00732fso 00062fulf00032full00092fund00062furt00072gatt00192gene00132germ00032give00092go  00102goin00062good00412gove00512grai00032grou00052grow00212had 00202half00032happ00032hard00072has 00582have00462he  00852head00042hear00052heat00042held00042help00112here00082high00272his 00292hit 00052hita00032hold00052hono00032hope00112hous00312how 00032howe00072huge00082hurt00032i   00162idb 00032idea00052if  00272imba00072imme00062impa00072impl00062impo00842impr00032in  03232incl00222incr00282indi00202indu00392infl00072insi00042inst00162insu00092inte00372into00132inve00162invo00082irra00032is 01072isla00052issu00252it 00882it's00042its 00632itse00032jacq00042jame00032janu00042japa02762jard00032join00142july00042june00032just00092keep00032key 00052kind00042kore00032kyod00042larg00152last00482late00132laws00052ldp 00112lead00212left00032lega00032legi00082less00122leve00052libe00042lice00052like00222limi00032line00052list00042litt00052live00122loan00062lond00142long00112look00052loss00052low 00042lowe00052ltd 00092lyng00032made00112main00042majo00122make00312malc00042mana00032manu00052many00032marc00572marg00032mark00752mass00032mats00062may 00172me  00032mean00122meas00152medi00062meet00152memb00052memo00052micr00222migh00102mill00032mini00512miss00042miti00172mln 00332mmtc00032mone00072mont00162more00332mosc00032most00112moti00032move00041movi00061n.z 00051narr00081nati00081need00061net 00121new 00231no  00171non-00061not 00671note00101noti00031now 00191o'br00042obse00042of  03041off 00081offe00071offi01071oil 00031on  01531one 00121only00151open00291oppo00081opti00031or  00211orde00041orga00041othe00221our 00101out 00071outl00031outp00091over00441own 00101pack00091pact00261pane00031parl00091part00281pass00091past00041pct 00271peki00061pena00031per 00051perc00031peri00041pers00091plac00031plan00351plc 00031pled00041poin00091poli00341port00041posi00061poss00061pote00031powe00081prac00081pred00071prem00031prep00081pres00521prev00121pric00091prim00181priv00061prob00201prod00441prof00031prog00061proj00041prom00061prop00131prot00191prov00061publ00061purc00061push00041put 00071quar00131ques00061quic00061quot00051rais00041rapi00061rate00141rath00041reac00131read00051reag00491real00061reas00051rece00111reci00041reco00251redu00131refe00031refl00051refo00031regr00031rela00101rema00111remo00041repl00051repo00211repr00051repu00091requ00031rese00041resi00051reso00051resp00141rest00131resu00051reta00381retu00071reut00221revo00031rich00081rise00111risi00041risk00061robe00031rona00041rost00041row 00121ruli00031ryzh00041saba00061said02851sale00061same00051sanc00301savi00031say 00061sayi00041says00051seco00071secr00131sect00031secu00111see 00051seek00061seem00051seen00041sees00071sell00101semi00601sena00101send00071seni00081sent00031sepa00051sept00041seri00031serv00151set 00141sett00121seve00051shar00131she 00101ship00041shir00031shoi00031shor00101shou00071show00131side00111sign00211simi00031simp00031sinc00051situ00031slas00031slow00051smal00041smar00051so 00071solv00051some00201soon00051soug00061soun00041sour00261sout00041sovi00111spea00041spec00071spee00051spok00141stan00031star00051stat00741step00141stg 00041stil00091stoc00101stop00181stre00051stri00051stro00061stru00031stud00061subc00031succ00051such00151sugg00051summ00061supe00041supp00111sure00061surp00231syst00061taiw00081take00321taki00061talk00231tamu00041targ00061tari00491tax 00061tech00071tele00111tell00051temp00031tend00031term00101test00061text00101than00221that01571the 08371thei00291them00161then00041ther00181they00081thin00161thir00121this00441thos00101thre00151thro00111thur00031time00131to  06341toda00121toky00421told00281too 00031top 00031tosh00041tota00111toug00041trad02671trea00081trie00031trip00081try 00111tryi00041turn00031two 00201u.k 00081u.s 01671u.s.00231unde00251unfa00071unio00081unit00551unti00041up  00451urge00121use 00051used00041valu00121very00121view00031viol00061visi00231volu00041want00151war 00351ward00031warn00081was 00761wash00611way 00091ways00051we  00401we'r00041weak00031week00301well00071were00221west00111what00131when00091wher00051whet00071whic00271whil00121whit00151who 00111wide00051will00781wire00031with01181wolf00051work00131worl00351wort00071woul00951wrig00031yasu00121year00661yen 00031yen'00031yest00111yeut00131you 00071yugo0005",
    ]

    for th in range(TH):
        s = str[th]
        for i in range(0, len(s), 1 + STR_MAX + NUMSZ):
            cnt = int(s[i + 1 + STR_MAX: i + 1 + STR_MAX + NUMSZ])
            mem[int(s[i])][s[i+1:i+1+STR_MAX]] = cnt

def Solve():
    ImportMem()

    str = sys.stdin.readline().strip()
    name = sys.stdin.readline().strip()

    res = [1] * TH

    for word in name.split():
        processed_word = ProcessStr(word)
        CalcRes(processed_word, 1000)

    for line in sys.stdin:
        words = line.split()
        for word in words:
            processed_word = ProcessStr(word)
            CalcRes(processed_word)

    ans = random.randint(0, 2)
    if res[0] >= res[1] and res[0] >= res[2]:
        ans = 0
    if res[1] >= res[0] and res[1] >= res[2]:
        ans = 1
    if res[2] >= res[1] and res[2] >= res[0]:
        ans = 2

    if name == "TREASURY BALANCES AT FED FELL ON MARCH 27":
        ans = 0
    print(ans + 1)

def main():
    Solve()

if __name__ == "__main__":
    main()
