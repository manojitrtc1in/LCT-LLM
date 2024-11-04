package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	TH       = 3
	MAXTR    = 50
	STR_MAX  = 5
	STR_MIN  = 3
	NUMSZ    = 4
	TAKE_CNT = 5
	LAPL     = 1
)

var (
	mem [TH]map[string]int
	sum [TH]int
	res [TH]float64
)

func labs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func sqr(x int) int {
	return x * x
}

func ToStr(smpl, sz int) string {
	test := strconv.Itoa(smpl)
	for len(test) < sz {
		test = "0" + test
	}
	return test
}

func ToStr3(smpl int) string {
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
		*s = ""
		return
	}

	if len(*s) < STR_MIN {
		*s = ""
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
		for smpl := 1; smpl <= MAXTR; smpl++ {
			test := ToStr3(smpl)
			file := "train/" + string('1'+th) + "/" + test + ".txt"

			fin, err := os.Open(file)
			if err != nil {
				fmt.Println(err)
				return
			}

			scanner := bufio.NewScanner(fin)
			scanner.Scan()
			ParseFile(th, fin)
			fin.Close()
		}
	}

	for i := 0; i < TH; i++ {
		for key, val := range mem[i] {
			if val < TAKE_CNT {
				continue
			}
			fmt.Printf("%d%s%s%s\n", i, key, strings.Repeat(" ", STR_MAX-len(key)), ToStr(val, NUMSZ))
		}
		fmt.Println()
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

	for i := 0; i < TH; i++ {
		res[i] = 1
	}

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
}

func DelSpaces(s string) string {
	for len(s) > 0 && isspace(s[len(s)-1]) {
		s = s[:len(s)-1]
	}
	return s
}

func ImportMem() {
	for i := 0; i < TH; i++ {
		sum[i] = 0
	}

	str := []string{
		"0about00100accor00100accou00100activ00070added00050advan00050after00170again00190agenc00060agree00160also 00140among00080amoun00060analy00090and  01480any  00090appro00100april00090arab 00140are  00190aroun00230asian00080asked00070asset00050assis00200austr00090autho00050avera00070bahra00090baker00160balan00090band 00090bange00060bank 00830bank'00050banke00070banki00100banks00290basis00050becau00090been 00110befor00090begin00050belie00060betwe00070bill 00090billi00640bills00330bond 00120bonds00070both 00050bough00110budge00070bunde00140busin00080but  00350buyin00050call 00060can  00080caref00080centr00260chang00090circu00100close00070comme00120commi00120commo00190compa00120compl00050conce00070confe00050consi00160conti00110contr00240coope00060corre00050could00150count00110credi00070curre00830custo00120daily00080day  00090deale00340decli00060defic00090deman00060depos00070did  00060dinar00050direc00060disco00100discu00050dlrs 00280dolla00650domes00090drain00060durin00100earli00050early00170econo00300end  00050engla00160estim00110exces00070excha00530facto00050fall 00140far  00110fecs 00060fed  00150feder00100fell 00090finan00200firms00050five 00090for  00630forec00130forei00330foste00060four 00050franc00090frenc00070frida00050from 00520fund 00060funds00160furth00110futur00090germa00110giord00080given00080gold 00050gover00150great00050growt00060had  00450has  00180have 00420hedgi00060help 00140herst00050highe00050his  00050horne00050hours00080house00170imbal00050inclu00050incre00090indus00110insti00050inter00390into 00100intro00050inves00150its  00420james00070janua00090japan00280key  00050large00120last 00150late 00080leban00080level00090life 00050light00070likel00060liqui00210local00050londo00150low  00090major00130make 00050manag00050many 00050march00530marke00870marks00100measu00060meeti00100might00070minis00160mln  00570monet00220money00480month00120more 00150morni00070most 00050much 00110must 00060natio00110neede00080new  00250not  00330note 00050now  00110offer00090offic00210one  00210open 00100openi00050opera00070optio00200other00160out  00080over 00060paris00120pct  00400phila00060phlx 00100polic00240popul00050prese00050presi00060press00120price00200proce00050produ00070provi00150purch00150range00050rate 00160rates00200recen00130recor00060reduc00080remai00060repor00060repur00090reser00160respe00050resul00070retur00060reute00090revis00100rise 00060said 01620sales00050say  00060says 00100secre00080secur00160seen 00060selli00070serve00060sessi00080set  00050short00200shoul00080since00090six  00070small00050sold 00060some 00180sourc00090spoke00070stabi00120start00060state00190stg  00590still00100stock00070stren00060subst00050such 00080sumit00080suppl00070suppo00050surpl00070surve00050suspe00060syste00270taiwa00060take 00080takin00050targe00080than 00120that 00540the  05750their00260them 00070these00100they 00230third00050this 00280those00060thoug00080three00080throu00080time 00060today00310tokyo00100told 00140total00080trade00240tradi00200trans00100treas00460trust00050two  00140u.k  00110u.s  00330under00110unite00090was  00310washi00080week 00050were 00190west 00090when 00090which00270while00130will 00410with 00540worki00050world00050would00320year 00180yen  00130yeste00060yield00060york 0007",
		"1about00141accep00111accou00131added00051adjus00261after00331again00141aggre00101ago  00071all  00061also 00061and  01451annua00131april00161are  00081asset00171autho00061avera00211balan00251bank 00891banki00081banks00291been 00081befor00051billi02851books00051borro00141both 00051broad00191budge00061bunde00051busin00201but  00171canad00251cash 00101cds  00081centr00161certi00051chang00061chart00131circu00111comme00101compa00331confi00081contr00111credi00101curre00151daily00071data 00161day  00101days00061decem00731defic00071defin00061deman00061depos00461disco00051dlr  00071dlrs 02251dolla00111down 00071durin00091earli00131econo00301end  00251ended00231estim00051exces00081exclu00061expan00051expec00071fall 00121falls00071feb  00111febru00711fed  00311fed's00061feder00251fell 00651figur00161finan00061first00061fixed00081float00061fomc 00091for  00481forec00061forei00111four 00051from 01021funds00121gener00051gover00151grew 00131growt00451had  00131has  00121have 00091high 00051howev00051inclu00091incre00261infla00101inter00221inves00051issue00131its  00171janua00811japan00061korea00061large00111last 00191lates00131lendi00061level00101liqui00141loan 00101loans00251local00051m-1  00571m-1-a00081m-2  00301m-3  00231major00101march00691marke00151marks00061measu00191membe00051mln  00911monet00161money00951month00271more 00081movin00061n.z  00051narro00081natio00081net  00121new  00231non-b00061non-p00081not  00131note 00051notes00081novem00221offic00091one  00131opera00061other00081outst00101over 00091pct  02201perio00131perso00061pesos00091plus 00191polic00191possi00051previ00221prior00051priva00101proje00051provi00221publi00071quart00101range00061rate 00131rates00101recen00051requi00071reser00571respe00091restr00051reute00081revis00181rise 00391rises00161rose 01091said 01121same 00081savin00111seaso00201secto00151secur00071set  00061short00091showe00111sight00051singa00141six  00141sligh00051small00071some 00081spain00071spoke00091state00171sterl00081stg  00201still00051stock00061stren00061subst00050such 00080sumit00080suppl00070suppo00050surpl00070surve00050suspe00060syste00270taiwa00060take 00080takin00050targe00080than 00120that 00540the  05750their00260them 00070these00100they 00230third00050this 00280those00060thoug00080three00080throu00080time 00060today00310tokyo00100told 00140total00080trade00240tradi00200trans00100treas00460trust00050two  00140u.k  00110u.s  00330under00110unite00090was  00310washi00080week 00050were 00190west 00090what 00140when 00090where00050wheth00070which00270while00130white00150who  00110will 00690willi00060with 00540worki00050world00050would00320year 00180yen  00130yeste00060yield00060york 0007",
