


using namespace std;

map<pair<int, int>, pair<int, vector<string>>> mp;
int main() {
    mp[make_pair(1,1)] = make_pair(0,
        vector<string>{
            "."
        }
    );

    mp[make_pair(1,2)] = make_pair(0,
        vector<string>{
            ".."
        }
    );

    mp[make_pair(1,3)] = make_pair(0,
        vector<string>{
            "..."
        }
    );

    mp[make_pair(1,4)] = make_pair(0,
        vector<string>{
            "...."
        }
    );

    mp[make_pair(1,5)] = make_pair(0,
        vector<string>{
            "....."
        }
    );

    mp[make_pair(1,6)] = make_pair(0,
        vector<string>{
            "......"
        }
    );

    mp[make_pair(1,7)] = make_pair(0,
        vector<string>{
            "......."
        }
    );

    mp[make_pair(1,8)] = make_pair(0,
        vector<string>{
            "........"
        }
    );

    mp[make_pair(1,9)] = make_pair(0,
        vector<string>{
            "........."
        }
    );

    mp[make_pair(2,1)] = make_pair(0,
        vector<string>{
            ".",
            "."
        }
    );

    mp[make_pair(2,2)] = make_pair(0,
        vector<string>{
            "..",
            ".."
        }
    );

    mp[make_pair(2,3)] = make_pair(0,
        vector<string>{
            "...",
            "..."
        }
    );

    mp[make_pair(2,4)] = make_pair(0,
        vector<string>{
            "....",
            "...."
        }
    );

    mp[make_pair(2,5)] = make_pair(0,
        vector<string>{
            ".....",
            "....."
        }
    );

    mp[make_pair(2,6)] = make_pair(0,
        vector<string>{
            "......",
            "......"
        }
    );

    mp[make_pair(2,7)] = make_pair(0,
        vector<string>{
            ".......",
            "......."
        }
    );

    mp[make_pair(2,8)] = make_pair(0,
        vector<string>{
            "........",
            "........"
        }
    );

    mp[make_pair(2,9)] = make_pair(0,
        vector<string>{
            ".........",
            "........."
        }
    );

    mp[make_pair(3,1)] = make_pair(0,
        vector<string>{
            ".",
            ".",
            "."
        }
    );

    mp[make_pair(3,2)] = make_pair(0,
        vector<string>{
            "..",
            "..",
            ".."
        }
    );

    mp[make_pair(3,3)] = make_pair(1,
        vector<string>{
            "AAA",
            ".A.",
            ".A."
        }
    );

    mp[make_pair(3,4)] = make_pair(1,
        vector<string>{
            "AAA.",
            ".A..",
            ".A.."
        }
    );

    mp[make_pair(3,5)] = make_pair(2,
        vector<string>{
            "AAA.B",
            ".ABBB",
            ".A..B"
        }
    );

    mp[make_pair(3,6)] = make_pair(2,
        vector<string>{
            "AAABBB",
            ".A..B.",
            ".A..B."
        }
    );

    mp[make_pair(3,7)] = make_pair(3,
        vector<string>{
            "AAACBBB",
            ".A.C.B.",
            ".ACCCB."
        }
    );

    mp[make_pair(3,8)] = make_pair(3,
        vector<string>{
            "AAABBB.C",
            ".A..BCCC",
            ".A..B..C"
        }
    );

    mp[make_pair(3,9)] = make_pair(4,
        vector<string>{
            "AAADBBB.C",
            ".A.D.BCCC",
            ".ADDDB..C"
        }
    );

    mp[make_pair(4,1)] = make_pair(0,
        vector<string>{
            ".",
            ".",
            ".",
            "."
        }
    );

    mp[make_pair(4,2)] = make_pair(0,
        vector<string>{
            "..",
            "..",
            "..",
            ".."
        }
    );

    mp[make_pair(4,3)] = make_pair(1,
        vector<string>{
            "AAA",
            ".A.",
            ".A.",
            "..."
        }
    );

    mp[make_pair(4,4)] = make_pair(2,
        vector<string>{
            "AAA.",
            ".AB.",
            ".AB.",
            ".BBB"
        }
    );

    mp[make_pair(4,5)] = make_pair(2,
        vector<string>{
            "AAA..",
            ".ABBB",
            ".A.B.",
            "...B."
        }
    );

    mp[make_pair(4,6)] = make_pair(3,
        vector<string>{
            "AAABBB",
            ".AC.B.",
            ".AC.B.",
            ".CCC.."
        }
    );

    mp[make_pair(4,7)] = make_pair(4,
        vector<string>{
            "AAAB...",
            ".ADBBBC",
            ".ADBCCC",
            ".DDD..C"
        }
    );

    mp[make_pair(4,8)] = make_pair(4,
        vector<string>{
            "AAABBB..",
            ".AD.BCCC",
            ".AD.B.C.",
            ".DDD..C."
        }
    );

    mp[make_pair(4,9)] = make_pair(5,
        vector<string>{
            "AAABBBCCC",
            ".AD.BE.C.",
            ".AD.BE.C.",
            ".DDDEEE.."
        }
    );

    mp[make_pair(5,1)] = make_pair(0,
        vector<string>{
            ".",
            ".",
            ".",
            ".",
            "."
        }
    );

    mp[make_pair(5,2)] = make_pair(0,
        vector<string>{
            "..",
            "..",
            "..",
            "..",
            ".."
        }
    );

    mp[make_pair(5,3)] = make_pair(2,
        vector<string>{
            "AAA",
            ".A.",
            "BA.",
            "BBB",
            "B.."
        }
    );

    mp[make_pair(5,4)] = make_pair(2,
        vector<string>{
            "AAA.",
            ".A..",
            "BA..",
            "BBB.",
            "B..."
        }
    );

    mp[make_pair(5,5)] = make_pair(4,
        vector<string>{
            "AAA.B",
            ".ABBB",
            "CA.DB",
            "CCCD.",
            "C.DDD"
        }
    );

    mp[make_pair(5,6)] = make_pair(4,
        vector<string>{
            "AAABBB",
            ".A..B.",
            "CA.DB.",
            "CCCDDD",
            "C..D.."
        }
    );

    mp[make_pair(5,7)] = make_pair(5,
        vector<string>{
            "AAABBB.",
            ".A..BD.",
            "CA.EBD.",
            "CCCEDDD",
            "C.EEE.."
        }
    );

    mp[make_pair(5,8)] = make_pair(6,
        vector<string>{
            "AAABBB.C",
            ".A..BCCC",
            "DA.EB.FC",
            "DDDEEEF.",
            "D..E.FFF"
        }
    );

    mp[make_pair(5,9)] = make_pair(7,
        vector<string>{
            "AAABBBC..",
            ".A..BECCC",
            "DA.FBECG.",
            "DDDFEEEG.",
            "D.FFF.GGG"
        }
    );

    mp[make_pair(6,1)] = make_pair(0,
        vector<string>{
            ".",
            ".",
            ".",
            ".",
            ".",
            "."
        }
    );

    mp[make_pair(6,2)] = make_pair(0,
        vector<string>{
            "..",
            "..",
            "..",
            "..",
            "..",
            ".."
        }
    );

    mp[make_pair(6,3)] = make_pair(2,
        vector<string>{
            "AAA",
            ".A.",
            "BA.",
            "BBB",
            "B..",
            "..."
        }
    );

    mp[make_pair(6,4)] = make_pair(3,
        vector<string>{
            "AAA.",
            ".A..",
            "BA..",
            "BBBC",
            "BCCC",
            "...C"
        }
    );

    mp[make_pair(6,5)] = make_pair(4,
        vector<string>{
            "AAA..",
            ".ABBB",
            "CA.B.",
            "CCCBD",
            "C.DDD",
            "....D"
        }
    );

    mp[make_pair(6,6)] = make_pair(5,
        vector<string>{
            "AAABBB",
            ".AC.B.",
            ".AC.B.",
            "DCCC.E",
            "DDDEEE",
            "D....E"
        }
    );

    mp[make_pair(6,7)] = make_pair(6,
        vector<string>{
            "AAA.BBB",
            ".AC..B.",
            ".ACCCB.",
            "E.CFDDD",
            "EEEF.D.",
            "E.FFFD."
        }
    );

    mp[make_pair(6,8)] = make_pair(7,
        vector<string>{
            "AAABBB..",
            ".AD.BCCC",
            ".AD.B.C.",
            "EDDDG.CF",
            "EEE.GFFF",
            "E..GGG.F"
        }
    );

    mp[make_pair(6,9)] = make_pair(8,
        vector<string>{
            "AAABBBCCC",
            ".AD.B..C.",
            ".AD.BE.C.",
            "FDDDHEEEG",
            "FFF.HEGGG",
            "F..HHH..G"
        }
    );

    mp[make_pair(7,1)] = make_pair(0,
        vector<string>{
            ".",
            ".",
            ".",
            ".",
            ".",
            ".",
            "."
        }
    );

    mp[make_pair(7,2)] = make_pair(0,
        vector<string>{
            "..",
            "..",
            "..",
            "..",
            "..",
            "..",
            ".."
        }
    );

    mp[make_pair(7,3)] = make_pair(3,
        vector<string>{
            "AAA",
            ".A.",
            "BA.",
            "BBB",
            "B.C",
            "CCC",
            "..C"
        }
    );

    mp[make_pair(7,4)] = make_pair(4,
        vector<string>{
            "AAA.",
            ".AB.",
            ".AB.",
            "CBBB",
            "CCCD",
            "CDDD",
            "...D"
        }
    );

    mp[make_pair(7,5)] = make_pair(5,
        vector<string>{
            "AAA..",
            ".ABBB",
            "CA.B.",
            "CCCB.",
            "CEDDD",
            ".E.D.",
            "EEED."
        }
    );

    mp[make_pair(7,6)] = make_pair(6,
        vector<string>{
            "AAABBB",
            ".A..B.",
            "CA.DB.",
            "CCCDDD",
            "CE.DF.",
            ".EEEF.",
            ".E.FFF"
        }
    );

    mp[make_pair(7,7)] = make_pair(8,
        vector<string>{
            "AAA.BBB",
            ".ACCCB.",
            "DA.C.BE",
            "DDDCEEE",
            "DGFFFHE",
            ".G.F.H.",
            "GGGFHHH"
        }
    );

    mp[make_pair(7,8)] = make_pair(9,
        vector<string>{
            "AAA.BBB.",
            ".ACCCBE.",
            ".ADC.BE.",
            "DDDCFEEE",
            "G.DIFFFH",
            "GGGIFHHH",
            "G.III..H"
        }
    );

    mp[make_pair(7,9)] = make_pair(10,
        vector<string>{
            "AAA.BBB..",
            ".ACCCBDDD",
            ".AECFB.D.",
            "EEECFFFDG",
            "H.EJFIGGG",
            "HHHJ.IIIG",
            "H.JJJI..."
        }
    );

    mp[make_pair(8,1)] = make_pair(0,
        vector<string>{
            ".",
            ".",
            ".",
            ".",
            ".",
            ".",
            ".",
            "."
        }
    );

    mp[make_pair(8,2)] = make_pair(0,
        vector<string>{
            "..",
            "..",
            "..",
            "..",
            "..",
            "..",
            "..",
            ".."
        }
    );

    mp[make_pair(8,3)] = make_pair(3,
        vector<string>{
            "AAA",
            ".A.",
            "BA.",
            "BBB",
            "B..",
            "CCC",
            ".C.",
            ".C."
        }
    );

    mp[make_pair(8,4)] = make_pair(4,
        vector<string>{
            "AAA.",
            ".A..",
            "BA..",
            "BBB.",
            "BCCC",
            ".DC.",
            ".DC.",
            "DDD."
        }
    );

    mp[make_pair(8,5)] = make_pair(6,
        vector<string>{
            "AAA..",
            ".ABBB",
            "CA.B.",
            "CCCBD",
            "C.DDD",
            "EEEFD",
            ".E.F.",
            ".EFFF"
        }
    );

    mp[make_pair(8,6)] = make_pair(7,
        vector<string>{
            "AAABBB",
            ".A..B.",
            "CA.DB.",
            "CCCDDD",
            "C.ED..",
            ".GEEEF",
            ".GEFFF",
            "GGG..F"
        }
    );

    mp[make_pair(8,7)] = make_pair(9,
        vector<string>{
            "AAA.BBB",
            ".ACCCB.",
            "DA.CEB.",
            "DDDCEEE",
            "DFFFE.G",
            ".IFHGGG",
            ".IFHHHG",
            "IIIH..."
        }
    );

    mp[make_pair(8,8)] = make_pair(10,
        vector<string>{
            "AAABBB..",
            ".A..BCCC",
            "DA..B.C.",
            "DDDEEECG",
            "DFFFEGGG",
            ".IFHE.JG",
            ".IFHHHJ.",
            "IIIH.JJJ"
        }
    );

    mp[make_pair(8,9)] = make_pair(12,
        vector<string>{
            "AAA.BBB.D",
            ".ACCCBDDD",
            "EA.CFB.GD",
            "EEECFFFG.",
            "E..HFIGGG",
            "JHHHLIIIK",
            "JJJHLIKKK",
            "J..LLL..K"
        }
    );

    mp[make_pair(9,1)] = make_pair(0,
        vector<string>{
            ".",
            ".",
            ".",
            ".",
            ".",
            ".",
            ".",
            ".",
            "."
        }
    );

    mp[make_pair(9,2)] = make_pair(0,
        vector<string>{
            "..",
            "..",
            "..",
            "..",
            "..",
            "..",
            "..",
            "..",
            ".."
        }
    );

    mp[make_pair(9,3)] = make_pair(4,
        vector<string>{
            "AAA",
            ".A.",
            "BA.",
            "BBB",
            "B.C",
            "CCC",
            "D.C",
            "DDD",
            "D.."
        }
    );

    mp[make_pair(9,4)] = make_pair(5,
        vector<string>{
            "AAA.",
            ".A..",
            "BA..",
            "BBBC",
            "BCCC",
            "DDDC",
            ".DE.",
            ".DE.",
            ".EEE"
        }
    );

    mp[make_pair(9,5)] = make_pair(7,
        vector<string>{
            "AAA..",
            ".ABBB",
            "CA.B.",
            "CCCBD",
            "CEDDD",
            ".EEED",
            "GEFFF",
            "GGGF.",
            "G..F."
        }
    );

    mp[make_pair(9,6)] = make_pair(8,
        vector<string>{
            "AAABBB",
            ".A..B.",
            "CA.DB.",
            "CCCDDD",
            "C.ED..",
            "EEEFFF",
            "G.EHF.",
            "GGGHF.",
            "G.HHH."
        }
    );

    mp[make_pair(9,7)] = make_pair(10,
        vector<string>{
            "AAABBB.",
            ".A..BD.",
            "CA.EBD.",
            "CCCEDDD",
            "CFEEE.G",
            ".FFFGGG",
            "IFHHHJG",
            "IIIH.J.",
            "I..HJJJ"
        }
    );

    mp[make_pair(9,8)] = make_pair(12,
        vector<string>{
            "AAABBB.C",
            ".AD.BCCC",
            ".AD.B.EC",
            "FDDDEEE.",
            "FFFGGGEI",
            "FHHHGIII",
            ".KHJG.LI",
            ".KHJJJL.",
            "KKKJ.LLL"
        }
    );

    mp[make_pair(9,9)] = make_pair(13,
        vector<string>{
            "AAABBBCCC",
            ".AD.BE.C.",
            ".AD.BE.C.",
            "FDDDEEE.H",
            "FFFGGGHHH",
            "FIIIGJJJH",
            ".LIKG.JM.",
            ".LIKKKJM.",
            "LLLK..MMM"
        }
    );

    int n, m; cin >> n >> m;
    pair<int, vector<string>> p = mp[make_pair(n,m)];
    cout << p.first << endl;
    for (int i=0; i < n; i++) cout << p.second[i] << endl;
    return 0;
}
