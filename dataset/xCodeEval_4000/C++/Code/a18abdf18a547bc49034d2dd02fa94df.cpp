#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <time.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define Y1 y1
map<string, pii> ma;
int main() {
  ma["ABU"] = mp(1, 3);
  ma["AIDS"] = mp(3, 4);
  ma["Action"] = mp(3, 6);
  ma["Agreement"] = mp(3, 4);
  ma["Agriculture"] = mp(3, 7);
  ma["American"] = mp(3, 27);
  ma["Arab"] = mp(1, 13);
  ma["Armacost"] = mp(3, 3);
  ma["Assets"] = mp(2, 3);
  ma["Bahrain"] = mp(1, 7);
  ma["Baldrige"] = mp(3, 9);
  ma["Bangemann"] = mp(1, 5);
  ma["Bond"] = mp(1, 3);
  ma["Both"] = mp(3, 3);
  ma["Bouldikian"] = mp(1, 3);
  ma["Brien"] = mp(3, 4);
  ma["Broadly"] = mp(2, 3);
  ma["Byrd"] = mp(3, 5);
  ma["CDs"] = mp(2, 7);
  ma["Cable"] = mp(3, 3);
  ma["Chartered"] = mp(2, 6);
  ma["Chicago"] = mp(2, 3);
  ma["Chirac"] = mp(3, 10);
  ma["Clark"] = mp(3, 3);
  ma["Clayton"] = mp(3, 4);
  ma["Clercq"] = mp(3, 8);
  ma["Commerce"] = mp(3, 5);
  ma["Commission"] = mp(3, 3);
  ma["Conable"] = mp(3, 5);
  ma["Congress"] = mp(3, 20);
  ma["Congressmen"] = mp(3, 5);
  ma["Croo"] = mp(3, 5);
  ma["DHABI"] = mp(1, 3);
  ma["DRAM"] = mp(3, 5);
  ma["Dattel"] = mp(1, 3);
  ma["Dealers"] = mp(1, 11);
  ma["Democrat"] = mp(3, 3);
  ma["Democratic"] = mp(3, 11);
  ma["Department"] = mp(3, 4);
  ma["Deputy"] = mp(3, 3);
  ma["Development"] = mp(3, 3);
  ma["ECGD"] = mp(3, 3);
  ma["EEP"] = mp(3, 7);
  ma["Economic"] = mp(3, 8);
  ma["Edwards"] = mp(3, 5);
  ma["Electric"] = mp(3, 3);
  ma["Electronic"] = mp(3, 3);
  ma["Europe"] = mp(3, 8);
  ma["FECs"] = mp(1, 6);
  ma["FOMC"] = mp(2, 8);
  ma["FSO"] = mp(3, 6);
  ma["Faced"] = mp(3, 3);
  ma["Fitzwater"] = mp(3, 3);
  ma["Fleming"] = mp(3, 3);
  ma["GATT"] = mp(3, 17);
  ma["General"] = mp(3, 5);
  ma["Giordano"] = mp(1, 8);
  ma["Gulf"] = mp(1, 4);
  ma["Heller"] = mp(1, 4);
  ma["Herstatt"] = mp(1, 4);
  ma["Hitachi"] = mp(3, 3);
  ma["Horner"] = mp(1, 5);
  ma["IDB"] = mp(3, 4);
  ma["India"] = mp(3, 10);
  ma["Indian"] = mp(3, 5);
  ma["Industries"] = mp(3, 3);
  ma["Islamic"] = mp(3, 4);
  ma["Jardine"] = mp(3, 3);
  ma["Johnson"] = mp(2, 3);
  ma["July"] = mp(3, 4);
  ma["Kyodo"] = mp(3, 4);
  ma["LDP"] = mp(3, 11);
  ma["Leader"] = mp(3, 3);
  ma["Lebanese"] = mp(1, 5);
  ma["Liberal"] = mp(3, 3);
  ma["Local"] = mp(2, 3);
  ma["London"] = mp(3, 11);
  ma["Lyng"] = mp(3, 3);
  ma["MITI"] = mp(3, 17);
  ma["MMTC"] = mp(3, 3);
  ma["MPs"] = mp(3, 4);
  ma["Malcolm"] = mp(3, 4);
  ma["Margaret"] = mp(3, 3);
  ma["Matsunaga"] = mp(3, 5);
  ma["McCarthy"] = mp(2, 3);
  ma["Melzer"] = mp(2, 3);
  ma["Miller"] = mp(3, 3);
  ma["Most"] = mp(3, 3);
  ma["NEC"] = mp(3, 6);
  ma["Nakasone"] = mp(3, 47);
  ma["Nashashibi"] = mp(1, 3);
  ma["News"] = mp(3, 4);
  ma["Notes"] = mp(2, 3);
  ma["November"] = mp(2, 22);
  ma["OTTAWA"] = mp(2, 4);
  ma["Officials"] = mp(3, 5);
  ma["PHLX"] = mp(1, 10);
  ma["PSL"] = mp(2, 3);
  ma["Partly"] = mp(1, 3);
  ma["Party"] = mp(3, 3);
  ma["Philadelphia"] = mp(1, 4);
  ma["Plaza"] = mp(1, 4);
  ma["Policy"] = mp(3, 8);
  ma["Prime"] = mp(3, 17);
  ma["Representative"] = mp(3, 3);
  ma["Republican"] = mp(3, 7);
  ma["Rich"] = mp(3, 3);
  ma["Richard"] = mp(3, 4);
  ma["Ronald"] = mp(3, 4);
  ma["Rostenkowski"] = mp(3, 3);
  ma["Russell"] = mp(2, 4);
  ma["Ryzhkov"] = mp(3, 4);
  ma["Saba"] = mp(3, 6);
  ma["Savings"] = mp(2, 3);
  ma["Senate"] = mp(3, 9);
  ma["Service"] = mp(3, 3);
  ma["Shiratori"] = mp(3, 3);
  ma["Shoichi"] = mp(3, 3);
  ma["Smart"] = mp(3, 5);
  ma["Stephens"] = mp(3, 5);
  ma["Sumita"] = mp(1, 6);
  ma["Tamura"] = mp(3, 4);
  ma["Tariffs"] = mp(3, 8);
  ma["Thatcher"] = mp(3, 4);
  ma["Their"] = mp(3, 4);
  ma["Third"] = mp(3, 5);
  ma["Though"] = mp(1, 3);
  ma["Tian"] = mp(1, 4);
  ma["Toshiba"] = mp(3, 4);
  ma["Vice"] = mp(1, 5);
  ma["Volcker"] = mp(2, 3);
  ma["Washington"] = mp(3, 38);
  ma["While"] = mp(3, 7);
  ma["White"] = mp(3, 12);
  ma["Willy"] = mp(3, 3);
  ma["Wireless"] = mp(3, 3);
  ma["Wolf"] = mp(3, 5);
  ma["World"] = mp(3, 9);
  ma["Wright"] = mp(3, 3);
  ma["Yasuhiro"] = mp(3, 12);
  ma["Yeutter"] = mp(3, 11);
  ma["abide"] = mp(3, 3);
  ma["able"] = mp(1, 3);
  ma["acceptances"] = mp(2, 10);
  ma["acquisition"] = mp(3, 3);
  ma["act"] = mp(3, 8);
  ma["add"] = mp(1, 4);
  ma["adverse"] = mp(3, 3);
  ma["aggregate"] = mp(2, 4);
  ma["aggregates"] = mp(2, 6);
  ma["agricultural"] = mp(3, 3);
  ma["alleged"] = mp(3, 13);
  ma["amendment"] = mp(3, 3);
  ma["amounts"] = mp(1, 4);
  ma["anger"] = mp(3, 4);
  ma["angry"] = mp(3, 4);
  ma["announcement"] = mp(3, 3);
  ma["annualised"] = mp(2, 5);
  ma["annualized"] = mp(2, 5);
  ma["anti"] = mp(3, 3);
  ma["application"] = mp(3, 5);
  ma["areas"] = mp(3, 5);
  ma["assistance"] = mp(1, 14);
  ma["attempt"] = mp(3, 4);
  ma["auto"] = mp(3, 3);
  ma["averaged"] = mp(2, 4);
  ma["band"] = mp(1, 9);
  ma["bankers"] = mp(1, 5);
  ma["barriers"] = mp(3, 6);
  ma["bearing"] = mp(2, 4);
  ma["bilateral"] = mp(3, 12);
  ma["booked"] = mp(2, 4);
  ma["books"] = mp(2, 5);
  ma["borrowings"] = mp(2, 8);
  ma["bringing"] = mp(2, 3);
  ma["broader"] = mp(2, 3);
  ma["car"] = mp(3, 4);
  ma["carefully"] = mp(1, 4);
  ma["cause"] = mp(3, 3);
  ma["cent"] = mp(3, 3);
  ma["certain"] = mp(3, 5);
  ma["chance"] = mp(3, 5);
  ma["changed"] = mp(2, 3);
  ma["chartered"] = mp(2, 7);
  ma["chequable"] = mp(2, 4);
  ma["chip"] = mp(3, 30);
  ma["chips"] = mp(3, 21);
  ma["circular"] = mp(1, 3);
  ma["claims"] = mp(3, 3);
  ma["closely"] = mp(1, 4);
  ma["coins"] = mp(2, 4);
  ma["come"] = mp(3, 14);
  ma["comment"] = mp(1, 4);
  ma["committed"] = mp(1, 4);
  ma["commodity"] = mp(1, 11);
  ma["common"] = mp(1, 3);
  ma["company"] = mp(3, 7);
  ma["compares"] = mp(1, 5);
  ma["computer"] = mp(3, 16);
  ma["concerned"] = mp(3, 4);
  ma["concerns"] = mp(3, 3);
  ma["conciliatory"] = mp(3, 4);
  ma["confident"] = mp(3, 3);
  ma["considering"] = mp(3, 3);
  ma["consultations"] = mp(3, 4);
  ma["contract"] = mp(1, 4);
  ma["contractionary"] = mp(2, 3);
  ma["contracts"] = mp(1, 5);
  ma["controls"] = mp(1, 8);
  ma["convince"] = mp(3, 5);
  ma["cooperate"] = mp(1, 3);
  ma["counter"] = mp(1, 4);
  ma["countertrade"] = mp(3, 7);
  ma["cross"] = mp(3, 3);
  ma["curbs"] = mp(3, 6);
  ma["currencies"] = mp(1, 24);
  ma["customer"] = mp(1, 3);
  ma["date"] = mp(3, 3);
  ma["deal"] = mp(3, 3);
  ma["dealers"] = mp(1, 16);
  ma["deals"] = mp(3, 4);
  ma["defined"] = mp(2, 9);
  ma["defuse"] = mp(3, 3);
  ma["developed"] = mp(3, 3);
  ma["difficult"] = mp(3, 5);
  ma["dinar"] = mp(1, 3);
  ma["directive"] = mp(2, 3);
  ma["discuss"] = mp(3, 3);
  ma["dispute"] = mp(3, 24);
  ma["doing"] = mp(3, 4);
  ma["dollars"] = mp(1, 8);
  ma["downwards"] = mp(2, 3);
  ma["dumping"] = mp(3, 16);
  ma["duties"] = mp(3, 6);
  ma["eased"] = mp(1, 3);
  ma["efforts"] = mp(3, 7);
  ma["elected"] = mp(1, 3);
  ma["elections"] = mp(3, 3);
  ma["electronic"] = mp(3, 14);
  ma["electronics"] = mp(3, 8);
  ma["emphasis"] = mp(3, 3);
  ma["ensure"] = mp(3, 4);
  ma["estimate"] = mp(1, 7);
  ma["exchequer"] = mp(1, 3);
  ma["excluding"] = mp(2, 6);
  ma["expanding"] = mp(3, 5);
  ma["expectations"] = mp(2, 3);
  ma["export"] = mp(3, 10);
  ma["expressed"] = mp(3, 3);
  ma["extended"] = mp(2, 4);
  ma["fallen"] = mp(1, 3);
  ma["fear"] = mp(3, 3);
  ma["figure"] = mp(2, 5);
  ma["final"] = mp(3, 6);
  ma["fire"] = mp(3, 3);
  ma["float"] = mp(2, 6);
  ma["focus"] = mp(3, 5);
  ma["forced"] = mp(3, 4);
  ma["foster"] = mp(1, 5);
  ma["foundation"] = mp(3, 3);
  ma["friction"] = mp(3, 4);
  ma["fund"] = mp(1, 4);
  ma["futures"] = mp(1, 4);
  ma["gold"] = mp(1, 5);
  ma["goods"] = mp(3, 33);
  ma["group"] = mp(3, 3);
  ma["guilders"] = mp(2, 3);
  ma["hand"] = mp(1, 4);
  ma["hard"] = mp(3, 5);
  ma["hearing"] = mp(3, 5);
  ma["heated"] = mp(3, 4);
  ma["hedging"] = mp(1, 6);
  ma["hope"] = mp(3, 6);
  ma["hoped"] = mp(3, 3);
  ma["house"] = mp(1, 3);
  ma["how"] = mp(3, 3);
  ma["huge"] = mp(3, 8);
  ma["implement"] = mp(3, 3);
  ma["import"] = mp(3, 7);
  ma["important"] = mp(3, 3);
  ma["impose"] = mp(3, 15);
  ma["imposed"] = mp(3, 4);
  ma["imposing"] = mp(3, 3);
  ma["include"] = mp(3, 10);
  ma["index"] = mp(1, 3);
  ma["industrialized"] = mp(1, 3);
  ma["industries"] = mp(3, 4);
  ma["intend"] = mp(1, 3);
  ma["interbank"] = mp(1, 3);
  ma["interests"] = mp(3, 3);
  ma["investigation"] = mp(3, 4);
  ma["irrational"] = mp(3, 3);
  ma["island"] = mp(1, 3);
  ma["issue"] = mp(3, 11);
  ma["join"] = mp(3, 4);
  ma["joint"] = mp(3, 9);
  ma["keep"] = mp(3, 3);
  ma["kind"] = mp(3, 3);
  ma["leaders"] = mp(3, 5);
  ma["legislation"] = mp(3, 8);
  ma["liabilities"] = mp(2, 3);
  ma["licences"] = mp(3, 4);
  ma["list"] = mp(3, 4);
  ma["live"] = mp(3, 10);
  ma["look"] = mp(3, 4);
  ma["loss"] = mp(3, 3);
  ma["makers"] = mp(3, 12);
  ma["manufacturers"] = mp(3, 3);
  ma["maturing"] = mp(1, 3);
  ma["memory"] = mp(3, 4);
  ma["microchip"] = mp(3, 7);
  ma["microchips"] = mp(3, 11);
  ma["minimum"] = mp(1, 3);
  ma["minus"] = mp(2, 3);
  ma["minutes"] = mp(2, 4);
  ma["missiles"] = mp(3, 3);
  ma["morning"] = mp(1, 7);
  ma["moves"] = mp(3, 4);
  ma["narrowly"] = mp(2, 4);
  ma["newly"] = mp(1, 3);
  ma["normally"] = mp(1, 3);
  ma["offers"] = mp(1, 3);
  ma["offsetting"] = mp(1, 3);
  ma["opened"] = mp(3, 4);
  ma["opposition"] = mp(3, 4);
  ma["output"] = mp(3, 8);
  ma["outstanding"] = mp(2, 9);
  ma["package"] = mp(3, 4);
  ma["packages"] = mp(3, 4);
  ma["parliament"] = mp(3, 3);
  ma["parties"] = mp(3, 5);
  ma["parts"] = mp(3, 6);
  ma["passed"] = mp(3, 5);
  ma["per"] = mp(3, 5);
  ma["persuade"] = mp(3, 5);
  ma["pesos"] = mp(2, 9);
  ma["planned"] = mp(3, 4);
  ma["pledged"] = mp(3, 4);
  ma["plus"] = mp(2, 19);
  ma["polled"] = mp(2, 4);
  ma["power"] = mp(3, 4);
  ma["practices"] = mp(3, 6);
  ma["predicted"] = mp(3, 3);
  ma["pressing"] = mp(1, 3);
  ma["products"] = mp(3, 17);
  ma["programme"] = mp(1, 3);
  ma["projections"] = mp(2, 4);
  ma["proposal"] = mp(3, 3);
  ma["propose"] = mp(3, 7);
  ma["provided"] = mp(1, 9);
  ma["provisional"] = mp(2, 22);
  ma["purchased"] = mp(1, 4);
  ma["quickly"] = mp(3, 4);
  ma["ranges"] = mp(1, 3);
  ma["react"] = mp(3, 4);
  ma["ready"] = mp(3, 3);
  ma["recommendation"] = mp(3, 3);
  ma["recommendations"] = mp(3, 5);
  ma["reform"] = mp(3, 3);
  ma["regret"] = mp(3, 3);
  ma["relations"] = mp(3, 3);
  ma["relationship"] = mp(3, 4);
  ma["replied"] = mp(3, 4);
  ma["report"] = mp(3, 10);
  ma["request"] = mp(3, 3);
  ma["resist"] = mp(3, 3);
  ma["resolve"] = mp(3, 4);
  ma["restraint"] = mp(2, 4);
  ma["restrictions"] = mp(3, 3);
  ma["retaliate"] = mp(3, 8);
  ma["retaliation"] = mp(3, 19);
  ma["retaliatory"] = mp(3, 8);
  ma["round"] = mp(1, 4);
  ma["row"] = mp(3, 7);
  ma["ruling"] = mp(3, 3);
  ma["run"] = mp(3, 3);
  ma["sanctions"] = mp(3, 26);
  ma["says"] = mp(1, 7);
  ma["seasonal"] = mp(2, 3);
  ma["secretary"] = mp(3, 3);
  ma["see"] = mp(3, 4);
  ma["sell"] = mp(3, 4);
  ma["semiconductor"] = mp(3, 33);
  ma["semiconductors"] = mp(3, 23);
  ma["send"] = mp(3, 5);
  ma["separate"] = mp(3, 5);
  ma["serious"] = mp(3, 3);
  ma["serve"] = mp(1, 6);
  ma["services"] = mp(3, 9);
  ma["sessions"] = mp(1, 3);
  ma["settle"] = mp(3, 6);
  ma["settlement"] = mp(3, 6);
  ma["she"] = mp(3, 8);
  ma["shipments"] = mp(3, 3);
  ma["sight"] = mp(2, 5);
  ma["signed"] = mp(3, 10);
  ma["significantly"] = mp(3, 3);
  ma["slash"] = mp(3, 3);
  ma["smallest"] = mp(2, 3);
  ma["something"] = mp(3, 4);
  ma["soon"] = mp(3, 5);
  ma["source"] = mp(3, 3);
  ma["specific"] = mp(3, 5);
  ma["speech"] = mp(3, 3);
  ma["spokeswoman"] = mp(3, 3);
  ma["stability"] = mp(1, 6);
  ma["steady"] = mp(2, 3);
  ma["steep"] = mp(1, 3);
  ma["step"] = mp(3, 4);
  ma["steps"] = mp(3, 3);
  ma["stop"] = mp(3, 11);
  ma["stopped"] = mp(3, 5);
  ma["strengthen"] = mp(1, 3);
  ma["studying"] = mp(3, 3);
  ma["success"] = mp(3, 4);
  ma["summer"] = mp(3, 3);
  ma["sure"] = mp(3, 6);
  ma["survey"] = mp(1, 3);
  ma["technology"] = mp(3, 5);
  ma["television"] = mp(3, 3);
  ma["tell"] = mp(3, 3);
  ma["test"] = mp(3, 4);
  ma["textile"] = mp(3, 6);
  ma["textiles"] = mp(3, 3);
  ma["thus"] = mp(2, 3);
  ma["tied"] = mp(1, 3);
  ma["totalled"] = mp(2, 6);
  ma["tough"] = mp(3, 3);
  ma["trader"] = mp(1, 3);
  ma["transactions"] = mp(1, 6);
  ma["tried"] = mp(3, 3);
  ma["trip"] = mp(3, 8);
  ma["try"] = mp(3, 11);
  ma["trying"] = mp(3, 4);
  ma["unadjusted"] = mp(2, 5);
  ma["unchanged"] = mp(2, 6);
  ma["underlying"] = mp(1, 4);
  ma["unfair"] = mp(3, 7);
  ma["urge"] = mp(3, 3);
  ma["violating"] = mp(3, 3);
  ma["visit"] = mp(3, 14);
  ma["volume"] = mp(3, 3);
  ma["voted"] = mp(2, 3);
  ma["ward"] = mp(3, 3);
  ma["warned"] = mp(3, 3);
  ma["warning"] = mp(3, 3);
  ma["weakened"] = mp(3, 3);
  ma["willing"] = mp(3, 4);
  ma["yield"] = mp(1, 3);
  ma["yields"] = mp(1, 3);
  string s;
  int a[4];
  memset(a, 0, sizeof a);
  while (cin >> s) {
    if (ma.find(s) != ma.end()) {
      a[ma[s].first] += ma[s].second;
    }
  }
  int m = max(max(a[1], a[2]), a[3]);
  if (a[1] == m) {
    cout << 1 << endl;
  } else {
    if (a[2] == m) {
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
  return 0;
}