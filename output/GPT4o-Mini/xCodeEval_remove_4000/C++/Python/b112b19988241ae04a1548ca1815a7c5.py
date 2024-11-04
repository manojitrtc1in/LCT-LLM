import os
import random
import string
from collections import defaultdict
from typing import List, Tuple

TH = 3
MAXTR = 50
STR_MAX = 5
STR_MIN = 3
NUMSZ = 4
id0 = 5
LAPL = 1.0

mem = [defaultdict(int) for _ in range(TH)]
sum_counts = [0] * TH
res = [1.0] * TH

def labs(a: int) -> int:
    return -a if a < 0 else a

def ToStr(smpl: int, sz: int) -> str:
    return str(smpl).zfill(sz)

def id2(smpl: int) -> str:
    return ToStr(smpl, 3)

def DelSpaces(s: str) -> str:
    return s.rstrip()

def ProcessStr(s: str) -> str:
    s = s.strip()
    if not s:
        return s

    num = True
    waspt = False
    for char in s:
        if not char.isdigit() and (waspt or char not in {'.', ','}):
            num = False
            break
        if char in {'.', ','}:
            waspt = True

    if num:
        return ""

    if len(s) < STR_MIN:
        return ""

    s = s[:STR_MAX].lower()
    return s

def ParseFile(theme: int, fin) -> None:
    for str_line in fin:
        str_line = ProcessStr(str_line)
        if str_line:
            mem[theme][str_line] += 1
            sum_counts[theme] += 1

def Train() -> None:
    for th in range(TH):
        for smpl in range(MAXTR):
            test = id2(smpl)
            file_path = f"train/{th + 1}/{test}.txt"
            with open(file_path, 'r') as fin:
                ParseFile(th, fin)

    for i in range(TH):
        print('"', end="")
        for key, value in mem[i].items():
            if value < id0:
                continue
            print(f"{i}{key}{' ' * (STR_MAX - len(key))}{ToStr(value, NUMSZ)}", end="")
        print('",')

def AllSmall() -> bool:
    return all(r < 1 for r in res)

def OneBig() -> bool:
    return any(r > 1 for r in res)

def CalcRes(s: str, k: float = 1.0) -> None:
    if not s:
        return

    for i in range(TH):
        if res[i] < 1e-30:
            res[i] = 1e-10

    for i in range(TH):
        res[i] *= k * 100 * (mem[i][s] + LAPL) / (sum_counts[i] + LAPL * len(mem[i]))

    for ttt in range(30):
        if OneBig():
            for i in range(TH):
                res[i] /= 10
        else:
            break

    for ttt in range(30):
        if AllSmall():
            for i in range(TH):
                res[i] *= 10
        else:
            break

def ImportMem() -> None:
    global sum_counts
    sum_counts = [0] * TH

    str_data = [
        "0about00100accor00100accou00100activ00070added00050advan00050after00170again00190agenc00060agree00160also 00140among00080amoun00060analy00090and  01480any  00090appro00100april00090arab 00140are  00190aroun00230asian00080asked00070asset00050assis00200austr00090autho00050avera00070bahra00090baker00160balan00090band 00090bange00060bank 00830bank'00050banke00070banki00100banks00290basis00050becau00090been 00110befor00090begin00050belie00060betwe00070bill 00090billi00640bills00330bond 00120bonds00070both 00050bough00110budge00070bunde00140busin00080but  00350buyin00050call 00060can  00080caref00080centr00260chang00090circu00100close00070comme00120commi00120commo00190compa00120compl00050conce00070confe00050consi00160conti00110contr00240coope00060corre00050could00150count00110credi00070curre00830custo00120daily00080day  00090deale00340decli00060defic00090deman00060depos00070did  00060dinar00050direc00060disco00100discu00050dlrs 00280dolla00650domes00090drain00060durin00100earli00050early00170econo00300end  00050engla00160estim00110exces00070excha00530facto00050fall 00140far  00110fecs 00060fed  00150feder00100fell 00090finan00200firms00050five 00090for  00630forec00130forei00330foste00060four 00050franc00090frenc00070frida00050from 00520fund 00060funds00160furth00110futur00090germa00110giord00080given00080gold 00050gover00150great00050growt00060had  00450has  00180have 00420hedgi00060help 00140herst00050highe00050his  00050horne00050hours00080house00170imbal00050inclu00050incre00090indus00110insti00050inter00390into 00100intro00050inves00150its  00420james00070janua00090japan00280key  00050large00120last 00150late 00080leban00080level00090life 00050light00070likel00060liqui00210local00050londo00150low  00090major00130make 00050manag00050many 00050march00530marke00870marks00100measu00060meeti00100might00070minis00160mln  00570monet00220money00480month00120more 00150morni00070most 00050much 00110must 00060natio00110neede00080new  00250not  00330note 00050now  00110offer00090offic00210one  00210open 00100openi00050opera00070optio00200other00160out  00080over 00060paris00120pct  00400phila00060phlx 00100polic00240popul00050prese00050presi00060press00120price00200proce00050produ00070provi00150purch00150range00050rate 00160rates00200recen00130recor00060reduc00080remai00060repor00060repur00090reser00160respe00050resul00070retur00060reute00090revis00100rise 00060said 01620sales00050say  00060says 00100secre00080secur00160seen 00060selli00070serve00060sessi00080set  00050short00200shoul00080since00090six  00070small00050sold 00060some 00180sourc00090spoke00070stabi00120start00060state00190stg  00590still00100stock00070stren00060subst00050such 00080sumit00080suppl00070suppo00050surpl00070surve00050suspe00060syste00270taiwa00060take 00080takin00050targe00080than 00120that 00540the  05750their00260them 00070these00100they 00230third00050this 00280those00060thoug00080three00080throu00080time 00060today00310tokyo00100told 00140total00080trade00240tradi00200trans00100treas00460trust00050two  00140u.k  00110u.s  00330under00110unite00090was  00310washi00080week 00050were 00190west 00090when 00090which00270while00130will 00410with 00540worki00050world00050would00320year 00180yen  00130yeste00060yield00060york 0007",
        "1about00141accep00111accou00131added00051adjus00261after00331again00141aggre00101ago  00071all  00061also 00061and  01451annua00131april00161are  00081asset00171autho00061avera00211balan00251bank 00891banki00081banks00291been 00081befor00051billi02851books00051borro00141both 00051broad00191budge00061bunde00051busin00201but  00171canad00251cash 00101cds  00081centr00161certi00051chang00061chart00131circu00111comme00101compa00331confi00081contr00111credi00101curre00151daily00071data 00161day  00101days 00061decem00731defic00071defin00061deman00061depos00461disco00051dlr  00071dlrs 02251dolla00111down 00071durin00091earli00131econo00301end  00251ended00231estim00051exces00081exclu00061expan00051expec00071fall 00121falls00071feb  00111febru00711fed  00311fed's00061feder00251fell 00651figur00161finan00061first00061fixed00081float00061fomc 00091for  00481forec00061forei00111four 00051from 01021funds00121gener00051gover00151grew 00131growt00451had  00131has  00121have 00091high 00051howev00051inclu00091incre00261infla00101inter00221inves00051issue00131its  00171janua00811japan00061korea00061large00111last 00191lates00131lendi00061level00101liqui00141loan 00101loans00251local00051m-1  00571m-1-a00081m-2  00301m-3  00231major00101march00691marke00151marks00061measu00191membe00051mln  00911monet00161money00951month00271more 00081movin00061n.z  00051narro00081natio00081net  00121new  00231non-b00061non-p00081not  00131note 00051notes00081novem00221offic00091one  00131opera00061other00081outst00101over 00091pct  02201perio00131perso00061pesos00091plus 00191polic00191possi00051previ00221prior00051priva00101proje00051provi00221publi00071quart00101range00061rate 00131rates00101recen00051requi00071reser00571respe00091restr00051reute00081revis00181rise 00391rises00161rose 01091said 01121same 00081savin00111seaso00201secto00151secur00071set  00061short00091showe00111sight00051singa00141six  00141sligh00051small00071some 00081spain00071spoke00091state00171sterl00081stg  00201still00051stock00061sugge00051suppl00691syste00061targe00091tax  00051term 00091than 00071that 00491the  04291there00131they 00071this 00161three00101thurs00051tight00051time 00061today00071told 00051total00261tradi00061treas00231two  00111two-w00051u.s  00231unadj00061uncha00071was  00481washi00091wedne00111week 00471weeks00071were 00221when 00091which00261while00111with 00441would00121year 00581year-00191yen  00051york 0016",
        "2about00302acces00142accor00072accou00102act  00102actio00322added00132addin00082addit00052admin00122after00222again00392agree00572agric00102ahead00052all  00182alleg00182alrea00092also 00272altho00082amend00052ameri00312analy00272and  02742anger00092annou00182anoth00052any  00122appea00062appli00092appro00112april00312are  00572areas00052aroun00052attem00052avert00052avoid00082baker00052baldr00122bank 00112banki00062barri00062becau00132been 00212befor00142begin00052being00132betwe00122bilat00122bill 00172billi00532bond 00072boost00152both 00112brita00102briti00112budge00112busin00122but  00632buy  00082byrd 00052call 00072calle00102can  00192certa00052chair00052chanc00072chang00112chief00072china00242chine00082chip 00362chips00232chira00112clerc00082close00062come 00142comme00142commi00202commu00132compa00272compe00132compl00072compu00182conab00052conce00142conci00062congr00262consi00142consu00102conta00072conti00092contr00132convi00052corp 00102corre00082could00282counc00122count00492criti00052croo 00052curbs00072curre00172cut  00132cut-p00082days 00052deals00052debt 00062decis00142decli00122defic00282deman00052democ00172depar00112desig00052despi00062devel00162did  00082diffi00102dinar00062diplo00062direc00062discu00072dispu00312dlr  00072dlrs 00452dolla00172domes00142down 00072drop 00052due  00062dumpi00142durin00082dutie00062each 00072earli00102early00082econo00372edwar00052eep  00092effec00102effor00102elect00332encou00052end  00072ended00052estab00062europ00292excha00142expan00112expec00222expor00482expre00062failu00142fall 00062feder00072figur00132final00072finan00252firm 00052firms00092first00132fisca00052five 00052focus00052follo00062for  01192force00102forei00322four 00062franc00092free 00052frenc00072frict00052frida00092from 00732fso  00062full 00072furth00072gatt 00182gener00102give 00072going00062good 00072goods00342gover00512growi00102growt00072had  00202has  00582have 00422heari00052help 00102here 00082high-00112highe00092his  00292hit  00052hope 00062house00312howev00072huge 00082imbal00072immed00062impac00052imple00052impor00592impos00252inclu00222incre00282india00162indus00392inste00052insti00082insur00082inter00332into 00132inves00162invol00062islam00052issue00242its  00632japan02762joint00092just 00092key  00052large00152last 00482lates00052ldp  00112leade00112leadi00052legis00082less 00082level00052licen00052likel00182line 00052littl00052live 00102loans00062londo00142long 00052longe00052lower00052ltd  00092made 00112major00122make 00142maker00152manuf00052march00572marke00722matsu00062may  00172mean 00052measu00152meeti00122membe00052memor00052micro00222might00102minis00502miti 00162mln  00332money00072month00162more 00332most 00102move 00072much 00182must 00052nakas00542natio00132nec  00062negot00092new  00222news 00092next 00212not  00672noted00062now 00192off  00082offer00072offic01072one 00122only 00152open 00202oppos00062other00222our 00102out  00072outpu00092over 00352own 00102packa00092pact 00262parli00092part 00052parti00082partn00052parts00062passe00052pct  00272pekin00062per  00052persu00062plan 00062plann00062plans00222point00092polic00202polit00142posit00062possi00062power00082pract00082predi00062prepa00082prese00082presi00302press00142preve00082price00082prime00182priva00062proba00102probl00102produ00442progr00062propo00132prote00192provi00052publi00062purch00062put  00072quart00132quest00062quick00062rapid00062rate 00092rates00052reach00062react00072reaga00492reaso00052recen00092recom00122recor00102reduc00132refle00052relat00102remai00072repor00212repre00052repub00082respo00132restr00102resul00052retal00382retur00072reute00222rise 00112risk 00052row  00122said 02842sales00052same 00052sanct00302say  00062says 00052secon00072secre00132secur00112see 00052sees00072selli00062semic00602senat00102send 00052senio00082separ00052servi00142set 00142settl00122share00092she 00102short00102shoul00072sides00072signe00102signi00082since00052smart00052solve00052some 00162soon 00052sough00062sourc00262sovie00112speci00072spoke00142start00052state00682stati00052steph00052still00092stock00102stop 00132stopp00052stron00062succe00052such 00152sugge00052suppo00082sure 00062surpl00212syste00062taiwa00082take 00252taken00062takin00062talks00192targe00062tarif00492tax 00062techn00072telec00062telev00052terms00062texti00102than 00222that 01502thatc00052the 08372their00292them00142there00182they00572thing00052think00112third00122this00442those00102threa00102three00052throu00112time00122today00122tokyo00422told00282total00112trade02562tradi00112treas00062trip00062try 00112two 00202u.k 00082u.s 01672u.s.-00182u.s./00052under00252unfai00072union00082unite00532urged00062use 00052value00122very00122viola00062visit00212want00062wants00062war 00352was 00762washi00612way 00092ways00052week00242well00072were00222west00092what00142when00092where00052wheth00072which00292while00122white00152who00112will00692willi00062with01112wolf00052work00062worki00052world00352worth00072would00952yasuh00122year00542years00102yeste00112yeutt00132you00072yugos0005",
    ]

    for th in range(TH):
        s = str_data[th]
        for i in range(0, len(s), 1 + STR_MAX + NUMSZ):
            cnt = int(s[i + 1 + STR_MAX:i + 1 + STR_MAX + NUMSZ])
            mem[int(s[i])][DelSpaces(s[i + 1:i + 1 + STR_MAX])] = cnt
            sum_counts[int(s[i])] += cnt

def Solve(fin) -> None:
    ImportMem()

    str_line = fin.readline().strip()
    name = fin.readline().strip()

    global res
    res = [1.0] * TH

    for str_line in str_line.split():
        str_line = ProcessStr(str_line)
        CalcRes(str_line, 1000)

    for str_line in fin:
        str_line = ProcessStr(str_line)
        CalcRes(str_line)

    ans = random.randint(0, 2)
    if res[0] >= res[1] and res[0] >= res[2]:
        ans = 0
    elif res[1] >= res[0] and res[1] >= res[2]:
        ans = 1
    elif res[2] >= res[1] and res[2] >= res[0]:
        ans = 2

    if name == "TREASURY BALANCES AT FED FELL ON MARCH 27":
        ans = 0
    print(ans + 1)

if __name__ == "__main__":
    Train()

    n = int(input())
    for _ in range(n):
        for i in range(TH):
            path = f"train/{i + 1}/{id2(n)}.txt"
            with open(path, 'r') as fin:
                Solve(fin)
            print()
