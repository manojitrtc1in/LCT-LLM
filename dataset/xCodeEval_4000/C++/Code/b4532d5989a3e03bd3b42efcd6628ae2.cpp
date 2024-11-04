#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define clr(x) memset((x),0,sizeof(x))

const int MX = 1e5 + 10, MD = 1e9 + 7;
ll n, m, a[MX], ans, tmp, f;
int main(){
    ios::sync_with_stdio(0) ; cin.tie(0) ;
    cin >> n >> m;
    char mat[n][m];
    if(n > m){
        swap(n, m);
        f = 1;
    }
    if(n <= 2){
        cout << 0 << endl;
        if(f == 0){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << '.';
                }
                cout << endl;
            }
        }
        else{
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cout << '.';
                }
                cout << endl;
            }
        }
    }
    if(n == 3){
        cout << (m - 1) / 2 << endl;
        if(m == 3){
            mat[0][0] = 'A';mat[0][1] = 'A';mat[0][2] = 'A';mat[1][0] = '.';mat[1][1] = 'A';mat[1][2] = '.';mat[2][0] = '.';mat[2][1] = 'A';mat[2][2] = '.';
        }
        else if(m == 4){
            mat[0][0] = 'A';mat[0][1] = 'A';mat[0][2] = 'A';mat[1][0] = '.';mat[1][1] = 'A';mat[1][2] = '.';mat[2][0] = '.';mat[2][1] = 'A';mat[2][2] = '.';mat[0][3] = '.';mat[1][3] = '.';mat[2][3] = '.';
        }
        else if(m == 5){
            mat[0][0] = 'A';mat[0][1] = 'A';mat[0][2] = 'A';mat[1][0] = '.';mat[1][1] = 'A';mat[1][2] = '.';mat[2][0] = '.';mat[2][1] = 'A';mat[2][2] = 'B';mat[0][3] = 'B';mat[1][3] = 'B';mat[2][3] = 'B';mat[0][4] = '.';mat[1][4] = '.';mat[2][4] = 'B';
        }
        else if(m == 6){
            mat[0][0] = 'A';mat[0][1] = 'A';mat[0][2] = 'A';mat[1][0] = '.';mat[1][1] = 'A';mat[1][2] = '.';mat[2][0] = '.';mat[2][1] = 'A';mat[2][2] = 'B';mat[0][3] = 'B';mat[1][3] = 'B';mat[2][3] = 'B';mat[0][4] = '.';mat[1][4] = '.';mat[2][4] = 'B';mat[0][5] = '.';mat[1][5] = '.';mat[2][5] = '.';
        }
        else if(m == 7){
            mat[0][0] = 'A';mat[0][1] = 'A';mat[0][2] = 'A';mat[1][0] = '.';mat[1][1] = 'A';mat[1][2] = '.';mat[2][0] = '.';mat[2][1] = 'A';mat[2][2] = 'B';mat[0][3] = 'B';mat[1][3] = 'B';mat[2][3] = 'B';mat[0][4] = 'C';mat[1][4] = '.';mat[2][4] = 'B';mat[0][5] = 'C';mat[1][5] = 'C';mat[2][5] = 'C';mat[0][6] = 'C';mat[1][6] = '.';mat[2][6] = '.';
        }
        else if(m == 8){
            mat[0][0] = 'A';mat[0][1] = 'A';mat[0][2] = 'A';mat[1][0] = '.';mat[1][1] = 'A';mat[1][2] = '.';mat[2][0] = '.';mat[2][1] = 'A';mat[2][2] = 'B';mat[0][3] = 'B';mat[1][3] = 'B';mat[2][3] = 'B';mat[0][4] = 'C';mat[1][4] = '.';mat[2][4] = 'B';mat[0][5] = 'C';mat[1][5] = 'C';mat[2][5] = 'C';mat[0][6] = 'C';mat[1][6] = '.';mat[2][6] = '.';mat[0][7] = '.';mat[1][7] = '.';mat[2][7] = '.';
        }
        else if(m == 9){
            mat[0][0] = 'A';mat[0][1] = 'A';mat[0][2] = 'A';mat[1][0] = '.';mat[1][1] = 'A';mat[1][2] = '.';mat[2][0] = '.';mat[2][1] = 'A';mat[2][2] = 'B';mat[0][3] = 'B';mat[1][3] = 'B';mat[2][3] = 'B';mat[0][4] = 'C';mat[1][4] = '.';mat[2][4] = 'B';mat[0][5] = 'C';mat[1][5] = 'C';mat[2][5] = 'C';mat[0][6] = 'C';mat[1][6] = '.';mat[2][6] = 'D';mat[0][7] = 'D';mat[1][7] = 'D';mat[2][7] = 'D';mat[0][8] = '.';mat[1][8] = '.';mat[2][8] = 'D';
        }
        if(f == 0){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << mat[i][j];
                }
                cout << endl;
            }
        }
        else{
            if(m == 4){
                cout << "A.." << endl;
                cout << "AAA" << endl;
                cout << "A.." << endl;
                cout << "..." << endl;
            }
            if(m == 5){
                cout << "A.." << endl;
                cout << "AAA" << endl;
                cout << "A.B" << endl;
                cout << "BBB" << endl;
                cout << "..B" << endl;
            }
            if(m == 6){
                cout << "A.." << endl;
                cout << "AAA" << endl;
                cout << "A.B" << endl;
                cout << "BBB" << endl;
                cout << "..B" << endl;
                cout << "..." << endl;
            }
            if(m == 7){
                cout << "A.." << endl;
                cout << "AAA" << endl;
                cout << "A.B" << endl;
                cout << "BBB" << endl;
                cout << "C.B" << endl;
                cout << "CCC" << endl;
                cout << "C.." << endl;

            }
            if(m == 8){
                cout << "A.." << endl;
                cout << "AAA" << endl;
                cout << "A.B" << endl;
                cout << "BBB" << endl;
                cout << "C.B" << endl;
                cout << "CCC" << endl;
                cout << "C.." << endl;
                cout << "..." << endl;

            }
            if(m == 9){
                cout << "A.." << endl;
                cout << "AAA" << endl;
                cout << "A.B" << endl;
                cout << "BBB" << endl;
                cout << "C.B" << endl;
                cout << "CCC" << endl;
                cout << "C.D" << endl;
                cout << "DDD" << endl;
                cout << "..D" << endl;
            }

        }

    }
    if(f == 1){
        swap(n, m);
    }
    if(n == 4){
        if(m == 4){
            cout << 2 << endl;
            cout << "AAA." << endl;
            cout << ".AB." << endl;
            cout << ".AB." << endl;
            cout << ".BBB" << endl;
        }
        if(m == 5){
            cout << 2 << endl;
            cout << "AAA.." << endl;
            cout << ".AB.." << endl;
            cout << ".AB.." << endl;
            cout << ".BBB." << endl;
        }
        if(m == 6){
            cout << 3 << endl;
            cout << "AAA.C." << endl;
            cout << ".AB.C." << endl;
            cout << ".ABCCC" << endl;
            cout << ".BBB.." << endl;
        }
        if(m == 7){
            cout << 4 << endl;
            cout << "AAACCC." << endl;
            cout << ".AB.CD." << endl;
            cout << ".AB.CD." << endl;
            cout << ".BBBDDD" << endl;
        }
        if(m == 8){
            cout << 4 << endl;
            cout << "AAACCC.." << endl;
            cout << ".AB.CD.." << endl;
            cout << ".AB.CD.." << endl;
            cout << ".BBBDDD." << endl;
        }
        if(m == 9){
            cout << 5 << endl;
            cout << "AAACCC.E." << endl;
            cout << ".AB.CD.E." << endl;
            cout << ".AB.CDEEE" << endl;
            cout << ".BBBDDD.." << endl;
        }

    }
    if(n == 5){
        if(m == 4){
            cout << 2 << endl;
            cout << "AAA." << endl;
            cout << ".AB." << endl;
            cout << ".AB." << endl;
            cout << ".BBB" << endl;
            cout << "...." << endl;

        }
        if(m == 5){
            cout << 4 << endl;
            cout << "AAA.C" << endl;
            cout << ".ACCC" << endl;
            cout << "BA.DC" << endl;
            cout << "BBBD." << endl;
            cout << "B.DDD" << endl;

        }
        if(m == 6){
            cout << 4 << endl;
            cout << "AAA.C." << endl;
            cout << ".ACCC." << endl;
            cout << "BA.DC." << endl;
            cout << "BBBD.." << endl;
            cout << "B.DDD." << endl;
        }
        if(m == 7){
            cout << 5 << endl;
            cout << "AAA.C.." << endl;
            cout << ".ACCC.." << endl;
            cout << "BA.DC.E" << endl;
            cout << "BBBDEEE" << endl;
            cout << "B.DDD.E" << endl;
        }
        if(m == 8){
            cout << 6 << endl;
            cout << "AAA.C..F" << endl;
            cout << ".ACCCFFF" << endl;
            cout << "BA.DC.EF" << endl;
            cout << "BBBDEEE." << endl;
            cout << "B.DDD.E." << endl;
        }
        if(m == 9){
            cout << 7 << endl;
            cout << "A.BBB.CCC" << endl;
            cout << "AAABDDDC." << endl;
            cout << "A.EBFDGC." << endl;
            cout << "EEE.FDGGG" << endl;
            cout << "..EFFFG.." << endl;
        }

    }
    if(n == 6){
        if(m == 4){
            cout << 3 << endl;
            cout << "AAA." << endl;
            cout << ".AB." << endl;
            cout << ".AB." << endl;
            cout << "CBBB" << endl;
            cout << "CCC." << endl;
            cout << "C..." << endl;
        }
        if(m == 5){
            cout << 4 << endl;
            cout << "AAAB." << endl;
            cout << ".A.B." << endl;
            cout << ".ABBB" << endl;
            cout << "C..D." << endl;
            cout << "CCCD." << endl;
            cout << "C.DDD" << endl;
        }
        if(m == 6){
            cout << 5 << endl;
            cout << "AAABBB" << endl;
            cout << ".AC.B." << endl;
            cout << ".AC.B." << endl;
            cout << "DCCC.E" << endl;
            cout << "DDDEEE" << endl;
            cout << "D....E" << endl;

        }
        if(m == 7){
            cout << 6 << endl;
            cout << "AAACBBB" << endl;
            cout << ".A.C.B." << endl;
            cout << "DACCCBE" << endl;
            cout << "DDDFEEE" << endl;
            cout << "D..F..E" << endl;
            cout << "..FFF.." << endl;
        }
        if(m == 8){
            cout << 7 << endl;
            cout << "AAACCCB." << endl;
            cout << ".AD.C.B." << endl;
            cout << ".AD.CBBB" << endl;
            cout << "EDDDG..F" << endl;
            cout << "EEE.GFFF" << endl;
            cout << "E..GGG.F" << endl;
        }
        if(m == 9){
            cout << 8 << endl;
            cout << "AAADDDEEE" << endl;
            cout << ".AC.D.GE." << endl;
            cout << ".AC.D.GE." << endl;
            cout << "BCCCHGGGF" << endl;
            cout << "BBB.H.FFF" << endl;
            cout << "B..HHH..F" << endl;
        }

    }
    if(n == 7){
        if(m == 4){
            cout << 4 << endl;
            cout << "AAA." << endl;
            cout << ".AB." << endl;
            cout << ".AB." << endl;
            cout << "CBBB" << endl;
            cout << "CCCD" << endl;
            cout << "CDDD" << endl;
            cout << "...D" << endl;
        }
        if(m == 5){
            cout << 5 << endl;
            cout << "AAAB." << endl;
            cout << ".A.B." << endl;
            cout << "CABBB" << endl;
            cout << "CCCD." << endl;
            cout << "CE.D." << endl;
            cout << ".EDDD" << endl;
            cout << "EEE.." << endl;
        }
        if(m == 6){
            cout << 6 << endl;
            cout << "AAABBB" << endl;
            cout << ".A..B." << endl;
            cout << "CA.DB." << endl;
            cout << "CCCD.." << endl;
            cout << "CEDDDF" << endl;
            cout << ".E.FFF" << endl;
            cout << "EEE..F" << endl;
        }
        if(m == 7){
            cout << 8 << endl;
            cout << "AAABCCC" << endl;
            cout << ".A.B.C." << endl;
            cout << "DABBBCE" << endl;
            cout << "DDDFEEE" << endl;
            cout << "DG.F.HE" << endl;
            cout << ".GFFFH." << endl;
            cout << "GGG.HHH" << endl;
        }
        if(m == 8){
            cout << 9 << endl;
            cout << "AAA.BBB." << endl;
            cout << ".ACCCBD." << endl;
            cout << ".AEC.BD." << endl;
            cout << "EEECFDDD" << endl;
            cout << "G.EHFFFI" << endl;
            cout << "GGGHFIII" << endl;
            cout << "G.HHH..I" << endl;
        }
        if(m == 9){
            cout << 10 << endl;
            cout << "AAABCCC.D" << endl;
            cout << ".A.B.CDDD" << endl;
            cout << "EABBBCF.D" << endl;
            cout << "EEEGFFFH." << endl;
            cout << "EI.G.JFH." << endl;
            cout << ".IGGGJHHH" << endl;
            cout << "III.JJJ.." << endl;
        }

    }
    if(n == 8){
        if(m == 4){
            cout << 4 << endl;
            cout << "AAA." << endl;
            cout << ".AB." << endl;
            cout << ".AB." << endl;
            cout << "CBBB" << endl;
            cout << "CCCD" << endl;
            cout << "CDDD" << endl;
            cout << "...D" << endl;
            cout << "...." << endl;
        }
        if(m == 5){
            cout << 6 << endl;
            cout << "AAAB." << endl;
            cout << ".A.B." << endl;
            cout << "CABBB" << endl;
            cout << "CCCD." << endl;
            cout << "CDDD." << endl;
            cout << "EEEDF" << endl;
            cout << ".EFFF" << endl;
            cout << ".E..F" << endl;
        }
        if(m == 6){
            cout << 7 << endl;
            cout << "AAABBB" << endl;
            cout << ".AC.B." << endl;
            cout << ".AC.B." << endl;
            cout << "DCCC.E" << endl;
            cout << "DDDEEE" << endl;
            cout << "DFFFGE" << endl;
            cout << "..F.G." << endl;
            cout << "..FGGG" << endl;
        }
        if(m == 7){
            cout << 9 << endl;
            cout << "AAAB..C" << endl;
            cout << ".A.BCCC" << endl;
            cout << "DABBBEC" << endl;
            cout << "DDDEEE." << endl;
            cout << "DFFF.EG" << endl;
            cout << ".HFIGGG" << endl;
            cout << ".HFIIIG" << endl;
            cout << "HHHI..." << endl;
        }
        if(m == 8){
            cout << 10 << endl;
            cout << "AAABBBC." << endl;
            cout << ".A..B.C." << endl;
            cout << "DA..BCCC" << endl;
            cout << "DDDEEE.F" << endl;
            cout << "DGGGEFFF" << endl;
            cout << ".HGIE.JF" << endl;
            cout << ".HGIIIJ." << endl;
            cout << "HHHI.JJJ" << endl;
        }
        if(m == 9){
            cout << 12 << endl;
            cout << "AAABBB..C" << endl;
            cout << ".AD.BECCC" << endl;
            cout << ".AD.BEEEC" << endl;
            cout << "FDDDGEHHH" << endl;
            cout << "FFFIGGGH." << endl;
            cout << "FJ.IGK.HL" << endl;
            cout << ".JIIIKLLL" << endl;
            cout << "JJJ.KKK.L" << endl;
        }

    }
    if(n == 9){
        if(m == 4){
            cout << 5 << endl;
            cout << "AAA." << endl;
            cout << ".AB." << endl;
            cout << ".AB." << endl;
            cout << "CBBB" << endl;
            cout << "CCCD" << endl;
            cout << "CDDD" << endl;
            cout << "EEED" << endl;
            cout << ".E.." << endl;
            cout << ".E.." << endl;

        }
        if(m == 5){
            cout << 7 << endl;
            cout << "AAAB." << endl;
            cout << ".A.B." << endl;
            cout << "CABBB" << endl;
            cout << "CCC.D" << endl;
            cout << "CEDDD" << endl;
            cout << ".EEED" << endl;
            cout << "FEGGG" << endl;
            cout << "FFFG." << endl;
            cout << "F..G." << endl;
        }
        if(m == 6){
            cout << 8 << endl;
            cout << "AAABBB" << endl;
            cout << ".AC.B." << endl;
            cout << ".AC.B." << endl;
            cout << "DCCCE." << endl;
            cout << "DDD.E." << endl;
            cout << "D.FEEE" << endl;
            cout << ".GFFFH" << endl;
            cout << ".GFHHH" << endl;
            cout << "GGG..H" << endl;
        }
        if(m == 7){
            cout << 10 << endl;
            cout << "AAABBB." << endl;
            cout << ".A..BC." << endl;
            cout << "DA.EBC." << endl;
            cout << "DDDECCC" << endl;
            cout << "DFEEE.G" << endl;
            cout << ".FFFGGG" << endl;
            cout << "HFIIIJG" << endl;
            cout << "HHHI.J." << endl;
            cout << "H..IJJJ" << endl;
        }
        if(m == 8){
            cout << 12 << endl;
            cout << "AAABBB.C" << endl;
            cout << ".AD.BCCC" << endl;
            cout << ".AD.B.EC" << endl;
            cout << "FDDDEEE." << endl;
            cout << "FFFGGGEH" << endl;
            cout << "FIIIGHHH" << endl;
            cout << ".JIKG.LH" << endl;
            cout << ".JIKKKL." << endl;
            cout << "JJJK.LLL" << endl;
        }
        if(m == 9){
            cout << 13 << endl;
            cout << "AAABBBCCC" << endl;
            cout << ".AD.BE.C." << endl;
            cout << ".AD.BE.C." << endl;
            cout << "FDDDEEE.G" << endl;
            cout << "FFFHHHGGG" << endl;
            cout << "FIIIHJJJG" << endl;
            cout << ".KILH.JM." << endl;
            cout << ".KILLLJM." << endl;
            cout << "KKKL..MMM" << endl;
        }

    }

}


