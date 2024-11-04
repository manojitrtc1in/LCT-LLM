










using namespace std;

void print(string s){
  cout<<s<<endl;
}

int n, m;
int main(){
  cin>>n>>m;
  if(n == 1 && m == 1){
cout<<0<<endl;
    cout<<"."<<endl;
  }
  if(n == 1 && m == 2){
cout<<0<<endl;
    cout<<".."<<endl;
  }
  if(n == 1 && m == 3){
cout<<0<<endl;
    cout<<"..."<<endl;
  }
  if(n == 1 && m == 4){
cout<<0<<endl;
    cout<<"...."<<endl;
  }
  if(n == 1 && m == 5){
cout<<0<<endl;
    cout<<"....."<<endl;
  }
  if(n == 1 && m == 6){
cout<<0<<endl;
    cout<<"......"<<endl;
  }
  if(n == 1 && m == 7){
cout<<0<<endl;
    cout<<"......."<<endl;
  }
  if(n == 1 && m == 8){
cout<<0<<endl;
    cout<<"........"<<endl;
  }
  if(n == 1 && m == 9){
cout<<0<<endl;
    cout<<"........."<<endl;
  }
  if(n == 2 && m == 1){
cout<<0<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
  }
  if(n == 2 && m == 2){
cout<<0<<endl;
    cout<<".."<<endl;
    cout<<".."<<endl;
  }
  if(n == 2 && m == 3){
cout<<0<<endl;
    cout<<"..."<<endl;
    cout<<"..."<<endl;
  }
  if(n == 2 && m == 4){
cout<<0<<endl;
    cout<<"...."<<endl;
    cout<<"...."<<endl;
  }
  if(n == 2 && m == 5){
cout<<0<<endl;
    cout<<"....."<<endl;
    cout<<"....."<<endl;
  }
  if(n == 2 && m == 6){
cout<<0<<endl;
    cout<<"......"<<endl;
    cout<<"......"<<endl;
  }
  if(n == 2 && m == 7){
cout<<0<<endl;
    cout<<"......."<<endl;
    cout<<"......."<<endl;
  }
  if(n == 2 && m == 8){
cout<<0<<endl;
    cout<<"........"<<endl;
    cout<<"........"<<endl;
  }
  if(n == 2 && m == 9){
cout<<0<<endl;
    cout<<"........."<<endl;
    cout<<"........."<<endl;
  }
  if(n == 3 && m == 1){
cout<<0<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
  }
  if(n == 3 && m == 2){
    cout<<0<<endl;
    cout<<".."<<endl;
    cout<<".."<<endl;
    cout<<".."<<endl;
  }
  if(n == 3 && m == 3){
    cout<<1<<endl;
    cout<<"AAA"<<endl;
    cout<<".A."<<endl;
    cout<<".A."<<endl;
  }
  if(n == 3 && m == 4){
    cout<<1<<endl;
    cout<<"AAA."<<endl;
    cout<<".A.."<<endl;
    cout<<".A.."<<endl;
  }
  if(n == 3 && m == 5){
    cout<<2<<endl;
    cout<<"AAAB."<<endl;
    cout<<".A.B."<<endl;
    cout<<".ABBB"<<endl;
  }
  if(n == 3 && m == 6){
    cout<<2<<endl;
    cout<<"AAAB.."<<endl;
    cout<<".A.B.."<<endl;
    cout<<".ABBB."<<endl;
  }
  if(n == 3 && m == 7){
    cout<<3<<endl;
    cout<<"AAAB..C"<<endl;
    cout<<".A.BCCC"<<endl;
    cout<<".ABBB.C"<<endl;
  }
  if(n == 3 && m == 8){
    cout<<3<<endl;
    cout<<"AAAB..C."<<endl;
    cout<<".A.BCCC."<<endl;
    cout<<".ABBB.C."<<endl;
  }
  if(n == 3 && m == 9){
    cout<<4<<endl;
    cout<<"AAABCCCD."<<endl;
    cout<<".A.B.C.D."<<endl;
    cout<<".ABBBCDDD"<<endl;
  }
  if(n == 4 && m == 1){
    cout<<0<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
  }
  if(n == 4 && m == 2){
    cout<<0<<endl;
    cout<<".."<<endl;
    cout<<".."<<endl;
    cout<<".."<<endl;
    cout<<".."<<endl;
  }
  if(n == 4 && m == 3){
    cout<<1<<endl;
    cout<<"AAA"<<endl;
    cout<<".A."<<endl;
    cout<<".A."<<endl;
    cout<<"..."<<endl;
  }
  if(n == 4 && m == 4){
    cout<<2<<endl;
    cout<<"AAA."<<endl;
    cout<<".AB."<<endl;
    cout<<".AB."<<endl;
    cout<<".BBB"<<endl;
  }
  if(n == 4 && m == 5){
    cout<<2<<endl;
    cout<<"AAA.."<<endl;
    cout<<".AB.."<<endl;
    cout<<".AB.."<<endl;
    cout<<".BBB."<<endl;
  }
  if(n == 4 && m == 6){
    cout<<3<<endl;
    cout<<"AAA..C"<<endl;
    cout<<".ABCCC"<<endl;
    cout<<".AB..C"<<endl;
    cout<<".BBB.."<<endl;
  }
  if(n == 4 && m == 7){
    cout<<4<<endl;
    cout<<"AAACCC."<<endl;
    cout<<".AB.CD."<<endl;
    cout<<".AB.CD."<<endl;
    cout<<".BBBDDD"<<endl;
  }
  if(n == 4 && m == 8){
    cout<<4<<endl;
    cout<<"AAADDD.."<<endl;
    cout<<".AB.DC.."<<endl;
    cout<<".AB.DC.."<<endl;
    cout<<".BBBCCC."<<endl;
  }
  if(n == 4 && m == 9){
    cout<<5<<endl;
    cout<<"AAADDDEEE"<<endl;
    cout<<".AB.DC.E."<<endl;
    cout<<".AB.DC.E."<<endl;
    cout<<".BBBCCC.."<<endl;
  }
  if(n == 5 && m == 1){
    cout<<0<<endl;
    for(int i = 0; i < n; ++i)cout<<"."<<endl;
  }
  if(n == 5 && m == 2){
    cout<<0<<endl;
    for(int i = 0; i < n; ++i)cout<<".."<<endl;
  }
  if(n == 5 && m == 3){
    cout<<2<<endl;
    cout<<"AAA"<<endl;
    cout<<".A."<<endl;
    cout<<".AB"<<endl;
    cout<<"BBB"<<endl;
    cout<<"..B"<<endl;
  }
 if(n == 5 && m == 4){
    cout<<2<<endl;
    cout<<"AAA."<<endl;
    cout<<".A.."<<endl;
    cout<<".AB."<<endl;
    cout<<"BBB."<<endl;
    cout<<"..B."<<endl;
  }
 if(n == 5 && m == 5){
    cout<<4<<endl;
    cout<<"AAA.B"<<endl;
    cout<<".ABBB"<<endl;
    cout<<"CA.DB"<<endl;
    cout<<"CCCD."<<endl;
    cout<<"C.DDD"<<endl;
  }

 if(n == 5 && m == 6){
    cout<<4<<endl;
    cout<<"AAA..."<<endl;
    cout<<".ACCC."<<endl;
    cout<<".ABCD."<<endl;
    cout<<"BBBCD."<<endl;
    cout<<"..BDDD"<<endl;
  }
 if(n == 5 && m == 7){
    cout<<5<<endl;
    cout<<"AAA.EEE"<<endl;
    cout<<".ACCCE."<<endl;
    cout<<".ABCDE."<<endl;
    cout<<"BBBCD.."<<endl;
    cout<<"..BDDD."<<endl;
  }
 if(n == 5 && m == 8){
    cout<<6<<endl;
    cout<<"AAA.EEE."<<endl;
    cout<<".ACCCE.."<<endl;
    cout<<".ABCDE.F"<<endl;
    cout<<"BBBCDFFF"<<endl;
    cout<<"..BDDD.F"<<endl;
  }
 if(n == 5 && m == 9){
    cout<<7<<endl;
    cout<<"AAA.EEE.G"<<endl;
    cout<<".ACCCEGGG"<<endl;
    cout<<".ABCDE.FG"<<endl;
    cout<<"BBBCDFFF."<<endl;
    cout<<"..BDDD.F."<<endl;
  }
 int i = 0;
 if(n == 6 && m == 1){
   cout<<0<<endl;
   for(i = 0; i < n; ++i)cout<<"."<<endl;
 }
 if(n == 6 && m == 2){
   cout<<0<<endl;
   for(i = 0; i < 6; ++i){
     cout<<".."<<endl;
   }
 }
 if(n == 6 && m == 3){
   cout<<2<< endl;
   cout<<"AAA"<<endl;
   cout<<".A."<<endl;
   cout<<".AB"<<endl;
   cout<<"BBB"<<endl;
   cout<<"..B"<<endl;
   cout<<"..."<<endl;
 }
 if(n == 6 && m == 4){
   cout<<3<< endl;
   cout<<"A..."<<endl;
   cout<<"AAAB"<<endl;
   cout<<"ABBB"<<endl;
   cout<<"CCCB"<<endl;
   cout<<".C.."<<endl;
   cout<<".C.."<<endl;
 }
 if(n == 6 && m == 5){
   cout<<4<< endl;
   cout<<"A...."<<endl;
   cout<<"AAAB."<<endl;
   cout<<"ABBB."<<endl;
   cout<<"CCCBD"<<endl;
   cout<<".CDDD"<<endl;
   cout<<".C..D"<<endl;
 }
 if(n == 6 && m == 6){
   cout<<5<< endl;
   cout<<"A..EEE"<<endl;
   cout<<"AAABE."<<endl;
   cout<<"ABBBE."<<endl;
   cout<<"CCCBD."<<endl;
   cout<<".CDDD."<<endl;
   cout<<".C..D."<<endl;
 }
 if(n == 6 && m == 7){
   cout<<6<< endl;
   cout<<"A..C..E"<<endl;
   cout<<"AAACEEE"<<endl;
   cout<<"ABCCCFE"<<endl;
   cout<<".B.D.F."<<endl;
   cout<<"BBBDFFF"<<endl;
   cout<<"..DDD.."<<endl;
 }
 if(n == 6 && m == 8){
   cout<<7<<endl;
   cout<<"AAAC.EEE"<<endl;
   cout<<".ABCCCE."<<endl;
   cout<<".ABCG.EF"<<endl;
   cout<<"DBBBGFFF"<<endl;
   cout<<"DDDGGG.F"<<endl;
   cout<<"D......."<<endl;
 }
 if(n == 6 && m == 9){
   cout<<8<<endl;
   cout<<"A..CEEE.G"<<endl;
   cout<<"AAAC.EGGG"<<endl;
   cout<<"ABCCCEF.G"<<endl;
   cout<<".B.DFFFH."<<endl;
   cout<<"BBBD..FH."<<endl;
   cout<<"..DDD.HHH"<<endl;
 }
 if(n == 7 && m == 1){
   cout<<0<<endl;
   for(i = 0; i < n; ++i){
     cout<<"."<<endl;
   }
 }
 if(n == 7 && m == 2){
   cout<<0<<endl;
   for(i = 0; i < n; ++i){
     cout<<".."<<endl;
   }
 }
 if(n == 7 && m == 3){
   cout<<3<<endl;
   cout<<"AAA"<<endl;
   cout<<".A."<<endl;
   cout<<".AB"<<endl;
   cout<<"BBB"<<endl;
   cout<<".CB"<<endl;
   cout<<".C."<<endl;
   cout<<"CCC"<<endl;
 }
 if(n == 7 && m == 4){
   cout<<4<<endl;
   cout<<"AAA."<<endl;
   cout<<".AB."<<endl;
   cout<<".AB."<<endl;
   cout<<"CBBB"<<endl;
   cout<<"CCCD"<<endl;
   cout<<"CDDD"<<endl;
   cout<<"...D"<<endl;
 }
 if(n == 7 && m == 5){
   cout<<5<<endl;
   cout<<"AAA.D"<<endl;
   cout<<".ADDD"<<endl;
   cout<<".AB.D"<<endl;
   cout<<"BBB.."<<endl;
   cout<<".CB.E"<<endl;
   cout<<".CEEE"<<endl;
   cout<<"CCC.E"<<endl;
 }
if(n == 7 && m == 6){
   cout<<6<<endl;
   cout<<"AAA.D."<<endl;
   cout<<".ADDD."<<endl;
   cout<<".AB.DF"<<endl;
   cout<<"BBBFFF"<<endl;
   cout<<".CB.EF"<<endl;
   cout<<".CEEE."<<endl;
   cout<<"CCC.E."<<endl;
 }
if(n == 7 && m == 7){
   cout<<8<<endl;
   cout<<"AAABCCC"<<endl;
   cout<<".A.B.C."<<endl;
   cout<<"DABBBCE"<<endl;
   cout<<"DDDFEEE"<<endl;
   cout<<"DG.F.HE"<<endl;
   cout<<".GFFFH."<<endl;
   cout<<"GGG.HHH"<<endl;
 }
if(n == 7 && m == 8){
   cout<<9<<endl;
   cout<<"A.DDD..H"<<endl;
   cout<<"AAADFHHH"<<endl;
   cout<<"A.BDFFFH"<<endl;
   cout<<"BBBEFIII"<<endl;
   cout<<".CBE.GI."<<endl;
   cout<<".CEEEGI."<<endl;
   cout<<"CCC.GGG."<<endl;
 }
if(n == 7 && m == 9){
   cout<<10<<endl;
   cout<<"A..DFFF.H"<<endl;
   cout<<"AAAD.FHHH"<<endl;
   cout<<"ABDDDFI.H"<<endl;
   cout<<".B.EEEIII"<<endl;
   cout<<"BBBCEGI.J"<<endl;
   cout<<".CCCEGJJJ"<<endl;
   cout<<"...CGGG.J"<<endl;
 }
 if(n == 8 && m == 1){
   cout<<0<<endl;
   for(i = 0; i < n; ++i)cout<<"."<<endl;
 }
 if(n == 8 && m == 2){
   cout<<0<<endl;
   for(i = 0; i < n; ++i)cout<<".."<<endl;
 }
 if(n == 8 && m == 3){
   cout<<3<<endl;
   cout<<"AAA"<<endl;
   cout<<".A."<<endl;
   cout<<".AB"<<endl;
   cout<<"BBB"<<endl;
   cout<<".CB"<<endl;
   cout<<".C."<<endl;
   cout<<"CCC"<<endl;
   cout<<"..."<<endl;
 }
 if(n == 8 && m == 4){
   cout<<4<<endl;
   cout<<"AAA."<<endl;
   cout<<".AB."<<endl;
   cout<<".AB."<<endl;
   cout<<".BBB"<<endl;
   cout<<".CCC"<<endl;
   cout<<".DC."<<endl;
   cout<<".DC."<<endl;
   cout<<"DDD."<<endl;
 }
if(n == 8 && m == 5){
   cout<<6<<endl;
   cout<<"AAA.B"<<endl;
   cout<<".ABBB"<<endl;
   cout<<"CA.DB"<<endl;
   cout<<"CCCD."<<endl;
   cout<<"CEDDD"<<endl;
   cout<<".EFFF"<<endl;
   cout<<"EEEF."<<endl;
   cout<<"...F."<<endl;
 }
if(n == 8 && m == 6){
   cout<<7<<endl;
   cout<<"AAA.B."<<endl;
   cout<<".ABBB."<<endl;
   cout<<".AC.BD"<<endl;
   cout<<"CCCDDD"<<endl;
   cout<<"..CE.D"<<endl;
   cout<<"FEEEG."<<endl;
   cout<<"FFFEG."<<endl;
   cout<<"F..GGG"<<endl;
 }
if(n == 8 && m == 7){
   cout<<9<<endl;
   cout<<"AAAB..C"<<endl;
   cout<<".A.BCCC"<<endl;
   cout<<"DABBBEC"<<endl;
   cout<<"DDDEEE."<<endl;
   cout<<"DFFF.EG"<<endl;
   cout<<".HFIGGG"<<endl;
   cout<<".HFIIIG"<<endl;
   cout<<"HHHI..."<<endl;
 }
if(n == 8 && m == 8){
   cout<<10<<endl;
   cout<<"AAA.BCCC"<<endl;
   cout<<".ABBBDC."<<endl;
   cout<<"EA.FBDC."<<endl;
   cout<<"EEEFDDDG"<<endl;
   cout<<"EHFFFGGG"<<endl;
   cout<<".HIII.JG"<<endl;
   cout<<"HHHIJJJ."<<endl;
   cout<<"...I..J."<<endl;
 }
if(n == 8 && m == 9){
   cout<<12<<endl;
   cout<<"A.EEE.JJJ"<<endl;
   cout<<"AAAEHHHJ."<<endl;
   cout<<"AB.EFHKJ."<<endl;
   cout<<".BFFFHKKK"<<endl;
   cout<<"BBBDFIK.."<<endl;
   cout<<"CDDDGIIIL"<<endl;
   cout<<"CCCDGILLL"<<endl;
   cout<<"C..GGG..L"<<endl;
 }
 if(n == 9 && m == 1){
   cout<<0<<endl;
   for(i = 0; i < n; ++i){
     cout<<"."<<endl;
   }
 }
 if(n == 9 && m == 2){
   cout<<0<<endl;
   for(i = 0; i < n; ++i){
     cout<<".."<<endl;
   }
 }
 if(n == 9 && m == 3){
   cout<<4<<endl;
   cout<<"..A"<<endl;
   cout<<"AAA"<<endl;
   cout<<"B.A"<<endl;
   cout<<"BBB"<<endl;
   cout<<"B.C"<<endl;
   cout<<"CCC"<<endl;
   cout<<"D.C"<<endl;
   cout<<"DDD"<<endl;
   cout<<"D.."<<endl;
 }
 if(n == 9 && m == 4){
   cout<<5<<endl;
   cout<<"AAA."<<endl;
   cout<<".AB."<<endl;
   cout<<".AB."<<endl;
   cout<<"CBBB"<<endl;
   cout<<"CCCD"<<endl;
   cout<<"CDDD"<<endl;
   cout<<"EEED"<<endl;
   cout<<".E.."<<endl;
   cout<<".E.."<<endl;
 }
 if(n == 9 && m == 5){
   cout<<7<<endl;
   cout<<".B..A"<<endl;
   cout<<".BAAA"<<endl;
   cout<<"BBBCA"<<endl;
   cout<<"DCCC."<<endl;
   cout<<"DDDCE"<<endl;
   cout<<"DFEEE"<<endl;
   cout<<".F.GE"<<endl;
   cout<<"FFFG."<<endl;
   cout<<"..GGG"<<endl;
 }
 if(n == 9 && m == 6){
   cout<<8<<endl;
   cout<<"AAA.B."<<endl;
   cout<<".ABBB."<<endl;
   cout<<".AC.BD"<<endl;
   cout<<"CCCDDD"<<endl;
   cout<<"E.CF.D"<<endl;
   cout<<"EEEF.."<<endl;
   cout<<"EGFFFH"<<endl;
   cout<<".G.HHH"<<endl;
   cout<<"GGG..H"<<endl;
 }
 if(n == 9 && m == 7){
   cout<<10<<endl;
   cout<<"AAABCCC"<<endl;
   cout<<".A.B.C."<<endl;
   cout<<"DABBBCH"<<endl;
   cout<<"DDDIHHH"<<endl;
   cout<<"D.FIIIH"<<endl;
   cout<<"FFFIGGG"<<endl;
   cout<<".EF.JG."<<endl;
   cout<<".EJJJG."<<endl;
   cout<<"EEE.J.."<<endl;
 }
 if(n == 9 && m == 8){
   cout<<12<<endl;
   print("J..K.LLL");
   print("JJJK.IL.");
   print("JHKKKIL.");
   print(".HHHIIIG");
   print("EHFFFGGG");
   print("EEEFDDDG");
   print("EA.FBDC.");
   print(".ABBBDC.");
   print("AAA.BCCC");
 }
 if(n == 9 && m == 9){
   cout<<13<<endl;
   print("AAA.BCCC.");
   print(".ABBB.CD.");
   print(".AE.BFCD.");
   print("EEEFFFDDD");
   print("G.E.HFIII");
   print("GGGJHHHI.");
   print("GK.JHL.IM");
   print(".KJJJLMMM");
   print("KKK.LLL.M");
 }
 
  return 0;
}
