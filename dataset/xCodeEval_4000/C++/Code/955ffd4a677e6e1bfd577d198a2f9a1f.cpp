#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	if(n == 1 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << ".";}
	else if(n == 1 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << "..";}
	else if(n == 1 && m == 3) {
	cout << 0 << endl;
	cout << ""<< endl << "...";}
	else if(n == 1 && m == 4) {
	cout << 0 << endl;
	cout << ""<< endl << "....";}
	else if(n == 1 && m == 5) {
	cout << 0 << endl;
	cout << ""<< endl << ".....";}
	else if(n == 1 && m == 6) {
	cout << 0 << endl;
	cout << ""<< endl << "......";}
	else if(n == 1 && m == 7) {
	cout << 0 << endl;
	cout << ""<< endl << ".......";}
	else if(n == 1 && m == 8) {
	cout << 0 << endl;
	cout << ""<< endl << "........";}
	else if(n == 1 && m == 9) {
	cout << 0 << endl;
	cout << ""<< endl << ".........";}
	else if(n == 2 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << ".";}
	else if(n == 2 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << "..";}
	else if(n == 2 && m == 3) {
	cout << 0 << endl;
	cout << ""<< endl << "..."<< endl << "...";}
	else if(n == 2 && m == 4) {
	cout << 0 << endl;
	cout << ""<< endl << "...."<< endl << "....";}
	else if(n == 2 && m == 5) {
	cout << 0 << endl;
	cout << ""<< endl << "....."<< endl << ".....";}
	else if(n == 2 && m == 6) {
	cout << 0 << endl;
	cout << ""<< endl << "......"<< endl << "......";}
	else if(n == 2 && m == 7) {
	cout << 0 << endl;
	cout << ""<< endl << "......."<< endl << ".......";}
	else if(n == 2 && m == 8) {
	cout << 0 << endl;
	cout << ""<< endl << "........"<< endl << "........";}
	else if(n == 2 && m == 9) {
	cout << 0 << endl;
	cout << ""<< endl << "........."<< endl << ".........";}
	else if(n == 3 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << "."<< endl << ".";}
	else if(n == 3 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << ".."<< endl << "..";}
	else if(n == 3 && m == 3) {
	cout << 1 << endl;
	cout << ""<< endl << "AAA"<< endl << ".A."<< endl << ".A.";}
	else if(n == 3 && m == 4) {
	cout << 1 << endl;
	cout << ""<< endl << "AAA."<< endl << ".A.."<< endl << ".A..";}
	else if(n == 3 && m == 5) {
	cout << 2 << endl;
	cout << ""<< endl << "AAA.B"<< endl << ".ABBB"<< endl << ".A..B";}
	else if(n == 3 && m == 6) {
	cout << 2 << endl;
	cout << ""<< endl << "AAABBB"<< endl << ".A..B."<< endl << ".A..B.";}
	else if(n == 3 && m == 7) {
	cout << 3 << endl;
	cout << ""<< endl << "AAACBBB"<< endl << ".A.C.B."<< endl << ".ACCCB.";}
	else if(n == 3 && m == 8) {
	cout << 3 << endl;
	cout << ""<< endl << "AAABBB.C"<< endl << ".A..BCCC"<< endl << ".A..B..C";}
	else if(n == 3 && m == 9) {
	cout << 4 << endl;
	cout << ""<< endl << "AAADBBB.C"<< endl << ".A.D.BCCC"<< endl << ".ADDDB..C";}
	else if(n == 4 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << "."<< endl << "."<< endl << ".";}
	else if(n == 4 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << ".."<< endl << ".."<< endl << "..";}
	else if(n == 4 && m == 3) {
	cout << 1 << endl;
	cout << ""<< endl << "AAA"<< endl << ".A."<< endl << ".A."<< endl << "...";}
	else if(n == 4 && m == 4) {
	cout << 2 << endl;
	cout << ""<< endl << "AAA."<< endl << ".AB."<< endl << ".AB."<< endl << ".BBB";}
	else if(n == 4 && m == 5) {
	cout << 2 << endl;
	cout << ""<< endl << "AAA.."<< endl << ".ABBB"<< endl << ".A.B."<< endl << "...B.";}
	else if(n == 4 && m == 6) {
	cout << 3 << endl;
	cout << ""<< endl << "AAABBB"<< endl << ".AC.B."<< endl << ".AC.B."<< endl << ".CCC..";}
	else if(n == 4 && m == 7) {
	cout << 4 << endl;
	cout << ""<< endl << "AAABBB."<< endl << ".AC.BD."<< endl << ".AC.BD."<< endl << ".CCCDDD";}
	else if(n == 4 && m == 8) {
	cout << 4 << endl;
	cout << ""<< endl << "AAABBB.."<< endl << ".AD.BCCC"<< endl << ".AD.B.C."<< endl << ".DDD..C.";}
	else if(n == 4 && m == 9) {
	cout << 5 << endl;
	cout << ""<< endl << "AAABBBCCC"<< endl << ".AD.BE.C."<< endl << ".AD.BE.C."<< endl << ".DDDEEE..";}
	else if(n == 5 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << ".";}
	else if(n == 5 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << "..";}
	else if(n == 5 && m == 3) {
	cout << 2 << endl;
	cout << ""<< endl << "AAA"<< endl << ".A."<< endl << "BA."<< endl << "BBB"<< endl << "B..";}
	else if(n == 5 && m == 4) {
	cout << 2 << endl;
	cout << ""<< endl << "AAA."<< endl << ".A.."<< endl << "BA.."<< endl << "BBB."<< endl << "B...";}
	else if(n == 5 && m == 5) {
	cout << 4 << endl;
	cout << ""<< endl << "AAA.B"<< endl << ".ABBB"<< endl << "CA.DB"<< endl << "CCCD."<< endl << "C.DDD";}
	else if(n == 5 && m == 6) {
	cout << 4 << endl;
	cout << ""<< endl << "AAABBB"<< endl << ".A..B."<< endl << "CA.DB."<< endl << "CCCDDD"<< endl << "C..D..";}
	else if(n == 5 && m == 7) {
	cout << 5 << endl;
	cout << ""<< endl << "AAABBB."<< endl << ".A..BD."<< endl << "CA.EBD."<< endl << "CCCEDDD"<< endl << "C.EEE..";}
	else if(n == 5 && m == 8) {
	cout << 6 << endl;
	cout << ""<< endl << "AAABBB.C"<< endl << ".A..BCCC"<< endl << "DA.EB.FC"<< endl << "DDDEEEF."<< endl << "D..E.FFF";}
	else if(n == 5 && m == 9) {
	cout << 7 << endl;
	cout << ""<< endl << "AAABBBC.."<< endl << ".A..BECCC"<< endl << "DA.FBECG."<< endl << "DDDFEEEG."<< endl << "D.FFF.GGG";}
	else if(n == 6 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << ".";}
	else if(n == 6 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << "..";}
	else if(n == 6 && m == 3) {
	cout << 2 << endl;
	cout << ""<< endl << "AAA"<< endl << ".A."<< endl << "BA."<< endl << "BBB"<< endl << "B.."<< endl << "...";}
	else if(n == 6 && m == 4) {
	cout << 3 << endl;
	cout << ""<< endl << "AAA."<< endl << ".A.."<< endl << "BA.."<< endl << "BBBC"<< endl << "BCCC"<< endl << "...C";}
	else if(n == 6 && m == 5) {
	cout << 4 << endl;
	cout << ""<< endl << "AAA.."<< endl << ".ABBB"<< endl << "CA.B."<< endl << "CCCBD"<< endl << "C.DDD"<< endl << "....D";}
	else if(n == 6 && m == 6) {
	cout << 5 << endl;
	cout << ""<< endl << "AAABBB"<< endl << ".AC.B."<< endl << ".AC.B."<< endl << "DCCC.E"<< endl << "DDDEEE"<< endl << "D....E";}
	else if(n == 6 && m == 7) {
	cout << 6 << endl;
	cout << ""<< endl << "AAA.BBB"<< endl << ".AC..B."<< endl << ".ACCCB."<< endl << "E.CFDDD"<< endl << "EEEF.D."<< endl << "E.FFFD.";}
	else if(n == 6 && m == 8) {
	cout << 7 << endl;
	cout << ""<< endl << "AAABBB.."<< endl << ".AD.BCCC"<< endl << ".AD.B.C."<< endl << "EDDDG.CF"<< endl << "EEE.GFFF"<< endl << "E..GGG.F";}
	else if(n == 6 && m == 9) {
	cout << 8 << endl;
	cout << ""<< endl << "AAABBBCCC"<< endl << ".AD.B..C."<< endl << ".AD.BE.C."<< endl << "FDDDHEEEG"<< endl << "FFF.HEGGG"<< endl << "F..HHH..G";}
	else if(n == 7 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << ".";}
	else if(n == 7 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << "..";}
	else if(n == 7 && m == 3) {
	cout << 3 << endl;
	cout << ""<< endl << "AAA"<< endl << ".A."<< endl << "BA."<< endl << "BBB"<< endl << "B.C"<< endl << "CCC"<< endl << "..C";}
	else if(n == 7 && m == 4) {
	cout << 4 << endl;
	cout << ""<< endl << "AAA."<< endl << ".AB."<< endl << ".AB."<< endl << "CBBB"<< endl << "CCCD"<< endl << "CDDD"<< endl << "...D";}
	else if(n == 7 && m == 5) {
	cout << 5 << endl;
	cout << ""<< endl << "AAA.."<< endl << ".ABBB"<< endl << "CA.B."<< endl << "CCCB."<< endl << "CEDDD"<< endl << ".E.D."<< endl << "EEED.";}
	else if(n == 7 && m == 6) {
	cout << 6 << endl;
	cout << ""<< endl << "AAABBB"<< endl << ".A..B."<< endl << "CA.DB."<< endl << "CCCDDD"<< endl << "CE.DF."<< endl << ".EEEF."<< endl << ".E.FFF";}
	else if(n == 7 && m == 7) {
	cout << 8 << endl;
	cout << ""<< endl << "AAA.BBB"<< endl << ".ACCCB."<< endl << "DA.C.BE"<< endl << "DDDCEEE"<< endl << "DGFFFHE"<< endl << ".G.F.H."<< endl << "GGGFHHH";}
	else if(n == 7 && m == 8) {
	cout << 9 << endl;
	cout << ""<< endl << "AAA.BBB."<< endl << ".ACCCBE."<< endl << ".ADC.BE."<< endl << "DDDCFEEE"<< endl << "G.DIFFFH"<< endl << "GGGIFHHH"<< endl << "G.III..H";}
	else if(n == 7 && m == 9) {
	cout << 10 << endl;
	cout << ""<< endl << "AAA.BBB.."<< endl << ".ACCCBDDD"<< endl << ".AECFB.D."<< endl << "EEECFFFDG"<< endl << "H.EJFIGGG"<< endl << "HHHJ.IIIG"<< endl << "H.JJJI...";}
	else if(n == 8 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << ".";}
	else if(n == 8 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << "..";}
	else if(n == 8 && m == 3) {
	cout << 3 << endl;
	cout << ""<< endl << "AAA"<< endl << ".A."<< endl << "BA."<< endl << "BBB"<< endl << "B.."<< endl << "CCC"<< endl << ".C."<< endl << ".C.";}
	else if(n == 8 && m == 4) {
	cout << 4 << endl;
	cout << ""<< endl << "AAA."<< endl << ".A.."<< endl << "BA.."<< endl << "BBB."<< endl << "BCCC"<< endl << ".DC."<< endl << ".DC."<< endl << "DDD.";}
	else if(n == 8 && m == 5) {
	cout << 6 << endl;
	cout << ""<< endl << "AAA.."<< endl << ".ABBB"<< endl << "CA.B."<< endl << "CCCBD"<< endl << "C.DDD"<< endl << "EEEFD"<< endl << ".E.F."<< endl << ".EFFF";}
	else if(n == 8 && m == 6) {
	cout << 7 << endl;
	cout << ""<< endl << "AAABBB"<< endl << ".A..B."<< endl << "CA.DB."<< endl << "CCCDDD"<< endl << "C.ED.."<< endl << ".GEEEF"<< endl << ".GEFFF"<< endl << "GGG..F";}
	else if(n == 8 && m == 7) {
	cout << 9 << endl;
	cout << ""<< endl << "AAA.BBB"<< endl << ".ACCCB."<< endl << "DA.CEB."<< endl << "DDDCEEE"<< endl << "DFFFE.G"<< endl << ".IFHGGG"<< endl << ".IFHHHG"<< endl << "IIIH...";}
	else if(n == 8 && m == 8) {
	cout << 10 << endl;
	cout << ""<< endl << "AAABBB.."<< endl << ".A..BCCC"<< endl << "DA..B.C."<< endl << "DDDEEECG"<< endl << "DFFFEGGG"<< endl << ".IFHE.JG"<< endl << ".IFHHHJ."<< endl << "IIIH.JJJ";}
	else if(n == 8 && m == 9) {
	cout << 12 << endl;
	cout << ""<< endl << "AAA.BBB.D"<< endl << ".ACCCBDDD"<< endl << "EA.CFB.GD"<< endl << "EEECFFFG."<< endl << "E..HFIGGG"<< endl << "JHHHLIIIK"<< endl << "JJJHLIKKK"<< endl << "J..LLL..K";}
	else if(n == 9 && m == 1) {
	cout << 0 << endl;
	cout << ""<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << "."<< endl << ".";}
	else if(n == 9 && m == 2) {
	cout << 0 << endl;
	cout << ""<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << ".."<< endl << "..";}
	else if(n == 9 && m == 3) {
	cout << 4 << endl;
	cout << ""<< endl << "AAA"<< endl << ".A."<< endl << "BA."<< endl << "BBB"<< endl << "B.C"<< endl << "CCC"<< endl << "D.C"<< endl << "DDD"<< endl << "D..";}
	else if(n == 9 && m == 4) {
	cout << 5 << endl;
	cout << ""<< endl << "AAA."<< endl << ".A.."<< endl << "BA.."<< endl << "BBBC"<< endl << "BCCC"<< endl << "DDDC"<< endl << ".DE."<< endl << ".DE."<< endl << ".EEE";}
	else if(n == 9 && m == 5) {
	cout << 7 << endl;
	cout << ""<< endl << "AAA.."<< endl << ".ABBB"<< endl << "CA.B."<< endl << "CCCBD"<< endl << "CEDDD"<< endl << ".EEED"<< endl << "GEFFF"<< endl << "GGGF."<< endl << "G..F.";}
	else if(n == 9 && m == 6) {
	cout << 8 << endl;
	cout << ""<< endl << "AAABBB"<< endl << ".A..B."<< endl << "CA.DB."<< endl << "CCCDDD"<< endl << "C.ED.."<< endl << "EEEFFF"<< endl << "G.EHF."<< endl << "GGGHF."<< endl << "G.HHH.";}
	else if(n == 9 && m == 7) {
	cout << 10 << endl;
	cout << ""<< endl << "AAABBB."<< endl << ".A..BD."<< endl << "CA.EBD."<< endl << "CCCEDDD"<< endl << "CFEEE.G"<< endl << ".FFFGGG"<< endl << "IFHHHJG"<< endl << "IIIH.J."<< endl << "I..HJJJ";}
	else if(n == 9 && m == 8) {
	cout << 12 << endl;
	cout << ""<< endl << "AAABBB.C"<< endl << ".AD.BCCC"<< endl << ".AD.B.EC"<< endl << "FDDDEEE."<< endl << "FFFGGGEI"<< endl << "FHHHGIII"<< endl << ".KHJG.LI"<< endl << ".KHJJJL."<< endl << "KKKJ.LLL";}
	else if(n == 9 && m == 9) {
	cout << 13 << endl;
	cout << ""<< endl << "AAABBBCCC"<< endl << ".AD.BE.C."<< endl << ".AD.BE.C."<< endl << "FDDDEEE.H"<< endl << "FFFGGGHHH"<< endl << "FIIIGJJJH"<< endl << ".LIKG.JM."<< endl << ".LIKKKJM."<< endl << "LLLK..MMM";}
}
