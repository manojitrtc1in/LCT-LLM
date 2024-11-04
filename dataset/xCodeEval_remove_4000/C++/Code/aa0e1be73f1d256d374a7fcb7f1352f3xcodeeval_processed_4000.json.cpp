












using namespace std;

const double pi = acos(-1.0);










int ans[100][100], n, m;
string str[100][100];
char tmp[100][100];

int main() {
    

    

    scanf("%d%d", &n, &m);
    ans[1][1] = 0;
    ans[1][1] = 0;
str[1][1] = ".\n";
ans[1][2] = 0;
str[1][2] = "..\n";
ans[1][3] = 0;
str[1][3] = "...\n";
ans[1][4] = 0;
str[1][4] = "....\n";
ans[1][5] = 0;
str[1][5] = ".....\n";
ans[1][6] = 0;
str[1][6] = "......\n";
ans[1][7] = 0;
str[1][7] = ".......\n";
ans[1][8] = 0;
str[1][8] = "........\n";
ans[1][9] = 0;
str[1][9] = ".........\n";
ans[2][2] = 0;
str[2][2] = "..\n..\n";
ans[2][3] = 0;
str[2][3] = "...\n...\n";
ans[2][4] = 0;
str[2][4] = "....\n....\n";
ans[2][5] = 0;
str[2][5] = ".....\n.....\n";
ans[2][6] = 0;
str[2][6] = "......\n......\n";
ans[2][7] = 0;
str[2][7] = ".......\n.......\n";
ans[2][8] = 0;
str[2][8] = "........\n........\n";
ans[2][9] = 0;
str[2][9] = ".........\n.........\n";
str[3][3] = "AAA\n.A.\n.A.\n";
ans[3][3] = 1;
str[3][3] = "AAA\n.A.\n.A.\n";
str[3][4] = ".AAA\n..A.\n..A.\n";
ans[3][4] = 1;
str[3][4] = ".AAA\n..A.\n..A.\n";
str[3][5] = "..AAA\n...A.\n...A.\n";
str[3][5] = "AAA.B\n.ABBB\n.A..B\n";
ans[3][5] = 2;
str[3][5] = "AAA.B\n.ABBB\n.A..B\n";
str[3][6] = "...AAA\n....A.\n....A.\n";
str[3][6] = ".AAA.B\n..ABBB\n..A..B\n";
ans[3][6] = 2;
str[3][6] = ".AAA.B\n..ABBB\n..A..B\n";
str[3][7] = "....AAA\n.....A.\n.....A.\n";
str[3][7] = "..AAA.B\n...ABBB\n...A..B\n";
str[3][7] = "AAABCCC\n.A.B.C.\n.ABBBC.\n";
ans[3][7] = 3;
str[3][7] = "AAABCCC\n.A.B.C.\n.ABBBC.\n";
str[3][8] = ".....AAA\n......A.\n......A.\n";
str[3][8] = "...AAA.B\n....ABBB\n....A..B\n";
str[3][8] = ".AAABCCC\n..A.B.C.\n..ABBBC.\n";
ans[3][8] = 3;
str[3][8] = ".AAABCCC\n..A.B.C.\n..ABBBC.\n";
str[3][9] = "......AAA\n.......A.\n.......A.\n";
str[3][9] = "....AAA.B\n.....ABBB\n.....A..B\n";
str[3][9] = "..AAABCCC\n...A.B.C.\n...ABBBC.\n";
str[3][9] = "AAABCCC.D\n.A.B.CDDD\n.ABBBC..D\n";
ans[3][9] = 4;
str[3][9] = "AAABCCC.D\n.A.B.CDDD\n.ABBBC..D\n";
str[4][4] = "....\n.AAA\n..A.\n..A.\n";
str[4][4] = ".AAA\n.BA.\n.BA.\nBBB.\n";
ans[4][4] = 2;
str[4][4] = ".AAA\n.BA.\n.BA.\nBBB.\n";
str[4][5] = ".....\n..AAA\n...A.\n...A.\n";
str[4][5] = ".....\nAAA.B\n.ABBB\n.A..B\n";
ans[4][5] = 2;
str[4][5] = ".....\nAAA.B\n.ABBB\n.A..B\n";
str[4][6] = "......\n...AAA\n....A.\n....A.\n";
str[4][6] = "......\n.AAA.B\n..ABBB\n..A..B\n";
str[4][6] = "...AAA\nBBBCA.\n.B.CA.\n.BCCC.\n";
ans[4][6] = 3;
str[4][6] = "...AAA\nBBBCA.\n.B.CA.\n.BCCC.\n";
str[4][7] = ".......\n....AAA\n.....A.\n.....A.\n";
str[4][7] = ".......\n..AAA.B\n...ABBB\n...A..B\n";
str[4][7] = ".......\nAAABCCC\n.A.B.C.\n.ABBBC.\n";
str[4][7] = ".AAABBB\n.CA.DB.\n.CA.DB.\nCCCDDD.\n";
ans[4][7] = 4;
str[4][7] = ".AAABBB\n.CA.DB.\n.CA.DB.\nCCCDDD.\n";
str[4][8] = "........\n.....AAA\n......A.\n......A.\n";
str[4][8] = "........\n...AAA.B\n....ABBB\n....A..B\n";
str[4][8] = "........\n.AAABCCC\n..A.B.C.\n..ABBBC.\n";
str[4][8] = ".....AAA\n.BCCCDA.\n.B.C.DA.\nBBBCDDD.\n";
ans[4][8] = 4;
str[4][8] = ".....AAA\n.BCCCDA.\n.B.C.DA.\nBBBCDDD.\n";
str[4][9] = ".........\n......AAA\n.......A.\n.......A.\n";
str[4][9] = ".........\n....AAA.B\n.....ABBB\n.....A..B\n";
str[4][9] = ".........\n..AAABCCC\n...A.B.C.\n...ABBBC.\n";
str[4][9] = ".........\nAAABCCC.D\n.A.B.CDDD\n.ABBBC..D\n";
str[4][9] = "...AAABBB\nCCCDA.EB.\n.C.DA.EB.\n.CDDDEEE.\n";
ans[4][9] = 5;
str[4][9] = "...AAABBB\nCCCDA.EB.\n.C.DA.EB.\n.CDDDEEE.\n";
str[5][5] = ".....\n.....\n..AAA\n...A.\n...A.\n";
str[5][5] = ".....\n.....\nAAA.B\n.ABBB\n.A..B\n";
str[5][5] = "..AAA\n...A.\nBBBAC\n.BCCC\n.B..C\n";
str[5][5] = "AAA.B\n.ABBB\nCA.DB\nCCCD.\nC.DDD\n";
ans[5][5] = 4;
str[5][5] = "AAA.B\n.ABBB\nCA.DB\nCCCD.\nC.DDD\n";
str[5][6] = "......\n......\n...AAA\n....A.\n....A.\n";
str[5][6] = "......\n......\n.AAA.B\n..ABBB\n..A..B\n";
str[5][6] = "......\n...AAA\nBBBCA.\n.B.CA.\n.BCCC.\n";
str[5][6] = "...AAA\n.BBBA.\n.CB.AD\n.CBDDD\nCCC..D\n";
ans[5][6] = 4;
str[5][6] = "...AAA\n.BBBA.\n.CB.AD\n.CBDDD\nCCC..D\n";
str[5][7] = ".......\n.......\n....AAA\n.....A.\n.....A.\n";
str[5][7] = ".......\n.......\n..AAA.B\n...ABBB\n...A..B\n";
str[5][7] = ".......\n.......\nAAABCCC\n.A.B.C.\n.ABBBC.\n";
str[5][7] = ".......\n.AAABBB\n.CA.DB.\n.CA.DB.\nCCCDDD.\n";
str[5][7] = "..AAA.B\nCCCABBB\n.CDA.EB\n.CDDDE.\n..D.EEE\n";
ans[5][7] = 5;
str[5][7] = "..AAA.B\nCCCABBB\n.CDA.EB\n.CDDDE.\n..D.EEE\n";
str[5][8] = "........\n........\n.....AAA\n......A.\n......A.\n";
str[5][8] = "........\n........\n...AAA.B\n....ABBB\n....A..B\n";
str[5][8] = "........\n........\n.AAABCCC\n..A.B.C.\n..ABBBC.\n";
str[5][8] = "........\n.....AAA\n.BCCCDA.\n.B.C.DA.\nBBBCDDD.\n";
str[5][8] = ".....AAA\n...BBBA.\nCCCDB.AE\n.C.DBEEE\n.CDDD..E\n";
str[5][8] = "...AAA.B\n.CCCABBB\n.DCEA.FB\n.DCEEEF.\nDDDE.FFF\n";
ans[5][8] = 6;
str[5][8] = "...AAA.B\n.CCCABBB\n.DCEA.FB\n.DCEEEF.\nDDDE.FFF\n";
str[5][9] = ".........\n.........\n......AAA\n.......A.\n.......A.\n";
str[5][9] = ".........\n.........\n....AAA.B\n.....ABBB\n.....A..B\n";
str[5][9] = ".........\n.........\n..AAABCCC\n...A.B.C.\n...ABBBC.\n";
str[5][9] = ".........\n.........\nAAABCCC.D\n.A.B.CDDD\n.ABBBC..D\n";
str[5][9] = ".........\n...AAABBB\nCCCDA.EB.\n.C.DA.EB.\n.CDDDEEE.\n";
str[5][9] = "......AAA\n.BBBCCCA.\n.DB.EC.AF\n.DB.ECFFF\nDDDEEE..F\n";
str[5][9] = ".AAAB.CCC\n..ADBBBC.\n.EADBF.CG\n.EDDDFGGG\nEEE.FFF.G\n";
ans[5][9] = 7;
str[5][9] = ".AAAB.CCC\n..ADBBBC.\n.EADBF.CG\n.EDDDFGGG\nEEE.FFF.G\n";
str[6][6] = "......\n......\n......\n...AAA\n....A.\n....A.\n";
str[6][6] = "......\n......\n......\n.AAA.B\n..ABBB\n..A..B\n";
str[6][6] = "......\n......\n...AAA\nBBBCA.\n.B.CA.\n.BCCC.\n";
str[6][6] = "......\n...AAA\n.BBBA.\n.CB.AD\n.CBDDD\nCCC..D\n";
str[6][6] = "...AAA\nBBBCA.\n.B.CA.\nDBCCCE\nDDDEEE\nD....E\n";
ans[6][6] = 5;
str[6][6] = "...AAA\nBBBCA.\n.B.CA.\nDBCCCE\nDDDEEE\nD....E\n";
str[6][7] = ".......\n.......\n.......\n....AAA\n.....A.\n.....A.\n";
str[6][7] = ".......\n.......\n.......\n..AAA.B\n...ABBB\n...A..B\n";
str[6][7] = ".......\n.......\n.......\nAAABCCC\n.A.B.C.\n.ABBBC.\n";
str[6][7] = ".......\n.......\n.AAABBB\n.CA.DB.\n.CA.DB.\nCCCDDD.\n";
str[6][7] = ".......\n..AAA.B\nCCCABBB\n.CDA.EB\n.CDDDE.\n..D.EEE\n";
str[6][7] = "....AAA\nBBB.CA.\n.BCCCA.\nDB.EC.F\nDDDEFFF\nD.EEE.F\n";
ans[6][7] = 6;
str[6][7] = "....AAA\nBBB.CA.\n.BCCCA.\nDB.EC.F\nDDDEFFF\nD.EEE.F\n";
str[6][8] = "........\n........\n........\n.....AAA\n......A.\n......A.\n";
str[6][8] = "........\n........\n........\n...AAA.B\n....ABBB\n....A..B\n";
str[6][8] = "........\n........\n........\n.AAABCCC\n..A.B.C.\n..ABBBC.\n";
str[6][8] = "........\n........\n.....AAA\n.BCCCDA.\n.B.C.DA.\nBBBCDDD.\n";
str[6][8] = "........\n.....AAA\n...BBBA.\nCCCDB.AE\n.C.DBEEE\n.CDDD..E\n";
str[6][8] = "........\n...AAA.B\n.CCCABBB\n.DCEA.FB\n.DCEEEF.\nDDDE.FFF\n";
str[6][8] = ".......A\nB.CCCAAA\nBBBCDDDA\nBE.CFDG.\n.EFFFDG.\nEEE.FGGG\n";
ans[6][8] = 7;
str[6][8] = ".......A\nB.CCCAAA\nBBBCDDDA\nBE.CFDG.\n.EFFFDG.\nEEE.FGGG\n";
str[6][9] = ".........\n.........\n.........\n......AAA\n.......A.\n.......A.\n";
str[6][9] = ".........\n.........\n.........\n....AAA.B\n.....ABBB\n.....A..B\n";
str[6][9] = ".........\n.........\n.........\n..AAABCCC\n...A.B.C.\n...ABBBC.\n";
str[6][9] = ".........\n.........\n.........\nAAABCCC.D\n.A.B.CDDD\n.ABBBC..D\n";
str[6][9] = ".........\n.........\n...AAABBB\nCCCDA.EB.\n.C.DA.EB.\n.CDDDEEE.\n";
str[6][9] = ".........\n......AAA\n.BBBCCCA.\n.DB.EC.AF\n.DB.ECFFF\nDDDEEE..F\n";
str[6][9] = ".........\n.AAAB.CCC\n..ADBBBC.\n.EADBF.CG\n.EDDDFGGG\nEEE.FFF.G\n";
str[6][9] = ".....ABBB\nC.DDDA.B.\nCCCDAAABE\nCF.DGHEEE\n.FGGGHHHE\nFFF.GH...\n";
ans[6][9] = 8;
str[6][9] = ".....ABBB\nC.DDDA.B.\nCCCDAAABE\nCF.DGHEEE\n.FGGGHHHE\nFFF.GH...\n";
str[7][7] = ".......\n.......\n.......\n.......\n....AAA\n.....A.\n.....A.\n";
str[7][7] = ".......\n.......\n.......\n.......\n..AAA.B\n...ABBB\n...A..B\n";
str[7][7] = ".......\n.......\n.......\n.......\nAAABCCC\n.A.B.C.\n.ABBBC.\n";
str[7][7] = ".......\n.......\n.......\n.AAABBB\n.CA.DB.\n.CA.DB.\nCCCDDD.\n";
str[7][7] = ".......\n.......\n..AAA.B\nCCCABBB\n.CDA.EB\n.CDDDE.\n..D.EEE\n";
str[7][7] = ".......\n....AAA\nBBB.CA.\n.BCCCA.\nDB.EC.F\nDDDEFFF\nD.EEE.F\n";
str[7][7] = "....AAA\n..BBBA.\nCCCB.AD\n.C.BDDD\nECFFFGD\nEEEF.G.\nE..FGGG\n";
str[7][7] = "AAA.BBB\n.ACCCB.\n.ADCEB.\nDDDCEEE\nF.DGE.H\nFFFGHHH\nF.GGG.H\n";
ans[7][7] = 8;
str[7][7] = "AAA.BBB\n.ACCCB.\n.ADCEB.\nDDDCEEE\nF.DGE.H\nFFFGHHH\nF.GGG.H\n";
str[7][8] = "........\n........\n........\n........\n.....AAA\n......A.\n......A.\n";
str[7][8] = "........\n........\n........\n........\n...AAA.B\n....ABBB\n....A..B\n";
str[7][8] = "........\n........\n........\n........\n.AAABCCC\n..A.B.C.\n..ABBBC.\n";
str[7][8] = "........\n........\n........\n.....AAA\n.BCCCDA.\n.B.C.DA.\nBBBCDDD.\n";
str[7][8] = "........\n........\n.....AAA\n...BBBA.\nCCCDB.AE\n.C.DBEEE\n.CDDD..E\n";
str[7][8] = "........\n........\n...AAA.B\n.CCCABBB\n.DCEA.FB\n.DCEEEF.\nDDDE.FFF\n";
str[7][8] = "........\n.......A\nB.CCCAAA\nBBBCDDDA\nBE.CFDG.\n.EFFFDG.\nEEE.FGGG\n";
str[7][8] = ".....AAA\n.B.CCCA.\n.BBBCDA.\n.B.ECDDD\nFEEEGD.H\nFFFEGHHH\nF..GGG.H\n";
str[7][8] = ".AAA.BBB\n.CADDDB.\n.CA.DEB.\nCCCFDEEE\nGFFFHE.I\nGGGFHIII\nG..HHH.I\n";
ans[7][8] = 9;
str[7][8] = ".AAA.BBB\n.CADDDB.\n.CA.DEB.\nCCCFDEEE\nGFFFHE.I\nGGGFHIII\nG..HHH.I\n";
str[7][9] = ".........\n.........\n.........\n.........\n......AAA\n.......A.\n.......A.\n";
str[7][9] = ".........\n.........\n.........\n.........\n....AAA.B\n.....ABBB\n.....A..B\n";
str[7][9] = ".........\n.........\n.........\n.........\n..AAABCCC\n...A.B.C.\n...ABBBC.\n";
str[7][9] = ".........\n.........\n.........\n.........\nAAABCCC.D\n.A.B.CDDD\n.ABBBC..D\n";
str[7][9] = ".........\n.........\n.........\n...AAABBB\nCCCDA.EB.\n.C.DA.EB.\n.CDDDEEE.\n";
str[7][9] = ".........\n.........\n......AAA\n.BBBCCCA.\n.DB.EC.AF\n.DB.ECFFF\nDDDEEE..F\n";
str[7][9] = ".........\n.........\n.AAAB.CCC\n..ADBBBC.\n.EADBF.CG\n.EDDDFGGG\nEEE.FFF.G\n";
str[7][9] = ".........\n.....ABBB\nC.DDDA.B.\nCCCDAAABE\nCF.DGHEEE\n.FGGGHHHE\nFFF.GH...\n";
str[7][9] = "......AAA\n...BCCCA.\nDDDB.C.AE\n.DBBBCEEE\nFD.GHHHIE\nFFFG.H.I.\nF.GGGHIII\n";
str[7][9] = "..AAA.BBB\nCCCADDDB.\n.C.AEDFB.\nGCEEEDFFF\nGGGHEIF.J\nGHHH.IJJJ\n...HIII.J\n";
ans[7][9] = 10;
str[7][9] = "..AAA.BBB\nCCCADDDB.\n.C.AEDFB.\nGCEEEDFFF\nGGGHEIF.J\nGHHH.IJJJ\n...HIII.J\n";
str[8][8] = "........\n........\n........\n........\n........\n.....AAA\n......A.\n......A.\n";
str[8][8] = "........\n........\n........\n........\n........\n...AAA.B\n....ABBB\n....A..B\n";
str[8][8] = "........\n........\n........\n........\n........\n.AAABCCC\n..A.B.C.\n..ABBBC.\n";
str[8][8] = "........\n........\n........\n........\n.....AAA\n.BCCCDA.\n.B.C.DA.\nBBBCDDD.\n";
str[8][8] = "........\n........\n........\n.....AAA\n...BBBA.\nCCCDB.AE\n.C.DBEEE\n.CDDD..E\n";
str[8][8] = "........\n........\n........\n...AAA.B\n.CCCABBB\n.DCEA.FB\n.DCEEEF.\nDDDE.FFF\n";
str[8][8] = "........\n........\n.......A\nB.CCCAAA\nBBBCDDDA\nBE.CFDG.\n.EFFFDG.\nEEE.FGGG\n";
str[8][8] = "........\n.....AAA\n.B.CCCA.\n.BBBCDA.\n.B.ECDDD\nFEEEGD.H\nFFFEGHHH\nF..GGG.H\n";
str[8][8] = "........\n.AAA.BBB\n.CADDDB.\n.CA.DEB.\nCCCFDEEE\nGFFFHE.I\nGGGFHIII\nG..HHH.I\n";
str[8][8] = "...AAA.B\n.CCCABBB\n.DCEA.FB\n.DCEEEF.\nDDDEGFFF\nHHHIGGGJ\n.H.IGJJJ\n.HIII..J\n";
ans[8][8] = 10;
str[8][8] = "...AAA.B\n.CCCABBB\n.DCEA.FB\n.DCEEEF.\nDDDEGFFF\nHHHIGGGJ\n.H.IGJJJ\n.HIII..J\n";
ans[8][9] = 12;
str[8][9] = "...ABBB.C\nDAAAEBCCC\nDDDAEBF.C\nD.GEEEFFF\nGGGHHHF.I\nJ.GKHLIII\nJJJKHLLLI\nJ.KKKL...\n";
ans[9][9] = 12;
str[9][9] = ".........\n...ABBB.C\nDAAAEBCCC\nDDDAEBF.C\nD.GEEEFFF\nGGGHHHF.I\nJ.GKHLIII\nJJJKHLLLI\nJ.KKKL...\n";
ans[9][9] = 13;
str[9][9] = "...AAA..B\nCCCDAEBBB\n.C.DAEEEB\nFCDDDEGGG\nFFFHHHIG.\nFJJJH.IG.\n.KJLHIIIM\n.KJLLLMMM\nKKKL....M\n";

    if (n <= m) {
        printf("%d\n%s", ans[n][m], str[n][m].c_str());
        return 0;
    } else {
        int k = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n + 1; ++j)
                tmp[i][j] = str[m][n][k++];
        printf("%d\n", ans[m][n]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                printf("%c", tmp[j][i]);
            printf("\n");
        }
    }
    return 0;
}
