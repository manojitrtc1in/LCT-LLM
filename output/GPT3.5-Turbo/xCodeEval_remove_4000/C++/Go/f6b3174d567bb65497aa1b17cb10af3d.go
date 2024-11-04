package main

import (
	"fmt"
)

type pii struct {
	first  int
	second int
}

func main() {
	ma := make(map[string]pii)
	ma["ABU"] = pii{1, 3}
	ma["AIDS"] = pii{3, 4}
	ma["Action"] = pii{3, 6}
	ma["Agreement"] = pii{3, 4}
	ma["Agriculture"] = pii{3, 7}
	ma["American"] = pii{3, 27}
	ma["Arab"] = pii{1, 13}
	ma["Armacost"] = pii{3, 3}
	ma["Assets"] = pii{2, 3}
	ma["Bahrain"] = pii{1, 7}
	ma["Baldrige"] = pii{3, 9}
	ma["Bangemann"] = pii{1, 5}
	ma["Bond"] = pii{1, 3}
	ma["Both"] = pii{3, 3}
	ma["Bouldikian"] = pii{1, 3}
	ma["Brien"] = pii{3, 4}
	ma["Broadly"] = pii{2, 3}
	ma["Byrd"] = pii{3, 5}
	ma["CDs"] = pii{2, 7}
	ma["Cable"] = pii{3, 3}
	ma["Chartered"] = pii{2, 6}
	ma["Chicago"] = pii{2, 3}
	ma["Chirac"] = pii{3, 10}
	ma["Clark"] = pii{3, 3}
	ma["Clayton"] = pii{3, 4}
	ma["Clercq"] = pii{3, 8}
	ma["Commerce"] = pii{3, 5}
	ma["Commission"] = pii{3, 3}
	ma["Conable"] = pii{3, 5}
	ma["Congress"] = pii{3, 20}
	ma["Congressmen"] = pii{3, 5}
	ma["Croo"] = pii{3, 5}
	ma["DHABI"] = pii{1, 3}
	ma["DRAM"] = pii{3, 5}
	ma["Dattel"] = pii{1, 3}
	ma["Dealers"] = pii{1, 11}
	ma["Democrat"] = pii{3, 3}
	ma["Democratic"] = pii{3, 11}
	ma["Department"] = pii{3, 4}
	ma["Deputy"] = pii{3, 3}
	ma["Development"] = pii{3, 3}
	ma["ECGD"] = pii{3, 3}
	ma["EEP"] = pii{3, 7}
	ma["Economic"] = pii{3, 8}
	ma["Edwards"] = pii{3, 5}
	ma["Electric"] = pii{3, 3}
	ma["Electronic"] = pii{3, 3}
	ma["Europe"] = pii{3, 8}
	ma["FECs"] = pii{1, 6}
	ma["FOMC"] = pii{2, 8}
	ma["FSO"] = pii{3, 6}
	ma["Faced"] = pii{3, 3}
	ma["Fitzwater"] = pii{3, 3}
	ma["Fleming"] = pii{3, 3}
	ma["GATT"] = pii{3, 17}
	ma["General"] = pii{3, 5}
	ma["Giordano"] = pii{1, 8}
	ma["Gulf"] = pii{1, 4}
	ma["Heller"] = pii{1, 4}
	ma["Herstatt"] = pii{1, 4}
	ma["Hitachi"] = pii{3, 3}
	ma["Horner"] = pii{1, 5}
	ma["IDB"] = pii{3, 4}
	ma["India"] = pii{3, 10}
	ma["Indian"] = pii{3, 5}
	ma["Industries"] = pii{3, 3}
	ma["Islamic"] = pii{3, 4}
	ma["Jardine"] = pii{3, 3}
	ma["Johnson"] = pii{2, 3}
	ma["July"] = pii{3, 4}
	ma["Kyodo"] = pii{3, 4}
	ma["LDP"] = pii{3, 11}
	ma["Leader"] = pii{3, 3}
	ma["Lebanese"] = pii{1, 5}
	ma["Liberal"] = pii{3, 3}
	ma["Local"] = pii{2, 3}
	ma["London"] = pii{3, 11}
	ma["Lyng"] = pii{3, 3}
	ma["MITI"] = pii{3, 17}
	ma["MMTC"] = pii{3, 3}
	ma["MPs"] = pii{3, 4}
	ma["Malcolm"] = pii{3, 4}
	ma["Margaret"] = pii{3, 3}
	ma["Matsunaga"] = pii{3, 5}
	ma["McCarthy"] = pii{2, 3}
	ma["Melzer"] = pii{2, 3}
	ma["Miller"] = pii{3, 3}
	ma["Most"] = pii{3, 3}
	ma["NEC"] = pii{3, 6}
	ma["Nakasone"] = pii{3, 47}
	ma["Nashashibi"] = pii{1, 3}
	ma["News"] = pii{3, 4}
	ma["Notes"] = pii{2, 3}
	ma["November"] = pii{2, 22}
	ma["OTTAWA"] = pii{2, 4}
	ma["Officials"] = pii{3, 5}
	ma["PHLX"] = pii{1, 10}
	ma["PSL"] = pii{2, 3}
	ma["Partly"] = pii{1, 3}
	ma["Party"] = pii{3, 3}
	ma["Philadelphia"] = pii{1, 4}
	ma["Plaza"] = pii{1, 4}
	ma["Policy"] = pii{3, 8}
	ma["Prime"] = pii{3, 17}
	ma["Representative"] = pii{3, 3}
	ma["Republican"] = pii{3, 7}
	ma["Rich"] = pii{3, 3}
	ma["Richard"] = pii{3, 4}
	ma["Ronald"] = pii{3, 4}
	ma["Rostenkowski"] = pii{3, 3}
	ma["Russell"] = pii{2, 4}
	ma["Ryzhkov"] = pii{3, 4}
	ma["Saba"] = pii{3, 6}
	ma["Savings"] = pii{2, 3}
	ma["Senate"] = pii{3, 9}
	ma["Service"] = pii{3, 3}
	ma["Shiratori"] = pii{3, 3}
	ma["Shoichi"] = pii{3, 3}
	ma["Smart"] = pii{3, 5}
	ma["Stephens"] = pii{3, 5}
	ma["Sumita"] = pii{1, 6}
	ma["Tamura"] = pii{3, 4}
	ma["Tariffs"] = pii{3, 8}
	ma["Thatcher"] = pii{3, 4}
	ma["Their"] = pii{3, 4}
	ma["Third"] = pii{3, 5}
	ma["Though"] = pii{1, 3}
	ma["Tian"] = pii{1, 4}
	ma["Toshiba"] = pii{3, 4}
	ma["Vice"] = pii{1, 5}
	ma["Volcker"] = pii{2, 3}
	ma["Washington"] = pii{3, 38}
	ma["While"] = pii{3, 7}
	ma["White"] = pii{3, 12}
	ma["Willy"] = pii{3, 3}
	ma["Wireless"] = pii{3, 3}
	ma["Wolf"] = pii{3, 5}
	ma["World"] = pii{3, 9}
	ma["Wright"] = pii{3, 3}
	ma["Yasuhiro"] = pii{3, 12}
	ma["Yeutter"] = pii{3, 11}
	ma["abide"] = pii{3, 3}
	ma["able"] = pii{1, 3}
	ma["acceptances"] = pii{2, 10}
	ma["acquisition"] = pii{3, 3}
	ma["act"] = pii{3, 8}
	ma["add"] = pii{1, 4}
	ma["adverse"] = pii{3, 3}
	ma["aggregate"] = pii{2, 4}
	ma["aggregates"] = pii{2, 6}
	ma["agricultural"] = pii{3, 3}
	ma["alleged"] = pii{3, 13}
	ma["amendment"] = pii{3, 3}
	ma["amounts"] = pii{1, 4}
	ma["anger"] = pii{3, 4}
	ma["angry"] = pii{3, 4}
	ma["announcement"] = pii{3, 3}
	ma["annualised"] = pii{2, 5}
	ma["annualized"] = pii{2, 5}
	ma["anti"] = pii{3, 3}
	ma["application"] = pii{3, 5}
	ma["areas"] = pii{3, 5}
	ma["assistance"] = pii{1, 14}
	ma["attempt"] = pii{3, 4}
	ma["auto"] = pii{3, 3}
	ma["averaged"] = pii{2, 4}
	ma["band"] = pii{1, 9}
	ma["bankers"] = pii{1, 5}
	ma["barriers"] = pii{3, 6}
	ma["bearing"] = pii{2, 4}
	ma["bilateral"] = pii{3, 12}
	ma["booked"] = pii{2, 4}
	ma["books"] = pii{2, 5}
	ma["borrowings"] = pii{2, 8}
	ma["bringing"] = pii{2, 3}
	ma["broader"] = pii{2, 3}
	ma["car"] = pii{3, 4}
	ma["carefully"] = pii{1, 4}
	ma["cause"] = pii{3, 3}
	ma["cent"] = pii{3, 3}
	ma["certain"] = pii{3, 5}
	ma["chance"] = pii{3, 5}
	ma["changed"] = pii{2, 3}
	ma["chartered"] = pii{2, 7}
	ma["chequable"] = pii{2, 4}
	ma["chip"] = pii{3, 30}
	ma["chips"] = pii{3, 21}
	ma["circular"] = pii{1, 3}
	ma["claims"] = pii{3, 3}
	ma["closely"] = pii{1, 4}
	ma["coins"] = pii{2, 4}
	ma["come"] = pii{3, 14}
	ma["comment"] = pii{1, 4}
	ma["committed"] = pii{1, 4}
	ma["commodity"] = pii{1, 11}
	ma["common"] = pii{1, 3}
	ma["company"] = pii{3, 7}
	ma["compares"] = pii{1, 5}
	ma["computer"] = pii{3, 16}
	ma["concerned"] = pii{3, 4}
	ma["concerns"] = pii{3, 3}
	ma["conciliatory"] = pii{3, 4}
	ma["confident"] = pii{3, 3}
	ma["considering"] = pii{3, 3}
	ma["consultations"] = pii{3, 4}
	ma["contract"] = pii{1, 4}
	ma["contractionary"] = pii{2, 3}
	ma["contracts"] = pii{1, 5}
	ma["controls"] = pii{1, 8}
	ma["convince"] = pii{3, 5}
	ma["cooperate"] = pii{1, 3}
	ma["counter"] = pii{1, 4}
	ma["countertrade"] = pii{3, 7}
	ma["cross"] = pii{3, 3}
	ma["curbs"] = pii{3, 6}
	ma["currencies"] = pii{1, 24}
	ma["customer"] = pii{1, 3}
	ma["date"] = pii{3, 3}
	ma["deal"] = pii{3, 3}
	ma["dealers"] = pii{1, 16}
	ma["deals"] = pii{3, 4}
	ma["defined"] = pii{2, 9}
	ma["defuse"] = pii{3, 3}
	ma["developed"] = pii{3, 3}
	ma["difficult"] = pii{3, 5}
	ma["dinar"] = pii{1, 3}
	ma["directive"] = pii{2, 3}
	ma["discuss"] = pii{3, 3}
	ma["dispute"] = pii{3, 24}
	ma["doing"] = pii{3, 4}
	ma["dollars"] = pii{1, 8}
	ma["downwards"] = pii{2, 3}
	ma["dumping"] = pii{3, 16}
	ma["duties"] = pii{3, 6}
	ma["eased"] = pii{1, 3}
	ma["efforts"] = pii{3, 7}
	ma["elected"] = pii{1, 3}
	ma["elections"] = pii{3, 3}
	ma["electronic"] = pii{3, 14}
	ma["electronics"] = pii{3, 8}
	ma["emphasis"] = pii{3, 3}
	ma["ensure"] = pii{3, 4}
	ma["estimate"] = pii{1, 7}
	ma["exchequer"] = pii{1, 3}
	ma["excluding"] = pii{2, 6}
	ma["expanding"] = pii{3, 5}
	ma["expectations"] = pii{2, 3}
	ma["export"] = pii{3, 10}
	ma["expressed"] = pii{3, 3}
	ma["extended"] = pii{2, 4}
	ma["fallen"] = pii{1, 3}
	ma["fear"] = pii{3, 3}
	ma["figure"] = pii{2, 5}
	ma["final"] = pii{3, 6}
	ma["fire"] = pii{3, 3}
	ma["float"] = pii{2, 6}
	ma["focus"] = pii{3, 5}
	ma["forced"] = pii{3, 4}
	ma["foster"] = pii{1, 5}
	ma["foundation"] = pii{3, 3}
	ma["friction"] = pii{3, 4}
	ma["fund"] = pii{1, 4}
	ma["futures"] = pii{1, 4}
	ma["gold"] = pii{1, 5}
	ma["goods"] = pii{3, 33}
	ma["group"] = pii{3, 3}
	ma["guilders"] = pii{2, 3}
	ma["hand"] = pii{1, 4}
	ma["hard"] = pii{3, 5}
	ma["hearing"] = pii{3, 5}
	ma["heated"] = pii{3, 4}
	ma["hedging"] = pii{1, 6}
	ma["hope"] = pii{3, 6}
	ma["hoped"] = pii{3, 3}
	ma["house"] = pii{1, 3}
	ma["how"] = pii{3, 3}
	ma["huge"] = pii{3, 8}
	ma["implement"] = pii{3, 3}
	ma["import"] = pii{3, 7}
	ma["important"] = pii{3, 3}
	ma["impose"] = pii{3, 15}
	ma["imposed"] = pii{3, 4}
	ma["imposing"] = pii{3, 3}
	ma["include"] = pii{3, 10}
	ma["index"] = pii{1, 3}
	ma["industrialized"] = pii{1, 3}
	ma["industries"] = pii{3, 4}
	ma["intend"] = pii{1, 3}
	ma["interbank"] = pii{1, 3}
	ma["interests"] = pii{3, 3}
	ma["investigation"] = pii{3, 4}
	ma["irrational"] = pii{3, 3}
	ma["island"] = pii{1, 3}
	ma["issue"] = pii{3, 11}
	ma["join"] = pii{3, 4}
	ma["joint"] = pii{3, 9}
	ma["keep"] = pii{3, 3}
	ma["kind"] = pii{3, 3}
	ma["leaders"] = pii{3, 5}
	ma["legislation"] = pii{3, 8}
	ma["liabilities"] = pii{2, 3}
	ma["licences"] = pii{3, 4}
	ma["list"] = pii{3, 4}
	ma["live"] = pii{3, 10}
	ma["look"] = pii{3, 4}
	ma["loss"] = pii{3, 3}
	ma["makers"] = pii{3, 12}
	ma["manufacturers"] = pii{3, 3}
	ma["maturing"] = pii{1, 3}
	ma["memory"] = pii{3, 4}
	ma["microchip"] = pii{3, 7}
	ma["microchips"] = pii{3, 11}
	ma["minimum"] = pii{1, 3}
	ma["minus"] = pii{2, 3}
	ma["minutes"] = pii{2, 4}
	ma["missiles"] = pii{3, 3}
	ma["morning"] = pii{1, 7}
	ma["moves"] = pii{3, 4}
	ma["narrowly"] = pii{2, 4}
	ma["newly"] = pii{1, 3}
	ma["normally"] = pii{1, 3}
	ma["offers"] = pii{1, 3}
	ma["offsetting"] = pii{1, 3}
	ma["opened"] = pii{3, 4}
	ma["opposition"] = pii{3, 4}
	ma["output"] = pii{3, 8}
	ma["outstanding"] = pii{2, 9}
	ma["package"] = pii{3, 4}
	ma["packages"] = pii{3, 4}
	ma["parliament"] = pii{3, 3}
	ma["parties"] = pii{3, 5}
	ma["parts"] = pii{3, 6}
	ma["passed"] = pii{3, 5}
	ma["per"] = pii{3, 5}
	ma["persuade"] = pii{3, 5}
	ma["pesos"] = pii{2, 9}
	ma["planned"] = pii{3, 4}
	ma["pledged"] = pii{3, 4}
	ma["plus"] = pii{2, 19}
	ma["polled"] = pii{2, 4}
	ma["power"] = pii{3, 4}
	ma["practices"] = pii{3, 6}
	ma["predicted"] = pii{3, 3}
	ma["pressing"] = pii{1, 3}
	ma["products"] = pii{3, 17}
	ma["programme"] = pii{1, 3}
	ma["projections"] = pii{2, 4}
	ma["proposal"] = pii{3, 3}
	ma["propose"] = pii{3, 7}
	ma["provided"] = pii{1, 9}
	ma["provisional"] = pii{2, 22}
	ma["purchased"] = pii{1, 4}
	ma["quickly"] = pii{3, 4}
	ma["ranges"] = pii{1, 3}
	ma["react"] = pii{3, 4}
	ma["ready"] = pii{3, 3}
	ma["recommendation"] = pii{3, 3}
	ma["recommendations"] = pii{3, 5}
	ma["reform"] = pii{3, 3}
	ma["regret"] = pii{3, 3}
	ma["relations"] = pii{3, 3}
	ma["relationship"] = pii{3, 4}
	ma["replied"] = pii{3, 4}
	ma["report"] = pii{3, 10}
	ma["request"] = pii{3, 3}
	ma["resist"] = pii{3, 3}
	ma["resolve"] = pii{3, 4}
	ma["restraint"] = pii{2, 4}
	ma["restrictions"] = pii{3, 3}
	ma["retaliate"] = pii{3, 8}
	ma["retaliation"] = pii{3, 19}
	ma["retaliatory"] = pii{3, 8}
	ma["round"] = pii{1, 4}
	ma["row"] = pii{3, 7}
	ma["ruling"] = pii{3, 3}
	ma["run"] = pii{3, 3}
	ma["sanctions"] = pii{3, 26}
	ma["says"] = pii{1, 7}
	ma["seasonal"] = pii{2, 3}
	ma["secretary"] = pii{3, 3}
	ma["see"] = pii{3, 4}
	ma["sell"] = pii{3, 4}
	ma["semiconductor"] = pii{3, 33}
	ma["semiconductors"] = pii{3, 23}
	ma["send"] = pii{3, 5}
	ma["separate"] = pii{3, 5}
	ma["serious"] = pii{3, 3}
	ma["serve"] = pii{1, 6}
	ma["services"] = pii{3, 9}
	ma["sessions"] = pii{1, 3}
	ma["settle"] = pii{3, 6}
	ma["settlement"] = pii{3, 6}
	ma["she"] = pii{3, 8}
	ma["shipments"] = pii{3, 3}
	ma["sight"] = pii{2, 5}
	ma["signed"] = pii{3, 10}
	ma["significantly"] = pii{3, 3}
	ma["slash"] = pii{3, 3}
	ma["smallest"] = pii{2, 3}
	ma["something"] = pii{3, 4}
	ma["soon"] = pii{3, 5}
	ma["source"] = pii{3, 3}
	ma["specific"] = pii{3, 5}
	ma["speech"] = pii{3, 3}
	ma["spokeswoman"] = pii{3, 3}
	ma["stability"] = pii{1, 6}
	ma["steady"] = pii{2, 3}
	ma["steep"] = pii{1, 3}
	ma["step"] = pii{3, 4}
	ma["steps"] = pii{3, 3}
	ma["stop"] = pii{3, 11}
	ma["stopped"] = pii{3, 5}
	ma["strengthen"] = pii{1, 3}
	ma["studying"] = pii{3, 3}
	ma["success"] = pii{3, 4}
	ma["summer"] = pii{3, 3}
	ma["sure"] = pii{3, 6}
	ma["survey"] = pii{1, 3}
	ma["technology"] = pii{3, 5}
	ma["television"] = pii{3, 3}
	ma["tell"] = pii{3, 3}
	ma["test"] = pii{3, 4}
	ma["textile"] = pii{3, 6}
	ma["textiles"] = pii{3, 3}
	ma["thus"] = pii{2, 3}
	ma["tied"] = pii{1, 3}
	ma["totalled"] = pii{2, 6}
	ma["tough"] = pii{3, 3}
	ma["trader"] = pii{1, 3}
	ma["transactions"] = pii{1, 6}
	ma["tried"] = pii{3, 3}
	ma["trip"] = pii{3, 8}
	ma["try"] = pii{3, 11}
	ma["trying"] = pii{3, 4}
	ma["unadjusted"] = pii{2, 5}
	ma["unchanged"] = pii{2, 6}
	ma["underlying"] = pii{1, 4}
	ma["unfair"] = pii{3, 7}
	ma["urge"] = pii{3, 3}
	ma["violating"] = pii{3, 3}
	ma["visit"] = pii{3, 14}
	ma["volume"] = pii{3, 3}
	ma["voted"] = pii{2, 3}
	ma["ward"] = pii{3, 3}
	ma["warned"] = pii{3, 3}
	ma["warning"] = pii{3, 3}
	ma["weakened"] = pii{3, 3}
	ma["willing"] = pii{3, 4}
	ma["yield"] = pii{1, 3}
	ma["yields"] = pii{1, 3}

	var s string
	a := [4]int{}
	for {
		_, err := fmt.Scan(&s)
		if err != nil {
			break
		}
		if val, ok := ma[s]; ok {
			a[val.first] += val.second
		}
	}
	m := max(max(a[1], a[2]), a[3])
	if a[1] == m {
		fmt.Println(1)
	} else if a[2] == m {
		fmt.Println(2)
	} else {
		fmt.Println(3)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}