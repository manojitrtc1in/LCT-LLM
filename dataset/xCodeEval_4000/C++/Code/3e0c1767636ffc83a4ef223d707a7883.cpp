

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int ans[10][10];
vector<string> grid[10][10];


int main(void) {
    ans[1][1] = 0;
    grid[1][1] = {
    {"."}};
    ans[1][2] = 0;
    grid[1][2] = {
    {".."}};
    ans[1][3] = 0;
    grid[1][3] = {
    {"..."}};
    ans[1][4] = 0;
    grid[1][4] = {
    {"...."}};
    ans[1][5] = 0;
    grid[1][5] = {
    {"....."}};
    ans[1][6] = 0;
    grid[1][6] = {
    {"......"}};
    ans[1][7] = 0;
    grid[1][7] = {
    {"......."}};
    ans[1][8] = 0;
    grid[1][8] = {
    {"........"}};
    ans[1][9] = 0;
    grid[1][9] = {
    {"........."}};
    ans[2][1] = 0;
    grid[2][1] = {
    {"."},
    {"."}};
    ans[2][2] = 0;
    grid[2][2] = {
    {".."},
    {".."}};
    ans[2][3] = 0;
    grid[2][3] = {
    {"..."},
    {"..."}};
    ans[2][4] = 0;
    grid[2][4] = {
    {"...."},
    {"...."}};
    ans[2][5] = 0;
    grid[2][5] = {
    {"....."},
    {"....."}};
    ans[2][6] = 0;
    grid[2][6] = {
    {"......"},
    {"......"}};
    ans[2][7] = 0;
    grid[2][7] = {
    {"......."},
    {"......."}};
    ans[2][8] = 0;
    grid[2][8] = {
    {"........"},
    {"........"}};
    ans[2][9] = 0;
    grid[2][9] = {
    {"........."},
    {"........."}};
    ans[3][1] = 0;
    grid[3][1] = {
    {"."},
    {"."},
    {"."}};
    ans[3][2] = 0;
    grid[3][2] = {
    {".."},
    {".."},
    {".."}};
    ans[3][3] = 1;
    grid[3][3] = {
    {"AAA"},
    {".A."},
    {".A."}};
    ans[3][4] = 1;
    grid[3][4] = {
    {"AAA."},
    {".A.."},
    {".A.."}};
    ans[3][5] = 2;
    grid[3][5] = {
    {"AAA.B"},
    {".ABBB"},
    {".A..B"}};
    ans[3][6] = 2;
    grid[3][6] = {
    {"AAA.B."},
    {".ABBB."},
    {".A..B."}};
    ans[3][7] = 3;
    grid[3][7] = {
    {"AAABCCC"},
    {".A.B.C."},
    {".ABBBC."}};
    ans[3][8] = 3;
    grid[3][8] = {
    {"AAA.BCCC"},
    {".ABBB.C."},
    {".A..B.C."}};
    ans[3][9] = 4;
    grid[3][9] = {
    {"AAABCCC.D"},
    {".A.B.CDDD"},
    {".ABBBC..D"}};
    ans[4][1] = 0;
    grid[4][1] = {
    {"."},
    {"."},
    {"."},
    {"."}};
    ans[4][2] = 0;
    grid[4][2] = {
    {".."},
    {".."},
    {".."},
    {".."}};
    ans[4][3] = 1;
    grid[4][3] = {
    {"AAA"},
    {".A."},
    {".A."},
    {"..."}};
    ans[4][4] = 2;
    grid[4][4] = {
    {"AAA."},
    {".AB."},
    {".AB."},
    {".BBB"}};
    ans[4][5] = 2;
    grid[4][5] = {
    {"AAA.B"},
    {".ABBB"},
    {".A..B"},
    {"....."}};
    ans[4][6] = 3;
    grid[4][6] = {
    {"AAABBB"},
    {".AC.B."},
    {".AC.B."},
    {".CCC.."}};
    ans[4][7] = 4;
    grid[4][7] = {
    {"AAABBB."},
    {".AC.BD."},
    {".AC.BD."},
    {".CCCDDD"}};
    ans[4][8] = 4;
    grid[4][8] = {
    {"AAA.BCCC"},
    {".ABBBDC."},
    {".A..BDC."},
    {"....DDD."}};
    ans[4][9] = 5;
    grid[4][9] = {
    {"AAABBBCCC"},
    {".AD.BE.C."},
    {".AD.BE.C."},
    {".DDDEEE.."}};
    ans[5][1] = 0;
    grid[5][1] = {
    {"."},
    {"."},
    {"."},
    {"."},
    {"."}};
    ans[5][2] = 0;
    grid[5][2] = {
    {".."},
    {".."},
    {".."},
    {".."},
    {".."}};
    ans[5][3] = 2;
    grid[5][3] = {
    {"AAA"},
    {".A."},
    {".AB"},
    {"BBB"},
    {"..B"}};
    ans[5][4] = 2;
    grid[5][4] = {
    {"AAA."},
    {".AB."},
    {".AB."},
    {".BBB"},
    {"...."}};
    ans[5][5] = 4;
    grid[5][5] = {
    {"AAA.B"},
    {".ABBB"},
    {"CA.DB"},
    {"CCCD."},
    {"C.DDD"}};
    ans[5][6] = 4;
    grid[5][6] = {
    {"AAA.B."},
    {".ABBB."},
    {".AC.BD"},
    {"CCCDDD"},
    {"..C..D"}};
    ans[5][7] = 5;
    grid[5][7] = {
    {"AAA.B.."},
    {".ABBBC."},
    {"DA.EBC."},
    {"DDDECCC"},
    {"D.EEE.."}};
    ans[5][8] = 6;
    grid[5][8] = {
    {"AAA.BCCC"},
    {".ABBBDC."},
    {"EA.FBDC."},
    {"EEEFDDD."},
    {"E.FFF..."}};
    ans[5][9] = 7;
    grid[5][9] = {
    {"AAA.BCCC."},
    {".ABBBDC.."},
    {"EA.FBDCG."},
    {"EEEFDDDG."},
    {"E.FFF.GGG"}};
    ans[6][1] = 0;
    grid[6][1] = {
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."}};
    ans[6][2] = 0;
    grid[6][2] = {
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."}};
    ans[6][3] = 2;
    grid[6][3] = {
    {"AAA"},
    {".A."},
    {".AB"},
    {"BBB"},
    {"..B"},
    {"..."}};
    ans[6][4] = 3;
    grid[6][4] = {
    {"AAA."},
    {".AB."},
    {".AB."},
    {"CBBB"},
    {"CCC."},
    {"C..."}};
    ans[6][5] = 4;
    grid[6][5] = {
    {"AAA.B"},
    {".ABBB"},
    {".AC.B"},
    {"CCCD."},
    {"..CD."},
    {"..DDD"}};
    ans[6][6] = 5;
    grid[6][6] = {
    {"AAA.B."},
    {".ABBB."},
    {".A.CB."},
    {"DCCCE."},
    {"DDDCE."},
    {"D..EEE"}};
    ans[6][7] = 6;
    grid[6][7] = {
    {"AAABCCC"},
    {".A.B.C."},
    {"DABBBCE"},
    {"DDDFEEE"},
    {"DFFF..E"},
    {"...F..."}};
    ans[6][8] = 7;
    grid[6][8] = {
    {"AAA.BCCC"},
    {".ABBBDC."},
    {".AE.BDC."},
    {"EEEFDDDG"},
    {"..EF.GGG"},
    {"..FFF..G"}};
    ans[6][9] = 8;
    grid[6][9] = {
    {"AAA.BCCC."},
    {".ABBB.C.."},
    {".A.DBEC.."},
    {"FDDDGEEEH"},
    {"FFFDGEHHH"},
    {"F..GGG..H"}};
    ans[7][1] = 0;
    grid[7][1] = {
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."}};
    ans[7][2] = 0;
    grid[7][2] = {
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."}};
    ans[7][3] = 3;
    grid[7][3] = {
    {"AAA"},
    {".A."},
    {".AB"},
    {"BBB"},
    {".CB"},
    {".C."},
    {"CCC"}};
    ans[7][4] = 4;
    grid[7][4] = {
    {"AAA."},
    {".AB."},
    {".AB."},
    {"CBBB"},
    {"CCCD"},
    {"CDDD"},
    {"...D"}};
    ans[7][5] = 5;
    grid[7][5] = {
    {"AAA.B"},
    {".ABBB"},
    {".AC.B"},
    {"CCCD."},
    {".ECD."},
    {".EDDD"},
    {"EEE.."}};
    ans[7][6] = 6;
    grid[7][6] = {
    {"AAA.B."},
    {".ABBB."},
    {".AC.BD"},
    {"CCCDDD"},
    {".EC.FD"},
    {".EFFF."},
    {"EEE.F."}};
    ans[7][7] = 8;
    grid[7][7] = {
    {"AAABCCC"},
    {".A.B.C."},
    {"DABBBCE"},
    {"DDDFEEE"},
    {"DG.F.HE"},
    {".GFFFH."},
    {"GGG.HHH"}};
    ans[7][8] = 9;
    grid[7][8] = {
    {"AAA.BBB."},
    {".ACCCBD."},
    {".AEC.BD."},
    {"EEECFDDD"},
    {"G.EHFFFI"},
    {"GGGHFIII"},
    {"G.HHH..I"}};
    ans[7][9] = 10;
    grid[7][9] = {
    {"AAA.BC..."},
    {".ABBBCCCD"},
    {"EA.FBCDDD"},
    {"EEEF.GGGD"},
    {"EHFFFIGJ."},
    {".H.IIIGJ."},
    {"HHH..IJJJ"}};
    ans[8][1] = 0;
    grid[8][1] = {
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."}};
    ans[8][2] = 0;
    grid[8][2] = {
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."}};
    ans[8][3] = 3;
    grid[8][3] = {
    {"AAA"},
    {".A."},
    {".AB"},
    {"BBB"},
    {".CB"},
    {".C."},
    {"CCC"},
    {"..."}};
    ans[8][4] = 4;
    grid[8][4] = {
    {"AAA."},
    {".AB."},
    {".AB."},
    {"CBBB"},
    {"CCCD"},
    {"CDDD"},
    {"...D"},
    {"...."}};
    ans[8][5] = 6;
    grid[8][5] = {
    {"AAA.B"},
    {".ABBB"},
    {"CA.DB"},
    {"CCCD."},
    {"CEDDD"},
    {".EFFF"},
    {"EEEF."},
    {"...F."}};
    ans[8][6] = 7;
    grid[8][6] = {
    {"AAA.B."},
    {".ABBB."},
    {".AC.BD"},
    {"CCCDDD"},
    {"..CE.D"},
    {"FEEEG."},
    {"FFFEG."},
    {"F..GGG"}};
    ans[8][7] = 9;
    grid[8][7] = {
    {"AAAB..C"},
    {".A.BCCC"},
    {"DABBBEC"},
    {"DDDEEE."},
    {"DFFF.EG"},
    {".HFIGGG"},
    {".HFIIIG"},
    {"HHHI..."}};
    ans[8][8] = 10;
    grid[8][8] = {
    {"AAA.BCCC"},
    {".ABBBDC."},
    {"EA.FBDC."},
    {"EEEFDDDG"},
    {"EHFFFGGG"},
    {".HIII.JG"},
    {"HHHIJJJ."},
    {"...I..J."}};
    ans[8][9] = 12;
    grid[8][9] = {
    {"AAABBB..C"},
    {".AD.BECCC"},
    {".AD.BEEEC"},
    {"FDDDGEHHH"},
    {"FFFIGGGH."},
    {"FJ.IGK.HL"},
    {".JIIIKLLL"},
    {"JJJ.KKK.L"}};
    ans[9][1] = 0;
    grid[9][1] = {
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."},
    {"."}};
    ans[9][2] = 0;
    grid[9][2] = {
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."},
    {".."}};
    ans[9][3] = 4;
    grid[9][3] = {
    {"AAA"},
    {".A."},
    {".AB"},
    {"BBB"},
    {"C.B"},
    {"CCC"},
    {"C.D"},
    {"DDD"},
    {"..D"}};
    ans[9][4] = 5;
    grid[9][4] = {
    {"AAA."},
    {".AB."},
    {".AB."},
    {"CBBB"},
    {"CCCD"},
    {"CDDD"},
    {"EEED"},
    {".E.."},
    {".E.."}};
    ans[9][5] = 7;
    grid[9][5] = {
    {"AAA.B"},
    {".ABBB"},
    {"CA.DB"},
    {"CCCD."},
    {"CEDDD"},
    {".EEEF"},
    {"GEFFF"},
    {"GGG.F"},
    {"G...."}};
    ans[9][6] = 8;
    grid[9][6] = {
    {"AAA.B."},
    {".ABBB."},
    {".AC.BD"},
    {"CCCDDD"},
    {"E.CF.D"},
    {"EEEF.."},
    {"EGFFFH"},
    {".G.HHH"},
    {"GGG..H"}};
    ans[9][7] = 10;
    grid[9][7] = {
    {"AAA.B.."},
    {".ABBBC."},
    {".AD.BC."},
    {"DDDECCC"},
    {"F.DEEEG"},
    {"FFFEGGG"},
    {"FHIIIJG"},
    {".H.I.J."},
    {"HHHIJJJ"}};
    ans[9][8] = 12;
    grid[9][8] = {
    {"AAA.BCCC"},
    {".ABBBDC."},
    {"EA.FBDC."},
    {"EEEFDDDG"},
    {"EHFFFGGG"},
    {".HHHIIIG"},
    {"JHKKKIL."},
    {"JJJK.IL."},
    {"J..K.LLL"}};
    ans[9][9] = 13;
    grid[9][9] = {
    {"AAA.BCCC."},
    {".ABBB.CD."},
    {".AE.BFCD."},
    {"EEEFFFDDD"},
    {"G.E.HFIII"},
    {"GGGJHHHI."},
    {"GK.JHL.IM"},
    {".KJJJLMMM"},
    {"KKK.LLL.M"}};
    int n, m;

    scanf(" %d %d", &n, &m);
    printf("%d\n", ans[n][m]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", grid[n][m][i][j]);
        }
        printf("\n");
    }
    return 0;
}
