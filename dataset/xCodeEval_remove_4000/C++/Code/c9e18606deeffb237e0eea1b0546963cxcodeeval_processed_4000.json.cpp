






























using namespace std;




















typedef long long ll;
typedef long double ld;
typedef pair< int,int > ii;
typedef vector< int > vi;
typedef vector< double > vd;
typedef vector< ii > vii;
typedef vector< vii > vvii;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef vector< vd > vvd;






const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
int bit_count(int x){ return x==0 ? 0 : 1+bit_count(x&(x-1)); }
inline int last_bit(int x){ return x&-x; } 




inline int sign(double x){ return x<-EPS ? -1 : x>EPS ? 1 : 0; }
inline int sign(int x){ return (x>0)-(x<0); }



int gcd(int a, int b){ while(b){ int r=a%b; a=b; b=r; } return a; }
int lcm(int a, int b){ return a/gcd(a,b)*b; }



const int BUF_SIZE = 201;
char buf[BUF_SIZE];

inline string getToken(){
    return scanf("%s", buf) ? buf : (fprintf(stderr, "trying to read\n"),"");
}

inline string getLine(){
    fgets(buf, BUF_SIZE, stdin);
    return buf;
}

inline int getInt(){
    int a;
    return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getDouble(){
    double a;
    return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1.0);
}



inline double myRand(){
    return ((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX);
}






void myCode(){
int m=getInt(), n=getInt();

if(m==1 && n==1){
    printf("0\n");
    printf(".\n");
}
if(m==1 && n==2){
    printf("0\n");
    printf("..\n");
}
if(m==1 && n==3){
    printf("0\n");
    printf("...\n");
}
if(m==1 && n==4){
    printf("0\n");
    printf("....\n");
}
if(m==1 && n==5){
    printf("0\n");
    printf(".....\n");
}
if(m==1 && n==6){
    printf("0\n");
    printf("......\n");
}
if(m==1 && n==7){
    printf("0\n");
    printf(".......\n");
}
if(m==1 && n==8){
    printf("0\n");
    printf("........\n");
}
if(m==1 && n==9){
    printf("0\n");
    printf(".........\n");
}
if(m==2 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
}
if(m==2 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
}
if(m==2 && n==3){
    printf("0\n");
    printf("...\n");
    printf("...\n");
}
if(m==2 && n==4){
    printf("0\n");
    printf("....\n");
    printf("....\n");
}
if(m==2 && n==5){
    printf("0\n");
    printf(".....\n");
    printf(".....\n");
}
if(m==2 && n==6){
    printf("0\n");
    printf("......\n");
    printf("......\n");
}
if(m==2 && n==7){
    printf("0\n");
    printf(".......\n");
    printf(".......\n");
}
if(m==2 && n==8){
    printf("0\n");
    printf("........\n");
    printf("........\n");
}
if(m==2 && n==9){
    printf("0\n");
    printf(".........\n");
    printf(".........\n");
}
if(m==3 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}
if(m==3 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
}
if(m==3 && n==3){
    printf("1\n");
    printf("AAA\n");
    printf(".A.\n");
    printf(".A.\n");
}
if(m==3 && n==4){
    printf("1\n");
    printf("AAA.\n");
    printf(".A..\n");
    printf(".A..\n");
}
if(m==3 && n==5){
    printf("2\n");
    printf("AAAB.\n");
    printf(".A.B.\n");
    printf(".ABBB\n");
}
if(m==3 && n==6){
    printf("2\n");
    printf("AAAB..\n");
    printf(".A.B..\n");
    printf(".ABBB.\n");
}
if(m==3 && n==7){
    printf("3\n");
    printf("AAABCCC\n");
    printf(".A.B.C.\n");
    printf(".ABBBC.\n");
}
if(m==3 && n==8){
    printf("3\n");
    printf("AAABCCC.\n");
    printf(".A.B.C..\n");
    printf(".ABBBC..\n");
}
if(m==3 && n==9){
    printf("4\n");
    printf("AAABCCCD.\n");
    printf(".A.B.C.D.\n");
    printf(".ABBBCDDD\n");
}
if(m==4 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}
if(m==4 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
}
if(m==4 && n==3){
    printf("1\n");
    printf("AAA\n");
    printf(".A.\n");
    printf(".A.\n");
    printf("...\n");
}
if(m==4 && n==4){
    printf("2\n");
    printf("AAA.\n");
    printf(".AB.\n");
    printf(".AB.\n");
    printf(".BBB\n");
}
if(m==4 && n==5){
    printf("2\n");
    printf("AAAB.\n");
    printf(".A.B.\n");
    printf(".ABBB\n");
    printf(".....\n");
}
if(m==4 && n==6){
    printf("3\n");
    printf("AAABBB\n");
    printf(".AC.B.\n");
    printf(".AC.B.\n");
    printf(".CCC..\n");
}
if(m==4 && n==7){
    printf("4\n");
    printf("AAABBB.\n");
    printf(".AC.BD.\n");
    printf(".AC.BD.\n");
    printf(".CCCDDD\n");
}
if(m==4 && n==8){
    printf("4\n");
    printf("AAABCCC.\n");
    printf(".A.B.CD.\n");
    printf(".ABBBCD.\n");
    printf(".....DDD\n");
}
if(m==4 && n==9){
    printf("5\n");
    printf("AAABBBCCC\n");
    printf(".AD.BE.C.\n");
    printf(".AD.BE.C.\n");
    printf(".DDDEEE..\n");
}
if(m==5 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}
if(m==5 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
}
if(m==5 && n==3){
    printf("2\n");
    printf("AAA\n");
    printf(".A.\n");
    printf("BA.\n");
    printf("BBB\n");
    printf("B..\n");
}
if(m==5 && n==4){
    printf("2\n");
    printf("AAA.\n");
    printf(".AB.\n");
    printf(".AB.\n");
    printf(".BBB\n");
    printf("....\n");
}
if(m==5 && n==5){
    printf("4\n");
    printf("AAA.B\n");
    printf(".ABBB\n");
    printf("CA.DB\n");
    printf("CCCD.\n");
    printf("C.DDD\n");
}
if(m==5 && n==6){
    printf("4\n");
    printf("AAAB..\n");
    printf(".A.B..\n");
    printf("CABBBD\n");
    printf("CCCDDD\n");
    printf("C....D\n");
}
if(m==5 && n==7){
    printf("5\n");
    printf("AAABCCC\n");
    printf(".A.B.C.\n");
    printf("DABBBCE\n");
    printf("DDD.EEE\n");
    printf("D.....E\n");
}
if(m==5 && n==8){
    printf("6\n");
    printf("AAA.BCCC\n");
    printf(".ABBBDC.\n");
    printf("EA.FBDC.\n");
    printf("EEEFDDD.\n");
    printf("E.FFF...\n");
}
if(m==5 && n==9){
    printf("7\n");
    printf("AAA.BCCC.\n");
    printf(".ABBBDC..\n");
    printf("EA.FBDCG.\n");
    printf("EEEFDDDG.\n");
    printf("E.FFF.GGG\n");
}
if(m==6 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}
if(m==6 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
}
if(m==6 && n==3){
    printf("2\n");
    printf("AAA\n");
    printf(".A.\n");
    printf("BA.\n");
    printf("BBB\n");
    printf("B..\n");
    printf("...\n");
}
if(m==6 && n==4){
    printf("3\n");
    printf("AAA.\n");
    printf(".AB.\n");
    printf(".AB.\n");
    printf("CBBB\n");
    printf("CCC.\n");
    printf("C...\n");
}
if(m==6 && n==5){
    printf("4\n");
    printf("AAAB.\n");
    printf(".A.B.\n");
    printf("CABBB\n");
    printf("CCCD.\n");
    printf("CDDD.\n");
    printf("...D.\n");
}
if(m==6 && n==6){
    printf("5\n");
    printf("AAA.B.\n");
    printf(".ABBB.\n");
    printf(".A.CB.\n");
    printf("DCCCE.\n");
    printf("DDDCE.\n");
    printf("D..EEE\n");
}
if(m==6 && n==7){
    printf("6\n");
    printf("AAABCCC\n");
    printf(".A.B.C.\n");
    printf("DABBBCE\n");
    printf("DDDFEEE\n");
    printf("DFFF..E\n");
    printf("...F...\n");
}
if(m==6 && n==8){
    printf("7\n");
    printf("AAABCCC.\n");
    printf(".A.B.CD.\n");
    printf("EABBBCD.\n");
    printf("EEEFGDDD\n");
    printf("EFFFGGG.\n");
    printf("...FG...\n");
}
if(m==6 && n==9){
    printf("8\n");
    printf("AAABCCCD.\n");
    printf(".A.B.C.D.\n");
    printf("EABBBCDDD\n");
    printf("EEEFGGGH.\n");
    printf("EFFF.G.H.\n");
    printf("...F.GHHH\n");
}
if(m==7 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}
if(m==7 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
}
if(m==7 && n==3){
    printf("3\n");
    printf("AAA\n");
    printf(".A.\n");
    printf("BA.\n");
    printf("BBB\n");
    printf("BC.\n");
    printf(".C.\n");
    printf("CCC\n");
}
if(m==7 && n==4){
    printf("4\n");
    printf("AAA.\n");
    printf(".AB.\n");
    printf(".AB.\n");
    printf("CBBB\n");
    printf("CCCD\n");
    printf("CDDD\n");
    printf("...D\n");
}
if(m==7 && n==5){
    printf("5\n");
    printf("AAAB.\n");
    printf(".A.B.\n");
    printf("CABBB\n");
    printf("CCCD.\n");
    printf("CE.D.\n");
    printf(".EDDD\n");
    printf("EEE..\n");
}
if(m==7 && n==6){
    printf("6\n");
    printf("AAAB..\n");
    printf(".A.B..\n");
    printf("CABBBD\n");
    printf("CCCDDD\n");
    printf("CEFFFD\n");
    printf(".E.F..\n");
    printf("EEEF..\n");
}
if(m==7 && n==7){
    printf("8\n");
    printf("AAABCCC\n");
    printf(".A.B.C.\n");
    printf("DABBBCE\n");
    printf("DDDFEEE\n");
    printf("DG.F.HE\n");
    printf(".GFFFH.\n");
    printf("GGG.HHH\n");
}
if(m==7 && n==8){
    printf("9\n");
    printf("AAA.BBB.\n");
    printf(".ACCCBD.\n");
    printf(".AEC.BD.\n");
    printf("EEECFDDD\n");
    printf("G.EHFFFI\n");
    printf("GGGHFIII\n");
    printf("G.HHH..I\n");
}
if(m==7 && n==9){
    printf("10\n");
    printf("AAABCCC.D\n");
    printf(".A.B.CDDD\n");
    printf("EABBBCF.D\n");
    printf("EEEGFFFH.\n");
    printf("EI.G.JFH.\n");
    printf(".IGGGJHHH\n");
    printf("III.JJJ..\n");
}
if(m==8 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}
if(m==8 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
}
if(m==8 && n==3){
    printf("3\n");
    printf("AAA\n");
    printf(".A.\n");
    printf("BA.\n");
    printf("BBB\n");
    printf("BC.\n");
    printf(".C.\n");
    printf("CCC\n");
    printf("...\n");
}
if(m==8 && n==4){
    printf("4\n");
    printf("AAA.\n");
    printf(".AB.\n");
    printf(".AB.\n");
    printf("CBBB\n");
    printf("CCCD\n");
    printf("CDDD\n");
    printf("...D\n");
    printf("....\n");
}
if(m==8 && n==5){
    printf("6\n");
    printf("AAAB.\n");
    printf(".A.B.\n");
    printf("CABBB\n");
    printf("CCCD.\n");
    printf("CDDD.\n");
    printf("EEEDF\n");
    printf(".EFFF\n");
    printf(".E..F\n");
}
if(m==8 && n==6){
    printf("7\n");
    printf("AAAB..\n");
    printf(".A.B..\n");
    printf("CABBBD\n");
    printf("CCCDDD\n");
    printf("CEFFFD\n");
    printf(".E.FG.\n");
    printf("EEEFG.\n");
    printf("...GGG\n");
}
if(m==8 && n==7){
    printf("9\n");
    printf("AAAB..C\n");
    printf(".A.BCCC\n");
    printf("DABBBEC\n");
    printf("DDDEEE.\n");
    printf("DFFF.EG\n");
    printf(".HFIGGG\n");
    printf(".HFIIIG\n");
    printf("HHHI...\n");
}
if(m==8 && n==8){
    printf("10\n");
    printf("AAABCCC.\n");
    printf(".A.B.CD.\n");
    printf("EABBBCD.\n");
    printf("EEEF.DDD\n");
    printf("EFFFGGG.\n");
    printf("HHHFIGJ.\n");
    printf(".HIIIGJ.\n");
    printf(".H..IJJJ\n");
}
if(m==8 && n==9){
    printf("12\n");
    printf("AAABBB..C\n");
    printf(".AD.BECCC\n");
    printf(".AD.BEEEC\n");
    printf("FDDDGEHHH\n");
    printf("FFFIGGGH.\n");
    printf("FJ.IGK.HL\n");
    printf(".JIIIKLLL\n");
    printf("JJJ.KKK.L\n");
}
if(m==9 && n==1){
    printf("0\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
}
if(m==9 && n==2){
    printf("0\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
    printf("..\n");
}
if(m==9 && n==3){
    printf("4\n");
    printf("AAA\n");
    printf(".A.\n");
    printf("BA.\n");
    printf("BBB\n");
    printf("B.C\n");
    printf("CCC\n");
    printf(".DC\n");
    printf(".D.\n");
    printf("DDD\n");
}
if(m==9 && n==4){
    printf("5\n");
    printf("AAA.\n");
    printf(".AB.\n");
    printf(".AB.\n");
    printf("CBBB\n");
    printf("CCCD\n");
    printf("CDDD\n");
    printf("EEED\n");
    printf(".E..\n");
    printf(".E..\n");
}
if(m==9 && n==5){
    printf("7\n");
    printf("AAAB.\n");
    printf(".A.B.\n");
    printf("CABBB\n");
    printf("CCC.D\n");
    printf("CEDDD\n");
    printf(".EEED\n");
    printf("FEGGG\n");
    printf("FFFG.\n");
    printf("F..G.\n");
}
if(m==9 && n==6){
    printf("8\n");
    printf("AAAB..\n");
    printf(".A.B..\n");
    printf("CABBBD\n");
    printf("CCCDDD\n");
    printf("C.EF.D\n");
    printf("EEEFFF\n");
    printf(".GEFH.\n");
    printf(".GHHH.\n");
    printf("GGG.H.\n");
}
if(m==9 && n==7){
    printf("10\n");
    printf("AAABCCC\n");
    printf(".A.B.C.\n");
    printf("DABBBCE\n");
    printf("DDDFEEE\n");
    printf("DFFFG.E\n");
    printf("HHHFG..\n");
    printf(".HIGGGJ\n");
    printf(".HI.JJJ\n");
    printf(".III..J\n");
}
if(m==9 && n==8){
    printf("12\n");
    printf("AAABCCC.\n");
    printf(".A.B.CD.\n");
    printf("EABBBCD.\n");
    printf("EEEFGDDD\n");
    printf("EFFFGGGH\n");
    printf("IIIFGHHH\n");
    printf(".IJKKKLH\n");
    printf(".IJ.K.L.\n");
    printf(".JJJKLLL\n");
}
if(m==9 && n==9){
    printf("13\n");
    printf("AAABCCCD.\n");
    printf(".A.B.C.D.\n");
    printf("EABBBCDDD\n");
    printf("EEE.FG...\n");
    printf("EHFFFGGGI\n");
    printf(".HHHFGIII\n");
    printf("JH.KLLLMI\n");
    printf("JJJK.L.M.\n");
    printf("J.KKKLMMM\n");
}

}

int main() {
    srand(time(NULL));
    myCode();
    return 0;
}
