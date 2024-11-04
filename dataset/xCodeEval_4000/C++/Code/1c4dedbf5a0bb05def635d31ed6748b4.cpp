





































































































































































































































#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	ios::sync_with_stdio(0),cout.tie(0);
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << endl << ".\n";
        return 0;
    }
    if (n == 1 && m == 2) {
        cout << 0 << endl << "..\n";
        return 0;
    }
    if (n == 1 && m == 3) {
        cout << 0 << endl << "...\n";
        return 0;
    }
    if (n == 1 && m == 4) {
        cout << 0 << endl << "....\n";
        return 0;
    }
    if (n == 1 && m == 5) {
        cout << 0 << endl << ".....\n";
        return 0;
    }
    if (n == 1 && m == 6) {
        cout << 0 << endl << "......\n";
        return 0;
    }
    if (n == 1 && m == 7) {
        cout << 0 << endl << ".......\n";
        return 0;
    }
    if (n == 1 && m == 8) {
        cout << 0 << endl << "........\n";
        return 0;
    }
    if (n == 1 && m == 9) {
        cout << 0 << endl << ".........\n";
        return 0;
    }
    if (n == 2 && m == 1) {
        cout << 0 << endl << ".\n.\n";
        return 0;
    }
    if (n == 2 && m == 2) {
        cout << 0 << endl << "..\n..\n";
        return 0;
    }
    if (n == 2 && m == 3) {
        cout << 0 << endl << "...\n...\n";
        return 0;
    }
    if (n == 2 && m == 4) {
        cout << 0 << endl << "....\n....\n";
        return 0;
    }
    if (n == 2 && m == 5) {
        cout << 0 << endl << ".....\n.....\n";
        return 0;
    }
    if (n == 2 && m == 6) {
        cout << 0 << endl << "......\n......\n";
        return 0;
    }
    if (n == 2 && m == 7) {
        cout << 0 << endl << ".......\n.......\n";
        return 0;
    }
    if (n == 2 && m == 8) {
        cout << 0 << endl << "........\n........\n";
        return 0;
    }
    if (n == 2 && m == 9) {
        cout << 0 << endl << ".........\n.........\n";
        return 0;
    }
    if (n == 3 && m == 1) {
        cout << 0 << endl << ".\n.\n.\n";
        return 0;
    }
    if (n == 3 && m == 2) {
        cout << 0 << endl << "..\n..\n..\n";
        return 0;
    }
    if (n == 3 && m == 3) {
        cout << 1 << endl << "A..\nAAA\nA..\n";
        return 0;
    }
    if (n == 3 && m == 4) {
        cout << 1 << endl << "A...\nAAA.\nA...\n";
        return 0;
    }
    if (n == 3 && m == 5) {
        cout << 2 << endl << "A..B.\nAAAB.\nA.BBB\n";
        return 0;
    }
    if (n == 3 && m == 6) {
        cout << 2 << endl << "A..B..\nAAAB..\nA.BBB.\n";
        return 0;
    }
    if (n == 3 && m == 7) {
        cout << 3 << endl << "A.BBB.C\nAAABCCC\nA..B..C\n";
        return 0;
    }
    if (n == 3 && m == 8) {
        cout << 3 << endl << "A.BBBC..\nAAAB.CCC\nA..B.C..\n";
        return 0;
    }
    if (n == 3 && m == 9) {
        cout << 4 << endl << "A.BBBDCCC\nAAAB.D.C.\nA..BDDDC.\n";
        return 0;
    }
    if (n == 4 && m == 1) {
        cout << 0 << endl << ".\n.\n.\n.\n";
        return 0;
    }
    if (n == 4 && m == 2) {
        cout << 0 << endl << "..\n..\n..\n..\n";
        return 0;
    }
    if (n == 4 && m == 3) {
        cout << 1 << endl << "A..\nAAA\nA..\n...\n";
        return 0;
    }
    if (n == 4 && m == 4) {
        cout << 2 << endl << "A...\nAAAB\nABBB\n...B\n";
        return 0;
    }
    if (n == 4 && m == 5) {
        cout << 2 << endl << "A....\nAAAB.\nABBB.\n...B.\n";
        return 0;
    }
    if (n == 4 && m == 6) {
        cout << 3 << endl << "A..BBB\nAAACB.\nACCCB.\n...C..\n";
        return 0;
    }
    if (n == 4 && m == 7) {
        cout << 4 << endl << "AAAB...\n.ADBBBC\n.ADBCCC\n.DDD..C\n";
        return 0;
    }
    if (n == 4 && m == 8) {
        cout << 4 << endl << "A.BBB...\nAAABDCCC\nA..BD.C.\n...DDDC.\n";
        return 0;
    }
    if (n == 4 && m == 9) {
        cout << 5 << endl << "A.BBBC...\nAAABECCCD\nA..BECDDD\n...EEE..D\n";
        return 0;
    }
    if (n == 5 && m == 1) {
        cout << 0 << endl << ".\n.\n.\n.\n.\n";
        return 0;
    }
    if (n == 5 && m == 2) {
        cout << 0 << endl << "..\n..\n..\n..\n..\n";
        return 0;
    }
    if (n == 5 && m == 3) {
        cout << 2 << endl << "A..\nAAA\nA.B\nBBB\n..B\n";
        return 0;
    }
    if (n == 5 && m == 4) {
        cout << 2 << endl << "A...\nAAAB\nABBB\n...B\n....\n";
        return 0;
    }
    if (n == 5 && m == 5) {
        cout << 4 << endl << "A.BBB\nAAAB.\nAD.BC\n.DCCC\nDDD.C\n";
        return 0;
    }
    if (n == 5 && m == 6) {
        cout << 4 << endl << "A..B..\nAAAB..\nADBBBC\n.D.CCC\nDDD..C\n";
        return 0;
    }
    if (n == 5 && m == 7) {
        cout << 5 << endl << "A.BBB..\nAAABCCC\nAE.BDC.\n.EDDDC.\nEEE.D..\n";
        return 0;
    }
    if (n == 5 && m == 8) {
        cout << 6 << endl << "A.BBBC..\nAAAB.CCC\nAD.BFC.E\n.DDDFEEE\n.D.FFF.E\n";
        return 0;
    }
    if (n == 5 && m == 9) {
        cout << 7 << endl << "A.BBB.CCC\nAAABDDDC.\nAE.BGDFC.\n.EEEGDFFF\n.E.GGGF..\n";
        return 0;
    }
    if (n == 6 && m == 1) {
        cout << 0 << endl << ".\n.\n.\n.\n.\n.\n";
        return 0;
    }
    if (n == 6 && m == 2) {
        cout << 0 << endl << "..\n..\n..\n..\n..\n..\n";
        return 0;
    }
    if (n == 6 && m == 3) {
        cout << 2 << endl << "A..\nAAA\nA.B\nBBB\n..B\n...\n";
        return 0;
    }
    if (n == 6 && m == 4) {
        cout << 3 << endl << "A...\nAAAB\nABBB\nC..B\nCCC.\nC...\n";
        return 0;
    }
    if (n == 6 && m == 5) {
        cout << 4 << endl << "A....\nAAAB.\nABBB.\nCCCBD\n.CDDD\n.C..D\n";
        return 0;
    }
    if (n == 6 && m == 6) {
        cout << 5 << endl << "A.....\nAAABBB\nACCCB.\n.ECDB.\n.ECDDD\nEEED..\n";
        return 0;
    }
    if (n == 6 && m == 7) {
        cout << 6 << endl << "A..C...\nAAACBBB\nA.CCCB.\nD.EEEBF\nDDDEFFF\nD..E..F\n";
        return 0;
    }
    if (n == 6 && m == 8) {
        cout << 7 << endl << "A.....D.\nAAABBBD.\nACCCBDDD\n.GCEBFFF\n.GCEEEF.\nGGGE..F.\n";
        return 0;
    }
    if (n == 6 && m == 9) {
        cout << 8 << endl << "A.BBBE...\nAAAB.ECCC\nA.DBEEEC.\nDDDHFFFCG\n..DH.FGGG\n..HHHF..G\n";
        return 0;
    }
    if (n == 7 && m == 1) {
        cout << 0 << endl << ".\n.\n.\n.\n.\n.\n.\n";
        return 0;
    }
    if (n == 7 && m == 2) {
        cout << 0 << endl << "..\n..\n..\n..\n..\n..\n..\n";
        return 0;
    }
    if (n == 7 && m == 3) {
        cout << 3 << endl << "A..\nAAA\nA.B\nBBB\nC.B\nCCC\nC..\n";
        return 0;
    }
    if (n == 7 && m == 4) {
        cout << 4 << endl << "A...\nAAAB\nABBB\nC..B\nCCCD\nCDDD\n...D\n";
        return 0;
    }
    if (n == 7 && m == 5) {
        cout << 5 << endl << "A....\nAAA.B\nACBBB\n.CCCB\nDCEEE\nDDDE.\nD..E.\n";
        return 0;
    }
    if (n == 7 && m == 6) {
        cout << 6 << endl << "A.BBB.\nAAABD.\nA.CBD.\nCCCDDD\nE.CF..\nEEEFFF\nE..F..\n";
        return 0;
    }
    if (n == 7 && m == 7) {
        cout << 8 << endl << "A.BBB.C\nAAABCCC\nAD.BE.C\n.DDDEEE\nFD.HE.G\nFFFHGGG\nF.HHH.G\n";
        return 0;
    }
    if (n == 7 && m == 8) {
        cout << 9 << endl << "A..BBB.C\nAAADBCCC\nADDDB.EC\nFFFDEEE.\n.FIGGGEH\n.FI.GHHH\n.IIIG..H\n";
        return 0;
    }
    if (n == 7 && m == 9) {
        cout << 10 << endl << "A.BBBE...\nAAAB.ECCC\nA.DBEEEC.\nDDDFFF.CG\nH.DJFIGGG\nHHHJFIIIG\nH.JJJI...\n";
        return 0;
    }
    if (n == 8 && m == 1) {
        cout << 0 << endl << ".\n.\n.\n.\n.\n.\n.\n.\n";
        return 0;
    }
    if (n == 8 && m == 2) {
        cout << 0 << endl << "..\n..\n..\n..\n..\n..\n..\n..\n";
        return 0;
    }
    if (n == 8 && m == 3) {
        cout << 3 << endl << "A..\nAAA\nA.B\nBBB\nC.B\nCCC\nC..\n...\n";
        return 0;
    }
    if (n == 8 && m == 4) {
        cout << 4 << endl << "A...\nAAAB\nABBB\nC..B\nCCCD\nCDDD\n...D\n....\n";
        return 0;
    }
    if (n == 8 && m == 5) {
        cout << 6 << endl << "A..C.\nAAAC.\nABCCC\n.BBBD\nEBDDD\nEEEFD\nEFFF.\n...F.\n";
        return 0;
    }
    if (n == 8 && m == 6) {
        cout << 7 << endl << "A.BBB.\nAAAB..\nAC.BE.\n.CCCE.\n.CDEEE\n.GDDDF\n.GDFFF\nGGG..F\n";
        return 0;
    }
    if (n == 8 && m == 7) {
        cout << 9 << endl << "AAAB...\n.AEBBBC\n.AEBCCC\nDEEE.FC\nDDDFFF.\nDIGGGFH\n.I.GHHH\nIIIG..H\n";
        return 0;
    }
    if (n == 8 && m == 8) {
        cout << 10 << endl << "A.BBB...\nAAABCCC.\nAE.BDCG.\n.EDDDCG.\nEEEFDGGG\nHFFFJIII\nHHHFJ.I.\nH..JJJI.\n";
        return 0;
    }
    if (n == 8 && m == 9) {
        cout << 12 << endl << "A.BBBC...\nAAABFCCCD\nA.EBFCDDD\nEEEFFFG.D\nH.EIIIGGG\nHHHJILG.K\nHJJJILKKK\n...JLLL.K\n";
        return 0;
    }
    if (n == 9 && m == 1) {
        cout << 0 << endl << ".\n.\n.\n.\n.\n.\n.\n.\n.\n";
        return 0;
    }
    if (n == 9 && m == 2) {
        cout << 0 << endl << "..\n..\n..\n..\n..\n..\n..\n..\n..\n";
        return 0;
    }
    if (n == 9 && m == 3) {
        cout << 4 << endl << "A..\nAAA\nA.B\nBBB\nC.B\nCCC\nC.D\nDDD\n..D\n";
        return 0;
    }
    if (n == 9 && m == 4) {
        cout << 5 << endl << "A...\nAAAB\nABBB\nC..B\nCCCD\nCDDD\nE..D\nEEE.\nE...\n";
        return 0;
    }
    if (n == 9 && m == 5) {
        cout << 7 << endl << "A....\nAAA.B\nACBBB\n.CCCB\nDCEEE\nDDDE.\nDG.EF\n.GFFF\nGGG.F\n";
        return 0;
    }
    if (n == 9 && m == 6) {
        cout << 8 << endl << "A...C.\nAAA.C.\nA.BCCC\nBBBDDD\nE.BFD.\nEEEFD.\nEHFFFG\n.H.GGG\nHHH..G\n";
        return 0;
    }
    if (n == 9 && m == 7) {
        cout << 10 << endl << "A.BBB.C\nAAABCCC\nAD.BE.C\n.DDDEEE\nFD..EG.\nFFFGGG.\nFJHHHGI\n.J.HIII\nJJJH..I\n";
        return 0;
    }
    if (n == 9 && m == 8) {
        cout << 12 << endl << "AAAB.CCC\n.AFBBBC.\n.AFBG.CD\nEFFFGDDD\nEEEGGGHD\nEIIIHHH.\n.LIJJJHK\n.LI.JKKK\nLLL.J..K\n";
        return 0;
    }
    if (n == 9 && m == 9) {
        cout << 13 << endl << "A.BBB..E.\nAAABCCCE.\nAD.BHCEEE\n.DDDHCF..\n.DGHHHFFF\nGGGIIIF.J\nK.GMILJJJ\nKKKMILLLJ\nK.MMML...\n";
        return 0;
    }
}
